
namespace strange
{

template <typename element>
class range_of_d;

template <typename element>
inline range_of_d<element> ___range_of_dynamic___(any_a<> const& thing); 

template <typename element>
class range_of_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline range_of_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline range_of_a operator++(int)
	{
		assert(___handle___);
		range_of_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline range_of_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline range_of_a operator--(int)
	{
		assert(___handle___);
		range_of_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline range_of_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline range_of_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline range_of_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline range_of_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline range_of_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> cbegin__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().cbegin__(arguments); }

	inline forward_const_iterator_a<> cbegin_() const
	{ assert(___handle___); return ___read___().cbegin_(); }

	inline any_a<> cend__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().cend__(arguments); }

	inline forward_const_iterator_a<> cend_() const
	{ assert(___handle___); return ___read___().cend_(); }

protected:
	struct ___range_of_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> cbegin__(range_a<> const& arguments) const = 0;
		virtual forward_const_iterator_a<> cbegin_() const = 0;
		virtual any_a<> cend__(range_a<> const& arguments) const = 0;
		virtual forward_const_iterator_a<> cend_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___range_of_a_handle_base___>
	struct ___range_of_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___range_of_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___range_of_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___range_of_a_handle___(___variadic_tag___, Args&&... args)
			: ___any_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> cbegin__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.cbegin__(arguments); }

		virtual inline forward_const_iterator_a<> cbegin_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.cbegin_(); }

		virtual inline any_a<> cend__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.cend__(arguments); }

		virtual inline forward_const_iterator_a<> cend_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.cend_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___range_of_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___range_of_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___range_of_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___range_of_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___range_of_a_handle_final___ final : ___range_of_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___range_of_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___range_of_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___range_of_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___range_of_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___range_of_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___range_of_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___range_of_a_handle_final___>(___range_of_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___range_of_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___range_of_a_handle_final___<___TTT___&>
	{
		inline ___range_of_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___range_of_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___range_of_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___range_of_a_handle_base___ const>(___handle___);
	}

	inline ___range_of_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___range_of_a_handle_base___>(___handle___);
	}

public:
	static inline range_of_a val(range_of_a const& other) noexcept
	{
		return range_of_a{ other };
	}

	static inline range_of_a ref(range_of_a& other) noexcept
	{
		return range_of_a(other, ___reference_tag___{});
	}

	static inline range_of_a dup(range_of_a& other) noexcept
	{
		return range_of_a(other, ___duplicate_tag___{});
	}

	inline range_of_a() = default;

	inline range_of_a(range_of_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline range_of_a(range_of_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline range_of_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___range_of_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline range_of_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___range_of_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<range_of_a, std::decay_t<___TTT___>>::value>>
	explicit inline range_of_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___range_of_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline range_of_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a{ std::make_shared<___range_of_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline range_of_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___range_of_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<range_of_a, std::decay_t<___TTT___>>::value>>
	inline range_of_a& operator=(___TTT___ value) noexcept
	{
		range_of_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___range_of_a_handle_base___>(thing.___handle___) };
	}

	static inline range_of_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___range_of_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return range_of_a{ thing.___handle___ };
		}
		return range_of_a{ range_of_d<element>{ thing } };
	}

	static inline range_of_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___range_of_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return range_of_a(thing.___handle___, ___reference_tag___{});
		}
		return range_of_a{ range_of_d<element>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::range_of", flock_vals(kind_create<___kind_a___>(2, "")));
		return CAT;
	}

	template <typename ___TTT___, typename... Args>
	static inline range_of_a create(Args&&... args)
	{
		return range_of_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___range_of_a_share___;
}; // class range_of_a

template <typename element>
bool const range_of_a<element>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<range_of_a<element>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename element>
class range_of_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline range_of_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline range_of_d operator++(int)
	{
		assert(___handle___);
		range_of_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline range_of_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline range_of_d operator--(int)
	{
		assert(___handle___);
		range_of_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline range_of_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline range_of_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline range_of_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline range_of_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline range_of_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> cbegin__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("cbegin_");
		if (!op)
		{
			throw dis("dynamic range_of_d::cbegin_ passed non-existent member");
		}
		return op.operate(*const_cast<range_of_d*>(this), arguments);
	}

	inline forward_const_iterator_a<> cbegin_() const
	{
		assert(___handle___);
		auto const op = operation("cbegin_");
		if (!op)
		{
			throw dis("dynamic range_of_d::cbegin_ passed non-existent member");
		}
		return cast<forward_const_iterator_a<>>(variadic_operate(op, *const_cast<range_of_d*>(this)));
	}

	inline any_a<> cend__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("cend_");
		if (!op)
		{
			throw dis("dynamic range_of_d::cend_ passed non-existent member");
		}
		return op.operate(*const_cast<range_of_d*>(this), arguments);
	}

	inline forward_const_iterator_a<> cend_() const
	{
		assert(___handle___);
		auto const op = operation("cend_");
		if (!op)
		{
			throw dis("dynamic range_of_d::cend_ passed non-existent member");
		}
		return cast<forward_const_iterator_a<>>(variadic_operate(op, *const_cast<range_of_d*>(this)));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit range_of_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit range_of_d(any_a<>& thing, ___reference_tag___)
		: any_a<>{ thing, ___reference_tag___{} }
	{}

	explicit range_of_d(any_a<>& thing, ___duplicate_tag___)
		: any_a<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename element>
inline range_of_d<element> ___range_of_dynamic___(any_a<> const& thing)
{
	return range_of_d<element>{ thing };
}

} // namespace
