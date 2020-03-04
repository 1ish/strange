
namespace strange
{

template <typename _1_ = void>
class token_d;

template <typename _1_ = void>
inline token_d<_1_> ___token_dynamic___(any_a<> const& thing); 

template <typename _1_>
class token_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline token_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline token_a operator++(int)
	{
		assert(___handle___);
		token_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline token_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline token_a operator--(int)
	{
		assert(___handle___);
		token_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline token_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline token_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline token_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline token_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline token_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> filename__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().filename__(range); }

	inline symbol_a<> filename_() const
	{ assert(___handle___); return ___read___().filename_(); }

	inline std :: string filename() const
	{ assert(___handle___); return ___read___().filename(); }

	inline any_a<> line__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().line__(range); }

	inline number_data_int64_a<> line_() const
	{ assert(___handle___); return ___read___().line_(); }

	inline int64_t line() const
	{ assert(___handle___); return ___read___().line(); }

	inline any_a<> position__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().position__(range); }

	inline number_data_int64_a<> position_() const
	{ assert(___handle___); return ___read___().position_(); }

	inline int64_t position() const
	{ assert(___handle___); return ___read___().position(); }

	inline any_a<> tag__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().tag__(range); }

	inline symbol_a<> tag_() const
	{ assert(___handle___); return ___read___().tag_(); }

	inline std :: string tag() const
	{ assert(___handle___); return ___read___().tag(); }

	inline any_a<> symbol__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().symbol__(range); }

	inline symbol_a<> symbol_() const
	{ assert(___handle___); return ___read___().symbol_(); }

	inline std :: string symbol() const
	{ assert(___handle___); return ___read___().symbol(); }

	inline any_a<> literal__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().literal__(range); }

	inline any_a<> literal_() const
	{ assert(___handle___); return ___read___().literal_(); }

	inline any_a<> precedence__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().precedence__(range); }

	inline number_data_int64_a<> precedence_() const
	{ assert(___handle___); return ___read___().precedence_(); }

	inline int64_t precedence() const
	{ assert(___handle___); return ___read___().precedence(); }

	inline any_a<> report__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().report__(range); }

	inline misunderstanding_a<> report_() const
	{ assert(___handle___); return ___read___().report_(); }

	inline std :: string report() const
	{ assert(___handle___); return ___read___().report(); }

protected:
	struct ___token_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> filename__(range_a<> const& range) const = 0;
		virtual symbol_a<> filename_() const = 0;
		virtual std :: string filename() const = 0;
		virtual any_a<> line__(range_a<> const& range) const = 0;
		virtual number_data_int64_a<> line_() const = 0;
		virtual int64_t line() const = 0;
		virtual any_a<> position__(range_a<> const& range) const = 0;
		virtual number_data_int64_a<> position_() const = 0;
		virtual int64_t position() const = 0;
		virtual any_a<> tag__(range_a<> const& range) const = 0;
		virtual symbol_a<> tag_() const = 0;
		virtual std :: string tag() const = 0;
		virtual any_a<> symbol__(range_a<> const& range) const = 0;
		virtual symbol_a<> symbol_() const = 0;
		virtual std :: string symbol() const = 0;
		virtual any_a<> literal__(range_a<> const& range) const = 0;
		virtual any_a<> literal_() const = 0;
		virtual any_a<> precedence__(range_a<> const& range) const = 0;
		virtual number_data_int64_a<> precedence_() const = 0;
		virtual int64_t precedence() const = 0;
		virtual any_a<> report__(range_a<> const& range) const = 0;
		virtual misunderstanding_a<> report_() const = 0;
		virtual std :: string report() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___token_a_handle_base___>
	struct ___token_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___token_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___token_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___token_a_handle___(___variadic_tag___, Args&&... args)
			: ___any_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> filename__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.filename__(range); }

		virtual inline symbol_a<> filename_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.filename_(); }

		virtual inline std :: string filename() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.filename(); }

		virtual inline any_a<> line__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.line__(range); }

		virtual inline number_data_int64_a<> line_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.line_(); }

		virtual inline int64_t line() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.line(); }

		virtual inline any_a<> position__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.position__(range); }

		virtual inline number_data_int64_a<> position_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.position_(); }

		virtual inline int64_t position() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.position(); }

		virtual inline any_a<> tag__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.tag__(range); }

		virtual inline symbol_a<> tag_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.tag_(); }

		virtual inline std :: string tag() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.tag(); }

		virtual inline any_a<> symbol__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.symbol__(range); }

		virtual inline symbol_a<> symbol_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.symbol_(); }

		virtual inline std :: string symbol() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.symbol(); }

		virtual inline any_a<> literal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.literal__(range); }

		virtual inline any_a<> literal_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.literal_(); }

		virtual inline any_a<> precedence__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.precedence__(range); }

		virtual inline number_data_int64_a<> precedence_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.precedence_(); }

		virtual inline int64_t precedence() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.precedence(); }

		virtual inline any_a<> report__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.report__(range); }

		virtual inline misunderstanding_a<> report_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.report_(); }

		virtual inline std :: string report() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.report(); }

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
		inline ___token_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___token_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___token_a_handle_final___>(___token_a_handle___<___TTT___>::___value___);
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
		return *std::static_pointer_cast<___token_a_handle_base___ const>(___handle___);
	}

	inline ___token_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___token_a_handle_base___>(___handle___);
	}

public:
	static inline token_a val(token_a const& other) noexcept
	{
		return token_a{ other };
	}

	static inline token_a ref(token_a& other) noexcept
	{
		return token_a(other, ___reference_tag___{});
	}

	static inline token_a dup(token_a& other) noexcept
	{
		return token_a(other, ___duplicate_tag___{});
	}

	inline token_a() = default;

	inline token_a(token_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline token_a(token_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline token_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___token_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline token_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___token_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<token_a, std::decay_t<___TTT___>>::value>>
	explicit inline token_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___token_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline token_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a{ std::make_shared<___token_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline token_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___token_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<token_a, std::decay_t<___TTT___>>::value>>
	inline token_a& operator=(___TTT___ value) noexcept
	{
		token_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
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
		return token_a{ token_d<_1_>{ thing } };
	}

	static inline token_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___token_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return token_a(thing.___handle___, ___reference_tag___{});
		}
		return token_a{ token_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	___cat_a___ ___cat___() const
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::token");
		return CAT;
	}

	template <typename ___TTT___, typename... Args>
	static inline token_a create(Args&&... args)
	{
		return token_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___token_a_share___;
}; // class token_a

template <typename _1_>
bool const token_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<token_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class token_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline token_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline token_d operator++(int)
	{
		assert(___handle___);
		token_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline token_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline token_d operator--(int)
	{
		assert(___handle___);
		token_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline token_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline token_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline token_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline token_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline token_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> filename__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("filename_");
		if (!op)
		{
			throw dis("dynamic token_d::filename_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), range);
	}

	inline symbol_a<> filename_() const
	{
		assert(___handle___);
		auto const op = operation("filename_");
		if (!op)
		{
			throw dis("dynamic token_d::filename_ passed non-existent member");
		}
		return cast<symbol_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline std :: string filename() const
	{ return filename_().to_string(); }

	inline any_a<> line__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("line_");
		if (!op)
		{
			throw dis("dynamic token_d::line_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), range);
	}

	inline number_data_int64_a<> line_() const
	{
		assert(___handle___);
		auto const op = operation("line_");
		if (!op)
		{
			throw dis("dynamic token_d::line_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline int64_t line() const
	{ return line_().extract_primitive(); }

	inline any_a<> position__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("position_");
		if (!op)
		{
			throw dis("dynamic token_d::position_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), range);
	}

	inline number_data_int64_a<> position_() const
	{
		assert(___handle___);
		auto const op = operation("position_");
		if (!op)
		{
			throw dis("dynamic token_d::position_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline int64_t position() const
	{ return position_().extract_primitive(); }

	inline any_a<> tag__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("tag_");
		if (!op)
		{
			throw dis("dynamic token_d::tag_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), range);
	}

	inline symbol_a<> tag_() const
	{
		assert(___handle___);
		auto const op = operation("tag_");
		if (!op)
		{
			throw dis("dynamic token_d::tag_ passed non-existent member");
		}
		return cast<symbol_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline std :: string tag() const
	{ return tag_().to_string(); }

	inline any_a<> symbol__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("symbol_");
		if (!op)
		{
			throw dis("dynamic token_d::symbol_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), range);
	}

	inline symbol_a<> symbol_() const
	{
		assert(___handle___);
		auto const op = operation("symbol_");
		if (!op)
		{
			throw dis("dynamic token_d::symbol_ passed non-existent member");
		}
		return cast<symbol_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline std :: string symbol() const
	{ return symbol_().to_string(); }

	inline any_a<> literal__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("literal_");
		if (!op)
		{
			throw dis("dynamic token_d::literal_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), range);
	}

	inline any_a<> literal_() const
	{
		assert(___handle___);
		auto const op = operation("literal_");
		if (!op)
		{
			throw dis("dynamic token_d::literal_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline any_a<> precedence__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("precedence_");
		if (!op)
		{
			throw dis("dynamic token_d::precedence_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), range);
	}

	inline number_data_int64_a<> precedence_() const
	{
		assert(___handle___);
		auto const op = operation("precedence_");
		if (!op)
		{
			throw dis("dynamic token_d::precedence_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline int64_t precedence() const
	{ return precedence_().extract_primitive(); }

	inline any_a<> report__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("report_");
		if (!op)
		{
			throw dis("dynamic token_d::report_ passed non-existent member");
		}
		return op.operate(*const_cast<token_d*>(this), range);
	}

	inline misunderstanding_a<> report_() const
	{
		assert(___handle___);
		auto const op = operation("report_");
		if (!op)
		{
			throw dis("dynamic token_d::report_ passed non-existent member");
		}
		return cast<misunderstanding_a<>>(variadic_operate(op, *const_cast<token_d*>(this)));
	}

	inline std :: string report() const
	{ return report_().to_string(); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit token_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit token_d(any_a<>& thing, ___reference_tag___)
		: any_a<>{ thing, ___reference_tag___{} }
	{}

	explicit token_d(any_a<>& thing, ___duplicate_tag___)
		: any_a<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename _1_>
inline token_d<_1_> ___token_dynamic___(any_a<> const& thing)
{
	return token_d<_1_>{ thing };
}

} // namespace
