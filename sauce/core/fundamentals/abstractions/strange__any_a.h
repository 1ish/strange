#ifndef COM_ONEISH__STRANGE__ANY_A_H
#define COM_ONEISH__STRANGE__ANY_A_H

namespace strange
{
	struct any_o
	{
		var<symbol_a> (*cat)(con<> const& me_); //TODO cat

		void (*_free)(any_a const& me_);

		void (*_copy)(any_a const& me_,
			any_a& copy_);

		bool (*is)(con<> const& me_,
			con<> const& abstraction_);

		bool (*as)(con<> const& me_,
			var<> const& abstraction_);

		var<symbol_a> (*type)(con<> const& me_);

		void (*_set_pointer)(var<> const& me_,
			bool is_pointer);

		bool (*_pointer)(con<> const& me_);

		void (*set_something)(var<>& me_,
			bool is_something);

		bool (*something)(con<> const& me_);

		void (*set_error)(var<>& me_,
			con<> const& error_);

		var<> (*error)(con<> const& me_);

		uint64_t (*hash)(con<> const& me_);

		bool (*equal)(con<> const& me_,
			con<> const& other_);

		bool (*not_equal)(con<> const& me_,
			con<> const& other_);

		bool (*less)(con<> const& me_,
			con<> const& other_);

		bool (*greater)(con<> const& me_,
			con<> const& other_);

		bool (*less_or_equal)(con<> const& me_,
			con<> const& other_);

		bool (*greater_or_equal)(con<> const& me_,
			con<> const& other_);
	};

	struct any_a
	{
		using operations = any_o;
		using creator = var<>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat_e(con<> const& me_); //TODO cat

		static creator creator_f(con<symbol_a> const& scope_,
			con<symbol_a> const& thing_,
			con<symbol_a> const& function_);
	};
}

#endif
