#ifndef COM_ONEISH__STRANGE__DATA_T_H
#define COM_ONEISH__STRANGE__DATA_T_H

namespace strange
{
	template <typename type_d>
	struct data_t : thing_t
	{
		type_d data_;

	protected:
		data_t(any_a& me);

		data_t(any_a& me,
			type_d& data);

		data_t(any_a& me,
			any_a const& original);

		data_t(data_t const&) = delete;

		data_t& operator=(data_t const&) = delete;

	private:
		// data_o
		static data_o<type_d> const* _operations();
		static data_o<type_d> const* _pointer_operations();

	protected:
		// any_a
		static bool is(con<> const& me,
			con<> const& abstraction);

		static bool as(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type(con<> const& me);

		// data_a
		static type_d const& extract_data(con<data_a<type_d>> const& me);

		static type_d& mutate_data(var<data_a<type_d>> const& me);

	public:
		// creators
		static var<data_a<type_d>> create(type_d& data);

		static var<data_a<type_d>> create_default();
	};

	template <typename type_d>
	struct data_pointer_t : data_t<type_d*>
	{
	protected:
		data_pointer_t(any_a& me,
			type_d* data);

		data_pointer_t(any_a& me,
			any_a const& original);

		virtual ~data_pointer_t()
		{
			delete data_t<type_d*>::data_;
		}

	private:
		// data_o
		static data_o<type_d> const* _operations();
		static data_o<type_d> const* _pointer_operations();

	protected:
		// data_a
		static type_d const& extract_data(con<data_a<type_d>> const& me);

		static type_d& mutate_data(var<data_a<type_d>> const& me);

	public:
		// creators
		static var<data_a<type_d>> create(type_d* data);
	};

	template <typename type_d>
	inline var<data_a<type_d>> dat_val(type_d const& data)
	{
		return data_t<type_d>::create(data);
	}

	template <typename type_d>
	inline var<data_a<type_d>> dat_val()
	{
		return data_t<type_d>::create_default();
	}

	template <typename type_d>
	inline var<data_a<type_d>> dat_ref(type_d& data)
	{
		return data_t<type_d&>::create(data);
	}

	template <typename type_d>
	inline var<data_a<type_d>> dat_ptr(type_d* data)
	{
		return data_pointer_t<type_d>::create(data);
	}

	template <typename D>
	struct default_copy : D
	{
		default_copy() = default;

		default_copy(default_copy const&) : D{} {} // copy constructor

		default_copy& operator=(default_copy const&) = delete; // copy assignment operator
	};

	template <typename type_d>
	inline var<data_a<default_copy<type_d>>> dat_def()
	{
		return data_t<default_copy<type_d>>::create_default();
	}

	inline var<> lock_o::read_lock(con<lock_a> const& me)
	{
		return dat_ptr(new std::shared_lock<std::shared_timed_mutex>(static_cast<data_t<default_copy<std::shared_timed_mutex>>*>(me.t)->data_));
	}

	inline var<> lock_o::write_lock(con<lock_a> const& me)
	{
		return dat_ptr(new std::unique_lock<std::shared_timed_mutex>(static_cast<data_t<default_copy<std::shared_timed_mutex>>*>(me.t)->data_));
	}

	inline std::shared_lock<std::shared_timed_mutex> lock_o::_read_lock(con<lock_a> const& me)
	{
		return std::shared_lock<std::shared_timed_mutex>(static_cast<data_t<default_copy<std::shared_timed_mutex>>*>(me.t)->data_);
	}

	inline std::unique_lock<std::shared_timed_mutex> lock_o::_write_lock(con<lock_a> const& me)
	{
		return std::unique_lock<std::shared_timed_mutex>(static_cast<data_t<default_copy<std::shared_timed_mutex>>*>(me.t)->data_);
	}
}

#endif
