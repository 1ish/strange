
namespace strange
{

template <typename _element, typename _type>
class forward_extractor_data_d;

template <typename _element, typename _type>
inline forward_extractor_data_d<_element, _type> ___forward_extractor_data_dynamic___(any_a<> const& thing); 

template <typename _element, typename _type>
class forward_extractor_data_a : public forward_extractor_a< _element >
{
public:
	inline bool operator==(forward_extractor_data_a < _element , _type > const & it ) const;

	inline bool operator!=(forward_extractor_data_a < _element , _type > const & it ) const;

	inline _type const & extract_it() const;

	inline _type & mutate_it();

protected:
	struct ___forward_extractor_data_a_handle_base___ : forward_extractor_a< _element >::___forward_extractor_a_handle_base___
	{
		virtual bool operator==(forward_extractor_data_a < _element , _type > const & it ) const = 0;
		virtual bool operator!=(forward_extractor_data_a < _element , _type > const & it ) const = 0;
		virtual _type const & extract_it() const = 0;
		virtual _type & mutate_it() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___forward_extractor_data_a_handle_base___>
	struct ___forward_extractor_data_a_handle___ : forward_extractor_a< _element >::template ___forward_extractor_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___forward_extractor_data_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: forward_extractor_a< _element >::template ___forward_extractor_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___forward_extractor_data_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: forward_extractor_a< _element >::template ___forward_extractor_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___forward_extractor_data_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: forward_extractor_a< _element >::template ___forward_extractor_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(forward_extractor_data_a < _element , _type > const & it ) const final;

		virtual inline bool operator!=(forward_extractor_data_a < _element , _type > const & it ) const final;

		virtual inline _type const & extract_it() const final;

		virtual inline _type & mutate_it() final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___forward_extractor_data_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___forward_extractor_data_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___forward_extractor_data_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___forward_extractor_data_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___forward_extractor_data_a_handle_final___ final : ___forward_extractor_data_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___forward_extractor_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___forward_extractor_data_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___forward_extractor_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___forward_extractor_data_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___forward_extractor_data_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___forward_extractor_data_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___forward_extractor_data_a_handle_final___>(___forward_extractor_data_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___forward_extractor_data_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___forward_extractor_data_a_handle_final___<___TTT___&>
	{
		inline ___forward_extractor_data_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___forward_extractor_data_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___forward_extractor_data_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___forward_extractor_data_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___forward_extractor_data_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___forward_extractor_data_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline forward_extractor_data_a val(forward_extractor_data_a const& other) noexcept
	{
		return forward_extractor_data_a{ other };
	}

	static inline forward_extractor_data_a ref(forward_extractor_data_a& other) noexcept
	{
		return forward_extractor_data_a(other, any_a<>::___reference_tag___{});
	}

	static inline forward_extractor_data_a dup(forward_extractor_data_a& other) noexcept
	{
		return forward_extractor_data_a(other, any_a<>::___duplicate_tag___{});
	}

	inline forward_extractor_data_a() = default;

	inline forward_extractor_data_a(forward_extractor_data_a& other, any_a<>::___reference_tag___) noexcept
		: forward_extractor_a< _element >(other, any_a<>::___reference_tag___{})
	{}

	inline forward_extractor_data_a(forward_extractor_data_a& other, any_a<>::___duplicate_tag___) noexcept
		: forward_extractor_a< _element >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline forward_extractor_data_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: forward_extractor_a< _element >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_extractor_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline forward_extractor_data_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: forward_extractor_a< _element >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_extractor_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_extractor_data_a, std::decay_t<___TTT___>>::value>>
	explicit inline forward_extractor_data_a(___TTT___ value) noexcept
		: forward_extractor_a< _element >{ std::make_shared<___forward_extractor_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline forward_extractor_data_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: forward_extractor_a< _element >{ std::make_shared<___forward_extractor_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline forward_extractor_data_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___forward_extractor_data_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<forward_extractor_data_a, std::decay_t<___TTT___>>::value>>
	inline forward_extractor_data_a& operator=(___TTT___ value) noexcept
	{
		forward_extractor_data_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___forward_extractor_data_a_handle_base___>(thing.___handle___) };
	}

	static inline forward_extractor_data_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___forward_extractor_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return forward_extractor_data_a{ thing.___handle___ };
		}
		return forward_extractor_data_a{ forward_extractor_data_d<_element, _type>{ thing } };
	}

	static inline forward_extractor_data_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___forward_extractor_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return forward_extractor_data_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return forward_extractor_data_a{ forward_extractor_data_d<_element, _type>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::forward_extractor_data", flock_vals(kind_create<___kind_a___>(2, ""), kind_create<___kind_a___>(2, "")));
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = forward_extractor_a< _element >::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>(), flock_vals(kind_of<_element>(), kind_of<_type>()));
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = forward_extractor_a< _element >::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline forward_extractor_data_a create(Args&&... args)
	{
		return forward_extractor_data_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class forward_extractor_data_a

template <typename _element, typename _type>
class forward_extractor_data_d : public forward_extractor_d< _element >
{
public:
	inline bool operator==(forward_extractor_data_a < _element , _type > const & it ) const
	{ throw dis("dynamic forward_extractor_data_d::operator==(it) not available"); }

	inline bool operator!=(forward_extractor_data_a < _element , _type > const & it ) const
	{ throw dis("dynamic forward_extractor_data_d::operator!=(it) not available"); }

	inline _type const & extract_it() const
	{ throw dis("dynamic forward_extractor_data_d::extract_it() not available"); }

	inline _type & mutate_it()
	{ throw dis("dynamic forward_extractor_data_d::mutate_it() not available"); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit forward_extractor_data_d(any_a<> const& thing)
		: forward_extractor_d< _element >{ thing }
	{}

	explicit forward_extractor_data_d(any_a<>& thing, any_a<>::___reference_tag___)
		: forward_extractor_d< _element >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit forward_extractor_data_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: forward_extractor_d< _element >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
