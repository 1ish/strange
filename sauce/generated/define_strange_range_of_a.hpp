
namespace strange
{

template <typename element>
class range_of_d;

template <typename element>
inline range_of_d<element> ___range_of_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename element_chk>
inline bool check(range_of_a<element_chk> const& value) noexcept;

template <typename element>
class range_of_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline range_of_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline range_of_a operator++(int)
	{
		assert(handle_);
		range_of_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline range_of_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline range_of_a operator--(int)
	{
		assert(handle_);
		range_of_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline range_of_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline range_of_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline range_of_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline range_of_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline range_of_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> cbegin__(range_a<> const& range) const
	{ assert(handle_); return read().cbegin__(range); }

	inline forward_const_iterator_a<> cbegin_() const
	{ assert(handle_); return read().cbegin_(); }

	inline any_a<> cend__(range_a<> const& range) const
	{ assert(handle_); return read().cend__(range); }

	inline forward_const_iterator_a<> cend_() const
	{ assert(handle_); return read().cend_(); }

protected:
	struct ___range_of_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> cbegin__(range_a<> const& range) const = 0;
		virtual forward_const_iterator_a<> cbegin_() const = 0;
		virtual any_a<> cend__(range_a<> const& range) const = 0;
		virtual forward_const_iterator_a<> cend_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___range_of_a_handle_base___>
	struct ___range_of_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___range_of_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___range_of_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> cbegin__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.cbegin__(range); }

		virtual inline forward_const_iterator_a<> cbegin_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.cbegin_(); }

		virtual inline any_a<> cend__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.cend__(range); }

		virtual inline forward_const_iterator_a<> cend_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.cend_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___range_of_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___range_of_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___range_of_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___range_of_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___range_of_a_handle_final___ final : ___range_of_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___range_of_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___range_of_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___range_of_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___range_of_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___range_of_a_handle_final___>(___range_of_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___range_of_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___range_of_a_handle_final___<___TTT___&>
	{
		inline ___range_of_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___range_of_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___range_of_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___range_of_a_handle_base___ const>(handle_);
	}

	inline ___range_of_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___range_of_a_handle_base___>(handle_);
	}

private:
	template <typename ___TTT___, typename element_chk>
	friend inline bool check(range_of_a<element_chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___range_of_a_handle_base___>(handle));
	}

	static inline range_of_a cast(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___range_of_a_handle_base___>(static_cast<range_of_a const&>(thing).handle_);
		if (ptr)
		{
			return range_of_a{ ptr };
		}
		return range_of_a{ range_of_d<element>{ thing } };
	}

	static inline range_of_a val(range_of_a const& other) noexcept
	{
		return range_of_a{ other };
	}

	static inline range_of_a ref(range_of_a& other) noexcept
	{
		return range_of_a(other, ___reference_tag___{});
	}

	static inline range_of_a dup(range_of_a& other) noexcept
	{
		return range_of_a(other, ___duplicate_tag___{});
	}

	inline range_of_a() = default;

	inline range_of_a(range_of_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline range_of_a(range_of_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline range_of_a(std::shared_ptr<___TTT___> const& handle)
		: any_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___range_of_a_handle_base___>(handle))
		{
			throw dis("range_of_a constructor failed to cast from base to range_of_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline range_of_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___range_of_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline range_of_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: any_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___range_of_a_handle_base___>(handle))
		{
			throw dis("range_of_a constructor failed to cast from base to range_of_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline range_of_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___range_of_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<range_of_a, std::decay_t<___TTT___>>::value>>
	explicit inline range_of_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___range_of_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline range_of_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___range_of_a_handle_base___>(handle))
		{
			throw dis("range_of_a assignment failed to cast from base to range_of_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline range_of_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___range_of_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<range_of_a, std::decay_t<___TTT___>>::value>>
	inline range_of_a& operator=(___TTT___ value) noexcept
	{
		range_of_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___range_of_a_share___;
}; // class range_of_a

template <typename ___TTT___, typename element_chk>
inline bool check(range_of_a<element_chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename element>
bool const range_of_a<element>::___share___ = []()
{
	auto& shoal = shared();
	reflection<range_of_a<element>>::share(shoal);
	return shoal;
}();

template <typename element>
class range_of_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline range_of_d& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline range_of_d operator++(int)
	{
		assert(handle_);
		range_of_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline range_of_d& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline range_of_d operator--(int)
	{
		assert(handle_);
		range_of_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline range_of_d& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline range_of_d& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline range_of_d& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline range_of_d& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline range_of_d& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> cbegin__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("cbegin_");
		if (!op)
		{
			throw dis("dynamic range_of_d::cbegin_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline forward_const_iterator_a<> cbegin_() const
	{
		assert(handle_);
		auto const op = operation("cbegin_");
		if (!op)
		{
			throw dis("dynamic range_of_d::cbegin_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline any_a<> cend__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("cend_");
		if (!op)
		{
			throw dis("dynamic range_of_d::cend_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline forward_const_iterator_a<> cend_() const
	{
		assert(handle_);
		auto const op = operation("cend_");
		if (!op)
		{
			throw dis("dynamic range_of_d::cend_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	explicit range_of_d(any_a<> const& thing)
		: any_a{ thing }
	{}
};

template <typename element>
inline range_of_d<element> ___range_of_dynamic___(any_a<> const& thing)
{
	return range_of_d<element>{ thing };
}

} // namespace
