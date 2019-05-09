#ifndef COM_ONEISH_STRANGE_COLLECTION_A_H
#define COM_ONEISH_STRANGE_COLLECTION_A_H

// # include "any_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename number_data_a_int64 >
    class collection_a : public ___root___

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

    		% struct_name% result = *this;

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

    		% struct_name% result = *this;

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

    

     inline any_a < > has ( any_a < > const & range ) const
     { assert(handle_); return read().has(range ); }
     inline any_a < > has_ ( any_a < > const & key ) const
     { assert(handle_); return read().has_(key ); }
     inline bool has__ ( any_a < > const & key ) const
     { assert(handle_); return read().has__(key ); }
     inline any_a < > at ( any_a < > const & range ) const
     { assert(handle_); return read().at(range ); }
     inline any_a < > at_ ( any_a < > const & key ) const
     { assert(handle_); return read().at_(key ); }
     inline any_a < > update ( any_a < > const & range )
     { assert(handle_); return write().update(range ); }
     inline any_a < > update_ ( any_a < > const & key , any_a < > const & value )
     { assert(handle_); return write().update_(key, value ); }
     inline any_a < > insert ( any_a < > const & range )
     { assert(handle_); return write().insert(range ); }
     inline any_a < > insert_ ( any_a < > const & key , any_a < > const & value )
     { assert(handle_); return write().insert_(key, value ); }
     inline bool insert__ ( any_a < > const & key , any_a < > const & value )
     { assert(handle_); return write().insert__(key, value ); }
     inline any_a < > erase ( any_a < > const & range )
     { assert(handle_); return write().erase(range ); }
     inline any_a < > erase_ ( any_a < > const & key )
     { assert(handle_); return write().erase_(key ); }
     inline bool erase__ ( any_a < > const & key )
     { assert(handle_); return write().erase__(key ); }
     inline any_a < > clear ( any_a < > const & _ )
     { assert(handle_); return write().clear(_ ); }
     inline any_a < > clear_ ( )
     { assert(handle_); return write().clear_( ); }
     inline void clear__ ( )
     { assert(handle_); write().clear__( ); }
     inline any_a < > size ( any_a < > const & _ ) const
     { assert(handle_); return read().size(_ ); }
     inline number_data_a_int64 size_ ( ) const
     { assert(handle_); return read().size_( ); }
     inline int64_t size__ ( ) const
     { assert(handle_); return read().size__( ); }
     inline any_a < > empty ( any_a < > const & _ ) const
     { assert(handle_); return read().empty(_ ); }
     inline any_a < > empty_ ( ) const
     { assert(handle_); return read().empty_( ); }
     inline bool empty__ ( ) const
     { assert(handle_); return read().empty__( ); }
     inline any_a < > push_front ( any_a < > const & range )
     { assert(handle_); return write().push_front(range ); }
     inline any_a < > push_front_ ( any_a < > const & thing )
     { assert(handle_); return write().push_front_(thing ); }
     inline void push_front__ ( any_a < > const & thing )
     { assert(handle_); write().push_front__(thing ); }
     inline any_a < > pop_front ( any_a < > const & _ )
     { assert(handle_); return write().pop_front(_ ); }
     inline any_a < > pop_front_ ( )
     { assert(handle_); return write().pop_front_( ); }
     inline any_a < > push_back ( any_a < > const & range )
     { assert(handle_); return write().push_back(range ); }
     inline any_a < > push_back_ ( any_a < > const & thing )
     { assert(handle_); return write().push_back_(thing ); }
     inline void push_back__ ( any_a < > const & thing )
     { assert(handle_); write().push_back__(thing ); }
     inline any_a < > pop_back ( any_a < > const & _ )
     { assert(handle_); return write().pop_back(_ ); }
     inline any_a < > pop_back_ ( )
     { assert(handle_); return write().pop_back_( ); }
     inline any_a < > self_add ( any_a < > const & range )
     { assert(handle_); return write().self_add(range ); }
     inline collection_a self_add_ ( collection_a const & collection )
     { assert(handle_); return write().self_add_(collection ); }
     inline any_a < > add ( any_a < > const & range ) const
     { assert(handle_); return read().add(range ); }
     inline collection_a add_ ( collection_a const & collection ) const
     { assert(handle_); return read().add_(collection ); }
     inline collection_a operator + ( collection_a const & collection ) const
     { assert(handle_); return read().operator+(collection ); }
     inline any_a < > self_subtract ( any_a < > const & range )
     { assert(handle_); return write().self_subtract(range ); }
     inline collection_a self_subtract_ ( collection_a const & collection )
     { assert(handle_); return write().self_subtract_(collection ); }
     inline any_a < > subtract ( any_a < > const & range ) const
     { assert(handle_); return read().subtract(range ); }
     inline collection_a subtract_ ( collection_a const & collection ) const
     { assert(handle_); return read().subtract_(collection ); }
     inline collection_a operator - ( collection_a const & collection ) const
     { assert(handle_); return read().operator-(collection ); }
    

    protected:

    	struct ___derived_handle_base___ : ___root_handle_base___

    	{

      virtual inline any_a < > has ( any_a < > const & range ) const = 0;
      virtual inline any_a < > has_ ( any_a < > const & key ) const = 0;
      virtual inline bool has__ ( any_a < > const & key ) const = 0;
      virtual inline any_a < > at ( any_a < > const & range ) const = 0;
      virtual inline any_a < > at_ ( any_a < > const & key ) const = 0;
      virtual inline any_a < > update ( any_a < > const & range ) = 0;
      virtual inline any_a < > update_ ( any_a < > const & key , any_a < > const & value ) = 0;
      virtual inline any_a < > insert ( any_a < > const & range ) = 0;
      virtual inline any_a < > insert_ ( any_a < > const & key , any_a < > const & value ) = 0;
      virtual inline bool insert__ ( any_a < > const & key , any_a < > const & value ) = 0;
      virtual inline any_a < > erase ( any_a < > const & range ) = 0;
      virtual inline any_a < > erase_ ( any_a < > const & key ) = 0;
      virtual inline bool erase__ ( any_a < > const & key ) = 0;
      virtual inline any_a < > clear ( any_a < > const & _ ) = 0;
      virtual inline any_a < > clear_ ( ) = 0;
      virtual inline void clear__ ( ) = 0;
      virtual inline any_a < > size ( any_a < > const & _ ) const = 0;
      virtual inline number_data_a_int64 size_ ( ) const = 0;
      virtual inline int64_t size__ ( ) const = 0;
      virtual inline any_a < > empty ( any_a < > const & _ ) const = 0;
      virtual inline any_a < > empty_ ( ) const = 0;
      virtual inline bool empty__ ( ) const = 0;
      virtual inline any_a < > push_front ( any_a < > const & range ) = 0;
      virtual inline any_a < > push_front_ ( any_a < > const & thing ) = 0;
      virtual inline void push_front__ ( any_a < > const & thing ) = 0;
      virtual inline any_a < > pop_front ( any_a < > const & _ ) = 0;
      virtual inline any_a < > pop_front_ ( ) = 0;
      virtual inline any_a < > push_back ( any_a < > const & range ) = 0;
      virtual inline any_a < > push_back_ ( any_a < > const & thing ) = 0;
      virtual inline void push_back__ ( any_a < > const & thing ) = 0;
      virtual inline any_a < > pop_back ( any_a < > const & _ ) = 0;
      virtual inline any_a < > pop_back_ ( ) = 0;
      virtual inline any_a < > self_add ( any_a < > const & range ) = 0;
      virtual inline collection_a self_add_ ( collection_a const & collection ) = 0;
      virtual inline any_a < > add ( any_a < > const & range ) const = 0;
      virtual inline collection_a add_ ( collection_a const & collection ) const = 0;
      virtual inline collection_a operator + ( collection_a const & collection ) const = 0;
      virtual inline any_a < > self_subtract ( any_a < > const & range ) = 0;
      virtual inline collection_a self_subtract_ ( collection_a const & collection ) = 0;
      virtual inline any_a < > subtract ( any_a < > const & range ) const = 0;
      virtual inline collection_a subtract_ ( collection_a const & collection ) const = 0;
      virtual inline collection_a operator - ( collection_a const & collection ) const = 0;
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

    

      virtual inline any_a < > has ( any_a < > const & range ) const
      { return value_.has(range ); }
      virtual inline any_a < > has_ ( any_a < > const & key ) const
      { return value_.has_(key ); }
      virtual inline bool has__ ( any_a < > const & key ) const
      { return value_.has__(key ); }
      virtual inline any_a < > at ( any_a < > const & range ) const
      { return value_.at(range ); }
      virtual inline any_a < > at_ ( any_a < > const & key ) const
      { return value_.at_(key ); }
      virtual inline any_a < > update ( any_a < > const & range )
      { return value_.update(range ); }
      virtual inline any_a < > update_ ( any_a < > const & key , any_a < > const & value )
      { return value_.update_(key, value ); }
      virtual inline any_a < > insert ( any_a < > const & range )
      { return value_.insert(range ); }
      virtual inline any_a < > insert_ ( any_a < > const & key , any_a < > const & value )
      { return value_.insert_(key, value ); }
      virtual inline bool insert__ ( any_a < > const & key , any_a < > const & value )
      { return value_.insert__(key, value ); }
      virtual inline any_a < > erase ( any_a < > const & range )
      { return value_.erase(range ); }
      virtual inline any_a < > erase_ ( any_a < > const & key )
      { return value_.erase_(key ); }
      virtual inline bool erase__ ( any_a < > const & key )
      { return value_.erase__(key ); }
      virtual inline any_a < > clear ( any_a < > const & _ )
      { return value_.clear(_ ); }
      virtual inline any_a < > clear_ ( )
      { return value_.clear_( ); }
      virtual inline void clear__ ( )
      { value_.clear__( ); }
      virtual inline any_a < > size ( any_a < > const & _ ) const
      { return value_.size(_ ); }
      virtual inline number_data_a_int64 size_ ( ) const
      { return value_.size_( ); }
      virtual inline int64_t size__ ( ) const
      { return value_.size__( ); }
      virtual inline any_a < > empty ( any_a < > const & _ ) const
      { return value_.empty(_ ); }
      virtual inline any_a < > empty_ ( ) const
      { return value_.empty_( ); }
      virtual inline bool empty__ ( ) const
      { return value_.empty__( ); }
      virtual inline any_a < > push_front ( any_a < > const & range )
      { return value_.push_front(range ); }
      virtual inline any_a < > push_front_ ( any_a < > const & thing )
      { return value_.push_front_(thing ); }
      virtual inline void push_front__ ( any_a < > const & thing )
      { value_.push_front__(thing ); }
      virtual inline any_a < > pop_front ( any_a < > const & _ )
      { return value_.pop_front(_ ); }
      virtual inline any_a < > pop_front_ ( )
      { return value_.pop_front_( ); }
      virtual inline any_a < > push_back ( any_a < > const & range )
      { return value_.push_back(range ); }
      virtual inline any_a < > push_back_ ( any_a < > const & thing )
      { return value_.push_back_(thing ); }
      virtual inline void push_back__ ( any_a < > const & thing )
      { value_.push_back__(thing ); }
      virtual inline any_a < > pop_back ( any_a < > const & _ )
      { return value_.pop_back(_ ); }
      virtual inline any_a < > pop_back_ ( )
      { return value_.pop_back_( ); }
      virtual inline any_a < > self_add ( any_a < > const & range )
      { return value_.self_add(range ); }
      virtual inline collection_a self_add_ ( collection_a const & collection )
      { return value_.self_add_(collection ); }
      virtual inline any_a < > add ( any_a < > const & range ) const
      { return value_.add(range ); }
      virtual inline collection_a add_ ( collection_a const & collection ) const
      { return value_.add_(collection ); }
      virtual inline collection_a operator + ( collection_a const & collection ) const
      { return value_.operator+(collection ); }
      virtual inline any_a < > self_subtract ( any_a < > const & range )
      { return value_.self_subtract(range ); }
      virtual inline collection_a self_subtract_ ( collection_a const & collection )
      { return value_.self_subtract_(collection ); }
      virtual inline any_a < > subtract ( any_a < > const & range ) const
      { return value_.subtract(range ); }
      virtual inline collection_a subtract_ ( collection_a const & collection ) const
      { return value_.subtract_(collection ); }
      virtual inline collection_a operator - ( collection_a const & collection ) const
      { return value_.operator-(collection ); }
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

    

    		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final

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

    	friend inline bool check_(collection_a<> const& value) noexcept;

    

    public:

    	static inline char const* ___abstraction_name___() noexcept

    	{

    		return "collection_a";

    	}

    

    	static inline bool ___check___(std::shared_ptr<___root_handle_base___>const & handle) noexcept

    	{

    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    

    	inline collection_a() = default;

    

    	explicit inline collection_a(bool reference) noexcept

    		: ___root___{ reference }

    	{}

    

    	inline collection_a(collection_a const& other, bool reference) noexcept

    		: ___root___(other, reference)

    	{}

    

    	inline collection_a(collection_a&& other, bool reference) noexcept

    		: ___root___(std::move(other), reference)

    	{}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline collection_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)

    		: ___root___(handle, reference)

    	{

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis__("collection_a constructor failed to cast from base to derived");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline collection_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept

    		: ___root___(handle, reference)

    	{

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<collection_a, std::decay_t<___TTT___>>::value>>

    	explicit inline collection_a(___TTT___ value, bool reference = false) noexcept

    		: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	inline collection_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis__("collection_a assignment failed to cast from base to derived");

    		}

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    #else

    	template <typename ___TTT___>

    	inline collection_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept

    	{

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

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

    

}
#endif
