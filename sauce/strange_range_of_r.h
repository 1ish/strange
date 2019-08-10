#ifndef COM_ONEISH_STRANGE_RANGE_OF_R_H
#define COM_ONEISH_STRANGE_RANGE_OF_R_H

namespace strange
{

template<>
class reflection<range_of_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::range_of");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = cat_to_kind(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = cats_to_kinds(cats());
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update_string("cbegin", native_extraction_t<range_of_a<>>::val(&range_of_a<>::cbegin__));
			operations.update_string("cend", native_extraction_t<range_of_a<>>::val(&range_of_a<>::cend__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

template<>
class reflection<range_of_a<symbol_a<>>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::range_of_symbol");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = cat_to_kind(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = cats_to_kinds(cats());
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update_string("cbegin", native_extraction_t<range_of_a<symbol_a<>>>::val(&range_of_a<symbol_a<>>::cbegin__));
			operations.update_string("cend", native_extraction_t<range_of_a<symbol_a<>>>::val(&range_of_a<symbol_a<>>::cend__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___range_of_a_share___
{
	static inline bool ___share___()
	{
		return range_of_a<>::___share___
			&& range_of_a<symbol_a<>>::___share___;
	}
};

template<>
class reflection<range_of_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::range_of");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::range_of::val", native_function_t<>::val(&range_of_t<>::val__));
	}
};

template<>
class reflection<range_of_t<symbol_a<>>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::range_of_symbol");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::range_of_symbol::val", native_function_t<>::val(&range_of_t<symbol_a<>>::val__));
	}
};

class ___range_of_t_share___
{
	static inline bool ___share___()
	{
		return range_of_t<>::___share___
			&& range_of_t<symbol_a<>>::___share___;
	}
};

}

#endif
