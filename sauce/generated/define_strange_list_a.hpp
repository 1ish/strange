
namespace strange
{

template <typename _1 = void>
class list_d;

template <typename _1 = void>
inline list_d<_1> ___list_dynamic___(any_a<> const& thing); 

template <typename _1>
class list_a : public any_a<>
{
public:
	inline any_a<> begin__(range_a<> const& ___arguments___) const;

	inline forward_extractor_a< any_a<> > begin_() const;

	inline any_a<> end__(range_a<> const& ___arguments___) const;

	inline forward_extractor_a< any_a<> > end_() const;

protected:
	struct ___list_a_handle_base___ : any_a<>::___any_a_handle_base___
	{
		virtual forward_extractor_a< any_a<> > begin_() const = 0;
		virtual forward_extractor_a< any_a<> > end_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___list_a_handle_base___>
	struct ___list_a_handle___ : any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___list_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___list_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___list_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline forward_extractor_a< any_a<> > begin_() const final;

		virtual inline forward_extractor_a< any_a<> > end_() const final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___list_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___list_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___list_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___list_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___list_a_handle_final___ final : ___list_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___list_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___list_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___list_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___list_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___list_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___list_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___list_a_handle_final___>(___list_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___list_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___list_a_handle_final___<___TTT___&>
	{
		inline ___list_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___list_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___list_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___list_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___list_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___list_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline list_a val(list_a const& other) noexcept
	{
		return list_a{ other };
	}

	static inline list_a ref(list_a& other) noexcept
	{
		return list_a(other, any_a<>::___reference_tag___{});
	}

	static inline list_a dup(list_a& other) noexcept
	{
		return list_a(other, any_a<>::___duplicate_tag___{});
	}

	inline list_a() = default;

	inline list_a(list_a& other, any_a<>::___reference_tag___) noexcept
		: any_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline list_a(list_a& other, any_a<>::___duplicate_tag___) noexcept
		: any_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline list_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: any_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___list_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline list_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: any_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___list_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<list_a, std::decay_t<___TTT___>>::value>>
	explicit inline list_a(___TTT___ value) noexcept
		: any_a<>{ std_make_shared<___list_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline list_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a<>{ std_make_shared<___list_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline list_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___list_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<list_a, std::decay_t<___TTT___>>::value>>
	inline list_a& operator=(___TTT___ value) noexcept
	{
		list_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___list_a_handle_base___>(thing.___handle___) };
	}

	static inline list_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___list_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return list_a{ thing.___handle___ };
		}
		return list_a{ list_d<_1>{ thing } };
	}

	static inline list_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___list_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return list_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return list_a{ list_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::list");
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
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>());
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
	static inline ___unordered_shoal_a___ ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline list_a create(Args&&... args)
	{
		return list_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class list_a

template <typename _1>
class list_d : public any_a<>
{
public:
	inline any_a<> begin__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("begin_");
		if (!op)
		{
			throw dis("dynamic list_d::begin_ passed non-existent member");
		}
		return op.operate(*const_cast<list_d*>(this), arguments);
	}

	inline forward_extractor_a< any_a<> > begin_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("begin_");
		if (!op)
		{
			throw dis("dynamic list_d::begin_ passed non-existent member");
		}
		return cast<forward_extractor_a< any_a<> >>(variadic_operate(op, *const_cast<list_d*>(this)));
	}

	inline any_a<> end__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("end_");
		if (!op)
		{
			throw dis("dynamic list_d::end_ passed non-existent member");
		}
		return op.operate(*const_cast<list_d*>(this), arguments);
	}

	inline forward_extractor_a< any_a<> > end_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("end_");
		if (!op)
		{
			throw dis("dynamic list_d::end_ passed non-existent member");
		}
		return cast<forward_extractor_a< any_a<> >>(variadic_operate(op, *const_cast<list_d*>(this)));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit list_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit list_d(any_a<>& thing, any_a<>::___reference_tag___)
		: any_a<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit list_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: any_a<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
