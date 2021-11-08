#ifndef COM_ONEISH__STRANGE__QUEUE_T_H
#define COM_ONEISH__STRANGE__QUEUE_T_H

namespace strange
{
	template <typename collection_d, typename element_d>
	struct queue_t : collection_t<collection_d, int64_t, element_d, element_d>
	{
	protected:
		inline queue_t(any_a const& me)
			: collection_t<collection_d, int64_t, element_d, element_d>{ me }
		{
			me.o = queue_t<collection_d, element_d>::_operations();
		}

		inline queue_t(any_a const& me,
			collection_d const& collection)
			: collection_t<collection_d, int64_t, element_d, element_d>{ me, collection }
		{
			me.o = queue_t<collection_d, element_d>::_operations();
		}

		inline queue_t(any_a const& me,
			any_a const& original)
			: collection_t<collection_d, int64_t, element_d, element_d>{ me, original }
		{
			me.o = queue_t<collection_d, element_d>::_operations();
		}

		queue_t(queue_t const&) = delete;

		queue_t& operator=(queue_t const&) = delete;

	private:
		// queue_o
		static queue_o<element_d> const* _operations();
		static queue_o<element_d> const* _pointer_operations();

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

		// collection_a
		static bool has(con<collection_a<int64_t, element_d, element_d>> const& me,
			int64_t const& key);

		static element_d at(con<collection_a<int64_t, element_d, element_d>> const& me,
			int64_t const& key);

		static void update(var<collection_a<int64_t, element_d, element_d>> const& me,
			int64_t const& key,
			element_d const& value);

		static bool insert(var<collection_a<int64_t, element_d, element_d>> const& me,
			int64_t const& key,
			element_d const& value);

		static bool erase(var<collection_a<int64_t, element_d, element_d>> const& me,
			int64_t const& key);

		static void clear(var<collection_a<int64_t, element_d, element_d>> const& me);

		static int64_t size(con<collection_a<int64_t, element_d, element_d>> const& me);

		static bool empty(con<collection_a<int64_t, element_d, element_d>> const& me);

		static void push_front(var<collection_a<int64_t, element_d, element_d>> const& me,
			element_d const& element);

		static element_d pop_front(var<collection_a<int64_t, element_d, element_d>> const& me);

		static void push_back(var<collection_a<int64_t, element_d, element_d>> const& me,
			element_d const& element);

		static element_d pop_back(var<collection_a<int64_t, element_d, element_d>> const& me);

		static void self_assign(var<collection_a<int64_t, element_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static void self_add(var<collection_a<int64_t, element_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static var<collection_a<int64_t, element_d, element_d>> add(con<collection_a<int64_t, element_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static void self_subtract(var<collection_a<int64_t, element_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static var<collection_a<int64_t, element_d, element_d>> subtract(con<collection_a<int64_t, element_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		// queue_a
		static var<random_access_range_a<element_d>> range(con<queue_a<element_d>> const& me);

		static rat<random_access_extractor_a<element_d>> begin(con<queue_a<element_d>> const& me);

		static rat<random_access_extractor_a<element_d>> end(con<queue_a<element_d>> const& me);

		static var<random_access_mutator_range_a<element_d>> mutator_range(var<queue_a<element_d>> const& me);

		static rat<random_access_mutator_a<element_d>> mutator_begin(var<queue_a<element_d>> const& me);

		static rat<random_access_mutator_a<element_d>> mutator_end(var<queue_a<element_d>> const& me);

	private:
		// random_access_range_a
		static random_access_range_o<element_d> const* _range_operations();
		static random_access_range_o<element_d> const* _range_pointer_operations();

	protected:
		static bool _range_is(con<> const& me,
			con<> const& abstraction);

		static bool _range_as(con<> const& me,
			var<> const& abstraction);

		static void _range_copy(con<> const& me,
			var<> const& copy);

		static void _range_set_pointer(con<> const& me,
			bool is_pointer);

	private:
		// random_access_mutator_range_a
		static random_access_mutator_range_o<element_d> const* _mutator_range_operations();
		static random_access_mutator_range_o<element_d> const* _mutator_range_pointer_operations();

	protected:
		static bool _mutator_range_is(con<> const& me,
			con<> const& abstraction);

		static bool _mutator_range_as(con<> const& me,
			var<> const& abstraction);

		static void _mutator_range_copy(con<> const& me,
			var<> const& copy);

		static void _mutator_range_set_pointer(con<> const& me,
			bool is_pointer);

	public:
		// creators
		static inline var<queue_a<element_d>> create_default()
		{
			any_a r;
			new queue_t<collection_d, element_d>{ r };
			queue_t<collection_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<queue_a<element_d>>{ reinterpret_cast<queue_a<element_d>&>(r) };
		}

		static inline var<queue_a<element_d>> create(collection_d const& collection)
		{
			any_a r;
			new queue_t<collection_d, element_d>{ r, collection };
			queue_t<collection_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<queue_a<element_d>>{ reinterpret_cast<queue_a<element_d>&>(r) };
		}

		static inline var<queue_a<element_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline var<queue_a<element_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};
}

#endif
