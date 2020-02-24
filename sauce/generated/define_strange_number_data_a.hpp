
namespace strange
{

template <typename ___TTT___, typename _1__chk>
inline bool check(number_data_a<_1__chk> const& value) noexcept;

template <typename _1_>
class number_data_a : public number_a<>
{
public:
	// arithmetic operator overloads
	inline number_data_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline number_data_a operator++(int)
	{
		assert(handle_);
		number_data_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline number_data_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline number_data_a operator--(int)
	{
		assert(handle_);
		number_data_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline number_data_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline number_data_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline number_data_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline number_data_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline number_data_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline _1_ const & extract_primitive() const
	{ assert(handle_); return read().extract_primitive(); }

	inline _1_ & mutate_primitive()
	{ assert(handle_); return write().mutate_primitive(); }

protected:
	struct ___number_data_a_handle_base___ : ___number_a_handle_base___
	{
		virtual _1_ const & extract_primitive() const = 0;
		virtual _1_ & mutate_primitive() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___number_data_a_handle_base___>
	struct ___number_data_a_handle___ : ___number_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___number_data_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___number_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___number_data_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___number_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline _1_ const & extract_primitive() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.extract_primitive(); }

		virtual inline _1_ & mutate_primitive() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.mutate_primitive(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___number_data_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___number_data_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___number_data_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___number_data_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___number_data_a_handle_final___ final : ___number_data_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___number_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___number_data_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___number_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___number_data_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___number_data_a_handle_final___>(___number_data_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___number_data_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___number_data_a_handle_final___<___TTT___&>
	{
		inline ___number_data_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___number_data_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___number_data_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___number_data_a_handle_base___ const>(handle_);
	}

	inline ___number_data_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___number_data_a_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(number_data_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle));
	}

	static inline number_data_a val(number_data_a const& other) noexcept
	{
		return number_data_a{ other };
	}

	static inline number_data_a ref(number_data_a& other) noexcept
	{
		return number_data_a(other, ___reference_tag___{});
	}

	static inline number_data_a dup(number_data_a& other) noexcept
	{
		return number_data_a(other, ___duplicate_tag___{});
	}

	inline number_data_a() = default;

	inline number_data_a(number_data_a& other, ___reference_tag___) noexcept
		: number_a(other, ___reference_tag___{})
	{}

	inline number_data_a(number_data_a& other, ___duplicate_tag___) noexcept
		: number_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline number_data_a(std::shared_ptr<___TTT___> const& handle)
		: number_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle))
		{
			throw dis("number_data_a constructor failed to cast from base to number_data_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline number_data_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: number_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline number_data_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: number_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle))
		{
			throw dis("number_data_a constructor failed to cast from base to number_data_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline number_data_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: number_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_data_a, std::decay_t<___TTT___>>::value>>
	explicit inline number_data_a(___TTT___ value) noexcept
		: number_a{ std::make_shared<___number_data_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline number_data_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle))
		{
			throw dis("number_data_a assignment failed to cast from base to number_data_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline number_data_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_data_a, std::decay_t<___TTT___>>::value>>
	inline number_data_a& operator=(___TTT___ value) noexcept
	{
		number_data_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___number_data_a_share___;
}; // class number_data_a

template <typename ___TTT___, typename _1__chk>
inline bool check(number_data_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const number_data_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<number_data_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class number_data_d : public number_d<>
{
public:
	// arithmetic operator overloads
	inline number_data_d& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline number_data_d operator++(int)
	{
		assert(handle_);
		number_data_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline number_data_d& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline number_data_d operator--(int)
	{
		assert(handle_);
		number_data_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline number_data_d& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline number_data_d& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline number_data_d& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline number_data_d& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline number_data_d& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline _1_ const & extract_primitive() const
	{ throw dis("dynamic number_data_d::extract_primitive() not available"); }

	inline _1_ & mutate_primitive()
	{ throw dis("dynamic number_data_d::mutate_primitive() not available"); }

};

} // namespace
