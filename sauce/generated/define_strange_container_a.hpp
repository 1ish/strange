
namespace strange
{

template <typename _1 = void>
class container_d;

template <typename _1 = void>
inline container_d<_1> ___container_dynamic___(any_a<> const& thing); 

template <typename _1>
class container_a : public collection_a< any_a<> , container_a<> , container_a<> >
{
public:
	inline any_a<> unpack__(list_a<> const& ___arguments___) const;

	inline any_a<> unpack_(shoal_a<> const& shared_shoal) const;

	inline any_a<> unpack_unique__(list_a<> const& ___arguments___) const;

	inline any_a<> unpack_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const;

	inline any_a < > unpack(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const;

	inline any_a<> keys_begin__(list_a<> const& ___arguments___) const;

	inline bidirectional_extractor_a< any_a<> > keys_begin_() const;

	inline any_a<> keys_end__(list_a<> const& ___arguments___) const;

	inline bidirectional_extractor_a< any_a<> > keys_end_() const;

protected:
	struct ___container_a_handle_base___ : collection_a< any_a<> , container_a<> , container_a<> >::___collection_a_handle_base___
	{
		virtual any_a<> unpack_(shoal_a<> const& shared_shoal) const = 0;
		virtual any_a<> unpack_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const = 0;
		virtual any_a < > unpack(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const = 0;
		virtual bidirectional_extractor_a< any_a<> > keys_begin_() const = 0;
		virtual bidirectional_extractor_a< any_a<> > keys_end_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___container_a_handle_base___>
	struct ___container_a_handle___ : collection_a< any_a<> , container_a<> , container_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___container_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: collection_a< any_a<> , container_a<> , container_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___container_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: collection_a< any_a<> , container_a<> , container_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___container_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: collection_a< any_a<> , container_a<> , container_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> unpack_(shoal_a<> const& shared_shoal) const final;

		virtual inline any_a<> unpack_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const final;

		virtual inline any_a < > unpack(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const final;

		virtual inline bidirectional_extractor_a< any_a<> > keys_begin_() const final;

		virtual inline bidirectional_extractor_a< any_a<> > keys_end_() const final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___container_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___container_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___container_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___container_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___container_a_handle_final___ final : ___container_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___container_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___container_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___container_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___container_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___container_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___container_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___container_a_handle_final___>(___container_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___container_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___container_a_handle_final___<___TTT___&>
	{
		inline ___container_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___container_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___container_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___container_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___container_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___container_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline container_a val(container_a const& other) noexcept
	{
		return container_a{ other };
	}

	static inline container_a ref(container_a& other) noexcept
	{
		return container_a(other, any_a<>::___reference_tag___{});
	}

	static inline container_a dup(container_a& other) noexcept
	{
		return container_a(other, any_a<>::___duplicate_tag___{});
	}

	inline container_a() = default;

	inline container_a(container_a& other, any_a<>::___reference_tag___) noexcept
		: collection_a< any_a<> , container_a<> , container_a<> >(other, any_a<>::___reference_tag___{})
	{}

	inline container_a(container_a& other, any_a<>::___duplicate_tag___) noexcept
		: collection_a< any_a<> , container_a<> , container_a<> >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline container_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: collection_a< any_a<> , container_a<> , container_a<> >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___container_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline container_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: collection_a< any_a<> , container_a<> , container_a<> >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___container_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<container_a, std::decay_t<___TTT___>>::value>>
	explicit inline container_a(___TTT___ value) noexcept
		: collection_a< any_a<> , container_a<> , container_a<> >{ std_make_shared<___container_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline container_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: collection_a< any_a<> , container_a<> , container_a<> >{ std_make_shared<___container_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline container_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___container_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<container_a, std::decay_t<___TTT___>>::value>>
	inline container_a& operator=(___TTT___ value) noexcept
	{
		container_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___container_a_handle_base___>(thing.___handle___) };
	}

	static inline container_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___container_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return container_a{ thing.___handle___ };
		}
		return container_a{ container_d<_1>{ thing } };
	}

	static inline container_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___container_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return container_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return container_a{ container_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::container");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = collection_a< any_a<> , container_a<> , container_a<> >::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = collection_a< any_a<> , container_a<> , container_a<> >::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline container_a create(Args&&... args)
	{
		return container_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class container_a

template <typename _1>
class container_d : public collection_d< any_a<> , container_a<> , container_a<> >
{
public:
	inline any_a<> unpack__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("unpack_");
		if (!op)
		{
			throw dis("dynamic container_d::unpack_ passed non-existent member");
		}
		return op.operate(*const_cast<container_d*>(this), arguments);
	}

	inline any_a<> unpack_(shoal_a<> const& shared_shoal) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("unpack_");
		if (!op)
		{
			throw dis("dynamic container_d::unpack_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<container_d*>(this), shared_shoal));
	}

	inline any_a<> unpack_unique__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("unpack_unique_");
		if (!op)
		{
			throw dis("dynamic container_d::unpack_unique_ passed non-existent member");
		}
		return op.operate(*const_cast<container_d*>(this), arguments);
	}

	inline any_a<> unpack_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("unpack_unique_");
		if (!op)
		{
			throw dis("dynamic container_d::unpack_unique_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<container_d*>(this), shared_shoal, unique_shoal));
	}

	inline any_a < > unpack(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const
	{ throw dis("dynamic container_d::unpack(shared_shoal, unique_shoal) not available"); }

	inline any_a<> keys_begin__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("keys_begin_");
		if (!op)
		{
			throw dis("dynamic container_d::keys_begin_ passed non-existent member");
		}
		return op.operate(*const_cast<container_d*>(this), arguments);
	}

	inline bidirectional_extractor_a< any_a<> > keys_begin_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("keys_begin_");
		if (!op)
		{
			throw dis("dynamic container_d::keys_begin_ passed non-existent member");
		}
		return cast<bidirectional_extractor_a< any_a<> >>(variadic_operate(op, *const_cast<container_d*>(this)));
	}

	inline any_a<> keys_end__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("keys_end_");
		if (!op)
		{
			throw dis("dynamic container_d::keys_end_ passed non-existent member");
		}
		return op.operate(*const_cast<container_d*>(this), arguments);
	}

	inline bidirectional_extractor_a< any_a<> > keys_end_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("keys_end_");
		if (!op)
		{
			throw dis("dynamic container_d::keys_end_ passed non-existent member");
		}
		return cast<bidirectional_extractor_a< any_a<> >>(variadic_operate(op, *const_cast<container_d*>(this)));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit container_d(any_a<> const& thing)
		: collection_d< any_a<> , container_a<> , container_a<> >{ thing }
	{}

	explicit container_d(any_a<>& thing, any_a<>::___reference_tag___)
		: collection_d< any_a<> , container_a<> , container_a<> >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit container_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: collection_d< any_a<> , container_a<> , container_a<> >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
