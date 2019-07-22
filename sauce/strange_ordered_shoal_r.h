#ifndef COM_ONEISH_STRANGE_ORDERED_SHOAL_R_H
#define COM_ONEISH_STRANGE_ORDERED_SHOAL_R_H

namespace strange
{

template<>
class reflection<ordered_shoal_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::ordered_shoal");
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

	static inline unordered_shoal_a<> operations()
	{
		return reflection<shoal_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___ordered_shoal_a_share___
{
	static inline bool ___share___()
	{
		return ordered_shoal_a<>::___share___;
	}
};

template<>
class reflection<ordered_shoal_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::ordered_shoal");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::ordered_shoal::val", native_function_t<>::val(&ordered_shoal_t<>::val__));
	}
};

template<>
class reflection<ordered_shoal_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::ordered_shoal_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::ordered_shoal_concurrent::val", native_function_t<>::val(&ordered_shoal_t<true>::val__));
	}
};

class ___ordered_shoal_t_share___
{
	static inline bool ___share___()
	{
		return ordered_shoal_t<>::___share___
			&& ordered_shoal_t<true>::___share___;
	}
};

}

#endif
