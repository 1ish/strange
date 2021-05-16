#ifndef COM_ONEISH__STRANGE__VALUE_C_H
#define COM_ONEISH__STRANGE__VALUE_C_H

#include <cstdlib>
#include <iostream>

namespace strange
{

inline void one(void const* const me /* :<any># */)
{
	auto const ma = reinterpret_cast<strange__any_a const* const>(me);
	ma->d->refs = 1;
}

inline void ref(void const* const me /* :<any># */)
{
	auto const ma = reinterpret_cast<strange__any_a const* const>(me);
	++(ma->d->refs);
}

inline void rel(void const* const me /* :<any># */)
{
	auto const ma = reinterpret_cast<strange__any_a const* const>(me);
	if (!--(ma->d->refs))
	{
		ma->o->_free(ma);
		std::free(ma->d); std::cout << "free\n";
	}
}

inline void mut(void* const me /* :<any>= */)
{
	auto const ma = reinterpret_cast<strange__any_a* const>(me);
	if (ma->d->refs > 1)
	{
		strange__any_a cp = *ma;
		ma->o->_copy(ma, &cp);
		--(ma->d->refs);
		*ma = cp;
	}
}

template <typename A>
struct strange__variable_c;

template <typename A>
struct strange__pointer_c;

template <typename A>
struct strange__value_c
{
	explicit inline strange__value_c(A const& abstraction) :a(abstraction)
	{
		if (a.o->_pointer(&a))
		{
			a.o->_set_pointer(&a, false);
			mut();
		}
	}

	inline strange__value_c(strange__value_c const& original) :a(original.a)
	{
		ref();
	}

	explicit inline strange__value_c(strange__variable_c<typename std::remove_const_t<A>> const& original) : a(original.a)
	{
		ref();
	}

	explicit inline strange__value_c(strange__pointer_c<typename std::remove_const_t<A>> const& original) : a(original.a)
	{
		ref();
		a.o->_set_pointer(&a, false);
		mut();
	}

	inline ~strange__value_c()
	{
		rel();
	}

	inline operator A const* () const
	{
		return &a;
	}

	inline void ref() const
	{
		++(a.d->refs);
	}

	inline void rel() const
	{
		if (!--(a.d->refs))
		{
			a.o->_free(&a);
			std::free(a.d); std::cout << "free\n";
		}
	}

	inline A const ret() const
	{
		++(a.d->refs);
		return a;
	}

	inline void mut()
	{
		if (a.d->refs > 1)
		{
			auto cp = a;
			a.o->_copy(&a, &cp);
			--(a.d->refs);
			a = cp;
		}
	}

	typename std::remove_const_t<A> a;
};

template <typename A>
struct strange__variable_c
{
	explicit inline strange__variable_c(A const& abstraction) :a(abstraction)
	{
		if (a.o->_pointer(&a))
		{
			a.o->_set_pointer(&a, false);
			mut();
		}
	}

	explicit inline strange__variable_c(strange__value_c<A const> const& original) : a(original.a)
	{
		ref();
	}

	inline strange__variable_c(strange__variable_c const& original) : a(original.a)
	{
		ref();
	}

	explicit inline strange__variable_c(strange__pointer_c<A> const& original) : a(original.a)
	{
		ref();
		a.o->_set_pointer(&a, false);
		mut();
	}

	inline ~strange__variable_c()
	{
		rel();
	}

	inline strange__variable_c& operator=(A const& abstraction)
	{
		rel();
		a = abstraction;
		if (a.o->_pointer(&a))
		{
			a.o->_set_pointer(&a, false);
			mut();
		}
		return *this;
	}

	inline strange__variable_c& operator=(strange__value_c<A const> const& original)
	{
		if (a.d != original.a.d)
		{
			rel();
			a = original.a;
			ref();
		}
		else
		{
			a.o = original.a.o;
		}
		return *this;
	}

	inline strange__variable_c& operator=(strange__variable_c const& original)
	{
		if (a.d != original.a.d)
		{
			rel();
			a = original.a;
			ref();
		}
		else
		{
			a.o = original.a.o;
		}
		return *this;
	}

	inline strange__variable_c& operator=(strange__pointer_c<A> const& original)
	{
		if (a.d != original.a.d)
		{
			rel();
			a = original.a;
			ref();
		}
		else
		{
			a.o = original.a.o;
		}
		a.o->_set_pointer(&a, false);
		mut();
		return *this;
	}

	inline operator A* ()
	{
		return &a;
	}

	inline operator A const* () const
	{
		return &a;
	}

	inline void ref() const
	{
		++(a.d->refs);
	}

	inline void rel() const
	{
		if (!--(a.d->refs))
		{
			a.o->_free(&a);
			std::free(a.d); std::cout << "free\n";
		}
	}

	inline A ret() const
	{
		++(a.d->refs);
		return a;
	}

	inline void mut()
	{
		if (a.d->refs > 1)
		{
			auto cp = a;
			a.o->_copy(&a, &cp);
			--(a.d->refs);
			a = cp;
		}
	}

	A a;
};

template <typename A>
struct strange__pointer_c
{
	explicit inline strange__pointer_c(A const& abstraction) :a(abstraction)
	{
		if (!a.o->_pointer(&a))
		{
			mut();
			a.o->_set_pointer(&a, true);
		}
	}

	explicit inline strange__pointer_c(strange__value_c<A const> const& original) : a(original.a)
	{
		ref();
		mut();
		a.o->_set_pointer(&a, true);
	}

	explicit inline strange__pointer_c(strange__variable_c<A> const& original) : a(original.a)
	{
		ref();
		mut();
		a.o->_set_pointer(&a, true);
	}

	inline strange__pointer_c(strange__pointer_c const& original) : a(original.a)
	{
		ref();
	}

	inline ~strange__pointer_c()
	{
		rel();
	}

	inline strange__pointer_c& operator=(A const& abstraction)
	{
		rel();
		a = abstraction;
		if (!a.o->_pointer(&a))
		{
			mut();
			a.o->_set_pointer(&a, true);
		}
		return *this;
	}

	inline strange__pointer_c& operator=(strange__value_c<A const> const& original)
	{
		if (a.d != original.a.d)
		{
			rel();
			a = original.a;
			ref();
		}
		else
		{
			a.o = original.a.o;
		}
		mut();
		a.o->_set_pointer(&a, true);
		return *this;
	}

	inline strange__pointer_c& operator=(strange__variable_c<A> const& original)
	{
		if (a.d != original.a.d)
		{
			rel();
			a = original.a;
			ref();
		}
		else
		{
			a.o = original.a.o;
		}
		mut();
		a.o->_set_pointer(&a, true);
		return *this;
	}

	inline strange__pointer_c& operator=(strange__pointer_c const& original)
	{
		if (a.d != original.a.d)
		{
			rel();
			a = original.a;
			ref();
		}
		else
		{
			a.o = original.a.o;
		}
		return *this;
	}

	inline operator A* ()
	{
		return &a;
	}

	inline operator A const* () const
	{
		return &a;
	}

	inline void ref() const
	{
		++(a.d->refs);
	}

	inline void rel() const
	{
		if (!--(a.d->refs))
		{
			a.o->_free(&a);
			std::free(a.d); std::cout << "free\n";
		}
	}

	inline A ret() const
	{
		++(a.d->refs);
		return a;
	}

	inline void mut()
	{
		if (a.d->refs > 1)
		{
			auto cp = a;
			a.o->_copy(&a, &cp);
			--(a.d->refs);
			a = cp;
		}
	}

	A a;
};

template <typename A>
inline strange__value_c<A const> val(A const& a)
{
	return strange__value_c<A const>(a);
}

template <typename A>
inline strange__variable_c<A> var(A const& a)
{
	return strange__variable_c<A>(a);
}

template <typename A>
inline strange__pointer_c<A> ptr(A const& a)
{
	return strange__pointer_c<A>(a);
}

}

#endif
