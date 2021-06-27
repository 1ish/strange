#ifndef COM_ONEISH__STRANGE__GROUP_A_H
#define COM_ONEISH__STRANGE__GROUP_A_H

namespace strange
{
	template <typename element_d>
	struct group_o :
		collection_o<element_d, element_d, element_d>
	{
		var<group_a<>> (*to_collection_any) (con<group_a<element_d>> const& me);

		void (*update_element) (var<group_a<element_d>> const& me,
			element_d const& element);

		bool (*insert_element) (var<group_a<element_d>> const& me,
			element_d const& element);
	};

	template <typename element_d>
	struct group_a
	{
		using non_mutator_range = bool;
		using operations = group_o<element_d>;
		using creator_fp = var<group_a<element_d>> (*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
