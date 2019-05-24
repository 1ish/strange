#ifndef COM_ONEISH_STRANGE_BROOK_O_H
#define COM_ONEISH_STRANGE_BROOK_O_H

namespace strange
{

template<>
class abstraction<brook_a<int8_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::brook_int_8"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<inventory_a<>>::operations();
	}
};

template<>
class abstraction<brook_a<uint8_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::brook_uint_8"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<inventory_a<>>::operations();
	}
};

template<>
class abstraction<brook_a<int16_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::brook_int_16"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<inventory_a<>>::operations();
	}
};

template<>
class abstraction<brook_a<uint16_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::brook_uint_16"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<inventory_a<>>::operations();
	}
};

template<>
class abstraction<brook_a<int32_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::brook_int_32"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<inventory_a<>>::operations();
	}
};

template<>
class abstraction<brook_a<uint32_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::brook_uint_32"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<inventory_a<>>::operations();
	}
};

template<>
class abstraction<brook_a<int64_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::brook_int_64"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<inventory_a<>>::operations();
	}
};

template<>
class abstraction<brook_a<uint64_t>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::brook_uint_64"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<inventory_a<>>::operations();
	}
};

template<>
class abstraction<brook_a<float>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::brook_float_32"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<inventory_a<>>::operations();
	}
};

template<>
class abstraction<brook_a<double>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::brook_float_64"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<inventory_a<>>::operations();
	}
};

}

#endif
