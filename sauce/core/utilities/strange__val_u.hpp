#ifndef COM_ONEISH__STRANGE__VAL_U_H
#define COM_ONEISH__STRANGE__VAL_U_H

namespace strange
{
	// value - base class for value types
	template <typename abstraction_d>
	struct val : abstraction_d
	{
		inline val() : abstraction_d{} // default constructor
		{
		}

		explicit inline val(abstraction_d const& abstract) : abstraction_d{ abstract }
		{
			inc();
		}

		inline val(val const& original) : abstraction_d{ original } // copy constructor
		{
			inc();
		}

		inline ~val() // non-virtual destructor
		{
			dec();
		}

		inline val& operator=(val const& original) = delete; // copy assignment operator

		inline void inc() const // increment ref count
		{
			++(abstraction_d::t->refs_);
		}

		inline void dec() const // decrement ref count
		{
			if (!--(abstraction_d::t->refs_))
			{
				abstraction_d::o->_free(reinterpret_cast<any_a const&>(*this));
				if (!--(abstraction_d::t->weak_))
				{
					operator delete(abstraction_d::t);
				}
			}
		}

		inline void mut() const // mutate
		{
			if (abstraction_d::t->refs_ > 1)
			{
				abstraction_d cp;
				abstraction_d::o->_copy(reinterpret_cast<any_a const&>(*this), reinterpret_cast<any_a&>(cp));
				++(cp.t->refs_);
				dec();
				abstraction_d::t = cp.t;
				abstraction_d::o = cp.o;
			}
		}
	};
}

#endif
