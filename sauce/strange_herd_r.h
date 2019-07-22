#ifndef COM_ONEISH_STRANGE_HERD_R_H
#define COM_ONEISH_STRANGE_HERD_R_H

namespace strange
{

template<>
class reflection<herd_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::herd");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<collection_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<collection_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___herd_a_share___
{
	static inline bool ___share___()
	{
		return herd_a<>::___share___;
	}
};

}

#endif
