#ifndef COM_ONEISH__STRANGE__ORDERED_GROUP_T_H
#define COM_ONEISH__STRANGE__ORDERED_GROUP_T_H

namespace strange
{
	template <typename collection_d, typename element_d>
	struct ordered_group_t : group_t<collection_d, element_d>
	{
	protected:
		inline ordered_group_t(any_a const& me)
			: group_t<collection_d, element_d>{ me }
		{
			me.o = ordered_group_t<collection_d, element_d>::_operations();
		}

		inline ordered_group_t(any_a const& me,
			collection_d const& collection)
			: group_t<collection_d, element_d>{ me, collection }
		{
			me.o = ordered_group_t<collection_d, element_d>::_operations();
		}

		template <typename... elements_d>
		inline ordered_group_t(any_a const& me,
			bool const variadic,
			elements_d const&... elements)
			: group_t<collection_d, element_d>{ me, variadic, elements... }
		{
			me.o = ordered_group_t<collection_d, element_d>::_operations();
		}

		inline ordered_group_t(any_a const& me,
			any_a const& original)
			: group_t<collection_d, element_d>{ me, original }
		{
			me.o = ordered_group_t<collection_d, element_d>::_operations();
		}

		ordered_group_t(ordered_group_t const&) = delete;
		ordered_group_t& operator=(ordered_group_t const&) = delete;

	private:
		// ordered_group_o
		static ordered_group_o<element_d> const* _operations();
		static ordered_group_o<element_d> const* _pointer_operations();

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

		// ordered_group_a
		static var<bidirectional_range_a<element_d>> range(con<ordered_group_a<element_d>> const& me);

		static bit<bidirectional_extractor_a<element_d>> begin(con<ordered_group_a<element_d>> const& me);

		static bit<bidirectional_extractor_a<element_d>> end(con<ordered_group_a<element_d>> const& me);

	private:
		// bidirectional_range_a
		static bidirectional_range_o<element_d> const* _range_operations();
		static bidirectional_range_o<element_d> const* _range_pointer_operations();

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

	public:
		// creators
		static inline var<ordered_group_a<element_d>> create_default()
		{
			any_a r;
			new ordered_group_t<collection_d, element_d>{ r };
			ordered_group_t<collection_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<ordered_group_a<element_d>>{ reinterpret_cast<ordered_group_a<element_d>&>(r) };
		}

		static inline var<ordered_group_a<element_d>> create(collection_d const& collection)
		{
			any_a r;
			new ordered_group_t<collection_d, element_d>{ r, collection };
			ordered_group_t<collection_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<ordered_group_a<element_d>>{ reinterpret_cast<ordered_group_a<element_d>&>(r) };
		}

		template <typename... elements_d>
		static inline var<ordered_group_a<element_d>> create_variadic(elements_d const&... elements)
		{
			any_a r;
			new ordered_group_t<collection_d, element_d>{ r, true, elements... };
			ordered_group_t<collection_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<ordered_group_a<element_d>>{ reinterpret_cast<ordered_group_a<element_d>&>(r) };
		}

		static inline var<ordered_group_a<element_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline var<ordered_group_a<element_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};

	template <typename element_d = var<>, typename... elements_d>
	inline var<ordered_group_a<element_d>> ordered_group(elements_d const&... elements)
	{
		return ordered_group_t<std::set<element_d>, element_d>::create_variadic(elements...);
	}
}

#endif
