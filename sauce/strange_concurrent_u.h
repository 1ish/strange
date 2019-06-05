#ifndef COM_ONEISH_STRANGE_CONCURRENT_U_H
#define COM_ONEISH_STRANGE_CONCURRENT_U_H

template <bool CONCURRENT>
class concurrent_u;

template <>
class concurrent_u<false>
{
public:
    class mutex
    {
    };

    class read_lock
    {
    public:
        read_lock(mutex&){}
    };

    class write_lock
    {
    public:
        write_lock(mutex&){}
    };
};

template <>
class concurrent_u<true>
{
public:
    using mutex = std::shared_timed_mutex;
    using read_lock = std::shared_lock<mutex>;
    using write_lock = std::unique_lock<mutex>;
};

#endif