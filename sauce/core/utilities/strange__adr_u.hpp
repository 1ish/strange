#ifndef COM_ONEISH__STRANGE__ADR_U_H
#define COM_ONEISH__STRANGE__ADR_U_H

namespace strange
{
	// address - weak pointer
	template <typename value_d>
	struct adr : protected value_d::abstraction
	{
		explicit inline adr(value_d const& value) : value_d::abstraction{ value }
		{
			inc_weak();
		}

		inline adr(adr const& original) : value_d::abstraction{ original } // copy constructor
		{
			inc_weak();
		}

		inline ~adr() // intentionally non-virtual destructor
		{
			dec_weak();
		}

		inline void assign_from(adr const& original) const
		{
			if (value_d::abstraction::t != original.t)
			{
				dec_weak();
				value_d::abstraction::t = original.t;
				value_d::abstraction::o = original.o;
				inc_weak();
			}
			else
			{
				value_d::abstraction::o = original.o;
			}
		}

		inline adr const& operator=(adr const& original) const // copy assignment operator
		{
			assign_from(original);
			return *this;
		}

		inline adr& operator=(adr const& original) // copy assignment operator
		{
			assign_from(original);
			return *this;
		}

		inline void inc_weak() const
		{
			++(value_d::abstraction::t->weak_);
		}

		inline void dec_weak() const
		{
			if (!--(value_d::abstraction::t->weak_))
			{
				operator delete(value_d::abstraction::t);
			}
		}

		inline value_d value() const
		{
			int64_t previous = value_d::abstraction::t->refs_.load();
			for (;;)
			{
				if (previous == 0)
				{
					return value_d{};
				}
				if (value_d::abstraction::t->refs_.compare_exchange_weak(previous, previous + 1))
				{
					break;
				}
			}
			value_d result{ *this };
			--(value_d::abstraction::t->refs_);
			return result;
		}
	};
}

#endif
