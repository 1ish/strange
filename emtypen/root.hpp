%struct_prefix%
{
public:
	inline operator bool() const
	{
		assert(handle_); return read().operator bool();
	}

	%nonvirtual_members%

protected:
	struct ___root_handle_base___
	{
		___root_handle_base___() = default;
		___root_handle_base___(const ___root_handle_base___&) = default;
		___root_handle_base___(___root_handle_base___&&) = default;
		___root_handle_base___& operator=(const ___root_handle_base___&) = default;
		___root_handle_base___& operator=(___root_handle_base___&&) = default;
		virtual ~___root_handle_base___() = default;

		virtual std::shared_ptr<___root_handle_base___> ___clone___() const = 0;

		virtual inline operator bool() const = 0;

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

		virtual inline operator bool() const
		{
			return value_.operator bool();
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

	const bool ___reference___;

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

	inline const ___root_handle_base___& read() const
	{
		return *handle_;
	}

	inline ___root_handle_base___& write()
	{
		if (!___reference___ && !handle_.unique())
		{
			handle_ = handle_->___clone___();
		}
		return *handle_;
	}

	template <typename ___TTT___>
	friend inline bool check_(const %struct_name%& value);

	template <typename ___TTT___>
	friend inline ___TTT___ cast_(const %struct_name%& value, bool reference = false);

public:
	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>&)
	{
		return true;
	}

	inline %struct_name% (bool reference = false)
		: handle_{}
		, ___reference___{ reference }
	{}

	inline %struct_name% (const %struct_name%& other)
		: handle_{ other.handle_ }
		, ___reference___{ false }
	{}

	inline %struct_name% (%struct_name%&& other)
		: handle_{ std::move(other.handle_) }
		, ___reference___{ false }
	{}

	inline %struct_name%& operator=(const %struct_name%& other)
	{
		handle_ = other.handle_;
		return *this;
	}

	inline %struct_name%& operator=(%struct_name%&& other)
	{
		handle_ = std::move(other.handle_);
		return *this;
	}

	virtual ~%struct_name%() = default;

	template <typename ___TTT___>
	inline %struct_name%(const std::shared_ptr<___TTT___>& handle, bool reference = false)
		: handle_{ handle }
		, ___reference___{ reference }
	{}

	template <typename ___TTT___>
	inline %struct_name%(___TTT___ value, bool reference = false);

	template <typename ___TTT___>
	inline %struct_name%& operator=(const std::shared_ptr<___TTT___>& handle)
	{
		handle_ = handle;
		return *this;
	}

	template <typename ___TTT___>
	inline %struct_name%& operator=(___TTT___ value);
};

template <typename ___TTT___>
inline bool check_(const %struct_name%& value)
{
	return ___TTT___::___check___(value.handle_);
}

template <typename ___TTT___, typename ___VVV___>
inline bool check_(const ___VVV___&)
{
	return false;
}

template <typename ___TTT___>
inline ___TTT___ cast_(const %struct_name%& value, bool reference)
{
	return ___TTT___(value.handle_, reference);
}

template <typename ___TTT___>
inline %struct_name%::%struct_name%(___TTT___ value, bool reference)
	: handle_{ check_<%struct_name%>(value)
		? cast_<%struct_name%>(value).handle_
		: std::make_shared<___root_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	, ___reference___{ reference }
{}

template <typename ___TTT___>
inline %struct_name%& %struct_name%::operator=(___TTT___ value)
{
	%struct_name% temp{ check_<%struct_name%>(value)
		? cast_<%struct_name%>(value)
		: std::move(value) };
	std::swap(temp.handle_, handle_);
	return *this;
}
