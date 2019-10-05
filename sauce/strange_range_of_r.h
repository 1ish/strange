#ifndef COM_ONEISH_STRANGE_RANGE_OF_R_H
#define COM_ONEISH_STRANGE_RANGE_OF_R_H

namespace strange
{

template<typename _element_>
class reflection<range_of_a<_element_>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::range_of",
			flock_t<>::create_(cat_t<>::create(2, "strange::any")));
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
		static kind_a<> KIND = kind_from_cat(cat(), flock_t<>::create_(reflection<_element_>::cat()));
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<any_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update_string("cbegin", native_extraction_t<range_of_a<_element_>>::create(&range_of_a<_element_>::cbegin__));
			operations.update_string("cend", native_extraction_t<range_of_a<_element_>>::create(&range_of_a<_element_>::cend__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___range_of_a_share___
{
	static inline bool ___share___()
	{
		return range_of_a<>::___share___;
	}
};

template<typename _element_>
class reflection<range_of_t<_element_>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::range_of" + reflection<_element_>::cat().to_string());
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type().to_string() + "::create", native_function_t<>::create(&range_of_t<_element_>::create__));
	}
};

class ___range_of_t_share___
{
	static inline bool ___share___()
	{
		return range_of_t<>::___share___;
	}
};

}

#endif
