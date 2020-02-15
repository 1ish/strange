
namespace strange
{

template <typename ___TTT___, typename _1_ = void>
inline bool check(forward_const_iterator_a<_1_> const& value) noexcept;

template <typename _1_>
class forward_const_iterator_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline forward_const_iterator_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

	inline forward_const_iterator_a operator++(int)
	{
		assert(handle_);
		forward_const_iterator_a result = *this;
		write().operator++();
		return result;
	}

	inline forward_const_iterator_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

	inline forward_const_iterator_a operator--(int)
	{
		assert(handle_);
		forward_const_iterator_a result = *this;
		write().operator--();
		return result;
	}

	inline forward_const_iterator_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> get__(range_a<> const& range) const
	{ assert(handle_); return read().get__(range); }

	inline any_a<> get_() const
	{ assert(handle_); return read().get_(); }

	inline any_a < > const & operator*() const
	{ assert(handle_); return read().operator*(); }

	inline any_a < > const * operator->() const
	{ assert(handle_); return read().operator->(); }

	inline any_a<> increment__(range_a<> const& range)
	{ assert(handle_); return write().increment__(range); }

	inline forward_const_iterator_a<> increment_()
	{ assert(handle_); return write().increment_(); }

protected:
	struct ___forward_const_iterator_a_handle_base___ : ___any_a_handle_base___
	{
		virtual inline any_a<> get__(range_a<> const& range) const = 0;
		virtual inline any_a<> get_() const = 0;
		virtual inline any_a < > const & operator*() const = 0;
		virtual inline any_a < > const * operator->() const = 0;
		virtual inline any_a<> increment__(range_a<> const& range) = 0;
		virtual inline forward_const_iterator_a<> increment_() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___forward_const_iterator_a_handle_base___>
	struct ___forward_const_iterator_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___forward_const_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___forward_const_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> get__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.get__(range); }

		virtual inline any_a<> get_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.get_(); }

		virtual inline any_a < > const & operator*() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator*(); }

		virtual inline any_a < > const * operator->() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator->(); }

		virtual inline any_a<> increment__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.increment__(range); }

		virtual inline forward_const_iterator_a<> increment_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.increment_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___forward_const_iterator_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___forward_const_iterator_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___forward_const_iterator_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___forward_const_iterator_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___forward_const_iterator_a_handle_final___ final : ___forward_const_iterator_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___forward_const_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___forward_const_iterator_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___forward_const_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___forward_const_iterator_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___forward_const_iterator_a_handle_final___>(___forward_const_iterator_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___forward_const_iterator_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___forward_const_iterator_a_handle_final___<___TTT___&>
	{
		inline ___forward_const_iterator_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___forward_const_iterator_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___forward_const_iterator_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___forward_const_iterator_a_handle_base___ const>(handle_);
	}

	inline ___forward_const_iterator_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___forward_const_iterator_a_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename _1_>
	friend inline bool check(forward_const_iterator_a<_1_> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle));
	}

	static inline forward_const_iterator_a val(forward_const_iterator_a const& other) noexcept
	{
		return forward_const_iterator_a{ other };
	}

	static inline forward_const_iterator_a ref(forward_const_iterator_a& other) noexcept
	{
		return forward_const_iterator_a(other, ___reference_tag___{});
	}

	static inline forward_const_iterator_a dup(forward_const_iterator_a& other) noexcept
	{
		return forward_const_iterator_a(other, ___duplicate_tag___{});
	}

	inline forward_const_iterator_a() = default;

	inline forward_const_iterator_a(forward_const_iterator_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline forward_const_iterator_a(forward_const_iterator_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline forward_const_iterator_a(std::shared_ptr<___TTT___> const& handle)
		: any_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle))
		{
			throw dis("forward_const_iterator_a constructor failed to cast from base to forward_const_iterator_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline forward_const_iterator_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline forward_const_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: any_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle))
		{
			throw dis("forward_const_iterator_a constructor failed to cast from base to forward_const_iterator_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline forward_const_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_const_iterator_a, std::decay_t<___TTT___>>::value>>
	explicit inline forward_const_iterator_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___forward_const_iterator_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline forward_const_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle))
		{
			throw dis("forward_const_iterator_a assignment failed to cast from base to forward_const_iterator_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline forward_const_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_const_iterator_a, std::decay_t<___TTT___>>::value>>
	inline forward_const_iterator_a& operator=(___TTT___ value) noexcept
	{
		forward_const_iterator_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___forward_const_iterator_a_share___;
}; // class forward_const_iterator_a

template <typename ___TTT___, typename _1_>
inline bool check(forward_const_iterator_a<_1_> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const forward_const_iterator_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<forward_const_iterator_a<_1_>>::share(shoal);
	return shoal.something();
}();

} // namespace
