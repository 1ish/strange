#ifndef COM_ONEISH__STRANGE__LOCKED_DATA_POINTER_T_H
#define COM_ONEISH__STRANGE__LOCKED_DATA_POINTER_T_H

namespace strange
{
	template <typename type_d, typename lock_d>
	struct locked_data_pointer_t : data_pointer_t<type_d>
	{
		lock_d lock_;

	protected:
		inline locked_data_pointer_t(any_a& me,
			type_d data)
			: data_pointer_t<type_d>{ me, data }
			, lock_{ create_lock<lock_d>() }
		{
			me.o = locked_data_pointer_t<type_d, lock_d>::_operations();
		}

		inline locked_data_pointer_t(any_a& me,
			any_a const& original)
			: data_pointer_t<type_d>{ me, nullptr }
			, lock_{ static_cast<locked_data_pointer_t<type_d, lock_d>*>(original.t)->lock_ }
		{
			me.o = locked_data_pointer_t<type_d, lock_d>::_operations();
		}

	private:
		// data_o
		static data_o<type_d> const* _operations();
		static data_o<type_d> const* _pointer_operations();

	protected:
		// any_a
		static var<symbol_a> type(con<> const& me);

		static void _copy(any_a const& me,
			any_a& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

		// data_a
		static ptr<> read_lock(ptr<data_a<type_d>> const& me);

		static ptr<> write_lock(ptr<data_a<type_d>> const& me);

	public:
		// creators
		static inline var<data_a<type_d>> create(type_d data)
		{
			any_a r;
			new locked_data_pointer_t<type_d, lock_d>{ r, data };
			locked_data_pointer_t<type_d, lock_d>::_initialise(r);
			return var<data_a<type_d>>{ reinterpret_cast<data_a<type_d>&>(r) };
		}

		static inline ptr<data_a<type_d>> create_ptr(type_d data)
		{
			any_a r;
			new locked_data_pointer_t<type_d, lock_d>{ r, data };
			locked_data_pointer_t<type_d, lock_d>::_initialise(r);
			return ptr<data_a<type_d>>{ reinterpret_cast<data_a<type_d>&>(r) };
		}

		static inline var<data_a<type_d>> create_from_range(con<range_a<>> const& range)
		{
			return create(nullptr);
		}

		static inline var<data_a<type_d>> unpack(con<container_a> const& container)
		{
			return create(nullptr);
		}
	};

	template <typename type_d, typename lock_d = var<lock_a>>
	inline ptr<data_a<type_d*>> locked_dat_ptr(type_d* data)
	{
		return locked_data_pointer_t<type_d*, lock_d>::create_ptr(data);
	}
}

#endif
