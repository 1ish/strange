#ifndef COM_ONEISH_STRANGE_RANDOM_ACCESS_CONST_ITERATOR_A_H
#define COM_ONEISH_STRANGE_RANDOM_ACCESS_CONST_ITERATOR_A_H

 //# include "any_forward.hpp"
 //# include "range_forward.hpp"
 //# include "number_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class random_access_const_iterator_a : public ___derived___

    {

    public:

    	inline random_access_const_iterator_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline random_access_const_iterator_a operator++(int)

    	{

    		assert(handle_);

    		random_access_const_iterator_a result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline random_access_const_iterator_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline random_access_const_iterator_a operator--(int)

    	{

    		assert(handle_);

    		random_access_const_iterator_a result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline random_access_const_iterator_a& operator+=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline random_access_const_iterator_a& operator-=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline random_access_const_iterator_a& operator*=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline random_access_const_iterator_a& operator/=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline random_access_const_iterator_a& operator%=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline any_a < > self_add__ ( range_a < > const & range )
     { assert(handle_); return write().self_add__(range ); }
     inline random_access_const_iterator_a self_add_ ( number_a < > const & number )
     { assert(handle_); return write().self_add_(number ); }
     inline any_a < > add__ ( range_a < > const & range ) const
     { assert(handle_); return read().add__(range ); }
     inline random_access_const_iterator_a add_ ( number_a < > const & number ) const
     { assert(handle_); return read().add_(number ); }
     inline random_access_const_iterator_a operator + ( number_a < > const & number ) const
     { assert(handle_); return read().operator+(number ); }
     inline any_a < > self_subtract__ ( range_a < > const & range )
     { assert(handle_); return write().self_subtract__(range ); }
     inline random_access_const_iterator_a self_subtract_ ( number_a < > const & number )
     { assert(handle_); return write().self_subtract_(number ); }
     inline any_a < > subtract__ ( range_a < > const & range ) const
     { assert(handle_); return read().subtract__(range ); }
     inline random_access_const_iterator_a subtract_ ( number_a < > const & number ) const
     { assert(handle_); return read().subtract_(number ); }
     inline random_access_const_iterator_a operator - ( number_a < > const & number ) const
     { assert(handle_); return read().operator-(number ); }
     inline any_a < > less_than__ ( range_a < > const & range ) const
     { assert(handle_); return read().less_than__(range ); }
     inline any_a < > less_than_ ( random_access_const_iterator_a const & it ) const
     { assert(handle_); return read().less_than_(it ); }
     inline bool operator < ( random_access_const_iterator_a const & it ) const
     { assert(handle_); return read().operator<(it ); }
     inline any_a < > greater_than__ ( range_a < > const & range ) const
     { assert(handle_); return read().greater_than__(range ); }
     inline any_a < > greater_than_ ( random_access_const_iterator_a const & it ) const
     { assert(handle_); return read().greater_than_(it ); }
     inline bool operator > ( random_access_const_iterator_a const & it ) const
     { assert(handle_); return read().operator>(it ); }
     inline any_a < > less_or_equal__ ( range_a < > const & range ) const
     { assert(handle_); return read().less_or_equal__(range ); }
     inline any_a < > less_or_equal_ ( random_access_const_iterator_a const & it ) const
     { assert(handle_); return read().less_or_equal_(it ); }
     inline bool operator <= ( random_access_const_iterator_a const & it ) const
     { assert(handle_); return read().operator<=(it ); }
     inline any_a < > greater_or_equal__ ( range_a < > const & range ) const
     { assert(handle_); return read().greater_or_equal__(range ); }
     inline any_a < > greater_or_equal_ ( random_access_const_iterator_a const & it ) const
     { assert(handle_); return read().greater_or_equal_(it ); }
     inline bool operator >= ( random_access_const_iterator_a const & it ) const
     { assert(handle_); return read().operator>=(it ); }
    

    protected:

    	struct ___ddderived_handle_base___ : ___dderived_handle_base___

    	{

      virtual inline any_a < > self_add__ ( range_a < > const & range ) = 0;
      virtual inline random_access_const_iterator_a self_add_ ( number_a < > const & number ) = 0;
      virtual inline any_a < > add__ ( range_a < > const & range ) const = 0;
      virtual inline random_access_const_iterator_a add_ ( number_a < > const & number ) const = 0;
      virtual inline random_access_const_iterator_a operator + ( number_a < > const & number ) const = 0;
      virtual inline any_a < > self_subtract__ ( range_a < > const & range ) = 0;
      virtual inline random_access_const_iterator_a self_subtract_ ( number_a < > const & number ) = 0;
      virtual inline any_a < > subtract__ ( range_a < > const & range ) const = 0;
      virtual inline random_access_const_iterator_a subtract_ ( number_a < > const & number ) const = 0;
      virtual inline random_access_const_iterator_a operator - ( number_a < > const & number ) const = 0;
      virtual inline any_a < > less_than__ ( range_a < > const & range ) const = 0;
      virtual inline any_a < > less_than_ ( random_access_const_iterator_a const & it ) const = 0;
      virtual inline bool operator < ( random_access_const_iterator_a const & it ) const = 0;
      virtual inline any_a < > greater_than__ ( range_a < > const & range ) const = 0;
      virtual inline any_a < > greater_than_ ( random_access_const_iterator_a const & it ) const = 0;
      virtual inline bool operator > ( random_access_const_iterator_a const & it ) const = 0;
      virtual inline any_a < > less_or_equal__ ( range_a < > const & range ) const = 0;
      virtual inline any_a < > less_or_equal_ ( random_access_const_iterator_a const & it ) const = 0;
      virtual inline bool operator <= ( random_access_const_iterator_a const & it ) const = 0;
      virtual inline any_a < > greater_or_equal__ ( range_a < > const & range ) const = 0;
      virtual inline any_a < > greater_or_equal_ ( random_access_const_iterator_a const & it ) const = 0;
      virtual inline bool operator >= ( random_access_const_iterator_a const & it ) const = 0;
    	};

    

    	template <typename ___TTT___, typename ___DDDHB___ = ___ddderived_handle_base___>

    	struct ___ddderived_handle___ : ___dderived_handle___<___TTT___, ___DDDHB___>

    	{

    		template <typename ___UUU___ = ___TTT___>

    		inline ___ddderived_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)

    			: ___dderived_handle___<___TTT___, ___DDDHB___>{ value }

    		{}

    

    		template <typename ___UUU___ = ___TTT___>

    		inline ___ddderived_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept

    			: ___dderived_handle___<___TTT___, ___DDDHB___>{ std::move(value) }

    		{}

    

      virtual inline any_a < > self_add__ ( range_a < > const & range )
      { return value_.self_add__(range ); }
      virtual inline random_access_const_iterator_a self_add_ ( number_a < > const & number )
      { return value_.self_add_(number ); }
      virtual inline any_a < > add__ ( range_a < > const & range ) const
      { return value_.add__(range ); }
      virtual inline random_access_const_iterator_a add_ ( number_a < > const & number ) const
      { return value_.add_(number ); }
      virtual inline random_access_const_iterator_a operator + ( number_a < > const & number ) const
      { return value_.operator+(number ); }
      virtual inline any_a < > self_subtract__ ( range_a < > const & range )
      { return value_.self_subtract__(range ); }
      virtual inline random_access_const_iterator_a self_subtract_ ( number_a < > const & number )
      { return value_.self_subtract_(number ); }
      virtual inline any_a < > subtract__ ( range_a < > const & range ) const
      { return value_.subtract__(range ); }
      virtual inline random_access_const_iterator_a subtract_ ( number_a < > const & number ) const
      { return value_.subtract_(number ); }
      virtual inline random_access_const_iterator_a operator - ( number_a < > const & number ) const
      { return value_.operator-(number ); }
      virtual inline any_a < > less_than__ ( range_a < > const & range ) const
      { return value_.less_than__(range ); }
      virtual inline any_a < > less_than_ ( random_access_const_iterator_a const & it ) const
      { return value_.less_than_(it ); }
      virtual inline bool operator < ( random_access_const_iterator_a const & it ) const
      { return value_.operator<(it ); }
      virtual inline any_a < > greater_than__ ( range_a < > const & range ) const
      { return value_.greater_than__(range ); }
      virtual inline any_a < > greater_than_ ( random_access_const_iterator_a const & it ) const
      { return value_.greater_than_(it ); }
      virtual inline bool operator > ( random_access_const_iterator_a const & it ) const
      { return value_.operator>(it ); }
      virtual inline any_a < > less_or_equal__ ( range_a < > const & range ) const
      { return value_.less_or_equal__(range ); }
      virtual inline any_a < > less_or_equal_ ( random_access_const_iterator_a const & it ) const
      { return value_.less_or_equal_(it ); }
      virtual inline bool operator <= ( random_access_const_iterator_a const & it ) const
      { return value_.operator<=(it ); }
      virtual inline any_a < > greater_or_equal__ ( range_a < > const & range ) const
      { return value_.greater_or_equal__(range ); }
      virtual inline any_a < > greater_or_equal_ ( random_access_const_iterator_a const & it ) const
      { return value_.greater_or_equal_(it ); }
      virtual inline bool operator >= ( random_access_const_iterator_a const & it ) const
      { return value_.operator>=(it ); }
    	};

    

    	template <typename ___TTT___, typename ___DDDHB___>

    	struct ___ddderived_handle___<std::reference_wrapper<___TTT___>, ___DDDHB___>

    		: ___ddderived_handle___<___TTT___&, ___DDDHB___>

    	{

    		inline ___ddderived_handle___(std::reference_wrapper<___TTT___> ref)

    			: ___ddderived_handle___<___TTT___&, ___DDDHB___>{ ref.get() }

    		{}

    	};

    

    private:

    	template <typename ___TTT___>

    	struct ___ddderived_handle_final___ final : ___ddderived_handle___<___TTT___>

    	{

    		template <typename ___UUU___ = ___TTT___>

    		inline ___ddderived_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)

    			: ___ddderived_handle___<___TTT___>{ value }

    		{}

    

    		template <typename ___UUU___ = ___TTT___>

    		inline ___ddderived_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept

    			: ___ddderived_handle___<___TTT___>{ std::move(value) }

    		{}

    

    		virtual inline ___SHARED___ ___clone___() const final

    		{

    			return std::make_shared<___ddderived_handle_final___>(___ddderived_handle___<___TTT___>::value_);

    		}

    	};

    

    	template <typename ___TTT___>

    	struct ___ddderived_handle_final___<std::reference_wrapper<___TTT___>> final

    		: ___ddderived_handle_final___<___TTT___&>

    	{

    		inline ___ddderived_handle_final___(std::reference_wrapper<___TTT___> ref)

    			: ___ddderived_handle_final___<___TTT___&>{ ref.get() }

    		{}

    	};

    

    	inline ___ddderived_handle_base___ const& read() const noexcept

    	{

    		return *std::static_pointer_cast<___ddderived_handle_base___ const>(handle_);

    	}

    

    	inline ___ddderived_handle_base___& write() noexcept

    	{

    		if (!handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___ddderived_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___>

    	friend inline bool check(random_access_const_iterator_a<> const& value) noexcept;

    

    public:

    	static inline bool ___check___(___SHARED___ const& handle) noexcept

    	{

    		return bool(std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));

    	}

    

    	inline random_access_const_iterator_a() = default;

    

    	static inline random_access_const_iterator_a val(random_access_const_iterator_a const& other) noexcept

    	{

    		return random_access_const_iterator_a{ other };

    	}

    /*

    	inline random_access_const_iterator_a(random_access_const_iterator_a const& other, bool reference) noexcept

    		: ___derived___(other, reference)

    	{}

    */

    	inline random_access_const_iterator_a(random_access_const_iterator_a& other, ___reference_tag___) noexcept

    		: ___derived___(other, ___reference_tag___{})

    	{}

    

    	static inline random_access_const_iterator_a ref(random_access_const_iterator_a& other) noexcept

    	{

    		return random_access_const_iterator_a(other, ___reference_tag___{});

    	}

    

    	inline random_access_const_iterator_a(random_access_const_iterator_a& other, ___duplicate_tag___) noexcept

    		: ___derived___(other, ___duplicate_tag___{})

    	{}

    

    	static inline random_access_const_iterator_a dup(random_access_const_iterator_a& other) noexcept

    	{

    		return random_access_const_iterator_a(other, ___duplicate_tag___{});

    	}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline random_access_const_iterator_a(std::shared_ptr<___TTT___> const& handle)

    		: ___derived___{ handle }

    	{

    		if (handle && !std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))

    		{

    			throw dis("random_access_const_iterator_a constructor failed to cast from base to ddderived");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline random_access_const_iterator_a(std::shared_ptr<___TTT___> const& handle) noexcept

    		: ___derived___{ handle }

    	{

    		assert(!handle || std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));

    	}

    #endif

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline random_access_const_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)

    		: ___derived___(handle, ___reference_tag___{})

    	{

    		if (handle && !std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))

    		{

    			throw dis("random_access_const_iterator_a constructor failed to cast from base to ddderived");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline random_access_const_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept

    		: ___derived___(handle, ___reference_tag___{})

    	{

    		assert(!handle || std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_const_iterator_a, std::decay_t<___TTT___>>::value>>

    	explicit inline random_access_const_iterator_a(___TTT___ value) noexcept

    		: ___derived___{ std::make_shared<___ddderived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }

    	{

    		handle_->___weak___(handle_);

    	}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	inline random_access_const_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    		if (handle && !std::dynamic_pointer_cast<___ddderived_handle_base___>(handle))

    		{

    			throw dis("random_access_const_iterator_a assignment failed to cast from base to ddderived");

    		}

    		handle_ = handle;

    		return *this;

    	}

    #else

    	template <typename ___TTT___>

    	inline random_access_const_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept

    	{

    		assert(!handle || std::dynamic_pointer_cast<___ddderived_handle_base___>(handle));

    		handle_ = handle;

    		return *this;

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_const_iterator_a, std::decay_t<___TTT___>>::value>>

    	inline random_access_const_iterator_a& operator=(___TTT___ value) noexcept

    	{

    		random_access_const_iterator_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		return *this;

    	}

    

    private:

    	static bool const ___share___;

    	friend class ___random_access_const_iterator_a_share___;

    };

    

    template <typename ___TTT___>

    inline bool check(random_access_const_iterator_a<> const& value) noexcept

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    template <typename ___1___>

    bool const random_access_const_iterator_a<___1___>::___share___ = []()

    {

    	auto& shoal = shared();

    	reflection<random_access_const_iterator_a<___1___>>::share(shoal);

    	return shoal.something();

    }();

    

    #undef ___derived___

}
#endif
