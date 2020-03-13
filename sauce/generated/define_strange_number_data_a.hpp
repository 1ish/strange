
namespace strange
{

template <typename _1_>
class number_data_d;

template <typename _1_>
inline number_data_d<_1_> ___number_data_dynamic___(any_a<> const& thing); 

template <typename _1_>
class number_data_a : public number_a<>
{
public:
	inline bool operator==(number_data_a < _1_ > const & number ) const
	{ assert(___handle___); return ___read___().operator==(number); }

	inline bool operator!=(number_data_a < _1_ > const & number ) const
	{ assert(___handle___); return ___read___().operator!=(number); }

	inline bool operator<(number_data_a < _1_ > const & number ) const
	{ assert(___handle___); return ___read___().operator<(number); }

	inline bool operator>(number_data_a < _1_ > const & number ) const
	{ assert(___handle___); return ___read___().operator>(number); }

	inline bool operator<=(number_data_a < _1_ > const & number ) const
	{ assert(___handle___); return ___read___().operator<=(number); }

	inline bool operator>=(number_data_a < _1_ > const & number ) const
	{ assert(___handle___); return ___read___().operator>=(number); }

	inline _1_ const & extract_primitive() const
	{ assert(___handle___); return ___read___().extract_primitive(); }

	inline _1_ & mutate_primitive()
	{ assert(___handle___); return ___write___().mutate_primitive(); }

protected:
	struct ___number_data_a_handle_base___ : ___number_a_handle_base___
	{
		virtual bool operator==(number_data_a < _1_ > const & number ) const = 0;
		virtual bool operator!=(number_data_a < _1_ > const & number ) const = 0;
		virtual bool operator<(number_data_a < _1_ > const & number ) const = 0;
		virtual bool operator>(number_data_a < _1_ > const & number ) const = 0;
		virtual bool operator<=(number_data_a < _1_ > const & number ) const = 0;
		virtual bool operator>=(number_data_a < _1_ > const & number ) const = 0;
		virtual _1_ const & extract_primitive() const = 0;
		virtual _1_ & mutate_primitive() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___number_data_a_handle_base___>
	struct ___number_data_a_handle___ : ___number_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___number_data_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___number_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___number_data_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___number_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___number_data_a_handle___(___variadic_tag___, Args&&... args)
			: ___number_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(number_data_a < _1_ > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(number); }

		virtual inline bool operator!=(number_data_a < _1_ > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(number); }

		virtual inline bool operator<(number_data_a < _1_ > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(number); }

		virtual inline bool operator>(number_data_a < _1_ > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(number); }

		virtual inline bool operator<=(number_data_a < _1_ > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(number); }

		virtual inline bool operator>=(number_data_a < _1_ > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(number); }

		virtual inline _1_ const & extract_primitive() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_primitive(); }

		virtual inline _1_ & mutate_primitive() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_primitive(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___number_data_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___number_data_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___number_data_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___number_data_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___number_data_a_handle_final___ final : ___number_data_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___number_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___number_data_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___number_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___number_data_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___number_data_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___number_data_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___number_data_a_handle_final___>(___number_data_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___number_data_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___number_data_a_handle_final___<___TTT___&>
	{
		inline ___number_data_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___number_data_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___number_data_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___number_data_a_handle_base___ const>(___handle___);
	}

	inline ___number_data_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___number_data_a_handle_base___>(___handle___);
	}

public:
	static inline number_data_a val(number_data_a const& other) noexcept
	{
		return number_data_a{ other };
	}

	static inline number_data_a ref(number_data_a& other) noexcept
	{
		return number_data_a(other, ___reference_tag___{});
	}

	static inline number_data_a dup(number_data_a& other) noexcept
	{
		return number_data_a(other, ___duplicate_tag___{});
	}

	inline number_data_a() = default;

	inline number_data_a(number_data_a& other, ___reference_tag___) noexcept
		: number_a(other, ___reference_tag___{})
	{}

	inline number_data_a(number_data_a& other, ___duplicate_tag___) noexcept
		: number_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline number_data_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: number_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline number_data_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: number_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_data_a, std::decay_t<___TTT___>>::value>>
	explicit inline number_data_a(___TTT___ value) noexcept
		: number_a{ std::make_shared<___number_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline number_data_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: number_a{ std::make_shared<___number_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline number_data_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_data_a, std::decay_t<___TTT___>>::value>>
	inline number_data_a& operator=(___TTT___ value) noexcept
	{
		number_data_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___number_data_a_handle_base___>(thing.___handle___) };
	}

	static inline number_data_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___number_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return number_data_a{ thing.___handle___ };
		}
		return number_data_a{ number_data_d<_1_>{ thing } };
	}

	static inline number_data_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___number_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return number_data_a(thing.___handle___, ___reference_tag___{});
		}
		return number_data_a{ number_data_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::number_data", flock_vals(kind_create<___kind_a___>(2, "")));
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = number_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>(), flock_vals(kind_of<_1_>()));
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = number_a::___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___()
	{
		static ___unordered_shoal_a___ OPERATIONS = []()
		{
			___unordered_shoal_a___ operations = number_a::___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline number_data_a create(Args&&... args)
	{
		return number_data_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___number_data_a_share___;
}; // class number_data_a

template <typename _1_>
class number_data_d : public number_d<>
{
public:
	inline bool operator==(number_data_a < _1_ > const & number ) const
	{ return same_(number); }

	inline bool operator!=(number_data_a < _1_ > const & number ) const
	{ return different_(number); }

	inline bool operator<(number_data_a < _1_ > const & number ) const
	{ return less_than_(number); }

	inline bool operator>(number_data_a < _1_ > const & number ) const
	{ return greater_than_(number); }

	inline bool operator<=(number_data_a < _1_ > const & number ) const
	{ return less_or_equal_(number); }

	inline bool operator>=(number_data_a < _1_ > const & number ) const
	{ return greater_or_equal_(number); }

	inline _1_ const & extract_primitive() const
	{ throw dis("dynamic number_data_d::extract_primitive() not available"); }

	inline _1_ & mutate_primitive()
	{ throw dis("dynamic number_data_d::mutate_primitive() not available"); }

	void ___weak___(number_d<>::___WEAK___ const& weak) const {}

	explicit number_data_d(any_a<> const& thing)
		: number_d<>{ thing }
	{}

	explicit number_data_d(any_a<>& thing, ___reference_tag___)
		: number_d<>{ thing, ___reference_tag___{} }
	{}

	explicit number_data_d(any_a<>& thing, ___duplicate_tag___)
		: number_d<>{ thing, ___duplicate_tag___{} }
	{}
};

} // namespace
