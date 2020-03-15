
namespace strange
{

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
class any_a
{
protected:
	struct ___any_a_handle_base___;

public:
	// constructor tags
	struct ___reference_tag___ {};
	struct ___duplicate_tag___ {};

	struct ___variadic_tag___ {};

	// shared pointer typedefs
	using ___WEAK___ = std::weak_ptr<___any_a_handle_base___>;
	using ___SHARED___ = std::shared_ptr<___any_a_handle_base___>;

	// operator overloads
	inline any_a<> operator[](range const& arguments)
	{
		return invoke(*this, arguments);
	}

	inline any_a<> operator()(range const& arguments)
	{
		return operate(*this, arguments);
	}

	inline operator bool() const
	{
		assert(___handle___);
		return ___read___().operator bool();
	}

	// trigger copy on write
	void mutate()
	{
		assert(___handle___);
		___write___();
	}

	inline one_t const & extract_thing() const
	{ assert(___handle___); return ___read___().extract_thing(); }

	inline one_t & mutate_thing()
	{ assert(___handle___); return ___write___().mutate_thing(); }

	inline any_a<> type__(range const& ___arguments___) const;

	inline symbol type_() const
	{ assert(___handle___); return ___read___().type_(); }

	inline any_a<> cat__(range const& ___arguments___) const;

	inline cat cat_() const
	{ assert(___handle___); return ___read___().cat_(); }

	inline any_a<> cats__(range const& ___arguments___) const;

	inline unordered_herd cats_() const
	{ assert(___handle___); return ___read___().cats_(); }

	inline any_a<> kind__(range const& ___arguments___) const;

	inline kind kind_() const
	{ assert(___handle___); return ___read___().kind_(); }

	inline any_a<> kinds__(range const& ___arguments___) const;

	inline unordered_herd kinds_() const
	{ assert(___handle___); return ___read___().kinds_(); }

	inline any_a<> operations__(range const& ___arguments___) const;

	inline unordered_shoal operations_() const
	{ assert(___handle___); return ___read___().operations_(); }

	inline any_a<> visit__(range const& ___arguments___) const;

	inline any_a<> visit_(inventory & arguments) const
	{ assert(___handle___); return ___read___().visit_(arguments); }

	inline any_a < > invoke(any_a < > & thing , range const & arguments ) const
	{ assert(___handle___); return ___read___().invoke(thing, arguments); }

	inline any_a < > operate(any_a < > & thing , range const & arguments ) const
	{ assert(___handle___); return ___read___().operate(thing, arguments); }

	inline any_a<> identity__(range const& ___arguments___) const;

	inline number_data_uint64 identity_() const
	{ assert(___handle___); return ___read___().identity_(); }

	inline void const * identity() const
	{ assert(___handle___); return ___read___().identity(); }

	inline any_a<> identical__(range const& ___arguments___) const;

	inline any_a<> identical_(any_a<> const& thing) const
	{ assert(___handle___); return ___read___().identical_(thing); }

	inline bool identical(any_a < > const & thing ) const
	{ assert(___handle___); return ___read___().identical(thing); }

	inline any_a<> nothing__(range const& ___arguments___) const;

	inline any_a<> nothing_() const
	{ assert(___handle___); return ___read___().nothing_(); }

	inline bool nothing() const
	{ assert(___handle___); return ___read___().nothing(); }

	inline any_a<> something__(range const& ___arguments___) const;

	inline any_a<> something_() const
	{ assert(___handle___); return ___read___().something_(); }

	inline bool something() const
	{ assert(___handle___); return ___read___().something(); }

	inline any_a<> same__(range const& ___arguments___) const;

	inline any_a<> same_(any_a<> const& thing) const
	{ assert(___handle___); return boole(___read___().same_(thing)); }

	inline bool operator==(any_a<> const& thing) const
	{ assert(___handle___); return ___read___().same_(thing); }

	inline any_a<> different__(range const& ___arguments___) const;

	inline any_a<> different_(any_a<> const& thing) const
	{ assert(___handle___); return boole(___read___().different_(thing)); }

	inline bool operator!=(any_a<> const& thing) const
	{ assert(___handle___); return ___read___().different_(thing); }

	inline any_a<> less_than__(range const& ___arguments___) const;

	inline any_a<> less_than_(any_a<> const& thing) const
	{ assert(___handle___); return boole(___read___().less_than_(thing)); }

	inline bool operator<(any_a<> const& thing) const
	{ assert(___handle___); return ___read___().less_than_(thing); }

	inline any_a<> greater_than__(range const& ___arguments___) const;

	inline any_a<> greater_than_(any_a<> const& thing) const
	{ assert(___handle___); return boole(___read___().greater_than_(thing)); }

	inline bool operator>(any_a<> const& thing) const
	{ assert(___handle___); return ___read___().greater_than_(thing); }

	inline any_a<> less_or_equal__(range const& ___arguments___) const;

	inline any_a<> less_or_equal_(any_a<> const& thing) const
	{ assert(___handle___); return boole(___read___().less_or_equal_(thing)); }

	inline bool operator<=(any_a<> const& thing) const
	{ assert(___handle___); return ___read___().less_or_equal_(thing); }

	inline any_a<> greater_or_equal__(range const& ___arguments___) const;

	inline any_a<> greater_or_equal_(any_a<> const& thing) const
	{ assert(___handle___); return boole(___read___().greater_or_equal_(thing)); }

	inline bool operator>=(any_a<> const& thing) const
	{ assert(___handle___); return ___read___().greater_or_equal_(thing); }

	inline any_a<> hash__(range const& ___arguments___) const;

	inline number_data_uint64 hash_() const
	{ assert(___handle___); return ___read___().hash_(); }

	inline std :: size_t hash() const
	{ assert(___handle___); return ___read___().hash(); }

	inline bool is(std :: string const & s ) const
	{ assert(___handle___); return ___read___().is(s); }

protected:
	struct ___any_a_handle_base___
	{
		___any_a_handle_base___() = default;
		___any_a_handle_base___(___any_a_handle_base___ const&) = default;
		___any_a_handle_base___(___any_a_handle_base___&&) = default;
		___any_a_handle_base___& operator=(___any_a_handle_base___ const&) = default;
		___any_a_handle_base___& operator=(___any_a_handle_base___&&) = default;
		virtual ~___any_a_handle_base___() = default;
		virtual ___SHARED___ ___clone___() const = 0;
		virtual void ___weak___(___WEAK___ const& weak) const = 0;
		virtual operator bool() const = 0;
		virtual one_t const & extract_thing() const = 0;
		virtual one_t & mutate_thing() = 0;
		virtual symbol type_() const = 0;
		virtual cat cat_() const = 0;
		virtual unordered_herd cats_() const = 0;
		virtual kind kind_() const = 0;
		virtual unordered_herd kinds_() const = 0;
		virtual unordered_shoal operations_() const = 0;
		virtual any_a<> visit_(inventory & arguments) const = 0;
		virtual any_a < > invoke(any_a < > & thing , range const & arguments ) const = 0;
		virtual any_a < > operate(any_a < > & thing , range const & arguments ) const = 0;
		virtual number_data_uint64 identity_() const = 0;
		virtual void const * identity() const = 0;
		virtual any_a<> identical_(any_a<> const& thing) const = 0;
		virtual bool identical(any_a < > const & thing ) const = 0;
		virtual any_a<> nothing_() const = 0;
		virtual bool nothing() const = 0;
		virtual any_a<> something_() const = 0;
		virtual bool something() const = 0;
		virtual bool same_(any_a<> const& thing) const = 0;
		virtual bool different_(any_a<> const& thing) const = 0;
		virtual bool less_than_(any_a<> const& thing) const = 0;
		virtual bool greater_than_(any_a<> const& thing) const = 0;
		virtual bool less_or_equal_(any_a<> const& thing) const = 0;
		virtual bool greater_or_equal_(any_a<> const& thing) const = 0;
		virtual number_data_uint64 hash_() const = 0;
		virtual std :: size_t hash() const = 0;
		virtual bool is(std :: string const & s ) const = 0;
	};

	template <typename ___TTT___, typename ___BHB___ = ___any_a_handle_base___>
	struct ___any_a_handle___ : ___BHB___
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___any_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___value___{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___any_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___value___{ std::move(value) }
		{}

		template <typename... Args>
		inline ___any_a_handle___(___variadic_tag___, Args&&... args)
			: ___value___(std::forward<Args>(args)...)
		{}

		virtual inline void ___weak___(___WEAK___ const& weak) const final
		{
			___value___.___weak___(weak);
		}

		virtual inline operator bool() const final
		{
			return ___value___.operator bool();
		}

		virtual inline one_t const & extract_thing() const final
		{ return ___value___.extract_thing(); }

		virtual inline one_t & mutate_thing() final
		{ return ___value___.mutate_thing(); }

		virtual inline symbol type_() const final
		{ return ___value___.type_(); }

		virtual inline cat cat_() const final
		{ return ___value___.cat_(); }

		virtual inline unordered_herd cats_() const final
		{ return ___value___.cats_(); }

		virtual inline kind kind_() const final
		{ return ___value___.kind_(); }

		virtual inline unordered_herd kinds_() const final
		{ return ___value___.kinds_(); }

		virtual inline unordered_shoal operations_() const final
		{ return ___value___.operations_(); }

		virtual inline any_a<> visit_(inventory & arguments) const final
		{ return ___value___.visit_(arguments); }

		virtual inline any_a < > invoke(any_a < > & thing , range const & arguments ) const final
		{ return ___value___.invoke(thing, arguments); }

		virtual inline any_a < > operate(any_a < > & thing , range const & arguments ) const final
		{ return ___value___.operate(thing, arguments); }

		virtual inline number_data_uint64 identity_() const final
		{ return ___value___.identity_(); }

		virtual inline void const * identity() const final
		{ return ___value___.identity(); }

		virtual inline any_a<> identical_(any_a<> const& thing) const final
		{ return ___value___.identical_(thing); }

		virtual inline bool identical(any_a < > const & thing ) const final
		{ return ___value___.identical(thing); }

		virtual inline any_a<> nothing_() const final
		{ return ___value___.nothing_(); }

		virtual inline bool nothing() const final
		{ return ___value___.nothing(); }

		virtual inline any_a<> something_() const final
		{ return ___value___.something_(); }

		virtual inline bool something() const final
		{ return ___value___.something(); }

		virtual inline bool same_(any_a<> const& thing) const final
		{ return bool{ ___value___.same_(thing) }; }

		virtual inline bool different_(any_a<> const& thing) const final
		{ return bool{ ___value___.different_(thing) }; }

		virtual inline bool less_than_(any_a<> const& thing) const final
		{ return bool{ ___value___.less_than_(thing) }; }

		virtual inline bool greater_than_(any_a<> const& thing) const final
		{ return bool{ ___value___.greater_than_(thing) }; }

		virtual inline bool less_or_equal_(any_a<> const& thing) const final
		{ return bool{ ___value___.less_or_equal_(thing) }; }

		virtual inline bool greater_or_equal_(any_a<> const& thing) const final
		{ return bool{ ___value___.greater_or_equal_(thing) }; }

		virtual inline number_data_uint64 hash_() const final
		{ return ___value___.hash_(); }

		virtual inline std :: size_t hash() const final
		{ return ___value___.hash(); }

		virtual inline bool is(std :: string const & s ) const final
		{ return ___value___.is(s); }

		___TTT___ ___value___;
	};

	template <typename ___TTT___, typename ___BHB___>
	struct ___any_a_handle___<std::reference_wrapper<___TTT___>, ___BHB___>
		: ___any_a_handle___<___TTT___&, ___BHB___>
	{
		inline ___any_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___any_a_handle___<___TTT___&, ___BHB___>{ ref.get() }
		{}
	};

	___SHARED___ ___shared___;

public:
	___SHARED___& ___handle___;

private:
	template <typename ___TTT___>
	struct ___any_a_handle_final___ final : ___any_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___any_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___any_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___any_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___any_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___any_a_handle_final___>(___any_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___any_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___any_a_handle_final___<___TTT___&>
	{
		inline ___any_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___any_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___any_a_handle_base___ const& ___read___() const noexcept
	{
		return *___handle___;
	}

	inline ___any_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *___handle___;
	}

	inline any_a<> operation(std::string const& name) const
	{
		return ___read___().operations_().at_string(name);
	}

public:
	inline bool is_ref() const
	{
		return &___handle___ != &___shared___;
	}

	static inline any_a val(any_a const& other) noexcept
	{
		return any_a{ other };
	}

	static inline any_a ref(any_a& other) noexcept
	{
		return any_a(other, ___reference_tag___{});
	}

	static inline any_a dup(any_a& other) noexcept
	{
		return any_a(other, ___duplicate_tag___{});
	}

	inline any_a() noexcept
		: ___shared___{}
		, ___handle___{ ___shared___ }
	{}

	inline any_a(any_a const& other) noexcept
		: ___shared___{ other.___handle___ }
		, ___handle___{ ___shared___ }
	{}

	inline any_a(any_a& other, ___reference_tag___) noexcept
		: ___shared___{ ___SHARED___{} }
		, ___handle___{ other.___handle___ }
	{}

	inline any_a(any_a& other, ___duplicate_tag___) noexcept
		: ___shared___{ &other.___handle___ == &other.___shared___ ? other.___handle___ : ___SHARED___{} }
		, ___handle___{ *(&other.___handle___ == &other.___shared___ ? &___shared___ : &other.___handle___) }
	{}

	inline any_a(any_a&& other) noexcept
	: ___shared___{ other.___handle___ }
	, ___handle___{ ___shared___ }
	{}

	inline any_a& operator=(any_a const& other) noexcept
	{
		___handle___ = other.___handle___;
		return *this;
	}

	inline any_a& operator=(any_a&& other) noexcept
	{
		___handle___ = other.___handle___;
		return *this;
	}

	virtual ~any_a() = default;

	template <typename ___TTT___>
	explicit inline any_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: ___shared___{ handle }
		, ___handle___{ ___shared___ }
	{}

	template <typename ___TTT___>
	explicit inline any_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: ___shared___{ ___SHARED___{} }
		, ___handle___{ reinterpret_cast<___SHARED___&>(handle) }
	{}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<any_a, std::decay_t<___TTT___>>::value>>
	explicit inline any_a(___TTT___ value) noexcept
		: ___shared___{ std::make_shared<___any_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
		, ___handle___{ ___shared___ }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline any_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: ___shared___{ std::make_shared<___any_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
		, ___handle___{ ___shared___ }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline any_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<any_a, std::decay_t<___TTT___>>::value>>
	inline any_a& operator=(___TTT___ value) noexcept
	{
		any_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ thing.___handle___ };
	}

	static inline any_a<> ___cast___(any_a<> const& thing)
	{
		return thing;
	}

	static inline any_a<> ___cast_ref___(any_a<>& thing)
	{
		return any_a<>(thing, ___reference_tag___{});
	}

	template <typename ___cat_a___ = cat, typename ___kind_a___ = kind>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::any");
		return CAT;
	}

	template <typename ___cat_a___ = cat, typename ___kind_a___ = kind, typename ___unordered_herd_a___ = unordered_herd>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = unordered_herd_vals(___cat___<___cat_a___, ___kind_a___>());
		return CATS;
	}

	template <typename ___cat_a___ = cat, typename ___kind_a___ = kind>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>());
		return KIND;
	}

	template <typename ___cat_a___ = cat, typename ___kind_a___ = kind, typename ___unordered_herd_a___ = unordered_herd>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = unordered_herd_vals(___kind___<___cat_a___, ___kind_a___>());
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal>
	static inline ___unordered_shoal_a___ ___operations___()
	{
		static ___unordered_shoal_a___ OPERATIONS = []()
		{
			___unordered_shoal_a___ operations = unordered_shoal_create<false, ___unordered_shoal_a___>();
			operations.update_string("call_", native_mutation_t<any_a>::create(&any_a::operator[]));
			operations.update_string("perform_", native_mutation_t<any_a>::create(&any_a::operator()));
			operations.update_string("type_", native_extraction_t<any_a>::create(&any_a::type__));
			operations.update_string("cat_", native_extraction_t<any_a>::create(&any_a::cat__));
			operations.update_string("cats_", native_extraction_t<any_a>::create(&any_a::cats__));
			operations.update_string("kind_", native_extraction_t<any_a>::create(&any_a::kind__));
			operations.update_string("kinds_", native_extraction_t<any_a>::create(&any_a::kinds__));
			operations.update_string("operations_", native_extraction_t<any_a>::create(&any_a::operations__));
			operations.update_string("visit_", native_extraction_t<any_a>::create(&any_a::visit__));
			operations.update_string("identity_", native_extraction_t<any_a>::create(&any_a::identity__));
			operations.update_string("identical_", native_extraction_t<any_a>::create(&any_a::identical__));
			operations.update_string("nothing_", native_extraction_t<any_a>::create(&any_a::nothing__));
			operations.update_string("something_", native_extraction_t<any_a>::create(&any_a::something__));
			operations.update_string("same_", native_extraction_t<any_a>::create(&any_a::same__));
			operations.update_string("different_", native_extraction_t<any_a>::create(&any_a::different__));
			operations.update_string("less_than_", native_extraction_t<any_a>::create(&any_a::less_than__));
			operations.update_string("greater_than_", native_extraction_t<any_a>::create(&any_a::greater_than__));
			operations.update_string("less_or_equal_", native_extraction_t<any_a>::create(&any_a::less_or_equal__));
			operations.update_string("greater_or_equal_", native_extraction_t<any_a>::create(&any_a::greater_or_equal__));
			operations.update_string("hash_", native_extraction_t<any_a>::create(&any_a::hash__));
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline any_a create(Args&&... args)
	{
		return any_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

}; // class any_a

} // namespace
