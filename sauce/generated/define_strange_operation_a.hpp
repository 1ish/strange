
namespace strange
{

template <typename _1_ = void>
class operation_d;

template <typename _1_ = void>
inline operation_d<_1_> ___operation_dynamic___(any_a<> const& thing); 

template <typename _1_>
class operation_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline operation_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline operation_a operator++(int)
	{
		assert(___handle___);
		operation_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline operation_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline operation_a operator--(int)
	{
		assert(___handle___);
		operation_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline operation_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline operation_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline operation_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline operation_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline operation_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> pure__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().pure__(range); }

	inline any_a<> pure_() const
	{ assert(___handle___); return ___read___().pure_(); }

	inline bool pure() const
	{ assert(___handle___); return ___read___().pure(); }

	inline void aspects(unordered_shoal_a < > const & shoal )
	{ assert(___handle___); ___write___().aspects(shoal); }

	inline void assign(operation_a < > const & operation )
	{ assert(___handle___); ___write___().assign(operation); }

	inline any_a<> names__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().names__(range); }

	inline flock_a<> names_() const
	{ assert(___handle___); return ___read___().names_(); }

protected:
	struct ___operation_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> pure__(range_a<> const& range) const = 0;
		virtual any_a<> pure_() const = 0;
		virtual bool pure() const = 0;
		virtual void aspects(unordered_shoal_a < > const & shoal ) = 0;
		virtual void assign(operation_a < > const & operation ) = 0;
		virtual any_a<> names__(range_a<> const& range) const = 0;
		virtual flock_a<> names_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___operation_a_handle_base___>
	struct ___operation_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___operation_a_handle___(___variadic_tag___, Args&&... args)
			: ___any_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> pure__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.pure__(range); }

		virtual inline any_a<> pure_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.pure_(); }

		virtual inline bool pure() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.pure(); }

		virtual inline void aspects(unordered_shoal_a < > const & shoal ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.aspects(shoal); }

		virtual inline void assign(operation_a < > const & operation ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.assign(operation); }

		virtual inline any_a<> names__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.names__(range); }

		virtual inline flock_a<> names_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.names_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___operation_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___operation_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___operation_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___operation_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___operation_a_handle_final___ final : ___operation_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___operation_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___operation_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___operation_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___operation_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___operation_a_handle_final___>(___operation_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___operation_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___operation_a_handle_final___<___TTT___&>
	{
		inline ___operation_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___operation_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___operation_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___operation_a_handle_base___ const>(___handle___);
	}

	inline ___operation_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___operation_a_handle_base___>(___handle___);
	}

public:
	static inline operation_a val(operation_a const& other) noexcept
	{
		return operation_a{ other };
	}

	static inline operation_a ref(operation_a& other) noexcept
	{
		return operation_a(other, ___reference_tag___{});
	}

	static inline operation_a dup(operation_a& other) noexcept
	{
		return operation_a(other, ___duplicate_tag___{});
	}

	inline operation_a() = default;

	inline operation_a(operation_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline operation_a(operation_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline operation_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___operation_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline operation_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___operation_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<operation_a, std::decay_t<___TTT___>>::value>>
	explicit inline operation_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___operation_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline operation_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a{ std::make_shared<___operation_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline operation_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___operation_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<operation_a, std::decay_t<___TTT___>>::value>>
	inline operation_a& operator=(___TTT___ value) noexcept
	{
		operation_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___operation_a_handle_base___>(thing.___handle___) };
	}

	static inline operation_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___operation_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return operation_a{ thing.___handle___ };
		}
		return operation_a{ operation_d<_1_>{ thing } };
	}

	static inline operation_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___operation_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return operation_a(thing.___handle___, ___reference_tag___{});
		}
		return operation_a{ operation_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	___cat_a___ ___cat___() const
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::operation");
		return CAT;
	}

	template <typename ___TTT___, typename... Args>
	static inline operation_a create(Args&&... args)
	{
		return operation_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___operation_a_share___;
}; // class operation_a

template <typename _1_>
bool const operation_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<operation_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class operation_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline operation_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline operation_d operator++(int)
	{
		assert(___handle___);
		operation_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline operation_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline operation_d operator--(int)
	{
		assert(___handle___);
		operation_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline operation_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline operation_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline operation_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline operation_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline operation_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> pure__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("pure_");
		if (!op)
		{
			throw dis("dynamic operation_d::pure_ passed non-existent member");
		}
		return op.operate(*const_cast<operation_d*>(this), range);
	}

	inline any_a<> pure_() const
	{
		assert(___handle___);
		auto const op = operation("pure_");
		if (!op)
		{
			throw dis("dynamic operation_d::pure_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<operation_d*>(this)));
	}

	inline bool pure() const
	{ return pure_(); }

	inline void aspects(unordered_shoal_a < > const & shoal )
	{ throw dis("dynamic operation_d::aspects(shoal) not available"); }

	inline void assign(operation_a < > const & operation )
	{ throw dis("dynamic operation_d::assign(operation) not available"); }

	inline any_a<> names__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("names_");
		if (!op)
		{
			throw dis("dynamic operation_d::names_ passed non-existent member");
		}
		return op.operate(*const_cast<operation_d*>(this), range);
	}

	inline flock_a<> names_() const
	{
		assert(___handle___);
		auto const op = operation("names_");
		if (!op)
		{
			throw dis("dynamic operation_d::names_ passed non-existent member");
		}
		return cast<flock_a<>>(variadic_operate(op, *const_cast<operation_d*>(this)));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit operation_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit operation_d(any_a<>& thing, ___reference_tag___)
		: any_a<>{ thing, ___reference_tag___{} }
	{}

	explicit operation_d(any_a<>& thing, ___duplicate_tag___)
		: any_a<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline operation_d<_1_> ___operation_dynamic___(any_a<> const& thing)
{
	return operation_d<_1_>{ thing };
}

} // namespace
