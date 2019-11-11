#ifndef COM_ONEISH_STRANGE_OPERATION_T_H
#define COM_ONEISH_STRANGE_OPERATION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class operation_t : public thing_t<___ego___>
{
public:
	// operation
	inline any_a<> pure__(range_a<> const&) const
	{
		return pure_();
	}

	inline any_a<> pure_() const
	{
		return boole(pure());
	}

	inline bool pure() const
	{
		return _pure;
	}

	inline any_a<> literal__(range_a<> const&) const
	{
		return literal_();
	}

	inline any_a<> literal_() const
	{
		return boole(literal());
	}

	inline bool literal() const
	{
		return _literal;
	}

	static inline void aspects(unordered_shoal_a<> const&)
	{}

protected:
	bool const _pure;
	bool const _literal;

	inline operation_t(bool pure = false, bool literal = false)
		: thing_t{}
		, _pure(pure)
		, _literal(literal)
	{}

	static inline std::pair<kind_a<>, flock_a<>> kind_eater_params(flock_a<> const& params)
	{
		std::pair<kind_a<>, flock_a<>> kind_eater(kind_t<>::create_(), flock_t<>::create_());
		auto it = params.cbegin_();
		if (it == params.cend_())
		{
			return kind_eater;
		}
		auto kind = *it;
		if (!check<kind_a<>>(kind))
		{
			throw dis("strange::operation::kind_eater_params passed non-kind result");
		}
		auto kind_result = cast<kind_a<>>(kind);
		auto kind_params = flock_t<>::create_();
		while (++it != params.cend_())
		{
			auto name = *it;
			if (!check<symbol_a<>>(name))
			{
				throw dis("strange::operation::kind_eater_params passed non-symbol name");
			}
			bool const end = (++it == params.cend_());
			kind = end ? cast<any_a<>>(kind_t<>::create_()) : *it;
			if (!end && !check<kind_a<>>(kind))
			{
				throw dis("strange::operation::kind_eater_params passed non-kind param");
			}
			kind_eater.second.push_back(name);
			kind_params.push_back(kind);
			if (end)
			{
				break;
			}
		}
		kind_eater.first = kind_t<>::create(1, "", flock_t<>::create_(), flock_t<>::create_(), kind_params, kind_result);
		return kind_eater;
	}

	static inline unordered_herd_a<> cats(cat_a<> const& cat)
	{
		auto result = reflection<___ego___>::cats();
		result.insert(cat);
		return result;
	}

	static inline unordered_herd_a<> kinds(kind_a<> const& kind)
	{
		auto result = reflection<___ego___>::kinds();
		result.insert(kind);
		return result;
	}
};

} // namespace strange

#endif
