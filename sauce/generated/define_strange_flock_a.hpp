
namespace strange
{

template <typename _1_ = void>
class flock_d;

template <typename _1_ = void>
inline flock_d<_1_> ___flock_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(flock_a<_1__chk> const& value) noexcept;

template <typename _1_>
class flock_a : public inventory_a<>
{
public:
	// arithmetic operator overloads
	inline flock_a& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline flock_a operator++(int)
	{
		assert(___handle___);
		flock_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline flock_a& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline flock_a operator--(int)
	{
		assert(___handle___);
		flock_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline flock_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline flock_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline flock_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline flock_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline flock_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline std :: vector < any_a < > > const & extract_vector() const
	{ assert(___handle___); return read().extract_vector(); }

	inline std :: vector < any_a < > > & mutate_vector()
	{ assert(___handle___); return write().mutate_vector(); }

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
	inline ___flock_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___flock_a_handle_base___ const>(___handle___);
	}

	inline ___flock_a_handle_base___& write() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___flock_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(flock_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___flock_a_handle_base___>(handle));
	}

	static inline flock_a cast(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___flock_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return flock_a{ ptr };
		}
		return flock_a{ flock_d<_1_>{ thing } };
	}

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

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline flock_a(std::shared_ptr<___TTT___> const& handle)
		: inventory_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___flock_a_handle_base___>(handle))
		{
			throw dis("flock_a constructor failed to cast from base to flock_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline flock_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: inventory_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___flock_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline flock_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: inventory_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___flock_a_handle_base___>(handle))
		{
			throw dis("flock_a constructor failed to cast from base to flock_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline flock_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: inventory_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___flock_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<flock_a, std::decay_t<___TTT___>>::value>>
	explicit inline flock_a(___TTT___ value) noexcept
		: inventory_a{ std::make_shared<___flock_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline flock_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___flock_a_handle_base___>(handle))
		{
			throw dis("flock_a assignment failed to cast from base to flock_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline flock_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___flock_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<flock_a, std::decay_t<___TTT___>>::value>>
	inline flock_a& operator=(___TTT___ value) noexcept
	{
		flock_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___flock_a_share___;
}; // class flock_a

template <typename ___TTT___, typename _1__chk>
inline bool check(flock_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

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
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline flock_d operator++(int)
	{
		assert(___handle___);
		flock_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline flock_d& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline flock_d operator--(int)
	{
		assert(___handle___);
		flock_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline flock_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline flock_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline flock_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline flock_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline flock_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline std :: vector < any_a < > > const & extract_vector() const
	{ throw dis("dynamic flock_d::extract_vector() not available"); }

	inline std :: vector < any_a < > > & mutate_vector()
	{ throw dis("dynamic flock_d::mutate_vector() not available"); }

	explicit flock_d(any_a<> const& thing)
		: inventory_d{ thing }
	{}
};

template <typename _1_>
inline flock_d<_1_> ___flock_dynamic___(any_a<> const& thing)
{
	return flock_d<_1_>{ thing };
}

} // namespace
