
namespace strange
{

template <typename _1_ = void>
class kind_d;

template <typename _1_ = void>
inline kind_d<_1_> ___kind_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(kind_a<_1__chk> const& value) noexcept;

template <typename _1_>
class kind_a : public cat_a<>
{
public:
	// arithmetic operator overloads
	inline kind_a& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline kind_a operator++(int)
	{
		assert(___handle___);
		kind_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline kind_a& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline kind_a operator--(int)
	{
		assert(___handle___);
		kind_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline kind_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline kind_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline kind_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline kind_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline kind_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> aspects__(range_a<> const& range) const
	{ assert(___handle___); return read().aspects__(range); }

	inline flock_a<> aspects_() const
	{ assert(___handle___); return read().aspects_(); }

	inline any_a<> fixed__(range_a<> const& range) const
	{ assert(___handle___); return read().fixed__(range); }

	inline any_a<> fixed_() const
	{ assert(___handle___); return read().fixed_(); }

	inline bool fixed() const
	{ assert(___handle___); return read().fixed(); }

	inline any_a<> reference__(range_a<> const& range) const
	{ assert(___handle___); return read().reference__(range); }

	inline any_a<> reference_() const
	{ assert(___handle___); return read().reference_(); }

	inline bool reference() const
	{ assert(___handle___); return read().reference(); }

	inline any_a<> optional__(range_a<> const& range) const
	{ assert(___handle___); return read().optional__(range); }

	inline any_a<> optional_() const
	{ assert(___handle___); return read().optional_(); }

	inline bool optional() const
	{ assert(___handle___); return read().optional(); }

protected:
	struct ___kind_a_handle_base___ : ___cat_a_handle_base___
	{
		virtual any_a<> aspects__(range_a<> const& range) const = 0;
		virtual flock_a<> aspects_() const = 0;
		virtual any_a<> fixed__(range_a<> const& range) const = 0;
		virtual any_a<> fixed_() const = 0;
		virtual bool fixed() const = 0;
		virtual any_a<> reference__(range_a<> const& range) const = 0;
		virtual any_a<> reference_() const = 0;
		virtual bool reference() const = 0;
		virtual any_a<> optional__(range_a<> const& range) const = 0;
		virtual any_a<> optional_() const = 0;
		virtual bool optional() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___kind_a_handle_base___>
	struct ___kind_a_handle___ : ___cat_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___kind_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___cat_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___kind_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___cat_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> aspects__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.aspects__(range); }

		virtual inline flock_a<> aspects_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.aspects_(); }

		virtual inline any_a<> fixed__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.fixed__(range); }

		virtual inline any_a<> fixed_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.fixed_(); }

		virtual inline bool fixed() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.fixed(); }

		virtual inline any_a<> reference__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.reference__(range); }

		virtual inline any_a<> reference_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.reference_(); }

		virtual inline bool reference() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.reference(); }

		virtual inline any_a<> optional__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.optional__(range); }

		virtual inline any_a<> optional_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.optional_(); }

		virtual inline bool optional() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.optional(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___kind_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___kind_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___kind_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___kind_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___kind_a_handle_final___ final : ___kind_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___kind_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___kind_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___kind_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___kind_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___kind_a_handle_final___>(___kind_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___kind_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___kind_a_handle_final___<___TTT___&>
	{
		inline ___kind_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___kind_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___kind_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___kind_a_handle_base___ const>(___handle___);
	}

	inline ___kind_a_handle_base___& write() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___kind_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(kind_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___kind_a_handle_base___>(handle));
	}

	static inline kind_a cast(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___kind_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return kind_a{ ptr };
		}
		return kind_a{ kind_d<_1_>{ thing } };
	}

	static inline kind_a val(kind_a const& other) noexcept
	{
		return kind_a{ other };
	}

	static inline kind_a ref(kind_a& other) noexcept
	{
		return kind_a(other, ___reference_tag___{});
	}

	static inline kind_a dup(kind_a& other) noexcept
	{
		return kind_a(other, ___duplicate_tag___{});
	}

	inline kind_a() = default;

	inline kind_a(kind_a& other, ___reference_tag___) noexcept
		: cat_a(other, ___reference_tag___{})
	{}

	inline kind_a(kind_a& other, ___duplicate_tag___) noexcept
		: cat_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline kind_a(std::shared_ptr<___TTT___> const& handle)
		: cat_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___kind_a_handle_base___>(handle))
		{
			throw dis("kind_a constructor failed to cast from base to kind_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline kind_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: cat_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___kind_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline kind_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: cat_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___kind_a_handle_base___>(handle))
		{
			throw dis("kind_a constructor failed to cast from base to kind_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline kind_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: cat_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___kind_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<kind_a, std::decay_t<___TTT___>>::value>>
	explicit inline kind_a(___TTT___ value) noexcept
		: cat_a{ std::make_shared<___kind_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline kind_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___kind_a_handle_base___>(handle))
		{
			throw dis("kind_a assignment failed to cast from base to kind_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline kind_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___kind_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<kind_a, std::decay_t<___TTT___>>::value>>
	inline kind_a& operator=(___TTT___ value) noexcept
	{
		kind_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___kind_a_share___;
}; // class kind_a

template <typename ___TTT___, typename _1__chk>
inline bool check(kind_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

template <typename _1_>
bool const kind_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<kind_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class kind_d : public cat_d<>
{
public:
	// arithmetic operator overloads
	inline kind_d& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline kind_d operator++(int)
	{
		assert(___handle___);
		kind_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline kind_d& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline kind_d operator--(int)
	{
		assert(___handle___);
		kind_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline kind_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline kind_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline kind_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline kind_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline kind_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> aspects__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("aspects_");
		if (!op)
		{
			throw dis("dynamic kind_d::aspects_ passed non-existent member");
		}
		return op.operate(*const_cast<kind_d*>(this), range);
	}

	inline flock_a<> aspects_() const
	{
		assert(___handle___);
		auto const op = operation("aspects_");
		if (!op)
		{
			throw dis("dynamic kind_d::aspects_ passed non-existent member");
		}
		return variadic_operate(op, *const_cast<kind_d*>(this));
	}

	inline any_a<> fixed__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("fixed_");
		if (!op)
		{
			throw dis("dynamic kind_d::fixed_ passed non-existent member");
		}
		return op.operate(*const_cast<kind_d*>(this), range);
	}

	inline any_a<> fixed_() const
	{
		assert(___handle___);
		auto const op = operation("fixed_");
		if (!op)
		{
			throw dis("dynamic kind_d::fixed_ passed non-existent member");
		}
		return variadic_operate(op, *const_cast<kind_d*>(this));
	}

	inline bool fixed() const
	{ return fixed_(); }

	inline any_a<> reference__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("reference_");
		if (!op)
		{
			throw dis("dynamic kind_d::reference_ passed non-existent member");
		}
		return op.operate(*const_cast<kind_d*>(this), range);
	}

	inline any_a<> reference_() const
	{
		assert(___handle___);
		auto const op = operation("reference_");
		if (!op)
		{
			throw dis("dynamic kind_d::reference_ passed non-existent member");
		}
		return variadic_operate(op, *const_cast<kind_d*>(this));
	}

	inline bool reference() const
	{ return reference_(); }

	inline any_a<> optional__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("optional_");
		if (!op)
		{
			throw dis("dynamic kind_d::optional_ passed non-existent member");
		}
		return op.operate(*const_cast<kind_d*>(this), range);
	}

	inline any_a<> optional_() const
	{
		assert(___handle___);
		auto const op = operation("optional_");
		if (!op)
		{
			throw dis("dynamic kind_d::optional_ passed non-existent member");
		}
		return variadic_operate(op, *const_cast<kind_d*>(this));
	}

	inline bool optional() const
	{ return optional_(); }

	void ___weak___(cat_d<>::___WEAK___ const& weak) const {}

	explicit kind_d(any_a<> const& thing)
		: cat_d<>{ thing }
	{}
};

template <typename _1_>
inline kind_d<_1_> ___kind_dynamic___(any_a<> const& thing)
{
	return kind_d<_1_>{ thing };
}

} // namespace
