
namespace strange
{

template <typename _1 = void>
class token_d;

template <typename _1 = void>
inline token_d<_1> ___token_dynamic___(any_a<> const& thing);

template <typename _1>
class token_a : public any_a<>
{
public:
	inline any_a<> filename__(list_a<> const& ___arguments___) const;

	inline symbol_a<> filename_() const;

	inline std_string filename() const;

	inline any_a<> line__(list_a<> const& ___arguments___) const;

	inline number_data_int64_a<> line_() const;

	inline int64_t line() const;

	inline any_a<> position__(list_a<> const& ___arguments___) const;

	inline number_data_int64_a<> position_() const;

	inline int64_t position() const;

	inline any_a<> tag__(list_a<> const& ___arguments___) const;

	inline symbol_a<> tag_() const;

	inline std_string tag() const;

	inline any_a<> symbol__(list_a<> const& ___arguments___) const;

	inline symbol_a<> symbol_() const;

	inline std_string symbol() const;

	inline any_a<> literal__(list_a<> const& ___arguments___) const;

	inline any_a<> literal_() const;

	inline bool literal() const;

	inline any_a<> precedence__(list_a<> const& ___arguments___) const;

	inline number_data_int64_a<> precedence_() const;

	inline int64_t precedence() const;

	inline any_a<> report__(list_a<> const& ___arguments___) const;

	inline misunderstanding_a<> report_() const;

	inline std_string report() const;

protected:
	struct ___token_a_handle_base___ : any_a<>::___any_a_handle_base___
	{
		virtual symbol_a<> filename_() const = 0;
		virtual std_string filename() const = 0;
		virtual number_data_int64_a<> line_() const = 0;
		virtual int64_t line() const = 0;
		virtual number_data_int64_a<> position_() const = 0;
		virtual int64_t position() const = 0;
		virtual symbol_a<> tag_() const = 0;
		virtual std_string tag() const = 0;
		virtual symbol_a<> symbol_() const = 0;
		virtual std_string symbol() const = 0;
		virtual any_a<> literal_() const = 0;
		virtual bool literal() const = 0;
		virtual number_data_int64_a<> precedence_() const = 0;
		virtual int64_t precedence() const = 0;
		virtual misunderstanding_a<> report_() const = 0;
		virtual std_string report() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___token_a_handle_base___>
	struct ___token_a_handle___ : any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___token_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___token_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___token_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline symbol_a<> filename_() const final;

		virtual inline std_string filename() const final;

		virtual inline number_data_int64_a<> line_() const final;

		virtual inline int64_t line() const final;

		virtual inline number_data_int64_a<> position_() const final;

		virtual inline int64_t position() const final;

		virtual inline symbol_a<> tag_() const final;

		virtual inline std_string tag() const final;

		virtual inline symbol_a<> symbol_() const final;

		virtual inline std_string symbol() const final;

		virtual inline any_a<> literal_() const final;

		virtual inline bool literal() const final;

		virtual inline number_data_int64_a<> precedence_() const final;

		virtual inline int64_t precedence() const final;

		virtual inline misunderstanding_a<> report_() const final;

		virtual inline std_string report() const final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___token_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___token_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___token_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___token_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___token_a_handle_final___ final : ___token_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___token_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___token_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___token_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___token_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___token_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___token_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___token_a_handle_final___>(___token_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___token_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___token_a_handle_final___<___TTT___&>
	{
		inline ___token_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___token_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___token_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___token_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___token_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___token_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline token_a val(token_a const& other) noexcept
	{
		return token_a{ other };
	}

	static inline token_a ref(token_a& other) noexcept
	{
		return token_a(other, any_a<>::___reference_tag___{});
	}

	static inline token_a dup(token_a& other) noexcept
	{
		return token_a(other, any_a<>::___duplicate_tag___{});
	}

	inline token_a() = default;

	inline token_a(token_a& other, any_a<>::___reference_tag___) noexcept
		: any_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline token_a(token_a& other, any_a<>::___duplicate_tag___) noexcept
		: any_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline token_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: any_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___token_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline token_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: any_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___token_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<token_a, std::decay_t<___TTT___>>::value>>
	explicit inline token_a(___TTT___ value) noexcept
		: any_a<>{ std_make_shared<___token_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline token_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a<>{ std_make_shared<___token_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline token_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___token_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<token_a, std::decay_t<___TTT___>>::value>>
	inline token_a& operator=(___TTT___ value) noexcept
	{
		token_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___token_a_handle_base___>(thing.___handle___) };
	}

	static inline token_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___token_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return token_a{ thing.___handle___ };
		}
		return token_a{ token_d<_1>{ thing } };
	}

	static inline token_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___token_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return token_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return token_a{ token_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	static inline cat_a<> ___cat___();

	static inline unordered_herd_a<> ___cats___();

	static inline kind_a<> ___kind___();

	static inline unordered_herd_a<> ___kinds___();

	static inline unordered_shoal_a<> ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline token_a create(Args&&... args)
	{
		return token_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class token_a

template <typename _1>
class token_d : public any_a<>
{
public:
	inline any_a<> filename__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("filename_");
		if (!op)
		{
			throw dis("dynamic token_d::filename_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), arguments);
	}

	inline symbol_a<> filename_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("filename_");
		if (!op)
		{
			throw dis("dynamic token_d::filename_ passed non-existent member");
		}
		return cast<symbol_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline std_string filename() const
	{ return filename_().to_string(); }

	inline any_a<> line__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("line_");
		if (!op)
		{
			throw dis("dynamic token_d::line_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), arguments);
	}

	inline number_data_int64_a<> line_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("line_");
		if (!op)
		{
			throw dis("dynamic token_d::line_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline int64_t line() const
	{ return line_().extract_primitive(); }

	inline any_a<> position__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("position_");
		if (!op)
		{
			throw dis("dynamic token_d::position_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), arguments);
	}

	inline number_data_int64_a<> position_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("position_");
		if (!op)
		{
			throw dis("dynamic token_d::position_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline int64_t position() const
	{ return position_().extract_primitive(); }

	inline any_a<> tag__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("tag_");
		if (!op)
		{
			throw dis("dynamic token_d::tag_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), arguments);
	}

	inline symbol_a<> tag_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("tag_");
		if (!op)
		{
			throw dis("dynamic token_d::tag_ passed non-existent member");
		}
		return cast<symbol_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline std_string tag() const
	{ return tag_().to_string(); }

	inline any_a<> symbol__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("symbol_");
		if (!op)
		{
			throw dis("dynamic token_d::symbol_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), arguments);
	}

	inline symbol_a<> symbol_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("symbol_");
		if (!op)
		{
			throw dis("dynamic token_d::symbol_ passed non-existent member");
		}
		return cast<symbol_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline std_string symbol() const
	{ return symbol_().to_string(); }

	inline any_a<> literal__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("literal_");
		if (!op)
		{
			throw dis("dynamic token_d::literal_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), arguments);
	}

	inline any_a<> literal_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("literal_");
		if (!op)
		{
			throw dis("dynamic token_d::literal_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline bool literal() const
	{ return literal_(); }

	inline any_a<> precedence__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("precedence_");
		if (!op)
		{
			throw dis("dynamic token_d::precedence_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), arguments);
	}

	inline number_data_int64_a<> precedence_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("precedence_");
		if (!op)
		{
			throw dis("dynamic token_d::precedence_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline int64_t precedence() const
	{ return precedence_().extract_primitive(); }

	inline any_a<> report__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("report_");
		if (!op)
		{
			throw dis("dynamic token_d::report_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), arguments);
	}

	inline misunderstanding_a<> report_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("report_");
		if (!op)
		{
			throw dis("dynamic token_d::report_ passed non-existent member");
		}
		return cast<misunderstanding_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline std_string report() const
	{ return report_().to_string(); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit token_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit token_d(any_a<>& thing, any_a<>::___reference_tag___)
		: any_a<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit token_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: any_a<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
