#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_A_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_A_H

// # include "any_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class misunderstanding_a : public ___root___

    {

    public:

     inline std :: string const & to_string__ ( ) const
     { assert(handle_); return read().to_string__( ); }
     inline misunderstanding_a add ( any_a < > const & range ) const
     { assert(handle_); return read().add(range ); }
     inline misunderstanding_a add_ ( misunderstanding_a const & misunderstanding ) const
     { assert(handle_); return read().add_(misunderstanding ); }
     inline misunderstanding_a operator + ( misunderstanding_a const & misunderstanding ) const
     { assert(handle_); return read().operator+(misunderstanding ); }
    

    protected:

    	struct ___derived_handle_base___ : ___root_handle_base___

    	{

      virtual inline std :: string const & to_string__ ( ) const = 0;
      virtual inline misunderstanding_a add ( any_a < > const & range ) const = 0;
      virtual inline misunderstanding_a add_ ( misunderstanding_a const & misunderstanding ) const = 0;
      virtual inline misunderstanding_a operator + ( misunderstanding_a const & misunderstanding ) const = 0;
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

    

      virtual inline std :: string const & to_string__ ( ) const
      { return value_.to_string__( ); }
      virtual inline misunderstanding_a add ( any_a < > const & range ) const
      { return value_.add(range ); }
      virtual inline misunderstanding_a add_ ( misunderstanding_a const & misunderstanding ) const
      { return value_.add_(misunderstanding ); }
      virtual inline misunderstanding_a operator + ( misunderstanding_a const & misunderstanding ) const
      { return value_.operator+(misunderstanding ); }
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

    	friend inline bool check_(misunderstanding_a<___1___> const& value);

    

    public:

    	static inline char const* ___abstraction_name___()

    	{

    		return "misunderstanding_a";

    	}

    

    	static inline bool ___check___(std::shared_ptr<___root_handle_base___>const & handle)

    	{

    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    

    	inline misunderstanding_a() = default;

    

    	explicit inline misunderstanding_a(bool reference)

    		: ___root___{ reference }

    	{}

    

    	inline misunderstanding_a(misunderstanding_a const& other, bool reference)

    		: ___root___(other, reference)

    	{}

    

    	inline misunderstanding_a(misunderstanding_a&& other, bool reference)

    		: ___root___(std::move(other), reference)

    	{}

    

    	template <typename ___TTT___>

    	explicit inline misunderstanding_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)

    		: ___root___(handle, reference)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis__("misunderstanding_a constructor failed to cast from base to derived");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    #endif

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<misunderstanding_a, std::decay_t<___TTT___>>::value>>

    	explicit inline misunderstanding_a(___TTT___ value, bool reference = false)

    		: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{}

    

    	template <typename ___TTT___>

    	inline misunderstanding_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis__("misunderstanding_a assignment failed to cast from base to derived");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    #endif

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<misunderstanding_a, std::decay_t<___TTT___>>::value>>

    	inline misunderstanding_a& operator=(___TTT___ value)

    	{

    		misunderstanding_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}

    };

    

    template <typename ___TTT___, typename ___1___>

    inline bool check_(misunderstanding_a<___1___> const& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

}
#endif
