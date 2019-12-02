#ifndef COM_ONEISH_STRANGE_SYMBOL_A_H
#define COM_ONEISH_STRANGE_SYMBOL_A_H

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
    class symbol_a : public ___root___

    {

    public:

    	inline symbol_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline symbol_a operator++(int)

    	{

    		assert(handle_);

    		symbol_a result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline symbol_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline symbol_a operator--(int)

    	{

    		assert(handle_);

    		symbol_a result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline symbol_a& operator+=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline symbol_a& operator-=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline symbol_a& operator*=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline symbol_a& operator/=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline symbol_a& operator%=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline std :: string const & to_string ( ) const
     { assert(handle_); return read().to_string( ); }
     inline int8_t first_character ( ) const
     { assert(handle_); return read().first_character( ); }
     inline int8_t last_character ( ) const
     { assert(handle_); return read().last_character( ); }
     inline any_a < > add__ ( range_a < > const & range ) const
     { assert(handle_); return read().add__(range ); }
     inline symbol_a add_ ( symbol_a const & symbol ) const
     { assert(handle_); return read().add_(symbol ); }
     inline symbol_a operator + ( symbol_a const & symbol ) const
     { assert(handle_); return read().operator+(symbol ); }
    

    protected:

    	struct ___derived_handle_base___ : ___root_handle_base___

    	{

      virtual inline std :: string const & to_string ( ) const = 0;
      virtual inline int8_t first_character ( ) const = 0;
      virtual inline int8_t last_character ( ) const = 0;
      virtual inline any_a < > add__ ( range_a < > const & range ) const = 0;
      virtual inline symbol_a add_ ( symbol_a const & symbol ) const = 0;
      virtual inline symbol_a operator + ( symbol_a const & symbol ) const = 0;
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

    

      virtual inline std :: string const & to_string ( ) const
      { return value_.to_string( ); }
      virtual inline int8_t first_character ( ) const
      { return value_.first_character( ); }
      virtual inline int8_t last_character ( ) const
      { return value_.last_character( ); }
      virtual inline any_a < > add__ ( range_a < > const & range ) const
      { return value_.add__(range ); }
      virtual inline symbol_a add_ ( symbol_a const & symbol ) const
      { return value_.add_(symbol ); }
      virtual inline symbol_a operator + ( symbol_a const & symbol ) const
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

    

    	inline ___derived_handle_base___ const& read() const noexcept

    	{

    		return *std::static_pointer_cast<___derived_handle_base___ const>(handle_);

    	}

    

    	inline ___derived_handle_base___& write() noexcept

    	{

    		if (!___reference___ && !handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___derived_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___>

    	friend inline bool check(symbol_a<> const& value) noexcept;

    

    public:

    	static inline bool ___check___(std::shared_ptr<___root_handle_base___>const & handle) noexcept

    	{

    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    

    	inline symbol_a() = default;

    

    	explicit inline symbol_a(bool reference) noexcept

    		: ___root___{ reference }

    	{}

    

    	inline symbol_a(symbol_a const& other, bool reference) noexcept

    		: ___root___(other, reference)

    	{}

    

    	inline symbol_a(symbol_a&& other, bool reference) noexcept

    		: ___root___(std::move(other), reference)

    	{}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline symbol_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)

    		: ___root___(handle, reference)

    	{

    		if (handle && !std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis("symbol_a constructor failed to cast from base to derived");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline symbol_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept

    		: ___root___(handle, reference)

    	{

    		assert(!handle || std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<symbol_a, std::decay_t<___TTT___>>::value>>

    	explicit inline symbol_a(___TTT___ value, bool reference = false) noexcept

    		: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{

    		handle_->___weak___(handle_);

    	}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	inline symbol_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    		if (handle && !std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis("symbol_a assignment failed to cast from base to derived");

    		}

    		handle_ = handle;

    		return *this;

    	}

    #else

    	template <typename ___TTT___>

    	inline symbol_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept

    	{

    		assert(!handle || std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    		handle_ = handle;

    		return *this;

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<symbol_a, std::decay_t<___TTT___>>::value>>

    	inline symbol_a& operator=(___TTT___ value) noexcept

    	{

    		symbol_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		return *this;

    	}

    

    private:

    	static bool const ___share___;

    	friend class ___symbol_a_share___;

    };

    

    template <typename ___TTT___>

    inline bool check(symbol_a<> const& value) noexcept

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    template <typename ___1___>

    bool const symbol_a<___1___>::___share___ = []()

    {

    	auto shoal = shoal_a<>(shared(), true);

    	reflection<symbol_a<___1___>>::share(shoal);

    	return shoal;

    }();

    

}
#endif
