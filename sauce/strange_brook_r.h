#ifndef COM_ONEISH_STRANGE_BROOK_R_H
#define COM_ONEISH_STRANGE_BROOK_R_H

namespace strange
{

template<typename _primitive_>
class reflection<brook_a<_primitive_>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::brook_" + number_u<_primitive_>::category());
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<inventory_a<>>::cats();
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
			auto kinds = reflection<inventory_a<>>::kinds();
			kinds.insert_thing(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<inventory_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___brook_a_share___
{
	static inline bool ___share___()
	{
		return brook_a<int8_t>::___share___
			&& brook_a<uint8_t>::___share___
			&& brook_a<int16_t>::___share___
			&& brook_a<uint16_t>::___share___
			&& brook_a<int32_t>::___share___
			&& brook_a<uint32_t>::___share___
			&& brook_a<int64_t>::___share___
			&& brook_a<uint64_t>::___share___
			&& brook_a<float>::___share___
			&& brook_a<double>::___share___;
	}
};

}

#endif
