#ifndef COM_ONEISH_STRANGE_THING_H
#define COM_ONEISH_STRANGE_THING_H

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
    
    class Thing

    {

    public:

        // Contructors

        Thing () = default;

    

        template <typename T>

        Thing (T value) :

            handle_ (

                std::make_shared<handle<typename std::remove_reference<T>::type>>(

                    std::move(value)

                )

            )

        {}

    

        // Assignment

        template <typename T>

        Thing & operator= (T value)

        {

            Thing temp(std::move(value));

            std::swap(temp.handle_, handle_);

            return *this;

        }

    

        Thing mutate ( Thing thing )
        { assert(handle_); return write().mutate(thing ); }
        Thing extract ( Thing thing ) const
        { assert(handle_); return read().extract(thing ); }
        Thing operator ( ) ( Thing thing )
        { assert(handle_); return write().operator()(thing ); }
        Thing operator ( ) ( Thing thing ) const
        { assert(handle_); return read().operator()(thing ); }
        Thing same ( Thing thing ) const
        { assert(handle_); return read().same(thing ); }
        Thing different ( Thing thing ) const
        { assert(handle_); return read().different(thing ); }
        bool operator == ( Thing thing ) const
        { assert(handle_); return read().operator==(thing ); }
        bool operator != ( Thing thing ) const
        { assert(handle_); return read().operator!=(thing ); }
        Thing is_something ( Thing _ ) const
        { assert(handle_); return read().is_something(_ ); }
        bool is_something_ ( ) const
        { assert(handle_); return read().is_something_( ); }
        Thing is_nothing ( Thing _ ) const
        { assert(handle_); return read().is_nothing(_ ); }
        bool is_nothing_ ( ) const
        { assert(handle_); return read().is_nothing_( ); }
        Thing begin ( Thing _ )
        { assert(handle_); return write().begin(_ ); }
        Thing cbegin ( Thing _ ) const
        { assert(handle_); return read().cbegin(_ ); }
        Thing end ( Thing _ )
        { assert(handle_); return write().end(_ ); }
        Thing cend ( Thing _ ) const
        { assert(handle_); return read().cend(_ ); }
        Thing set ( Thing thing )
        { assert(handle_); return write().set(thing ); }
        Thing get ( Thing _ ) const
        { assert(handle_); return read().get(_ ); }
        Thing & operator * ( )
        { assert(handle_); return write().operator*( ); }
        const Thing & operator * ( ) const
        { assert(handle_); return read().operator*( ); }
        Thing * operator -> ( )
        { assert(handle_); return write().operator->( ); }
        const Thing * operator -> ( ) const
        { assert(handle_); return read().operator->( ); }
        Thing increment ( Thing _ )
        { assert(handle_); return write().increment(_ ); }
        Thing & operator ++ ( )
        { assert(handle_); return write().operator++( ); }
    

    private:

        struct handle_base

        {

            virtual ~handle_base () {}

            virtual std::shared_ptr<handle_base> clone () const = 0;

    

            virtual Thing mutate ( Thing thing ) = 0;
            virtual Thing extract ( Thing thing ) const = 0;
            virtual Thing operator ( ) ( Thing thing ) = 0;
            virtual Thing operator ( ) ( Thing thing ) const = 0;
            virtual Thing same ( Thing thing ) const = 0;
            virtual Thing different ( Thing thing ) const = 0;
            virtual bool operator == ( Thing thing ) const = 0;
            virtual bool operator != ( Thing thing ) const = 0;
            virtual Thing is_something ( Thing _ ) const = 0;
            virtual bool is_something_ ( ) const = 0;
            virtual Thing is_nothing ( Thing _ ) const = 0;
            virtual bool is_nothing_ ( ) const = 0;
            virtual Thing begin ( Thing _ ) = 0;
            virtual Thing cbegin ( Thing _ ) const = 0;
            virtual Thing end ( Thing _ ) = 0;
            virtual Thing cend ( Thing _ ) const = 0;
            virtual Thing set ( Thing thing ) = 0;
            virtual Thing get ( Thing _ ) const = 0;
            virtual Thing & operator * ( ) = 0;
            virtual const Thing & operator * ( ) const = 0;
            virtual Thing * operator -> ( ) = 0;
            virtual const Thing * operator -> ( ) const = 0;
            virtual Thing increment ( Thing _ ) = 0;
            virtual Thing & operator ++ ( ) = 0;
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

    

            virtual Thing mutate ( Thing thing )
            { return value_.mutate(thing ); }
            virtual Thing extract ( Thing thing ) const
            { return value_.extract(thing ); }
            virtual Thing operator ( ) ( Thing thing )
            { return value_.operator()(thing ); }
            virtual Thing operator ( ) ( Thing thing ) const
            { return value_.operator()(thing ); }
            virtual Thing same ( Thing thing ) const
            { return value_.same(thing ); }
            virtual Thing different ( Thing thing ) const
            { return value_.different(thing ); }
            virtual bool operator == ( Thing thing ) const
            { return value_.operator==(thing ); }
            virtual bool operator != ( Thing thing ) const
            { return value_.operator!=(thing ); }
            virtual Thing is_something ( Thing _ ) const
            { return value_.is_something(_ ); }
            virtual bool is_something_ ( ) const
            { return value_.is_something_( ); }
            virtual Thing is_nothing ( Thing _ ) const
            { return value_.is_nothing(_ ); }
            virtual bool is_nothing_ ( ) const
            { return value_.is_nothing_( ); }
            virtual Thing begin ( Thing _ )
            { return value_.begin(_ ); }
            virtual Thing cbegin ( Thing _ ) const
            { return value_.cbegin(_ ); }
            virtual Thing end ( Thing _ )
            { return value_.end(_ ); }
            virtual Thing cend ( Thing _ ) const
            { return value_.cend(_ ); }
            virtual Thing set ( Thing thing )
            { return value_.set(thing ); }
            virtual Thing get ( Thing _ ) const
            { return value_.get(_ ); }
            virtual Thing & operator * ( )
            { return value_.operator*( ); }
            virtual const Thing & operator * ( ) const
            { return value_.operator*( ); }
            virtual Thing * operator -> ( )
            { return value_.operator->( ); }
            virtual const Thing * operator -> ( ) const
            { return value_.operator->( ); }
            virtual Thing increment ( Thing _ )
            { return value_.increment(_ ); }
            virtual Thing & operator ++ ( )
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
