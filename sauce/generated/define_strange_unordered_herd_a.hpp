
namespace strange
{

template <typename _1_ = void>
class unordered_herd_d;

template <typename _1_ = void>
inline unordered_herd_d<_1_> ___unordered_herd_dynamic___(any_a<> const& thing); 

template <typename _1_>
class unordered_herd_a : public herd_a<>
{
public:
	// arithmetic operator overloads
	inline unordered_herd_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline unordered_herd_a operator++(int)
	{
		assert(___handle___);
		unordered_herd_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline unordered_herd_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline unordered_herd_a operator--(int)
	{
		assert(___handle___);
		unordered_herd_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline unordered_herd_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline unordered_herd_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline unordered_herd_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline unordered_herd_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline unordered_herd_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: unordered_set < any_a < > > const & extract_set() const
	{ assert(___handle___); return ___read___().extract_set(); }

	inline std :: unordered_set < any_a < > > & mutate_set()
	{ assert(___handle___); return ___write___().mutate_set(); }

protected:
	struct ___unordered_herd_a_handle_base___ : ___herd_a_handle_base___
	{
		virtual std :: unordered_set < any_a < > > const & extract_set() const = 0;
		virtual std :: unordered_set < any_a < > > & mutate_set() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___unordered_herd_a_handle_base___>
	struct ___unordered_herd_a_handle___ : ___herd_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_herd_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___herd_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_herd_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___herd_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___unordered_herd_a_handle___(___variadic_tag___, Args&&... args)
			: ___herd_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline std :: unordered_set < any_a < > > const & extract_set() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_set(); }

		virtual inline std :: unordered_set < any_a < > > & mutate_set() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_set(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___unordered_herd_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___unordered_herd_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___unordered_herd_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___unordered_herd_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___unordered_herd_a_handle_final___ final : ___unordered_herd_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_herd_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___unordered_herd_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_herd_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___unordered_herd_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___unordered_herd_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___unordered_herd_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___unordered_herd_a_handle_final___>(___unordered_herd_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___unordered_herd_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___unordered_herd_a_handle_final___<___TTT___&>
	{
		inline ___unordered_herd_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___unordered_herd_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___unordered_herd_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___unordered_herd_a_handle_base___ const>(___handle___);
	}

	inline ___unordered_herd_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___unordered_herd_a_handle_base___>(___handle___);
	}

public:
	static inline unordered_herd_a val(unordered_herd_a const& other) noexcept
	{
		return unordered_herd_a{ other };
	}

	static inline unordered_herd_a ref(unordered_herd_a& other) noexcept
	{
		return unordered_herd_a(other, ___reference_tag___{});
	}

	static inline unordered_herd_a dup(unordered_herd_a& other) noexcept
	{
		return unordered_herd_a(other, ___duplicate_tag___{});
	}

	inline unordered_herd_a() = default;

	inline unordered_herd_a(unordered_herd_a& other, ___reference_tag___) noexcept
		: herd_a(other, ___reference_tag___{})
	{}

	inline unordered_herd_a(unordered_herd_a& other, ___duplicate_tag___) noexcept
		: herd_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline unordered_herd_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: herd_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline unordered_herd_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: herd_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<unordered_herd_a, std::decay_t<___TTT___>>::value>>
	explicit inline unordered_herd_a(___TTT___ value) noexcept
		: herd_a{ std::make_shared<___unordered_herd_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline unordered_herd_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: herd_a{ std::make_shared<___unordered_herd_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline unordered_herd_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<unordered_herd_a, std::decay_t<___TTT___>>::value>>
	inline unordered_herd_a& operator=(___TTT___ value) noexcept
	{
		unordered_herd_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(thing.___handle___) };
	}

	static inline unordered_herd_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return unordered_herd_a{ thing.___handle___ };
		}
		return unordered_herd_a{ unordered_herd_d<_1_>{ thing } };
	}

	static inline unordered_herd_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return unordered_herd_a(thing.___handle___, ___reference_tag___{});
		}
		return unordered_herd_a{ unordered_herd_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::unordered_herd");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = herd_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = herd_a::___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = herd_a::___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline unordered_herd_a create(Args&&... args)
	{
		return unordered_herd_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___unordered_herd_a_share___;
}; // class unordered_herd_a

template <typename _1_>
class unordered_herd_d : public herd_d<>
{
public:
	// arithmetic operator overloads
	inline unordered_herd_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline unordered_herd_d operator++(int)
	{
		assert(___handle___);
		unordered_herd_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline unordered_herd_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline unordered_herd_d operator--(int)
	{
		assert(___handle___);
		unordered_herd_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline unordered_herd_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline unordered_herd_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline unordered_herd_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline unordered_herd_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline unordered_herd_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: unordered_set < any_a < > > const & extract_set() const
	{ throw dis("dynamic unordered_herd_d::extract_set() not available"); }

	inline std :: unordered_set < any_a < > > & mutate_set()
	{ throw dis("dynamic unordered_herd_d::mutate_set() not available"); }

	void ___weak___(herd_d<>::___WEAK___ const& weak) const {}

	explicit unordered_herd_d(any_a<> const& thing)
		: herd_d<>{ thing }
	{}

	explicit unordered_herd_d(any_a<>& thing, ___reference_tag___)
		: herd_d<>{ thing, ___reference_tag___{} }
	{}

	explicit unordered_herd_d(any_a<>& thing, ___duplicate_tag___)
		: herd_d<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline unordered_herd_d<_1_> ___unordered_herd_dynamic___(any_a<> const& thing)
{
	return unordered_herd_d<_1_>{ thing };
}

} // namespace
