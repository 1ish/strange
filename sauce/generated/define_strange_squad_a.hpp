
namespace strange
{

template <typename _1_ = void>
class squad_d;

template <typename _1_ = void>
inline squad_d<_1_> ___squad_dynamic___(any_a<> const& thing); 

template <typename _1_>
class squad_a : public inventory_a<>
{
public:
	// arithmetic operator overloads
	inline squad_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline squad_a operator++(int)
	{
		assert(___handle___);
		squad_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline squad_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline squad_a operator--(int)
	{
		assert(___handle___);
		squad_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline squad_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline squad_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline squad_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline squad_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline squad_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: deque < any_a < > > const & extract_deque() const
	{ assert(___handle___); return ___read___().extract_deque(); }

	inline std :: deque < any_a < > > & mutate_deque()
	{ assert(___handle___); return ___write___().mutate_deque(); }

protected:
	struct ___squad_a_handle_base___ : ___inventory_a_handle_base___
	{
		virtual std :: deque < any_a < > > const & extract_deque() const = 0;
		virtual std :: deque < any_a < > > & mutate_deque() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___squad_a_handle_base___>
	struct ___squad_a_handle___ : ___inventory_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___squad_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___inventory_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___squad_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___inventory_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___squad_a_handle___(___variadic_tag___, Args&&... args)
			: ___inventory_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline std :: deque < any_a < > > const & extract_deque() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_deque(); }

		virtual inline std :: deque < any_a < > > & mutate_deque() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_deque(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___squad_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___squad_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___squad_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___squad_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___squad_a_handle_final___ final : ___squad_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___squad_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___squad_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___squad_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___squad_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___squad_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___squad_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___squad_a_handle_final___>(___squad_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___squad_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___squad_a_handle_final___<___TTT___&>
	{
		inline ___squad_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___squad_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___squad_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___squad_a_handle_base___ const>(___handle___);
	}

	inline ___squad_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___squad_a_handle_base___>(___handle___);
	}

public:
	static inline squad_a val(squad_a const& other) noexcept
	{
		return squad_a{ other };
	}

	static inline squad_a ref(squad_a& other) noexcept
	{
		return squad_a(other, ___reference_tag___{});
	}

	static inline squad_a dup(squad_a& other) noexcept
	{
		return squad_a(other, ___duplicate_tag___{});
	}

	inline squad_a() = default;

	inline squad_a(squad_a& other, ___reference_tag___) noexcept
		: inventory_a(other, ___reference_tag___{})
	{}

	inline squad_a(squad_a& other, ___duplicate_tag___) noexcept
		: inventory_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline squad_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: inventory_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___squad_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline squad_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: inventory_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___squad_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<squad_a, std::decay_t<___TTT___>>::value>>
	explicit inline squad_a(___TTT___ value) noexcept
		: inventory_a{ std::make_shared<___squad_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline squad_a(___variadic_tag___, Args&&... args)
		: inventory_a{ std::make_shared<___squad_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline squad_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___squad_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<squad_a, std::decay_t<___TTT___>>::value>>
	inline squad_a& operator=(___TTT___ value) noexcept
	{
		squad_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___squad_a_handle_base___>(thing.___handle___) };
	}

	static inline squad_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___squad_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return squad_a{ thing.___handle___ };
		}
		return squad_a{ squad_d<_1_>{ thing } };
	}

	static inline squad_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___squad_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return squad_a(thing.___handle___, ___reference_tag___{});
		}
		return squad_a{ squad_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>>
	___cat_a___ ___cat___() const
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::squad");
		return CAT;
	}

private:
	static bool const ___share___;
	friend class ___squad_a_share___;
}; // class squad_a

template <typename _1_>
bool const squad_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<squad_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class squad_d : public inventory_d<>
{
public:
	// arithmetic operator overloads
	inline squad_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline squad_d operator++(int)
	{
		assert(___handle___);
		squad_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline squad_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline squad_d operator--(int)
	{
		assert(___handle___);
		squad_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline squad_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline squad_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline squad_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline squad_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline squad_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: deque < any_a < > > const & extract_deque() const
	{ throw dis("dynamic squad_d::extract_deque() not available"); }

	inline std :: deque < any_a < > > & mutate_deque()
	{ throw dis("dynamic squad_d::mutate_deque() not available"); }

	void ___weak___(inventory_d<>::___WEAK___ const& weak) const {}

	explicit squad_d(any_a<> const& thing)
		: inventory_d<>{ thing }
	{}

	explicit squad_d(any_a<>& thing, ___reference_tag___)
		: inventory_d<>{ thing, ___reference_tag___{} }
	{}

	explicit squad_d(any_a<>& thing, ___duplicate_tag___)
		: inventory_d<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline squad_d<_1_> ___squad_dynamic___(any_a<> const& thing)
{
	return squad_d<_1_>{ thing };
}

} // namespace
