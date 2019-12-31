#ifndef COM_ONEISH_STRANGE_RIVER_A_H
#define COM_ONEISH_STRANGE_RIVER_A_H

 //# include "any_forward.hpp"
 //# include "range_forward.hpp"
 //# include "lake_forward.hpp"
 //# include "number_data_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename lake_a_int8 >
    class river_a : public ___derived___
    {
    public:
    	inline river_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline river_a operator++(int)
    	{
    		assert(handle_);
    		river_a result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline river_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline river_a operator--(int)
    	{
    		assert(handle_);
    		river_a result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline river_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline river_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline river_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline river_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline river_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline std :: string to_string ( )
     { assert(handle_); return write().to_string( ); }
     inline any_a < > get__ ( range_a < > const & _ )
     { assert(handle_); return write().get__(_ ); }
     inline number_data_a < int8_t > get_ ( )
     { assert(handle_); return write().get_( ); }
     inline int8_t get ( )
     { assert(handle_); return write().get( ); }
     inline any_a < > peek__ ( range_a < > const & _ )
     { assert(handle_); return write().peek__(_ ); }
     inline number_data_a < int8_t > peek_ ( )
     { assert(handle_); return write().peek_( ); }
     inline int8_t peek ( )
     { assert(handle_); return write().peek( ); }
     inline any_a < > unget__ ( range_a < > const & _ )
     { assert(handle_); return write().unget__(_ ); }
     inline any_a < > unget_ ( )
     { assert(handle_); return write().unget_( ); }
     inline void unget ( )
     { assert(handle_); write().unget( ); }
     inline any_a < > putback__ ( range_a < > const & range )
     { assert(handle_); return write().putback__(range ); }
     inline any_a < > putback_ ( number_data_a < int8_t > const & int_8 )
     { assert(handle_); return write().putback_(int_8 ); }
     inline void putback ( int8_t int_8 )
     { assert(handle_); write().putback(int_8 ); }
     inline any_a < > getline__ ( range_a < > const & range )
     { assert(handle_); return write().getline__(range ); }
     inline lake_a_int8 getline_ ( number_data_a < int64_t > const & count , number_data_a < int8_t > const & delimiter )
     { assert(handle_); return write().getline_(count, delimiter ); }
     inline std :: vector < int8_t > getline ( int64_t count , int8_t delimiter )
     { assert(handle_); return write().getline(count, delimiter ); }
     inline any_a < > ignore__ ( range_a < > const & range )
     { assert(handle_); return write().ignore__(range ); }
     inline any_a < > ignore_ ( number_data_a < int64_t > const & count )
     { assert(handle_); return write().ignore_(count ); }
     inline void ignore ( int64_t count )
     { assert(handle_); write().ignore(count ); }
     inline any_a < > read__ ( range_a < > const & range )
     { assert(handle_); return write().read__(range ); }
     inline lake_a_int8 read_ ( number_data_a < int64_t > const & count )
     { assert(handle_); return write().read_(count ); }
     inline std :: vector < int8_t > read ( int64_t count )
     { assert(handle_); return write().read(count ); }
     inline std :: string read_string ( int64_t count )
     { assert(handle_); return write().read_string(count ); }
     inline any_a < > tellg__ ( range_a < > const & _ ) const
     { assert(handle_); return read().tellg__(_ ); }
     inline number_data_a < int64_t > tellg_ ( ) const
     { assert(handle_); return read().tellg_( ); }
     inline int64_t tellg ( ) const
     { assert(handle_); return read().tellg( ); }
     inline any_a < > seekg_beg__ ( range_a < > const & range )
     { assert(handle_); return write().seekg_beg__(range ); }
     inline any_a < > seekg_beg_ ( number_data_a < int64_t > const & offset )
     { assert(handle_); return write().seekg_beg_(offset ); }
     inline void seekg_beg ( int64_t offset )
     { assert(handle_); write().seekg_beg(offset ); }
     inline any_a < > seekg_end__ ( range_a < > const & range )
     { assert(handle_); return write().seekg_end__(range ); }
     inline any_a < > seekg_end_ ( number_data_a < int64_t > const & offset )
     { assert(handle_); return write().seekg_end_(offset ); }
     inline void seekg_end ( int64_t offset )
     { assert(handle_); write().seekg_end(offset ); }
     inline any_a < > seekg_cur__ ( range_a < > const & range )
     { assert(handle_); return write().seekg_cur__(range ); }
     inline any_a < > seekg_cur_ ( number_data_a < int64_t > const & offset )
     { assert(handle_); return write().seekg_cur_(offset ); }
     inline void seekg_cur ( int64_t offset )
     { assert(handle_); write().seekg_cur(offset ); }
     inline any_a < > sync__ ( range_a < > const & _ )
     { assert(handle_); return write().sync__(_ ); }
     inline any_a < > sync_ ( )
     { assert(handle_); return write().sync_( ); }
     inline bool sync ( )
     { assert(handle_); return write().sync( ); }
     inline any_a < > put__ ( range_a < > const & range )
     { assert(handle_); return write().put__(range ); }
     inline any_a < > put_ ( number_data_a < int8_t > const & int_8 )
     { assert(handle_); return write().put_(int_8 ); }
     inline void put ( int8_t int_8 )
     { assert(handle_); write().put(int_8 ); }
     inline any_a < > write__ ( range_a < > const & range )
     { assert(handle_); return write().write__(range ); }
     inline any_a < > write_ ( lake_a_int8 const & lake )
     { assert(handle_); return write().write_(lake ); }
     inline void write ( std :: vector < int8_t > const & lake )
     { assert(handle_); write().write(lake ); }
     inline void write_string ( std :: string const & str )
     { assert(handle_); write().write_string(str ); }
     inline any_a < > tellp__ ( range_a < > const & _ ) const
     { assert(handle_); return read().tellp__(_ ); }
     inline number_data_a < int64_t > tellp_ ( ) const
     { assert(handle_); return read().tellp_( ); }
     inline int64_t tellp ( ) const
     { assert(handle_); return read().tellp( ); }
     inline any_a < > seekp_beg__ ( range_a < > const & range )
     { assert(handle_); return write().seekp_beg__(range ); }
     inline any_a < > seekp_beg_ ( number_data_a < int64_t > const & offset )
     { assert(handle_); return write().seekp_beg_(offset ); }
     inline void seekp_beg ( int64_t offset )
     { assert(handle_); write().seekp_beg(offset ); }
     inline any_a < > seekp_end__ ( range_a < > const & range )
     { assert(handle_); return write().seekp_end__(range ); }
     inline any_a < > seekp_end_ ( number_data_a < int64_t > const & offset )
     { assert(handle_); return write().seekp_end_(offset ); }
     inline void seekp_end ( int64_t offset )
     { assert(handle_); write().seekp_end(offset ); }
     inline any_a < > seekp_cur__ ( range_a < > const & range )
     { assert(handle_); return write().seekp_cur__(range ); }
     inline any_a < > seekp_cur_ ( number_data_a < int64_t > const & offset )
     { assert(handle_); return write().seekp_cur_(offset ); }
     inline void seekp_cur ( int64_t offset )
     { assert(handle_); write().seekp_cur(offset ); }
     inline any_a < > flush__ ( range_a < > const & _ )
     { assert(handle_); return write().flush__(_ ); }
     inline any_a < > flush_ ( )
     { assert(handle_); return write().flush_( ); }
     inline void flush ( )
     { assert(handle_); write().flush( ); }
     inline any_a < > good__ ( range_a < > const & _ ) const
     { assert(handle_); return read().good__(_ ); }
     inline any_a < > good_ ( ) const
     { assert(handle_); return read().good_( ); }
     inline bool good ( ) const
     { assert(handle_); return read().good( ); }
     inline any_a < > eof__ ( range_a < > const & _ ) const
     { assert(handle_); return read().eof__(_ ); }
     inline any_a < > eof_ ( ) const
     { assert(handle_); return read().eof_( ); }
     inline bool eof ( ) const
     { assert(handle_); return read().eof( ); }
     inline any_a < > fail__ ( range_a < > const & _ ) const
     { assert(handle_); return read().fail__(_ ); }
     inline any_a < > fail_ ( ) const
     { assert(handle_); return read().fail_( ); }
     inline bool fail ( ) const
     { assert(handle_); return read().fail( ); }
     inline any_a < > bad__ ( range_a < > const & _ ) const
     { assert(handle_); return read().bad__(_ ); }
     inline any_a < > bad_ ( ) const
     { assert(handle_); return read().bad_( ); }
     inline bool bad ( ) const
     { assert(handle_); return read().bad( ); }
     inline any_a < > set_good__ ( range_a < > const & range )
     { assert(handle_); return write().set_good__(range ); }
     inline any_a < > set_good_ ( any_a < > const & value )
     { assert(handle_); return write().set_good_(value ); }
     inline void set_good ( bool value )
     { assert(handle_); write().set_good(value ); }
     inline any_a < > set_eof__ ( range_a < > const & range )
     { assert(handle_); return write().set_eof__(range ); }
     inline any_a < > set_eof_ ( any_a < > const & value )
     { assert(handle_); return write().set_eof_(value ); }
     inline void set_eof ( bool value )
     { assert(handle_); write().set_eof(value ); }
     inline any_a < > set_fail__ ( range_a < > const & range )
     { assert(handle_); return write().set_fail__(range ); }
     inline any_a < > set_fail_ ( any_a < > const & value )
     { assert(handle_); return write().set_fail_(value ); }
     inline void set_fail ( bool value )
     { assert(handle_); write().set_fail(value ); }
     inline any_a < > set_bad__ ( range_a < > const & range )
     { assert(handle_); return write().set_bad__(range ); }
     inline any_a < > set_bad_ ( any_a < > const & value )
     { assert(handle_); return write().set_bad_(value ); }
     inline void set_bad ( bool value )
     { assert(handle_); write().set_bad(value ); }
     inline any_a < > filename__ ( range_a < > const & _ ) const
     { assert(handle_); return read().filename__(_ ); }
     inline lake_a < int8_t > filename_ ( ) const
     { assert(handle_); return read().filename_( ); }
     inline std :: string filename ( ) const
     { assert(handle_); return read().filename( ); }
    
    protected:
    	struct ___dderived_handle_base___ : ___derived_handle_base___
    	{
      virtual inline std :: string to_string ( ) = 0;
      virtual inline any_a < > get__ ( range_a < > const & _ ) = 0;
      virtual inline number_data_a < int8_t > get_ ( ) = 0;
      virtual inline int8_t get ( ) = 0;
      virtual inline any_a < > peek__ ( range_a < > const & _ ) = 0;
      virtual inline number_data_a < int8_t > peek_ ( ) = 0;
      virtual inline int8_t peek ( ) = 0;
      virtual inline any_a < > unget__ ( range_a < > const & _ ) = 0;
      virtual inline any_a < > unget_ ( ) = 0;
      virtual inline void unget ( ) = 0;
      virtual inline any_a < > putback__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > putback_ ( number_data_a < int8_t > const & int_8 ) = 0;
      virtual inline void putback ( int8_t int_8 ) = 0;
      virtual inline any_a < > getline__ ( range_a < > const & range ) = 0;
      virtual inline lake_a_int8 getline_ ( number_data_a < int64_t > const & count , number_data_a < int8_t > const & delimiter ) = 0;
      virtual inline std :: vector < int8_t > getline ( int64_t count , int8_t delimiter ) = 0;
      virtual inline any_a < > ignore__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > ignore_ ( number_data_a < int64_t > const & count ) = 0;
      virtual inline void ignore ( int64_t count ) = 0;
      virtual inline any_a < > read__ ( range_a < > const & range ) = 0;
      virtual inline lake_a_int8 read_ ( number_data_a < int64_t > const & count ) = 0;
      virtual inline std :: vector < int8_t > read ( int64_t count ) = 0;
      virtual inline std :: string read_string ( int64_t count ) = 0;
      virtual inline any_a < > tellg__ ( range_a < > const & _ ) const = 0;
      virtual inline number_data_a < int64_t > tellg_ ( ) const = 0;
      virtual inline int64_t tellg ( ) const = 0;
      virtual inline any_a < > seekg_beg__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > seekg_beg_ ( number_data_a < int64_t > const & offset ) = 0;
      virtual inline void seekg_beg ( int64_t offset ) = 0;
      virtual inline any_a < > seekg_end__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > seekg_end_ ( number_data_a < int64_t > const & offset ) = 0;
      virtual inline void seekg_end ( int64_t offset ) = 0;
      virtual inline any_a < > seekg_cur__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > seekg_cur_ ( number_data_a < int64_t > const & offset ) = 0;
      virtual inline void seekg_cur ( int64_t offset ) = 0;
      virtual inline any_a < > sync__ ( range_a < > const & _ ) = 0;
      virtual inline any_a < > sync_ ( ) = 0;
      virtual inline bool sync ( ) = 0;
      virtual inline any_a < > put__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > put_ ( number_data_a < int8_t > const & int_8 ) = 0;
      virtual inline void put ( int8_t int_8 ) = 0;
      virtual inline any_a < > write__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > write_ ( lake_a_int8 const & lake ) = 0;
      virtual inline void write ( std :: vector < int8_t > const & lake ) = 0;
      virtual inline void write_string ( std :: string const & str ) = 0;
      virtual inline any_a < > tellp__ ( range_a < > const & _ ) const = 0;
      virtual inline number_data_a < int64_t > tellp_ ( ) const = 0;
      virtual inline int64_t tellp ( ) const = 0;
      virtual inline any_a < > seekp_beg__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > seekp_beg_ ( number_data_a < int64_t > const & offset ) = 0;
      virtual inline void seekp_beg ( int64_t offset ) = 0;
      virtual inline any_a < > seekp_end__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > seekp_end_ ( number_data_a < int64_t > const & offset ) = 0;
      virtual inline void seekp_end ( int64_t offset ) = 0;
      virtual inline any_a < > seekp_cur__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > seekp_cur_ ( number_data_a < int64_t > const & offset ) = 0;
      virtual inline void seekp_cur ( int64_t offset ) = 0;
      virtual inline any_a < > flush__ ( range_a < > const & _ ) = 0;
      virtual inline any_a < > flush_ ( ) = 0;
      virtual inline void flush ( ) = 0;
      virtual inline any_a < > good__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > good_ ( ) const = 0;
      virtual inline bool good ( ) const = 0;
      virtual inline any_a < > eof__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > eof_ ( ) const = 0;
      virtual inline bool eof ( ) const = 0;
      virtual inline any_a < > fail__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > fail_ ( ) const = 0;
      virtual inline bool fail ( ) const = 0;
      virtual inline any_a < > bad__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > bad_ ( ) const = 0;
      virtual inline bool bad ( ) const = 0;
      virtual inline any_a < > set_good__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > set_good_ ( any_a < > const & value ) = 0;
      virtual inline void set_good ( bool value ) = 0;
      virtual inline any_a < > set_eof__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > set_eof_ ( any_a < > const & value ) = 0;
      virtual inline void set_eof ( bool value ) = 0;
      virtual inline any_a < > set_fail__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > set_fail_ ( any_a < > const & value ) = 0;
      virtual inline void set_fail ( bool value ) = 0;
      virtual inline any_a < > set_bad__ ( range_a < > const & range ) = 0;
      virtual inline any_a < > set_bad_ ( any_a < > const & value ) = 0;
      virtual inline void set_bad ( bool value ) = 0;
      virtual inline any_a < > filename__ ( range_a < > const & _ ) const = 0;
      virtual inline lake_a < int8_t > filename_ ( ) const = 0;
      virtual inline std :: string filename ( ) const = 0;
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
    
      virtual inline std :: string to_string ( )
      { return value_.to_string( ); }
      virtual inline any_a < > get__ ( range_a < > const & _ )
      { return value_.get__(_ ); }
      virtual inline number_data_a < int8_t > get_ ( )
      { return value_.get_( ); }
      virtual inline int8_t get ( )
      { return value_.get( ); }
      virtual inline any_a < > peek__ ( range_a < > const & _ )
      { return value_.peek__(_ ); }
      virtual inline number_data_a < int8_t > peek_ ( )
      { return value_.peek_( ); }
      virtual inline int8_t peek ( )
      { return value_.peek( ); }
      virtual inline any_a < > unget__ ( range_a < > const & _ )
      { return value_.unget__(_ ); }
      virtual inline any_a < > unget_ ( )
      { return value_.unget_( ); }
      virtual inline void unget ( )
      { value_.unget( ); }
      virtual inline any_a < > putback__ ( range_a < > const & range )
      { return value_.putback__(range ); }
      virtual inline any_a < > putback_ ( number_data_a < int8_t > const & int_8 )
      { return value_.putback_(int_8 ); }
      virtual inline void putback ( int8_t int_8 )
      { value_.putback(int_8 ); }
      virtual inline any_a < > getline__ ( range_a < > const & range )
      { return value_.getline__(range ); }
      virtual inline lake_a_int8 getline_ ( number_data_a < int64_t > const & count , number_data_a < int8_t > const & delimiter )
      { return value_.getline_(count, delimiter ); }
      virtual inline std :: vector < int8_t > getline ( int64_t count , int8_t delimiter )
      { return value_.getline(count, delimiter ); }
      virtual inline any_a < > ignore__ ( range_a < > const & range )
      { return value_.ignore__(range ); }
      virtual inline any_a < > ignore_ ( number_data_a < int64_t > const & count )
      { return value_.ignore_(count ); }
      virtual inline void ignore ( int64_t count )
      { value_.ignore(count ); }
      virtual inline any_a < > read__ ( range_a < > const & range )
      { return value_.read__(range ); }
      virtual inline lake_a_int8 read_ ( number_data_a < int64_t > const & count )
      { return value_.read_(count ); }
      virtual inline std :: vector < int8_t > read ( int64_t count )
      { return value_.read(count ); }
      virtual inline std :: string read_string ( int64_t count )
      { return value_.read_string(count ); }
      virtual inline any_a < > tellg__ ( range_a < > const & _ ) const
      { return value_.tellg__(_ ); }
      virtual inline number_data_a < int64_t > tellg_ ( ) const
      { return value_.tellg_( ); }
      virtual inline int64_t tellg ( ) const
      { return value_.tellg( ); }
      virtual inline any_a < > seekg_beg__ ( range_a < > const & range )
      { return value_.seekg_beg__(range ); }
      virtual inline any_a < > seekg_beg_ ( number_data_a < int64_t > const & offset )
      { return value_.seekg_beg_(offset ); }
      virtual inline void seekg_beg ( int64_t offset )
      { value_.seekg_beg(offset ); }
      virtual inline any_a < > seekg_end__ ( range_a < > const & range )
      { return value_.seekg_end__(range ); }
      virtual inline any_a < > seekg_end_ ( number_data_a < int64_t > const & offset )
      { return value_.seekg_end_(offset ); }
      virtual inline void seekg_end ( int64_t offset )
      { value_.seekg_end(offset ); }
      virtual inline any_a < > seekg_cur__ ( range_a < > const & range )
      { return value_.seekg_cur__(range ); }
      virtual inline any_a < > seekg_cur_ ( number_data_a < int64_t > const & offset )
      { return value_.seekg_cur_(offset ); }
      virtual inline void seekg_cur ( int64_t offset )
      { value_.seekg_cur(offset ); }
      virtual inline any_a < > sync__ ( range_a < > const & _ )
      { return value_.sync__(_ ); }
      virtual inline any_a < > sync_ ( )
      { return value_.sync_( ); }
      virtual inline bool sync ( )
      { return value_.sync( ); }
      virtual inline any_a < > put__ ( range_a < > const & range )
      { return value_.put__(range ); }
      virtual inline any_a < > put_ ( number_data_a < int8_t > const & int_8 )
      { return value_.put_(int_8 ); }
      virtual inline void put ( int8_t int_8 )
      { value_.put(int_8 ); }
      virtual inline any_a < > write__ ( range_a < > const & range )
      { return value_.write__(range ); }
      virtual inline any_a < > write_ ( lake_a_int8 const & lake )
      { return value_.write_(lake ); }
      virtual inline void write ( std :: vector < int8_t > const & lake )
      { value_.write(lake ); }
      virtual inline void write_string ( std :: string const & str )
      { value_.write_string(str ); }
      virtual inline any_a < > tellp__ ( range_a < > const & _ ) const
      { return value_.tellp__(_ ); }
      virtual inline number_data_a < int64_t > tellp_ ( ) const
      { return value_.tellp_( ); }
      virtual inline int64_t tellp ( ) const
      { return value_.tellp( ); }
      virtual inline any_a < > seekp_beg__ ( range_a < > const & range )
      { return value_.seekp_beg__(range ); }
      virtual inline any_a < > seekp_beg_ ( number_data_a < int64_t > const & offset )
      { return value_.seekp_beg_(offset ); }
      virtual inline void seekp_beg ( int64_t offset )
      { value_.seekp_beg(offset ); }
      virtual inline any_a < > seekp_end__ ( range_a < > const & range )
      { return value_.seekp_end__(range ); }
      virtual inline any_a < > seekp_end_ ( number_data_a < int64_t > const & offset )
      { return value_.seekp_end_(offset ); }
      virtual inline void seekp_end ( int64_t offset )
      { value_.seekp_end(offset ); }
      virtual inline any_a < > seekp_cur__ ( range_a < > const & range )
      { return value_.seekp_cur__(range ); }
      virtual inline any_a < > seekp_cur_ ( number_data_a < int64_t > const & offset )
      { return value_.seekp_cur_(offset ); }
      virtual inline void seekp_cur ( int64_t offset )
      { value_.seekp_cur(offset ); }
      virtual inline any_a < > flush__ ( range_a < > const & _ )
      { return value_.flush__(_ ); }
      virtual inline any_a < > flush_ ( )
      { return value_.flush_( ); }
      virtual inline void flush ( )
      { value_.flush( ); }
      virtual inline any_a < > good__ ( range_a < > const & _ ) const
      { return value_.good__(_ ); }
      virtual inline any_a < > good_ ( ) const
      { return value_.good_( ); }
      virtual inline bool good ( ) const
      { return value_.good( ); }
      virtual inline any_a < > eof__ ( range_a < > const & _ ) const
      { return value_.eof__(_ ); }
      virtual inline any_a < > eof_ ( ) const
      { return value_.eof_( ); }
      virtual inline bool eof ( ) const
      { return value_.eof( ); }
      virtual inline any_a < > fail__ ( range_a < > const & _ ) const
      { return value_.fail__(_ ); }
      virtual inline any_a < > fail_ ( ) const
      { return value_.fail_( ); }
      virtual inline bool fail ( ) const
      { return value_.fail( ); }
      virtual inline any_a < > bad__ ( range_a < > const & _ ) const
      { return value_.bad__(_ ); }
      virtual inline any_a < > bad_ ( ) const
      { return value_.bad_( ); }
      virtual inline bool bad ( ) const
      { return value_.bad( ); }
      virtual inline any_a < > set_good__ ( range_a < > const & range )
      { return value_.set_good__(range ); }
      virtual inline any_a < > set_good_ ( any_a < > const & value )
      { return value_.set_good_(value ); }
      virtual inline void set_good ( bool value )
      { value_.set_good(value ); }
      virtual inline any_a < > set_eof__ ( range_a < > const & range )
      { return value_.set_eof__(range ); }
      virtual inline any_a < > set_eof_ ( any_a < > const & value )
      { return value_.set_eof_(value ); }
      virtual inline void set_eof ( bool value )
      { value_.set_eof(value ); }
      virtual inline any_a < > set_fail__ ( range_a < > const & range )
      { return value_.set_fail__(range ); }
      virtual inline any_a < > set_fail_ ( any_a < > const & value )
      { return value_.set_fail_(value ); }
      virtual inline void set_fail ( bool value )
      { value_.set_fail(value ); }
      virtual inline any_a < > set_bad__ ( range_a < > const & range )
      { return value_.set_bad__(range ); }
      virtual inline any_a < > set_bad_ ( any_a < > const & value )
      { return value_.set_bad_(value ); }
      virtual inline void set_bad ( bool value )
      { value_.set_bad(value ); }
      virtual inline any_a < > filename__ ( range_a < > const & _ ) const
      { return value_.filename__(_ ); }
      virtual inline lake_a < int8_t > filename_ ( ) const
      { return value_.filename_( ); }
      virtual inline std :: string filename ( ) const
      { return value_.filename( ); }
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
    
    		virtual inline ___SHARED___ ___clone___() const final
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
    		return *std::static_pointer_cast<___dderived_handle_base___>(handle_);
    	}
    
    	template <typename ___TTT___>
    	friend inline bool check(river_a<> const& value) noexcept;
    
    public:
    	static inline bool ___check___(___SHARED___ const& handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    	}
    
    	inline river_a() = default;
    
    	inline river_a(river_a const& other, bool reference) noexcept
    		: ___derived___(other, reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline river_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)
    		: ___derived___(handle, reference)
    	{
    		if (handle && !std::dynamic_pointer_cast<___dderived_handle_base___>(handle))
    		{
    			throw dis("river_a constructor failed to cast from base to dderived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline river_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
    		: ___derived___(handle, reference)
    	{
    		assert(!handle || std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<river_a, std::decay_t<___TTT___>>::value>>
    	explicit inline river_a(___TTT___ value, bool reference = false) noexcept
    		: ___derived___(std::make_shared<___dderived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
    			reference)
    	{
    		handle_->___weak___(handle_);
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline river_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (handle && !std::dynamic_pointer_cast<___dderived_handle_base___>(handle))
    		{
    			throw dis("river_a assignment failed to cast from base to dderived");
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
    	inline river_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(!handle || std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    		handle_ = handle;
    		if (___reference___)
    		{
    			*___reference___ = handle_;
    		}
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<river_a, std::decay_t<___TTT___>>::value>>
    	inline river_a& operator=(___TTT___ value) noexcept
    	{
    		river_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		if (___reference___)
    		{
    			*___reference___ = handle_;
    		}
    		return *this;
    	}
    
    private:
    	static bool const ___share___;
    	friend class ___river_a_share___;
    };
    
    template <typename ___TTT___>
    inline bool check(river_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    template <typename ___1___>
    bool const river_a<___1___>::___share___ = []()
    {
    	auto shoal = shoal_a<>(shared(), true);
    	reflection<river_a<___1___>>::share(shoal);
    	return shoal;
    }();
    
    #undef ___derived___

}
#endif
