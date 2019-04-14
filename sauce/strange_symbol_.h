#ifndef COM_ONEISH_STRANGE_SYMBOL__H
#define COM_ONEISH_STRANGE_SYMBOL__H

// # include "thing_.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    #define ___root___ thing_

    

    
    class symbol_ : public ___root___

    {

    public:

     inline const std :: string & to_string__ ( ) const
     { assert(handle_); return read().to_string__( ); }
     inline symbol_ add ( thing_ range ) const
     { assert(handle_); return read().add(range ); }
     inline symbol_ add_ ( symbol_ symbol ) const
     { assert(handle_); return read().add_(symbol ); }
     inline symbol_ operator + ( symbol_ symbol ) const
     { assert(handle_); return read().operator+(symbol ); }
    

    protected:

    	struct ___derived_handle_base___ : ___root_handle_base___

    	{

      virtual inline const std :: string & to_string__ ( ) const = 0;
      virtual inline symbol_ add ( thing_ range ) const = 0;
      virtual inline symbol_ add_ ( symbol_ symbol ) const = 0;
      virtual inline symbol_ operator + ( symbol_ symbol ) const = 0;
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
      virtual inline symbol_ add ( thing_ range ) const
      { return value_.add(range ); }
      virtual inline symbol_ add_ ( symbol_ symbol ) const
      { return value_.add_(symbol ); }
      virtual inline symbol_ operator + ( symbol_ symbol ) const
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

    	friend inline bool check_(const symbol_& value);

    

    public:

    	static inline const char* ___struct_name___()

    	{

    		return "symbol_";

    	}

    

    	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>& handle)

    	{

    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    

    	inline symbol_() = default;

    

    	explicit inline symbol_(bool reference)

    		: ___root___{ reference }

    	{}

    

    	inline symbol_(const symbol_& other, bool reference)

    		: ___root___(other, reference)

    	{}

    

    	inline symbol_(symbol_&& other, bool reference)

    		: ___root___(std::move(other), reference)

    	{}

    

    	template <typename ___TTT___>

    	explicit inline symbol_(const std::shared_ptr<___TTT___>& handle, bool reference = false)

    		: ___root___(handle, reference)

    	{

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<symbol_, ___TTT___>::value>>

    	explicit inline symbol_(___TTT___ value, bool reference = false);

    

    	template <typename ___TTT___>

    	inline symbol_& operator=(const std::shared_ptr<___TTT___>& handle)

    	{

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<symbol_, ___TTT___>::value>>

    	inline symbol_& operator=(___TTT___ value);

    };

    

    template <typename ___TTT___>

    inline bool check_(const symbol_& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    template <typename ___TTT___, typename>

    inline symbol_::symbol_(___TTT___ value, bool reference)

    	: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    		reference)

    {}

    

    template <typename ___TTT___, typename>

    inline symbol_& symbol_::operator=(___TTT___ value)

    {

    	symbol_ temp{ std::move(value) };

    	std::swap(temp.handle_, handle_);

    	handle_->___weak___(handle_);

    	return *this;

    }

    

    #undef ___root___

}
#endif
