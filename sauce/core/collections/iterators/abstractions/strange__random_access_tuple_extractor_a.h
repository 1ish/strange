#ifndef COM_ONEISH__STRANGE__RANDOM_ACCESS_TUPLE_EXTRACTOR_A_H
#define COM_ONEISH__STRANGE__RANDOM_ACCESS_TUPLE_EXTRACTOR_A_H

namespace strange
{
	template <typename... elements_d>
	struct random_access_tuple_extractor_o :
		bidirectional_tuple_extractor_o<elements_d...>
	{
		bool (*less) (con<random_access_tuple_extractor_a<elements_d...>> const& me,
			con<random_access_tuple_extractor_a<elements_d...>> const& other);

		static inline bool greater(con<random_access_tuple_extractor_a<elements_d...>> const& me,
			con<random_access_tuple_extractor_a<elements_d...>> const& other);

		bool (*less_or_equal) (con<random_access_tuple_extractor_a<elements_d...>> const& me,
			con<random_access_tuple_extractor_a<elements_d...>> const& other);

		static inline bool greater_or_equal(con<random_access_tuple_extractor_a<elements_d...>> const& me,
			con<random_access_tuple_extractor_a<elements_d...>> const& other);

		void (*self_add) (var<random_access_tuple_extractor_a<elements_d...>> const& me,
			int64_t offset);

		rat<random_access_tuple_extractor_a<elements_d...>> (*add) (con<random_access_tuple_extractor_a<elements_d...>> const& me,
			int64_t offset);
	};

	template <typename... elements_d>
	struct random_access_tuple_extractor_a
	{
		using operations = random_access_tuple_extractor_o<elements_d...>;
		using creator_fp = fit<random_access_tuple_extractor_a<elements_d...>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};

	template <typename... elements_d>
	inline bool random_access_tuple_extractor_o<elements_d...>::greater(con<random_access_tuple_extractor_a<elements_d...>> const& me,
		con<random_access_tuple_extractor_a<elements_d...>> const& other)
	{
		return !me.o->less_or_equal(me, other);
	}

	template <typename... elements_d>
	inline bool random_access_tuple_extractor_o<elements_d...>::greater_or_equal(con<random_access_tuple_extractor_a<elements_d...>> const& me,
		con<random_access_tuple_extractor_a<elements_d...>> const& other)
	{
		return !me.o->less(me, other);
	}
}

#endif
