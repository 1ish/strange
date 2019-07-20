#ifndef COM_ONEISH_STRANGE_OPERATION_T_H
#define COM_ONEISH_STRANGE_OPERATION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = operation_a<>>
class operation_t : public thing_t<_ABSTRACTION_>
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

protected:
	bool const _pure;
	bool const _literal;

	inline operation_t(bool pure = false, bool literal = false)
		: thing_t{}
		, _pure(pure)
		, _literal(literal)
	{}

	static inline std::pair<cat_a<>, flock_a<>> cat_eater_params(symbol_a<> const& prefix, flock_a<> const& params)
	{
		std::pair<cat_a<>, flock_a<>> cat_eater(cat_t<>::val_(), flock_t<>::val_());
		auto it = params.cbegin_();
		if (it == params.cend_())
		{
			return cat_eater;
		}
		auto cat_name = sym("");
		auto cat_params = flock_t<>::val_();
		auto cat_result = cat_t<>::val_();
		bool first = true;
		while (it != params.cend_())
		{
			auto name = *it;
			if (!check<symbol_a<>>(name))
			{
				throw dis("strange::native_mutation::val passed non-symbol name");
			}
			bool const end = (++it == params.cend_());
			auto cat = end ? cast<any_a<>>(cat_t<>::val_()) : *it;
			if (!end && !check<cat_a<>>(cat))
			{
				throw dis("strange::native_mutation::val passed non-cat param");
			}
			if (first)
			{
				cat_name = prefix + cast<symbol_a<>>(name);
				cat_result = cast<cat_a<>>(cat);
				first = false;
			}
			else
			{
				cat_eater.second.push_back(name);
				cat_params.push_back(cat);
			}
			if (end)
			{
				break;
			}
			++it;
		}
		cat_eater.first = cat_t<>::val_(cat_name, flock_t<>::val_(), cat_params, cat_result);
		return cat_eater;
	}
};

} // namespace strange

#endif
