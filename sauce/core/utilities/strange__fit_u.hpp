#ifndef COM_ONEISH__STRANGE__FIT_U_H
#define COM_ONEISH__STRANGE__FIT_U_H

namespace strange
{
	// forward iterator - variable with extra operators
	template <typename abstraction_d>
	struct fit : var<abstraction_d>
	{
		inline fit() : var<abstraction_d>{} // default constructor
		{
		}

		explicit inline fit(abstraction_d const& abstract) : var<abstraction_d>{ abstract }
		{
		}

		inline fit(fit const& original) : var<abstraction_d>{ original } // copy constructor
		{
		}

		inline fit const& operator=(fit const& original) const // copy assignment operator
		{
			var<abstraction_d>::operator=(original);
			return *this;
		}

		inline fit& operator=(fit const& original) // copy assignment operator
		{
			var<abstraction_d>::operator=(original);
			return *this;
		}

		inline adr<fit<abstraction_d>> address() const
		{
			return adr<fit<abstraction_d>>{ *this };
		}

		inline auto& operator*() const
		{
			return var<abstraction_d>::o->_operator_star(*this);
		}

		inline auto* operator->() const
		{
			return var<abstraction_d>::o->_operator_arrow(*this);
		}

		inline fit const& operator++() const // pre
		{
			var<abstraction_d>::o->increment(*this);
			return *this;
		}

		inline fit& operator++() // pre
		{
			var<abstraction_d>::o->increment(*this);
			return *this;
		}

		inline fit operator++(int) const // post
		{
			auto before = *this;
			var<abstraction_d>::o->increment(*this);
			return before;
		}
	};
}

#endif
