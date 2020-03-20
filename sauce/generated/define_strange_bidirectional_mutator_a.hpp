
namespace strange
{

template <typename _1 = void>
class bidirectional_mutator_d;

template <typename _1 = void>
inline bidirectional_mutator_d<_1> ___bidirectional_mutator_dynamic___(any_a<> const& thing); 

template <typename _1>
class bidirectional_mutator_a : public forward_mutator_a<>
{
public:
	inline any_a<> decrement__(range_a<> const& ___arguments___);

	inline bidirectional_mutator_a decrement_()
	{
		assert(any_a<>::___handle___);
		___write___().decrement_();
		return *this;
	}

	inline bidirectional_mutator_a& operator--()
	{
		assert(any_a<>::___handle___);
		___write___().decrement_();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline bidirectional_mutator_a operator--(int)
	{
		assert(any_a<>::___handle___);
		bidirectional_mutator_a result = *this;
		___write___().decrement_();
		return result;
	}
#endif

protected:
	struct ___bidirectional_mutator_a_handle_base___ : forward_mutator_a<>::template ___forward_mutator_a_handle_base___
	{
		virtual void decrement_() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___bidirectional_mutator_a_handle_base___>
	struct ___bidirectional_mutator_a_handle___ : forward_mutator_a<>::template ___forward_mutator_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_mutator_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: forward_mutator_a<>::template ___forward_mutator_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_mutator_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: forward_mutator_a<>::template ___forward_mutator_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___bidirectional_mutator_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: forward_mutator_a<>::template ___forward_mutator_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline void decrement_() final
		{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.decrement_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___bidirectional_mutator_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___bidirectional_mutator_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___bidirectional_mutator_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___bidirectional_mutator_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___bidirectional_mutator_a_handle_final___ final : ___bidirectional_mutator_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_mutator_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___bidirectional_mutator_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___bidirectional_mutator_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___bidirectional_mutator_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___bidirectional_mutator_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___bidirectional_mutator_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___bidirectional_mutator_a_handle_final___>(___bidirectional_mutator_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___bidirectional_mutator_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___bidirectional_mutator_a_handle_final___<___TTT___&>
	{
		inline ___bidirectional_mutator_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___bidirectional_mutator_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___bidirectional_mutator_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___bidirectional_mutator_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___bidirectional_mutator_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___bidirectional_mutator_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline bidirectional_mutator_a val(bidirectional_mutator_a const& other) noexcept
	{
		return bidirectional_mutator_a{ other };
	}

	static inline bidirectional_mutator_a ref(bidirectional_mutator_a& other) noexcept
	{
		return bidirectional_mutator_a(other, any_a<>::___reference_tag___{});
	}

	static inline bidirectional_mutator_a dup(bidirectional_mutator_a& other) noexcept
	{
		return bidirectional_mutator_a(other, any_a<>::___duplicate_tag___{});
	}

	inline bidirectional_mutator_a() = default;

	inline bidirectional_mutator_a(bidirectional_mutator_a& other, any_a<>::___reference_tag___) noexcept
		: forward_mutator_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline bidirectional_mutator_a(bidirectional_mutator_a& other, any_a<>::___duplicate_tag___) noexcept
		: forward_mutator_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline bidirectional_mutator_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: forward_mutator_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___bidirectional_mutator_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline bidirectional_mutator_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: forward_mutator_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___bidirectional_mutator_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<bidirectional_mutator_a, std::decay_t<___TTT___>>::value>>
	explicit inline bidirectional_mutator_a(___TTT___ value) noexcept
		: forward_mutator_a<>{ std::make_shared<___bidirectional_mutator_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline bidirectional_mutator_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: forward_mutator_a<>{ std::make_shared<___bidirectional_mutator_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline bidirectional_mutator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___bidirectional_mutator_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<bidirectional_mutator_a, std::decay_t<___TTT___>>::value>>
	inline bidirectional_mutator_a& operator=(___TTT___ value) noexcept
	{
		bidirectional_mutator_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___bidirectional_mutator_a_handle_base___>(thing.___handle___) };
	}

	static inline bidirectional_mutator_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___bidirectional_mutator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return bidirectional_mutator_a{ thing.___handle___ };
		}
		return bidirectional_mutator_a{ bidirectional_mutator_d<_1>{ thing } };
	}

	static inline bidirectional_mutator_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___bidirectional_mutator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return bidirectional_mutator_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return bidirectional_mutator_a{ bidirectional_mutator_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::bidirectional_mutator");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = forward_mutator_a<>::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>());
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = forward_mutator_a<>::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___()
	{
		static ___unordered_shoal_a___ OPERATIONS = []()
		{
			___unordered_shoal_a___ operations = forward_mutator_a<>::template ___operations___<___unordered_shoal_a___>();
			operations.update_string("decrement_", native_mutation_t<bidirectional_mutator_a>::create(&bidirectional_mutator_a::decrement__));
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline bidirectional_mutator_a create(Args&&... args)
	{
		return bidirectional_mutator_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class bidirectional_mutator_a

template <typename _1>
class bidirectional_mutator_d : public forward_mutator_d<>
{
public:
	inline any_a<> decrement__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = operation("decrement_");
		if (!op)
		{
			throw dis("dynamic bidirectional_mutator_d::decrement_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline bidirectional_mutator_a<> decrement_()
	{
		assert(any_a<>::___handle___);
		auto const op = operation("decrement_");
		if (!op)
		{
			throw dis("dynamic bidirectional_mutator_d::decrement_ passed non-existent member");
		}
		return cast<bidirectional_mutator_a<>>(variadic_operate(op, *this));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit bidirectional_mutator_d(any_a<> const& thing)
		: forward_mutator_d<>{ thing }
	{}

	explicit bidirectional_mutator_d(any_a<>& thing, any_a<>::___reference_tag___)
		: forward_mutator_d<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit bidirectional_mutator_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: forward_mutator_d<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
