
namespace strange
{

template <typename ___TTT___, typename number_data_int64_a_chk = number_data_int64_a<> >
inline bool check(collection_a<number_data_int64_a_chk> const& value) noexcept;

template <typename number_data_int64_a>
class collection_a : public range_a<>
{
public:
	// arithmetic operator overloads
	inline collection_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

	inline collection_a operator++(int)
	{
		assert(handle_);
		collection_a result = *this;
		write().operator++();
		return result;
	}

	inline collection_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

	inline collection_a operator--(int)
	{
		assert(handle_);
		collection_a result = *this;
		write().operator--();
		return result;
	}

	inline collection_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline collection_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline collection_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline collection_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline collection_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> has__(range_a<> const& range) const
	{ assert(handle_); return read().has__(range); }

	inline any_a<> has_(any_a<> const& key) const
	{ assert(handle_); return read().has_(key); }

	inline bool has(any_a < > const & key ) const
	{ assert(handle_); return read().has(key); }

	inline any_a<> at__(range_a<> const& range) const
	{ assert(handle_); return read().at__(range); }

	inline any_a<> at_(any_a<> const& key) const
	{ assert(handle_); return read().at_(key); }

	inline any_a<> update__(range_a<> const& range)
	{ assert(handle_); return write().update__(range); }

	inline any_a<> update_(any_a<> const& key, any_a<> const& value = strange::no() )
	{ assert(handle_); return write().update_(key, value); }

	inline void update(any_a < > const & key , any_a < > const & value )
	{ assert(handle_); write().update(key, value); }

	inline any_a<> insert__(range_a<> const& range)
	{ assert(handle_); return write().insert__(range); }

	inline any_a<> insert_(any_a<> const& key, any_a<> const& value = strange::no() )
	{ assert(handle_); return write().insert_(key, value); }

	inline void insert(any_a < > const & key , any_a < > const & value )
	{ assert(handle_); write().insert(key, value); }

	inline any_a<> erase__(range_a<> const& range)
	{ assert(handle_); return write().erase__(range); }

	inline any_a<> erase_(any_a<> const& key)
	{ assert(handle_); return write().erase_(key); }

	inline bool erase(any_a < > const & key )
	{ assert(handle_); return write().erase(key); }

	inline any_a<> clear__(range_a<> const& range)
	{ assert(handle_); return write().clear__(range); }

	inline collection_a<> clear_()
	{ assert(handle_); return write().clear_(); }

	inline void clear()
	{ assert(handle_); write().clear(); }

	inline any_a<> size__(range_a<> const& range) const
	{ assert(handle_); return read().size__(range); }

	inline number_data_int64_a size_() const
	{ assert(handle_); return read().size_(); }

	inline int64_t size() const
	{ assert(handle_); return read().size(); }

	inline any_a<> empty__(range_a<> const& range) const
	{ assert(handle_); return read().empty__(range); }

	inline any_a<> empty_() const
	{ assert(handle_); return read().empty_(); }

	inline bool empty() const
	{ assert(handle_); return read().empty(); }

	inline any_a<> push_front__(range_a<> const& range)
	{ assert(handle_); return write().push_front__(range); }

	inline collection_a<> push_front_(any_a<> const& thing)
	{ assert(handle_); return write().push_front_(thing); }

	inline void push_front(any_a < > const & thing )
	{ assert(handle_); write().push_front(thing); }

	inline any_a<> pop_front__(range_a<> const& range)
	{ assert(handle_); return write().pop_front__(range); }

	inline any_a<> pop_front_()
	{ assert(handle_); return write().pop_front_(); }

	inline any_a<> push_back__(range_a<> const& range)
	{ assert(handle_); return write().push_back__(range); }

	inline collection_a<> push_back_(any_a<> const& thing)
	{ assert(handle_); return write().push_back_(thing); }

	inline void push_back(any_a < > const & thing )
	{ assert(handle_); write().push_back(thing); }

	inline any_a<> pop_back__(range_a<> const& range)
	{ assert(handle_); return write().pop_back__(range); }

	inline any_a<> pop_back_()
	{ assert(handle_); return write().pop_back_(); }

	inline any_a<> self_assign__(range_a<> const& range)
	{ assert(handle_); return write().self_assign__(range); }

	inline collection_a<> self_assign_(range_a<> const& range)
	{ assert(handle_); return write().self_assign_(range); }

	inline any_a<> self_add__(range_a<> const& range)
	{ assert(handle_); return write().self_add__(range); }

	inline collection_a<> self_add_(range_a<> const& range)
	{ assert(handle_); return write().self_add_(range); }

	inline any_a<> add__(range_a<> const& range) const
	{ assert(handle_); return read().add__(range); }

	inline collection_a<> add_(range_a<> const& range) const
	{ assert(handle_); return read().add_(range); }

	inline collection_a operator+(range_a < > const & range ) const
	{ assert(handle_); return read().operator+(range); }

	inline any_a<> self_subtract__(range_a<> const& range)
	{ assert(handle_); return write().self_subtract__(range); }

	inline collection_a<> self_subtract_(range_a<> const& range)
	{ assert(handle_); return write().self_subtract_(range); }

	inline any_a<> subtract__(range_a<> const& range) const
	{ assert(handle_); return read().subtract__(range); }

	inline collection_a<> subtract_(range_a<> const& range) const
	{ assert(handle_); return read().subtract_(range); }

	inline collection_a operator-(range_a < > const & range ) const
	{ assert(handle_); return read().operator-(range); }

	inline any_a<> read_lock__(range_a<> const& range) const
	{ assert(handle_); return read().read_lock__(range); }

	inline any_a<> read_lock_() const
	{ assert(handle_); return read().read_lock_(); }

	inline any_a<> write_lock__(range_a<> const& range) const
	{ assert(handle_); return read().write_lock__(range); }

	inline any_a<> write_lock_() const
	{ assert(handle_); return read().write_lock_(); }

protected:
	struct ___collection_a_handle_base___ : ___range_a_handle_base___
	{
		virtual inline any_a<> has__(range_a<> const& range) const = 0;
		virtual inline any_a<> has_(any_a<> const& key) const = 0;
		virtual inline bool has(any_a < > const & key ) const = 0;
		virtual inline any_a<> at__(range_a<> const& range) const = 0;
		virtual inline any_a<> at_(any_a<> const& key) const = 0;
		virtual inline any_a<> update__(range_a<> const& range) = 0;
		virtual inline any_a<> update_(any_a<> const& key, any_a<> const& value = strange::no() ) = 0;
		virtual inline void update(any_a < > const & key , any_a < > const & value ) = 0;
		virtual inline any_a<> insert__(range_a<> const& range) = 0;
		virtual inline any_a<> insert_(any_a<> const& key, any_a<> const& value = strange::no() ) = 0;
		virtual inline void insert(any_a < > const & key , any_a < > const & value ) = 0;
		virtual inline any_a<> erase__(range_a<> const& range) = 0;
		virtual inline any_a<> erase_(any_a<> const& key) = 0;
		virtual inline bool erase(any_a < > const & key ) = 0;
		virtual inline any_a<> clear__(range_a<> const& range) = 0;
		virtual inline collection_a<> clear_() = 0;
		virtual inline void clear() = 0;
		virtual inline any_a<> size__(range_a<> const& range) const = 0;
		virtual inline number_data_int64_a size_() const = 0;
		virtual inline int64_t size() const = 0;
		virtual inline any_a<> empty__(range_a<> const& range) const = 0;
		virtual inline any_a<> empty_() const = 0;
		virtual inline bool empty() const = 0;
		virtual inline any_a<> push_front__(range_a<> const& range) = 0;
		virtual inline collection_a<> push_front_(any_a<> const& thing) = 0;
		virtual inline void push_front(any_a < > const & thing ) = 0;
		virtual inline any_a<> pop_front__(range_a<> const& range) = 0;
		virtual inline any_a<> pop_front_() = 0;
		virtual inline any_a<> push_back__(range_a<> const& range) = 0;
		virtual inline collection_a<> push_back_(any_a<> const& thing) = 0;
		virtual inline void push_back(any_a < > const & thing ) = 0;
		virtual inline any_a<> pop_back__(range_a<> const& range) = 0;
		virtual inline any_a<> pop_back_() = 0;
		virtual inline any_a<> self_assign__(range_a<> const& range) = 0;
		virtual inline collection_a<> self_assign_(range_a<> const& range) = 0;
		virtual inline any_a<> self_add__(range_a<> const& range) = 0;
		virtual inline collection_a<> self_add_(range_a<> const& range) = 0;
		virtual inline any_a<> add__(range_a<> const& range) const = 0;
		virtual inline collection_a<> add_(range_a<> const& range) const = 0;
		virtual inline collection_a operator+(range_a < > const & range ) const = 0;
		virtual inline any_a<> self_subtract__(range_a<> const& range) = 0;
		virtual inline collection_a<> self_subtract_(range_a<> const& range) = 0;
		virtual inline any_a<> subtract__(range_a<> const& range) const = 0;
		virtual inline collection_a<> subtract_(range_a<> const& range) const = 0;
		virtual inline collection_a operator-(range_a < > const & range ) const = 0;
		virtual inline any_a<> read_lock__(range_a<> const& range) const = 0;
		virtual inline any_a<> read_lock_() const = 0;
		virtual inline any_a<> write_lock__(range_a<> const& range) const = 0;
		virtual inline any_a<> write_lock_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___collection_a_handle_base___>
	struct ___collection_a_handle___ : ___range_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___collection_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___range_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___collection_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___range_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> has__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.has__(range); }

		virtual inline any_a<> has_(any_a<> const& key) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.has_(key); }

		virtual inline bool has(any_a < > const & key ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.has(key); }

		virtual inline any_a<> at__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.at__(range); }

		virtual inline any_a<> at_(any_a<> const& key) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.at_(key); }

		virtual inline any_a<> update__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.update__(range); }

		virtual inline any_a<> update_(any_a<> const& key, any_a<> const& value = strange::no() ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.update_(key, value); }

		virtual inline void update(any_a < > const & key , any_a < > const & value ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.update(key, value); }

		virtual inline any_a<> insert__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.insert__(range); }

		virtual inline any_a<> insert_(any_a<> const& key, any_a<> const& value = strange::no() ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.insert_(key, value); }

		virtual inline void insert(any_a < > const & key , any_a < > const & value ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.insert(key, value); }

		virtual inline any_a<> erase__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.erase__(range); }

		virtual inline any_a<> erase_(any_a<> const& key) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.erase_(key); }

		virtual inline bool erase(any_a < > const & key ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.erase(key); }

		virtual inline any_a<> clear__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.clear__(range); }

		virtual inline collection_a<> clear_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.clear_(); }

		virtual inline void clear() final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.clear(); }

		virtual inline any_a<> size__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.size__(range); }

		virtual inline number_data_int64_a size_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.size_(); }

		virtual inline int64_t size() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.size(); }

		virtual inline any_a<> empty__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.empty__(range); }

		virtual inline any_a<> empty_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.empty_(); }

		virtual inline bool empty() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.empty(); }

		virtual inline any_a<> push_front__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.push_front__(range); }

		virtual inline collection_a<> push_front_(any_a<> const& thing) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.push_front_(thing); }

		virtual inline void push_front(any_a < > const & thing ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.push_front(thing); }

		virtual inline any_a<> pop_front__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.pop_front__(range); }

		virtual inline any_a<> pop_front_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.pop_front_(); }

		virtual inline any_a<> push_back__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.push_back__(range); }

		virtual inline collection_a<> push_back_(any_a<> const& thing) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.push_back_(thing); }

		virtual inline void push_back(any_a < > const & thing ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.push_back(thing); }

		virtual inline any_a<> pop_back__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.pop_back__(range); }

		virtual inline any_a<> pop_back_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.pop_back_(); }

		virtual inline any_a<> self_assign__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_assign__(range); }

		virtual inline collection_a<> self_assign_(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_assign_(range); }

		virtual inline any_a<> self_add__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_add__(range); }

		virtual inline collection_a<> self_add_(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_add_(range); }

		virtual inline any_a<> add__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.add__(range); }

		virtual inline collection_a<> add_(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.add_(range); }

		virtual inline collection_a operator+(range_a < > const & range ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator+(range); }

		virtual inline any_a<> self_subtract__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_subtract__(range); }

		virtual inline collection_a<> self_subtract_(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_subtract_(range); }

		virtual inline any_a<> subtract__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.subtract__(range); }

		virtual inline collection_a<> subtract_(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.subtract_(range); }

		virtual inline collection_a operator-(range_a < > const & range ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator-(range); }

		virtual inline any_a<> read_lock__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.read_lock__(range); }

		virtual inline any_a<> read_lock_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.read_lock_(); }

		virtual inline any_a<> write_lock__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.write_lock__(range); }

		virtual inline any_a<> write_lock_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.write_lock_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___collection_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___collection_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___collection_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___collection_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___collection_a_handle_final___ final : ___collection_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___collection_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___collection_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___collection_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___collection_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___collection_a_handle_final___>(___collection_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___collection_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___collection_a_handle_final___<___TTT___&>
	{
		inline ___collection_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___collection_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___collection_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___collection_a_handle_base___ const>(handle_);
	}

	inline ___collection_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___collection_a_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename number_data_int64_a_chk>
	friend inline bool check(collection_a<number_data_int64_a_chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
	}

	static inline collection_a val(collection_a const& other) noexcept
	{
		return collection_a{ other };
	}

	static inline collection_a ref(collection_a& other) noexcept
	{
		return collection_a(other, ___reference_tag___{});
	}

	static inline collection_a dup(collection_a& other) noexcept
	{
		return collection_a(other, ___duplicate_tag___{});
	}

	inline collection_a() = default;

	inline collection_a(collection_a& other, ___reference_tag___) noexcept
		: range_a(other, ___reference_tag___{})
	{}

	inline collection_a(collection_a& other, ___duplicate_tag___) noexcept
		: range_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline collection_a(std::shared_ptr<___TTT___> const& handle)
		: range_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___collection_a_handle_base___>(handle))
		{
			throw dis("collection_a constructor failed to cast from base to collection_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline collection_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: range_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline collection_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: range_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___collection_a_handle_base___>(handle))
		{
			throw dis("collection_a constructor failed to cast from base to collection_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline collection_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: range_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<collection_a, std::decay_t<___TTT___>>::value>>
	explicit inline collection_a(___TTT___ value) noexcept
		: range_a{ std::make_shared<___collection_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline collection_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___collection_a_handle_base___>(handle))
		{
			throw dis("collection_a assignment failed to cast from base to collection_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline collection_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<collection_a, std::decay_t<___TTT___>>::value>>
	inline collection_a& operator=(___TTT___ value) noexcept
	{
		collection_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___collection_a_share___;
}; // class collection_a

template <typename ___TTT___, typename number_data_int64_a_chk>
inline bool check(collection_a<number_data_int64_a_chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename number_data_int64_a>
bool const collection_a<number_data_int64_a>::___share___ = []()
{
	auto& shoal = shared();
	reflection<collection_a<number_data_int64_a>>::share(shoal);
	return shoal;
}();

} // namespace
