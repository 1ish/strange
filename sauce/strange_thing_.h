#ifndef COM_ONEISH_STRANGE_THING__HPP
#define COM_ONEISH_STRANGE_THING__HPP

#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

#if defined(_MSC_VER) && _MSC_VER == 1800
#define noexcept
#define alignof __alignof
#endif


namespace strange {
    
    class thing_

    {

    public:

        // Contructors

        thing_ () = default;

    

        template <typename T>

        thing_ (T value) :

            handle_ (

                std::make_shared<handle<typename std::remove_reference<T>::type>>(

                    std::move(value)

                )

            )

        {}

    

        // Assignment

        template <typename T>

        thing_ & operator= (T value)

        {

            thing_ temp(std::move(value));

            std::swap(temp.handle_, handle_);

            return *this;

        }

    

        thing_ mutate ( thing_ thing )
        { assert(handle_); return write().mutate(thing ); }
        thing_ extract ( thing_ thing ) const
        { assert(handle_); return read().extract(thing ); }
        thing_ operator ( ) ( thing_ thing )
        { assert(handle_); return write().operator()(thing ); }
        thing_ operator ( ) ( thing_ thing ) const
        { assert(handle_); return read().operator()(thing ); }
        thing_ same ( thing_ thing ) const
        { assert(handle_); return read().same(thing ); }
        thing_ different ( thing_ thing ) const
        { assert(handle_); return read().different(thing ); }
        bool operator == ( thing_ thing ) const
        { assert(handle_); return read().operator==(thing ); }
        bool operator != ( thing_ thing ) const
        { assert(handle_); return read().operator!=(thing ); }
        thing_ is_something ( thing_ _ ) const
        { assert(handle_); return read().is_something(_ ); }
        bool is_something_ ( ) const
        { assert(handle_); return read().is_something_( ); }
        thing_ is_nothing ( thing_ _ ) const
        { assert(handle_); return read().is_nothing(_ ); }
        bool is_nothing_ ( ) const
        { assert(handle_); return read().is_nothing_( ); }
        thing_ begin ( thing_ _ )
        { assert(handle_); return write().begin(_ ); }
        thing_ cbegin ( thing_ _ ) const
        { assert(handle_); return read().cbegin(_ ); }
        thing_ end ( thing_ _ )
        { assert(handle_); return write().end(_ ); }
        thing_ cend ( thing_ _ ) const
        { assert(handle_); return read().cend(_ ); }
        thing_ set ( thing_ thing )
        { assert(handle_); return write().set(thing ); }
        thing_ get ( thing_ _ ) const
        { assert(handle_); return read().get(_ ); }
        thing_ & operator * ( )
        { assert(handle_); return write().operator*( ); }
        const thing_ & operator * ( ) const
        { assert(handle_); return read().operator*( ); }
        thing_ * operator -> ( )
        { assert(handle_); return write().operator->( ); }
        const thing_ * operator -> ( ) const
        { assert(handle_); return read().operator->( ); }
        thing_ increment ( thing_ _ )
        { assert(handle_); return write().increment(_ ); }
        thing_ & operator ++ ( )
        { assert(handle_); return write().operator++( ); }
    

    private:

        struct handle_base

        {

            virtual ~handle_base () {}

            virtual std::shared_ptr<handle_base> clone () const = 0;

    

            virtual thing_ mutate ( thing_ thing ) = 0;
            virtual thing_ extract ( thing_ thing ) const = 0;
            virtual thing_ operator ( ) ( thing_ thing ) = 0;
            virtual thing_ operator ( ) ( thing_ thing ) const = 0;
            virtual thing_ same ( thing_ thing ) const = 0;
            virtual thing_ different ( thing_ thing ) const = 0;
            virtual bool operator == ( thing_ thing ) const = 0;
            virtual bool operator != ( thing_ thing ) const = 0;
            virtual thing_ is_something ( thing_ _ ) const = 0;
            virtual bool is_something_ ( ) const = 0;
            virtual thing_ is_nothing ( thing_ _ ) const = 0;
            virtual bool is_nothing_ ( ) const = 0;
            virtual thing_ begin ( thing_ _ ) = 0;
            virtual thing_ cbegin ( thing_ _ ) const = 0;
            virtual thing_ end ( thing_ _ ) = 0;
            virtual thing_ cend ( thing_ _ ) const = 0;
            virtual thing_ set ( thing_ thing ) = 0;
            virtual thing_ get ( thing_ _ ) const = 0;
            virtual thing_ & operator * ( ) = 0;
            virtual const thing_ & operator * ( ) const = 0;
            virtual thing_ * operator -> ( ) = 0;
            virtual const thing_ * operator -> ( ) const = 0;
            virtual thing_ increment ( thing_ _ ) = 0;
            virtual thing_ & operator ++ ( ) = 0;
        };

    

        template <typename T>

        struct handle :

            handle_base

        {

            template <typename U = T>

            handle (T value,

                    typename std::enable_if<

                        std::is_reference<U>::value

                    >::type * = 0) :

                value_ (value)

            {}

    

            template <typename U = T>

            handle (T value,

                    typename std::enable_if<

                        !std::is_reference<U>::value,

                        int

                    >::type * = 0) noexcept :

                value_ (std::move(value))

            {}

    

            virtual std::shared_ptr<handle_base> clone () const

            { return std::make_shared<handle>(value_); }

    

            virtual thing_ mutate ( thing_ thing )
            { return value_.mutate(thing ); }
            virtual thing_ extract ( thing_ thing ) const
            { return value_.extract(thing ); }
            virtual thing_ operator ( ) ( thing_ thing )
            { return value_.operator()(thing ); }
            virtual thing_ operator ( ) ( thing_ thing ) const
            { return value_.operator()(thing ); }
            virtual thing_ same ( thing_ thing ) const
            { return value_.same(thing ); }
            virtual thing_ different ( thing_ thing ) const
            { return value_.different(thing ); }
            virtual bool operator == ( thing_ thing ) const
            { return value_.operator==(thing ); }
            virtual bool operator != ( thing_ thing ) const
            { return value_.operator!=(thing ); }
            virtual thing_ is_something ( thing_ _ ) const
            { return value_.is_something(_ ); }
            virtual bool is_something_ ( ) const
            { return value_.is_something_( ); }
            virtual thing_ is_nothing ( thing_ _ ) const
            { return value_.is_nothing(_ ); }
            virtual bool is_nothing_ ( ) const
            { return value_.is_nothing_( ); }
            virtual thing_ begin ( thing_ _ )
            { return value_.begin(_ ); }
            virtual thing_ cbegin ( thing_ _ ) const
            { return value_.cbegin(_ ); }
            virtual thing_ end ( thing_ _ )
            { return value_.end(_ ); }
            virtual thing_ cend ( thing_ _ ) const
            { return value_.cend(_ ); }
            virtual thing_ set ( thing_ thing )
            { return value_.set(thing ); }
            virtual thing_ get ( thing_ _ ) const
            { return value_.get(_ ); }
            virtual thing_ & operator * ( )
            { return value_.operator*( ); }
            virtual const thing_ & operator * ( ) const
            { return value_.operator*( ); }
            virtual thing_ * operator -> ( )
            { return value_.operator->( ); }
            virtual const thing_ * operator -> ( ) const
            { return value_.operator->( ); }
            virtual thing_ increment ( thing_ _ )
            { return value_.increment(_ ); }
            virtual thing_ & operator ++ ( )
            { return value_.operator++( ); }
    

            T value_;

        };

    

        template <typename T>

        struct handle<std::reference_wrapper<T>> :

            handle<T &>

        {

            handle (std::reference_wrapper<T> ref) :

                handle<T &> (ref.get())

            {}

        };

    

        const handle_base & read () const

        { return *handle_; }

    

        handle_base & write ()

        {

            if (!handle_.unique())

                handle_ = handle_->clone();

            return *handle_;

        }

    

        std::shared_ptr<handle_base> handle_;

    };

    

}
#endif
