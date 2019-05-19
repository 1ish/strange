#ifndef COM_ONEISH_STRANGE_COLLECTION_A_H
#define COM_ONEISH_STRANGE_COLLECTION_A_H

 //#include "any_forward.hpp"
 //#include "range_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename number_data_a_int64 >
    class collection_a : public ___derived___
    {
    public:
    	inline collection_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline collection_a operator++(int)
    	{
    		assert(handle_);
    		collection_a result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline collection_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline collection_a operator--(int)
    	{
    		assert(handle_);
    		collection_a result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline collection_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline collection_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline collection_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline collection_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline collection_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline any_a < > has__ ( range_a < > const & range ) const
     { assert(handle_); return read().has__(range ); }
     inline any_a < > has_ ( any_a < > const & key ) const
     { assert(handle_); return read().has_(key ); }
     inline bool has ( any_a < > const & key ) const
     { assert(handle_); return read().has(key ); }
     inline any_a < > at__ ( range_a < > const & range ) const
     { assert(handle_); return read().at__(range ); }
     inline any_a < > at_ ( any_a < > const & key ) const
     { assert(handle_); return read().at_(key ); }
     inline any_a < > update__ ( range_a < > const & range )
     { assert(handle_); return write().update__(range ); }
     inline any_a < > update_ ( any_a < > const & key , any_a < > const & value )
     { assert(handle_); return write().update_(key, value ); }
     inline any_a < > insert__ ( range_a < > const & range )
     { assert(handle_); return write().insert__(range ); }
     inline any_a < > insert_ ( any_a < > const & key , any_a < > const & value )
     { assert(handle_); return write().insert_(key, value ); }
     inline bool insert ( any_a < > const & key , any_a < > const & value )
     { assert(handle_); return write().insert(key, value ); }
     inline any_a < > erase__ ( range_a < > const & range )
     { assert(handle_); return write().erase__(range ); }
     inline any_a < > erase_ ( any_a < > const & key )
     { assert(handle_); return write().erase_(key ); }
     inline bool erase ( any_a < > const & key )
     { assert(handle_); return write().erase(key ); }
     inline any_a < > clear__ ( range_a < > const & _ )
     { assert(handle_); return write().clear__(_ ); }
     inline any_a < > clear_ ( )
     { assert(handle_); return write().clear_( ); }
     inline void clear ( )
     { assert(handle_); write().clear( ); }
     inline any_a < > size__ ( range_a < > const & _ ) const
     { assert(handle_); return read().size__(_ ); }
     inline number_data_a_int64 size_ ( ) const
     { assert(handle_); return read().size_( ); }
     inline int64_t size ( ) const
     { assert(handle_); return read().size( ); }
     inline any_a < > empty__ ( range_a < > const & _ ) const
     { assert(handle_); return read().empty__(_ ); }
     inline any_a < > empty_ ( ) const
     { assert(handle_); return read().empty_( ); }
     inline bool empty ( ) const
     { assert(handle_); return read().empty( ); }
     inline any_a < > push_front__ ( range_a < > const & range )
     { assert(handle_); return write().push_front__(range ); }
     inline any_a < > push_front_ ( any_a < > const & thing )
     { assert(handle_); return write().push_front_(thing ); }
     inline void push_front ( any_a < > const & thing )
     { assert(handle_); write().push_front(thing ); }
     inline any_a < > pop_front__ ( range_a < > const & _ )
     { assert(handle_); return write().pop_front__(_ ); }
     inline any_a < > pop_front_ ( )
     { assert(handle_); return write().pop_front_( ); }
     inline any_a < > push_back__ ( range_a < > const & range )
     { assert(handle_); return write().push_back__(range ); }
     inline any_a < > push_back_ ( any_a < > const & thing )
     { assert(handle_); return write().push_back_(thing ); }
     inline void push_back ( any_a < > const & thing )
     { assert(handle_); write().push_back(thing ); }
     inline any_a < > pop_back__ ( range_a < > const & _ )
     { assert(handle_); return write().pop_back__(_ ); }
     inline any_a < > pop_back_ ( )
     { assert(handle_); return write().pop_back_( ); }
     inline any_a < > self_add__ ( range_a < > const & range )
     { assert(handle_); return write().self_add__(range ); }
     inline range_a < > self_add_ ( range_a < > const & range )
     { assert(handle_); return write().self_add_(range ); }
     inline any_a < > add__ ( range_a < > const & range ) const
     { assert(handle_); return read().add__(range ); }
     inline range_a < > add_ ( range_a < > const & range ) const
     { assert(handle_); return read().add_(range ); }
     inline range_a < > operator + ( range_a < > const & range ) const
     { assert(handle_); return read().operator+(range ); }
     inline any_a < > self_subtract__ ( range_a < > const & range )
     { assert(handle_); return write().self_subtract__(range ); }
     inline range_a < > self_subtract_ ( range_a < > const & range )
     { assert(handle_); return write().self_subtract_(range ); }
     inline any_a < > subtract__ ( range_a < > const & range ) const
     { assert(handle_); return read().subtract__(range ); }
     inline range_a < > subtract_ ( range_a < > const & range ) const
     { assert(handle_); return read().subtract_(range ); }
     inline range_a < > operator - ( range_a < > const & range ) const
     { assert(handle_); return read().operator-(range ); }
    
    protected:
    	struct ___dderived_handle_base___ : ___derived_handle_base___
    	{
      virtual inline any_a < > has__ ( range_a < > const & range ) const = 0;
      virtual inline any_a < > has_ ( any_a < > const & key ) const = 0;
      virtual inline bool has ( any_a < > const & key ) const = 0;
      virtual inline any_a < > at__ ( range_a < > const & range ) const = 0;
      virtual inline any_a < > at_ ( any_a < > const & key ) const = 0;
      virtual inline any_a < > update__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > update_ ( any_a < > const & key , any_a < > const & value ) = 0;
      virtual inline any_a < > insert__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > insert_ ( any_a < > const & key , any_a < > const & value ) = 0;
      virtual inline bool insert ( any_a < > const & key , any_a < > const & value ) = 0;
      virtual inline any_a < > erase__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > erase_ ( any_a < > const & key ) = 0;
      virtual inline bool erase ( any_a < > const & key ) = 0;
      virtual inline any_a < > clear__ ( range_a < > const & _ ) = 0;
      virtual inline any_a < > clear_ ( ) = 0;
      virtual inline void clear ( ) = 0;
      virtual inline any_a < > size__ ( range_a < > const & _ ) const = 0;
      virtual inline number_data_a_int64 size_ ( ) const = 0;
      virtual inline int64_t size ( ) const = 0;
      virtual inline any_a < > empty__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > empty_ ( ) const = 0;
      virtual inline bool empty ( ) const = 0;
      virtual inline any_a < > push_front__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > push_front_ ( any_a < > const & thing ) = 0;
      virtual inline void push_front ( any_a < > const & thing ) = 0;
      virtual inline any_a < > pop_front__ ( range_a < > const & _ ) = 0;
      virtual inline any_a < > pop_front_ ( ) = 0;
      virtual inline any_a < > push_back__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > push_back_ ( any_a < > const & thing ) = 0;
      virtual inline void push_back ( any_a < > const & thing ) = 0;
      virtual inline any_a < > pop_back__ ( range_a < > const & _ ) = 0;
      virtual inline any_a < > pop_back_ ( ) = 0;
      virtual inline any_a < > self_add__ ( range_a < > const & range ) = 0;
      virtual inline range_a < > self_add_ ( range_a < > const & range ) = 0;
      virtual inline any_a < > add__ ( range_a < > const & range ) const = 0;
      virtual inline range_a < > add_ ( range_a < > const & range ) const = 0;
      virtual inline range_a < > operator + ( range_a < > const & range ) const = 0;
      virtual inline any_a < > self_subtract__ ( range_a < > const & range ) = 0;
      virtual inline range_a < > self_subtract_ ( range_a < > const & range ) = 0;
      virtual inline any_a < > subtract__ ( range_a < > const & range ) const = 0;
      virtual inline range_a < > subtract_ ( range_a < > const & range ) const = 0;
      virtual inline range_a < > operator - ( range_a < > const & range ) const = 0;
    	};
    
    	template <typename ___TTT___, typename ___DDHB___ = ___dderived_handle_base___>
    	struct ___dderived_handle___ : ___derived_handle___<___TTT___, ___DDHB___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___dderived_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: ___derived_handle___<___TTT___, ___DDHB___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___dderived_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: ___derived_handle___<___TTT___, ___DDHB___>{ std::move(value) }
    		{}
    
      virtual inline any_a < > has__ ( range_a < > const & range ) const
      { return value_.has__(range ); }
      virtual inline any_a < > has_ ( any_a < > const & key ) const
      { return value_.has_(key ); }
      virtual inline bool has ( any_a < > const & key ) const
      { return value_.has(key ); }
      virtual inline any_a < > at__ ( range_a < > const & range ) const
      { return value_.at__(range ); }
      virtual inline any_a < > at_ ( any_a < > const & key ) const
      { return value_.at_(key ); }
      virtual inline any_a < > update__ ( range_a < > const & range )
      { return value_.update__(range ); }
      virtual inline any_a < > update_ ( any_a < > const & key , any_a < > const & value )
      { return value_.update_(key, value ); }
      virtual inline any_a < > insert__ ( range_a < > const & range )
      { return value_.insert__(range ); }
      virtual inline any_a < > insert_ ( any_a < > const & key , any_a < > const & value )
      { return value_.insert_(key, value ); }
      virtual inline bool insert ( any_a < > const & key , any_a < > const & value )
      { return value_.insert(key, value ); }
      virtual inline any_a < > erase__ ( range_a < > const & range )
      { return value_.erase__(range ); }
      virtual inline any_a < > erase_ ( any_a < > const & key )
      { return value_.erase_(key ); }
      virtual inline bool erase ( any_a < > const & key )
      { return value_.erase(key ); }
      virtual inline any_a < > clear__ ( range_a < > const & _ )
      { return value_.clear__(_ ); }
      virtual inline any_a < > clear_ ( )
      { return value_.clear_( ); }
      virtual inline void clear ( )
      { value_.clear( ); }
      virtual inline any_a < > size__ ( range_a < > const & _ ) const
      { return value_.size__(_ ); }
      virtual inline number_data_a_int64 size_ ( ) const
      { return value_.size_( ); }
      virtual inline int64_t size ( ) const
      { return value_.size( ); }
      virtual inline any_a < > empty__ ( range_a < > const & _ ) const
      { return value_.empty__(_ ); }
      virtual inline any_a < > empty_ ( ) const
      { return value_.empty_( ); }
      virtual inline bool empty ( ) const
      { return value_.empty( ); }
      virtual inline any_a < > push_front__ ( range_a < > const & range )
      { return value_.push_front__(range ); }
      virtual inline any_a < > push_front_ ( any_a < > const & thing )
      { return value_.push_front_(thing ); }
      virtual inline void push_front ( any_a < > const & thing )
      { value_.push_front(thing ); }
      virtual inline any_a < > pop_front__ ( range_a < > const & _ )
      { return value_.pop_front__(_ ); }
      virtual inline any_a < > pop_front_ ( )
      { return value_.pop_front_( ); }
      virtual inline any_a < > push_back__ ( range_a < > const & range )
      { return value_.push_back__(range ); }
      virtual inline any_a < > push_back_ ( any_a < > const & thing )
      { return value_.push_back_(thing ); }
      virtual inline void push_back ( any_a < > const & thing )
      { value_.push_back(thing ); }
      virtual inline any_a < > pop_back__ ( range_a < > const & _ )
      { return value_.pop_back__(_ ); }
      virtual inline any_a < > pop_back_ ( )
      { return value_.pop_back_( ); }
      virtual inline any_a < > self_add__ ( range_a < > const & range )
      { return value_.self_add__(range ); }
      virtual inline range_a < > self_add_ ( range_a < > const & range )
      { return value_.self_add_(range ); }
      virtual inline any_a < > add__ ( range_a < > const & range ) const
      { return value_.add__(range ); }
      virtual inline range_a < > add_ ( range_a < > const & range ) const
      { return value_.add_(range ); }
      virtual inline range_a < > operator + ( range_a < > const & range ) const
      { return value_.operator+(range ); }
      virtual inline any_a < > self_subtract__ ( range_a < > const & range )
      { return value_.self_subtract__(range ); }
      virtual inline range_a < > self_subtract_ ( range_a < > const & range )
      { return value_.self_subtract_(range ); }
      virtual inline any_a < > subtract__ ( range_a < > const & range ) const
      { return value_.subtract__(range ); }
      virtual inline range_a < > subtract_ ( range_a < > const & range ) const
      { return value_.subtract_(range ); }
      virtual inline range_a < > operator - ( range_a < > const & range ) const
      { return value_.operator-(range ); }
    	};
    
    	template <typename ___TTT___, typename ___DDHB___>
    	struct ___dderived_handle___<std::reference_wrapper<___TTT___>, ___DDHB___>
    		: ___dderived_handle___<___TTT___&, ___DDHB___>
    	{
    		inline ___dderived_handle___(std::reference_wrapper<___TTT___> ref)
    			: ___dderived_handle___<___TTT___&, ___DDHB___>{ ref.get() }
    		{}
    	};
    
    private:
    	template <typename ___TTT___>
    	struct ___dderived_handle_final___ final : ___dderived_handle___<___TTT___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___dderived_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: ___dderived_handle___<___TTT___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___dderived_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: ___dderived_handle___<___TTT___>{ std::move(value) }
    		{}
    
    		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
    		{
    			return std::make_shared<___dderived_handle_final___>(___dderived_handle___<___TTT___>::value_);
    		}
    	};
    
    	template <typename ___TTT___>
    	struct ___dderived_handle_final___<std::reference_wrapper<___TTT___>> final
    		: ___dderived_handle_final___<___TTT___&>
    	{
    		inline ___dderived_handle_final___(std::reference_wrapper<___TTT___> ref)
    			: ___dderived_handle_final___<___TTT___&>{ ref.get() }
    		{}
    	};
    
    	inline ___dderived_handle_base___ const& read() const noexcept
    	{
    		return *std::static_pointer_cast<___dderived_handle_base___ const>(handle_);
    	}
    
    	inline ___dderived_handle_base___& write() noexcept
    	{
    		if (!___reference___ && !handle_.unique())
    		{
    			handle_ = handle_->___clone___();
    			handle_->___weak___(handle_);
    		}
    		return *std::static_pointer_cast<___dderived_handle_base___>(handle_);
    	}
    
    	template <typename ___TTT___>
    	friend inline bool check_(collection_a<> const& value) noexcept;
    
    public:
    	static inline char const* ___abstraction_name___() noexcept
    	{
    		return "collection_a";
    	}
    
    	static inline bool ___check___(std::shared_ptr<___root_handle_base___>const & handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    	}
    
    	inline collection_a() = default;
    
    	explicit inline collection_a(bool reference) noexcept
    		: ___derived___{ reference }
    	{}
    
    	inline collection_a(collection_a const& other, bool reference) noexcept
    		: ___derived___(other, reference)
    	{}
    
    	inline collection_a(collection_a&& other, bool reference) noexcept
    		: ___derived___(std::move(other), reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline collection_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)
    		: ___derived___(handle, reference)
    	{
    		if (!std::dynamic_pointer_cast<___dderived_handle_base___>(handle))
    		{
    			throw dis("collection_a constructor failed to cast from base to dderived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline collection_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
    		: ___derived___(handle, reference)
    	{
    		assert(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<collection_a, std::decay_t<___TTT___>>::value>>
    	explicit inline collection_a(___TTT___ value, bool reference = false) noexcept
    		: ___derived___(std::make_shared<___dderived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
    			reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline collection_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (!std::dynamic_pointer_cast<___dderived_handle_base___>(handle))
    		{
    			throw dis("collection_a assignment failed to cast from base to dderived");
    		}
    		handle_ = handle;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline collection_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    		handle_ = handle;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<collection_a, std::decay_t<___TTT___>>::value>>
    	inline collection_a& operator=(___TTT___ value) noexcept
    	{
    		collection_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		handle_->___weak___(handle_);
    		return *this;
    	}
    };
    
    template <typename ___TTT___>
    inline bool check_(collection_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    #undef ___derived___

}
#endif
