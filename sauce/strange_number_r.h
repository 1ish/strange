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
		static cat_a<> CAT = cat_t<>::create(1, "strange::number");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
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
			auto kinds = reflection<any_a<>>::kinds();
			kinds.insert_thing(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update_string("increment_", native_mutation_t<number_a<>>::create(&number_a<>::increment__));
			operations.update_string("decrement_", native_mutation_t<number_a<>>::create(&number_a<>::decrement__));
			operations.update_string("self_assign_", native_mutation_t<number_a<>>::create(&number_a<>::self_assign__));
			operations.update_string("self_add_", native_mutation_t<number_a<>>::create(&number_a<>::self_add__));
			operations.update_string("add_", native_extraction_t<number_a<>>::create(&number_a<>::add__));
			operations.update_string("self_subtract_", native_mutation_t<number_a<>>::create(&number_a<>::self_subtract__));
			operations.update_string("subtract_", native_extraction_t<number_a<>>::create(&number_a<>::subtract__));
			operations.update_string("self_multiply_", native_mutation_t<number_a<>>::create(&number_a<>::self_multiply__));
			operations.update_string("multiply_", native_extraction_t<number_a<>>::create(&number_a<>::multiply__));
			operations.update_string("self_divide_", native_mutation_t<number_a<>>::create(&number_a<>::self_divide__));
			operations.update_string("divide_", native_extraction_t<number_a<>>::create(&number_a<>::divide__));
			operations.update_string("self_modulo_", native_mutation_t<number_a<>>::create(&number_a<>::self_modulo__));
			operations.update_string("modulo_", native_extraction_t<number_a<>>::create(&number_a<>::modulo__));
			operations.update_string("to_int_64_", native_extraction_t<number_a<>>::create(&number_a<>::to_int_64__));
			operations.update_string("from_int_64_", native_mutation_t<number_a<>>::create(&number_a<>::from_int_64__));
			operations.update_string("to_uint_64_", native_extraction_t<number_a<>>::create(&number_a<>::to_uint_64__));
			operations.update_string("from_uint_64_", native_mutation_t<number_a<>>::create(&number_a<>::from_uint_64__));
			operations.update_string("to_float_64_", native_extraction_t<number_a<>>::create(&number_a<>::to_float_64__));
			operations.update_string("from_float_64_", native_mutation_t<number_a<>>::create(&number_a<>::from_float_64__));
			operations.update_string("less_than_", native_extraction_t<number_a<>>::create(&number_a<>::less_than__));
			operations.update_string("greater_than_", native_extraction_t<number_a<>>::create(&number_a<>::greater_than__));
			operations.update_string("less_or_equal_", native_extraction_t<number_a<>>::create(&number_a<>::less_or_equal__));
			operations.update_string("greater_or_equal_", native_extraction_t<number_a<>>::create(&number_a<>::greater_or_equal__));
			operations.update_string("byte_size_", native_extraction_t<number_a<>>::create(&number_a<>::byte_size__));
			operations.update_string("is_int_", native_extraction_t<number_a<>>::create(&number_a<>::is_int__));
			operations.update_string("is_signed_", native_extraction_t<number_a<>>::create(&number_a<>::is_signed__));
			operations.update_string("is_nan_", native_extraction_t<number_a<>>::create(&number_a<>::is_nan__));
			operations.update_string("is_inf_", native_extraction_t<number_a<>>::create(&number_a<>::is_inf__));
			operations.update_string("is_finite_", native_extraction_t<number_a<>>::create(&number_a<>::is_finite__));
			operations.update_string("is_normal_", native_extraction_t<number_a<>>::create(&number_a<>::is_normal__));
			operations.update_string("little_endian_", native_extraction_t<number_a<>>::create(&number_a<>::little_endian__));
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

}

#endif
