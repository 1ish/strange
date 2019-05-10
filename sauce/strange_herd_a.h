#ifndef COM_ONEISH_STRANGE_HERD_A_H
#define COM_ONEISH_STRANGE_HERD_A_H

 //# include "any.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class herd_a final : public ___derived___
    {
    public:
    	inline herd_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline herd_a operator++(int)
    	{
    		assert(handle_);
    		% struct_name% result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline herd_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline herd_a operator--(int)
    	{
    		assert(handle_);
    		% struct_name% result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline herd_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline herd_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline herd_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline herd_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline herd_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline bool has__ ( std :: string const & s ) const
     { assert(handle_); return read().has__(s ); }
     inline bool at__ ( std :: string const & s ) const
     { assert(handle_); return read().at__(s ); }
     inline bool insert__ ( std :: string const & s )
     { assert(handle_); return write().insert__(s ); }
     inline bool erase__ ( std :: string const & s )
     { assert(handle_); return write().erase__(s ); }
     inline std :: unordered_set < any_a < > , any_a < > :: hash_f > const & extract__ ( ) const
     { assert(handle_); return read().extract__( ); }
     inline void mutate__ ( std :: unordered_set < any_a < > , any_a < > :: hash_f > const & data )
     { assert(handle_); write().mutate__(data ); }
     inline std :: unordered_set < any_a < > , any_a < > :: hash_f > & reference__ ( )
     { assert(handle_); return write().reference__( ); }
    
    private:
    	struct ___finale_handle_base___ : ___dderived_handle_base___
    	{
      virtual inline bool has__ ( std :: string const & s ) const = 0;
      virtual inline bool at__ ( std :: string const & s ) const = 0;
      virtual inline bool insert__ ( std :: string const & s ) = 0;
      virtual inline bool erase__ ( std :: string const & s ) = 0;
      virtual inline std :: unordered_set < any_a < > , any_a < > :: hash_f > const & extract__ ( ) const = 0;
      virtual inline void mutate__ ( std :: unordered_set < any_a < > , any_a < > :: hash_f > const & data ) = 0;
      virtual inline std :: unordered_set < any_a < > , any_a < > :: hash_f > & reference__ ( ) = 0;
    	};
    
    	template <typename ___TTT___>
    	struct ___finale_handle_final___ final : ___dderived_handle___<___TTT___, ___finale_handle_base___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: ___dderived_handle___<___TTT___, ___finale_handle_base___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: ___dderived_handle___<___TTT___, ___finale_handle_base___>{ std::move(value) }
    		{}
    
    		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
    		{
    			return std::make_shared<___finale_handle_final___>(___dderived_handle___<___TTT___, ___finale_handle_base___>::value_);
    		}
    
      virtual inline bool has__ ( std :: string const & s ) const
      { return value_.has__(s ); }
      virtual inline bool at__ ( std :: string const & s ) const
      { return value_.at__(s ); }
      virtual inline bool insert__ ( std :: string const & s )
      { return value_.insert__(s ); }
      virtual inline bool erase__ ( std :: string const & s )
      { return value_.erase__(s ); }
      virtual inline std :: unordered_set < any_a < > , any_a < > :: hash_f > const & extract__ ( ) const
      { return value_.extract__( ); }
      virtual inline void mutate__ ( std :: unordered_set < any_a < > , any_a < > :: hash_f > const & data )
      { value_.mutate__(data ); }
      virtual inline std :: unordered_set < any_a < > , any_a < > :: hash_f > & reference__ ( )
      { return value_.reference__( ); }
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
    	friend inline bool check_(herd_a<> const& value) noexcept;
    
    public:
    	static inline char const* ___abstraction_name___() noexcept
    	{
    		return "herd_a";
    	}
    
    	static inline bool ___check___(std::shared_ptr<___root_handle_base___> const& handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    	}
    
    	inline herd_a() = default;
    
    	explicit inline herd_a(bool reference) noexcept
    		: ___derived___{ reference }
    	{}
    
    	inline herd_a(herd_a const& other, bool reference) noexcept
    		: ___derived___(other, reference)
    	{}
    
    	inline herd_a(herd_a&& other, bool reference) noexcept
    		: ___derived___(std::move(other), reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline herd_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)
    		: ___derived___(handle, reference)
    	{
    		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))
    		{
    			throw dis__("herd_a constructor failed to cast from base to final");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline herd_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
    		: ___derived___(handle, reference)
    	{
    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<herd_a, std::decay_t<___TTT___>>::value>>
    	explicit inline herd_a(___TTT___ value, bool reference = false) noexcept
    		: ___derived___(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
    			reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline herd_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))
    		{
    			throw dis__("herd_a assignment failed to cast from base to final");
    		}
    		handle_ = handle;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline herd_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    		handle_ = handle;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<herd_a, std::decay_t<___TTT___>>::value>>
    	inline herd_a& operator=(___TTT___ value) noexcept
    	{
    		herd_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		handle_->___weak___(handle_);
    		return *this;
    	}
    };
    
    template <typename ___TTT___>
    inline bool check_(herd_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    #undef ___derived___

}
#endif
