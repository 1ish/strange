#ifndef COM_ONEISH_STRANGE_DISAGREEMENT_T_H
#define COM_ONEISH_STRANGE_DISAGREEMENT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = misunderstanding_a>
class disagreement_t : public misunderstanding_t<_ABSTRACTION_>
{
public: ___THING___
	// construction
	static inline misunderstanding_a val(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline misunderstanding_a val_(any_a thing = nothing_t<>::val_())
	{
		return val__("");
	}

	template <typename F>
	static inline misunderstanding_a val__(F&& s)
	{
		return misunderstanding_a{ disagreement_t{ std::forward<F>(s) } };
	}

	static inline misunderstanding_a ref(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return ref_();
		}
		return ref_(*it);
	}

	static inline misunderstanding_a ref_(any_a thing = nothing_t<>::val_())
	{
		return ref__("");
	}

	template <typename F>
	static inline misunderstanding_a ref__(F&& s)
	{
		return misunderstanding_a(disagreement_t{ std::forward<F>(s) }, true);
	}

	// reflection
	static inline misunderstanding_a type_()
	{
		static misunderstanding_a TYPE = sym__("strange::disagreement");
		return TYPE;
	}

protected:
	template <typename F>
	inline disagreement_t(F&& s)
		: misunderstanding_t{ std::forward<F>(s) }
	{}
};

template <typename F>
inline misunderstanding_a dis__(F&& s)
{
	return disagreement_t<>::val__(std::forward<F>(s));
}

} // namespace strange

#endif
