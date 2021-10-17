#ifndef COM_ONEISH__STRANGE__DATA_POINTER_T_H
#define COM_ONEISH__STRANGE__DATA_POINTER_T_H

namespace strange
{
	template <typename type_d>
	struct data_pointer_t : data_t<type_d>
	{
	protected:
		inline data_pointer_t(any_a& me,
			type_d data)
		: data_t<type_d>{ me, data }
		{
			me.o = data_pointer_t<type_d>::_operations();
		}

		inline data_pointer_t(any_a& me,
			any_a const& original)
		: data_t<type_d>{ me, nullptr }
		{
			me.o = data_pointer_t<type_d>::_operations();
		}

		virtual ~data_pointer_t()
		{
			delete data_t<type_d>::data_;
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

	public:
		// creators
		static inline ptr<data_a<type_d>> create_ptr(type_d data)
		{
			any_a r;
			new data_pointer_t<type_d>{ r, data };
			data_pointer_t<type_d>::_initialise(r);
			return ptr<data_a<type_d>>{ reinterpret_cast<data_a<type_d>&>(r) };
		}

		static inline var<data_a<type_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_ptr(nullptr);
		}

		static inline var<data_a<type_d>> unpack(con<container_a> const& container)
		{
			return create_ptr(nullptr);
		}
	};

	template <typename type_d>
	inline ptr<data_a<type_d*>> dat_ptr(type_d* data)
	{
		return data_pointer_t<type_d*>::create_ptr(data);
	}

	inline ptr<> lock_o::read_lock(var<lock_a> const& me)
	{
		me.mut();
		return dat_ptr(new std::shared_lock<std::shared_mutex>(static_cast<data_t<default_copy<std::shared_mutex>>*>(me.t)->data_));
	}

	inline ptr<> lock_o::write_lock(var<lock_a> const& me)
	{
		me.mut();
		return dat_ptr(new std::unique_lock<std::shared_mutex>(static_cast<data_t<default_copy<std::shared_mutex>>*>(me.t)->data_));
	}

	inline std::shared_lock<std::shared_mutex> lock_o::_read_lock(var<lock_a> const& me)
	{
		me.mut();
		return std::shared_lock<std::shared_mutex>(static_cast<data_t<default_copy<std::shared_mutex>>*>(me.t)->data_);
	}

	inline std::unique_lock<std::shared_mutex> lock_o::_write_lock(var<lock_a> const& me)
	{
		me.mut();
		return std::unique_lock<std::shared_mutex>(static_cast<data_t<default_copy<std::shared_mutex>>*>(me.t)->data_);
	}
}

#endif
