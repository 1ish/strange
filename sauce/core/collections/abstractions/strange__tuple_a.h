#ifndef COM_ONEISH__STRANGE__TUPLE_A_H
#define COM_ONEISH__STRANGE__TUPLE_A_H

namespace strange
{
	template <typename... elements_d>
	struct tuple_o :
		any_o
	{
		var<list_a<>> (*to_list_any) (con<tuple_a<elements_d...>> const& me);

		void (*destruct) (con<tuple_a<elements_d...>> const& me,
			elements_d&... elements);

		void (*restruct) (var<tuple_a<elements_d...>> const& me,
			elements_d const&... elements);
	};

	template <typename... elements_d>
	struct tuple_a
	{
		using operations = tuple_o<elements_d...>;
		using creator_fp = var<tuple_a<elements_d...>> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
