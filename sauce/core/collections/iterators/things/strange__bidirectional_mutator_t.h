#ifndef COM_ONEISH__STRANGE__BIDIRECTIONAL_MUTATOR_T_H
#define COM_ONEISH__STRANGE__BIDIRECTIONAL_MUTATOR_T_H

namespace strange
{
	template <typename iterator_d, typename element_d>
	struct bidirectional_mutator_t : forward_mutator_t<iterator_d, element_d>
	{
	protected:
		inline bidirectional_mutator_t(any_a const& me)
			: forward_mutator_t<iterator_d, element_d>{ me }
		{
			me.o = bidirectional_mutator_t<iterator_d, element_d>::_operations();
		}

		inline bidirectional_mutator_t(any_a const& me,
			iterator_d const& iterator)
			: forward_mutator_t<iterator_d, element_d>{ me, iterator }
		{
			me.o = bidirectional_mutator_t<iterator_d, element_d>::_operations();
		}

		inline bidirectional_mutator_t(any_a const& me,
			any_a const& original)
			: forward_mutator_t<iterator_d, element_d>{ me, original }
		{
			me.o = bidirectional_mutator_t<iterator_d, element_d>::_operations();
		}

		bidirectional_mutator_t(bidirectional_mutator_t const&) = delete;

		bidirectional_mutator_t& operator=(bidirectional_mutator_t const&) = delete;

	private:
		// bidirectional_mutator_o
		static bidirectional_mutator_o<element_d> const* _operations();
		static bidirectional_mutator_o<element_d> const* _pointer_operations();

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

		// bidirectional_mutator_a
		static void decrement(var<bidirectional_mutator_a<element_d>> const& me);

	public:
		// creators
		static inline bit<bidirectional_mutator_a<element_d>> create_default()
		{
			any_a r;
			new bidirectional_mutator_t<iterator_d, element_d>{ r };
			bidirectional_mutator_t<iterator_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return bit<bidirectional_mutator_a<element_d>>{ reinterpret_cast<bidirectional_mutator_a<element_d>&>(r) };
		}

		static inline bit<bidirectional_mutator_a<element_d>> create(iterator_d const& iterator)
		{
			any_a r;
			new bidirectional_mutator_t<iterator_d, element_d>{ r, iterator };
			bidirectional_mutator_t<iterator_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return bit<bidirectional_mutator_a<element_d>>{ reinterpret_cast<bidirectional_mutator_a<element_d>&>(r) };
		}

		static inline bit<bidirectional_mutator_a<element_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline bit<bidirectional_mutator_a<element_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};
}

#endif
