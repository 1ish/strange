#ifndef COM_ONEISH__STRANGE__LAKE_T_H
#define COM_ONEISH__STRANGE__LAKE_T_H

namespace strange
{
	struct lake_t : list_t<std::vector<uint8_t>, uint8_t>
	{
		using element_d = uint8_t;
		using collection_d = std::vector<element_d>;

	protected:
		inline lake_t(any_a const& me)
		: list_t<collection_d, element_d>{ me }
		{
			me.o = lake_t::_operations();
		}

		inline lake_t(any_a const& me,
			collection_d const& collection)
			: list_t<collection_d, element_d>{ me, collection }
		{
			me.o = lake_t::_operations();
		}

		inline lake_t(any_a const& me,
			any_a const& original)
		: list_t<collection_d, element_d>{ me, original }
		{
			me.o = lake_t::_operations();
		}

		lake_t(lake_t const&) = delete;
		lake_t& operator=(lake_t const&) = delete;

	private:
		// lake_o
		static lake_o const* _operations();
		static lake_o const* _pointer_operations();

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

		// lake_a
		// ...

	public:
		// creators
		static inline var<lake_a> create_default()
		{
			any_a r;
			new lake_t{ r };
			lake_t::_initialise(reinterpret_cast<var<> const&>(r));
			return var<lake_a>{ reinterpret_cast<lake_a&>(r) };
		}

		static inline var<lake_a> create(collection_d const& collection)
		{
			any_a r;
			new lake_t{ r, collection };
			lake_t::_initialise(reinterpret_cast<var<> const&>(r));
			return var<lake_a>{ reinterpret_cast<lake_a&>(r) };
		}

		static inline var<lake_a> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline var<lake_a> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};
}

#endif
