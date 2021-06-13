#ifndef COM_ONEISH__STRANGE__COLLECTION_A_H
#define COM_ONEISH__STRANGE__COLLECTION_A_H

namespace strange
{
	template <typename key_d, typename value_d, typename element_d>
	struct collection_o : range_o<element_d>
	{
		var<> (*write_lock)(var<collection_a<key_d, value_d, element_d>> const& me);

		var<collection_a<>> (*to_collection_any)(var<collection_a<key_d, value_d, element_d>> const& me);

		bool (*has)(con<collection_a<key_d, value_d, element_d>> const& me,
			con<key_d> const& key);

		var<value_d> (*at)(con<collection_a<key_d, value_d, element_d>> const& me,
			con<key_d> const& key);

		void (*update)(var<collection_a<key_d, value_d, element_d>> const& me,
			con<key_d> const& key, con<value_d> const& value);

		bool (*insert)(var<collection_a<key_d, value_d, element_d>> const& me,
			con<key_d> const& key, con<value_d> const& value);

		bool (*erase)(var<collection_a<key_d, value_d, element_d>> const& me,
			con<key_d> const& key);

		void (*clear)(var<collection_a<key_d, value_d, element_d>> const& me);

		int64_t (*size)(con<collection_a<key_d, value_d, element_d>> const& me);

		bool (*empty)(con<collection_a<key_d, value_d, element_d>> const& me);

		void (*push_front)(var<collection_a<key_d, value_d, element_d>> const& me,
			con<element_d> const& element);

		var<element_d> (*pop_front)(var<collection_a<key_d, value_d, element_d>> const& me);

		void (*push_back)(var<collection_a<key_d, value_d, element_d>> const& me,
			con<element_d> const& element);

		var<element_d> (*pop_back)(var<collection_a<key_d, value_d, element_d>> const& me);

		void (*self_assign)(var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		void (*self_add)(var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		var<collection_a<key_d, value_d, element_d>> (*add)(var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		void (*self_subtract)(var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		var<collection_a<key_d, value_d, element_d>> (*subtract)(var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);
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
