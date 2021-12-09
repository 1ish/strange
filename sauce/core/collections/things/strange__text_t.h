#ifndef COM_ONEISH__STRANGE__TEXT_T_H
#define COM_ONEISH__STRANGE__TEXT_T_H

namespace strange
{
	struct text_t : lake_t
	{
	protected:
		inline text_t(any_a const& me)
		: lake_t{ me }
		{
			me.o = text_t::_operations();
		}

		inline text_t(any_a const& me,
			typename lake_t::collection_d const& collection)
			: lake_t{ me, collection }
		{
			me.o = text_t::_operations();
		}

		inline text_t(any_a const& me,
			any_a const& original)
		: lake_t{ me, original }
		{
			me.o = text_t::_operations();
		}

		text_t(text_t const&) = delete;
		text_t& operator=(text_t const&) = delete;

	private:
		// text_o
		static text_o const* _operations();
		static text_o const* _pointer_operations();

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

		// text_a
		// ...

	public:
		// creators
		static inline var<text_a> create_default()
		{
			any_a r;
			new text_t{ r };
			text_t::_initialise(reinterpret_cast<var<> const&>(r));
			return var<text_a>{ reinterpret_cast<text_a&>(r) };
		}

		static inline var<text_a> create(typename lake_t::collection_d const& collection)
		{
			any_a r;
			new text_t{ r, collection };
			text_t::_initialise(reinterpret_cast<var<> const&>(r));
			return var<text_a>{ reinterpret_cast<text_a&>(r) };
		}

		static inline var<text_a> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline var<text_a> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};

	inline var<text_a> text(char const* s)
	{
		return text_t::create(
			std::vector<uint8_t>{reinterpret_cast<uint8_t const*>(s),
			reinterpret_cast<uint8_t const*>(s) + std::strlen(s)}).reference<var<text_a>>();
	}
}

#endif
