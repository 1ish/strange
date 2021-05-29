#ifndef COM_ONEISH__STRANGE__ANY_A_H
#define COM_ONEISH__STRANGE__ANY_A_H

namespace strange
{
	struct any_o
	{
		var<symbol_a> (*cat)(val<> const& me_); //TODO cat

		void (*_free)(any_a& me_);

		void (*_copy)(any_a const& me_,
			any_a& copy_);

		bool (*is)(val<> const& me_,
			val<> const& abstraction_);

		bool (*as)(val<> const& me_,
			var<>& abstraction_);

		var<symbol_a> (*type)(val<> const& me_);

		void (*_set_pointer)(var<>& me_,
			bool is_pointer);

		bool (*_pointer)(val<> const& me_);

		void (*set_something)(var<>& me_,
			bool is_something);

		bool (*something)(val<> const& me_);

		void (*set_error)(var<>& me_,
			val<> const& error_);

		var<> (*error)(val<> const& me_);

		uint64_t (*hash)(val<> const& me_);

		bool (*equal)(val<> const& me_,
			val<> const& other_);

		bool (*not_equal)(val<> const& me_,
			val<> const& other_);

		bool (*less)(val<> const& me_,
			val<> const& other_);

		bool (*greater)(val<> const& me_,
			val<> const& other_);

		bool (*less_or_equal)(val<> const& me_,
			val<> const& other_);

		bool (*greater_or_equal)(val<> const& me_,
			val<> const& other_);
	};

	struct any_a
	{
		using operations = any_o;
		using creator = var<>(*)();

		thing_t* t;
		operations const* o;

		static var<symbol_a> cat_e(val<> const& me_); //TODO cat

		static creator creator_f(val<symbol_a> const& scope_,
			val<symbol_a> const& thing_,
			val<symbol_a> const& function_);
	};
}

#endif
