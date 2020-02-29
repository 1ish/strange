
namespace strange
{

template <typename _1_ = void>
class parser_d;

template <typename _1_ = void>
inline parser_d<_1_> ___parser_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(parser_a<_1__chk> const& value) noexcept;

template <typename _1_>
class parser_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline parser_a& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline parser_a operator++(int)
	{
		assert(___handle___);
		parser_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline parser_a& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline parser_a operator--(int)
	{
		assert(___handle___);
		parser_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline parser_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline parser_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline parser_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline parser_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline parser_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> parse__(range_a<> const& range)
	{ assert(___handle___); return write().parse__(range); }

	inline expression_a<> parse_(range_a<> const& tokenizer)
	{ assert(___handle___); return write().parse_(tokenizer); }

protected:
	struct ___parser_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> parse__(range_a<> const& range) = 0;
		virtual expression_a<> parse_(range_a<> const& tokenizer) = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___parser_a_handle_base___>
	struct ___parser_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___parser_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___parser_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> parse__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.parse__(range); }

		virtual inline expression_a<> parse_(range_a<> const& tokenizer) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.parse_(tokenizer); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___parser_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___parser_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___parser_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___parser_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___parser_a_handle_final___ final : ___parser_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___parser_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___parser_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___parser_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___parser_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___parser_a_handle_final___>(___parser_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___parser_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___parser_a_handle_final___<___TTT___&>
	{
		inline ___parser_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___parser_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___parser_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___parser_a_handle_base___ const>(___handle___);
	}

	inline ___parser_a_handle_base___& write() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___parser_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(parser_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___parser_a_handle_base___>(handle));
	}

	static inline parser_a cast(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___parser_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return parser_a{ ptr };
		}
		return parser_a{ parser_d<_1_>{ thing } };
	}

	static inline parser_a val(parser_a const& other) noexcept
	{
		return parser_a{ other };
	}

	static inline parser_a ref(parser_a& other) noexcept
	{
		return parser_a(other, ___reference_tag___{});
	}

	static inline parser_a dup(parser_a& other) noexcept
	{
		return parser_a(other, ___duplicate_tag___{});
	}

	inline parser_a() = default;

	inline parser_a(parser_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline parser_a(parser_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline parser_a(std::shared_ptr<___TTT___> const& handle)
		: any_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___parser_a_handle_base___>(handle))
		{
			throw dis("parser_a constructor failed to cast from base to parser_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline parser_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___parser_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline parser_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: any_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___parser_a_handle_base___>(handle))
		{
			throw dis("parser_a constructor failed to cast from base to parser_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline parser_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___parser_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<parser_a, std::decay_t<___TTT___>>::value>>
	explicit inline parser_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___parser_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline parser_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___parser_a_handle_base___>(handle))
		{
			throw dis("parser_a assignment failed to cast from base to parser_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline parser_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___parser_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<parser_a, std::decay_t<___TTT___>>::value>>
	inline parser_a& operator=(___TTT___ value) noexcept
	{
		parser_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___parser_a_share___;
}; // class parser_a

template <typename ___TTT___, typename _1__chk>
inline bool check(parser_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

template <typename _1_>
bool const parser_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<parser_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class parser_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline parser_d& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline parser_d operator++(int)
	{
		assert(___handle___);
		parser_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline parser_d& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline parser_d operator--(int)
	{
		assert(___handle___);
		parser_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline parser_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline parser_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline parser_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline parser_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline parser_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> parse__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("parse_");
		if (!op)
		{
			throw dis("dynamic parser_d::parse_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline expression_a<> parse_(range_a<> const& tokenizer)
	{
		assert(___handle___);
		auto const op = operation("parse_");
		if (!op)
		{
			throw dis("dynamic parser_d::parse_ passed non-existent member");
		}
		return variadic_operate(op, *this, tokenizer);
	}

	explicit parser_d(any_a<> const& thing)
		: any_a{ thing }
	{}
};

template <typename _1_>
inline parser_d<_1_> ___parser_dynamic___(any_a<> const& thing)
{
	return parser_d<_1_>{ thing };
}

} // namespace
