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
		return _initial();
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
		lake_a<int8_t> const& scope_lake = lake_int_8_t<>::val_(),
		unordered_herd_a<> const& fixed_herd = unordered_herd_t<>::val_(),
		unordered_shoal_a<> const& kind_shoal = unordered_shoal_t<>::val_())
	{
		expression_a<> initial = expression_t<>::val(_token_);
		bool consumed = false;
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
				initial = _local(scope_lake, fixed_herd, kind_shoal);
				consumed = true;
			}
		}
		else if (_token_.tag() == "punctuation")
		{
			//TODO ...
		}
		if ((consumed && _it_ == _end_) || (!consumed && !_next()))
		{
			return initial;
		}
		return _subsequent(initial, scope_lake, fixed_herd, kind_shoal);
	}

	inline expression_a<> _attribute(
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		if (scope_lake.empty())
		{
			// me._name_[]
			return expression_intimate_t<>::val_(token,
				flock_t<>::val_(expression_me_t<>::val_(token, flock_t<>::val_()),
					expression_literal_t<>::val_(token, flock_t<>::val_(token.symbol_()))));
		}
		else
		{
			// me._scope_name_[]
			return expression_intimate_t<>::val_(token,
				flock_t<>::val_(expression_me_t<>::val_(token, flock_t<>::val_()),
					expression_literal_t<>::val_(token, flock_t<>::val_(sym("_" + lake_to_string(scope_lake) + token.symbol_().to_string())))));
		}
		//TODO assignment / consume
	}

	inline expression_a<> _intimate(
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		// me._name[...] / me._scope_name[...]
		auto terms = scope_lake.empty()
			? flock_t<>::val_(expression_me_t<>::val_(token, flock_t<>::val_()),
				expression_literal_t<>::val_(token, flock_t<>::val_(token.symbol_())))
			: flock_t<>::val_(expression_me_t<>::val_(token, flock_t<>::val_()),
				expression_literal_t<>::val_(token, flock_t<>::val_(sym("_" + lake_to_string(scope_lake) + token.symbol_().to_string()))));
		if (!_next())
		{
			throw dis("strange::parser intimate operation with no arguments:\n") + token.report_();
		}
		if (_token_.tag() == "punctuation" && _token_.symbol() == "[")
		{
			terms += _elements(scope_lake, fixed_herd, kind_shoal);
			return expression_intimate_t<>::val_(token, terms);
		}
		terms.push_back_(_initial(scope_lake, fixed_herd, kind_shoal)); //TODO precedence / consume
		return expression_intimate_range_t<>::val_(token, terms);
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
		if (!_next())
		{
			throw dis("strange::parser instruction with no arguments:\n") + token.report_();
		}
		if (_token_.tag() == "punctuation" && _token_.symbol() == "(")
		{
			auto const terms = _elements(scope_lake, fixed_herd, kind_shoal);
			auto const expression = instruction.operate_(no(), terms);
			if (!check<expression_a<>>(expression))
			{
				throw dis("strange::parser instruction returned non-expression:\n") + token.report_();
			}
			return cast<expression_a<>>(expression);
		}
		throw dis("strange::parser instruction with no arguments:\n") + token.report_();
	}

	inline expression_a<> _local(
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		auto const token = _token_;
		auto const name = _token_.symbol_();
		auto const kind = kind_shoal.at_(name);
		if (_next())
		{
			//TODO ...
			if (kind)
			{
			}
		}
		return expression_local_at_t<>::val_(token, flock_t<>::val_(name));
	}

	inline expression_a<> _subsequent(
		expression_a<> const& initial,
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		//TODO ...
		return initial;
	}

	inline flock_a<> _elements(
		lake_a<int8_t> const& scope_lake,
		unordered_herd_a<> const& fixed_herd,
		unordered_shoal_a<> const& kind_shoal)
	{
		//TODO ...
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
