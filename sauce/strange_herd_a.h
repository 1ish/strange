#ifndef COM_ONEISH_STRANGE_HERD_A_H
#define COM_ONEISH_STRANGE_HERD_A_H

 //# include "any_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class herd_a : public ___derived___
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
    		herd_a result = *this;
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
    		herd_a result = *this;
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
    
     inline bool has_string ( std :: string const & s ) const
     { assert(handle_); return read().has_string(s ); }
     inline bool at_string ( std :: string const & s ) const
     { assert(handle_); return read().at_string(s ); }
     inline void update ( any_a < > const & thing )
     { assert(handle_); write().update(thing ); }
     inline void update_string ( std :: string const & s )
     { assert(handle_); write().update_string(s ); }
     inline bool insert ( any_a < > const & thing )
     { assert(handle_); return write().insert(thing ); }
     inline bool insert_string ( std :: string const & s )
     { assert(handle_); return write().insert_string(s ); }
     inline bool erase_string ( std :: string const & s )
     { assert(handle_); return write().erase_string(s ); }
    
    protected:
    	struct ___ddderived_handle_base___ : ___dderived_handle_base___
    	{
      virtual inline bool has_string ( std :: string const & s ) const = 0;
      virtual inline bool at_string ( std :: string const & s ) const = 0;
      virtual inline void update ( any_a < > const & thing ) = 0;
      virtual inline void update_string ( std :: string const & s ) = 0;
      virtual inline bool insert ( any_a < > const & thing ) = 0;
      virtual inline bool insert_string ( std :: string const & s ) = 0;
      virtual inline bool erase_string ( std :: string const & s ) = 0;
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
    
      virtual inline bool has_string ( std :: string const & s ) const
      { return value_.has_string(s ); }
      virtual inline bool at_string ( std :: string const & s ) const
      { return value_.at_string(s ); }
      virtual inline void update ( any_a < > const & thing )
      { value_.update(thing ); }
      virtual inline void update_string ( std :: string const & s )
      { value_.update_string(s ); }
      virtual inline bool insert ( any_a < > const & thing )
      { return value_.insert(thing ); }
      virtual inline bool insert_string ( std :: string const & s )
      { return value_.insert_string(s ); }
      virtual inline bool erase_string ( std :: string const & s )
      { return value_.erase_string(s ); }
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
    	friend inline bool check(herd_a<> const& value) noexcept;
    
    public:
    	static inline bool ___check___(___SHARED___ const& handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    	}
    
    	inline herd_a() = default;
    
    	inline herd_a(herd_a const& other, bool reference) noexcept
    		: ___derived___(other, reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline herd_a(std::shared_ptr<___TTT___> const& handle)
    		: ___derived___{ handle }
    	{
    		if (handle && !std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))
    		{
    			throw dis("herd_a constructor failed to cast from base to ddderived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline herd_a(std::shared_ptr<___TTT___> const& handle) noexcept
    		: ___derived___{ handle }
    	{
    		assert(!handle || std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    	}
    #endif
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline herd_a(std::shared_ptr<___TTT___> const& handle, bool reference)
    		: ___derived___(handle, reference)
    	{
    		if (handle && !std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))
    		{
    			throw dis("herd_a constructor failed to cast from base to ddderived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline herd_a(std::shared_ptr<___TTT___> const& handle, bool reference) noexcept
    		: ___derived___(handle, reference)
    	{
    		assert(!handle || std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<herd_a, std::decay_t<___TTT___>>::value>>
    	explicit inline herd_a(___TTT___ value) noexcept
    		: ___derived___{ std::make_shared<___ddderived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
    	{
    		handle_->___weak___(handle_);
    	}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline herd_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (handle && !std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))
    		{
    			throw dis("herd_a assignment failed to cast from base to ddderived");
    		}
    		handle_ = handle;
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline herd_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(!handle || std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));
    		handle_ = handle;
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<herd_a, std::decay_t<___TTT___>>::value>>
    	inline herd_a& operator=(___TTT___ value) noexcept
    	{
    		herd_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		return *this;
    	}
    
    private:
    	static bool const ___share___;
    	friend class ___herd_a_share___;
    };
    
    template <typename ___TTT___>
    inline bool check(herd_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    template <typename ___1___>
    bool const herd_a<___1___>::___share___ = []()
    {
    	auto& shoal = shared();
    	reflection<herd_a<___1___>>::share(shoal);
    	return shoal.something();
    }();
    
    #undef ___derived___

}
#endif
