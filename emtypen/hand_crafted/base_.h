#ifndef BASE__H
#define BASE__H

#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

class base_
{
public:
	inline void print() const
	{
		assert(handle_);
		read().print();
	}

protected:
	struct base_handle_base
	{
		base_handle_base() = default;
		base_handle_base(const base_handle_base&) = default;
		base_handle_base(base_handle_base&&) = default;
		base_handle_base& operator=(const base_handle_base&) = default;
		base_handle_base& operator=(base_handle_base&&) = default;
		virtual ~base_handle_base() = default;

		virtual std::shared_ptr<base_handle_base> clone() const = 0;

		virtual void print() const = 0;
	};

	template <typename ___TTT___, typename ___BHB___ = base_handle_base>
	struct base_handle : ___BHB___
	{
		template <typename ___UUU___ = ___TTT___>
		inline base_handle(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: value_{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline base_handle(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: value_{ std::move(value) }
		{}

		virtual inline void print() const final
		{
			value_.print();
		}

		___TTT___ value_;
	};

	template <typename ___TTT___, typename ___BHB___>
	struct base_handle<std::reference_wrapper<___TTT___>, ___BHB___>
		: base_handle<___TTT___&, ___BHB___>
	{
		inline base_handle(std::reference_wrapper<___TTT___> ref)
			: base_handle<___TTT___&, ___BHB___>{ ref.get() }
		{}
	};

	template <typename ___TTT___>
	struct base_handle_ final : base_handle<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline base_handle_(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: base_handle<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline base_handle_(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: base_handle<___TTT___>{ std::move(value) }
		{}

		virtual inline std::shared_ptr<base_handle_base> clone() const final
		{
			return std::make_shared<base_handle_>(base_handle<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct base_handle_<std::reference_wrapper<___TTT___>> final
		: base_handle_<___TTT___&>
	{
		inline base_handle_(std::reference_wrapper<___TTT___> ref)
			: base_handle_<___TTT___&>{ ref.get() }
		{}
	};

	inline const base_handle_base& read() const
	{
		return *handle_;
	}

	inline base_handle_base& write()
	{
		if (!handle_.unique())
		{
			handle_ = handle_->clone();
		}
		return *handle_;
	}

	std::shared_ptr<base_handle_base> handle_;

	template <typename ___TTT___>
	friend inline bool check_(const base_& v);

	template <typename ___TTT___>
	friend inline ___TTT___ static_(const base_& v);

public:
	static inline bool check(const std::shared_ptr<base_handle_base>&)
	{
		return true;
	}

	base_() = default;
	base_(const base_&) = default;
	base_(base_&&) = default;
	base_& operator=(const base_&) = default;
	base_& operator=(base_&&) = default;
	virtual ~base_() = default;

	template <typename ___TTT___>
	inline base_(const std::shared_ptr<___TTT___>& other)
		: handle_{ other }
	{}

	template <typename ___TTT___>
	inline base_(___TTT___ value);

	template <typename ___TTT___>
	inline base_& operator=(const std::shared_ptr<___TTT___>& other)
	{
		handle_ = other;
		return *this;
	}

	template <typename ___TTT___>
	inline base_& operator=(___TTT___ value);
};

template <typename ___TTT___>
inline bool check_(const base_& v)
{
	return ___TTT___::check(v.handle_);
}

template <typename ___TTT___, typename ___VVV___>
inline bool check_(const ___VVV___&)
{
	return false;
}

template <typename ___TTT___>
inline ___TTT___ static_(const base_& v)
{
	return ___TTT___{ v.handle_ };
}

template <typename ___TTT___>
inline base_::base_(___TTT___ value)
	: handle_{ check_<base_>(value)
		? static_<base_>(std::move(value)).handle_
		: std::make_shared<base_handle_<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
{}

template <typename ___TTT___>
inline base_& base_::operator=(___TTT___ value)
{
	base_ temp{ check_<base_>(value)
		? static_<base_>(std::move(value))
		: std::move(value) };
	std::swap(temp.handle_, handle_);
	return *this;
}

#endif