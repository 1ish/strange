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

		void (*set_something)(var<> const& me,
			bool is_something);

		bool (*something)(con<> const& me);

		void (*set_error)(var<> const& me,
			con<> const& error);

		var<> (*error)(con<> const& me);

		uint64_t (*hash)(con<> const& me);

		bool (*equal)(con<> const& me,
			con<> const& other);

		bool (*not_equal)(con<> const& me,
			con<> const& other);

		bool (*less)(con<> const& me,
			con<> const& other);

		bool (*greater)(con<> const& me,
			con<> const& other);

		bool (*less_or_equal)(con<> const& me,
			con<> const& other);

		bool (*greater_or_equal)(con<> const& me,
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
		using creator = var<>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat_f(con<> const& me); //TODO cat

		static creator creator_f(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
