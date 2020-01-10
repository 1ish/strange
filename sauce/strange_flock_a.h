#ifndef COM_ONEISH_STRANGE_FLOCK_A_H
#define COM_ONEISH_STRANGE_FLOCK_A_H

 //# include "any_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class flock_a final : public ___derived___
    {
    public:
    	inline flock_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline flock_a operator++(int)
    	{
    		assert(handle_);
    		flock_a result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline flock_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline flock_a operator--(int)
    	{
    		assert(handle_);
    		flock_a result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline flock_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline flock_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline flock_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline flock_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline flock_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline std :: vector < any_a < >> const & extract_vector ( ) const
     { assert(handle_); return read().extract_vector( ); }
     inline std :: vector < any_a < >> & mutate_vector ( )
     { assert(handle_); return write().mutate_vector( ); }
    
    private:
    	struct ___finale_handle_base___ : ___ddderived_handle_base___
    	{
      virtual inline std :: vector < any_a < >> const & extract_vector ( ) const = 0;
      virtual inline std :: vector < any_a < >> & mutate_vector ( ) = 0;
    	};
    
    	template <typename ___TTT___>
    	struct ___finale_handle_final___ final : ___ddderived_handle___<___TTT___, ___finale_handle_base___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
    			: ___ddderived_handle___<___TTT___, ___finale_handle_base___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
    			: ___ddderived_handle___<___TTT___, ___finale_handle_base___>{ std::move(value) }
    		{}
    
    		virtual inline ___SHARED___ ___clone___() const final
    		{
    			return std::make_shared<___finale_handle_final___>(___ddderived_handle___<___TTT___, ___finale_handle_base___>::value_);
    		}
    
      virtual inline std :: vector < any_a < >> const & extract_vector ( ) const
      { return value_.extract_vector( ); }
      virtual inline std :: vector < any_a < >> & mutate_vector ( )
      { return value_.mutate_vector( ); }
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
    		if (!handle_.unique())
    		{
    			handle_ = handle_->___clone___();
    			handle_->___weak___(handle_);
    		}
    		return *std::static_pointer_cast<___finale_handle_base___>(handle_);
    	}
    
    	template <typename ___TTT___>
    	friend inline bool check(flock_a<> const& value) noexcept;
    
    public:
    	static inline bool ___check___(___SHARED___ const& handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    	}
    
    	inline flock_a() = default;
    
    	static inline flock_a val(flock_a const& other) noexcept
    	{
    		return flock_a{ other };
    	}
    /*
    	inline flock_a(flock_a const& other, bool reference) noexcept
    		: ___derived___(other, reference)
    	{}
    */
    	inline flock_a(flock_a& other, ___reference_tag___) noexcept
    		: ___derived___(other, ___reference_tag___{})
    	{}
    
    	static inline flock_a ref(flock_a& other) noexcept
    	{
    		return flock_a(other, ___reference_tag___{});
    	}
    
    	inline flock_a(flock_a& other, ___duplicate_tag___) noexcept
    		: ___derived___(other, ___duplicate_tag___{})
    	{}
    
    	static inline flock_a dup(flock_a& other) noexcept
    	{
    		return flock_a(other, ___duplicate_tag___{});
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline flock_a(std::shared_ptr<___TTT___> const& handle)
    		: ___derived___{ handle }
    	{
    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))
    		{
    			throw dis("flock_a constructor failed to cast from base to final");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline flock_a(std::shared_ptr<___TTT___> const& handle) noexcept
    		: ___derived___{ handle }
    	{
    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    	}
    #endif
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline flock_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
    		: ___derived___(handle, ___reference_tag___{})
    	{
    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))
    		{
    			throw dis("flock_a constructor failed to cast from base to final");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline flock_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
    		: ___derived___(handle, ___reference_tag___{})
    	{
    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<flock_a, std::decay_t<___TTT___>>::value>>
    	explicit inline flock_a(___TTT___ value) noexcept
    		: ___derived___{ std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
    	{
    		handle_->___weak___(handle_);
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline flock_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))
    		{
    			throw dis("flock_a assignment failed to cast from base to final");
    		}
    		handle_ = handle;
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline flock_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));
    		handle_ = handle;
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<flock_a, std::decay_t<___TTT___>>::value>>
    	inline flock_a& operator=(___TTT___ value) noexcept
    	{
    		flock_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		return *this;
    	}
    
    private:
    	static bool const ___share___;
    	friend class ___flock_a_share___;
    };
    
    template <typename ___TTT___>
    inline bool check(flock_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    template <typename ___1___>
    bool const flock_a<___1___>::___share___ = []()
    {
    	auto& shoal = shared();
    	reflection<flock_a<___1___>>::share(shoal);
    	return shoal.something();
    }();
    
    #undef ___derived___

}
#endif
