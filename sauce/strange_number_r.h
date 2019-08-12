#ifndef COM_ONEISH_STRANGE_NUMBER_R_H
#define COM_ONEISH_STRANGE_NUMBER_R_H

namespace strange
{

template<>
class reflection<number_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::number");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
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
			auto kinds = reflection<any_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update_string("increment", native_mutation_t<number_a<>>::val(&number_a<>::increment__));
			operations.update_string("decrement", native_mutation_t<number_a<>>::val(&number_a<>::decrement__));
			operations.update_string("self_add", native_mutation_t<number_a<>>::val(&number_a<>::self_add__));
			operations.update_string("add", native_extraction_t<number_a<>>::val(&number_a<>::add__));
			operations.update_string("self_subtract", native_mutation_t<number_a<>>::val(&number_a<>::self_subtract__));
			operations.update_string("subtract", native_extraction_t<number_a<>>::val(&number_a<>::subtract__));
			operations.update_string("self_multiply", native_mutation_t<number_a<>>::val(&number_a<>::self_multiply__));
			operations.update_string("multiply", native_extraction_t<number_a<>>::val(&number_a<>::multiply__));
			operations.update_string("self_divide", native_mutation_t<number_a<>>::val(&number_a<>::self_divide__));
			operations.update_string("divide", native_extraction_t<number_a<>>::val(&number_a<>::divide__));
			operations.update_string("self_modulo", native_mutation_t<number_a<>>::val(&number_a<>::self_modulo__));
			operations.update_string("modulo", native_extraction_t<number_a<>>::val(&number_a<>::modulo__));
			operations.update_string("to_int_64", native_extraction_t<number_a<>>::val(&number_a<>::to_int_64__));
			operations.update_string("from_int_64", native_mutation_t<number_a<>>::val(&number_a<>::from_int_64__));
			operations.update_string("to_uint_64", native_extraction_t<number_a<>>::val(&number_a<>::to_uint_64__));
			operations.update_string("from_uint_64", native_mutation_t<number_a<>>::val(&number_a<>::from_uint_64__));
			operations.update_string("to_float_64", native_extraction_t<number_a<>>::val(&number_a<>::to_float_64__));
			operations.update_string("from_float_64", native_mutation_t<number_a<>>::val(&number_a<>::from_float_64__));
			operations.update_string("less_than", native_extraction_t<number_a<>>::val(&number_a<>::less_than__));
			operations.update_string("greater_than", native_extraction_t<number_a<>>::val(&number_a<>::greater_than__));
			operations.update_string("less_or_equal", native_extraction_t<number_a<>>::val(&number_a<>::less_or_equal__));
			operations.update_string("greater_or_equal", native_extraction_t<number_a<>>::val(&number_a<>::greater_or_equal__));
			operations.update_string("byte_size", native_extraction_t<number_a<>>::val(&number_a<>::byte_size__));
			operations.update_string("is_int", native_extraction_t<number_a<>>::val(&number_a<>::is_int__));
			operations.update_string("is_signed", native_extraction_t<number_a<>>::val(&number_a<>::is_signed__));
			operations.update_string("is_nan", native_extraction_t<number_a<>>::val(&number_a<>::is_nan__));
			operations.update_string("is_inf", native_extraction_t<number_a<>>::val(&number_a<>::is_inf__));
			operations.update_string("is_finite", native_extraction_t<number_a<>>::val(&number_a<>::is_finite__));
			operations.update_string("is_normal", native_extraction_t<number_a<>>::val(&number_a<>::is_normal__));
			operations.update_string("little_endian", native_extraction_t<number_a<>>::val(&number_a<>::little_endian__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___number_a_share___
{
	static inline bool ___share___()
	{
		return number_a<>::___share___;
	}
};

template<>
class reflection<number_int_8_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_int_8");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::number_int_8::val", native_function_t<>::val(&number_int_8_t<>::val__));
	}
};

template<>
class reflection<number_uint_8_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_uint_8");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::number_uint_8::val", native_function_t<>::val(&number_uint_8_t<>::val__));
	}
};

template<>
class reflection<number_int_16_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_int_16");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::number_int_16::val", native_function_t<>::val(&number_int_16_t<>::val__));
	}
};

template<>
class reflection<number_uint_16_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_uint_16");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::number_uint_16::val", native_function_t<>::val(&number_uint_16_t<>::val__));
	}
};

template<>
class reflection<number_int_32_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_int_32");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::number_int_32::val", native_function_t<>::val(&number_int_32_t<>::val__));
	}
};

template<>
class reflection<number_uint_32_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_uint_32");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::number_uint_32::val", native_function_t<>::val(&number_uint_32_t<>::val__));
	}
};

template<>
class reflection<number_int_64_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_int_64");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::number_int_64::val", native_function_t<>::val(&number_int_64_t<>::val__));
	}
};

template<>
class reflection<number_uint_64_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_uint_64");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::number_uint_64::val", native_function_t<>::val(&number_uint_64_t<>::val__));
	}
};

template<>
class reflection<number_float_32_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_float_32");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::number_float_32::val", native_function_t<>::val(&number_float_32_t<>::val__));
	}
};

template<>
class reflection<number_float_64_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_float_64");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::number_float_64::val", native_function_t<>::val(&number_float_64_t<>::val__));
	}
};

class ___number_t_share___
{
	static inline bool ___share___()
	{
		return number_int_8_t<>::___share___
			&& number_uint_8_t<>::___share___
			&& number_int_16_t<>::___share___
			&& number_uint_16_t<>::___share___
			&& number_int_32_t<>::___share___
			&& number_uint_32_t<>::___share___
			&& number_int_64_t<>::___share___
			&& number_uint_64_t<>::___share___
			&& number_float_32_t<>::___share___
			&& number_float_64_t<>::___share___;
	}
};

}

#endif
