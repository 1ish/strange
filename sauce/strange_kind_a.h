#ifndef COM_ONEISH_STRANGE_KIND_A_H
#define COM_ONEISH_STRANGE_KIND_A_H

 //# include "any_forward.hpp"
 //# include "range_forward.hpp"
 //# include "flock_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class kind_a final : public ___derived___

    {

    public:

    	inline kind_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline kind_a operator++(int)

    	{

    		assert(handle_);

    		kind_a result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline kind_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline kind_a operator--(int)

    	{

    		assert(handle_);

    		kind_a result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline kind_a& operator+=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline kind_a& operator-=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline kind_a& operator*=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline kind_a& operator/=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline kind_a& operator%=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline any_a < > aspects__ ( range_a < > const & _ ) const
     { assert(handle_); return read().aspects__(_ ); }
     inline flock_a < > aspects_ ( ) const
     { assert(handle_); return read().aspects_( ); }
     inline any_a < > fixed__ ( range_a < > const & _ ) const
     { assert(handle_); return read().fixed__(_ ); }
     inline any_a < > fixed_ ( ) const
     { assert(handle_); return read().fixed_( ); }
     inline bool fixed ( ) const
     { assert(handle_); return read().fixed( ); }
     inline any_a < > reference__ ( range_a < > const & _ ) const
     { assert(handle_); return read().reference__(_ ); }
     inline any_a < > reference_ ( ) const
     { assert(handle_); return read().reference_( ); }
     inline bool reference ( ) const
     { assert(handle_); return read().reference( ); }
     inline any_a < > optional__ ( range_a < > const & _ ) const
     { assert(handle_); return read().optional__(_ ); }
     inline any_a < > optional_ ( ) const
     { assert(handle_); return read().optional_( ); }
     inline bool optional ( ) const
     { assert(handle_); return read().optional( ); }
    

    private:

    	struct ___finale_handle_base___ : ___dderived_handle_base___

    	{

      virtual inline any_a < > aspects__ ( range_a < > const & _ ) const = 0;
      virtual inline flock_a < > aspects_ ( ) const = 0;
      virtual inline any_a < > fixed__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > fixed_ ( ) const = 0;
      virtual inline bool fixed ( ) const = 0;
      virtual inline any_a < > reference__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > reference_ ( ) const = 0;
      virtual inline bool reference ( ) const = 0;
      virtual inline any_a < > optional__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > optional_ ( ) const = 0;
      virtual inline bool optional ( ) const = 0;
    	};

    

    	template <typename ___TTT___>

    	struct ___finale_handle_final___ final : ___dderived_handle___<___TTT___, ___finale_handle_base___>

    	{

    		template <typename ___UUU___ = ___TTT___>

    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)

    			: ___dderived_handle___<___TTT___, ___finale_handle_base___>{ value }

    		{}

    

    		template <typename ___UUU___ = ___TTT___>

    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept

    			: ___dderived_handle___<___TTT___, ___finale_handle_base___>{ std::move(value) }

    		{}

    

    		virtual inline ___SHARED___ ___clone___() const final

    		{

    			return std::make_shared<___finale_handle_final___>(___dderived_handle___<___TTT___, ___finale_handle_base___>::value_);

    		}

    

      virtual inline any_a < > aspects__ ( range_a < > const & _ ) const
      { return value_.aspects__(_ ); }
      virtual inline flock_a < > aspects_ ( ) const
      { return value_.aspects_( ); }
      virtual inline any_a < > fixed__ ( range_a < > const & _ ) const
      { return value_.fixed__(_ ); }
      virtual inline any_a < > fixed_ ( ) const
      { return value_.fixed_( ); }
      virtual inline bool fixed ( ) const
      { return value_.fixed( ); }
      virtual inline any_a < > reference__ ( range_a < > const & _ ) const
      { return value_.reference__(_ ); }
      virtual inline any_a < > reference_ ( ) const
      { return value_.reference_( ); }
      virtual inline bool reference ( ) const
      { return value_.reference( ); }
      virtual inline any_a < > optional__ ( range_a < > const & _ ) const
      { return value_.optional__(_ ); }
      virtual inline any_a < > optional_ ( ) const
      { return value_.optional_( ); }
      virtual inline bool optional ( ) const
      { return value_.optional( ); }
    	};

    

    	template <typename ___TTT___>

    	struct ___finale_handle_final___<std::reference_wrapper<___TTT___>> final

    		: ___finale_handle_final___<___TTT___&>

    	{

    		inline ___finale_handle_final___(std::reference_wrapper<___TTT___> ref)

    			: ___finale_handle_final___<___TTT___&>{ ref.get() }

    		{}

    	};

    

    	inline ___finale_handle_base___ const& read() const noexcept

    	{

    		return *std::static_pointer_cast<___finale_handle_base___ const>(handle_);

    	}

    

    	inline ___finale_handle_base___& write() noexcept

    	{

    		if (!handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___finale_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___>

    	friend inline bool check(kind_a<> const& value) noexcept;

    

    public:

    	static inline bool ___check___(___SHARED___ const& handle) noexcept

    	{

    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    

    	inline kind_a() = default;

    

    	static inline kind_a val(kind_a const& other) noexcept

    	{

    		return kind_a{ other };

    	}

    

    	inline kind_a(kind_a& other, ___reference_tag___) noexcept

    		: ___derived___(other, ___reference_tag___{})

    	{}

    

    	static inline kind_a ref(kind_a& other) noexcept

    	{

    		return kind_a(other, ___reference_tag___{});

    	}

    

    	inline kind_a(kind_a& other, ___duplicate_tag___) noexcept

    		: ___derived___(other, ___duplicate_tag___{})

    	{}

    

    	static inline kind_a dup(kind_a& other) noexcept

    	{

    		return kind_a(other, ___duplicate_tag___{});

    	}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline kind_a(std::shared_ptr<___TTT___> const& handle)

    		: ___derived___{ handle }

    	{

    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis("kind_a constructor failed to cast from base to final");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline kind_a(std::shared_ptr<___TTT___> const& handle) noexcept

    		: ___derived___{ handle }

    	{

    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    #endif

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline kind_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)

    		: ___derived___(handle, ___reference_tag___{})

    	{

    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis("kind_a constructor failed to cast from base to final");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline kind_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept

    		: ___derived___(handle, ___reference_tag___{})

    	{

    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<kind_a, std::decay_t<___TTT___>>::value>>

    	explicit inline kind_a(___TTT___ value) noexcept

    		: ___derived___{ std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }

    	{

    		handle_->___weak___(handle_);

    	}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	inline kind_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis("kind_a assignment failed to cast from base to final");

    		}

    		handle_ = handle;

    		return *this;

    	}

    #else

    	template <typename ___TTT___>

    	inline kind_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept

    	{

    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    		handle_ = handle;

    		return *this;

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<kind_a, std::decay_t<___TTT___>>::value>>

    	inline kind_a& operator=(___TTT___ value) noexcept

    	{

    		kind_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		return *this;

    	}

    

    private:

    	static bool const ___share___;

    	friend class ___kind_a_share___;

    };

    

    template <typename ___TTT___>

    inline bool check(kind_a<> const& value) noexcept

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    template <typename ___1___>

    bool const kind_a<___1___>::___share___ = []()

    {

    	auto& shoal = shared();

    	reflection<kind_a<___1___>>::share(shoal);

    	return shoal;

    }();

    

    #undef ___derived___

}
#endif
