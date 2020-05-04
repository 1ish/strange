
namespace strange
{

template <typename _element = any_a<> >
class range_d;

template <typename _element = any_a<> >
inline range_d<_element> ___range_dynamic___(any_a<> const& thing);

template <typename _element>
class range_a : public list_a<>
{
public:
	inline any_a<> extract_begin__(list_a<> const& ___arguments___) const;

	inline forward_extractor_a< _element > extract_begin_() const;

	inline any_a<> extract_end__(list_a<> const& ___arguments___) const;

	inline forward_extractor_a< _element > extract_end_() const;

protected:
	struct ___range_a_handle_base___ : list_a<>::___list_a_handle_base___
	{
		virtual forward_extractor_a< _element > extract_begin_() const = 0;
		virtual forward_extractor_a< _element > extract_end_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___range_a_handle_base___>
	struct ___range_a_handle___ : list_a<>::template ___list_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___range_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: list_a<>::template ___list_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___range_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: list_a<>::template ___list_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___range_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: list_a<>::template ___list_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline forward_extractor_a< _element > extract_begin_() const final;

		virtual inline forward_extractor_a< _element > extract_end_() const final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___range_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___range_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___range_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___range_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___range_a_handle_final___ final : ___range_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___range_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___range_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___range_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___range_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___range_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___range_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___range_a_handle_final___>(___range_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___range_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___range_a_handle_final___<___TTT___&>
	{
		inline ___range_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___range_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___range_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___range_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___range_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___range_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline range_a val(range_a const& other) noexcept
	{
		return range_a{ other };
	}

	static inline range_a ref(range_a& other) noexcept
	{
		return range_a(other, any_a<>::___reference_tag___{});
	}

	static inline range_a dup(range_a& other) noexcept
	{
		return range_a(other, any_a<>::___duplicate_tag___{});
	}

	inline range_a() = default;

	inline range_a(range_a& other, any_a<>::___reference_tag___) noexcept
		: list_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline range_a(range_a& other, any_a<>::___duplicate_tag___) noexcept
		: list_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline range_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: list_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___range_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline range_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: list_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___range_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<range_a, std::decay_t<___TTT___>>::value>>
	explicit inline range_a(___TTT___ value) noexcept
		: list_a<>{ std_make_shared<___range_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline range_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: list_a<>{ std_make_shared<___range_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline range_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___range_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<range_a, std::decay_t<___TTT___>>::value>>
	inline range_a& operator=(___TTT___ value) noexcept
	{
		range_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___range_a_handle_base___>(thing.___handle___) };
	}

	static inline range_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___range_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return range_a{ thing.___handle___ };
		}
		return range_a{ range_d<_element>{ thing } };
	}

	static inline range_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___range_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return range_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return range_a{ range_d<_element>(thing, any_a<>::___reference_tag___{}) };
	}

	static inline cat_a<> ___cat___();

	static inline unordered_herd_a<> ___cats___();

	static inline kind_a<> ___kind___();

	static inline unordered_herd_a<> ___kinds___();

	static inline unordered_shoal_a<> ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline range_a create(Args&&... args)
	{
		return range_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class range_a

template <typename _element>
class range_d : public list_d<>
{
public:
	inline any_a<> extract_begin__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("extract_begin_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic range_d::extract_begin_ passed non-existent member");
		}
		return op.operate(*const_cast<range_d*>(this), arguments);
	}

	inline forward_extractor_a< _element > extract_begin_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("extract_begin_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic range_d::extract_begin_ passed non-existent member");
		}
		return cast<forward_extractor_a< _element >>(variadic_operate(op, *const_cast<range_d*>(this)));
	}

	inline any_a<> extract_end__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("extract_end_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic range_d::extract_end_ passed non-existent member");
		}
		return op.operate(*const_cast<range_d*>(this), arguments);
	}

	inline forward_extractor_a< _element > extract_end_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("extract_end_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic range_d::extract_end_ passed non-existent member");
		}
		return cast<forward_extractor_a< _element >>(variadic_operate(op, *const_cast<range_d*>(this)));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit range_d(any_a<> const& thing)
		: list_d<>{ thing }
	{}

	explicit range_d(any_a<>& thing, any_a<>::___reference_tag___)
		: list_d<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit range_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: list_d<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
