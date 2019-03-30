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

     inline thing_ mutate ( thing_ thing )
     { assert(handle_); return write().mutate(thing ); }
     inline thing_ extract ( thing_ thing ) const
     { assert(handle_); return read().extract(thing ); }
     inline thing_ operator ( ) ( thing_ thing )
     { assert(handle_); return write().operator()(thing ); }
     inline thing_ operator ( ) ( thing_ thing ) const
     { assert(handle_); return read().operator()(thing ); }
     inline thing_ same ( thing_ thing ) const
     { assert(handle_); return read().same(thing ); }
     inline thing_ different ( thing_ thing ) const
     { assert(handle_); return read().different(thing ); }
     inline bool operator == ( thing_ thing ) const
     { assert(handle_); return read().operator==(thing ); }
     inline bool operator != ( thing_ thing ) const
     { assert(handle_); return read().operator!=(thing ); }
     inline thing_ is_something ( thing_ _ = thing_ ( ) ) const
     { assert(handle_); return read().is_something(_ ); }
     inline bool is_something_ ( ) const
     { assert(handle_); return read().is_something_( ); }
     inline thing_ is_nothing ( thing_ _ = thing_ ( ) ) const
     { assert(handle_); return read().is_nothing(_ ); }
     inline bool is_nothing_ ( ) const
     { assert(handle_); return read().is_nothing_( ); }
     inline thing_ begin ( thing_ _ = thing_ ( ) )
     { assert(handle_); return write().begin(_ ); }
     inline thing_ cbegin ( thing_ _ = thing_ ( ) ) const
     { assert(handle_); return read().cbegin(_ ); }
     inline thing_ end ( thing_ _ = thing_ ( ) )
     { assert(handle_); return write().end(_ ); }
     inline thing_ cend ( thing_ _ = thing_ ( ) ) const
     { assert(handle_); return read().cend(_ ); }
     inline thing_ set ( thing_ thing )
     { assert(handle_); return write().set(thing ); }
     inline thing_ get ( thing_ _ = thing_ ( ) ) const
     { assert(handle_); return read().get(_ ); }
     inline thing_ & operator * ( )
     { assert(handle_); return write().operator*( ); }
     inline const thing_ & operator * ( ) const
     { assert(handle_); return read().operator*( ); }
     inline thing_ * operator -> ( )
     { assert(handle_); return write().operator->( ); }
     inline const thing_ * operator -> ( ) const
     { assert(handle_); return read().operator->( ); }
     inline thing_ increment ( thing_ _ = thing_ ( ) )
     { assert(handle_); return write().increment(_ ); }
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

    

      virtual inline thing_ mutate ( thing_ thing ) = 0;
      virtual inline thing_ extract ( thing_ thing ) const = 0;
      virtual inline thing_ operator ( ) ( thing_ thing ) = 0;
      virtual inline thing_ operator ( ) ( thing_ thing ) const = 0;
      virtual inline thing_ same ( thing_ thing ) const = 0;
      virtual inline thing_ different ( thing_ thing ) const = 0;
      virtual inline bool operator == ( thing_ thing ) const = 0;
      virtual inline bool operator != ( thing_ thing ) const = 0;
      virtual inline thing_ is_something ( thing_ _ = thing_ ( ) ) const = 0;
      virtual inline bool is_something_ ( ) const = 0;
      virtual inline thing_ is_nothing ( thing_ _ = thing_ ( ) ) const = 0;
      virtual inline bool is_nothing_ ( ) const = 0;
      virtual inline thing_ begin ( thing_ _ = thing_ ( ) ) = 0;
      virtual inline thing_ cbegin ( thing_ _ = thing_ ( ) ) const = 0;
      virtual inline thing_ end ( thing_ _ = thing_ ( ) ) = 0;
      virtual inline thing_ cend ( thing_ _ = thing_ ( ) ) const = 0;
      virtual inline thing_ set ( thing_ thing ) = 0;
      virtual inline thing_ get ( thing_ _ = thing_ ( ) ) const = 0;
      virtual inline thing_ & operator * ( ) = 0;
      virtual inline const thing_ & operator * ( ) const = 0;
      virtual inline thing_ * operator -> ( ) = 0;
      virtual inline const thing_ * operator -> ( ) const = 0;
      virtual inline thing_ increment ( thing_ _ = thing_ ( ) ) = 0;
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

    

      virtual inline thing_ mutate ( thing_ thing )
      { return value_.mutate(thing ); }
      virtual inline thing_ extract ( thing_ thing ) const
      { return value_.extract(thing ); }
      virtual inline thing_ operator ( ) ( thing_ thing )
      { return value_.operator()(thing ); }
      virtual inline thing_ operator ( ) ( thing_ thing ) const
      { return value_.operator()(thing ); }
      virtual inline thing_ same ( thing_ thing ) const
      { return value_.same(thing ); }
      virtual inline thing_ different ( thing_ thing ) const
      { return value_.different(thing ); }
      virtual inline bool operator == ( thing_ thing ) const
      { return value_.operator==(thing ); }
      virtual inline bool operator != ( thing_ thing ) const
      { return value_.operator!=(thing ); }
      virtual inline thing_ is_something ( thing_ _ = thing_ ( ) ) const
      { return value_.is_something(_ ); }
      virtual inline bool is_something_ ( ) const
      { return value_.is_something_( ); }
      virtual inline thing_ is_nothing ( thing_ _ = thing_ ( ) ) const
      { return value_.is_nothing(_ ); }
      virtual inline bool is_nothing_ ( ) const
      { return value_.is_nothing_( ); }
      virtual inline thing_ begin ( thing_ _ = thing_ ( ) )
      { return value_.begin(_ ); }
      virtual inline thing_ cbegin ( thing_ _ = thing_ ( ) ) const
      { return value_.cbegin(_ ); }
      virtual inline thing_ end ( thing_ _ = thing_ ( ) )
      { return value_.end(_ ); }
      virtual inline thing_ cend ( thing_ _ = thing_ ( ) ) const
      { return value_.cend(_ ); }
      virtual inline thing_ set ( thing_ thing )
      { return value_.set(thing ); }
      virtual inline thing_ get ( thing_ _ = thing_ ( ) ) const
      { return value_.get(_ ); }
      virtual inline thing_ & operator * ( )
      { return value_.operator*( ); }
      virtual inline const thing_ & operator * ( ) const
      { return value_.operator*( ); }
      virtual inline thing_ * operator -> ( )
      { return value_.operator->( ); }
      virtual inline const thing_ * operator -> ( ) const
      { return value_.operator->( ); }
      virtual inline thing_ increment ( thing_ _ = thing_ ( ) )
      { return value_.increment(_ ); }
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

    		if (!handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    		}

    		return *handle_;

    	}

    

    	template <typename ___TTT___>

    	friend inline bool check_(const thing_& v);

    

    	template <typename ___TTT___>

    	friend inline ___TTT___ static_(const thing_& v);

    

    public:

    	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>&)

    	{

    		return true;

    	}

    

    	thing_ () = default;

    	thing_ (const thing_&) = default;

    	thing_ (thing_&&) = default;

    	thing_& operator=(const thing_&) = default;

    	thing_& operator=(thing_&&) = default;

    	virtual ~thing_() = default;

    

    	template <typename ___TTT___>

    	inline thing_(const std::shared_ptr<___TTT___>& other)

    		: handle_{ other }

    	{}

    

    	template <typename ___TTT___>

    	inline thing_(___TTT___ value);

    

    	template <typename ___TTT___>

    	inline thing_& operator=(const std::shared_ptr<___TTT___>& other)

    	{

    		handle_ = other;

    		return *this;

    	}

    

    	template <typename ___TTT___>

    	inline thing_& operator=(___TTT___ value);

    };

    

    template <typename ___TTT___>

    inline bool check_(const thing_& v)

    {

    	return ___TTT___::___check___(v.handle_);

    }

    

    template <typename ___TTT___, typename ___VVV___>

    inline bool check_(const ___VVV___&)

    {

    	return false;

    }

    

    template <typename ___TTT___>

    inline ___TTT___ static_(const thing_& v)

    {

    	return ___TTT___{ v.handle_ };

    }

    

    template <typename ___TTT___>

    inline thing_::thing_(___TTT___ value)

    	: handle_{ check_<thing_>(value)

    		? static_<thing_>(std::move(value)).handle_

    		: std::make_shared<___root_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }

    {}

    

    template <typename ___TTT___>

    inline thing_& thing_::operator=(___TTT___ value)

    {

    	thing_ temp{ check_<thing_>(value)

    		? static_<thing_>(std::move(value))

    		: std::move(value) };

    	std::swap(temp.handle_, handle_);

    	return *this;

    }

    

}
#endif
