#ifndef ROOT__H
#define ROOT__H

#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

class root_
{
public:
	inline void print() const
	{
		assert(handle_);
		read().print();
	}

protected:
	struct root_handle_base
	{
		root_handle_base() = default;
		root_handle_base(const root_handle_base&) = default;
		root_handle_base(root_handle_base&&) = default;
		root_handle_base& operator=(const root_handle_base&) = default;
		root_handle_base& operator=(root_handle_base&&) = default;
		virtual ~root_handle_base() = default;

		virtual std::shared_ptr<root_handle_base> clone() const = 0;

		virtual void print() const = 0;
	};

	template <typename ___TTT___, typename ___BHB___ = root_handle_base>
	struct root_handle : ___BHB___
	{
		template <typename ___UUU___ = ___TTT___>
		inline root_handle(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: value_{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline root_handle(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: value_{ std::move(value) }
		{}

		virtual inline void print() const final
		{
			value_.print();
		}

		___TTT___ value_;
	};

	template <typename ___TTT___, typename ___BHB___>
	struct root_handle<std::reference_wrapper<___TTT___>, ___BHB___>
		: root_handle<___TTT___&, ___BHB___>
	{
		inline root_handle(std::reference_wrapper<___TTT___> ref)
			: root_handle<___TTT___&, ___BHB___>{ ref.get() }
		{}
	};

	template <typename ___TTT___>
	struct root_handle_ final : root_handle<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline root_handle_(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: root_handle<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline root_handle_(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: root_handle<___TTT___>{ std::move(value) }
		{}

		virtual inline std::shared_ptr<root_handle_base> clone() const final
		{
			return std::make_shared<root_handle_>(root_handle<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct root_handle_<std::reference_wrapper<___TTT___>> final
		: root_handle_<___TTT___&>
	{
		inline root_handle_(std::reference_wrapper<___TTT___> ref)
			: root_handle_<___TTT___&>{ ref.get() }
		{}
	};

	inline const root_handle_base& read() const
	{
		return *handle_;
	}

	inline root_handle_base& write()
	{
		if (!handle_.unique())
		{
			handle_ = handle_->clone();
		}
		return *handle_;
	}

	std::shared_ptr<root_handle_base> handle_;

	template <typename ___TTT___>
	friend inline bool check_(const root_& v);

	template <typename ___TTT___>
	friend inline ___TTT___ static_(const root_& v);

public:
	static inline bool check(const std::shared_ptr<root_handle_base>&)
	{
		return true;
	}

	root_() = default;
	root_(const root_&) = default;
	root_(root_&&) = default;
	root_& operator=(const root_&) = default;
	root_& operator=(root_&&) = default;
	virtual ~root_() = default;

	template <typename ___TTT___>
	inline root_(const std::shared_ptr<___TTT___>& other)
		: handle_{ other }
	{}

	template <typename ___TTT___>
	inline root_(___TTT___ value);

	template <typename ___TTT___>
	inline root_& operator=(const std::shared_ptr<___TTT___>& other)
	{
		handle_ = other;
		return *this;
	}

	template <typename ___TTT___>
	inline root_& operator=(___TTT___ value);
};

template <typename ___TTT___>
inline bool check_(const root_& v)
{
	return ___TTT___::check(v.handle_);
}

template <typename ___TTT___, typename ___VVV___>
inline bool check_(const ___VVV___&)
{
	return false;
}

template <typename ___TTT___>
inline ___TTT___ static_(const root_& v)
{
	return ___TTT___{ v.handle_ };
}

template <typename ___TTT___>
inline root_::root_(___TTT___ value)
	: handle_{ check_<root_>(value)
		? static_<root_>(std::move(value)).handle_
		: std::make_shared<root_handle_<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
{}

template <typename ___TTT___>
inline root_& root_::operator=(___TTT___ value)
{
	root_ temp{ check_<root_>(value)
		? static_<root_>(std::move(value))
		: std::move(value) };
	std::swap(temp.handle_, handle_);
	return *this;
}

#endif