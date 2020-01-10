#ifndef COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_A_H
#define COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_A_H

 //# include "any_forward.hpp"
 //# include "range_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class bidirectional_iterator_a : public ___derived___

    {

    public:

    	inline bidirectional_iterator_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline bidirectional_iterator_a operator++(int)

    	{

    		assert(handle_);

    		bidirectional_iterator_a result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline bidirectional_iterator_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline bidirectional_iterator_a operator--(int)

    	{

    		assert(handle_);

    		bidirectional_iterator_a result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline bidirectional_iterator_a& operator+=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline bidirectional_iterator_a& operator-=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline bidirectional_iterator_a& operator*=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline bidirectional_iterator_a& operator/=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline bidirectional_iterator_a& operator%=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline any_a < > decrement__ ( range_a < > const & _ )
     { assert(handle_); return write().decrement__(_ ); }
     inline bidirectional_iterator_a decrement_ ( )
     { assert(handle_); return write().decrement_( ); }
    

    protected:

    	struct ___dderived_handle_base___ : ___derived_handle_base___

    	{

      virtual inline any_a < > decrement__ ( range_a < > const & _ ) = 0;
      virtual inline bidirectional_iterator_a decrement_ ( ) = 0;
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

    

      virtual inline any_a < > decrement__ ( range_a < > const & _ )
      { return value_.decrement__(_ ); }
      virtual inline bidirectional_iterator_a decrement_ ( )
      { return value_.decrement_( ); }
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

    

    		virtual inline ___SHARED___ ___clone___() const final

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

    

    	inline ___dderived_handle_base___ const& read() const noexcept

    	{

    		return *std::static_pointer_cast<___dderived_handle_base___ const>(handle_);

    	}

    

    	inline ___dderived_handle_base___& write() noexcept

    	{

    		if (!handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___dderived_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___>

    	friend inline bool check(bidirectional_iterator_a<> const& value) noexcept;

    

    public:

    	static inline bool ___check___(___SHARED___ const& handle) noexcept

    	{

    		return bool(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));

    	}

    

    	inline bidirectional_iterator_a() = default;

    

    	static inline bidirectional_iterator_a val(bidirectional_iterator_a const& other) noexcept

    	{

    		return bidirectional_iterator_a{ other };

    	}

    /*

    	inline bidirectional_iterator_a(bidirectional_iterator_a const& other, bool reference) noexcept

    		: ___derived___(other, reference)

    	{}

    */

    	inline bidirectional_iterator_a(bidirectional_iterator_a& other, ___reference_tag___) noexcept

    		: ___derived___(other, ___reference_tag___{})

    	{}

    

    	static inline bidirectional_iterator_a ref(bidirectional_iterator_a& other) noexcept

    	{

    		return bidirectional_iterator_a(other, ___reference_tag___{});

    	}

    

    	inline bidirectional_iterator_a(bidirectional_iterator_a& other, ___duplicate_tag___) noexcept

    		: ___derived___(other, ___duplicate_tag___{})

    	{}

    

    	static inline bidirectional_iterator_a dup(bidirectional_iterator_a& other) noexcept

    	{

    		return bidirectional_iterator_a(other, ___duplicate_tag___{});

    	}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline bidirectional_iterator_a(std::shared_ptr<___TTT___> const& handle)

    		: ___derived___{ handle }

    	{

    		if (handle && !std::dynamic_pointer_cast<___dderived_handle_base___>(handle))

    		{

    			throw dis("bidirectional_iterator_a constructor failed to cast from base to dderived");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline bidirectional_iterator_a(std::shared_ptr<___TTT___> const& handle) noexcept

    		: ___derived___{ handle }

    	{

    		assert(!handle || std::dynamic_pointer_cast<___dderived_handle_base___>(handle));

    	}

    #endif

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline bidirectional_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)

    		: ___derived___(handle, ___reference_tag___{})

    	{

    		if (handle && !std::dynamic_pointer_cast<___dderived_handle_base___>(handle))

    		{

    			throw dis("bidirectional_iterator_a constructor failed to cast from base to dderived");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline bidirectional_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept

    		: ___derived___(handle, ___reference_tag___{})

    	{

    		assert(!handle || std::dynamic_pointer_cast<___dderived_handle_base___>(handle));

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<bidirectional_iterator_a, std::decay_t<___TTT___>>::value>>

    	explicit inline bidirectional_iterator_a(___TTT___ value) noexcept

    		: ___derived___{ std::make_shared<___dderived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }

    	{

    		handle_->___weak___(handle_);

    	}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	inline bidirectional_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    		if (handle && !std::dynamic_pointer_cast<___dderived_handle_base___>(handle))

    		{

    			throw dis("bidirectional_iterator_a assignment failed to cast from base to dderived");

    		}

    		handle_ = handle;

    		return *this;

    	}

    #else

    	template <typename ___TTT___>

    	inline bidirectional_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept

    	{

    		assert(!handle || std::dynamic_pointer_cast<___dderived_handle_base___>(handle));

    		handle_ = handle;

    		return *this;

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<bidirectional_iterator_a, std::decay_t<___TTT___>>::value>>

    	inline bidirectional_iterator_a& operator=(___TTT___ value) noexcept

    	{

    		bidirectional_iterator_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		return *this;

    	}

    

    private:

    	static bool const ___share___;

    	friend class ___bidirectional_iterator_a_share___;

    };

    

    template <typename ___TTT___>

    inline bool check(bidirectional_iterator_a<> const& value) noexcept

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    template <typename ___1___>

    bool const bidirectional_iterator_a<___1___>::___share___ = []()

    {

    	auto& shoal = shared();

    	reflection<bidirectional_iterator_a<___1___>>::share(shoal);

    	return shoal.something();

    }();

    

    #undef ___derived___

}
#endif
