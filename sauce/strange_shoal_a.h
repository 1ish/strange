#ifndef COM_ONEISH_STRANGE_SHOAL_A_H
#define COM_ONEISH_STRANGE_SHOAL_A_H

// # include "collection.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    
    class shoal_a final : public ___derived___

    {

    public:

     inline bool has__ ( const std :: string & s ) const
     { assert(handle_); return read().has__(s ); }
     inline any_a at__ ( const std :: string & s ) const
     { assert(handle_); return read().at__(s ); }
     inline void update__ ( const std :: string & s , any_a value )
     { assert(handle_); write().update__(s, value ); }
     inline bool insert__ ( const std :: string & s , any_a value )
     { assert(handle_); return write().insert__(s, value ); }
     inline bool erase__ ( const std :: string & s )
     { assert(handle_); return write().erase__(s ); }
    

    private:

    	struct ___finale_handle_base___ : ___derived_handle_base___

    	{

      virtual inline bool has__ ( const std :: string & s ) const = 0;
      virtual inline any_a at__ ( const std :: string & s ) const = 0;
      virtual inline void update__ ( const std :: string & s , any_a value ) = 0;
      virtual inline bool insert__ ( const std :: string & s , any_a value ) = 0;
      virtual inline bool erase__ ( const std :: string & s ) = 0;
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

    

      virtual inline bool has__ ( const std :: string & s ) const
      { return value_.has__(s ); }
      virtual inline any_a at__ ( const std :: string & s ) const
      { return value_.at__(s ); }
      virtual inline void update__ ( const std :: string & s , any_a value )
      { value_.update__(s, value ); }
      virtual inline bool insert__ ( const std :: string & s , any_a value )
      { return value_.insert__(s, value ); }
      virtual inline bool erase__ ( const std :: string & s )
      { return value_.erase__(s ); }
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

    	friend inline bool check_(const shoal_a& value);

    

    public:

    	static inline const char* ___abstraction_name___()

    	{

    		return "shoal";

    	}

    

    	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>& handle)

    	{

    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    

    	inline shoal_a() = default;

    

    	explicit inline shoal_a(bool reference)

    		: ___derived___{ reference }

    	{}

    

    	inline shoal_a(const shoal_a& other, bool reference)

    		: ___derived___(other, reference)

    	{}

    

    	inline shoal_a(shoal_a&& other, bool reference)

    		: ___derived___(std::move(other), reference)

    	{}

    

    	template <typename ___TTT___>

    	explicit inline shoal_a(const std::shared_ptr<___TTT___>& handle, bool reference = false)

    		: ___derived___(handle, reference)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis__("shoal constructor failed to cast from base to final");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    #endif

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<shoal_a, std::decay_t<___TTT___>>::value>>

    	explicit inline shoal_a(___TTT___ value, bool reference = false)

    		: ___derived___(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{}

    

    	template <typename ___TTT___>

    	inline shoal_a& operator=(const std::shared_ptr<___TTT___>& handle)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis__("shoal assignment failed to cast from base to final");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    #endif

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<shoal_a, std::decay_t<___TTT___>>::value>>

    	inline shoal_a& operator=(___TTT___ value)

    	{

    		shoal_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}

    };

    

    template <typename ___TTT___>

    inline bool check_(const shoal_a& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    #undef ___derived___

}
#endif
