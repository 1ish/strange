#ifndef COM_ONEISH_STRANGE_SYMBOL_A_H
#define COM_ONEISH_STRANGE_SYMBOL_A_H

// # include "any.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    
    class symbol_a : public ___root___

    {

    public:

     inline const std :: string & to_string__ ( ) const
     { assert(handle_); return read().to_string__( ); }
     inline symbol_a add ( any_a range ) const
     { assert(handle_); return read().add(range ); }
     inline symbol_a add_ ( symbol_a symbol ) const
     { assert(handle_); return read().add_(symbol ); }
     inline symbol_a operator + ( symbol_a symbol ) const
     { assert(handle_); return read().operator+(symbol ); }
    

    protected:

    	struct ___derived_handle_base___ : ___root_handle_base___

    	{

      virtual inline const std :: string & to_string__ ( ) const = 0;
      virtual inline symbol_a add ( any_a range ) const = 0;
      virtual inline symbol_a add_ ( symbol_a symbol ) const = 0;
      virtual inline symbol_a operator + ( symbol_a symbol ) const = 0;
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

    

      virtual inline const std :: string & to_string__ ( ) const
      { return value_.to_string__( ); }
      virtual inline symbol_a add ( any_a range ) const
      { return value_.add(range ); }
      virtual inline symbol_a add_ ( symbol_a symbol ) const
      { return value_.add_(symbol ); }
      virtual inline symbol_a operator + ( symbol_a symbol ) const
      { return value_.operator+(symbol ); }
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

    

    	inline const ___derived_handle_base___& read() const

    	{

    		return *std::static_pointer_cast<const ___derived_handle_base___>(handle_);

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

    

    	template <typename ___TTT___>

    	friend inline bool check_(const symbol_a& value);

    

    public:

    	static inline const char* ___abstraction_name___()

    	{

    		return "symbol";

    	}

    

    	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>& handle)

    	{

    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    

    	inline symbol_a() = default;

    

    	explicit inline symbol_a(bool reference)

    		: ___root___{ reference }

    	{}

    

    	inline symbol_a(const symbol_a& other, bool reference)

    		: ___root___(other, reference)

    	{}

    

    	inline symbol_a(symbol_a&& other, bool reference)

    		: ___root___(std::move(other), reference)

    	{}

    

    	template <typename ___TTT___>

    	explicit inline symbol_a(const std::shared_ptr<___TTT___>& handle, bool reference = false)

    		: ___root___(handle, reference)

    	{

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<symbol_a, std::decay_t<___TTT___>>::value>>

    	explicit inline symbol_a(___TTT___ value, bool reference = false);

    

    	template <typename ___TTT___>

    	inline symbol_a& operator=(const std::shared_ptr<___TTT___>& handle)

    	{

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<symbol_a, std::decay_t<___TTT___>>::value>>

    	inline symbol_a& operator=(___TTT___ value);

    };

    

    template <typename ___TTT___>

    inline bool check_(const symbol_a& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    template <typename ___TTT___, typename>

    inline symbol_a::symbol_a(___TTT___ value, bool reference)

    	: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    		reference)

    {}

    

    template <typename ___TTT___, typename>

    inline symbol_a& symbol_a::operator=(___TTT___ value)

    {

    	symbol_a temp{ std::move(value) };

    	std::swap(temp.handle_, handle_);

    	handle_->___weak___(handle_);

    	return *this;

    }

    

    #undef ___root___

}
#endif