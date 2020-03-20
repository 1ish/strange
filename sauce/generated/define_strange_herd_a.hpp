
namespace strange
{

template <typename _1 = void>
class herd_d;

template <typename _1 = void>
inline herd_d<_1> ___herd_dynamic___(any_a<> const& thing); 

template <typename _1>
class herd_a : public collection_a<>
{
public:
	inline bool has_string(std :: string const & s ) const
	{ assert(any_a<>::___handle___); return ___read___().has_string(s); }

	inline any_a < > at_string(std :: string const & s ) const
	{ assert(any_a<>::___handle___); return ___read___().at_string(s); }

	inline void update_thing(any_a < > const & thing )
	{ assert(any_a<>::___handle___); ___write___().update_thing(thing); }

	inline void update_string(std :: string const & s )
	{ assert(any_a<>::___handle___); ___write___().update_string(s); }

	inline bool insert_thing(any_a < > const & thing )
	{ assert(any_a<>::___handle___); return ___write___().insert_thing(thing); }

	inline bool insert_string(std :: string const & s )
	{ assert(any_a<>::___handle___); return ___write___().insert_string(s); }

	inline bool erase_string(std :: string const & s )
	{ assert(any_a<>::___handle___); return ___write___().erase_string(s); }

protected:
	struct ___herd_a_handle_base___ : collection_a<>::template ___collection_a_handle_base___
	{
		virtual bool has_string(std :: string const & s ) const = 0;
		virtual any_a < > at_string(std :: string const & s ) const = 0;
		virtual void update_thing(any_a < > const & thing ) = 0;
		virtual void update_string(std :: string const & s ) = 0;
		virtual bool insert_thing(any_a < > const & thing ) = 0;
		virtual bool insert_string(std :: string const & s ) = 0;
		virtual bool erase_string(std :: string const & s ) = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___herd_a_handle_base___>
	struct ___herd_a_handle___ : collection_a<>::template ___collection_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___herd_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: collection_a<>::template ___collection_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___herd_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: collection_a<>::template ___collection_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___herd_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: collection_a<>::template ___collection_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool has_string(std :: string const & s ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.has_string(s); }

		virtual inline any_a < > at_string(std :: string const & s ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.at_string(s); }

		virtual inline void update_thing(any_a < > const & thing ) final
		{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_thing(thing); }

		virtual inline void update_string(std :: string const & s ) final
		{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_string(s); }

		virtual inline bool insert_thing(any_a < > const & thing ) final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_thing(thing); }

		virtual inline bool insert_string(std :: string const & s ) final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_string(s); }

		virtual inline bool erase_string(std :: string const & s ) final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.erase_string(s); }

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

		virtual inline collection_a<>::template ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___herd_a_handle_final___>(___herd_a_handle___<___TTT___>::___value___);
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
		: collection_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline herd_a(herd_a& other, any_a<>::___duplicate_tag___) noexcept
		: collection_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline herd_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: collection_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___herd_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline herd_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: collection_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___herd_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<herd_a, std::decay_t<___TTT___>>::value>>
	explicit inline herd_a(___TTT___ value) noexcept
		: collection_a<>{ std::make_shared<___herd_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline herd_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: collection_a<>{ std::make_shared<___herd_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline herd_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
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
		return herd_a{ herd_d<_1>{ thing } };
	}

	static inline herd_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___herd_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return herd_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return herd_a{ herd_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::herd");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = collection_a<>::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = collection_a<>::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = collection_a<>::template ___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline herd_a create(Args&&... args)
	{
		return herd_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class herd_a

template <typename _1>
class herd_d : public collection_d<>
{
public:
	inline bool has_string(std :: string const & s ) const
	{ return has(sym(s)); }

	inline any_a < > at_string(std :: string const & s ) const
	{ return at_(sym(s)); }

	inline void update_thing(any_a < > const & thing )
	{ update_(thing, no()); }

	inline void update_string(std :: string const & s )
	{ update_thing(sym(s)); }

	inline bool insert_thing(any_a < > const & thing )
	{ return insert_(thing, no()); }

	inline bool insert_string(std :: string const & s )
	{ return insert_thing(sym(s)); }

	inline bool erase_string(std :: string const & s )
	{ return erase(sym(s)); }

	void ___weak___(collection_d<>::template ___WEAK___ const& weak) const {}

	explicit herd_d(any_a<> const& thing)
		: collection_d{ thing }
	{}

	explicit herd_d(any_a<>& thing, any_a<>::___reference_tag___)
		: collection_d{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit herd_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: collection_d{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
