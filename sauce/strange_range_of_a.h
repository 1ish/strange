#ifndef COM_ONEISH_STRANGE_RANGE_OF_A_H
#define COM_ONEISH_STRANGE_RANGE_OF_A_H

 //# include "any_forward.hpp"
 //# include "range_forward.hpp"
 //# include "forward_const_iterator_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _element_ >
    class range_of_a : public ___root___
    {
    public:
    	inline range_of_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline range_of_a operator++(int)
    	{
    		assert(handle_);
    		range_of_a result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline range_of_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline range_of_a operator--(int)
    	{
    		assert(handle_);
    		range_of_a result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline range_of_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline range_of_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline range_of_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline range_of_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline range_of_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline any_a < > cbegin__ ( range_a < > const & _ ) const
     { assert(handle_); return read().cbegin__(_ ); }
     inline forward_const_iterator_a < > cbegin_ ( ) const
     { assert(handle_); return read().cbegin_( ); }
     inline any_a < > cend__ ( range_a < > const & _ ) const
     { assert(handle_); return read().cend__(_ ); }
     inline forward_const_iterator_a < > cend_ ( ) const
     { assert(handle_); return read().cend_( ); }
    
    protected:
    	struct ___derived_handle_base___ : ___root_handle_base___
    	{
      virtual inline any_a < > cbegin__ ( range_a < > const & _ ) const = 0;
      virtual inline forward_const_iterator_a < > cbegin_ ( ) const = 0;
      virtual inline any_a < > cend__ ( range_a < > const & _ ) const = 0;
      virtual inline forward_const_iterator_a < > cend_ ( ) const = 0;
    	};
    
    	template <typename ___TTT___, typename ___DHB___ = ___derived_handle_base___>
    	struct ___derived_handle___ : ___root_handle___<___TTT___, ___DHB___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___derived_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: ___root_handle___<___TTT___, ___DHB___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___derived_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: ___root_handle___<___TTT___, ___DHB___>{ std::move(value) }
    		{}
    
      virtual inline any_a < > cbegin__ ( range_a < > const & _ ) const
      { return value_.cbegin__(_ ); }
      virtual inline forward_const_iterator_a < > cbegin_ ( ) const
      { return value_.cbegin_( ); }
      virtual inline any_a < > cend__ ( range_a < > const & _ ) const
      { return value_.cend__(_ ); }
      virtual inline forward_const_iterator_a < > cend_ ( ) const
      { return value_.cend_( ); }
    	};
    
    	template <typename ___TTT___, typename ___DHB___>
    	struct ___derived_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
    		: ___derived_handle___<___TTT___&, ___DHB___>
    	{
    		inline ___derived_handle___(std::reference_wrapper<___TTT___> ref)
    			: ___derived_handle___<___TTT___&, ___DHB___>{ ref.get() }
    		{}
    	};
    
    private:
    	template <typename ___TTT___>
    	struct ___derived_handle_final___ final : ___derived_handle___<___TTT___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___derived_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: ___derived_handle___<___TTT___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___derived_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: ___derived_handle___<___TTT___>{ std::move(value) }
    		{}
    
    		virtual inline ___SHARED___ ___clone___() const final
    		{
    			return std::make_shared<___derived_handle_final___>(___derived_handle___<___TTT___>::value_);
    		}
    	};
    
    	template <typename ___TTT___>
    	struct ___derived_handle_final___<std::reference_wrapper<___TTT___>> final
    		: ___derived_handle_final___<___TTT___&>
    	{
    		inline ___derived_handle_final___(std::reference_wrapper<___TTT___> ref)
    			: ___derived_handle_final___<___TTT___&>{ ref.get() }
    		{}
    	};
    
    	inline ___derived_handle_base___ const& read() const noexcept
    	{
    		return *std::static_pointer_cast<___derived_handle_base___ const>(handle_);
    	}
    
    	inline ___derived_handle_base___& write() noexcept
    	{
    		if (!handle_.unique())
    		{
    			if (___reference___)
    			{
    				___reference___->reset();
    				if (!handle_.unique())
    				{
    					handle_ = handle_->___clone___();
    					handle_->___weak___(handle_);
    				}
    				*___reference___ = handle_;
    			}
    			else
    			{
    				handle_ = handle_->___clone___();
    				handle_->___weak___(handle_);
    			}
    		}
    		return *std::static_pointer_cast<___derived_handle_base___>(handle_);
    	}
    
    	template <typename ___TTT___>
    	friend inline bool check(range_of_a<> const& value) noexcept;
    
    public:
    	static inline bool ___check___(___SHARED___ const& handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));
    	}
    
    	inline range_of_a() = default;
    
    	inline range_of_a(range_of_a const& other, bool reference) noexcept
    		: ___root___(other, reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline range_of_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)
    		: ___root___(handle, reference)
    	{
    		if (handle && !std::dynamic_pointer_cast<___derived_handle_base___>(handle))
    		{
    			throw dis("range_of_a constructor failed to cast from base to derived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline range_of_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
    		: ___root___(handle, reference)
    	{
    		assert(!handle || std::dynamic_pointer_cast<___derived_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<range_of_a, std::decay_t<___TTT___>>::value>>
    	explicit inline range_of_a(___TTT___ value, bool reference = false) noexcept
    		: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
    			reference)
    	{
    		handle_->___weak___(handle_);
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline range_of_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (handle && !std::dynamic_pointer_cast<___derived_handle_base___>(handle))
    		{
    			throw dis("range_of_a assignment failed to cast from base to derived");
    		}
    		handle_ = handle;
    		if (___reference___)
    		{
    			*___reference___ = handle_;
    		}
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline range_of_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(!handle || std::dynamic_pointer_cast<___derived_handle_base___>(handle));
    		handle_ = handle;
    		if (___reference___)
    		{
    			*___reference___ = handle_;
    		}
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<range_of_a, std::decay_t<___TTT___>>::value>>
    	inline range_of_a& operator=(___TTT___ value) noexcept
    	{
    		range_of_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		if (___reference___)
    		{
    			*___reference___ = handle_;
    		}
    		return *this;
    	}
    
    private:
    	static bool const ___share___;
    	friend class ___range_of_a_share___;
    };
    
    template <typename ___TTT___>
    inline bool check(range_of_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    template <typename ___1___>
    bool const range_of_a<___1___>::___share___ = []()
    {
    	auto shoal = shoal_a<>(shared(), true);
    	reflection<range_of_a<___1___>>::share(shoal);
    	return shoal;
    }();
    

}
#endif
