#ifndef COM_ONEISH__STRANGE__VAL_C_H
#define COM_ONEISH__STRANGE__VAL_C_H

#include <cstdlib>
#include <iostream>

namespace strange
{
	template <typename A>
	struct var;

	template <typename A>
	struct ptr;

	template <typename A>
	struct val : A
	{
		explicit inline val(A const& abstraction) : A{ abstraction }
		{
			ref();
			if (A::o->_pointer(this))
			{
				A::o->_set_pointer(this, false);
				mut();
			}
		}

		inline val(val const& original) : A{ original }
		{
			ref();
		}

		explicit inline val(var<A> const& original) : A{ original }
		{
			ref();
		}

		explicit inline val(ptr<A> const& original) : A{ original }
		{
			ref();
			A::o->_set_pointer(this, false);
			mut();
		}

		inline ~val()
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
			}
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
	struct var : A
	{
		explicit inline var(A const& abstraction) :A { abstraction }
		{
			ref();
			if (A::o->_pointer(this))
			{
				A::o->_set_pointer(this, false);
				mut();
			}
		}

		explicit inline var(val<A> const& original) : A{ original }
		{
			ref();
		}

		inline var(var const& original) : A{ original }
		{
			ref();
		}

		explicit inline var(ptr<A> const& original) : A{ original }
		{
			ref();
			A::o->_set_pointer(this, false);
			mut();
		}

		inline ~var()
		{
			rel();
		}

		inline var& operator=(A const& abstraction)
		{
			rel();
			A::t = abstraction.t;
			A::o = abstraction.o;
			ref();
			if (A::o->_pointer(this))
			{
				A::o->_set_pointer(this, false);
				mut();
			}
			return *this;
		}

		inline var& operator=(val<A> const& original)
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

		inline var& operator=(var const& original)
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

		inline var& operator=(ptr<A> const& original)
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
			}
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
	struct ptr : A
	{
		explicit inline ptr(A const& abstraction) :A{ abstraction }
		{
			ref();
			if (!A::o->_pointer(this))
			{
				mut();
				A::o->_set_pointer(this, true);
			}
		}

		explicit inline ptr(val<A> const& original) : A{ original }
		{
			ref();
			mut();
			A::o->_set_pointer(this, true);
		}

		explicit inline ptr(var<A> const& original) : A{ original }
		{
			ref();
			mut();
			A::o->_set_pointer(this, true);
		}

		inline ptr(ptr const& original) : A{ original }
		{
			ref();
		}

		inline ~ptr()
		{
			rel();
		}

		inline ptr& operator=(A const& abstraction)
		{
			rel();
			A::t = abstraction.t;
			A::o = abstraction.o;
			ref();
			if (!A::o->_pointer(this))
			{
				mut();
				A::o->_set_pointer(this, true);
			}
			return *this;
		}

		inline ptr& operator=(val<A> const& original)
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

		inline ptr& operator=(var<A> const& original)
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

		inline ptr& operator=(ptr const& original)
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
			}
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
}

#endif
