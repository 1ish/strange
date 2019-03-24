%struct_prefix%
{
public:
    // Contructors
    %struct_name% () = default;

    template <typename ___TTT___>
    %struct_name% (___TTT___ value) :
        handle_ (
            std::make_shared<handle<typename std::remove_reference<___TTT___>::type>>(
                std::move(value)
            )
        )
    {}

    // Assignment
    template <typename ___TTT___>
    %struct_name% & operator= (___TTT___ value)
    {
        %struct_name% temp(std::move(value));
        std::swap(temp.handle_, handle_);
        return *this;
    }

    %nonvirtual_members%

private:
    struct handle_base
    {
        virtual ~handle_base () {}
        virtual std::shared_ptr<handle_base> clone () const = 0;

        %pure_virtual_members%
    };

    template <typename ___TTT___>
    struct handle :
        handle_base
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

        virtual std::shared_ptr<handle_base> clone () const
        { return std::make_shared<handle>(value_); }

        %virtual_members%

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
