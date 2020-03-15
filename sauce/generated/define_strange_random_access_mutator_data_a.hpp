
namespace strange
{

template <typename _1_>
class random_access_mutator_data_d;

template <typename _1_>
inline random_access_mutator_data_d<_1_> ___random_access_mutator_data_dynamic___(any_a<> const& thing); 

template <typename _1_>
class random_access_mutator_data_a : public random_access_mutator_a<>
{
public:
	inline bool operator==(random_access_mutator_data_a < _1_ > const & it ) const
	{ assert(___handle___); return ___read___().operator==(it); }

	inline bool operator!=(random_access_mutator_data_a < _1_ > const & it ) const
	{ assert(___handle___); return ___read___().operator!=(it); }

	inline bool operator<(random_access_mutator_data_a < _1_ > const & it ) const
	{ assert(___handle___); return ___read___().operator<(it); }

	inline bool operator>(random_access_mutator_data_a < _1_ > const & it ) const
	{ assert(___handle___); return ___read___().operator>(it); }

	inline bool operator<=(random_access_mutator_data_a < _1_ > const & it ) const
	{ assert(___handle___); return ___read___().operator<=(it); }

	inline bool operator>=(random_access_mutator_data_a < _1_ > const & it ) const
	{ assert(___handle___); return ___read___().operator>=(it); }

	inline _1_ const & extract_it() const
	{ assert(___handle___); return ___read___().extract_it(); }

	inline _1_ & mutate_it()
	{ assert(___handle___); return ___write___().mutate_it(); }

protected:
	struct ___random_access_mutator_data_a_handle_base___ : ___random_access_mutator_a_handle_base___
	{
		virtual bool operator==(random_access_mutator_data_a < _1_ > const & it ) const = 0;
		virtual bool operator!=(random_access_mutator_data_a < _1_ > const & it ) const = 0;
		virtual bool operator<(random_access_mutator_data_a < _1_ > const & it ) const = 0;
		virtual bool operator>(random_access_mutator_data_a < _1_ > const & it ) const = 0;
		virtual bool operator<=(random_access_mutator_data_a < _1_ > const & it ) const = 0;
		virtual bool operator>=(random_access_mutator_data_a < _1_ > const & it ) const = 0;
		virtual _1_ const & extract_it() const = 0;
		virtual _1_ & mutate_it() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___random_access_mutator_data_a_handle_base___>
	struct ___random_access_mutator_data_a_handle___ : ___random_access_mutator_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_mutator_data_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___random_access_mutator_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_mutator_data_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___random_access_mutator_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___random_access_mutator_data_a_handle___(___variadic_tag___, Args&&... args)
			: ___random_access_mutator_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(random_access_mutator_data_a < _1_ > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(it); }

		virtual inline bool operator!=(random_access_mutator_data_a < _1_ > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(it); }

		virtual inline bool operator<(random_access_mutator_data_a < _1_ > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(it); }

		virtual inline bool operator>(random_access_mutator_data_a < _1_ > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(it); }

		virtual inline bool operator<=(random_access_mutator_data_a < _1_ > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(it); }

		virtual inline bool operator>=(random_access_mutator_data_a < _1_ > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(it); }

		virtual inline _1_ const & extract_it() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_it(); }

		virtual inline _1_ & mutate_it() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_it(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___random_access_mutator_data_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___random_access_mutator_data_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___random_access_mutator_data_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_mutator_data_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___random_access_mutator_data_a_handle_final___ final : ___random_access_mutator_data_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_mutator_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___random_access_mutator_data_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_mutator_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___random_access_mutator_data_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___random_access_mutator_data_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___random_access_mutator_data_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___random_access_mutator_data_a_handle_final___>(___random_access_mutator_data_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___random_access_mutator_data_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___random_access_mutator_data_a_handle_final___<___TTT___&>
	{
		inline ___random_access_mutator_data_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_mutator_data_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___random_access_mutator_data_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___random_access_mutator_data_a_handle_base___ const>(___handle___);
	}

	inline ___random_access_mutator_data_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___random_access_mutator_data_a_handle_base___>(___handle___);
	}

public:
	static inline random_access_mutator_data_a val(random_access_mutator_data_a const& other) noexcept
	{
		return random_access_mutator_data_a{ other };
	}

	static inline random_access_mutator_data_a ref(random_access_mutator_data_a& other) noexcept
	{
		return random_access_mutator_data_a(other, ___reference_tag___{});
	}

	static inline random_access_mutator_data_a dup(random_access_mutator_data_a& other) noexcept
	{
		return random_access_mutator_data_a(other, ___duplicate_tag___{});
	}

	inline random_access_mutator_data_a() = default;

	inline random_access_mutator_data_a(random_access_mutator_data_a& other, ___reference_tag___) noexcept
		: random_access_mutator_a(other, ___reference_tag___{})
	{}

	inline random_access_mutator_data_a(random_access_mutator_data_a& other, ___duplicate_tag___) noexcept
		: random_access_mutator_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline random_access_mutator_data_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: random_access_mutator_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_mutator_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline random_access_mutator_data_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: random_access_mutator_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_mutator_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_mutator_data_a, std::decay_t<___TTT___>>::value>>
	explicit inline random_access_mutator_data_a(___TTT___ value) noexcept
		: random_access_mutator_a{ std::make_shared<___random_access_mutator_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline random_access_mutator_data_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: random_access_mutator_a{ std::make_shared<___random_access_mutator_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline random_access_mutator_data_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_mutator_data_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_mutator_data_a, std::decay_t<___TTT___>>::value>>
	inline random_access_mutator_data_a& operator=(___TTT___ value) noexcept
	{
		random_access_mutator_data_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___random_access_mutator_data_a_handle_base___>(thing.___handle___) };
	}

	static inline random_access_mutator_data_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___random_access_mutator_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return random_access_mutator_data_a{ thing.___handle___ };
		}
		return random_access_mutator_data_a{ random_access_mutator_data_d<_1_>{ thing } };
	}

	static inline random_access_mutator_data_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___random_access_mutator_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return random_access_mutator_data_a(thing.___handle___, ___reference_tag___{});
		}
		return random_access_mutator_data_a{ random_access_mutator_data_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::random_access_mutator_data", flock_vals(kind_create<___kind_a___>(2, "")));
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = random_access_mutator_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = random_access_mutator_a::___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = random_access_mutator_a::___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline random_access_mutator_data_a create(Args&&... args)
	{
		return random_access_mutator_data_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class random_access_mutator_data_a

template <typename _1_>
class random_access_mutator_data_d : public random_access_mutator_d<>
{
public:
	inline bool operator==(random_access_mutator_data_a < _1_ > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator==(it) not available"); }

	inline bool operator!=(random_access_mutator_data_a < _1_ > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator!=(it) not available"); }

	inline bool operator<(random_access_mutator_data_a < _1_ > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator<(it) not available"); }

	inline bool operator>(random_access_mutator_data_a < _1_ > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator>(it) not available"); }

	inline bool operator<=(random_access_mutator_data_a < _1_ > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator<=(it) not available"); }

	inline bool operator>=(random_access_mutator_data_a < _1_ > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator>=(it) not available"); }

	inline _1_ const & extract_it() const
	{ throw dis("dynamic random_access_mutator_data_d::extract_it() not available"); }

	inline _1_ & mutate_it()
	{ throw dis("dynamic random_access_mutator_data_d::mutate_it() not available"); }

	void ___weak___(random_access_mutator_d<>::___WEAK___ const& weak) const {}

	explicit random_access_mutator_data_d(any_a<> const& thing)
		: random_access_mutator_d<>{ thing }
	{}

	explicit random_access_mutator_data_d(any_a<>& thing, ___reference_tag___)
		: random_access_mutator_d<>{ thing, ___reference_tag___{} }
	{}

	explicit random_access_mutator_data_d(any_a<>& thing, ___duplicate_tag___)
		: random_access_mutator_d<>{ thing, ___duplicate_tag___{} }
	{}
};

} // namespace
