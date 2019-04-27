%struct_prefix%_a final : public ___derived___
{
public:
	%nonvirtual_members% //TODO move params

private:
	struct ___finale_handle_base___ : ___derived_handle_base___
	{
		%pure_virtual_members%
	};

	template <typename ___TTT___>
	struct ___finale_handle_final___ final : ___derived_handle___<___TTT___, ___finale_handle_base___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: ___derived_handle___<___TTT___, ___finale_handle_base___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: ___derived_handle___<___TTT___, ___finale_handle_base___>{ std::move(value) }
		{}

		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
		{
			return std::make_shared<___finale_handle_final___>(___derived_handle___<___TTT___, ___finale_handle_base___>::value_);
		}

		%virtual_members% //TODO final / move params
	};

	template <typename ___TTT___>
	struct ___finale_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___finale_handle_final___<___TTT___&>
	{
		inline ___finale_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___finale_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline const ___finale_handle_base___& read() const
	{
		return *std::static_pointer_cast<const ___finale_handle_base___>(handle_);
	}

	inline ___finale_handle_base___& write()
	{
		if (!___reference___ && !handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___finale_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename D>
	friend inline bool check_(const %struct_name%_a<D>& value);

public:
	static inline const char* ___abstraction_name___()
	{
		return "%struct_name%";
	}

	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>& handle)
	{
		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
	}

	inline %struct_name%_a() = default;

	explicit inline %struct_name%_a(bool reference)
		: ___derived___{ reference }
	{}

	inline %struct_name%_a(const %struct_name%_a& other, bool reference)
		: ___derived___(other, reference)
	{}

	inline %struct_name%_a(%struct_name%_a&& other, bool reference)
		: ___derived___(std::move(other), reference)
	{}

	template <typename ___TTT___>
	explicit inline %struct_name%_a(const std::shared_ptr<___TTT___>& handle, bool reference = false)
		: ___derived___(handle, reference)
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))
		{
			throw dis__("%struct_name% constructor failed to cast from base to final");
		}
#else
		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
#endif
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<%struct_name%_a, std::decay_t<___TTT___>>::value>>
	explicit inline %struct_name%_a(___TTT___ value, bool reference = false)
		: ___derived___(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
			reference)
	{}

	template <typename ___TTT___>
	inline %struct_name%_a& operator=(const std::shared_ptr<___TTT___>& handle)
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))
		{
			throw dis__("%struct_name% assignment failed to cast from base to final");
		}
#else
		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
#endif
		handle_ = handle;
		handle_->___weak___(handle_);
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<%struct_name%_a, std::decay_t<___TTT___>>::value>>
	inline %struct_name%_a& operator=(___TTT___ value)
	{
		%struct_name%_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		handle_->___weak___(handle_);
		return *this;
	}
};

template <typename ___TTT___, typename D>
inline bool check_(const %struct_name%_a<D>& value)
{
	return ___TTT___::___check___(value.handle_);
}

#undef ___derived___