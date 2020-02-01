#ifndef COM_ONEISH_STRANGE_CAT_A_H
#define COM_ONEISH_STRANGE_CAT_A_H

 //# include "any_forward.hpp"
 //# include "range_forward.hpp"
 //# include "symbol_forward.hpp"
 //# include "flock_forward.hpp"
 //# include "herd_forward.hpp"
 //# include "number_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename lake_int8_a >
    class cat_a : public ___derived___
    {
    public:
    	inline cat_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline cat_a operator++(int)
    	{
    		assert(handle_);
    		cat_a result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline cat_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline cat_a operator--(int)
    	{
    		assert(handle_);
    		cat_a result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline cat_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline cat_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline cat_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline cat_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline cat_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline any_a < > symbolic__ ( range_a < > const & _ ) const
     { assert(handle_); return read().symbolic__(_ ); }
     inline any_a < > symbolic_ ( ) const
     { assert(handle_); return read().symbolic_( ); }
     inline bool symbolic ( ) const
     { assert(handle_); return read().symbolic( ); }
     inline any_a < > order__ ( range_a < > const & _ ) const
     { assert(handle_); return read().order__(_ ); }
     inline number_data_a < int64_t > order_ ( ) const
     { assert(handle_); return read().order_( ); }
     inline int64_t order ( ) const
     { assert(handle_); return read().order( ); }
     inline any_a < > name__ ( range_a < > const & _ ) const
     { assert(handle_); return read().name__(_ ); }
     inline symbol_a < > name_ ( ) const
     { assert(handle_); return read().name_( ); }
     inline any_a < > dimensions__ ( range_a < > const & _ ) const
     { assert(handle_); return read().dimensions__(_ ); }
     inline flock_a < > dimensions_ ( ) const
     { assert(handle_); return read().dimensions_( ); }
     inline any_a < > parameters__ ( range_a < > const & _ ) const
     { assert(handle_); return read().parameters__(_ ); }
     inline flock_a < > parameters_ ( ) const
     { assert(handle_); return read().parameters_( ); }
     inline any_a < > result__ ( range_a < > const & _ ) const
     { assert(handle_); return read().result__(_ ); }
     inline cat_a result_ ( ) const
     { assert(handle_); return read().result_( ); }
     inline any_a < > code__ ( range_a < > const & _ ) const
     { assert(handle_); return read().code__(_ ); }
     inline lake_int8_a code_ ( ) const
     { assert(handle_); return read().code_( ); }
     inline std :: string code ( ) const
     { assert(handle_); return read().code( ); }
    
    protected:
    	struct ___dderived_handle_base___ : ___derived_handle_base___
    	{
      virtual inline any_a < > symbolic__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > symbolic_ ( ) const = 0;
      virtual inline bool symbolic ( ) const = 0;
      virtual inline any_a < > order__ ( range_a < > const & _ ) const = 0;
      virtual inline number_data_a < int64_t > order_ ( ) const = 0;
      virtual inline int64_t order ( ) const = 0;
      virtual inline any_a < > name__ ( range_a < > const & _ ) const = 0;
      virtual inline symbol_a < > name_ ( ) const = 0;
      virtual inline any_a < > dimensions__ ( range_a < > const & _ ) const = 0;
      virtual inline flock_a < > dimensions_ ( ) const = 0;
      virtual inline any_a < > parameters__ ( range_a < > const & _ ) const = 0;
      virtual inline flock_a < > parameters_ ( ) const = 0;
      virtual inline any_a < > result__ ( range_a < > const & _ ) const = 0;
      virtual inline cat_a result_ ( ) const = 0;
      virtual inline any_a < > code__ ( range_a < > const & _ ) const = 0;
      virtual inline lake_int8_a code_ ( ) const = 0;
      virtual inline std :: string code ( ) const = 0;
    	};
    
    	template <typename ___TTT___, typename ___DDHB___ = ___dderived_handle_base___>
    	struct ___dderived_handle___ : ___derived_handle___<___TTT___, ___DDHB___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___dderived_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
    			: ___derived_handle___<___TTT___, ___DDHB___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___dderived_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
    			: ___derived_handle___<___TTT___, ___DDHB___>{ std::move(value) }
    		{}
    
      virtual inline any_a < > symbolic__ ( range_a < > const & _ ) const
      { return value_.symbolic__(_ ); }
      virtual inline any_a < > symbolic_ ( ) const
      { return value_.symbolic_( ); }
      virtual inline bool symbolic ( ) const
      { return value_.symbolic( ); }
      virtual inline any_a < > order__ ( range_a < > const & _ ) const
      { return value_.order__(_ ); }
      virtual inline number_data_a < int64_t > order_ ( ) const
      { return value_.order_( ); }
      virtual inline int64_t order ( ) const
      { return value_.order( ); }
      virtual inline any_a < > name__ ( range_a < > const & _ ) const
      { return value_.name__(_ ); }
      virtual inline symbol_a < > name_ ( ) const
      { return value_.name_( ); }
      virtual inline any_a < > dimensions__ ( range_a < > const & _ ) const
      { return value_.dimensions__(_ ); }
      virtual inline flock_a < > dimensions_ ( ) const
      { return value_.dimensions_( ); }
      virtual inline any_a < > parameters__ ( range_a < > const & _ ) const
      { return value_.parameters__(_ ); }
      virtual inline flock_a < > parameters_ ( ) const
      { return value_.parameters_( ); }
      virtual inline any_a < > result__ ( range_a < > const & _ ) const
      { return value_.result__(_ ); }
      virtual inline cat_a result_ ( ) const
      { return value_.result_( ); }
      virtual inline any_a < > code__ ( range_a < > const & _ ) const
      { return value_.code__(_ ); }
      virtual inline lake_int8_a code_ ( ) const
      { return value_.code_( ); }
      virtual inline std :: string code ( ) const
      { return value_.code( ); }
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
    		inline ___dderived_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
    			: ___dderived_handle___<___TTT___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___dderived_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
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
    			handle_ = handle_->___clone___();
    			handle_->___weak___(handle_);
    		}
    		return *std::static_pointer_cast<___dderived_handle_base___>(handle_);
    	}
    
    	template <typename ___TTT___>
    	friend inline bool check(cat_a<> const& value) noexcept;
    
    public:
    	static inline bool ___check___(___SHARED___ const& handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    	}
    
    	inline cat_a() = default;
    
    	static inline cat_a val(cat_a const& other) noexcept
    	{
    		return cat_a{ other };
    	}
    
    	inline cat_a(cat_a& other, ___reference_tag___) noexcept
    		: ___derived___(other, ___reference_tag___{})
    	{}
    
    	static inline cat_a ref(cat_a& other) noexcept
    	{
    		return cat_a(other, ___reference_tag___{});
    	}
    
    	inline cat_a(cat_a& other, ___duplicate_tag___) noexcept
    		: ___derived___(other, ___duplicate_tag___{})
    	{}
    
    	static inline cat_a dup(cat_a& other) noexcept
    	{
    		return cat_a(other, ___duplicate_tag___{});
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline cat_a(std::shared_ptr<___TTT___> const& handle)
    		: ___derived___{ handle }
    	{
    		if (handle && !std::dynamic_pointer_cast<___dderived_handle_base___>(handle))
    		{
    			throw dis("cat_a constructor failed to cast from base to dderived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline cat_a(std::shared_ptr<___TTT___> const& handle) noexcept
    		: ___derived___{ handle }
    	{
    		assert(!handle || std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    	}
    #endif
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline cat_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
    		: ___derived___(handle, ___reference_tag___{})
    	{
    		if (handle && !std::dynamic_pointer_cast<___dderived_handle_base___>(handle))
    		{
    			throw dis("cat_a constructor failed to cast from base to dderived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline cat_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
    		: ___derived___(handle, ___reference_tag___{})
    	{
    		assert(!handle || std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_a, std::decay_t<___TTT___>>::value>>
    	explicit inline cat_a(___TTT___ value) noexcept
    		: ___derived___{ std::make_shared<___dderived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
    	{
    		handle_->___weak___(handle_);
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline cat_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (handle && !std::dynamic_pointer_cast<___dderived_handle_base___>(handle))
    		{
    			throw dis("cat_a assignment failed to cast from base to dderived");
    		}
    		handle_ = handle;
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline cat_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(!handle || std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    		handle_ = handle;
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_a, std::decay_t<___TTT___>>::value>>
    	inline cat_a& operator=(___TTT___ value) noexcept
    	{
    		cat_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		return *this;
    	}
    
    private:
    	static bool const ___share___;
    	friend class ___cat_a_share___;
    };
    
    template <typename ___TTT___>
    inline bool check(cat_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    template <typename ___1___>
    bool const cat_a<___1___>::___share___ = []()
    {
    	auto& shoal = shared();
    	reflection<cat_a<___1___>>::share(shoal);
    	return shoal.something();
    }();
    
    #undef ___derived___

}
#endif
