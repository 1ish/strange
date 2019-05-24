#ifndef COM_ONEISH_STRANGE_INVENTORY_A_H
#define COM_ONEISH_STRANGE_INVENTORY_A_H

 //#include "any_forward.hpp"
 //#include "range_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename random_access_iterator_a >
    class inventory_a : public ___derived___
    {
    public:
    	inline inventory_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline inventory_a operator++(int)
    	{
    		assert(handle_);
    		inventory_a result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline inventory_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline inventory_a operator--(int)
    	{
    		assert(handle_);
    		inventory_a result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline inventory_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline inventory_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline inventory_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline inventory_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline inventory_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline bool has ( int64_t index ) const
     { assert(handle_); return read().has(index ); }
     inline any_a < > at ( int64_t index ) const
     { assert(handle_); return read().at(index ); }
     inline void update ( int64_t index , any_a < > const & value )
     { assert(handle_); write().update(index, value ); }
     inline bool insert ( int64_t index , any_a < > const & value )
     { assert(handle_); return write().insert(index, value ); }
     inline bool erase ( int64_t index )
     { assert(handle_); return write().erase(index ); }
     inline any_a < > begin__ ( range_a < > const & _ )
     { assert(handle_); return write().begin__(_ ); }
     inline random_access_iterator_a begin_ ( )
     { assert(handle_); return write().begin_( ); }
     inline random_access_iterator_a begin ( )
     { assert(handle_); return write().begin( ); }
     inline any_a < > end__ ( range_a < > const & _ )
     { assert(handle_); return write().end__(_ ); }
     inline random_access_iterator_a end_ ( )
     { assert(handle_); return write().end_( ); }
     inline random_access_iterator_a end ( )
     { assert(handle_); return write().end( ); }
    
    protected:
    	struct ___ddderived_handle_base___ : ___dderived_handle_base___
    	{
      virtual inline bool has ( int64_t index ) const = 0;
      virtual inline any_a < > at ( int64_t index ) const = 0;
      virtual inline void update ( int64_t index , any_a < > const & value ) = 0;
      virtual inline bool insert ( int64_t index , any_a < > const & value ) = 0;
      virtual inline bool erase ( int64_t index ) = 0;
      virtual inline any_a < > begin__ ( range_a < > const & _ ) = 0;
      virtual inline random_access_iterator_a begin_ ( ) = 0;
      virtual inline random_access_iterator_a begin ( ) = 0;
      virtual inline any_a < > end__ ( range_a < > const & _ ) = 0;
      virtual inline random_access_iterator_a end_ ( ) = 0;
      virtual inline random_access_iterator_a end ( ) = 0;
    	};
    
    	template <typename ___TTT___, typename ___DDDHB___ = ___ddderived_handle_base___>
    	struct ___ddderived_handle___ : ___dderived_handle___<___TTT___, ___DDDHB___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___ddderived_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: ___dderived_handle___<___TTT___, ___DDDHB___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___ddderived_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: ___dderived_handle___<___TTT___, ___DDDHB___>{ std::move(value) }
    		{}
    
      virtual inline bool has ( int64_t index ) const
      { return value_.has(index ); }
      virtual inline any_a < > at ( int64_t index ) const
      { return value_.at(index ); }
      virtual inline void update ( int64_t index , any_a < > const & value )
      { value_.update(index, value ); }
      virtual inline bool insert ( int64_t index , any_a < > const & value )
      { return value_.insert(index, value ); }
      virtual inline bool erase ( int64_t index )
      { return value_.erase(index ); }
      virtual inline any_a < > begin__ ( range_a < > const & _ )
      { return value_.begin__(_ ); }
      virtual inline random_access_iterator_a begin_ ( )
      { return value_.begin_( ); }
      virtual inline random_access_iterator_a begin ( )
      { return value_.begin( ); }
      virtual inline any_a < > end__ ( range_a < > const & _ )
      { return value_.end__(_ ); }
      virtual inline random_access_iterator_a end_ ( )
      { return value_.end_( ); }
      virtual inline random_access_iterator_a end ( )
      { return value_.end( ); }
    	};
    
    	template <typename ___TTT___, typename ___DDDHB___>
    	struct ___ddderived_handle___<std::reference_wrapper<___TTT___>, ___DDDHB___>
    		: ___ddderived_handle___<___TTT___&, ___DDDHB___>
    	{
    		inline ___ddderived_handle___(std::reference_wrapper<___TTT___> ref)
    			: ___ddderived_handle___<___TTT___&, ___DDDHB___>{ ref.get() }
    		{}
    	};
    
    private:
    	template <typename ___TTT___>
    	struct ___ddderived_handle_final___ final : ___ddderived_handle___<___TTT___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___ddderived_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: ___ddderived_handle___<___TTT___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___ddderived_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: ___ddderived_handle___<___TTT___>{ std::move(value) }
    		{}
    
    		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
    		{
    			return std::make_shared<___ddderived_handle_final___>(___ddderived_handle___<___TTT___>::value_);
    		}
    	};
    
    	template <typename ___TTT___>
    	struct ___ddderived_handle_final___<std::reference_wrapper<___TTT___>> final
    		: ___ddderived_handle_final___<___TTT___&>
    	{
    		inline ___ddderived_handle_final___(std::reference_wrapper<___TTT___> ref)
    			: ___ddderived_handle_final___<___TTT___&>{ ref.get() }
    		{}
    	};
    
    	inline ___ddderived_handle_base___ const& read() const noexcept
    	{
    		return *std::static_pointer_cast<___ddderived_handle_base___ const>(handle_);
    	}
    
    	inline ___ddderived_handle_base___& write() noexcept
    	{
    		if (!___reference___ && !handle_.unique())
    		{
    			handle_ = handle_->___clone___();
    			handle_->___weak___(handle_);
    		}
    		return *std::static_pointer_cast<___ddderived_handle_base___>(handle_);
    	}
    
    	template <typename ___TTT___>
    	friend inline bool check(inventory_a<> const& value) noexcept;
    
    public:
    	static inline bool ___check___(std::shared_ptr<___root_handle_base___>const & handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    	}
    
    	inline inventory_a() = default;
    
    	explicit inline inventory_a(bool reference) noexcept
    		: ___derived___{ reference }
    	{}
    
    	inline inventory_a(inventory_a const& other, bool reference) noexcept
    		: ___derived___(other, reference)
    	{}
    
    	inline inventory_a(inventory_a&& other, bool reference) noexcept
    		: ___derived___(std::move(other), reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline inventory_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)
    		: ___derived___(handle, reference)
    	{
    		if (!std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))
    		{
    			throw dis("inventory_a constructor failed to cast from base to ddderived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline inventory_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
    		: ___derived___(handle, reference)
    	{
    		assert(std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<inventory_a, std::decay_t<___TTT___>>::value>>
    	explicit inline inventory_a(___TTT___ value, bool reference = false) noexcept
    		: ___derived___(std::make_shared<___ddderived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
    			reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline inventory_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (!std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))
    		{
    			throw dis("inventory_a assignment failed to cast from base to ddderived");
    		}
    		handle_ = handle;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline inventory_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    		handle_ = handle;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<inventory_a, std::decay_t<___TTT___>>::value>>
    	inline inventory_a& operator=(___TTT___ value) noexcept
    	{
    		inventory_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		handle_->___weak___(handle_);
    		return *this;
    	}
    };
    
    template <typename ___TTT___>
    inline bool check(inventory_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    #undef ___derived___

}
#endif
