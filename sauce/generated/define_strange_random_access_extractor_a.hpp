
namespace strange
{

template <typename _element>
class random_access_extractor_d;

template <typename _element>
inline random_access_extractor_d<_element> ___random_access_extractor_dynamic___(any_a<> const& thing); 

template <typename _element>
class random_access_extractor_a : public bidirectional_extractor_a< _element >
{
public:
	inline any_a<> self_add__(range_a<> const& ___arguments___);

	inline random_access_extractor_a self_add_(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		___write___().self_add_(number);
		return *this;
	}

	inline random_access_extractor_a& operator+=(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		___write___().self_add_(number);
		return *this;
	}

	inline any_a<> add__(range_a<> const& ___arguments___) const;

	inline random_access_extractor_a< _element > add_(number_a<> const& number) const
	{ assert(any_a<>::___handle___); return ___read___().add_(number); }

	inline random_access_extractor_a< _element > operator+(number_a<> const& number) const
	{ assert(any_a<>::___handle___); return ___read___().add_(number); }

	inline any_a<> self_subtract__(range_a<> const& ___arguments___);

	inline random_access_extractor_a self_subtract_(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		___write___().self_subtract_(number);
		return *this;
	}

	inline random_access_extractor_a& operator-=(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		___write___().self_subtract_(number);
		return *this;
	}

	inline any_a<> subtract__(range_a<> const& ___arguments___) const;

	inline random_access_extractor_a< _element > subtract_(number_a<> const& number) const
	{ assert(any_a<>::___handle___); return ___read___().subtract_(number); }

	inline random_access_extractor_a< _element > operator-(number_a<> const& number) const
	{ assert(any_a<>::___handle___); return ___read___().subtract_(number); }

protected:
	struct ___random_access_extractor_a_handle_base___ : bidirectional_extractor_a< _element >::___bidirectional_extractor_a_handle_base___
	{
		virtual void self_add_(number_a<> const& number) = 0;
		virtual random_access_extractor_a< _element > add_(number_a<> const& number) const = 0;
		virtual void self_subtract_(number_a<> const& number) = 0;
		virtual random_access_extractor_a< _element > subtract_(number_a<> const& number) const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___random_access_extractor_a_handle_base___>
	struct ___random_access_extractor_a_handle___ : bidirectional_extractor_a< _element >::template ___bidirectional_extractor_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_extractor_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: bidirectional_extractor_a< _element >::template ___bidirectional_extractor_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_extractor_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: bidirectional_extractor_a< _element >::template ___bidirectional_extractor_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___random_access_extractor_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: bidirectional_extractor_a< _element >::template ___bidirectional_extractor_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline void self_add_(number_a<> const& number) final
		{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_add_(number); }

		virtual inline random_access_extractor_a< _element > add_(number_a<> const& number) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(number); }

		virtual inline void self_subtract_(number_a<> const& number) final
		{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_subtract_(number); }

		virtual inline random_access_extractor_a< _element > subtract_(number_a<> const& number) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.subtract_(number); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___random_access_extractor_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___random_access_extractor_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___random_access_extractor_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_extractor_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___random_access_extractor_a_handle_final___ final : ___random_access_extractor_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_extractor_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___random_access_extractor_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_extractor_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___random_access_extractor_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___random_access_extractor_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___random_access_extractor_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___random_access_extractor_a_handle_final___>(___random_access_extractor_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___random_access_extractor_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___random_access_extractor_a_handle_final___<___TTT___&>
	{
		inline ___random_access_extractor_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_extractor_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___random_access_extractor_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___random_access_extractor_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___random_access_extractor_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___random_access_extractor_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline random_access_extractor_a val(random_access_extractor_a const& other) noexcept
	{
		return random_access_extractor_a{ other };
	}

	static inline random_access_extractor_a ref(random_access_extractor_a& other) noexcept
	{
		return random_access_extractor_a(other, any_a<>::___reference_tag___{});
	}

	static inline random_access_extractor_a dup(random_access_extractor_a& other) noexcept
	{
		return random_access_extractor_a(other, any_a<>::___duplicate_tag___{});
	}

	inline random_access_extractor_a() = default;

	inline random_access_extractor_a(random_access_extractor_a& other, any_a<>::___reference_tag___) noexcept
		: bidirectional_extractor_a< _element >(other, any_a<>::___reference_tag___{})
	{}

	inline random_access_extractor_a(random_access_extractor_a& other, any_a<>::___duplicate_tag___) noexcept
		: bidirectional_extractor_a< _element >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline random_access_extractor_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: bidirectional_extractor_a< _element >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_extractor_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline random_access_extractor_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: bidirectional_extractor_a< _element >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_extractor_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_extractor_a, std::decay_t<___TTT___>>::value>>
	explicit inline random_access_extractor_a(___TTT___ value) noexcept
		: bidirectional_extractor_a< _element >{ std::make_shared<___random_access_extractor_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline random_access_extractor_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: bidirectional_extractor_a< _element >{ std::make_shared<___random_access_extractor_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline random_access_extractor_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_extractor_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_extractor_a, std::decay_t<___TTT___>>::value>>
	inline random_access_extractor_a& operator=(___TTT___ value) noexcept
	{
		random_access_extractor_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___random_access_extractor_a_handle_base___>(thing.___handle___) };
	}

	static inline random_access_extractor_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___random_access_extractor_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return random_access_extractor_a{ thing.___handle___ };
		}
		return random_access_extractor_a{ random_access_extractor_d<_element>{ thing } };
	}

	static inline random_access_extractor_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___random_access_extractor_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return random_access_extractor_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return random_access_extractor_a{ random_access_extractor_d<_element>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::random_access_extractor", flock_vals(kind_create<___kind_a___>(2, "")));
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = bidirectional_extractor_a< _element >::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>(), flock_vals(kind_of<_element>()));
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = bidirectional_extractor_a< _element >::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = bidirectional_extractor_a< _element >::template ___operations___<___unordered_shoal_a___>();
			operations.update_string("self_add_", native_mutation_t<random_access_extractor_a>::create(&random_access_extractor_a::self_add__));
			operations.update_string("add_", native_extraction_t<random_access_extractor_a>::create(&random_access_extractor_a::add__));
			operations.update_string("self_subtract_", native_mutation_t<random_access_extractor_a>::create(&random_access_extractor_a::self_subtract__));
			operations.update_string("subtract_", native_extraction_t<random_access_extractor_a>::create(&random_access_extractor_a::subtract__));
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline random_access_extractor_a create(Args&&... args)
	{
		return random_access_extractor_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class random_access_extractor_a

template <typename _element>
class random_access_extractor_d : public bidirectional_extractor_d< _element >
{
public:
	inline any_a<> self_add__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("self_add_");
		if (!op)
		{
			throw dis("dynamic random_access_extractor_d::self_add_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline random_access_extractor_a< _element > self_add_(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("self_add_");
		if (!op)
		{
			throw dis("dynamic random_access_extractor_d::self_add_ passed non-existent member");
		}
		return cast<random_access_extractor_a< _element >>(variadic_operate(op, *this, number));
	}

	inline any_a<> add__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("add_");
		if (!op)
		{
			throw dis("dynamic random_access_extractor_d::add_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_extractor_d*>(this), arguments);
	}

	inline random_access_extractor_a< _element > add_(number_a<> const& number) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("add_");
		if (!op)
		{
			throw dis("dynamic random_access_extractor_d::add_ passed non-existent member");
		}
		return cast<random_access_extractor_a< _element >>(variadic_operate(op, *const_cast<random_access_extractor_d*>(this), number));
	}

	inline any_a<> self_subtract__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_extractor_d::self_subtract_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline random_access_extractor_a< _element > self_subtract_(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_extractor_d::self_subtract_ passed non-existent member");
		}
		return cast<random_access_extractor_a< _element >>(variadic_operate(op, *this, number));
	}

	inline any_a<> subtract__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_extractor_d::subtract_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_extractor_d*>(this), arguments);
	}

	inline random_access_extractor_a< _element > subtract_(number_a<> const& number) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_extractor_d::subtract_ passed non-existent member");
		}
		return cast<random_access_extractor_a< _element >>(variadic_operate(op, *const_cast<random_access_extractor_d*>(this), number));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit random_access_extractor_d(any_a<> const& thing)
		: bidirectional_extractor_d< _element >{ thing }
	{}

	explicit random_access_extractor_d(any_a<>& thing, any_a<>::___reference_tag___)
		: bidirectional_extractor_d< _element >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit random_access_extractor_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: bidirectional_extractor_d< _element >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
