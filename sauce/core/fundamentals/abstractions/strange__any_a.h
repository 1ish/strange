#ifndef COM_ONEISH__STRANGE__ANY_A_H
#define COM_ONEISH__STRANGE__ANY_A_H

namespace strange
{
	struct any_o
	{
		var<symbol_a> (*cat)(con<> const& me); //TODO cat

		bool (*is)(con<> const& me,
			con<> const& abstraction);

		bool (*as)(con<> const& me,
			var<> const& abstraction);

		var<symbol_a> (*type)(con<> const& me);

		static inline void set_something(var<> const& me,
			bool is_something);

		static inline bool something(con<> const& me);

		void (*set_error)(var<> const& me,
			con<> const& error);

		var<> (*error)(con<> const& me);

		static inline uint64_t identity(con<> const& me);

		uint64_t (*hash)(con<> const& me);

		bool (*equal)(con<> const& me,
			con<> const& other);

		static inline bool not_equal(con<> const& me,
			con<> const& other);

		bool (*less)(con<> const& me,
			con<> const& other);

		static inline bool greater(con<> const& me,
			con<> const& other);

		bool (*less_or_equal)(con<> const& me,
			con<> const& other);

		static inline bool greater_or_equal(con<> const& me,
			con<> const& other);

		void (*_free)(any_a const& me);

		void (*_copy)(any_a const& me,
			any_a& copy);

		void (*_set_pointer)(var<> const& me,
			bool is_pointer);

		bool (*_pointer)(con<> const& me);
	};

	struct any_a
	{
		using operations = any_o;
		using creator_fp = var<>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};

	inline uint64_t any_o::identity(con<> const& me)
	{
		return reinterpret_cast<std::uintptr_t>(me.t);
	}

	inline bool any_o::not_equal(con<> const& me,
		con<> const& other)
	{
		return !me.o->equal(me, other);
	}

	inline bool any_o::greater(con<> const& me,
		con<> const& other)
	{
		return !me.o->less_or_equal(me, other);
	}

	inline bool any_o::greater_or_equal(con<> const& me,
		con<> const& other)
	{
		return !me.o->less(me, other);
	}
}

#endif
