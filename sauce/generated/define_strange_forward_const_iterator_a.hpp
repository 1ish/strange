
namespace strange
{

template <typename _1_ = void>
class forward_const_iterator_d;

template <typename _1_ = void>
inline forward_const_iterator_d<_1_> ___forward_const_iterator_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(forward_const_iterator_a<_1__chk> const& value) noexcept;

template <typename _1_>
class forward_const_iterator_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline forward_const_iterator_a& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline forward_const_iterator_a operator++(int)
	{
		assert(___handle___);
		forward_const_iterator_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline forward_const_iterator_a& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline forward_const_iterator_a operator--(int)
	{
		assert(___handle___);
		forward_const_iterator_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline forward_const_iterator_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> get__(range_a<> const& range) const
	{ assert(___handle___); return read().get__(range); }

	inline any_a<> get_() const
	{ assert(___handle___); return read().get_(); }

	inline any_a < > const & operator*() const
	{ assert(___handle___); return read().operator*(); }

	inline any_a < > const * operator->() const
	{ assert(___handle___); return read().operator->(); }

	inline any_a<> increment__(range_a<> const& range)
	{ assert(___handle___); return write().increment__(range); }

	inline forward_const_iterator_a<> increment_()
	{ assert(___handle___); return write().increment_(); }

protected:
	struct ___forward_const_iterator_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> get__(range_a<> const& range) const = 0;
		virtual any_a<> get_() const = 0;
		virtual any_a < > const & operator*() const = 0;
		virtual any_a < > const * operator->() const = 0;
		virtual any_a<> increment__(range_a<> const& range) = 0;
		virtual forward_const_iterator_a<> increment_() = 0;
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
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.get__(range); }

		virtual inline any_a<> get_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.get_(); }

		virtual inline any_a < > const & operator*() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator*(); }

		virtual inline any_a < > const * operator->() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator->(); }

		virtual inline any_a<> increment__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.increment__(range); }

		virtual inline forward_const_iterator_a<> increment_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.increment_(); }

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
			return std::make_shared<___forward_const_iterator_a_handle_final___>(___forward_const_iterator_a_handle___<___TTT___>::___value___);
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

protected:
	inline ___forward_const_iterator_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___forward_const_iterator_a_handle_base___ const>(___handle___);
	}

	inline ___forward_const_iterator_a_handle_base___& write() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___forward_const_iterator_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(forward_const_iterator_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle));
	}

	static inline forward_const_iterator_a cast(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return forward_const_iterator_a{ ptr };
		}
		return forward_const_iterator_a{ forward_const_iterator_d<_1_>{ thing } };
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
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline forward_const_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle))
		{
			throw dis("forward_const_iterator_a assignment failed to cast from base to forward_const_iterator_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline forward_const_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_const_iterator_a, std::decay_t<___TTT___>>::value>>
	inline forward_const_iterator_a& operator=(___TTT___ value) noexcept
	{
		forward_const_iterator_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___forward_const_iterator_a_share___;
}; // class forward_const_iterator_a

template <typename ___TTT___, typename _1__chk>
inline bool check(forward_const_iterator_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

template <typename _1_>
bool const forward_const_iterator_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<forward_const_iterator_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class forward_const_iterator_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline forward_const_iterator_d& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline forward_const_iterator_d operator++(int)
	{
		assert(___handle___);
		forward_const_iterator_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline forward_const_iterator_d& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline forward_const_iterator_d operator--(int)
	{
		assert(___handle___);
		forward_const_iterator_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline forward_const_iterator_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline forward_const_iterator_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline forward_const_iterator_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline forward_const_iterator_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline forward_const_iterator_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> get__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("get_");
		if (!op)
		{
			throw dis("dynamic forward_const_iterator_d::get_ passed non-existent member");
		}
		return op.operate(*const_cast<forward_const_iterator_d*>(this), range);
	}

	inline any_a<> get_() const
	{
		assert(___handle___);
		auto const op = operation("get_");
		if (!op)
		{
			throw dis("dynamic forward_const_iterator_d::get_ passed non-existent member");
		}
		return variadic_operate(op, *const_cast<forward_const_iterator_d*>(this));
	}

	inline any_a < > const & operator*() const
	{ throw dis("dynamic forward_const_iterator_d::operator*() not available"); }

	inline any_a < > const * operator->() const
	{ throw dis("dynamic forward_const_iterator_d::operator->() not available"); }

	inline any_a<> increment__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("increment_");
		if (!op)
		{
			throw dis("dynamic forward_const_iterator_d::increment_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline forward_const_iterator_a<> increment_()
	{
		assert(___handle___);
		auto const op = operation("increment_");
		if (!op)
		{
			throw dis("dynamic forward_const_iterator_d::increment_ passed non-existent member");
		}
		return variadic_operate(op, *this);
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit forward_const_iterator_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}
};

template <typename _1_>
inline forward_const_iterator_d<_1_> ___forward_const_iterator_dynamic___(any_a<> const& thing)
{
	return forward_const_iterator_d<_1_>{ thing };
}

} // namespace
