#ifndef COM_ONEISH_STRANGE_NUMBER_A_H
#define COM_ONEISH_STRANGE_NUMBER_A_H

 //# include "any_forward.hpp"
 //# include "range_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename number_data_a_int64 , typename number_data_a_uint64 , typename number_data_a_double >
    class number_a : public ___root___
    {
    public:
    	inline number_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline number_a operator++(int)
    	{
    		assert(handle_);
    		% struct_name% result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline number_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline number_a operator--(int)
    	{
    		assert(handle_);
    		% struct_name% result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline number_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline number_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline number_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline number_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline number_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline any_a < > increment ( range_a < > const & _ )
     { assert(handle_); return write().increment(_ ); }
     inline number_a increment_ ( )
     { assert(handle_); return write().increment_( ); }
     inline any_a < > decrement ( range_a < > const & _ )
     { assert(handle_); return write().decrement(_ ); }
     inline number_a decrement_ ( )
     { assert(handle_); return write().decrement_( ); }
     inline any_a < > self_add ( range_a < > const & range )
     { assert(handle_); return write().self_add(range ); }
     inline number_a self_add_ ( number_a const & number )
     { assert(handle_); return write().self_add_(number ); }
     inline any_a < > add ( range_a < > const & range ) const
     { assert(handle_); return read().add(range ); }
     inline number_a add_ ( number_a const & number ) const
     { assert(handle_); return read().add_(number ); }
     inline number_a operator + ( number_a const & number ) const
     { assert(handle_); return read().operator+(number ); }
     inline any_a < > self_subtract ( range_a < > const & range )
     { assert(handle_); return write().self_subtract(range ); }
     inline number_a self_subtract_ ( number_a const & number )
     { assert(handle_); return write().self_subtract_(number ); }
     inline any_a < > subtract ( range_a < > const & range ) const
     { assert(handle_); return read().subtract(range ); }
     inline number_a subtract_ ( number_a const & number ) const
     { assert(handle_); return read().subtract_(number ); }
     inline number_a operator - ( number_a const & number ) const
     { assert(handle_); return read().operator-(number ); }
     inline any_a < > self_multiply ( range_a < > const & range )
     { assert(handle_); return write().self_multiply(range ); }
     inline number_a self_multiply_ ( number_a const & number )
     { assert(handle_); return write().self_multiply_(number ); }
     inline any_a < > multiply ( range_a < > const & range ) const
     { assert(handle_); return read().multiply(range ); }
     inline number_a multiply_ ( number_a const & number ) const
     { assert(handle_); return read().multiply_(number ); }
     inline number_a operator * ( number_a const & number ) const
     { assert(handle_); return read().operator*(number ); }
     inline any_a < > self_divide ( range_a < > const & range )
     { assert(handle_); return write().self_divide(range ); }
     inline number_a self_divide_ ( number_a const & number )
     { assert(handle_); return write().self_divide_(number ); }
     inline any_a < > divide ( range_a < > const & range ) const
     { assert(handle_); return read().divide(range ); }
     inline number_a divide_ ( number_a const & number ) const
     { assert(handle_); return read().divide_(number ); }
     inline number_a operator / ( number_a const & number ) const
     { assert(handle_); return read().operator/(number ); }
     inline any_a < > self_modulo ( range_a < > const & range )
     { assert(handle_); return write().self_modulo(range ); }
     inline number_a self_modulo_ ( number_a const & number )
     { assert(handle_); return write().self_modulo_(number ); }
     inline any_a < > modulo ( range_a < > const & range ) const
     { assert(handle_); return read().modulo(range ); }
     inline number_a modulo_ ( number_a const & number ) const
     { assert(handle_); return read().modulo_(number ); }
     inline number_a operator % ( number_a const & number ) const
     { assert(handle_); return read().operator%(number ); }
     inline any_a < > to_int_64 ( range_a < > const & _ ) const
     { assert(handle_); return read().to_int_64(_ ); }
     inline number_data_a_int64 to_int_64_ ( ) const
     { assert(handle_); return read().to_int_64_( ); }
     inline int64_t to_int_64__ ( ) const
     { assert(handle_); return read().to_int_64__( ); }
     inline any_a < > from_int_64 ( range_a < > const & range )
     { assert(handle_); return write().from_int_64(range ); }
     inline any_a < > from_int_64_ ( number_data_a_int64 const & int_64 )
     { assert(handle_); return write().from_int_64_(int_64 ); }
     inline void from_int_64__ ( int64_t int_64 )
     { assert(handle_); write().from_int_64__(int_64 ); }
     inline any_a < > to_uint_64 ( range_a < > const & _ ) const
     { assert(handle_); return read().to_uint_64(_ ); }
     inline number_data_a_uint64 to_uint_64_ ( ) const
     { assert(handle_); return read().to_uint_64_( ); }
     inline uint64_t to_uint_64__ ( ) const
     { assert(handle_); return read().to_uint_64__( ); }
     inline any_a < > from_uint_64 ( range_a < > const & range )
     { assert(handle_); return write().from_uint_64(range ); }
     inline any_a < > from_uint_64_ ( number_data_a_uint64 const & uint_64 )
     { assert(handle_); return write().from_uint_64_(uint_64 ); }
     inline void from_uint_64__ ( uint64_t uint_64 )
     { assert(handle_); write().from_uint_64__(uint_64 ); }
     inline any_a < > to_float_64 ( range_a < > const & _ ) const
     { assert(handle_); return read().to_float_64(_ ); }
     inline number_data_a_double to_float_64_ ( ) const
     { assert(handle_); return read().to_float_64_( ); }
     inline double to_float_64__ ( ) const
     { assert(handle_); return read().to_float_64__( ); }
     inline any_a < > from_float_64 ( range_a < > const & range )
     { assert(handle_); return write().from_float_64(range ); }
     inline any_a < > from_float_64_ ( number_data_a_double const & float_64 )
     { assert(handle_); return write().from_float_64_(float_64 ); }
     inline void from_float_64__ ( double float_64 )
     { assert(handle_); write().from_float_64__(float_64 ); }
     inline any_a < > less_than ( range_a < > const & range ) const
     { assert(handle_); return read().less_than(range ); }
     inline any_a < > less_than_ ( number_a const & number ) const
     { assert(handle_); return read().less_than_(number ); }
     inline bool operator < ( number_a const & number ) const
     { assert(handle_); return read().operator<(number ); }
     inline any_a < > greater_than ( range_a < > const & range ) const
     { assert(handle_); return read().greater_than(range ); }
     inline any_a < > greater_than_ ( number_a const & number ) const
     { assert(handle_); return read().greater_than_(number ); }
     inline bool operator > ( number_a const & number ) const
     { assert(handle_); return read().operator>(number ); }
     inline any_a < > less_or_equal ( range_a < > const & range ) const
     { assert(handle_); return read().less_or_equal(range ); }
     inline any_a < > less_or_equal_ ( number_a const & number ) const
     { assert(handle_); return read().less_or_equal_(number ); }
     inline bool operator <= ( number_a const & number ) const
     { assert(handle_); return read().operator<=(number ); }
     inline any_a < > greater_or_equal ( range_a < > const & range ) const
     { assert(handle_); return read().greater_or_equal(range ); }
     inline any_a < > greater_or_equal_ ( number_a const & number ) const
     { assert(handle_); return read().greater_or_equal_(number ); }
     inline bool operator >= ( number_a const & number ) const
     { assert(handle_); return read().operator>=(number ); }
     inline any_a < > byte_size ( range_a < > const & _ ) const
     { assert(handle_); return read().byte_size(_ ); }
     inline number_data_a_int64 byte_size_ ( ) const
     { assert(handle_); return read().byte_size_( ); }
     inline int64_t byte_size__ ( ) const
     { assert(handle_); return read().byte_size__( ); }
     inline any_a < > is_int ( range_a < > const & _ ) const
     { assert(handle_); return read().is_int(_ ); }
     inline any_a < > is_int_ ( ) const
     { assert(handle_); return read().is_int_( ); }
     inline bool is_int__ ( ) const
     { assert(handle_); return read().is_int__( ); }
     inline any_a < > is_signed ( range_a < > const & _ ) const
     { assert(handle_); return read().is_signed(_ ); }
     inline any_a < > is_signed_ ( ) const
     { assert(handle_); return read().is_signed_( ); }
     inline bool is_signed__ ( ) const
     { assert(handle_); return read().is_signed__( ); }
     inline any_a < > is_nan ( range_a < > const & _ ) const
     { assert(handle_); return read().is_nan(_ ); }
     inline any_a < > is_nan_ ( ) const
     { assert(handle_); return read().is_nan_( ); }
     inline bool is_nan__ ( ) const
     { assert(handle_); return read().is_nan__( ); }
     inline any_a < > is_inf ( range_a < > const & _ ) const
     { assert(handle_); return read().is_inf(_ ); }
     inline any_a < > is_inf_ ( ) const
     { assert(handle_); return read().is_inf_( ); }
     inline bool is_inf__ ( ) const
     { assert(handle_); return read().is_inf__( ); }
     inline any_a < > is_finite ( range_a < > const & _ ) const
     { assert(handle_); return read().is_finite(_ ); }
     inline any_a < > is_finite_ ( ) const
     { assert(handle_); return read().is_finite_( ); }
     inline bool is_finite__ ( ) const
     { assert(handle_); return read().is_finite__( ); }
     inline any_a < > is_normal ( range_a < > const & _ ) const
     { assert(handle_); return read().is_normal(_ ); }
     inline any_a < > is_normal_ ( ) const
     { assert(handle_); return read().is_normal_( ); }
     inline bool is_normal__ ( ) const
     { assert(handle_); return read().is_normal__( ); }
     inline any_a < > little_endian ( range_a < > const & _ ) const
     { assert(handle_); return read().little_endian(_ ); }
     inline any_a < > little_endian_ ( ) const
     { assert(handle_); return read().little_endian_( ); }
     inline bool little_endian__ ( ) const
     { assert(handle_); return read().little_endian__( ); }
    
    protected:
    	struct ___derived_handle_base___ : ___root_handle_base___
    	{
      virtual inline any_a < > increment ( range_a < > const & _ ) = 0;
      virtual inline number_a increment_ ( ) = 0;
      virtual inline any_a < > decrement ( range_a < > const & _ ) = 0;
      virtual inline number_a decrement_ ( ) = 0;
      virtual inline any_a < > self_add ( range_a < > const & range ) = 0;
      virtual inline number_a self_add_ ( number_a const & number ) = 0;
      virtual inline any_a < > add ( range_a < > const & range ) const = 0;
      virtual inline number_a add_ ( number_a const & number ) const = 0;
      virtual inline number_a operator + ( number_a const & number ) const = 0;
      virtual inline any_a < > self_subtract ( range_a < > const & range ) = 0;
      virtual inline number_a self_subtract_ ( number_a const & number ) = 0;
      virtual inline any_a < > subtract ( range_a < > const & range ) const = 0;
      virtual inline number_a subtract_ ( number_a const & number ) const = 0;
      virtual inline number_a operator - ( number_a const & number ) const = 0;
      virtual inline any_a < > self_multiply ( range_a < > const & range ) = 0;
      virtual inline number_a self_multiply_ ( number_a const & number ) = 0;
      virtual inline any_a < > multiply ( range_a < > const & range ) const = 0;
      virtual inline number_a multiply_ ( number_a const & number ) const = 0;
      virtual inline number_a operator * ( number_a const & number ) const = 0;
      virtual inline any_a < > self_divide ( range_a < > const & range ) = 0;
      virtual inline number_a self_divide_ ( number_a const & number ) = 0;
      virtual inline any_a < > divide ( range_a < > const & range ) const = 0;
      virtual inline number_a divide_ ( number_a const & number ) const = 0;
      virtual inline number_a operator / ( number_a const & number ) const = 0;
      virtual inline any_a < > self_modulo ( range_a < > const & range ) = 0;
      virtual inline number_a self_modulo_ ( number_a const & number ) = 0;
      virtual inline any_a < > modulo ( range_a < > const & range ) const = 0;
      virtual inline number_a modulo_ ( number_a const & number ) const = 0;
      virtual inline number_a operator % ( number_a const & number ) const = 0;
      virtual inline any_a < > to_int_64 ( range_a < > const & _ ) const = 0;
      virtual inline number_data_a_int64 to_int_64_ ( ) const = 0;
      virtual inline int64_t to_int_64__ ( ) const = 0;
      virtual inline any_a < > from_int_64 ( range_a < > const & range ) = 0;
      virtual inline any_a < > from_int_64_ ( number_data_a_int64 const & int_64 ) = 0;
      virtual inline void from_int_64__ ( int64_t int_64 ) = 0;
      virtual inline any_a < > to_uint_64 ( range_a < > const & _ ) const = 0;
      virtual inline number_data_a_uint64 to_uint_64_ ( ) const = 0;
      virtual inline uint64_t to_uint_64__ ( ) const = 0;
      virtual inline any_a < > from_uint_64 ( range_a < > const & range ) = 0;
      virtual inline any_a < > from_uint_64_ ( number_data_a_uint64 const & uint_64 ) = 0;
      virtual inline void from_uint_64__ ( uint64_t uint_64 ) = 0;
      virtual inline any_a < > to_float_64 ( range_a < > const & _ ) const = 0;
      virtual inline number_data_a_double to_float_64_ ( ) const = 0;
      virtual inline double to_float_64__ ( ) const = 0;
      virtual inline any_a < > from_float_64 ( range_a < > const & range ) = 0;
      virtual inline any_a < > from_float_64_ ( number_data_a_double const & float_64 ) = 0;
      virtual inline void from_float_64__ ( double float_64 ) = 0;
      virtual inline any_a < > less_than ( range_a < > const & range ) const = 0;
      virtual inline any_a < > less_than_ ( number_a const & number ) const = 0;
      virtual inline bool operator < ( number_a const & number ) const = 0;
      virtual inline any_a < > greater_than ( range_a < > const & range ) const = 0;
      virtual inline any_a < > greater_than_ ( number_a const & number ) const = 0;
      virtual inline bool operator > ( number_a const & number ) const = 0;
      virtual inline any_a < > less_or_equal ( range_a < > const & range ) const = 0;
      virtual inline any_a < > less_or_equal_ ( number_a const & number ) const = 0;
      virtual inline bool operator <= ( number_a const & number ) const = 0;
      virtual inline any_a < > greater_or_equal ( range_a < > const & range ) const = 0;
      virtual inline any_a < > greater_or_equal_ ( number_a const & number ) const = 0;
      virtual inline bool operator >= ( number_a const & number ) const = 0;
      virtual inline any_a < > byte_size ( range_a < > const & _ ) const = 0;
      virtual inline number_data_a_int64 byte_size_ ( ) const = 0;
      virtual inline int64_t byte_size__ ( ) const = 0;
      virtual inline any_a < > is_int ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > is_int_ ( ) const = 0;
      virtual inline bool is_int__ ( ) const = 0;
      virtual inline any_a < > is_signed ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > is_signed_ ( ) const = 0;
      virtual inline bool is_signed__ ( ) const = 0;
      virtual inline any_a < > is_nan ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > is_nan_ ( ) const = 0;
      virtual inline bool is_nan__ ( ) const = 0;
      virtual inline any_a < > is_inf ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > is_inf_ ( ) const = 0;
      virtual inline bool is_inf__ ( ) const = 0;
      virtual inline any_a < > is_finite ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > is_finite_ ( ) const = 0;
      virtual inline bool is_finite__ ( ) const = 0;
      virtual inline any_a < > is_normal ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > is_normal_ ( ) const = 0;
      virtual inline bool is_normal__ ( ) const = 0;
      virtual inline any_a < > little_endian ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > little_endian_ ( ) const = 0;
      virtual inline bool little_endian__ ( ) const = 0;
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
    
      virtual inline any_a < > increment ( range_a < > const & _ )
      { return value_.increment(_ ); }
      virtual inline number_a increment_ ( )
      { return value_.increment_( ); }
      virtual inline any_a < > decrement ( range_a < > const & _ )
      { return value_.decrement(_ ); }
      virtual inline number_a decrement_ ( )
      { return value_.decrement_( ); }
      virtual inline any_a < > self_add ( range_a < > const & range )
      { return value_.self_add(range ); }
      virtual inline number_a self_add_ ( number_a const & number )
      { return value_.self_add_(number ); }
      virtual inline any_a < > add ( range_a < > const & range ) const
      { return value_.add(range ); }
      virtual inline number_a add_ ( number_a const & number ) const
      { return value_.add_(number ); }
      virtual inline number_a operator + ( number_a const & number ) const
      { return value_.operator+(number ); }
      virtual inline any_a < > self_subtract ( range_a < > const & range )
      { return value_.self_subtract(range ); }
      virtual inline number_a self_subtract_ ( number_a const & number )
      { return value_.self_subtract_(number ); }
      virtual inline any_a < > subtract ( range_a < > const & range ) const
      { return value_.subtract(range ); }
      virtual inline number_a subtract_ ( number_a const & number ) const
      { return value_.subtract_(number ); }
      virtual inline number_a operator - ( number_a const & number ) const
      { return value_.operator-(number ); }
      virtual inline any_a < > self_multiply ( range_a < > const & range )
      { return value_.self_multiply(range ); }
      virtual inline number_a self_multiply_ ( number_a const & number )
      { return value_.self_multiply_(number ); }
      virtual inline any_a < > multiply ( range_a < > const & range ) const
      { return value_.multiply(range ); }
      virtual inline number_a multiply_ ( number_a const & number ) const
      { return value_.multiply_(number ); }
      virtual inline number_a operator * ( number_a const & number ) const
      { return value_.operator*(number ); }
      virtual inline any_a < > self_divide ( range_a < > const & range )
      { return value_.self_divide(range ); }
      virtual inline number_a self_divide_ ( number_a const & number )
      { return value_.self_divide_(number ); }
      virtual inline any_a < > divide ( range_a < > const & range ) const
      { return value_.divide(range ); }
      virtual inline number_a divide_ ( number_a const & number ) const
      { return value_.divide_(number ); }
      virtual inline number_a operator / ( number_a const & number ) const
      { return value_.operator/(number ); }
      virtual inline any_a < > self_modulo ( range_a < > const & range )
      { return value_.self_modulo(range ); }
      virtual inline number_a self_modulo_ ( number_a const & number )
      { return value_.self_modulo_(number ); }
      virtual inline any_a < > modulo ( range_a < > const & range ) const
      { return value_.modulo(range ); }
      virtual inline number_a modulo_ ( number_a const & number ) const
      { return value_.modulo_(number ); }
      virtual inline number_a operator % ( number_a const & number ) const
      { return value_.operator%(number ); }
      virtual inline any_a < > to_int_64 ( range_a < > const & _ ) const
      { return value_.to_int_64(_ ); }
      virtual inline number_data_a_int64 to_int_64_ ( ) const
      { return value_.to_int_64_( ); }
      virtual inline int64_t to_int_64__ ( ) const
      { return value_.to_int_64__( ); }
      virtual inline any_a < > from_int_64 ( range_a < > const & range )
      { return value_.from_int_64(range ); }
      virtual inline any_a < > from_int_64_ ( number_data_a_int64 const & int_64 )
      { return value_.from_int_64_(int_64 ); }
      virtual inline void from_int_64__ ( int64_t int_64 )
      { value_.from_int_64__(int_64 ); }
      virtual inline any_a < > to_uint_64 ( range_a < > const & _ ) const
      { return value_.to_uint_64(_ ); }
      virtual inline number_data_a_uint64 to_uint_64_ ( ) const
      { return value_.to_uint_64_( ); }
      virtual inline uint64_t to_uint_64__ ( ) const
      { return value_.to_uint_64__( ); }
      virtual inline any_a < > from_uint_64 ( range_a < > const & range )
      { return value_.from_uint_64(range ); }
      virtual inline any_a < > from_uint_64_ ( number_data_a_uint64 const & uint_64 )
      { return value_.from_uint_64_(uint_64 ); }
      virtual inline void from_uint_64__ ( uint64_t uint_64 )
      { value_.from_uint_64__(uint_64 ); }
      virtual inline any_a < > to_float_64 ( range_a < > const & _ ) const
      { return value_.to_float_64(_ ); }
      virtual inline number_data_a_double to_float_64_ ( ) const
      { return value_.to_float_64_( ); }
      virtual inline double to_float_64__ ( ) const
      { return value_.to_float_64__( ); }
      virtual inline any_a < > from_float_64 ( range_a < > const & range )
      { return value_.from_float_64(range ); }
      virtual inline any_a < > from_float_64_ ( number_data_a_double const & float_64 )
      { return value_.from_float_64_(float_64 ); }
      virtual inline void from_float_64__ ( double float_64 )
      { value_.from_float_64__(float_64 ); }
      virtual inline any_a < > less_than ( range_a < > const & range ) const
      { return value_.less_than(range ); }
      virtual inline any_a < > less_than_ ( number_a const & number ) const
      { return value_.less_than_(number ); }
      virtual inline bool operator < ( number_a const & number ) const
      { return value_.operator<(number ); }
      virtual inline any_a < > greater_than ( range_a < > const & range ) const
      { return value_.greater_than(range ); }
      virtual inline any_a < > greater_than_ ( number_a const & number ) const
      { return value_.greater_than_(number ); }
      virtual inline bool operator > ( number_a const & number ) const
      { return value_.operator>(number ); }
      virtual inline any_a < > less_or_equal ( range_a < > const & range ) const
      { return value_.less_or_equal(range ); }
      virtual inline any_a < > less_or_equal_ ( number_a const & number ) const
      { return value_.less_or_equal_(number ); }
      virtual inline bool operator <= ( number_a const & number ) const
      { return value_.operator<=(number ); }
      virtual inline any_a < > greater_or_equal ( range_a < > const & range ) const
      { return value_.greater_or_equal(range ); }
      virtual inline any_a < > greater_or_equal_ ( number_a const & number ) const
      { return value_.greater_or_equal_(number ); }
      virtual inline bool operator >= ( number_a const & number ) const
      { return value_.operator>=(number ); }
      virtual inline any_a < > byte_size ( range_a < > const & _ ) const
      { return value_.byte_size(_ ); }
      virtual inline number_data_a_int64 byte_size_ ( ) const
      { return value_.byte_size_( ); }
      virtual inline int64_t byte_size__ ( ) const
      { return value_.byte_size__( ); }
      virtual inline any_a < > is_int ( range_a < > const & _ ) const
      { return value_.is_int(_ ); }
      virtual inline any_a < > is_int_ ( ) const
      { return value_.is_int_( ); }
      virtual inline bool is_int__ ( ) const
      { return value_.is_int__( ); }
      virtual inline any_a < > is_signed ( range_a < > const & _ ) const
      { return value_.is_signed(_ ); }
      virtual inline any_a < > is_signed_ ( ) const
      { return value_.is_signed_( ); }
      virtual inline bool is_signed__ ( ) const
      { return value_.is_signed__( ); }
      virtual inline any_a < > is_nan ( range_a < > const & _ ) const
      { return value_.is_nan(_ ); }
      virtual inline any_a < > is_nan_ ( ) const
      { return value_.is_nan_( ); }
      virtual inline bool is_nan__ ( ) const
      { return value_.is_nan__( ); }
      virtual inline any_a < > is_inf ( range_a < > const & _ ) const
      { return value_.is_inf(_ ); }
      virtual inline any_a < > is_inf_ ( ) const
      { return value_.is_inf_( ); }
      virtual inline bool is_inf__ ( ) const
      { return value_.is_inf__( ); }
      virtual inline any_a < > is_finite ( range_a < > const & _ ) const
      { return value_.is_finite(_ ); }
      virtual inline any_a < > is_finite_ ( ) const
      { return value_.is_finite_( ); }
      virtual inline bool is_finite__ ( ) const
      { return value_.is_finite__( ); }
      virtual inline any_a < > is_normal ( range_a < > const & _ ) const
      { return value_.is_normal(_ ); }
      virtual inline any_a < > is_normal_ ( ) const
      { return value_.is_normal_( ); }
      virtual inline bool is_normal__ ( ) const
      { return value_.is_normal__( ); }
      virtual inline any_a < > little_endian ( range_a < > const & _ ) const
      { return value_.little_endian(_ ); }
      virtual inline any_a < > little_endian_ ( ) const
      { return value_.little_endian_( ); }
      virtual inline bool little_endian__ ( ) const
      { return value_.little_endian__( ); }
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
    
    	template <typename ___TTT___, typename ___1___, typename ___2___, typename ___3___>
    	friend inline bool check_(number_a<___1___, ___2___, ___3___> const& value) noexcept;
    
    public:
    	static inline char const* ___abstraction_name___() noexcept
    	{
    		return "number_a";
    	}
    
    	static inline bool ___check___(std::shared_ptr<___root_handle_base___>const & handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));
    	}
    
    	inline number_a() = default;
    
    	explicit inline number_a(bool reference) noexcept
    		: ___root___{ reference }
    	{}
    
    	inline number_a(number_a const& other, bool reference) noexcept
    		: ___root___(other, reference)
    	{}
    
    	inline number_a(number_a&& other, bool reference) noexcept
    		: ___root___(std::move(other), reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline number_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)
    		: ___root___(handle, reference)
    	{
    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))
    		{
    			throw dis__("number_a constructor failed to cast from base to derived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline number_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
    		: ___root___(handle, reference)
    	{
    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_a, std::decay_t<___TTT___>>::value>>
    	explicit inline number_a(___TTT___ value, bool reference = false) noexcept
    		: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
    			reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline number_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))
    		{
    			throw dis__("number_a assignment failed to cast from base to derived");
    		}
    		handle_ = handle;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline number_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));
    		handle_ = handle;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_a, std::decay_t<___TTT___>>::value>>
    	inline number_a& operator=(___TTT___ value) noexcept
    	{
    		number_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		handle_->___weak___(handle_);
    		return *this;
    	}
    };
    
    template <typename ___TTT___, typename ___1___, typename ___2___, typename ___3___>
    inline bool check_(number_a<___1___, ___2___, ___3___> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    

}
#endif
