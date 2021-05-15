#ifndef COM_ONEISH__STRANGE__ANY_A_H
#define COM_ONEISH__STRANGE__ANY_A_H

#define STRANGE__ANY_O \
		strange__symbol_a (*cat)(void const* const me /* :<any># */); \
\
		void (*_free)(void const* const me /* :<any># */); \
\
		void (*_copy)(void const* const me /* :<any># */, \
			void* const cp /* :<any>= */); \
\
		bool (*is)(void const* const me /* :<any># */, \
			void const* const ab /* :<any># */); \
\
		bool (*as)(void const* const me /* :<any># */, \
			void* const ab /* :<any>= */); \
\
		void (*_as)(void const* const me /* :<any># */, \
			void* const ab /* :<any>= */); \
\
		strange__symbol_a (*type)(void const* const me /* :<any># */); \
\
		void (*_set_pointer)(void* const me /* :<any>= */, \
			bool is_pointer /* :_bool_# */ ); \
\
		bool (*_pointer)(void const* const me /* :<any># */); \
\
		void (*set_something)(void* const me /* :<any>= */, \
			bool is_something /* :_bool_# */); \
\
		bool (*something)(void const* const me /* :<any># */); \
\
		void (*set_error)(void* const me /* :<any>= */, \
			void const* const error /* :<any># */); \
\
		strange__any_a (*error)(void const* const me /* :<any># */); \
\
		bool (*equal)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \
\
		bool (*_equal)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \
\
		bool (*not_equal)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \
\
		bool (*_not_equal)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \
\
		bool (*less)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \
\
		bool (*_less)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \
\
		bool (*greater)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \
\
		bool (*_greater)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \
\
		bool (*less_or_equal)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \
\
		bool (*_less_or_equal)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \
\
		bool (*greater_or_equal)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \
\
		bool (*_greater_or_equal)(void const* const me /* :<any># */, \
			void const* const other /* :<any># */); \

extern "C"
{
	struct strange__any_o
	{
		STRANGE__ANY_O
	};

	struct strange__any_a
	{
		strange__thing_d* d;
		strange__any_o const* o;
	};
}

#endif
