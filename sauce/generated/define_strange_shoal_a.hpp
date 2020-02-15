
namespace strange
{

template <typename ___TTT___, typename _1_ = void>
inline bool check(shoal_a<_1_> const& value) noexcept;

template <typename _1_>
class shoal_a : public collection_a<>
{
public:
	// arithmetic operator overloads
	inline shoal_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

	inline shoal_a operator++(int)
	{
		assert(handle_);
		shoal_a result = *this;
		write().operator++();
		return result;
	}

	inline shoal_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

	inline shoal_a operator--(int)
	{
		assert(handle_);
		shoal_a result = *this;
		write().operator--();
		return result;
	}

	inline shoal_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline shoal_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline shoal_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline shoal_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline shoal_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline bool has_string(std :: string const & s ) const
	{ assert(handle_); return read().has_string(s); }

	inline any_a < > at_string(std :: string const & s ) const
	{ assert(handle_); return read().at_string(s); }

	inline void update_string(std :: string const & s , any_a < > const & value )
	{ assert(handle_); write().update_string(s, value); }

	inline bool insert_string(std :: string const & s , any_a < > const & value )
	{ assert(handle_); return write().insert_string(s, value); }

	inline bool erase_string(std :: string const & s )
	{ assert(handle_); return write().erase_string(s); }

	inline any_a<> begin__(range_a<> const& range)
	{ assert(handle_); return write().begin__(range); }

	inline forward_iterator_a<> begin_()
	{ assert(handle_); return write().begin_(); }

	inline any_a<> end__(range_a<> const& range)
	{ assert(handle_); return write().end__(range); }

	inline forward_iterator_a<> end_()
	{ assert(handle_); return write().end_(); }

protected:
	struct ___shoal_a_handle_base___ : ___collection_a_handle_base___
	{
		virtual inline bool has_string(std :: string const & s ) const = 0;
		virtual inline any_a < > at_string(std :: string const & s ) const = 0;
		virtual inline void update_string(std :: string const & s , any_a < > const & value ) = 0;
		virtual inline bool insert_string(std :: string const & s , any_a < > const & value ) = 0;
		virtual inline bool erase_string(std :: string const & s ) = 0;
		virtual inline any_a<> begin__(range_a<> const& range) = 0;
		virtual inline forward_iterator_a<> begin_() = 0;
		virtual inline any_a<> end__(range_a<> const& range) = 0;
		virtual inline forward_iterator_a<> end_() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___shoal_a_handle_base___>
	struct ___shoal_a_handle___ : ___collection_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___shoal_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___collection_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___shoal_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___collection_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline bool has_string(std :: string const & s ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.has_string(s); }

		virtual inline any_a < > at_string(std :: string const & s ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.at_string(s); }

		virtual inline void update_string(std :: string const & s , any_a < > const & value ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.update_string(s, value); }

		virtual inline bool insert_string(std :: string const & s , any_a < > const & value ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.insert_string(s, value); }

		virtual inline bool erase_string(std :: string const & s ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.erase_string(s); }

		virtual inline any_a<> begin__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.begin__(range); }

		virtual inline forward_iterator_a<> begin_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.begin_(); }

		virtual inline any_a<> end__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.end__(range); }

		virtual inline forward_iterator_a<> end_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.end_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___shoal_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___shoal_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___shoal_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___shoal_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___shoal_a_handle_final___ final : ___shoal_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___shoal_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___shoal_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___shoal_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___shoal_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___shoal_a_handle_final___>(___shoal_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___shoal_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___shoal_a_handle_final___<___TTT___&>
	{
		inline ___shoal_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___shoal_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___shoal_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___shoal_a_handle_base___ const>(handle_);
	}

	inline ___shoal_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___shoal_a_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename _1_>
	friend inline bool check(shoal_a<_1_> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___shoal_a_handle_base___>(handle));
	}

	static inline shoal_a val(shoal_a const& other) noexcept
	{
		return shoal_a{ other };
	}

	static inline shoal_a ref(shoal_a& other) noexcept
	{
		return shoal_a(other, ___reference_tag___{});
	}

	static inline shoal_a dup(shoal_a& other) noexcept
	{
		return shoal_a(other, ___duplicate_tag___{});
	}

	inline shoal_a() = default;

	inline shoal_a(shoal_a& other, ___reference_tag___) noexcept
		: collection_a(other, ___reference_tag___{})
	{}

	inline shoal_a(shoal_a& other, ___duplicate_tag___) noexcept
		: collection_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline shoal_a(std::shared_ptr<___TTT___> const& handle)
		: collection_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___shoal_a_handle_base___>(handle))
		{
			throw dis("shoal_a constructor failed to cast from base to shoal_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline shoal_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: collection_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___shoal_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline shoal_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: collection_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___shoal_a_handle_base___>(handle))
		{
			throw dis("shoal_a constructor failed to cast from base to shoal_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline shoal_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: collection_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___shoal_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<shoal_a, std::decay_t<___TTT___>>::value>>
	explicit inline shoal_a(___TTT___ value) noexcept
		: collection_a{ std::make_shared<___shoal_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline shoal_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___shoal_a_handle_base___>(handle))
		{
			throw dis("shoal_a assignment failed to cast from base to shoal_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline shoal_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___shoal_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<shoal_a, std::decay_t<___TTT___>>::value>>
	inline shoal_a& operator=(___TTT___ value) noexcept
	{
		shoal_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___shoal_a_share___;
}; // class shoal_a

template <typename ___TTT___, typename _1_>
inline bool check(shoal_a<_1_> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const shoal_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<shoal_a<_1_>>::share(shoal);
	return shoal;
}();

} // namespace
