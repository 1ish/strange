
namespace strange
{

template <typename _1_ = void>
class flock_d;

template <typename _1_ = void>
inline flock_d<_1_> ___flock_dynamic___(any_a<> const& thing); 

template <typename _1_>
class flock_a : public inventory_a<>
{
public:
	// arithmetic operator overloads
	inline flock_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline flock_a operator++(int)
	{
		assert(___handle___);
		flock_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline flock_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline flock_a operator--(int)
	{
		assert(___handle___);
		flock_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline flock_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline flock_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline flock_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline flock_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline flock_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: vector < any_a < > > const & extract_vector() const
	{ assert(___handle___); return ___read___().extract_vector(); }

	inline std :: vector < any_a < > > & mutate_vector()
	{ assert(___handle___); return ___write___().mutate_vector(); }

protected:
	struct ___flock_a_handle_base___ : ___inventory_a_handle_base___
	{
		virtual std :: vector < any_a < > > const & extract_vector() const = 0;
		virtual std :: vector < any_a < > > & mutate_vector() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___flock_a_handle_base___>
	struct ___flock_a_handle___ : ___inventory_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___flock_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___inventory_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___flock_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___inventory_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___flock_a_handle___(___variadic_tag___, Args&&... args)
			: ___inventory_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline std :: vector < any_a < > > const & extract_vector() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_vector(); }

		virtual inline std :: vector < any_a < > > & mutate_vector() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_vector(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___flock_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___flock_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___flock_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___flock_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___flock_a_handle_final___ final : ___flock_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___flock_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___flock_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___flock_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___flock_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___flock_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___flock_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___flock_a_handle_final___>(___flock_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___flock_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___flock_a_handle_final___<___TTT___&>
	{
		inline ___flock_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___flock_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___flock_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___flock_a_handle_base___ const>(___handle___);
	}

	inline ___flock_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___flock_a_handle_base___>(___handle___);
	}

public:
	static inline flock_a val(flock_a const& other) noexcept
	{
		return flock_a{ other };
	}

	static inline flock_a ref(flock_a& other) noexcept
	{
		return flock_a(other, ___reference_tag___{});
	}

	static inline flock_a dup(flock_a& other) noexcept
	{
		return flock_a(other, ___duplicate_tag___{});
	}

	inline flock_a() = default;

	inline flock_a(flock_a& other, ___reference_tag___) noexcept
		: inventory_a(other, ___reference_tag___{})
	{}

	inline flock_a(flock_a& other, ___duplicate_tag___) noexcept
		: inventory_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline flock_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: inventory_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___flock_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline flock_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: inventory_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___flock_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<flock_a, std::decay_t<___TTT___>>::value>>
	explicit inline flock_a(___TTT___ value) noexcept
		: inventory_a{ std::make_shared<___flock_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline flock_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: inventory_a{ std::make_shared<___flock_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline flock_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___flock_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<flock_a, std::decay_t<___TTT___>>::value>>
	inline flock_a& operator=(___TTT___ value) noexcept
	{
		flock_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___flock_a_handle_base___>(thing.___handle___) };
	}

	static inline flock_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___flock_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return flock_a{ thing.___handle___ };
		}
		return flock_a{ flock_d<_1_>{ thing } };
	}

	static inline flock_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___flock_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return flock_a(thing.___handle___, ___reference_tag___{});
		}
		return flock_a{ flock_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	___cat_a___ ___cat___() const
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::flock");
		return CAT;
	}

	template <typename ___TTT___, typename... Args>
	static inline flock_a create(Args&&... args)
	{
		return flock_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___flock_a_share___;
}; // class flock_a

template <typename _1_>
bool const flock_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<flock_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class flock_d : public inventory_d<>
{
public:
	// arithmetic operator overloads
	inline flock_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline flock_d operator++(int)
	{
		assert(___handle___);
		flock_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline flock_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline flock_d operator--(int)
	{
		assert(___handle___);
		flock_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline flock_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline flock_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline flock_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline flock_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline flock_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: vector < any_a < > > const & extract_vector() const
	{ throw dis("dynamic flock_d::extract_vector() not available"); }

	inline std :: vector < any_a < > > & mutate_vector()
	{ throw dis("dynamic flock_d::mutate_vector() not available"); }

	void ___weak___(inventory_d<>::___WEAK___ const& weak) const {}

	explicit flock_d(any_a<> const& thing)
		: inventory_d<>{ thing }
	{}

	explicit flock_d(any_a<>& thing, ___reference_tag___)
		: inventory_d<>{ thing, ___reference_tag___{} }
	{}

	explicit flock_d(any_a<>& thing, ___duplicate_tag___)
		: inventory_d<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline flock_d<_1_> ___flock_dynamic___(any_a<> const& thing)
{
	return flock_d<_1_>{ thing };
}

} // namespace
