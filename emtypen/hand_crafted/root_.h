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
		assert(___handle___);
		___read___().print();
	}

protected:
	struct ___root_handle_base___
	{
		___root_handle_base___() = default;
		___root_handle_base___(const ___root_handle_base___&) = default;
		___root_handle_base___(___root_handle_base___&&) = default;
		___root_handle_base___& operator=(const ___root_handle_base___&) = default;
		___root_handle_base___& operator=(___root_handle_base___&&) = default;
		virtual ~___root_handle_base___() = default;

		virtual std::shared_ptr<___root_handle_base___> ___clone___() const = 0;

		virtual void print() const = 0;
	};

	template <typename ___TTT___, typename ___BHB___ = ___root_handle_base___>
	struct ___root_handle___ : ___BHB___
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___root_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: ___value___{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___root_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: ___value___{ std::move(value) }
		{}

		virtual inline void print() const final
		{
			___value___.print();
		}

		___TTT___ ___value___;
	};

	template <typename ___TTT___, typename ___BHB___>
	struct ___root_handle___<std::reference_wrapper<___TTT___>, ___BHB___>
		: ___root_handle___<___TTT___&, ___BHB___>
	{
		inline ___root_handle___(std::reference_wrapper<___TTT___> ref)
			: ___root_handle___<___TTT___&, ___BHB___>{ ref.get() }
		{}
	};

	std::shared_ptr<___root_handle_base___> ___handle___;

	const bool ___reference___;

private:
	template <typename ___TTT___>
	struct ___root_handle_final___ final : ___root_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___root_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: ___root_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___root_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: ___root_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
		{
			return std::make_shared<___root_handle_final___>(___root_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___root_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___root_handle_final___<___TTT___&>
	{
		inline ___root_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___root_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline const ___root_handle_base___& ___read___() const
	{
		return *___handle___;
	}

	inline ___root_handle_base___& ___write___()
	{
		if (!___reference___ && !___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
		}
		return *___handle___;
	}

	template <typename ___TTT___>
	friend inline bool check_(const root_& v);

	template <typename ___TTT___>
	friend inline ___TTT___ static_(const root_& v, bool reference = false);

public:
	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>&)
	{
		return true;
	}

	inline root_(bool reference = false)
		: ___handle___{}
		, ___reference___{ reference }
	{}

	inline root_(const root_& other)
		: ___handle___{ other.___handle___ }
		, ___reference___{ false }
	{}

	inline root_(root_&& other)
		: ___handle___{ std::move(other.___handle___) }
		, ___reference___{ false }
	{}

	inline root_& operator=(const root_& other)
	{
		___handle___ = other.___handle___;
		return *this;
	}

	inline root_& operator=(root_&& other)
	{
		___handle___ = std::move(other.___handle___);
		return *this;
	}

	virtual ~root_() = default;

	template <typename ___TTT___>
	inline root_(const std::shared_ptr<___TTT___>& handle, bool reference = false)
		: ___handle___{ handle }
		, ___reference___{ reference }
	{}

	template <typename ___TTT___>
	inline root_(___TTT___ value, bool reference = false);

	template <typename ___TTT___>
	inline root_& operator=(const std::shared_ptr<___TTT___>& other)
	{
		___handle___ = other;
		return *this;
	}

	template <typename ___TTT___>
	inline root_& operator=(___TTT___ value);
};

template <typename ___TTT___>
inline bool check_(const root_& v)
{
	return ___TTT___::___check___(v.___handle___);
}

template <typename ___TTT___, typename ___VVV___>
inline bool check_(const ___VVV___&)
{
	return false;
}

template <typename ___TTT___>
inline ___TTT___ static_(const root_& v, bool reference)
{
	return ___TTT___(v.___handle___, reference);
}

template <typename ___TTT___>
inline root_::root_(___TTT___ value, bool reference)
	: ___handle___{ check_<root_>(value)
		? static_<root_>(value, reference).___handle___
		: std::make_shared<___root_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	, ___reference___{ reference }
{}

template <typename ___TTT___>
inline root_& root_::operator=(___TTT___ value)
{
	root_ temp{ check_<root_>(value)
		? static_<root_>(value)
		: std::move(value) };
	std::swap(temp.___handle___, ___handle___);
	return *this;
}

#endif