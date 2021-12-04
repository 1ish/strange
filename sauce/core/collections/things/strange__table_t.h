#ifndef COM_ONEISH__STRANGE__TABLE_T_H
#define COM_ONEISH__STRANGE__TABLE_T_H

namespace strange
{
	template <typename collection_d, typename key_d, typename value_d>
	struct table_t : thing_t
	{
		using element_d = var<tuple_a<key_d, value_d>>;

		collection_d collection_;

	protected:
		inline table_t(any_a const& me)
			: thing_t{ me }
			, collection_{}
		{
			me.o = table_t<collection_d, key_d, value_d>::_operations();
		}

		inline table_t(any_a const& me,
			collection_d const& collection)
			: thing_t{ me }
			, collection_{ collection }
		{
			me.o = table_t<collection_d, key_d, value_d>::_operations();
		}

		inline table_t(any_a const& me,
			any_a const& original)
			: thing_t{ me, original }
			, collection_{ static_cast<table_t<collection_d, key_d, value_d>*>(original.t)->collection_ }
		{
			me.o = table_t<collection_d, key_d, value_d>::_operations();
		}

		table_t(table_t const&) = delete;
		table_t& operator=(table_t const&) = delete;

	private:
		// pair_table_o
		static pair_table_o<key_d, value_d> const* _operations();
		static pair_table_o<key_d, value_d> const* _pointer_operations();

	public:
		// inline
		static inline bool equal_table(con<pair_table_a<key_d, value_d>> const& me,
			con<pair_table_a<key_d, value_d>> const& other)
		{
			return me.o->type(me) == other.o->type(other) &&
				static_cast<table_t<collection_d, key_d, value_d> const*>(me.t)->collection_ ==
				static_cast<table_t<collection_d, key_d, value_d> const*>(other.t)->collection_;
		}

	protected:
		// any_a
		static bool is(con<> const& me,
			con<> const& abstraction);

		static bool as(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type(con<> const& me);

		static bool equal(con<> const& me,
			con<> const& other);

		static void _copy(con<> const& me,
			var<> const& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

		// collection_a
		static ptr<> read_lock(con<collection_a<key_d, value_d, element_d>> const& me);

		static ptr<> write_lock(var<collection_a<key_d, value_d, element_d>> const& me);

		static bool has(con<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		static value_d at(con<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		static void update(var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key,
			value_d const& value);

		static bool insert(var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key,
			value_d const& value);

		static bool erase(var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		static void clear(var<collection_a<key_d, value_d, element_d>> const& me);

		static int64_t size(con<collection_a<key_d, value_d, element_d>> const& me);

		static bool empty(con<collection_a<key_d, value_d, element_d>> const& me);

		static void push_front(var<collection_a<key_d, value_d, element_d>> const& me,
			element_d const& element);

		static element_d pop_front(var<collection_a<key_d, value_d, element_d>> const& me);

		static void push_back(var<collection_a<key_d, value_d, element_d>> const& me,
			element_d const& element);

		static element_d pop_back(var<collection_a<key_d, value_d, element_d>> const& me);

		static void self_assign(var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static void self_add(var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static var<collection_a<key_d, value_d, element_d>> add(con<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static void self_subtract(var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static var<collection_a<key_d, value_d, element_d>> subtract(con<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		// table_a
		static var<tuple_range_a<key_d, value_d>> range(con<table_a<key_d, value_d>> const& me);

		static fit<forward_tuple_extractor_a<key_d, value_d>> begin(con<table_a<key_d, value_d>> const& me);

		static fit<forward_tuple_extractor_a<key_d, value_d>> end(con<table_a<key_d, value_d>> const& me);

		static var<tuple_mutator_range_a<key_d, value_d>> mutator_range(var<table_a<key_d, value_d>> const& me);

		static fit<forward_tuple_mutator_a<key_d, value_d>> mutator_begin(var<table_a<key_d, value_d>> const& me);

		static fit<forward_tuple_mutator_a<key_d, value_d>> mutator_end(var<table_a<key_d, value_d>> const& me);

		// pair_table_a
		static var<range_a<std::pair<key_d const, value_d>>> pair_range(con<pair_table_a<key_d, value_d>> const& me);

		static fit<forward_extractor_a<std::pair<key_d const, value_d>>> pair_begin(con<pair_table_a<key_d, value_d>> const& me);

		static fit<forward_extractor_a<std::pair<key_d const, value_d>>> pair_end(con<pair_table_a<key_d, value_d>> const& me);

		static var<mutator_range_a<std::pair<key_d const, value_d>>> pair_mutator_range(var<pair_table_a<key_d, value_d>> const& me);

		static fit<forward_mutator_a<std::pair<key_d const, value_d>>> pair_mutator_begin(var<pair_table_a<key_d, value_d>> const& me);

		static fit<forward_mutator_a<std::pair<key_d const, value_d>>> pair_mutator_end(var<pair_table_a<key_d, value_d>> const& me);

	private:
		// tuple_range_a
		static tuple_range_o<key_d, value_d> const* _range_operations();
		static tuple_range_o<key_d, value_d> const* _range_pointer_operations();

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
		// tuple_mutator_range_a
		static tuple_mutator_range_o<key_d, value_d> const* _mutator_range_operations();
		static tuple_mutator_range_o<key_d, value_d> const* _mutator_range_pointer_operations();

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
		// range_a
		static range_o<std::pair<key_d const, value_d>> const* _pair_range_operations();
		static range_o<std::pair<key_d const, value_d>> const* _pair_range_pointer_operations();

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
		// mutator_range_a
		static mutator_range_o<std::pair<key_d const, value_d>> const* _pair_mutator_range_operations();
		static mutator_range_o<std::pair<key_d const, value_d>> const* _pair_mutator_range_pointer_operations();

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
		static inline var<pair_table_a<key_d, value_d>> create_default()
		{
			any_a r;
			new table_t<collection_d, key_d, value_d>{ r };
			table_t<collection_d, key_d, value_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<pair_table_a<key_d, value_d>>{ reinterpret_cast<pair_table_a<key_d, value_d>&>(r) };
		}

		static inline var<pair_table_a<key_d, value_d>> create(collection_d const& collection)
		{
			any_a r;
			new table_t<collection_d, key_d, value_d>{ r, collection };
			table_t<collection_d, key_d, value_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<pair_table_a<key_d, value_d>>{ reinterpret_cast<pair_table_a<key_d, value_d>&>(r) };
		}

		static inline var<pair_table_a<key_d, value_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline var<pair_table_a<key_d, value_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};

	template <typename key_d = con<>, typename value_d = var<>>
	inline var<pair_table_a<key_d, value_d>> table()
	{
		return table_t<std::unordered_map<key_d, table_value_tuple_u<key_d, value_d, std::pair<key_d const, value_d>>>, key_d, value_d>::create_default();
	}
}

#endif
