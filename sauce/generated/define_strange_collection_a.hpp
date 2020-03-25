
namespace strange
{

template <typename _key = any_a<> , typename _value = any_a<> , typename _element = any_a<> >
class collection_d;

template <typename _key = any_a<> , typename _value = any_a<> , typename _element = any_a<> >
inline collection_d<_key, _value, _element> ___collection_dynamic___(any_a<> const& thing); 

template <typename _key, typename _value, typename _element>
class collection_a : public range_a< _element >
{
public:
	inline any_a<> has__(range_a<> const& ___arguments___) const;

	inline any_a<> has_(_key const& key) const;

	inline bool has(_key const & key ) const;

	inline any_a<> at__(range_a<> const& ___arguments___) const;

	inline any_a<> at_(_key const& key) const;

	inline any_a<> update__(range_a<> const& ___arguments___);

	inline _value update_(_key const& key, _value const& value = strange::no() );

	inline void update(_key const & key , _value const & value );

	inline any_a<> insert__(range_a<> const& ___arguments___);

	inline any_a<> insert_(_key const& key, _value const& value = strange::no() );

	inline void insert(_key const & key , _value const & value );

	inline any_a<> erase__(range_a<> const& ___arguments___);

	inline any_a<> erase_(_key const& key);

	inline bool erase(_key const & key );

	inline any_a<> clear__(range_a<> const& ___arguments___);

	inline collection_a< _key , _value , _element > clear_();

	inline void clear();

	inline any_a<> size__(range_a<> const& ___arguments___) const;

	inline number_data_int64_a<> size_() const;

	inline int64_t size() const;

	inline any_a<> empty__(range_a<> const& ___arguments___) const;

	inline any_a<> empty_() const;

	inline bool empty() const;

	inline any_a<> push_front__(range_a<> const& ___arguments___);

	inline collection_a< _key , _value , _element > push_front_(_element const& thing);

	inline void push_front(_element const & thing );

	inline any_a<> pop_front__(range_a<> const& ___arguments___);

	inline _element pop_front_();

	inline any_a<> push_back__(range_a<> const& ___arguments___);

	inline collection_a< _key , _value , _element > push_back_(_element const& thing);

	inline void push_back(_element const & thing );

	inline any_a<> pop_back__(range_a<> const& ___arguments___);

	inline _element pop_back_();

	inline any_a<> self_assign__(range_a<> const& ___arguments___);

	inline collection_a self_assign_(range_a< _element > const& range);

	inline any_a<> self_add__(range_a<> const& ___arguments___);

	inline collection_a self_add_(range_a< _element > const& range);

	inline collection_a& operator+=(range_a< _element > const& range);

	inline any_a<> add__(range_a<> const& ___arguments___) const;

	inline collection_a< _key , _value , _element > add_(range_a< _element > const& range) const;

	inline collection_a< _key , _value , _element > operator+(range_a< _element > const& range) const;

	inline any_a<> self_subtract__(range_a<> const& ___arguments___);

	inline collection_a self_subtract_(range_a< _element > const& range);

	inline collection_a& operator-=(range_a< _element > const& range);

	inline any_a<> subtract__(range_a<> const& ___arguments___) const;

	inline collection_a< _key , _value , _element > subtract_(range_a< _element > const& range) const;

	inline collection_a< _key , _value , _element > operator-(range_a< _element > const& range) const;

	inline any_a<> read_lock__(range_a<> const& ___arguments___) const;

	inline any_a<> read_lock_() const;

	inline any_a<> write_lock__(range_a<> const& ___arguments___) const;

	inline any_a<> write_lock_() const;

protected:
	struct ___collection_a_handle_base___ : range_a< _element >::___range_a_handle_base___
	{
		virtual any_a<> has_(_key const& key) const = 0;
		virtual bool has(_key const & key ) const = 0;
		virtual any_a<> at_(_key const& key) const = 0;
		virtual _value update_(_key const& key, _value const& value = strange::no() ) = 0;
		virtual void update(_key const & key , _value const & value ) = 0;
		virtual any_a<> insert_(_key const& key, _value const& value = strange::no() ) = 0;
		virtual void insert(_key const & key , _value const & value ) = 0;
		virtual any_a<> erase_(_key const& key) = 0;
		virtual bool erase(_key const & key ) = 0;
		virtual collection_a< _key , _value , _element > clear_() = 0;
		virtual void clear() = 0;
		virtual number_data_int64_a<> size_() const = 0;
		virtual int64_t size() const = 0;
		virtual any_a<> empty_() const = 0;
		virtual bool empty() const = 0;
		virtual collection_a< _key , _value , _element > push_front_(_element const& thing) = 0;
		virtual void push_front(_element const & thing ) = 0;
		virtual _element pop_front_() = 0;
		virtual collection_a< _key , _value , _element > push_back_(_element const& thing) = 0;
		virtual void push_back(_element const & thing ) = 0;
		virtual _element pop_back_() = 0;
		virtual void self_assign_(range_a< _element > const& range) = 0;
		virtual void self_add_(range_a< _element > const& range) = 0;
		virtual collection_a< _key , _value , _element > add_(range_a< _element > const& range) const = 0;
		virtual void self_subtract_(range_a< _element > const& range) = 0;
		virtual collection_a< _key , _value , _element > subtract_(range_a< _element > const& range) const = 0;
		virtual any_a<> read_lock_() const = 0;
		virtual any_a<> write_lock_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___collection_a_handle_base___>
	struct ___collection_a_handle___ : range_a< _element >::template ___range_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___collection_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: range_a< _element >::template ___range_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___collection_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: range_a< _element >::template ___range_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___collection_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: range_a< _element >::template ___range_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> has_(_key const& key) const final;

		virtual inline bool has(_key const & key ) const final;

		virtual inline any_a<> at_(_key const& key) const final;

		virtual inline _value update_(_key const& key, _value const& value = strange::no() ) final;

		virtual inline void update(_key const & key , _value const & value ) final;

		virtual inline any_a<> insert_(_key const& key, _value const& value = strange::no() ) final;

		virtual inline void insert(_key const & key , _value const & value ) final;

		virtual inline any_a<> erase_(_key const& key) final;

		virtual inline bool erase(_key const & key ) final;

		virtual inline collection_a< _key , _value , _element > clear_() final;

		virtual inline void clear() final;

		virtual inline number_data_int64_a<> size_() const final;

		virtual inline int64_t size() const final;

		virtual inline any_a<> empty_() const final;

		virtual inline bool empty() const final;

		virtual inline collection_a< _key , _value , _element > push_front_(_element const& thing) final;

		virtual inline void push_front(_element const & thing ) final;

		virtual inline _element pop_front_() final;

		virtual inline collection_a< _key , _value , _element > push_back_(_element const& thing) final;

		virtual inline void push_back(_element const & thing ) final;

		virtual inline _element pop_back_() final;

		virtual inline void self_assign_(range_a< _element > const& range) final;

		virtual inline void self_add_(range_a< _element > const& range) final;

		virtual inline collection_a< _key , _value , _element > add_(range_a< _element > const& range) const final;

		virtual inline void self_subtract_(range_a< _element > const& range) final;

		virtual inline collection_a< _key , _value , _element > subtract_(range_a< _element > const& range) const final;

		virtual inline any_a<> read_lock_() const final;

		virtual inline any_a<> write_lock_() const final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___collection_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___collection_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___collection_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___collection_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___collection_a_handle_final___ final : ___collection_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___collection_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___collection_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___collection_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___collection_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___collection_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___collection_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___collection_a_handle_final___>(___collection_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___collection_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___collection_a_handle_final___<___TTT___&>
	{
		inline ___collection_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___collection_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___collection_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___collection_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___collection_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___collection_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline collection_a val(collection_a const& other) noexcept
	{
		return collection_a{ other };
	}

	static inline collection_a ref(collection_a& other) noexcept
	{
		return collection_a(other, any_a<>::___reference_tag___{});
	}

	static inline collection_a dup(collection_a& other) noexcept
	{
		return collection_a(other, any_a<>::___duplicate_tag___{});
	}

	inline collection_a() = default;

	inline collection_a(collection_a& other, any_a<>::___reference_tag___) noexcept
		: range_a< _element >(other, any_a<>::___reference_tag___{})
	{}

	inline collection_a(collection_a& other, any_a<>::___duplicate_tag___) noexcept
		: range_a< _element >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline collection_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: range_a< _element >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline collection_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: range_a< _element >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<collection_a, std::decay_t<___TTT___>>::value>>
	explicit inline collection_a(___TTT___ value) noexcept
		: range_a< _element >{ std::make_shared<___collection_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline collection_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: range_a< _element >{ std::make_shared<___collection_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline collection_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<collection_a, std::decay_t<___TTT___>>::value>>
	inline collection_a& operator=(___TTT___ value) noexcept
	{
		collection_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___collection_a_handle_base___>(thing.___handle___) };
	}

	static inline collection_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___collection_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return collection_a{ thing.___handle___ };
		}
		return collection_a{ collection_d<_key, _value, _element>{ thing } };
	}

	static inline collection_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___collection_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return collection_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return collection_a{ collection_d<_key, _value, _element>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::collection");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = range_a< _element >::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = range_a< _element >::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = range_a< _element >::template ___operations___<___unordered_shoal_a___>();
			operations.update_string("has_", native_extraction_t<collection_a>::create(&collection_a::has__));
			operations.update_string("at_", native_extraction_t<collection_a>::create(&collection_a::at__));
			operations.update_string("update_", native_mutation_t<collection_a>::create(&collection_a::update__));
			operations.update_string("insert_", native_mutation_t<collection_a>::create(&collection_a::insert__));
			operations.update_string("erase_", native_mutation_t<collection_a>::create(&collection_a::erase__));
			operations.update_string("clear_", native_mutation_t<collection_a>::create(&collection_a::clear__));
			operations.update_string("size_", native_extraction_t<collection_a>::create(&collection_a::size__));
			operations.update_string("empty_", native_extraction_t<collection_a>::create(&collection_a::empty__));
			operations.update_string("push_front_", native_mutation_t<collection_a>::create(&collection_a::push_front__));
			operations.update_string("pop_front_", native_mutation_t<collection_a>::create(&collection_a::pop_front__));
			operations.update_string("push_back_", native_mutation_t<collection_a>::create(&collection_a::push_back__));
			operations.update_string("pop_back_", native_mutation_t<collection_a>::create(&collection_a::pop_back__));
			operations.update_string("self_assign_", native_mutation_t<collection_a>::create(&collection_a::self_assign__));
			operations.update_string("self_add_", native_mutation_t<collection_a>::create(&collection_a::self_add__));
			operations.update_string("add_", native_extraction_t<collection_a>::create(&collection_a::add__));
			operations.update_string("self_subtract_", native_mutation_t<collection_a>::create(&collection_a::self_subtract__));
			operations.update_string("subtract_", native_extraction_t<collection_a>::create(&collection_a::subtract__));
			operations.update_string("read_lock_", native_extraction_t<collection_a>::create(&collection_a::read_lock__));
			operations.update_string("write_lock_", native_extraction_t<collection_a>::create(&collection_a::write_lock__));
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline collection_a create(Args&&... args)
	{
		return collection_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class collection_a

template <typename _key, typename _value, typename _element>
class collection_d : public range_d< _element >
{
public:
	inline any_a<> has__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("has_");
		if (!op)
		{
			throw dis("dynamic collection_d::has_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), arguments);
	}

	inline any_a<> has_(_key const& key) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("has_");
		if (!op)
		{
			throw dis("dynamic collection_d::has_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<collection_d*>(this), key));
	}

	inline bool has(_key const & key ) const
	{ return has_(key); }

	inline any_a<> at__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("at_");
		if (!op)
		{
			throw dis("dynamic collection_d::at_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), arguments);
	}

	inline any_a<> at_(_key const& key) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("at_");
		if (!op)
		{
			throw dis("dynamic collection_d::at_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<collection_d*>(this), key));
	}

	inline any_a<> update__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("update_");
		if (!op)
		{
			throw dis("dynamic collection_d::update_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline _value update_(_key const& key, _value const& value = strange::no() )
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("update_");
		if (!op)
		{
			throw dis("dynamic collection_d::update_ passed non-existent member");
		}
		return cast<_value>(variadic_operate(op, *this, key, value));
	}

	inline void update(_key const & key , _value const & value )
	{ update_(key, value); }

	inline any_a<> insert__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("insert_");
		if (!op)
		{
			throw dis("dynamic collection_d::insert_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline any_a<> insert_(_key const& key, _value const& value = strange::no() )
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("insert_");
		if (!op)
		{
			throw dis("dynamic collection_d::insert_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, key, value));
	}

	inline void insert(_key const & key , _value const & value )
	{ insert_(key, value); }

	inline any_a<> erase__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("erase_");
		if (!op)
		{
			throw dis("dynamic collection_d::erase_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline any_a<> erase_(_key const& key)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("erase_");
		if (!op)
		{
			throw dis("dynamic collection_d::erase_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, key));
	}

	inline bool erase(_key const & key )
	{ return erase_(key); }

	inline any_a<> clear__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("clear_");
		if (!op)
		{
			throw dis("dynamic collection_d::clear_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline collection_a< _key , _value , _element > clear_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("clear_");
		if (!op)
		{
			throw dis("dynamic collection_d::clear_ passed non-existent member");
		}
		return cast<collection_a< _key , _value , _element >>(variadic_operate(op, *this));
	}

	inline void clear()
	{ clear_(); }

	inline any_a<> size__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("size_");
		if (!op)
		{
			throw dis("dynamic collection_d::size_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), arguments);
	}

	inline number_data_int64_a<> size_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("size_");
		if (!op)
		{
			throw dis("dynamic collection_d::size_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<collection_d*>(this)));
	}

	inline int64_t size() const
	{ return size_().extract_primitive(); }

	inline any_a<> empty__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("empty_");
		if (!op)
		{
			throw dis("dynamic collection_d::empty_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), arguments);
	}

	inline any_a<> empty_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("empty_");
		if (!op)
		{
			throw dis("dynamic collection_d::empty_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<collection_d*>(this)));
	}

	inline bool empty() const
	{ return empty_(); }

	inline any_a<> push_front__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("push_front_");
		if (!op)
		{
			throw dis("dynamic collection_d::push_front_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline collection_a< _key , _value , _element > push_front_(_element const& thing)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("push_front_");
		if (!op)
		{
			throw dis("dynamic collection_d::push_front_ passed non-existent member");
		}
		return cast<collection_a< _key , _value , _element >>(variadic_operate(op, *this, thing));
	}

	inline void push_front(_element const & thing )
	{ push_front_(thing); }

	inline any_a<> pop_front__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("pop_front_");
		if (!op)
		{
			throw dis("dynamic collection_d::pop_front_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline _element pop_front_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("pop_front_");
		if (!op)
		{
			throw dis("dynamic collection_d::pop_front_ passed non-existent member");
		}
		return cast<_element>(variadic_operate(op, *this));
	}

	inline any_a<> push_back__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("push_back_");
		if (!op)
		{
			throw dis("dynamic collection_d::push_back_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline collection_a< _key , _value , _element > push_back_(_element const& thing)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("push_back_");
		if (!op)
		{
			throw dis("dynamic collection_d::push_back_ passed non-existent member");
		}
		return cast<collection_a< _key , _value , _element >>(variadic_operate(op, *this, thing));
	}

	inline void push_back(_element const & thing )
	{ push_back_(thing); }

	inline any_a<> pop_back__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("pop_back_");
		if (!op)
		{
			throw dis("dynamic collection_d::pop_back_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline _element pop_back_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("pop_back_");
		if (!op)
		{
			throw dis("dynamic collection_d::pop_back_ passed non-existent member");
		}
		return cast<_element>(variadic_operate(op, *this));
	}

	inline any_a<> self_assign__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("self_assign_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_assign_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline collection_a< _key , _value , _element > self_assign_(range_a< _element > const& range)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("self_assign_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_assign_ passed non-existent member");
		}
		return cast<collection_a< _key , _value , _element >>(variadic_operate(op, *this, range));
	}

	inline any_a<> self_add__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("self_add_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_add_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline collection_a< _key , _value , _element > self_add_(range_a< _element > const& range)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("self_add_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_add_ passed non-existent member");
		}
		return cast<collection_a< _key , _value , _element >>(variadic_operate(op, *this, range));
	}

	inline any_a<> add__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("add_");
		if (!op)
		{
			throw dis("dynamic collection_d::add_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), arguments);
	}

	inline collection_a< _key , _value , _element > add_(range_a< _element > const& range) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("add_");
		if (!op)
		{
			throw dis("dynamic collection_d::add_ passed non-existent member");
		}
		return cast<collection_a< _key , _value , _element >>(variadic_operate(op, *const_cast<collection_d*>(this), range));
	}

	inline any_a<> self_subtract__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_subtract_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline collection_a< _key , _value , _element > self_subtract_(range_a< _element > const& range)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic collection_d::self_subtract_ passed non-existent member");
		}
		return cast<collection_a< _key , _value , _element >>(variadic_operate(op, *this, range));
	}

	inline any_a<> subtract__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("subtract_");
		if (!op)
		{
			throw dis("dynamic collection_d::subtract_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), arguments);
	}

	inline collection_a< _key , _value , _element > subtract_(range_a< _element > const& range) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("subtract_");
		if (!op)
		{
			throw dis("dynamic collection_d::subtract_ passed non-existent member");
		}
		return cast<collection_a< _key , _value , _element >>(variadic_operate(op, *const_cast<collection_d*>(this), range));
	}

	inline any_a<> read_lock__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("read_lock_");
		if (!op)
		{
			throw dis("dynamic collection_d::read_lock_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), arguments);
	}

	inline any_a<> read_lock_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("read_lock_");
		if (!op)
		{
			throw dis("dynamic collection_d::read_lock_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<collection_d*>(this)));
	}

	inline any_a<> write_lock__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("write_lock_");
		if (!op)
		{
			throw dis("dynamic collection_d::write_lock_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), arguments);
	}

	inline any_a<> write_lock_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("write_lock_");
		if (!op)
		{
			throw dis("dynamic collection_d::write_lock_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<collection_d*>(this)));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit collection_d(any_a<> const& thing)
		: range_d< _element >{ thing }
	{}

	explicit collection_d(any_a<>& thing, any_a<>::___reference_tag___)
		: range_d< _element >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit collection_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: range_d< _element >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
