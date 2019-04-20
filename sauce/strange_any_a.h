#ifndef COM_ONEISH_STRANGE_ANY_A_H
#define COM_ONEISH_STRANGE_ANY_A_H

// # include "definitions.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    
    class any_a

    {

    public:

    	inline operator bool() const

    	{

    		assert(handle_); return read().operator bool();

    	}

    

    	inline any_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline any_a operator++(int)

    	{

    		assert(handle_);

    		any_a result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline any_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline any_a operator--(int)

    	{

    		assert(handle_);

    		any_a result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline any_a& operator+=(any_a other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline any_a& operator-=(any_a other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline any_a& operator*=(any_a other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline any_a& operator/=(any_a other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline any_a& operator%=(any_a other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline any_a val ( any_a range ) const
     { assert(handle_); return read().val(range ); }
     inline any_a ref ( any_a range ) const
     { assert(handle_); return read().ref(range ); }
     inline any_a type ( any_a _ ) const
     { assert(handle_); return read().type(_ ); }
     inline any_a type_ ( ) const
     { assert(handle_); return read().type_( ); }
     inline any_a cat ( any_a _ ) const
     { assert(handle_); return read().cat(_ ); }
     inline any_a cat_ ( ) const
     { assert(handle_); return read().cat_( ); }
     inline any_a eater ( any_a _ ) const
     { assert(handle_); return read().eater(_ ); }
     inline any_a eater_ ( ) const
     { assert(handle_); return read().eater_( ); }
     inline any_a feeder ( any_a range ) const
     { assert(handle_); return read().feeder(range ); }
     inline any_a visit ( any_a range )
     { assert(handle_); return write().visit(range ); }
     inline any_a invoke ( any_a range ) const
     { assert(handle_); return read().invoke(range ); }
     inline any_a invoke_ ( any_a member , any_a range ) const
     { assert(handle_); return read().invoke_(member, range ); }
     inline any_a operate ( any_a range ) const
     { assert(handle_); return read().operate(range ); }
     inline any_a operate_ ( any_a thing , any_a operation , any_a range ) const
     { assert(handle_); return read().operate_(thing, operation, range ); }
     inline any_a operator ( ) ( any_a thing , any_a range ) const
     { assert(handle_); return read().operator()(thing, range ); }
     inline const void * identity__ ( ) const
     { assert(handle_); return read().identity__( ); }
     inline any_a identical ( any_a range ) const
     { assert(handle_); return read().identical(range ); }
     inline any_a identical_ ( any_a thing ) const
     { assert(handle_); return read().identical_(thing ); }
     inline bool identical__ ( any_a thing ) const
     { assert(handle_); return read().identical__(thing ); }
     inline any_a nothing ( any_a _ ) const
     { assert(handle_); return read().nothing(_ ); }
     inline any_a nothing_ ( ) const
     { assert(handle_); return read().nothing_( ); }
     inline bool nothing__ ( ) const
     { assert(handle_); return read().nothing__( ); }
     inline any_a anything ( any_a _ ) const
     { assert(handle_); return read().anything(_ ); }
     inline any_a anything_ ( ) const
     { assert(handle_); return read().anything_( ); }
     inline bool anything__ ( ) const
     { assert(handle_); return read().anything__( ); }
     inline any_a something ( any_a _ ) const
     { assert(handle_); return read().something(_ ); }
     inline any_a something_ ( ) const
     { assert(handle_); return read().something_( ); }
     inline bool something__ ( ) const
     { assert(handle_); return read().something__( ); }
     inline any_a everything ( any_a _ ) const
     { assert(handle_); return read().everything(_ ); }
     inline any_a everything_ ( ) const
     { assert(handle_); return read().everything_( ); }
     inline bool everything__ ( ) const
     { assert(handle_); return read().everything__( ); }
     inline any_a same ( any_a range ) const
     { assert(handle_); return read().same(range ); }
     inline any_a same_ ( any_a thing ) const
     { assert(handle_); return read().same_(thing ); }
     inline bool operator == ( any_a thing ) const
     { assert(handle_); return read().operator==(thing ); }
     inline any_a different ( any_a range ) const
     { assert(handle_); return read().different(range ); }
     inline any_a different_ ( any_a thing ) const
     { assert(handle_); return read().different_(thing ); }
     inline bool operator != ( any_a thing ) const
     { assert(handle_); return read().operator!=(thing ); }
     inline any_a hash ( any_a _ ) const
     { assert(handle_); return read().hash(_ ); }
     inline any_a hash_ ( ) const
     { assert(handle_); return read().hash_( ); }
     inline std :: size_t hash__ ( ) const
     { assert(handle_); return read().hash__( ); }
     inline bool is__ ( const std :: string & s ) const
     { assert(handle_); return read().is__(s ); }
     inline any_a beget ( any_a _ ) const
     { assert(handle_); return read().beget(_ ); }
     inline any_a beget_ ( ) const
     { assert(handle_); return read().beget_( ); }
     inline any_a cbegin ( ) const
     { assert(handle_); return read().cbegin( ); }
     inline any_a beset ( any_a _ )
     { assert(handle_); return write().beset(_ ); }
     inline any_a beset_ ( )
     { assert(handle_); return write().beset_( ); }
     inline any_a begin ( )
     { assert(handle_); return write().begin( ); }
     inline any_a enget ( any_a _ ) const
     { assert(handle_); return read().enget(_ ); }
     inline any_a enget_ ( ) const
     { assert(handle_); return read().enget_( ); }
     inline any_a cend ( ) const
     { assert(handle_); return read().cend( ); }
     inline any_a enset ( any_a _ )
     { assert(handle_); return write().enset(_ ); }
     inline any_a enset_ ( )
     { assert(handle_); return write().enset_( ); }
     inline any_a end ( )
     { assert(handle_); return write().end( ); }
     inline any_a get ( any_a _ ) const
     { assert(handle_); return read().get(_ ); }
     inline any_a get_ ( ) const
     { assert(handle_); return read().get_( ); }
     inline any_a set ( any_a range ) const
     { assert(handle_); return read().set(range ); }
     inline any_a set_ ( any_a thing ) const
     { assert(handle_); return read().set_(thing ); }
     inline any_a & operator * ( ) const
     { assert(handle_); return read().operator*( ); }
     inline any_a * operator -> ( ) const
     { assert(handle_); return read().operator->( ); }
     inline any_a increment ( any_a _ )
     { assert(handle_); return write().increment(_ ); }
     inline any_a increment_ ( )
     { assert(handle_); return write().increment_( ); }
    

    protected:

    	struct ___root_handle_base___

    	{

    		___root_handle_base___() = default;

    		___root_handle_base___(const ___root_handle_base___&) = default;

    		___root_handle_base___(___root_handle_base___&&) = default;

    		___root_handle_base___& operator=(const ___root_handle_base___&) = default;

    		___root_handle_base___& operator=(___root_handle_base___&&) = default;

    		virtual ~___root_handle_base___() = default;

    

    		virtual std::shared_ptr<___root_handle_base___> ___clone___() const = 0;

    

    		virtual void ___weak___(const std::weak_ptr<___root_handle_base___>& weak) const = 0;

    

    		virtual inline operator bool() const = 0;

    

    		virtual inline void operator++() = 0;

    

    		virtual inline void operator--() = 0;

    

    		virtual inline void operator+=(any_a other) = 0;

    

    		virtual inline void operator-=(any_a other) = 0;

    

    		virtual inline void operator*=(any_a other) = 0;

    

    		virtual inline void operator/=(any_a other) = 0;

    

    		virtual inline void operator%=(any_a other) = 0;

    

      virtual inline any_a val ( any_a range ) const = 0;
      virtual inline any_a ref ( any_a range ) const = 0;
      virtual inline any_a type ( any_a _ ) const = 0;
      virtual inline any_a type_ ( ) const = 0;
      virtual inline any_a cat ( any_a _ ) const = 0;
      virtual inline any_a cat_ ( ) const = 0;
      virtual inline any_a eater ( any_a _ ) const = 0;
      virtual inline any_a eater_ ( ) const = 0;
      virtual inline any_a feeder ( any_a range ) const = 0;
      virtual inline any_a visit ( any_a range ) = 0;
      virtual inline any_a invoke ( any_a range ) const = 0;
      virtual inline any_a invoke_ ( any_a member , any_a range ) const = 0;
      virtual inline any_a operate ( any_a range ) const = 0;
      virtual inline any_a operate_ ( any_a thing , any_a operation , any_a range ) const = 0;
      virtual inline any_a operator ( ) ( any_a thing , any_a range ) const = 0;
      virtual inline const void * identity__ ( ) const = 0;
      virtual inline any_a identical ( any_a range ) const = 0;
      virtual inline any_a identical_ ( any_a thing ) const = 0;
      virtual inline bool identical__ ( any_a thing ) const = 0;
      virtual inline any_a nothing ( any_a _ ) const = 0;
      virtual inline any_a nothing_ ( ) const = 0;
      virtual inline bool nothing__ ( ) const = 0;
      virtual inline any_a anything ( any_a _ ) const = 0;
      virtual inline any_a anything_ ( ) const = 0;
      virtual inline bool anything__ ( ) const = 0;
      virtual inline any_a something ( any_a _ ) const = 0;
      virtual inline any_a something_ ( ) const = 0;
      virtual inline bool something__ ( ) const = 0;
      virtual inline any_a everything ( any_a _ ) const = 0;
      virtual inline any_a everything_ ( ) const = 0;
      virtual inline bool everything__ ( ) const = 0;
      virtual inline any_a same ( any_a range ) const = 0;
      virtual inline any_a same_ ( any_a thing ) const = 0;
      virtual inline bool operator == ( any_a thing ) const = 0;
      virtual inline any_a different ( any_a range ) const = 0;
      virtual inline any_a different_ ( any_a thing ) const = 0;
      virtual inline bool operator != ( any_a thing ) const = 0;
      virtual inline any_a hash ( any_a _ ) const = 0;
      virtual inline any_a hash_ ( ) const = 0;
      virtual inline std :: size_t hash__ ( ) const = 0;
      virtual inline bool is__ ( const std :: string & s ) const = 0;
      virtual inline any_a beget ( any_a _ ) const = 0;
      virtual inline any_a beget_ ( ) const = 0;
      virtual inline any_a cbegin ( ) const = 0;
      virtual inline any_a beset ( any_a _ ) = 0;
      virtual inline any_a beset_ ( ) = 0;
      virtual inline any_a begin ( ) = 0;
      virtual inline any_a enget ( any_a _ ) const = 0;
      virtual inline any_a enget_ ( ) const = 0;
      virtual inline any_a cend ( ) const = 0;
      virtual inline any_a enset ( any_a _ ) = 0;
      virtual inline any_a enset_ ( ) = 0;
      virtual inline any_a end ( ) = 0;
      virtual inline any_a get ( any_a _ ) const = 0;
      virtual inline any_a get_ ( ) const = 0;
      virtual inline any_a set ( any_a range ) const = 0;
      virtual inline any_a set_ ( any_a thing ) const = 0;
      virtual inline any_a & operator * ( ) const = 0;
      virtual inline any_a * operator -> ( ) const = 0;
      virtual inline any_a increment ( any_a _ ) = 0;
      virtual inline any_a increment_ ( ) = 0;
    	};

    

    	template <typename ___TTT___, typename ___BHB___ = ___root_handle_base___>

    	struct ___root_handle___ : ___BHB___

    	{

    		template <typename ___UUU___ = ___TTT___>

    		inline ___root_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)

    			: value_{ value }

    		{}

    

    		template <typename ___UUU___ = ___TTT___>

    		inline ___root_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept

    			: value_{ std::move(value) }

    		{}

    

    		virtual inline void ___weak___(const std::weak_ptr<___root_handle_base___>& weak) const final

    		{

    			value_.___weak___(weak);

    		}

    

    		virtual inline operator bool() const final

    		{

    			return value_.operator bool();

    		}

    

    		virtual inline void operator++() final

    		{

    			value_.operator++();

    		}

    

    		virtual inline void operator--() final

    		{

    			value_.operator--();

    		}

    

    		virtual inline void operator+=(any_a other) final

    		{

    			value_.operator+=(other);

    		}

    

    		virtual inline void operator-=(any_a other) final

    		{

    			value_.operator-=(other);

    		}

    

    		virtual inline void operator*=(any_a other) final

    		{

    			value_.operator*=(other);

    		}

    

    		virtual inline void operator/=(any_a other) final

    		{

    			value_.operator/=(other);

    		}

    

    		virtual inline void operator%=(any_a other) final

    		{

    			value_.operator%=(other);

    		}

    

      virtual inline any_a val ( any_a range ) const
      { return value_.val(range ); }
      virtual inline any_a ref ( any_a range ) const
      { return value_.ref(range ); }
      virtual inline any_a type ( any_a _ ) const
      { return value_.type(_ ); }
      virtual inline any_a type_ ( ) const
      { return value_.type_( ); }
      virtual inline any_a cat ( any_a _ ) const
      { return value_.cat(_ ); }
      virtual inline any_a cat_ ( ) const
      { return value_.cat_( ); }
      virtual inline any_a eater ( any_a _ ) const
      { return value_.eater(_ ); }
      virtual inline any_a eater_ ( ) const
      { return value_.eater_( ); }
      virtual inline any_a feeder ( any_a range ) const
      { return value_.feeder(range ); }
      virtual inline any_a visit ( any_a range )
      { return value_.visit(range ); }
      virtual inline any_a invoke ( any_a range ) const
      { return value_.invoke(range ); }
      virtual inline any_a invoke_ ( any_a member , any_a range ) const
      { return value_.invoke_(member, range ); }
      virtual inline any_a operate ( any_a range ) const
      { return value_.operate(range ); }
      virtual inline any_a operate_ ( any_a thing , any_a operation , any_a range ) const
      { return value_.operate_(thing, operation, range ); }
      virtual inline any_a operator ( ) ( any_a thing , any_a range ) const
      { return value_.operator()(thing, range ); }
      virtual inline const void * identity__ ( ) const
      { return value_.identity__( ); }
      virtual inline any_a identical ( any_a range ) const
      { return value_.identical(range ); }
      virtual inline any_a identical_ ( any_a thing ) const
      { return value_.identical_(thing ); }
      virtual inline bool identical__ ( any_a thing ) const
      { return value_.identical__(thing ); }
      virtual inline any_a nothing ( any_a _ ) const
      { return value_.nothing(_ ); }
      virtual inline any_a nothing_ ( ) const
      { return value_.nothing_( ); }
      virtual inline bool nothing__ ( ) const
      { return value_.nothing__( ); }
      virtual inline any_a anything ( any_a _ ) const
      { return value_.anything(_ ); }
      virtual inline any_a anything_ ( ) const
      { return value_.anything_( ); }
      virtual inline bool anything__ ( ) const
      { return value_.anything__( ); }
      virtual inline any_a something ( any_a _ ) const
      { return value_.something(_ ); }
      virtual inline any_a something_ ( ) const
      { return value_.something_( ); }
      virtual inline bool something__ ( ) const
      { return value_.something__( ); }
      virtual inline any_a everything ( any_a _ ) const
      { return value_.everything(_ ); }
      virtual inline any_a everything_ ( ) const
      { return value_.everything_( ); }
      virtual inline bool everything__ ( ) const
      { return value_.everything__( ); }
      virtual inline any_a same ( any_a range ) const
      { return value_.same(range ); }
      virtual inline any_a same_ ( any_a thing ) const
      { return value_.same_(thing ); }
      virtual inline bool operator == ( any_a thing ) const
      { return value_.operator==(thing ); }
      virtual inline any_a different ( any_a range ) const
      { return value_.different(range ); }
      virtual inline any_a different_ ( any_a thing ) const
      { return value_.different_(thing ); }
      virtual inline bool operator != ( any_a thing ) const
      { return value_.operator!=(thing ); }
      virtual inline any_a hash ( any_a _ ) const
      { return value_.hash(_ ); }
      virtual inline any_a hash_ ( ) const
      { return value_.hash_( ); }
      virtual inline std :: size_t hash__ ( ) const
      { return value_.hash__( ); }
      virtual inline bool is__ ( const std :: string & s ) const
      { return value_.is__(s ); }
      virtual inline any_a beget ( any_a _ ) const
      { return value_.beget(_ ); }
      virtual inline any_a beget_ ( ) const
      { return value_.beget_( ); }
      virtual inline any_a cbegin ( ) const
      { return value_.cbegin( ); }
      virtual inline any_a beset ( any_a _ )
      { return value_.beset(_ ); }
      virtual inline any_a beset_ ( )
      { return value_.beset_( ); }
      virtual inline any_a begin ( )
      { return value_.begin( ); }
      virtual inline any_a enget ( any_a _ ) const
      { return value_.enget(_ ); }
      virtual inline any_a enget_ ( ) const
      { return value_.enget_( ); }
      virtual inline any_a cend ( ) const
      { return value_.cend( ); }
      virtual inline any_a enset ( any_a _ )
      { return value_.enset(_ ); }
      virtual inline any_a enset_ ( )
      { return value_.enset_( ); }
      virtual inline any_a end ( )
      { return value_.end( ); }
      virtual inline any_a get ( any_a _ ) const
      { return value_.get(_ ); }
      virtual inline any_a get_ ( ) const
      { return value_.get_( ); }
      virtual inline any_a set ( any_a range ) const
      { return value_.set(range ); }
      virtual inline any_a set_ ( any_a thing ) const
      { return value_.set_(thing ); }
      virtual inline any_a & operator * ( ) const
      { return value_.operator*( ); }
      virtual inline any_a * operator -> ( ) const
      { return value_.operator->( ); }
      virtual inline any_a increment ( any_a _ )
      { return value_.increment(_ ); }
      virtual inline any_a increment_ ( )
      { return value_.increment_( ); }
    

    		___TTT___ value_;

    	};

    

    	template <typename ___TTT___, typename ___BHB___>

    	struct ___root_handle___<std::reference_wrapper<___TTT___>, ___BHB___>

    		: ___root_handle___<___TTT___&, ___BHB___>

    	{

    		inline ___root_handle___(std::reference_wrapper<___TTT___> ref)

    			: ___root_handle___<___TTT___&, ___BHB___>{ ref.get() }

    		{}

    	};

    

    	std::shared_ptr<___root_handle_base___> handle_;

    

    	const bool ___reference___;

    

    private:

    	template <typename ___TTT___>

    	struct ___root_handle_final___ final : ___root_handle___<___TTT___>

    	{

    		template <typename ___UUU___ = ___TTT___>

    		inline ___root_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)

    			: ___root_handle___<___TTT___>{ value }

    		{}

    

    		template <typename ___UUU___ = ___TTT___>

    		inline ___root_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept

    			: ___root_handle___<___TTT___>{ std::move(value) }

    		{}

    

    		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final

    		{

    			return std::make_shared<___root_handle_final___>(___root_handle___<___TTT___>::value_);

    		}

    	};

    

    	template <typename ___TTT___>

    	struct ___root_handle_final___<std::reference_wrapper<___TTT___>> final

    		: ___root_handle_final___<___TTT___&>

    	{

    		inline ___root_handle_final___(std::reference_wrapper<___TTT___> ref)

    			: ___root_handle_final___<___TTT___&>{ ref.get() }

    		{}

    	};

    

    	inline const ___root_handle_base___& read() const

    	{

    		return *handle_;

    	}

    

    	inline ___root_handle_base___& write()

    	{

    		if (!___reference___ && !handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *handle_;

    	}

    

    	template <typename ___TTT___>

    	friend inline bool check_(const any_a& value);

    

    	template <typename ___TTT___>

    	friend inline ___TTT___ cast_(const any_a& value, bool reference = false);

    

    public:

    	using ___WEAK___ = std::weak_ptr<___root_handle_base___>;

    

    	static inline const char* ___abstraction_name___()

    	{

    		return "any";

    	}

    

    	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>&)

    	{

    		return true;

    	}

    

    	inline any_a()

    		: handle_{}

    		, ___reference___{ false }

    	{}

    

    	explicit inline any_a(bool reference)

    		: handle_{}

    		, ___reference___{ reference }

    	{}

    

    	inline any_a(const any_a& other)

    		: handle_{ other.handle_ }

    		, ___reference___{ false }

    	{

    		handle_->___weak___(handle_);

    	}

    

    	inline any_a(const any_a& other, bool reference)

    		: handle_{ other.handle_ }

    		, ___reference___{ reference }

    	{

    		handle_->___weak___(handle_);

    	}

    

    	inline any_a(any_a&& other)

    		: handle_{ std::move(other.handle_) }

    		, ___reference___{ false }

    	{

    		handle_->___weak___(handle_);

    	}

    

    	inline any_a(any_a&& other, bool reference)

    		: handle_{ std::move(other.handle_) }

    		, ___reference___{ reference }

    	{

    		handle_->___weak___(handle_);

    	}

    

    	inline any_a& operator=(const any_a& other)

    	{

    		handle_ = other.handle_;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	inline any_a& operator=(any_a&& other)

    	{

    		handle_ = std::move(other.handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	virtual ~any_a() = default;

    

    	template <typename ___TTT___>

    	explicit inline any_a(const std::shared_ptr<___TTT___>& handle, bool reference = false)

    		: handle_{ handle }

    		, ___reference___{ reference }

    	{

    		handle_->___weak___(handle_);

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<any_a, std::decay_t<___TTT___>>::value>>

    	explicit inline any_a(___TTT___ value, bool reference = false);

    

    	template <typename ___TTT___>

    	inline any_a& operator=(const std::shared_ptr<___TTT___>& handle)

    	{

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<any_a, std::decay_t<___TTT___>>::value>>

    	inline any_a& operator=(___TTT___ value);

    };

    

    template <typename ___TTT___>

    inline bool check_(const any_a& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    template <typename ___TTT___, typename ___VVV___>

    inline bool check_(const ___VVV___&)

    {

    	return false;

    }

    

    template <typename ___TTT___>

    inline ___TTT___ cast_(const any_a& value, bool reference)

    {

    	return ___TTT___(value.handle_, reference);

    }

    

    template <typename ___TTT___, typename>

    inline any_a::any_a(___TTT___ value, bool reference)

    	: handle_{ std::make_shared<___root_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }

    	, ___reference___{ reference }

    {

    	handle_->___weak___(handle_);

    }

    

    template <typename ___TTT___, typename>

    inline any_a& any_a::operator=(___TTT___ value)

    {

    	any_a temp{ std::move(value) };

    	std::swap(temp.handle_, handle_);

    	handle_->___weak___(handle_);

    	return *this;

    }

    

}
#endif
