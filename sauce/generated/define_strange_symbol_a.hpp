
namespace strange
{

template <typename ___TTT___, typename _1__chk = void>
inline bool check(symbol_a<_1__chk> const& value) noexcept;

template <typename _1_>
class symbol_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline symbol_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline symbol_a operator++(int)
	{
		assert(handle_);
		symbol_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline symbol_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline symbol_a operator--(int)
	{
		assert(handle_);
		symbol_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline symbol_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline symbol_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline symbol_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline symbol_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline symbol_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> to_lake__(range_a<> const& range) const
	{ assert(handle_); return read().to_lake__(range); }

	inline lake_int8_a<> to_lake_() const
	{ assert(handle_); return read().to_lake_(); }

	inline std :: string const & to_string() const
	{ assert(handle_); return read().to_string(); }

	inline int8_t first_character() const
	{ assert(handle_); return read().first_character(); }

	inline int8_t last_character() const
	{ assert(handle_); return read().last_character(); }

	inline any_a<> add__(range_a<> const& range) const
	{ assert(handle_); return read().add__(range); }

	inline symbol_a<> add_(symbol_a<> const& symbol) const
	{ assert(handle_); return read().add_(symbol); }

	inline symbol_a < > operator+(symbol_a < > const & symbol ) const
	{ assert(handle_); return read().operator+(symbol); }

protected:
	struct ___symbol_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> to_lake__(range_a<> const& range) const = 0;
		virtual lake_int8_a<> to_lake_() const = 0;
		virtual std :: string const & to_string() const = 0;
		virtual int8_t first_character() const = 0;
		virtual int8_t last_character() const = 0;
		virtual any_a<> add__(range_a<> const& range) const = 0;
		virtual symbol_a<> add_(symbol_a<> const& symbol) const = 0;
		virtual symbol_a < > operator+(symbol_a < > const & symbol ) const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___symbol_a_handle_base___>
	struct ___symbol_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___symbol_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___symbol_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> to_lake__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_lake__(range); }

		virtual inline lake_int8_a<> to_lake_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_lake_(); }

		virtual inline std :: string const & to_string() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_string(); }

		virtual inline int8_t first_character() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.first_character(); }

		virtual inline int8_t last_character() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.last_character(); }

		virtual inline any_a<> add__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.add__(range); }

		virtual inline symbol_a<> add_(symbol_a<> const& symbol) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.add_(symbol); }

		virtual inline symbol_a < > operator+(symbol_a < > const & symbol ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator+(symbol); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___symbol_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___symbol_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___symbol_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___symbol_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___symbol_a_handle_final___ final : ___symbol_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___symbol_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___symbol_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___symbol_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___symbol_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___symbol_a_handle_final___>(___symbol_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___symbol_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___symbol_a_handle_final___<___TTT___&>
	{
		inline ___symbol_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___symbol_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___symbol_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___symbol_a_handle_base___ const>(handle_);
	}

	inline ___symbol_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___symbol_a_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(symbol_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___symbol_a_handle_base___>(handle));
	}

	static inline symbol_a val(symbol_a const& other) noexcept
	{
		return symbol_a{ other };
	}

	static inline symbol_a ref(symbol_a& other) noexcept
	{
		return symbol_a(other, ___reference_tag___{});
	}

	static inline symbol_a dup(symbol_a& other) noexcept
	{
		return symbol_a(other, ___duplicate_tag___{});
	}

	inline symbol_a() = default;

	inline symbol_a(symbol_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline symbol_a(symbol_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline symbol_a(std::shared_ptr<___TTT___> const& handle)
		: any_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___symbol_a_handle_base___>(handle))
		{
			throw dis("symbol_a constructor failed to cast from base to symbol_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline symbol_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___symbol_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline symbol_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: any_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___symbol_a_handle_base___>(handle))
		{
			throw dis("symbol_a constructor failed to cast from base to symbol_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline symbol_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___symbol_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<symbol_a, std::decay_t<___TTT___>>::value>>
	explicit inline symbol_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___symbol_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline symbol_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___symbol_a_handle_base___>(handle))
		{
			throw dis("symbol_a assignment failed to cast from base to symbol_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline symbol_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___symbol_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<symbol_a, std::decay_t<___TTT___>>::value>>
	inline symbol_a& operator=(___TTT___ value) noexcept
	{
		symbol_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___symbol_a_share___;
}; // class symbol_a

template <typename ___TTT___, typename _1__chk>
inline bool check(symbol_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const symbol_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<symbol_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_ = void>
class symbol_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline symbol_d& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline symbol_d operator++(int)
	{
		assert(handle_);
		symbol_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline symbol_d& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline symbol_d operator--(int)
	{
		assert(handle_);
		symbol_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline symbol_d& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline symbol_d& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline symbol_d& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline symbol_d& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline symbol_d& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> to_lake__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("to_lake_");
		if (!op)
		{
			throw dis("dynamic symbol_d::to_lake_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline lake_int8_a<> to_lake_() const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("to_lake_");
		if (!op)
		{
			throw dis("dynamic symbol_d::to_lake_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline std :: string const & to_string() const
	{ throw dis("dynamic symbol_d::to_string() not available"); }

	inline int8_t first_character() const
	{ throw dis("dynamic symbol_d::first_character() not available"); }

	inline int8_t last_character() const
	{ throw dis("dynamic symbol_d::last_character() not available"); }

	inline any_a<> add__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("add_");
		if (!op)
		{
			throw dis("dynamic symbol_d::add_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline symbol_a<> add_(symbol_a<> const& symbol) const
	{
		assert(handle_);
		auto const op = read().operations_().at_string("add_");
		if (!op)
		{
			throw dis("dynamic symbol_d::add_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this), symbol);
	}

	inline symbol_a < > operator+(symbol_a < > const & symbol ) const
	{ throw dis("dynamic symbol_d::operator+(symbol) not available"); }

};

} // namespace
