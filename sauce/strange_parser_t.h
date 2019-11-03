#ifndef COM_ONEISH_STRANGE_PARSER_T_H
#define COM_ONEISH_STRANGE_PARSER_T_H

namespace strange
{

template <typename ___ego___ = parser_a<>>
class parser_t : public thing_t<___ego___>
{
public:
	// override
	using over = thing_o<parser_t<>>;

	// construction
	static inline parser_a<> create_()
	{
		return parser_a<>{ over{ parser_t<>{} } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<parser_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<parser_t<>>::share(shoal);
	}

	// parser
	inline expression_a<> parse_(range_a<> const& tokenizer)
	{
		_tokenizer = tokenizer;
		_it = _tokenizer.cbegin_();
		_end = _tokenizer.cend_();
		if (_it == _end)
		{
			return expression_t<>::create(token_t<>::create_punctuation_());
		}
		_previous = token_t<>::create_punctuation_();
		_token = cast<token_a<>>(*_it);
		if (_token.tag() == "error")
		{
			throw dis("strange::parser tokenizer error:") + _token.report_();
		}
		return _initial(0, sym(""), sym(""), unordered_herd_t<>::create_(), unordered_shoal_t<>::create_());
	}

protected:
	inline parser_t()
		: thing_t{}
		, _shared{ unordered_shoal_t<>::create_() }
		, _tokenizer{ tokenizer_t<>::create_(river_t<>::create_()) }
		, _it{ _tokenizer.cbegin_() }
		, _end{ _tokenizer.cend_() }
		, _previous{ token_t<>::create_punctuation_() }
		, _token{ _previous }
	{
		_shared += shared();
	}

private:
	unordered_shoal_a<> _shared;
	range_a<> _tokenizer;
	forward_const_iterator_a<> _it;
	forward_const_iterator_a<> _end;
	token_a<> _previous;
	token_a<> _token;

	inline bool _next()
	{
		if (_it == _end)
		{
			return false;
		}
		if (++_it == _end)
		{
			return false;
		}
		_previous = _token;
		_token = cast<token_a<>>(*_it);
		if (_token.tag() == "error")
		{
			throw dis("strange::parser tokenizer error:") + _token.report_();
		}
		return true;
	}

	inline expression_a<> _initial(
		int64_t const min_precedence,
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		expression_a<> initial = expression_t<>::create(_token);
		if (_token.tag() == "symbol" ||
			_token.tag() == "lake" ||
			_token.tag() == "int" ||
			_token.tag() == "float")
		{
			// literal
			initial = expression_literal_t<>::create_(_token, flock_t<>::create_(_token.literal_()));
			_next();
		}
		else if (_token.tag() == "name")
		{
			std::string const name = _token.symbol();
			if (name.c_str()[name.length() - 1] == '_')
			{
				initial = _initial_attribute(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			else if (name.c_str()[0] == '_')
			{
				initial = _initial_intimate(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			else if (name == "true")
			{
				_next();
				initial = expression_literal_t<>::create_(_token, flock_t<>::create_(yes()));
			}
			else if (name == "false" || name == "null")
			{
				_next();
				initial = expression_literal_t<>::create_(_token, flock_t<>::create_(no()));
			}
			else if (_shared.has_string(name + "!"))
			{
				initial = _initial_instruction(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			else
			{
				initial = _initial_local(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
		}
		else if (_token.tag() == "punctuation")
		{
			auto const token = _token;
			std::string const op = token.symbol();
			if (op == "$") // shared local
			{
				initial = _initial_local(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			else if (op == "$$") // shared scope
			{
				initial = _shared_scope(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			else if (op == "^^") // shoal scope
			{
				initial = expression_shared_scope_t<>::create_(token, flock_t<>::create_(_shared, shoal_symbol));
			}
			else if (op == "^") // me
			{
				if (_next() && _token.tag() == "punctuation")
				{
					if (_token.symbol() == ".") // me dot
					{
						initial = _initial_me_dot(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
					}
					else if (_token.symbol() == ":.") // me colon-dot
					{
						initial = _initial_me_colon_dot(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
					}
				}
				else
				{
					initial = expression_me_t<>::create_(token); // me
				}
			}
			else if (token.symbol() == "[") // flock
			{
				initial = expression_flock_t<>::create_(token, _elements(shoal_symbol, scope_symbol, fixed_herd, kind_shoal));
			}
			else if (token.symbol() == "(") // block
			{
				initial = expression_block_t<>::create_(token, _elements(shoal_symbol, scope_symbol, fixed_herd, kind_shoal));
			}
			else if (token.symbol() == "{") // shoal or herd
			{
				initial = _initial_shoal_or_herd(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			else if (token.symbol() == "<") // kind
			{
				initial = _kind(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			else
			{
				throw dis("strange::parser unexpected punctuation:") + token.report_();
			}
		}
		else
		{
			throw dis("strange::parser unexpected token tag:") + _token.report_();
		}
		return _subsequent(min_precedence, initial, shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
	}

	inline expression_a<> _initial_me_dot(
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token;
		if (!_next())
		{
			throw dis("strange::parser ^. with nothing following it:") + token.report_();
		}
		if (_token.tag() != "name")
		{
			throw dis("strange::parser ^. with non-name following it:") + token.report_();
		}
		auto const name_symbol = _token.symbol_();
		std::string const name = name_symbol.to_string();
		if (name.c_str()[name.length() - 1] == '_')
		{
			return _initial_attribute(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
		}
		if (name.c_str()[0] == '_')
		{
			return _initial_intimate(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
		}
		if (!_next())
		{
			throw dis("strange::parser ^. with no nothing following member name:") + token.report_();
		}
		auto terms = flock_t<>::create_(expression_me_t<>::create_(token)); // me
		if (_token.tag() == "punctuation" && _token.symbol() == "[")
		{
			terms.push_back_(expression_literal_t<>::create_(token, flock_t<>::create_(name_symbol)));
			terms += _elements(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			return expression_invoke_t<>::create_(token, terms);
		}
		terms.push_back_(name_symbol);
		terms.push_back_(_initial(100, shoal_symbol, scope_symbol, fixed_herd, kind_shoal));
		return expression_invoke_member_range_t<>::create_(token, terms);
	}

	inline expression_a<> _initial_me_colon_dot(
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token;
		if (!_next())
		{
			throw dis("strange::parser ^:. with nothing following it:") + token.report_();
		}
		if (_token.tag() != "name")
		{
			throw dis("strange::parser ^:. with non-name following it:") + token.report_();
		}
		auto const name_symbol = _token.symbol_();
		std::string const name = name_symbol.to_string();
		if (name.c_str()[name.length() - 1] == '_')
		{
			throw dis("strange::parser ^:. with attribute name following it:") + token.report_();
		}
		else if (name.c_str()[0] == '_')
		{
			_next();
			auto const terms = flock_t<>::create_(
				expression_me_t<>::create_(token),
				_identifier(scope_symbol, name_symbol)); // me:._name / me:._scope_name
			return expression_intimate_member_t<>::create_(token, terms);
		}
		_next();
		auto const terms = flock_t<>::create_(
			expression_me_t<>::create_(token),
			name_symbol); // me:.name
		return expression_member_t<>::create_(token, terms);
	}

	inline expression_a<> _initial_attribute(
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token;
		auto const name = token.symbol_();
		auto terms = flock_t<>::create_(_identifier(scope_symbol, name)); // _name_ / _scope_name_
		if (_next() && _token.tag() == "punctuation" &&
			(_token.symbol() == ":=" || _token.symbol() == ":" || _token.symbol() == ":<"))
		{
			bool optional = true;
			if (_token.symbol() == ":=")
			{
				_next();
				terms.push_back(kind_t<>::create_());
			}
			else
			{
				try
				{
					auto const kind = cast<kind_a<>>(_kind(shoal_symbol, scope_symbol, fixed_herd, kind_shoal).evaluate_());
					optional = kind.optional();
					terms.push_back(kind);
				}
				catch (misunderstanding_a<>& misunderstanding)
				{
					throw dis("strange::parser attribute assignment kind evaluation error:") + token.report_() + misunderstanding;
				}
			}
			if (optional)
			{
				if (_it == _end)
				{
					throw dis("strange::parser attribute assignment with nothing following it:") + token.report_();
				}
				terms.push_back_(_initial(0, shoal_symbol, scope_symbol, fixed_herd, kind_shoal)); // assignment
			}
		}
		return expression_intimate_attribute_t<>::create_(token, terms); //TODO pass kind expression?
	}

	inline expression_a<> _initial_intimate(
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token;
		auto terms = flock_t<>::create_(expression_me_t<>::create_(token)); // me
		auto const identifier = _identifier(scope_symbol, token.symbol_()); // _name / _scope_name
		if (!_next())
		{
			throw dis("strange::parser intimate operation with no arguments:") + token.report_();
		}
		if (_token.tag() == "punctuation" && _token.symbol() == "[")
		{
			terms.push_back_(expression_literal_t<>::create_(token, flock_t<>::create_(identifier)));
			terms += _elements(shoal_symbol, scope_symbol, fixed_herd, kind_shoal); // me._scope_name[...]
			return expression_intimate_t<>::create_(token, terms);
		}
		terms.push_back_(identifier);
		terms.push_back_(_initial(100, shoal_symbol, scope_symbol, fixed_herd, kind_shoal)); // me._scope_name range
		return expression_intimate_member_range_t<>::create_(token, terms);
	}

	static inline symbol_a<> _identifier(
		symbol_a<> const& scope_symbol,
		symbol_a<> const& name)
	{
		// name / _scope_name
		return (scope_symbol.is("") || name.to_string().c_str()[0] != '_')
			? name
			: sym("_" + scope_symbol.to_string() + name.to_string());
	}

	static inline symbol_a<> _scope_name(
		symbol_a<> const& scope_symbol,
		symbol_a<> const& name)
	{
		// name / scope::name
		return scope_symbol.is("")
			? name
			: sym(scope_symbol.to_string() + "::" + name.to_string());
	}

	inline expression_a<> _initial_instruction(
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token;
		auto const instruction = _shared.at_string(token.symbol() + "!");
		if (!instruction)
		{
			throw dis("strange::parser instruction not recognised:") + token.report_();
		}
		if (!_next())
		{
			throw dis("strange::parser instruction with no arguments:") + token.report_();
		}
		if (_token.tag() == "punctuation" && _token.symbol() == "(")
		{
			auto const expression = instruction.operate(no(),
				flock_t<>::create_(token, _elements(shoal_symbol, scope_symbol, fixed_herd, kind_shoal)));
			if (!check<expression_a<>>(expression))
			{
				throw dis("strange::parser instruction returned non-expression:") + token.report_();
			}
			return cast<expression_a<>>(expression);
		}
		throw dis("strange::parser instruction with no arguments:") + token.report_();
	}

	inline expression_a<> _initial_local(
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		bool const shared = _token.tag() == "punctuation";
		if (shared && !_next())
		{
			throw dis("strange::parser $ with nothing following it:") + _token.report_();
		}
		auto const token = _token;
		auto const name = _token.symbol_();
		bool fixed = fixed_herd.has(name);
		auto kind = kind_shoal.at_(name);
		bool insert = false;
		bool update = false;
		bool optional = true;
		if (_next() && _token.tag() == "punctuation")
		{
			auto const op = _token.symbol();
			if (kind)
			{
				if (op == ":=")
				{
					if (fixed)
					{
						throw dis("strange::parser cannot reassign fixed variable:") + _token.report_();
					}
					update = true;
				}
				else if (op == ":#")
				{
					throw dis("strange::parser cannot reassign variable with fixed:") + _token.report_();
				}
				else if (op == ":<" || op == ":{")
				{
					throw dis("strange::parser cannot reassign variable kind:") + _token.report_();
				}
			}
			else if (fixed)
			{
				throw dis("strange::parser recursive variable definition:") + _token.report_();
			}
			else
			{
				kind = kind_t<>::create_();
				if (op == ":=")
				{
					fixed = false;
					insert = true;
				}
				else if (op == ":#")
				{
					fixed = true;
					insert = true;
				}
				else if (op == ":" || op == ":<" || op == ":{")
				{
					auto const kind_expression = _kind(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
					bool const punctuation = _previous.tag() == "punctuation";
					fixed = punctuation && _previous.symbol() == "#";
					optional = fixed || punctuation && _previous.symbol() == "=";
					insert = true;
					try
					{
						kind = kind_expression.evaluate_();
					}
					catch (misunderstanding_a<>&)
					{
						throw dis("strange::parser kind expression not yet implemented here:") + _token.report_(); //TODO
					}
				}
			}
		}
		if (insert || update)
		{
			if (!_next())
			{
				throw dis("strange::parser local assignment with no right-hand side:") + token.report_();
			}
			unordered_herd_a<>(fixed_herd, true).insert(name);
			any_a<> const rhs = optional
				? _initial(0, shoal_symbol, scope_symbol, fixed_herd, kind_shoal)
				: no();
			if (!fixed)
			{
				unordered_herd_a<>(fixed_herd, true).erase(name);
			}
			//TODO pass kind expression below?
			if (insert)
			{
				unordered_shoal_a<>(kind_shoal, true).insert_(name, kind);
				if (optional)
				{
					if (shared)
					{
						return expression_shared_insert_t<>::create_(token, flock_t<>::create_(name, kind, rhs));
					}
					return expression_local_insert_t<>::create_(token, flock_t<>::create_(name, kind, rhs));
				}
				else
				{
					if (shared)
					{
						return expression_shared_insert_t<>::create_(token, flock_t<>::create_(name, kind));
					}
					return expression_local_insert_t<>::create_(token, flock_t<>::create_(name, kind));
				}
			}
			if (update)
			{
				if (shared)
				{
					return expression_shared_update_t<>::create_(token, flock_t<>::create_(name, kind, rhs));
				}
				return expression_local_update_t<>::create_(token, flock_t<>::create_(name, kind, rhs));
			}
		}
		if (shared)
		{
			return expression_shared_at_t<>::create_(token, flock_t<>::create_(name));
		}
		return expression_local_at_t<>::create_(token, flock_t<>::create_(name));
	}

	inline expression_a<> _shared_scope(
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		if (!_next())
		{
			throw dis("strange::parser $$ with nothing following it:") + _token.report_();
		}
		auto const token = _token;
		if (token.tag() == "punctuation" && token.symbol() == "<")
		{
			try
			{
				return expression_shared_scope_t<>::create_(token, flock_t<>::create_(_shared, _kind(shoal_symbol, scope_symbol, fixed_herd, kind_shoal).evaluate_()));
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::parser shared scope kind evaluation error:") + token.report_() + misunderstanding;
			}
		}
		else if (token.tag() == "name")
		{
			return expression_shared_scope_t<>::create_(token, flock_t<>::create_(_shared, _scope()));
		}
		else
		{
			throw dis("strange::parser $$ with invalid token following it:") + _token.report_();
		}
	}

	inline symbol_a<> _scope()
	{
		std::string scope;
		for (bool first = true;;first = false)
		{
			if (_token.tag() != "name")
			{
				if (first)
				{
					break;
				}
				throw dis("strange::parser :: with non-name following it:") + _token.report_();
			}
			scope += _token.symbol();
			if (!_next() || _token.tag() != "punctuation" || _token.symbol() != "::")
			{
				break;
			}
			scope += "::";
			if (!_next())
			{
				throw dis("strange::parser :: with nothing following it:") + _token.report_();
			}
		}
		return sym(scope);
	}

	inline expression_a<> _initial_shoal_or_herd(
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token;
		if (!_next())
		{
			throw dis("strange::parser { with nothing following it:") + token.report_();
		}
		auto flock = flock_t<>::create_();
		bool herd = false;
		bool shoal = false;
		auto key = expression_t<>::create(token);
		if (_token.tag() == "punctuation" &&
			(_token.symbol() == "}" || _token.symbol() == "!"))
		{
			if (_token.symbol() == "!")
			{
				if (!_next() || _token.symbol() != "}")
				{
					throw dis("strange::parser {! without } immediately following it:") + token.report_();
				}
				herd = true;
			}
			_next();
		}
		else for (;;)
		{
			if (_token.tag() == "name")
			{
				key = expression_literal_t<>::create_(_token, flock_t<>::create_(_token.symbol_()));
				_next();
			}
			else
			{
				key = _initial(0, scope_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			if (_it == _end)
			{
				if (shoal)
				{
					throw dis("strange::parser shoal key with nothing following it:") + _token.report_();
				}
				throw dis("strange::parser element with nothing following it:") + _token.report_();
			}
			if (_token.tag() != "punctuation")
			{
				if (shoal)
				{
					throw dis("strange::parser shoal key with non-punctuation following it:") + _token.report_();
				}
				throw dis("strange::parser element with non-punctuation following it:") + _token.report_();
			}
			bool comma = _token.symbol() == ",";
			if (comma)
			{
				if (shoal)
				{
					throw dis("strange::parser shoal key without a corresponding value:") + _token.report_();
				}
				if (!_next())
				{
					throw dis("strange::parser , with nothing following it:") + _token.report_();
				}
			}
			if (_token.symbol() == "}")
			{
				if (shoal)
				{
					throw dis("strange::parser shoal key without a corresponding value:") + _token.report_();
				}
				_next();
				herd = true;
				flock.push_back(key);
				break;
			}
			if (comma)
			{
				herd = true;
				flock.push_back(key);
				continue;
			}
			if (herd)
			{
				throw dis("strange::parser herd element with unexpected punctuation following it:") + _token.report_();
			}
			shoal = true;
			auto const operator_token = _token;
			if (!_next())
			{
				throw dis("strange::parser shoal " + operator_token.symbol() + " with nothing following it:") + operator_token.report_();
			}
			auto key_symbol = no();
			try
			{
				key_symbol = key.evaluate_();
			}
			catch (misunderstanding_a<>&)
			{}
			auto const new_scope_symbol = _scope_name(scope_symbol,
				check<symbol_a<>>(key_symbol) ? cast<symbol_a<>>(key_symbol) : sym("#"));

			auto value = expression_t<>::create(operator_token);
			if (operator_token.symbol() == ":")
			{
				// regular key/value pair
				value = _initial(0, scope_symbol, new_scope_symbol, fixed_herd, kind_shoal);
			}
			else if (operator_token.symbol() == "::")
			{
				// shared scope
				value = _initial(0, scope_symbol, new_scope_symbol, unordered_herd_t<>::create_(), unordered_shoal_t<>::create_());
				bool clash = false;
				try
				{
					clash = !_shared.insert(new_scope_symbol, value.evaluate_());
				}
				catch (misunderstanding_a<>& misunderstanding)
				{
					throw dis("strange::parser shoal :: value evaluation error:") + _token.report_() + misunderstanding;
				}
				if (clash)
				{
					throw dis("strange::parser shoal :: redefinition of shared name:") + _token.report_();
				}
			}
			else if (operator_token.symbol() == ":#" || operator_token.symbol() == ":=") //TODO :kind=
			{
				bool const fixed = (operator_token.symbol() == ":#");
				auto const key_string = cast<symbol_a<>>(key_symbol).to_string();
				if (key_string[key_string.length() - 1] == '_')
				{
					// attribute extraction/mutation
					auto const terms = flock_t<>::create_(key_symbol, kind_t<>::create_(), _initial(0, scope_symbol, new_scope_symbol, unordered_herd_t<>::create_(), unordered_shoal_t<>::create_()));
					if (fixed)
					{
						value = expression_attribute_extraction_t<>::create_(operator_token, terms);
					}
					else
					{
						value = expression_attribute_mutation_t<>::create_(operator_token, terms);
					}
				}
				else
				{
					// extraction/mutation
					if (_token.tag() != "punctuation" || _token.symbol() != "(")
					{
						throw dis("strange::parser shoal " + operator_token.symbol() + " without ( following it:") + _token.report_();
					}
					auto const terms = _elements(scope_symbol, new_scope_symbol, unordered_herd_t<>::create_(), unordered_shoal_t<>::create_());
					if (fixed)
					{
						value = expression_extraction_t<>::create_(operator_token, terms);
					}
					else
					{
						value = expression_mutation_t<>::create_(operator_token, terms);
					}
				}
			}
			else
			{
				throw dis("strange::parser shoal key with unexpected punctuation following it:") + _token.report_();
			}
			if (_it == _end)
			{
				throw dis("strange::parser shoal value with nothing following it:") + _token.report_();
			}
			if (_token.tag() != "punctuation")
			{
				throw dis("strange::parser shoal value with non-punctuation following it:") + _token.report_();
			}
			flock.push_back(expression_flock_t<>::create_(operator_token, flock_t<>::create_(key, value)));
			comma = _token.symbol() == ",";
			if (comma && !_next())
			{
				throw dis("strange::parser shoal , with nothing following it:") + _token.report_();
			}
			if (_token.symbol() == "}")
			{
				_next();
				break;
			}
			if (!comma)
			{
				throw dis("strange::parser shoal value with unexpected punctuation following it:") + _token.report_();
			}
		}
		if (herd)
		{
			return expression_herd_t<>::create_(token, flock);
		}
		return expression_shoal_t<>::create_(token, flock);
	}

	inline expression_a<> _kind(
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token;
		bool const punctuation = token.tag() == "punctuation";
		bool modify = punctuation && token.symbol() == ":";
		auto expression = no();
		if (modify)
		{
			if (!_next())
			{
				throw dis("strange::parser kind : with nothing following it:") + token.report_();
			}
			expression = _initial(100, shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
		}
		bool const variant = punctuation && token.symbol() == ":{";
		if (variant)
		{
			throw dis("strange::parser variants not yet implemented:") + token.report_(); //TODO variants
		}
		bool const colon = modify || variant || punctuation && token.symbol() == ":<";
		auto terms = flock_t<>::create_();

		// order
		int64_t order = 0;
		if (!modify)
		{
			while (!order && colon ||
				_token.tag() == "punctuation" && _token.symbol() == "<")
			{
				++order;
				if (!_next())
				{
					throw dis("strange::parser kind < with nothing following it:") + token.report_();
				}
			}
		}
		terms.push_back(number_int_64_t<>::create(order));

		// name
		bool const name = !modify && _token.tag() == "name";
		if (name)
		{
			if (_token.symbol().c_str()[_token.symbol().length() - 1] == '_')
			{
				modify = true;
				expression = _initial(100, shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
				terms.push_back(sym(""));
			}
			else
			{
				terms.push_back(_scope());
			}
			if (_it == _end)
			{
				throw dis("strange::parser kind name with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(sym(""));
		}

		// dimensions
		bool const dimensions = !modify && _token.tag() == "punctuation" && _token.symbol() == "{";
		if (dimensions)
		{
			terms.push_back(expression_flock_t<>::create_(token, _elements(shoal_symbol, scope_symbol, fixed_herd, kind_shoal)));
			if (_it == _end)
			{
				throw dis("strange::parser kind } with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(expression_flock_t<>::create(token));
		}

		// aspects
		bool const aspects = !modify && _token.tag() == "punctuation" && _token.symbol() == "[";
		if (aspects)
		{
			terms.push_back(expression_flock_t<>::create_(token, _elements(shoal_symbol, scope_symbol, fixed_herd, kind_shoal)));
			if (_it == _end)
			{
				throw dis("strange::parser kind ] with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(expression_flock_t<>::create(token));
		}

		// paramters
		bool const parameters = !modify && _token.tag() == "punctuation" && _token.symbol() == "(";
		if (parameters)
		{
			terms.push_back(expression_flock_t<>::create_(token, _elements(shoal_symbol, scope_symbol, fixed_herd, kind_shoal)));
			if (_it == _end)
			{
				throw dis("strange::parser kind ) with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(expression_flock_t<>::create(token));
		}

		// result
		bool const result = !modify && _token.tag() == "punctuation" && (_token.symbol() == ":" || _token.symbol() == ":<");
		if (result)
		{
			terms.push_back(_kind(shoal_symbol, scope_symbol, fixed_herd, kind_shoal)); // recurse for result
			if (_it == _end)
			{
				throw dis("strange::parser kind result with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(expression_kind_t<>::create(_token, flock_t<>::create_()));
		}

		// close
		while (order && _it != _end && _token.tag() == "punctuation" && _token.symbol() == ">")
		{
			_next();
			--order;
		}
		if (order)
		{
			throw dis("strange::parser mismatched kind < and > pair:") + token.report_();
		}

		// reference
		bool const reference = _it != _end && _token.tag() == "punctuation" && _token.symbol() == "&";
		if (reference)
		{
			terms.push_back(yes());
			_next();
		}
		else
		{
			terms.push_back(no());
		}

		// optional
		if (colon && _it != _end && _token.tag() == "punctuation" &&
			(_token.symbol() == "#" || _token.symbol() == "="))
		{
			terms.push_back(yes());
			_next();
		}
		else if (modify)
		{
			terms.push_back(no());
		}
		else if (!reference)
		{
			// remove redundant terms
			terms.pop_back_();
			if (!result)
			{
				terms.pop_back_();
				if (!parameters)
				{
					terms.pop_back_();
					if (!aspects)
					{
						terms.pop_back_();
						if (!dimensions)
						{
							terms.pop_back_();
							if (!name)
							{
								terms.pop_back_();
							}
						}
					}
				}
			}
		}

		// expression
		if (modify)
		{
			terms.push_back(expression);
		}

		return expression_kind_t<>::create_(token, terms);
	}
	
	inline expression_a<> _subsequent(
		int64_t const min_precedence,
		expression_a<> const& initial,
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		if (min_precedence >= 100 || _it == _end)
		{
			return initial;
		}
		auto const token = _token;
		if (token.tag() == "punctuation")
		{
			auto const op = token.symbol();
			if (op == "[")
			{
				// operate with elements
				auto terms = flock_t<>::create_(initial);
				terms += _elements(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
				return _subsequent(min_precedence, expression_operate_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			if (op == ".")
			{
				// invoke member
				if (!_next())
				{
					throw dis("strange::parser . with nothing following it:") + token.report_();
				}
				return _subsequent_dot(min_precedence, initial, shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			if (op == ".:")
			{
				// operate
				if (!_next())
				{
					throw dis("strange::parser .: with nothing following it:") + token.report_();
				}
				return _subsequent_dot_colon(min_precedence, initial, shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			if (op == ":.")
			{
				// member
				if (!_next())
				{
					throw dis("strange::parser :. with nothing following it:") + token.report_();
				}
				return _subsequent_colon_dot(min_precedence, initial, shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			}
			if (op == "," || op == ":" || op == "::" || op == ":#" || op == ":=" || op == ":<" || op == ":{" || op == ";" || op == "]" || op == "}" || op == ")")
			{
				// delimiter
				return initial;
			}
			int64_t const precedence = token.precedence();
			if (precedence)
			{
				// operator
				if (precedence < min_precedence)
				{
					return initial;
				}
				if (op == "&&" || op == "!&" || op == "%%" || op == "!%" || op == "||" || op == "!|")
				{
					// logic operator
					if (!_next())
					{
						throw dis("strange::parser logic operator with nothing following it:") + token.report_();
					}
					auto const terms = flock_t<>::create_(
						initial,
						_initial(precedence + 1, shoal_symbol, scope_symbol, fixed_herd, kind_shoal));
					if (op == "&&")
					{
						return _subsequent(min_precedence, expression_and_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
					}
					if (op == "!&")
					{
						return _subsequent(min_precedence, expression_nand_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
					}
					if (op == "%%")
					{
						return _subsequent(min_precedence, expression_xor_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
					}
					if (op == "!%")
					{
						return _subsequent(min_precedence, expression_xnor_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
					}
					if (op == "||")
					{
						return _subsequent(min_precedence, expression_or_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
					}
					if (op == "!|")
					{
						return _subsequent(min_precedence, expression_nor_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
					}
				}
				auto oper = sym("");
				int64_t count = 2;
				bool right_to_left = false;
				if (op == "@?")
				{
					oper = sym("has");
				}
				else if (op == "@")
				{
					oper = sym("at");
				}
				else if (op == "@=")
				{
					oper = sym("update");
					count = 3;
				}
				else if (op == "@+")
				{
					oper = sym("insert");
					count = 3;
				}
				else if (op == "@-")
				{
					oper = sym("erase");
				}
				else if (op == "@<")
				{
					oper = sym("push_back");
				}
				else if (op == ">@")
				{
					oper = sym("push_front");
				}
				else if (op == "@>")
				{
					oper = sym("pop_back");
					count = 1;
				}
				else if (op == "<@")
				{
					oper = sym("pop_front");
					count = 1;
				}
				else if (op == "++")
				{
					oper = sym("increment");
					count = 1;
				}
				else if (op == "--")
				{
					oper = sym("decrement");
					count = 1;
				}
				else if (op == "?")
				{
					oper = sym("something");
					count = 1;
				}
				else if (op == "!")
				{
					oper = sym("nothing");
					count = 1;
				}
				else if (op == "*")
				{
					oper = sym("multiply");
				}
				else if (op == "/")
				{
					oper = sym("divide");
				}
				else if (op == "%")
				{
					oper = sym("modulo");
				}
				else if (op == "+")
				{
					oper = sym("add");
				}
				else if (op == "-")
				{
					oper = sym("subtract");
				}
				else if (op == "<")
				{
					oper = sym("less_than");
				}
				else if (op == ">")
				{
					oper = sym("greater_than");
				}
				else if (op == "<=")
				{
					oper = sym("less_or_equal");
				}
				else if (op == ">=")
				{
					oper = sym("greater_or_equal");
				}
				else if (op == "==")
				{
					oper = sym("same");
				}
				else if (op == "!=")
				{
					oper = sym("different");
				}
				else if (op == "=")
				{
					oper = sym("self_assign");
					right_to_left = true;
				}
				else if (op == "*=")
				{
					oper = sym("self_multiply");
					right_to_left = true;
				}
				else if (op == "/=")
				{
					oper = sym("self_divide");
					right_to_left = true;
				}
				else if (op == "%=")
				{
					oper = sym("self_modulo");
					right_to_left = true;
				}
				else if (op == "+=")
				{
					oper = sym("self_add");
					right_to_left = true;
				}
				else if (op == "-=")
				{
					oper = sym("self_subtract");
					right_to_left = true;
				}
				else
				{
					throw dis("strange::parser unexpected operator:") + token.report_();
				}
				if (count == 1)
				{
					// invoke unary operator
					_next();
					auto const terms = flock_t<>::create_(initial, expression_literal_t<>::create_(token, flock_t<>::create_(oper)));
					return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
				}
				else if (count == 2)
				{
					// invoke binary operator
					if (!_next())
					{
						throw dis("strange::parser binary operator with nothing following it:") + token.report_();
					}
					auto const terms = flock_t<>::create_(
						initial,
						expression_literal_t<>::create_(token, flock_t<>::create_(oper)),
						_initial(precedence + (right_to_left ? 0 : 1), shoal_symbol, scope_symbol, fixed_herd, kind_shoal));
					return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
				}
				else if (count == 3)
				{
					// invoke ternary operator
					if (!_next())
					{
						throw dis("strange::parser ternary operator with nothing following it:") + token.report_();
					}
					auto const second = _initial(precedence + (right_to_left ? 0 : 1), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
					if (!_next() || _token.tag() != "punctuation" || _token.symbol() != ":")
					{
						auto const terms = flock_t<>::create_(
							initial,
							expression_literal_t<>::create_(token, flock_t<>::create_(oper)),
							second);
						return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
					}
					if (!_next())
					{
						throw dis("strange::parser ternary operator with nothing following the delimiter:") + token.report_();
					}
					auto const terms = flock_t<>::create_(
						initial,
						expression_literal_t<>::create_(token, flock_t<>::create_(oper)),
						second,
						_initial(precedence + (right_to_left ? 0 : 1), shoal_symbol, scope_symbol, fixed_herd, kind_shoal));
					return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
				}
				assert(count >= 1 && count <= 3);
			}
		}
		// operate with range
		auto const terms = flock_t<>::create_(initial, _initial(100, shoal_symbol, scope_symbol, fixed_herd, kind_shoal));
		return _subsequent(min_precedence, expression_operate_range_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
	}

	inline flock_a<> _elements(
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		bool const square = _token.symbol() == "[";
		bool const round = _token.symbol() == "(";
		bool const curly = _token.symbol() == "{";
		auto new_fixed_herd = fixed_herd;
		auto new_kind_shoal = kind_shoal;
		if (round || curly)
		{
			new_fixed_herd.mutate_thing();
			new_kind_shoal.mutate_thing();
		}
		if (!_next())
		{
			throw dis("strange::parser " + _token.symbol() + " with nothing following it:") + _token.report_();
		}
		auto flock = flock_t<>::create_();
		if (_token.tag() == "punctuation" &&
			(square && _token.symbol() == "]" ||
				round && _token.symbol() == ")" ||
				curly && _token.symbol() == "}"))
		{
			_next();
		}
		else for (;;)
		{
			flock.push_back(_initial(0, shoal_symbol, scope_symbol, new_fixed_herd, new_kind_shoal));
			if (_it == _end)
			{
				throw dis("strange::parser element with nothing following it:") + _token.report_();
			}
			if (_token.tag() != "punctuation")
			{
				throw dis("strange::parser element with non-punctuation following it:") + _token.report_();
			}
			bool const comma = _token.symbol() == ",";
			if (comma && !_next())
			{
				throw dis("strange::parser , with nothing following it:") + _token.report_();
			}
			if (square && _token.symbol() == "]" ||
				round && _token.symbol() == ")" ||
				curly && _token.symbol() == "}")
			{
				_next();
				break;
			}
			if (!comma)
			{
				throw dis("strange::parser element with unexpected punctuation following it:") + _token.report_();
			}
		}
		return flock;
	}

	inline expression_a<> _subsequent_dot(
		int64_t const min_precedence,
		expression_a<> const& initial,
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token;
		if (token.tag() != "name")
		{
			throw dis("strange::parser . with non-name following it:") + token.report_();
		}
		auto terms = flock_t<>::create_(initial);
		if (token.symbol().c_str()[token.symbol().length() - 1] == '_')
		{
			// attribute
			terms.push_back_(token.symbol_());
			if (_next() && _token.tag() == "punctuation" && _token.symbol() == ":=")
			{
				if (!_next())
				{
					throw dis("strange::parser attribute assignment with nothing following it:") + token.report_();
				}
				terms.push_back_(_initial(0, shoal_symbol, scope_symbol, fixed_herd, kind_shoal)); // assignment
			}
			return _subsequent(min_precedence, expression_invoke_attribute_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
		}
		if (!_next())
		{
			throw dis("strange::parser . with nothing following member name:") + token.report_();
		}
		if (_token.tag() == "punctuation" && _token.symbol() == "[")
		{
			terms.push_back_(expression_literal_t<>::create_(token, flock_t<>::create_(token.symbol_())));
			terms += _elements(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
		}
		terms.push_back_(token.symbol_());
		terms.push_back_(_initial(100, shoal_symbol, scope_symbol, fixed_herd, kind_shoal));
		return _subsequent(min_precedence, expression_invoke_member_range_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
	}

	inline expression_a<> _subsequent_dot_colon(
		int64_t const min_precedence,
		expression_a<> const& initial,
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token;
		auto second = _initial(100, shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
		if (_it != _end && _token.tag() == "punctuation" && _token.symbol() == ":.")
		{
			// member
			if (!_next())
			{
				throw dis("strange::parser :. with nothing following it:") + token.report_();
			}
			second = _subsequent_colon_dot(100, second, shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
		}
		auto terms = flock_t<>::create_(initial, second);
		if (!_next())
		{
			throw dis("strange::parser .: with nothing following its operation:") + token.report_();
		}
		if (_token.tag() == "punctuation" && _token.symbol() == "[")
		{
			terms += _elements(shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
			return _subsequent(min_precedence, expression_operate_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
		}
		terms.push_back_(_initial(100, shoal_symbol, scope_symbol, fixed_herd, kind_shoal));
		return _subsequent(min_precedence, expression_operate_range_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
	}

	inline expression_a<> _subsequent_colon_dot(
		int64_t const min_precedence,
		expression_a<> const& initial,
		symbol_a<> const& shoal_symbol,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token;
		if (token.tag() != "name")
		{
			throw dis("strange::parser :. with non-name following it:") + token.report_();
		}
		_next();
		auto const terms = flock_t<>::create_(initial, token.symbol_());
		return _subsequent(min_precedence, expression_member_t<>::create_(token, terms), shoal_symbol, scope_symbol, fixed_herd, kind_shoal);
	}

	static bool const ___share___;
	friend class ___parser_t_share___;
};

template <typename ___ego___>
bool const parser_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	parser_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
