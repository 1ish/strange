#ifndef COM_ONEISH_STRANGE_ORDERED_HERD_R_H
#define COM_ONEISH_STRANGE_ORDERED_HERD_R_H

namespace strange
{

template<>
class reflection<ordered_herd_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::ordered_herd");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<herd_a<>>::cats();
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
		return reflection<herd_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___ordered_herd_a_share___
{
	static inline bool ___share___()
	{
		return ordered_herd_a<>::___share___;
	}
};

template<>
class reflection<ordered_herd_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::ordered_herd");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::ordered_herd::val", native_function_t<>::val(&ordered_herd_t<>::val__));
	}
};

template<>
class reflection<ordered_herd_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::ordered_herd_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::ordered_herd_concurrent::val", native_function_t<>::val(&ordered_herd_t<true>::val__));
	}
};

class ___ordered_herd_t_share___
{
	static inline bool ___share___()
	{
		return ordered_herd_t<>::___share___
			&& ordered_herd_t<true>::___share___;
	}
};

}

#endif
