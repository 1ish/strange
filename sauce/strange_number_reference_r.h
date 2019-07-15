#ifndef COM_ONEISH_STRANGE_NUMBER_REFERENCE_R_H
#define COM_ONEISH_STRANGE_NUMBER_REFERENCE_R_H

namespace strange
{

template<>
class reflection<number_reference_int_8_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_int_8");
		return TYPE;
	}
};

template<>
class reflection<number_reference_uint_8_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_uint_8");
		return TYPE;
	}
};

template<>
class reflection<number_reference_int_16_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_int_16");
		return TYPE;
	}
};

template<>
class reflection<number_reference_uint_16_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_uint_16");
		return TYPE;
	}
};

template<>
class reflection<number_reference_int_32_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_int_32");
		return TYPE;
	}
};

template<>
class reflection<number_reference_uint_32_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_uint_32");
		return TYPE;
	}
};

template<>
class reflection<number_reference_int_64_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_int_64");
		return TYPE;
	}
};

template<>
class reflection<number_reference_uint_64_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_uint_64");
		return TYPE;
	}
};

template<>
class reflection<number_reference_float_32_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_float_32");
		return TYPE;
	}
};

template<>
class reflection<number_reference_float_64_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_float_64");
		return TYPE;
	}
};

}

#endif
