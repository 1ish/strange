
namespace strange
{

template <typename ___TTT___, typename _1_ = void>
inline bool check(token_a<_1_> const& value) noexcept;

template <typename _1_>
class token_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline token_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

	inline token_a operator++(int)
	{
		assert(handle_);
		token_a result = *this;
		write().operator++();
		return result;
	}

	inline token_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

	inline token_a operator--(int)
	{
		assert(handle_);
		token_a result = *this;
		write().operator--();
		return result;
	}

	inline token_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline token_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline token_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline token_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline token_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> filename__(range_a<> const& range) const
	{ assert(handle_); return read().filename__(range); }

	inline symbol_a<> filename_() const
	{ assert(handle_); return read().filename_(); }

	inline std :: string filename() const
	{ assert(handle_); return read().filename(); }

	inline any_a<> line__(range_a<> const& range) const
	{ assert(handle_); return read().line__(range); }

	inline number_data_int64_a<> line_() const
	{ assert(handle_); return read().line_(); }

	inline int64_t line() const
	{ assert(handle_); return read().line(); }

	inline any_a<> position__(range_a<> const& range) const
	{ assert(handle_); return read().position__(range); }

	inline number_data_int64_a<> position_() const
	{ assert(handle_); return read().position_(); }

	inline int64_t position() const
	{ assert(handle_); return read().position(); }

	inline any_a<> tag__(range_a<> const& range) const
	{ assert(handle_); return read().tag__(range); }

	inline symbol_a<> tag_() const
	{ assert(handle_); return read().tag_(); }

	inline std :: string tag() const
	{ assert(handle_); return read().tag(); }

	inline any_a<> symbol__(range_a<> const& range) const
	{ assert(handle_); return read().symbol__(range); }

	inline symbol_a<> symbol_() const
	{ assert(handle_); return read().symbol_(); }

	inline std :: string symbol() const
	{ assert(handle_); return read().symbol(); }

	inline any_a<> literal__(range_a<> const& range) const
	{ assert(handle_); return read().literal__(range); }

	inline any_a<> literal_() const
	{ assert(handle_); return read().literal_(); }

	inline any_a<> precedence__(range_a<> const& range) const
	{ assert(handle_); return read().precedence__(range); }

	inline number_data_int64_a<> precedence_() const
	{ assert(handle_); return read().precedence_(); }

	inline int64_t precedence() const
	{ assert(handle_); return read().precedence(); }

	inline any_a<> report__(range_a<> const& range) const
	{ assert(handle_); return read().report__(range); }

	inline misunderstanding_a<> report_() const
	{ assert(handle_); return read().report_(); }

	inline std :: string report() const
	{ assert(handle_); return read().report(); }

protected:
	struct ___token_a_handle_base___ : ___any_a_handle_base___
	{
		virtual inline any_a<> filename__(range_a<> const& range) const = 0;
		virtual inline symbol_a<> filename_() const = 0;
		virtual inline std :: string filename() const = 0;
		virtual inline any_a<> line__(range_a<> const& range) const = 0;
		virtual inline number_data_int64_a<> line_() const = 0;
		virtual inline int64_t line() const = 0;
		virtual inline any_a<> position__(range_a<> const& range) const = 0;
		virtual inline number_data_int64_a<> position_() const = 0;
		virtual inline int64_t position() const = 0;
		virtual inline any_a<> tag__(range_a<> const& range) const = 0;
		virtual inline symbol_a<> tag_() const = 0;
		virtual inline std :: string tag() const = 0;
		virtual inline any_a<> symbol__(range_a<> const& range) const = 0;
		virtual inline symbol_a<> symbol_() const = 0;
		virtual inline std :: string symbol() const = 0;
		virtual inline any_a<> literal__(range_a<> const& range) const = 0;
		virtual inline any_a<> literal_() const = 0;
		virtual inline any_a<> precedence__(range_a<> const& range) const = 0;
		virtual inline number_data_int64_a<> precedence_() const = 0;
		virtual inline int64_t precedence() const = 0;
		virtual inline any_a<> report__(range_a<> const& range) const = 0;
		virtual inline misunderstanding_a<> report_() const = 0;
		virtual inline std :: string report() const = 0;
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

		virtual inline any_a<> filename__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.filename__(range); }

		virtual inline symbol_a<> filename_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.filename_(); }

		virtual inline std :: string filename() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.filename(); }

		virtual inline any_a<> line__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.line__(range); }

		virtual inline number_data_int64_a<> line_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.line_(); }

		virtual inline int64_t line() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.line(); }

		virtual inline any_a<> position__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.position__(range); }

		virtual inline number_data_int64_a<> position_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.position_(); }

		virtual inline int64_t position() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.position(); }

		virtual inline any_a<> tag__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.tag__(range); }

		virtual inline symbol_a<> tag_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.tag_(); }

		virtual inline std :: string tag() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.tag(); }

		virtual inline any_a<> symbol__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.symbol__(range); }

		virtual inline symbol_a<> symbol_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.symbol_(); }

		virtual inline std :: string symbol() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.symbol(); }

		virtual inline any_a<> literal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.literal__(range); }

		virtual inline any_a<> literal_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.literal_(); }

		virtual inline any_a<> precedence__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.precedence__(range); }

		virtual inline number_data_int64_a<> precedence_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.precedence_(); }

		virtual inline int64_t precedence() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.precedence(); }

		virtual inline any_a<> report__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.report__(range); }

		virtual inline misunderstanding_a<> report_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.report_(); }

		virtual inline std :: string report() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.report(); }

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

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___token_a_handle_final___>(___token_a_handle___<___TTT___>::value_);
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

	inline ___token_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___token_a_handle_base___ const>(handle_);
	}

	inline ___token_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___token_a_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename _1_>
	friend inline bool check(token_a<_1_> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___token_a_handle_base___>(handle));
	}

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

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline token_a(std::shared_ptr<___TTT___> const& handle)
		: any_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___token_a_handle_base___>(handle))
		{
			throw dis("token_a constructor failed to cast from base to token_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline token_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___token_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline token_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: any_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___token_a_handle_base___>(handle))
		{
			throw dis("token_a constructor failed to cast from base to token_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline token_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___token_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<token_a, std::decay_t<___TTT___>>::value>>
	explicit inline token_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___token_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline token_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___token_a_handle_base___>(handle))
		{
			throw dis("token_a assignment failed to cast from base to token_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline token_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___token_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<token_a, std::decay_t<___TTT___>>::value>>
	inline token_a& operator=(___TTT___ value) noexcept
	{
		token_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___token_a_share___;
}; // class token_a

template <typename ___TTT___, typename _1_>
inline bool check(token_a<_1_> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const token_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<token_a<_1_>>::share(shoal);
	return shoal;
}();

} // namespace
