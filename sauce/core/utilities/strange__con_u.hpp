#ifndef COM_ONEISH__STRANGE__CON_U_H
#define COM_ONEISH__STRANGE__CON_U_H

namespace strange
{
	// constant - immutable value
	template <typename abstraction_d>
	struct con : val<abstraction_d>
	{
		using abstraction = abstraction_d;

		inline con() : val<abstraction_d>{} // default constructor
		{
			auto const nothing = val<abstraction_d>::t->create_nothing();
			static typename abstraction::operations const null_ops = [](void const* const nothing_ops, uint64_t const size)
			{
				typename abstraction::operations nops = {};
				std::memcpy(&nops, nothing_ops, size);
				nops.cat = abstraction::cat;
				return nops;
			}(nothing.o, sizeof(*(nothing.o)));
			val<abstraction_d>::t = nothing.t;
			val<abstraction_d>::o = &null_ops;
			val<abstraction_d>::inc();
		}

		inline void pointer_to_non_pointer() const
		{
			if (val<abstraction_d>::o->_pointer(*this))
			{
				val<abstraction_d>::o->_set_pointer(*this, false);
				val<abstraction_d>::mut();
			}
		}

		explicit inline con(abstraction const& abstract) : val<abstraction_d>{ abstract }
		{
			pointer_to_non_pointer();
		}

		inline con(con const& original) : val<abstraction_d>{ original } // copy constructor
		{
			pointer_to_non_pointer();
		}

		explicit inline con(var<abstraction> const& original) : val<abstraction_d>{ original }
		{
			pointer_to_non_pointer();
		}

		explicit inline con(ptr<abstraction> const& original) : val<abstraction_d>{ original }
		{
			pointer_to_non_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		explicit inline con(con<derived_d> const& derived) : val<abstraction_d>{ reinterpret_cast<abstraction const&>(derived) }
		{
			pointer_to_non_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		explicit inline con(var<derived_d> const& derived) : val<abstraction_d>{ reinterpret_cast<abstraction const&>(derived) }
		{
			pointer_to_non_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		explicit inline con(ptr<derived_d> const& derived) : val<abstraction_d>{ reinterpret_cast<abstraction const&>(derived) }
		{
			pointer_to_non_pointer();
		}

		inline con& operator=(con const& original) = delete; // copy assignment operator

		using is_constant = bool;
		using non_variable = bool;
		using non_pointer = bool;

		template <typename R>
		inline R dynamic() const
		{
			R r;
			val<abstraction_d>::o->as(*this, reinterpret_cast<var<> const&>(r));
			return r;
		}

		template <typename R>
		inline R value() const
		{
			return R{ reinterpret_cast<R const&>(*this) };
		}

		template <typename R>
		inline R const& reference() const
		{
			static_assert(typename R::is_constant{ true });
			return reinterpret_cast<R const&>(*this);
		}

		template <typename R>
		inline R& reference()
		{
			static_assert(typename R::is_constant{ true });
			return reinterpret_cast<R&>(*this);
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction::operations>, bool> = true>
		inline operator con<B> const& () const
		{
			return reference<con<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction::operations>, bool> = true>
		inline operator con<B>& ()
		{
			return reference<con<B>>();
		}

		inline adr<con<abstraction>> address() const
		{
			return adr<con<abstraction>>{ *this };
		}

		template <typename function_d, typename... parameters_d>
		inline auto perform(function_d function, parameters_d const&... parameters) const
		{
			return function(*this, parameters...);
		}

		template <typename function_d, typename operation_d, typename... parameters_d>
		inline auto perform(function_d operation_d::* member, parameters_d const&... parameters) const
		{
			return (val<abstraction_d>::o->*member)(*this, parameters...);
		}

		template <typename other_d>
		inline bool operator==(other_d const& other) const
		{
			return val<abstraction_d>::o->equal(*this, other);
		}

		template <typename other_d>
		inline bool operator!=(other_d const& other) const
		{
			return !val<abstraction_d>::o->equal(*this, other);
		}

		template <typename other_d>
		inline bool operator<(other_d const& other) const
		{
			return val<abstraction_d>::o->less(*this, other);
		}

		template <typename other_d>
		inline bool operator>(other_d const& other) const
		{
			return !val<abstraction_d>::o->less_or_equal(*this, other);
		}

		template <typename other_d>
		inline bool operator<=(other_d const& other) const
		{
			return val<abstraction_d>::o->less_or_equal(*this, other);
		}

		template <typename other_d>
		inline bool operator>=(other_d const& other) const
		{
			return !val<abstraction_d>::o->less(*this, other);
		}
	};
}

#endif
