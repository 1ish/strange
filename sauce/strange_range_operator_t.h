#ifndef COM_ONEISH_STRANGE_RANGE_OPERATOR_T_H
#define COM_ONEISH_STRANGE_RANGE_OPERATOR_T_H

namespace strange
{

// template <typename ___ego___ = range_a<>>
template <typename ___ego___>
class range_operator_t : public thing_t<___ego___>
{
	template <typename _element, typename _iterator_, typename ___ego_it___ = forward_extractor_data_a<_element, _iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline forward_extractor_data_a<_element, _iterator_> create(range_a<> const& range, F&& it, any_a<>& thing_ref, range_a<> const& range_ref)
		{
			return forward_extractor_data_a<_element, _iterator_>::template create<extractor_t<_element, _iterator_>>(range, std::forward<F>(it), thing_ref, range_ref);
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::range_operator::extractor");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<forward_extractor_data_a<_element, _iterator_>>(thing) &&
				_it == fast<forward_extractor_data_a<_element, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(forward_extractor_data_a<_element, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(forward_extractor_data_a<_element, _iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std_size_t hash() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		// forward extractor
		inline _element get_() const
		{
			return operator*();
		}

		inline _element const* operator->() const
		{
			return &operator*();
		}

		inline _element const& operator*() const
		{
			auto& vector = _results.mutate_vector();
			if (_it == _range.extract_end_())
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

		inline forward_extractor_a<any_a<>> to_extractor_any_() const
		{
			return extractor_t<any_a<>, _iterator_>::create(_range, _it, _thing_ref, _range_ref);
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
		std_size_t _pos;

		friend class any_a<>;

		template <typename F>
		inline extractor_t(range_a<> const& range, F&& it, any_a<>& thing_ref, range_a<> const& range_ref)
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
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("strange::range_operator::create passed empty range");
		}
		any_a<> the_range = *it;
		if (!check<range_a<>>(the_range))
		{
			throw dis("strange::range_operator::create passed non-range");
		}
		if (++it == range.extract_end_())
		{
			throw dis("strange::range_operator::create passed short range");
		}
		any_a<> thing_ref = fast_dup(*it);
		if (++it == range.extract_end_())
		{
			throw dis("strange::range_operator::create passed short range");
		}
		any_a<> range_ref = fast_dup(*it);
		if (!check<range_a<>>(range_ref))
		{
			throw dis("strange::range_operator::create passed non-range range ref");
		}
		return create_(fast<range_a<>>(the_range), thing_ref, fast_dup<range_a<>>(range_ref));
	}

	static inline range_a<> create_(range_a<> const& range, any_a<>& thing_ref, range_a<> const& range_ref)
	{
		return range_a<>::create<range_operator_t<>>(range, thing_ref, range_ref);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::range_operator");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::range_operator::create"), native_function_create(&range_operator_t<>::create__));
	}

	// list
	inline forward_extractor_a<any_a<>> begin_() const
	{
		return extractor_t<any_a<>, forward_extractor_a<any_a<>>>::create(_range, _range.extract_begin_(), _thing_ref, _range_ref);
	}

	inline forward_extractor_a<any_a<>> end_() const
	{
		return extractor_t<any_a<>, forward_extractor_a<any_a<>>>::create(_range, _range.extract_end_(), _thing_ref, _range_ref);
	}

	// range
	inline forward_extractor_a<any_a<>> extract_begin_() const
	{
		return extractor_t<any_a<>, forward_extractor_a<any_a<>>>::create(_range, _range.extract_begin_(), _thing_ref, _range_ref);
	}

	inline forward_extractor_data_a<any_a<>, forward_extractor_a<any_a<>>> extract_begin() const
	{
		return extractor_t<any_a<>, forward_extractor_a<any_a<>>>::create(_range, _range.extract_begin_(), _thing_ref, _range_ref);
	}

	inline forward_extractor_a<any_a<>> extract_end_() const
	{
		return extractor_t<any_a<>, forward_extractor_a<any_a<>>>::create(_range, _range.extract_end_(), _thing_ref, _range_ref);
	}

	inline forward_extractor_data_a<any_a<>, forward_extractor_a<any_a<>>> extract_end() const
	{
		return extractor_t<any_a<>, forward_extractor_a<any_a<>>>::create(_range, _range.extract_end_(), _thing_ref, _range_ref);
	}

protected:
	range_a<> const _range;
	any_a<>& _thing_ref;
	range_a<> const& _range_ref;

	friend class any_a<>;

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

inline range_a<> range_operator_create(range_a<> const& range, any_a<>& thing_ref, range_a<> const& range_ref)
{
	return range_operator_t<>::create_(range, thing_ref, range_ref);
}

} // namespace strange

#endif
