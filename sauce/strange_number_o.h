#ifndef COM_ONEISH_STRANGE_NUMBER_O_H
#define COM_ONEISH_STRANGE_NUMBER_O_H

namespace strange
{

template<>
class abstraction<number_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::number"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = abstraction<any_a<>>::operations();
			operations.update("increment", native_mutation_t<number_a<>>::val(&number_a<>::increment__));
			operations.update("decrement", native_mutation_t<number_a<>>::val(&number_a<>::decrement__));
			operations.update("self_add", native_mutation_t<number_a<>>::val(&number_a<>::self_add__));
			operations.update("add", native_extraction_t<number_a<>>::val(&number_a<>::add__));
			operations.update("self_subtract", native_mutation_t<number_a<>>::val(&number_a<>::self_subtract__));
			operations.update("subtract", native_extraction_t<number_a<>>::val(&number_a<>::subtract__));
			operations.update("self_multiply", native_mutation_t<number_a<>>::val(&number_a<>::self_multiply__));
			operations.update("multiply", native_extraction_t<number_a<>>::val(&number_a<>::multiply__));
			operations.update("self_divide", native_mutation_t<number_a<>>::val(&number_a<>::self_divide__));
			operations.update("divide", native_extraction_t<number_a<>>::val(&number_a<>::divide__));
			operations.update("self_modulo", native_mutation_t<number_a<>>::val(&number_a<>::self_modulo__));
			operations.update("modulo", native_extraction_t<number_a<>>::val(&number_a<>::modulo__));
			operations.update("to_int_64", native_extraction_t<number_a<>>::val(&number_a<>::to_int_64__));
			operations.update("from_int_64", native_mutation_t<number_a<>>::val(&number_a<>::from_int_64__));
			operations.update("to_uint_64", native_extraction_t<number_a<>>::val(&number_a<>::to_uint_64__));
			operations.update("from_uint_64", native_mutation_t<number_a<>>::val(&number_a<>::from_uint_64__));
			operations.update("to_float_64", native_extraction_t<number_a<>>::val(&number_a<>::to_float_64__));
			operations.update("from_float_64", native_mutation_t<number_a<>>::val(&number_a<>::from_float_64__));
			operations.update("less_than", native_extraction_t<number_a<>>::val(&number_a<>::less_than__));
			operations.update("greater_than", native_extraction_t<number_a<>>::val(&number_a<>::greater_than__));
			operations.update("less_or_equal", native_extraction_t<number_a<>>::val(&number_a<>::less_or_equal__));
			operations.update("greater_or_equal", native_extraction_t<number_a<>>::val(&number_a<>::greater_or_equal__));
			operations.update("byte_size", native_extraction_t<number_a<>>::val(&number_a<>::byte_size__));
			operations.update("is_int", native_extraction_t<number_a<>>::val(&number_a<>::is_int__));
			operations.update("is_signed", native_extraction_t<number_a<>>::val(&number_a<>::is_signed__));
			operations.update("is_nan", native_extraction_t<number_a<>>::val(&number_a<>::is_nan__));
			operations.update("is_inf", native_extraction_t<number_a<>>::val(&number_a<>::is_inf__));
			operations.update("is_finite", native_extraction_t<number_a<>>::val(&number_a<>::is_finite__));
			operations.update("is_normal", native_extraction_t<number_a<>>::val(&number_a<>::is_normal__));
			operations.update("little_endian", native_extraction_t<number_a<>>::val(&number_a<>::little_endian__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
