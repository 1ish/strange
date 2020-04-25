
namespace strange
{

template <typename _1>
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
	using ___WEAK___ = std_weak_ptr<___any_a_handle_base___>;
	using ___SHARED___ = std_shared_ptr<___any_a_handle_base___>;

	// operator overloads
	inline any_a<> operator[](list_a<> const& arguments)
	{
		return invoke(*this, arguments);
	}

	inline any_a<> operator()(list_a<> const& arguments)
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

	inline one_t const & extract_thing() const;

	inline one_t & mutate_thing();

	inline any_a<> type__(list_a<> const& ___arguments___) const;

	inline symbol_a<> type_() const;

	inline any_a<> cat__(list_a<> const& ___arguments___) const;

	inline cat_a<> cat_() const;

	inline any_a<> cats__(list_a<> const& ___arguments___) const;

	inline unordered_herd_a<> cats_() const;

	inline any_a<> kind__(list_a<> const& ___arguments___) const;

	inline kind_a<> kind_() const;

	inline any_a<> kinds__(list_a<> const& ___arguments___) const;

	inline unordered_herd_a<> kinds_() const;

	inline any_a<> operations__(list_a<> const& ___arguments___) const;

	inline unordered_shoal_a<> operations_() const;

	inline any_a<> visit__(list_a<> const& ___arguments___) const;

	inline any_a<> visit_(inventory_a<> & arguments) const;

	inline any_a < > invoke(any_a < > & thing , list_a < > const & arguments ) const;

	inline any_a < > operate(any_a < > & thing , list_a < > const & arguments ) const;

	inline any_a<> identity__(list_a<> const& ___arguments___) const;

	inline number_data_uint64_a<> identity_() const;

	inline void const * identity() const;

	inline any_a<> identical__(list_a<> const& ___arguments___) const;

	inline any_a<> identical_(any_a<> const& thing) const;

	inline bool identical(any_a < > const & thing ) const;

	inline any_a<> nothing__(list_a<> const& ___arguments___) const;

	inline any_a<> nothing_() const;

	inline bool nothing() const;

	inline any_a<> something__(list_a<> const& ___arguments___) const;

	inline any_a<> something_() const;

	inline bool something() const;

	inline any_a<> same__(list_a<> const& ___arguments___) const;

	inline any_a<> same_(any_a<> const& thing) const;

	inline bool operator==(any_a<> const& thing) const;

	inline any_a<> different__(list_a<> const& ___arguments___) const;

	inline any_a<> different_(any_a<> const& thing) const;

	inline bool operator!=(any_a<> const& thing) const;

	inline any_a<> less_than__(list_a<> const& ___arguments___) const;

	inline any_a<> less_than_(any_a<> const& thing) const;

	inline bool operator<(any_a<> const& thing) const;

	inline any_a<> greater_than__(list_a<> const& ___arguments___) const;

	inline any_a<> greater_than_(any_a<> const& thing) const;

	inline bool operator>(any_a<> const& thing) const;

	inline any_a<> less_or_equal__(list_a<> const& ___arguments___) const;

	inline any_a<> less_or_equal_(any_a<> const& thing) const;

	inline bool operator<=(any_a<> const& thing) const;

	inline any_a<> greater_or_equal__(list_a<> const& ___arguments___) const;

	inline any_a<> greater_or_equal_(any_a<> const& thing) const;

	inline bool operator>=(any_a<> const& thing) const;

	inline any_a<> hash__(list_a<> const& ___arguments___) const;

	inline number_data_uint64_a<> hash_() const;

	inline std_size_t hash() const;

	inline bool is(std_string const & s ) const;

	inline any_a<> pack__(list_a<> const& ___arguments___) const;

	inline any_a<> pack_(container_a<> & container) const;

	inline any_a<> pack_unique__(list_a<> const& ___arguments___) const;

	inline any_a<> pack_unique_(container_a<> & container, herd_a<number_data_uint64_a<>> & unique_herd) const;

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
		virtual symbol_a<> type_() const = 0;
		virtual cat_a<> cat_() const = 0;
		virtual unordered_herd_a<> cats_() const = 0;
		virtual kind_a<> kind_() const = 0;
		virtual unordered_herd_a<> kinds_() const = 0;
		virtual unordered_shoal_a<> operations_() const = 0;
		virtual any_a<> visit_(inventory_a<> & arguments) const = 0;
		virtual any_a < > invoke(any_a < > & thing , list_a < > const & arguments ) const = 0;
		virtual any_a < > operate(any_a < > & thing , list_a < > const & arguments ) const = 0;
		virtual number_data_uint64_a<> identity_() const = 0;
		virtual void const * identity() const = 0;
		virtual any_a<> identical_(any_a<> const& thing) const = 0;
		virtual bool identical(any_a < > const & thing ) const = 0;
		virtual any_a<> nothing_() const = 0;
		virtual bool nothing() const = 0;
		virtual any_a<> something_() const = 0;
		virtual bool something() const = 0;
		virtual bool same_(any_a<> const& thing) const = 0;
		virtual bool less_than_(any_a<> const& thing) const = 0;
		virtual bool greater_than_(any_a<> const& thing) const = 0;
		virtual bool less_or_equal_(any_a<> const& thing) const = 0;
		virtual bool greater_or_equal_(any_a<> const& thing) const = 0;
		virtual number_data_uint64_a<> hash_() const = 0;
		virtual std_size_t hash() const = 0;
		virtual bool is(std_string const & s ) const = 0;
		virtual any_a<> pack_(container_a<> & container) const = 0;
		virtual any_a<> pack_unique_(container_a<> & container, herd_a<number_data_uint64_a<>> & unique_herd) const = 0;
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

		virtual inline one_t const & extract_thing() const final;

		virtual inline one_t & mutate_thing() final;

		virtual inline symbol_a<> type_() const final;

		virtual inline cat_a<> cat_() const final;

		virtual inline unordered_herd_a<> cats_() const final;

		virtual inline kind_a<> kind_() const final;

		virtual inline unordered_herd_a<> kinds_() const final;

		virtual inline unordered_shoal_a<> operations_() const final;

		virtual inline any_a<> visit_(inventory_a<> & arguments) const final;

		virtual inline any_a < > invoke(any_a < > & thing , list_a < > const & arguments ) const final;

		virtual inline any_a < > operate(any_a < > & thing , list_a < > const & arguments ) const final;

		virtual inline number_data_uint64_a<> identity_() const final;

		virtual inline void const * identity() const final;

		virtual inline any_a<> identical_(any_a<> const& thing) const final;

		virtual inline bool identical(any_a < > const & thing ) const final;

		virtual inline any_a<> nothing_() const final;

		virtual inline bool nothing() const final;

		virtual inline any_a<> something_() const final;

		virtual inline bool something() const final;

		virtual inline bool same_(any_a<> const& thing) const final;

		virtual inline bool less_than_(any_a<> const& thing) const final;

		virtual inline bool greater_than_(any_a<> const& thing) const final;

		virtual inline bool less_or_equal_(any_a<> const& thing) const final;

		virtual inline bool greater_or_equal_(any_a<> const& thing) const final;

		virtual inline number_data_uint64_a<> hash_() const final;

		virtual inline std_size_t hash() const final;

		virtual inline bool is(std_string const & s ) const final;

		virtual inline any_a<> pack_(container_a<> & container) const final;

		virtual inline any_a<> pack_unique_(container_a<> & container, herd_a<number_data_uint64_a<>> & unique_herd) const final;

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
			return std_make_shared<___any_a_handle_final___>(___any_a_handle___<___TTT___>::___value___);
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

	inline any_a<> operation(std_string const& name) const;

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
	explicit inline any_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: ___shared___{ handle }
		, ___handle___{ ___shared___ }
	{}

	template <typename ___TTT___>
	explicit inline any_a(std_shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: ___shared___{ ___SHARED___{} }
		, ___handle___{ reinterpret_cast<___SHARED___&>(handle) }
	{}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<any_a, std::decay_t<___TTT___>>::value>>
	explicit inline any_a(___TTT___ value) noexcept
		: ___shared___{ std_make_shared<___any_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
		, ___handle___{ ___shared___ }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline any_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: ___shared___{ std_make_shared<___any_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
		, ___handle___{ ___shared___ }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline any_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
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

	static inline cat_a<> ___cat___();

	static inline unordered_herd_a<> ___cats___();

	static inline kind_a<> ___kind___();

	static inline unordered_herd_a<> ___kinds___();

	static inline unordered_shoal_a<> ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline any_a create(Args&&... args)
	{
		return any_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class any_a

} // namespace
