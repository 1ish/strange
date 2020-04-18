
namespace strange
{

template <typename _element = any_a<> >
class unordered_herd_d;

template <typename _element = any_a<> >
inline unordered_herd_d<_element> ___unordered_herd_dynamic___(any_a<> const& thing); 

template <typename _element>
class unordered_herd_a : public herd_a< _element >
{
public:
	inline bool operator==(unordered_herd_a < _element > const & herd ) const;

	inline bool operator!=(unordered_herd_a < _element > const & herd ) const;

	inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > extract_begin() const;

	inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > extract_end() const;

	inline std_unordered_set < _element > const & extract_set() const;

	inline std_unordered_set < _element > & mutate_set();

protected:
	struct ___unordered_herd_a_handle_base___ : herd_a< _element >::___herd_a_handle_base___
	{
		virtual bool operator==(unordered_herd_a < _element > const & herd ) const = 0;
		virtual bool operator!=(unordered_herd_a < _element > const & herd ) const = 0;
		virtual forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > extract_begin() const = 0;
		virtual forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > extract_end() const = 0;
		virtual std_unordered_set < _element > const & extract_set() const = 0;
		virtual std_unordered_set < _element > & mutate_set() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___unordered_herd_a_handle_base___>
	struct ___unordered_herd_a_handle___ : herd_a< _element >::template ___herd_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_herd_a_handle___(___TTT___ value, typename std_enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: herd_a< _element >::template ___herd_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_herd_a_handle___(___TTT___ value, typename std_enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: herd_a< _element >::template ___herd_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___unordered_herd_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: herd_a< _element >::template ___herd_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(unordered_herd_a < _element > const & herd ) const final;

		virtual inline bool operator!=(unordered_herd_a < _element > const & herd ) const final;

		virtual inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > extract_begin() const final;

		virtual inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > extract_end() const final;

		virtual inline std_unordered_set < _element > const & extract_set() const final;

		virtual inline std_unordered_set < _element > & mutate_set() final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___unordered_herd_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___unordered_herd_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___unordered_herd_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___unordered_herd_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___unordered_herd_a_handle_final___ final : ___unordered_herd_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_herd_a_handle_final___(___TTT___ value, typename std_enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___unordered_herd_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_herd_a_handle_final___(___TTT___ value, typename std_enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___unordered_herd_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___unordered_herd_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___unordered_herd_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___unordered_herd_a_handle_final___>(___unordered_herd_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___unordered_herd_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___unordered_herd_a_handle_final___<___TTT___&>
	{
		inline ___unordered_herd_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___unordered_herd_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___unordered_herd_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___unordered_herd_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___unordered_herd_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___unordered_herd_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline unordered_herd_a val(unordered_herd_a const& other) noexcept
	{
		return unordered_herd_a{ other };
	}

	static inline unordered_herd_a ref(unordered_herd_a& other) noexcept
	{
		return unordered_herd_a(other, any_a<>::___reference_tag___{});
	}

	static inline unordered_herd_a dup(unordered_herd_a& other) noexcept
	{
		return unordered_herd_a(other, any_a<>::___duplicate_tag___{});
	}

	inline unordered_herd_a() = default;

	inline unordered_herd_a(unordered_herd_a& other, any_a<>::___reference_tag___) noexcept
		: herd_a< _element >(other, any_a<>::___reference_tag___{})
	{}

	inline unordered_herd_a(unordered_herd_a& other, any_a<>::___duplicate_tag___) noexcept
		: herd_a< _element >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline unordered_herd_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: herd_a< _element >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline unordered_herd_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: herd_a< _element >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std_enable_if_t<!std::is_base_of<unordered_herd_a, std::decay_t<___TTT___>>::value>>
	explicit inline unordered_herd_a(___TTT___ value) noexcept
		: herd_a< _element >{ std::make_shared<___unordered_herd_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline unordered_herd_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: herd_a< _element >{ std::make_shared<___unordered_herd_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline unordered_herd_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std_enable_if_t<!std::is_base_of<unordered_herd_a, std::decay_t<___TTT___>>::value>>
	inline unordered_herd_a& operator=(___TTT___ value) noexcept
	{
		unordered_herd_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(thing.___handle___) };
	}

	static inline unordered_herd_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return unordered_herd_a{ thing.___handle___ };
		}
		return unordered_herd_a{ unordered_herd_d<_element>{ thing } };
	}

	static inline unordered_herd_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___unordered_herd_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return unordered_herd_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return unordered_herd_a{ unordered_herd_d<_element>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::unordered_herd");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = herd_a< _element >::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = herd_a< _element >::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline unordered_herd_a create(Args&&... args)
	{
		return unordered_herd_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class unordered_herd_a

template <typename _element>
class unordered_herd_d : public herd_d< _element >
{
public:
	inline bool operator==(unordered_herd_a < _element > const & herd ) const
	{ throw dis("dynamic unordered_herd_d::operator==(herd) not available"); }

	inline bool operator!=(unordered_herd_a < _element > const & herd ) const
	{ throw dis("dynamic unordered_herd_d::operator!=(herd) not available"); }

	inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > extract_begin() const
	{ throw dis("dynamic unordered_herd_d::extract_begin() not available"); }

	inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > extract_end() const
	{ throw dis("dynamic unordered_herd_d::extract_end() not available"); }

	inline std_unordered_set < _element > const & extract_set() const
	{ throw dis("dynamic unordered_herd_d::extract_set() not available"); }

	inline std_unordered_set < _element > & mutate_set()
	{ throw dis("dynamic unordered_herd_d::mutate_set() not available"); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit unordered_herd_d(any_a<> const& thing)
		: herd_d< _element >{ thing }
	{}

	explicit unordered_herd_d(any_a<>& thing, any_a<>::___reference_tag___)
		: herd_d< _element >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit unordered_herd_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: herd_d< _element >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
