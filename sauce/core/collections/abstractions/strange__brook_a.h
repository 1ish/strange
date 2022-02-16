#ifndef COM_ONEISH__STRANGE__BROOK_A_H
#define COM_ONEISH__STRANGE__BROOK_A_H

namespace strange
{
	struct brook_o : // operations
		queue_o<uint8_t>
	{
	};

	struct brook_b // base
	{
		mutable thing_t* t;
		mutable brook_o const* o;
	};

	template <typename base_d>
	struct brook_c : // constant
		queue_c<base_d, uint8_t>
	{
		using me_d = con<brook_a>;
	};

	template <typename base_d>
	struct brook_v : // variable
		queue_v<base_d, uint8_t>
	{
		using me_d = var<brook_a>;
	};

	struct brook_a : // abstraction
		brook_c<brook_b>
	{
		using non_mutator_range = bool;
		using operations = brook_o;
		using variations = brook_v<brook_a>;
		using creator_fp = var<brook_a> (*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
