#ifndef COM_ONEISH_STRANGE_LAKE_R_H
#define COM_ONEISH_STRANGE_LAKE_R_H

namespace strange
{

template<>
class reflection<lake_a<int8_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::lake_int_8");
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
class reflection<lake_a<uint8_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::lake_uint_8");
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
class reflection<lake_a<int16_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::lake_int_16");
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
class reflection<lake_a<uint16_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::lake_uint_16");
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
class reflection<lake_a<int32_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::lake_int_32");
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
class reflection<lake_a<uint32_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::lake_uint_32");
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
class reflection<lake_a<int64_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::lake_int_64");
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
class reflection<lake_a<uint64_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::lake_uint_64");
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
class reflection<lake_a<float>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::lake_float_32");
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
class reflection<lake_a<double>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::lake_float_64");
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
class reflection<lake_int_8_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_int_8");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_int_8::val", native_function_t<>::val(&lake_int_8_t<>::val__));
	}
};

template<>
class reflection<lake_uint_8_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_uint_8");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_uint_8::val", native_function_t<>::val(&lake_uint_8_t<>::val__));
	}
};

template<>
class reflection<lake_int_16_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_int_16");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_int_16::val", native_function_t<>::val(&lake_int_16_t<>::val__));
	}
};

template<>
class reflection<lake_uint_16_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_uint_16");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_uint_16::val", native_function_t<>::val(&lake_uint_16_t<>::val__));
	}
};

template<>
class reflection<lake_int_32_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_int_32");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_int_32::val", native_function_t<>::val(&lake_int_32_t<>::val__));
	}
};

template<>
class reflection<lake_uint_32_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_uint_32");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_uint_32::val", native_function_t<>::val(&lake_uint_32_t<>::val__));
	}
};

template<>
class reflection<lake_int_64_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_int_64");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_int_64::val", native_function_t<>::val(&lake_int_64_t<>::val__));
	}
};

template<>
class reflection<lake_uint_64_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_uint_64");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_uint_64::val", native_function_t<>::val(&lake_uint_64_t<>::val__));
	}
};

template<>
class reflection<lake_float_32_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_float_32");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_float_32::val", native_function_t<>::val(&lake_float_32_t<>::val__));
	}
};

template<>
class reflection<lake_float_64_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_float_64");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_float_64::val", native_function_t<>::val(&lake_float_64_t<>::val__));
	}
};

template<>
class reflection<lake_int_8_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_int_8_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_int_8_concurrent::val", native_function_t<>::val(&lake_int_8_t<true>::val__));
	}
};

template<>
class reflection<lake_uint_8_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_uint_8_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_uint_8_concurrent::val", native_function_t<>::val(&lake_uint_8_t<true>::val__));
	}
};

template<>
class reflection<lake_int_16_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_int_16_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_int_16_concurrent::val", native_function_t<>::val(&lake_int_16_t<true>::val__));
	}
};

template<>
class reflection<lake_uint_16_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_uint_16_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_uint_16_concurrent::val", native_function_t<>::val(&lake_uint_16_t<true>::val__));
	}
};

template<>
class reflection<lake_int_32_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_int_32_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_int_32_concurrent::val", native_function_t<>::val(&lake_int_32_t<true>::val__));
	}
};

template<>
class reflection<lake_uint_32_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_uint_32_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_uint_32_concurrent::val", native_function_t<>::val(&lake_uint_32_t<true>::val__));
	}
};

template<>
class reflection<lake_int_64_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_int_64_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_int_64_concurrent::val", native_function_t<>::val(&lake_int_64_t<true>::val__));
	}
};

template<>
class reflection<lake_uint_64_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_uint_64_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_uint_64_concurrent::val", native_function_t<>::val(&lake_uint_64_t<true>::val__));
	}
};

template<>
class reflection<lake_float_32_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_float_32_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_float_32_concurrent::val", native_function_t<>::val(&lake_float_32_t<true>::val__));
	}
};

template<>
class reflection<lake_float_64_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::lake_float_64_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::lake_float_64_concurrent::val", native_function_t<>::val(&lake_float_64_t<true>::val__));
	}
};

}

#endif
