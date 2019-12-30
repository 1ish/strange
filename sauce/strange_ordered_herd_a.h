#ifndef COM_ONEISH_STRANGE_ORDERED_HERD_A_H
#define COM_ONEISH_STRANGE_ORDERED_HERD_A_H

 //# include "any_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class ordered_herd_a final : public ___derived___

    {

    public:

    	inline ordered_herd_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline ordered_herd_a operator++(int)

    	{

    		assert(handle_);

    		ordered_herd_a result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline ordered_herd_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline ordered_herd_a operator--(int)

    	{

    		assert(handle_);

    		ordered_herd_a result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline ordered_herd_a& operator+=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline ordered_herd_a& operator-=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline ordered_herd_a& operator*=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline ordered_herd_a& operator/=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline ordered_herd_a& operator%=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline std :: set < any_a < >> const & extract_ordered_set ( ) const
     { assert(handle_); return read().extract_ordered_set( ); }
     inline std :: set < any_a < >> & mutate_ordered_set ( )
     { assert(handle_); return write().mutate_ordered_set( ); }
    

    private:

    	struct ___finale_handle_base___ : ___ddderived_handle_base___

    	{

      virtual inline std :: set < any_a < >> const & extract_ordered_set ( ) const = 0;
      virtual inline std :: set < any_a < >> & mutate_ordered_set ( ) = 0;
    	};

    

    	template <typename ___TTT___>

    	struct ___finale_handle_final___ final : ___ddderived_handle___<___TTT___, ___finale_handle_base___>

    	{

    		template <typename ___UUU___ = ___TTT___>

    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)

    			: ___ddderived_handle___<___TTT___, ___finale_handle_base___>{ value }

    		{}

    

    		template <typename ___UUU___ = ___TTT___>

    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept

    			: ___ddderived_handle___<___TTT___, ___finale_handle_base___>{ std::move(value) }

    		{}

    

    		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final

    		{

    			return std::make_shared<___finale_handle_final___>(___ddderived_handle___<___TTT___, ___finale_handle_base___>::value_);

    		}

    

      virtual inline std :: set < any_a < >> const & extract_ordered_set ( ) const
      { return value_.extract_ordered_set( ); }
      virtual inline std :: set < any_a < >> & mutate_ordered_set ( )
      { return value_.mutate_ordered_set( ); }
    	};

    

    	template <typename ___TTT___>

    	struct ___finale_handle_final___<std::reference_wrapper<___TTT___>> final

    		: ___finale_handle_final___<___TTT___&>

    	{

    		inline ___finale_handle_final___(std::reference_wrapper<___TTT___> ref)

    			: ___finale_handle_final___<___TTT___&>{ ref.get() }

    		{}

    	};

    

    	inline ___finale_handle_base___ const& read() const noexcept

    	{

    		return *std::static_pointer_cast<___finale_handle_base___ const>(handle_);

    	}

    

    	inline ___finale_handle_base___& write() noexcept

    	{

    		if (!___reference___ && !handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___finale_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___>

    	friend inline bool check(ordered_herd_a<> const& value) noexcept;

    

    public:

    	static inline bool ___check___(std::shared_ptr<___root_handle_base___> const& handle) noexcept

    	{

    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    

    	inline ordered_herd_a() = default;

    

    	explicit inline ordered_herd_a(bool reference) noexcept

    		: ___derived___{ reference }

    	{}

    

    	inline ordered_herd_a(ordered_herd_a const& other, bool reference) noexcept

    		: ___derived___(other, reference)

    	{}

    

    	inline ordered_herd_a(ordered_herd_a&& other, bool reference) noexcept

    		: ___derived___(std::move(other), reference)

    	{}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline ordered_herd_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)

    		: ___derived___(handle, reference)

    	{

    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis("ordered_herd_a constructor failed to cast from base to final");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline ordered_herd_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept

    		: ___derived___(handle, reference)

    	{

    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<ordered_herd_a, std::decay_t<___TTT___>>::value>>

    	explicit inline ordered_herd_a(___TTT___ value, bool reference = false) noexcept

    		: ___derived___(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{

    		handle_->___weak___(handle_);

    	}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	inline ordered_herd_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis("ordered_herd_a assignment failed to cast from base to final");

    		}

    		handle_ = handle;

    		return *this;

    	}

    #else

    	template <typename ___TTT___>

    	inline ordered_herd_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept

    	{

    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    		handle_ = handle;

    		return *this;

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<ordered_herd_a, std::decay_t<___TTT___>>::value>>

    	inline ordered_herd_a& operator=(___TTT___ value) noexcept

    	{

    		ordered_herd_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		return *this;

    	}

    

    private:

    	static bool const ___share___;

    	friend class ___ordered_herd_a_share___;

    };

    

    template <typename ___TTT___>

    inline bool check(ordered_herd_a<> const& value) noexcept

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    template <typename ___1___>

    bool const ordered_herd_a<___1___>::___share___ = []()

    {

    	auto shoal = shoal_a<>(shared(), true);

    	reflection<ordered_herd_a<___1___>>::share(shoal);

    	return shoal;

    }();

    

    #undef ___derived___

}
#endif
