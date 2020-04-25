
namespace strange
{

template <typename _element = any_a<> >
class inventory_d;

template <typename _element = any_a<> >
inline inventory_d<_element> ___inventory_dynamic___(any_a<> const& thing);

template <typename _element>
class inventory_a : public collection_a< number_data_int64_a<> , _element , _element >
{
public:
	inline bool has_index(int64_t index ) const;

	inline _element at_index(int64_t index ) const;

	inline void update_index(int64_t index , _element const & value );

	inline bool insert_index(int64_t index , _element const & value );

	inline bool erase_index(int64_t index );

	inline any_a<> mutate_begin__(list_a<> const& ___arguments___);

	inline random_access_mutator_a< _element > mutate_begin_();

	inline any_a<> mutate_end__(list_a<> const& ___arguments___);

	inline random_access_mutator_a< _element > mutate_end_();

protected:
	struct ___inventory_a_handle_base___ : collection_a< number_data_int64_a<> , _element , _element >::___collection_a_handle_base___
	{
		virtual bool has_index(int64_t index ) const = 0;
		virtual _element at_index(int64_t index ) const = 0;
		virtual void update_index(int64_t index , _element const & value ) = 0;
		virtual bool insert_index(int64_t index , _element const & value ) = 0;
		virtual bool erase_index(int64_t index ) = 0;
		virtual random_access_mutator_a< _element > mutate_begin_() = 0;
		virtual random_access_mutator_a< _element > mutate_end_() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___inventory_a_handle_base___>
	struct ___inventory_a_handle___ : collection_a< number_data_int64_a<> , _element , _element >::template ___collection_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: collection_a< number_data_int64_a<> , _element , _element >::template ___collection_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: collection_a< number_data_int64_a<> , _element , _element >::template ___collection_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___inventory_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: collection_a< number_data_int64_a<> , _element , _element >::template ___collection_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool has_index(int64_t index ) const final;

		virtual inline _element at_index(int64_t index ) const final;

		virtual inline void update_index(int64_t index , _element const & value ) final;

		virtual inline bool insert_index(int64_t index , _element const & value ) final;

		virtual inline bool erase_index(int64_t index ) final;

		virtual inline random_access_mutator_a< _element > mutate_begin_() final;

		virtual inline random_access_mutator_a< _element > mutate_end_() final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___inventory_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___inventory_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___inventory_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___inventory_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___inventory_a_handle_final___ final : ___inventory_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___inventory_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___inventory_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___inventory_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___inventory_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___inventory_a_handle_final___>(___inventory_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___inventory_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___inventory_a_handle_final___<___TTT___&>
	{
		inline ___inventory_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___inventory_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___inventory_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___inventory_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___inventory_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___inventory_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline inventory_a val(inventory_a const& other) noexcept
	{
		return inventory_a{ other };
	}

	static inline inventory_a ref(inventory_a& other) noexcept
	{
		return inventory_a(other, any_a<>::___reference_tag___{});
	}

	static inline inventory_a dup(inventory_a& other) noexcept
	{
		return inventory_a(other, any_a<>::___duplicate_tag___{});
	}

	inline inventory_a() = default;

	inline inventory_a(inventory_a& other, any_a<>::___reference_tag___) noexcept
		: collection_a< number_data_int64_a<> , _element , _element >(other, any_a<>::___reference_tag___{})
	{}

	inline inventory_a(inventory_a& other, any_a<>::___duplicate_tag___) noexcept
		: collection_a< number_data_int64_a<> , _element , _element >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline inventory_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: collection_a< number_data_int64_a<> , _element , _element >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline inventory_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: collection_a< number_data_int64_a<> , _element , _element >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<inventory_a, std::decay_t<___TTT___>>::value>>
	explicit inline inventory_a(___TTT___ value) noexcept
		: collection_a< number_data_int64_a<> , _element , _element >{ std_make_shared<___inventory_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline inventory_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: collection_a< number_data_int64_a<> , _element , _element >{ std_make_shared<___inventory_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline inventory_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<inventory_a, std::decay_t<___TTT___>>::value>>
	inline inventory_a& operator=(___TTT___ value) noexcept
	{
		inventory_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___inventory_a_handle_base___>(thing.___handle___) };
	}

	static inline inventory_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___inventory_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return inventory_a{ thing.___handle___ };
		}
		return inventory_a{ inventory_d<_element>{ thing } };
	}

	static inline inventory_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___inventory_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return inventory_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return inventory_a{ inventory_d<_element>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::inventory");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = collection_a< number_data_int64_a<> , _element , _element >::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = collection_a< number_data_int64_a<> , _element , _element >::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline inventory_a create(Args&&... args)
	{
		return inventory_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class inventory_a

template <typename _element>
class inventory_d : public collection_d< number_data_int64_a<> , _element , _element >
{
public:
	inline bool has_index(int64_t index ) const
	{ return collection_d<number_data_int64_a<>, _element , _element>::has_(num(index)); }

	inline _element at_index(int64_t index ) const
	{ return collection_d<number_data_int64_a<>, _element , _element>::at_(num(index)); }

	inline void update_index(int64_t index , _element const & value )
	{ collection_d<number_data_int64_a<>, _element , _element>::update_(num(index), value); }

	inline bool insert_index(int64_t index , _element const & value )
	{ return collection_d<number_data_int64_a<>, _element , _element>::insert_(num(index), value); }

	inline bool erase_index(int64_t index )
	{ return collection_d<number_data_int64_a<>, _element , _element>::erase_(num(index)); }

	inline any_a<> mutate_begin__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("mutate_begin_");
		if (!op)
		{
			throw dis("dynamic inventory_d::mutate_begin_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline random_access_mutator_a< _element > mutate_begin_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("mutate_begin_");
		if (!op)
		{
			throw dis("dynamic inventory_d::mutate_begin_ passed non-existent member");
		}
		return cast<random_access_mutator_a< _element >>(variadic_operate(op, *this));
	}

	inline any_a<> mutate_end__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("mutate_end_");
		if (!op)
		{
			throw dis("dynamic inventory_d::mutate_end_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline random_access_mutator_a< _element > mutate_end_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("mutate_end_");
		if (!op)
		{
			throw dis("dynamic inventory_d::mutate_end_ passed non-existent member");
		}
		return cast<random_access_mutator_a< _element >>(variadic_operate(op, *this));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit inventory_d(any_a<> const& thing)
		: collection_d< number_data_int64_a<> , _element , _element >{ thing }
	{}

	explicit inventory_d(any_a<>& thing, any_a<>::___reference_tag___)
		: collection_d< number_data_int64_a<> , _element , _element >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit inventory_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: collection_d< number_data_int64_a<> , _element , _element >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
