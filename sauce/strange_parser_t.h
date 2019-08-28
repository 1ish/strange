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
		_tokenizer = tokenizer;
		_it = _tokenizer.cbegin_();
		_end = _tokenizer.cend_();
		if (_it == _end)
		{
			return expression_t<>::val(token_t<>::punctuation_val_());
		}
		_token = cast<token_a<>>(*_it);
		return _initial_(sym(""));
	}

protected:
	unordered_shoal_a<> _shared;
	range_a<> _tokenizer;
	forward_const_iterator_a<> _it;
	forward_const_iterator_a<> _end;
	token_a<> _token;

	inline parser_t()
		: thing_t{}
		, _shared{ unordered_shoal_t<>::val_() }
		, _tokenizer{ tokenizer_t<>::val_(river_t<>::val_()) }
		, _it{ _tokenizer.cbegin_() }
		, _end{ _tokenizer.cend_() }
		, _token{ token_t<>::punctuation_val_() }
	{
		_shared += shared();
	}

	inline expression_a<> _initial_(symbol_a<> const scope)
	{
		return expression_t<>::val(_token);
	}

private:
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
