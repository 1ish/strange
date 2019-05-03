#ifndef COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_DATA_A_H
#define COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_DATA_A_H

// # include "random_access_iterator_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class random_access_iterator_data_a final : public ___derived___

    {

    public:

    	inline random_access_iterator_data_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline random_access_iterator_data_a operator++(int)

    	{

    		assert(handle_);

    		% struct_name% result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline random_access_iterator_data_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline random_access_iterator_data_a operator--(int)

    	{

    		assert(handle_);

    		% struct_name% result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline random_access_iterator_data_a& operator+=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline random_access_iterator_data_a& operator-=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline random_access_iterator_data_a& operator*=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline random_access_iterator_data_a& operator/=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline random_access_iterator_data_a& operator%=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline _1_ const & extract__ ( ) const
     { assert(handle_); return read().extract__( ); }
     inline void mutate__ ( _1_ const & data )
     { assert(handle_); write().mutate__(data ); }
     inline _1_ & reference__ ( )
     { assert(handle_); return write().reference__( ); }
    

    private:

    	struct ___finale_handle_base___ : ___derived_handle_base___

    	{

      virtual inline _1_ const & extract__ ( ) const = 0;
      virtual inline void mutate__ ( _1_ const & data ) = 0;
      virtual inline _1_ & reference__ ( ) = 0;
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

    

      virtual inline _1_ const & extract__ ( ) const
      { return value_.extract__( ); }
      virtual inline void mutate__ ( _1_ const & data )
      { value_.mutate__(data ); }
      virtual inline _1_ & reference__ ( )
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

    	friend inline bool check_(random_access_iterator_data_a<___1___> const& value);

    

    public:

    	static inline char const* ___abstraction_name___()

    	{

    		return "random_access_iterator_data_a";

    	}

    

    	static inline bool ___check___(std::shared_ptr<___root_handle_base___> const& handle)

    	{

    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    

    	inline random_access_iterator_data_a() = default;

    

    	explicit inline random_access_iterator_data_a(bool reference)

    		: ___derived___{ reference }

    	{}

    

    	inline random_access_iterator_data_a(random_access_iterator_data_a const& other, bool reference)

    		: ___derived___(other, reference)

    	{}

    

    	inline random_access_iterator_data_a(random_access_iterator_data_a&& other, bool reference)

    		: ___derived___(std::move(other), reference)

    	{}

    

    	template <typename ___TTT___>

    	explicit inline random_access_iterator_data_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)

    		: ___derived___(handle, reference)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis__("random_access_iterator_data_a constructor failed to cast from base to final");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    #endif

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_iterator_data_a, std::decay_t<___TTT___>>::value>>

    	explicit inline random_access_iterator_data_a(___TTT___ value, bool reference = false)

    		: ___derived___(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{}

    

    	template <typename ___TTT___>

    	inline random_access_iterator_data_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis__("random_access_iterator_data_a assignment failed to cast from base to final");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    #endif

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_iterator_data_a, std::decay_t<___TTT___>>::value>>

    	inline random_access_iterator_data_a& operator=(___TTT___ value)

    	{

    		random_access_iterator_data_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}

    };

    

    template <typename ___TTT___, typename ___1___>

    inline bool check_(random_access_iterator_data_a<___1___> const& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    #undef ___derived___

}
#endif
