
namespace strange
{

template <typename _1_>
class brook_d;

template <typename _1_>
inline brook_d<_1_> ___brook_dynamic___(any_a<> const& thing); 

template <typename _1_>
class brook_a : public inventory_a<>
{
public:
	// arithmetic operator overloads
	inline brook_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline brook_a operator++(int)
	{
		assert(___handle___);
		brook_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline brook_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline brook_a operator--(int)
	{
		assert(___handle___);
		brook_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline brook_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline brook_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline brook_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline brook_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline brook_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: deque < _1_ > const & extract_deque() const
	{ assert(___handle___); return ___read___().extract_deque(); }

	inline std :: deque < _1_ > & mutate_deque()
	{ assert(___handle___); return ___write___().mutate_deque(); }

protected:
	struct ___brook_a_handle_base___ : ___inventory_a_handle_base___
	{
		virtual std :: deque < _1_ > const & extract_deque() const = 0;
		virtual std :: deque < _1_ > & mutate_deque() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___brook_a_handle_base___>
	struct ___brook_a_handle___ : ___inventory_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___brook_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___inventory_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___brook_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___inventory_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___brook_a_handle___(___variadic_tag___, Args&&... args)
			: ___inventory_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline std :: deque < _1_ > const & extract_deque() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_deque(); }

		virtual inline std :: deque < _1_ > & mutate_deque() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_deque(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___brook_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___brook_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___brook_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___brook_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___brook_a_handle_final___ final : ___brook_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___brook_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___brook_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___brook_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___brook_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___brook_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___brook_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___brook_a_handle_final___>(___brook_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___brook_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___brook_a_handle_final___<___TTT___&>
	{
		inline ___brook_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___brook_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___brook_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___brook_a_handle_base___ const>(___handle___);
	}

	inline ___brook_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___brook_a_handle_base___>(___handle___);
	}

public:
	static inline brook_a val(brook_a const& other) noexcept
	{
		return brook_a{ other };
	}

	static inline brook_a ref(brook_a& other) noexcept
	{
		return brook_a(other, ___reference_tag___{});
	}

	static inline brook_a dup(brook_a& other) noexcept
	{
		return brook_a(other, ___duplicate_tag___{});
	}

	inline brook_a() = default;

	inline brook_a(brook_a& other, ___reference_tag___) noexcept
		: inventory_a(other, ___reference_tag___{})
	{}

	inline brook_a(brook_a& other, ___duplicate_tag___) noexcept
		: inventory_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline brook_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: inventory_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___brook_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline brook_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: inventory_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___brook_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<brook_a, std::decay_t<___TTT___>>::value>>
	explicit inline brook_a(___TTT___ value) noexcept
		: inventory_a{ std::make_shared<___brook_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline brook_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: inventory_a{ std::make_shared<___brook_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline brook_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___brook_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<brook_a, std::decay_t<___TTT___>>::value>>
	inline brook_a& operator=(___TTT___ value) noexcept
	{
		brook_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___brook_a_handle_base___>(thing.___handle___) };
	}

	static inline brook_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___brook_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return brook_a{ thing.___handle___ };
		}
		return brook_a{ brook_d<_1_>{ thing } };
	}

	static inline brook_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___brook_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return brook_a(thing.___handle___, ___reference_tag___{});
		}
		return brook_a{ brook_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::brook", flock_vals(kind_create<___kind_a___>(2, "")));
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = inventory_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>(), flock_vals(kind_of<_1_>()));
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = inventory_a::___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = inventory_a::___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline brook_a create(Args&&... args)
	{
		return brook_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___brook_a_share___;
}; // class brook_a

template <typename _1_>
class brook_d : public inventory_d<>
{
public:
	// arithmetic operator overloads
	inline brook_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline brook_d operator++(int)
	{
		assert(___handle___);
		brook_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline brook_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline brook_d operator--(int)
	{
		assert(___handle___);
		brook_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline brook_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline brook_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline brook_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline brook_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline brook_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: deque < _1_ > const & extract_deque() const
	{ throw dis("dynamic brook_d::extract_deque() not available"); }

	inline std :: deque < _1_ > & mutate_deque()
	{ throw dis("dynamic brook_d::mutate_deque() not available"); }

	void ___weak___(inventory_d<>::___WEAK___ const& weak) const {}

	explicit brook_d(any_a<> const& thing)
		: inventory_d<>{ thing }
	{}

	explicit brook_d(any_a<>& thing, ___reference_tag___)
		: inventory_d<>{ thing, ___reference_tag___{} }
	{}

	explicit brook_d(any_a<>& thing, ___duplicate_tag___)
		: inventory_d<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline brook_d<_1_> ___brook_dynamic___(any_a<> const& thing)
{
	return brook_d<_1_>{ thing };
}

} // namespace
