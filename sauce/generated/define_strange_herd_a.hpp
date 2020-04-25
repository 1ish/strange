
namespace strange
{

template <typename _element = any_a<> >
class herd_d;

template <typename _element = any_a<> >
inline herd_d<_element> ___herd_dynamic___(any_a<> const& thing);

template <typename _element>
class herd_a : public collection_a< _element , _element , _element >
{
public:
	inline any_a<> update_thing__(list_a<> const& ___arguments___);

	inline _element update_thing_(_element const& thing);

	inline void update_thing(_element const & thing );

	inline any_a<> insert_thing__(list_a<> const& ___arguments___);

	inline any_a<> insert_thing_(_element const& thing);

	inline bool insert_thing(_element const & thing );

protected:
	struct ___herd_a_handle_base___ : collection_a< _element , _element , _element >::___collection_a_handle_base___
	{
		virtual _element update_thing_(_element const& thing) = 0;
		virtual void update_thing(_element const & thing ) = 0;
		virtual any_a<> insert_thing_(_element const& thing) = 0;
		virtual bool insert_thing(_element const & thing ) = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___herd_a_handle_base___>
	struct ___herd_a_handle___ : collection_a< _element , _element , _element >::template ___collection_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___herd_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: collection_a< _element , _element , _element >::template ___collection_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___herd_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: collection_a< _element , _element , _element >::template ___collection_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___herd_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: collection_a< _element , _element , _element >::template ___collection_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline _element update_thing_(_element const& thing) final;

		virtual inline void update_thing(_element const & thing ) final;

		virtual inline any_a<> insert_thing_(_element const& thing) final;

		virtual inline bool insert_thing(_element const & thing ) final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___herd_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___herd_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___herd_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___herd_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___herd_a_handle_final___ final : ___herd_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___herd_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___herd_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___herd_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___herd_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___herd_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___herd_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___herd_a_handle_final___>(___herd_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___herd_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___herd_a_handle_final___<___TTT___&>
	{
		inline ___herd_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___herd_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___herd_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___herd_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___herd_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___herd_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline herd_a val(herd_a const& other) noexcept
	{
		return herd_a{ other };
	}

	static inline herd_a ref(herd_a& other) noexcept
	{
		return herd_a(other, any_a<>::___reference_tag___{});
	}

	static inline herd_a dup(herd_a& other) noexcept
	{
		return herd_a(other, any_a<>::___duplicate_tag___{});
	}

	inline herd_a() = default;

	inline herd_a(herd_a& other, any_a<>::___reference_tag___) noexcept
		: collection_a< _element , _element , _element >(other, any_a<>::___reference_tag___{})
	{}

	inline herd_a(herd_a& other, any_a<>::___duplicate_tag___) noexcept
		: collection_a< _element , _element , _element >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline herd_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: collection_a< _element , _element , _element >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___herd_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline herd_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: collection_a< _element , _element , _element >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___herd_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<herd_a, std::decay_t<___TTT___>>::value>>
	explicit inline herd_a(___TTT___ value) noexcept
		: collection_a< _element , _element , _element >{ std_make_shared<___herd_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline herd_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: collection_a< _element , _element , _element >{ std_make_shared<___herd_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline herd_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___herd_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<herd_a, std::decay_t<___TTT___>>::value>>
	inline herd_a& operator=(___TTT___ value) noexcept
	{
		herd_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___herd_a_handle_base___>(thing.___handle___) };
	}

	static inline herd_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___herd_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return herd_a{ thing.___handle___ };
		}
		return herd_a{ herd_d<_element>{ thing } };
	}

	static inline herd_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___herd_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return herd_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return herd_a{ herd_d<_element>(thing, any_a<>::___reference_tag___{}) };
	}

	static inline cat_a<> ___cat___();

	static inline unordered_herd_a<> ___cats___();

	static inline kind_a<> ___kind___();

	static inline unordered_herd_a<> ___kinds___();

	static inline unordered_shoal_a<> ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline herd_a create(Args&&... args)
	{
		return herd_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class herd_a

template <typename _element>
class herd_d : public collection_d< _element , _element , _element >
{
public:
	inline any_a<> update_thing__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("update_thing_");
		if (!op)
		{
			throw dis("dynamic herd_d::update_thing_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline _element update_thing_(_element const& thing)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("update_thing_");
		if (!op)
		{
			throw dis("dynamic herd_d::update_thing_ passed non-existent member");
		}
		return cast<_element>(variadic_operate(op, *this, thing));
	}

	inline void update_thing(_element const & thing )
	{ update_thing_(thing); }

	inline any_a<> insert_thing__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("insert_thing_");
		if (!op)
		{
			throw dis("dynamic herd_d::insert_thing_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline any_a<> insert_thing_(_element const& thing)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("insert_thing_");
		if (!op)
		{
			throw dis("dynamic herd_d::insert_thing_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, thing));
	}

	inline bool insert_thing(_element const & thing )
	{ return insert_thing_(thing); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit herd_d(any_a<> const& thing)
		: collection_d< _element , _element , _element >{ thing }
	{}

	explicit herd_d(any_a<>& thing, any_a<>::___reference_tag___)
		: collection_d< _element , _element , _element >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit herd_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: collection_d< _element , _element , _element >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
