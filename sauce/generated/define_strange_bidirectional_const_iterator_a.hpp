
namespace strange
{

template <typename _1_ = void>
class bidirectional_const_iterator_d;

template <typename _1_ = void>
inline bidirectional_const_iterator_d<_1_> ___bidirectional_const_iterator_dynamic___(any_a<> const& thing); 

template <typename _1_>
class bidirectional_const_iterator_a : public forward_const_iterator_a<>
{
public:
	// arithmetic operator overloads
	inline bidirectional_const_iterator_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline bidirectional_const_iterator_a operator++(int)
	{
		assert(___handle___);
		bidirectional_const_iterator_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline bidirectional_const_iterator_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline bidirectional_const_iterator_a operator--(int)
	{
		assert(___handle___);
		bidirectional_const_iterator_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline bidirectional_const_iterator_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline bidirectional_const_iterator_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline bidirectional_const_iterator_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline bidirectional_const_iterator_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline bidirectional_const_iterator_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> decrement__(range_a<> const& arguments)
	{ assert(___handle___); return ___write___().decrement__(arguments); }

	inline bidirectional_const_iterator_a<> decrement_()
	{ assert(___handle___); return ___write___().decrement_(); }

protected:
	struct ___bidirectional_const_iterator_a_handle_base___ : ___forward_const_iterator_a_handle_base___
	{
		virtual any_a<> decrement__(range_a<> const& arguments) = 0;
		virtual bidirectional_const_iterator_a<> decrement_() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___bidirectional_const_iterator_a_handle_base___>
	struct ___bidirectional_const_iterator_a_handle___ : ___forward_const_iterator_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_const_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___forward_const_iterator_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_const_iterator_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___forward_const_iterator_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___bidirectional_const_iterator_a_handle___(___variadic_tag___, Args&&... args)
			: ___forward_const_iterator_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> decrement__(range_a<> const& arguments) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.decrement__(arguments); }

		virtual inline bidirectional_const_iterator_a<> decrement_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.decrement_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___bidirectional_const_iterator_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___bidirectional_const_iterator_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___bidirectional_const_iterator_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___bidirectional_const_iterator_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___bidirectional_const_iterator_a_handle_final___ final : ___bidirectional_const_iterator_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_const_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___bidirectional_const_iterator_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_const_iterator_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___bidirectional_const_iterator_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___bidirectional_const_iterator_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___bidirectional_const_iterator_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___bidirectional_const_iterator_a_handle_final___>(___bidirectional_const_iterator_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___bidirectional_const_iterator_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___bidirectional_const_iterator_a_handle_final___<___TTT___&>
	{
		inline ___bidirectional_const_iterator_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___bidirectional_const_iterator_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___bidirectional_const_iterator_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___bidirectional_const_iterator_a_handle_base___ const>(___handle___);
	}

	inline ___bidirectional_const_iterator_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___bidirectional_const_iterator_a_handle_base___>(___handle___);
	}

public:
	static inline bidirectional_const_iterator_a val(bidirectional_const_iterator_a const& other) noexcept
	{
		return bidirectional_const_iterator_a{ other };
	}

	static inline bidirectional_const_iterator_a ref(bidirectional_const_iterator_a& other) noexcept
	{
		return bidirectional_const_iterator_a(other, ___reference_tag___{});
	}

	static inline bidirectional_const_iterator_a dup(bidirectional_const_iterator_a& other) noexcept
	{
		return bidirectional_const_iterator_a(other, ___duplicate_tag___{});
	}

	inline bidirectional_const_iterator_a() = default;

	inline bidirectional_const_iterator_a(bidirectional_const_iterator_a& other, ___reference_tag___) noexcept
		: forward_const_iterator_a(other, ___reference_tag___{})
	{}

	inline bidirectional_const_iterator_a(bidirectional_const_iterator_a& other, ___duplicate_tag___) noexcept
		: forward_const_iterator_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline bidirectional_const_iterator_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: forward_const_iterator_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___bidirectional_const_iterator_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline bidirectional_const_iterator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: forward_const_iterator_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___bidirectional_const_iterator_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<bidirectional_const_iterator_a, std::decay_t<___TTT___>>::value>>
	explicit inline bidirectional_const_iterator_a(___TTT___ value) noexcept
		: forward_const_iterator_a{ std::make_shared<___bidirectional_const_iterator_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline bidirectional_const_iterator_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: forward_const_iterator_a{ std::make_shared<___bidirectional_const_iterator_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline bidirectional_const_iterator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___bidirectional_const_iterator_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<bidirectional_const_iterator_a, std::decay_t<___TTT___>>::value>>
	inline bidirectional_const_iterator_a& operator=(___TTT___ value) noexcept
	{
		bidirectional_const_iterator_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___bidirectional_const_iterator_a_handle_base___>(thing.___handle___) };
	}

	static inline bidirectional_const_iterator_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___bidirectional_const_iterator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return bidirectional_const_iterator_a{ thing.___handle___ };
		}
		return bidirectional_const_iterator_a{ bidirectional_const_iterator_d<_1_>{ thing } };
	}

	static inline bidirectional_const_iterator_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___bidirectional_const_iterator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return bidirectional_const_iterator_a(thing.___handle___, ___reference_tag___{});
		}
		return bidirectional_const_iterator_a{ bidirectional_const_iterator_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::bidirectional_const_iterator");
		return CAT;
	}

	template <typename ___TTT___, typename... Args>
	static inline bidirectional_const_iterator_a create(Args&&... args)
	{
		return bidirectional_const_iterator_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___bidirectional_const_iterator_a_share___;
}; // class bidirectional_const_iterator_a

template <typename _1_>
bool const bidirectional_const_iterator_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<bidirectional_const_iterator_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
class bidirectional_const_iterator_d : public forward_const_iterator_d<>
{
public:
	// arithmetic operator overloads
	inline bidirectional_const_iterator_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline bidirectional_const_iterator_d operator++(int)
	{
		assert(___handle___);
		bidirectional_const_iterator_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline bidirectional_const_iterator_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline bidirectional_const_iterator_d operator--(int)
	{
		assert(___handle___);
		bidirectional_const_iterator_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline bidirectional_const_iterator_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline bidirectional_const_iterator_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline bidirectional_const_iterator_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline bidirectional_const_iterator_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline bidirectional_const_iterator_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> decrement__(range_a<> const& arguments)
	{
		assert(___handle___);
		auto const op = operation("decrement_");
		if (!op)
		{
			throw dis("dynamic bidirectional_const_iterator_d::decrement_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline bidirectional_const_iterator_a<> decrement_()
	{
		assert(___handle___);
		auto const op = operation("decrement_");
		if (!op)
		{
			throw dis("dynamic bidirectional_const_iterator_d::decrement_ passed non-existent member");
		}
		return cast<bidirectional_const_iterator_a<>>(variadic_operate(op, *this));
	}

	void ___weak___(forward_const_iterator_d<>::___WEAK___ const& weak) const {}

	explicit bidirectional_const_iterator_d(any_a<> const& thing)
		: forward_const_iterator_d<>{ thing }
	{}

	explicit bidirectional_const_iterator_d(any_a<>& thing, ___reference_tag___)
		: forward_const_iterator_d<>{ thing, ___reference_tag___{} }
	{}

	explicit bidirectional_const_iterator_d(any_a<>& thing, ___duplicate_tag___)
		: forward_const_iterator_d<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline bidirectional_const_iterator_d<_1_> ___bidirectional_const_iterator_dynamic___(any_a<> const& thing)
{
	return bidirectional_const_iterator_d<_1_>{ thing };
}

} // namespace
