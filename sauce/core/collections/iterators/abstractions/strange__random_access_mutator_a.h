#ifndef COM_ONEISH__STRANGE__RANDOM_ACCESS_MUTATOR_A_H
#define COM_ONEISH__STRANGE__RANDOM_ACCESS_MUTATOR_A_H

namespace strange
{
	template <typename element_d>
	struct random_access_mutator_o : bidirectional_mutator_o<element_d>
	{
		void (*self_add)(var<random_access_mutator_a<element_d>> const& me,
			int64_t offset);

		rat<random_access_mutator_a<element_d>>(*add)(con<random_access_mutator_a<element_d>> const& me,
			int64_t offset);

		rat<random_access_mutator_a<>>(*to_random_access_mutator_any)(con<random_access_mutator_a<element_d>> const& me);
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
}

#endif
