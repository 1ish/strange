#ifndef COM_ONEISH__STRANGE__NUMBER_A_H
#define COM_ONEISH__STRANGE__NUMBER_A_H

namespace strange
{
	template <typename type_d>
	struct number_o :
		mutable_numeric_o
	{
		bool (*equal) (con<number_a<type_d>> const& me,
			con<number_a<type_d>> const& other);

		static inline bool not_equal(con<number_a<type_d>> const& me,
			con<number_a<type_d>> const& other);

		bool (*less) (con<number_a<type_d>> const& me,
			con<number_a<type_d>> const& other);

		static inline bool greater(con<number_a<type_d>> const& me,
			con<number_a<type_d>> const& other);

		bool (*less_or_equal) (con<number_a<type_d>> const& me,
			con<number_a<type_d>> const& other);

		static inline bool greater_or_equal(con<number_a<type_d>> const& me,
			con<number_a<type_d>> const& other);

		var<data_a<type_d>> (*data) (con<number_a<type_d>> const& me);

		type_d const& (*extract) (con<number_a<type_d>> const& me);

		type_d& (*mutate) (var<number_a<type_d>> const& me);

		rat<random_access_extractor_a<type_d>> (*extractor) (con<number_a<type_d>> const& me);
	};

	template <typename type_d>
	struct number_a
	{
		using operations = number_o<type_d>;
		using variations = any_v<number_a<type_d>>;
		using creator_fp = var<number_a<type_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};

	template <typename type_d>
	inline bool number_o<type_d>::not_equal(con<number_a<type_d>> const& me,
		con<number_a<type_d>> const& other)
	{
		return !me.o->equal(me, other);
	}

	template <typename type_d>
	inline bool number_o<type_d>::greater(con<number_a<type_d>> const& me,
		con<number_a<type_d>> const& other)
	{
		return !me.o->less_or_equal(me, other);
	}

	template <typename type_d>
	inline bool number_o<type_d>::greater_or_equal(con<number_a<type_d>> const& me,
		con<number_a<type_d>> const& other)
	{
		return !me.o->less(me, other);
	}
}

#endif
