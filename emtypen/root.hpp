%struct_prefix%
{
public:
	class hash_f
	{
	public:
		inline std::size_t operator()(%struct_name% const& thing) const
		{
			return thing.hash();
		}
	};

	inline any_a operator[](range_a const& range)
	{
		return invoke_(*this, range);
	}

	inline any_a operator()(range_a const& range)
	{
		return operate_(*this, range);
	}

	inline operator bool() const
	{
		assert(handle_);
		return read().operator bool();
	}

	inline %struct_name%& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

	inline %struct_name% operator++(int)
	{
		assert(handle_);
		%struct_name% result = *this;
		write().operator++();
		return result;
	}

	inline %struct_name%& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

	inline %struct_name% operator--(int)
	{
		assert(handle_);
		%struct_name% result = *this;
		write().operator--();
		return result;
	}

	inline %struct_name%& operator+=(%struct_name% const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline %struct_name%& operator-=(%struct_name% const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline %struct_name%& operator*=(%struct_name% const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline %struct_name%& operator/=(%struct_name% const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline %struct_name%& operator%=(%struct_name% const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	%nonvirtual_members%

protected:
	struct ___root_handle_base___
	{
		___root_handle_base___() = default;
		___root_handle_base___(___root_handle_base___ const&) = default;
		___root_handle_base___(___root_handle_base___&&) = default;
		___root_handle_base___& operator=(___root_handle_base___ const&) = default;
		___root_handle_base___& operator=(___root_handle_base___&&) = default;
		virtual ~___root_handle_base___() = default;

		virtual std::shared_ptr<___root_handle_base___> ___clone___() const = 0;

		virtual void ___weak___(std::weak_ptr<___root_handle_base___> const& weak) const = 0;

		virtual inline operator bool() const = 0;

		virtual inline void operator++() = 0;

		virtual inline void operator--() = 0;

		virtual inline void operator+=(%struct_name% const& other) = 0;

		virtual inline void operator-=(%struct_name% const& other) = 0;

		virtual inline void operator*=(%struct_name% const& other) = 0;

		virtual inline void operator/=(%struct_name% const& other) = 0;

		virtual inline void operator%=(%struct_name% const& other) = 0;

		%pure_virtual_members%
	};

	template <typename ___TTT___, typename ___BHB___ = ___root_handle_base___>
	struct ___root_handle___ : ___BHB___
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___root_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: value_{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___root_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: value_{ std::move(value) }
		{}

		virtual inline void ___weak___(std::weak_ptr<___root_handle_base___> const& weak) const final
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

		virtual inline void operator+=(%struct_name% const& other) final
		{
			value_.operator+=(other);
		}

		virtual inline void operator-=(%struct_name% const& other) final
		{
			value_.operator-=(other);
		}

		virtual inline void operator*=(%struct_name% const& other) final
		{
			value_.operator*=(other);
		}

		virtual inline void operator/=(%struct_name% const& other) final
		{
			value_.operator/=(other);
		}

		virtual inline void operator%=(%struct_name% const& other) final
		{
			value_.operator%=(other);
		}

		%virtual_members% //TODO final

		___TTT___ value_;
	};

	template <typename ___TTT___, typename ___BHB___>
	struct ___root_handle___<std::reference_wrapper<___TTT___>, ___BHB___>
		: ___root_handle___<___TTT___&, ___BHB___>
	{
		inline ___root_handle___(std::reference_wrapper<___TTT___> ref)
			: ___root_handle___<___TTT___&, ___BHB___>{ ref.get() }
		{}
	};

	std::shared_ptr<___root_handle_base___> handle_;

	bool const ___reference___;

private:
	template <typename ___TTT___>
	struct ___root_handle_final___ final : ___root_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___root_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: ___root_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___root_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: ___root_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
		{
			return std::make_shared<___root_handle_final___>(___root_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___root_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___root_handle_final___<___TTT___&>
	{
		inline ___root_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___root_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___root_handle_base___ const& read() const noexcept
	{
		return *handle_;
	}

	inline ___root_handle_base___& write() noexcept
	{
		if (!___reference___ && !handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *handle_;
	}

	template <typename ___TTT___>
	friend inline bool check(%struct_name%<> const& value) noexcept;

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	friend inline ___TTT___ cast(%struct_name%<> const& value, bool reference = false);
#else
	template <typename ___TTT___>
	friend inline ___TTT___ cast(%struct_name%<> const& value, bool reference = false) noexcept;
#endif

public:
	using ___WEAK___ = std::weak_ptr<___root_handle_base___>;

	static inline bool ___check___(std::shared_ptr<___root_handle_base___> const&) noexcept
	{
		return true;
	}

	inline %struct_name%() noexcept
		: handle_{}
		, ___reference___{ false }
	{}

	explicit inline %struct_name%(bool reference) noexcept
		: handle_{}
		, ___reference___{ reference }
	{}

	inline %struct_name%(%struct_name% const& other) noexcept
		: handle_{ other.handle_ }
		, ___reference___{ false }
	{
		handle_->___weak___(handle_);
	}

	inline %struct_name%(%struct_name% const& other, bool reference) noexcept
		: handle_{ other.handle_ }
		, ___reference___{ reference }
	{
		handle_->___weak___(handle_);
	}

	inline %struct_name%(%struct_name%&& other) noexcept
		: handle_{ std::move(other.handle_) }
		, ___reference___{ false }
	{
		handle_->___weak___(handle_);
	}

	inline %struct_name%(%struct_name%&& other, bool reference) noexcept
		: handle_{ std::move(other.handle_) }
		, ___reference___{ reference }
	{
		handle_->___weak___(handle_);
	}

	inline %struct_name%& operator=(%struct_name% const& other) noexcept
	{
		handle_ = other.handle_;
		handle_->___weak___(handle_);
		return *this;
	}

	inline %struct_name%& operator=(%struct_name%&& other) noexcept
	{
		handle_ = std::move(other.handle_);
		handle_->___weak___(handle_);
		return *this;
	}

	virtual ~%struct_name%() = default;

	template <typename ___TTT___>
	explicit inline %struct_name%(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
		: handle_{ handle }
		, ___reference___{ reference }
	{
		handle_->___weak___(handle_);
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<%struct_name%, std::decay_t<___TTT___>>::value>>
	explicit inline %struct_name%(___TTT___ value, bool reference = false) noexcept
		: handle_{ std::make_shared<___root_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
		, ___reference___{ reference }
	{
		handle_->___weak___(handle_);
	}

	template <typename ___TTT___>
	inline %struct_name%& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		handle_ = handle;
		handle_->___weak___(handle_);
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<%struct_name%, std::decay_t<___TTT___>>::value>>
	inline %struct_name%& operator=(___TTT___ value) noexcept
	{
		%struct_name% temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		handle_->___weak___(handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___%struct_name%_share___;
};

template <typename ___TTT___>
inline bool check(%struct_name%<> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename ___TTT___, typename ___VVV___>
inline bool check(___VVV___ const&) noexcept
{
	return false;
}

#ifdef STRANGE_CHECK_STATIC_CASTS
template <typename ___TTT___>
inline ___TTT___ cast(%struct_name%<> const& value, bool reference)
{
	return ___TTT___(value.handle_, reference);
}
#else
template <typename ___TTT___>
inline ___TTT___ cast(%struct_name%<> const& value, bool reference) noexcept
{
	return ___TTT___(value.handle_, reference);
}
#endif

template <typename ___1___, typename ___2___, typename ___3___, typename ___4___, typename ___5___, typename ___6___, typename ___7___, typename ___8___>
bool const %struct_name%<___1___, ___2___, ___3___, ___4___, ___5___, ___6___, ___7___, ___8___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	reflection<%struct_name%<___1___, ___2___, ___3___, ___4___, ___5___, ___6___, ___7___, ___8___>>::share(shoal);
	return shoal;
}();
