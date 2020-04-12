
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

	inline any_a<> unwrap_() const;

	inline any_a<> close__(range_a<> const& ___arguments___);

	inline any_a<> close_();

	inline any_a<> closed__(range_a<> const& ___arguments___) const;

	inline any_a<> closed_() const;

	inline any_a<> reopen__(range_a<> const& ___arguments___);

	inline any_a<> reopen_();

	inline any_a<> binary__(range_a<> const& ___arguments___) const;

	inline lake_int8_a<> binary_() const;

	inline std :: string binary() const;

	inline any_a<> to_number__(range_a<> const& ___arguments___) const;

	inline number_a<> to_number_() const;

	inline any_a<> to_number_or__(range_a<> const& ___arguments___) const;

	inline number_a<> to_number_or_(number_a<> const& number) const;

	inline any_a<> to_int_64__(range_a<> const& ___arguments___) const;

	inline number_data_int64_a<> to_int_64_() const;

	inline any_a<> to_float_64__(range_a<> const& ___arguments___) const;

	inline number_data_double_a<> to_float_64_() const;

	inline any_a<> to_symbol__(range_a<> const& ___arguments___) const;

	inline symbol_a<> to_symbol_() const;

	inline any_a<> to_flock__(range_a<> const& ___arguments___) const;

	inline flock_a<> to_flock_() const;

	inline any_a<> to_lake__(range_a<> const& ___arguments___) const;

	inline lake_int8_a<> to_lake_() const;

	inline any_a<> to_ordered_herd__(range_a<> const& ___arguments___) const;

	inline ordered_herd_a<> to_ordered_herd_() const;

	inline any_a<> to_ordered_shoal__(range_a<> const& ___arguments___) const;

	inline ordered_shoal_a<> to_ordered_shoal_() const;

	inline any_a<> to_squad__(range_a<> const& ___arguments___) const;

	inline squad_a<> to_squad_() const;

	inline any_a<> to_unordered_herd__(range_a<> const& ___arguments___) const;

	inline unordered_herd_a<> to_unordered_herd_() const;

	inline any_a<> to_unordered_shoal__(range_a<> const& ___arguments___) const;

	inline unordered_shoal_a<> to_unordered_shoal_() const;

	inline bool operator==(parcel_a < > const & parcel ) const;

	inline bool operator!=(parcel_a < > const & parcel ) const;

	inline bool operator<(parcel_a < > const & parcel ) const;

	inline bool operator>(parcel_a < > const & parcel ) const;

	inline bool operator<=(parcel_a < > const & parcel ) const;

	inline bool operator>=(parcel_a < > const & parcel ) const;

	inline any_a<> key_begin__(range_a<> const& ___arguments___) const;

	inline bidirectional_extractor_a< parcel_a<> > key_begin_() const;

	inline any_a<> key_end__(range_a<> const& ___arguments___) const;

	inline bidirectional_extractor_a< parcel_a<> > key_end_() const;

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > key_begin() const;

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > key_end() const;

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_begin() const;

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_end() const;

	inline bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > mutate_begin();

	inline bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > mutate_end();

	inline dart :: packet const & extract_packet() const;

	inline dart :: packet & mutate_packet();

protected:
	struct ___parcel_a_handle_base___ : collection_a< any_a<> , parcel_a<> , parcel_a<> >::___collection_a_handle_base___
	{
		virtual any_a<> unwrap_() const = 0;
		virtual any_a<> close_() = 0;
		virtual any_a<> closed_() const = 0;
		virtual any_a<> reopen_() = 0;
		virtual lake_int8_a<> binary_() const = 0;
		virtual std :: string binary() const = 0;
		virtual number_a<> to_number_() const = 0;
		virtual number_a<> to_number_or_(number_a<> const& number) const = 0;
		virtual number_data_int64_a<> to_int_64_() const = 0;
		virtual number_data_double_a<> to_float_64_() const = 0;
		virtual symbol_a<> to_symbol_() const = 0;
		virtual flock_a<> to_flock_() const = 0;
		virtual lake_int8_a<> to_lake_() const = 0;
		virtual ordered_herd_a<> to_ordered_herd_() const = 0;
		virtual ordered_shoal_a<> to_ordered_shoal_() const = 0;
		virtual squad_a<> to_squad_() const = 0;
		virtual unordered_herd_a<> to_unordered_herd_() const = 0;
		virtual unordered_shoal_a<> to_unordered_shoal_() const = 0;
		virtual bool operator==(parcel_a < > const & parcel ) const = 0;
		virtual bool operator!=(parcel_a < > const & parcel ) const = 0;
		virtual bool operator<(parcel_a < > const & parcel ) const = 0;
		virtual bool operator>(parcel_a < > const & parcel ) const = 0;
		virtual bool operator<=(parcel_a < > const & parcel ) const = 0;
		virtual bool operator>=(parcel_a < > const & parcel ) const = 0;
		virtual bidirectional_extractor_a< parcel_a<> > key_begin_() const = 0;
		virtual bidirectional_extractor_a< parcel_a<> > key_end_() const = 0;
		virtual bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > key_begin() const = 0;
		virtual bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > key_end() const = 0;
		virtual bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_begin() const = 0;
		virtual bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_end() const = 0;
		virtual bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > mutate_begin() = 0;
		virtual bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > mutate_end() = 0;
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

		virtual inline any_a<> unwrap_() const final;

		virtual inline any_a<> close_() final;

		virtual inline any_a<> closed_() const final;

		virtual inline any_a<> reopen_() final;

		virtual inline lake_int8_a<> binary_() const final;

		virtual inline std :: string binary() const final;

		virtual inline number_a<> to_number_() const final;

		virtual inline number_a<> to_number_or_(number_a<> const& number) const final;

		virtual inline number_data_int64_a<> to_int_64_() const final;

		virtual inline number_data_double_a<> to_float_64_() const final;

		virtual inline symbol_a<> to_symbol_() const final;

		virtual inline flock_a<> to_flock_() const final;

		virtual inline lake_int8_a<> to_lake_() const final;

		virtual inline ordered_herd_a<> to_ordered_herd_() const final;

		virtual inline ordered_shoal_a<> to_ordered_shoal_() const final;

		virtual inline squad_a<> to_squad_() const final;

		virtual inline unordered_herd_a<> to_unordered_herd_() const final;

		virtual inline unordered_shoal_a<> to_unordered_shoal_() const final;

		virtual inline bool operator==(parcel_a < > const & parcel ) const final;

		virtual inline bool operator!=(parcel_a < > const & parcel ) const final;

		virtual inline bool operator<(parcel_a < > const & parcel ) const final;

		virtual inline bool operator>(parcel_a < > const & parcel ) const final;

		virtual inline bool operator<=(parcel_a < > const & parcel ) const final;

		virtual inline bool operator>=(parcel_a < > const & parcel ) const final;

		virtual inline bidirectional_extractor_a< parcel_a<> > key_begin_() const final;

		virtual inline bidirectional_extractor_a< parcel_a<> > key_end_() const final;

		virtual inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > key_begin() const final;

		virtual inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > key_end() const final;

		virtual inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_begin() const final;

		virtual inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_end() const final;

		virtual inline bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > mutate_begin() final;

		virtual inline bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > mutate_end() final;

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
	static inline ___unordered_shoal_a___ ___operations___()
	{
		static ___unordered_shoal_a___ OPERATIONS = []()
		{
			___unordered_shoal_a___ operations = collection_a< any_a<> , parcel_a<> , parcel_a<> >::template ___operations___<___unordered_shoal_a___>();
			operations.update_string("unwrap_", native_extraction_t<parcel_a>::create(&parcel_a::unwrap__));
			operations.update_string("close_", native_mutation_t<parcel_a>::create(&parcel_a::close__));
			operations.update_string("closed_", native_extraction_t<parcel_a>::create(&parcel_a::closed__));
			operations.update_string("reopen_", native_mutation_t<parcel_a>::create(&parcel_a::reopen__));
			operations.update_string("binary_", native_extraction_t<parcel_a>::create(&parcel_a::binary__));
			operations.update_string("to_number_", native_extraction_t<parcel_a>::create(&parcel_a::to_number__));
			operations.update_string("to_number_or_", native_extraction_t<parcel_a>::create(&parcel_a::to_number_or__));
			operations.update_string("to_int_64_", native_extraction_t<parcel_a>::create(&parcel_a::to_int_64__));
			operations.update_string("to_float_64_", native_extraction_t<parcel_a>::create(&parcel_a::to_float_64__));
			operations.update_string("to_symbol_", native_extraction_t<parcel_a>::create(&parcel_a::to_symbol__));
			operations.update_string("to_flock_", native_extraction_t<parcel_a>::create(&parcel_a::to_flock__));
			operations.update_string("to_lake_", native_extraction_t<parcel_a>::create(&parcel_a::to_lake__));
			operations.update_string("to_ordered_herd_", native_extraction_t<parcel_a>::create(&parcel_a::to_ordered_herd__));
			operations.update_string("to_ordered_shoal_", native_extraction_t<parcel_a>::create(&parcel_a::to_ordered_shoal__));
			operations.update_string("to_squad_", native_extraction_t<parcel_a>::create(&parcel_a::to_squad__));
			operations.update_string("to_unordered_herd_", native_extraction_t<parcel_a>::create(&parcel_a::to_unordered_herd__));
			operations.update_string("to_unordered_shoal_", native_extraction_t<parcel_a>::create(&parcel_a::to_unordered_shoal__));
			operations.update_string("key_begin_", native_extraction_t<parcel_a>::create(&parcel_a::key_begin__));
			operations.update_string("key_end_", native_extraction_t<parcel_a>::create(&parcel_a::key_end__));
			return operations;
		}();
		return OPERATIONS;
	}

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

	inline any_a<> unwrap_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("unwrap_");
		if (!op)
		{
			throw dis("dynamic parcel_d::unwrap_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> close__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("close_");
		if (!op)
		{
			throw dis("dynamic parcel_d::close_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline any_a<> close_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("close_");
		if (!op)
		{
			throw dis("dynamic parcel_d::close_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this));
	}

	inline any_a<> closed__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("closed_");
		if (!op)
		{
			throw dis("dynamic parcel_d::closed_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline any_a<> closed_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("closed_");
		if (!op)
		{
			throw dis("dynamic parcel_d::closed_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> reopen__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("reopen_");
		if (!op)
		{
			throw dis("dynamic parcel_d::reopen_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline any_a<> reopen_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("reopen_");
		if (!op)
		{
			throw dis("dynamic parcel_d::reopen_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this));
	}

	inline any_a<> binary__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("binary_");
		if (!op)
		{
			throw dis("dynamic parcel_d::binary_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline lake_int8_a<> binary_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("binary_");
		if (!op)
		{
			throw dis("dynamic parcel_d::binary_ passed non-existent member");
		}
		return cast<lake_int8_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline std :: string binary() const
	{ return lake_to_string(binary_()); }

	inline any_a<> to_number__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_number_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_number_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline number_a<> to_number_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_number_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_number_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> to_number_or__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_number_or_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_number_or_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline number_a<> to_number_or_(number_a<> const& number) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_number_or_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_number_or_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this), number));
	}

	inline any_a<> to_int_64__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_int_64_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_int_64_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline number_data_int64_a<> to_int_64_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_int_64_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_int_64_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> to_float_64__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_float_64_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_float_64_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline number_data_double_a<> to_float_64_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_float_64_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_float_64_ passed non-existent member");
		}
		return cast<number_data_double_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> to_symbol__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_symbol_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_symbol_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline symbol_a<> to_symbol_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_symbol_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_symbol_ passed non-existent member");
		}
		return cast<symbol_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> to_flock__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_flock_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_flock_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline flock_a<> to_flock_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_flock_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_flock_ passed non-existent member");
		}
		return cast<flock_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> to_lake__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_lake_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_lake_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline lake_int8_a<> to_lake_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_lake_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_lake_ passed non-existent member");
		}
		return cast<lake_int8_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> to_ordered_herd__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_ordered_herd_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_ordered_herd_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline ordered_herd_a<> to_ordered_herd_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_ordered_herd_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_ordered_herd_ passed non-existent member");
		}
		return cast<ordered_herd_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> to_ordered_shoal__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_ordered_shoal_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_ordered_shoal_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline ordered_shoal_a<> to_ordered_shoal_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_ordered_shoal_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_ordered_shoal_ passed non-existent member");
		}
		return cast<ordered_shoal_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> to_squad__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_squad_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_squad_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline squad_a<> to_squad_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_squad_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_squad_ passed non-existent member");
		}
		return cast<squad_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> to_unordered_herd__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_unordered_herd_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_unordered_herd_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline unordered_herd_a<> to_unordered_herd_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_unordered_herd_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_unordered_herd_ passed non-existent member");
		}
		return cast<unordered_herd_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> to_unordered_shoal__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_unordered_shoal_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_unordered_shoal_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline unordered_shoal_a<> to_unordered_shoal_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_unordered_shoal_");
		if (!op)
		{
			throw dis("dynamic parcel_d::to_unordered_shoal_ passed non-existent member");
		}
		return cast<unordered_shoal_a<>>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline bool operator==(parcel_a < > const & parcel ) const
	{ throw dis("dynamic parcel_d::operator==(parcel) not available"); }

	inline bool operator!=(parcel_a < > const & parcel ) const
	{ throw dis("dynamic parcel_d::operator!=(parcel) not available"); }

	inline bool operator<(parcel_a < > const & parcel ) const
	{ throw dis("dynamic parcel_d::operator<(parcel) not available"); }

	inline bool operator>(parcel_a < > const & parcel ) const
	{ throw dis("dynamic parcel_d::operator>(parcel) not available"); }

	inline bool operator<=(parcel_a < > const & parcel ) const
	{ throw dis("dynamic parcel_d::operator<=(parcel) not available"); }

	inline bool operator>=(parcel_a < > const & parcel ) const
	{ throw dis("dynamic parcel_d::operator>=(parcel) not available"); }

	inline any_a<> key_begin__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("key_begin_");
		if (!op)
		{
			throw dis("dynamic parcel_d::key_begin_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline bidirectional_extractor_a< parcel_a<> > key_begin_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("key_begin_");
		if (!op)
		{
			throw dis("dynamic parcel_d::key_begin_ passed non-existent member");
		}
		return cast<bidirectional_extractor_a< parcel_a<> >>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline any_a<> key_end__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("key_end_");
		if (!op)
		{
			throw dis("dynamic parcel_d::key_end_ passed non-existent member");
		}
		return op.operate(*const_cast<parcel_d*>(this), arguments);
	}

	inline bidirectional_extractor_a< parcel_a<> > key_end_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("key_end_");
		if (!op)
		{
			throw dis("dynamic parcel_d::key_end_ passed non-existent member");
		}
		return cast<bidirectional_extractor_a< parcel_a<> >>(variadic_operate(op, *const_cast<parcel_d*>(this)));
	}

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > key_begin() const
	{ throw dis("dynamic parcel_d::key_begin() not available"); }

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > key_end() const
	{ throw dis("dynamic parcel_d::key_end() not available"); }

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_begin() const
	{ throw dis("dynamic parcel_d::extract_begin() not available"); }

	inline bidirectional_extractor_data_a < parcel_a < > , typename dart :: packet :: iterator > extract_end() const
	{ throw dis("dynamic parcel_d::extract_end() not available"); }

	inline bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > mutate_begin()
	{ throw dis("dynamic parcel_d::mutate_begin() not available"); }

	inline bidirectional_mutator_data_a < parcel_a < > , typename dart :: packet :: iterator > mutate_end()
	{ throw dis("dynamic parcel_d::mutate_end() not available"); }

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
