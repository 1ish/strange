#ifndef DERIVED__H
#define DERIVED__H

#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

#include "base_.h"

class derived_ : public base_
{
public:
	inline void mutate()
	{
		assert(handle_);
		write().mutate();
	}

protected:
	struct derived_handle_base : base_handle_base
	{
		virtual void mutate() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = derived_handle_base>
	struct derived_handle : base_handle<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline derived_handle(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: base_handle<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline derived_handle(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: base_handle<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline void mutate() final
		{
			base_handle<___TTT___, ___DHB___>::value_.mutate();
		}
	};

	template <typename ___TTT___, typename ___DHB___>
	struct derived_handle<std::reference_wrapper<___TTT___>, ___DHB___>
		: derived_handle<___TTT___&, ___DHB___>
	{
		inline derived_handle(std::reference_wrapper<___TTT___> ref)
			: derived_handle<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

	template <typename ___TTT___>
	struct derived_handle_ final : derived_handle<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline derived_handle_(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: derived_handle<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline derived_handle_(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: derived_handle<___TTT___>{ std::move(value) }
		{}

		virtual inline std::shared_ptr<base_handle_base> clone() const final
		{
			return std::make_shared<derived_handle_>(derived_handle<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct derived_handle_<std::reference_wrapper<___TTT___>> final
		: derived_handle_<___TTT___&>
	{
		inline derived_handle_(std::reference_wrapper<___TTT___> ref)
			: derived_handle_<___TTT___&>{ ref.get() }
		{}
	};

	inline const derived_handle_base& read() const
	{
		return *std::static_pointer_cast<const derived_handle_base>(handle_);
	}

	inline derived_handle_base& write()
	{
		if (!handle_.unique())
		{
			handle_ = handle_->clone();
		}
		return *std::static_pointer_cast<derived_handle_base>(handle_);
	}

	template <typename ___TTT___>
	friend inline bool check_(const derived_& v);

public:
	static inline bool check(const std::shared_ptr<base_handle_base>& h)
	{
		return bool(std::dynamic_pointer_cast<derived_handle_base>(h));
	}

	derived_() = default;

	template <typename ___TTT___>
	inline derived_(const std::shared_ptr<___TTT___>& other)
		: base_{ other }
	{
		assert(std::dynamic_pointer_cast<derived_handle_base>(other));
	}

	template <typename ___TTT___>
	inline derived_(___TTT___ value);

	template <typename ___TTT___>
	inline derived_& operator=(const std::shared_ptr<___TTT___>& other)
	{
		assert(std::dynamic_pointer_cast<derived_handle_base>(other));
		handle_ = other;
		return *this;
	}

	template <typename ___TTT___>
	inline derived_& operator=(___TTT___ value);
};

template <typename ___TTT___>
inline bool check_(const derived_& v)
{
	return ___TTT___::check(v.handle_);
}

template <typename ___TTT___>
inline derived_::derived_(___TTT___ value)
	: base_{ check_<derived_>(value)
		? static_<derived_>(std::move(value)).handle_
		: std::make_shared<derived_handle_<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
{}

template <typename ___TTT___>
inline derived_& derived_::operator=(___TTT___ value)
{
	derived_ temp{ check_<derived_>(value)
		? static_<derived_>(std::move(value))
		: std::move(value) };
	std::swap(temp.handle_, handle_);
	return *this;
}

#endif