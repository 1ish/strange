#ifndef COM_ONEISH__STRANGE__PAIR_POINTER_TUPLE_T_H
#define COM_ONEISH__STRANGE__PAIR_POINTER_TUPLE_T_H

namespace strange
{
	template <typename first_d, typename second_d, typename pair_d>
	struct pair_pointer_tuple_t : thing_t
	{
		pair_d* const pair_pointer_;

	protected:
		inline pair_pointer_tuple_t(any_a const& me)
			: thing_t{ me }
			, pair_pointer_{ nullptr }
		{
			me.o = pair_pointer_tuple_t<first_d, second_d, pair_d>::_operations();
		}

		inline pair_pointer_tuple_t(any_a const& me,
			pair_d* const pair_pointer)
			: thing_t{ me }
			, pair_pointer_{ pair_pointer }
		{
			me.o = pair_pointer_tuple_t<first_d, second_d, pair_d>::_operations();
		}

		inline pair_pointer_tuple_t(any_a const& me,
			any_a const& original)
			: thing_t{ me, original }
			, pair_pointer_{ static_cast<pair_pointer_tuple_t<first_d, second_d, pair_d>*>(original.t)->pair_pointer_ }
		{
			me.o = pair_pointer_tuple_t<first_d, second_d, pair_d>::_operations();
		}

		pair_pointer_tuple_t(pair_pointer_tuple_t const&) = delete;

		pair_pointer_tuple_t& operator=(pair_pointer_tuple_t const&) = delete;

	private:
		// tuple_o
		static tuple_o<first_d, second_d> const* _operations();
		static tuple_o<first_d, second_d> const* _pointer_operations();

	public:
		// inline
		static inline bool equal_tuple(con<tuple_a<first_d, second_d>> const& me,
			con<tuple_a<first_d, second_d>> const& other)
		{
			return me.o->type(me) == other.o->type(other) &&
				static_cast<pair_pointer_tuple_t<first_d, second_d, pair_d> const*>(me.t)->pair_pointer_ ==
				static_cast<pair_pointer_tuple_t<first_d, second_d, pair_d> const*>(other.t)->pair_pointer_;
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
		static var<list_a<>> list(con<tuple_a<first_d, second_d>> const& me);

		static void destruct(con<tuple_a<first_d, second_d>> const& me,
			first_d& first,
			second_d& second);

		static void restruct(var<tuple_a<first_d, second_d>> const& me,
			first_d const& first,
			second_d const& second);

	public:
		// creators
		static inline var<tuple_a<first_d, second_d>> create_default()
		{
			any_a r;
			new pair_pointer_tuple_t<first_d, second_d, pair_d>{ r };
			pair_pointer_tuple_t<first_d, second_d, pair_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<tuple_a<first_d, second_d>>{ reinterpret_cast<tuple_a<first_d, second_d>&>(r) };
		}

		static inline var<tuple_a<first_d, second_d>> create(pair_d* const pair_pointer)
		{
			any_a r;
			new pair_pointer_tuple_t<first_d, second_d, pair_d>{ r, pair_pointer };
			pair_pointer_tuple_t<first_d, second_d, pair_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<tuple_a<first_d, second_d>>{ reinterpret_cast<tuple_a<first_d, second_d>&>(r) };
		}

		static inline var<tuple_a<first_d, second_d>> create_offset(var<tuple_a<first_d, second_d>> const& original,
			std::ptrdiff_t const offset)
		{
			return create(reinterpret_cast<pair_d*>
				(reinterpret_cast<std::uintptr_t>(static_cast<pair_pointer_tuple_t<first_d, second_d, pair_d> const*>(original.t)->pair_pointer_) + offset));
		}

		static inline var<tuple_a<first_d, second_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline var<tuple_a<first_d, second_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};
}

#endif
