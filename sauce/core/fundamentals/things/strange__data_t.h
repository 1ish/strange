#ifndef COM_ONEISH__STRANGE__DATA_T_H
#define COM_ONEISH__STRANGE__DATA_T_H

namespace strange
{
	template <typename type_d>
	struct data_t : thing_t
	{
		type_d data_;

	protected:
		template <typename v=void>
		inline data_t(any_a const& me)
			: thing_t{ me }
			, data_{}
		{
			me.o = data_t<type_d>::_operations();
		}

		template <typename v = void>
		inline data_t(any_a const& me,
			type_d const& data)
		: thing_t{ me }
		, data_{ data }
		{
			me.o = data_t<type_d>::_operations();
		}

		inline data_t(any_a const& me,
			type_d& data)
			: thing_t{ me }
			, data_{ data }
		{
			me.o = data_t<type_d>::_operations();
		}

		inline data_t(any_a const& me,
			any_a const& original)
		: thing_t{ me, original }
		, data_{ static_cast<data_t<type_d>*>(original.t)->data_ }
		{
			me.o = data_t<type_d>::_operations();
		}

		data_t(data_t const&) = delete;

		data_t& operator=(data_t const&) = delete;

	private:
		// data_o
		static data_o<std::remove_reference_t<type_d>> const* _operations();
		static data_o<std::remove_reference_t<type_d>> const* _pointer_operations();

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

		// data_a
		static ptr<> read_lock(con<data_a<std::remove_reference_t<type_d>>> const& me);

		static ptr<> write_lock(var<data_a<std::remove_reference_t<type_d>>> const& me);

		static std::remove_reference_t<type_d> const& extract(con<data_a<std::remove_reference_t<type_d>>> const& me);

		static std::remove_reference_t<type_d>& mutate(var<data_a<std::remove_reference_t<type_d>>> const& me);

	public:
		// creators
		template <typename v = void>
		static inline var<data_a<std::remove_reference_t<type_d>>> create_default()
		{
			any_a r;
			new data_t<type_d>{ r };
			data_t<type_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<data_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<data_a<std::remove_reference_t<type_d>>&>(r) };
		}

		template <typename v = void>
		static inline var<data_a<std::remove_reference_t<type_d>>> create(type_d const& data)
		{
			any_a r;
			new data_t<type_d>{ r, data };
			data_t<type_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<data_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<data_a<std::remove_reference_t<type_d>>&>(r) };
		}

		template <typename v = void>
		static inline ptr<data_a<std::remove_reference_t<type_d>>> create_ptr(type_d const& data)
		{
			any_a r;
			new data_t<type_d>{ r, data };
			data_t<type_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return ptr<data_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<data_a<std::remove_reference_t<type_d>>&>(r) };
		}

		static inline var<data_a<std::remove_reference_t<type_d>>> create_ref(type_d& data)
		{
			any_a r;
			new data_t<type_d>{ r, data };
			data_t<type_d>::_initialise(reinterpret_cast<var<> const&>(r));
			return var<data_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<data_a<std::remove_reference_t<type_d>>&>(r) };
		}

		template <typename v = void>
		static inline var<data_a<std::remove_reference_t<type_d>>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		template <typename v = void>
		static inline var<data_a<std::remove_reference_t<type_d>>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};

	template <typename type_d>
	inline var<data_a<std::remove_reference_t<type_d>>> dat(type_d const& data)
	{
		return data_t<type_d>::create(data);
	}

	template <typename type_d>
	inline var<data_a<std::remove_reference_t<type_d>>> dat()
	{
		return data_t<type_d>::create_default();
	}

	template <typename type_d>
	inline var<data_a<std::remove_reference_t<type_d>>> dat_ref(type_d& data)
	{
		return data_t<type_d&>::create_ref(data);
	}

	template <typename D>
	struct default_copy : D
	{
		default_copy() = default;

		inline default_copy(default_copy const&) : D{} {} // copy constructor

		default_copy& operator=(default_copy const&) = delete; // copy assignment operator
	};

	template <typename type_d>
	inline var<data_a<default_copy<type_d>>> dat_def()
	{
		return data_t<default_copy<type_d>>::create_default();
	}
}

#endif
