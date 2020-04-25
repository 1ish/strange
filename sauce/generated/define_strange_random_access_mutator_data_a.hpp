
namespace strange
{

template <typename _element, typename _type>
class random_access_mutator_data_d;

template <typename _element, typename _type>
inline random_access_mutator_data_d<_element, _type> ___random_access_mutator_data_dynamic___(any_a<> const& thing);

template <typename _element, typename _type>
class random_access_mutator_data_a : public random_access_mutator_a< _element >
{
public:
	inline bool operator==(random_access_mutator_data_a < _element , _type > const & it ) const;

	inline bool operator!=(random_access_mutator_data_a < _element , _type > const & it ) const;

	inline bool operator<(random_access_mutator_data_a < _element , _type > const & it ) const;

	inline bool operator>(random_access_mutator_data_a < _element , _type > const & it ) const;

	inline bool operator<=(random_access_mutator_data_a < _element , _type > const & it ) const;

	inline bool operator>=(random_access_mutator_data_a < _element , _type > const & it ) const;

	inline _type const & extract_it() const;

	inline _type & mutate_it();

protected:
	struct ___random_access_mutator_data_a_handle_base___ : random_access_mutator_a< _element >::___random_access_mutator_a_handle_base___
	{
		virtual bool operator==(random_access_mutator_data_a < _element , _type > const & it ) const = 0;
		virtual bool operator!=(random_access_mutator_data_a < _element , _type > const & it ) const = 0;
		virtual bool operator<(random_access_mutator_data_a < _element , _type > const & it ) const = 0;
		virtual bool operator>(random_access_mutator_data_a < _element , _type > const & it ) const = 0;
		virtual bool operator<=(random_access_mutator_data_a < _element , _type > const & it ) const = 0;
		virtual bool operator>=(random_access_mutator_data_a < _element , _type > const & it ) const = 0;
		virtual _type const & extract_it() const = 0;
		virtual _type & mutate_it() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___random_access_mutator_data_a_handle_base___>
	struct ___random_access_mutator_data_a_handle___ : random_access_mutator_a< _element >::template ___random_access_mutator_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_mutator_data_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: random_access_mutator_a< _element >::template ___random_access_mutator_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_mutator_data_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: random_access_mutator_a< _element >::template ___random_access_mutator_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___random_access_mutator_data_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: random_access_mutator_a< _element >::template ___random_access_mutator_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(random_access_mutator_data_a < _element , _type > const & it ) const final;

		virtual inline bool operator!=(random_access_mutator_data_a < _element , _type > const & it ) const final;

		virtual inline bool operator<(random_access_mutator_data_a < _element , _type > const & it ) const final;

		virtual inline bool operator>(random_access_mutator_data_a < _element , _type > const & it ) const final;

		virtual inline bool operator<=(random_access_mutator_data_a < _element , _type > const & it ) const final;

		virtual inline bool operator>=(random_access_mutator_data_a < _element , _type > const & it ) const final;

		virtual inline _type const & extract_it() const final;

		virtual inline _type & mutate_it() final;

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
		inline ___random_access_mutator_data_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___random_access_mutator_data_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___random_access_mutator_data_a_handle_final___>(___random_access_mutator_data_a_handle___<___TTT___>::___value___);
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
		return *std::static_pointer_cast<___random_access_mutator_data_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___random_access_mutator_data_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___random_access_mutator_data_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline random_access_mutator_data_a val(random_access_mutator_data_a const& other) noexcept
	{
		return random_access_mutator_data_a{ other };
	}

	static inline random_access_mutator_data_a ref(random_access_mutator_data_a& other) noexcept
	{
		return random_access_mutator_data_a(other, any_a<>::___reference_tag___{});
	}

	static inline random_access_mutator_data_a dup(random_access_mutator_data_a& other) noexcept
	{
		return random_access_mutator_data_a(other, any_a<>::___duplicate_tag___{});
	}

	inline random_access_mutator_data_a() = default;

	inline random_access_mutator_data_a(random_access_mutator_data_a& other, any_a<>::___reference_tag___) noexcept
		: random_access_mutator_a< _element >(other, any_a<>::___reference_tag___{})
	{}

	inline random_access_mutator_data_a(random_access_mutator_data_a& other, any_a<>::___duplicate_tag___) noexcept
		: random_access_mutator_a< _element >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline random_access_mutator_data_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: random_access_mutator_a< _element >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_mutator_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline random_access_mutator_data_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: random_access_mutator_a< _element >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_mutator_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_mutator_data_a, std::decay_t<___TTT___>>::value>>
	explicit inline random_access_mutator_data_a(___TTT___ value) noexcept
		: random_access_mutator_a< _element >{ std_make_shared<___random_access_mutator_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline random_access_mutator_data_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: random_access_mutator_a< _element >{ std_make_shared<___random_access_mutator_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline random_access_mutator_data_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_mutator_data_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_mutator_data_a, std::decay_t<___TTT___>>::value>>
	inline random_access_mutator_data_a& operator=(___TTT___ value) noexcept
	{
		random_access_mutator_data_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
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
		return random_access_mutator_data_a{ random_access_mutator_data_d<_element, _type>{ thing } };
	}

	static inline random_access_mutator_data_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___random_access_mutator_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return random_access_mutator_data_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return random_access_mutator_data_a{ random_access_mutator_data_d<_element, _type>(thing, any_a<>::___reference_tag___{}) };
	}

	static inline cat_a<> ___cat___();

	static inline unordered_herd_a<> ___cats___();

	static inline kind_a<> ___kind___();

	static inline unordered_herd_a<> ___kinds___();

	static inline unordered_shoal_a<> ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline random_access_mutator_data_a create(Args&&... args)
	{
		return random_access_mutator_data_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class random_access_mutator_data_a

template <typename _element, typename _type>
class random_access_mutator_data_d : public random_access_mutator_d< _element >
{
public:
	inline bool operator==(random_access_mutator_data_a < _element , _type > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator==(it) not available"); }

	inline bool operator!=(random_access_mutator_data_a < _element , _type > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator!=(it) not available"); }

	inline bool operator<(random_access_mutator_data_a < _element , _type > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator<(it) not available"); }

	inline bool operator>(random_access_mutator_data_a < _element , _type > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator>(it) not available"); }

	inline bool operator<=(random_access_mutator_data_a < _element , _type > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator<=(it) not available"); }

	inline bool operator>=(random_access_mutator_data_a < _element , _type > const & it ) const
	{ throw dis("dynamic random_access_mutator_data_d::operator>=(it) not available"); }

	inline _type const & extract_it() const
	{ throw dis("dynamic random_access_mutator_data_d::extract_it() not available"); }

	inline _type & mutate_it()
	{ throw dis("dynamic random_access_mutator_data_d::mutate_it() not available"); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit random_access_mutator_data_d(any_a<> const& thing)
		: random_access_mutator_d< _element >{ thing }
	{}

	explicit random_access_mutator_data_d(any_a<>& thing, any_a<>::___reference_tag___)
		: random_access_mutator_d< _element >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit random_access_mutator_data_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: random_access_mutator_d< _element >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
