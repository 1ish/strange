
namespace strange
{

template <typename ___TTT___, typename _1__chk = void>
inline bool check(random_access_const_iterator_a<_1__chk> const& value) noexcept;

template <typename _1_>
class random_access_const_iterator_a : public bidirectional_const_iterator_a<>
{
public:
	// arithmetic operator overloads
	inline random_access_const_iterator_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_const_iterator_a operator++(int)
	{
		assert(handle_);
		random_access_const_iterator_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline random_access_const_iterator_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_const_iterator_a operator--(int)
	{
		assert(handle_);
		random_access_const_iterator_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline random_access_const_iterator_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline random_access_const_iterator_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline random_access_const_iterator_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline random_access_const_iterator_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline random_access_const_iterator_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> self_add__(range_a<> const& range)
	{ assert(handle_); return write().self_add__(range); }

	inline random_access_const_iterator_a<> self_add_(number_a<> const& number)
	{ assert(handle_); return write().self_add_(number); }

	inline any_a<> add__(range_a<> const& range) const
	{ assert(handle_); return read().add__(range); }

	inline random_access_const_iterator_a<> add_(number_a<> const& number) const
	{ assert(handle_); return read().add_(number); }

	inline random_access_const_iterator_a operator+(number_a < > const & number ) const
	{ assert(handle_); return read().operator+(number); }

	inline any_a<> self_subtract__(range_a<> const& range)
	{ assert(handle_); return write().self_subtract__(range); }

	inline random_access_const_iterator_a<> self_subtract_(number_a<> const& number)
	{ assert(handle_); return write().self_subtract_(number); }

	inline any_a<> subtract__(range_a<> const& range) const
	{ assert(handle_); return read().subtract__(range); }

	inline random_access_const_iterator_a<> subtract_(number_a<> const& number) const
	{ assert(handle_); return read().subtract_(number); }

	inline random_access_const_iterator_a operator-(number_a < > const & number ) const
	{ assert(handle_); return read().operator-(number); }

	inline any_a<> less_than__(range_a<> const& range) const
	{ assert(handle_); return read().less_than__(range); }

	inline any_a<> less_than_(random_access_const_iterator_a<> const& it) const
	{ assert(handle_); return read().less_than_(it); }

	inline bool operator<(random_access_const_iterator_a < > const & it ) const
	{ assert(handle_); return read().operator<(it); }

	inline any_a<> greater_than__(range_a<> const& range) const
	{ assert(handle_); return read().greater_than__(range); }

	inline any_a<> greater_than_(random_access_const_iterator_a<> const& it) const
	{ assert(handle_); return read().greater_than_(it); }

	inline bool operator>(random_access_const_iterator_a < > const & it ) const
	{ assert(handle_); return read().operator>(it); }

	inline any_a<> less_or_equal__(range_a<> const& range) const
	{ assert(handle_); return read().less_or_equal__(range); }

	inline any_a<> less_or_equal_(random_access_const_iterator_a<> const& it) const
	{ assert(handle_); return read().less_or_equal_(it); }

	inline bool operator<=(random_access_const_iterator_a < > const & it ) const
	{ assert(handle_); return read().operator<=(it); }

	inline any_a<> greater_or_equal__(range_a<> const& range) const
	{ assert(handle_); return read().greater_or_equal__(range); }

	inline any_a<> greater_or_equal_(random_access_const_iterator_a<> const& it) const
	{ assert(handle_); return read().greater_or_equal_(it); }

	inline bool operator>=(random_access_const_iterator_a < > const & it ) const
	{ assert(handle_); return read().operator>=(it); }

protected:
	struct ___random_access_const_iterator_a_handle_base___ : ___bidirectional_const_iterator_a_handle_base___
	{
		virtual any_a<> self_add__(range_a<> const& range) = 0;
		virtual random_access_const_iterator_a<> self_add_(number_a<> const& number) = 0;
		virtual any_a<> add__(range_a<> const& range) const = 0;
		virtual random_access_const_iterator_a<> add_(number_a<> const& number) const = 0;
		virtual random_access_const_iterator_a operator+(number_a < > const & number ) const = 0;
		virtual any_a<> self_subtract__(range_a<> const& range) = 0;
		virtual random_access_const_iterator_a<> self_subtract_(number_a<> const& number) = 0;
		virtual any_a<> subtract__(range_a<> const& range) const = 0;
		virtual random_access_const_iterator_a<> subtract_(number_a<> const& number) const = 0;
		virtual random_access_const_iterator_a operator-(number_a < > const & number ) const = 0;
		virtual any_a<> less_than__(range_a<> const& range) const = 0;
		virtual any_a<> less_than_(random_access_const_iterator_a<> const& it) const = 0;
		virtual bool operator<(random_access_const_iterator_a < > const & it ) const = 0;
		virtual any_a<> greater_than__(range_a<> const& range) const = 0;
		virtual any_a<> greater_than_(random_access_const_iterator_a<> const& it) const = 0;
		virtual bool operator>(random_access_const_iterator_a < > const & it ) const = 0;
		virtual any_a<> less_or_equal__(range_a<> const& range) const = 0;
		virtual any_a<> less_or_equal_(random_access_const_iterator_a<> const& it) const = 0;
		virtual bool operator<=(random_access_const_iterator_a < > const & it ) const = 0;
		virtual any_a<> greater_or_equal__(range_a<> const& range) const = 0;
		virtual any_a<> greater_or_equal_(random_access_const_iterator_a<> const& it) const = 0;
		virtual bool operator>=(random_access_const_iterator_a < > const & it ) const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___random_access_const_iterator_a_handle_base___>
	struct ___random_access_const_iterator_a_handle___ : ___bidirectional_const_iterator_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_const_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___bidirectional_const_iterator_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_const_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___bidirectional_const_iterator_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> self_add__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_add__(range); }

		virtual inline random_access_const_iterator_a<> self_add_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_add_(number); }

		virtual inline any_a<> add__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.add__(range); }

		virtual inline random_access_const_iterator_a<> add_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.add_(number); }

		virtual inline random_access_const_iterator_a operator+(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator+(number); }

		virtual inline any_a<> self_subtract__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_subtract__(range); }

		virtual inline random_access_const_iterator_a<> self_subtract_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_subtract_(number); }

		virtual inline any_a<> subtract__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.subtract__(range); }

		virtual inline random_access_const_iterator_a<> subtract_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.subtract_(number); }

		virtual inline random_access_const_iterator_a operator-(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator-(number); }

		virtual inline any_a<> less_than__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.less_than__(range); }

		virtual inline any_a<> less_than_(random_access_const_iterator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.less_than_(it); }

		virtual inline bool operator<(random_access_const_iterator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator<(it); }

		virtual inline any_a<> greater_than__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.greater_than__(range); }

		virtual inline any_a<> greater_than_(random_access_const_iterator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.greater_than_(it); }

		virtual inline bool operator>(random_access_const_iterator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator>(it); }

		virtual inline any_a<> less_or_equal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.less_or_equal__(range); }

		virtual inline any_a<> less_or_equal_(random_access_const_iterator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.less_or_equal_(it); }

		virtual inline bool operator<=(random_access_const_iterator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator<=(it); }

		virtual inline any_a<> greater_or_equal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.greater_or_equal__(range); }

		virtual inline any_a<> greater_or_equal_(random_access_const_iterator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.greater_or_equal_(it); }

		virtual inline bool operator>=(random_access_const_iterator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator>=(it); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___random_access_const_iterator_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___random_access_const_iterator_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___random_access_const_iterator_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_const_iterator_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___random_access_const_iterator_a_handle_final___ final : ___random_access_const_iterator_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_const_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___random_access_const_iterator_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_const_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___random_access_const_iterator_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___random_access_const_iterator_a_handle_final___>(___random_access_const_iterator_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___random_access_const_iterator_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___random_access_const_iterator_a_handle_final___<___TTT___&>
	{
		inline ___random_access_const_iterator_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_const_iterator_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___random_access_const_iterator_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___random_access_const_iterator_a_handle_base___ const>(handle_);
	}

	inline ___random_access_const_iterator_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___random_access_const_iterator_a_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(random_access_const_iterator_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___random_access_const_iterator_a_handle_base___>(handle));
	}

	static inline random_access_const_iterator_a val(random_access_const_iterator_a const& other) noexcept
	{
		return random_access_const_iterator_a{ other };
	}

	static inline random_access_const_iterator_a ref(random_access_const_iterator_a& other) noexcept
	{
		return random_access_const_iterator_a(other, ___reference_tag___{});
	}

	static inline random_access_const_iterator_a dup(random_access_const_iterator_a& other) noexcept
	{
		return random_access_const_iterator_a(other, ___duplicate_tag___{});
	}

	inline random_access_const_iterator_a() = default;

	inline random_access_const_iterator_a(random_access_const_iterator_a& other, ___reference_tag___) noexcept
		: bidirectional_const_iterator_a(other, ___reference_tag___{})
	{}

	inline random_access_const_iterator_a(random_access_const_iterator_a& other, ___duplicate_tag___) noexcept
		: bidirectional_const_iterator_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline random_access_const_iterator_a(std::shared_ptr<___TTT___> const& handle)
		: bidirectional_const_iterator_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___random_access_const_iterator_a_handle_base___>(handle))
		{
			throw dis("random_access_const_iterator_a constructor failed to cast from base to random_access_const_iterator_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline random_access_const_iterator_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: bidirectional_const_iterator_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_const_iterator_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline random_access_const_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: bidirectional_const_iterator_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___random_access_const_iterator_a_handle_base___>(handle))
		{
			throw dis("random_access_const_iterator_a constructor failed to cast from base to random_access_const_iterator_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline random_access_const_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: bidirectional_const_iterator_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_const_iterator_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_const_iterator_a, std::decay_t<___TTT___>>::value>>
	explicit inline random_access_const_iterator_a(___TTT___ value) noexcept
		: bidirectional_const_iterator_a{ std::make_shared<___random_access_const_iterator_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline random_access_const_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___random_access_const_iterator_a_handle_base___>(handle))
		{
			throw dis("random_access_const_iterator_a assignment failed to cast from base to random_access_const_iterator_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline random_access_const_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_const_iterator_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_const_iterator_a, std::decay_t<___TTT___>>::value>>
	inline random_access_const_iterator_a& operator=(___TTT___ value) noexcept
	{
		random_access_const_iterator_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___random_access_const_iterator_a_share___;
}; // class random_access_const_iterator_a

template <typename ___TTT___, typename _1__chk>
inline bool check(random_access_const_iterator_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const random_access_const_iterator_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<random_access_const_iterator_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_ = void>
class random_access_const_iterator_d : public bidirectional_const_iterator_d<>
{
public:
	// arithmetic operator overloads
	inline random_access_const_iterator_d& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_const_iterator_d operator++(int)
	{
		assert(handle_);
		random_access_const_iterator_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline random_access_const_iterator_d& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_const_iterator_d operator--(int)
	{
		assert(handle_);
		random_access_const_iterator_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline random_access_const_iterator_d& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline random_access_const_iterator_d& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline random_access_const_iterator_d& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline random_access_const_iterator_d& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline random_access_const_iterator_d& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> self_add__(range_a<> const& range)
	{
		assert(handle_);
		auto const op = read().operations_().at_string("self_add_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::self_add_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline random_access_const_iterator_a<> self_add_(number_a<> const& number)
	{
		assert(handle_);
		auto const op = read().operations_().at_string("self_add_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::self_add_ passed non-existent member");
		}
		return variadic_operate(op, *this, number);
	}

	inline any_a<> add__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("add_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::add_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline random_access_const_iterator_a<> add_(number_a<> const& number) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("add_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::add_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this), number);
	}

	inline random_access_const_iterator_a<_1_> operator+(number_a < > const & number ) const
	{ throw dis("dynamic random_access_const_iterator_d::operator+(number) not available"); }

	inline any_a<> self_subtract__(range_a<> const& range)
	{
		assert(handle_);
		auto const op = read().operations_().at_string("self_subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::self_subtract_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline random_access_const_iterator_a<> self_subtract_(number_a<> const& number)
	{
		assert(handle_);
		auto const op = read().operations_().at_string("self_subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::self_subtract_ passed non-existent member");
		}
		return variadic_operate(op, *this, number);
	}

	inline any_a<> subtract__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::subtract_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline random_access_const_iterator_a<> subtract_(number_a<> const& number) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::subtract_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this), number);
	}

	inline random_access_const_iterator_a<_1_> operator-(number_a < > const & number ) const
	{ throw dis("dynamic random_access_const_iterator_d::operator-(number) not available"); }

	inline any_a<> less_than__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("less_than_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::less_than_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline any_a<> less_than_(random_access_const_iterator_a<> const& it) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("less_than_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::less_than_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this), it);
	}

	inline bool operator<(random_access_const_iterator_a < > const & it ) const
	{ throw dis("dynamic random_access_const_iterator_d::operator<(it) not available"); }

	inline any_a<> greater_than__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("greater_than_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::greater_than_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline any_a<> greater_than_(random_access_const_iterator_a<> const& it) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("greater_than_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::greater_than_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this), it);
	}

	inline bool operator>(random_access_const_iterator_a < > const & it ) const
	{ throw dis("dynamic random_access_const_iterator_d::operator>(it) not available"); }

	inline any_a<> less_or_equal__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("less_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::less_or_equal_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline any_a<> less_or_equal_(random_access_const_iterator_a<> const& it) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("less_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::less_or_equal_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this), it);
	}

	inline bool operator<=(random_access_const_iterator_a < > const & it ) const
	{ throw dis("dynamic random_access_const_iterator_d::operator<=(it) not available"); }

	inline any_a<> greater_or_equal__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("greater_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::greater_or_equal_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline any_a<> greater_or_equal_(random_access_const_iterator_a<> const& it) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("greater_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_const_iterator_d::greater_or_equal_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this), it);
	}

	inline bool operator>=(random_access_const_iterator_a < > const & it ) const
	{ throw dis("dynamic random_access_const_iterator_d::operator>=(it) not available"); }

};

} // namespace
