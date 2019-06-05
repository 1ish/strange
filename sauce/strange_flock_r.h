#ifndef COM_ONEISH_STRANGE_FLOCK_R_H
#define COM_ONEISH_STRANGE_FLOCK_R_H

namespace strange
{

template<>
class reflection<flock_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::flock");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<inventory_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<inventory_a<>>::operations();
	}
};

template<>
class reflection<flock_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::flock");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::flock::val", native_function_t<>::val(&flock_t<>::val__));
	}
};

template<>
class reflection<flock_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::flock_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::flock_concurrent::val", native_function_t<>::val(&flock_t<true>::val__));
	}
};

}

#endif
