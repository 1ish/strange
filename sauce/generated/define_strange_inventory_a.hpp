
namespace strange
{

template <typename ___TTT___, typename _1_ = void>
inline bool check(inventory_a<_1_> const& value) noexcept;

template <typename _1_>
class inventory_a : public collection_a<>
{
public:
	// arithmetic operator overloads
	inline inventory_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

	inline inventory_a operator++(int)
	{
		assert(handle_);
		inventory_a result = *this;
		write().operator++();
		return result;
	}

	inline inventory_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

	inline inventory_a operator--(int)
	{
		assert(handle_);
		inventory_a result = *this;
		write().operator--();
		return result;
	}

	inline inventory_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline inventory_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline inventory_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline inventory_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline inventory_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline bool has_index(int64_t index ) const
	{ assert(handle_); return read().has_index(index); }

	inline any_a < > at_index(int64_t index ) const
	{ assert(handle_); return read().at_index(index); }

	inline void update_index(int64_t index , any_a < > const & value )
	{ assert(handle_); write().update_index(index, value); }

	inline bool insert_index(int64_t index , any_a < > const & value )
	{ assert(handle_); return write().insert_index(index, value); }

	inline bool erase_index(int64_t index )
	{ assert(handle_); return write().erase_index(index); }

	inline any_a<> begin__(range_a<> const& range)
	{ assert(handle_); return write().begin__(range); }

	inline random_access_iterator_a<> begin_()
	{ assert(handle_); return write().begin_(); }

	inline any_a<> end__(range_a<> const& range)
	{ assert(handle_); return write().end__(range); }

	inline random_access_iterator_a<> end_()
	{ assert(handle_); return write().end_(); }

protected:
	struct ___inventory_a_handle_base___ : ___collection_a_handle_base___
	{
		virtual inline bool has_index(int64_t index ) const = 0;
		virtual inline any_a < > at_index(int64_t index ) const = 0;
		virtual inline void update_index(int64_t index , any_a < > const & value ) = 0;
		virtual inline bool insert_index(int64_t index , any_a < > const & value ) = 0;
		virtual inline bool erase_index(int64_t index ) = 0;
		virtual inline any_a<> begin__(range_a<> const& range) = 0;
		virtual inline random_access_iterator_a<> begin_() = 0;
		virtual inline any_a<> end__(range_a<> const& range) = 0;
		virtual inline random_access_iterator_a<> end_() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___inventory_a_handle_base___>
	struct ___inventory_a_handle___ : ___collection_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___collection_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___collection_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline bool has_index(int64_t index ) const final
		{ return value_.has_index(index); }

		virtual inline any_a < > at_index(int64_t index ) const final
		{ return value_.at_index(index); }

		virtual inline void update_index(int64_t index , any_a < > const & value ) final
		{ value_.update_index(index, value); }

		virtual inline bool insert_index(int64_t index , any_a < > const & value ) final
		{ return value_.insert_index(index, value); }

		virtual inline bool erase_index(int64_t index ) final
		{ return value_.erase_index(index); }

		virtual inline any_a<> begin__(range_a<> const& range) final
		{ return value_.begin__(range); }

		virtual inline random_access_iterator_a<> begin_() final
		{ return value_.begin_(); }

		virtual inline any_a<> end__(range_a<> const& range) final
		{ return value_.end__(range); }

		virtual inline random_access_iterator_a<> end_() final
		{ return value_.end_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___inventory_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___inventory_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___inventory_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___inventory_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___inventory_a_handle_final___ final : ___inventory_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___inventory_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___inventory_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___inventory_a_handle_final___>(___inventory_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___inventory_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___inventory_a_handle_final___<___TTT___&>
	{
		inline ___inventory_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___inventory_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___inventory_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___inventory_a_handle_base___ const>(handle_);
	}

	inline ___inventory_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___inventory_a_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename _1_>
	friend inline bool check(inventory_a<_1_> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
	}

	static inline inventory_a val(inventory_a const& other) noexcept
	{
		return inventory_a{ other };
	}

	static inline inventory_a ref(inventory_a& other) noexcept
	{
		return inventory_a(other, ___reference_tag___{});
	}

	static inline inventory_a dup(inventory_a& other) noexcept
	{
		return inventory_a(other, ___duplicate_tag___{});
	}

	inline inventory_a() = default;

	inline inventory_a(inventory_a& other, ___reference_tag___) noexcept
		: collection_a(other, ___reference_tag___{})
	{}

	inline inventory_a(inventory_a& other, ___duplicate_tag___) noexcept
		: collection_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline inventory_a(std::shared_ptr<___TTT___> const& handle)
		: collection_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle))
		{
			throw dis("inventory_a constructor failed to cast from base to inventory_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline inventory_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: collection_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline inventory_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: collection_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle))
		{
			throw dis("inventory_a constructor failed to cast from base to inventory_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline inventory_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: collection_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<inventory_a, std::decay_t<___TTT___>>::value>>
	explicit inline inventory_a(___TTT___ value) noexcept
		: collection_a{ std::make_shared<___inventory_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline inventory_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle))
		{
			throw dis("inventory_a assignment failed to cast from base to inventory_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline inventory_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<inventory_a, std::decay_t<___TTT___>>::value>>
	inline inventory_a& operator=(___TTT___ value) noexcept
	{
		inventory_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___inventory_a_share___;
}; // class inventory_a

template <typename ___TTT___, typename _1_>
inline bool check(inventory_a<_1_> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const inventory_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<inventory_a<_1_>>::share(shoal);
	return shoal.something();
}();

} // namespace
