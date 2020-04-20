#ifndef COM_ONEISH_STRANGE_ATTRIBUTE_MUTATION_T_H
#define COM_ONEISH_STRANGE_ATTRIBUTE_MUTATION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class attribute_mutation_t : public operation_t<___ego___>
{
public:
	// construction
	static inline operation_a<> create_(symbol_a<> const& name, any_a<> const& kind, any_a<> const& thing)
	{
		return operation_a<>::create<attribute_mutation_t<>>(name, kind, thing);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::attribute_mutation");
		return TYPE;
	}

	static inline void share(shoal_a<>&)
	{}

	// function
	inline any_a<> operate(any_a<>& thing, list_a<> const& list) const
	{
		auto const it = list.begin_();
		if (it != list.end_()) // assign
		{
			auto const value = *it;
			if (!_thing.identical(value))
			{
				auto const original = thing.extract_thing().identity();
#ifdef STRANGE_CHECK_STATIC_CASTS
				if (thing.type_().to_string().length() < 9 || thing.type_().to_string().substr(thing.type_().to_string().length() - 9) != "_creature")
				{
					throw dis("strange::attribute_mutation::operate passed non-creature thing");
				}
#endif
				auto& mut = static_cast<any_c<>&>(thing.mutate_thing());
				if (mut.identity() != original)
				{
					mut.mutate_attribute(_name, attribute_mutation_t<>::create_(_name, _kind, value));
					return value;
				}
				if (!value.kinds_().has(_kind))
				{
					throw dis("strange::attribute_mutation::operate passed wrong kind of thing");
				}
				_thing = value;
			}
		}
		return _thing;
	}

protected:
	symbol_a<> const _name;
	any_a<> const _kind;
	any_a<> mutable _thing;

	friend class any_a<>;

	inline attribute_mutation_t(symbol_a<> const& name, any_a<> const& kind, any_a<> const& thing)
		: operation_t<___ego___>{}
		, _name{ name }
		, _kind{ kind }
		, _thing{ thing }
	{}
};

inline operation_a<> attribute_mutation_create(symbol_a<> const& name, any_a<> const& kind, any_a<> const& thing)
{
	return attribute_mutation_t<>::create_(name, kind, thing);
}

} // namespace strange

#endif
