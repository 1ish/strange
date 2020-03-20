
namespace strange
{

template <typename _type>
class data_d;

template <typename _type>
inline data_d<_type> ___data_dynamic___(any_a<> const& thing); 

template <typename _type>
class data_a : public any_a<>
{
public:
	inline bool operator==(data_a < _type > const & data ) const
	{ assert(any_a<>::___handle___); return ___read___().operator==(data); }

	inline bool operator!=(data_a < _type > const & data ) const
	{ assert(any_a<>::___handle___); return ___read___().operator!=(data); }

	inline _type const & extract_data() const
	{ assert(any_a<>::___handle___); return ___read___().extract_data(); }

	inline _type & mutate_data()
	{ assert(any_a<>::___handle___); return ___write___().mutate_data(); }

protected:
	struct ___data_a_handle_base___ : any_a<>::template ___any_a_handle_base___
	{
		virtual bool operator==(data_a < _type > const & data ) const = 0;
		virtual bool operator!=(data_a < _type > const & data ) const = 0;
		virtual _type const & extract_data() const = 0;
		virtual _type & mutate_data() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___data_a_handle_base___>
	struct ___data_a_handle___ : any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___data_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___data_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___data_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(data_a < _type > const & data ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(data); }

		virtual inline bool operator!=(data_a < _type > const & data ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(data); }

		virtual inline _type const & extract_data() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_data(); }

		virtual inline _type & mutate_data() final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_data(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___data_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___data_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___data_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___data_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___data_a_handle_final___ final : ___data_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___data_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___data_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___data_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___data_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___data_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___data_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___data_a_handle_final___>(___data_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___data_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___data_a_handle_final___<___TTT___&>
	{
		inline ___data_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___data_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___data_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___data_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___data_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___data_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline data_a val(data_a const& other) noexcept
	{
		return data_a{ other };
	}

	static inline data_a ref(data_a& other) noexcept
	{
		return data_a(other, any_a<>::___reference_tag___{});
	}

	static inline data_a dup(data_a& other) noexcept
	{
		return data_a(other, any_a<>::___duplicate_tag___{});
	}

	inline data_a() = default;

	inline data_a(data_a& other, any_a<>::___reference_tag___) noexcept
		: any_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline data_a(data_a& other, any_a<>::___duplicate_tag___) noexcept
		: any_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline data_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___data_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline data_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: any_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___data_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<data_a, std::decay_t<___TTT___>>::value>>
	explicit inline data_a(___TTT___ value) noexcept
		: any_a<>{ std::make_shared<___data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline data_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a<>{ std::make_shared<___data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline data_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___data_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<data_a, std::decay_t<___TTT___>>::value>>
	inline data_a& operator=(___TTT___ value) noexcept
	{
		data_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___data_a_handle_base___>(thing.___handle___) };
	}

	static inline data_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return data_a{ thing.___handle___ };
		}
		return data_a{ data_d<_type>{ thing } };
	}

	static inline data_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return data_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return data_a{ data_d<_type>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::data", flock_vals(kind_create<___kind_a___>(2, "")));
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
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>(), flock_vals(kind_of<_type>()));
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
	static inline ___unordered_shoal_a___ ___operations___()
	{
		static ___unordered_shoal_a___ OPERATIONS = []()
		{
			___unordered_shoal_a___ operations = any_a<>::template ___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline data_a create(Args&&... args)
	{
		return data_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class data_a

template <typename _type>
class data_d : public any_a<>
{
public:
	inline bool operator==(data_a < _type > const & data ) const
	{ throw dis("dynamic data_d::operator==(data) not available"); }

	inline bool operator!=(data_a < _type > const & data ) const
	{ throw dis("dynamic data_d::operator!=(data) not available"); }

	inline _type const & extract_data() const
	{ throw dis("dynamic data_d::extract_data() not available"); }

	inline _type & mutate_data()
	{ throw dis("dynamic data_d::mutate_data() not available"); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit data_d(any_a<> const& thing)
		: any_a{ thing }
	{}

	explicit data_d(any_a<>& thing, any_a<>::___reference_tag___)
		: any_a{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit data_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: any_a{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
