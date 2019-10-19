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
		static cat_a<> CAT = cat_t<>::create(1, "strange::river");
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

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<range_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<range_a<>>::operations();
			operations.update_string("get", native_mutation_t<river_a<>>::create(&river_a<>::get__));
			operations.update_string("peek", native_mutation_t<river_a<>>::create(&river_a<>::peek__));
			operations.update_string("unget", native_mutation_t<river_a<>>::create(&river_a<>::unget__));
			operations.update_string("putback", native_mutation_t<river_a<>>::create(&river_a<>::putback__));
			operations.update_string("getline", native_mutation_t<river_a<>>::create(&river_a<>::getline__));
			operations.update_string("ignore", native_mutation_t<river_a<>>::create(&river_a<>::ignore__));
			operations.update_string("read", native_mutation_t<river_a<>>::create(&river_a<>::read__));
			operations.update_string("tellg", native_extraction_t<river_a<>>::create(&river_a<>::tellg__));
			operations.update_string("seekg_beg", native_mutation_t<river_a<>>::create(&river_a<>::seekg_beg__));
			operations.update_string("seekg_end", native_mutation_t<river_a<>>::create(&river_a<>::seekg_end__));
			operations.update_string("seekg_cur", native_mutation_t<river_a<>>::create(&river_a<>::seekg_cur__));
			operations.update_string("sync", native_mutation_t<river_a<>>::create(&river_a<>::sync__));
			operations.update_string("put", native_mutation_t<river_a<>>::create(&river_a<>::put__));
			operations.update_string("write", native_mutation_t<river_a<>>::create(&river_a<>::write__));
			operations.update_string("tellp", native_extraction_t<river_a<>>::create(&river_a<>::tellp__));
			operations.update_string("seekp_beg", native_mutation_t<river_a<>>::create(&river_a<>::seekp_beg__));
			operations.update_string("seekp_end", native_mutation_t<river_a<>>::create(&river_a<>::seekp_end__));
			operations.update_string("seekp_cur", native_mutation_t<river_a<>>::create(&river_a<>::seekp_cur__));
			operations.update_string("flush", native_mutation_t<river_a<>>::create(&river_a<>::flush__));
			operations.update_string("good", native_extraction_t<river_a<>>::create(&river_a<>::good__));
			operations.update_string("eof", native_extraction_t<river_a<>>::create(&river_a<>::eof__));
			operations.update_string("fail", native_extraction_t<river_a<>>::create(&river_a<>::fail__));
			operations.update_string("bad", native_extraction_t<river_a<>>::create(&river_a<>::bad__));
			operations.update_string("set_good", native_mutation_t<river_a<>>::create(&river_a<>::set_good__));
			operations.update_string("set_eof", native_mutation_t<river_a<>>::create(&river_a<>::set_eof__));
			operations.update_string("set_fail", native_mutation_t<river_a<>>::create(&river_a<>::set_fail__));
			operations.update_string("set_bad", native_mutation_t<river_a<>>::create(&river_a<>::set_bad__));
			operations.update_string("filename", native_extraction_t<river_a<>>::create(&river_a<>::filename__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___river_a_share___
{
	static inline bool ___share___()
	{
		return river_a<>::___share___;
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
		shoal.update_string("strange::river::create", native_function_t<>::create(&river_t<>::create__));
		shoal.update_string("strange::river::file", native_function_t<>::create(&river_t<>::file__));
		shoal.update_string("strange::river::in", native_function_t<>::create(&river_t<>::in__));
		shoal.update_string("strange::river::out", native_function_t<>::create(&river_t<>::out__));
		shoal.update_string("strange::river::err", native_function_t<>::create(&river_t<>::err__));
	}
};

class ___river_t_share___
{
	static inline bool ___share___()
	{
		return river_t<>::___share___;
	}
};

}

#endif
