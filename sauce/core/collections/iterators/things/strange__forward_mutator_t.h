#ifndef COM_ONEISH__STRANGE__FORWARD_MUTATOR_T_H
#define COM_ONEISH__STRANGE__FORWARD_MUTATOR_T_H

namespace strange
{
	template <typename iterator_d, typename element_d>
	struct forward_mutator_t : thing_t
	{
		iterator_d iterator_;

	protected:
		inline forward_mutator_t(any_a const& me)
			: thing_t{ me }
			, iterator_{}
		{
			me.o = forward_mutator_t<iterator_d, element_d>::_operations();
		}

		inline forward_mutator_t(any_a const& me,
			iterator_d const& iterator)
			: thing_t{ me }
			, iterator_{ iterator }
		{
			me.o = forward_mutator_t<iterator_d, element_d>::_operations();
		}

		inline forward_mutator_t(any_a const& me,
			any_a const& original)
			: thing_t{ me, original }
			, iterator_{ static_cast<forward_mutator_t<iterator_d, element_d>*>(original.t)->iterator_ }
		{
			me.o = forward_mutator_t<iterator_d, element_d>::_operations();
		}

		forward_mutator_t(forward_mutator_t const&) = delete;

		forward_mutator_t& operator=(forward_mutator_t const&) = delete;

	private:
		// forward_mutator_o
		static forward_mutator_o<element_d> const* _operations();
		static forward_mutator_o<element_d> const* _pointer_operations();

	public:
		// inline
		static inline bool equal_iterator(con<forward_mutator_a<element_d>> const& me,
			con<forward_mutator_a<element_d>> const& other)
		{
			//TODO check other iterator type is compatible
			return static_cast<forward_mutator_t<iterator_d, element_d>*>(me.t)->iterator_ ==
				static_cast<forward_mutator_t<iterator_d, element_d>*>(other.t)->iterator_;
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

		// forward_mutator_a
		static element_d get(con<forward_mutator_a<element_d>> const& me);

		static void set(con<forward_mutator_a<element_d>> const& me,
			element_d const& element);

		static void increment(var<forward_mutator_a<element_d>> const& me);

		static element_d& _operator_star(con<forward_mutator_a<element_d>> const& me);

		static element_d* _operator_arrow(con<forward_mutator_a<element_d>> const& me);

	public:
		// creators
		static inline fit<forward_mutator_a<element_d>> create_default()
		{
			any_a r;
			new forward_mutator_t<iterator_d, element_d>{ r };
			forward_mutator_t<iterator_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return fit<forward_mutator_a<element_d>>{ reinterpret_cast<forward_mutator_a<element_d>&>(r) };
		}

		static inline fit<forward_mutator_a<element_d>> create(iterator_d const& iterator)
		{
			any_a r;
			new forward_mutator_t<iterator_d, element_d>{ r, iterator };
			forward_mutator_t<iterator_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return fit<forward_mutator_a<element_d>>{ reinterpret_cast<forward_mutator_a<element_d>&>(r) };
		}

		static inline fit<forward_mutator_a<element_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline fit<forward_mutator_a<element_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};
}

#endif
