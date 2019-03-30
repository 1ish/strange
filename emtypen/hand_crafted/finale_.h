#ifndef FINALE__H
#define FINALE__H

#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

#include "derived_.h"

class finale_ final : public derived_
{
public:
	inline void finish()
	{
		assert(handle_);
		write().finish();
	}

protected:
	struct finale_handle_base : derived_handle_base
	{
		virtual void finish() = 0;
	};

	template <typename ___TTT___>
	struct finale_handle final : derived_handle<___TTT___, finale_handle_base>
	{
		template <typename ___UUU___ = ___TTT___>
		inline finale_handle(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: derived_handle<___TTT___, finale_handle_base>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline finale_handle(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: derived_handle<___TTT___, finale_handle_base>{ std::move(value) }
		{}

		virtual inline std::shared_ptr<root_handle_base> clone() const final
		{
			return std::make_shared<finale_handle>(derived_handle<___TTT___, finale_handle_base>::value_);
		}

		virtual inline void finish() final
		{
			derived_handle<___TTT___, finale_handle_base>::value_.finish();
		}
	};

	template <typename ___TTT___>
	struct finale_handle<std::reference_wrapper<___TTT___>> final
		: finale_handle<___TTT___&>
	{
		inline finale_handle(std::reference_wrapper<___TTT___> ref)
			: finale_handle<___TTT___&>{ ref.get() }
		{}
	};

	inline const finale_handle_base& read() const
	{
		return *std::static_pointer_cast<const finale_handle_base>(handle_);
	}

	inline finale_handle_base& write()
	{
		if (!handle_.unique())
		{
			handle_ = handle_->clone();
		}
		return *std::static_pointer_cast<finale_handle_base>(handle_);
	}

	template <typename ___TTT___>
	friend inline bool check_(const finale_& v);

public:
	static inline bool check(const std::shared_ptr<root_handle_base>& h)
	{
		return bool(std::dynamic_pointer_cast<finale_handle_base>(h));
	}

	finale_() = default;

	template <typename ___TTT___>
	inline finale_(const std::shared_ptr<___TTT___>& other)
		: derived_{ other }
	{
		assert(std::dynamic_pointer_cast<finale_handle_base>(other));
	}

	template <typename ___TTT___>
	inline finale_(___TTT___ value)
		: derived_{ std::make_shared<finale_handle<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{}

	template <typename ___TTT___>
	inline finale_& operator=(const std::shared_ptr<___TTT___>& other)
	{
		assert(std::dynamic_pointer_cast<finale_handle_base>(other));
		handle_ = other;
		return *this;
	}

	template <typename ___TTT___>
	inline finale_& operator=(___TTT___ value)
	{
		finale_ temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}
};

template <typename ___TTT___>
inline bool check_(const finale_& v)
{
	return ___TTT___::check(v.handle_);
}

#endif