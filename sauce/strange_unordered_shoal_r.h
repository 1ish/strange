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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::unordered_shoal"));
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
};

}

#endif
