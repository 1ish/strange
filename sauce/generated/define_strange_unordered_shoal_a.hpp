
namespace strange
{

template <typename _key = any_a<> , typename _value = any_a<> >
class unordered_shoal_d;

template <typename _key = any_a<> , typename _value = any_a<> >
inline unordered_shoal_d<_key, _value> ___unordered_shoal_dynamic___(any_a<> const& thing);

template <typename _key, typename _value>
class unordered_shoal_a : public shoal_a< _key , _value >
{
public:
	inline bool operator==(unordered_shoal_a < _key , _value > const & shoal ) const;

	inline bool operator!=(unordered_shoal_a < _key , _value > const & shoal ) const;

	inline forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > extract_begin() const;

	inline forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > extract_end() const;

	inline forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > mutate_begin();

	inline forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > mutate_end();

	inline std_unordered_map < _key , _value > const & extract_map() const;

	inline std_unordered_map < _key , _value > & mutate_map();

protected:
	struct ___unordered_shoal_a_handle_base___ : shoal_a< _key , _value >::___shoal_a_handle_base___
	{
		virtual bool operator==(unordered_shoal_a < _key , _value > const & shoal ) const = 0;
		virtual bool operator!=(unordered_shoal_a < _key , _value > const & shoal ) const = 0;
		virtual forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > extract_begin() const = 0;
		virtual forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > extract_end() const = 0;
		virtual forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > mutate_begin() = 0;
		virtual forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > mutate_end() = 0;
		virtual std_unordered_map < _key , _value > const & extract_map() const = 0;
		virtual std_unordered_map < _key , _value > & mutate_map() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___unordered_shoal_a_handle_base___>
	struct ___unordered_shoal_a_handle___ : shoal_a< _key , _value >::template ___shoal_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_shoal_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: shoal_a< _key , _value >::template ___shoal_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_shoal_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: shoal_a< _key , _value >::template ___shoal_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___unordered_shoal_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: shoal_a< _key , _value >::template ___shoal_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(unordered_shoal_a < _key , _value > const & shoal ) const final;

		virtual inline bool operator!=(unordered_shoal_a < _key , _value > const & shoal ) const final;

		virtual inline forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > extract_begin() const final;

		virtual inline forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > extract_end() const final;

		virtual inline forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > mutate_begin() final;

		virtual inline forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > mutate_end() final;

		virtual inline std_unordered_map < _key , _value > const & extract_map() const final;

		virtual inline std_unordered_map < _key , _value > & mutate_map() final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___unordered_shoal_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___unordered_shoal_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___unordered_shoal_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___unordered_shoal_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___unordered_shoal_a_handle_final___ final : ___unordered_shoal_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_shoal_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___unordered_shoal_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___unordered_shoal_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___unordered_shoal_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___unordered_shoal_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___unordered_shoal_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___unordered_shoal_a_handle_final___>(___unordered_shoal_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___unordered_shoal_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___unordered_shoal_a_handle_final___<___TTT___&>
	{
		inline ___unordered_shoal_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___unordered_shoal_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___unordered_shoal_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___unordered_shoal_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___unordered_shoal_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___unordered_shoal_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline unordered_shoal_a val(unordered_shoal_a const& other) noexcept
	{
		return unordered_shoal_a{ other };
	}

	static inline unordered_shoal_a ref(unordered_shoal_a& other) noexcept
	{
		return unordered_shoal_a(other, any_a<>::___reference_tag___{});
	}

	static inline unordered_shoal_a dup(unordered_shoal_a& other) noexcept
	{
		return unordered_shoal_a(other, any_a<>::___duplicate_tag___{});
	}

	inline unordered_shoal_a() = default;

	inline unordered_shoal_a(unordered_shoal_a& other, any_a<>::___reference_tag___) noexcept
		: shoal_a< _key , _value >(other, any_a<>::___reference_tag___{})
	{}

	inline unordered_shoal_a(unordered_shoal_a& other, any_a<>::___duplicate_tag___) noexcept
		: shoal_a< _key , _value >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline unordered_shoal_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: shoal_a< _key , _value >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline unordered_shoal_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: shoal_a< _key , _value >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<unordered_shoal_a, std::decay_t<___TTT___>>::value>>
	explicit inline unordered_shoal_a(___TTT___ value) noexcept
		: shoal_a< _key , _value >{ std_make_shared<___unordered_shoal_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline unordered_shoal_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: shoal_a< _key , _value >{ std_make_shared<___unordered_shoal_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline unordered_shoal_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<unordered_shoal_a, std::decay_t<___TTT___>>::value>>
	inline unordered_shoal_a& operator=(___TTT___ value) noexcept
	{
		unordered_shoal_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(thing.___handle___) };
	}

	static inline unordered_shoal_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return unordered_shoal_a{ thing.___handle___ };
		}
		return unordered_shoal_a{ unordered_shoal_d<_key, _value>{ thing } };
	}

	static inline unordered_shoal_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___unordered_shoal_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return unordered_shoal_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return unordered_shoal_a{ unordered_shoal_d<_key, _value>(thing, any_a<>::___reference_tag___{}) };
	}

	static inline cat_a<> ___cat___();

	static inline unordered_herd_a<> ___cats___();

	static inline kind_a<> ___kind___();

	static inline unordered_herd_a<> ___kinds___();

	static inline unordered_shoal_a<> ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline unordered_shoal_a create(Args&&... args)
	{
		return unordered_shoal_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class unordered_shoal_a

template <typename _key, typename _value>
class unordered_shoal_d : public shoal_d< _key , _value >
{
public:
	inline bool operator==(unordered_shoal_a < _key , _value > const & shoal ) const
	{ throw dis("dynamic unordered_shoal_d::operator==(shoal) not available"); }

	inline bool operator!=(unordered_shoal_a < _key , _value > const & shoal ) const
	{ throw dis("dynamic unordered_shoal_d::operator!=(shoal) not available"); }

	inline forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > extract_begin() const
	{ throw dis("dynamic unordered_shoal_d::extract_begin() not available"); }

	inline forward_extractor_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: const_iterator > extract_end() const
	{ throw dis("dynamic unordered_shoal_d::extract_end() not available"); }

	inline forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > mutate_begin()
	{ throw dis("dynamic unordered_shoal_d::mutate_begin() not available"); }

	inline forward_mutator_data_a < flock_a < > , typename std_unordered_map < _key , _value > :: iterator > mutate_end()
	{ throw dis("dynamic unordered_shoal_d::mutate_end() not available"); }

	inline std_unordered_map < _key , _value > const & extract_map() const
	{ throw dis("dynamic unordered_shoal_d::extract_map() not available"); }

	inline std_unordered_map < _key , _value > & mutate_map()
	{ throw dis("dynamic unordered_shoal_d::mutate_map() not available"); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit unordered_shoal_d(any_a<> const& thing)
		: shoal_d< _key , _value >{ thing }
	{}

	explicit unordered_shoal_d(any_a<>& thing, any_a<>::___reference_tag___)
		: shoal_d< _key , _value >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit unordered_shoal_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: shoal_d< _key , _value >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
