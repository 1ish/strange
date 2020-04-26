
namespace strange
{

template <typename _1 = void>
class expression_d;

template <typename _1 = void>
inline expression_d<_1> ___expression_dynamic___(any_a<> const& thing);

template <typename _1>
class expression_a : public operation_a<>
{
public:
	inline any_a<> recreate__(list_a<> const& ___arguments___) const;

	inline expression_a<> recreate_() const;

	inline any_a<> literal__(list_a<> const& ___arguments___) const;

	inline any_a<> literal_() const;

	inline bool literal() const;

	inline any_a<> evaluate__(list_a<> const& ___arguments___) const;

	inline any_a<> evaluate_() const;

	inline any_a<> token__(list_a<> const& ___arguments___) const;

	inline token_a<> token_() const;

	inline any_a<> terms__(list_a<> const& ___arguments___) const;

	inline flock_a<> terms_() const;

	inline any_a<> generate__(list_a<> const& ___arguments___) const;

	inline any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const;

	inline void generate(int64_t version , int64_t indent , river_a < > & river ) const;

	inline any_a<> generate_cpp__(list_a<> const& ___arguments___) const;

	inline any_a<> generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = strange::no() ) const;

	inline void generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type = false ) const;

protected:
	struct ___expression_a_handle_base___ : operation_a<>::___operation_a_handle_base___
	{
		virtual expression_a<> recreate_() const = 0;
		virtual any_a<> literal_() const = 0;
		virtual bool literal() const = 0;
		virtual any_a<> evaluate_() const = 0;
		virtual token_a<> token_() const = 0;
		virtual flock_a<> terms_() const = 0;
		virtual any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const = 0;
		virtual void generate(int64_t version , int64_t indent , river_a < > & river ) const = 0;
		virtual any_a<> generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = strange::no() ) const = 0;
		virtual void generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type = false ) const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___expression_a_handle_base___>
	struct ___expression_a_handle___ : operation_a<>::template ___operation_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___expression_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: operation_a<>::template ___operation_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___expression_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: operation_a<>::template ___operation_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___expression_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: operation_a<>::template ___operation_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline expression_a<> recreate_() const final;

		virtual inline any_a<> literal_() const final;

		virtual inline bool literal() const final;

		virtual inline any_a<> evaluate_() const final;

		virtual inline token_a<> token_() const final;

		virtual inline flock_a<> terms_() const final;

		virtual inline any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const final;

		virtual inline void generate(int64_t version , int64_t indent , river_a < > & river ) const final;

		virtual inline any_a<> generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = strange::no() ) const final;

		virtual inline void generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type = false ) const final;

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

		template <typename... Args>
		inline ___expression_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___expression_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___expression_a_handle_final___>(___expression_a_handle___<___TTT___>::___value___);
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
	inline ___expression_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___expression_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___expression_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___expression_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline expression_a val(expression_a const& other) noexcept
	{
		return expression_a{ other };
	}

	static inline expression_a ref(expression_a& other) noexcept
	{
		return expression_a(other, any_a<>::___reference_tag___{});
	}

	static inline expression_a dup(expression_a& other) noexcept
	{
		return expression_a(other, any_a<>::___duplicate_tag___{});
	}

	inline expression_a() = default;

	inline expression_a(expression_a& other, any_a<>::___reference_tag___) noexcept
		: operation_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline expression_a(expression_a& other, any_a<>::___duplicate_tag___) noexcept
		: operation_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline expression_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: operation_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___expression_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline expression_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: operation_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___expression_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<expression_a, std::decay_t<___TTT___>>::value>>
	explicit inline expression_a(___TTT___ value) noexcept
		: operation_a<>{ std_make_shared<___expression_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline expression_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: operation_a<>{ std_make_shared<___expression_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline expression_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___expression_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<expression_a, std::decay_t<___TTT___>>::value>>
	inline expression_a& operator=(___TTT___ value) noexcept
	{
		expression_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___expression_a_handle_base___>(thing.___handle___) };
	}

	static inline expression_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___expression_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return expression_a{ thing.___handle___ };
		}
		return expression_a{ expression_d<_1>{ thing } };
	}

	static inline expression_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___expression_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return expression_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return expression_a{ expression_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	static inline cat_a<> ___cat___();

	static inline unordered_herd_a<> ___cats___();

	static inline kind_a<> ___kind___();

	static inline unordered_herd_a<> ___kinds___();

	static inline unordered_shoal_a<> ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline expression_a create(Args&&... args)
	{
		return expression_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class expression_a

template <typename _1>
class expression_d : public operation_d<>
{
public:
	inline any_a<> recreate__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("recreate_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::recreate_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline expression_a<> recreate_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("recreate_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::recreate_ passed non-existent member");
		}
		return cast<expression_a<>>(variadic_operate(op, *const_cast<expression_d*>(this)));
	}

	inline any_a<> literal__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("literal_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::literal_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline any_a<> literal_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("literal_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::literal_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<expression_d*>(this)));
	}

	inline bool literal() const
	{ return literal_(); }

	inline any_a<> evaluate__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("evaluate_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::evaluate_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline any_a<> evaluate_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("evaluate_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::evaluate_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<expression_d*>(this)));
	}

	inline any_a<> token__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("token_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::token_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline token_a<> token_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("token_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::token_ passed non-existent member");
		}
		return cast<token_a<>>(variadic_operate(op, *const_cast<expression_d*>(this)));
	}

	inline any_a<> terms__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("terms_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::terms_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline flock_a<> terms_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("terms_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::terms_ passed non-existent member");
		}
		return cast<flock_a<>>(variadic_operate(op, *const_cast<expression_d*>(this)));
	}

	inline any_a<> generate__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("generate_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::generate_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("generate_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::generate_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<expression_d*>(this), version, indent, river));
	}

	inline void generate(int64_t version , int64_t indent , river_a < > & river ) const
	{ generate_(num(version), num(indent), river); }

	inline any_a<> generate_cpp__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("generate_cpp_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::generate_cpp_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline any_a<> generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = strange::no() ) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("generate_cpp_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic expression_d::generate_cpp_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<expression_d*>(this), version, indent, river, declare, define, type));
	}

	inline void generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type = false ) const
	{ generate_cpp_(num(version), num(indent), river, boole(declare), boole(define), boole(type)); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit expression_d(any_a<> const& thing)
		: operation_d<>{ thing }
	{}

	explicit expression_d(any_a<>& thing, any_a<>::___reference_tag___)
		: operation_d<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit expression_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: operation_d<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
