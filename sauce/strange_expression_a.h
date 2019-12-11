#ifndef COM_ONEISH_STRANGE_EXPRESSION_A_H
#define COM_ONEISH_STRANGE_EXPRESSION_A_H

 //# include "any_forward.hpp"
 //# include "range_forward.hpp"
 //# include "token_forward.hpp"
 //# include "flock_forward.hpp"
 //# include "unordered_shoal_forward.hpp"
 //# include "river_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename number_data_a_int64 >
    class expression_a final : public ___derived___
    {
    public:
    	inline expression_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline expression_a operator++(int)
    	{
    		assert(handle_);
    		expression_a result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline expression_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline expression_a operator--(int)
    	{
    		assert(handle_);
    		expression_a result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline expression_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline expression_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline expression_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline expression_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline expression_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline any_a < > evaluate__ ( range_a < > const & _ ) const
     { assert(handle_); return read().evaluate__(_ ); }
     inline any_a < > evaluate_ ( ) const
     { assert(handle_); return read().evaluate_( ); }
     inline any_a < > token__ ( range_a < > const & _ ) const
     { assert(handle_); return read().token__(_ ); }
     inline token_a < > token_ ( ) const
     { assert(handle_); return read().token_( ); }
     inline any_a < > terms__ ( range_a < > const & _ ) const
     { assert(handle_); return read().terms__(_ ); }
     inline flock_a < > terms_ ( ) const
     { assert(handle_); return read().terms_( ); }
     inline any_a < > generate__ ( range_a < > const & range ) const
     { assert(handle_); return read().generate__(range ); }
     inline any_a < > generate_ ( number_data_a_int64 const & version , number_data_a_int64 const & indent , river_a < > & river ) const
     { assert(handle_); return read().generate_(version, indent, river ); }
     inline void generate ( int64_t version , int64_t indent , river_a < > & river ) const
     { assert(handle_); read().generate(version, indent, river ); }
     inline any_a < > generate_cpp__ ( range_a < > const & range ) const
     { assert(handle_); return read().generate_cpp__(range ); }
     inline any_a < > generate_cpp_ ( number_data_a_int64 const & version , number_data_a_int64 const & indent , river_a < > & river ) const
     { assert(handle_); return read().generate_cpp_(version, indent, river ); }
     inline void generate_cpp ( int64_t version , int64_t indent , river_a < > & river ) const
     { assert(handle_); read().generate_cpp(version, indent, river ); }
     inline any_a < > generate_cpp_type__ ( range_a < > const & range ) const
     { assert(handle_); return read().generate_cpp_type__(range ); }
     inline any_a < > generate_cpp_type_ ( number_data_a_int64 const & version , number_data_a_int64 const & indent , river_a < > & river ) const
     { assert(handle_); return read().generate_cpp_type_(version, indent, river ); }
     inline void generate_cpp_type ( int64_t version , int64_t indent , river_a < > & river ) const
     { assert(handle_); read().generate_cpp_type(version, indent, river ); }
    
    private:
    	struct ___finale_handle_base___ : ___derived_handle_base___
    	{
      virtual inline any_a < > evaluate__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > evaluate_ ( ) const = 0;
      virtual inline any_a < > token__ ( range_a < > const & _ ) const = 0;
      virtual inline token_a < > token_ ( ) const = 0;
      virtual inline any_a < > terms__ ( range_a < > const & _ ) const = 0;
      virtual inline flock_a < > terms_ ( ) const = 0;
      virtual inline any_a < > generate__ ( range_a < > const & range ) const = 0;
      virtual inline any_a < > generate_ ( number_data_a_int64 const & version , number_data_a_int64 const & indent , river_a < > & river ) const = 0;
      virtual inline void generate ( int64_t version , int64_t indent , river_a < > & river ) const = 0;
      virtual inline any_a < > generate_cpp__ ( range_a < > const & range ) const = 0;
      virtual inline any_a < > generate_cpp_ ( number_data_a_int64 const & version , number_data_a_int64 const & indent , river_a < > & river ) const = 0;
      virtual inline void generate_cpp ( int64_t version , int64_t indent , river_a < > & river ) const = 0;
      virtual inline any_a < > generate_cpp_type__ ( range_a < > const & range ) const = 0;
      virtual inline any_a < > generate_cpp_type_ ( number_data_a_int64 const & version , number_data_a_int64 const & indent , river_a < > & river ) const = 0;
      virtual inline void generate_cpp_type ( int64_t version , int64_t indent , river_a < > & river ) const = 0;
    	};
    
    	template <typename ___TTT___>
    	struct ___finale_handle_final___ final : ___derived_handle___<___TTT___, ___finale_handle_base___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: ___derived_handle___<___TTT___, ___finale_handle_base___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: ___derived_handle___<___TTT___, ___finale_handle_base___>{ std::move(value) }
    		{}
    
    		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
    		{
    			return std::make_shared<___finale_handle_final___>(___derived_handle___<___TTT___, ___finale_handle_base___>::value_);
    		}
    
      virtual inline any_a < > evaluate__ ( range_a < > const & _ ) const
      { return value_.evaluate__(_ ); }
      virtual inline any_a < > evaluate_ ( ) const
      { return value_.evaluate_( ); }
      virtual inline any_a < > token__ ( range_a < > const & _ ) const
      { return value_.token__(_ ); }
      virtual inline token_a < > token_ ( ) const
      { return value_.token_( ); }
      virtual inline any_a < > terms__ ( range_a < > const & _ ) const
      { return value_.terms__(_ ); }
      virtual inline flock_a < > terms_ ( ) const
      { return value_.terms_( ); }
      virtual inline any_a < > generate__ ( range_a < > const & range ) const
      { return value_.generate__(range ); }
      virtual inline any_a < > generate_ ( number_data_a_int64 const & version , number_data_a_int64 const & indent , river_a < > & river ) const
      { return value_.generate_(version, indent, river ); }
      virtual inline void generate ( int64_t version , int64_t indent , river_a < > & river ) const
      { value_.generate(version, indent, river ); }
      virtual inline any_a < > generate_cpp__ ( range_a < > const & range ) const
      { return value_.generate_cpp__(range ); }
      virtual inline any_a < > generate_cpp_ ( number_data_a_int64 const & version , number_data_a_int64 const & indent , river_a < > & river ) const
      { return value_.generate_cpp_(version, indent, river ); }
      virtual inline void generate_cpp ( int64_t version , int64_t indent , river_a < > & river ) const
      { value_.generate_cpp(version, indent, river ); }
      virtual inline any_a < > generate_cpp_type__ ( range_a < > const & range ) const
      { return value_.generate_cpp_type__(range ); }
      virtual inline any_a < > generate_cpp_type_ ( number_data_a_int64 const & version , number_data_a_int64 const & indent , river_a < > & river ) const
      { return value_.generate_cpp_type_(version, indent, river ); }
      virtual inline void generate_cpp_type ( int64_t version , int64_t indent , river_a < > & river ) const
      { value_.generate_cpp_type(version, indent, river ); }
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
    		if (!___reference___ && !handle_.unique())
    		{
    			handle_ = handle_->___clone___();
    			handle_->___weak___(handle_);
    		}
    		return *std::static_pointer_cast<___finale_handle_base___>(handle_);
    	}
    
    	template <typename ___TTT___>
    	friend inline bool check(expression_a<> const& value) noexcept;
    
    public:
    	static inline bool ___check___(std::shared_ptr<___root_handle_base___> const& handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    	}
    
    	inline expression_a() = default;
    
    	explicit inline expression_a(bool reference) noexcept
    		: ___derived___{ reference }
    	{}
    
    	inline expression_a(expression_a const& other, bool reference) noexcept
    		: ___derived___(other, reference)
    	{}
    
    	inline expression_a(expression_a&& other, bool reference) noexcept
    		: ___derived___(std::move(other), reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline expression_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)
    		: ___derived___(handle, reference)
    	{
    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))
    		{
    			throw dis("expression_a constructor failed to cast from base to final");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline expression_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
    		: ___derived___(handle, reference)
    	{
    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<expression_a, std::decay_t<___TTT___>>::value>>
    	explicit inline expression_a(___TTT___ value, bool reference = false) noexcept
    		: ___derived___(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
    			reference)
    	{
    		handle_->___weak___(handle_);
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline expression_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))
    		{
    			throw dis("expression_a assignment failed to cast from base to final");
    		}
    		handle_ = handle;
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline expression_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    		handle_ = handle;
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<expression_a, std::decay_t<___TTT___>>::value>>
    	inline expression_a& operator=(___TTT___ value) noexcept
    	{
    		expression_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		return *this;
    	}
    
    private:
    	static bool const ___share___;
    	friend class ___expression_a_share___;
    };
    
    template <typename ___TTT___>
    inline bool check(expression_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    template <typename ___1___>
    bool const expression_a<___1___>::___share___ = []()
    {
    	auto shoal = shoal_a<>(shared(), true);
    	reflection<expression_a<___1___>>::share(shoal);
    	return shoal;
    }();
    
    #undef ___derived___

}
#endif
