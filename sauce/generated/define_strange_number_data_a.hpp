
namespace strange
{

template <typename _primitive>
class number_data_d;

template <typename _primitive>
inline number_data_d<_primitive> ___number_data_dynamic___(any_a<> const& thing); 

template <typename _primitive>
class number_data_a : public number_a<>
{
public:
	inline bool operator==(number_data_a < _primitive > const & number ) const
	{ assert(any_a<>::___handle___); return ___read___().operator==(number); }

	inline bool operator!=(number_data_a < _primitive > const & number ) const
	{ assert(any_a<>::___handle___); return ___read___().operator!=(number); }

	inline bool operator<(number_data_a < _primitive > const & number ) const
	{ assert(any_a<>::___handle___); return ___read___().operator<(number); }

	inline bool operator>(number_data_a < _primitive > const & number ) const
	{ assert(any_a<>::___handle___); return ___read___().operator>(number); }

	inline bool operator<=(number_data_a < _primitive > const & number ) const
	{ assert(any_a<>::___handle___); return ___read___().operator<=(number); }

	inline bool operator>=(number_data_a < _primitive > const & number ) const
	{ assert(any_a<>::___handle___); return ___read___().operator>=(number); }

	inline _primitive const & extract_primitive() const
	{ assert(any_a<>::___handle___); return ___read___().extract_primitive(); }

	inline _primitive & mutate_primitive()
	{ assert(any_a<>::___handle___); return ___write___().mutate_primitive(); }

protected:
	struct ___number_data_a_handle_base___ : number_a<>::template ___number_a_handle_base___
	{
		virtual bool operator==(number_data_a < _primitive > const & number ) const = 0;
		virtual bool operator!=(number_data_a < _primitive > const & number ) const = 0;
		virtual bool operator<(number_data_a < _primitive > const & number ) const = 0;
		virtual bool operator>(number_data_a < _primitive > const & number ) const = 0;
		virtual bool operator<=(number_data_a < _primitive > const & number ) const = 0;
		virtual bool operator>=(number_data_a < _primitive > const & number ) const = 0;
		virtual _primitive const & extract_primitive() const = 0;
		virtual _primitive & mutate_primitive() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___number_data_a_handle_base___>
	struct ___number_data_a_handle___ : number_a<>::template ___number_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___number_data_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: number_a<>::template ___number_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___number_data_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: number_a<>::template ___number_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___number_data_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: number_a<>::template ___number_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(number_data_a < _primitive > const & number ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(number); }

		virtual inline bool operator!=(number_data_a < _primitive > const & number ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(number); }

		virtual inline bool operator<(number_data_a < _primitive > const & number ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(number); }

		virtual inline bool operator>(number_data_a < _primitive > const & number ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(number); }

		virtual inline bool operator<=(number_data_a < _primitive > const & number ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(number); }

		virtual inline bool operator>=(number_data_a < _primitive > const & number ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(number); }

		virtual inline _primitive const & extract_primitive() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_primitive(); }

		virtual inline _primitive & mutate_primitive() final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_primitive(); }

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
		inline ___number_data_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___number_data_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
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
		return *std::static_pointer_cast<___number_data_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___number_data_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___number_data_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline number_data_a val(number_data_a const& other) noexcept
	{
		return number_data_a{ other };
	}

	static inline number_data_a ref(number_data_a& other) noexcept
	{
		return number_data_a(other, any_a<>::___reference_tag___{});
	}

	static inline number_data_a dup(number_data_a& other) noexcept
	{
		return number_data_a(other, any_a<>::___duplicate_tag___{});
	}

	inline number_data_a() = default;

	inline number_data_a(number_data_a& other, any_a<>::___reference_tag___) noexcept
		: number_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline number_data_a(number_data_a& other, any_a<>::___duplicate_tag___) noexcept
		: number_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline number_data_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: number_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline number_data_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: number_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_data_a, std::decay_t<___TTT___>>::value>>
	explicit inline number_data_a(___TTT___ value) noexcept
		: number_a<>{ std::make_shared<___number_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline number_data_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: number_a<>{ std::make_shared<___number_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline number_data_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___number_data_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_data_a, std::decay_t<___TTT___>>::value>>
	inline number_data_a& operator=(___TTT___ value) noexcept
	{
		number_data_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
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
		return number_data_a{ number_data_d<_primitive>{ thing } };
	}

	static inline number_data_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___number_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return number_data_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return number_data_a{ number_data_d<_primitive>(thing, any_a<>::___reference_tag___{}) };
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
			auto cats = number_a<>::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>(), flock_vals(kind_of<_primitive>()));
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = number_a<>::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = number_a<>::template ___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline number_data_a create(Args&&... args)
	{
		return number_data_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class number_data_a

template <typename _primitive>
class number_data_d : public number_d<>
{
public:
	inline bool operator==(number_data_a < _primitive > const & number ) const
	{ return same_(number); }

	inline bool operator!=(number_data_a < _primitive > const & number ) const
	{ return different_(number); }

	inline bool operator<(number_data_a < _primitive > const & number ) const
	{ return less_than_(number); }

	inline bool operator>(number_data_a < _primitive > const & number ) const
	{ return greater_than_(number); }

	inline bool operator<=(number_data_a < _primitive > const & number ) const
	{ return less_or_equal_(number); }

	inline bool operator>=(number_data_a < _primitive > const & number ) const
	{ return greater_or_equal_(number); }

	inline _primitive const & extract_primitive() const
	{ throw dis("dynamic number_data_d::extract_primitive() not available"); }

	inline _primitive & mutate_primitive()
	{ throw dis("dynamic number_data_d::mutate_primitive() not available"); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit number_data_d(any_a<> const& thing)
		: number_d<>{ thing }
	{}

	explicit number_data_d(any_a<>& thing, any_a<>::___reference_tag___)
		: number_d<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit number_data_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: number_d<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
