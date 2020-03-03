
namespace strange
{

template <typename _1_>
class random_access_iterator_data_d;

template <typename _1_>
inline random_access_iterator_data_d<_1_> ___random_access_iterator_data_dynamic___(any_a<> const& thing); 

template <typename _1_>
class random_access_iterator_data_a : public random_access_iterator_a<>
{
public:
	// arithmetic operator overloads
	inline random_access_iterator_data_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_data_a operator++(int)
	{
		assert(___handle___);
		random_access_iterator_data_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline random_access_iterator_data_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_data_a operator--(int)
	{
		assert(___handle___);
		random_access_iterator_data_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline random_access_iterator_data_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline random_access_iterator_data_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline random_access_iterator_data_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline random_access_iterator_data_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline random_access_iterator_data_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline _1_ const & extract_it() const
	{ assert(___handle___); return ___read___().extract_it(); }

	inline _1_ & mutate_it()
	{ assert(___handle___); return ___write___().mutate_it(); }

protected:
	struct ___random_access_iterator_data_a_handle_base___ : ___random_access_iterator_a_handle_base___
	{
		virtual _1_ const & extract_it() const = 0;
		virtual _1_ & mutate_it() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___random_access_iterator_data_a_handle_base___>
	struct ___random_access_iterator_data_a_handle___ : ___random_access_iterator_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_iterator_data_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___random_access_iterator_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_iterator_data_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___random_access_iterator_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___random_access_iterator_data_a_handle___(___variadic_tag___, Args&&... args)
			: ___random_access_iterator_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline _1_ const & extract_it() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_it(); }

		virtual inline _1_ & mutate_it() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_it(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___random_access_iterator_data_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___random_access_iterator_data_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___random_access_iterator_data_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_iterator_data_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___random_access_iterator_data_a_handle_final___ final : ___random_access_iterator_data_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_iterator_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___random_access_iterator_data_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_iterator_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___random_access_iterator_data_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___random_access_iterator_data_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___random_access_iterator_data_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___random_access_iterator_data_a_handle_final___>(___random_access_iterator_data_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___random_access_iterator_data_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___random_access_iterator_data_a_handle_final___<___TTT___&>
	{
		inline ___random_access_iterator_data_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_iterator_data_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___random_access_iterator_data_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___random_access_iterator_data_a_handle_base___ const>(___handle___);
	}

	inline ___random_access_iterator_data_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___random_access_iterator_data_a_handle_base___>(___handle___);
	}

public:
	static inline random_access_iterator_data_a val(random_access_iterator_data_a const& other) noexcept
	{
		return random_access_iterator_data_a{ other };
	}

	static inline random_access_iterator_data_a ref(random_access_iterator_data_a& other) noexcept
	{
		return random_access_iterator_data_a(other, ___reference_tag___{});
	}

	static inline random_access_iterator_data_a dup(random_access_iterator_data_a& other) noexcept
	{
		return random_access_iterator_data_a(other, ___duplicate_tag___{});
	}

	inline random_access_iterator_data_a() = default;

	inline random_access_iterator_data_a(random_access_iterator_data_a& other, ___reference_tag___) noexcept
		: random_access_iterator_a(other, ___reference_tag___{})
	{}

	inline random_access_iterator_data_a(random_access_iterator_data_a& other, ___duplicate_tag___) noexcept
		: random_access_iterator_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline random_access_iterator_data_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: random_access_iterator_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline random_access_iterator_data_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: random_access_iterator_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_iterator_data_a, std::decay_t<___TTT___>>::value>>
	explicit inline random_access_iterator_data_a(___TTT___ value) noexcept
		: random_access_iterator_a{ std::make_shared<___random_access_iterator_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline random_access_iterator_data_a(___variadic_tag___, Args&&... args)
		: random_access_iterator_a{ std::make_shared<___random_access_iterator_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline random_access_iterator_data_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_iterator_data_a, std::decay_t<___TTT___>>::value>>
	inline random_access_iterator_data_a& operator=(___TTT___ value) noexcept
	{
		random_access_iterator_data_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(thing.___handle___) };
	}

	static inline random_access_iterator_data_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return random_access_iterator_data_a{ thing.___handle___ };
		}
		return random_access_iterator_data_a{ random_access_iterator_data_d<_1_>{ thing } };
	}

	static inline random_access_iterator_data_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return random_access_iterator_data_a(thing.___handle___, ___reference_tag___{});
		}
		return random_access_iterator_data_a{ random_access_iterator_data_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>>
	___cat_a___ ___cat___() const
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::random_access_iterator_data");
		return CAT;
	}

private:
	static bool const ___share___;
	friend class ___random_access_iterator_data_a_share___;
}; // class random_access_iterator_data_a

template <typename _1_>
bool const random_access_iterator_data_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<random_access_iterator_data_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class random_access_iterator_data_d : public random_access_iterator_d<>
{
public:
	// arithmetic operator overloads
	inline random_access_iterator_data_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_data_d operator++(int)
	{
		assert(___handle___);
		random_access_iterator_data_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline random_access_iterator_data_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_data_d operator--(int)
	{
		assert(___handle___);
		random_access_iterator_data_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline random_access_iterator_data_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline random_access_iterator_data_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline random_access_iterator_data_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline random_access_iterator_data_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline random_access_iterator_data_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline _1_ const & extract_it() const
	{ throw dis("dynamic random_access_iterator_data_d::extract_it() not available"); }

	inline _1_ & mutate_it()
	{ throw dis("dynamic random_access_iterator_data_d::mutate_it() not available"); }

	void ___weak___(random_access_iterator_d<>::___WEAK___ const& weak) const {}

	explicit random_access_iterator_data_d(any_a<> const& thing)
		: random_access_iterator_d<>{ thing }
	{}

	explicit random_access_iterator_data_d(any_a<>& thing, ___reference_tag___)
		: random_access_iterator_d<>{ thing, ___reference_tag___{} }
	{}

	explicit random_access_iterator_data_d(any_a<>& thing, ___duplicate_tag___)
		: random_access_iterator_d<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline random_access_iterator_data_d<_1_> ___random_access_iterator_data_dynamic___(any_a<> const& thing)
{
	return random_access_iterator_data_d<_1_>{ thing };
}

} // namespace
