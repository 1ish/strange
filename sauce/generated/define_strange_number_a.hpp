
namespace strange
{

template <typename _number_data_int64 = number_data_int64_a<> , typename _number_data_uint64 = number_data_uint64_a<> , typename _number_data_double = number_data_double_a<> >
class number_d;

template <typename _number_data_int64 = number_data_int64_a<> , typename _number_data_uint64 = number_data_uint64_a<> , typename _number_data_double = number_data_double_a<> >
inline number_d<_number_data_int64, _number_data_uint64, _number_data_double> ___number_dynamic___(any_a<> const& thing); 

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
class number_a : public any_a<>
{
public:
	inline any_a<> increment__(list_a<> const& ___arguments___);

	inline number_a increment_();

	inline number_a& operator++();

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline number_a operator++(int);
#endif

	inline any_a<> decrement__(list_a<> const& ___arguments___);

	inline number_a decrement_();

	inline number_a& operator--();

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline number_a operator--(int);
#endif

	inline any_a<> self_assign__(list_a<> const& ___arguments___);

	inline number_a self_assign_(number_a<> const& number);

	inline any_a<> self_add__(list_a<> const& ___arguments___);

	inline number_a self_add_(number_a<> const& number);

	inline number_a& operator+=(number_a<> const& number);

	inline any_a<> add__(list_a<> const& ___arguments___) const;

	inline number_a<> add_(number_a<> const& number) const;

	inline number_a<> operator+(number_a<> const& number) const;

	inline any_a<> self_subtract__(list_a<> const& ___arguments___);

	inline number_a self_subtract_(number_a<> const& number);

	inline number_a& operator-=(number_a<> const& number);

	inline any_a<> subtract__(list_a<> const& ___arguments___) const;

	inline number_a<> subtract_(number_a<> const& number) const;

	inline number_a<> operator-(number_a<> const& number) const;

	inline any_a<> self_multiply__(list_a<> const& ___arguments___);

	inline number_a self_multiply_(number_a<> const& number);

	inline number_a& operator*=(number_a<> const& number);

	inline any_a<> multiply__(list_a<> const& ___arguments___) const;

	inline number_a<> multiply_(number_a<> const& number) const;

	inline number_a<> operator*(number_a<> const& number) const;

	inline any_a<> self_divide__(list_a<> const& ___arguments___);

	inline number_a self_divide_(number_a<> const& number);

	inline number_a& operator/=(number_a<> const& number);

	inline any_a<> divide__(list_a<> const& ___arguments___) const;

	inline number_a<> divide_(number_a<> const& number) const;

	inline number_a<> operator/(number_a<> const& number) const;

	inline any_a<> self_modulo__(list_a<> const& ___arguments___);

	inline number_a self_modulo_(number_a<> const& number);

	inline number_a& operator%=(number_a<> const& number);

	inline any_a<> modulo__(list_a<> const& ___arguments___) const;

	inline number_a<> modulo_(number_a<> const& number) const;

	inline number_a<> operator%(number_a<> const& number) const;

	inline any_a<> to_int_64__(list_a<> const& ___arguments___) const;

	inline _number_data_int64 to_int_64_() const;

	inline int64_t to_int_64() const;

	inline any_a<> from_int_64__(list_a<> const& ___arguments___);

	inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_int_64_(_number_data_int64 const& int_64);

	inline void from_int_64(int64_t int_64 );

	inline any_a<> to_uint_64__(list_a<> const& ___arguments___) const;

	inline _number_data_uint64 to_uint_64_() const;

	inline uint64_t to_uint_64() const;

	inline any_a<> from_uint_64__(list_a<> const& ___arguments___);

	inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_uint_64_(_number_data_uint64 const& uint_64);

	inline void from_uint_64(uint64_t uint_64 );

	inline any_a<> to_float_64__(list_a<> const& ___arguments___) const;

	inline _number_data_double to_float_64_() const;

	inline double to_float_64() const;

	inline any_a<> from_float_64__(list_a<> const& ___arguments___);

	inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_float_64_(_number_data_double const& float_64);

	inline void from_float_64(double float_64 );

	inline any_a<> byte_size__(list_a<> const& ___arguments___) const;

	inline _number_data_int64 byte_size_() const;

	inline int64_t byte_size() const;

	inline any_a<> is_int__(list_a<> const& ___arguments___) const;

	inline any_a<> is_int_() const;

	inline bool is_int() const;

	inline any_a<> is_signed__(list_a<> const& ___arguments___) const;

	inline any_a<> is_signed_() const;

	inline bool is_signed() const;

	inline any_a<> is_nan__(list_a<> const& ___arguments___) const;

	inline any_a<> is_nan_() const;

	inline bool is_nan() const;

	inline any_a<> is_inf__(list_a<> const& ___arguments___) const;

	inline any_a<> is_inf_() const;

	inline bool is_inf() const;

	inline any_a<> is_finite__(list_a<> const& ___arguments___) const;

	inline any_a<> is_finite_() const;

	inline bool is_finite() const;

	inline any_a<> is_normal__(list_a<> const& ___arguments___) const;

	inline any_a<> is_normal_() const;

	inline bool is_normal() const;

	inline any_a<> little_endian__(list_a<> const& ___arguments___) const;

	inline any_a<> little_endian_() const;

	inline bool little_endian() const;

protected:
	struct ___number_a_handle_base___ : any_a<>::___any_a_handle_base___
	{
		virtual void increment_() = 0;
		virtual void decrement_() = 0;
		virtual void self_assign_(number_a<> const& number) = 0;
		virtual void self_add_(number_a<> const& number) = 0;
		virtual number_a<> add_(number_a<> const& number) const = 0;
		virtual void self_subtract_(number_a<> const& number) = 0;
		virtual number_a<> subtract_(number_a<> const& number) const = 0;
		virtual void self_multiply_(number_a<> const& number) = 0;
		virtual number_a<> multiply_(number_a<> const& number) const = 0;
		virtual void self_divide_(number_a<> const& number) = 0;
		virtual number_a<> divide_(number_a<> const& number) const = 0;
		virtual void self_modulo_(number_a<> const& number) = 0;
		virtual number_a<> modulo_(number_a<> const& number) const = 0;
		virtual _number_data_int64 to_int_64_() const = 0;
		virtual int64_t to_int_64() const = 0;
		virtual number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_int_64_(_number_data_int64 const& int_64) = 0;
		virtual void from_int_64(int64_t int_64 ) = 0;
		virtual _number_data_uint64 to_uint_64_() const = 0;
		virtual uint64_t to_uint_64() const = 0;
		virtual number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_uint_64_(_number_data_uint64 const& uint_64) = 0;
		virtual void from_uint_64(uint64_t uint_64 ) = 0;
		virtual _number_data_double to_float_64_() const = 0;
		virtual double to_float_64() const = 0;
		virtual number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_float_64_(_number_data_double const& float_64) = 0;
		virtual void from_float_64(double float_64 ) = 0;
		virtual _number_data_int64 byte_size_() const = 0;
		virtual int64_t byte_size() const = 0;
		virtual any_a<> is_int_() const = 0;
		virtual bool is_int() const = 0;
		virtual any_a<> is_signed_() const = 0;
		virtual bool is_signed() const = 0;
		virtual any_a<> is_nan_() const = 0;
		virtual bool is_nan() const = 0;
		virtual any_a<> is_inf_() const = 0;
		virtual bool is_inf() const = 0;
		virtual any_a<> is_finite_() const = 0;
		virtual bool is_finite() const = 0;
		virtual any_a<> is_normal_() const = 0;
		virtual bool is_normal() const = 0;
		virtual any_a<> little_endian_() const = 0;
		virtual bool little_endian() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___number_a_handle_base___>
	struct ___number_a_handle___ : any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___number_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___number_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___number_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline void increment_() final;

		virtual inline void decrement_() final;

		virtual inline void self_assign_(number_a<> const& number) final;

		virtual inline void self_add_(number_a<> const& number) final;

		virtual inline number_a<> add_(number_a<> const& number) const final;

		virtual inline void self_subtract_(number_a<> const& number) final;

		virtual inline number_a<> subtract_(number_a<> const& number) const final;

		virtual inline void self_multiply_(number_a<> const& number) final;

		virtual inline number_a<> multiply_(number_a<> const& number) const final;

		virtual inline void self_divide_(number_a<> const& number) final;

		virtual inline number_a<> divide_(number_a<> const& number) const final;

		virtual inline void self_modulo_(number_a<> const& number) final;

		virtual inline number_a<> modulo_(number_a<> const& number) const final;

		virtual inline _number_data_int64 to_int_64_() const final;

		virtual inline int64_t to_int_64() const final;

		virtual inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_int_64_(_number_data_int64 const& int_64) final;

		virtual inline void from_int_64(int64_t int_64 ) final;

		virtual inline _number_data_uint64 to_uint_64_() const final;

		virtual inline uint64_t to_uint_64() const final;

		virtual inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_uint_64_(_number_data_uint64 const& uint_64) final;

		virtual inline void from_uint_64(uint64_t uint_64 ) final;

		virtual inline _number_data_double to_float_64_() const final;

		virtual inline double to_float_64() const final;

		virtual inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_float_64_(_number_data_double const& float_64) final;

		virtual inline void from_float_64(double float_64 ) final;

		virtual inline _number_data_int64 byte_size_() const final;

		virtual inline int64_t byte_size() const final;

		virtual inline any_a<> is_int_() const final;

		virtual inline bool is_int() const final;

		virtual inline any_a<> is_signed_() const final;

		virtual inline bool is_signed() const final;

		virtual inline any_a<> is_nan_() const final;

		virtual inline bool is_nan() const final;

		virtual inline any_a<> is_inf_() const final;

		virtual inline bool is_inf() const final;

		virtual inline any_a<> is_finite_() const final;

		virtual inline bool is_finite() const final;

		virtual inline any_a<> is_normal_() const final;

		virtual inline bool is_normal() const final;

		virtual inline any_a<> little_endian_() const final;

		virtual inline bool little_endian() const final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___number_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___number_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___number_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___number_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___number_a_handle_final___ final : ___number_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___number_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___number_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___number_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___number_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___number_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___number_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___number_a_handle_final___>(___number_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___number_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___number_a_handle_final___<___TTT___&>
	{
		inline ___number_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___number_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___number_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___number_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___number_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___number_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline number_a val(number_a const& other) noexcept
	{
		return number_a{ other };
	}

	static inline number_a ref(number_a& other) noexcept
	{
		return number_a(other, any_a<>::___reference_tag___{});
	}

	static inline number_a dup(number_a& other) noexcept
	{
		return number_a(other, any_a<>::___duplicate_tag___{});
	}

	inline number_a() = default;

	inline number_a(number_a& other, any_a<>::___reference_tag___) noexcept
		: any_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline number_a(number_a& other, any_a<>::___duplicate_tag___) noexcept
		: any_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline number_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: any_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___number_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline number_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: any_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___number_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_a, std::decay_t<___TTT___>>::value>>
	explicit inline number_a(___TTT___ value) noexcept
		: any_a<>{ std_make_shared<___number_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline number_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a<>{ std_make_shared<___number_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline number_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___number_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_a, std::decay_t<___TTT___>>::value>>
	inline number_a& operator=(___TTT___ value) noexcept
	{
		number_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___number_a_handle_base___>(thing.___handle___) };
	}

	static inline number_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___number_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return number_a{ thing.___handle___ };
		}
		return number_a{ number_d<_number_data_int64, _number_data_uint64, _number_data_double>{ thing } };
	}

	static inline number_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___number_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return number_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return number_a{ number_d<_number_data_int64, _number_data_uint64, _number_data_double>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::number");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = any_a<>::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = any_a<>::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline number_a create(Args&&... args)
	{
		return number_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class number_a

template <typename _number_data_int64, typename _number_data_uint64, typename _number_data_double>
class number_d : public any_a<>
{
public:
	inline any_a<> increment__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("increment_");
		if (!op)
		{
			throw dis("dynamic number_d::increment_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_a<> increment_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("increment_");
		if (!op)
		{
			throw dis("dynamic number_d::increment_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this));
	}

	inline any_a<> decrement__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("decrement_");
		if (!op)
		{
			throw dis("dynamic number_d::decrement_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_a<> decrement_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("decrement_");
		if (!op)
		{
			throw dis("dynamic number_d::decrement_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this));
	}

	inline any_a<> self_assign__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("self_assign_");
		if (!op)
		{
			throw dis("dynamic number_d::self_assign_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_a<> self_assign_(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("self_assign_");
		if (!op)
		{
			throw dis("dynamic number_d::self_assign_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> self_add__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("self_add_");
		if (!op)
		{
			throw dis("dynamic number_d::self_add_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_a<> self_add_(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("self_add_");
		if (!op)
		{
			throw dis("dynamic number_d::self_add_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> add__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("add_");
		if (!op)
		{
			throw dis("dynamic number_d::add_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline number_a<> add_(number_a<> const& number) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("add_");
		if (!op)
		{
			throw dis("dynamic number_d::add_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline any_a<> self_subtract__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic number_d::self_subtract_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_a<> self_subtract_(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic number_d::self_subtract_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> subtract__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("subtract_");
		if (!op)
		{
			throw dis("dynamic number_d::subtract_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline number_a<> subtract_(number_a<> const& number) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("subtract_");
		if (!op)
		{
			throw dis("dynamic number_d::subtract_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline any_a<> self_multiply__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("self_multiply_");
		if (!op)
		{
			throw dis("dynamic number_d::self_multiply_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_a<> self_multiply_(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("self_multiply_");
		if (!op)
		{
			throw dis("dynamic number_d::self_multiply_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> multiply__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("multiply_");
		if (!op)
		{
			throw dis("dynamic number_d::multiply_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline number_a<> multiply_(number_a<> const& number) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("multiply_");
		if (!op)
		{
			throw dis("dynamic number_d::multiply_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline any_a<> self_divide__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("self_divide_");
		if (!op)
		{
			throw dis("dynamic number_d::self_divide_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_a<> self_divide_(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("self_divide_");
		if (!op)
		{
			throw dis("dynamic number_d::self_divide_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> divide__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("divide_");
		if (!op)
		{
			throw dis("dynamic number_d::divide_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline number_a<> divide_(number_a<> const& number) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("divide_");
		if (!op)
		{
			throw dis("dynamic number_d::divide_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline any_a<> self_modulo__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("self_modulo_");
		if (!op)
		{
			throw dis("dynamic number_d::self_modulo_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_a<> self_modulo_(number_a<> const& number)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("self_modulo_");
		if (!op)
		{
			throw dis("dynamic number_d::self_modulo_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> modulo__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("modulo_");
		if (!op)
		{
			throw dis("dynamic number_d::modulo_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline number_a<> modulo_(number_a<> const& number) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("modulo_");
		if (!op)
		{
			throw dis("dynamic number_d::modulo_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline any_a<> to_int_64__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_int_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_int_64_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline _number_data_int64 to_int_64_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_int_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_int_64_ passed non-existent member");
		}
		return cast<_number_data_int64>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline int64_t to_int_64() const
	{ return to_int_64_().extract_primitive(); }

	inline any_a<> from_int_64__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("from_int_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_int_64_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_int_64_(_number_data_int64 const& int_64)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("from_int_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_int_64_ passed non-existent member");
		}
		return cast<number_a< _number_data_int64 , _number_data_uint64 , _number_data_double >>(variadic_operate(op, *this, int_64));
	}

	inline void from_int_64(int64_t int_64 )
	{ from_int_64_(num<int64_t, _number_data_int64>(int_64)); }

	inline any_a<> to_uint_64__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_uint_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_uint_64_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline _number_data_uint64 to_uint_64_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_uint_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_uint_64_ passed non-existent member");
		}
		return cast<_number_data_uint64>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline uint64_t to_uint_64() const
	{ return to_uint_64_().extract_primitive(); }

	inline any_a<> from_uint_64__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("from_uint_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_uint_64_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_uint_64_(_number_data_uint64 const& uint_64)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("from_uint_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_uint_64_ passed non-existent member");
		}
		return cast<number_a< _number_data_int64 , _number_data_uint64 , _number_data_double >>(variadic_operate(op, *this, uint_64));
	}

	inline void from_uint_64(uint64_t uint_64 )
	{ from_uint_64_(num<uint64_t, _number_data_uint64>(uint_64)); }

	inline any_a<> to_float_64__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_float_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_float_64_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline _number_data_double to_float_64_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_float_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_float_64_ passed non-existent member");
		}
		return cast<_number_data_double>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline double to_float_64() const
	{ return to_float_64_().extract_primitive(); }

	inline any_a<> from_float_64__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("from_float_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_float_64_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_a< _number_data_int64 , _number_data_uint64 , _number_data_double > from_float_64_(_number_data_double const& float_64)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("from_float_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_float_64_ passed non-existent member");
		}
		return cast<number_a< _number_data_int64 , _number_data_uint64 , _number_data_double >>(variadic_operate(op, *this, float_64));
	}

	inline void from_float_64(double float_64 )
	{ from_float_64_(num<double, _number_data_double>(float_64)); }

	inline any_a<> byte_size__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("byte_size_");
		if (!op)
		{
			throw dis("dynamic number_d::byte_size_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline _number_data_int64 byte_size_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("byte_size_");
		if (!op)
		{
			throw dis("dynamic number_d::byte_size_ passed non-existent member");
		}
		return cast<_number_data_int64>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline int64_t byte_size() const
	{ return byte_size_().extract_primitive(); }

	inline any_a<> is_int__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("is_int_");
		if (!op)
		{
			throw dis("dynamic number_d::is_int_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline any_a<> is_int_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("is_int_");
		if (!op)
		{
			throw dis("dynamic number_d::is_int_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_int() const
	{ return is_int_(); }

	inline any_a<> is_signed__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("is_signed_");
		if (!op)
		{
			throw dis("dynamic number_d::is_signed_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline any_a<> is_signed_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("is_signed_");
		if (!op)
		{
			throw dis("dynamic number_d::is_signed_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_signed() const
	{ return is_signed_(); }

	inline any_a<> is_nan__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("is_nan_");
		if (!op)
		{
			throw dis("dynamic number_d::is_nan_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline any_a<> is_nan_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("is_nan_");
		if (!op)
		{
			throw dis("dynamic number_d::is_nan_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_nan() const
	{ return is_nan_(); }

	inline any_a<> is_inf__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("is_inf_");
		if (!op)
		{
			throw dis("dynamic number_d::is_inf_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline any_a<> is_inf_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("is_inf_");
		if (!op)
		{
			throw dis("dynamic number_d::is_inf_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_inf() const
	{ return is_inf_(); }

	inline any_a<> is_finite__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("is_finite_");
		if (!op)
		{
			throw dis("dynamic number_d::is_finite_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline any_a<> is_finite_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("is_finite_");
		if (!op)
		{
			throw dis("dynamic number_d::is_finite_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_finite() const
	{ return is_finite_(); }

	inline any_a<> is_normal__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("is_normal_");
		if (!op)
		{
			throw dis("dynamic number_d::is_normal_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline any_a<> is_normal_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("is_normal_");
		if (!op)
		{
			throw dis("dynamic number_d::is_normal_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_normal() const
	{ return is_normal_(); }

	inline any_a<> little_endian__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("little_endian_");
		if (!op)
		{
			throw dis("dynamic number_d::little_endian_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), arguments);
	}

	inline any_a<> little_endian_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("little_endian_");
		if (!op)
		{
			throw dis("dynamic number_d::little_endian_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool little_endian() const
	{ return little_endian_(); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit number_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit number_d(any_a<>& thing, any_a<>::___reference_tag___)
		: any_a<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit number_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: any_a<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
