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
	static inline parser_a<> val_()
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
			return expression_t<>::val(token_t<>::punctuation_val_());
		}
		_token_ = cast<token_a<>>(*_it_);
		if (_token_.tag() == "error")
		{
			throw dis("strange::parser tokenizer error:") + _token_.report_();
		}
		return _initial(0, lake_int_8_t<>::val_(), unordered_herd_t<>::val_(), unordered_shoal_t<>::val_());
	}

protected:
	inline parser_t()
		: thing_t{}
		, _shared_{ unordered_shoal_t<>::val_() }
		, _tokenizer_{ tokenizer_t<>::val_(river_t<>::val_()) }
		, _it_{ _tokenizer_.cbegin_() }
		, _end_{ _tokenizer_.cend_() }
		, _token_{ token_t<>::punctuation_val_() }
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
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		expression_a<> initial = expression_t<>::val(_token_);
		if (_token_.tag() == "symbol" ||
			_token_.tag() == "lake" ||
			_token_.tag() == "int" ||
			_token_.tag() == "float")
		{
			// literal
			initial = expression_literal_t<>::val_(_token_, flock_t<>::val_(_token_.literal_()));
		}
		else if (_token_.tag() == "name")
		{
			std::string const name = _token_.symbol();
			if (name.c_str()[name.length() - 1] == '_')
			{
				initial = _initial_attribute(scope_lake, fixed_herd, kind_shoal);
			}
			else if (name.c_str()[0] == '_')
			{
				initial = _initial_intimate(scope_lake, fixed_herd, kind_shoal);
			}
			else if (name == "true")
			{
				_next();
				initial = expression_literal_t<>::val_(_token_, flock_t<>::val_(yes()));
			}
			else if (name == "false" || name == "null")
			{
				_next();
				initial = expression_literal_t<>::val_(_token_, flock_t<>::val_(no()));
			}
			else if (_shared_.has_string(name))
			{
				initial = _initial_instruction(scope_lake, fixed_herd, kind_shoal);
			}
			else
			{
				initial = _initial_local(false, scope_lake, fixed_herd, kind_shoal);
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
				initial = _initial_local(true, scope_lake, fixed_herd, kind_shoal);
			}
			else if (op == "$$") // shared scope
			{
				if (!_next())
				{
					throw dis("strange::parser $$ with nothing following it:") + token.report_();
				}
				initial = expression_shared_scope_t<>::val_(token, flock_t<>::val_(_shared_, _scope()));
			}
			else if (op == "^") // me
			{
				if (_next() && _token_.tag() == "punctuation")
				{
					if (_token_.symbol() == ".") // me dot
					{
						initial = _initial_me_dot(scope_lake, fixed_herd, kind_shoal);
					}
					else if (_token_.symbol() == ":.") // me colon-dot
					{
						initial = _initial_me_colon_dot(scope_lake, fixed_herd, kind_shoal);
					}
				}
				else
				{
					initial = expression_me_t<>::val_(token); // me
				}
			}
			else if (token.symbol() == "[") // flock
			{
				initial = expression_flock_t<>::val_(token, _elements(scope_lake, fixed_herd, kind_shoal));
			}
			else if (token.symbol() == "(") // block
			{
				initial = expression_block_t<>::val_(token, _elements(scope_lake, fixed_herd, kind_shoal));
			}
			else if (token.symbol() == "{") // shoal or herd
			{
				initial = _initial_shoal_or_herd(scope_lake, fixed_herd, kind_shoal);
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
		return _subsequent(min_precedence, initial, scope_lake, fixed_herd, kind_shoal);
	}

	inline expression_a<> _initial_me_dot(
		lake_a<int8_t> const& scope_lake,
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
			return _initial_attribute(scope_lake, fixed_herd, kind_shoal);
		}
		if (name.c_str()[0] == '_')
		{
			return _initial_intimate(scope_lake, fixed_herd, kind_shoal);
		}
		if (!_next())
		{
			throw dis("strange::parser ^. with no nothing following member name:") + token.report_();
		}
		auto terms = flock_t<>::val_(expression_me_t<>::val_(token)); // me
		if (_token_.tag() == "punctuation" && _token_.symbol() == "[")
		{
			terms.push_back_(expression_literal_t<>::val_(token, flock_t<>::val_(name_symbol)));
			terms += _elements(scope_lake, fixed_herd, kind_shoal);
			return expression_invoke_t<>::val_(token, terms);
		}
		terms.push_back_(name_symbol);
		terms.push_back_(_initial(100, scope_lake, fixed_herd, kind_shoal));
		return expression_invoke_member_range_t<>::val_(token, terms);
	}

	inline expression_a<> _initial_me_colon_dot(
		lake_a<int8_t> const& scope_lake,
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
			auto const terms = flock_t<>::val_(
				expression_me_t<>::val_(token),
				_identifier(scope_lake, name_symbol)); // me:._name / me:._scope_name
			return expression_intimate_member_t<>::val_(token, terms);
		}
		_next();
		auto const terms = flock_t<>::val_(
			expression_me_t<>::val_(token),
			name_symbol); // me:.name
		return expression_member_t<>::val_(token, terms);
	}

	inline expression_a<> _initial_attribute(
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto const name = token.symbol_();
		auto terms = flock_t<>::val_(expression_me_t<>::val_(token)); // me
		terms.push_back_(_identifier(scope_lake, name)); // _name_ / _scope_name_
		if (_next() && _token_.tag() == "punctuation" && _token_.symbol() == ":=") // consume
		{
			if (!_next())
			{
				throw dis("strange::parser attribute assignment with nothing following it:") + token.report_();
			}
			terms.push_back_(_initial(0, scope_lake, fixed_herd, kind_shoal)); // assignment
		}
		return expression_intimate_attribute_t<>::val_(token, terms);
	}

	inline expression_a<> _initial_intimate(
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto terms = flock_t<>::val_(expression_me_t<>::val_(token)); // me
		auto const identifier = _identifier(scope_lake, token.symbol_()); // _name / _scope_name
		if (!_next()) // consume
		{
			throw dis("strange::parser intimate operation with no arguments:") + token.report_();
		}
		if (_token_.tag() == "punctuation" && _token_.symbol() == "[")
		{
			terms.push_back_(expression_literal_t<>::val_(token, flock_t<>::val_(identifier)));
			terms += _elements(scope_lake, fixed_herd, kind_shoal); // me._scope_name[...]
			return expression_intimate_t<>::val_(token, terms);
		}
		terms.push_back_(identifier);
		terms.push_back_(_initial(100, scope_lake, fixed_herd, kind_shoal)); // me._scope_name range
		return expression_intimate_member_range_t<>::val_(token, terms);
	}

	static inline symbol_a<> _identifier(
		lake_a<int8_t> const& scope_lake,
		symbol_a<> const& name)
	{
		// name / _scope_name
		return (scope_lake.empty() || name.to_string().c_str()[0] != '_')
			? name
			: sym("_" + lake_to_string(scope_lake) + name.to_string());
	}

	static inline symbol_a<> _scope_name(
		lake_a<int8_t> const& scope_lake,
		symbol_a<> const& name)
	{
		// name / scope::name
		return scope_lake.empty()
			? name
			: sym(lake_to_string(scope_lake) + "::" + name.to_string());
	}

	inline expression_a<> _initial_instruction(
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto const instruction = _shared_.at_(token.symbol_());
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
			auto const expression = instruction.operate(no(), _elements(scope_lake, fixed_herd, kind_shoal));
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
		lake_a<int8_t> const& scope_lake,
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
				if (op == ":<")
				{
					throw dis("strange::parser cannot reassign variable kind:") + _token_.report_();
				}
				if (op == "#=" || op == "#<")
				{
					throw dis("strange::parser cannot reassign variable with fixed:") + _token_.report_();
				}
				if (op == ":=")
				{
					if (fixed)
					{
						throw dis("strange::parser cannot reassign fixed variable:") + _token_.report_();
					}
					update = true;
				}
			}
			else
			{
				kind = kind_t<>::val_();
				if (op == ":=" || op == "#=" || op == ":<" || op == "#<")
				{
					fixed = (op[0] == '#');
					insert = true;
					if (op[1] == '<')
					{
						//TODO parse kind
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
			if (insert)
			{
				if (fixed)
				{
					unordered_herd_a<>(fixed_herd, true).insert(name);
				}
				unordered_shoal_a<>(kind_shoal, true).insert_(name, kind);
				if (shared)
				{
					return expression_shared_insert_t<>::val_(token, flock_t<>::val_(name, kind, _initial(0, scope_lake, fixed_herd, kind_shoal)));
				}
				return expression_local_insert_t<>::val_(token, flock_t<>::val_(name, kind, _initial(0, scope_lake, fixed_herd, kind_shoal)));
			}
			if (update)
			{
				if (shared)
				{
					return expression_shared_update_t<>::val_(token, flock_t<>::val_(name, kind, _initial(0, scope_lake, fixed_herd, kind_shoal)));
				}
				return expression_local_update_t<>::val_(token, flock_t<>::val_(name, kind, _initial(0, scope_lake, fixed_herd, kind_shoal)));
			}
		}
		if (shared)
		{
			return expression_shared_at_t<>::val_(token, flock_t<>::val_(name));
		}
		return expression_local_at_t<>::val_(token, flock_t<>::val_(name));
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
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		if (!_next())
		{
			throw dis("strange::parser { with nothing following it:") + token.report_();
		}
		auto flock = flock_t<>::val_();
		bool herd = false;
		bool shoal = false;
		auto key = no();
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
			key = _initial(0, scope_lake, fixed_herd, kind_shoal);
			flock.push_back(key);
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
			if (_token_.symbol() == ",")
			{
				if (shoal)
				{
					throw dis("strange::parser shoal key without a corresponding value:") + _token_.report_();
				}
				if (!_next())
				{
					throw dis("strange::parser , with nothing following it:") + _token_.report_();
				}
				herd = true;
				continue;
			}
			if (_token_.symbol() == "}")
			{
				if (shoal)
				{
					throw dis("strange::parser shoal key without a corresponding value:") + _token_.report_();
				}
				_next();
				break;
			}
			if (herd)
			{
				throw dis("strange::parser herd element with unexpected punctuation following it:") + _token_.report_();
			}
			shoal = true;
			if (_token_.symbol() == ":")
			{
				if (!_next())
				{
					throw dis("strange::parser shoal : with nothing following it:") + _token_.report_();
				}
				flock.push_back(_initial(0, scope_lake, fixed_herd, kind_shoal));
			}
			else if (_token_.symbol() == "::")
			{
				if (!check<symbol_a<>>(key))
				{
					throw dis("strange::parser shoal :: with non-symbol key:") + _token_.report_();
				}
				if (!_next())
				{
					throw dis("strange::parser shoal :: with nothing following it:") + _token_.report_();
				}
				auto const expression = _initial(0, scope_lake, fixed_herd, kind_shoal);
				flock.push_back(expression);
				bool clash = false;
				try
				{
					clash = !_shared_.insert(_scope_name(scope_lake, cast<symbol_a<>>(key)), expression.evaluate_());
				}
				catch (misunderstanding_a<>& misunderstanding)
				{
					throw dis("strange::parser shoal :: evaluation error:") + _token_.report_() + misunderstanding;
				}
				if (clash)
				{
					throw dis("strange::parser shoal :: redefinition of shared name:") + _token_.report_();
				}
			}
			else if (_token_.symbol() == ":#")
			{
				if (!_next())
				{
					throw dis("strange::parser shoal :# with nothing following it:") + _token_.report_();
				}
				auto const value = _initial(0, scope_lake, fixed_herd, kind_shoal);
				//TODO attribute extraction
			}
			else if (_token_.symbol() == ":~")
			{
				if (!_next())
				{
					throw dis("strange::parser shoal :~ with nothing following it:") + _token_.report_();
				}
				auto const value = _initial(0, scope_lake, fixed_herd, kind_shoal);
				//TODO attribute mutation
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
			if (_token_.symbol() == ",")
			{
				if (!_next())
				{
					throw dis("strange::parser shoal , with nothing following it:") + _token_.report_();
				}
				continue;
			}
			if (_token_.symbol() == "}")
			{
				_next();
				break;
			}
			throw dis("strange::parser shoal value with unexpected punctuation following it:") + _token_.report_();
		}
		if (herd)
		{
			return expression_herd_t<>::val_(token, flock);
		}
		return expression_shoal_t<>::val_(token, flock);
	}

	inline expression_a<> _subsequent(
		int64_t const min_precedence,
		expression_a<> const& initial,
		lake_a<int8_t> const& scope_lake,
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
				auto terms = flock_t<>::val_(initial);
				terms += _elements(scope_lake, fixed_herd, kind_shoal);
				return _subsequent(min_precedence, expression_operate_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
			}
			if (op == ".")
			{
				// invoke member
				if (!_next())
				{
					throw dis("strange::parser . with nothing following it:") + token.report_();
				}
				return _subsequent_dot(min_precedence, initial, scope_lake, fixed_herd, kind_shoal);
			}
			if (op == ".:")
			{
				// operate
				if (!_next())
				{
					throw dis("strange::parser .: with nothing following it:") + token.report_();
				}
				return _subsequent_dot_colon(min_precedence, initial, scope_lake, fixed_herd, kind_shoal);
			}
			if (op == ":.")
			{
				// member
				if (!_next())
				{
					throw dis("strange::parser :. with nothing following it:") + token.report_();
				}
				return _subsequent_colon_dot(min_precedence, initial, scope_lake, fixed_herd, kind_shoal);
			}
			if (op == "," || op == ":" || op == ";" || op == "]" || op == "}" || op == ")") //TODO ...
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
					auto const terms = flock_t<>::val_(
						initial,
						_initial(precedence + 1, scope_lake, fixed_herd, kind_shoal));
					if (op == "&&")
					{
						return _subsequent(min_precedence, expression_and_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
					}
					if (op == "!&")
					{
						return _subsequent(min_precedence, expression_nand_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
					}
					if (op == "%%")
					{
						return _subsequent(min_precedence, expression_xor_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
					}
					if (op == "!%")
					{
						return _subsequent(min_precedence, expression_xnor_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
					}
					if (op == "||")
					{
						return _subsequent(min_precedence, expression_or_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
					}
					if (op == "!|")
					{
						return _subsequent(min_precedence, expression_nor_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
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
					auto const terms = flock_t<>::val_(initial, expression_literal_t<>::val_(token, flock_t<>::val_(oper)));
					return _subsequent(min_precedence, expression_invoke_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
				}
				else if (count == 2)
				{
					// invoke binary operator
					if (!_next())
					{
						throw dis("strange::parser binary operator with nothing following it:") + token.report_();
					}
					auto const terms = flock_t<>::val_(
						initial,
						expression_literal_t<>::val_(token, flock_t<>::val_(oper)),
						_initial(precedence + (right_to_left ? 0 : 1), scope_lake, fixed_herd, kind_shoal));
					return _subsequent(min_precedence, expression_invoke_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
				}
				else if (count == 3)
				{
					// invoke ternary operator
					if (!_next())
					{
						throw dis("strange::parser ternary operator with nothing following it:") + token.report_();
					}
					auto const second = _initial(precedence + (right_to_left ? 0 : 1), scope_lake, fixed_herd, kind_shoal);
					if (!_next() || _token_.tag() != "punctuation" || _token_.symbol() != ":")
					{
						auto const terms = flock_t<>::val_(
							initial,
							expression_literal_t<>::val_(token, flock_t<>::val_(oper)),
							second);
						return _subsequent(min_precedence, expression_invoke_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
					}
					if (!_next())
					{
						throw dis("strange::parser ternary operator with nothing following the delimiter:") + token.report_();
					}
					auto const terms = flock_t<>::val_(
						initial,
						expression_literal_t<>::val_(token, flock_t<>::val_(oper)),
						second,
						_initial(precedence + (right_to_left ? 0 : 1), scope_lake, fixed_herd, kind_shoal));
					return _subsequent(min_precedence, expression_invoke_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
				}
				assert(count >= 1 && count <= 3);
			}
		}
		// operate with range
		auto const terms = flock_t<>::val_(initial, _initial(100, scope_lake, fixed_herd, kind_shoal));
		return _subsequent(min_precedence, expression_operate_range_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
	}

	inline flock_a<> _elements(
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		bool const square = _token_.symbol() == "[";
		bool const round = _token_.symbol() == "(";
		if (!_next())
		{
			throw dis("strange::parser " + _token_.symbol() + " with nothing following it:") + _token_.report_();
		}
		auto flock = flock_t<>::val_();
		if (_token_.tag() == "punctuation" &&
			(square && _token_.symbol() == "]" ||
				round && _token_.symbol() == ")"))
		{
			_next();
		}
		else for (;;)
		{
			flock.push_back(_initial(0, scope_lake, fixed_herd, kind_shoal));
			if (_it_ == _end_)
			{
				throw dis("strange::parser element with nothing following it:") + _token_.report_();
			}
			if (_token_.tag() != "punctuation")
			{
				throw dis("strange::parser element with non-punctuation following it:") + _token_.report_();
			}
			if (_token_.symbol() == ",")
			{
				if (!_next())
				{
					throw dis("strange::parser , with nothing following it:") + _token_.report_();
				}
				continue;
			}
			if (square && _token_.symbol() == "]" ||
				round && _token_.symbol() == ")")
			{
				_next();
				break;
			}
			throw dis("strange::parser element with unexpected punctuation following it:") + _token_.report_();
		}
		return flock;
	}

	inline expression_a<> _subsequent_dot(
		int64_t const min_precedence,
		expression_a<> const& initial,
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		if (token.tag() != "name")
		{
			throw dis("strange::parser . with non-name following it:") + token.report_();
		}
		auto terms = flock_t<>::val_(initial);
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
				terms.push_back_(_initial(0, scope_lake, fixed_herd, kind_shoal)); // assignment
			}
			return _subsequent(min_precedence, expression_invoke_attribute_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
		}
		if (!_next())
		{
			throw dis("strange::parser . with nothing following member name:") + token.report_();
		}
		if (_token_.tag() == "punctuation" && _token_.symbol() == "[")
		{
			terms.push_back_(expression_literal_t<>::val_(token, flock_t<>::val_(token.symbol_())));
			terms += _elements(scope_lake, fixed_herd, kind_shoal);
			return _subsequent(min_precedence, expression_invoke_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
		}
		terms.push_back_(token.symbol_());
		terms.push_back_(_initial(100, scope_lake, fixed_herd, kind_shoal));
		return _subsequent(min_precedence, expression_invoke_member_range_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
	}

	inline expression_a<> _subsequent_dot_colon(
		int64_t const min_precedence,
		expression_a<> const& initial,
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto second = _initial(100, scope_lake, fixed_herd, kind_shoal);
		if (_it_ != _end_ && _token_.tag() == "punctuation" && _token_.symbol() == ":.")
		{
			// member
			if (!_next())
			{
				throw dis("strange::parser :. with nothing following it:") + token.report_();
			}
			second = _subsequent_colon_dot(100, second, scope_lake, fixed_herd, kind_shoal);
		}
		auto terms = flock_t<>::val_(initial, second);
		if (!_next())
		{
			throw dis("strange::parser .: with nothing following its operation:") + token.report_();
		}
		if (_token_.tag() == "punctuation" && _token_.symbol() == "[")
		{
			terms += _elements(scope_lake, fixed_herd, kind_shoal);
			return _subsequent(min_precedence, expression_operate_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
		}
		terms.push_back_(_initial(100, scope_lake, fixed_herd, kind_shoal));
		return _subsequent(min_precedence, expression_operate_range_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
	}

	inline expression_a<> _subsequent_colon_dot(
		int64_t const min_precedence,
		expression_a<> const& initial,
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		if (token.tag() != "name")
		{
			throw dis("strange::parser :. with non-name following it:") + token.report_();
		}
		_next();
		auto const terms = flock_t<>::val_(initial, token.symbol_());
		return _subsequent(min_precedence, expression_member_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
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
