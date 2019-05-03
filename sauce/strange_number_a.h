#ifndef COM_ONEISH_STRANGE_NUMBER_A_H
#define COM_ONEISH_STRANGE_NUMBER_A_H

// # include "any_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class number_a : public ___root___

    {

    public:

     inline number_a decrement ( any_a < > const & _ )
     { assert(handle_); return write().decrement(_ ); }
     inline number_a decrement_ ( )
     { assert(handle_); return write().decrement_( ); }
     inline number_a self_add ( any_a < > const & range )
     { assert(handle_); return write().self_add(range ); }
     inline number_a self_add_ ( number_a const & number )
     { assert(handle_); return write().self_add_(number ); }
     inline number_a add ( any_a < > const & range ) const
     { assert(handle_); return read().add(range ); }
     inline number_a add_ ( number_a const & number ) const
     { assert(handle_); return read().add_(number ); }
     inline number_a operator + ( number_a const & number ) const
     { assert(handle_); return read().operator+(number ); }
     inline number_a self_subtract ( any_a < > const & range )
     { assert(handle_); return write().self_subtract(range ); }
     inline number_a self_subtract_ ( number_a const & number )
     { assert(handle_); return write().self_subtract_(number ); }
     inline number_a subtract ( any_a < > const & range ) const
     { assert(handle_); return read().subtract(range ); }
     inline number_a subtract_ ( number_a const & number ) const
     { assert(handle_); return read().subtract_(number ); }
     inline number_a operator - ( number_a const & number ) const
     { assert(handle_); return read().operator-(number ); }
     inline number_a self_multiply ( any_a < > const & range )
     { assert(handle_); return write().self_multiply(range ); }
     inline number_a self_multiply_ ( number_a const & number )
     { assert(handle_); return write().self_multiply_(number ); }
     inline number_a multiply ( any_a < > const & range ) const
     { assert(handle_); return read().multiply(range ); }
     inline number_a multiply_ ( number_a const & number ) const
     { assert(handle_); return read().multiply_(number ); }
     inline number_a operator * ( number_a const & number ) const
     { assert(handle_); return read().operator*(number ); }
     inline number_a self_divide ( any_a < > const & range )
     { assert(handle_); return write().self_divide(range ); }
     inline number_a self_divide_ ( number_a const & number )
     { assert(handle_); return write().self_divide_(number ); }
     inline number_a divide ( any_a < > const & range ) const
     { assert(handle_); return read().divide(range ); }
     inline number_a divide_ ( number_a const & number ) const
     { assert(handle_); return read().divide_(number ); }
     inline number_a operator / ( number_a const & number ) const
     { assert(handle_); return read().operator/(number ); }
     inline number_a self_modulo ( any_a < > const & range )
     { assert(handle_); return write().self_modulo(range ); }
     inline number_a self_modulo_ ( number_a const & number )
     { assert(handle_); return write().self_modulo_(number ); }
     inline number_a modulo ( any_a < > const & range ) const
     { assert(handle_); return read().modulo(range ); }
     inline number_a modulo_ ( number_a const & number ) const
     { assert(handle_); return read().modulo_(number ); }
     inline number_a operator % ( number_a const & number ) const
     { assert(handle_); return read().operator%(number ); }
     inline number_a to_int_64 ( any_a < > const & _ ) const
     { assert(handle_); return read().to_int_64(_ ); }
     inline number_a to_int_64_ ( ) const
     { assert(handle_); return read().to_int_64_( ); }
     inline int64_t to_int_64__ ( ) const
     { assert(handle_); return read().to_int_64__( ); }
     inline any_a < > from_int_64 ( any_a < > const & range )
     { assert(handle_); return write().from_int_64(range ); }
     inline any_a < > from_int_64_ ( number_a const & int_64 )
     { assert(handle_); return write().from_int_64_(int_64 ); }
     inline void from_int_64__ ( int64_t int_64 )
     { assert(handle_); write().from_int_64__(int_64 ); }
     inline number_a to_float_64 ( any_a < > const & _ ) const
     { assert(handle_); return read().to_float_64(_ ); }
     inline number_a to_float_64_ ( ) const
     { assert(handle_); return read().to_float_64_( ); }
     inline double to_float_64__ ( ) const
     { assert(handle_); return read().to_float_64__( ); }
     inline any_a < > from_float_64 ( any_a < > const & range )
     { assert(handle_); return write().from_float_64(range ); }
     inline any_a < > from_float_64_ ( number_a const & float_64 )
     { assert(handle_); return write().from_float_64_(float_64 ); }
     inline void from_float_64__ ( double float_64 )
     { assert(handle_); write().from_float_64__(float_64 ); }
     inline any_a < > less_than ( any_a < > const & range ) const
     { assert(handle_); return read().less_than(range ); }
     inline any_a < > less_than_ ( number_a const & number ) const
     { assert(handle_); return read().less_than_(number ); }
     inline bool operator < ( number_a const & number ) const
     { assert(handle_); return read().operator<(number ); }
     inline any_a < > greater_than ( any_a < > const & range ) const
     { assert(handle_); return read().greater_than(range ); }
     inline any_a < > greater_than_ ( number_a const & number ) const
     { assert(handle_); return read().greater_than_(number ); }
     inline bool operator > ( number_a const & number ) const
     { assert(handle_); return read().operator>(number ); }
     inline any_a < > less_or_equal ( any_a < > const & range ) const
     { assert(handle_); return read().less_or_equal(range ); }
     inline any_a < > less_or_equal_ ( number_a const & number ) const
     { assert(handle_); return read().less_or_equal_(number ); }
     inline bool operator <= ( number_a const & number ) const
     { assert(handle_); return read().operator<=(number ); }
     inline any_a < > greater_or_equal ( any_a < > const & range ) const
     { assert(handle_); return read().greater_or_equal(range ); }
     inline any_a < > greater_or_equal_ ( number_a const & number ) const
     { assert(handle_); return read().greater_or_equal_(number ); }
     inline bool operator >= ( number_a const & number ) const
     { assert(handle_); return read().operator>=(number ); }
    

    protected:

    	struct ___derived_handle_base___ : ___root_handle_base___

    	{

      virtual inline number_a decrement ( any_a < > const & _ ) = 0;
      virtual inline number_a decrement_ ( ) = 0;
      virtual inline number_a self_add ( any_a < > const & range ) = 0;
      virtual inline number_a self_add_ ( number_a const & number ) = 0;
      virtual inline number_a add ( any_a < > const & range ) const = 0;
      virtual inline number_a add_ ( number_a const & number ) const = 0;
      virtual inline number_a operator + ( number_a const & number ) const = 0;
      virtual inline number_a self_subtract ( any_a < > const & range ) = 0;
      virtual inline number_a self_subtract_ ( number_a const & number ) = 0;
      virtual inline number_a subtract ( any_a < > const & range ) const = 0;
      virtual inline number_a subtract_ ( number_a const & number ) const = 0;
      virtual inline number_a operator - ( number_a const & number ) const = 0;
      virtual inline number_a self_multiply ( any_a < > const & range ) = 0;
      virtual inline number_a self_multiply_ ( number_a const & number ) = 0;
      virtual inline number_a multiply ( any_a < > const & range ) const = 0;
      virtual inline number_a multiply_ ( number_a const & number ) const = 0;
      virtual inline number_a operator * ( number_a const & number ) const = 0;
      virtual inline number_a self_divide ( any_a < > const & range ) = 0;
      virtual inline number_a self_divide_ ( number_a const & number ) = 0;
      virtual inline number_a divide ( any_a < > const & range ) const = 0;
      virtual inline number_a divide_ ( number_a const & number ) const = 0;
      virtual inline number_a operator / ( number_a const & number ) const = 0;
      virtual inline number_a self_modulo ( any_a < > const & range ) = 0;
      virtual inline number_a self_modulo_ ( number_a const & number ) = 0;
      virtual inline number_a modulo ( any_a < > const & range ) const = 0;
      virtual inline number_a modulo_ ( number_a const & number ) const = 0;
      virtual inline number_a operator % ( number_a const & number ) const = 0;
      virtual inline number_a to_int_64 ( any_a < > const & _ ) const = 0;
      virtual inline number_a to_int_64_ ( ) const = 0;
      virtual inline int64_t to_int_64__ ( ) const = 0;
      virtual inline any_a < > from_int_64 ( any_a < > const & range ) = 0;
      virtual inline any_a < > from_int_64_ ( number_a const & int_64 ) = 0;
      virtual inline void from_int_64__ ( int64_t int_64 ) = 0;
      virtual inline number_a to_float_64 ( any_a < > const & _ ) const = 0;
      virtual inline number_a to_float_64_ ( ) const = 0;
      virtual inline double to_float_64__ ( ) const = 0;
      virtual inline any_a < > from_float_64 ( any_a < > const & range ) = 0;
      virtual inline any_a < > from_float_64_ ( number_a const & float_64 ) = 0;
      virtual inline void from_float_64__ ( double float_64 ) = 0;
      virtual inline any_a < > less_than ( any_a < > const & range ) const = 0;
      virtual inline any_a < > less_than_ ( number_a const & number ) const = 0;
      virtual inline bool operator < ( number_a const & number ) const = 0;
      virtual inline any_a < > greater_than ( any_a < > const & range ) const = 0;
      virtual inline any_a < > greater_than_ ( number_a const & number ) const = 0;
      virtual inline bool operator > ( number_a const & number ) const = 0;
      virtual inline any_a < > less_or_equal ( any_a < > const & range ) const = 0;
      virtual inline any_a < > less_or_equal_ ( number_a const & number ) const = 0;
      virtual inline bool operator <= ( number_a const & number ) const = 0;
      virtual inline any_a < > greater_or_equal ( any_a < > const & range ) const = 0;
      virtual inline any_a < > greater_or_equal_ ( number_a const & number ) const = 0;
      virtual inline bool operator >= ( number_a const & number ) const = 0;
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

    

      virtual inline number_a decrement ( any_a < > const & _ )
      { return value_.decrement(_ ); }
      virtual inline number_a decrement_ ( )
      { return value_.decrement_( ); }
      virtual inline number_a self_add ( any_a < > const & range )
      { return value_.self_add(range ); }
      virtual inline number_a self_add_ ( number_a const & number )
      { return value_.self_add_(number ); }
      virtual inline number_a add ( any_a < > const & range ) const
      { return value_.add(range ); }
      virtual inline number_a add_ ( number_a const & number ) const
      { return value_.add_(number ); }
      virtual inline number_a operator + ( number_a const & number ) const
      { return value_.operator+(number ); }
      virtual inline number_a self_subtract ( any_a < > const & range )
      { return value_.self_subtract(range ); }
      virtual inline number_a self_subtract_ ( number_a const & number )
      { return value_.self_subtract_(number ); }
      virtual inline number_a subtract ( any_a < > const & range ) const
      { return value_.subtract(range ); }
      virtual inline number_a subtract_ ( number_a const & number ) const
      { return value_.subtract_(number ); }
      virtual inline number_a operator - ( number_a const & number ) const
      { return value_.operator-(number ); }
      virtual inline number_a self_multiply ( any_a < > const & range )
      { return value_.self_multiply(range ); }
      virtual inline number_a self_multiply_ ( number_a const & number )
      { return value_.self_multiply_(number ); }
      virtual inline number_a multiply ( any_a < > const & range ) const
      { return value_.multiply(range ); }
      virtual inline number_a multiply_ ( number_a const & number ) const
      { return value_.multiply_(number ); }
      virtual inline number_a operator * ( number_a const & number ) const
      { return value_.operator*(number ); }
      virtual inline number_a self_divide ( any_a < > const & range )
      { return value_.self_divide(range ); }
      virtual inline number_a self_divide_ ( number_a const & number )
      { return value_.self_divide_(number ); }
      virtual inline number_a divide ( any_a < > const & range ) const
      { return value_.divide(range ); }
      virtual inline number_a divide_ ( number_a const & number ) const
      { return value_.divide_(number ); }
      virtual inline number_a operator / ( number_a const & number ) const
      { return value_.operator/(number ); }
      virtual inline number_a self_modulo ( any_a < > const & range )
      { return value_.self_modulo(range ); }
      virtual inline number_a self_modulo_ ( number_a const & number )
      { return value_.self_modulo_(number ); }
      virtual inline number_a modulo ( any_a < > const & range ) const
      { return value_.modulo(range ); }
      virtual inline number_a modulo_ ( number_a const & number ) const
      { return value_.modulo_(number ); }
      virtual inline number_a operator % ( number_a const & number ) const
      { return value_.operator%(number ); }
      virtual inline number_a to_int_64 ( any_a < > const & _ ) const
      { return value_.to_int_64(_ ); }
      virtual inline number_a to_int_64_ ( ) const
      { return value_.to_int_64_( ); }
      virtual inline int64_t to_int_64__ ( ) const
      { return value_.to_int_64__( ); }
      virtual inline any_a < > from_int_64 ( any_a < > const & range )
      { return value_.from_int_64(range ); }
      virtual inline any_a < > from_int_64_ ( number_a const & int_64 )
      { return value_.from_int_64_(int_64 ); }
      virtual inline void from_int_64__ ( int64_t int_64 )
      { value_.from_int_64__(int_64 ); }
      virtual inline number_a to_float_64 ( any_a < > const & _ ) const
      { return value_.to_float_64(_ ); }
      virtual inline number_a to_float_64_ ( ) const
      { return value_.to_float_64_( ); }
      virtual inline double to_float_64__ ( ) const
      { return value_.to_float_64__( ); }
      virtual inline any_a < > from_float_64 ( any_a < > const & range )
      { return value_.from_float_64(range ); }
      virtual inline any_a < > from_float_64_ ( number_a const & float_64 )
      { return value_.from_float_64_(float_64 ); }
      virtual inline void from_float_64__ ( double float_64 )
      { value_.from_float_64__(float_64 ); }
      virtual inline any_a < > less_than ( any_a < > const & range ) const
      { return value_.less_than(range ); }
      virtual inline any_a < > less_than_ ( number_a const & number ) const
      { return value_.less_than_(number ); }
      virtual inline bool operator < ( number_a const & number ) const
      { return value_.operator<(number ); }
      virtual inline any_a < > greater_than ( any_a < > const & range ) const
      { return value_.greater_than(range ); }
      virtual inline any_a < > greater_than_ ( number_a const & number ) const
      { return value_.greater_than_(number ); }
      virtual inline bool operator > ( number_a const & number ) const
      { return value_.operator>(number ); }
      virtual inline any_a < > less_or_equal ( any_a < > const & range ) const
      { return value_.less_or_equal(range ); }
      virtual inline any_a < > less_or_equal_ ( number_a const & number ) const
      { return value_.less_or_equal_(number ); }
      virtual inline bool operator <= ( number_a const & number ) const
      { return value_.operator<=(number ); }
      virtual inline any_a < > greater_or_equal ( any_a < > const & range ) const
      { return value_.greater_or_equal(range ); }
      virtual inline any_a < > greater_or_equal_ ( number_a const & number ) const
      { return value_.greater_or_equal_(number ); }
      virtual inline bool operator >= ( number_a const & number ) const
      { return value_.operator>=(number ); }
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

    

    	inline ___derived_handle_base___ const& read() const

    	{

    		return *std::static_pointer_cast<___derived_handle_base___ const>(handle_);

    	}

    

    	inline ___derived_handle_base___& write()

    	{

    		if (!___reference___ && !handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___derived_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___, typename ___1___>

    	friend inline bool check_(number_a<___1___> const& value);

    

    public:

    	static inline char const* ___abstraction_name___()

    	{

    		return "number_a";

    	}

    

    	static inline bool ___check___(std::shared_ptr<___root_handle_base___>const & handle)

    	{

    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    

    	inline number_a() = default;

    

    	explicit inline number_a(bool reference)

    		: ___root___{ reference }

    	{}

    

    	inline number_a(number_a const& other, bool reference)

    		: ___root___(other, reference)

    	{}

    

    	inline number_a(number_a&& other, bool reference)

    		: ___root___(std::move(other), reference)

    	{}

    

    	template <typename ___TTT___>

    	explicit inline number_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)

    		: ___root___(handle, reference)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis__("number_a constructor failed to cast from base to derived");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    #endif

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_a, std::decay_t<___TTT___>>::value>>

    	explicit inline number_a(___TTT___ value, bool reference = false)

    		: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{}

    

    	template <typename ___TTT___>

    	inline number_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis__("number_a assignment failed to cast from base to derived");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    #endif

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_a, std::decay_t<___TTT___>>::value>>

    	inline number_a& operator=(___TTT___ value)

    	{

    		number_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}

    };

    

    template <typename ___TTT___, typename ___1___>

    inline bool check_(number_a<___1___> const& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

}
#endif
