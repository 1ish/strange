
namespace strange
{

template <typename _1_ = void>
class expression_d;

template <typename _1_ = void>
inline expression_d<_1_> ___expression_dynamic___(any_a<> const& thing); 

template <typename _1_>
class expression_a : public operation_a<>
{
public:
	// arithmetic operator overloads
	inline expression_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline expression_a operator++(int)
	{
		assert(___handle___);
		expression_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline expression_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline expression_a operator--(int)
	{
		assert(___handle___);
		expression_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline expression_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline expression_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline expression_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline expression_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline expression_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> recreate__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().recreate__(arguments); }

	inline expression_a<> recreate_() const
	{ assert(___handle___); return ___read___().recreate_(); }

	inline void recreated(expression_a < > const & expression ) const
	{ assert(___handle___); ___read___().recreated(expression); }

	inline any_a<> literal__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().literal__(arguments); }

	inline any_a<> literal_() const
	{ assert(___handle___); return ___read___().literal_(); }

	inline bool literal() const
	{ assert(___handle___); return ___read___().literal(); }

	inline any_a<> evaluate__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().evaluate__(arguments); }

	inline any_a<> evaluate_() const
	{ assert(___handle___); return ___read___().evaluate_(); }

	inline any_a<> token__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().token__(arguments); }

	inline token_a<> token_() const
	{ assert(___handle___); return ___read___().token_(); }

	inline any_a<> terms__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().terms__(arguments); }

	inline flock_a<> terms_() const
	{ assert(___handle___); return ___read___().terms_(); }

	inline any_a<> generate__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().generate__(arguments); }

	inline any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const
	{ assert(___handle___); return ___read___().generate_(version, indent, river); }

	inline void generate(int64_t version , int64_t indent , river_a < > & river ) const
	{ assert(___handle___); ___read___().generate(version, indent, river); }

	inline any_a<> generate_cpp__(range_a<> const& arguments) const
	{ assert(___handle___); return ___read___().generate_cpp__(arguments); }

	inline any_a<> generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = strange::no() ) const
	{ assert(___handle___); return ___read___().generate_cpp_(version, indent, river, declare, define, type); }

	inline void generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type = false ) const
	{ assert(___handle___); ___read___().generate_cpp(version, indent, river, declare, define, type); }

protected:
	struct ___expression_a_handle_base___ : ___operation_a_handle_base___
	{
		virtual any_a<> recreate__(range_a<> const& arguments) const = 0;
		virtual expression_a<> recreate_() const = 0;
		virtual void recreated(expression_a < > const & expression ) const = 0;
		virtual any_a<> literal__(range_a<> const& arguments) const = 0;
		virtual any_a<> literal_() const = 0;
		virtual bool literal() const = 0;
		virtual any_a<> evaluate__(range_a<> const& arguments) const = 0;
		virtual any_a<> evaluate_() const = 0;
		virtual any_a<> token__(range_a<> const& arguments) const = 0;
		virtual token_a<> token_() const = 0;
		virtual any_a<> terms__(range_a<> const& arguments) const = 0;
		virtual flock_a<> terms_() const = 0;
		virtual any_a<> generate__(range_a<> const& arguments) const = 0;
		virtual any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const = 0;
		virtual void generate(int64_t version , int64_t indent , river_a < > & river ) const = 0;
		virtual any_a<> generate_cpp__(range_a<> const& arguments) const = 0;
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

		template <typename... Args>
		inline ___expression_a_handle___(___variadic_tag___, Args&&... args)
			: ___operation_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> recreate__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.recreate__(arguments); }

		virtual inline expression_a<> recreate_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.recreate_(); }

		virtual inline void recreated(expression_a < > const & expression ) const final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.recreated(expression); }

		virtual inline any_a<> literal__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.literal__(arguments); }

		virtual inline any_a<> literal_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.literal_(); }

		virtual inline bool literal() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.literal(); }

		virtual inline any_a<> evaluate__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.evaluate__(arguments); }

		virtual inline any_a<> evaluate_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.evaluate_(); }

		virtual inline any_a<> token__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.token__(arguments); }

		virtual inline token_a<> token_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.token_(); }

		virtual inline any_a<> terms__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.terms__(arguments); }

		virtual inline flock_a<> terms_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.terms_(); }

		virtual inline any_a<> generate__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.generate__(arguments); }

		virtual inline any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.generate_(version, indent, river); }

		virtual inline void generate(int64_t version , int64_t indent , river_a < > & river ) const final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.generate(version, indent, river); }

		virtual inline any_a<> generate_cpp__(range_a<> const& arguments) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.generate_cpp__(arguments); }

		virtual inline any_a<> generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = strange::no() ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.generate_cpp_(version, indent, river, declare, define, type); }

		virtual inline void generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type = false ) const final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.generate_cpp(version, indent, river, declare, define, type); }

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
		inline ___expression_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___expression_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___expression_a_handle_final___>(___expression_a_handle___<___TTT___>::___value___);
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
		return *std::static_pointer_cast<___expression_a_handle_base___ const>(___handle___);
	}

	inline ___expression_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___expression_a_handle_base___>(___handle___);
	}

public:
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

	template <typename ___TTT___>
	explicit inline expression_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: operation_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___expression_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline expression_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: operation_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___expression_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<expression_a, std::decay_t<___TTT___>>::value>>
	explicit inline expression_a(___TTT___ value) noexcept
		: operation_a{ std::make_shared<___expression_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline expression_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: operation_a{ std::make_shared<___expression_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline expression_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___expression_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<expression_a, std::decay_t<___TTT___>>::value>>
	inline expression_a& operator=(___TTT___ value) noexcept
	{
		expression_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
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
		return expression_a{ expression_d<_1_>{ thing } };
	}

	static inline expression_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___expression_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return expression_a(thing.___handle___, ___reference_tag___{});
		}
		return expression_a{ expression_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::expression");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = operation_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___TTT___, typename... Args>
	static inline expression_a create(Args&&... args)
	{
		return expression_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___expression_a_share___;
}; // class expression_a

template <typename _1_>
bool const expression_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<expression_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
class expression_d : public operation_d<>
{
public:
	// arithmetic operator overloads
	inline expression_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline expression_d operator++(int)
	{
		assert(___handle___);
		expression_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline expression_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline expression_d operator--(int)
	{
		assert(___handle___);
		expression_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline expression_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline expression_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline expression_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline expression_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline expression_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> recreate__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("recreate_");
		if (!op)
		{
			throw dis("dynamic expression_d::recreate_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline expression_a<> recreate_() const
	{
		assert(___handle___);
		auto const op = operation("recreate_");
		if (!op)
		{
			throw dis("dynamic expression_d::recreate_ passed non-existent member");
		}
		return cast<expression_a<>>(variadic_operate(op, *const_cast<expression_d*>(this)));
	}

	inline void recreated(expression_a < > const & expression ) const
	{}

	inline any_a<> literal__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("literal_");
		if (!op)
		{
			throw dis("dynamic expression_d::literal_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline any_a<> literal_() const
	{
		assert(___handle___);
		auto const op = operation("literal_");
		if (!op)
		{
			throw dis("dynamic expression_d::literal_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<expression_d*>(this)));
	}

	inline bool literal() const
	{ return literal_(); }

	inline any_a<> evaluate__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("evaluate_");
		if (!op)
		{
			throw dis("dynamic expression_d::evaluate_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline any_a<> evaluate_() const
	{
		assert(___handle___);
		auto const op = operation("evaluate_");
		if (!op)
		{
			throw dis("dynamic expression_d::evaluate_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<expression_d*>(this)));
	}

	inline any_a<> token__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("token_");
		if (!op)
		{
			throw dis("dynamic expression_d::token_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline token_a<> token_() const
	{
		assert(___handle___);
		auto const op = operation("token_");
		if (!op)
		{
			throw dis("dynamic expression_d::token_ passed non-existent member");
		}
		return cast<token_a<>>(variadic_operate(op, *const_cast<expression_d*>(this)));
	}

	inline any_a<> terms__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("terms_");
		if (!op)
		{
			throw dis("dynamic expression_d::terms_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline flock_a<> terms_() const
	{
		assert(___handle___);
		auto const op = operation("terms_");
		if (!op)
		{
			throw dis("dynamic expression_d::terms_ passed non-existent member");
		}
		return cast<flock_a<>>(variadic_operate(op, *const_cast<expression_d*>(this)));
	}

	inline any_a<> generate__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("generate_");
		if (!op)
		{
			throw dis("dynamic expression_d::generate_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline any_a<> generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const
	{
		assert(___handle___);
		auto const op = operation("generate_");
		if (!op)
		{
			throw dis("dynamic expression_d::generate_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<expression_d*>(this), version, indent, river));
	}

	inline void generate(int64_t version , int64_t indent , river_a < > & river ) const
	{ generate_(num(version), num(indent), river); }

	inline any_a<> generate_cpp__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("generate_cpp_");
		if (!op)
		{
			throw dis("dynamic expression_d::generate_cpp_ passed non-existent member");
		}
		return op.operate(*const_cast<expression_d*>(this), arguments);
	}

	inline any_a<> generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = strange::no() ) const
	{
		assert(___handle___);
		auto const op = operation("generate_cpp_");
		if (!op)
		{
			throw dis("dynamic expression_d::generate_cpp_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<expression_d*>(this), version, indent, river, declare, define, type));
	}

	inline void generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type = false ) const
	{ generate_cpp_(num(version), num(indent), river, boole(declare), boole(define), boole(type)); }

	void ___weak___(operation_d<>::___WEAK___ const& weak) const {}

	explicit expression_d(any_a<> const& thing)
		: operation_d<>{ thing }
	{}

	explicit expression_d(any_a<>& thing, ___reference_tag___)
		: operation_d<>{ thing, ___reference_tag___{} }
	{}

	explicit expression_d(any_a<>& thing, ___duplicate_tag___)
		: operation_d<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline expression_d<_1_> ___expression_dynamic___(any_a<> const& thing)
{
	return expression_d<_1_>{ thing };
}

} // namespace
