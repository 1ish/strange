
namespace strange
{

template <typename _1 = void>
class parcel_d;

template <typename _1 = void>
inline parcel_d<_1> ___parcel_dynamic___(any_a<> const& thing); 

template <typename _1>
class parcel_a : public collection_a< any_a<> , parcel_a<> , parcel_a<> >
{
public:
	inline any_a<> unwrap__(range_a<> const& ___arguments___) const;

	inline any_a<> unwrap_(shoal_a<> const& shared_shoal) const;

	inline any_a<> unwrap_unique__(range_a<> const& ___arguments___) const;

	inline any_a<> unwrap_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const;

	inline any_a < > unwrap(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const;

	inline bool operator==(parcel_a < > const & parcel ) const;

	inline bool operator!=(parcel_a < > const & parcel ) const;

	inline any_a<> keys_begin__(range_a<> const& ___arguments___) const;

	inline bidirectional_extractor_a< any_a<> > keys_begin_() const;

	inline any_a<> keys_end__(range_a<> const& ___arguments___) const;

	inline bidirectional_extractor_a< any_a<> > keys_end_() const;

	inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > keys_begin() const;

	inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > keys_end() const;

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_begin() const;

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_end() const;

	inline dart :: packet const & extract_packet() const;

	inline dart :: packet & mutate_packet();

protected:
	struct ___parcel_a_handle_base___ : collection_a< any_a<> , parcel_a<> , parcel_a<> >::___collection_a_handle_base___
	{
		virtual any_a<> unwrap_(shoal_a<> const& shared_shoal) const = 0;
		virtual any_a<> unwrap_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const = 0;
		virtual any_a < > unwrap(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const = 0;
		virtual bool operator==(parcel_a < > const & parcel ) const = 0;
		virtual bool operator!=(parcel_a < > const & parcel ) const = 0;
		virtual bidirectional_extractor_a< any_a<> > keys_begin_() const = 0;
		virtual bidirectional_extractor_a< any_a<> > keys_end_() const = 0;
		virtual bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > keys_begin() const = 0;
		virtual bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > keys_end() const = 0;
		virtual bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_begin() const = 0;
		virtual bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_end() const = 0;
		virtual dart :: packet const & extract_packet() const = 0;
		virtual dart :: packet & mutate_packet() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___parcel_a_handle_base___>
	struct ___parcel_a_handle___ : collection_a< any_a<> , parcel_a<> , parcel_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___parcel_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: collection_a< any_a<> , parcel_a<> , parcel_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___parcel_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: collection_a< any_a<> , parcel_a<> , parcel_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___parcel_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: collection_a< any_a<> , parcel_a<> , parcel_a<> >::template ___collection_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> unwrap_(shoal_a<> const& shared_shoal) const final;

		virtual inline any_a<> unwrap_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const final;

		virtual inline any_a < > unwrap(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const final;

		virtual inline bool operator==(parcel_a < > const & parcel ) const final;

		virtual inline bool operator!=(parcel_a < > const & parcel ) const final;

		virtual inline bidirectional_extractor_a< any_a<> > keys_begin_() const final;

		virtual inline bidirectional_extractor_a< any_a<> > keys_end_() const final;

		virtual inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > keys_begin() const final;

		virtual inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > keys_end() const final;

		virtual inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_begin() const final;

		virtual inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_end() const final;

		virtual inline dart :: packet const & extract_packet() const final;

		virtual inline dart :: packet & mutate_packet() final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___parcel_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___parcel_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___parcel_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___parcel_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___parcel_a_handle_final___ final : ___parcel_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___parcel_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___parcel_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___parcel_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___parcel_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___parcel_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___parcel_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___parcel_a_handle_final___>(___parcel_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___parcel_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___parcel_a_handle_final___<___TTT___&>
	{
		inline ___parcel_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___parcel_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___parcel_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___parcel_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___parcel_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___parcel_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline parcel_a val(parcel_a const& other) noexcept
	{
		return parcel_a{ other };
	}

	static inline parcel_a ref(parcel_a& other) noexcept
	{
		return parcel_a(other, any_a<>::___reference_tag___{});
	}

	static inline parcel_a dup(parcel_a& other) noexcept
	{
		return parcel_a(other, any_a<>::___duplicate_tag___{});
	}

	inline parcel_a() = default;

	inline parcel_a(parcel_a& other, any_a<>::___reference_tag___) noexcept
		: collection_a< any_a<> , parcel_a<> , parcel_a<> >(other, any_a<>::___reference_tag___{})
	{}

	inline parcel_a(parcel_a& other, any_a<>::___duplicate_tag___) noexcept
		: collection_a< any_a<> , parcel_a<> , parcel_a<> >(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline parcel_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: collection_a< any_a<> , parcel_a<> , parcel_a<> >{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___parcel_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline parcel_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: collection_a< any_a<> , parcel_a<> , parcel_a<> >(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___parcel_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<parcel_a, std::decay_t<___TTT___>>::value>>
	explicit inline parcel_a(___TTT___ value) noexcept
		: collection_a< any_a<> , parcel_a<> , parcel_a<> >{ std::make_shared<___parcel_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline parcel_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: collection_a< any_a<> , parcel_a<> , parcel_a<> >{ std::make_shared<___parcel_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline parcel_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___parcel_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<parcel_a, std::decay_t<___TTT___>>::value>>
	inline parcel_a& operator=(___TTT___ value) noexcept
	{
		parcel_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___parcel_a_handle_base___>(thing.___handle___) };
	}

	static inline parcel_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___parcel_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return parcel_a{ thing.___handle___ };
		}
		return parcel_a{ parcel_d<_1>{ thing } };
	}

	static inline parcel_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___parcel_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return parcel_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return parcel_a{ parcel_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::parcel");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = collection_a< any_a<> , parcel_a<> , parcel_a<> >::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = collection_a< any_a<> , parcel_a<> , parcel_a<> >::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline parcel_a create(Args&&... args)
	{
		return parcel_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class parcel_a

template <typename _1>
class parcel_d : public collection_d< any_a<> , parcel_a<> , parcel_a<> >
{
public:
	inline any_a<> unwrap__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("unwrap_");
		if (!op)
		{
			throw dis("dynamic parcel_d::unwrap_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline any_a<> unwrap_(shoal_a<> const& shared_shoal) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("unwrap_");
		if (!op)
		{
			throw dis("dynamic parcel_d::unwrap_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this), shared_shoal));
	}

	inline any_a<> unwrap_unique__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("unwrap_unique_");
		if (!op)
		{
			throw dis("dynamic parcel_d::unwrap_unique_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline any_a<> unwrap_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_uint64_a<>, strange::any_a<>> & unique_shoal) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("unwrap_unique_");
		if (!op)
		{
			throw dis("dynamic parcel_d::unwrap_unique_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this), shared_shoal, unique_shoal));
	}

	inline any_a < > unwrap(shoal_a < > const & shared_shoal , any_a < > & unique_shoal ) const
	{ throw dis("dynamic parcel_d::unwrap(shared_shoal, unique_shoal) not available"); }

	inline bool operator==(parcel_a < > const & parcel ) const
	{ throw dis("dynamic parcel_d::operator==(parcel) not available"); }

	inline bool operator!=(parcel_a < > const & parcel ) const
	{ throw dis("dynamic parcel_d::operator!=(parcel) not available"); }

	inline any_a<> keys_begin__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("keys_begin_");
		if (!op)
		{
			throw dis("dynamic parcel_d::keys_begin_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline bidirectional_extractor_a< any_a<> > keys_begin_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("keys_begin_");
		if (!op)
		{
			throw dis("dynamic parcel_d::keys_begin_ passed non-existent member");
		}
		return cast<bidirectional_extractor_a< any_a<> >>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> keys_end__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("keys_end_");
		if (!op)
		{
			throw dis("dynamic parcel_d::keys_end_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline bidirectional_extractor_a< any_a<> > keys_end_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("keys_end_");
		if (!op)
		{
			throw dis("dynamic parcel_d::keys_end_ passed non-existent member");
		}
		return cast<bidirectional_extractor_a< any_a<> >>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > keys_begin() const
	{ throw dis("dynamic parcel_d::keys_begin() not available"); }

	inline bidirectional_extractor_data_a < any_a < > , typename dart :: packet :: iterator > keys_end() const
	{ throw dis("dynamic parcel_d::keys_end() not available"); }

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_begin() const
	{ throw dis("dynamic parcel_d::extract_begin() not available"); }

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_end() const
	{ throw dis("dynamic parcel_d::extract_end() not available"); }

	inline dart :: packet const & extract_packet() const
	{ throw dis("dynamic parcel_d::extract_packet() not available"); }

	inline dart :: packet & mutate_packet()
	{ throw dis("dynamic parcel_d::mutate_packet() not available"); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit parcel_d(any_a<> const& thing)
		: collection_d< any_a<> , parcel_a<> , parcel_a<> >{ thing }
	{}

	explicit parcel_d(any_a<>& thing, any_a<>::___reference_tag___)
		: collection_d< any_a<> , parcel_a<> , parcel_a<> >{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit parcel_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: collection_d< any_a<> , parcel_a<> , parcel_a<> >{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
