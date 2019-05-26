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
			operations.update("get", native_mutation_t<river_a<>>::val(&river_a<>::get__));
			operations.update("peek", native_mutation_t<river_a<>>::val(&river_a<>::peek__));
			operations.update("unget", native_mutation_t<river_a<>>::val(&river_a<>::unget__));
			operations.update("putback", native_mutation_t<river_a<>>::val(&river_a<>::putback__));
			operations.update("getline", native_mutation_t<river_a<>>::val(&river_a<>::getline__));
			operations.update("ignore", native_mutation_t<river_a<>>::val(&river_a<>::ignore__));
			operations.update("read", native_mutation_t<river_a<>>::val(&river_a<>::read__));
			operations.update("tellg", native_extraction_t<river_a<>>::val(&river_a<>::tellg__));
			operations.update("seekg_beg", native_mutation_t<river_a<>>::val(&river_a<>::seekg_beg__));
			operations.update("seekg_end", native_mutation_t<river_a<>>::val(&river_a<>::seekg_end__));
			operations.update("seekg_cur", native_mutation_t<river_a<>>::val(&river_a<>::seekg_cur__));
			operations.update("sync", native_mutation_t<river_a<>>::val(&river_a<>::sync__));
			operations.update("put", native_mutation_t<river_a<>>::val(&river_a<>::put__));
			operations.update("write", native_mutation_t<river_a<>>::val(&river_a<>::write__));
			operations.update("tellp", native_extraction_t<river_a<>>::val(&river_a<>::tellp__));
			operations.update("seekp_beg", native_mutation_t<river_a<>>::val(&river_a<>::seekp_beg__));
			operations.update("seekp_end", native_mutation_t<river_a<>>::val(&river_a<>::seekp_end__));
			operations.update("seekp_cur", native_mutation_t<river_a<>>::val(&river_a<>::seekp_cur__));
			operations.update("flush", native_mutation_t<river_a<>>::val(&river_a<>::flush__));
			operations.update("good", native_extraction_t<river_a<>>::val(&river_a<>::good__));
			operations.update("eof", native_extraction_t<river_a<>>::val(&river_a<>::eof__));
			operations.update("fail", native_extraction_t<river_a<>>::val(&river_a<>::fail__));
			operations.update("bad", native_extraction_t<river_a<>>::val(&river_a<>::bad__));
			operations.update("set_good", native_mutation_t<river_a<>>::val(&river_a<>::set_good__));
			operations.update("set_eof", native_mutation_t<river_a<>>::val(&river_a<>::set_eof__));
			operations.update("set_fail", native_mutation_t<river_a<>>::val(&river_a<>::set_fail__));
			operations.update("set_bad", native_mutation_t<river_a<>>::val(&river_a<>::set_bad__));
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

	static inline void share(shoal_a<> const& shoal)
	{
		auto ref = shoal_a<>(shoal, true);
		ref.update("strange::river::val", native_function_t<>::val(&river_t<>::val__));
	}
};

}

#endif
