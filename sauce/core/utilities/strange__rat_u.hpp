#ifndef COM_ONEISH__STRANGE__RAT_U_H
#define COM_ONEISH__STRANGE__RAT_U_H

namespace strange
{
	// random access iterator - variable with extra operators
	template <typename abstraction_d>
	struct rat : bit<abstraction_d>
	{
		inline rat() : bit<abstraction_d>{} // default constructor
		{
		}
		
		explicit inline rat(abstraction_d const& abstract) : bit<abstraction_d>{ abstract }
		{
		}

		inline rat(rat const& original) : bit<abstraction_d>{ original } // copy constructor
		{
		}

		inline rat const& operator=(rat const& original) const // copy assignment operator
		{
			bit<abstraction_d>::operator=(original);
			return *this;
		}

		inline rat& operator=(rat const& original) // copy assignment operator
		{
			bit<abstraction_d>::operator=(original);
			return *this;
		}

		inline adr<rat<abstraction_d>> address() const
		{
			return adr<rat<abstraction_d>>{ *this };
		}

		inline rat const& operator++() const // pre
		{
			bit<abstraction_d>::o->increment(*this);
			return *this;
		}

		inline rat& operator++() // pre
		{
			bit<abstraction_d>::o->increment(*this);
			return *this;
		}

		inline rat operator++(int) const // post
		{
			auto before = *this;
			bit<abstraction_d>::o->increment(*this);
			return before;
		}

		inline rat const& operator--() const // pre
		{
			bit<abstraction_d>::o->decrement(*this);
			return *this;
		}

		inline rat& operator--() // pre
		{
			bit<abstraction_d>::o->decrement(*this);
			return *this;
		}

		inline rat operator--(int) const // post
		{
			auto before = *this;
			bit<abstraction_d>::o->decrement(*this);
			return before;
		}

		inline rat const& operator+=(int64_t offset) const
		{
			bit<abstraction_d>::o->self_add(*this, offset);
			return *this;
		}

		inline rat& operator+=(int64_t offset)
		{
			bit<abstraction_d>::o->self_add(*this, offset);
			return *this;
		}

		inline rat const& operator-=(int64_t offset) const
		{
			bit<abstraction_d>::o->self_add(*this, -offset);
			return *this;
		}

		inline rat& operator-=(int64_t offset)
		{
			bit<abstraction_d>::o->self_add(*this, -offset);
			return *this;
		}

		inline rat operator+(int64_t offset) const
		{
			return bit<abstraction_d>::o->add(*this, offset);
		}

		inline rat operator-(int64_t offset) const
		{
			return bit<abstraction_d>::o->add(*this, -offset);
		}
	};
}

#endif
