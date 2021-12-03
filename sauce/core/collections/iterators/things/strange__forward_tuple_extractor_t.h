#ifndef COM_ONEISH__STRANGE__FORWARD_TUPLE_EXTRACTOR_T_H
#define COM_ONEISH__STRANGE__FORWARD_TUPLE_EXTRACTOR_T_H

namespace strange
{
	template <typename iterator_d, typename key_d, typename value_d>
	struct forward_tuple_extractor_t : thing_t
	{
		using element_d = var<tuple_a<key_d, value_d>>;

		iterator_d iterator_;

	protected:
		inline forward_tuple_extractor_t(any_a const& me)
			: thing_t{ me }
			, iterator_{}
		{
			me.o = forward_tuple_extractor_t<iterator_d, key_d, value_d>::_operations();
		}

		inline forward_tuple_extractor_t(any_a const& me,
			iterator_d const& iterator)
			: thing_t{ me }
			, iterator_{ iterator }
		{
			me.o = forward_tuple_extractor_t<iterator_d, key_d, value_d>::_operations();
		}

		inline forward_tuple_extractor_t(any_a const& me,
			any_a const& original)
			: thing_t{ me, original }
			, iterator_{ static_cast<forward_tuple_extractor_t<iterator_d, key_d, value_d>*>(original.t)->iterator_ }
		{
			me.o = forward_tuple_extractor_t<iterator_d, key_d, value_d>::_operations();
		}

		forward_tuple_extractor_t(forward_tuple_extractor_t const&) = delete;

		forward_tuple_extractor_t& operator=(forward_tuple_extractor_t const&) = delete;

	private:
		// forward_tuple_extractor_o
		static forward_tuple_extractor_o<key_d, value_d> const* _operations();
		static forward_tuple_extractor_o<key_d, value_d> const* _pointer_operations();

	public:
		// inline
		static inline bool equal_iterator(con<forward_extractor_a<element_d>> const& me,
			con<forward_extractor_a<element_d>> const& other)
		{
			return me.o->type(me) == other.o->type(other) &&
				static_cast<forward_tuple_extractor_t<iterator_d, key_d, value_d> const*>(me.t)->iterator_ ==
				static_cast<forward_tuple_extractor_t<iterator_d, key_d, value_d> const*>(other.t)->iterator_;
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

		// forward_extractor_a
		static element_d get(con<forward_extractor_a<element_d>> const& me);

		static void increment(var<forward_extractor_a<element_d>> const& me);

		static element_d const& _operator_star(con<forward_extractor_a<element_d>> const& me);

		static element_d const* _operator_arrow(con<forward_extractor_a<element_d>> const& me);

		// forward_tuple_extractor_a
		static var<list_a<>> list(con<forward_tuple_extractor_a<key_d, value_d>> const& me);

		static void destruct(con<forward_tuple_extractor_a<key_d, value_d>> const& me,
			key_d& key,
			value_d& value);

	public:
		// creators
		static inline fit<forward_tuple_extractor_a<key_d, value_d>> create_default()
		{
			any_a r;
			new forward_tuple_extractor_t<iterator_d, key_d, value_d>{ r };
			forward_tuple_extractor_t<iterator_d, key_d, value_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return fit<forward_tuple_extractor_a<key_d, value_d>>{ reinterpret_cast<forward_tuple_extractor_a<key_d, value_d>&>(r) };
		}

		static inline fit<forward_tuple_extractor_a<key_d, value_d>> create(iterator_d const& iterator)
		{
			any_a r;
			new forward_tuple_extractor_t<iterator_d, key_d, value_d>{ r, iterator };
			forward_tuple_extractor_t<iterator_d, key_d, value_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return fit<forward_tuple_extractor_a<key_d, value_d>>{ reinterpret_cast<forward_tuple_extractor_a<key_d, value_d>&>(r) };
		}

		static inline fit<forward_tuple_extractor_a<key_d, value_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline fit<forward_tuple_extractor_a<key_d, value_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};
}

#endif
