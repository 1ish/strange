#ifndef COM_ONEISH__STRANGE__COLLECTION_A_H
#define COM_ONEISH__STRANGE__COLLECTION_A_H

namespace strange
{
	template <typename key_d, typename value_d, typename element_d>
	struct collection_o : range_o<element_d>
	{
		var<>(*write_lock)(var<collection_a<key_d, value_d, element_d>> const& me);

		var<collection_a<>> (*to_collection_any)(var<collection_a<key_d, value_d, element_d>> const& me);
	};

	template <typename key_d, typename value_d, typename element_d>
	struct collection_a
	{
		using is_mutator = bool;
		using operations = collection_o<key_d, value_d, element_d>;
		using creator_fp = var<collection_a<key_d, value_d, element_d>>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
