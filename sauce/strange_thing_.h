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

        // Contructors

        thing_ () = default;

    

        template <typename ___TTT___>

        thing_ (___TTT___ value) :

            handle_ (

                std::make_shared<handle<typename std::remove_reference<___TTT___>::type>>(

                    std::move(value)

                )

            )

        {}

    

        // Assignment

        template <typename ___TTT___>

        thing_ & operator= (___TTT___ value)

        {

            thing_ temp(std::move(value));

            std::swap(temp.handle_, handle_);

            return *this;

        }

    

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
        inline thing_ is_something ( thing_ _ ) const
        { assert(handle_); return read().is_something(_ ); }
        inline bool is_something_ ( ) const
        { assert(handle_); return read().is_something_( ); }
        inline thing_ is_nothing ( thing_ _ ) const
        { assert(handle_); return read().is_nothing(_ ); }
        inline bool is_nothing_ ( ) const
        { assert(handle_); return read().is_nothing_( ); }
        inline thing_ begin ( thing_ _ )
        { assert(handle_); return write().begin(_ ); }
        inline thing_ cbegin ( thing_ _ ) const
        { assert(handle_); return read().cbegin(_ ); }
        inline thing_ end ( thing_ _ )
        { assert(handle_); return write().end(_ ); }
        inline thing_ cend ( thing_ _ ) const
        { assert(handle_); return read().cend(_ ); }
        inline thing_ set ( thing_ thing )
        { assert(handle_); return write().set(thing ); }
        inline thing_ get ( thing_ _ ) const
        { assert(handle_); return read().get(_ ); }
        inline thing_ & operator * ( )
        { assert(handle_); return write().operator*( ); }
        inline const thing_ & operator * ( ) const
        { assert(handle_); return read().operator*( ); }
        inline thing_ * operator -> ( )
        { assert(handle_); return write().operator->( ); }
        inline const thing_ * operator -> ( ) const
        { assert(handle_); return read().operator->( ); }
        inline thing_ increment ( thing_ _ )
        { assert(handle_); return write().increment(_ ); }
        inline thing_ & operator ++ ( )
        { assert(handle_); return write().operator++( ); }
    

    private:

        struct handle_base___

        {

            virtual ~handle_base___ () {}

            virtual std::shared_ptr<handle_base___> clone () const = 0;

    

            virtual inline thing_ mutate ( thing_ thing ) = 0;
            virtual inline thing_ extract ( thing_ thing ) const = 0;
            virtual inline thing_ operator ( ) ( thing_ thing ) = 0;
            virtual inline thing_ operator ( ) ( thing_ thing ) const = 0;
            virtual inline thing_ same ( thing_ thing ) const = 0;
            virtual inline thing_ different ( thing_ thing ) const = 0;
            virtual inline bool operator == ( thing_ thing ) const = 0;
            virtual inline bool operator != ( thing_ thing ) const = 0;
            virtual inline thing_ is_something ( thing_ _ ) const = 0;
            virtual inline bool is_something_ ( ) const = 0;
            virtual inline thing_ is_nothing ( thing_ _ ) const = 0;
            virtual inline bool is_nothing_ ( ) const = 0;
            virtual inline thing_ begin ( thing_ _ ) = 0;
            virtual inline thing_ cbegin ( thing_ _ ) const = 0;
            virtual inline thing_ end ( thing_ _ ) = 0;
            virtual inline thing_ cend ( thing_ _ ) const = 0;
            virtual inline thing_ set ( thing_ thing ) = 0;
            virtual inline thing_ get ( thing_ _ ) const = 0;
            virtual inline thing_ & operator * ( ) = 0;
            virtual inline const thing_ & operator * ( ) const = 0;
            virtual inline thing_ * operator -> ( ) = 0;
            virtual inline const thing_ * operator -> ( ) const = 0;
            virtual inline thing_ increment ( thing_ _ ) = 0;
            virtual inline thing_ & operator ++ ( ) = 0;
        };

    

        template <typename ___TTT___>

        struct handle :

            handle_base___

        {

            template <typename ___UUU___ = ___TTT___>

            handle (___TTT___ value,

                    typename std::enable_if<

                        std::is_reference<___UUU___>::value

                    >::type * = 0) :

                value_ (value)

            {}

    

            template <typename ___UUU___ = ___TTT___>

            handle (___TTT___ value,

                    typename std::enable_if<

                        !std::is_reference<___UUU___>::value,

                        int

                    >::type * = 0) noexcept :

                value_ (std::move(value))

            {}

    

            virtual std::shared_ptr<handle_base___> clone () const

            { return std::make_shared<handle>(value_); }

    

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
            virtual inline thing_ is_something ( thing_ _ ) const
            { return value_.is_something(_ ); }
            virtual inline bool is_something_ ( ) const
            { return value_.is_something_( ); }
            virtual inline thing_ is_nothing ( thing_ _ ) const
            { return value_.is_nothing(_ ); }
            virtual inline bool is_nothing_ ( ) const
            { return value_.is_nothing_( ); }
            virtual inline thing_ begin ( thing_ _ )
            { return value_.begin(_ ); }
            virtual inline thing_ cbegin ( thing_ _ ) const
            { return value_.cbegin(_ ); }
            virtual inline thing_ end ( thing_ _ )
            { return value_.end(_ ); }
            virtual inline thing_ cend ( thing_ _ ) const
            { return value_.cend(_ ); }
            virtual inline thing_ set ( thing_ thing )
            { return value_.set(thing ); }
            virtual inline thing_ get ( thing_ _ ) const
            { return value_.get(_ ); }
            virtual inline thing_ & operator * ( )
            { return value_.operator*( ); }
            virtual inline const thing_ & operator * ( ) const
            { return value_.operator*( ); }
            virtual inline thing_ * operator -> ( )
            { return value_.operator->( ); }
            virtual inline const thing_ * operator -> ( ) const
            { return value_.operator->( ); }
            virtual inline thing_ increment ( thing_ _ )
            { return value_.increment(_ ); }
            virtual inline thing_ & operator ++ ( )
            { return value_.operator++( ); }
    

            ___TTT___ value_;

        };

    

        template <typename ___TTT___>

        struct handle<std::reference_wrapper<___TTT___>> :

            handle<___TTT___ &>

        {

            handle (std::reference_wrapper<___TTT___> ref) :

                handle<___TTT___ &> (ref.get())

            {}

        };

    

        const handle_base___ & read () const

        { return *handle_; }

    

        handle_base___ & write ()

        {

            if (!handle_.unique())

                handle_ = handle_->clone();

            return *handle_;

        }

    

        std::shared_ptr<handle_base___> handle_;

    };

    

}
#endif
