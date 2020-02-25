
namespace strange
{

template <typename ___TTT___, typename range_a_chk = range_a<> , typename symbol_a_chk = symbol_a<> , typename cat_a_chk = cat_a<> , typename kind_a_chk = kind_a<> , typename inventory_a_chk = inventory_a<> , typename unordered_herd_a_chk = unordered_herd_a<> , typename shoal_a_chk = shoal_a<> , typename unordered_shoal_a_chk = unordered_shoal_a<> , typename number_data_uint64_a_chk = number_data_uint64_a<> >
inline bool check(any_a<range_a_chk, symbol_a_chk, cat_a_chk, kind_a_chk, inventory_a_chk, unordered_herd_a_chk, shoal_a_chk, unordered_shoal_a_chk, number_data_uint64_a_chk> const& value) noexcept;

template <typename range_a, typename symbol_a, typename cat_a, typename kind_a, typename inventory_a, typename unordered_herd_a, typename shoal_a, typename unordered_shoal_a, typename number_data_uint64_a>
class any_a
{
protected:
	struct ___any_a_handle_base___;

public:
	// constructor tags
	struct ___reference_tag___ {};
	struct ___duplicate_tag___ {};

	// shared pointer typedefs
	using ___WEAK___ = std::weak_ptr<___any_a_handle_base___>;
	using ___SHARED___ = std::shared_ptr<___any_a_handle_base___>;

	// hash function wrapper class
	class hash_f
	{
	public:
		inline std::size_t operator()(any_a const& thing) const
		{
			return thing.hash();
		}
	};

	// operator overloads
	inline any_a<> operator[](range_a const& range)
	{
		return invoke(*this, range);
	}

	inline any_a<> operator()(range_a const& range)
	{
		return operate(*this, range);
	}

	inline operator bool() const
	{
		assert(handle_);
		return read().operator bool();
	}

	// trigger copy on write
	void mutate()
	{
		assert(handle_);
		write();
	}

	// arithmetic operator overloads
	inline any_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline any_a operator++(int)
	{
		assert(handle_);
		any_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline any_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline any_a operator--(int)
	{
		assert(handle_);
		any_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline any_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline any_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline any_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline any_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline any_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline one_t const & extract_thing() const
	{ assert(handle_); return read().extract_thing(); }

	inline one_t & mutate_thing()
	{ assert(handle_); return write().mutate_thing(); }

	inline any_a<> type__(range_a const& range) const
	{ assert(handle_); return read().type__(range); }

	inline symbol_a type_() const
	{ assert(handle_); return read().type_(); }

	inline any_a<> shared__(range_a const& range) const
	{ assert(handle_); return read().shared__(range); }

	inline unordered_shoal_a shared_() const
	{ assert(handle_); return read().shared_(); }

	inline void share(shoal_a & shoal ) const
	{ assert(handle_); read().share(shoal); }

	inline any_a<> cat__(range_a const& range) const
	{ assert(handle_); return read().cat__(range); }

	inline cat_a cat_() const
	{ assert(handle_); return read().cat_(); }

	inline any_a<> cats__(range_a const& range) const
	{ assert(handle_); return read().cats__(range); }

	inline unordered_herd_a cats_() const
	{ assert(handle_); return read().cats_(); }

	inline any_a<> kind__(range_a const& range) const
	{ assert(handle_); return read().kind__(range); }

	inline kind_a kind_() const
	{ assert(handle_); return read().kind_(); }

	inline any_a<> kinds__(range_a const& range) const
	{ assert(handle_); return read().kinds__(range); }

	inline unordered_herd_a kinds_() const
	{ assert(handle_); return read().kinds_(); }

	inline any_a<> operations__(range_a const& range) const
	{ assert(handle_); return read().operations__(range); }

	inline unordered_shoal_a operations_() const
	{ assert(handle_); return read().operations_(); }

	inline any_a<> visit__(range_a const& range) const
	{ assert(handle_); return read().visit__(range); }

	inline any_a<> visit_(inventory_a & inventory) const
	{ assert(handle_); return read().visit_(inventory); }

	inline any_a < > invoke(any_a < > & thing , range_a const & range ) const
	{ assert(handle_); return read().invoke(thing, range); }

	inline any_a < > operate(any_a < > & thing , range_a const & range ) const
	{ assert(handle_); return read().operate(thing, range); }

	inline any_a<> identity__(range_a const& range) const
	{ assert(handle_); return read().identity__(range); }

	inline number_data_uint64_a identity_() const
	{ assert(handle_); return read().identity_(); }

	inline void const * identity() const
	{ assert(handle_); return read().identity(); }

	inline any_a<> identical__(range_a const& range) const
	{ assert(handle_); return read().identical__(range); }

	inline any_a<> identical_(any_a<> const& thing) const
	{ assert(handle_); return read().identical_(thing); }

	inline bool identical(any_a < > const & thing ) const
	{ assert(handle_); return read().identical(thing); }

	inline any_a<> nothing__(range_a const& range) const
	{ assert(handle_); return read().nothing__(range); }

	inline any_a<> nothing_() const
	{ assert(handle_); return read().nothing_(); }

	inline bool nothing() const
	{ assert(handle_); return read().nothing(); }

	inline any_a<> something__(range_a const& range) const
	{ assert(handle_); return read().something__(range); }

	inline any_a<> something_() const
	{ assert(handle_); return read().something_(); }

	inline bool something() const
	{ assert(handle_); return read().something(); }

	inline any_a<> same__(range_a const& range) const
	{ assert(handle_); return read().same__(range); }

	inline any_a<> same_(any_a<> const& thing) const
	{ assert(handle_); return read().same_(thing); }

	inline bool operator==(any_a < > const & thing ) const
	{ assert(handle_); return read().operator==(thing); }

	inline any_a<> different__(range_a const& range) const
	{ assert(handle_); return read().different__(range); }

	inline any_a<> different_(any_a<> const& thing) const
	{ assert(handle_); return read().different_(thing); }

	inline bool operator!=(any_a < > const & thing ) const
	{ assert(handle_); return read().operator!=(thing); }

	inline any_a<> hash__(range_a const& range) const
	{ assert(handle_); return read().hash__(range); }

	inline number_data_uint64_a hash_() const
	{ assert(handle_); return read().hash_(); }

	inline std :: size_t hash() const
	{ assert(handle_); return read().hash(); }

	inline bool is(std :: string const & s ) const
	{ assert(handle_); return read().is(s); }

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
		virtual void operator++() = 0;
		virtual void operator--() = 0;
		virtual void operator+=(any_a<> const& other) = 0;
		virtual void operator-=(any_a<> const& other) = 0;
		virtual void operator*=(any_a<> const& other) = 0;
		virtual void operator/=(any_a<> const& other) = 0;
		virtual void operator%=(any_a<> const& other) = 0;
		virtual one_t const & extract_thing() const = 0;
		virtual one_t & mutate_thing() = 0;
		virtual any_a<> type__(range_a const& range) const = 0;
		virtual symbol_a type_() const = 0;
		virtual any_a<> shared__(range_a const& range) const = 0;
		virtual unordered_shoal_a shared_() const = 0;
		virtual void share(shoal_a & shoal ) const = 0;
		virtual any_a<> cat__(range_a const& range) const = 0;
		virtual cat_a cat_() const = 0;
		virtual any_a<> cats__(range_a const& range) const = 0;
		virtual unordered_herd_a cats_() const = 0;
		virtual any_a<> kind__(range_a const& range) const = 0;
		virtual kind_a kind_() const = 0;
		virtual any_a<> kinds__(range_a const& range) const = 0;
		virtual unordered_herd_a kinds_() const = 0;
		virtual any_a<> operations__(range_a const& range) const = 0;
		virtual unordered_shoal_a operations_() const = 0;
		virtual any_a<> visit__(range_a const& range) const = 0;
		virtual any_a<> visit_(inventory_a & inventory) const = 0;
		virtual any_a < > invoke(any_a < > & thing , range_a const & range ) const = 0;
		virtual any_a < > operate(any_a < > & thing , range_a const & range ) const = 0;
		virtual any_a<> identity__(range_a const& range) const = 0;
		virtual number_data_uint64_a identity_() const = 0;
		virtual void const * identity() const = 0;
		virtual any_a<> identical__(range_a const& range) const = 0;
		virtual any_a<> identical_(any_a<> const& thing) const = 0;
		virtual bool identical(any_a < > const & thing ) const = 0;
		virtual any_a<> nothing__(range_a const& range) const = 0;
		virtual any_a<> nothing_() const = 0;
		virtual bool nothing() const = 0;
		virtual any_a<> something__(range_a const& range) const = 0;
		virtual any_a<> something_() const = 0;
		virtual bool something() const = 0;
		virtual any_a<> same__(range_a const& range) const = 0;
		virtual any_a<> same_(any_a<> const& thing) const = 0;
		virtual bool operator==(any_a < > const & thing ) const = 0;
		virtual any_a<> different__(range_a const& range) const = 0;
		virtual any_a<> different_(any_a<> const& thing) const = 0;
		virtual bool operator!=(any_a < > const & thing ) const = 0;
		virtual any_a<> hash__(range_a const& range) const = 0;
		virtual number_data_uint64_a hash_() const = 0;
		virtual std :: size_t hash() const = 0;
		virtual bool is(std :: string const & s ) const = 0;
	};

	template <typename ___TTT___, typename ___BHB___ = ___any_a_handle_base___>
	struct ___any_a_handle___ : ___BHB___
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___any_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: value_{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___any_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: value_{ std::move(value) }
		{}

		virtual inline void ___weak___(___WEAK___ const& weak) const final
		{
			value_.___weak___(weak);
		}

		virtual inline operator bool() const final
		{
			return value_.operator bool();
		}

		virtual inline void operator++() final
		{
			value_.operator++();
		}

		virtual inline void operator--() final
		{
			value_.operator--();
		}

		virtual inline void operator+=(any_a<> const& other) final
		{
			value_.operator+=(other);
		}

		virtual inline void operator-=(any_a<> const& other) final
		{
			value_.operator-=(other);
		}

		virtual inline void operator*=(any_a<> const& other) final
		{
			value_.operator*=(other);
		}

		virtual inline void operator/=(any_a<> const& other) final
		{
			value_.operator/=(other);
		}

		virtual inline void operator%=(any_a<> const& other) final
		{
			value_.operator%=(other);
		}

		virtual inline one_t const & extract_thing() const final
		{ return value_.extract_thing(); }

		virtual inline one_t & mutate_thing() final
		{ return value_.mutate_thing(); }

		virtual inline any_a<> type__(range_a const& range) const final
		{ return value_.type__(range); }

		virtual inline symbol_a type_() const final
		{ return value_.type_(); }

		virtual inline any_a<> shared__(range_a const& range) const final
		{ return value_.shared__(range); }

		virtual inline unordered_shoal_a shared_() const final
		{ return value_.shared_(); }

		virtual inline void share(shoal_a & shoal ) const final
		{ value_.share(shoal); }

		virtual inline any_a<> cat__(range_a const& range) const final
		{ return value_.cat__(range); }

		virtual inline cat_a cat_() const final
		{ return value_.cat_(); }

		virtual inline any_a<> cats__(range_a const& range) const final
		{ return value_.cats__(range); }

		virtual inline unordered_herd_a cats_() const final
		{ return value_.cats_(); }

		virtual inline any_a<> kind__(range_a const& range) const final
		{ return value_.kind__(range); }

		virtual inline kind_a kind_() const final
		{ return value_.kind_(); }

		virtual inline any_a<> kinds__(range_a const& range) const final
		{ return value_.kinds__(range); }

		virtual inline unordered_herd_a kinds_() const final
		{ return value_.kinds_(); }

		virtual inline any_a<> operations__(range_a const& range) const final
		{ return value_.operations__(range); }

		virtual inline unordered_shoal_a operations_() const final
		{ return value_.operations_(); }

		virtual inline any_a<> visit__(range_a const& range) const final
		{ return value_.visit__(range); }

		virtual inline any_a<> visit_(inventory_a & inventory) const final
		{ return value_.visit_(inventory); }

		virtual inline any_a < > invoke(any_a < > & thing , range_a const & range ) const final
		{ return value_.invoke(thing, range); }

		virtual inline any_a < > operate(any_a < > & thing , range_a const & range ) const final
		{ return value_.operate(thing, range); }

		virtual inline any_a<> identity__(range_a const& range) const final
		{ return value_.identity__(range); }

		virtual inline number_data_uint64_a identity_() const final
		{ return value_.identity_(); }

		virtual inline void const * identity() const final
		{ return value_.identity(); }

		virtual inline any_a<> identical__(range_a const& range) const final
		{ return value_.identical__(range); }

		virtual inline any_a<> identical_(any_a<> const& thing) const final
		{ return value_.identical_(thing); }

		virtual inline bool identical(any_a < > const & thing ) const final
		{ return value_.identical(thing); }

		virtual inline any_a<> nothing__(range_a const& range) const final
		{ return value_.nothing__(range); }

		virtual inline any_a<> nothing_() const final
		{ return value_.nothing_(); }

		virtual inline bool nothing() const final
		{ return value_.nothing(); }

		virtual inline any_a<> something__(range_a const& range) const final
		{ return value_.something__(range); }

		virtual inline any_a<> something_() const final
		{ return value_.something_(); }

		virtual inline bool something() const final
		{ return value_.something(); }

		virtual inline any_a<> same__(range_a const& range) const final
		{ return value_.same__(range); }

		virtual inline any_a<> same_(any_a<> const& thing) const final
		{ return value_.same_(thing); }

		virtual inline bool operator==(any_a < > const & thing ) const final
		{ return value_.operator==(thing); }

		virtual inline any_a<> different__(range_a const& range) const final
		{ return value_.different__(range); }

		virtual inline any_a<> different_(any_a<> const& thing) const final
		{ return value_.different_(thing); }

		virtual inline bool operator!=(any_a < > const & thing ) const final
		{ return value_.operator!=(thing); }

		virtual inline any_a<> hash__(range_a const& range) const final
		{ return value_.hash__(range); }

		virtual inline number_data_uint64_a hash_() const final
		{ return value_.hash_(); }

		virtual inline std :: size_t hash() const final
		{ return value_.hash(); }

		virtual inline bool is(std :: string const & s ) const final
		{ return value_.is(s); }

		___TTT___ value_;
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

	___SHARED___& handle_;

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

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___any_a_handle_final___>(___any_a_handle___<___TTT___>::value_);
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
	inline ___any_a_handle_base___ const& read() const noexcept
	{
		return *handle_;
	}

	inline ___any_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *handle_;
	}

	inline any_a<> operation(std::string const& name) const
	{
		return read().operations_().at_string(name);
	}

private:
	template <typename ___TTT___, typename range_a_chk, typename symbol_a_chk, typename cat_a_chk, typename kind_a_chk, typename inventory_a_chk, typename unordered_herd_a_chk, typename shoal_a_chk, typename unordered_shoal_a_chk, typename number_data_uint64_a_chk>
	friend inline bool check(any_a<range_a_chk, symbol_a_chk, cat_a_chk, kind_a_chk, inventory_a_chk, unordered_herd_a_chk, shoal_a_chk, unordered_shoal_a_chk, number_data_uint64_a_chk> const& value) noexcept;

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	friend inline ___TTT___ cast(any_a<> const& value);
#else
	template <typename ___TTT___>
	friend inline ___TTT___ cast(any_a<> const& value) noexcept;
#endif
#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	friend inline ___TTT___ cast_ref(any_a<>& value);
#else
	template <typename ___TTT___>
	friend inline ___TTT___ cast_ref(any_a<>& value) noexcept;
#endif
#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	friend inline ___TTT___ cast_dup(any_a<>& value);
#else
	template <typename ___TTT___>
	friend inline ___TTT___ cast_dup(any_a<>& value) noexcept;
#endif

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(handle);
	}

	inline bool is_ref() const
	{
		return &handle_ != &___shared___;
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
		, handle_{ ___shared___ }
	{}

	inline any_a(any_a const& other) noexcept
		: ___shared___{ other.handle_ }
		, handle_{ ___shared___ }
	{}

	inline any_a(any_a& other, ___reference_tag___) noexcept
		: ___shared___{ ___SHARED___{} }
		, handle_{ other.handle_ }
	{}

	inline any_a(any_a& other, ___duplicate_tag___) noexcept
		: ___shared___{ &other.handle_ == &other.___shared___ ? other.handle_ : ___SHARED___{} }
		, handle_{ *(&other.handle_ == &other.___shared___ ? &___shared___ : &other.handle_) }
	{}

	inline any_a(any_a&& other) noexcept
	: ___shared___{ other.handle_ }
	, handle_{ ___shared___ }
	{}

	inline any_a& operator=(any_a const& other) noexcept
	{
		handle_ = other.handle_;
		return *this;
	}

	inline any_a& operator=(any_a&& other) noexcept
	{
		handle_ = other.handle_;
		return *this;
	}

	virtual ~any_a() = default;

	template <typename ___TTT___>
	explicit inline any_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: ___shared___{ handle }
		, handle_{ ___shared___ }
	{}

	template <typename ___TTT___>
	explicit inline any_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: ___shared___{ ___SHARED___{} }
		, handle_{ reinterpret_cast<___SHARED___&>(handle) }
	{}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<any_a, std::decay_t<___TTT___>>::value>>
	explicit inline any_a(___TTT___ value) noexcept
		: ___shared___{ std::make_shared<___any_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
		, handle_{ ___shared___ }
	{
		handle_->___weak___(handle_);
	}

	template <typename ___TTT___>
	inline any_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		handle_ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<any_a, std::decay_t<___TTT___>>::value>>
	inline any_a& operator=(___TTT___ value) noexcept
	{
		any_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___any_a_share___;
}; // class any_a

template <typename ___TTT___, typename range_a_chk, typename symbol_a_chk, typename cat_a_chk, typename kind_a_chk, typename inventory_a_chk, typename unordered_herd_a_chk, typename shoal_a_chk, typename unordered_shoal_a_chk, typename number_data_uint64_a_chk>
inline bool check(any_a<range_a_chk, symbol_a_chk, cat_a_chk, kind_a_chk, inventory_a_chk, unordered_herd_a_chk, shoal_a_chk, unordered_shoal_a_chk, number_data_uint64_a_chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename range_a, typename symbol_a, typename cat_a, typename kind_a, typename inventory_a, typename unordered_herd_a, typename shoal_a, typename unordered_shoal_a, typename number_data_uint64_a>
bool const any_a<range_a, symbol_a, cat_a, kind_a, inventory_a, unordered_herd_a, shoal_a, unordered_shoal_a, number_data_uint64_a>::___share___ = []()
{
	auto& shoal = shared();
	reflection<any_a<range_a, symbol_a, cat_a, kind_a, inventory_a, unordered_herd_a, shoal_a, unordered_shoal_a, number_data_uint64_a>>::share(shoal);
	return shoal;
}();

} // namespace
