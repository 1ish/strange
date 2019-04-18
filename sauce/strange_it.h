#ifndef COM_ONEISH_STRANGE_IT_H
#define COM_ONEISH_STRANGE_IT_H

namespace strange
{

template <bool CONST = false, typename CAT_ = any_a, typename END = Nothing<>>
class It : public Something<CAT_>
{
public: ___THING___
	// construction
	static inline any_a val(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline any_a val_(any_a thing = END::val_())
	{
		return any_a{ It<CONST, CAT_, END>{ thing } };
	}

	static inline any_a ref(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return ref_();
		}
		return ref_(*it);
	}

	static inline any_a ref_(any_a thing = END::val_())
	{
		return any_a(It<CONST, CAT_, END>{ thing }, true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::It");
		return TYPE;
	}

	// comparison
	inline bool operator==(any_a thing) const
	{
		return thing->nothing__() == _thing.nothing__();
	}

	inline bool operator!=(any_a thing) const
	{
		return thing->nothing__() != _thing.nothing__();
	}

	inline std::size_t hash__() const
	{
		return _thing.hash__();
	}

	// iterator
	inline any_a& operator*() const
	{
		return _thing;
	}

	inline It& operator++()
	{
		_thing = END::val_();
		return *this;
	}

	inline It operator++(int)
	{
		It result = *this;
		operator++();
		return result;
	}

protected:
	mutable any_a _thing; //TODO A forward iterator cannot be "stashing": it cannot return a reference to an object within itself, because such references would be invalidated by the destruction of the forward iterator.

	inline It(const any_a& thing)
		: Something{}
		, _thing(thing, !CONST)
	{}
};

} // namespace strange

#endif
