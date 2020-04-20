
namespace strange
{

template <typename _key = any_a<> , typename _value = any_a<> >
class shoal_d;

template <typename _key = any_a<> , typename _value = any_a<> >
inline shoal_d<_key, _value> ___shoal_dynamic___(any_a<> const& thing); 

template <typename _key, typename _value>
class shoal_a : public collection_a< _key , _value , flock_a<> >
{
public:
	inline any_a<> mutate_begin__(list_a<> const& ___arguments___);

	inline forward_mutator_a< flock_a<> > mutate_begin_();

	inline any_a<> mutate_end__(list_a<> const& ___arguments___);

	inline forward_mutator_a< flock_a<> > mutate_end_();

protected:
	struct ___shoal_a_handle_base___ : collection_a< _key , _value , flock_a<> >::___collection_a_handle_base___
	{
		virtual forward_mutator_a< flock_a<> > mutate_begin_() = 0;
		virtual forward_mutator_a< flock_a<> > mutate_end_() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___shoal_a_handle_base___>
	struct ___shoal_a_handle___ : collection_a< _key , _value , flock_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___shoal_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: collection_a< _key , _value , flock_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___shoal_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: collection_a< _key , _value , flock_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___shoal_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: collection_a< _key , _value , flock_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline forward_mutator_a< flock_a<> > mutate_begin_() final;

		virtual inline forward_mutator_a< flock_a<> > mutate_end_() final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___shoal_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___shoal_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___shoal_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___shoal_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___shoal_a_handle_final___ final : ___shoal_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___shoal_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___shoal_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___shoal_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___shoal_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___shoal_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___shoal_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___shoal_a_handle_final___>(___shoal_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___shoal_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___shoal_a_handle_final___<___TTT___&>
	{
		inline ___shoal_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___shoal_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___shoal_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___shoal_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___shoal_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___shoal_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline shoal_a val(shoal_a const& other) noexcept
	{
		return shoal_a{ other };
	}

	static inline shoal_a ref(shoal_a& other) noexcept
	{
		return shoal_a(other, any_a<>::___reference_tag___{});
	}

	static inline shoal_a dup(shoal_a& other) noexcept
	{
		return shoal_a(other, any_a<>::___duplicate_tag___{});
	}

	inline shoal_a() = default;

	inline shoal_a(shoal_a& other, any_a<>::___reference_tag___) noexcept
		: collection_a< _key , _value , flock_a<> >(other, any_a<>::___reference_tag___{})
	{}

	inline shoal_a(shoal_a& other, any_a<>::___duplicate_tag___) noexcept
		: collection_a< _key , _value , flock_a<> >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline shoal_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: collection_a< _key , _value , flock_a<> >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___shoal_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline shoal_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: collection_a< _key , _value , flock_a<> >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___shoal_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<shoal_a, std::decay_t<___TTT___>>::value>>
	explicit inline shoal_a(___TTT___ value) noexcept
		: collection_a< _key , _value , flock_a<> >{ std_make_shared<___shoal_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline shoal_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: collection_a< _key , _value , flock_a<> >{ std_make_shared<___shoal_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline shoal_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___shoal_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<shoal_a, std::decay_t<___TTT___>>::value>>
	inline shoal_a& operator=(___TTT___ value) noexcept
	{
		shoal_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___shoal_a_handle_base___>(thing.___handle___) };
	}

	static inline shoal_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___shoal_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return shoal_a{ thing.___handle___ };
		}
		return shoal_a{ shoal_d<_key, _value>{ thing } };
	}

	static inline shoal_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___shoal_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return shoal_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return shoal_a{ shoal_d<_key, _value>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::shoal");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = collection_a< _key , _value , flock_a<> >::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = collection_a< _key , _value , flock_a<> >::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline shoal_a create(Args&&... args)
	{
		return shoal_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class shoal_a

template <typename _key, typename _value>
class shoal_d : public collection_d< _key , _value , flock_a<> >
{
public:
	inline any_a<> mutate_begin__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("mutate_begin_");
		if (!op)
		{
			throw dis("dynamic shoal_d::mutate_begin_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline forward_mutator_a< flock_a<> > mutate_begin_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("mutate_begin_");
		if (!op)
		{
			throw dis("dynamic shoal_d::mutate_begin_ passed non-existent member");
		}
		return cast<forward_mutator_a< flock_a<> >>(variadic_operate(op, *this));
	}

	inline any_a<> mutate_end__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("mutate_end_");
		if (!op)
		{
			throw dis("dynamic shoal_d::mutate_end_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline forward_mutator_a< flock_a<> > mutate_end_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("mutate_end_");
		if (!op)
		{
			throw dis("dynamic shoal_d::mutate_end_ passed non-existent member");
		}
		return cast<forward_mutator_a< flock_a<> >>(variadic_operate(op, *this));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit shoal_d(any_a<> const& thing)
		: collection_d< _key , _value , flock_a<> >{ thing }
	{}

	explicit shoal_d(any_a<>& thing, any_a<>::___reference_tag___)
		: collection_d< _key , _value , flock_a<> >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit shoal_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: collection_d< _key , _value , flock_a<> >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
