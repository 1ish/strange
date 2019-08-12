#ifndef COM_ONEISH_STRANGE_BROOK_R_H
#define COM_ONEISH_STRANGE_BROOK_R_H

namespace strange
{

template<typename PRIMITIVE>
class reflection<brook_a<PRIMITIVE>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::brook_" + number_u<PRIMITIVE>::category());
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
			kinds.insert(kind());
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

template<typename PRIMITIVE, bool CONCURRENT>
class reflection<brook_t<PRIMITIVE, CONCURRENT>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::brook_" + number_u<PRIMITIVE>::category() +
			(CONCURRENT ? "_concurrent" : ""));
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type().to_string() + "::val", native_function_t<>::val(&brook_t<PRIMITIVE, CONCURRENT>::val__));
	}
};

class ___brook_t_share___
{
	static inline bool ___share___()
	{
		return brook_int_8_t<>::___share___
			&& brook_uint_8_t<>::___share___
			&& brook_int_16_t<>::___share___
			&& brook_uint_16_t<>::___share___
			&& brook_int_32_t<>::___share___
			&& brook_uint_32_t<>::___share___
			&& brook_int_64_t<>::___share___
			&& brook_uint_64_t<>::___share___
			&& brook_float_32_t<>::___share___
			&& brook_float_64_t<>::___share___
			&& brook_int_8_t<true>::___share___
			&& brook_uint_8_t<true>::___share___
			&& brook_int_16_t<true>::___share___
			&& brook_uint_16_t<true>::___share___
			&& brook_int_32_t<true>::___share___
			&& brook_uint_32_t<true>::___share___
			&& brook_int_64_t<true>::___share___
			&& brook_uint_64_t<true>::___share___
			&& brook_float_32_t<true>::___share___
			&& brook_float_64_t<true>::___share___;
	}
};

}

#endif
