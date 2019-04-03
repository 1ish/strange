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
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
		}
		return *handle_;
	}

	template <typename ___TTT___>
	friend inline bool check_(const %struct_name%& v);

	template <typename ___TTT___>
	friend inline ___TTT___ static_(const %struct_name%& v);

public:
	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>&)
	{
		return true;
	}

	%struct_name% () = default;
	%struct_name% (const %struct_name%&) = default;
	%struct_name% (%struct_name%&&) = default;
	%struct_name%& operator=(const %struct_name%&) = default;
	%struct_name%& operator=(%struct_name%&&) = default;
	virtual ~%struct_name%() = default;

	template <typename ___TTT___>
	inline %struct_name%(const std::shared_ptr<___TTT___>& other)
		: handle_{ other }
	{}

	template <typename ___TTT___>
	inline %struct_name%(___TTT___ value);

	template <typename ___TTT___>
	inline %struct_name%& operator=(const std::shared_ptr<___TTT___>& other)
	{
		handle_ = other;
		return *this;
	}

	template <typename ___TTT___>
	inline %struct_name%& operator=(___TTT___ value);
};

template <typename ___TTT___>
inline bool check_(const %struct_name%& v)
{
	return ___TTT___::___check___(v.handle_);
}

template <typename ___TTT___, typename ___VVV___>
inline bool check_(const ___VVV___&)
{
	return false;
}

template <typename ___TTT___>
inline ___TTT___ static_(const %struct_name%& v)
{
	return ___TTT___{ v.handle_ };
}

template <typename ___TTT___>
inline %struct_name%::%struct_name%(___TTT___ value)
	: handle_{ check_<%struct_name%>(value)
		? static_<%struct_name%>(std::move(value)).handle_
		: std::make_shared<___root_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
{}

template <typename ___TTT___>
inline %struct_name%& %struct_name%::operator=(___TTT___ value)
{
	%struct_name% temp{ check_<%struct_name%>(value)
		? static_<%struct_name%>(std::move(value))
		: std::move(value) };
	std::swap(temp.handle_, handle_);
	return *this;
}
