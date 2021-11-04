#ifndef COM_ONEISH__STRANGE__COLLECTION_T_H
#define COM_ONEISH__STRANGE__COLLECTION_T_H

namespace strange
{
	template <typename collection_d, typename key_d, typename value_d, typename element_d>
	struct collection_t : thing_t
	{
		collection_d collection_;

	protected:
		inline collection_t(any_a const& me)
			: thing_t{ me }
			, collection_{}
		{
			me.o = collection_t<collection_d, key_d, value_d, element_d>::_operations();
		}

		inline collection_t(any_a const& me,
			collection_d const& collection)
			: thing_t{ me }
			, collection_{ collection }
		{
			me.o = collection_t<collection_d, key_d, value_d, element_d>::_operations();
		}

		inline collection_t(any_a const& me,
			any_a const& original)
			: thing_t{ me, original }
			, collection_{ static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(original.t)->collection_ }
		{
			me.o = collection_t<collection_d, key_d, value_d, element_d>::_operations();
		}

		collection_t(collection_t const&) = delete;

		collection_t& operator=(collection_t const&) = delete;

	private:
		// collection_o
		static collection_o<key_d, value_d, element_d> const* _operations();
		static collection_o<key_d, value_d, element_d> const* _pointer_operations();

	public:
		// inline
		static inline bool equal_collection(con<collection_a<key_d, value_d, element_d>> const& me,
			con<collection_a<key_d, value_d, element_d>> const& other)
		{
			//TODO check other collection type is compatible
			return static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(me.t)->collection_ ==
				static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(other.t)->collection_;
		}

	protected:
		// any_a
		static bool is(con<> const& me,
			con<> const& abstraction);

		static bool as(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type(con<> const& me);

		static bool equal(con<> const& me,
			con<> const& other);

		static void _copy(con<> const& me,
			var<> const& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

		// collection_a
		static var<range_a<element_d>> range(con<collection_a<key_d, value_d, element_d>> const& me);

		static fit<forward_extractor_a<element_d>> begin(con<collection_a<key_d, value_d, element_d>> const& me);

		static fit<forward_extractor_a<element_d>> end(con<collection_a<key_d, value_d, element_d>> const& me);

		static ptr<> read_lock(con<collection_a<key_d, value_d, element_d>> const& me);

		static ptr<> write_lock(var<collection_a<key_d, value_d, element_d>> const& me);

		static bool has(con<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		static value_d at(con<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		static void update(var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key,
			value_d const& value);

		static bool insert(var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key,
			value_d const& value);

		static bool erase(var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		static void clear(var<collection_a<key_d, value_d, element_d>> const& me);

		static int64_t size(con<collection_a<key_d, value_d, element_d>> const& me);

		static bool empty(con<collection_a<key_d, value_d, element_d>> const& me);

		static void push_front(var<collection_a<key_d, value_d, element_d>> const& me,
			element_d const& element);

		static element_d pop_front(var<collection_a<key_d, value_d, element_d>> const& me);

		static void push_back(var<collection_a<key_d, value_d, element_d>> const& me,
			element_d const& element);

		static element_d pop_back(var<collection_a<key_d, value_d, element_d>> const& me);

		static void self_assign(var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static void self_add(var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static var<collection_a<key_d, value_d, element_d>> add(con<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static void self_subtract(var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		static var<collection_a<key_d, value_d, element_d>> subtract(con<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

	private:
		// range_a
		static range_o<element_d> const* _range_operations();
		static range_o<element_d> const* _range_pointer_operations();

	protected:
		static bool _range_is(con<> const& me,
			con<> const& abstraction);

		static bool _range_as(con<> const& me,
			var<> const& abstraction);

		static void _range_copy(con<> const& me,
			var<> const& copy);

		static void _range_set_pointer(con<> const& me,
			bool is_pointer);

	public:
		// creators
		static inline var<collection_a<key_d, value_d, element_d>> create_default()
		{
			any_a r;
			new collection_t<collection_d, key_d, value_d, element_d>{ r };
			collection_t<collection_d, key_d, value_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<collection_a<key_d, value_d, element_d>>{ reinterpret_cast<collection_a<key_d, value_d, element_d>&>(r) };
		}

		static inline var<collection_a<key_d, value_d, element_d>> create(collection_d const& collection)
		{
			any_a r;
			new collection_t<collection_d, key_d, value_d, element_d>{ r, collection };
			collection_t<collection_d, key_d, value_d, element_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<collection_a<key_d, value_d, element_d>>{ reinterpret_cast<collection_a<key_d, value_d, element_d>&>(r) };
		}

		static inline var<collection_a<key_d, value_d, element_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		static inline var<collection_a<key_d, value_d, element_d>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};
}

#endif
