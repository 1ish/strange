#ifndef COM_ONEISH_STRANGE_RANGE_OPERATOR_T_H
#define COM_ONEISH_STRANGE_RANGE_OPERATOR_T_H

namespace strange
{

// template <typename ___ego___ = range_a<>>
template <typename ___ego___>
class range_operator_t : public thing_t<___ego___>
{
	template <typename _iterator_, typename ___ego_it___ = forward_const_iterator_data_a<_iterator_>>
	class const_iterator_t : public thing_t<___ego_it___>
	{
	public:
		// override
		using over = thing_o<const_iterator_t<_iterator_>>;

		// construction
		template <typename F>
		static inline forward_const_iterator_data_a<_iterator_> create(range_a<> const& range, F&& it, any_a<>& thing_ref, range_a<> const& range_ref)
		{
			return forward_const_iterator_data_a<_iterator_>{ over{ const_iterator_t<_iterator_>(range, std::forward<F>(it), thing_ref, range_ref) } };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::range_operator::const_iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<forward_const_iterator_data_a<_iterator_>>(thing))
			{
				return false;
			}
			return _it == cast<forward_const_iterator_data_a<_iterator_>>(thing).extract_it();
		}

		inline std::size_t hash() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		// forward iterator
		inline any_a<> get_() const
		{
			return operator*();
		}

		inline any_a<> const* operator->() const
		{
			return &operator*();
		}

		inline any_a<> const& operator*() const
		{
			auto& vector = _results.mutate_vector();
			if (_it == _range.cend_())
			{
				vector.resize(_pos + 1);
			}
			else if(vector.size() != _pos + 1)
			{
				vector.resize(_pos);
				auto thing = _it->operate(_thing_ref, _range_ref);
				vector.emplace_back(thing, any_a<>::___duplicate_tag___{});
			}
			return vector.back();
		}

		inline void increment_()
		{
			++_it;
			++_pos;
		}

		// data
		inline _iterator_ const& extract_it() const
		{
			return _it;
		}

		inline _iterator_& mutate_it()
		{
			return _it;
		}

	protected:
		_iterator_ _it;
		range_a<> const _range;
		any_a<>& _thing_ref;
		range_a<> const& _range_ref;
		flock_a<> mutable _results;
		std::size_t _pos;

		template <typename F>
		inline const_iterator_t(range_a<> const& range, F&& it, any_a<>& thing_ref, range_a<> const& range_ref)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _range{ range }
			, _thing_ref{ thing_ref }
			, _range_ref{ range_ref }
			, _results{ flock_t<>::create_() }
			, _pos{ 0 }
		{}
	};

public:
	// override
	using over = thing_o<range_operator_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::range_operator::create passed empty range");
		}
		any_a<> the_range = *it;
		if (!check<range_a<>>(the_range))
		{
			throw dis("strange::range_operator::create passed non-range");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::range_operator::create passed short range");
		}
		any_a<> thing_ref = cast_dup(*it);
		if (++it == range.cend_())
		{
			throw dis("strange::range_operator::create passed short range");
		}
		any_a<> range_ref = cast_dup(*it);
		if (!check<range_a<>>(range_ref))
		{
			throw dis("strange::range_operator::create passed non-range range ref");
		}
		return create_(cast<range_a<>>(the_range), thing_ref, fast_dup<range_a<>>(range_ref));
	}

	static inline range_a<> create_(range_a<> const& range, any_a<>& thing_ref, range_a<> const& range_ref)
	{
		return range_a<>::create<over>(range_operator_t<>(range, thing_ref, range_ref));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::range_operator");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::range_operator::create", native_function_create(&range_operator_t<>::create__));
	}

	// range
	inline forward_const_iterator_a<> cbegin_() const
	{
		return const_iterator_t<forward_const_iterator_a<>>::create(_range, _range.cbegin_(), _thing_ref, _range_ref);
	}

	inline forward_const_iterator_a<> cend_() const
	{
		return const_iterator_t<forward_const_iterator_a<>>::create(_range, _range.cend_(), _thing_ref, _range_ref);
	}

protected:
	range_a<> const _range;
	any_a<>& _thing_ref;
	range_a<> const& _range_ref;

	inline range_operator_t(range_a<> const& range, any_a<>& thing_ref, range_a<> const& range_ref)
		: thing_t<___ego___>{}
		, _range(range)
		, _thing_ref(thing_ref)
		, _range_ref(range_ref)
	{}

private:
	static bool const ___share___;
	friend class ___range_operator_t_share___;
};

template <typename ___ego___>
bool const range_operator_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	range_operator_t<___ego___>::share(shoal);
	return shoal;
}();

class ___range_operator_t_share___
{
	static inline bool ___share___()
	{
		return range_operator_t<>::___share___;
	}
};

} // namespace strange

#endif
