
namespace strange
{

template <typename _1 = void>
class flock_d;

template <typename _1 = void>
inline flock_d<_1> ___flock_dynamic___(any_a<> const& thing); 

template <typename _1>
class flock_a : public inventory_a<>
{
public:
	inline bool operator==(flock_a < > const & flock ) const
	{ assert(any_a<>::___handle___); return ___read___().operator==(flock); }

	inline bool operator!=(flock_a < > const & flock ) const
	{ assert(any_a<>::___handle___); return ___read___().operator!=(flock); }

	inline bool operator<(flock_a < > const & flock ) const
	{ assert(any_a<>::___handle___); return ___read___().operator<(flock); }

	inline bool operator>(flock_a < > const & flock ) const
	{ assert(any_a<>::___handle___); return ___read___().operator>(flock); }

	inline bool operator<=(flock_a < > const & flock ) const
	{ assert(any_a<>::___handle___); return ___read___().operator<=(flock); }

	inline bool operator>=(flock_a < > const & flock ) const
	{ assert(any_a<>::___handle___); return ___read___().operator>=(flock); }

	inline random_access_extractor_data_a < typename std :: vector < any_a < > > :: const_iterator > extract_begin() const
	{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

	inline random_access_extractor_data_a < typename std :: vector < any_a < > > :: const_iterator > extract_end() const
	{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

	inline random_access_mutator_data_a < typename std :: vector < any_a < > > :: iterator > mutate_begin()
	{ assert(any_a<>::___handle___); return ___write___().mutate_begin(); }

	inline random_access_mutator_data_a < typename std :: vector < any_a < > > :: iterator > mutate_end()
	{ assert(any_a<>::___handle___); return ___write___().mutate_end(); }

	inline std :: vector < any_a < > > const & extract_vector() const
	{ assert(any_a<>::___handle___); return ___read___().extract_vector(); }

	inline std :: vector < any_a < > > & mutate_vector()
	{ assert(any_a<>::___handle___); return ___write___().mutate_vector(); }

protected:
	struct ___flock_a_handle_base___ : inventory_a<>::template ___inventory_a_handle_base___
	{
		virtual bool operator==(flock_a < > const & flock ) const = 0;
		virtual bool operator!=(flock_a < > const & flock ) const = 0;
		virtual bool operator<(flock_a < > const & flock ) const = 0;
		virtual bool operator>(flock_a < > const & flock ) const = 0;
		virtual bool operator<=(flock_a < > const & flock ) const = 0;
		virtual bool operator>=(flock_a < > const & flock ) const = 0;
		virtual random_access_extractor_data_a < typename std :: vector < any_a < > > :: const_iterator > extract_begin() const = 0;
		virtual random_access_extractor_data_a < typename std :: vector < any_a < > > :: const_iterator > extract_end() const = 0;
		virtual random_access_mutator_data_a < typename std :: vector < any_a < > > :: iterator > mutate_begin() = 0;
		virtual random_access_mutator_data_a < typename std :: vector < any_a < > > :: iterator > mutate_end() = 0;
		virtual std :: vector < any_a < > > const & extract_vector() const = 0;
		virtual std :: vector < any_a < > > & mutate_vector() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___flock_a_handle_base___>
	struct ___flock_a_handle___ : inventory_a<>::template ___inventory_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___flock_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: inventory_a<>::template ___inventory_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___flock_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: inventory_a<>::template ___inventory_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___flock_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: inventory_a<>::template ___inventory_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(flock_a < > const & flock ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(flock); }

		virtual inline bool operator!=(flock_a < > const & flock ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(flock); }

		virtual inline bool operator<(flock_a < > const & flock ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(flock); }

		virtual inline bool operator>(flock_a < > const & flock ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(flock); }

		virtual inline bool operator<=(flock_a < > const & flock ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(flock); }

		virtual inline bool operator>=(flock_a < > const & flock ) const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(flock); }

		virtual inline random_access_extractor_data_a < typename std :: vector < any_a < > > :: const_iterator > extract_begin() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

		virtual inline random_access_extractor_data_a < typename std :: vector < any_a < > > :: const_iterator > extract_end() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

		virtual inline random_access_mutator_data_a < typename std :: vector < any_a < > > :: iterator > mutate_begin() final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin(); }

		virtual inline random_access_mutator_data_a < typename std :: vector < any_a < > > :: iterator > mutate_end() final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end(); }

		virtual inline std :: vector < any_a < > > const & extract_vector() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_vector(); }

		virtual inline std :: vector < any_a < > > & mutate_vector() final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_vector(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___flock_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___flock_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___flock_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___flock_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___flock_a_handle_final___ final : ___flock_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___flock_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___flock_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___flock_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___flock_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___flock_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___flock_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline inventory_a<>::template ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___flock_a_handle_final___>(___flock_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___flock_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___flock_a_handle_final___<___TTT___&>
	{
		inline ___flock_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___flock_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___flock_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___flock_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___flock_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___flock_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline flock_a val(flock_a const& other) noexcept
	{
		return flock_a{ other };
	}

	static inline flock_a ref(flock_a& other) noexcept
	{
		return flock_a(other, any_a<>::___reference_tag___{});
	}

	static inline flock_a dup(flock_a& other) noexcept
	{
		return flock_a(other, any_a<>::___duplicate_tag___{});
	}

	inline flock_a() = default;

	inline flock_a(flock_a& other, any_a<>::___reference_tag___) noexcept
		: inventory_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline flock_a(flock_a& other, any_a<>::___duplicate_tag___) noexcept
		: inventory_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline flock_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: inventory_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___flock_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline flock_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: inventory_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___flock_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<flock_a, std::decay_t<___TTT___>>::value>>
	explicit inline flock_a(___TTT___ value) noexcept
		: inventory_a<>{ std::make_shared<___flock_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline flock_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: inventory_a<>{ std::make_shared<___flock_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline flock_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___flock_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<flock_a, std::decay_t<___TTT___>>::value>>
	inline flock_a& operator=(___TTT___ value) noexcept
	{
		flock_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___flock_a_handle_base___>(thing.___handle___) };
	}

	static inline flock_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___flock_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return flock_a{ thing.___handle___ };
		}
		return flock_a{ flock_d<_1>{ thing } };
	}

	static inline flock_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___flock_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return flock_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return flock_a{ flock_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::flock");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = inventory_a<>::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = inventory_a<>::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = inventory_a<>::template ___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline flock_a create(Args&&... args)
	{
		return flock_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class flock_a

template <typename _1>
class flock_d : public inventory_d<>
{
public:
	inline bool operator==(flock_a < > const & flock ) const
	{ throw dis("dynamic flock_d::operator==(flock) not available"); }

	inline bool operator!=(flock_a < > const & flock ) const
	{ throw dis("dynamic flock_d::operator!=(flock) not available"); }

	inline bool operator<(flock_a < > const & flock ) const
	{ throw dis("dynamic flock_d::operator<(flock) not available"); }

	inline bool operator>(flock_a < > const & flock ) const
	{ throw dis("dynamic flock_d::operator>(flock) not available"); }

	inline bool operator<=(flock_a < > const & flock ) const
	{ throw dis("dynamic flock_d::operator<=(flock) not available"); }

	inline bool operator>=(flock_a < > const & flock ) const
	{ throw dis("dynamic flock_d::operator>=(flock) not available"); }

	inline random_access_extractor_data_a < typename std :: vector < any_a < > > :: const_iterator > extract_begin() const
	{ throw dis("dynamic flock_d::extract_begin() not available"); }

	inline random_access_extractor_data_a < typename std :: vector < any_a < > > :: const_iterator > extract_end() const
	{ throw dis("dynamic flock_d::extract_end() not available"); }

	inline random_access_mutator_data_a < typename std :: vector < any_a < > > :: iterator > mutate_begin()
	{ throw dis("dynamic flock_d::mutate_begin() not available"); }

	inline random_access_mutator_data_a < typename std :: vector < any_a < > > :: iterator > mutate_end()
	{ throw dis("dynamic flock_d::mutate_end() not available"); }

	inline std :: vector < any_a < > > const & extract_vector() const
	{ throw dis("dynamic flock_d::extract_vector() not available"); }

	inline std :: vector < any_a < > > & mutate_vector()
	{ throw dis("dynamic flock_d::mutate_vector() not available"); }

	void ___weak___(inventory_d<>::template ___WEAK___ const& weak) const {}

	explicit flock_d(any_a<> const& thing)
		: inventory_d{ thing }
	{}

	explicit flock_d(any_a<>& thing, any_a<>::___reference_tag___)
		: inventory_d{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit flock_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: inventory_d{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
