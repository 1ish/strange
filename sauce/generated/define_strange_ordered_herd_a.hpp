
namespace strange
{

template <typename _1 = void>
class ordered_herd_d;

template <typename _1 = void>
inline ordered_herd_d<_1> ___ordered_herd_dynamic___(any_a<> const& thing); 

template <typename _1>
class ordered_herd_a : public herd_a<>
{
public:
	inline bool operator==(ordered_herd_a < > const & herd ) const
	{ assert(any_a<>::___handle___); return ___read___().operator==(herd); }

	inline bool operator!=(ordered_herd_a < > const & herd ) const
	{ assert(any_a<>::___handle___); return ___read___().operator!=(herd); }

	inline bool operator<(ordered_herd_a < > const & herd ) const
	{ assert(any_a<>::___handle___); return ___read___().operator<(herd); }

	inline bool operator>(ordered_herd_a < > const & herd ) const
	{ assert(any_a<>::___handle___); return ___read___().operator>(herd); }

	inline bool operator<=(ordered_herd_a < > const & herd ) const
	{ assert(any_a<>::___handle___); return ___read___().operator<=(herd); }

	inline bool operator>=(ordered_herd_a < > const & herd ) const
	{ assert(any_a<>::___handle___); return ___read___().operator>=(herd); }

	inline bidirectional_extractor_data_a < typename std :: set < any_a < > > :: const_iterator > extract_begin() const
	{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

	inline bidirectional_extractor_data_a < typename std :: set < any_a < > > :: const_iterator > extract_end() const
	{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

	inline std :: set < any_a < > > const & extract_set() const
	{ assert(any_a<>::___handle___); return ___read___().extract_set(); }

	inline std :: set < any_a < > > & mutate_set()
	{ assert(any_a<>::___handle___); return ___write___().mutate_set(); }

protected:
	struct ___ordered_herd_a_handle_base___ : herd_a<>::template ___herd_a_handle_base___
	{
		virtual bool operator==(ordered_herd_a < > const & herd ) const = 0;
		virtual bool operator!=(ordered_herd_a < > const & herd ) const = 0;
		virtual bool operator<(ordered_herd_a < > const & herd ) const = 0;
		virtual bool operator>(ordered_herd_a < > const & herd ) const = 0;
		virtual bool operator<=(ordered_herd_a < > const & herd ) const = 0;
		virtual bool operator>=(ordered_herd_a < > const & herd ) const = 0;
		virtual bidirectional_extractor_data_a < typename std :: set < any_a < > > :: const_iterator > extract_begin() const = 0;
		virtual bidirectional_extractor_data_a < typename std :: set < any_a < > > :: const_iterator > extract_end() const = 0;
		virtual std :: set < any_a < > > const & extract_set() const = 0;
		virtual std :: set < any_a < > > & mutate_set() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___ordered_herd_a_handle_base___>
	struct ___ordered_herd_a_handle___ : herd_a<>::template ___herd_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_herd_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: herd_a<>::template ___herd_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_herd_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: herd_a<>::template ___herd_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___ordered_herd_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: herd_a<>::template ___herd_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(ordered_herd_a < > const & herd ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(herd); }

		virtual inline bool operator!=(ordered_herd_a < > const & herd ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(herd); }

		virtual inline bool operator<(ordered_herd_a < > const & herd ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(herd); }

		virtual inline bool operator>(ordered_herd_a < > const & herd ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(herd); }

		virtual inline bool operator<=(ordered_herd_a < > const & herd ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(herd); }

		virtual inline bool operator>=(ordered_herd_a < > const & herd ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(herd); }

		virtual inline bidirectional_extractor_data_a < typename std :: set < any_a < > > :: const_iterator > extract_begin() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

		virtual inline bidirectional_extractor_data_a < typename std :: set < any_a < > > :: const_iterator > extract_end() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

		virtual inline std :: set < any_a < > > const & extract_set() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_set(); }

		virtual inline std :: set < any_a < > > & mutate_set() final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_set(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___ordered_herd_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___ordered_herd_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___ordered_herd_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___ordered_herd_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___ordered_herd_a_handle_final___ final : ___ordered_herd_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_herd_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___ordered_herd_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_herd_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___ordered_herd_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___ordered_herd_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___ordered_herd_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline herd_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___ordered_herd_a_handle_final___>(___ordered_herd_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___ordered_herd_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___ordered_herd_a_handle_final___<___TTT___&>
	{
		inline ___ordered_herd_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___ordered_herd_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___ordered_herd_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___ordered_herd_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___ordered_herd_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___ordered_herd_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline ordered_herd_a val(ordered_herd_a const& other) noexcept
	{
		return ordered_herd_a{ other };
	}

	static inline ordered_herd_a ref(ordered_herd_a& other) noexcept
	{
		return ordered_herd_a(other, any_a<>::___reference_tag___{});
	}

	static inline ordered_herd_a dup(ordered_herd_a& other) noexcept
	{
		return ordered_herd_a(other, any_a<>::___duplicate_tag___{});
	}

	inline ordered_herd_a() = default;

	inline ordered_herd_a(ordered_herd_a& other, any_a<>::___reference_tag___) noexcept
		: herd_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline ordered_herd_a(ordered_herd_a& other, any_a<>::___duplicate_tag___) noexcept
		: herd_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline ordered_herd_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: herd_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline ordered_herd_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: herd_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<ordered_herd_a, std::decay_t<___TTT___>>::value>>
	explicit inline ordered_herd_a(___TTT___ value) noexcept
		: herd_a<>{ std::make_shared<___ordered_herd_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline ordered_herd_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: herd_a<>{ std::make_shared<___ordered_herd_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline ordered_herd_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<ordered_herd_a, std::decay_t<___TTT___>>::value>>
	inline ordered_herd_a& operator=(___TTT___ value) noexcept
	{
		ordered_herd_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(thing.___handle___) };
	}

	static inline ordered_herd_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return ordered_herd_a{ thing.___handle___ };
		}
		return ordered_herd_a{ ordered_herd_d<_1>{ thing } };
	}

	static inline ordered_herd_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return ordered_herd_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return ordered_herd_a{ ordered_herd_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::ordered_herd");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = herd_a<>::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = herd_a<>::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = herd_a<>::template ___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline ordered_herd_a create(Args&&... args)
	{
		return ordered_herd_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class ordered_herd_a

template <typename _1>
class ordered_herd_d : public herd_d<>
{
public:
	inline bool operator==(ordered_herd_a < > const & herd ) const
	{ throw dis("dynamic ordered_herd_d::operator==(herd) not available"); }

	inline bool operator!=(ordered_herd_a < > const & herd ) const
	{ throw dis("dynamic ordered_herd_d::operator!=(herd) not available"); }

	inline bool operator<(ordered_herd_a < > const & herd ) const
	{ throw dis("dynamic ordered_herd_d::operator<(herd) not available"); }

	inline bool operator>(ordered_herd_a < > const & herd ) const
	{ throw dis("dynamic ordered_herd_d::operator>(herd) not available"); }

	inline bool operator<=(ordered_herd_a < > const & herd ) const
	{ throw dis("dynamic ordered_herd_d::operator<=(herd) not available"); }

	inline bool operator>=(ordered_herd_a < > const & herd ) const
	{ throw dis("dynamic ordered_herd_d::operator>=(herd) not available"); }

	inline bidirectional_extractor_data_a < typename std :: set < any_a < > > :: const_iterator > extract_begin() const
	{ throw dis("dynamic ordered_herd_d::extract_begin() not available"); }

	inline bidirectional_extractor_data_a < typename std :: set < any_a < > > :: const_iterator > extract_end() const
	{ throw dis("dynamic ordered_herd_d::extract_end() not available"); }

	inline std :: set < any_a < > > const & extract_set() const
	{ throw dis("dynamic ordered_herd_d::extract_set() not available"); }

	inline std :: set < any_a < > > & mutate_set()
	{ throw dis("dynamic ordered_herd_d::mutate_set() not available"); }

	void ___weak___(herd_d<>::___WEAK___ const& weak) const {}

	explicit ordered_herd_d(any_a<> const& thing)
		: herd_d{ thing }
	{}

	explicit ordered_herd_d(any_a<>& thing, any_a<>::___reference_tag___)
		: herd_d{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit ordered_herd_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: herd_d{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
