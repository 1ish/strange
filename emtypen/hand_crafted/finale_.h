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
		assert(___handle___);
		___write___().finish();
	}

private:
	struct ___finale_handle_base___ : ___derived_handle_base___
	{
		virtual void finish() = 0;
	};

	template <typename ___TTT___>
	struct ___finale_handle_final___ final : ___derived_handle___<___TTT___, ___finale_handle_base___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: ___derived_handle___<___TTT___, ___finale_handle_base___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: ___derived_handle___<___TTT___, ___finale_handle_base___>{ std::move(value) }
		{}

		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
		{
			return std::make_shared<___finale_handle_final___>(___derived_handle___<___TTT___, ___finale_handle_base___>::___value___);
		}

		virtual inline void finish() final
		{
			___derived_handle___<___TTT___, ___finale_handle_base___>::___value___.finish();
		}
	};

	template <typename ___TTT___>
	struct ___finale_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___finale_handle_final___<___TTT___&>
	{
		inline ___finale_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___finale_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline const ___finale_handle_base___& ___read___() const
	{
		return *std::static_pointer_cast<const ___finale_handle_base___>(___handle___);
	}

	inline ___finale_handle_base___& ___write___()
	{
		if (!___reference___ && !___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
		}
		return *std::static_pointer_cast<___finale_handle_base___>(___handle___);
	}

	template <typename ___TTT___>
	friend inline bool check_(const finale_& v);

public:
	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>& h)
	{
		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(h));
	}

	finale_() = default;

	inline finale_(bool reference)
		: derived_{ reference }
	{}

	inline finale_(const finale_& other, bool reference)
		: derived_(other, reference)
	{}

	inline finale_(finale_&& other, bool reference)
		: derived_(std::move(other), reference)
	{}

	template <typename ___TTT___>
	inline finale_(const std::shared_ptr<___TTT___>& other, bool reference = false)
		: derived_(other, reference)
	{
		assert(std::dynamic_pointer_cast<___finale_handle_base___>(other));
	}

	template <typename ___TTT___>
	inline finale_(___TTT___ value, bool reference = false)
		: derived_(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
			reference)
	{}

	template <typename ___TTT___>
	inline finale_& operator=(const std::shared_ptr<___TTT___>& other)
	{
		assert(std::dynamic_pointer_cast<___finale_handle_base___>(other));
		___handle___ = other;
		return *this;
	}

	template <typename ___TTT___>
	inline finale_& operator=(___TTT___ value)
	{
		finale_ temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}
};

template <typename ___TTT___>
inline bool check_(const finale_& v)
{
	return ___TTT___::___check___(v.___handle___);
}

#endif