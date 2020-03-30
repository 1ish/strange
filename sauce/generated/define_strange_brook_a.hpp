
namespace strange
{

template <typename _primitive>
class brook_d;

template <typename _primitive>
inline brook_d<_primitive> ___brook_dynamic___(any_a<> const& thing); 

template <typename _primitive>
class brook_a : public inventory_a< number_data_a< _primitive > >
{
public:
	inline bool operator==(brook_a < _primitive > const & brook ) const;

	inline bool operator!=(brook_a < _primitive > const & brook ) const;

	inline bool operator<(brook_a < _primitive > const & brook ) const;

	inline bool operator>(brook_a < _primitive > const & brook ) const;

	inline bool operator<=(brook_a < _primitive > const & brook ) const;

	inline bool operator>=(brook_a < _primitive > const & brook ) const;

	inline random_access_extractor_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: const_iterator > extract_begin() const;

	inline random_access_extractor_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: const_iterator > extract_end() const;

	inline random_access_mutator_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: iterator > mutate_begin();

	inline random_access_mutator_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: iterator > mutate_end();

	inline std :: deque < _primitive > const & extract_deque() const;

	inline std :: deque < _primitive > & mutate_deque();

protected:
	struct ___brook_a_handle_base___ : inventory_a< number_data_a< _primitive > >::___inventory_a_handle_base___
	{
		virtual bool operator==(brook_a < _primitive > const & brook ) const = 0;
		virtual bool operator!=(brook_a < _primitive > const & brook ) const = 0;
		virtual bool operator<(brook_a < _primitive > const & brook ) const = 0;
		virtual bool operator>(brook_a < _primitive > const & brook ) const = 0;
		virtual bool operator<=(brook_a < _primitive > const & brook ) const = 0;
		virtual bool operator>=(brook_a < _primitive > const & brook ) const = 0;
		virtual random_access_extractor_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: const_iterator > extract_begin() const = 0;
		virtual random_access_extractor_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: const_iterator > extract_end() const = 0;
		virtual random_access_mutator_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: iterator > mutate_begin() = 0;
		virtual random_access_mutator_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: iterator > mutate_end() = 0;
		virtual std :: deque < _primitive > const & extract_deque() const = 0;
		virtual std :: deque < _primitive > & mutate_deque() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___brook_a_handle_base___>
	struct ___brook_a_handle___ : inventory_a< number_data_a< _primitive > >::template ___inventory_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___brook_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: inventory_a< number_data_a< _primitive > >::template ___inventory_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___brook_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: inventory_a< number_data_a< _primitive > >::template ___inventory_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___brook_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: inventory_a< number_data_a< _primitive > >::template ___inventory_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(brook_a < _primitive > const & brook ) const final;

		virtual inline bool operator!=(brook_a < _primitive > const & brook ) const final;

		virtual inline bool operator<(brook_a < _primitive > const & brook ) const final;

		virtual inline bool operator>(brook_a < _primitive > const & brook ) const final;

		virtual inline bool operator<=(brook_a < _primitive > const & brook ) const final;

		virtual inline bool operator>=(brook_a < _primitive > const & brook ) const final;

		virtual inline random_access_extractor_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: const_iterator > extract_begin() const final;

		virtual inline random_access_extractor_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: const_iterator > extract_end() const final;

		virtual inline random_access_mutator_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: iterator > mutate_begin() final;

		virtual inline random_access_mutator_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: iterator > mutate_end() final;

		virtual inline std :: deque < _primitive > const & extract_deque() const final;

		virtual inline std :: deque < _primitive > & mutate_deque() final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___brook_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___brook_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___brook_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___brook_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___brook_a_handle_final___ final : ___brook_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___brook_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___brook_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___brook_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___brook_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___brook_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___brook_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___brook_a_handle_final___>(___brook_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___brook_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___brook_a_handle_final___<___TTT___&>
	{
		inline ___brook_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___brook_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___brook_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___brook_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___brook_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___brook_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline brook_a val(brook_a const& other) noexcept
	{
		return brook_a{ other };
	}

	static inline brook_a ref(brook_a& other) noexcept
	{
		return brook_a(other, any_a<>::___reference_tag___{});
	}

	static inline brook_a dup(brook_a& other) noexcept
	{
		return brook_a(other, any_a<>::___duplicate_tag___{});
	}

	inline brook_a() = default;

	inline brook_a(brook_a& other, any_a<>::___reference_tag___) noexcept
		: inventory_a< number_data_a< _primitive > >(other, any_a<>::___reference_tag___{})
	{}

	inline brook_a(brook_a& other, any_a<>::___duplicate_tag___) noexcept
		: inventory_a< number_data_a< _primitive > >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline brook_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: inventory_a< number_data_a< _primitive > >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___brook_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline brook_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: inventory_a< number_data_a< _primitive > >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___brook_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<brook_a, std::decay_t<___TTT___>>::value>>
	explicit inline brook_a(___TTT___ value) noexcept
		: inventory_a< number_data_a< _primitive > >{ std::make_shared<___brook_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline brook_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: inventory_a< number_data_a< _primitive > >{ std::make_shared<___brook_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline brook_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___brook_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<brook_a, std::decay_t<___TTT___>>::value>>
	inline brook_a& operator=(___TTT___ value) noexcept
	{
		brook_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___brook_a_handle_base___>(thing.___handle___) };
	}

	static inline brook_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___brook_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return brook_a{ thing.___handle___ };
		}
		return brook_a{ brook_d<_primitive>{ thing } };
	}

	static inline brook_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___brook_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return brook_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return brook_a{ brook_d<_primitive>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::brook", flock_vals(kind_create<___kind_a___>(2, "")));
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = inventory_a< number_data_a< _primitive > >::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>(), flock_vals(kind_of<_primitive>()));
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = inventory_a< number_data_a< _primitive > >::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = inventory_a< number_data_a< _primitive > >::template ___operations___<___unordered_shoal_a___>();
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline brook_a create(Args&&... args)
	{
		return brook_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class brook_a

template <typename _primitive>
class brook_d : public inventory_d< number_data_a< _primitive > >
{
public:
	inline bool operator==(brook_a < _primitive > const & brook ) const
	{ throw dis("dynamic brook_d::operator==(brook) not available"); }

	inline bool operator!=(brook_a < _primitive > const & brook ) const
	{ throw dis("dynamic brook_d::operator!=(brook) not available"); }

	inline bool operator<(brook_a < _primitive > const & brook ) const
	{ throw dis("dynamic brook_d::operator<(brook) not available"); }

	inline bool operator>(brook_a < _primitive > const & brook ) const
	{ throw dis("dynamic brook_d::operator>(brook) not available"); }

	inline bool operator<=(brook_a < _primitive > const & brook ) const
	{ throw dis("dynamic brook_d::operator<=(brook) not available"); }

	inline bool operator>=(brook_a < _primitive > const & brook ) const
	{ throw dis("dynamic brook_d::operator>=(brook) not available"); }

	inline random_access_extractor_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: const_iterator > extract_begin() const
	{ throw dis("dynamic brook_d::extract_begin() not available"); }

	inline random_access_extractor_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: const_iterator > extract_end() const
	{ throw dis("dynamic brook_d::extract_end() not available"); }

	inline random_access_mutator_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: iterator > mutate_begin()
	{ throw dis("dynamic brook_d::mutate_begin() not available"); }

	inline random_access_mutator_data_a < number_data_a < _primitive > , typename std :: deque < _primitive > :: iterator > mutate_end()
	{ throw dis("dynamic brook_d::mutate_end() not available"); }

	inline std :: deque < _primitive > const & extract_deque() const
	{ throw dis("dynamic brook_d::extract_deque() not available"); }

	inline std :: deque < _primitive > & mutate_deque()
	{ throw dis("dynamic brook_d::mutate_deque() not available"); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit brook_d(any_a<> const& thing)
		: inventory_d< number_data_a< _primitive > >{ thing }
	{}

	explicit brook_d(any_a<>& thing, any_a<>::___reference_tag___)
		: inventory_d< number_data_a< _primitive > >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit brook_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: inventory_d< number_data_a< _primitive > >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
