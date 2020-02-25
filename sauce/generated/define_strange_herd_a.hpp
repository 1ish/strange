
namespace strange
{

template <typename _1_ = void>
class herd_d;

template <typename _1_ = void>
inline herd_d<_1_> ___herd_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(herd_a<_1__chk> const& value) noexcept;

template <typename _1_>
class herd_a : public collection_a<>
{
public:
	// arithmetic operator overloads
	inline herd_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline herd_a operator++(int)
	{
		assert(handle_);
		herd_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline herd_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline herd_a operator--(int)
	{
		assert(handle_);
		herd_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline herd_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline herd_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline herd_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline herd_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline herd_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline bool has_string(std :: string const & s ) const
	{ assert(handle_); return read().has_string(s); }

	inline bool at_string(std :: string const & s ) const
	{ assert(handle_); return read().at_string(s); }

	inline void update(any_a < > const & thing )
	{ assert(handle_); write().update(thing); }

	inline void update_string(std :: string const & s )
	{ assert(handle_); write().update_string(s); }

	inline bool insert(any_a < > const & thing )
	{ assert(handle_); return write().insert(thing); }

	inline bool insert_string(std :: string const & s )
	{ assert(handle_); return write().insert_string(s); }

	inline bool erase_string(std :: string const & s )
	{ assert(handle_); return write().erase_string(s); }

protected:
	struct ___herd_a_handle_base___ : ___collection_a_handle_base___
	{
		virtual bool has_string(std :: string const & s ) const = 0;
		virtual bool at_string(std :: string const & s ) const = 0;
		virtual void update(any_a < > const & thing ) = 0;
		virtual void update_string(std :: string const & s ) = 0;
		virtual bool insert(any_a < > const & thing ) = 0;
		virtual bool insert_string(std :: string const & s ) = 0;
		virtual bool erase_string(std :: string const & s ) = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___herd_a_handle_base___>
	struct ___herd_a_handle___ : ___collection_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___herd_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___collection_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___herd_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___collection_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline bool has_string(std :: string const & s ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.has_string(s); }

		virtual inline bool at_string(std :: string const & s ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.at_string(s); }

		virtual inline void update(any_a < > const & thing ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.update(thing); }

		virtual inline void update_string(std :: string const & s ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.update_string(s); }

		virtual inline bool insert(any_a < > const & thing ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.insert(thing); }

		virtual inline bool insert_string(std :: string const & s ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.insert_string(s); }

		virtual inline bool erase_string(std :: string const & s ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.erase_string(s); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___herd_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___herd_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___herd_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___herd_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___herd_a_handle_final___ final : ___herd_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___herd_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___herd_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___herd_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___herd_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___herd_a_handle_final___>(___herd_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___herd_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___herd_a_handle_final___<___TTT___&>
	{
		inline ___herd_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___herd_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___herd_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___herd_a_handle_base___ const>(handle_);
	}

	inline ___herd_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___herd_a_handle_base___>(handle_);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(herd_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___herd_a_handle_base___>(handle));
	}

	static inline herd_a val(herd_a const& other) noexcept
	{
		return herd_a{ other };
	}

	static inline herd_a ref(herd_a& other) noexcept
	{
		return herd_a(other, ___reference_tag___{});
	}

	static inline herd_a dup(herd_a& other) noexcept
	{
		return herd_a(other, ___duplicate_tag___{});
	}

	inline herd_a() = default;

	inline herd_a(herd_a& other, ___reference_tag___) noexcept
		: collection_a(other, ___reference_tag___{})
	{}

	inline herd_a(herd_a& other, ___duplicate_tag___) noexcept
		: collection_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline herd_a(std::shared_ptr<___TTT___> const& handle)
		: collection_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___herd_a_handle_base___>(handle))
		{
			throw dis("herd_a constructor failed to cast from base to herd_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline herd_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: collection_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___herd_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline herd_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: collection_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___herd_a_handle_base___>(handle))
		{
			throw dis("herd_a constructor failed to cast from base to herd_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline herd_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: collection_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___herd_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<herd_a, std::decay_t<___TTT___>>::value>>
	explicit inline herd_a(___TTT___ value) noexcept
		: collection_a{ std::make_shared<___herd_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline herd_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___herd_a_handle_base___>(handle))
		{
			throw dis("herd_a assignment failed to cast from base to herd_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline herd_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___herd_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<herd_a, std::decay_t<___TTT___>>::value>>
	inline herd_a& operator=(___TTT___ value) noexcept
	{
		herd_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___herd_a_share___;
}; // class herd_a

template <typename ___TTT___, typename _1__chk>
inline bool check(herd_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const herd_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<herd_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class herd_d : public collection_d<>
{
public:
	// arithmetic operator overloads
	inline herd_d& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline herd_d operator++(int)
	{
		assert(handle_);
		herd_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline herd_d& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline herd_d operator--(int)
	{
		assert(handle_);
		herd_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline herd_d& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline herd_d& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline herd_d& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline herd_d& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline herd_d& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline bool has_string(std :: string const & s ) const
	{ throw dis("dynamic herd_d::has_string(s) not available"); }

	inline bool at_string(std :: string const & s ) const
	{ throw dis("dynamic herd_d::at_string(s) not available"); }

	inline void update(any_a < > const & thing )
	{ throw dis("dynamic herd_d::update(thing) not available"); }

	inline void update_string(std :: string const & s )
	{ throw dis("dynamic herd_d::update_string(s) not available"); }

	inline bool insert(any_a < > const & thing )
	{ throw dis("dynamic herd_d::insert(thing) not available"); }

	inline bool insert_string(std :: string const & s )
	{ throw dis("dynamic herd_d::insert_string(s) not available"); }

	inline bool erase_string(std :: string const & s )
	{ throw dis("dynamic herd_d::erase_string(s) not available"); }

	explicit herd_d(any_a<> const& thing)
		: collection_d{ thing }
	{}
};

template <typename _1_>
inline herd_d<_1_> ___herd_dynamic___(any_a<> const& thing)
{
	return herd_d<_1_>{ thing };
}

} // namespace
