#ifndef COM_ONEISH__STRANGE__GROUP_T_H
#define COM_ONEISH__STRANGE__GROUP_T_H

namespace strange
{
	template <typename collection_d, typename element_d>
	struct group_t : collection_t<collection_d, element_d, element_d, element_d>
	{
	protected:
		inline group_t(any_a const& me)
			: collection_t<collection_d, element_d, element_d, element_d>{ me }
		{
			me.o = group_t<collection_d, element_d>::_operations();
		}

		inline group_t(any_a const& me,
			collection_d const& collection)
			: collection_t<collection_d, element_d, element_d, element_d>{ me, collection }
		{
			me.o = group_t<collection_d, element_d>::_operations();
		}

		template <typename... elements_d>
		inline group_t(any_a const& me,
			bool const variadic,
			elements_d const&... elements)
			: collection_t<collection_d, element_d, element_d, element_d>{ me, variadic, elements... }
		{
			me.o = group_t<collection_d, element_d>::_operations();
		}

		inline group_t(any_a const& me,
			any_a const& original)
			: collection_t<collection_d, element_d, element_d, element_d>{ me, original }
		{
			me.o = group_t<collection_d, element_d>::_operations();
		}

		group_t(group_t const&) = delete;

		group_t& operator=(group_t const&) = delete;

	private:
		// group_o
		static group_o<element_d> const* _operations();
		static group_o<element_d> const* _pointer_operations();

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

		// collection_a
		static bool has(con<collection_a<element_d, element_d, element_d>> const& me,
			element_d const& key);

		static element_d at(con<collection_a<element_d, element_d, element_d>> const& me,
			element_d const& key);

		static void update(var<collection_a<element_d, element_d, element_d>> const& me,
			element_d const& key,
			element_d const& value);

		static bool insert(var<collection_a<element_d, element_d, element_d>> const& me,
			element_d const& key,
			element_d const& value);

		static bool erase(var<collection_a<element_d, element_d, element_d>> const& me,
			element_d const& key);

		static void push_front(var<collection_a<element_d, element_d, element_d>> const& me,
			element_d const& element);

		static element_d pop_front(var<collection_a<element_d, element_d, element_d>> const& me);

		static void push_back(var<collection_a<element_d, element_d, element_d>> const& me,
			element_d const& element);

		static element_d pop_back(var<collection_a<element_d, element_d, element_d>> const& me);

		static void self_assign(var<collection_a<element_d, element_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static void self_add(var<collection_a<element_d, element_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static var<collection_a<element_d, element_d, element_d>> add(con<collection_a<element_d, element_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static void self_subtract(var<collection_a<element_d, element_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static var<collection_a<element_d, element_d, element_d>> subtract(con<collection_a<element_d, element_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		// group_a
		static void update_element(var<group_a<element_d>> const& me,
			element_d const& element);

		static bool insert_element(var<group_a<element_d>> const& me,
			element_d const& element);

	public:
		// creators
		static inline var<group_a<element_d>> create_default()
		{
			any_a r;
			new group_t<collection_d, element_d>{ r };
			group_t<collection_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<group_a<element_d>>{ reinterpret_cast<group_a<element_d>&>(r) };
		}

		static inline var<group_a<element_d>> create(collection_d const& collection)
		{
			any_a r;
			new group_t<collection_d, element_d>{ r, collection };
			group_t<collection_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<group_a<element_d>>{ reinterpret_cast<group_a<element_d>&>(r) };
		}

		template <typename... elements_d>
		static inline var<group_a<element_d>> create_variadic(elements_d const&... elements)
		{
			any_a r;
			new group_t<collection_d, element_d>{ r, true, elements... };
			group_t<collection_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<group_a<element_d>>{ reinterpret_cast<group_a<element_d>&>(r) };
		}

		static inline var<group_a<element_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline var<group_a<element_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};

	template <typename element_d = var<>, typename... elements_d>
	inline var<group_a<element_d>> group(elements_d const&... elements)
	{
		return group_t<std::deque<element_d>, element_d>::create_variadic(elements...);
	}
}

#endif
