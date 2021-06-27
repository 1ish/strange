#ifndef COM_ONEISH__STRANGE__COLLECTION_A_H
#define COM_ONEISH__STRANGE__COLLECTION_A_H

namespace strange
{
	template <typename key_d, typename value_d, typename element_d>
	struct collection_o :
		any_o
	{
		var<range_a<element_d>> (*range) (con<collection_a<key_d, value_d, element_d>> const& me);

		fit<forward_extractor_a<element_d>> (*begin) (con<collection_a<key_d, value_d, element_d>> const& me);

		fit<forward_extractor_a<element_d>> (*end) (con<collection_a<key_d, value_d, element_d>> const& me);

		var<range_a<>> (*to_range_any) (con<collection_a<key_d, value_d, element_d>> const& me);

		var<> (*read_lock) (ptr<collection_a<key_d, value_d, element_d>> const& me);

		var<> (*write_lock) (ptr<collection_a<key_d, value_d, element_d>> const& me);

		var<collection_a<>> (*to_collection_any) (con<collection_a<key_d, value_d, element_d>> const& me);

		bool (*has) (con<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		value_d (*at) (con<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		void (*update) (var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key,
			value_d const& value);

		bool (*insert) (var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key,
			value_d const& value);

		bool (*erase) (var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		void (*clear) (var<collection_a<key_d, value_d, element_d>> const& me);

		int64_t (*size)(con<collection_a<key_d, value_d, element_d>> const& me);

		bool (*empty) (con<collection_a<key_d, value_d, element_d>> const& me);

		void (*push_front) (var<collection_a<key_d, value_d, element_d>> const& me,
			element_d const& element);

		element_d (*pop_front) (var<collection_a<key_d, value_d, element_d>> const& me);

		void (*push_back) (var<collection_a<key_d, value_d, element_d>> const& me,
			element_d const& element);

		element_d (*pop_back) (var<collection_a<key_d, value_d, element_d>> const& me);

		void (*self_assign) (var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		void (*self_add) (var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		var<collection_a<key_d, value_d, element_d>> (*add) (con<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		void (*self_subtract) (var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		var<collection_a<key_d, value_d, element_d>> (*subtract) (con<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);
	};

	template <typename key_d, typename value_d, typename element_d>
	struct collection_a
	{
		using non_mutator_range = bool;
		using operations = collection_o<key_d, value_d, element_d>;
		using creator_fp = var<collection_a<key_d, value_d, element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
