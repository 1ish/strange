#ifndef COM_ONEISH__STRANGE__LIST_T_H
#define COM_ONEISH__STRANGE__LIST_T_H

namespace strange
{
	template <typename collection_d, typename element_d>
	struct list_t : queue_t<collection_d, element_d>
	{
	protected:
		inline list_t(any_a const& me)
			: queue_t<collection_d, element_d>{ me }
		{
			me.o = list_t<collection_d, element_d>::_operations();
		}

		inline list_t(any_a const& me,
			collection_d const& collection)
			: queue_t<collection_d, element_d>{ me, collection }
		{
			me.o = list_t<collection_d, element_d>::_operations();
		}

		inline list_t(any_a const& me,
			any_a const& original)
			: queue_t<collection_d, element_d>{ me, original }
		{
			me.o = list_t<collection_d, element_d>::_operations();
		}

		list_t(list_t const&) = delete;

		list_t& operator=(list_t const&) = delete;

	private:
		// list_o
		static list_o<element_d> const* _operations();
		static list_o<element_d> const* _pointer_operations();

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

		// list_a
		static var<contiguous_range_a<element_d>> range(con<list_a<element_d>> const& me);

		static rat<contiguous_extractor_a<element_d>> begin(con<list_a<element_d>> const& me);

		static rat<contiguous_extractor_a<element_d>> end(con<list_a<element_d>> const& me);

		static var<contiguous_mutator_range_a<element_d>> mutator_range(var<list_a<element_d>> const& me);

		static rat<contiguous_mutator_a<element_d>> mutator_begin(var<list_a<element_d>> const& me);

		static rat<contiguous_mutator_a<element_d>> mutator_end(var<list_a<element_d>> const& me);

	private:
		// contiguous_range_a
		static contiguous_range_o<element_d> const* _range_operations();
		static contiguous_range_o<element_d> const* _range_pointer_operations();

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
		// contiguous_mutator_range_a
		static contiguous_mutator_range_o<element_d> const* _mutator_range_operations();
		static contiguous_mutator_range_o<element_d> const* _mutator_range_pointer_operations();

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

	public:
		// creators
		static inline var<list_a<element_d>> create_default()
		{
			any_a r;
			new list_t<collection_d, element_d>{ r };
			list_t<collection_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<list_a<element_d>>{ reinterpret_cast<list_a<element_d>&>(r) };
		}

		static inline var<list_a<element_d>> create(collection_d const& collection)
		{
			any_a r;
			new list_t<collection_d, element_d>{ r, collection };
			list_t<collection_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<list_a<element_d>>{ reinterpret_cast<list_a<element_d>&>(r) };
		}

		static inline var<list_a<element_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline var<list_a<element_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};
}

#endif
