#ifndef COM_ONEISH_STRANGE_ATTRIBUTE_MUTATION_T_H
#define COM_ONEISH_STRANGE_ATTRIBUTE_MUTATION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class attribute_mutation_t : public operation_t<___ego___>
{
public:
	// override
	using over = thing_o<attribute_mutation_t<>>;

	// construction
	static inline operation_a<> val_(symbol_a<> const& name, any_a<> const& thing)
	{
		return operation_a<>{ over{ attribute_mutation_t<>(name, thing) } };
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
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto const it = range.cbegin_();
		if (it != range.cend_()) // assign
		{
			auto const value = *it;
			if (!_thing.identical(value))
			{
				auto const original = thing.const_thing().identity();
				auto& mut = static_cast<any_c<>&>(thing.mutable_thing());
				if (mut.identity() != original)
				{
					mut.update_attribution(_name, attribute_mutation_t<>::val_(_name, value));
					return value;
				}
				_thing = value;
			}
		}
		return _thing;
	}

protected:
	symbol_a<> const _name;
	any_a<> mutable _thing;

	inline attribute_mutation_t(symbol_a<> const& name, any_a<> const& thing)
		: operation_t{}
		, _name{ name }
		, _thing{ thing }
	{}
};

} // namespace strange

#endif
