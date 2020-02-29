
namespace strange
{

template <typename _1_ = void>
class random_access_iterator_d;

template <typename _1_ = void>
inline random_access_iterator_d<_1_> ___random_access_iterator_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(random_access_iterator_a<_1__chk> const& value) noexcept;

template <typename _1_>
class random_access_iterator_a : public bidirectional_iterator_a<>
{
public:
	// arithmetic operator overloads
	inline random_access_iterator_a& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_a operator++(int)
	{
		assert(___handle___);
		random_access_iterator_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline random_access_iterator_a& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_a operator--(int)
	{
		assert(___handle___);
		random_access_iterator_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline random_access_iterator_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline random_access_iterator_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline random_access_iterator_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline random_access_iterator_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline random_access_iterator_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> self_add__(range_a<> const& range)
	{ assert(___handle___); return write().self_add__(range); }

	inline random_access_iterator_a<> self_add_(number_a<> const& number)
	{ assert(___handle___); return write().self_add_(number); }

	inline any_a<> add__(range_a<> const& range) const
	{ assert(___handle___); return read().add__(range); }

	inline random_access_iterator_a<> add_(number_a<> const& number) const
	{ assert(___handle___); return read().add_(number); }

	inline random_access_iterator_a operator+(number_a < > const & number ) const
	{ assert(___handle___); return read().operator+(number); }

	inline any_a<> self_subtract__(range_a<> const& range)
	{ assert(___handle___); return write().self_subtract__(range); }

	inline random_access_iterator_a<> self_subtract_(number_a<> const& number)
	{ assert(___handle___); return write().self_subtract_(number); }

	inline any_a<> subtract__(range_a<> const& range) const
	{ assert(___handle___); return read().subtract__(range); }

	inline random_access_iterator_a<> subtract_(number_a<> const& number) const
	{ assert(___handle___); return read().subtract_(number); }

	inline random_access_iterator_a operator-(number_a < > const & number ) const
	{ assert(___handle___); return read().operator-(number); }

	inline any_a<> less_than__(range_a<> const& range) const
	{ assert(___handle___); return read().less_than__(range); }

	inline any_a<> less_than_(random_access_iterator_a<> const& it) const
	{ assert(___handle___); return read().less_than_(it); }

	inline bool operator<(random_access_iterator_a < > const & it ) const
	{ assert(___handle___); return read().operator<(it); }

	inline any_a<> greater_than__(range_a<> const& range) const
	{ assert(___handle___); return read().greater_than__(range); }

	inline any_a<> greater_than_(random_access_iterator_a<> const& it) const
	{ assert(___handle___); return read().greater_than_(it); }

	inline bool operator>(random_access_iterator_a < > const & it ) const
	{ assert(___handle___); return read().operator>(it); }

	inline any_a<> less_or_equal__(range_a<> const& range) const
	{ assert(___handle___); return read().less_or_equal__(range); }

	inline any_a<> less_or_equal_(random_access_iterator_a<> const& it) const
	{ assert(___handle___); return read().less_or_equal_(it); }

	inline bool operator<=(random_access_iterator_a < > const & it ) const
	{ assert(___handle___); return read().operator<=(it); }

	inline any_a<> greater_or_equal__(range_a<> const& range) const
	{ assert(___handle___); return read().greater_or_equal__(range); }

	inline any_a<> greater_or_equal_(random_access_iterator_a<> const& it) const
	{ assert(___handle___); return read().greater_or_equal_(it); }

	inline bool operator>=(random_access_iterator_a < > const & it ) const
	{ assert(___handle___); return read().operator>=(it); }

protected:
	struct ___random_access_iterator_a_handle_base___ : ___bidirectional_iterator_a_handle_base___
	{
		virtual any_a<> self_add__(range_a<> const& range) = 0;
		virtual random_access_iterator_a<> self_add_(number_a<> const& number) = 0;
		virtual any_a<> add__(range_a<> const& range) const = 0;
		virtual random_access_iterator_a<> add_(number_a<> const& number) const = 0;
		virtual random_access_iterator_a operator+(number_a < > const & number ) const = 0;
		virtual any_a<> self_subtract__(range_a<> const& range) = 0;
		virtual random_access_iterator_a<> self_subtract_(number_a<> const& number) = 0;
		virtual any_a<> subtract__(range_a<> const& range) const = 0;
		virtual random_access_iterator_a<> subtract_(number_a<> const& number) const = 0;
		virtual random_access_iterator_a operator-(number_a < > const & number ) const = 0;
		virtual any_a<> less_than__(range_a<> const& range) const = 0;
		virtual any_a<> less_than_(random_access_iterator_a<> const& it) const = 0;
		virtual bool operator<(random_access_iterator_a < > const & it ) const = 0;
		virtual any_a<> greater_than__(range_a<> const& range) const = 0;
		virtual any_a<> greater_than_(random_access_iterator_a<> const& it) const = 0;
		virtual bool operator>(random_access_iterator_a < > const & it ) const = 0;
		virtual any_a<> less_or_equal__(range_a<> const& range) const = 0;
		virtual any_a<> less_or_equal_(random_access_iterator_a<> const& it) const = 0;
		virtual bool operator<=(random_access_iterator_a < > const & it ) const = 0;
		virtual any_a<> greater_or_equal__(range_a<> const& range) const = 0;
		virtual any_a<> greater_or_equal_(random_access_iterator_a<> const& it) const = 0;
		virtual bool operator>=(random_access_iterator_a < > const & it ) const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___random_access_iterator_a_handle_base___>
	struct ___random_access_iterator_a_handle___ : ___bidirectional_iterator_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___bidirectional_iterator_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___bidirectional_iterator_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> self_add__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_add__(range); }

		virtual inline random_access_iterator_a<> self_add_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_add_(number); }

		virtual inline any_a<> add__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.add__(range); }

		virtual inline random_access_iterator_a<> add_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(number); }

		virtual inline random_access_iterator_a operator+(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator+(number); }

		virtual inline any_a<> self_subtract__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_subtract__(range); }

		virtual inline random_access_iterator_a<> self_subtract_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_subtract_(number); }

		virtual inline any_a<> subtract__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.subtract__(range); }

		virtual inline random_access_iterator_a<> subtract_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.subtract_(number); }

		virtual inline random_access_iterator_a operator-(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator-(number); }

		virtual inline any_a<> less_than__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.less_than__(range); }

		virtual inline any_a<> less_than_(random_access_iterator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.less_than_(it); }

		virtual inline bool operator<(random_access_iterator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(it); }

		virtual inline any_a<> greater_than__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.greater_than__(range); }

		virtual inline any_a<> greater_than_(random_access_iterator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.greater_than_(it); }

		virtual inline bool operator>(random_access_iterator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(it); }

		virtual inline any_a<> less_or_equal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.less_or_equal__(range); }

		virtual inline any_a<> less_or_equal_(random_access_iterator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.less_or_equal_(it); }

		virtual inline bool operator<=(random_access_iterator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(it); }

		virtual inline any_a<> greater_or_equal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.greater_or_equal__(range); }

		virtual inline any_a<> greater_or_equal_(random_access_iterator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.greater_or_equal_(it); }

		virtual inline bool operator>=(random_access_iterator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(it); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___random_access_iterator_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___random_access_iterator_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___random_access_iterator_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_iterator_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___random_access_iterator_a_handle_final___ final : ___random_access_iterator_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___random_access_iterator_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___random_access_iterator_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___random_access_iterator_a_handle_final___>(___random_access_iterator_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___random_access_iterator_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___random_access_iterator_a_handle_final___<___TTT___&>
	{
		inline ___random_access_iterator_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_iterator_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___random_access_iterator_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___random_access_iterator_a_handle_base___ const>(___handle___);
	}

	inline ___random_access_iterator_a_handle_base___& write() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___random_access_iterator_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(random_access_iterator_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___random_access_iterator_a_handle_base___>(handle));
	}

	static inline random_access_iterator_a cast(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___random_access_iterator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return random_access_iterator_a{ ptr };
		}
		return random_access_iterator_a{ random_access_iterator_d<_1_>{ thing } };
	}

	static inline random_access_iterator_a val(random_access_iterator_a const& other) noexcept
	{
		return random_access_iterator_a{ other };
	}

	static inline random_access_iterator_a ref(random_access_iterator_a& other) noexcept
	{
		return random_access_iterator_a(other, ___reference_tag___{});
	}

	static inline random_access_iterator_a dup(random_access_iterator_a& other) noexcept
	{
		return random_access_iterator_a(other, ___duplicate_tag___{});
	}

	inline random_access_iterator_a() = default;

	inline random_access_iterator_a(random_access_iterator_a& other, ___reference_tag___) noexcept
		: bidirectional_iterator_a(other, ___reference_tag___{})
	{}

	inline random_access_iterator_a(random_access_iterator_a& other, ___duplicate_tag___) noexcept
		: bidirectional_iterator_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline random_access_iterator_a(std::shared_ptr<___TTT___> const& handle)
		: bidirectional_iterator_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___random_access_iterator_a_handle_base___>(handle))
		{
			throw dis("random_access_iterator_a constructor failed to cast from base to random_access_iterator_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline random_access_iterator_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: bidirectional_iterator_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_iterator_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline random_access_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: bidirectional_iterator_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___random_access_iterator_a_handle_base___>(handle))
		{
			throw dis("random_access_iterator_a constructor failed to cast from base to random_access_iterator_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline random_access_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: bidirectional_iterator_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_iterator_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_iterator_a, std::decay_t<___TTT___>>::value>>
	explicit inline random_access_iterator_a(___TTT___ value) noexcept
		: bidirectional_iterator_a{ std::make_shared<___random_access_iterator_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline random_access_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___random_access_iterator_a_handle_base___>(handle))
		{
			throw dis("random_access_iterator_a assignment failed to cast from base to random_access_iterator_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline random_access_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_iterator_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_iterator_a, std::decay_t<___TTT___>>::value>>
	inline random_access_iterator_a& operator=(___TTT___ value) noexcept
	{
		random_access_iterator_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___random_access_iterator_a_share___;
}; // class random_access_iterator_a

template <typename ___TTT___, typename _1__chk>
inline bool check(random_access_iterator_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

template <typename _1_>
bool const random_access_iterator_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<random_access_iterator_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class random_access_iterator_d : public bidirectional_iterator_d<>
{
public:
	// arithmetic operator overloads
	inline random_access_iterator_d& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_d operator++(int)
	{
		assert(___handle___);
		random_access_iterator_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline random_access_iterator_d& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_d operator--(int)
	{
		assert(___handle___);
		random_access_iterator_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline random_access_iterator_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline random_access_iterator_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline random_access_iterator_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline random_access_iterator_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline random_access_iterator_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> self_add__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_add_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::self_add_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline random_access_iterator_a<> self_add_(number_a<> const& number)
	{
		assert(___handle___);
		auto const op = operation("self_add_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::self_add_ passed non-existent member");
		}
		return variadic_operate(op, *this, number);
	}

	inline any_a<> add__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::add_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_iterator_d*>(this), range);
	}

	inline random_access_iterator_a<> add_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::add_ passed non-existent member");
		}
		return variadic_operate(op, *const_cast<random_access_iterator_d*>(this), number);
	}

	inline random_access_iterator_a<_1_> operator+(number_a < > const & number ) const
	{ return add_(number); }

	inline any_a<> self_subtract__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::self_subtract_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline random_access_iterator_a<> self_subtract_(number_a<> const& number)
	{
		assert(___handle___);
		auto const op = operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::self_subtract_ passed non-existent member");
		}
		return variadic_operate(op, *this, number);
	}

	inline any_a<> subtract__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::subtract_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_iterator_d*>(this), range);
	}

	inline random_access_iterator_a<> subtract_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::subtract_ passed non-existent member");
		}
		return variadic_operate(op, *const_cast<random_access_iterator_d*>(this), number);
	}

	inline random_access_iterator_a<_1_> operator-(number_a < > const & number ) const
	{ return subtract_(number); }

	inline any_a<> less_than__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("less_than_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::less_than_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_iterator_d*>(this), range);
	}

	inline any_a<> less_than_(random_access_iterator_a<> const& it) const
	{
		assert(___handle___);
		auto const op = operation("less_than_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::less_than_ passed non-existent member");
		}
		return variadic_operate(op, *const_cast<random_access_iterator_d*>(this), it);
	}

	inline bool operator<(random_access_iterator_a < > const & it ) const
	{ return less_than_(it); }

	inline any_a<> greater_than__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("greater_than_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::greater_than_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_iterator_d*>(this), range);
	}

	inline any_a<> greater_than_(random_access_iterator_a<> const& it) const
	{
		assert(___handle___);
		auto const op = operation("greater_than_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::greater_than_ passed non-existent member");
		}
		return variadic_operate(op, *const_cast<random_access_iterator_d*>(this), it);
	}

	inline bool operator>(random_access_iterator_a < > const & it ) const
	{ return greater_than_(it); }

	inline any_a<> less_or_equal__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("less_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::less_or_equal_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_iterator_d*>(this), range);
	}

	inline any_a<> less_or_equal_(random_access_iterator_a<> const& it) const
	{
		assert(___handle___);
		auto const op = operation("less_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::less_or_equal_ passed non-existent member");
		}
		return variadic_operate(op, *const_cast<random_access_iterator_d*>(this), it);
	}

	inline bool operator<=(random_access_iterator_a < > const & it ) const
	{ return less_or_equal_(it); }

	inline any_a<> greater_or_equal__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("greater_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::greater_or_equal_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_iterator_d*>(this), range);
	}

	inline any_a<> greater_or_equal_(random_access_iterator_a<> const& it) const
	{
		assert(___handle___);
		auto const op = operation("greater_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_iterator_d::greater_or_equal_ passed non-existent member");
		}
		return variadic_operate(op, *const_cast<random_access_iterator_d*>(this), it);
	}

	inline bool operator>=(random_access_iterator_a < > const & it ) const
	{ return greater_or_equal_(it); }

	void ___weak___(bidirectional_iterator_d<>::___WEAK___ const& weak) const {}

	explicit random_access_iterator_d(any_a<> const& thing)
		: bidirectional_iterator_d<>{ thing }
	{}
};

template <typename _1_>
inline random_access_iterator_d<_1_> ___random_access_iterator_dynamic___(any_a<> const& thing)
{
	return random_access_iterator_d<_1_>{ thing };
}

} // namespace
