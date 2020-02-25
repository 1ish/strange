
namespace strange
{

template <typename _1_ = void>
class operation_d;

template <typename _1_ = void>
inline operation_d<_1_> ___operation_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(operation_a<_1__chk> const& value) noexcept;

template <typename _1_>
class operation_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline operation_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline operation_a operator++(int)
	{
		assert(handle_);
		operation_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline operation_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline operation_a operator--(int)
	{
		assert(handle_);
		operation_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline operation_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline operation_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline operation_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline operation_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline operation_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> pure__(range_a<> const& range) const
	{ assert(handle_); return read().pure__(range); }

	inline any_a<> pure_() const
	{ assert(handle_); return read().pure_(); }

	inline bool pure() const
	{ assert(handle_); return read().pure(); }

	inline void aspects(unordered_shoal_a < > const & shoal )
	{ assert(handle_); write().aspects(shoal); }

	inline void assign(operation_a < > const & operation )
	{ assert(handle_); write().assign(operation); }

	inline any_a<> names__(range_a<> const& range) const
	{ assert(handle_); return read().names__(range); }

	inline flock_a<> names_() const
	{ assert(handle_); return read().names_(); }

protected:
	struct ___operation_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> pure__(range_a<> const& range) const = 0;
		virtual any_a<> pure_() const = 0;
		virtual bool pure() const = 0;
		virtual void aspects(unordered_shoal_a < > const & shoal ) = 0;
		virtual void assign(operation_a < > const & operation ) = 0;
		virtual any_a<> names__(range_a<> const& range) const = 0;
		virtual flock_a<> names_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___operation_a_handle_base___>
	struct ___operation_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> pure__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.pure__(range); }

		virtual inline any_a<> pure_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.pure_(); }

		virtual inline bool pure() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.pure(); }

		virtual inline void aspects(unordered_shoal_a < > const & shoal ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.aspects(shoal); }

		virtual inline void assign(operation_a < > const & operation ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.assign(operation); }

		virtual inline any_a<> names__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.names__(range); }

		virtual inline flock_a<> names_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.names_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___operation_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___operation_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___operation_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___operation_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___operation_a_handle_final___ final : ___operation_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___operation_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___operation_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___operation_a_handle_final___>(___operation_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___operation_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___operation_a_handle_final___<___TTT___&>
	{
		inline ___operation_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___operation_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___operation_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___operation_a_handle_base___ const>(handle_);
	}

	inline ___operation_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___operation_a_handle_base___>(handle_);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(operation_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___operation_a_handle_base___>(handle));
	}

	static inline operation_a val(operation_a const& other) noexcept
	{
		return operation_a{ other };
	}

	static inline operation_a ref(operation_a& other) noexcept
	{
		return operation_a(other, ___reference_tag___{});
	}

	static inline operation_a dup(operation_a& other) noexcept
	{
		return operation_a(other, ___duplicate_tag___{});
	}

	inline operation_a() = default;

	inline operation_a(operation_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline operation_a(operation_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline operation_a(std::shared_ptr<___TTT___> const& handle)
		: any_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___operation_a_handle_base___>(handle))
		{
			throw dis("operation_a constructor failed to cast from base to operation_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline operation_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___operation_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline operation_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: any_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___operation_a_handle_base___>(handle))
		{
			throw dis("operation_a constructor failed to cast from base to operation_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline operation_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___operation_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<operation_a, std::decay_t<___TTT___>>::value>>
	explicit inline operation_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___operation_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline operation_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___operation_a_handle_base___>(handle))
		{
			throw dis("operation_a assignment failed to cast from base to operation_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline operation_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___operation_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<operation_a, std::decay_t<___TTT___>>::value>>
	inline operation_a& operator=(___TTT___ value) noexcept
	{
		operation_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___operation_a_share___;
}; // class operation_a

template <typename ___TTT___, typename _1__chk>
inline bool check(operation_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const operation_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<operation_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class operation_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline operation_d& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline operation_d operator++(int)
	{
		assert(handle_);
		operation_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline operation_d& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline operation_d operator--(int)
	{
		assert(handle_);
		operation_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline operation_d& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline operation_d& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline operation_d& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline operation_d& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline operation_d& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> pure__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("pure_");
		if (!op)
		{
			throw dis("dynamic operation_d::pure_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline any_a<> pure_() const
	{
		assert(handle_);
		auto const op = operation("pure_");
		if (!op)
		{
			throw dis("dynamic operation_d::pure_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline bool pure() const
	{ throw dis("dynamic operation_d::pure() not available"); }

	inline void aspects(unordered_shoal_a < > const & shoal )
	{ throw dis("dynamic operation_d::aspects(shoal) not available"); }

	inline void assign(operation_a < > const & operation )
	{ throw dis("dynamic operation_d::assign(operation) not available"); }

	inline any_a<> names__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("names_");
		if (!op)
		{
			throw dis("dynamic operation_d::names_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline flock_a<> names_() const
	{
		assert(handle_);
		auto const op = operation("names_");
		if (!op)
		{
			throw dis("dynamic operation_d::names_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	explicit operation_d(any_a<> const& thing)
		: any_a{ thing }
	{}
};

template <typename _1_>
inline operation_d<_1_> ___operation_dynamic___(any_a<> const& thing)
{
	return operation_d<_1_>{ thing };
}

} // namespace
