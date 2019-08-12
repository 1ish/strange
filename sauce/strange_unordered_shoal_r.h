#ifndef COM_ONEISH_STRANGE_UNORDERED_SHOAL_R_H
#define COM_ONEISH_STRANGE_UNORDERED_SHOAL_R_H

namespace strange
{

template<>
class reflection<unordered_shoal_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::unordered_shoal");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<shoal_a<>>::cats();
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
		static unordered_herd_a<> KINDS = kinds_from_cats(cats());
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<shoal_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___unordered_shoal_a_share___
{
	static inline bool ___share___()
	{
		return unordered_shoal_a<>::___share___;
	}
};

template<>
class reflection<unordered_shoal_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::unordered_shoal");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::unordered_shoal::val", native_function_t<>::val(&unordered_shoal_t<>::val__));
	}
};

template<>
class reflection<unordered_shoal_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::unordered_shoal_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::unordered_shoal_concurrent::val", native_function_t<>::val(&unordered_shoal_t<true>::val__));
	}
};

class ___unordered_shoal_t_share___
{
	static inline bool ___share___()
	{
		return unordered_shoal_t<>::___share___
			&& unordered_shoal_t<true>::___share___;
	}
};

}

#endif
