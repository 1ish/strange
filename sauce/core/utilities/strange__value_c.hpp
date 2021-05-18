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
	struct strange__variable_c;

	template <typename A>
	struct strange__pointer_c;

	template <typename A>
	struct strange__value_c : A
	{
		explicit inline strange__value_c(A const& abstraction) : A{ abstraction }
		{
			if (A::o->_pointer(this))
			{
				A::o->_set_pointer(this, false);
				mut();
			}
		}

		inline strange__value_c(strange__value_c const& original) : A{ original }
		{
			ref();
		}

		explicit inline strange__value_c(strange__variable_c<typename std::remove_const_t<A>> const& original) : A{ original }
		{
			ref();
		}

		explicit inline strange__value_c(strange__pointer_c<typename std::remove_const_t<A>> const& original) : A{ original }
		{
			ref();
			A::o->_set_pointer(this, false);
			mut();
		}

		inline ~strange__value_c()
		{
			rel();
		}

		inline operator A const* () const
		{
			return this;
		}

		inline void ref() const
		{
			++(A::t->refs);
		}

		inline void rel() const
		{
			if (!--(A::t->refs))
			{
				A::o->_free(this);
				delete A::t;
			}
		}

		inline A const ret() const
		{
			++(A::t->refs);
			return *this;
		}

		inline void mut()
		{
			if (A::t->refs > 1)
			{
				typename std::remove_const_t<A> cp = { A::t, A::o };
				A::o->_copy(this, &cp);
				--(A::t->refs);
				A::t = cp.t;
				A::o = cp.o;
			}
		}
	};

	template <typename A>
	struct strange__variable_c : A
	{
		explicit inline strange__variable_c(A const& abstraction) :A { abstraction }
		{
			if (A::o->_pointer(this))
			{
				A::o->_set_pointer(this, false);
				mut();
			}
		}

		explicit inline strange__variable_c(strange__value_c<A const> const& original) : A{ original }
		{
			ref();
		}

		inline strange__variable_c(strange__variable_c const& original) : A{ original }
		{
			ref();
		}

		explicit inline strange__variable_c(strange__pointer_c<A> const& original) : A{ original }
		{
			ref();
			A::o->_set_pointer(this, false);
			mut();
		}

		inline ~strange__variable_c()
		{
			rel();
		}

		inline strange__variable_c& operator=(A const& abstraction)
		{
			rel();
			A::t = abstraction.t;
			A::o = abstraction.o;
			if (A::o->_pointer(this))
			{
				A::o->_set_pointer(this, false);
				mut();
			}
			return *this;
		}

		inline strange__variable_c& operator=(strange__value_c<A const> const& original)
		{
			if (A::t != original.t)
			{
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
			}
			else
			{
				A::o = original.o;
			}
			return *this;
		}

		inline strange__variable_c& operator=(strange__variable_c const& original)
		{
			if (A::t != original.t)
			{
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
			}
			else
			{
				A::o = original.o;
			}
			return *this;
		}

		inline strange__variable_c& operator=(strange__pointer_c<A> const& original)
		{
			if (A::t != original.t)
			{
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
			}
			else
			{
				A::o = original.o;
			}
			A::o->_set_pointer(this, false);
			mut();
			return *this;
		}

		inline operator A* ()
		{
			return this;
		}

		inline operator A const* () const
		{
			return this;
		}

		inline void ref() const
		{
			++(A::t->refs);
		}

		inline void rel() const
		{
			if (!--(A::t->refs))
			{
				A::o->_free(this);
				delete A::t;
			}
		}

		inline A ret() const
		{
			++(A::t->refs);
			return *this;
		}

		inline void mut()
		{
			if (A::t->refs > 1)
			{
				A cp = { A::t, A::o };
				A::o->_copy(this, &cp);
				--(A::t->refs);
				A::t = cp.t;
				A::o = cp.o;
			}
		}
	};

	template <typename A>
	struct strange__pointer_c : A
	{
		explicit inline strange__pointer_c(A const& abstraction) :A{ abstraction }
		{
			if (!A::o->_pointer(this))
			{
				mut();
				A::o->_set_pointer(this, true);
			}
		}

		explicit inline strange__pointer_c(strange__value_c<A const> const& original) : A{ original }
		{
			ref();
			mut();
			A::o->_set_pointer(this, true);
		}

		explicit inline strange__pointer_c(strange__variable_c<A> const& original) : A{ original }
		{
			ref();
			mut();
			A::o->_set_pointer(this, true);
		}

		inline strange__pointer_c(strange__pointer_c const& original) : A{ original }
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
			A::t = abstraction.t;
			A::o = abstraction.o;
			if (!A::o->_pointer(this))
			{
				mut();
				A::o->_set_pointer(this, true);
			}
			return *this;
		}

		inline strange__pointer_c& operator=(strange__value_c<A const> const& original)
		{
			if (A::t != original.t)
			{
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
			}
			else
			{
				A::o = original.o;
			}
			mut();
			A::o->_set_pointer(this, true);
			return *this;
		}

		inline strange__pointer_c& operator=(strange__variable_c<A> const& original)
		{
			if (A::t != original.t)
			{
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
			}
			else
			{
				A::o = original.o;
			}
			mut();
			A::o->_set_pointer(this, true);
			return *this;
		}

		inline strange__pointer_c& operator=(strange__pointer_c const& original)
		{
			if (A::t != original.t)
			{
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
			}
			else
			{
				A::o = original.o;
			}
			return *this;
		}

		inline operator A* ()
		{
			return this;
		}

		inline operator A const* () const
		{
			return this;
		}

		inline void ref() const
		{
			++(A::t->refs);
		}

		inline void rel() const
		{
			if (!--(A::t->refs))
			{
				A::o->_free(this);
				delete A::t;
			}
		}

		inline A ret() const
		{
			++(A::t->refs);
			return *this;
		}

		inline void mut()
		{
			if (A::t->refs > 1)
			{
				A cp = { A::t, A::o };
				A::o->_copy(this, &cp);
				--(A::t->refs);
				A::t = cp.t;
				A::o = cp.o;
			}
		}
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
