
namespace strange
{

template <typename _1 = void>
class cat_d;

template <typename _1 = void>
inline cat_d<_1> ___cat_dynamic___(any_a<> const& thing); 

template <typename _1>
class cat_a : public symbol_a<>
{
public:
	inline any_a<> symbolic__(range_a<> const& ___arguments___) const;

	inline any_a<> symbolic_() const;

	inline bool symbolic() const;

	inline any_a<> order__(range_a<> const& ___arguments___) const;

	inline number_data_int64_a<> order_() const;

	inline int64_t order() const;

	inline any_a<> name__(range_a<> const& ___arguments___) const;

	inline symbol_a<> name_() const;

	inline std :: string name() const;

	inline any_a<> dimensions__(range_a<> const& ___arguments___) const;

	inline flock_a<> dimensions_() const;

	inline any_a<> parameters__(range_a<> const& ___arguments___) const;

	inline flock_a<> parameters_() const;

	inline any_a<> result__(range_a<> const& ___arguments___) const;

	inline cat_a<> result_() const;

	inline any_a<> code__(range_a<> const& ___arguments___) const;

	inline lake_int8_a<> code_() const;

	inline std :: string code() const;

protected:
	struct ___cat_a_handle_base___ : symbol_a<>::___symbol_a_handle_base___
	{
		virtual any_a<> symbolic_() const = 0;
		virtual bool symbolic() const = 0;
		virtual number_data_int64_a<> order_() const = 0;
		virtual int64_t order() const = 0;
		virtual symbol_a<> name_() const = 0;
		virtual std :: string name() const = 0;
		virtual flock_a<> dimensions_() const = 0;
		virtual flock_a<> parameters_() const = 0;
		virtual cat_a<> result_() const = 0;
		virtual lake_int8_a<> code_() const = 0;
		virtual std :: string code() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___cat_a_handle_base___>
	struct ___cat_a_handle___ : symbol_a<>::template ___symbol_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___cat_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: symbol_a<>::template ___symbol_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___cat_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: symbol_a<>::template ___symbol_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___cat_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: symbol_a<>::template ___symbol_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> symbolic_() const final;

		virtual inline bool symbolic() const final;

		virtual inline number_data_int64_a<> order_() const final;

		virtual inline int64_t order() const final;

		virtual inline symbol_a<> name_() const final;

		virtual inline std :: string name() const final;

		virtual inline flock_a<> dimensions_() const final;

		virtual inline flock_a<> parameters_() const final;

		virtual inline cat_a<> result_() const final;

		virtual inline lake_int8_a<> code_() const final;

		virtual inline std :: string code() const final;

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

		template <typename... Args>
		inline ___cat_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___cat_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
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
	inline ___cat_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___cat_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___cat_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___cat_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline cat_a val(cat_a const& other) noexcept
	{
		return cat_a{ other };
	}

	static inline cat_a ref(cat_a& other) noexcept
	{
		return cat_a(other, any_a<>::___reference_tag___{});
	}

	static inline cat_a dup(cat_a& other) noexcept
	{
		return cat_a(other, any_a<>::___duplicate_tag___{});
	}

	inline cat_a() = default;

	inline cat_a(cat_a& other, any_a<>::___reference_tag___) noexcept
		: symbol_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline cat_a(cat_a& other, any_a<>::___duplicate_tag___) noexcept
		: symbol_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline cat_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: symbol_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___cat_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline cat_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: symbol_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___cat_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_a, std::decay_t<___TTT___>>::value>>
	explicit inline cat_a(___TTT___ value) noexcept
		: symbol_a<>{ std::make_shared<___cat_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline cat_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: symbol_a<>{ std::make_shared<___cat_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline cat_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___cat_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<cat_a, std::decay_t<___TTT___>>::value>>
	inline cat_a& operator=(___TTT___ value) noexcept
	{
		cat_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___cat_a_handle_base___>(thing.___handle___) };
	}

	static inline cat_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___cat_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return cat_a{ thing.___handle___ };
		}
		return cat_a{ cat_d<_1>{ thing } };
	}

	static inline cat_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___cat_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return cat_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return cat_a{ cat_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::cat");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = symbol_a<>::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>());
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = symbol_a<>::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline cat_a create(Args&&... args)
	{
		return cat_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class cat_a

template <typename _1>
class cat_d : public symbol_d<>
{
public:
	inline any_a<> symbolic__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("symbolic_");
		if (!op)
		{
			throw dis("dynamic cat_d::symbolic_ passed non-existent member");
		}
		return op.operate(*const_cast<cat_d*>(this), arguments);
	}

	inline any_a<> symbolic_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("symbolic_");
		if (!op)
		{
			throw dis("dynamic cat_d::symbolic_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<cat_d*>(this)));
	}

	inline bool symbolic() const
	{ return symbolic_(); }

	inline any_a<> order__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("order_");
		if (!op)
		{
			throw dis("dynamic cat_d::order_ passed non-existent member");
		}
		return op.operate(*const_cast<cat_d*>(this), arguments);
	}

	inline number_data_int64_a<> order_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("order_");
		if (!op)
		{
			throw dis("dynamic cat_d::order_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<cat_d*>(this)));
	}

	inline int64_t order() const
	{ return order_().to_int_64(); }

	inline any_a<> name__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("name_");
		if (!op)
		{
			throw dis("dynamic cat_d::name_ passed non-existent member");
		}
		return op.operate(*const_cast<cat_d*>(this), arguments);
	}

	inline symbol_a<> name_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("name_");
		if (!op)
		{
			throw dis("dynamic cat_d::name_ passed non-existent member");
		}
		return cast<symbol_a<>>(variadic_operate(op, *const_cast<cat_d*>(this)));
	}

	inline std :: string name() const
	{ return name_().to_string(); }

	inline any_a<> dimensions__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("dimensions_");
		if (!op)
		{
			throw dis("dynamic cat_d::dimensions_ passed non-existent member");
		}
		return op.operate(*const_cast<cat_d*>(this), arguments);
	}

	inline flock_a<> dimensions_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("dimensions_");
		if (!op)
		{
			throw dis("dynamic cat_d::dimensions_ passed non-existent member");
		}
		return cast<flock_a<>>(variadic_operate(op, *const_cast<cat_d*>(this)));
	}

	inline any_a<> parameters__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("parameters_");
		if (!op)
		{
			throw dis("dynamic cat_d::parameters_ passed non-existent member");
		}
		return op.operate(*const_cast<cat_d*>(this), arguments);
	}

	inline flock_a<> parameters_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("parameters_");
		if (!op)
		{
			throw dis("dynamic cat_d::parameters_ passed non-existent member");
		}
		return cast<flock_a<>>(variadic_operate(op, *const_cast<cat_d*>(this)));
	}

	inline any_a<> result__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("result_");
		if (!op)
		{
			throw dis("dynamic cat_d::result_ passed non-existent member");
		}
		return op.operate(*const_cast<cat_d*>(this), arguments);
	}

	inline cat_a<> result_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("result_");
		if (!op)
		{
			throw dis("dynamic cat_d::result_ passed non-existent member");
		}
		return cast<cat_a<>>(variadic_operate(op, *const_cast<cat_d*>(this)));
	}

	inline any_a<> code__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("code_");
		if (!op)
		{
			throw dis("dynamic cat_d::code_ passed non-existent member");
		}
		return op.operate(*const_cast<cat_d*>(this), arguments);
	}

	inline lake_int8_a<> code_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("code_");
		if (!op)
		{
			throw dis("dynamic cat_d::code_ passed non-existent member");
		}
		return cast<lake_int8_a<>>(variadic_operate(op, *const_cast<cat_d*>(this)));
	}

	inline std :: string code() const
	{ return lake_to_string(code_()); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit cat_d(any_a<> const& thing)
		: symbol_d<>{ thing }
	{}

	explicit cat_d(any_a<>& thing, any_a<>::___reference_tag___)
		: symbol_d<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit cat_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: symbol_d<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
