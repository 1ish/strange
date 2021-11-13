#ifndef COM_ONEISH__STRANGE__FORWARD_TUPLE_MUTATOR_A_H
#define COM_ONEISH__STRANGE__FORWARD_TUPLE_MUTATOR_A_H

namespace strange
{
	template <typename... elements_d>
	struct forward_tuple_mutator_o :
		forward_mutator_o<var<tuple_a<elements_d...>>>
	{
		var<list_a<>> (*list) (con<forward_tuple_mutator_a<elements_d...>> const& me);

		void (*destruct) (con<forward_tuple_mutator_a<elements_d...>> const& me,
			elements_d&... elements);

		void (*restruct) (con<forward_tuple_mutator_a<elements_d...>> const& me,
			elements_d const&... elements);
	};

	template <typename... elements_d>
	struct forward_tuple_mutator_a
	{
		using operations = forward_tuple_mutator_o<elements_d...>;
		using creator_fp = fit<forward_tuple_mutator_a<elements_d...>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
