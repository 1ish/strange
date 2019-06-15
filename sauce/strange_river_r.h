#ifndef COM_ONEISH_STRANGE_RIVER_R_H
#define COM_ONEISH_STRANGE_RIVER_R_H

namespace strange
{

template<>
class reflection<river_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::river");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<range_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<range_a<>>::operations();
			operations.update_string("get", native_mutation_t<river_a<>>::val(&river_a<>::get__));
			operations.update_string("peek", native_mutation_t<river_a<>>::val(&river_a<>::peek__));
			operations.update_string("unget", native_mutation_t<river_a<>>::val(&river_a<>::unget__));
			operations.update_string("putback", native_mutation_t<river_a<>>::val(&river_a<>::putback__));
			operations.update_string("getline", native_mutation_t<river_a<>>::val(&river_a<>::getline__));
			operations.update_string("ignore", native_mutation_t<river_a<>>::val(&river_a<>::ignore__));
			operations.update_string("read", native_mutation_t<river_a<>>::val(&river_a<>::read__));
			operations.update_string("tellg", native_extraction_t<river_a<>>::val(&river_a<>::tellg__));
			operations.update_string("seekg_beg", native_mutation_t<river_a<>>::val(&river_a<>::seekg_beg__));
			operations.update_string("seekg_end", native_mutation_t<river_a<>>::val(&river_a<>::seekg_end__));
			operations.update_string("seekg_cur", native_mutation_t<river_a<>>::val(&river_a<>::seekg_cur__));
			operations.update_string("sync", native_mutation_t<river_a<>>::val(&river_a<>::sync__));
			operations.update_string("put", native_mutation_t<river_a<>>::val(&river_a<>::put__));
			operations.update_string("write", native_mutation_t<river_a<>>::val(&river_a<>::write__));
			operations.update_string("tellp", native_extraction_t<river_a<>>::val(&river_a<>::tellp__));
			operations.update_string("seekp_beg", native_mutation_t<river_a<>>::val(&river_a<>::seekp_beg__));
			operations.update_string("seekp_end", native_mutation_t<river_a<>>::val(&river_a<>::seekp_end__));
			operations.update_string("seekp_cur", native_mutation_t<river_a<>>::val(&river_a<>::seekp_cur__));
			operations.update_string("flush", native_mutation_t<river_a<>>::val(&river_a<>::flush__));
			operations.update_string("good", native_extraction_t<river_a<>>::val(&river_a<>::good__));
			operations.update_string("eof", native_extraction_t<river_a<>>::val(&river_a<>::eof__));
			operations.update_string("fail", native_extraction_t<river_a<>>::val(&river_a<>::fail__));
			operations.update_string("bad", native_extraction_t<river_a<>>::val(&river_a<>::bad__));
			operations.update_string("set_good", native_mutation_t<river_a<>>::val(&river_a<>::set_good__));
			operations.update_string("set_eof", native_mutation_t<river_a<>>::val(&river_a<>::set_eof__));
			operations.update_string("set_fail", native_mutation_t<river_a<>>::val(&river_a<>::set_fail__));
			operations.update_string("set_bad", native_mutation_t<river_a<>>::val(&river_a<>::set_bad__));
			operations.update_string("filename", native_extraction_t<river_a<>>::val(&river_a<>::filename__));
			return operations;
		}();
		return OPERATIONS;
	}
};

template<>
class reflection<river_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::river");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::river::val", native_function_t<>::val(&river_t<>::val__));
		shoal.update_string("strange::river::file_val", native_function_t<>::val(&river_t<>::file_val__));
		shoal.update_string("strange::river::in_val", native_function_t<>::val(&river_t<>::in_val__));
		shoal.update_string("strange::river::out_val", native_function_t<>::val(&river_t<>::out_val__));
		shoal.update_string("strange::river::err_val", native_function_t<>::val(&river_t<>::err_val__));
	}
};

}

#endif
