
namespace strange
{

template <typename _type, typename _iterator>
class container_data_d;

template <typename _type, typename _iterator>
inline container_data_d<_type, _iterator> ___container_data_dynamic___(any_a<> const& thing); 

template <typename _type, typename _iterator>
class container_data_a : public container_a<>
{
public:
	inline bool operator==(container_data_a < _type , _iterator > const & container ) const;

	inline bool operator!=(container_data_a < _type , _iterator > const & container ) const;

	inline bidirectional_extractor_data_a < any_a < > , _iterator > keys_begin() const;

	inline bidirectional_extractor_data_a < any_a < > , _iterator > keys_end() const;

	inline bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > extract_begin() const;

	inline bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > extract_end() const;

	inline _type const & extract_packet() const;

	inline _type & mutate_packet();

protected:
	struct ___container_data_a_handle_base___ : container_a<>::___container_a_handle_base___
	{
		virtual bool operator==(container_data_a < _type , _iterator > const & container ) const = 0;
		virtual bool operator!=(container_data_a < _type , _iterator > const & container ) const = 0;
		virtual bidirectional_extractor_data_a < any_a < > , _iterator > keys_begin() const = 0;
		virtual bidirectional_extractor_data_a < any_a < > , _iterator > keys_end() const = 0;
		virtual bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > extract_begin() const = 0;
		virtual bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > extract_end() const = 0;
		virtual _type const & extract_packet() const = 0;
		virtual _type & mutate_packet() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___container_data_a_handle_base___>
	struct ___container_data_a_handle___ : container_a<>::template ___container_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___container_data_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: container_a<>::template ___container_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___container_data_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: container_a<>::template ___container_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___container_data_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: container_a<>::template ___container_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool operator==(container_data_a < _type , _iterator > const & container ) const final;

		virtual inline bool operator!=(container_data_a < _type , _iterator > const & container ) const final;

		virtual inline bidirectional_extractor_data_a < any_a < > , _iterator > keys_begin() const final;

		virtual inline bidirectional_extractor_data_a < any_a < > , _iterator > keys_end() const final;

		virtual inline bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > extract_begin() const final;

		virtual inline bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > extract_end() const final;

		virtual inline _type const & extract_packet() const final;

		virtual inline _type & mutate_packet() final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___container_data_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___container_data_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___container_data_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___container_data_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___container_data_a_handle_final___ final : ___container_data_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___container_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___container_data_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___container_data_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___container_data_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___container_data_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___container_data_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___container_data_a_handle_final___>(___container_data_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___container_data_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___container_data_a_handle_final___<___TTT___&>
	{
		inline ___container_data_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___container_data_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___container_data_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___container_data_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___container_data_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___container_data_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline container_data_a val(container_data_a const& other) noexcept
	{
		return container_data_a{ other };
	}

	static inline container_data_a ref(container_data_a& other) noexcept
	{
		return container_data_a(other, any_a<>::___reference_tag___{});
	}

	static inline container_data_a dup(container_data_a& other) noexcept
	{
		return container_data_a(other, any_a<>::___duplicate_tag___{});
	}

	inline container_data_a() = default;

	inline container_data_a(container_data_a& other, any_a<>::___reference_tag___) noexcept
		: container_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline container_data_a(container_data_a& other, any_a<>::___duplicate_tag___) noexcept
		: container_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline container_data_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: container_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___container_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline container_data_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: container_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___container_data_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<container_data_a, std::decay_t<___TTT___>>::value>>
	explicit inline container_data_a(___TTT___ value) noexcept
		: container_a<>{ std_make_shared<___container_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline container_data_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: container_a<>{ std_make_shared<___container_data_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline container_data_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___container_data_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<container_data_a, std::decay_t<___TTT___>>::value>>
	inline container_data_a& operator=(___TTT___ value) noexcept
	{
		container_data_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___container_data_a_handle_base___>(thing.___handle___) };
	}

	static inline container_data_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___container_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return container_data_a{ thing.___handle___ };
		}
		return container_data_a{ container_data_d<_type, _iterator>{ thing } };
	}

	static inline container_data_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___container_data_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return container_data_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return container_data_a{ container_data_d<_type, _iterator>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::container_data", flock_vals(kind_create<___kind_a___>(2, ""), kind_create<___kind_a___>(2, "")));
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = container_a<>::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>(), flock_vals(kind_of<_type>(), kind_of<_iterator>()));
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = container_a<>::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline container_data_a create(Args&&... args)
	{
		return container_data_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class container_data_a

template <typename _type, typename _iterator>
class container_data_d : public container_d<>
{
public:
	inline bool operator==(container_data_a < _type , _iterator > const & container ) const
	{ throw dis("dynamic container_data_d::operator==(container) not available"); }

	inline bool operator!=(container_data_a < _type , _iterator > const & container ) const
	{ throw dis("dynamic container_data_d::operator!=(container) not available"); }

	inline bidirectional_extractor_data_a < any_a < > , _iterator > keys_begin() const
	{ throw dis("dynamic container_data_d::keys_begin() not available"); }

	inline bidirectional_extractor_data_a < any_a < > , _iterator > keys_end() const
	{ throw dis("dynamic container_data_d::keys_end() not available"); }

	inline bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > extract_begin() const
	{ throw dis("dynamic container_data_d::extract_begin() not available"); }

	inline bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > extract_end() const
	{ throw dis("dynamic container_data_d::extract_end() not available"); }

	inline _type const & extract_packet() const
	{ throw dis("dynamic container_data_d::extract_packet() not available"); }

	inline _type & mutate_packet()
	{ throw dis("dynamic container_data_d::mutate_packet() not available"); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit container_data_d(any_a<> const& thing)
		: container_d<>{ thing }
	{}

	explicit container_data_d(any_a<>& thing, any_a<>::___reference_tag___)
		: container_d<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit container_data_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: container_d<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
