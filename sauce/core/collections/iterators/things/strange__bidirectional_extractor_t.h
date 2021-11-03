#ifndef COM_ONEISH__STRANGE__BIDIRECTIONAL_EXTRACTOR_T_H
#define COM_ONEISH__STRANGE__BIDIRECTIONAL_EXTRACTOR_T_H

namespace strange
{
	template <typename iterator_d, typename element_d>
	struct bidirectional_extractor_t : forward_extractor_t<iterator_d, element_d>
	{
	protected:
		inline bidirectional_extractor_t(any_a const& me)
			: forward_extractor_t<iterator_d, element_d>{ me }
		{
			me.o = bidirectional_extractor_t<iterator_d, element_d>::_operations();
		}

		inline bidirectional_extractor_t(any_a const& me,
			iterator_d const& iterator)
			: forward_extractor_t<iterator_d, element_d>{ me, iterator }
		{
			me.o = bidirectional_extractor_t<iterator_d, element_d>::_operations();
		}

		inline bidirectional_extractor_t(any_a const& me,
			any_a const& original)
			: forward_extractor_t<iterator_d, element_d>{ me, original }
		{
			me.o = bidirectional_extractor_t<iterator_d, element_d>::_operations();
		}

		bidirectional_extractor_t(bidirectional_extractor_t const&) = delete;

		bidirectional_extractor_t& operator=(bidirectional_extractor_t const&) = delete;

	private:
		// bidirectional_extractor_o
		static bidirectional_extractor_o<element_d> const* _operations();
		static bidirectional_extractor_o<element_d> const* _pointer_operations();

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

		// bidirectional_extractor_a
		static void decrement(var<bidirectional_extractor_a<element_d>> const& me);

	public:
		// creators
		static inline bit<bidirectional_extractor_a<element_d>> create_default()
		{
			any_a r;
			new bidirectional_extractor_t<iterator_d, element_d>{ r };
			bidirectional_extractor_t<iterator_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return bit<bidirectional_extractor_a<element_d>>{ reinterpret_cast<bidirectional_extractor_a<element_d>&>(r) };
		}

		static inline bit<bidirectional_extractor_a<element_d>> create(iterator_d const& iterator)
		{
			any_a r;
			new bidirectional_extractor_t<iterator_d, element_d>{ r, iterator };
			bidirectional_extractor_t<iterator_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return bit<bidirectional_extractor_a<element_d>>{ reinterpret_cast<bidirectional_extractor_a<element_d>&>(r) };
		}

		static inline bit<bidirectional_extractor_a<element_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline bit<bidirectional_extractor_a<element_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};
}

#endif
