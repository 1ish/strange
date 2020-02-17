%struct_prefix% final : public ___derived___
{
public:
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

	inline %struct_name%& operator+=(___root___ const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline %struct_name%& operator-=(___root___ const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline %struct_name%& operator*=(___root___ const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline %struct_name%& operator/=(___root___ const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline %struct_name%& operator%=(___root___ const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	%nonvirtual_members%

private:
	struct ___finale_handle_base___ : ___derived_handle_base___
	{
		%pure_virtual_members%
	};

	template <typename ___TTT___>
	struct ___finale_handle_final___ final : ___derived_handle___<___TTT___, ___finale_handle_base___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___derived_handle___<___TTT___, ___finale_handle_base___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___derived_handle___<___TTT___, ___finale_handle_base___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___finale_handle_final___>(___derived_handle___<___TTT___, ___finale_handle_base___>::value_);
		}

		%virtual_members% //TODO final
	};

	template <typename ___TTT___>
	struct ___finale_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___finale_handle_final___<___TTT___&>
	{
		inline ___finale_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___finale_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___finale_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___finale_handle_base___ const>(handle_);
	}

	inline ___finale_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___finale_handle_base___>(handle_);
	}

	template <typename ___TTT___>
	friend inline bool check(%struct_name%<> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
	}

	inline %struct_name%() = default;

	static inline %struct_name% val(%struct_name% const& other) noexcept
	{
		return %struct_name%{ other };
	}

	inline %struct_name%(%struct_name%& other, ___reference_tag___) noexcept
		: ___derived___(other, ___reference_tag___{})
	{}

	static inline %struct_name% ref(%struct_name%& other) noexcept
	{
		return %struct_name%(other, ___reference_tag___{});
	}

	inline %struct_name%(%struct_name%& other, ___duplicate_tag___) noexcept
		: ___derived___(other, ___duplicate_tag___{})
	{}

	static inline %struct_name% dup(%struct_name%& other) noexcept
	{
		return %struct_name%(other, ___duplicate_tag___{});
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline %struct_name%(std::shared_ptr<___TTT___> const& handle)
		: ___derived___{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))
		{
			throw dis("%struct_name% constructor failed to cast from base to final");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline %struct_name%(std::shared_ptr<___TTT___> const& handle) noexcept
		: ___derived___{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline %struct_name%(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: ___derived___(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))
		{
			throw dis("%struct_name% constructor failed to cast from base to final");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline %struct_name%(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: ___derived___(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<%struct_name%, std::decay_t<___TTT___>>::value>>
	explicit inline %struct_name%(___TTT___ value) noexcept
		: ___derived___{ std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline %struct_name%& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))
		{
			throw dis("%struct_name% assignment failed to cast from base to final");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline %struct_name%& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<%struct_name%, std::decay_t<___TTT___>>::value>>
	inline %struct_name%& operator=(___TTT___ value) noexcept
	{
		%struct_name% temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
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

template <typename ___1___>
bool const %struct_name%<___1___>::___share___ = []()
{
	auto& shoal = shared();
	reflection<%struct_name%<___1___>>::share(shoal);
	return shoal;
}();

#undef ___derived___