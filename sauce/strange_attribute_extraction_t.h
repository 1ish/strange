#ifndef COM_ONEISH_STRANGE_ATTRIBUTE_EXTRACTION_T_H
#define COM_ONEISH_STRANGE_ATTRIBUTE_EXTRACTION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class attribute_extraction_t : public operation_t<___ego___>
{
public:
	// construction
	static inline operation_a<> create_(any_a<> const& thing)
	{
		return operation_a<>::create<attribute_extraction_t<>>(thing);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::attribute_extraction");
		return TYPE;
	}

	static inline void share(shoal_a<>&)
	{}

	// function
	inline any_a<> operate(any_a<>&, list_a<> const& list) const
	{
		if (list.begin_() != list.end_()) //TODO check when parsing instead
		{
			throw dis(__FILE__, __LINE__, "strange::attribute_extraction passed non-empty list");
		}
		return _thing;
	}

protected:
	any_a<> const _thing;

	friend class any_a<>;

	inline attribute_extraction_t(any_a<> const& thing)
		: operation_t<___ego___>{}
		, _thing{ thing }
	{}
};

inline operation_a<> attribute_extraction_create(any_a<> const& thing)
{
	return attribute_extraction_t<>::create_(thing);
}

} // namespace strange

#endif
