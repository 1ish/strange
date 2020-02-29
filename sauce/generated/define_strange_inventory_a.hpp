
namespace strange
{

template <typename _1_ = void>
class inventory_d;

template <typename _1_ = void>
inline inventory_d<_1_> ___inventory_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(inventory_a<_1__chk> const& value) noexcept;

template <typename _1_>
class inventory_a : public collection_a<>
{
public:
	// arithmetic operator overloads
	inline inventory_a& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline inventory_a operator++(int)
	{
		assert(___handle___);
		inventory_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline inventory_a& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline inventory_a operator--(int)
	{
		assert(___handle___);
		inventory_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline inventory_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline inventory_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline inventory_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline inventory_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline inventory_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline bool has_index(int64_t index ) const
	{ assert(___handle___); return read().has_index(index); }

	inline any_a < > at_index(int64_t index ) const
	{ assert(___handle___); return read().at_index(index); }

	inline void update_index(int64_t index , any_a < > const & value )
	{ assert(___handle___); write().update_index(index, value); }

	inline bool insert_index(int64_t index , any_a < > const & value )
	{ assert(___handle___); return write().insert_index(index, value); }

	inline bool erase_index(int64_t index )
	{ assert(___handle___); return write().erase_index(index); }

	inline any_a<> begin__(range_a<> const& range)
	{ assert(___handle___); return write().begin__(range); }

	inline random_access_iterator_a<> begin_()
	{ assert(___handle___); return write().begin_(); }

	inline any_a<> end__(range_a<> const& range)
	{ assert(___handle___); return write().end__(range); }

	inline random_access_iterator_a<> end_()
	{ assert(___handle___); return write().end_(); }

protected:
	struct ___inventory_a_handle_base___ : ___collection_a_handle_base___
	{
		virtual bool has_index(int64_t index ) const = 0;
		virtual any_a < > at_index(int64_t index ) const = 0;
		virtual void update_index(int64_t index , any_a < > const & value ) = 0;
		virtual bool insert_index(int64_t index , any_a < > const & value ) = 0;
		virtual bool erase_index(int64_t index ) = 0;
		virtual any_a<> begin__(range_a<> const& range) = 0;
		virtual random_access_iterator_a<> begin_() = 0;
		virtual any_a<> end__(range_a<> const& range) = 0;
		virtual random_access_iterator_a<> end_() = 0;
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
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.has_index(index); }

		virtual inline any_a < > at_index(int64_t index ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.at_index(index); }

		virtual inline void update_index(int64_t index , any_a < > const & value ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.update_index(index, value); }

		virtual inline bool insert_index(int64_t index , any_a < > const & value ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_index(index, value); }

		virtual inline bool erase_index(int64_t index ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.erase_index(index); }

		virtual inline any_a<> begin__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.begin__(range); }

		virtual inline random_access_iterator_a<> begin_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.begin_(); }

		virtual inline any_a<> end__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.end__(range); }

		virtual inline random_access_iterator_a<> end_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.end_(); }

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
			return std::make_shared<___inventory_a_handle_final___>(___inventory_a_handle___<___TTT___>::___value___);
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

protected:
	inline ___inventory_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___inventory_a_handle_base___ const>(___handle___);
	}

	inline ___inventory_a_handle_base___& write() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___inventory_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(inventory_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
	}

	static inline inventory_a cast(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___inventory_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return inventory_a{ ptr };
		}
		return inventory_a{ inventory_d<_1_>{ thing } };
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
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline inventory_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle))
		{
			throw dis("inventory_a assignment failed to cast from base to inventory_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline inventory_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<inventory_a, std::decay_t<___TTT___>>::value>>
	inline inventory_a& operator=(___TTT___ value) noexcept
	{
		inventory_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___inventory_a_share___;
}; // class inventory_a

template <typename ___TTT___, typename _1__chk>
inline bool check(inventory_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

template <typename _1_>
bool const inventory_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<inventory_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class inventory_d : public collection_d<>
{
public:
	// arithmetic operator overloads
	inline inventory_d& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline inventory_d operator++(int)
	{
		assert(___handle___);
		inventory_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline inventory_d& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline inventory_d operator--(int)
	{
		assert(___handle___);
		inventory_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline inventory_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline inventory_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline inventory_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline inventory_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline inventory_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline bool has_index(int64_t index ) const
	{ return has_(num(index)); }

	inline any_a < > at_index(int64_t index ) const
	{ return at_(num(index)); }

	inline void update_index(int64_t index , any_a < > const & value )
	{ update_(num(index), value); }

	inline bool insert_index(int64_t index , any_a < > const & value )
	{ return insert_(num(index), value); }

	inline bool erase_index(int64_t index )
	{ return erase_(num(index)); }

	inline any_a<> begin__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("begin_");
		if (!op)
		{
			throw dis("dynamic inventory_d::begin_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline random_access_iterator_a<> begin_()
	{
		assert(___handle___);
		auto const op = operation("begin_");
		if (!op)
		{
			throw dis("dynamic inventory_d::begin_ passed non-existent member");
		}
		return variadic_operate(op, *this);
	}

	inline any_a<> end__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("end_");
		if (!op)
		{
			throw dis("dynamic inventory_d::end_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline random_access_iterator_a<> end_()
	{
		assert(___handle___);
		auto const op = operation("end_");
		if (!op)
		{
			throw dis("dynamic inventory_d::end_ passed non-existent member");
		}
		return variadic_operate(op, *this);
	}

	explicit inventory_d(any_a<> const& thing)
		: collection_d{ thing }
	{}
};

template <typename _1_>
inline inventory_d<_1_> ___inventory_dynamic___(any_a<> const& thing)
{
	return inventory_d<_1_>{ thing };
}

} // namespace
