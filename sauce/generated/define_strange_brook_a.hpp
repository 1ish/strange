
namespace strange
{

template <typename _1_>
class brook_d;

template <typename _1_>
inline brook_d<_1_> ___brook_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk>
inline bool check(brook_a<_1__chk> const& value) noexcept;

template <typename _1_>
class brook_a : public inventory_a<>
{
public:
	// arithmetic operator overloads
	inline brook_a& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline brook_a operator++(int)
	{
		assert(___handle___);
		brook_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline brook_a& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline brook_a operator--(int)
	{
		assert(___handle___);
		brook_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline brook_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline brook_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline brook_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline brook_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline brook_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline std :: deque < _1_ > const & extract_deque() const
	{ assert(___handle___); return read().extract_deque(); }

	inline std :: deque < _1_ > & mutate_deque()
	{ assert(___handle___); return write().mutate_deque(); }

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
	inline ___brook_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___brook_a_handle_base___ const>(___handle___);
	}

	inline ___brook_a_handle_base___& write() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___brook_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(brook_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___brook_a_handle_base___>(handle));
	}

	static inline brook_a cast(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___brook_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return brook_a{ ptr };
		}
		return brook_a{ brook_d<_1_>{ thing } };
	}

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

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline brook_a(std::shared_ptr<___TTT___> const& handle)
		: inventory_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___brook_a_handle_base___>(handle))
		{
			throw dis("brook_a constructor failed to cast from base to brook_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline brook_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: inventory_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___brook_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline brook_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: inventory_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___brook_a_handle_base___>(handle))
		{
			throw dis("brook_a constructor failed to cast from base to brook_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline brook_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: inventory_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___brook_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<brook_a, std::decay_t<___TTT___>>::value>>
	explicit inline brook_a(___TTT___ value) noexcept
		: inventory_a{ std::make_shared<___brook_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline brook_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___brook_a_handle_base___>(handle))
		{
			throw dis("brook_a assignment failed to cast from base to brook_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline brook_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___brook_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<brook_a, std::decay_t<___TTT___>>::value>>
	inline brook_a& operator=(___TTT___ value) noexcept
	{
		brook_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___brook_a_share___;
}; // class brook_a

template <typename ___TTT___, typename _1__chk>
inline bool check(brook_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

template <typename _1_>
bool const brook_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<brook_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class brook_d : public inventory_d<>
{
public:
	// arithmetic operator overloads
	inline brook_d& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline brook_d operator++(int)
	{
		assert(___handle___);
		brook_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline brook_d& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline brook_d operator--(int)
	{
		assert(___handle___);
		brook_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline brook_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline brook_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline brook_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline brook_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline brook_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline std :: deque < _1_ > const & extract_deque() const
	{ throw dis("dynamic brook_d::extract_deque() not available"); }

	inline std :: deque < _1_ > & mutate_deque()
	{ throw dis("dynamic brook_d::mutate_deque() not available"); }

	explicit brook_d(any_a<> const& thing)
		: inventory_d{ thing }
	{}
};

template <typename _1_>
inline brook_d<_1_> ___brook_dynamic___(any_a<> const& thing)
{
	return brook_d<_1_>{ thing };
}

} // namespace
