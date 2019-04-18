#ifndef COM_ONEISH_STRANGE_CAT__H
#define COM_ONEISH_STRANGE_CAT__H

// # include "symbol_.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    #define ___derived___ symbol_

    

    
    class cat_ final : public ___derived___

    {

    public:

     inline symbol_ name ( thing_ _ ) const
     { assert(handle_); return read().name(_ ); }
     inline symbol_ name_ ( ) const
     { assert(handle_); return read().name_( ); }
     inline thing_ arguments ( thing_ _ ) const
     { assert(handle_); return read().arguments(_ ); }
     inline thing_ arguments_ ( ) const
     { assert(handle_); return read().arguments_( ); }
     inline thing_ parameters ( thing_ _ ) const
     { assert(handle_); return read().parameters(_ ); }
     inline thing_ parameters_ ( ) const
     { assert(handle_); return read().parameters_( ); }
     inline cat_ result ( thing_ _ ) const
     { assert(handle_); return read().result(_ ); }
     inline cat_ result_ ( ) const
     { assert(handle_); return read().result_( ); }
     inline thing_ includes ( thing_ range ) const
     { assert(handle_); return read().includes(range ); }
     inline thing_ includes_ ( thing_ thing ) const
     { assert(handle_); return read().includes_(thing ); }
     inline bool includes__ ( thing_ thing ) const
     { assert(handle_); return read().includes__(thing ); }
     inline thing_ conforms ( thing_ range ) const
     { assert(handle_); return read().conforms(range ); }
     inline thing_ conforms_ ( thing_ thing , thing_ cat_or_herd ) const
     { assert(handle_); return read().conforms_(thing, cat_or_herd ); }
     inline bool conforms__ ( thing_ thing , thing_ cat_or_herd ) const
     { assert(handle_); return read().conforms__(thing, cat_or_herd ); }
    

    private:

    	struct ___finale_handle_base___ : ___derived_handle_base___

    	{

      virtual inline symbol_ name ( thing_ _ ) const = 0;
      virtual inline symbol_ name_ ( ) const = 0;
      virtual inline thing_ arguments ( thing_ _ ) const = 0;
      virtual inline thing_ arguments_ ( ) const = 0;
      virtual inline thing_ parameters ( thing_ _ ) const = 0;
      virtual inline thing_ parameters_ ( ) const = 0;
      virtual inline cat_ result ( thing_ _ ) const = 0;
      virtual inline cat_ result_ ( ) const = 0;
      virtual inline thing_ includes ( thing_ range ) const = 0;
      virtual inline thing_ includes_ ( thing_ thing ) const = 0;
      virtual inline bool includes__ ( thing_ thing ) const = 0;
      virtual inline thing_ conforms ( thing_ range ) const = 0;
      virtual inline thing_ conforms_ ( thing_ thing , thing_ cat_or_herd ) const = 0;
      virtual inline bool conforms__ ( thing_ thing , thing_ cat_or_herd ) const = 0;
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

    

      virtual inline symbol_ name ( thing_ _ ) const
      { return value_.name(_ ); }
      virtual inline symbol_ name_ ( ) const
      { return value_.name_( ); }
      virtual inline thing_ arguments ( thing_ _ ) const
      { return value_.arguments(_ ); }
      virtual inline thing_ arguments_ ( ) const
      { return value_.arguments_( ); }
      virtual inline thing_ parameters ( thing_ _ ) const
      { return value_.parameters(_ ); }
      virtual inline thing_ parameters_ ( ) const
      { return value_.parameters_( ); }
      virtual inline cat_ result ( thing_ _ ) const
      { return value_.result(_ ); }
      virtual inline cat_ result_ ( ) const
      { return value_.result_( ); }
      virtual inline thing_ includes ( thing_ range ) const
      { return value_.includes(range ); }
      virtual inline thing_ includes_ ( thing_ thing ) const
      { return value_.includes_(thing ); }
      virtual inline bool includes__ ( thing_ thing ) const
      { return value_.includes__(thing ); }
      virtual inline thing_ conforms ( thing_ range ) const
      { return value_.conforms(range ); }
      virtual inline thing_ conforms_ ( thing_ thing , thing_ cat_or_herd ) const
      { return value_.conforms_(thing, cat_or_herd ); }
      virtual inline bool conforms__ ( thing_ thing , thing_ cat_or_herd ) const
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

    

    	inline const ___finale_handle_base___& read() const

    	{

    		return *std::static_pointer_cast<const ___finale_handle_base___>(handle_);

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

    

    	template <typename ___TTT___>

    	friend inline bool check_(const cat_& value);

    

    public:

    	static inline const char* ___struct_name___()

    	{

    		return "cat_";

    	}

    

    	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>& handle)

    	{

    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    

    	inline cat_() = default;

    

    	explicit inline cat_(bool reference)

    		: ___derived___{ reference }

    	{}

    

    	inline cat_(const cat_& other, bool reference)

    		: ___derived___(other, reference)

    	{}

    

    	inline cat_(cat_&& other, bool reference)

    		: ___derived___(std::move(other), reference)

    	{}

    

    	template <typename ___TTT___>

    	explicit inline cat_(const std::shared_ptr<___TTT___>& handle, bool reference = false)

    		: ___derived___(handle, reference)

    	{

    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_, std::decay_t<___TTT___>>::value>>

    	explicit inline cat_(___TTT___ value, bool reference = false)

    		: ___derived___(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{}

    

    	template <typename ___TTT___>

    	inline cat_& operator=(const std::shared_ptr<___TTT___>& handle)

    	{

    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_, std::decay_t<___TTT___>>::value>>

    	inline cat_& operator=(___TTT___ value)

    	{

    		cat_ temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}

    };

    

    template <typename ___TTT___>

    inline bool check_(const cat_& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    #undef ___derived___

}
#endif
