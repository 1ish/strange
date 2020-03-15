
namespace strange
{

template <typename _1_ = void>
class range_d;

template <typename _1_ = void>
inline range_d<_1_> ___range_dynamic___(any_a<> const& thing); 

template <typename _1_>
class range_a : public any_a<>
{
public:
	inline any_a<> extract_begin__(range_a<> const& ___arguments___) const;

	inline forward_extractor_a<> extract_begin_() const
	{ assert(___handle___); return ___read___().extract_begin_(); }

	inline any_a<> extract_end__(range_a<> const& ___arguments___) const;

	inline forward_extractor_a<> extract_end_() const
	{ assert(___handle___); return ___read___().extract_end_(); }

protected:
	struct ___range_a_handle_base___ : ___any_a_handle_base___
	{
		virtual forward_extractor_a<> extract_begin_() const = 0;
		virtual forward_extractor_a<> extract_end_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___range_a_handle_base___>
	struct ___range_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___range_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___range_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___range_a_handle___(___variadic_tag___, Args&&... args)
			: ___any_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline forward_extractor_a<> extract_begin_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin_(); }

		virtual inline forward_extractor_a<> extract_end_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___range_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___range_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___range_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___range_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___range_a_handle_final___ final : ___range_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___range_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___range_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___range_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___range_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___range_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___range_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___range_a_handle_final___>(___range_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___range_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___range_a_handle_final___<___TTT___&>
	{
		inline ___range_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___range_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___range_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___range_a_handle_base___ const>(___handle___);
	}

	inline ___range_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___range_a_handle_base___>(___handle___);
	}

public:
	static inline range_a val(range_a const& other) noexcept
	{
		return range_a{ other };
	}

	static inline range_a ref(range_a& other) noexcept
	{
		return range_a(other, ___reference_tag___{});
	}

	static inline range_a dup(range_a& other) noexcept
	{
		return range_a(other, ___duplicate_tag___{});
	}

	inline range_a() = default;

	inline range_a(range_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline range_a(range_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline range_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___range_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline range_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___range_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<range_a, std::decay_t<___TTT___>>::value>>
	explicit inline range_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___range_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline range_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a{ std::make_shared<___range_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline range_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___range_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<range_a, std::decay_t<___TTT___>>::value>>
	inline range_a& operator=(___TTT___ value) noexcept
	{
		range_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___range_a_handle_base___>(thing.___handle___) };
	}

	static inline range_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___range_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return range_a{ thing.___handle___ };
		}
		return range_a{ range_d<_1_>{ thing } };
	}

	static inline range_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___range_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return range_a(thing.___handle___, ___reference_tag___{});
		}
		return range_a{ range_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::range");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = any_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = any_a::___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = any_a::___operations___<___unordered_shoal_a___>();
			operations.update_string("extract_begin_", native_extraction_t<range_a>::create(&range_a::extract_begin__));
			operations.update_string("extract_end_", native_extraction_t<range_a>::create(&range_a::extract_end__));
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline range_a create(Args&&... args)
	{
		return range_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___range_a_share___;
}; // class range_a

template <typename _1_>
class range_d : public any_a<>
{
public:
	inline any_a<> extract_begin__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("extract_begin_");
		if (!op)
		{
			throw dis("dynamic range_d::extract_begin_ passed non-existent member");
		}
		return op.operate(*const_cast<range_d*>(this), arguments);
	}

	inline forward_extractor_a<> extract_begin_() const
	{
		assert(___handle___);
		auto const op = operation("extract_begin_");
		if (!op)
		{
			throw dis("dynamic range_d::extract_begin_ passed non-existent member");
		}
		return cast<forward_extractor_a<>>(variadic_operate(op, *const_cast<range_d*>(this)));
	}

	inline any_a<> extract_end__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("extract_end_");
		if (!op)
		{
			throw dis("dynamic range_d::extract_end_ passed non-existent member");
		}
		return op.operate(*const_cast<range_d*>(this), arguments);
	}

	inline forward_extractor_a<> extract_end_() const
	{
		assert(___handle___);
		auto const op = operation("extract_end_");
		if (!op)
		{
			throw dis("dynamic range_d::extract_end_ passed non-existent member");
		}
		return cast<forward_extractor_a<>>(variadic_operate(op, *const_cast<range_d*>(this)));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit range_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit range_d(any_a<>& thing, ___reference_tag___)
		: any_a<>{ thing, ___reference_tag___{} }
	{}

	explicit range_d(any_a<>& thing, ___duplicate_tag___)
		: any_a<>{ thing, ___duplicate_tag___{} }
	{}
};

} // namespace
