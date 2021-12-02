#ifndef COM_ONEISH__STRANGE__TUPLE_T_H
#define COM_ONEISH__STRANGE__TUPLE_T_H

namespace strange
{
	template <typename... elements_d>
	struct tuple_t : thing_t
	{
		var<list_a<>> list_;

	protected:
		inline tuple_t(any_a const& me)
			: thing_t{ me }
			, list_{ list_t<std::vector<var<>>, var<>>::create_default() }
		{
			me.o = tuple_t<elements_d...>::_operations();
		}

		inline tuple_t(any_a const& me,
			con<list_a<>> const& list)
			: thing_t{ me }
			, list_{ list }
		{
			me.o = tuple_t<elements_d...>::_operations();
		}

		inline tuple_t(any_a const& me,
			any_a const& original)
			: thing_t{ me, original }
			, list_{ static_cast<tuple_t<elements_d...>*>(original.t)->list_ }
		{
			me.o = tuple_t<elements_d...>::_operations();
		}

		tuple_t(tuple_t const&) = delete;
		tuple_t& operator=(tuple_t const&) = delete;

	private:
		// tuple_o
		static tuple_o<elements_d...> const* _operations();
		static tuple_o<elements_d...> const* _pointer_operations();

	public:
		// inline
		static inline bool equal_tuple(con<tuple_a<elements_d...>> const& me,
			con<tuple_a<elements_d...>> const& other)
		{
			return me.o->type(me) == other.o->type(other) &&
				static_cast<tuple_t<elements_d...> const*>(me.t)->list_ ==
				static_cast<tuple_t<elements_d...> const*>(other.t)->list_;
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

		// tuple_a
		static var<list_a<>> list(con<tuple_a<elements_d...>> const& me);

		static void destruct(con<tuple_a<elements_d...>> const& me,
			elements_d&... elements);

		static void restruct(var<tuple_a<elements_d...>> const& me,
			elements_d const&... elements);

	public:
		// creators
		static inline var<tuple_a<elements_d...>> create_default()
		{
			any_a r;
			new tuple_t<elements_d...>{ r };
			tuple_t<elements_d...>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<tuple_a<elements_d...>>{ reinterpret_cast<tuple_a<elements_d...>&>(r) };
		}

		static inline var<tuple_a<elements_d...>> create(con<list_a<>> const& list)
		{
			any_a r;
			new tuple_t<elements_d...>{ r, list };
			tuple_t<elements_d...>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<tuple_a<elements_d...>>{ reinterpret_cast<tuple_a<elements_d...>&>(r) };
		}

		static inline var<tuple_a<elements_d...>> create_variadic(elements_d const&... elements)
		{
			any_a r;
			new tuple_t<elements_d...>{ r, strange::list(box<>(elements)...) };
			tuple_t<elements_d...>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<tuple_a<elements_d...>>{ reinterpret_cast<tuple_a<elements_d...>&>(r) };
		}

		static inline var<tuple_a<elements_d...>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline var<tuple_a<elements_d...>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};

	template <typename... elements_d>
	inline var<tuple_a<elements_d...>> tuple(elements_d const&... elements)
	{
		return tuple_t<elements_d...>::create_variadic(elements...);
	}
}

#endif
