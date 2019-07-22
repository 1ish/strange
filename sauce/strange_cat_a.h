#ifndef COM_ONEISH_STRANGE_CAT_A_H
#define COM_ONEISH_STRANGE_CAT_A_H

 //#include "any_forward.hpp"
 //#include "range_forward.hpp"
 //#include "symbol_forward.hpp"
 //#include "flock_forward.hpp"
 //#include "herd_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename lake_a_int8 >
    class cat_a final : public ___derived___

    {

    public:

    	inline cat_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline cat_a operator++(int)

    	{

    		assert(handle_);

    		cat_a result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline cat_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline cat_a operator--(int)

    	{

    		assert(handle_);

    		cat_a result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline cat_a& operator+=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline cat_a& operator-=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline cat_a& operator*=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline cat_a& operator/=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline cat_a& operator%=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline any_a < > symbolic__ ( range_a < > const & _ ) const
     { assert(handle_); return read().symbolic__(_ ); }
     inline any_a < > symbolic_ ( ) const
     { assert(handle_); return read().symbolic_( ); }
     inline bool symbolic ( ) const
     { assert(handle_); return read().symbolic( ); }
     inline any_a < > name__ ( range_a < > const & _ ) const
     { assert(handle_); return read().name__(_ ); }
     inline symbol_a < > name_ ( ) const
     { assert(handle_); return read().name_( ); }
     inline any_a < > args__ ( range_a < > const & _ ) const
     { assert(handle_); return read().args__(_ ); }
     inline flock_a < > args_ ( ) const
     { assert(handle_); return read().args_( ); }
     inline any_a < > params__ ( range_a < > const & _ ) const
     { assert(handle_); return read().params__(_ ); }
     inline flock_a < > params_ ( ) const
     { assert(handle_); return read().params_( ); }
     inline any_a < > result__ ( range_a < > const & _ ) const
     { assert(handle_); return read().result__(_ ); }
     inline cat_a result_ ( ) const
     { assert(handle_); return read().result_( ); }
     inline any_a < > def__ ( range_a < > const & _ ) const
     { assert(handle_); return read().def__(_ ); }
     inline any_a < > def_ ( ) const
     { assert(handle_); return read().def_( ); }
     inline bool def ( ) const
     { assert(handle_); return read().def( ); }
     inline any_a < > ref__ ( range_a < > const & _ ) const
     { assert(handle_); return read().ref__(_ ); }
     inline any_a < > ref_ ( ) const
     { assert(handle_); return read().ref_( ); }
     inline bool ref ( ) const
     { assert(handle_); return read().ref( ); }
     inline any_a < > code__ ( range_a < > const & _ ) const
     { assert(handle_); return read().code__(_ ); }
     inline lake_a_int8 code_ ( ) const
     { assert(handle_); return read().code_( ); }
     inline std :: string code ( ) const
     { assert(handle_); return read().code( ); }
    

    private:

    	struct ___finale_handle_base___ : ___derived_handle_base___

    	{

      virtual inline any_a < > symbolic__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > symbolic_ ( ) const = 0;
      virtual inline bool symbolic ( ) const = 0;
      virtual inline any_a < > name__ ( range_a < > const & _ ) const = 0;
      virtual inline symbol_a < > name_ ( ) const = 0;
      virtual inline any_a < > args__ ( range_a < > const & _ ) const = 0;
      virtual inline flock_a < > args_ ( ) const = 0;
      virtual inline any_a < > params__ ( range_a < > const & _ ) const = 0;
      virtual inline flock_a < > params_ ( ) const = 0;
      virtual inline any_a < > result__ ( range_a < > const & _ ) const = 0;
      virtual inline cat_a result_ ( ) const = 0;
      virtual inline any_a < > def__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > def_ ( ) const = 0;
      virtual inline bool def ( ) const = 0;
      virtual inline any_a < > ref__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > ref_ ( ) const = 0;
      virtual inline bool ref ( ) const = 0;
      virtual inline any_a < > code__ ( range_a < > const & _ ) const = 0;
      virtual inline lake_a_int8 code_ ( ) const = 0;
      virtual inline std :: string code ( ) const = 0;
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

    

      virtual inline any_a < > symbolic__ ( range_a < > const & _ ) const
      { return value_.symbolic__(_ ); }
      virtual inline any_a < > symbolic_ ( ) const
      { return value_.symbolic_( ); }
      virtual inline bool symbolic ( ) const
      { return value_.symbolic( ); }
      virtual inline any_a < > name__ ( range_a < > const & _ ) const
      { return value_.name__(_ ); }
      virtual inline symbol_a < > name_ ( ) const
      { return value_.name_( ); }
      virtual inline any_a < > args__ ( range_a < > const & _ ) const
      { return value_.args__(_ ); }
      virtual inline flock_a < > args_ ( ) const
      { return value_.args_( ); }
      virtual inline any_a < > params__ ( range_a < > const & _ ) const
      { return value_.params__(_ ); }
      virtual inline flock_a < > params_ ( ) const
      { return value_.params_( ); }
      virtual inline any_a < > result__ ( range_a < > const & _ ) const
      { return value_.result__(_ ); }
      virtual inline cat_a result_ ( ) const
      { return value_.result_( ); }
      virtual inline any_a < > def__ ( range_a < > const & _ ) const
      { return value_.def__(_ ); }
      virtual inline any_a < > def_ ( ) const
      { return value_.def_( ); }
      virtual inline bool def ( ) const
      { return value_.def( ); }
      virtual inline any_a < > ref__ ( range_a < > const & _ ) const
      { return value_.ref__(_ ); }
      virtual inline any_a < > ref_ ( ) const
      { return value_.ref_( ); }
      virtual inline bool ref ( ) const
      { return value_.ref( ); }
      virtual inline any_a < > code__ ( range_a < > const & _ ) const
      { return value_.code__(_ ); }
      virtual inline lake_a_int8 code_ ( ) const
      { return value_.code_( ); }
      virtual inline std :: string code ( ) const
      { return value_.code( ); }
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

    		if (!___reference___ && !handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___finale_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___>

    	friend inline bool check(cat_a<> const& value) noexcept;

    

    public:

    	static inline bool ___check___(std::shared_ptr<___root_handle_base___> const& handle) noexcept

    	{

    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    

    	inline cat_a() = default;

    

    	explicit inline cat_a(bool reference) noexcept

    		: ___derived___{ reference }

    	{}

    

    	inline cat_a(cat_a const& other, bool reference) noexcept

    		: ___derived___(other, reference)

    	{}

    

    	inline cat_a(cat_a&& other, bool reference) noexcept

    		: ___derived___(std::move(other), reference)

    	{}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline cat_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)

    		: ___derived___(handle, reference)

    	{

    		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis("cat_a constructor failed to cast from base to final");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline cat_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept

    		: ___derived___(handle, reference)

    	{

    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_a, std::decay_t<___TTT___>>::value>>

    	explicit inline cat_a(___TTT___ value, bool reference = false) noexcept

    		: ___derived___(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	inline cat_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis("cat_a assignment failed to cast from base to final");

    		}

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    #else

    	template <typename ___TTT___>

    	inline cat_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept

    	{

    		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_a, std::decay_t<___TTT___>>::value>>

    	inline cat_a& operator=(___TTT___ value) noexcept

    	{

    		cat_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}


	private:
		static bool const ___share___;
		friend class ___cat_a_share___;
	};

    

    template <typename ___TTT___>

    inline bool check(cat_a<> const& value) noexcept

    {

    	return ___TTT___::___check___(value.handle_);

    }

	template <typename _1_>
	bool const cat_a<_1_>::___share___ = []()
	{
		auto shoal = shoal_a<>(shared(), true);
		reflection<cat_a<_1_>>::share(shoal);
		return shoal;
	}();




    #undef ___derived___

}
#endif
