#ifndef COM_ONEISH_STRANGE_FORWARD_ITERATOR_A_H
#define COM_ONEISH_STRANGE_FORWARD_ITERATOR_A_H

 //# include "any_forward.hpp"
 //# include "range_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class forward_iterator_a : public ___root___
    {
    public:
    	inline forward_iterator_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline forward_iterator_a operator++(int)
    	{
    		assert(handle_);
    		forward_iterator_a result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline forward_iterator_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline forward_iterator_a operator--(int)
    	{
    		assert(handle_);
    		forward_iterator_a result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline forward_iterator_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline forward_iterator_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline forward_iterator_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline forward_iterator_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline forward_iterator_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline any_a < > get__ ( range_a < > const & _ ) const
     { assert(handle_); return read().get__(_ ); }
     inline any_a < > get_ ( ) const
     { assert(handle_); return read().get_( ); }
     inline any_a < > set__ ( range_a < > const & range ) const
     { assert(handle_); return read().set__(range ); }
     inline any_a < > set_ ( any_a < > const & thing ) const
     { assert(handle_); return read().set_(thing ); }
     inline any_a < > & operator * ( ) const
     { assert(handle_); return read().operator*( ); }
     inline any_a < > * operator -> ( ) const
     { assert(handle_); return read().operator->( ); }
     inline any_a < > increment__ ( range_a < > const & _ )
     { assert(handle_); return write().increment__(_ ); }
     inline forward_iterator_a increment_ ( )
     { assert(handle_); return write().increment_( ); }
    
    protected:
    	struct ___derived_handle_base___ : ___root_handle_base___
    	{
      virtual inline any_a < > get__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > get_ ( ) const = 0;
      virtual inline any_a < > set__ ( range_a < > const & range ) const = 0;
      virtual inline any_a < > set_ ( any_a < > const & thing ) const = 0;
      virtual inline any_a < > & operator * ( ) const = 0;
      virtual inline any_a < > * operator -> ( ) const = 0;
      virtual inline any_a < > increment__ ( range_a < > const & _ ) = 0;
      virtual inline forward_iterator_a increment_ ( ) = 0;
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
    
      virtual inline any_a < > get__ ( range_a < > const & _ ) const
      { return value_.get__(_ ); }
      virtual inline any_a < > get_ ( ) const
      { return value_.get_( ); }
      virtual inline any_a < > set__ ( range_a < > const & range ) const
      { return value_.set__(range ); }
      virtual inline any_a < > set_ ( any_a < > const & thing ) const
      { return value_.set_(thing ); }
      virtual inline any_a < > & operator * ( ) const
      { return value_.operator*( ); }
      virtual inline any_a < > * operator -> ( ) const
      { return value_.operator->( ); }
      virtual inline any_a < > increment__ ( range_a < > const & _ )
      { return value_.increment__(_ ); }
      virtual inline forward_iterator_a increment_ ( )
      { return value_.increment_( ); }
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
    		if (!___reference___ && !handle_.unique())
    		{
    			handle_ = handle_->___clone___();
    			handle_->___weak___(handle_);
    		}
    		return *std::static_pointer_cast<___derived_handle_base___>(handle_);
    	}
    
    	template <typename ___TTT___>
    	friend inline bool check(forward_iterator_a<> const& value) noexcept;
    
    public:
    	static inline bool ___check___(___SHARED___ const& handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));
    	}
    
    	inline forward_iterator_a() = default;
    
    	inline forward_iterator_a(forward_iterator_a const& other, bool reference) noexcept
    		: ___root___(other, reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline forward_iterator_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)
    		: ___root___(handle, reference)
    	{
    		if (handle && !std::dynamic_pointer_cast<___derived_handle_base___>(handle))
    		{
    			throw dis("forward_iterator_a constructor failed to cast from base to derived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline forward_iterator_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
    		: ___root___(handle, reference)
    	{
    		assert(!handle || std::dynamic_pointer_cast<___derived_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_iterator_a, std::decay_t<___TTT___>>::value>>
    	explicit inline forward_iterator_a(___TTT___ value, bool reference = false) noexcept
    		: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
    			reference)
    	{
    		handle_->___weak___(handle_);
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline forward_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (handle && !std::dynamic_pointer_cast<___derived_handle_base___>(handle))
    		{
    			throw dis("forward_iterator_a assignment failed to cast from base to derived");
    		}
    		handle_ = handle;
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline forward_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(!handle || std::dynamic_pointer_cast<___derived_handle_base___>(handle));
    		handle_ = handle;
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_iterator_a, std::decay_t<___TTT___>>::value>>
    	inline forward_iterator_a& operator=(___TTT___ value) noexcept
    	{
    		forward_iterator_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		return *this;
    	}
    
    private:
    	static bool const ___share___;
    	friend class ___forward_iterator_a_share___;
    };
    
    template <typename ___TTT___>
    inline bool check(forward_iterator_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    template <typename ___1___>
    bool const forward_iterator_a<___1___>::___share___ = []()
    {
    	auto shoal = shoal_a<>(shared(), true);
    	reflection<forward_iterator_a<___1___>>::share(shoal);
    	return shoal;
    }();
    

}
#endif
