#ifndef COM_ONEISH__STRANGE__BIDIRECTIONAL_MUTATOR_A_H
#define COM_ONEISH__STRANGE__BIDIRECTIONAL_MUTATOR_A_H

namespace strange
{
	template <typename element_d>
	struct bidirectional_mutator_i
	{
		void (*decrement) (var<bidirectional_mutator_a<element_d>> const& me);

		bit<bidirectional_mutator_a<>> (*to_bidirectional_mutator_any) (con<bidirectional_mutator_a<element_d>> const& me);
	};

	template <typename element_d>
	struct bidirectional_mutator_o :
		any_i,
		forward_mutator_i<element_d>,
		bidirectional_mutator_i<element_d>
	{
	};

	template <typename element_d>
	struct bidirectional_mutator_a
	{
		using interface = bidirectional_mutator_i<element_d>;
		using operations = bidirectional_mutator_o<element_d>;
		using creator_fp = bit<bidirectional_mutator_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
