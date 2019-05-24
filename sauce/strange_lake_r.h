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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::lake_int_8"));
		return CAT;
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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::lake_uint_8"));
		return CAT;
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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::lake_int_16"));
		return CAT;
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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::lake_uint_16"));
		return CAT;
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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::lake_int_32"));
		return CAT;
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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::lake_uint_32"));
		return CAT;
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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::lake_int_64"));
		return CAT;
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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::lake_uint_64"));
		return CAT;
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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::lake_float_32"));
		return CAT;
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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::lake_float_64"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<inventory_a<>>::operations();
	}
};

}

#endif
