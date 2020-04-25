#ifndef COM_ONEISH_STRANGE_LIST_T_H
#define COM_ONEISH_STRANGE_LIST_T_H

namespace strange
{

// template <typename ___ego___ = list_a<>>
template <typename ___ego___>
class list_t : public thing_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		auto it = list.begin_();
		auto end = list.end_();
		if (it == end)
		{
			return create_();
		}
		any_a<> beginning = *it;
		if (!check<forward_extractor_a<any_a<>>>(beginning))
		{
			throw dis("strange::list::create passed non-extractor begin");
		}
		if (++it == end)
		{
			throw dis("strange::list::create passed short list");
		}
		any_a<> ending = *it;
		if (!check<forward_extractor_a<any_a<>>>(ending))
		{
			throw dis("strange::list::create passed non-extractor end");
		}
		return create_(fast<forward_extractor_a<any_a<>>>(beginning), fast<forward_extractor_a<any_a<>>>(ending));
	}

	static inline list_a<> create_()
	{
		static auto VAL = list_t<>::create_(it_t<any_a<>>::create_(), it_t<any_a<>>::create_());
		return VAL;
	}

	static inline list_a<> create_(forward_extractor_a<any_a<>> const& begin, forward_extractor_a<any_a<>> const& end)
	{
		return list_a<>::template create<list_t<>>(begin, end);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::list");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::list::create"), native_function_create(&list_t<>::create__));
	}

	// visitor pattern
	inline any_a<> visit_(inventory_a<>& arguments, number_data_int64_a<> const& index) const
	{
		auto result = thing_t<>::operate__(arguments);
		if (result)
		{
			auto ind = index.extract_primitive();
			for (auto const& visited : create_(_begin, _end))
			{
				arguments.update_index(ind, visited);
				if (!visited.visit(arguments, ind))
				{
					return no();
				}
			}
		}
		return result;
	}

	inline bool visit(inventory_a<>& arguments, int64_t index) const
	{
		auto result = bool{ thing_t<>::operate__(arguments) };
		if (result)
		{
			for (auto const& visited : create_(_begin, _end))
			{
				arguments.update_index(index, visited);
				if (!visited.visit(arguments, index))
				{
					return false;
				}
			}
		}
		return result;
	}

	// list
	inline forward_extractor_a<any_a<>> begin_() const
	{
		return _begin;
	}

	inline forward_extractor_a<any_a<>> end_() const
	{
		return _end;
	}

protected:
	forward_extractor_a<any_a<>> _begin;
	forward_extractor_a<any_a<>> _end;

	friend class any_a<>;

	inline list_t(forward_extractor_a<any_a<>> const& begin, forward_extractor_a<any_a<>> const& end)
		: thing_t<___ego___>{}
		, _begin(begin)
		, _end(end)
	{}

private:
	static bool const ___share___;
	friend class ___list_t_share___;
};

template <typename ___ego___>
bool const list_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	list_t<___ego___>::share(shoal);
	return shoal;
}();

class ___list_t_share___
{
	static inline bool ___share___()
	{
		return list_t<>::___share___;
	}
};

inline list_a<> list_create()
{
	return list_t<>::create_();
}

inline list_a<> list_create(forward_extractor_a<any_a<>> const& begin, forward_extractor_a<any_a<>> const& end)
{
	return list_t<>::create_(begin, end);
}

} // namespace strange

#endif
