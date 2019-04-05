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

    

     inline thing_ extract ( thing_ range ) const
     { assert(handle_); return read().extract(range ); }
     inline thing_ operator ( ) ( thing_ range ) const
     { assert(handle_); return read().operator()(range ); }
     inline thing_ mutate ( thing_ range )
     { assert(handle_); return write().mutate(range ); }
     inline thing_ operator ( ) ( thing_ range )
     { assert(handle_); return write().operator()(range ); }
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
     inline thing_ is_something ( thing_ _ ) const
     { assert(handle_); return read().is_something(_ ); }
     inline thing_ is_something_ ( ) const
     { assert(handle_); return read().is_something_( ); }
     inline thing_ is_nothing ( thing_ _ ) const
     { assert(handle_); return read().is_nothing(_ ); }
     inline thing_ is_nothing_ ( ) const
     { assert(handle_); return read().is_nothing_( ); }
     inline thing_ begin_get ( thing_ _ ) const
     { assert(handle_); return read().begin_get(_ ); }
     inline thing_ begin_get_ ( ) const
     { assert(handle_); return read().begin_get_( ); }
     inline thing_ cbegin ( ) const
     { assert(handle_); return read().cbegin( ); }
     inline thing_ begin_set ( thing_ _ )
     { assert(handle_); return write().begin_set(_ ); }
     inline thing_ begin_set_ ( )
     { assert(handle_); return write().begin_set_( ); }
     inline thing_ begin ( )
     { assert(handle_); return write().begin( ); }
     inline thing_ end_get ( thing_ _ ) const
     { assert(handle_); return read().end_get(_ ); }
     inline thing_ end_get_ ( ) const
     { assert(handle_); return read().end_get_( ); }
     inline thing_ cend ( ) const
     { assert(handle_); return read().cend( ); }
     inline thing_ end_set ( thing_ _ )
     { assert(handle_); return write().end_set(_ ); }
     inline thing_ end_set_ ( )
     { assert(handle_); return write().end_set_( ); }
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
     inline thing_ & operator ++ ( )
     { assert(handle_); return write().operator++( ); }
    

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

    

    		virtual inline operator bool() const = 0;

    

      virtual inline thing_ extract ( thing_ range ) const = 0;
      virtual inline thing_ operator ( ) ( thing_ range ) const = 0;
      virtual inline thing_ mutate ( thing_ range ) = 0;
      virtual inline thing_ operator ( ) ( thing_ range ) = 0;
      virtual inline thing_ same ( thing_ range ) const = 0;
      virtual inline thing_ same_ ( thing_ thing ) const = 0;
      virtual inline bool operator == ( thing_ thing ) const = 0;
      virtual inline thing_ different ( thing_ range ) const = 0;
      virtual inline thing_ different_ ( thing_ thing ) const = 0;
      virtual inline bool operator != ( thing_ thing ) const = 0;
      virtual inline thing_ is_something ( thing_ _ ) const = 0;
      virtual inline thing_ is_something_ ( ) const = 0;
      virtual inline thing_ is_nothing ( thing_ _ ) const = 0;
      virtual inline thing_ is_nothing_ ( ) const = 0;
      virtual inline thing_ begin_get ( thing_ _ ) const = 0;
      virtual inline thing_ begin_get_ ( ) const = 0;
      virtual inline thing_ cbegin ( ) const = 0;
      virtual inline thing_ begin_set ( thing_ _ ) = 0;
      virtual inline thing_ begin_set_ ( ) = 0;
      virtual inline thing_ begin ( ) = 0;
      virtual inline thing_ end_get ( thing_ _ ) const = 0;
      virtual inline thing_ end_get_ ( ) const = 0;
      virtual inline thing_ cend ( ) const = 0;
      virtual inline thing_ end_set ( thing_ _ ) = 0;
      virtual inline thing_ end_set_ ( ) = 0;
      virtual inline thing_ end ( ) = 0;
      virtual inline thing_ get ( thing_ _ ) const = 0;
      virtual inline thing_ get_ ( ) const = 0;
      virtual inline thing_ set ( thing_ range ) const = 0;
      virtual inline thing_ set_ ( thing_ thing ) const = 0;
      virtual inline thing_ & operator * ( ) const = 0;
      virtual inline thing_ * operator -> ( ) const = 0;
      virtual inline thing_ increment ( thing_ _ ) = 0;
      virtual inline thing_ increment_ ( ) = 0;
      virtual inline thing_ & operator ++ ( ) = 0;
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

    

    		virtual inline operator bool() const

    		{

    			return value_.operator bool();

    		}

    

      virtual inline thing_ extract ( thing_ range ) const
      { return value_.extract(range ); }
      virtual inline thing_ operator ( ) ( thing_ range ) const
      { return value_.operator()(range ); }
      virtual inline thing_ mutate ( thing_ range )
      { return value_.mutate(range ); }
      virtual inline thing_ operator ( ) ( thing_ range )
      { return value_.operator()(range ); }
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
      virtual inline thing_ is_something ( thing_ _ ) const
      { return value_.is_something(_ ); }
      virtual inline thing_ is_something_ ( ) const
      { return value_.is_something_( ); }
      virtual inline thing_ is_nothing ( thing_ _ ) const
      { return value_.is_nothing(_ ); }
      virtual inline thing_ is_nothing_ ( ) const
      { return value_.is_nothing_( ); }
      virtual inline thing_ begin_get ( thing_ _ ) const
      { return value_.begin_get(_ ); }
      virtual inline thing_ begin_get_ ( ) const
      { return value_.begin_get_( ); }
      virtual inline thing_ cbegin ( ) const
      { return value_.cbegin( ); }
      virtual inline thing_ begin_set ( thing_ _ )
      { return value_.begin_set(_ ); }
      virtual inline thing_ begin_set_ ( )
      { return value_.begin_set_( ); }
      virtual inline thing_ begin ( )
      { return value_.begin( ); }
      virtual inline thing_ end_get ( thing_ _ ) const
      { return value_.end_get(_ ); }
      virtual inline thing_ end_get_ ( ) const
      { return value_.end_get_( ); }
      virtual inline thing_ cend ( ) const
      { return value_.cend( ); }
      virtual inline thing_ end_set ( thing_ _ )
      { return value_.end_set(_ ); }
      virtual inline thing_ end_set_ ( )
      { return value_.end_set_( ); }
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
      virtual inline thing_ & operator ++ ( )
      { return value_.operator++( ); }
    

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

    		}

    		return *handle_;

    	}

    

    	template <typename ___TTT___>

    	friend inline bool check_(const thing_& value);

    

    	template <typename ___TTT___>

    	friend inline ___TTT___ cast_(const thing_& value, bool reference = false);

    

    public:

    	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>&)

    	{

    		return true;

    	}

    

    	inline thing_ (bool reference = false)

    		: handle_{}

    		, ___reference___{ reference }

    	{}

    

    	inline thing_ (const thing_& other)

    		: handle_{ other.handle_ }

    		, ___reference___{ false }

    	{}

    

    	inline thing_ (thing_&& other)

    		: handle_{ std::move(other.handle_) }

    		, ___reference___{ false }

    	{}

    

    	inline thing_& operator=(const thing_& other)

    	{

    		handle_ = other.handle_;

    		return *this;

    	}

    

    	inline thing_& operator=(thing_&& other)

    	{

    		handle_ = std::move(other.handle_);

    		return *this;

    	}

    

    	virtual ~thing_() = default;

    

    	template <typename ___TTT___>

    	inline thing_(const std::shared_ptr<___TTT___>& handle, bool reference = false)

    		: handle_{ handle }

    		, ___reference___{ reference }

    	{}

    

    	template <typename ___TTT___>

    	inline thing_(___TTT___ value, bool reference = false);

    

    	template <typename ___TTT___>

    	inline thing_& operator=(const std::shared_ptr<___TTT___>& handle)

    	{

    		handle_ = handle;

    		return *this;

    	}

    

    	template <typename ___TTT___>

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

    

    template <typename ___TTT___>

    inline thing_::thing_(___TTT___ value, bool reference)

    	: handle_{ check_<thing_>(value)

    		? cast_<thing_>(value).handle_

    		: std::make_shared<___root_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }

    	, ___reference___{ reference }

    {}

    

    template <typename ___TTT___>

    inline thing_& thing_::operator=(___TTT___ value)

    {

    	thing_ temp{ check_<thing_>(value)

    		? cast_<thing_>(value)

    		: std::move(value) };

    	std::swap(temp.handle_, handle_);

    	return *this;

    }

    

}
#endif
