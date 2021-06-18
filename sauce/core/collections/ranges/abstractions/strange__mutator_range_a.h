#ifndef COM_ONEISH__STRANGE__MUTATOR_RANGE_A_H
#define COM_ONEISH__STRANGE__MUTATOR_RANGE_A_H

namespace strange
{
	template <typename element_d>
	struct mutator_range_i
	{
		fit<forward_mutator_a<element_d>> (*mutator_begin) (var<mutator_range_a<element_d>> const& me);

		fit<forward_mutator_a<element_d>> (*mutator_end) (var<mutator_range_a<element_d>> const& me);

		var<> (*write_lock) (var<mutator_range_a<element_d>> const& me);
	};

	template <typename element_d>
	struct mutator_range_o :
		any_o,
		mutator_range_i<element_d>
	{
	};

	template <typename element_d>
	struct mutator_range_a
	{
		using is_mutator_range = bool;
		using operations = mutator_range_o<element_d>;
		using creator_fp = var<mutator_range_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};

	template <typename mutator_range_d, typename mutator_range_d::is_mutator_range = true>
	inline auto begin(var<mutator_range_d> const& range)
	{
		return range.o->mutator_begin(range);
	}

	template <typename mutator_range_d, typename mutator_range_d::is_mutator_range = true>
	inline auto end(var<mutator_range_d> const& range)
	{
		return range.o->mutator_end(range);
	}

	template <typename mutator_range_d, typename mutator_range_d::is_mutator_range = true>
	inline auto begin(ptr<mutator_range_d> const& range)
	{
		return range.o->mutator_begin(reinterpret_cast<var<mutator_range_d>&>(range));
	}

	template <typename mutator_range_d, typename mutator_range_d::is_mutator_range = true>
	inline auto end(ptr<mutator_range_d> const& range)
	{
		return range.o->mutator_end(reinterpret_cast<var<mutator_range_d>&>(range));
	}
}

#endif
