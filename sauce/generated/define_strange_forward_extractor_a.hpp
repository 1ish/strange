
namespace strange
{

template <typename _element>
class forward_extractor_d;

template <typename _element>
inline forward_extractor_d<_element> ___forward_extractor_dynamic___(any_a<> const& thing);

template <typename _element>
class forward_extractor_a : public any_a<>
{
public:
	inline any_a<> get__(list_a<> const& ___arguments___) const;

	inline _element get_() const;

	inline _element const & operator*() const;

	inline _element const * operator->() const;

	inline any_a<> increment__(list_a<> const& ___arguments___);

	inline forward_extractor_a increment_();

	inline forward_extractor_a& operator++();

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline forward_extractor_a operator++(int);
#endif

	inline any_a<> to_extractor_any__(list_a<> const& ___arguments___) const;

	inline forward_extractor_a< any_a<> > to_extractor_any_() const;

protected:
	struct ___forward_extractor_a_handle_base___ : any_a<>::___any_a_handle_base___
	{
		virtual _element get_() const = 0;
		virtual _element const & operator*() const = 0;
		virtual _element const * operator->() const = 0;
		virtual void increment_() = 0;
		virtual forward_extractor_a< any_a<> > to_extractor_any_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___forward_extractor_a_handle_base___>
	struct ___forward_extractor_a_handle___ : any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___forward_extractor_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___forward_extractor_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___forward_extractor_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline _element get_() const final;

		virtual inline _element const & operator*() const final;

		virtual inline _element const * operator->() const final;

		virtual inline void increment_() final;

		virtual inline forward_extractor_a< any_a<> > to_extractor_any_() const final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___forward_extractor_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___forward_extractor_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___forward_extractor_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___forward_extractor_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___forward_extractor_a_handle_final___ final : ___forward_extractor_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___forward_extractor_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___forward_extractor_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___forward_extractor_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___forward_extractor_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___forward_extractor_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___forward_extractor_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___forward_extractor_a_handle_final___>(___forward_extractor_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___forward_extractor_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___forward_extractor_a_handle_final___<___TTT___&>
	{
		inline ___forward_extractor_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___forward_extractor_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___forward_extractor_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___forward_extractor_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___forward_extractor_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___forward_extractor_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline forward_extractor_a val(forward_extractor_a const& other) noexcept
	{
		return forward_extractor_a{ other };
	}

	static inline forward_extractor_a ref(forward_extractor_a& other) noexcept
	{
		return forward_extractor_a(other, any_a<>::___reference_tag___{});
	}

	static inline forward_extractor_a dup(forward_extractor_a& other) noexcept
	{
		return forward_extractor_a(other, any_a<>::___duplicate_tag___{});
	}

	inline forward_extractor_a() = default;

	inline forward_extractor_a(forward_extractor_a& other, any_a<>::___reference_tag___) noexcept
		: any_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline forward_extractor_a(forward_extractor_a& other, any_a<>::___duplicate_tag___) noexcept
		: any_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline forward_extractor_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: any_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_extractor_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline forward_extractor_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: any_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_extractor_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_extractor_a, std::decay_t<___TTT___>>::value>>
	explicit inline forward_extractor_a(___TTT___ value) noexcept
		: any_a<>{ std_make_shared<___forward_extractor_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline forward_extractor_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a<>{ std_make_shared<___forward_extractor_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline forward_extractor_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_extractor_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_extractor_a, std::decay_t<___TTT___>>::value>>
	inline forward_extractor_a& operator=(___TTT___ value) noexcept
	{
		forward_extractor_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___forward_extractor_a_handle_base___>(thing.___handle___) };
	}

	static inline forward_extractor_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___forward_extractor_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return forward_extractor_a{ thing.___handle___ };
		}
		return forward_extractor_a{ forward_extractor_d<_element>{ thing } };
	}

	static inline forward_extractor_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___forward_extractor_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return forward_extractor_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return forward_extractor_a{ forward_extractor_d<_element>(thing, any_a<>::___reference_tag___{}) };
	}

	static inline cat_a<> ___cat___();

	static inline unordered_herd_a<> ___cats___();

	static inline kind_a<> ___kind___();

	static inline unordered_herd_a<> ___kinds___();

	static inline unordered_shoal_a<> ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline forward_extractor_a create(Args&&... args)
	{
		return forward_extractor_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class forward_extractor_a

template <typename _element>
class forward_extractor_d : public any_a<>
{
public:
	inline any_a<> get__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("get_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic forward_extractor_d::get_ passed non-existent member");
		}
		return op.operate(*const_cast<forward_extractor_d*>(this), arguments);
	}

	inline _element get_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("get_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic forward_extractor_d::get_ passed non-existent member");
		}
		return cast<_element>(variadic_operate(op, *const_cast<forward_extractor_d*>(this)));
	}

	inline _element const & operator*() const
	{ throw dis(__FILE__, __LINE__, "dynamic forward_extractor_d::operator*() not available"); }

	inline _element const * operator->() const
	{ throw dis(__FILE__, __LINE__, "dynamic forward_extractor_d::operator->() not available"); }

	inline any_a<> increment__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("increment_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic forward_extractor_d::increment_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline forward_extractor_a< _element > increment_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("increment_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic forward_extractor_d::increment_ passed non-existent member");
		}
		return cast<forward_extractor_a< _element >>(variadic_operate(op, *this));
	}

	inline any_a<> to_extractor_any__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_extractor_any_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic forward_extractor_d::to_extractor_any_ passed non-existent member");
		}
		return op.operate(*const_cast<forward_extractor_d*>(this), arguments);
	}

	inline forward_extractor_a< any_a<> > to_extractor_any_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_extractor_any_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic forward_extractor_d::to_extractor_any_ passed non-existent member");
		}
		return cast<forward_extractor_a< any_a<> >>(variadic_operate(op, *const_cast<forward_extractor_d*>(this)));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit forward_extractor_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit forward_extractor_d(any_a<>& thing, any_a<>::___reference_tag___)
		: any_a<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit forward_extractor_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: any_a<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
