#ifndef COM_ONEISH_STRANGE_LAKE_R_H
#define COM_ONEISH_STRANGE_LAKE_R_H

namespace strange
{

template<typename _primitive_>
class reflection<lake_a<_primitive_>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::lake_" + number_u<_primitive_>::category());
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

class ___lake_a_share___
{
	static inline bool ___share___()
	{
		return lake_a<int8_t>::___share___
			&& lake_a<uint8_t>::___share___
			&& lake_a<int16_t>::___share___
			&& lake_a<uint16_t>::___share___
			&& lake_a<int32_t>::___share___
			&& lake_a<uint32_t>::___share___
			&& lake_a<int64_t>::___share___
			&& lake_a<uint64_t>::___share___
			&& lake_a<float>::___share___
			&& lake_a<double>::___share___;
	}
};

template<typename _primitive_, bool _concurrent_>
class reflection<lake_t<_primitive_, _concurrent_>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_" + number_u<_primitive_>::category() +
			(_concurrent_ ? "_concurrent" : ""));
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type().to_string() + "::create", native_function_t<>::create(&lake_t<_primitive_, _concurrent_>::create__));
	}
};

class ___lake_t_share___
{
	static inline bool ___share___()
	{
		return lake_int_8_t<>::___share___
			&& lake_uint_8_t<>::___share___
			&& lake_int_16_t<>::___share___
			&& lake_uint_16_t<>::___share___
			&& lake_int_32_t<>::___share___
			&& lake_uint_32_t<>::___share___
			&& lake_int_64_t<>::___share___
			&& lake_uint_64_t<>::___share___
			&& lake_float_32_t<>::___share___
			&& lake_float_64_t<>::___share___
			&& lake_int_8_t<true>::___share___
			&& lake_uint_8_t<true>::___share___
			&& lake_int_16_t<true>::___share___
			&& lake_uint_16_t<true>::___share___
			&& lake_int_32_t<true>::___share___
			&& lake_uint_32_t<true>::___share___
			&& lake_int_64_t<true>::___share___
			&& lake_uint_64_t<true>::___share___
			&& lake_float_32_t<true>::___share___
			&& lake_float_64_t<true>::___share___;
	}
};

}

#endif
