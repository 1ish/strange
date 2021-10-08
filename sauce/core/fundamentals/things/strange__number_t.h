#ifndef COM_ONEISH__STRANGE__NUMBER_T_H
#define COM_ONEISH__STRANGE__NUMBER_T_H

namespace strange
{
	template <typename type_d>
	struct number_t : data_t<type_d>
	{
	protected:
		template <typename v=void>
		inline number_t(any_a& me)
		: data_t<type_d>{ me }
		{
			me.o = number_t<type_d>::_operations();
		}

		template <typename v = void>
		inline number_t(any_a& me,
			type_d const& data)
		: data_t<type_d>{ me, data }
		{
			me.o = number_t<type_d>::_operations();
		}

		inline number_t(any_a& me,
			type_d& data)
			: data_t<type_d>{ me, data }
		{
			me.o = number_t<type_d>::_operations();
		}

		inline number_t(any_a& me,
			any_a const& original)
		: data_t<type_d>{ me, original }
		{
			me.o = number_t<type_d>::_operations();
		}

		number_t(number_t const&) = delete;

		number_t& operator=(number_t const&) = delete;

	private:
		// number_o
		static number_o<std::remove_reference_t<type_d>> const* _operations();
		static number_o<std::remove_reference_t<type_d>> const* _pointer_operations();

	public:
		// inline
		static inline bool equal_number(con<number_a<std::remove_reference_t<type_d>>> const& me,
			con<number_a<std::remove_reference_t<type_d>>> const& other)
		{
			auto const mt = static_cast<number_t<type_d> const* const>(me.t);
			return mt->data_ == other.o->extract(other);
		}

		static inline bool less_number(con<number_a<std::remove_reference_t<type_d>>> const& me,
			con<number_a<std::remove_reference_t<type_d>>> const& other)
		{
			auto const mt = static_cast<number_t<type_d> const* const>(me.t);
			return mt->data_ < other.o->extract(other);
		}

		static inline bool less_or_equal_number(con<number_a<std::remove_reference_t<type_d>>> const& me,
			con<number_a<std::remove_reference_t<type_d>>> const& other)
		{
			auto const mt = static_cast<number_t<type_d> const* const>(me.t);
			return mt->data_ <= other.o->extract(other);
		}

		static inline bool _extractor_equal_extractor(con<forward_extractor_a<std::remove_reference_t<type_d>>> const& me,
			con<forward_extractor_a<std::remove_reference_t<type_d>>> const& other)
		{
			assert(me.o->type(me) == other.o->type(other));
			auto const mt = static_cast<number_t<type_d> const* const>(me.t);
			auto const ot = static_cast<number_t<type_d> const* const>(other.t);
			return mt->data_ == ot->data_;
		}

		static inline bool _extractor_less_extractor(con<random_access_extractor_a<std::remove_reference_t<type_d>>> const& me,
			con<random_access_extractor_a<std::remove_reference_t<type_d>>> const& other)
		{
			assert(me.o->type(me) == other.o->type(other));
			auto const mt = static_cast<number_t<type_d> const* const>(me.t);
			auto const ot = static_cast<number_t<type_d> const* const>(other.t);
			return mt->data_ < ot->data_;
		}

		static inline bool _extractor_less_or_equal_extractor(con<random_access_extractor_a<std::remove_reference_t<type_d>>> const& me,
			con<random_access_extractor_a<std::remove_reference_t<type_d>>> const& other)
		{
			assert(me.o->type(me) == other.o->type(other));
			auto const mt = static_cast<number_t<type_d> const* const>(me.t);
			auto const ot = static_cast<number_t<type_d> const* const>(other.t);
			return mt->data_ <= ot->data_;
		}

	protected:
		// any_a
		static bool is(con<> const& me,
			con<> const& abstraction);

		static bool as(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type(con<> const& me);

		static uint64_t hash(con<> const& me);

		static bool equal(con<> const& me,
			con<> const& other);

		static bool less(con<> const& me,
			con<> const& other);

		static bool less_or_equal(con<> const& me,
			con<> const& other);

		static void _copy(any_a const& me,
			any_a& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

		// numeric_a
		static int64_t int64(con<numeric_a> const& me);

		static uint64_t uint64(con<numeric_a> const& me);

		static double float64(con<numeric_a> const& me);

		static int64_t byte_size(con<numeric_a> const& me);

		static bool is_int(con<numeric_a> const& me);

		static bool is_signed(con<numeric_a> const& me);

		static bool is_nan(con<numeric_a> const& me);

		static bool is_inf(con<numeric_a> const& me);

		static bool is_finite(con<numeric_a> const& me);

		static bool is_normal(con<numeric_a> const& me);

		// mutable_numeric_a
		static void from_int64(var<mutable_numeric_a> const& me,
			int64_t number);

		static void from_uint64(var<mutable_numeric_a> const& me,
			uint64_t number);

		static void from_float64(var<mutable_numeric_a> const& me,
			double number);

		// number_a
		static var<data_a<std::remove_reference_t<type_d>>> data(con<number_a<std::remove_reference_t<type_d>>> const& me);

		static std::remove_reference_t<type_d> const& extract(con<number_a<std::remove_reference_t<type_d>>> const& me);

		static std::remove_reference_t<type_d>& mutate(var<number_a<std::remove_reference_t<type_d>>> const& me);

	private:
		// data_a
		static data_o<std::remove_reference_t<type_d>> const* _data_operations();
		static data_o<std::remove_reference_t<type_d>> const* _data_pointer_operations();

	protected:
		static bool _data_is(con<> const& me,
			con<> const& abstraction);

		static bool _data_as(con<> const& me,
			var<> const& abstraction);

		static void _data_copy(any_a const& me,
			any_a& copy);

		static void _data_set_pointer(con<> const& me,
			bool is_pointer);

		// extractor_a
		static rat<random_access_extractor_a<std::remove_reference_t<type_d>>> extractor(con<number_a<std::remove_reference_t<type_d>>> const& me);

		static std::remove_reference_t<type_d> _extractor_get(con<forward_extractor_a<std::remove_reference_t<type_d>>> const& me);

		static void _extractor_increment(var<forward_extractor_a<std::remove_reference_t<type_d>>> const& me);

		static void _extractor_decrement(var<bidirectional_extractor_a<std::remove_reference_t<type_d>>> const& me);

		static std::remove_reference_t<type_d> const& _extractor_operator_star(con<forward_extractor_a<std::remove_reference_t<type_d>>> const& me);

		static std::remove_reference_t<type_d> const* _extractor_operator_arrow(con<forward_extractor_a<std::remove_reference_t<type_d>>> const& me);

		static void _extractor_self_add(var<random_access_extractor_a<std::remove_reference_t<type_d>>> const& me,
			int64_t offset);

		static rat<random_access_extractor_a<std::remove_reference_t<type_d>>> _extractor_add(con<random_access_extractor_a<std::remove_reference_t<type_d>>> const& me,
			int64_t offset);

	private:
		static random_access_extractor_o<std::remove_reference_t<type_d>> const* _extractor_operations();
		static random_access_extractor_o<std::remove_reference_t<type_d>> const* _extractor_pointer_operations();

	protected:
		static bool _extractor_is(con<> const& me,
			con<> const& abstraction);

		static bool _extractor_as(con<> const& me,
			var<> const& abstraction);

		static bool _extractor_equal(con<> const& me,
			con<> const& other);

		static bool _extractor_less(con<> const& me,
			con<> const& other);

		static bool _extractor_less_or_equal(con<> const& me,
			con<> const& other);

		static void _extractor_copy(any_a const& me,
			any_a& copy);

		static void _extractor_set_pointer(con<> const& me,
			bool is_pointer);

	public:
		// creators
		template <typename v = void>
		static inline var<number_a<std::remove_reference_t<type_d>>> create_default()
		{
			any_a r;
			new number_t<type_d>{ r };
			number_t<type_d>::_initialise(r);
			return var<number_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<number_a<std::remove_reference_t<type_d>>&>(r) };
		}

		template <typename v = void>
		static inline var<number_a<std::remove_reference_t<type_d>>> create(type_d const& data)
		{
			any_a r;
			new number_t<type_d>{ r, data };
			number_t<type_d>::_initialise(r);
			return var<number_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<number_a<std::remove_reference_t<type_d>>&>(r) };
		}

		static inline var<number_a<std::remove_reference_t<type_d>>> create_ref(type_d& data)
		{
			any_a r;
			new number_t<type_d>{ r, data };
			number_t<type_d>::_initialise(r);
			return var<number_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<number_a<std::remove_reference_t<type_d>>&>(r) };
		}

		template <typename v = void>
		static inline var<number_a<std::remove_reference_t<type_d>>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		template <typename v = void>
		static inline var<number_a<std::remove_reference_t<type_d>>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};

	template <typename type_d>
	inline var<number_a<std::remove_reference_t<type_d>>> num(type_d const& data)
	{
		return number_t<type_d>::create(data);
	}

	template <typename type_d>
	inline var<number_a<std::remove_reference_t<type_d>>> num()
	{
		return number_t<type_d>::create_default();
	}

	template <typename type_d>
	inline var<number_a<std::remove_reference_t<type_d>>> num_ref(type_d& data)
	{
		return number_t<type_d&>::create_ref(data);
	}
}

#endif
