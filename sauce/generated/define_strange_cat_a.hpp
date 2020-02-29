
namespace strange
{

template <typename _1_ = void>
class cat_d;

template <typename _1_ = void>
inline cat_d<_1_> ___cat_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(cat_a<_1__chk> const& value) noexcept;

template <typename _1_>
class cat_a : public symbol_a<>
{
public:
	// arithmetic operator overloads
	inline cat_a& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline cat_a operator++(int)
	{
		assert(___handle___);
		cat_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline cat_a& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline cat_a operator--(int)
	{
		assert(___handle___);
		cat_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline cat_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline cat_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline cat_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline cat_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline cat_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> symbolic__(range_a<> const& range) const
	{ assert(___handle___); return read().symbolic__(range); }

	inline any_a<> symbolic_() const
	{ assert(___handle___); return read().symbolic_(); }

	inline bool symbolic() const
	{ assert(___handle___); return read().symbolic(); }

	inline any_a<> order__(range_a<> const& range) const
	{ assert(___handle___); return read().order__(range); }

	inline number_data_int64_a<> order_() const
	{ assert(___handle___); return read().order_(); }

	inline int64_t order() const
	{ assert(___handle___); return read().order(); }

	inline any_a<> name__(range_a<> const& range) const
	{ assert(___handle___); return read().name__(range); }

	inline symbol_a<> name_() const
	{ assert(___handle___); return read().name_(); }

	inline any_a<> dimensions__(range_a<> const& range) const
	{ assert(___handle___); return read().dimensions__(range); }

	inline flock_a<> dimensions_() const
	{ assert(___handle___); return read().dimensions_(); }

	inline any_a<> parameters__(range_a<> const& range) const
	{ assert(___handle___); return read().parameters__(range); }

	inline flock_a<> parameters_() const
	{ assert(___handle___); return read().parameters_(); }

	inline any_a<> result__(range_a<> const& range) const
	{ assert(___handle___); return read().result__(range); }

	inline cat_a<> result_() const
	{ assert(___handle___); return read().result_(); }

	inline any_a<> code__(range_a<> const& range) const
	{ assert(___handle___); return read().code__(range); }

	inline lake_int8_a<> code_() const
	{ assert(___handle___); return read().code_(); }

	inline std :: string code() const
	{ assert(___handle___); return read().code(); }

protected:
	struct ___cat_a_handle_base___ : ___symbol_a_handle_base___
	{
		virtual any_a<> symbolic__(range_a<> const& range) const = 0;
		virtual any_a<> symbolic_() const = 0;
		virtual bool symbolic() const = 0;
		virtual any_a<> order__(range_a<> const& range) const = 0;
		virtual number_data_int64_a<> order_() const = 0;
		virtual int64_t order() const = 0;
		virtual any_a<> name__(range_a<> const& range) const = 0;
		virtual symbol_a<> name_() const = 0;
		virtual any_a<> dimensions__(range_a<> const& range) const = 0;
		virtual flock_a<> dimensions_() const = 0;
		virtual any_a<> parameters__(range_a<> const& range) const = 0;
		virtual flock_a<> parameters_() const = 0;
		virtual any_a<> result__(range_a<> const& range) const = 0;
		virtual cat_a<> result_() const = 0;
		virtual any_a<> code__(range_a<> const& range) const = 0;
		virtual lake_int8_a<> code_() const = 0;
		virtual std :: string code() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___cat_a_handle_base___>
	struct ___cat_a_handle___ : ___symbol_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___cat_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___symbol_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___cat_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___symbol_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> symbolic__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.symbolic__(range); }

		virtual inline any_a<> symbolic_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.symbolic_(); }

		virtual inline bool symbolic() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.symbolic(); }

		virtual inline any_a<> order__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.order__(range); }

		virtual inline number_data_int64_a<> order_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.order_(); }

		virtual inline int64_t order() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.order(); }

		virtual inline any_a<> name__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.name__(range); }

		virtual inline symbol_a<> name_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.name_(); }

		virtual inline any_a<> dimensions__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.dimensions__(range); }

		virtual inline flock_a<> dimensions_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.dimensions_(); }

		virtual inline any_a<> parameters__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.parameters__(range); }

		virtual inline flock_a<> parameters_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.parameters_(); }

		virtual inline any_a<> result__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.result__(range); }

		virtual inline cat_a<> result_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.result_(); }

		virtual inline any_a<> code__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.code__(range); }

		virtual inline lake_int8_a<> code_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.code_(); }

		virtual inline std :: string code() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.code(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___cat_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___cat_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___cat_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___cat_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___cat_a_handle_final___ final : ___cat_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___cat_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___cat_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___cat_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___cat_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___cat_a_handle_final___>(___cat_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___cat_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___cat_a_handle_final___<___TTT___&>
	{
		inline ___cat_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___cat_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___cat_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___cat_a_handle_base___ const>(___handle___);
	}

	inline ___cat_a_handle_base___& write() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___cat_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(cat_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___cat_a_handle_base___>(handle));
	}

	static inline cat_a cast(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___cat_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return cat_a{ ptr };
		}
		return cat_a{ cat_d<_1_>{ thing } };
	}

	static inline cat_a val(cat_a const& other) noexcept
	{
		return cat_a{ other };
	}

	static inline cat_a ref(cat_a& other) noexcept
	{
		return cat_a(other, ___reference_tag___{});
	}

	static inline cat_a dup(cat_a& other) noexcept
	{
		return cat_a(other, ___duplicate_tag___{});
	}

	inline cat_a() = default;

	inline cat_a(cat_a& other, ___reference_tag___) noexcept
		: symbol_a(other, ___reference_tag___{})
	{}

	inline cat_a(cat_a& other, ___duplicate_tag___) noexcept
		: symbol_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline cat_a(std::shared_ptr<___TTT___> const& handle)
		: symbol_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___cat_a_handle_base___>(handle))
		{
			throw dis("cat_a constructor failed to cast from base to cat_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline cat_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: symbol_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___cat_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline cat_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: symbol_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___cat_a_handle_base___>(handle))
		{
			throw dis("cat_a constructor failed to cast from base to cat_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline cat_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: symbol_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___cat_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_a, std::decay_t<___TTT___>>::value>>
	explicit inline cat_a(___TTT___ value) noexcept
		: symbol_a{ std::make_shared<___cat_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline cat_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___cat_a_handle_base___>(handle))
		{
			throw dis("cat_a assignment failed to cast from base to cat_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline cat_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___cat_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_a, std::decay_t<___TTT___>>::value>>
	inline cat_a& operator=(___TTT___ value) noexcept
	{
		cat_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___cat_a_share___;
}; // class cat_a

template <typename ___TTT___, typename _1__chk>
inline bool check(cat_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

template <typename _1_>
bool const cat_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<cat_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class cat_d : public symbol_d<>
{
public:
	// arithmetic operator overloads
	inline cat_d& operator++()
	{
		assert(___handle___);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline cat_d operator++(int)
	{
		assert(___handle___);
		cat_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline cat_d& operator--()
	{
		assert(___handle___);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline cat_d operator--(int)
	{
		assert(___handle___);
		cat_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline cat_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator+=(other);
		return *this;
	}

	inline cat_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator-=(other);
		return *this;
	}

	inline cat_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator*=(other);
		return *this;
	}

	inline cat_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator/=(other);
		return *this;
	}

	inline cat_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> symbolic__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("symbolic_");
		if (!op)
		{
			throw dis("dynamic cat_d::symbolic_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline any_a<> symbolic_() const
	{
		assert(___handle___);
		auto const op = operation("symbolic_");
		if (!op)
		{
			throw dis("dynamic cat_d::symbolic_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline bool symbolic() const
	{ return symbolic_(); }

	inline any_a<> order__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("order_");
		if (!op)
		{
			throw dis("dynamic cat_d::order_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline number_data_int64_a<> order_() const
	{
		assert(___handle___);
		auto const op = operation("order_");
		if (!op)
		{
			throw dis("dynamic cat_d::order_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline int64_t order() const
	{ return order_().to_int_64(); }

	inline any_a<> name__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("name_");
		if (!op)
		{
			throw dis("dynamic cat_d::name_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline symbol_a<> name_() const
	{
		assert(___handle___);
		auto const op = operation("name_");
		if (!op)
		{
			throw dis("dynamic cat_d::name_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline any_a<> dimensions__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("dimensions_");
		if (!op)
		{
			throw dis("dynamic cat_d::dimensions_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline flock_a<> dimensions_() const
	{
		assert(___handle___);
		auto const op = operation("dimensions_");
		if (!op)
		{
			throw dis("dynamic cat_d::dimensions_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline any_a<> parameters__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("parameters_");
		if (!op)
		{
			throw dis("dynamic cat_d::parameters_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline flock_a<> parameters_() const
	{
		assert(___handle___);
		auto const op = operation("parameters_");
		if (!op)
		{
			throw dis("dynamic cat_d::parameters_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline any_a<> result__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("result_");
		if (!op)
		{
			throw dis("dynamic cat_d::result_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline cat_a<> result_() const
	{
		assert(___handle___);
		auto const op = operation("result_");
		if (!op)
		{
			throw dis("dynamic cat_d::result_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline any_a<> code__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("code_");
		if (!op)
		{
			throw dis("dynamic cat_d::code_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline lake_int8_a<> code_() const
	{
		assert(___handle___);
		auto const op = operation("code_");
		if (!op)
		{
			throw dis("dynamic cat_d::code_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline std :: string code() const
	{ return lake_to_string(code_()); }

	explicit cat_d(any_a<> const& thing)
		: symbol_d{ thing }
	{}
};

template <typename _1_>
inline cat_d<_1_> ___cat_dynamic___(any_a<> const& thing)
{
	return cat_d<_1_>{ thing };
}

} // namespace
