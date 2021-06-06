#ifndef COM_ONEISH__STRANGE__THING_T_H
#define COM_ONEISH__STRANGE__THING_T_H

namespace strange
{
	struct thing_t
	{
		std::atomic_int64_t refs_;
		any_a error_;

	protected:
		thing_t(any_a& me);

		thing_t(any_a& me,
			any_a const& original);

		thing_t(thing_t const&) = delete;

		thing_t& operator=(thing_t const&) = delete;

		virtual ~thing_t();

	private:
		// any_o
		static any_o const* _operations();
		static any_o const* _pointer_operations();

	protected:
		// inline
		static inline void _initialise(any_a& me)
		{
		}

		static inline void _clone(any_a const& me,
			any_a& copy)
		{
		}

	public:
		static inline bool _equal(con<> const& me,
			con<> const& other)
		{
			return me.t == other.t;
		}

		static inline bool _less(con<> const& me,
			con<> const& other)
		{
			return me.t < other.t;
		}

		static inline bool _greater(con<> const& me,
			con<> const& other)
		{
			return me.t > other.t;
		}

		static inline bool _less_or_equal(con<> const& me,
			con<> const& other)
		{
			return me.t <= other.t;
		}

		static inline bool _greater_or_equal(con<> const& me,
			con<> const& other)
		{
			return me.t >= other.t;
		}

	protected:
		// any_a
		static bool is(con<> const& me,
			con<> const& abstraction);

		static bool as(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type(con<> const& me);

		static void set_error(var<> const& me,
			con<> const& error_);

		static var<> error(con<> const& me);

		static uint64_t hash(con<> const& me);

		static bool equal(con<> const& me,
			con<> const& other);

		static bool less(con<> const& me,
			con<> const& other);

		static bool greater(con<> const& me,
			con<> const& other);

		static bool less_or_equal(con<> const& me,
			con<> const& other);

		static bool greater_or_equal(con<> const& me,
			con<> const& other);

		static void _free(any_a const& me);

		static void _copy(any_a const& me,
			any_a& copy);

		static void _no_copy(any_a const& me,
			any_a& copy);

		static void _set_pointer(var<> const& me,
			bool is_pointer);

		static bool _pointer(con<> const& me);

	public:
		// creators
		static var<> create();
		static var<> create_nothing();
	};

	inline void any_o::set_something(var<> const& me,
		bool is_something)
	{
		me.o->set_error(me, is_something ? thing_t::create_nothing() : thing_t::create());
	}

	inline bool any_o::something(con<> const& me)
	{
		return !me.t->error_.t;
	}
}

#endif
