
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
	inline any_a<> has__(list_a<> const& ___arguments___) const;

	inline any_a<> has_(_key const& key) const;

	inline bool has(_key const & key ) const;

	inline any_a<> at__(list_a<> const& ___arguments___) const;

	inline _value at_(_key const& key) const;

	inline any_a<> update__(list_a<> const& ___arguments___);

	inline _value update_(_key const& key, _value const& value);

	inline void update(_key const & key , _value const & value );

	inline any_a<> insert__(list_a<> const& ___arguments___);

	inline any_a<> insert_(_key const& key, _value const& value);

	inline bool insert(_key const & key , _value const & value );

	inline any_a<> erase__(list_a<> const& ___arguments___);

	inline any_a<> erase_(_key const& key);

	inline bool erase(_key const & key );

	inline any_a<> clear__(list_a<> const& ___arguments___);

	inline collection_a< _key , _value , _element > clear_();

	inline void clear();

	inline any_a<> size__(list_a<> const& ___arguments___) const;

	inline number_data_int64_a<> size_() const;

	inline int64_t size() const;

	inline any_a<> empty__(list_a<> const& ___arguments___) const;

	inline any_a<> empty_() const;

	inline bool empty() const;

	inline any_a<> push_front__(list_a<> const& ___arguments___);

	inline collection_a< _key , _value , _element > push_front_(_element const& thing);

	inline void push_front(_element const & thing );

	inline any_a<> pop_front__(list_a<> const& ___arguments___);

	inline _element pop_front_();

	inline any_a<> push_back__(list_a<> const& ___arguments___);

	inline collection_a< _key , _value , _element > push_back_(_element const& thing);

	inline void push_back(_element const & thing );

	inline any_a<> pop_back__(list_a<> const& ___arguments___);

	inline _element pop_back_();

	inline any_a<> self_assign__(list_a<> const& ___arguments___);

	inline collection_a self_assign_(range_a< _element > const& range);

	inline any_a<> self_add__(list_a<> const& ___arguments___);

	inline collection_a self_add_(range_a< _element > const& range);

	inline collection_a& operator+=(range_a< _element > const& range);

	inline any_a<> add__(list_a<> const& ___arguments___) const;

	inline collection_a< _key , _value , _element > add_(range_a< _element > const& range) const;

	inline collection_a< _key , _value , _element > operator+(range_a< _element > const& range) const;

	inline any_a<> self_subtract__(list_a<> const& ___arguments___);

	inline collection_a self_subtract_(range_a< _element > const& range);

	inline collection_a& operator-=(range_a< _element > const& range);

	inline any_a<> subtract__(list_a<> const& ___arguments___) const;

	inline collection_a< _key , _value , _element > subtract_(range_a< _element > const& range) const;

	inline collection_a< _key , _value , _element > operator-(range_a< _element > const& range) const;

	inline any_a<> read_lock__(list_a<> const& ___arguments___) const;

	inline any_a<> read_lock_() const;

	inline any_a<> write_lock__(list_a<> const& ___arguments___) const;

	inline any_a<> write_lock_() const;

protected:
	struct ___collection_a_handle_base___ : range_a< _element >::___range_a_handle_base___
	{
		virtual any_a<> has_(_key const& key) const = 0;
		virtual bool has(_key const & key ) const = 0;
		virtual _value at_(_key const& key) const = 0;
		virtual _value update_(_key const& key, _value const& value) = 0;
		virtual void update(_key const & key , _value const & value ) = 0;
		virtual any_a<> insert_(_key const& key, _value const& value) = 0;
		virtual bool insert(_key const & key , _value const & value ) = 0;
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

		virtual inline _value at_(_key const& key) const final;

		virtual inline _value update_(_key const& key, _value const& value) final;

		virtual inline void update(_key const & key , _value const & value ) final;

		virtual inline any_a<> insert_(_key const& key, _value const& value) final;

		virtual inline bool insert(_key const & key , _value const & value ) final;

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
			return std_make_shared<___collection_a_handle_final___>(___collection_a_handle___<___TTT___>::___value___);
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
	explicit inline collection_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: range_a< _element >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline collection_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: range_a< _element >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___collection_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<collection_a, std::decay_t<___TTT___>>::value>>
	explicit inline collection_a(___TTT___ value) noexcept
		: range_a< _element >{ std_make_shared<___collection_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline collection_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: range_a< _element >{ std_make_shared<___collection_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline collection_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
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

	static inline cat_a<> ___cat___();

	static inline unordered_herd_a<> ___cats___();

	static inline kind_a<> ___kind___();

	static inline unordered_herd_a<> ___kinds___();

	static inline unordered_shoal_a<> ___operations___();

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
	inline any_a<> has__(list_a<> const& arguments) const
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

	inline any_a<> at__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("at_");
		if (!op)
		{
			throw dis("dynamic collection_d::at_ passed non-existent member");
		}
		return op.operate(*const_cast<collection_d*>(this), arguments);
	}

	inline _value at_(_key const& key) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("at_");
		if (!op)
		{
			throw dis("dynamic collection_d::at_ passed non-existent member");
		}
		return cast<_value>(variadic_operate(op, *const_cast<collection_d*>(this), key));
	}

	inline any_a<> update__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("update_");
		if (!op)
		{
			throw dis("dynamic collection_d::update_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline _value update_(_key const& key, _value const& value)
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

	inline any_a<> insert__(list_a<> const& arguments)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("insert_");
		if (!op)
		{
			throw dis("dynamic collection_d::insert_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline any_a<> insert_(_key const& key, _value const& value)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("insert_");
		if (!op)
		{
			throw dis("dynamic collection_d::insert_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, key, value));
	}

	inline bool insert(_key const & key , _value const & value )
	{ return insert_(key, value); }

	inline any_a<> erase__(list_a<> const& arguments)
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

	inline any_a<> clear__(list_a<> const& arguments)
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

	inline any_a<> size__(list_a<> const& arguments) const
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

	inline any_a<> empty__(list_a<> const& arguments) const
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

	inline any_a<> push_front__(list_a<> const& arguments)
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

	inline any_a<> pop_front__(list_a<> const& arguments)
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

	inline any_a<> push_back__(list_a<> const& arguments)
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

	inline any_a<> pop_back__(list_a<> const& arguments)
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

	inline any_a<> self_assign__(list_a<> const& arguments)
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

	inline any_a<> self_add__(list_a<> const& arguments)
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

	inline any_a<> add__(list_a<> const& arguments) const
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

	inline any_a<> self_subtract__(list_a<> const& arguments)
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

	inline any_a<> subtract__(list_a<> const& arguments) const
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

	inline any_a<> read_lock__(list_a<> const& arguments) const
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

	inline any_a<> write_lock__(list_a<> const& arguments) const
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
