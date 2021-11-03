#ifndef COM_ONEISH__STRANGE__RANDOM_ACCESS_EXTRACTOR_T_H
#define COM_ONEISH__STRANGE__RANDOM_ACCESS_EXTRACTOR_T_H

namespace strange
{
	template <typename iterator_d, typename element_d>
	struct random_access_extractor_t : bidirectional_extractor_t<iterator_d, element_d>
	{
	protected:
		inline random_access_extractor_t(any_a const& me)
			: bidirectional_extractor_t<iterator_d, element_d>{ me }
		{
			me.o = random_access_extractor_t<iterator_d, element_d>::_operations();
		}

		inline random_access_extractor_t(any_a const& me,
			iterator_d const& iterator)
			: bidirectional_extractor_t<iterator_d, element_d>{ me, iterator }
		{
			me.o = random_access_extractor_t<iterator_d, element_d>::_operations();
		}

		inline random_access_extractor_t(any_a const& me,
			any_a const& original)
			: bidirectional_extractor_t<iterator_d, element_d>{ me, original }
		{
			me.o = random_access_extractor_t<iterator_d, element_d>::_operations();
		}

		random_access_extractor_t(random_access_extractor_t const&) = delete;

		random_access_extractor_t& operator=(random_access_extractor_t const&) = delete;

	private:
		// random_access_extractor_o
		static random_access_extractor_o<element_d> const* _operations();
		static random_access_extractor_o<element_d> const* _pointer_operations();

	public:
		// inline
		static inline bool less_iterator(con<random_access_extractor_a<element_d>> const& me,
			con<random_access_extractor_a<element_d>> const& other)
		{
			//TODO check other iterator type is compatible
			return static_cast<random_access_extractor_t<iterator_d, element_d>*>(me.t)->iterator_ <
				static_cast<random_access_extractor_t<iterator_d, element_d>*>(other.t)->iterator_;
		}

		static inline bool less_or_equal_iterator(con<random_access_extractor_a<element_d>> const& me,
			con<random_access_extractor_a<element_d>> const& other)
		{
			//TODO check other iterator type is compatible
			return static_cast<random_access_extractor_t<iterator_d, element_d>*>(me.t)->iterator_ <=
				static_cast<random_access_extractor_t<iterator_d, element_d>*>(other.t)->iterator_;
		}

	protected:
		// any_a
		static bool is(con<> const& me,
			con<> const& abstraction);

		static bool as(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type(con<> const& me);

		static bool less(con<> const& me,
			con<> const& other);

		static bool less_or_equal(con<> const& me,
			con<> const& other);

		static void _copy(con<> const& me,
			var<> const& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

		// random_access_extractor_a
		static void self_add(var<random_access_extractor_a<element_d>> const& me,
			int64_t offset);

		static rat<random_access_extractor_a<element_d>> add(con<random_access_extractor_a<element_d>> const& me,
			int64_t offset);

	public:
		// creators
		static inline rat<random_access_extractor_a<element_d>> create_default()
		{
			any_a r;
			new random_access_extractor_t<iterator_d, element_d>{ r };
			random_access_extractor_t<iterator_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return rat<random_access_extractor_a<element_d>>{ reinterpret_cast<random_access_extractor_a<element_d>&>(r) };
		}

		static inline rat<random_access_extractor_a<element_d>> create(iterator_d const& iterator)
		{
			any_a r;
			new random_access_extractor_t<iterator_d, element_d>{ r, iterator };
			random_access_extractor_t<iterator_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return rat<random_access_extractor_a<element_d>>{ reinterpret_cast<random_access_extractor_a<element_d>&>(r) };
		}

		static inline rat<random_access_extractor_a<element_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline rat<random_access_extractor_a<element_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};
}

#endif
