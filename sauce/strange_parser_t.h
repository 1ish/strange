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
		_tokenizer_ = tokenizer;
		_it_ = _tokenizer_.cbegin_();
		_end_ = _tokenizer_.cend_();
		if (_it_ == _end_)
		{
			return expression_t<>::create(token_t<>::create_punctuation_());
		}
		_token_ = cast<token_a<>>(*_it_);
		if (_token_.tag() == "error")
		{
			throw dis("strange::parser tokenizer error:") + _token_.report_();
		}
		return _initial(0, sym(""), unordered_herd_t<>::create_(), unordered_shoal_t<>::create_());
	}

protected:
	inline parser_t()
		: thing_t{}
		, _shared_{ unordered_shoal_t<>::create_() }
		, _tokenizer_{ tokenizer_t<>::create_(river_t<>::create_()) }
		, _it_{ _tokenizer_.cbegin_() }
		, _end_{ _tokenizer_.cend_() }
		, _token_{ token_t<>::create_punctuation_() }
	{
		_shared_ += shared();
	}

private:
	unordered_shoal_a<> _shared_;
	range_a<> _tokenizer_;
	forward_const_iterator_a<> _it_;
	forward_const_iterator_a<> _end_;
	token_a<> _token_;

	inline bool _next()
	{
		if (_it_ == _end_)
		{
			return false;
		}
		if (++_it_ == _end_)
		{
			return false;
		}
		_token_ = cast<token_a<>>(*_it_);
		if (_token_.tag() == "error")
		{
			throw dis("strange::parser tokenizer error:") + _token_.report_();
		}
		return true;
	}

	inline expression_a<> _initial(
		int64_t const min_precedence,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		expression_a<> initial = expression_t<>::create(_token_);
		if (_token_.tag() == "symbol" ||
			_token_.tag() == "lake" ||
			_token_.tag() == "int" ||
			_token_.tag() == "float")
		{
			// literal
			initial = expression_literal_t<>::create_(_token_, flock_t<>::create_(_token_.literal_()));
			_next();
		}
		else if (_token_.tag() == "name")
		{
			std::string const name = _token_.symbol();
			if (name.c_str()[name.length() - 1] == '_')
			{
				initial = _initial_attribute(scope_symbol, fixed_herd, kind_shoal);
			}
			else if (name.c_str()[0] == '_')
			{
				initial = _initial_intimate(scope_symbol, fixed_herd, kind_shoal);
			}
			else if (name == "true")
			{
				_next();
				initial = expression_literal_t<>::create_(_token_, flock_t<>::create_(yes()));
			}
			else if (name == "false" || name == "null")
			{
				_next();
				initial = expression_literal_t<>::create_(_token_, flock_t<>::create_(no()));
			}
			else if (_shared_.has_string(name + "!"))
			{
				initial = _initial_instruction(scope_symbol, fixed_herd, kind_shoal);
			}
			else
			{
				initial = _initial_local(false, scope_symbol, fixed_herd, kind_shoal);
			}
		}
		else if (_token_.tag() == "punctuation")
		{
			auto const token = _token_;
			std::string const op = token.symbol();
			if (op == "$") // shared local
			{
				if (!_next())
				{
					throw dis("strange::parser $ with nothing following it:") + token.report_();
				}
				initial = _initial_local(true, scope_symbol, fixed_herd, kind_shoal);
			}
			else if (op == "$$") // shared scope
			{
				if (!_next())
				{
					throw dis("strange::parser $$ with nothing following it:") + token.report_();
				}
				initial = expression_shared_scope_t<>::create_(token, flock_t<>::create_(_shared_, _scope()));
			}
			else if (op == "^") // me
			{
				if (_next() && _token_.tag() == "punctuation")
				{
					if (_token_.symbol() == ".") // me dot
					{
						initial = _initial_me_dot(scope_symbol, fixed_herd, kind_shoal);
					}
					else if (_token_.symbol() == ":.") // me colon-dot
					{
						initial = _initial_me_colon_dot(scope_symbol, fixed_herd, kind_shoal);
					}
				}
				else
				{
					initial = expression_me_t<>::create_(token); // me
				}
			}
			else if (token.symbol() == "[") // flock
			{
				initial = expression_flock_t<>::create_(token, _elements(scope_symbol, fixed_herd, kind_shoal));
			}
			else if (token.symbol() == "(") // block
			{
				initial = expression_block_t<>::create_(token, _elements(scope_symbol, fixed_herd, kind_shoal));
			}
			else if (token.symbol() == "{") // shoal or herd
			{
				initial = _initial_shoal_or_herd(scope_symbol, fixed_herd, kind_shoal);
			}
			else if (token.symbol() == "<") // kind
			{
				initial = _initial_kind(scope_symbol, fixed_herd, kind_shoal);
			}
			//TODO ...
			else
			{
				throw dis("strange::parser unexpected punctuation:") + token.report_();
			}
		}
		else
		{
			throw dis("strange::parser unexpected token tag:") + _token_.report_();
		}
		return _subsequent(min_precedence, initial, scope_symbol, fixed_herd, kind_shoal);
	}

	inline expression_a<> _initial_me_dot(
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		if (!_next())
		{
			throw dis("strange::parser ^. with nothing following it:") + token.report_();
		}
		if (_token_.tag() != "name")
		{
			throw dis("strange::parser ^. with non-name following it:") + token.report_();
		}
		auto const name_symbol = _token_.symbol_();
		std::string const name = name_symbol.to_string();
		if (name.c_str()[name.length() - 1] == '_')
		{
			return _initial_attribute(scope_symbol, fixed_herd, kind_shoal);
		}
		if (name.c_str()[0] == '_')
		{
			return _initial_intimate(scope_symbol, fixed_herd, kind_shoal);
		}
		if (!_next())
		{
			throw dis("strange::parser ^. with no nothing following member name:") + token.report_();
		}
		auto terms = flock_t<>::create_(expression_me_t<>::create_(token)); // me
		if (_token_.tag() == "punctuation" && _token_.symbol() == "[")
		{
			terms.push_back_(expression_literal_t<>::create_(token, flock_t<>::create_(name_symbol)));
			terms += _elements(scope_symbol, fixed_herd, kind_shoal);
			return expression_invoke_t<>::create_(token, terms);
		}
		terms.push_back_(name_symbol);
		terms.push_back_(_initial(100, scope_symbol, fixed_herd, kind_shoal));
		return expression_invoke_member_range_t<>::create_(token, terms);
	}

	inline expression_a<> _initial_me_colon_dot(
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		if (!_next())
		{
			throw dis("strange::parser ^:. with nothing following it:") + token.report_();
		}
		if (_token_.tag() != "name")
		{
			throw dis("strange::parser ^:. with non-name following it:") + token.report_();
		}
		auto const name_symbol = _token_.symbol_();
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
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto const name = token.symbol_();
		auto terms = flock_t<>::create_(expression_me_t<>::create_(token)); // me
		terms.push_back_(_identifier(scope_symbol, name)); // _name_ / _scope_name_
		if (_next() && _token_.tag() == "punctuation" && _token_.symbol() == ":=") // consume
		{
			if (!_next())
			{
				throw dis("strange::parser attribute assignment with nothing following it:") + token.report_();
			}
			terms.push_back_(_initial(0, scope_symbol, fixed_herd, kind_shoal)); // assignment
		}
		return expression_intimate_attribute_t<>::create_(token, terms);
	}

	inline expression_a<> _initial_intimate(
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto terms = flock_t<>::create_(expression_me_t<>::create_(token)); // me
		auto const identifier = _identifier(scope_symbol, token.symbol_()); // _name / _scope_name
		if (!_next()) // consume
		{
			throw dis("strange::parser intimate operation with no arguments:") + token.report_();
		}
		if (_token_.tag() == "punctuation" && _token_.symbol() == "[")
		{
			terms.push_back_(expression_literal_t<>::create_(token, flock_t<>::create_(identifier)));
			terms += _elements(scope_symbol, fixed_herd, kind_shoal); // me._scope_name[...]
			return expression_intimate_t<>::create_(token, terms);
		}
		terms.push_back_(identifier);
		terms.push_back_(_initial(100, scope_symbol, fixed_herd, kind_shoal)); // me._scope_name range
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
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto const instruction = _shared_.at_string(token.symbol() + "!");
		if (!instruction)
		{
			throw dis("strange::parser instruction not recognised:") + token.report_();
		}
		if (!_next()) // consume
		{
			throw dis("strange::parser instruction with no arguments:") + token.report_();
		}
		if (_token_.tag() == "punctuation" && _token_.symbol() == "(")
		{
			auto const expression = instruction.operate(no(),
				flock_t<>::create_(token, _elements(scope_symbol, fixed_herd, kind_shoal)));
			if (!check<expression_a<>>(expression))
			{
				throw dis("strange::parser instruction returned non-expression:") + token.report_();
			}
			return cast<expression_a<>>(expression);
		}
		throw dis("strange::parser instruction with no arguments:") + token.report_();
	}

	inline expression_a<> _initial_local(
		bool const shared,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto const name = _token_.symbol_();
		bool fixed = fixed_herd.has(name);
		auto kind = kind_shoal.at_(name);
		bool insert = false;
		bool update = false;
		if (_next() && _token_.tag() == "punctuation") // consume
		{
			auto const op = _token_.symbol();
			if (kind)
			{
				if (op == ":=")
				{
					if (fixed)
					{
						throw dis("strange::parser cannot reassign fixed variable:") + _token_.report_();
					}
					update = true;
				}
				else if (op == ":#")
				{
					throw dis("strange::parser cannot reassign variable with fixed:") + _token_.report_();
				}
				else if (op == ":<" || op == ":{")
				{
					throw dis("strange::parser cannot reassign variable kind:") + _token_.report_();
				}
			}
			else if (fixed)
			{
				throw dis("strange::parser recursive variable definition:") + _token_.report_();
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
				else if (op == ":<" || op == ":{")
				{
					//TODO parse kind and fixed
					insert = true;
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
			auto const rhs = _initial(0, scope_symbol, fixed_herd, kind_shoal);
			if (!fixed)
			{
				unordered_herd_a<>(fixed_herd, true).erase(name);
			}
			if (insert)
			{
				unordered_shoal_a<>(kind_shoal, true).insert_(name, kind);
				if (shared)
				{
					return expression_shared_insert_t<>::create_(token, flock_t<>::create_(name, kind, rhs));
				}
				return expression_local_insert_t<>::create_(token, flock_t<>::create_(name, kind, rhs));
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

	inline symbol_a<> _scope()
	{
		std::string scope;
		for (bool first = true;;first = false)
		{
			if (_token_.tag() != "name")
			{
				if (first)
				{
					break;
				}
				throw dis("strange::parser :: with non-name following it:") + _token_.report_();
			}
			scope += _token_.symbol();
			if (!_next() || _token_.tag() != "punctuation" || _token_.symbol() != "::")
			{
				break;
			}
			scope += "::";
			if (!_next())
			{
				throw dis("strange::parser :: with nothing following it:") + _token_.report_();
			}
		}
		return sym(scope);
	}

	inline expression_a<> _initial_shoal_or_herd(
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		if (!_next())
		{
			throw dis("strange::parser { with nothing following it:") + token.report_();
		}
		auto flock = flock_t<>::create_();
		bool herd = false;
		bool shoal = false;
		auto key = expression_t<>::create(token);
		if (_token_.tag() == "punctuation" &&
			(_token_.symbol() == "}" || _token_.symbol() == "!"))
		{
			if (_token_.symbol() == "!")
			{
				if (!_next() || _token_.symbol() != "}")
				{
					throw dis("strange::parser {! without } immediately following it:") + token.report_();
				}
				herd = true;
			}
			_next();
		}
		else for (;;)
		{
			if (_token_.tag() == "name")
			{
				key = expression_literal_t<>::create_(_token_, flock_t<>::create_(_token_.symbol_()));
				_next();
			}
			else
			{
				key = _initial(0, scope_symbol, fixed_herd, kind_shoal);
			}
			if (_it_ == _end_)
			{
				if (shoal)
				{
					throw dis("strange::parser shoal key with nothing following it:") + _token_.report_();
				}
				throw dis("strange::parser element with nothing following it:") + _token_.report_();
			}
			if (_token_.tag() != "punctuation")
			{
				if (shoal)
				{
					throw dis("strange::parser shoal key with non-punctuation following it:") + _token_.report_();
				}
				throw dis("strange::parser element with non-punctuation following it:") + _token_.report_();
			}
			bool comma = _token_.symbol() == ",";
			if (comma)
			{
				if (shoal)
				{
					throw dis("strange::parser shoal key without a corresponding value:") + _token_.report_();
				}
				if (!_next())
				{
					throw dis("strange::parser , with nothing following it:") + _token_.report_();
				}
			}
			if (_token_.symbol() == "}")
			{
				if (shoal)
				{
					throw dis("strange::parser shoal key without a corresponding value:") + _token_.report_();
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
				throw dis("strange::parser herd element with unexpected punctuation following it:") + _token_.report_();
			}
			shoal = true;
			auto const operator_token = _token_;
			if (!_next())
			{
				throw dis("strange::parser shoal " + operator_token.symbol() + " with nothing following it:") + operator_token.report_();
			}
			auto key_symbol = no();
			if (key.literal())
			{
				try
				{
					key_symbol = key.evaluate_();
				}
				catch (misunderstanding_a<>& misunderstanding)
				{
					throw dis("strange::parser shoal " + operator_token.symbol() + " key evaluation error:") + operator_token.report_() + misunderstanding;
				}
			}
			auto const new_scope_symbol = _scope_name(scope_symbol,
				check<symbol_a<>>(key_symbol) ? cast<symbol_a<>>(key_symbol) : sym("#"));

			auto value = expression_t<>::create(operator_token);
			if (operator_token.symbol() == ":")
			{
				// regular key/value pair
				value = _initial(0, new_scope_symbol, fixed_herd, kind_shoal);
			}
			else if (operator_token.symbol() == "::")
			{
				// shared scope
				value = _initial(0, new_scope_symbol, unordered_herd_t<>::create_(), unordered_shoal_t<>::create_());
				bool clash = false;
				try
				{
					clash = !_shared_.insert(new_scope_symbol, value.evaluate_());
				}
				catch (misunderstanding_a<>& misunderstanding)
				{
					throw dis("strange::parser shoal :: value evaluation error:") + _token_.report_() + misunderstanding;
				}
				if (clash)
				{
					throw dis("strange::parser shoal :: redefinition of shared name:") + _token_.report_();
				}
			}
			else if (operator_token.symbol() == ":#" || operator_token.symbol() == ":=")
			{
				bool const fixed = (operator_token.symbol() == ":#");
				auto const key_string = cast<symbol_a<>>(key_symbol).to_string();
				if (key_string[key_string.length() - 1] == '_')
				{
					// attribute extraction/mutation
					auto const terms = flock_t<>::create_(key_symbol, kind_t<>::create_(), _initial(0, new_scope_symbol, unordered_herd_t<>::create_(), unordered_shoal_t<>::create_()));
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
					if (_token_.tag() != "punctuation" || _token_.symbol() != "(")
					{
						throw dis("strange::parser shoal " + operator_token.symbol() + " without ( following it:") + _token_.report_();
					}
					auto const terms = _elements(new_scope_symbol, unordered_herd_t<>::create_(), unordered_shoal_t<>::create_());
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
				throw dis("strange::parser shoal key with unexpected punctuation following it:") + _token_.report_();
			}
			if (_it_ == _end_)
			{
				throw dis("strange::parser shoal value with nothing following it:") + _token_.report_();
			}
			if (_token_.tag() != "punctuation")
			{
				throw dis("strange::parser shoal value with non-punctuation following it:") + _token_.report_();
			}
			flock.push_back(expression_flock_t<>::create_(operator_token, flock_t<>::create_(key, value)));
			comma = _token_.symbol() == ",";
			if (comma && !_next())
			{
				throw dis("strange::parser shoal , with nothing following it:") + _token_.report_();
			}
			if (_token_.symbol() == "}")
			{
				_next();
				break;
			}
			if (!comma)
			{
				throw dis("strange::parser shoal value with unexpected punctuation following it:") + _token_.report_();
			}
		}
		if (herd)
		{
			return expression_herd_t<>::create_(token, flock);
		}
		return expression_shoal_t<>::create_(token, flock);
	}

	inline expression_a<> _initial_kind(
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto terms = flock_t<>::create_();
		// order
		int64_t order = 0;
		while (_token_.tag() == "punctuation" && _token_.symbol() == "<")
		{
			++order;
			if (!_next())
			{
				throw dis("strange::parser kind < with nothing following it:") + token.report_();
			}
		}
		terms.push_back(number_int_64_t<>::create(order));
		// name
		bool const name = _token_.tag() == "name";
		if (name)
		{
			terms.push_back(_token_.symbol_());
			if (!_next())
			{
				throw dis("strange::parser kind name with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(sym(""));
		}
		// dimensions
		bool const dimensions = _token_.tag() == "punctuation" && _token_.symbol() == "{";
		if (dimensions)
		{
			terms.push_back(expression_flock_t<>::create_(token, _elements(scope_symbol, fixed_herd, kind_shoal)));
			if (_it_ == _end_)
			{
				throw dis("strange::parser kind } with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(expression_flock_t<>::create(token));
		}
		// aspects
		bool const aspects = _token_.tag() == "punctuation" && _token_.symbol() == "[";
		if (aspects)
		{
			terms.push_back(expression_flock_t<>::create_(token, _elements(scope_symbol, fixed_herd, kind_shoal)));
			if (_it_ == _end_)
			{
				throw dis("strange::parser kind ] with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(expression_flock_t<>::create(token));
		}
		// paramters
		bool const parameters = _token_.tag() == "punctuation" && _token_.symbol() == "(";
		if (parameters)
		{
			terms.push_back(expression_flock_t<>::create_(token, _elements(scope_symbol, fixed_herd, kind_shoal)));
			if (_it_ == _end_)
			{
				throw dis("strange::parser kind ) with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(expression_flock_t<>::create(token));
		}
		// result
		bool const result = _token_.tag() == "punctuation" && _token_.symbol() == ":";
		if (result)
		{
			if (!_next())
			{
				throw dis("strange::parser kind : with nothing following it:") + token.report_();
			}
			if (_token_.tag() != "punctuation" || _token_.symbol() != "<")
			{
				throw dis("strange::parser kind : without result following it:") + _token_.report_();
			}
			terms.push_back(_initial_kind(scope_symbol, fixed_herd, kind_shoal));
			if (_it_ == _end_)
			{
				throw dis("strange::parser kind result with nothing following it:") + token.report_();
			}
		}
		while (_token_.tag() == "punctuation" && _token_.symbol() == ">")
		{
			_next();
			if (!--order)
			{
				break;
			}
			if (_it_ == _end_)
			{
				throw dis("strange::parser kind > with nothing following it:") + token.report_();
			}
		}
		if (order)
		{
			throw dis("strange::parser mismatched kind < and > pair:") + token.report_();
		}
		// reference
		bool const reference = _it_ != _end_ && _token_.tag() == "punctuation" && _token_.symbol() == "&";
		if (reference)
		{
			terms.push_back(yes());
			_next();
		}
		// optional
		bool const optional = _it_ != _end_ && _token_.tag() == "punctuation" &&
			(_token_.symbol() == "#" || _token_.symbol() == "=");
		if (optional)
		{
			terms.push_back(yes());
		}
		//TODO remove redundant terms
		return expression_kind_t<>::create_(token, terms);
	}
	
	inline expression_a<> _subsequent(
		int64_t const min_precedence,
		expression_a<> const& initial,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		if (min_precedence >= 100 || _it_ == _end_)
		{
			return initial;
		}
		auto const token = _token_;
		if (token.tag() == "punctuation")
		{
			auto const op = token.symbol();
			if (op == "[")
			{
				// operate with elements
				auto terms = flock_t<>::create_(initial);
				terms += _elements(scope_symbol, fixed_herd, kind_shoal);
				return _subsequent(min_precedence, expression_operate_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
			}
			if (op == ".")
			{
				// invoke member
				if (!_next())
				{
					throw dis("strange::parser . with nothing following it:") + token.report_();
				}
				return _subsequent_dot(min_precedence, initial, scope_symbol, fixed_herd, kind_shoal);
			}
			if (op == ".:")
			{
				// operate
				if (!_next())
				{
					throw dis("strange::parser .: with nothing following it:") + token.report_();
				}
				return _subsequent_dot_colon(min_precedence, initial, scope_symbol, fixed_herd, kind_shoal);
			}
			if (op == ":.")
			{
				// member
				if (!_next())
				{
					throw dis("strange::parser :. with nothing following it:") + token.report_();
				}
				return _subsequent_colon_dot(min_precedence, initial, scope_symbol, fixed_herd, kind_shoal);
			}
			if (op == "," || op == ":" || op == "::" || op == ":#" || op == ":=" || op == ";" || op == "]" || op == "}" || op == ")") //TODO ...
			{
				// delimiter
				return initial;
			}
			//TODO ...
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
						_initial(precedence + 1, scope_symbol, fixed_herd, kind_shoal));
					if (op == "&&")
					{
						return _subsequent(min_precedence, expression_and_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
					}
					if (op == "!&")
					{
						return _subsequent(min_precedence, expression_nand_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
					}
					if (op == "%%")
					{
						return _subsequent(min_precedence, expression_xor_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
					}
					if (op == "!%")
					{
						return _subsequent(min_precedence, expression_xnor_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
					}
					if (op == "||")
					{
						return _subsequent(min_precedence, expression_or_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
					}
					if (op == "!|")
					{
						return _subsequent(min_precedence, expression_nor_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
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
					return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
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
						_initial(precedence + (right_to_left ? 0 : 1), scope_symbol, fixed_herd, kind_shoal));
					return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
				}
				else if (count == 3)
				{
					// invoke ternary operator
					if (!_next())
					{
						throw dis("strange::parser ternary operator with nothing following it:") + token.report_();
					}
					auto const second = _initial(precedence + (right_to_left ? 0 : 1), scope_symbol, fixed_herd, kind_shoal);
					if (!_next() || _token_.tag() != "punctuation" || _token_.symbol() != ":")
					{
						auto const terms = flock_t<>::create_(
							initial,
							expression_literal_t<>::create_(token, flock_t<>::create_(oper)),
							second);
						return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
					}
					if (!_next())
					{
						throw dis("strange::parser ternary operator with nothing following the delimiter:") + token.report_();
					}
					auto const terms = flock_t<>::create_(
						initial,
						expression_literal_t<>::create_(token, flock_t<>::create_(oper)),
						second,
						_initial(precedence + (right_to_left ? 0 : 1), scope_symbol, fixed_herd, kind_shoal));
					return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
				}
				assert(count >= 1 && count <= 3);
			}
		}
		// operate with range
		auto const terms = flock_t<>::create_(initial, _initial(100, scope_symbol, fixed_herd, kind_shoal));
		return _subsequent(min_precedence, expression_operate_range_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
	}

	inline flock_a<> _elements(
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		bool const square = _token_.symbol() == "[";
		bool const round = _token_.symbol() == "(";
		bool const curly = _token_.symbol() == "{";
		auto new_fixed_herd = fixed_herd;
		auto new_kind_shoal = kind_shoal;
		if (round || curly)
		{
			new_fixed_herd.mutate_thing();
			new_kind_shoal.mutate_thing();
		}
		if (!_next())
		{
			throw dis("strange::parser " + _token_.symbol() + " with nothing following it:") + _token_.report_();
		}
		auto flock = flock_t<>::create_();
		if (_token_.tag() == "punctuation" &&
			(square && _token_.symbol() == "]" ||
				round && _token_.symbol() == ")" ||
				curly && _token_.symbol() == "}"))
		{
			_next();
		}
		else for (;;)
		{
			flock.push_back(_initial(0, scope_symbol, new_fixed_herd, new_kind_shoal));
			if (_it_ == _end_)
			{
				throw dis("strange::parser element with nothing following it:") + _token_.report_();
			}
			if (_token_.tag() != "punctuation")
			{
				throw dis("strange::parser element with non-punctuation following it:") + _token_.report_();
			}
			bool const comma = _token_.symbol() == ",";
			if (comma && !_next())
			{
				throw dis("strange::parser , with nothing following it:") + _token_.report_();
			}
			if (square && _token_.symbol() == "]" ||
				round && _token_.symbol() == ")" ||
				curly && _token_.symbol() == "}")
			{
				_next();
				break;
			}
			if (!comma)
			{
				throw dis("strange::parser element with unexpected punctuation following it:") + _token_.report_();
			}
		}
		return flock;
	}

	inline expression_a<> _subsequent_dot(
		int64_t const min_precedence,
		expression_a<> const& initial,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		if (token.tag() != "name")
		{
			throw dis("strange::parser . with non-name following it:") + token.report_();
		}
		auto terms = flock_t<>::create_(initial);
		if (token.symbol().c_str()[token.symbol().length() - 1] == '_')
		{
			// attribute
			terms.push_back_(token.symbol_());
			if (_next() && _token_.tag() == "punctuation" && _token_.symbol() == ":=")
			{
				if (!_next())
				{
					throw dis("strange::parser attribute assignment with nothing following it:") + token.report_();
				}
				terms.push_back_(_initial(0, scope_symbol, fixed_herd, kind_shoal)); // assignment
			}
			return _subsequent(min_precedence, expression_invoke_attribute_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
		}
		if (!_next())
		{
			throw dis("strange::parser . with nothing following member name:") + token.report_();
		}
		if (_token_.tag() == "punctuation" && _token_.symbol() == "[")
		{
			terms.push_back_(expression_literal_t<>::create_(token, flock_t<>::create_(token.symbol_())));
			terms += _elements(scope_symbol, fixed_herd, kind_shoal);
			return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
		}
		terms.push_back_(token.symbol_());
		terms.push_back_(_initial(100, scope_symbol, fixed_herd, kind_shoal));
		return _subsequent(min_precedence, expression_invoke_member_range_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
	}

	inline expression_a<> _subsequent_dot_colon(
		int64_t const min_precedence,
		expression_a<> const& initial,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto second = _initial(100, scope_symbol, fixed_herd, kind_shoal);
		if (_it_ != _end_ && _token_.tag() == "punctuation" && _token_.symbol() == ":.")
		{
			// member
			if (!_next())
			{
				throw dis("strange::parser :. with nothing following it:") + token.report_();
			}
			second = _subsequent_colon_dot(100, second, scope_symbol, fixed_herd, kind_shoal);
		}
		auto terms = flock_t<>::create_(initial, second);
		if (!_next())
		{
			throw dis("strange::parser .: with nothing following its operation:") + token.report_();
		}
		if (_token_.tag() == "punctuation" && _token_.symbol() == "[")
		{
			terms += _elements(scope_symbol, fixed_herd, kind_shoal);
			return _subsequent(min_precedence, expression_operate_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
		}
		terms.push_back_(_initial(100, scope_symbol, fixed_herd, kind_shoal));
		return _subsequent(min_precedence, expression_operate_range_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
	}

	inline expression_a<> _subsequent_colon_dot(
		int64_t const min_precedence,
		expression_a<> const& initial,
		symbol_a<> const& scope_symbol,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		if (token.tag() != "name")
		{
			throw dis("strange::parser :. with non-name following it:") + token.report_();
		}
		_next();
		auto const terms = flock_t<>::create_(initial, token.symbol_());
		return _subsequent(min_precedence, expression_member_t<>::create_(token, terms), scope_symbol, fixed_herd, kind_shoal);
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
