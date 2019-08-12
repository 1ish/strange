#ifndef COM_ONEISH_STRANGE_NUMBER_DATA_R_H
#define COM_ONEISH_STRANGE_NUMBER_DATA_R_H

namespace strange
{

template<typename PRIMITIVE>
class reflection<number_data_a<PRIMITIVE>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::number_data_" + number_u<PRIMITIVE>::category());
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<number_a<>>::cats();
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
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<number_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<number_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___number_data_a_share___
{
	static inline bool ___share___()
	{
		return number_data_a<int8_t>::___share___
			&& number_data_a<uint8_t>::___share___
			&& number_data_a<int16_t>::___share___
			&& number_data_a<uint16_t>::___share___
			&& number_data_a<int32_t>::___share___
			&& number_data_a<uint32_t>::___share___
			&& number_data_a<int64_t>::___share___
			&& number_data_a<uint64_t>::___share___
			&& number_data_a<float>::___share___
			&& number_data_a<double>::___share___;
	}
};

}

#endif
