#ifndef COM_ONEISH__STRANGE__ANY_A_H
#define COM_ONEISH__STRANGE__ANY_A_H

namespace strange
{
	struct any_o
	{
		symbol_a (*cat)(void const* const me /* :<any># */);

		void (*_free)(void const* const me /* :<any># */);

		void (*_copy)(void const* const me /* :<any># */,
			void* const cp /* :<any>= */);

		bool (*is)(void const* const me /* :<any># */,
			void const* const ab /* :<any># */);

		bool (*as)(void const* const me /* :<any># */,
			void* const ab /* :<any>= */);

		void (*_as)(void const* const me /* :<any># */,
			void* const ab /* :<any>= */);

		symbol_a (*type)(void const* const me /* :<any># */);

		void (*_set_pointer)(void* const me /* :<any>= */,
			bool is_pointer /* :_bool_# */ );

		bool (*_pointer)(void const* const me /* :<any># */);

		void (*set_something)(void* const me /* :<any>= */,
			bool is_something /* :_bool_# */);

		bool (*something)(void const* const me /* :<any># */);

		void (*set_error)(void* const me /* :<any>= */,
			void const* const error /* :<any># */);

		any_a (*error)(void const* const me /* :<any># */);

		uint64_t (*hash)(void const* const me /* :<any># */);

		bool (*equal)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_equal)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		bool (*not_equal)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_not_equal)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		bool (*less)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_less)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		bool (*greater)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_greater)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		bool (*less_or_equal)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_less_or_equal)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		bool (*greater_or_equal)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_greater_or_equal)(void const* const me /* :<any># */,
			void const* const other /* :<any># */);
	};

	struct any_a
	{
		thing_t* d;
		any_o const* o;

		static symbol_a cat_f(void const* const me /* :<any># */);
	};
}

#endif
