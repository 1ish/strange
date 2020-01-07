#ifndef COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_DATA_A_H
#define COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_DATA_A_H

 //# include "random_access_iterator_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class random_access_iterator_data_a final : public ___derived___
    {
    public:
    	inline random_access_iterator_data_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline random_access_iterator_data_a operator++(int)
    	{
    		assert(handle_);
    		random_access_iterator_data_a result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline random_access_iterator_data_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline random_access_iterator_data_a operator--(int)
    	{
    		assert(handle_);
    		random_access_iterator_data_a result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline random_access_iterator_data_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline random_access_iterator_data_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline random_access_iterator_data_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline random_access_iterator_data_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline random_access_iterator_data_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline _1_ const & extract_it ( ) const
     { assert(handle_); return read().extract_it( ); }
     inline _1_ & mutate_it ( )
     { assert(handle_); return write().mutate_it( ); }
    
    private:
    	struct ___finale_handle_base___ : ___ddderived_handle_base___
    	{
      virtual inline _1_ const & extract_it ( ) const = 0;
      virtual inline _1_ & mutate_it ( ) = 0;
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
    
    		virtual inline ___SHARED___ ___clone___() const final
    		{
    			return std::make_shared<___finale_handle_final___>(___ddderived_handle___<___TTT___, ___finale_handle_base___>::value_);
    		}
    
      virtual inline _1_ const & extract_it ( ) const
      { return value_.extract_it( ); }
      virtual inline _1_ & mutate_it ( )
      { return value_.mutate_it( ); }
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
    		if (!handle_.unique())
    		{
    			handle_ = handle_->___clone___();
    			handle_->___weak___(handle_);
    		}
    		return *std::static_pointer_cast<___finale_handle_base___>(handle_);
    	}
    
    	template <typename ___TTT___, typename ___1___>
    	friend inline bool check(random_access_iterator_data_a<___1___> const& value) noexcept;
    
    public:
    	static inline bool ___check___(___SHARED___ const& handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    	}
    
    	inline random_access_iterator_data_a() = default;
    
    	inline random_access_iterator_data_a(random_access_iterator_data_a const& other, bool reference) noexcept
    		: ___derived___(other, reference)
    	{}
    
    	inline random_access_iterator_data_a(random_access_iterator_data_a& other, reference_tag) noexcept
    		: ___shared___{ ___SHARED___{} }
    		, handle_{ other.handle_ }
    	{}
    
    	static inline random_access_iterator_data_a ref(random_access_iterator_data_a& other) noexcept
    	{
    		return random_access_iterator_data_a(other, reference_tag{});
    	}
    
    	inline random_access_iterator_data_a(random_access_iterator_data_a& other, duplicate_tag) noexcept
    		: ___shared___{ &other.handle_ == &other.___shared___ ? other.handle_ : ___SHARED___{} }
    		, handle_{ *(&other.handle_ == &other.___shared___ ? &___shared___ : &other.handle_) }
    	{}
    
    	static inline random_access_iterator_data_a dup(random_access_iterator_data_a& other) noexcept
    	{
    		return random_access_iterator_data_a(other, duplicate_tag{});
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline random_access_iterator_data_a(std::shared_ptr<___TTT___> const& handle)
    		: ___derived___{ handle }
    	{
    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))
    		{
    			throw dis("random_access_iterator_data_a constructor failed to cast from base to final");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline random_access_iterator_data_a(std::shared_ptr<___TTT___> const& handle) noexcept
    		: ___derived___{ handle }
    	{
    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    	}
    #endif
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline random_access_iterator_data_a(std::shared_ptr<___TTT___>& handle, reference_tag)
    		: ___derived___(handle, reference_tag{})
    	{
    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))
    		{
    			throw dis("random_access_iterator_data_a constructor failed to cast from base to final");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline random_access_iterator_data_a(std::shared_ptr<___TTT___>& handle, reference_tag) noexcept
    		: ___derived___(handle, reference_tag{})
    	{
    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_iterator_data_a, std::decay_t<___TTT___>>::value>>
    	explicit inline random_access_iterator_data_a(___TTT___ value) noexcept
    		: ___derived___{ std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
    	{
    		handle_->___weak___(handle_);
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline random_access_iterator_data_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))
    		{
    			throw dis("random_access_iterator_data_a assignment failed to cast from base to final");
    		}
    		handle_ = handle;
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline random_access_iterator_data_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    		handle_ = handle;
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_iterator_data_a, std::decay_t<___TTT___>>::value>>
    	inline random_access_iterator_data_a& operator=(___TTT___ value) noexcept
    	{
    		random_access_iterator_data_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		return *this;
    	}
    
    private:
    	static bool const ___share___;
    	friend class ___random_access_iterator_data_a_share___;
    };
    
    template <typename ___TTT___, typename ___1___>
    inline bool check(random_access_iterator_data_a<___1___> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    template <typename ___1___>
    bool const random_access_iterator_data_a<___1___>::___share___ = []()
    {
    	auto& shoal = shared();
    	reflection<random_access_iterator_data_a<___1___>>::share(shoal);
    	return shoal.something();
    }();
    
    #undef ___derived___

}
#endif
