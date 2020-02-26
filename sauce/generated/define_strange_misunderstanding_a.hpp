
namespace strange
{

template <typename _1_ = void>
class misunderstanding_d;

template <typename _1_ = void>
inline misunderstanding_d<_1_> ___misunderstanding_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(misunderstanding_a<_1__chk> const& value) noexcept;

template <typename _1_>
class misunderstanding_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline misunderstanding_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline misunderstanding_a operator++(int)
	{
		assert(handle_);
		misunderstanding_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline misunderstanding_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline misunderstanding_a operator--(int)
	{
		assert(handle_);
		misunderstanding_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline misunderstanding_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline misunderstanding_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline misunderstanding_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline misunderstanding_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline misunderstanding_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline std :: string to_string() const
	{ assert(handle_); return read().to_string(); }

	inline any_a<> add__(range_a<> const& range) const
	{ assert(handle_); return read().add__(range); }

	inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const
	{ assert(handle_); return read().add_(misunderstanding); }

	inline misunderstanding_a < > operator+(misunderstanding_a < > const & misunderstanding ) const
	{ assert(handle_); return read().operator+(misunderstanding); }

protected:
	struct ___misunderstanding_a_handle_base___ : ___any_a_handle_base___
	{
		virtual std :: string to_string() const = 0;
		virtual any_a<> add__(range_a<> const& range) const = 0;
		virtual misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const = 0;
		virtual misunderstanding_a < > operator+(misunderstanding_a < > const & misunderstanding ) const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___misunderstanding_a_handle_base___>
	struct ___misunderstanding_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline std :: string to_string() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_string(); }

		virtual inline any_a<> add__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.add__(range); }

		virtual inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.add_(misunderstanding); }

		virtual inline misunderstanding_a < > operator+(misunderstanding_a < > const & misunderstanding ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator+(misunderstanding); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___misunderstanding_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___misunderstanding_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___misunderstanding_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___misunderstanding_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___misunderstanding_a_handle_final___ final : ___misunderstanding_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___misunderstanding_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___misunderstanding_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___misunderstanding_a_handle_final___>(___misunderstanding_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___misunderstanding_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___misunderstanding_a_handle_final___<___TTT___&>
	{
		inline ___misunderstanding_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___misunderstanding_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___misunderstanding_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___misunderstanding_a_handle_base___ const>(handle_);
	}

	inline ___misunderstanding_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___misunderstanding_a_handle_base___>(handle_);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(misunderstanding_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle));
	}

	static inline misunderstanding_a val(misunderstanding_a const& other) noexcept
	{
		return misunderstanding_a{ other };
	}

	static inline misunderstanding_a ref(misunderstanding_a& other) noexcept
	{
		return misunderstanding_a(other, ___reference_tag___{});
	}

	static inline misunderstanding_a dup(misunderstanding_a& other) noexcept
	{
		return misunderstanding_a(other, ___duplicate_tag___{});
	}

	inline misunderstanding_a() = default;

	inline misunderstanding_a(misunderstanding_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline misunderstanding_a(misunderstanding_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline misunderstanding_a(std::shared_ptr<___TTT___> const& handle)
		: any_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle))
		{
			throw dis("misunderstanding_a constructor failed to cast from base to misunderstanding_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline misunderstanding_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline misunderstanding_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: any_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle))
		{
			throw dis("misunderstanding_a constructor failed to cast from base to misunderstanding_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline misunderstanding_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<misunderstanding_a, std::decay_t<___TTT___>>::value>>
	explicit inline misunderstanding_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___misunderstanding_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline misunderstanding_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle))
		{
			throw dis("misunderstanding_a assignment failed to cast from base to misunderstanding_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline misunderstanding_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<misunderstanding_a, std::decay_t<___TTT___>>::value>>
	inline misunderstanding_a& operator=(___TTT___ value) noexcept
	{
		misunderstanding_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___misunderstanding_a_share___;
}; // class misunderstanding_a

template <typename ___TTT___, typename _1__chk>
inline bool check(misunderstanding_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const misunderstanding_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<misunderstanding_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class misunderstanding_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline misunderstanding_d& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline misunderstanding_d operator++(int)
	{
		assert(handle_);
		misunderstanding_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline misunderstanding_d& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline misunderstanding_d operator--(int)
	{
		assert(handle_);
		misunderstanding_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline misunderstanding_d& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline misunderstanding_d& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline misunderstanding_d& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline misunderstanding_d& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline misunderstanding_d& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline std :: string to_string() const
	{ throw dis("dynamic misunderstanding_d::to_string() not available"); }

	inline any_a<> add__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic misunderstanding_d::add_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const
	{
		assert(handle_);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic misunderstanding_d::add_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this), misunderstanding);
	}

	inline misunderstanding_a < > operator+(misunderstanding_a < > const & misunderstanding ) const
	{ return add_(misunderstanding); }

	explicit misunderstanding_d(any_a<> const& thing)
		: any_a{ thing }
	{}
};

template <typename _1_>
inline misunderstanding_d<_1_> ___misunderstanding_dynamic___(any_a<> const& thing)
{
	return misunderstanding_d<_1_>{ thing };
}

} // namespace
