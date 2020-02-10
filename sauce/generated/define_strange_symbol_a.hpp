
namespace strange
{

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

	inline symbol_a operator++(int)
	{
		assert(handle_);
		symbol_a result = *this;
		write().operator++();
		return result;
	}

	inline symbol_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

	inline symbol_a operator--(int)
	{
		assert(handle_);
		symbol_a result = *this;
		write().operator--();
		return result;
	}

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
	struct ___symbol_a_handle_base___
	{
		___symbol_a_handle_base___() = default;
		___symbol_a_handle_base___(___symbol_a_handle_base___ const&) = default;
		___symbol_a_handle_base___(___symbol_a_handle_base___&&) = default;
		___symbol_a_handle_base___& operator=(___symbol_a_handle_base___ const&) = default;
		___symbol_a_handle_base___& operator=(___symbol_a_handle_base___&&) = default;
		virtual ~___symbol_a_handle_base___() = default;
		virtual ___SHARED___ ___clone___() const = 0;
		virtual void ___weak___(___WEAK___ const& weak) const = 0;
		virtual inline operator bool() const = 0;
		virtual inline void operator++() = 0;
		virtual inline void operator--() = 0;
		virtual inline void operator+=(any_a<> const& other) = 0;
		virtual inline void operator-=(any_a<> const& other) = 0;
		virtual inline void operator*=(any_a<> const& other) = 0;
		virtual inline void operator/=(any_a<> const& other) = 0;
		virtual inline void operator%=(any_a<> const& other) = 0;
		virtual inline any_a<> to_lake__(range_a<> const& range) const = 0;
		virtual inline lake_int8_a<> to_lake_() const = 0;
		virtual inline std :: string const & to_string() const = 0;
		virtual inline int8_t first_character() const = 0;
		virtual inline int8_t last_character() const = 0;
		virtual inline any_a<> add__(range_a<> const& range) const = 0;
		virtual inline symbol_a<> add_(symbol_a<> const& symbol) const = 0;
		virtual inline symbol_a < > operator+(symbol_a < > const & symbol ) const = 0;
	};

	template <typename ___TTT___, typename ___BHB___ = ___symbol_a_handle_base___>
	struct ___symbol_a_handle___ : ___BHB___
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___symbol_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: value_{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___symbol_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: value_{ std::move(value) }
		{}

		virtual inline void ___weak___(___WEAK___ const& weak) const final
		{
			value_.___weak___(weak);
		}

		virtual inline operator bool() const final
		{
			return value_.operator bool();
		}

		virtual inline void operator++() final
		{
			value_.operator++();
		}

		virtual inline void operator--() final
		{
			value_.operator--();
		}

		virtual inline void operator+=(any_a<> const& other) final
		{
			value_.operator+=(other);
		}

		virtual inline void operator-=(any_a<> const& other) final
		{
			value_.operator-=(other);
		}

		virtual inline void operator*=(any_a<> const& other) final
		{
			value_.operator*=(other);
		}

		virtual inline void operator/=(any_a<> const& other) final
		{
			value_.operator/=(other);
		}

		virtual inline void operator%=(any_a<> const& other) final
		{
			value_.operator%=(other);
		}

		virtual inline any_a<> to_lake__(range_a<> const& range) const final
		{ return value_.to_lake__(range); }

		virtual inline lake_int8_a<> to_lake_() const final
		{ return value_.to_lake_(); }

		virtual inline std :: string const & to_string() const final
		{ return value_.to_string(); }

		virtual inline int8_t first_character() const final
		{ return value_.first_character(); }

		virtual inline int8_t last_character() const final
		{ return value_.last_character(); }

		virtual inline any_a<> add__(range_a<> const& range) const final
		{ return value_.add__(range); }

		virtual inline symbol_a<> add_(symbol_a<> const& symbol) const final
		{ return value_.add_(symbol); }

		virtual inline symbol_a < > operator+(symbol_a < > const & symbol ) const final
		{ return value_.operator+(symbol); }

		___TTT___ value_;
	};

	template <typename ___TTT___, typename ___BHB___>
	struct ___symbol_a_handle___<std::reference_wrapper<___TTT___>, ___BHB___>
		: ___symbol_a_handle___<___TTT___&, ___BHB___>
	{
		inline ___symbol_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___symbol_a_handle___<___TTT___&, ___BHB___>{ ref.get() }
		{}
	};

	___SHARED___ ___shared___;

	___SHARED___& handle_;

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
		return *handle_;
	}

	inline ___symbol_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *handle_;
	}

	template <typename ___TTT___>
	friend inline bool check(symbol_a<> const& value) noexcept;

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	friend inline ___TTT___ cast(symbol_a<> const& value);
#else
	template <typename ___TTT___>
	friend inline ___TTT___ cast(symbol_a<> const& value) noexcept;
#endif
#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	friend inline ___TTT___ cast_ref(symbol_a<>& value);
#else
	template <typename ___TTT___>
	friend inline ___TTT___ cast_ref(symbol_a<>& value) noexcept;
#endif
#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	friend inline ___TTT___ cast_dup(symbol_a<>& value);
#else
	template <typename ___TTT___>
	friend inline ___TTT___ cast_dup(symbol_a<>& value) noexcept;
#endif

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(handle);
	}

	inline bool is_ref() const
	{
		return &handle_ != &___shared___;
	}

	inline symbol_a() noexcept
		: ___shared___{}
		, handle_{ ___shared___ }
	{}

	inline symbol_a(symbol_a const& other) noexcept
		: ___shared___{ other.handle_ }
		, handle_{ ___shared___ }
	{}

	static inline symbol_a val(symbol_a const& other) noexcept
	{
		return symbol_a{ other };
	}

	inline symbol_a(symbol_a& other, ___reference_tag___) noexcept
		: ___shared___{ ___SHARED___{} }
		, handle_{ other.handle_ }
	{}

	static inline symbol_a ref(symbol_a& other) noexcept
	{
		return symbol_a(other, ___reference_tag___{});
	}

	inline symbol_a(symbol_a& other, ___duplicate_tag___) noexcept
		: ___shared___{ &other.handle_ == &other.___shared___ ? other.handle_ : ___SHARED___{} }
		, handle_{ *(&other.handle_ == &other.___shared___ ? &___shared___ : &other.handle_) }
	{}

	static inline symbol_a dup(symbol_a& other) noexcept
	{
		return symbol_a(other, ___duplicate_tag___{});
	}

	inline symbol_a(symbol_a&& other) noexcept
	: ___shared___{ other.handle_ }
	, handle_{ ___shared___ }
	{}

	inline symbol_a& operator=(symbol_a const& other) noexcept
	{
		handle_ = other.handle_;
		return *this;
	}

	inline symbol_a& operator=(symbol_a&& other) noexcept
	{
		handle_ = other.handle_;
		return *this;
	}

	virtual ~symbol_a() = default;

	template <typename ___TTT___>
	explicit inline symbol_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: ___shared___{ handle }
		, handle_{ ___shared___ }
	{}

	template <typename ___TTT___>
	explicit inline symbol_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: ___shared___{ ___SHARED___{} }
		, handle_{ reinterpret_cast<___SHARED___&>(handle) }
	{}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<symbol_a, std::decay_t<___TTT___>>::value>>
	explicit inline symbol_a(___TTT___ value) noexcept
		: ___shared___{ std::make_shared<___symbol_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
		, handle_{ ___shared___ }
	{
		handle_->___weak___(handle_);
	}

	template <typename ___TTT___>
	inline symbol_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		handle_ = handle;
		return *this;
	}

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

template <typename _1_>
bool const symbol_a<_1_>>::___share___ = []()
{
	auto& shoal = shared();
	reflection<symbol_a<_1_>>>::share(shoal);
	return shoal.something();
}();

} // namespace
