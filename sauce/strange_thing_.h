#ifndef COM_ONEISH_STRANGE_THING__H
#define COM_ONEISH_STRANGE_THING__H

// # include "definitions.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    
    class thing_

    {

    public:

    	inline operator bool() const

    	{

    		assert(handle_); return read().operator bool();

    	}

    

    	inline thing_& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline thing_ operator++(int)

    	{

    		assert(handle_);

    		thing_ result = *this;

    		write().operator++();

    		return result;

    	}

    

     inline thing_ val ( thing_ range ) const
     { assert(handle_); return read().val(range ); }
     inline thing_ ref ( thing_ range ) const
     { assert(handle_); return read().ref(range ); }
     inline thing_ extract ( thing_ range ) const
     { assert(handle_); return read().extract(range ); }
     inline thing_ operator ( ) ( const void * identity , thing_ range ) const
     { assert(handle_); return read().operator()(identity, range ); }
     inline thing_ mutate ( thing_ range )
     { assert(handle_); return write().mutate(range ); }
     inline thing_ operator ( ) ( void * identity , thing_ range ) const
     { assert(handle_); return read().operator()(identity, range ); }
     inline const void * identity__ ( ) const
     { assert(handle_); return read().identity__( ); }
     inline thing_ identical ( thing_ range ) const
     { assert(handle_); return read().identical(range ); }
     inline thing_ identical_ ( thing_ thing ) const
     { assert(handle_); return read().identical_(thing ); }
     inline bool identical__ ( thing_ thing ) const
     { assert(handle_); return read().identical__(thing ); }
     inline thing_ same ( thing_ range ) const
     { assert(handle_); return read().same(range ); }
     inline thing_ same_ ( thing_ thing ) const
     { assert(handle_); return read().same_(thing ); }
     inline bool operator == ( thing_ thing ) const
     { assert(handle_); return read().operator==(thing ); }
     inline thing_ different ( thing_ range ) const
     { assert(handle_); return read().different(range ); }
     inline thing_ different_ ( thing_ thing ) const
     { assert(handle_); return read().different_(thing ); }
     inline bool operator != ( thing_ thing ) const
     { assert(handle_); return read().operator!=(thing ); }
     inline thing_ hash ( thing_ _ ) const
     { assert(handle_); return read().hash(_ ); }
     inline thing_ hash_ ( ) const
     { assert(handle_); return read().hash_( ); }
     inline std :: size_t hash__ ( ) const
     { assert(handle_); return read().hash__( ); }
     inline thing_ nothing ( thing_ _ ) const
     { assert(handle_); return read().nothing(_ ); }
     inline thing_ nothing_ ( ) const
     { assert(handle_); return read().nothing_( ); }
     inline bool nothing__ ( ) const
     { assert(handle_); return read().nothing__( ); }
     inline thing_ anything ( thing_ _ ) const
     { assert(handle_); return read().anything(_ ); }
     inline thing_ anything_ ( ) const
     { assert(handle_); return read().anything_( ); }
     inline bool anything__ ( ) const
     { assert(handle_); return read().anything__( ); }
     inline thing_ something ( thing_ _ ) const
     { assert(handle_); return read().something(_ ); }
     inline thing_ something_ ( ) const
     { assert(handle_); return read().something_( ); }
     inline bool something__ ( ) const
     { assert(handle_); return read().something__( ); }
     inline thing_ everything ( thing_ _ ) const
     { assert(handle_); return read().everything(_ ); }
     inline thing_ everything_ ( ) const
     { assert(handle_); return read().everything_( ); }
     inline bool everything__ ( ) const
     { assert(handle_); return read().everything__( ); }
     inline bool is__ ( const std :: string & s ) const
     { assert(handle_); return read().is__(s ); }
     inline thing_ beget ( thing_ _ ) const
     { assert(handle_); return read().beget(_ ); }
     inline thing_ beget_ ( ) const
     { assert(handle_); return read().beget_( ); }
     inline thing_ cbegin ( ) const
     { assert(handle_); return read().cbegin( ); }
     inline thing_ beset ( thing_ _ )
     { assert(handle_); return write().beset(_ ); }
     inline thing_ beset_ ( )
     { assert(handle_); return write().beset_( ); }
     inline thing_ begin ( )
     { assert(handle_); return write().begin( ); }
     inline thing_ enget ( thing_ _ ) const
     { assert(handle_); return read().enget(_ ); }
     inline thing_ enget_ ( ) const
     { assert(handle_); return read().enget_( ); }
     inline thing_ cend ( ) const
     { assert(handle_); return read().cend( ); }
     inline thing_ enset ( thing_ _ )
     { assert(handle_); return write().enset(_ ); }
     inline thing_ enset_ ( )
     { assert(handle_); return write().enset_( ); }
     inline thing_ end ( )
     { assert(handle_); return write().end( ); }
     inline thing_ get ( thing_ _ ) const
     { assert(handle_); return read().get(_ ); }
     inline thing_ get_ ( ) const
     { assert(handle_); return read().get_( ); }
     inline thing_ set ( thing_ range ) const
     { assert(handle_); return read().set(range ); }
     inline thing_ set_ ( thing_ thing ) const
     { assert(handle_); return read().set_(thing ); }
     inline thing_ & operator * ( ) const
     { assert(handle_); return read().operator*( ); }
     inline thing_ * operator -> ( ) const
     { assert(handle_); return read().operator->( ); }
     inline thing_ increment ( thing_ _ )
     { assert(handle_); return write().increment(_ ); }
     inline thing_ increment_ ( )
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

    

      virtual inline thing_ val ( thing_ range ) const = 0;
      virtual inline thing_ ref ( thing_ range ) const = 0;
      virtual inline thing_ extract ( thing_ range ) const = 0;
      virtual inline thing_ operator ( ) ( const void * identity , thing_ range ) const = 0;
      virtual inline thing_ mutate ( thing_ range ) = 0;
      virtual inline thing_ operator ( ) ( void * identity , thing_ range ) const = 0;
      virtual inline const void * identity__ ( ) const = 0;
      virtual inline thing_ identical ( thing_ range ) const = 0;
      virtual inline thing_ identical_ ( thing_ thing ) const = 0;
      virtual inline bool identical__ ( thing_ thing ) const = 0;
      virtual inline thing_ same ( thing_ range ) const = 0;
      virtual inline thing_ same_ ( thing_ thing ) const = 0;
      virtual inline bool operator == ( thing_ thing ) const = 0;
      virtual inline thing_ different ( thing_ range ) const = 0;
      virtual inline thing_ different_ ( thing_ thing ) const = 0;
      virtual inline bool operator != ( thing_ thing ) const = 0;
      virtual inline thing_ hash ( thing_ _ ) const = 0;
      virtual inline thing_ hash_ ( ) const = 0;
      virtual inline std :: size_t hash__ ( ) const = 0;
      virtual inline thing_ nothing ( thing_ _ ) const = 0;
      virtual inline thing_ nothing_ ( ) const = 0;
      virtual inline bool nothing__ ( ) const = 0;
      virtual inline thing_ anything ( thing_ _ ) const = 0;
      virtual inline thing_ anything_ ( ) const = 0;
      virtual inline bool anything__ ( ) const = 0;
      virtual inline thing_ something ( thing_ _ ) const = 0;
      virtual inline thing_ something_ ( ) const = 0;
      virtual inline bool something__ ( ) const = 0;
      virtual inline thing_ everything ( thing_ _ ) const = 0;
      virtual inline thing_ everything_ ( ) const = 0;
      virtual inline bool everything__ ( ) const = 0;
      virtual inline bool is__ ( const std :: string & s ) const = 0;
      virtual inline thing_ beget ( thing_ _ ) const = 0;
      virtual inline thing_ beget_ ( ) const = 0;
      virtual inline thing_ cbegin ( ) const = 0;
      virtual inline thing_ beset ( thing_ _ ) = 0;
      virtual inline thing_ beset_ ( ) = 0;
      virtual inline thing_ begin ( ) = 0;
      virtual inline thing_ enget ( thing_ _ ) const = 0;
      virtual inline thing_ enget_ ( ) const = 0;
      virtual inline thing_ cend ( ) const = 0;
      virtual inline thing_ enset ( thing_ _ ) = 0;
      virtual inline thing_ enset_ ( ) = 0;
      virtual inline thing_ end ( ) = 0;
      virtual inline thing_ get ( thing_ _ ) const = 0;
      virtual inline thing_ get_ ( ) const = 0;
      virtual inline thing_ set ( thing_ range ) const = 0;
      virtual inline thing_ set_ ( thing_ thing ) const = 0;
      virtual inline thing_ & operator * ( ) const = 0;
      virtual inline thing_ * operator -> ( ) const = 0;
      virtual inline thing_ increment ( thing_ _ ) = 0;
      virtual inline thing_ increment_ ( ) = 0;
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

    

      virtual inline thing_ val ( thing_ range ) const
      { return value_.val(range ); }
      virtual inline thing_ ref ( thing_ range ) const
      { return value_.ref(range ); }
      virtual inline thing_ extract ( thing_ range ) const
      { return value_.extract(range ); }
      virtual inline thing_ operator ( ) ( const void * identity , thing_ range ) const
      { return value_.operator()(identity, range ); }
      virtual inline thing_ mutate ( thing_ range )
      { return value_.mutate(range ); }
      virtual inline thing_ operator ( ) ( void * identity , thing_ range ) const
      { return value_.operator()(identity, range ); }
      virtual inline const void * identity__ ( ) const
      { return value_.identity__( ); }
      virtual inline thing_ identical ( thing_ range ) const
      { return value_.identical(range ); }
      virtual inline thing_ identical_ ( thing_ thing ) const
      { return value_.identical_(thing ); }
      virtual inline bool identical__ ( thing_ thing ) const
      { return value_.identical__(thing ); }
      virtual inline thing_ same ( thing_ range ) const
      { return value_.same(range ); }
      virtual inline thing_ same_ ( thing_ thing ) const
      { return value_.same_(thing ); }
      virtual inline bool operator == ( thing_ thing ) const
      { return value_.operator==(thing ); }
      virtual inline thing_ different ( thing_ range ) const
      { return value_.different(range ); }
      virtual inline thing_ different_ ( thing_ thing ) const
      { return value_.different_(thing ); }
      virtual inline bool operator != ( thing_ thing ) const
      { return value_.operator!=(thing ); }
      virtual inline thing_ hash ( thing_ _ ) const
      { return value_.hash(_ ); }
      virtual inline thing_ hash_ ( ) const
      { return value_.hash_( ); }
      virtual inline std :: size_t hash__ ( ) const
      { return value_.hash__( ); }
      virtual inline thing_ nothing ( thing_ _ ) const
      { return value_.nothing(_ ); }
      virtual inline thing_ nothing_ ( ) const
      { return value_.nothing_( ); }
      virtual inline bool nothing__ ( ) const
      { return value_.nothing__( ); }
      virtual inline thing_ anything ( thing_ _ ) const
      { return value_.anything(_ ); }
      virtual inline thing_ anything_ ( ) const
      { return value_.anything_( ); }
      virtual inline bool anything__ ( ) const
      { return value_.anything__( ); }
      virtual inline thing_ something ( thing_ _ ) const
      { return value_.something(_ ); }
      virtual inline thing_ something_ ( ) const
      { return value_.something_( ); }
      virtual inline bool something__ ( ) const
      { return value_.something__( ); }
      virtual inline thing_ everything ( thing_ _ ) const
      { return value_.everything(_ ); }
      virtual inline thing_ everything_ ( ) const
      { return value_.everything_( ); }
      virtual inline bool everything__ ( ) const
      { return value_.everything__( ); }
      virtual inline bool is__ ( const std :: string & s ) const
      { return value_.is__(s ); }
      virtual inline thing_ beget ( thing_ _ ) const
      { return value_.beget(_ ); }
      virtual inline thing_ beget_ ( ) const
      { return value_.beget_( ); }
      virtual inline thing_ cbegin ( ) const
      { return value_.cbegin( ); }
      virtual inline thing_ beset ( thing_ _ )
      { return value_.beset(_ ); }
      virtual inline thing_ beset_ ( )
      { return value_.beset_( ); }
      virtual inline thing_ begin ( )
      { return value_.begin( ); }
      virtual inline thing_ enget ( thing_ _ ) const
      { return value_.enget(_ ); }
      virtual inline thing_ enget_ ( ) const
      { return value_.enget_( ); }
      virtual inline thing_ cend ( ) const
      { return value_.cend( ); }
      virtual inline thing_ enset ( thing_ _ )
      { return value_.enset(_ ); }
      virtual inline thing_ enset_ ( )
      { return value_.enset_( ); }
      virtual inline thing_ end ( )
      { return value_.end( ); }
      virtual inline thing_ get ( thing_ _ ) const
      { return value_.get(_ ); }
      virtual inline thing_ get_ ( ) const
      { return value_.get_( ); }
      virtual inline thing_ set ( thing_ range ) const
      { return value_.set(range ); }
      virtual inline thing_ set_ ( thing_ thing ) const
      { return value_.set_(thing ); }
      virtual inline thing_ & operator * ( ) const
      { return value_.operator*( ); }
      virtual inline thing_ * operator -> ( ) const
      { return value_.operator->( ); }
      virtual inline thing_ increment ( thing_ _ )
      { return value_.increment(_ ); }
      virtual inline thing_ increment_ ( )
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

    	friend inline bool check_(const thing_& value);

    

    	template <typename ___TTT___>

    	friend inline ___TTT___ cast_(const thing_& value, bool reference = false);

    

    public:

    	using ___WEAK___ = std::weak_ptr<___root_handle_base___>;

    

    	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>&)

    	{

    		return true;

    	}

    

    	inline thing_()

    		: handle_{}

    		, ___reference___{ false }

    	{}

    

    	explicit inline thing_(bool reference)

    		: handle_{}

    		, ___reference___{ reference }

    	{}

    

    	inline thing_(const thing_& other)

    		: handle_{ other.handle_ }

    		, ___reference___{ false }

    	{

    		handle_->___weak___(handle_);

    	}

    

    	inline thing_(const thing_& other, bool reference)

    		: handle_{ other.handle_ }

    		, ___reference___{ reference }

    	{

    		handle_->___weak___(handle_);

    	}

    

    	inline thing_(thing_&& other)

    		: handle_{ std::move(other.handle_) }

    		, ___reference___{ false }

    	{

    		handle_->___weak___(handle_);

    	}

    

    	inline thing_(thing_&& other, bool reference)

    		: handle_{ std::move(other.handle_) }

    		, ___reference___{ reference }

    	{

    		handle_->___weak___(handle_);

    	}

    

    	inline thing_& operator=(const thing_& other)

    	{

    		handle_ = other.handle_;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	inline thing_& operator=(thing_&& other)

    	{

    		handle_ = std::move(other.handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	virtual ~thing_() = default;

    

    	template <typename ___TTT___>

    	explicit inline thing_(const std::shared_ptr<___TTT___>& handle, bool reference = false)

    		: handle_{ handle }

    		, ___reference___{ reference }

    	{

    		handle_->___weak___(handle_);

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<thing_, ___TTT___>::value>>

    	explicit inline thing_(___TTT___ value, bool reference = false);

    

    	template <typename ___TTT___>

    	inline thing_& operator=(const std::shared_ptr<___TTT___>& handle)

    	{

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<thing_, ___TTT___>::value>>

    	inline thing_& operator=(___TTT___ value);

    };

    

    template <typename ___TTT___>

    inline bool check_(const thing_& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    template <typename ___TTT___, typename ___VVV___>

    inline bool check_(const ___VVV___&)

    {

    	return false;

    }

    

    template <typename ___TTT___>

    inline ___TTT___ cast_(const thing_& value, bool reference)

    {

    	return ___TTT___(value.handle_, reference);

    }

    

    template <typename ___TTT___, typename>

    inline thing_::thing_(___TTT___ value, bool reference)

    	: handle_{ std::make_shared<___root_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }

    	, ___reference___{ reference }

    {

    	handle_->___weak___(handle_);

    }

    

    template <typename ___TTT___, typename>

    inline thing_& thing_::operator=(___TTT___ value)

    {

    	thing_ temp{ std::move(value) };

    	std::swap(temp.handle_, handle_);

    	handle_->___weak___(handle_);

    	return *this;

    }

    

}
#endif
