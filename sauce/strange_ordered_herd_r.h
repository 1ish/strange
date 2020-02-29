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
		static cat_a<> CAT = cat_t<>::create(1, "strange::ordered_herd");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<herd_a<>>::cats();
			cats.insert_thing(cat());
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
			auto kinds = reflection<herd_a<>>::kinds();
			kinds.insert_thing(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<herd_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___ordered_herd_a_share___
{
	static inline bool ___share___()
	{
		return ordered_herd_a<>::___share___;
	}
};

}

#endif
