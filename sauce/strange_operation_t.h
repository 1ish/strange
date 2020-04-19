#ifndef COM_ONEISH_STRANGE_OPERATION_T_H
#define COM_ONEISH_STRANGE_OPERATION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class operation_t : public thing_t<___ego___>
{
public:
	// operation
	inline any_a<> pure_() const
	{
		return boole(pure());
	}

	inline bool pure() const
	{
		return _pure;
	}

	static inline void aspects(unordered_shoal_a<> const&)
	{}

	static inline void assign(operation_a<> const&)
	{}

	inline flock_a<> names_() const
	{
		return _names;
	}

protected:
	bool const _pure;
	flock_a<> const _names;

	inline operation_t(bool pure = false)
		: thing_t<___ego___>{}
		, _pure(pure)
		, _names(flock_create())
	{}

	inline operation_t(bool pure, flock_a<> const& names)
		: thing_t<___ego___>{}
		, _pure(pure)
		, _names(names)
	{}

	static inline std_pair<kind_a<>, flock_a<>> kind_names_params(flock_a<> const& params)
	{
		std_pair<kind_a<>, flock_a<>> kind_names(kind_create(), flock_create());
		auto it = params.extract_begin_();
		if (it == params.extract_end_())
		{
			return kind_names;
		}
		auto kind = *it;
		if (!check<kind_a<>>(kind))
		{
			throw dis("strange::operation::kind_names_params passed non-kind result");
		}
		auto kind_result = fast<kind_a<>>(kind);
		auto kind_params = flock_create();
		while (++it != params.extract_end_())
		{
			auto name = *it;
			if (!check<symbol_a<>>(name))
			{
				throw dis("strange::operation::kind_names_params passed non-symbol name");
			}
			bool const end = (++it == params.extract_end_());
			kind = end ? any_a<>::val(kind_create()) : *it;
			if (!end && !check<kind_a<>>(kind))
			{
				throw dis("strange::operation::kind_names_params passed non-kind param");
			}
			kind_names.second.push_back(name);
			kind_params.push_back(kind);
			if (end)
			{
				break;
			}
		}
		kind_names.first = kind_create(1, "", flock_create(), flock_create(), kind_params, kind_result);
		return kind_names;
	}

	static inline unordered_herd_a<> cats(cat_a<> const& cat)
	{
		auto result = ___ego___::___cats___();
		result.insert_thing(cat);
		return result;
	}

	static inline unordered_herd_a<> kinds(kind_a<> const& kind)
	{
		auto result = ___ego___::___kinds___();
		result.insert_thing(kind);
		return result;
	}
};

} // namespace strange

#endif
