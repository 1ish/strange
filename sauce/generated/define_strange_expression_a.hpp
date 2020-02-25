
namespace strange
{

template <typename _1_ = void>
class expression_d;

template <typename _1_ = void>
inline expression_d<_1_> ___expression_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(expression_a<_1__chk> const& value) noexcept;

template <typename _1_>
class expression_a : public operation_a<>
{
public:
	// arithmetic operator overloads
	inline expression_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline expression_a operator++(int)
	{
		assert(handle_);
		expression_a result = *this;
		write().operator++();
		return result;
	}
#endif

	inline expression_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline expression_a operator--(int)
	{
		assert(handle_);
		expression_a result = *this;
		write().operator--();
		return result;
	}
#endif

	inline expression_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline expression_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline expression_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline expression_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline expression_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> recreate__(range_a<> const& range) const
	{ assert(handle_); return read().recreate__(range); }

	inline expression_a<> recreate_() const
	{ assert(handle_); return read().recreate_(); }

	inline void recreated(expression_a < > const & expression ) const
	{ assert(handle_); read().recreated(expression); }

	inline any_a<> literal__(range_a<> const& range) const
	{ assert(handle_); return read().literal__(range); }

	inline any_a<> literal_() const
	{ assert(handle_); return read().literal_(); }

	inline bool literal() const
	{ assert(handle_); return read().literal(); }

	inline any_a<> evaluate__(range_a<> const& range) const
	{ assert(handle_); return read().evaluate__(range); }

	inline any_a<> evaluate_() const
	{ assert(handle_); return read().evaluate_(); }

	inline any_a<> token__(range_a<> const& range) const
	{ assert(handle_); return read().token__(range); }

	inline token_a<> token_() const
	{ assert(handle_); return read().token_(); }

	inline any_a<> terms__(range_a<> const& range) const
	{ assert(handle_); return read().terms__(range); }

	inline flock_a<> terms_() const
	{ assert(handle_); return read().terms_(); }

	inline any_a<> generate__(range_a<> const& range) const
	{ assert(handle_); return read().generate__(range); }

	inline any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const
	{ assert(handle_); return read().generate_(version, indent, river); }

	inline void generate(int64_t version , int64_t indent , river_a < > & river ) const
	{ assert(handle_); read().generate(version, indent, river); }

	inline any_a<> generate_cpp__(range_a<> const& range) const
	{ assert(handle_); return read().generate_cpp__(range); }

	inline any_a<> generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = strange::no() ) const
	{ assert(handle_); return read().generate_cpp_(version, indent, river, declare, define, type); }

	inline void generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type = false ) const
	{ assert(handle_); read().generate_cpp(version, indent, river, declare, define, type); }

protected:
	struct ___expression_a_handle_base___ : ___operation_a_handle_base___
	{
		virtual any_a<> recreate__(range_a<> const& range) const = 0;
		virtual expression_a<> recreate_() const = 0;
		virtual void recreated(expression_a < > const & expression ) const = 0;
		virtual any_a<> literal__(range_a<> const& range) const = 0;
		virtual any_a<> literal_() const = 0;
		virtual bool literal() const = 0;
		virtual any_a<> evaluate__(range_a<> const& range) const = 0;
		virtual any_a<> evaluate_() const = 0;
		virtual any_a<> token__(range_a<> const& range) const = 0;
		virtual token_a<> token_() const = 0;
		virtual any_a<> terms__(range_a<> const& range) const = 0;
		virtual flock_a<> terms_() const = 0;
		virtual any_a<> generate__(range_a<> const& range) const = 0;
		virtual any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const = 0;
		virtual void generate(int64_t version , int64_t indent , river_a < > & river ) const = 0;
		virtual any_a<> generate_cpp__(range_a<> const& range) const = 0;
		virtual any_a<> generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = strange::no() ) const = 0;
		virtual void generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type = false ) const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___expression_a_handle_base___>
	struct ___expression_a_handle___ : ___operation_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___expression_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___operation_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___expression_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___operation_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> recreate__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.recreate__(range); }

		virtual inline expression_a<> recreate_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.recreate_(); }

		virtual inline void recreated(expression_a < > const & expression ) const final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.recreated(expression); }

		virtual inline any_a<> literal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.literal__(range); }

		virtual inline any_a<> literal_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.literal_(); }

		virtual inline bool literal() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.literal(); }

		virtual inline any_a<> evaluate__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.evaluate__(range); }

		virtual inline any_a<> evaluate_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.evaluate_(); }

		virtual inline any_a<> token__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.token__(range); }

		virtual inline token_a<> token_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.token_(); }

		virtual inline any_a<> terms__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.terms__(range); }

		virtual inline flock_a<> terms_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.terms_(); }

		virtual inline any_a<> generate__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.generate__(range); }

		virtual inline any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.generate_(version, indent, river); }

		virtual inline void generate(int64_t version , int64_t indent , river_a < > & river ) const final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.generate(version, indent, river); }

		virtual inline any_a<> generate_cpp__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.generate_cpp__(range); }

		virtual inline any_a<> generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = strange::no() ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.generate_cpp_(version, indent, river, declare, define, type); }

		virtual inline void generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type = false ) const final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.generate_cpp(version, indent, river, declare, define, type); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___expression_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___expression_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___expression_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___expression_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___expression_a_handle_final___ final : ___expression_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___expression_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___expression_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___expression_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___expression_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___expression_a_handle_final___>(___expression_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___expression_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___expression_a_handle_final___<___TTT___&>
	{
		inline ___expression_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___expression_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___expression_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___expression_a_handle_base___ const>(handle_);
	}

	inline ___expression_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___expression_a_handle_base___>(handle_);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(expression_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___expression_a_handle_base___>(handle));
	}

	static inline expression_a val(expression_a const& other) noexcept
	{
		return expression_a{ other };
	}

	static inline expression_a ref(expression_a& other) noexcept
	{
		return expression_a(other, ___reference_tag___{});
	}

	static inline expression_a dup(expression_a& other) noexcept
	{
		return expression_a(other, ___duplicate_tag___{});
	}

	inline expression_a() = default;

	inline expression_a(expression_a& other, ___reference_tag___) noexcept
		: operation_a(other, ___reference_tag___{})
	{}

	inline expression_a(expression_a& other, ___duplicate_tag___) noexcept
		: operation_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline expression_a(std::shared_ptr<___TTT___> const& handle)
		: operation_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___expression_a_handle_base___>(handle))
		{
			throw dis("expression_a constructor failed to cast from base to expression_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline expression_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: operation_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___expression_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline expression_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: operation_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___expression_a_handle_base___>(handle))
		{
			throw dis("expression_a constructor failed to cast from base to expression_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline expression_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: operation_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___expression_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<expression_a, std::decay_t<___TTT___>>::value>>
	explicit inline expression_a(___TTT___ value) noexcept
		: operation_a{ std::make_shared<___expression_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline expression_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___expression_a_handle_base___>(handle))
		{
			throw dis("expression_a assignment failed to cast from base to expression_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline expression_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___expression_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<expression_a, std::decay_t<___TTT___>>::value>>
	inline expression_a& operator=(___TTT___ value) noexcept
	{
		expression_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___expression_a_share___;
}; // class expression_a

template <typename ___TTT___, typename _1__chk>
inline bool check(expression_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const expression_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<expression_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class expression_d : public operation_d<>
{
public:
	// arithmetic operator overloads
	inline expression_d& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline expression_d operator++(int)
	{
		assert(handle_);
		expression_d result = *this;
		write().operator++();
		return result;
	}
#endif

	inline expression_d& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline expression_d operator--(int)
	{
		assert(handle_);
		expression_d result = *this;
		write().operator--();
		return result;
	}
#endif

	inline expression_d& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline expression_d& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline expression_d& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline expression_d& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline expression_d& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> recreate__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("recreate_");
		if (!op)
		{
			throw dis("dynamic expression_d::recreate_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline expression_a<> recreate_() const
	{
		assert(handle_);
		auto const op = operation("recreate_");
		if (!op)
		{
			throw dis("dynamic expression_d::recreate_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline void recreated(expression_a < > const & expression ) const
	{ throw dis("dynamic expression_d::recreated(expression) not available"); }

	inline any_a<> literal__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("literal_");
		if (!op)
		{
			throw dis("dynamic expression_d::literal_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline any_a<> literal_() const
	{
		assert(handle_);
		auto const op = operation("literal_");
		if (!op)
		{
			throw dis("dynamic expression_d::literal_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline bool literal() const
	{ throw dis("dynamic expression_d::literal() not available"); }

	inline any_a<> evaluate__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("evaluate_");
		if (!op)
		{
			throw dis("dynamic expression_d::evaluate_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline any_a<> evaluate_() const
	{
		assert(handle_);
		auto const op = operation("evaluate_");
		if (!op)
		{
			throw dis("dynamic expression_d::evaluate_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline any_a<> token__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("token_");
		if (!op)
		{
			throw dis("dynamic expression_d::token_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline token_a<> token_() const
	{
		assert(handle_);
		auto const op = operation("token_");
		if (!op)
		{
			throw dis("dynamic expression_d::token_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline any_a<> terms__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("terms_");
		if (!op)
		{
			throw dis("dynamic expression_d::terms_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline flock_a<> terms_() const
	{
		assert(handle_);
		auto const op = operation("terms_");
		if (!op)
		{
			throw dis("dynamic expression_d::terms_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this));
	}

	inline any_a<> generate__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("generate_");
		if (!op)
		{
			throw dis("dynamic expression_d::generate_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const
	{
		assert(handle_);
		auto const op = operation("generate_");
		if (!op)
		{
			throw dis("dynamic expression_d::generate_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this), version, indent, river);
	}

	inline void generate(int64_t version , int64_t indent , river_a < > & river ) const
	{ throw dis("dynamic expression_d::generate(version, indent, river) not available"); }

	inline any_a<> generate_cpp__(range_a<> const& range) const
	{
		assert(handle_);
		auto const op = operation("generate_cpp_");
		if (!op)
		{
			throw dis("dynamic expression_d::generate_cpp_ passed non-existent member");
		}
		return op.operate(const_cast<any_a<>&>(*this), range);
	}

	inline any_a<> generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = strange::no() ) const
	{
		assert(handle_);
		auto const op = operation("generate_cpp_");
		if (!op)
		{
			throw dis("dynamic expression_d::generate_cpp_ passed non-existent member");
		}
		return variadic_operate(op, const_cast<any_a<>&>(*this), version, indent, river, declare, define, type);
	}

	inline void generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type = false ) const
	{ throw dis("dynamic expression_d::generate_cpp(version, indent, river, declare, define, type) not available"); }

	explicit expression_d(any_a<> const& thing)
		: operation_d{ thing }
	{}
};

template <typename _1_>
inline expression_d<_1_> ___expression_dynamic___(any_a<> const& thing)
{
	return expression_d<_1_>{ thing };
}

} // namespace
