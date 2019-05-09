#ifndef COM_ONEISH_STRANGE_LAKE_A_H
#define COM_ONEISH_STRANGE_LAKE_A_H

// # include "any_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename random_access_iterator_a >
    class lake_a : public ___derived___

    {

    public:

    	inline lake_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline lake_a operator++(int)

    	{

    		assert(handle_);

    		% struct_name% result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline lake_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline lake_a operator--(int)

    	{

    		assert(handle_);

    		% struct_name% result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline lake_a& operator+=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline lake_a& operator-=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline lake_a& operator*=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline lake_a& operator/=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline lake_a& operator%=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline bool has__ ( int64_t index ) const
     { assert(handle_); return read().has__(index ); }
     inline any_a < > at__ ( int64_t index ) const
     { assert(handle_); return read().at__(index ); }
     inline void update__ ( int64_t index , any_a < > const & value )
     { assert(handle_); write().update__(index, value ); }
     inline bool insert__ ( int64_t index , any_a < > const & value )
     { assert(handle_); return write().insert__(index, value ); }
     inline bool erase__ ( int64_t index )
     { assert(handle_); return write().erase__(index ); }
     inline any_a < > beset ( any_a < > const & _ )
     { assert(handle_); return write().beset(_ ); }
     inline random_access_iterator_a beset_ ( )
     { assert(handle_); return write().beset_( ); }
     inline random_access_iterator_a begin ( )
     { assert(handle_); return write().begin( ); }
     inline any_a < > enset ( any_a < > const & _ )
     { assert(handle_); return write().enset(_ ); }
     inline random_access_iterator_a enset_ ( )
     { assert(handle_); return write().enset_( ); }
     inline random_access_iterator_a end ( )
     { assert(handle_); return write().end( ); }
    

    protected:

    	struct ___dderived_handle_base___ : ___derived_handle_base___

    	{

      virtual inline bool has__ ( int64_t index ) const = 0;
      virtual inline any_a < > at__ ( int64_t index ) const = 0;
      virtual inline void update__ ( int64_t index , any_a < > const & value ) = 0;
      virtual inline bool insert__ ( int64_t index , any_a < > const & value ) = 0;
      virtual inline bool erase__ ( int64_t index ) = 0;
      virtual inline any_a < > beset ( any_a < > const & _ ) = 0;
      virtual inline random_access_iterator_a beset_ ( ) = 0;
      virtual inline random_access_iterator_a begin ( ) = 0;
      virtual inline any_a < > enset ( any_a < > const & _ ) = 0;
      virtual inline random_access_iterator_a enset_ ( ) = 0;
      virtual inline random_access_iterator_a end ( ) = 0;
    	};

    

    	template <typename ___TTT___, typename ___DDHB___ = ___dderived_handle_base___>

    	struct ___dderived_handle___ : ___derived_handle___<___TTT___, ___DDHB___>

    	{

    		template <typename ___UUU___ = ___TTT___>

    		inline ___dderived_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)

    			: ___derived_handle___<___TTT___, ___DDHB___>{ value }

    		{}

    

    		template <typename ___UUU___ = ___TTT___>

    		inline ___dderived_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept

    			: ___derived_handle___<___TTT___, ___DDHB___>{ std::move(value) }

    		{}

    

      virtual inline bool has__ ( int64_t index ) const
      { return value_.has__(index ); }
      virtual inline any_a < > at__ ( int64_t index ) const
      { return value_.at__(index ); }
      virtual inline void update__ ( int64_t index , any_a < > const & value )
      { value_.update__(index, value ); }
      virtual inline bool insert__ ( int64_t index , any_a < > const & value )
      { return value_.insert__(index, value ); }
      virtual inline bool erase__ ( int64_t index )
      { return value_.erase__(index ); }
      virtual inline any_a < > beset ( any_a < > const & _ )
      { return value_.beset(_ ); }
      virtual inline random_access_iterator_a beset_ ( )
      { return value_.beset_( ); }
      virtual inline random_access_iterator_a begin ( )
      { return value_.begin( ); }
      virtual inline any_a < > enset ( any_a < > const & _ )
      { return value_.enset(_ ); }
      virtual inline random_access_iterator_a enset_ ( )
      { return value_.enset_( ); }
      virtual inline random_access_iterator_a end ( )
      { return value_.end( ); }
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

    		inline ___dderived_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)

    			: ___dderived_handle___<___TTT___>{ value }

    		{}

    

    		template <typename ___UUU___ = ___TTT___>

    		inline ___dderived_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept

    			: ___dderived_handle___<___TTT___>{ std::move(value) }

    		{}

    

    		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final

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

    

    	inline ___dderived_handle_base___ const& read() const

    	{

    		return *std::static_pointer_cast<___dderived_handle_base___ const>(handle_);

    	}

    

    	inline ___dderived_handle_base___& write()

    	{

    		if (!___reference___ && !handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___dderived_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___>

    	friend inline bool check_(lake_a<> const& value);

    

    public:

    	static inline char const* ___abstraction_name___()

    	{

    		return "lake_a";

    	}

    

    	static inline bool ___check___(std::shared_ptr<___root_handle_base___>const & handle)

    	{

    		return bool(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));

    	}

    

    	inline lake_a() = default;

    

    	explicit inline lake_a(bool reference)

    		: ___derived___{ reference }

    	{}

    

    	inline lake_a(lake_a const& other, bool reference)

    		: ___derived___(other, reference)

    	{}

    

    	inline lake_a(lake_a&& other, bool reference)

    		: ___derived___(std::move(other), reference)

    	{}

    

    	template <typename ___TTT___>

    	explicit inline lake_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)

    		: ___derived___(handle, reference)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___dderived_handle_base___>(handle))

    		{

    			throw dis__("lake_a constructor failed to cast from base to dderived");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));

    #endif

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<lake_a, std::decay_t<___TTT___>>::value>>

    	explicit inline lake_a(___TTT___ value, bool reference = false)

    		: ___derived___(std::make_shared<___dderived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{}

    

    	template <typename ___TTT___>

    	inline lake_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___dderived_handle_base___>(handle))

    		{

    			throw dis__("lake_a assignment failed to cast from base to dderived");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));

    #endif

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<lake_a, std::decay_t<___TTT___>>::value>>

    	inline lake_a& operator=(___TTT___ value)

    	{

    		lake_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}

    };

    

    template <typename ___TTT___>

    inline bool check_(lake_a<> const& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    #undef ___derived___

}
#endif
