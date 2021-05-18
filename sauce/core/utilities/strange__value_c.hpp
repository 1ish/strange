#ifndef COM_ONEISH__STRANGE__VALUE_C_H
#define COM_ONEISH__STRANGE__VALUE_C_H

#include <cstdlib>
#include <iostream>

namespace strange
{
	static_assert(sizeof(std::atomic_int64_t) == sizeof(int64_t), "required to be true: sizeof(std::atomic_int64_t) == sizeof(int64_t)");

	inline void one(thing_t* const t)
	{
		t->refs = 1;
	}

	inline void ref(any_a const* const abstraction /* :<any># */)
	{
		++(abstraction->t->refs);
	}

	inline void rel(any_a const* const abstraction /* :<any># */)
	{
		if (!--(abstraction->t->refs))
		{
			abstraction->o->_free(abstraction);
			delete abstraction->t;
		}
	}

	inline void mut(void* const me /* :<any>= */)
	{
		auto const ma = reinterpret_cast<any_a* const>(me);
		if (ma->t->refs > 1)
		{
			any_a cp = *ma;
			ma->o->_copy(ma, &cp);
			--(ma->t->refs);
			*ma = cp;
		}
	}

	inline void rep(any_a* const after /* :<any>= */,
		bool pointer_before /* :_bool_# */,
		bool pointer_after /* :_bool_# */)
	{
		if (pointer_after != pointer_before)
		{
			if (pointer_after)
			{
				strange::mut(after);
				after->o->_set_pointer(after, true);
			}
			else
			{
				after->o->_set_pointer(after, false);
				strange::mut(after);
			}
		}
	}

	template <typename A>
	struct strange__variable_c; //TODO inherit from A

	template <typename A>
	struct strange__pointer_c; //TODO inherit from A

	template <typename A>
	struct strange__value_c //TODO inherit from A
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
			++(a.t->refs);
		}

		inline void rel() const
		{
			if (!--(a.t->refs))
			{
				a.o->_free(&a);
				delete a.t;
			}
		}

		inline A const ret() const
		{
			++(a.t->refs);
			return a;
		}

		inline void mut()
		{
			if (a.t->refs > 1)
			{
				auto cp = a;
				a.o->_copy(&a, &cp);
				--(a.t->refs);
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
			if (a.t != original.a.t)
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
			if (a.t != original.a.t)
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
			if (a.t != original.a.t)
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
			++(a.t->refs);
		}

		inline void rel() const
		{
			if (!--(a.t->refs))
			{
				a.o->_free(&a);
				delete a.t;
			}
		}

		inline A ret() const
		{
			++(a.t->refs);
			return a;
		}

		inline void mut()
		{
			if (a.t->refs > 1)
			{
				auto cp = a;
				a.o->_copy(&a, &cp);
				--(a.t->refs);
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
			if (a.t != original.a.t)
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
			if (a.t != original.a.t)
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
			if (a.t != original.a.t)
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
			++(a.t->refs);
		}

		inline void rel() const
		{
			if (!--(a.t->refs))
			{
				a.o->_free(&a);
				delete a.t;
			}
		}

		inline A ret() const
		{
			++(a.t->refs);
			return a;
		}

		inline void mut()
		{
			if (a.t->refs > 1)
			{
				auto cp = a;
				a.o->_copy(&a, &cp);
				--(a.t->refs);
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

	inline strange__value_c<symbol_a const> val(char const* const s)
	{
		return strange__value_c<symbol_a const>(symbol_t::create_f(s));
	}
}

#endif
