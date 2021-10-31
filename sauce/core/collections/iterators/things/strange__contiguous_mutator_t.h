#ifndef COM_ONEISH__STRANGE__CONTIGUOUS_MUTATOR_T_H
#define COM_ONEISH__STRANGE__CONTIGUOUS_MUTATOR_T_H

namespace strange
{
	template <typename iterator_d, typename element_d>
	struct contiguous_mutator_t : random_access_mutator_t<iterator_d, element_d>
	{
	protected:
		inline contiguous_mutator_t(any_a const& me)
			: random_access_mutator_t<iterator_d, element_d>{ me }
		{
			me.o = contiguous_mutator_t<iterator_d, element_d>::_operations();
		}

		inline contiguous_mutator_t(any_a const& me,
			iterator_d const& iterator)
			: random_access_mutator_t<iterator_d, element_d>{ me, iterator }
		{
			me.o = contiguous_mutator_t<iterator_d, element_d>::_operations();
		}

		inline contiguous_mutator_t(any_a const& me,
			any_a const& original)
			: random_access_mutator_t<iterator_d, element_d>{ me, original }
		{
			me.o = contiguous_mutator_t<iterator_d, element_d>::_operations();
		}

		contiguous_mutator_t(contiguous_mutator_t const&) = delete;

		contiguous_mutator_t& operator=(contiguous_mutator_t const&) = delete;

	private:
		// contiguous_mutator_o
		static contiguous_mutator_o<element_d> const* _operations();
		static contiguous_mutator_o<element_d> const* _pointer_operations();

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

	public:
		// creators
		static inline rat<contiguous_mutator_a<element_d>> create_default()
		{
			any_a r;
			new contiguous_mutator_t<iterator_d, element_d>{ r };
			contiguous_mutator_t<iterator_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return rat<contiguous_mutator_a<element_d>>{ reinterpret_cast<contiguous_mutator_a<element_d>&>(r) };
		}

		static inline rat<contiguous_mutator_a<element_d>> create(iterator_d const& iterator)
		{
			any_a r;
			new contiguous_mutator_t<iterator_d, element_d>{ r, iterator };
			contiguous_mutator_t<iterator_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return rat<contiguous_mutator_a<element_d>>{ reinterpret_cast<contiguous_mutator_a<element_d>&>(r) };
		}

		static inline rat<contiguous_mutator_a<element_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline rat<contiguous_mutator_a<element_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};
}

#endif
