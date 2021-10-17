#ifndef COM_ONEISH__STRANGE__BIT_U_H
#define COM_ONEISH__STRANGE__BIT_U_H

namespace strange
{
	// bidirectional iterator - variable with extra operators
	template <typename abstraction_d>
	struct bit : fit<abstraction_d>
	{
		inline bit() : fit<abstraction_d>{} // default constructor
		{
		}

		explicit inline bit(abstraction_d const& abstract) : fit<abstraction_d>{ abstract }
		{
		}

		inline bit(bit const& original) : fit<abstraction_d>{ original } // copy constructor
		{
		}

		inline bit const& operator=(bit const& original) const // copy assignment operator
		{
			fit<abstraction_d>::operator=(original);
			return *this;
		}

		inline bit& operator=(bit const& original) // copy assignment operator
		{
			fit<abstraction_d>::operator=(original);
			return *this;
		}

		inline adr<bit<abstraction_d>> address() const
		{
			return adr<bit<abstraction_d>>{ *this };
		}

		inline bit const& operator++() const // pre
		{
			fit<abstraction_d>::o->increment(*this);
			return *this;
		}

		inline bit& operator++() // pre
		{
			fit<abstraction_d>::o->increment(*this);
			return *this;
		}

		inline bit operator++(int) const // post
		{
			auto before = *this;
			fit<abstraction_d>::o->increment(*this);
			return before;
		}

		inline bit const& operator--() const // pre
		{
			fit<abstraction_d>::o->decrement(*this);
			return *this;
		}

		inline bit& operator--() // pre
		{
			fit<abstraction_d>::o->decrement(*this);
			return *this;
		}

		inline bit operator--(int) const // post
		{
			auto before = *this;
			fit<abstraction_d>::o->decrement(*this);
			return before;
		}
	};
}

#endif
