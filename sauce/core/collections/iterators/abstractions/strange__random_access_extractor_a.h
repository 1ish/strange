#ifndef COM_ONEISH__STRANGE__RANDOM_ACCESS_EXTRACTOR_A_H
#define COM_ONEISH__STRANGE__RANDOM_ACCESS_EXTRACTOR_A_H

namespace strange
{
	template <typename element_d>
	struct random_access_extractor_o : bidirectional_extractor_o<element_d>
	{
		void (*self_add)(var<random_access_extractor_a<element_d>> const& me, int64_t offset);

		var<random_access_extractor_a<element_d>>(*add)(con<random_access_extractor_a<element_d>> const& me, int64_t offset);

		var<random_access_extractor_a<>> (*to_random_access_extractor_any)(con<random_access_extractor_a<element_d>> const& me);
	};

	template <typename element_d>
	struct random_access_extractor_a
	{
		using non_mutator = bool;
		using operations = random_access_extractor_o<element_d>;
		using creator_fp = var<random_access_extractor_a<element_d>>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
