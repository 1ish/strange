#ifndef COM_ONEISH_STRANGE_CAT_A_H
#define COM_ONEISH_STRANGE_CAT_A_H

// # include "symbol.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class cat_a final : public ___derived___

    {

    public:

     inline symbol_a < > name ( any_a < > const & _ ) const
     { assert(handle_); return read().name(_ ); }
     inline symbol_a < > name_ ( ) const
     { assert(handle_); return read().name_( ); }
     inline any_a < > arguments ( any_a < > const & _ ) const
     { assert(handle_); return read().arguments(_ ); }
     inline any_a < > arguments_ ( ) const
     { assert(handle_); return read().arguments_( ); }
     inline any_a < > parameters ( any_a < > const & _ ) const
     { assert(handle_); return read().parameters(_ ); }
     inline any_a < > parameters_ ( ) const
     { assert(handle_); return read().parameters_( ); }
     inline cat_a result ( any_a < > const & _ ) const
     { assert(handle_); return read().result(_ ); }
     inline cat_a result_ ( ) const
     { assert(handle_); return read().result_( ); }
     inline any_a < > includes ( any_a < > const & range ) const
     { assert(handle_); return read().includes(range ); }
     inline any_a < > includes_ ( any_a < > const & thing ) const
     { assert(handle_); return read().includes_(thing ); }
     inline bool includes__ ( any_a < > const & thing ) const
     { assert(handle_); return read().includes__(thing ); }
     inline any_a < > conforms ( any_a < > const & range ) const
     { assert(handle_); return read().conforms(range ); }
     inline any_a < > conforms_ ( any_a < > const & thing , any_a < > const & cat_or_herd ) const
     { assert(handle_); return read().conforms_(thing, cat_or_herd ); }
     inline bool conforms__ ( any_a < > const & thing , any_a < > const & cat_or_herd ) const
     { assert(handle_); return read().conforms__(thing, cat_or_herd ); }
    

    private:

    	struct ___finale_handle_base___ : ___derived_handle_base___

    	{

      virtual inline symbol_a < > name ( any_a < > const & _ ) const = 0;
      virtual inline symbol_a < > name_ ( ) const = 0;
      virtual inline any_a < > arguments ( any_a < > const & _ ) const = 0;
      virtual inline any_a < > arguments_ ( ) const = 0;
      virtual inline any_a < > parameters ( any_a < > const & _ ) const = 0;
      virtual inline any_a < > parameters_ ( ) const = 0;
      virtual inline cat_a result ( any_a < > const & _ ) const = 0;
      virtual inline cat_a result_ ( ) const = 0;
      virtual inline any_a < > includes ( any_a < > const & range ) const = 0;
      virtual inline any_a < > includes_ ( any_a < > const & thing ) const = 0;
      virtual inline bool includes__ ( any_a < > const & thing ) const = 0;
      virtual inline any_a < > conforms ( any_a < > const & range ) const = 0;
      virtual inline any_a < > conforms_ ( any_a < > const & thing , any_a < > const & cat_or_herd ) const = 0;
      virtual inline bool conforms__ ( any_a < > const & thing , any_a < > const & cat_or_herd ) const = 0;
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

    

      virtual inline symbol_a < > name ( any_a < > const & _ ) const
      { return value_.name(_ ); }
      virtual inline symbol_a < > name_ ( ) const
      { return value_.name_( ); }
      virtual inline any_a < > arguments ( any_a < > const & _ ) const
      { return value_.arguments(_ ); }
      virtual inline any_a < > arguments_ ( ) const
      { return value_.arguments_( ); }
      virtual inline any_a < > parameters ( any_a < > const & _ ) const
      { return value_.parameters(_ ); }
      virtual inline any_a < > parameters_ ( ) const
      { return value_.parameters_( ); }
      virtual inline cat_a result ( any_a < > const & _ ) const
      { return value_.result(_ ); }
      virtual inline cat_a result_ ( ) const
      { return value_.result_( ); }
      virtual inline any_a < > includes ( any_a < > const & range ) const
      { return value_.includes(range ); }
      virtual inline any_a < > includes_ ( any_a < > const & thing ) const
      { return value_.includes_(thing ); }
      virtual inline bool includes__ ( any_a < > const & thing ) const
      { return value_.includes__(thing ); }
      virtual inline any_a < > conforms ( any_a < > const & range ) const
      { return value_.conforms(range ); }
      virtual inline any_a < > conforms_ ( any_a < > const & thing , any_a < > const & cat_or_herd ) const
      { return value_.conforms_(thing, cat_or_herd ); }
      virtual inline bool conforms__ ( any_a < > const & thing , any_a < > const & cat_or_herd ) const
      { return value_.conforms__(thing, cat_or_herd ); }
    	};

    

    	template <typename ___TTT___>

    	struct ___finale_handle_final___<std::reference_wrapper<___TTT___>> final

    		: ___finale_handle_final___<___TTT___&>

    	{

    		inline ___finale_handle_final___(std::reference_wrapper<___TTT___> ref)

    			: ___finale_handle_final___<___TTT___&>{ ref.get() }

    		{}

    	};

    

    	inline ___finale_handle_base___ const& read() const

    	{

    		return *std::static_pointer_cast<___finale_handle_base___ const>(handle_);

    	}

    

    	inline ___finale_handle_base___& write()

    	{

    		if (!___reference___ && !handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___finale_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___, typename ___1___>

    	friend inline bool check_(cat_a<___1___> const& value);

    

    public:

    	static inline char const* ___abstraction_name___()

    	{

    		return "cat_a";

    	}

    

    	static inline bool ___check___(std::shared_ptr<___root_handle_base___> const& handle)

    	{

    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    

    	inline cat_a() = default;

    

    	explicit inline cat_a(bool reference)

    		: ___derived___{ reference }

    	{}

    

    	inline cat_a(cat_a const& other, bool reference)

    		: ___derived___(other, reference)

    	{}

    

    	inline cat_a(cat_a&& other, bool reference)

    		: ___derived___(std::move(other), reference)

    	{}

    

    	template <typename ___TTT___>

    	explicit inline cat_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)

    		: ___derived___(handle, reference)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis__("cat_a constructor failed to cast from base to final");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    #endif

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_a, std::decay_t<___TTT___>>::value>>

    	explicit inline cat_a(___TTT___ value, bool reference = false)

    		: ___derived___(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{}

    

    	template <typename ___TTT___>

    	inline cat_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis__("cat_a assignment failed to cast from base to final");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    #endif

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_a, std::decay_t<___TTT___>>::value>>

    	inline cat_a& operator=(___TTT___ value)

    	{

    		cat_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}

    };

    

    template <typename ___TTT___, typename ___1___>

    inline bool check_(cat_a<___1___> const& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    #undef ___derived___

}
#endif
