
namespace strange
{

template <typename _1_ = void>
class misunderstanding_d;

template <typename _1_ = void>
inline misunderstanding_d<_1_> ___misunderstanding_dynamic___(any_a<> const& thing); 

template <typename _1_>
class misunderstanding_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline misunderstanding_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline misunderstanding_a operator++(int)
	{
		assert(___handle___);
		misunderstanding_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline misunderstanding_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline misunderstanding_a operator--(int)
	{
		assert(___handle___);
		misunderstanding_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline misunderstanding_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline misunderstanding_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline misunderstanding_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline misunderstanding_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline misunderstanding_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: string to_string() const
	{ assert(___handle___); return ___read___().to_string(); }

	inline any_a<> add__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().add__(arguments); }

	inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const
	{ assert(___handle___); return ___read___().add_(misunderstanding); }

	inline misunderstanding_a < > operator+(misunderstanding_a < > const & misunderstanding ) const
	{ assert(___handle___); return ___read___().operator+(misunderstanding); }

protected:
	struct ___misunderstanding_a_handle_base___ : ___any_a_handle_base___
	{
		virtual std :: string to_string() const = 0;
		virtual any_a<> add__(range_a<> const& arguments) const = 0;
		virtual misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const = 0;
		virtual misunderstanding_a < > operator+(misunderstanding_a < > const & misunderstanding ) const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___misunderstanding_a_handle_base___>
	struct ___misunderstanding_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___misunderstanding_a_handle___(___variadic_tag___, Args&&... args)
			: ___any_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline std :: string to_string() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_string(); }

		virtual inline any_a<> add__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.add__(arguments); }

		virtual inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(misunderstanding); }

		virtual inline misunderstanding_a < > operator+(misunderstanding_a < > const & misunderstanding ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator+(misunderstanding); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___misunderstanding_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___misunderstanding_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___misunderstanding_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___misunderstanding_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___misunderstanding_a_handle_final___ final : ___misunderstanding_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___misunderstanding_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___misunderstanding_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___misunderstanding_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___misunderstanding_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___misunderstanding_a_handle_final___>(___misunderstanding_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___misunderstanding_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___misunderstanding_a_handle_final___<___TTT___&>
	{
		inline ___misunderstanding_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___misunderstanding_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___misunderstanding_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___misunderstanding_a_handle_base___ const>(___handle___);
	}

	inline ___misunderstanding_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___misunderstanding_a_handle_base___>(___handle___);
	}

public:
	static inline misunderstanding_a val(misunderstanding_a const& other) noexcept
	{
		return misunderstanding_a{ other };
	}

	static inline misunderstanding_a ref(misunderstanding_a& other) noexcept
	{
		return misunderstanding_a(other, ___reference_tag___{});
	}

	static inline misunderstanding_a dup(misunderstanding_a& other) noexcept
	{
		return misunderstanding_a(other, ___duplicate_tag___{});
	}

	inline misunderstanding_a() = default;

	inline misunderstanding_a(misunderstanding_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline misunderstanding_a(misunderstanding_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline misunderstanding_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline misunderstanding_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<misunderstanding_a, std::decay_t<___TTT___>>::value>>
	explicit inline misunderstanding_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___misunderstanding_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline misunderstanding_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a{ std::make_shared<___misunderstanding_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline misunderstanding_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<misunderstanding_a, std::decay_t<___TTT___>>::value>>
	inline misunderstanding_a& operator=(___TTT___ value) noexcept
	{
		misunderstanding_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(thing.___handle___) };
	}

	static inline misunderstanding_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return misunderstanding_a{ thing.___handle___ };
		}
		return misunderstanding_a{ misunderstanding_d<_1_>{ thing } };
	}

	static inline misunderstanding_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return misunderstanding_a(thing.___handle___, ___reference_tag___{});
		}
		return misunderstanding_a{ misunderstanding_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::misunderstanding");
		return CAT;
	}

	template <typename ___TTT___, typename... Args>
	static inline misunderstanding_a create(Args&&... args)
	{
		return misunderstanding_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___misunderstanding_a_share___;
}; // class misunderstanding_a

template <typename _1_>
bool const misunderstanding_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<misunderstanding_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
class misunderstanding_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline misunderstanding_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline misunderstanding_d operator++(int)
	{
		assert(___handle___);
		misunderstanding_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline misunderstanding_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline misunderstanding_d operator--(int)
	{
		assert(___handle___);
		misunderstanding_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline misunderstanding_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline misunderstanding_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline misunderstanding_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline misunderstanding_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline misunderstanding_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: string to_string() const
	{ throw dis("dynamic misunderstanding_d::to_string() not available"); }

	inline any_a<> add__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic misunderstanding_d::add_ passed non-existent member");
		}
		return op.operate(*const_cast<misunderstanding_d*>(this), arguments);
	}

	inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic misunderstanding_d::add_ passed non-existent member");
		}
		return cast<misunderstanding_a<>>(variadic_operate(op, *const_cast<misunderstanding_d*>(this), misunderstanding));
	}

	inline misunderstanding_a < > operator+(misunderstanding_a < > const & misunderstanding ) const
	{ return add_(misunderstanding); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit misunderstanding_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit misunderstanding_d(any_a<>& thing, ___reference_tag___)
		: any_a<>{ thing, ___reference_tag___{} }
	{}

	explicit misunderstanding_d(any_a<>& thing, ___duplicate_tag___)
		: any_a<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline misunderstanding_d<_1_> ___misunderstanding_dynamic___(any_a<> const& thing)
{
	return misunderstanding_d<_1_>{ thing };
}

} // namespace
