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
		}

		inline collection_t(any_a const& me,
			collection_d const& collection)
			: thing_t{ me }
			, collection_{ collection }
		{
		}

		inline collection_t(any_a const& me,
			any_a const& original)
			: thing_t{ me, original }
			, collection_{ static_cast<collection_t<collection_d, key_d, value_d, element_d>*>(original.t)->collection_ }
		{
		}

		collection_t(collection_t const&) = delete;

		collection_t& operator=(collection_t const&) = delete;

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
		static var<symbol_a> type(con<> const& me);

		static bool equal(con<> const& me,
			con<> const& other);

		// collection_a
		static var<range_a<element_d>> range(con<collection_a<key_d, value_d, element_d>> const& me);

		static fit<forward_extractor_a<element_d>> begin(con<collection_a<key_d, value_d, element_d>> const& me);

		static fit<forward_extractor_a<element_d>> end(con<collection_a<key_d, value_d, element_d>> const& me);

		static ptr<> read_lock(con<collection_a<key_d, value_d, element_d>> const& me);

		static ptr<> write_lock(var<collection_a<key_d, value_d, element_d>> const& me);

		static void clear(var<collection_a<key_d, value_d, element_d>> const& me);

		static int64_t size(con<collection_a<key_d, value_d, element_d>> const& me);

		static bool empty(con<collection_a<key_d, value_d, element_d>> const& me);

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
	};
}

#endif
