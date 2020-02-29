
namespace strange
{

template <typename _1_>
class random_access_iterator_data_d;

template <typename _1_>
inline random_access_iterator_data_d<_1_> ___random_access_iterator_data_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk>
inline bool check(random_access_iterator_data_a<_1__chk> const& value) noexcept;

template <typename _1_>
class random_access_iterator_data_a : public random_access_iterator_a<>
{
public:
	// arithmetic operator overloads
	inline random_access_iterator_data_a& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_data_a operator++(int)
	{
		assert(___handle___);
		random_access_iterator_data_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline random_access_iterator_data_a& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_data_a operator--(int)
	{
		assert(___handle___);
		random_access_iterator_data_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline random_access_iterator_data_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline random_access_iterator_data_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline random_access_iterator_data_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline random_access_iterator_data_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline random_access_iterator_data_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline _1_ const & extract_it() const
	{ assert(___handle___); return read().extract_it(); }

	inline _1_ & mutate_it()
	{ assert(___handle___); return write().mutate_it(); }

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
	inline ___random_access_iterator_data_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___random_access_iterator_data_a_handle_base___ const>(___handle___);
	}

	inline ___random_access_iterator_data_a_handle_base___& write() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___random_access_iterator_data_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(random_access_iterator_data_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(handle));
	}

	static inline random_access_iterator_data_a cast(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return random_access_iterator_data_a{ ptr };
		}
		return random_access_iterator_data_a{ random_access_iterator_data_d<_1_>{ thing } };
	}

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

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline random_access_iterator_data_a(std::shared_ptr<___TTT___> const& handle)
		: random_access_iterator_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(handle))
		{
			throw dis("random_access_iterator_data_a constructor failed to cast from base to random_access_iterator_data_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline random_access_iterator_data_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: random_access_iterator_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline random_access_iterator_data_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: random_access_iterator_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(handle))
		{
			throw dis("random_access_iterator_data_a constructor failed to cast from base to random_access_iterator_data_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline random_access_iterator_data_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: random_access_iterator_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_iterator_data_a, std::decay_t<___TTT___>>::value>>
	explicit inline random_access_iterator_data_a(___TTT___ value) noexcept
		: random_access_iterator_a{ std::make_shared<___random_access_iterator_data_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline random_access_iterator_data_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(handle))
		{
			throw dis("random_access_iterator_data_a assignment failed to cast from base to random_access_iterator_data_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline random_access_iterator_data_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_iterator_data_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_iterator_data_a, std::decay_t<___TTT___>>::value>>
	inline random_access_iterator_data_a& operator=(___TTT___ value) noexcept
	{
		random_access_iterator_data_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___random_access_iterator_data_a_share___;
}; // class random_access_iterator_data_a

template <typename ___TTT___, typename _1__chk>
inline bool check(random_access_iterator_data_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

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
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_data_d operator++(int)
	{
		assert(___handle___);
		random_access_iterator_data_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline random_access_iterator_data_d& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline random_access_iterator_data_d operator--(int)
	{
		assert(___handle___);
		random_access_iterator_data_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline random_access_iterator_data_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline random_access_iterator_data_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline random_access_iterator_data_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline random_access_iterator_data_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline random_access_iterator_data_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
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
};

template <typename _1_>
inline random_access_iterator_data_d<_1_> ___random_access_iterator_data_dynamic___(any_a<> const& thing)
{
	return random_access_iterator_data_d<_1_>{ thing };
}

} // namespace
