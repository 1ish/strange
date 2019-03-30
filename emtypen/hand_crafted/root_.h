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
	struct ___root_handle_base___
	{
		___root_handle_base___() = default;
		___root_handle_base___(const ___root_handle_base___&) = default;
		___root_handle_base___(___root_handle_base___&&) = default;
		___root_handle_base___& operator=(const ___root_handle_base___&) = default;
		___root_handle_base___& operator=(___root_handle_base___&&) = default;
		virtual ~___root_handle_base___() = default;

		virtual std::shared_ptr<___root_handle_base___> clone() const = 0;

		virtual void print() const = 0;
	};

	template <typename ___TTT___, typename ___BHB___ = ___root_handle_base___>
	struct ___root_handle___ : ___BHB___
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___root_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: value_{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___root_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: value_{ std::move(value) }
		{}

		virtual inline void print() const final
		{
			value_.print();
		}

		___TTT___ value_;
	};

	template <typename ___TTT___, typename ___BHB___>
	struct ___root_handle___<std::reference_wrapper<___TTT___>, ___BHB___>
		: ___root_handle___<___TTT___&, ___BHB___>
	{
		inline ___root_handle___(std::reference_wrapper<___TTT___> ref)
			: ___root_handle___<___TTT___&, ___BHB___>{ ref.get() }
		{}
	};

	std::shared_ptr<___root_handle_base___> handle_;

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

		virtual inline std::shared_ptr<___root_handle_base___> clone() const final
		{
			return std::make_shared<___root_handle_final___>(___root_handle___<___TTT___>::value_);
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

	inline const ___root_handle_base___& read() const
	{
		return *handle_;
	}

	inline ___root_handle_base___& write()
	{
		if (!handle_.unique())
		{
			handle_ = handle_->clone();
		}
		return *handle_;
	}

	template <typename ___TTT___>
	friend inline bool check_(const root_& v);

	template <typename ___TTT___>
	friend inline ___TTT___ static_(const root_& v);

public:
	static inline bool check(const std::shared_ptr<___root_handle_base___>&)
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
		: std::make_shared<___root_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
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