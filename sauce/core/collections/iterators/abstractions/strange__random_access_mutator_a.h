#ifndef COM_ONEISH__STRANGE__RANDOM_ACCESS_MUTATOR_A_H
#define COM_ONEISH__STRANGE__RANDOM_ACCESS_MUTATOR_A_H

namespace strange
{
	template <typename element_d>
	struct random_access_mutator_o :
		bidirectional_mutator_o<element_d>
	{
		bool (*less) (con<random_access_mutator_a<element_d>> const& me,
			con<random_access_mutator_a<element_d>> const& other);

		static inline bool greater(con<random_access_mutator_a<element_d>> const& me,
			con<random_access_mutator_a<element_d>> const& other);

		bool (*less_or_equal) (con<random_access_mutator_a<element_d>> const& me,
			con<random_access_mutator_a<element_d>> const& other);

		static inline bool greater_or_equal(con<random_access_mutator_a<element_d>> const& me,
			con<random_access_mutator_a<element_d>> const& other);

		void (*self_add) (var<random_access_mutator_a<element_d>> const& me,
			int64_t offset);

		rat<random_access_mutator_a<element_d>> (*add) (con<random_access_mutator_a<element_d>> const& me,
			int64_t offset);
	};

	template <typename element_d>
	struct random_access_mutator_a
	{
		using operations = random_access_mutator_o<element_d>;
		using creator_fp = rat<random_access_mutator_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};

	template <typename element_d>
	inline bool random_access_mutator_o<element_d>::greater(con<random_access_mutator_a<element_d>> const& me,
		con<random_access_mutator_a<element_d>> const& other)
	{
		return !me.o->less_or_equal(me, other);
	}

	template <typename element_d>
	inline bool random_access_mutator_o<element_d>::greater_or_equal(con<random_access_mutator_a<element_d>> const& me,
		con<random_access_mutator_a<element_d>> const& other)
	{
		return !me.o->less(me, other);
	}
}

#endif
