
namespace strange
{

template <typename _1_>
class lake_d;

template <typename _1_>
inline lake_d<_1_> ___lake_dynamic___(any_a<> const& thing); 

template <typename _1_>
class lake_a : public inventory_a<>
{
public:
	inline bool operator==(lake_a < _1_ > const & lake ) const
	{ assert(___handle___); return ___read___().operator==(lake); }

	inline bool operator!=(lake_a < _1_ > const & lake ) const
	{ assert(___handle___); return ___read___().operator!=(lake); }

	inline bool operator<(lake_a < _1_ > const & lake ) const
	{ assert(___handle___); return ___read___().operator<(lake); }

	inline bool operator>(lake_a < _1_ > const & lake ) const
	{ assert(___handle___); return ___read___().operator>(lake); }

	inline bool operator<=(lake_a < _1_ > const & lake ) const
	{ assert(___handle___); return ___read___().operator<=(lake); }

	inline bool operator>=(lake_a < _1_ > const & lake ) const
	{ assert(___handle___); return ___read___().operator>=(lake); }

	inline random_access_extractor_data_a < typename std :: vector < _1_ > :: const_iterator > extract_begin() const
	{ assert(___handle___); return ___read___().extract_begin(); }

	inline random_access_extractor_data_a < typename std :: vector < _1_ > :: const_iterator > extract_end() const
	{ assert(___handle___); return ___read___().extract_end(); }

	inline random_access_mutator_data_a < typename std :: vector < _1_ > :: iterator > mutate_begin()
	{ assert(___handle___); return ___write___().mutate_begin(); }

	inline random_access_mutator_data_a < typename std :: vector < _1_ > :: iterator > mutate_end()
	{ assert(___handle___); return ___write___().mutate_end(); }

	inline std :: vector < _1_ > const & extract_vector() const
	{ assert(___handle___); return ___read___().extract_vector(); }

	inline std :: vector < _1_ > & mutate_vector()
	{ assert(___handle___); return ___write___().mutate_vector(); }

protected:
	struct ___lake_a_handle_base___ : ___inventory_a_handle_base___
	{
		virtual bool operator==(lake_a < _1_ > const & lake ) const = 0;
		virtual bool operator!=(lake_a < _1_ > const & lake ) const = 0;
		virtual bool operator<(lake_a < _1_ > const & lake ) const = 0;
		virtual bool operator>(lake_a < _1_ > const & lake ) const = 0;
		virtual bool operator<=(lake_a < _1_ > const & lake ) const = 0;
		virtual bool operator>=(lake_a < _1_ > const & lake ) const = 0;
		virtual random_access_extractor_data_a < typename std :: vector < _1_ > :: const_iterator > extract_begin() const = 0;
		virtual random_access_extractor_data_a < typename std :: vector < _1_ > :: const_iterator > extract_end() const = 0;
		virtual random_access_mutator_data_a < typename std :: vector < _1_ > :: iterator > mutate_begin() = 0;
		virtual random_access_mutator_data_a < typename std :: vector < _1_ > :: iterator > mutate_end() = 0;
		virtual std :: vector < _1_ > const & extract_vector() const = 0;
		virtual std :: vector < _1_ > & mutate_vector() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___lake_a_handle_base___>
	struct ___lake_a_handle___ : ___inventory_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___lake_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___inventory_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___lake_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___inventory_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___lake_a_handle___(___variadic_tag___, Args&&... args)
			: ___inventory_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(lake_a < _1_ > const & lake ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(lake); }

		virtual inline bool operator!=(lake_a < _1_ > const & lake ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(lake); }

		virtual inline bool operator<(lake_a < _1_ > const & lake ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(lake); }

		virtual inline bool operator>(lake_a < _1_ > const & lake ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(lake); }

		virtual inline bool operator<=(lake_a < _1_ > const & lake ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(lake); }

		virtual inline bool operator>=(lake_a < _1_ > const & lake ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(lake); }

		virtual inline random_access_extractor_data_a < typename std :: vector < _1_ > :: const_iterator > extract_begin() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

		virtual inline random_access_extractor_data_a < typename std :: vector < _1_ > :: const_iterator > extract_end() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

		virtual inline random_access_mutator_data_a < typename std :: vector < _1_ > :: iterator > mutate_begin() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin(); }

		virtual inline random_access_mutator_data_a < typename std :: vector < _1_ > :: iterator > mutate_end() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end(); }

		virtual inline std :: vector < _1_ > const & extract_vector() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_vector(); }

		virtual inline std :: vector < _1_ > & mutate_vector() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_vector(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___lake_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___lake_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___lake_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___lake_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___lake_a_handle_final___ final : ___lake_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___lake_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___lake_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___lake_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___lake_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___lake_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___lake_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___lake_a_handle_final___>(___lake_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___lake_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___lake_a_handle_final___<___TTT___&>
	{
		inline ___lake_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___lake_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___lake_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___lake_a_handle_base___ const>(___handle___);
	}

	inline ___lake_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___lake_a_handle_base___>(___handle___);
	}

public:
	static inline lake_a val(lake_a const& other) noexcept
	{
		return lake_a{ other };
	}

	static inline lake_a ref(lake_a& other) noexcept
	{
		return lake_a(other, ___reference_tag___{});
	}

	static inline lake_a dup(lake_a& other) noexcept
	{
		return lake_a(other, ___duplicate_tag___{});
	}

	inline lake_a() = default;

	inline lake_a(lake_a& other, ___reference_tag___) noexcept
		: inventory_a(other, ___reference_tag___{})
	{}

	inline lake_a(lake_a& other, ___duplicate_tag___) noexcept
		: inventory_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline lake_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: inventory_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___lake_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline lake_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: inventory_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___lake_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<lake_a, std::decay_t<___TTT___>>::value>>
	explicit inline lake_a(___TTT___ value) noexcept
		: inventory_a{ std::make_shared<___lake_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline lake_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: inventory_a{ std::make_shared<___lake_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline lake_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___lake_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<lake_a, std::decay_t<___TTT___>>::value>>
	inline lake_a& operator=(___TTT___ value) noexcept
	{
		lake_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___lake_a_handle_base___>(thing.___handle___) };
	}

	static inline lake_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___lake_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return lake_a{ thing.___handle___ };
		}
		return lake_a{ lake_d<_1_>{ thing } };
	}

	static inline lake_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___lake_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return lake_a(thing.___handle___, ___reference_tag___{});
		}
		return lake_a{ lake_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::lake", flock_vals(kind_create<___kind_a___>(2, "")));
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = inventory_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>(), flock_vals(kind_of<_1_>()));
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = inventory_a::___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = inventory_a::___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline lake_a create(Args&&... args)
	{
		return lake_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class lake_a

template <typename _1_>
class lake_d : public inventory_d<>
{
public:
	inline bool operator==(lake_a < _1_ > const & lake ) const
	{ throw dis("dynamic lake_d::operator==(lake) not available"); }

	inline bool operator!=(lake_a < _1_ > const & lake ) const
	{ throw dis("dynamic lake_d::operator!=(lake) not available"); }

	inline bool operator<(lake_a < _1_ > const & lake ) const
	{ throw dis("dynamic lake_d::operator<(lake) not available"); }

	inline bool operator>(lake_a < _1_ > const & lake ) const
	{ throw dis("dynamic lake_d::operator>(lake) not available"); }

	inline bool operator<=(lake_a < _1_ > const & lake ) const
	{ throw dis("dynamic lake_d::operator<=(lake) not available"); }

	inline bool operator>=(lake_a < _1_ > const & lake ) const
	{ throw dis("dynamic lake_d::operator>=(lake) not available"); }

	inline random_access_extractor_data_a < typename std :: vector < _1_ > :: const_iterator > extract_begin() const
	{ throw dis("dynamic lake_d::extract_begin() not available"); }

	inline random_access_extractor_data_a < typename std :: vector < _1_ > :: const_iterator > extract_end() const
	{ throw dis("dynamic lake_d::extract_end() not available"); }

	inline random_access_mutator_data_a < typename std :: vector < _1_ > :: iterator > mutate_begin()
	{ throw dis("dynamic lake_d::mutate_begin() not available"); }

	inline random_access_mutator_data_a < typename std :: vector < _1_ > :: iterator > mutate_end()
	{ throw dis("dynamic lake_d::mutate_end() not available"); }

	inline std :: vector < _1_ > const & extract_vector() const
	{ throw dis("dynamic lake_d::extract_vector() not available"); }

	inline std :: vector < _1_ > & mutate_vector()
	{ throw dis("dynamic lake_d::mutate_vector() not available"); }

	void ___weak___(inventory_d<>::___WEAK___ const& weak) const {}

	explicit lake_d(any_a<> const& thing)
		: inventory_d<>{ thing }
	{}

	explicit lake_d(any_a<>& thing, ___reference_tag___)
		: inventory_d<>{ thing, ___reference_tag___{} }
	{}

	explicit lake_d(any_a<>& thing, ___duplicate_tag___)
		: inventory_d<>{ thing, ___duplicate_tag___{} }
	{}
};

} // namespace
