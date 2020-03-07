
namespace strange
{

template <typename _1_ = void>
class symbol_d;

template <typename _1_ = void>
inline symbol_d<_1_> ___symbol_dynamic___(any_a<> const& thing); 

template <typename _1_>
class symbol_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline symbol_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline symbol_a operator++(int)
	{
		assert(___handle___);
		symbol_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline symbol_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline symbol_a operator--(int)
	{
		assert(___handle___);
		symbol_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline symbol_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline symbol_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline symbol_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline symbol_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline symbol_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> to_lake__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().to_lake__(arguments); }

	inline lake_int8_a<> to_lake_() const
	{ assert(___handle___); return ___read___().to_lake_(); }

	inline std :: string to_string() const
	{ assert(___handle___); return ___read___().to_string(); }

	inline int8_t first_character() const
	{ assert(___handle___); return ___read___().first_character(); }

	inline int8_t last_character() const
	{ assert(___handle___); return ___read___().last_character(); }

	inline any_a<> add__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().add__(arguments); }

	inline symbol_a<> add_(symbol_a<> const& symbol) const
	{ assert(___handle___); return ___read___().add_(symbol); }

	inline symbol_a < > operator+(symbol_a < > const & symbol ) const
	{ assert(___handle___); return ___read___().operator+(symbol); }

protected:
	struct ___symbol_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> to_lake__(range_a<> const& arguments) const = 0;
		virtual lake_int8_a<> to_lake_() const = 0;
		virtual std :: string to_string() const = 0;
		virtual int8_t first_character() const = 0;
		virtual int8_t last_character() const = 0;
		virtual any_a<> add__(range_a<> const& arguments) const = 0;
		virtual symbol_a<> add_(symbol_a<> const& symbol) const = 0;
		virtual symbol_a < > operator+(symbol_a < > const & symbol ) const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___symbol_a_handle_base___>
	struct ___symbol_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___symbol_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___symbol_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___symbol_a_handle___(___variadic_tag___, Args&&... args)
			: ___any_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> to_lake__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_lake__(arguments); }

		virtual inline lake_int8_a<> to_lake_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_lake_(); }

		virtual inline std :: string to_string() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_string(); }

		virtual inline int8_t first_character() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.first_character(); }

		virtual inline int8_t last_character() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.last_character(); }

		virtual inline any_a<> add__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.add__(arguments); }

		virtual inline symbol_a<> add_(symbol_a<> const& symbol) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(symbol); }

		virtual inline symbol_a < > operator+(symbol_a < > const & symbol ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator+(symbol); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___symbol_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___symbol_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___symbol_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___symbol_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___symbol_a_handle_final___ final : ___symbol_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___symbol_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___symbol_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___symbol_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___symbol_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___symbol_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___symbol_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___symbol_a_handle_final___>(___symbol_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___symbol_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___symbol_a_handle_final___<___TTT___&>
	{
		inline ___symbol_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___symbol_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___symbol_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___symbol_a_handle_base___ const>(___handle___);
	}

	inline ___symbol_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___symbol_a_handle_base___>(___handle___);
	}

public:
	static inline symbol_a val(symbol_a const& other) noexcept
	{
		return symbol_a{ other };
	}

	static inline symbol_a ref(symbol_a& other) noexcept
	{
		return symbol_a(other, ___reference_tag___{});
	}

	static inline symbol_a dup(symbol_a& other) noexcept
	{
		return symbol_a(other, ___duplicate_tag___{});
	}

	inline symbol_a() = default;

	inline symbol_a(symbol_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline symbol_a(symbol_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline symbol_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___symbol_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline symbol_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___symbol_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<symbol_a, std::decay_t<___TTT___>>::value>>
	explicit inline symbol_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___symbol_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline symbol_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a{ std::make_shared<___symbol_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline symbol_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___symbol_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<symbol_a, std::decay_t<___TTT___>>::value>>
	inline symbol_a& operator=(___TTT___ value) noexcept
	{
		symbol_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___symbol_a_handle_base___>(thing.___handle___) };
	}

	static inline symbol_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___symbol_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return symbol_a{ thing.___handle___ };
		}
		return symbol_a{ symbol_d<_1_>{ thing } };
	}

	static inline symbol_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___symbol_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return symbol_a(thing.___handle___, ___reference_tag___{});
		}
		return symbol_a{ symbol_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::symbol");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = any_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>());
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = any_a::___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___TTT___, typename... Args>
	static inline symbol_a create(Args&&... args)
	{
		return symbol_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___symbol_a_share___;
}; // class symbol_a

template <typename _1_>
bool const symbol_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<symbol_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
class symbol_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline symbol_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline symbol_d operator++(int)
	{
		assert(___handle___);
		symbol_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline symbol_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline symbol_d operator--(int)
	{
		assert(___handle___);
		symbol_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline symbol_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline symbol_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline symbol_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline symbol_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline symbol_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> to_lake__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("to_lake_");
		if (!op)
		{
			throw dis("dynamic symbol_d::to_lake_ passed non-existent member");
		}
		return op.operate(*const_cast<symbol_d*>(this), arguments);
	}

	inline lake_int8_a<> to_lake_() const
	{
		assert(___handle___);
		auto const op = operation("to_lake_");
		if (!op)
		{
			throw dis("dynamic symbol_d::to_lake_ passed non-existent member");
		}
		return cast<lake_int8_a<>>(variadic_operate(op, *const_cast<symbol_d*>(this)));
	}

	inline std :: string to_string() const
	{ return lake_to_string(to_lake_()); }

	inline int8_t first_character() const
	{ return to_lake_().extract_vector()[0]; }

	inline int8_t last_character() const
	{ auto const lake = to_lake_(); return lake.extract_vector()[lake.size() - 1]; }

	inline any_a<> add__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic symbol_d::add_ passed non-existent member");
		}
		return op.operate(*const_cast<symbol_d*>(this), arguments);
	}

	inline symbol_a<> add_(symbol_a<> const& symbol) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic symbol_d::add_ passed non-existent member");
		}
		return cast<symbol_a<>>(variadic_operate(op, *const_cast<symbol_d*>(this), symbol));
	}

	inline symbol_a < > operator+(symbol_a < > const & symbol ) const
	{ return add_(symbol); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit symbol_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit symbol_d(any_a<>& thing, ___reference_tag___)
		: any_a<>{ thing, ___reference_tag___{} }
	{}

	explicit symbol_d(any_a<>& thing, ___duplicate_tag___)
		: any_a<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline symbol_d<_1_> ___symbol_dynamic___(any_a<> const& thing)
{
	return symbol_d<_1_>{ thing };
}

} // namespace
