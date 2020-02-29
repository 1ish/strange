
namespace strange
{

template <typename _1_ = void>
class bidirectional_iterator_d;

template <typename _1_ = void>
inline bidirectional_iterator_d<_1_> ___bidirectional_iterator_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(bidirectional_iterator_a<_1__chk> const& value) noexcept;

template <typename _1_>
class bidirectional_iterator_a : public forward_iterator_a<>
{
public:
	// arithmetic operator overloads
	inline bidirectional_iterator_a& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline bidirectional_iterator_a operator++(int)
	{
		assert(___handle___);
		bidirectional_iterator_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline bidirectional_iterator_a& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline bidirectional_iterator_a operator--(int)
	{
		assert(___handle___);
		bidirectional_iterator_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline bidirectional_iterator_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline bidirectional_iterator_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline bidirectional_iterator_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline bidirectional_iterator_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline bidirectional_iterator_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> decrement__(range_a<> const& range)
	{ assert(___handle___); return write().decrement__(range); }

	inline bidirectional_iterator_a<> decrement_()
	{ assert(___handle___); return write().decrement_(); }

protected:
	struct ___bidirectional_iterator_a_handle_base___ : ___forward_iterator_a_handle_base___
	{
		virtual any_a<> decrement__(range_a<> const& range) = 0;
		virtual bidirectional_iterator_a<> decrement_() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___bidirectional_iterator_a_handle_base___>
	struct ___bidirectional_iterator_a_handle___ : ___forward_iterator_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___forward_iterator_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___forward_iterator_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> decrement__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.decrement__(range); }

		virtual inline bidirectional_iterator_a<> decrement_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.decrement_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___bidirectional_iterator_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___bidirectional_iterator_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___bidirectional_iterator_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___bidirectional_iterator_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___bidirectional_iterator_a_handle_final___ final : ___bidirectional_iterator_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___bidirectional_iterator_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___bidirectional_iterator_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___bidirectional_iterator_a_handle_final___>(___bidirectional_iterator_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___bidirectional_iterator_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___bidirectional_iterator_a_handle_final___<___TTT___&>
	{
		inline ___bidirectional_iterator_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___bidirectional_iterator_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___bidirectional_iterator_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___bidirectional_iterator_a_handle_base___ const>(___handle___);
	}

	inline ___bidirectional_iterator_a_handle_base___& write() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___bidirectional_iterator_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(bidirectional_iterator_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___bidirectional_iterator_a_handle_base___>(handle));
	}

	static inline bidirectional_iterator_a cast(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___bidirectional_iterator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return bidirectional_iterator_a{ ptr };
		}
		return bidirectional_iterator_a{ bidirectional_iterator_d<_1_>{ thing } };
	}

	static inline bidirectional_iterator_a val(bidirectional_iterator_a const& other) noexcept
	{
		return bidirectional_iterator_a{ other };
	}

	static inline bidirectional_iterator_a ref(bidirectional_iterator_a& other) noexcept
	{
		return bidirectional_iterator_a(other, ___reference_tag___{});
	}

	static inline bidirectional_iterator_a dup(bidirectional_iterator_a& other) noexcept
	{
		return bidirectional_iterator_a(other, ___duplicate_tag___{});
	}

	inline bidirectional_iterator_a() = default;

	inline bidirectional_iterator_a(bidirectional_iterator_a& other, ___reference_tag___) noexcept
		: forward_iterator_a(other, ___reference_tag___{})
	{}

	inline bidirectional_iterator_a(bidirectional_iterator_a& other, ___duplicate_tag___) noexcept
		: forward_iterator_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline bidirectional_iterator_a(std::shared_ptr<___TTT___> const& handle)
		: forward_iterator_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___bidirectional_iterator_a_handle_base___>(handle))
		{
			throw dis("bidirectional_iterator_a constructor failed to cast from base to bidirectional_iterator_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline bidirectional_iterator_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: forward_iterator_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___bidirectional_iterator_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline bidirectional_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: forward_iterator_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___bidirectional_iterator_a_handle_base___>(handle))
		{
			throw dis("bidirectional_iterator_a constructor failed to cast from base to bidirectional_iterator_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline bidirectional_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: forward_iterator_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___bidirectional_iterator_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<bidirectional_iterator_a, std::decay_t<___TTT___>>::value>>
	explicit inline bidirectional_iterator_a(___TTT___ value) noexcept
		: forward_iterator_a{ std::make_shared<___bidirectional_iterator_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline bidirectional_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___bidirectional_iterator_a_handle_base___>(handle))
		{
			throw dis("bidirectional_iterator_a assignment failed to cast from base to bidirectional_iterator_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline bidirectional_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___bidirectional_iterator_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<bidirectional_iterator_a, std::decay_t<___TTT___>>::value>>
	inline bidirectional_iterator_a& operator=(___TTT___ value) noexcept
	{
		bidirectional_iterator_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___bidirectional_iterator_a_share___;
}; // class bidirectional_iterator_a

template <typename ___TTT___, typename _1__chk>
inline bool check(bidirectional_iterator_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

template <typename _1_>
bool const bidirectional_iterator_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<bidirectional_iterator_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class bidirectional_iterator_d : public forward_iterator_d<>
{
public:
	// arithmetic operator overloads
	inline bidirectional_iterator_d& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline bidirectional_iterator_d operator++(int)
	{
		assert(___handle___);
		bidirectional_iterator_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline bidirectional_iterator_d& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline bidirectional_iterator_d operator--(int)
	{
		assert(___handle___);
		bidirectional_iterator_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline bidirectional_iterator_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline bidirectional_iterator_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline bidirectional_iterator_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline bidirectional_iterator_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline bidirectional_iterator_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> decrement__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("decrement_");
		if (!op)
		{
			throw dis("dynamic bidirectional_iterator_d::decrement_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline bidirectional_iterator_a<> decrement_()
	{
		assert(___handle___);
		auto const op = operation("decrement_");
		if (!op)
		{
			throw dis("dynamic bidirectional_iterator_d::decrement_ passed non-existent member");
		}
		return variadic_operate(op, *this);
	}

	void ___weak___(forward_iterator_d<>::___WEAK___ const& weak) const {}

	explicit bidirectional_iterator_d(any_a<> const& thing)
		: forward_iterator_d<>{ thing }
	{}
};

template <typename _1_>
inline bidirectional_iterator_d<_1_> ___bidirectional_iterator_dynamic___(any_a<> const& thing)
{
	return bidirectional_iterator_d<_1_>{ thing };
}

} // namespace
