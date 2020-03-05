
namespace strange
{

template <typename _1_ = void>
class collection_d;

template <typename _1_ = void>
inline collection_d<_1_> ___collection_dynamic___(any_a<> const& thing); 

template <typename _1_>
class collection_a : public range_a<>
{
public:
	// arithmetic operator overloads
	inline collection_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline collection_a operator++(int)
	{
		assert(___handle___);
		collection_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline collection_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline collection_a operator--(int)
	{
		assert(___handle___);
		collection_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline collection_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline collection_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline collection_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline collection_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline collection_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> has__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().has__(range); }

	inline any_a<> has_(any_a<> const& key) const
	{ assert(___handle___); return ___read___().has_(key); }

	inline bool has(any_a < > const & key ) const
	{ assert(___handle___); return ___read___().has(key); }

	inline any_a<> at__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().at__(range); }

	inline any_a<> at_(any_a<> const& key) const
	{ assert(___handle___); return ___read___().at_(key); }

	inline any_a<> update__(range_a<> const& range)
	{ assert(___handle___); return ___write___().update__(range); }

	inline any_a<> update_(any_a<> const& key, any_a<> const& value = strange::no() )
	{ assert(___handle___); return ___write___().update_(key, value); }

	inline void update(any_a < > const & key , any_a < > const & value )
	{ assert(___handle___); ___write___().update(key, value); }

	inline any_a<> insert__(range_a<> const& range)
	{ assert(___handle___); return ___write___().insert__(range); }

	inline any_a<> insert_(any_a<> const& key, any_a<> const& value = strange::no() )
	{ assert(___handle___); return ___write___().insert_(key, value); }

	inline void insert(any_a < > const & key , any_a < > const & value )
	{ assert(___handle___); ___write___().insert(key, value); }

	inline any_a<> erase__(range_a<> const& range)
	{ assert(___handle___); return ___write___().erase__(range); }

	inline any_a<> erase_(any_a<> const& key)
	{ assert(___handle___); return ___write___().erase_(key); }

	inline bool erase(any_a < > const & key )
	{ assert(___handle___); return ___write___().erase(key); }

	inline any_a<> clear__(range_a<> const& range)
	{ assert(___handle___); return ___write___().clear__(range); }

	inline collection_a<> clear_()
	{ assert(___handle___); return ___write___().clear_(); }

	inline void clear()
	{ assert(___handle___); ___write___().clear(); }

	inline any_a<> size__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().size__(range); }

	inline number_data_int64_a<> size_() const
	{ assert(___handle___); return ___read___().size_(); }

	inline int64_t size() const
	{ assert(___handle___); return ___read___().size(); }

	inline any_a<> empty__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().empty__(range); }

	inline any_a<> empty_() const
	{ assert(___handle___); return ___read___().empty_(); }

	inline bool empty() const
	{ assert(___handle___); return ___read___().empty(); }

	inline any_a<> push_front__(range_a<> const& range)
	{ assert(___handle___); return ___write___().push_front__(range); }

	inline collection_a<> push_front_(any_a<> const& thing)
	{ assert(___handle___); return ___write___().push_front_(thing); }

	inline void push_front(any_a < > const & thing )
	{ assert(___handle___); ___write___().push_front(thing); }

	inline any_a<> pop_front__(range_a<> const& range)
	{ assert(___handle___); return ___write___().pop_front__(range); }

	inline any_a<> pop_front_()
	{ assert(___handle___); return ___write___().pop_front_(); }

	inline any_a<> push_back__(range_a<> const& range)
	{ assert(___handle___); return ___write___().push_back__(range); }

	inline collection_a<> push_back_(any_a<> const& thing)
	{ assert(___handle___); return ___write___().push_back_(thing); }

	inline void push_back(any_a < > const & thing )
	{ assert(___handle___); ___write___().push_back(thing); }

	inline any_a<> pop_back__(range_a<> const& range)
	{ assert(___handle___); return ___write___().pop_back__(range); }

	inline any_a<> pop_back_()
	{ assert(___handle___); return ___write___().pop_back_(); }

	inline any_a<> self_assign__(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_assign__(range); }

	inline collection_a<> self_assign_(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_assign_(range); }

	inline any_a<> self_add__(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_add__(range); }

	inline collection_a<> self_add_(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_add_(range); }

	inline any_a<> add__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().add__(range); }

	inline collection_a<> add_(range_a<> const& range) const
	{ assert(___handle___); return ___read___().add_(range); }

	inline collection_a operator+(range_a < > const & range ) const
	{ assert(___handle___); return ___read___().operator+(range); }

	inline any_a<> self_subtract__(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_subtract__(range); }

	inline collection_a<> self_subtract_(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_subtract_(range); }

	inline any_a<> subtract__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().subtract__(range); }

	inline collection_a<> subtract_(range_a<> const& range) const
	{ assert(___handle___); return ___read___().subtract_(range); }

	inline collection_a operator-(range_a < > const & range ) const
	{ assert(___handle___); return ___read___().operator-(range); }

	inline any_a<> read_lock__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().read_lock__(range); }

	inline any_a<> read_lock_() const
	{ assert(___handle___); return ___read___().read_lock_(); }

	inline any_a<> write_lock__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().write_lock__(range); }

	inline any_a<> write_lock_() const
	{ assert(___handle___); return ___read___().write_lock_(); }

protected:
	struct ___collection_a_handle_base___ : ___range_a_handle_base___
	{
		virtual any_a<> has__(range_a<> const& range) const = 0;
		virtual any_a<> has_(any_a<> const& key) const = 0;
		virtual bool has(any_a < > const & key ) const = 0;
		virtual any_a<> at__(range_a<> const& range) const = 0;
		virtual any_a<> at_(any_a<> const& key) const = 0;
		virtual any_a<> update__(range_a<> const& range) = 0;
		virtual any_a<> update_(any_a<> const& key, any_a<> const& value = strange::no() ) = 0;
		virtual void update(any_a < > const & key , any_a < > const & value ) = 0;
		virtual any_a<> insert__(range_a<> const& range) = 0;
		virtual any_a<> insert_(any_a<> const& key, any_a<> const& value = strange::no() ) = 0;
		virtual void insert(any_a < > const & key , any_a < > const & value ) = 0;
		virtual any_a<> erase__(range_a<> const& range) = 0;
		virtual any_a<> erase_(any_a<> const& key) = 0;
		virtual bool erase(any_a < > const & key ) = 0;
		virtual any_a<> clear__(range_a<> const& range) = 0;
		virtual collection_a<> clear_() = 0;
		virtual void clear() = 0;
		virtual any_a<> size__(range_a<> const& range) const = 0;
		virtual number_data_int64_a<> size_() const = 0;
		virtual int64_t size() const = 0;
		virtual any_a<> empty__(range_a<> const& range) const = 0;
		virtual any_a<> empty_() const = 0;
		virtual bool empty() const = 0;
		virtual any_a<> push_front__(range_a<> const& range) = 0;
		virtual collection_a<> push_front_(any_a<> const& thing) = 0;
		virtual void push_front(any_a < > const & thing ) = 0;
		virtual any_a<> pop_front__(range_a<> const& range) = 0;
		virtual any_a<> pop_front_() = 0;
		virtual any_a<> push_back__(range_a<> const& range) = 0;
		virtual collection_a<> push_back_(any_a<> const& thing) = 0;
		virtual void push_back(any_a < > const & thing ) = 0;
		virtual any_a<> pop_back__(range_a<> const& range) = 0;
		virtual any_a<> pop_back_() = 0;
		virtual any_a<> self_assign__(range_a<> const& range) = 0;
		virtual collection_a<> self_assign_(range_a<> const& range) = 0;
		virtual any_a<> self_add__(range_a<> const& range) = 0;
		virtual collection_a<> self_add_(range_a<> const& range) = 0;
		virtual any_a<> add__(range_a<> const& range) const = 0;
		virtual collection_a<> add_(range_a<> const& range) const = 0;
		virtual collection_a operator+(range_a < > const & range ) const = 0;
		virtual any_a<> self_subtract__(range_a<> const& range) = 0;
		virtual collection_a<> self_subtract_(range_a<> const& range) = 0;
		virtual any_a<> subtract__(range_a<> const& range) const = 0;
		virtual collection_a<> subtract_(range_a<> const& range) const = 0;
		virtual collection_a operator-(range_a < > const & range ) const = 0;
		virtual any_a<> read_lock__(range_a<> const& range) const = 0;
		virtual any_a<> read_lock_() const = 0;
		virtual any_a<> write_lock__(range_a<> const& range) const = 0;
		virtual any_a<> write_lock_() const = 0;
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

		template <typename... Args>
		inline ___collection_a_handle___(___variadic_tag___, Args&&... args)
			: ___range_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> has__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.has__(range); }

		virtual inline any_a<> has_(any_a<> const& key) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.has_(key); }

		virtual inline bool has(any_a < > const & key ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.has(key); }

		virtual inline any_a<> at__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.at__(range); }

		virtual inline any_a<> at_(any_a<> const& key) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.at_(key); }

		virtual inline any_a<> update__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.update__(range); }

		virtual inline any_a<> update_(any_a<> const& key, any_a<> const& value = strange::no() ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.update_(key, value); }

		virtual inline void update(any_a < > const & key , any_a < > const & value ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.update(key, value); }

		virtual inline any_a<> insert__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.insert__(range); }

		virtual inline any_a<> insert_(any_a<> const& key, any_a<> const& value = strange::no() ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_(key, value); }

		virtual inline void insert(any_a < > const & key , any_a < > const & value ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.insert(key, value); }

		virtual inline any_a<> erase__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.erase__(range); }

		virtual inline any_a<> erase_(any_a<> const& key) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.erase_(key); }

		virtual inline bool erase(any_a < > const & key ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.erase(key); }

		virtual inline any_a<> clear__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.clear__(range); }

		virtual inline collection_a<> clear_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.clear_(); }

		virtual inline void clear() final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.clear(); }

		virtual inline any_a<> size__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.size__(range); }

		virtual inline number_data_int64_a<> size_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.size_(); }

		virtual inline int64_t size() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.size(); }

		virtual inline any_a<> empty__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.empty__(range); }

		virtual inline any_a<> empty_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.empty_(); }

		virtual inline bool empty() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.empty(); }

		virtual inline any_a<> push_front__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.push_front__(range); }

		virtual inline collection_a<> push_front_(any_a<> const& thing) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.push_front_(thing); }

		virtual inline void push_front(any_a < > const & thing ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.push_front(thing); }

		virtual inline any_a<> pop_front__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.pop_front__(range); }

		virtual inline any_a<> pop_front_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.pop_front_(); }

		virtual inline any_a<> push_back__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.push_back__(range); }

		virtual inline collection_a<> push_back_(any_a<> const& thing) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.push_back_(thing); }

		virtual inline void push_back(any_a < > const & thing ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.push_back(thing); }

		virtual inline any_a<> pop_back__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.pop_back__(range); }

		virtual inline any_a<> pop_back_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.pop_back_(); }

		virtual inline any_a<> self_assign__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_assign__(range); }

		virtual inline collection_a<> self_assign_(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_assign_(range); }

		virtual inline any_a<> self_add__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_add__(range); }

		virtual inline collection_a<> self_add_(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_add_(range); }

		virtual inline any_a<> add__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.add__(range); }

		virtual inline collection_a<> add_(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(range); }

		virtual inline collection_a operator+(range_a < > const & range ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator+(range); }

		virtual inline any_a<> self_subtract__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_subtract__(range); }

		virtual inline collection_a<> self_subtract_(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_subtract_(range); }

		virtual inline any_a<> subtract__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.subtract__(range); }

		virtual inline collection_a<> subtract_(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.subtract_(range); }

		virtual inline collection_a operator-(range_a < > const & range ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator-(range); }

		virtual inline any_a<> read_lock__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.read_lock__(range); }

		virtual inline any_a<> read_lock_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.read_lock_(); }

		virtual inline any_a<> write_lock__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.write_lock__(range); }

		virtual inline any_a<> write_lock_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.write_lock_(); }

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

		template <typename... Args>
		inline ___collection_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___collection_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___collection_a_handle_final___>(___collection_a_handle___<___TTT___>::___value___);
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

protected:
	inline ___collection_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___collection_a_handle_base___ const>(___handle___);
	}

	inline ___collection_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___collection_a_handle_base___>(___handle___);
	}

public:
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

	template <typename ___TTT___>
	explicit inline collection_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: range_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline collection_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: range_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<collection_a, std::decay_t<___TTT___>>::value>>
	explicit inline collection_a(___TTT___ value) noexcept
		: range_a{ std::make_shared<___collection_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline collection_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: range_a{ std::make_shared<___collection_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline collection_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<collection_a, std::decay_t<___TTT___>>::value>>
	inline collection_a& operator=(___TTT___ value) noexcept
	{
		collection_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___collection_a_handle_base___>(thing.___handle___) };
	}

	static inline collection_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___collection_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return collection_a{ thing.___handle___ };
		}
		return collection_a{ collection_d<_1_>{ thing } };
	}

	static inline collection_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___collection_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return collection_a(thing.___handle___, ___reference_tag___{});
		}
		return collection_a{ collection_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::collection");
		return CAT;
	}

	template <typename ___TTT___, typename... Args>
	static inline collection_a create(Args&&... args)
	{
		return collection_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___collection_a_share___;
}; // class collection_a

template <typename _1_>
bool const collection_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<collection_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class collection_d : public range_d<>
{
public:
	// arithmetic operator overloads
	inline collection_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline collection_d operator++(int)
	{
		assert(___handle___);
		collection_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline collection_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline collection_d operator--(int)
	{
		assert(___handle___);
		collection_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline collection_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline collection_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline collection_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline collection_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline collection_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> has__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("has_");
		if (!op)
		{
			throw dis("dynamic collection_d::has_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), range);
	}

	inline any_a<> has_(any_a<> const& key) const
	{
		assert(___handle___);
		auto const op = operation("has_");
		if (!op)
		{
			throw dis("dynamic collection_d::has_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<collection_d*>(this), key));
	}

	inline bool has(any_a < > const & key ) const
	{ return has_(key); }

	inline any_a<> at__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("at_");
		if (!op)
		{
			throw dis("dynamic collection_d::at_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), range);
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		assert(___handle___);
		auto const op = operation("at_");
		if (!op)
		{
			throw dis("dynamic collection_d::at_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<collection_d*>(this), key));
	}

	inline any_a<> update__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("update_");
		if (!op)
		{
			throw dis("dynamic collection_d::update_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> update_(any_a<> const& key, any_a<> const& value = strange::no() )
	{
		assert(___handle___);
		auto const op = operation("update_");
		if (!op)
		{
			throw dis("dynamic collection_d::update_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, key, value));
	}

	inline void update(any_a < > const & key , any_a < > const & value )
	{ update_(key, value); }

	inline any_a<> insert__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("insert_");
		if (!op)
		{
			throw dis("dynamic collection_d::insert_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> insert_(any_a<> const& key, any_a<> const& value = strange::no() )
	{
		assert(___handle___);
		auto const op = operation("insert_");
		if (!op)
		{
			throw dis("dynamic collection_d::insert_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, key, value));
	}

	inline void insert(any_a < > const & key , any_a < > const & value )
	{ insert_(key, value); }

	inline any_a<> erase__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("erase_");
		if (!op)
		{
			throw dis("dynamic collection_d::erase_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> erase_(any_a<> const& key)
	{
		assert(___handle___);
		auto const op = operation("erase_");
		if (!op)
		{
			throw dis("dynamic collection_d::erase_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, key));
	}

	inline bool erase(any_a < > const & key )
	{ return erase_(key); }

	inline any_a<> clear__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("clear_");
		if (!op)
		{
			throw dis("dynamic collection_d::clear_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline collection_a<> clear_()
	{
		assert(___handle___);
		auto const op = operation("clear_");
		if (!op)
		{
			throw dis("dynamic collection_d::clear_ passed non-existent member");
		}
		return cast<collection_a<>>(variadic_operate(op, *this));
	}

	inline void clear()
	{ clear_(); }

	inline any_a<> size__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("size_");
		if (!op)
		{
			throw dis("dynamic collection_d::size_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), range);
	}

	inline number_data_int64_a<> size_() const
	{
		assert(___handle___);
		auto const op = operation("size_");
		if (!op)
		{
			throw dis("dynamic collection_d::size_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<collection_d*>(this)));
	}

	inline int64_t size() const
	{ return size_().extract_primitive(); }

	inline any_a<> empty__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("empty_");
		if (!op)
		{
			throw dis("dynamic collection_d::empty_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), range);
	}

	inline any_a<> empty_() const
	{
		assert(___handle___);
		auto const op = operation("empty_");
		if (!op)
		{
			throw dis("dynamic collection_d::empty_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<collection_d*>(this)));
	}

	inline bool empty() const
	{ return empty_(); }

	inline any_a<> push_front__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("push_front_");
		if (!op)
		{
			throw dis("dynamic collection_d::push_front_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline collection_a<> push_front_(any_a<> const& thing)
	{
		assert(___handle___);
		auto const op = operation("push_front_");
		if (!op)
		{
			throw dis("dynamic collection_d::push_front_ passed non-existent member");
		}
		return cast<collection_a<>>(variadic_operate(op, *this, thing));
	}

	inline void push_front(any_a < > const & thing )
	{ push_front_(thing); }

	inline any_a<> pop_front__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("pop_front_");
		if (!op)
		{
			throw dis("dynamic collection_d::pop_front_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> pop_front_()
	{
		assert(___handle___);
		auto const op = operation("pop_front_");
		if (!op)
		{
			throw dis("dynamic collection_d::pop_front_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this));
	}

	inline any_a<> push_back__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("push_back_");
		if (!op)
		{
			throw dis("dynamic collection_d::push_back_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline collection_a<> push_back_(any_a<> const& thing)
	{
		assert(___handle___);
		auto const op = operation("push_back_");
		if (!op)
		{
			throw dis("dynamic collection_d::push_back_ passed non-existent member");
		}
		return cast<collection_a<>>(variadic_operate(op, *this, thing));
	}

	inline void push_back(any_a < > const & thing )
	{ push_back_(thing); }

	inline any_a<> pop_back__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("pop_back_");
		if (!op)
		{
			throw dis("dynamic collection_d::pop_back_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> pop_back_()
	{
		assert(___handle___);
		auto const op = operation("pop_back_");
		if (!op)
		{
			throw dis("dynamic collection_d::pop_back_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this));
	}

	inline any_a<> self_assign__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_assign_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_assign_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline collection_a<> self_assign_(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_assign_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_assign_ passed non-existent member");
		}
		return cast<collection_a<>>(variadic_operate(op, *this, range));
	}

	inline any_a<> self_add__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_add_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_add_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline collection_a<> self_add_(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_add_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_add_ passed non-existent member");
		}
		return cast<collection_a<>>(variadic_operate(op, *this, range));
	}

	inline any_a<> add__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic collection_d::add_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), range);
	}

	inline collection_a<> add_(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic collection_d::add_ passed non-existent member");
		}
		return cast<collection_a<>>(variadic_operate(op, *const_cast<collection_d*>(this), range));
	}

	inline collection_a<_1_> operator+(range_a < > const & range ) const
	{ return add_(range); }

	inline any_a<> self_subtract__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_subtract_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline collection_a<> self_subtract_(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_subtract_ passed non-existent member");
		}
		return cast<collection_a<>>(variadic_operate(op, *this, range));
	}

	inline any_a<> subtract__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("subtract_");
		if (!op)
		{
			throw dis("dynamic collection_d::subtract_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), range);
	}

	inline collection_a<> subtract_(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("subtract_");
		if (!op)
		{
			throw dis("dynamic collection_d::subtract_ passed non-existent member");
		}
		return cast<collection_a<>>(variadic_operate(op, *const_cast<collection_d*>(this), range));
	}

	inline collection_a<_1_> operator-(range_a < > const & range ) const
	{ return subtract_(range); }

	inline any_a<> read_lock__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("read_lock_");
		if (!op)
		{
			throw dis("dynamic collection_d::read_lock_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), range);
	}

	inline any_a<> read_lock_() const
	{
		assert(___handle___);
		auto const op = operation("read_lock_");
		if (!op)
		{
			throw dis("dynamic collection_d::read_lock_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<collection_d*>(this)));
	}

	inline any_a<> write_lock__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("write_lock_");
		if (!op)
		{
			throw dis("dynamic collection_d::write_lock_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), range);
	}

	inline any_a<> write_lock_() const
	{
		assert(___handle___);
		auto const op = operation("write_lock_");
		if (!op)
		{
			throw dis("dynamic collection_d::write_lock_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<collection_d*>(this)));
	}

	void ___weak___(range_d<>::___WEAK___ const& weak) const {}

	explicit collection_d(any_a<> const& thing)
		: range_d<>{ thing }
	{}

	explicit collection_d(any_a<>& thing, ___reference_tag___)
		: range_d<>{ thing, ___reference_tag___{} }
	{}

	explicit collection_d(any_a<>& thing, ___duplicate_tag___)
		: range_d<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline collection_d<_1_> ___collection_dynamic___(any_a<> const& thing)
{
	return collection_d<_1_>{ thing };
}

} // namespace
