#ifndef COM_ONEISH_STRANGE_CONCURRENT_U_H
#define COM_ONEISH_STRANGE_CONCURRENT_U_H

namespace strange
{

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
		read_lock(mutex&) {}
	};

	class write_lock
	{
	public:
		write_lock(mutex&) {}
	};

	using read_lock_ptr = std::shared_ptr<read_lock>;
	using write_lock_ptr = std::shared_ptr<write_lock>;

	static inline read_lock_ptr make_read_lock_ptr(mutex& m)
	{
		return std::make_shared<read_lock>(m);
	}

	static inline write_lock_ptr make_write_lock_ptr(mutex& m)
	{
		return std::make_shared<write_lock>(m);
	}
};

template <>
class concurrent_u<true>
{
public:
	using mutex = std::shared_timed_mutex;
	using read_lock = std::shared_lock<mutex>;
	using write_lock = std::unique_lock<mutex>;
	using read_lock_ptr = std::shared_ptr<read_lock>;
	using write_lock_ptr = std::shared_ptr<write_lock>;

	static inline read_lock_ptr make_read_lock_ptr(mutex& m)
	{
		return std::make_shared<read_lock>(m);
	}

	static inline write_lock_ptr make_write_lock_ptr(mutex& m)
	{
		return std::make_shared<write_lock>(m);
	}
};

template <bool CONCURRENT>
using read_lock_ptr = typename concurrent_u<CONCURRENT>::read_lock_ptr;

template <bool CONCURRENT>
using write_lock_ptr = typename concurrent_u<CONCURRENT>::write_lock_ptr;

template <bool CONCURRENT>
inline read_lock_ptr<CONCURRENT> make_read_lock_ptr(typename concurrent_u<CONCURRENT>::mutex& m)
{
	return std::make_shared<typename concurrent_u<CONCURRENT>::read_lock>(m);
}

template <bool CONCURRENT>
inline write_lock_ptr<CONCURRENT> make_write_lock_ptr(typename concurrent_u<CONCURRENT>::mutex& m)
{
	return std::make_shared<typename concurrent_u<CONCURRENT>::write_lock>(m);
}

}

#endif