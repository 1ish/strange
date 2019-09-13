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
			throw dis("strange::parser tokenizer error:\n") + _token_.report_();
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
			throw dis("strange::parser tokenizer error:\n") + _token_.report_();
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
			if (name.c_str()[0] == '_')
			{
				if (name.c_str()[name.length() - 1] == '_')
				{
					initial = _attribute(scope_lake, fixed_herd, kind_shoal);
				}
				else
				{
					initial = _intimate(scope_lake, fixed_herd, kind_shoal);
				}
			}
			else if (name.c_str()[name.length() - 1] == '_')
			{
				initial = _instruction(scope_lake, fixed_herd, kind_shoal);
			}
			else
			{
				initial = _local(false, scope_lake, fixed_herd, kind_shoal);
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
					throw dis("strange::parser $ with nothing following it:\n") + token.report_();
				}
				initial = _local(true, scope_lake, fixed_herd, kind_shoal);
			}
			else if (op == "$$") // shared scope
			{
				if (!_next())
				{
					throw dis("strange::parser $$ with nothing following it:\n") + token.report_();
				}
				initial = expression_shared_scope_t<>::val_(token, flock_t<>::val_(_shared_, _scope()));
			}
			//TODO ...
			else
			{
				throw dis("strange::parser unexpected punctuation:\n") + token.report_();
			}
		}
		else
		{
			throw dis("strange::parser unexpected token tag:\n") + _token_.report_();
		}
		return _subsequent(min_precedence, initial, scope_lake, fixed_herd, kind_shoal);
	}

	inline expression_a<> _attribute(
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto const name = token.symbol_();
		auto terms = flock_t<>::val_(expression_me_t<>::val_(token, flock_t<>::val_())); // me
		if (scope_lake.empty())
		{
			// me._name_[]
			terms.push_back_(expression_literal_t<>::val_(token, flock_t<>::val_(name)));
		}
		else
		{
			// me._scope_name_[]
			terms.push_back_(expression_literal_t<>::val_(token, flock_t<>::val_(sym("_" + lake_to_string(scope_lake) + name.to_string()))));
		}
		if (_next() && _token_.tag() == "punctuation" && _token_.symbol() == ":=") // consume
		{
			terms.push_back_(_initial(0, scope_lake, fixed_herd, kind_shoal)); // assignment
		}
		return expression_intimate_t<>::val_(token, terms);
	}

	inline expression_a<> _intimate(
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto terms = flock_t<>::val_(expression_me_t<>::val_(token, flock_t<>::val_())); // me
		if (scope_lake.empty())
		{
			// me._name
			terms.push_back_(expression_literal_t<>::val_(token, flock_t<>::val_(token.symbol_())));
		}
		else
		{
			// me._scope_name
			terms.push_back_(expression_literal_t<>::val_(token, flock_t<>::val_(sym("_" + lake_to_string(scope_lake) + token.symbol_().to_string()))));
		}
		if (!_next()) // consume
		{
			throw dis("strange::parser intimate operation with no arguments:\n") + token.report_();
		}
		if (_token_.tag() == "punctuation" && _token_.symbol() == "[")
		{
			terms += _elements(scope_lake, fixed_herd, kind_shoal); // me._name[...]
			return expression_intimate_t<>::val_(token, terms);
		}
		terms.push_back_(_initial(100, scope_lake, fixed_herd, kind_shoal)); // me._name range
		return expression_intimate_member_range_t<>::val_(token, terms);
	}

	inline expression_a<> _instruction(
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto const instruction = _shared_.at_(token.symbol_());
		if (!instruction)
		{
			throw dis("strange::parser instruction not recognised:\n") + token.report_();
		}
		if (!_next()) // consume
		{
			throw dis("strange::parser instruction with no arguments:\n") + token.report_();
		}
		if (_token_.tag() == "punctuation" && _token_.symbol() == "(")
		{
			auto const expression = instruction.operate(no(), _elements(scope_lake, fixed_herd, kind_shoal));
			if (!check<expression_a<>>(expression))
			{
				throw dis("strange::parser instruction returned non-expression:\n") + token.report_();
			}
			return cast<expression_a<>>(expression);
		}
		throw dis("strange::parser instruction with no arguments:\n") + token.report_();
	}

	inline expression_a<> _local(
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
					throw dis("strange::parser cannot reassign variable kind:\n") + _token_.report_();
				}
				if (op == "#=" || op == "#<")
				{
					throw dis("strange::parser cannot reassign variable with fixed:\n") + _token_.report_();
				}
				if (op == ":=")
				{
					if (fixed)
					{
						throw dis("strange::parser cannot reassign fixed variable:\n") + _token_.report_();
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
				throw dis("strange::parser local assignment with no right-hand side:\n") + token.report_();
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
				throw dis("strange::parser scope operator with unexpected token following it:\n") + _token_.report_();
			}
			scope += _token_.symbol();
			if (!_next() || _token_.tag() != "punctuation" || _token_.symbol() != "::")
			{
				break;
			}
			scope += "::";
			if (!_next())
			{
				throw dis("strange::parser scope operator with nothing following it:\n") + _token_.report_();
			}
		}
		return sym(scope);
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
			//TODO ...
			int64_t const precedence = token.precedence();
			if (precedence)
			{
				if (precedence < min_precedence)
				{
					return initial;
				}
				auto oper = sym("");
				bool binary = false;
				if (op == "@")
				{
					oper = sym("at");
					binary = true;
				}
				else if (op == "@=")
				{
					oper = sym("update");
					binary = true;
				}
				else if (op == "?")
				{
					oper = sym("something");
				}
				else if (op == "!")
				{
					oper = sym("nothing");
				}
				//TODO ...
				else
				{
					throw dis("strange::parser unexpected operator:\n") + token.report_();
				}
				if (binary)
				{
					// invoke binary operator
					if (!_next())
					{
						throw dis("strange::parser binary operator with nothing following it:\n") + token.report_();
					}
					auto const terms = flock_t<>::val_(
						initial,
						expression_literal_t<>::val_(token, flock_t<>::val_(oper)),
						_initial(precedence + 1, scope_lake, fixed_herd, kind_shoal));
					return _subsequent(min_precedence, expression_invoke_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
				}
				// invoke unary operator
				_next();
				auto const terms = flock_t<>::val_(initial, expression_literal_t<>::val_(token, flock_t<>::val_(oper)));
				return _subsequent(min_precedence, expression_invoke_t<>::val_(token, terms), scope_lake, fixed_herd, kind_shoal);
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
		//TODO consume [...]
		return flock_t<>::val_();
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
