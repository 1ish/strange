
namespace strange
{

template <typename _1 = void>
class ordered_shoal_d;

template <typename _1 = void>
inline ordered_shoal_d<_1> ___ordered_shoal_dynamic___(any_a<> const& thing); 

template <typename _1>
class ordered_shoal_a : public shoal_a<>
{
public:
	inline bool operator==(ordered_shoal_a < > const & shoal ) const
	{ assert(any_a<>::___handle___); return ___read___().operator==(shoal); }

	inline bool operator!=(ordered_shoal_a < > const & shoal ) const
	{ assert(any_a<>::___handle___); return ___read___().operator!=(shoal); }

	inline bool operator<(ordered_shoal_a < > const & shoal ) const
	{ assert(any_a<>::___handle___); return ___read___().operator<(shoal); }

	inline bool operator>(ordered_shoal_a < > const & shoal ) const
	{ assert(any_a<>::___handle___); return ___read___().operator>(shoal); }

	inline bool operator<=(ordered_shoal_a < > const & shoal ) const
	{ assert(any_a<>::___handle___); return ___read___().operator<=(shoal); }

	inline bool operator>=(ordered_shoal_a < > const & shoal ) const
	{ assert(any_a<>::___handle___); return ___read___().operator>=(shoal); }

	inline bidirectional_extractor_data_a < typename std :: map < any_a < > , any_a < > > :: const_iterator > extract_begin() const
	{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

	inline bidirectional_extractor_data_a < typename std :: map < any_a < > , any_a < > > :: const_iterator > extract_end() const
	{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

	inline bidirectional_mutator_data_a < typename std :: map < any_a < > , any_a < > > :: iterator > mutate_begin()
	{ assert(any_a<>::___handle___); return ___write___().mutate_begin(); }

	inline bidirectional_mutator_data_a < typename std :: map < any_a < > , any_a < > > :: iterator > mutate_end()
	{ assert(any_a<>::___handle___); return ___write___().mutate_end(); }

	inline std :: map < any_a < > , any_a < > > const & extract_map() const
	{ assert(any_a<>::___handle___); return ___read___().extract_map(); }

	inline std :: map < any_a < > , any_a < > > & mutate_map()
	{ assert(any_a<>::___handle___); return ___write___().mutate_map(); }

protected:
	struct ___ordered_shoal_a_handle_base___ : shoal_a<>::template ___shoal_a_handle_base___
	{
		virtual bool operator==(ordered_shoal_a < > const & shoal ) const = 0;
		virtual bool operator!=(ordered_shoal_a < > const & shoal ) const = 0;
		virtual bool operator<(ordered_shoal_a < > const & shoal ) const = 0;
		virtual bool operator>(ordered_shoal_a < > const & shoal ) const = 0;
		virtual bool operator<=(ordered_shoal_a < > const & shoal ) const = 0;
		virtual bool operator>=(ordered_shoal_a < > const & shoal ) const = 0;
		virtual bidirectional_extractor_data_a < typename std :: map < any_a < > , any_a < > > :: const_iterator > extract_begin() const = 0;
		virtual bidirectional_extractor_data_a < typename std :: map < any_a < > , any_a < > > :: const_iterator > extract_end() const = 0;
		virtual bidirectional_mutator_data_a < typename std :: map < any_a < > , any_a < > > :: iterator > mutate_begin() = 0;
		virtual bidirectional_mutator_data_a < typename std :: map < any_a < > , any_a < > > :: iterator > mutate_end() = 0;
		virtual std :: map < any_a < > , any_a < > > const & extract_map() const = 0;
		virtual std :: map < any_a < > , any_a < > > & mutate_map() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___ordered_shoal_a_handle_base___>
	struct ___ordered_shoal_a_handle___ : shoal_a<>::template ___shoal_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_shoal_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: shoal_a<>::template ___shoal_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_shoal_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: shoal_a<>::template ___shoal_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___ordered_shoal_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: shoal_a<>::template ___shoal_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(ordered_shoal_a < > const & shoal ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(shoal); }

		virtual inline bool operator!=(ordered_shoal_a < > const & shoal ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(shoal); }

		virtual inline bool operator<(ordered_shoal_a < > const & shoal ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(shoal); }

		virtual inline bool operator>(ordered_shoal_a < > const & shoal ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(shoal); }

		virtual inline bool operator<=(ordered_shoal_a < > const & shoal ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(shoal); }

		virtual inline bool operator>=(ordered_shoal_a < > const & shoal ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(shoal); }

		virtual inline bidirectional_extractor_data_a < typename std :: map < any_a < > , any_a < > > :: const_iterator > extract_begin() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

		virtual inline bidirectional_extractor_data_a < typename std :: map < any_a < > , any_a < > > :: const_iterator > extract_end() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

		virtual inline bidirectional_mutator_data_a < typename std :: map < any_a < > , any_a < > > :: iterator > mutate_begin() final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin(); }

		virtual inline bidirectional_mutator_data_a < typename std :: map < any_a < > , any_a < > > :: iterator > mutate_end() final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end(); }

		virtual inline std :: map < any_a < > , any_a < > > const & extract_map() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_map(); }

		virtual inline std :: map < any_a < > , any_a < > > & mutate_map() final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_map(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___ordered_shoal_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___ordered_shoal_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___ordered_shoal_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___ordered_shoal_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___ordered_shoal_a_handle_final___ final : ___ordered_shoal_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_shoal_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___ordered_shoal_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_shoal_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___ordered_shoal_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___ordered_shoal_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___ordered_shoal_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___ordered_shoal_a_handle_final___>(___ordered_shoal_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___ordered_shoal_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___ordered_shoal_a_handle_final___<___TTT___&>
	{
		inline ___ordered_shoal_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___ordered_shoal_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___ordered_shoal_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___ordered_shoal_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___ordered_shoal_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___ordered_shoal_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline ordered_shoal_a val(ordered_shoal_a const& other) noexcept
	{
		return ordered_shoal_a{ other };
	}

	static inline ordered_shoal_a ref(ordered_shoal_a& other) noexcept
	{
		return ordered_shoal_a(other, any_a<>::___reference_tag___{});
	}

	static inline ordered_shoal_a dup(ordered_shoal_a& other) noexcept
	{
		return ordered_shoal_a(other, any_a<>::___duplicate_tag___{});
	}

	inline ordered_shoal_a() = default;

	inline ordered_shoal_a(ordered_shoal_a& other, any_a<>::___reference_tag___) noexcept
		: shoal_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline ordered_shoal_a(ordered_shoal_a& other, any_a<>::___duplicate_tag___) noexcept
		: shoal_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline ordered_shoal_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: shoal_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___ordered_shoal_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline ordered_shoal_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: shoal_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___ordered_shoal_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<ordered_shoal_a, std::decay_t<___TTT___>>::value>>
	explicit inline ordered_shoal_a(___TTT___ value) noexcept
		: shoal_a<>{ std::make_shared<___ordered_shoal_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline ordered_shoal_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: shoal_a<>{ std::make_shared<___ordered_shoal_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline ordered_shoal_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___ordered_shoal_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<ordered_shoal_a, std::decay_t<___TTT___>>::value>>
	inline ordered_shoal_a& operator=(___TTT___ value) noexcept
	{
		ordered_shoal_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___ordered_shoal_a_handle_base___>(thing.___handle___) };
	}

	static inline ordered_shoal_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___ordered_shoal_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return ordered_shoal_a{ thing.___handle___ };
		}
		return ordered_shoal_a{ ordered_shoal_d<_1>{ thing } };
	}

	static inline ordered_shoal_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___ordered_shoal_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return ordered_shoal_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return ordered_shoal_a{ ordered_shoal_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::ordered_shoal");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = shoal_a<>::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = shoal_a<>::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = shoal_a<>::template ___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline ordered_shoal_a create(Args&&... args)
	{
		return ordered_shoal_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class ordered_shoal_a

template <typename _1>
class ordered_shoal_d : public shoal_d<>
{
public:
	inline bool operator==(ordered_shoal_a < > const & shoal ) const
	{ throw dis("dynamic ordered_shoal_d::operator==(shoal) not available"); }

	inline bool operator!=(ordered_shoal_a < > const & shoal ) const
	{ throw dis("dynamic ordered_shoal_d::operator!=(shoal) not available"); }

	inline bool operator<(ordered_shoal_a < > const & shoal ) const
	{ throw dis("dynamic ordered_shoal_d::operator<(shoal) not available"); }

	inline bool operator>(ordered_shoal_a < > const & shoal ) const
	{ throw dis("dynamic ordered_shoal_d::operator>(shoal) not available"); }

	inline bool operator<=(ordered_shoal_a < > const & shoal ) const
	{ throw dis("dynamic ordered_shoal_d::operator<=(shoal) not available"); }

	inline bool operator>=(ordered_shoal_a < > const & shoal ) const
	{ throw dis("dynamic ordered_shoal_d::operator>=(shoal) not available"); }

	inline bidirectional_extractor_data_a < typename std :: map < any_a < > , any_a < > > :: const_iterator > extract_begin() const
	{ throw dis("dynamic ordered_shoal_d::extract_begin() not available"); }

	inline bidirectional_extractor_data_a < typename std :: map < any_a < > , any_a < > > :: const_iterator > extract_end() const
	{ throw dis("dynamic ordered_shoal_d::extract_end() not available"); }

	inline bidirectional_mutator_data_a < typename std :: map < any_a < > , any_a < > > :: iterator > mutate_begin()
	{ throw dis("dynamic ordered_shoal_d::mutate_begin() not available"); }

	inline bidirectional_mutator_data_a < typename std :: map < any_a < > , any_a < > > :: iterator > mutate_end()
	{ throw dis("dynamic ordered_shoal_d::mutate_end() not available"); }

	inline std :: map < any_a < > , any_a < > > const & extract_map() const
	{ throw dis("dynamic ordered_shoal_d::extract_map() not available"); }

	inline std :: map < any_a < > , any_a < > > & mutate_map()
	{ throw dis("dynamic ordered_shoal_d::mutate_map() not available"); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit ordered_shoal_d(any_a<> const& thing)
		: shoal_d{ thing }
	{}

	explicit ordered_shoal_d(any_a<>& thing, any_a<>::___reference_tag___)
		: shoal_d{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit ordered_shoal_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: shoal_d{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
