#ifndef COM_ONEISH__STRANGE__NUMBER_A_H
#define COM_ONEISH__STRANGE__NUMBER_A_H

namespace strange
{
	template <typename type_d>
	struct number_o : // operations
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
	struct number_b // base
	{
		mutable thing_t* t;
		mutable number_o<type_d> const* o;
	};

	template <typename base_d, typename type_d>
	struct number_c : // constant
		mutable_numeric_c<base_d>
	{
		using me_d = con<number_a<type_d>>;

		inline bool equal(con<number_a<type_d>> const& other) const;

		inline bool not_equal(con<number_a<type_d>> const& other) const;

		inline bool less(con<number_a<type_d>> const& other) const;

		inline bool greater(con<number_a<type_d>> const& other) const;

		inline bool less_or_equal(con<number_a<type_d>> const& other) const;

		inline bool greater_or_equal(con<number_a<type_d>> const& other) const;

		inline var<data_a<type_d>> data() const;

		inline type_d const& extract() const;

		inline rat<random_access_extractor_a<type_d>> extractor() const;
	};

	template <typename base_d, typename type_d>
	struct number_v : // variable
		mutable_numeric_v<base_d>
	{
		using me_d = var<number_a<type_d>>;

		inline type_d& mutate() const;
	};

	template <typename type_d>
	struct number_a : // abstraction
		number_c<number_b<type_d>, type_d>
	{
		using operations = number_o<type_d>;
		using variations = number_v<number_a<type_d>, type_d>;
		using creator_fp = var<number_a<type_d>>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
