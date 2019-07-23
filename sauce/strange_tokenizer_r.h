#ifndef COM_ONEISH_STRANGE_TOKENIZER_R_H
#define COM_ONEISH_STRANGE_TOKENIZER_R_H

namespace strange
{

template<>
class reflection<tokenizer_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::tokenizer");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::tokenizer::val", native_function_t<>::val(&tokenizer_t<>::val__));
	}
};

class ___tokenizer_t_share___
{
	static inline bool ___share___()
	{
		return tokenizer_t<>::___share___;
	}
};

}

#endif
