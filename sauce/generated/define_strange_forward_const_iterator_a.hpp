
namespace strange
{

template <typename _1_ = void>
class forward_const_iterator_d;

template <typename _1_ = void>
inline forward_const_iterator_d<_1_> ___forward_const_iterator_dynamic___(any_a<> const& thing); 

template <typename _1_>
class forward_const_iterator_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline forward_const_iterator_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline forward_const_iterator_a operator++(int)
	{
		assert(___handle___);
		forward_const_iterator_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline forward_const_iterator_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline forward_const_iterator_a operator--(int)
	{
		assert(___handle___);
		forward_const_iterator_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline forward_const_iterator_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline forward_const_iterator_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> get__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().get__(range); }

	inline any_a<> get_() const
	{ assert(___handle___); return ___read___().get_(); }

	inline any_a < > const & operator*() const
	{ assert(___handle___); return ___read___().operator*(); }

	inline any_a < > const * operator->() const
	{ assert(___handle___); return ___read___().operator->(); }

	inline any_a<> increment__(range_a<> const& range)
	{ assert(___handle___); return ___write___().increment__(range); }

	inline forward_const_iterator_a<> increment_()
	{ assert(___handle___); return ___write___().increment_(); }

protected:
	struct ___forward_const_iterator_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> get__(range_a<> const& range) const = 0;
		virtual any_a<> get_() const = 0;
		virtual any_a < > const & operator*() const = 0;
		virtual any_a < > const * operator->() const = 0;
		virtual any_a<> increment__(range_a<> const& range) = 0;
		virtual forward_const_iterator_a<> increment_() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___forward_const_iterator_a_handle_base___>
	struct ___forward_const_iterator_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___forward_const_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___forward_const_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___forward_const_iterator_a_handle___(___variadic_tag___, Args&&... args)
			: ___any_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> get__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.get__(range); }

		virtual inline any_a<> get_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.get_(); }

		virtual inline any_a < > const & operator*() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator*(); }

		virtual inline any_a < > const * operator->() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator->(); }

		virtual inline any_a<> increment__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.increment__(range); }

		virtual inline forward_const_iterator_a<> increment_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.increment_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___forward_const_iterator_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___forward_const_iterator_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___forward_const_iterator_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___forward_const_iterator_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___forward_const_iterator_a_handle_final___ final : ___forward_const_iterator_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___forward_const_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___forward_const_iterator_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___forward_const_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___forward_const_iterator_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___forward_const_iterator_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___forward_const_iterator_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___forward_const_iterator_a_handle_final___>(___forward_const_iterator_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___forward_const_iterator_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___forward_const_iterator_a_handle_final___<___TTT___&>
	{
		inline ___forward_const_iterator_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___forward_const_iterator_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___forward_const_iterator_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___forward_const_iterator_a_handle_base___ const>(___handle___);
	}

	inline ___forward_const_iterator_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___forward_const_iterator_a_handle_base___>(___handle___);
	}

public:
	static inline forward_const_iterator_a val(forward_const_iterator_a const& other) noexcept
	{
		return forward_const_iterator_a{ other };
	}

	static inline forward_const_iterator_a ref(forward_const_iterator_a& other) noexcept
	{
		return forward_const_iterator_a(other, ___reference_tag___{});
	}

	static inline forward_const_iterator_a dup(forward_const_iterator_a& other) noexcept
	{
		return forward_const_iterator_a(other, ___duplicate_tag___{});
	}

	inline forward_const_iterator_a() = default;

	inline forward_const_iterator_a(forward_const_iterator_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline forward_const_iterator_a(forward_const_iterator_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline forward_const_iterator_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline forward_const_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_const_iterator_a, std::decay_t<___TTT___>>::value>>
	explicit inline forward_const_iterator_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___forward_const_iterator_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline forward_const_iterator_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a{ std::make_shared<___forward_const_iterator_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline forward_const_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_const_iterator_a, std::decay_t<___TTT___>>::value>>
	inline forward_const_iterator_a& operator=(___TTT___ value) noexcept
	{
		forward_const_iterator_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(thing.___handle___) };
	}

	static inline forward_const_iterator_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return forward_const_iterator_a{ thing.___handle___ };
		}
		return forward_const_iterator_a{ forward_const_iterator_d<_1_>{ thing } };
	}

	static inline forward_const_iterator_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___forward_const_iterator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return forward_const_iterator_a(thing.___handle___, ___reference_tag___{});
		}
		return forward_const_iterator_a{ forward_const_iterator_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>>
	___cat_a___ ___cat___() const
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::forward_const_iterator");
		return CAT;
	}

	template <typename ___TTT___, typename... Args>
	static inline forward_const_iterator_a create(Args&&... args)
	{
		return forward_const_iterator_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___forward_const_iterator_a_share___;
}; // class forward_const_iterator_a

template <typename _1_>
bool const forward_const_iterator_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<forward_const_iterator_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class forward_const_iterator_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline forward_const_iterator_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline forward_const_iterator_d operator++(int)
	{
		assert(___handle___);
		forward_const_iterator_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline forward_const_iterator_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline forward_const_iterator_d operator--(int)
	{
		assert(___handle___);
		forward_const_iterator_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline forward_const_iterator_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline forward_const_iterator_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline forward_const_iterator_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline forward_const_iterator_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline forward_const_iterator_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> get__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("get_");
		if (!op)
		{
			throw dis("dynamic forward_const_iterator_d::get_ passed non-existent member");
		}
		return op.operate(*const_cast<forward_const_iterator_d*>(this), range);
	}

	inline any_a<> get_() const
	{
		assert(___handle___);
		auto const op = operation("get_");
		if (!op)
		{
			throw dis("dynamic forward_const_iterator_d::get_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<forward_const_iterator_d*>(this)));
	}

	inline any_a < > const & operator*() const
	{ throw dis("dynamic forward_const_iterator_d::operator*() not available"); }

	inline any_a < > const * operator->() const
	{ throw dis("dynamic forward_const_iterator_d::operator->() not available"); }

	inline any_a<> increment__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("increment_");
		if (!op)
		{
			throw dis("dynamic forward_const_iterator_d::increment_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline forward_const_iterator_a<> increment_()
	{
		assert(___handle___);
		auto const op = operation("increment_");
		if (!op)
		{
			throw dis("dynamic forward_const_iterator_d::increment_ passed non-existent member");
		}
		return cast<forward_const_iterator_a<>>(variadic_operate(op, *this));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit forward_const_iterator_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit forward_const_iterator_d(any_a<>& thing, ___reference_tag___)
		: any_a<>{ thing, ___reference_tag___{} }
	{}

	explicit forward_const_iterator_d(any_a<>& thing, ___duplicate_tag___)
		: any_a<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline forward_const_iterator_d<_1_> ___forward_const_iterator_dynamic___(any_a<> const& thing)
{
	return forward_const_iterator_d<_1_>{ thing };
}

} // namespace
