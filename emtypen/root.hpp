%struct_prefix%
{
public:
	class hash_f
	{
	public:
		inline std::size_t operator()(%struct_name% const& thing) const
		{
			return thing.hash__();
		}
	};

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

	%nonvirtual_members% //TODO move params

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

		%virtual_members% //TODO final / move params

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

	inline ___root_handle_base___ const& read() const
	{
		return *handle_;
	}

	inline ___root_handle_base___& write()
	{
		if (!___reference___ && !handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *handle_;
	}

	template <typename ___TTT___>
	friend inline bool check_(%struct_name%<> const& value);

	template <typename ___TTT___>
	friend inline ___TTT___ cast_(%struct_name%<> const& value, bool reference = false);

public:
	using ___WEAK___ = std::weak_ptr<___root_handle_base___>;

	static inline char const* ___abstraction_name___()
	{
		return "%struct_name%";
	}

	static inline bool ___check___(std::shared_ptr<___root_handle_base___> const&)
	{
		return true;
	}

	inline %struct_name%()
		: handle_{}
		, ___reference___{ false }
	{}

	explicit inline %struct_name%(bool reference)
		: handle_{}
		, ___reference___{ reference }
	{}

	inline %struct_name%(%struct_name% const& other)
		: handle_{ other.handle_ }
		, ___reference___{ false }
	{
		handle_->___weak___(handle_);
	}

	inline %struct_name%(%struct_name% const& other, bool reference)
		: handle_{ other.handle_ }
		, ___reference___{ reference }
	{
		handle_->___weak___(handle_);
	}

	inline %struct_name%(%struct_name%&& other)
		: handle_{ std::move(other.handle_) }
		, ___reference___{ false }
	{
		handle_->___weak___(handle_);
	}

	inline %struct_name%(%struct_name%&& other, bool reference)
		: handle_{ std::move(other.handle_) }
		, ___reference___{ reference }
	{
		handle_->___weak___(handle_);
	}

	inline %struct_name%& operator=(%struct_name% const& other)
	{
		handle_ = other.handle_;
		handle_->___weak___(handle_);
		return *this;
	}

	inline %struct_name%& operator=(%struct_name%&& other)
	{
		handle_ = std::move(other.handle_);
		handle_->___weak___(handle_);
		return *this;
	}

	virtual ~%struct_name%() = default;

	template <typename ___TTT___>
	explicit inline %struct_name%(std::shared_ptr<___TTT___> const& handle, bool reference = false)
		: handle_{ handle }
		, ___reference___{ reference }
	{
		handle_->___weak___(handle_);
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<%struct_name%, std::decay_t<___TTT___>>::value>>
	explicit inline %struct_name%(___TTT___ value, bool reference = false)
		: handle_{ std::make_shared<___root_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
		, ___reference___{ reference }
	{
		handle_->___weak___(handle_);
	}

	template <typename ___TTT___>
	inline %struct_name%& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		handle_ = handle;
		handle_->___weak___(handle_);
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<%struct_name%, std::decay_t<___TTT___>>::value>>
	inline %struct_name%& operator=(___TTT___ value)
	{
		%struct_name% temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		handle_->___weak___(handle_);
		return *this;
	}
};

template <typename ___TTT___>
inline bool check_(%struct_name%<> const& value)
{
	return ___TTT___::___check___(value.handle_);
}

template <typename ___TTT___, typename ___VVV___>
inline bool check_(___VVV___ const&)
{
	return false;
}

template <typename ___TTT___>
inline ___TTT___ cast_(%struct_name%<> const& value, bool reference)
{
	return ___TTT___(value.handle_, reference);
}
