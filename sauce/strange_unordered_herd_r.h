#ifndef COM_ONEISH_STRANGE_UNORDERED_HERD_R_H
#define COM_ONEISH_STRANGE_UNORDERED_HERD_R_H

namespace strange
{

template<>
class reflection<unordered_herd_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::unordered_herd");
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

	static inline unordered_shoal_a<> operations()
	{
		return reflection<herd_a<>>::operations();
	}
};

template<>
class reflection<unordered_herd_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::unordered_herd");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::unordered_herd::val", native_function_t<>::val(&unordered_herd_t<>::val__));
	}
};

template<>
class reflection<unordered_herd_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::unordered_herd_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::unordered_herd_concurrent::val", native_function_t<>::val(&unordered_herd_t<true>::val__));
	}
};

}

#endif
