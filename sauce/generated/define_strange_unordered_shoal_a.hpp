
namespace strange
{

template <typename _1_ = void>
class unordered_shoal_d;

template <typename _1_ = void>
inline unordered_shoal_d<_1_> ___unordered_shoal_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(unordered_shoal_a<_1__chk> const& value) noexcept;

template <typename _1_>
class unordered_shoal_a : public shoal_a<>
{
public:
	// arithmetic operator overloads
	inline unordered_shoal_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline unordered_shoal_a operator++(int)
	{
		assert(___handle___);
		unordered_shoal_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline unordered_shoal_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline unordered_shoal_a operator--(int)
	{
		assert(___handle___);
		unordered_shoal_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline unordered_shoal_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline unordered_shoal_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline unordered_shoal_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline unordered_shoal_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline unordered_shoal_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: unordered_map < any_a < > , any_a < > , any_a < > :: hash_f > const & extract_map() const
	{ assert(___handle___); return ___read___().extract_map(); }

	inline std :: unordered_map < any_a < > , any_a < > , any_a < > :: hash_f > & mutate_map()
	{ assert(___handle___); return ___write___().mutate_map(); }

protected:
	struct ___unordered_shoal_a_handle_base___ : ___shoal_a_handle_base___
	{
		virtual std :: unordered_map < any_a < > , any_a < > , any_a < > :: hash_f > const & extract_map() const = 0;
		virtual std :: unordered_map < any_a < > , any_a < > , any_a < > :: hash_f > & mutate_map() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___unordered_shoal_a_handle_base___>
	struct ___unordered_shoal_a_handle___ : ___shoal_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_shoal_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___shoal_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_shoal_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___shoal_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline std :: unordered_map < any_a < > , any_a < > , any_a < > :: hash_f > const & extract_map() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_map(); }

		virtual inline std :: unordered_map < any_a < > , any_a < > , any_a < > :: hash_f > & mutate_map() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_map(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___unordered_shoal_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___unordered_shoal_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___unordered_shoal_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___unordered_shoal_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___unordered_shoal_a_handle_final___ final : ___unordered_shoal_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_shoal_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___unordered_shoal_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_shoal_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___unordered_shoal_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___unordered_shoal_a_handle_final___>(___unordered_shoal_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___unordered_shoal_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___unordered_shoal_a_handle_final___<___TTT___&>
	{
		inline ___unordered_shoal_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___unordered_shoal_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___unordered_shoal_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___unordered_shoal_a_handle_base___ const>(___handle___);
	}

	inline ___unordered_shoal_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___unordered_shoal_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(unordered_shoal_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(handle));
	}

	static inline unordered_shoal_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return unordered_shoal_a{ ptr };
		}
		return unordered_shoal_a{ unordered_shoal_d<_1_>{ thing } };
	}

	static inline unordered_shoal_a val(unordered_shoal_a const& other) noexcept
	{
		return unordered_shoal_a{ other };
	}

	static inline unordered_shoal_a ref(unordered_shoal_a& other) noexcept
	{
		return unordered_shoal_a(other, ___reference_tag___{});
	}

	static inline unordered_shoal_a dup(unordered_shoal_a& other) noexcept
	{
		return unordered_shoal_a(other, ___duplicate_tag___{});
	}

	inline unordered_shoal_a() = default;

	inline unordered_shoal_a(unordered_shoal_a& other, ___reference_tag___) noexcept
		: shoal_a(other, ___reference_tag___{})
	{}

	inline unordered_shoal_a(unordered_shoal_a& other, ___duplicate_tag___) noexcept
		: shoal_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline unordered_shoal_a(std::shared_ptr<___TTT___> const& handle)
		: shoal_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(handle))
		{
			throw dis("unordered_shoal_a constructor failed to cast from base to unordered_shoal_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline unordered_shoal_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: shoal_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline unordered_shoal_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: shoal_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(handle))
		{
			throw dis("unordered_shoal_a constructor failed to cast from base to unordered_shoal_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline unordered_shoal_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: shoal_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<unordered_shoal_a, std::decay_t<___TTT___>>::value>>
	explicit inline unordered_shoal_a(___TTT___ value) noexcept
		: shoal_a{ std::make_shared<___unordered_shoal_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline unordered_shoal_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(handle))
		{
			throw dis("unordered_shoal_a assignment failed to cast from base to unordered_shoal_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline unordered_shoal_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<unordered_shoal_a, std::decay_t<___TTT___>>::value>>
	inline unordered_shoal_a& operator=(___TTT___ value) noexcept
	{
		unordered_shoal_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___unordered_shoal_a_share___;
}; // class unordered_shoal_a

template <typename ___TTT___, typename _1__chk>
inline bool check(unordered_shoal_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

template <typename _1_>
bool const unordered_shoal_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<unordered_shoal_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class unordered_shoal_d : public shoal_d<>
{
public:
	// arithmetic operator overloads
	inline unordered_shoal_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline unordered_shoal_d operator++(int)
	{
		assert(___handle___);
		unordered_shoal_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline unordered_shoal_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline unordered_shoal_d operator--(int)
	{
		assert(___handle___);
		unordered_shoal_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline unordered_shoal_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline unordered_shoal_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline unordered_shoal_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline unordered_shoal_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline unordered_shoal_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: unordered_map < any_a < > , any_a < > , any_a < > :: hash_f > const & extract_map() const
	{ throw dis("dynamic unordered_shoal_d::extract_map() not available"); }

	inline std :: unordered_map < any_a < > , any_a < > , any_a < > :: hash_f > & mutate_map()
	{ throw dis("dynamic unordered_shoal_d::mutate_map() not available"); }

	void ___weak___(shoal_d<>::___WEAK___ const& weak) const {}

	explicit unordered_shoal_d(any_a<> const& thing)
		: shoal_d<>{ thing }
	{}
};

template <typename _1_>
inline unordered_shoal_d<_1_> ___unordered_shoal_dynamic___(any_a<> const& thing)
{
	return unordered_shoal_d<_1_>{ thing };
}

} // namespace
