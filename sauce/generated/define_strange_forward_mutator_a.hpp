
namespace strange
{

template <typename _1_ = void>
class forward_mutator_d;

template <typename _1_ = void>
inline forward_mutator_d<_1_> ___forward_mutator_dynamic___(any_a<> const& thing); 

template <typename _1_>
class forward_mutator_a : public any_a<>
{
public:
	inline any_a<> get__(range_a<> const& ___arguments___) const;

	inline any_a<> get_() const
	{ assert(___handle___); return ___read___().get_(); }

	inline any_a<> set__(range_a<> const& ___arguments___) const;

	inline any_a<> set_(any_a<> const& thing) const
	{ assert(___handle___); return ___read___().set_(thing); }

	inline any_a < > & operator*() const
	{ assert(___handle___); return ___read___().operator*(); }

	inline any_a < > * operator->() const
	{ assert(___handle___); return ___read___().operator->(); }

	inline any_a<> increment__(range_a<> const& ___arguments___);

	inline forward_mutator_a increment_()
	{
		assert(___handle___);
		___write___().increment_();
		return *this;
	}

	inline forward_mutator_a& operator++()
	{
		assert(___handle___);
		___write___().increment_();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline forward_mutator_a operator++(int)
	{
		assert(___handle___);
		forward_mutator_a result = *this;
		___write___().increment_();
		return result;
	}
#endif

protected:
	struct ___forward_mutator_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> get_() const = 0;
		virtual any_a<> set_(any_a<> const& thing) const = 0;
		virtual any_a < > & operator*() const = 0;
		virtual any_a < > * operator->() const = 0;
		virtual void increment_() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___forward_mutator_a_handle_base___>
	struct ___forward_mutator_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___forward_mutator_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___forward_mutator_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___forward_mutator_a_handle___(___variadic_tag___, Args&&... args)
			: ___any_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> get_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.get_(); }

		virtual inline any_a<> set_(any_a<> const& thing) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_(thing); }

		virtual inline any_a < > & operator*() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator*(); }

		virtual inline any_a < > * operator->() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator->(); }

		virtual inline void increment_() final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.increment_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___forward_mutator_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___forward_mutator_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___forward_mutator_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___forward_mutator_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___forward_mutator_a_handle_final___ final : ___forward_mutator_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___forward_mutator_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___forward_mutator_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___forward_mutator_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___forward_mutator_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___forward_mutator_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___forward_mutator_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___forward_mutator_a_handle_final___>(___forward_mutator_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___forward_mutator_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___forward_mutator_a_handle_final___<___TTT___&>
	{
		inline ___forward_mutator_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___forward_mutator_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___forward_mutator_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___forward_mutator_a_handle_base___ const>(___handle___);
	}

	inline ___forward_mutator_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___forward_mutator_a_handle_base___>(___handle___);
	}

public:
	static inline forward_mutator_a val(forward_mutator_a const& other) noexcept
	{
		return forward_mutator_a{ other };
	}

	static inline forward_mutator_a ref(forward_mutator_a& other) noexcept
	{
		return forward_mutator_a(other, ___reference_tag___{});
	}

	static inline forward_mutator_a dup(forward_mutator_a& other) noexcept
	{
		return forward_mutator_a(other, ___duplicate_tag___{});
	}

	inline forward_mutator_a() = default;

	inline forward_mutator_a(forward_mutator_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline forward_mutator_a(forward_mutator_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline forward_mutator_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_mutator_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline forward_mutator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_mutator_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_mutator_a, std::decay_t<___TTT___>>::value>>
	explicit inline forward_mutator_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___forward_mutator_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline forward_mutator_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a{ std::make_shared<___forward_mutator_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline forward_mutator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_mutator_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_mutator_a, std::decay_t<___TTT___>>::value>>
	inline forward_mutator_a& operator=(___TTT___ value) noexcept
	{
		forward_mutator_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___forward_mutator_a_handle_base___>(thing.___handle___) };
	}

	static inline forward_mutator_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___forward_mutator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return forward_mutator_a{ thing.___handle___ };
		}
		return forward_mutator_a{ forward_mutator_d<_1_>{ thing } };
	}

	static inline forward_mutator_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___forward_mutator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return forward_mutator_a(thing.___handle___, ___reference_tag___{});
		}
		return forward_mutator_a{ forward_mutator_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::forward_mutator");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = any_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = any_a::___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = any_a::___operations___<___unordered_shoal_a___>();
			operations.update_string("get_", native_extraction_t<forward_mutator_a>::create(&forward_mutator_a::get__));
			operations.update_string("set_", native_extraction_t<forward_mutator_a>::create(&forward_mutator_a::set__));
			operations.update_string("increment_", native_mutation_t<forward_mutator_a>::create(&forward_mutator_a::increment__));
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline forward_mutator_a create(Args&&... args)
	{
		return forward_mutator_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___forward_mutator_a_share___;
}; // class forward_mutator_a

template <typename _1_>
class forward_mutator_d : public any_a<>
{
public:
	inline any_a<> get__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("get_");
		if (!op)
		{
			throw dis("dynamic forward_mutator_d::get_ passed non-existent member");
		}
		return op.operate(*const_cast<forward_mutator_d*>(this), arguments);
	}

	inline any_a<> get_() const
	{
		assert(___handle___);
		auto const op = operation("get_");
		if (!op)
		{
			throw dis("dynamic forward_mutator_d::get_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<forward_mutator_d*>(this)));
	}

	inline any_a<> set__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("set_");
		if (!op)
		{
			throw dis("dynamic forward_mutator_d::set_ passed non-existent member");
		}
		return op.operate(*const_cast<forward_mutator_d*>(this), arguments);
	}

	inline any_a<> set_(any_a<> const& thing) const
	{
		assert(___handle___);
		auto const op = operation("set_");
		if (!op)
		{
			throw dis("dynamic forward_mutator_d::set_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<forward_mutator_d*>(this), thing));
	}

	inline any_a < > & operator*() const
	{ throw dis("dynamic forward_mutator_d::operator*() not available"); }

	inline any_a < > * operator->() const
	{ throw dis("dynamic forward_mutator_d::operator->() not available"); }

	inline any_a<> increment__(range_a<> const& arguments)
	{
		assert(___handle___);
		auto const op = operation("increment_");
		if (!op)
		{
			throw dis("dynamic forward_mutator_d::increment_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline forward_mutator_a<> increment_()
	{
		assert(___handle___);
		auto const op = operation("increment_");
		if (!op)
		{
			throw dis("dynamic forward_mutator_d::increment_ passed non-existent member");
		}
		return cast<forward_mutator_a<>>(variadic_operate(op, *this));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit forward_mutator_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit forward_mutator_d(any_a<>& thing, ___reference_tag___)
		: any_a<>{ thing, ___reference_tag___{} }
	{}

	explicit forward_mutator_d(any_a<>& thing, ___duplicate_tag___)
		: any_a<>{ thing, ___duplicate_tag___{} }
	{}
};

} // namespace
