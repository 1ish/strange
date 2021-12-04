#ifndef COM_ONEISH__STRANGE__ORDERED_TABLE_T_H
#define COM_ONEISH__STRANGE__ORDERED_TABLE_T_H

namespace strange
{
	template <typename collection_d, typename key_d, typename value_d>
	struct ordered_table_t : table_t<collection_d, key_d, value_d>
	{
		using element_d = var<tuple_a<key_d, value_d>>;

	protected:
		inline ordered_table_t(any_a const& me)
			: table_t<collection_d, key_d, value_d>{ me }
		{
			me.o = ordered_table_t<collection_d, key_d, value_d>::_operations();
		}

		inline ordered_table_t(any_a const& me,
			collection_d const& collection)
			: table_t<collection_d, key_d, value_d>{ me, collection }
		{
			me.o = ordered_table_t<collection_d, key_d, value_d>::_operations();
		}

		inline ordered_table_t(any_a const& me,
			any_a const& original)
			: table_t<collection_d, key_d, value_d>{ me, original }
		{
			me.o = ordered_table_t<collection_d, key_d, value_d>::_operations();
		}

		ordered_table_t(ordered_table_t const&) = delete;
		ordered_table_t& operator=(ordered_table_t const&) = delete;

	private:
		// pair_ordered_table_o
		static pair_ordered_table_o<key_d, value_d> const* _operations();
		static pair_ordered_table_o<key_d, value_d> const* _pointer_operations();

	protected:
		// any_a
		static bool is(con<> const& me,
			con<> const& abstraction);

		static bool as(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type(con<> const& me);

		static void _copy(con<> const& me,
			var<> const& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

		// ordered_table_a
		static var<bidirectional_tuple_range_a<key_d, value_d>> range(con<ordered_table_a<key_d, value_d>> const& me);

		static bit<bidirectional_tuple_extractor_a<key_d, value_d>> begin(con<ordered_table_a<key_d, value_d>> const& me);

		static bit<bidirectional_tuple_extractor_a<key_d, value_d>> end(con<ordered_table_a<key_d, value_d>> const& me);

		static var<bidirectional_tuple_mutator_range_a<key_d, value_d>> mutator_range(var<ordered_table_a<key_d, value_d>> const& me);

		static bit<bidirectional_tuple_mutator_a<key_d, value_d>> mutator_begin(var<ordered_table_a<key_d, value_d>> const& me);

		static bit<bidirectional_tuple_mutator_a<key_d, value_d>> mutator_end(var<ordered_table_a<key_d, value_d>> const& me);

		// pair_ordered_table_a
		static var<pair_table_a<key_d, value_d>> pair_table(con<pair_ordered_table_a<key_d, value_d>> const& me);

		static var<bidirectional_range_a<std::pair<key_d const, value_d>>> pair_range(con<pair_ordered_table_a<key_d, value_d>> const& me);

		static bit<bidirectional_extractor_a<std::pair<key_d const, value_d>>> pair_begin(con<pair_ordered_table_a<key_d, value_d>> const& me);

		static bit<bidirectional_extractor_a<std::pair<key_d const, value_d>>> pair_end(con<pair_ordered_table_a<key_d, value_d>> const& me);

		static var<bidirectional_mutator_range_a<std::pair<key_d const, value_d>>> pair_mutator_range(var<pair_ordered_table_a<key_d, value_d>> const& me);

		static bit<bidirectional_mutator_a<std::pair<key_d const, value_d>>> pair_mutator_begin(var<pair_ordered_table_a<key_d, value_d>> const& me);

		static bit<bidirectional_mutator_a<std::pair<key_d const, value_d>>> pair_mutator_end(var<pair_ordered_table_a<key_d, value_d>> const& me);

	private:
		// bidirectional_tuple_range_a
		static bidirectional_tuple_range_o<key_d, value_d> const* _range_operations();
		static bidirectional_tuple_range_o<key_d, value_d> const* _range_pointer_operations();

	protected:
		static bool _range_is(con<> const& me,
			con<> const& abstraction);

		static bool _range_as(con<> const& me,
			var<> const& abstraction);

		//TODO hash / equal / less / less_or_equal

		static void _range_copy(con<> const& me,
			var<> const& copy);

		static void _range_set_pointer(con<> const& me,
			bool is_pointer);

	private:
		// bidirectional_tuple_mutator_range_a
		static bidirectional_tuple_mutator_range_o<key_d, value_d> const* _mutator_range_operations();
		static bidirectional_tuple_mutator_range_o<key_d, value_d> const* _mutator_range_pointer_operations();

	protected:
		static bool _mutator_range_is(con<> const& me,
			con<> const& abstraction);

		static bool _mutator_range_as(con<> const& me,
			var<> const& abstraction);

		//TODO hash / equal / less / less_or_equal

		static void _mutator_range_copy(con<> const& me,
			var<> const& copy);

		static void _mutator_range_set_pointer(con<> const& me,
			bool is_pointer);

	private:
		// pair_ordered_table_a
		static pair_table_o<key_d, value_d> const* _pair_table_operations();
		static pair_table_o<key_d, value_d> const* _pair_table_pointer_operations();

	protected:
		static bool _pair_table_is(con<> const& me,
			con<> const& abstraction);

		static bool _pair_table_as(con<> const& me,
			var<> const& abstraction);

		//TODO hash / equal / less / less_or_equal

		static void _pair_table_copy(con<> const& me,
			var<> const& copy);

		static void _pair_table_set_pointer(con<> const& me,
			bool is_pointer);

	private:
		// bidirectional_range_a
		static bidirectional_range_o<std::pair<key_d const, value_d>> const* _pair_range_operations();
		static bidirectional_range_o<std::pair<key_d const, value_d>> const* _pair_range_pointer_operations();

	protected:
		static bool _pair_range_is(con<> const& me,
			con<> const& abstraction);

		static bool _pair_range_as(con<> const& me,
			var<> const& abstraction);

		//TODO hash / equal / less / less_or_equal

		static void _pair_range_copy(con<> const& me,
			var<> const& copy);

		static void _pair_range_set_pointer(con<> const& me,
			bool is_pointer);

	private:
		// bidirectional_mutator_range_a
		static bidirectional_mutator_range_o<std::pair<key_d const, value_d>> const* _pair_mutator_range_operations();
		static bidirectional_mutator_range_o<std::pair<key_d const, value_d>> const* _pair_mutator_range_pointer_operations();

	protected:
		static bool _pair_mutator_range_is(con<> const& me,
			con<> const& abstraction);

		static bool _pair_mutator_range_as(con<> const& me,
			var<> const& abstraction);

		//TODO hash / equal / less / less_or_equal

		static void _pair_mutator_range_copy(con<> const& me,
			var<> const& copy);

		static void _pair_mutator_range_set_pointer(con<> const& me,
			bool is_pointer);

	public:
		// creators
		static inline var<pair_ordered_table_a<key_d, value_d>> create_default()
		{
			any_a r;
			new ordered_table_t<collection_d, key_d, value_d>{ r };
			ordered_table_t<collection_d, key_d, value_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<pair_ordered_table_a<key_d, value_d>>{ reinterpret_cast<pair_ordered_table_a<key_d, value_d>&>(r) };
		}

		static inline var<pair_ordered_table_a<key_d, value_d>> create(collection_d const& collection)
		{
			any_a r;
			new ordered_table_t<collection_d, key_d, value_d>{ r, collection };
			ordered_table_t<collection_d, key_d, value_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<pair_ordered_table_a<key_d, value_d>>{ reinterpret_cast<pair_ordered_table_a<key_d, value_d>&>(r) };
		}

		static inline var<pair_ordered_table_a<key_d, value_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline var<pair_ordered_table_a<key_d, value_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};

	template <typename key_d = con<>, typename value_d = var<>>
	inline var<pair_ordered_table_a<key_d, value_d>> ordered_table()
	{
		return ordered_table_t<std::map<key_d, table_value_tuple_u<key_d, value_d, std::pair<key_d const, value_d>>>, key_d, value_d>::create_default();
	}
}

#endif
