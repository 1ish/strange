#ifndef COM_ONEISH_STRANGE_INVENTORY_A_H
#define COM_ONEISH_STRANGE_INVENTORY_A_H

 //# include "any_forward.hpp"
 //# include "range_forward.hpp"
 //# include "random_access_iterator_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
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
    
     inline bool has_index ( int64_t index ) const
     { assert(handle_); return read().has_index(index ); }
     inline any_a < > at_index ( int64_t index ) const
     { assert(handle_); return read().at_index(index ); }
     inline void update_index ( int64_t index , any_a < > const & value )
     { assert(handle_); write().update_index(index, value ); }
     inline bool insert_index ( int64_t index , any_a < > const & value )
     { assert(handle_); return write().insert_index(index, value ); }
     inline bool erase_index ( int64_t index )
     { assert(handle_); return write().erase_index(index ); }
     inline any_a < > begin__ ( range_a < > const & _ )
     { assert(handle_); return write().begin__(_ ); }
     inline random_access_iterator_a < > begin_ ( )
     { assert(handle_); return write().begin_( ); }
     inline any_a < > end__ ( range_a < > const & _ )
     { assert(handle_); return write().end__(_ ); }
     inline random_access_iterator_a < > end_ ( )
     { assert(handle_); return write().end_( ); }
    
    protected:
    	struct ___ddderived_handle_base___ : ___dderived_handle_base___
    	{
      virtual inline bool has_index ( int64_t index ) const = 0;
      virtual inline any_a < > at_index ( int64_t index ) const = 0;
      virtual inline void update_index ( int64_t index , any_a < > const & value ) = 0;
      virtual inline bool insert_index ( int64_t index , any_a < > const & value ) = 0;
      virtual inline bool erase_index ( int64_t index ) = 0;
      virtual inline any_a < > begin__ ( range_a < > const & _ ) = 0;
      virtual inline random_access_iterator_a < > begin_ ( ) = 0;
      virtual inline any_a < > end__ ( range_a < > const & _ ) = 0;
      virtual inline random_access_iterator_a < > end_ ( ) = 0;
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
    
      virtual inline bool has_index ( int64_t index ) const
      { return value_.has_index(index ); }
      virtual inline any_a < > at_index ( int64_t index ) const
      { return value_.at_index(index ); }
      virtual inline void update_index ( int64_t index , any_a < > const & value )
      { value_.update_index(index, value ); }
      virtual inline bool insert_index ( int64_t index , any_a < > const & value )
      { return value_.insert_index(index, value ); }
      virtual inline bool erase_index ( int64_t index )
      { return value_.erase_index(index ); }
      virtual inline any_a < > begin__ ( range_a < > const & _ )
      { return value_.begin__(_ ); }
      virtual inline random_access_iterator_a < > begin_ ( )
      { return value_.begin_( ); }
      virtual inline any_a < > end__ ( range_a < > const & _ )
      { return value_.end__(_ ); }
      virtual inline random_access_iterator_a < > end_ ( )
      { return value_.end_( ); }
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
    
    		virtual inline ___SHARED___ ___clone___() const final
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
    		if (!handle_.unique())
    		{
    			handle_ = handle_->___clone___();
    			handle_->___weak___(handle_);
    		}
    		return *std::static_pointer_cast<___ddderived_handle_base___>(handle_);
    	}
    
    	template <typename ___TTT___>
    	friend inline bool check(inventory_a<> const& value) noexcept;
    
    public:
    	static inline bool ___check___(___SHARED___ const& handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    	}
    
    	inline inventory_a() = default;
    
    	inline inventory_a(inventory_a const& other, bool reference) noexcept
    		: ___derived___(other, reference)
    	{}
    
    	inline inventory_a(inventory_a& other, reference_tag) noexcept
    		: ___shared___{ ___SHARED___{} }
    		, handle_{ other.handle_ }
    	{}
    
    	static inline inventory_a ref(inventory_a& other) noexcept
    	{
    		return inventory_a(other, reference_tag{});
    	}
    
    	inline inventory_a(inventory_a& other, duplicate_tag) noexcept
    		: ___shared___{ &other.handle_ == &other.___shared___ ? other.handle_ : ___SHARED___{} }
    		, handle_{ *(&other.handle_ == &other.___shared___ ? &___shared___ : &other.handle_) }
    	{}
    
    	static inline inventory_a dup(inventory_a& other) noexcept
    	{
    		return inventory_a(other, duplicate_tag{});
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline inventory_a(std::shared_ptr<___TTT___> const& handle)
    		: ___derived___{ handle }
    	{
    		if (handle && !std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))
    		{
    			throw dis("inventory_a constructor failed to cast from base to ddderived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline inventory_a(std::shared_ptr<___TTT___> const& handle) noexcept
    		: ___derived___{ handle }
    	{
    		assert(!handle || std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    	}
    #endif
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline inventory_a(std::shared_ptr<___TTT___> const& handle, bool reference)
    		: ___derived___(handle, reference)
    	{
    		if (handle && !std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))
    		{
    			throw dis("inventory_a constructor failed to cast from base to ddderived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline inventory_a(std::shared_ptr<___TTT___> const& handle, bool reference) noexcept
    		: ___derived___(handle, reference)
    	{
    		assert(!handle || std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    	}
    #endif
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline inventory_a(std::shared_ptr<___TTT___>& handle, reference_tag)
    		: ___derived___(handle, reference_tag{})
    	{
    		if (handle && !std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))
    		{
    			throw dis("inventory_a constructor failed to cast from base to ddderived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline inventory_a(std::shared_ptr<___TTT___>& handle, reference_tag) noexcept
    		: ___derived___(handle, reference_tag{})
    	{
    		assert(!handle || std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<inventory_a, std::decay_t<___TTT___>>::value>>
    	explicit inline inventory_a(___TTT___ value) noexcept
    		: ___derived___{ std::make_shared<___ddderived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
    	{
    		handle_->___weak___(handle_);
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline inventory_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (handle && !std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))
    		{
    			throw dis("inventory_a assignment failed to cast from base to ddderived");
    		}
    		handle_ = handle;
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline inventory_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(!handle || std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    		handle_ = handle;
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<inventory_a, std::decay_t<___TTT___>>::value>>
    	inline inventory_a& operator=(___TTT___ value) noexcept
    	{
    		inventory_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		return *this;
    	}
    
    private:
    	static bool const ___share___;
    	friend class ___inventory_a_share___;
    };
    
    template <typename ___TTT___>
    inline bool check(inventory_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    template <typename ___1___>
    bool const inventory_a<___1___>::___share___ = []()
    {
    	auto& shoal = shared();
    	reflection<inventory_a<___1___>>::share(shoal);
    	return shoal.something();
    }();
    
    #undef ___derived___

}
#endif
