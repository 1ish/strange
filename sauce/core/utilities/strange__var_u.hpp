#ifndef COM_ONEISH__STRANGE__VAR_U_H
#define COM_ONEISH__STRANGE__VAR_U_H

namespace strange
{
	// variable - mutable value
	template <typename abstraction_d>
	struct var : val<typename abstraction_d::variations>
	{
		using abstraction = abstraction_d;

		inline var() : val<typename abstraction_d::variations>{} // default constructor
		{
			auto const nothing = val<typename abstraction_d::variations>::t->create_nothing();
			static typename abstraction_d::operations const null_ops = [](void const* const nothing_ops, uint64_t const size)
			{
				typename abstraction_d::operations nops = {};
				std::memcpy(&nops, nothing_ops, size);
				nops.cat = abstraction_d::cat;
				return nops;
			}(nothing.o, sizeof(*(nothing.o)));
			val<typename abstraction_d::variations>::t = nothing.t;
			val<typename abstraction_d::variations>::o = &null_ops;
			val<typename abstraction_d::variations>::inc();
		}

		inline void pointer_to_non_pointer() const
		{
			if (val<typename abstraction_d::variations>::o->_pointer(*this))
			{
				val<typename abstraction_d::variations>::o->_set_pointer(*this, false);
				val<typename abstraction_d::variations>::mut();
			}
		}

		explicit inline var(abstraction_d const& abstract) : val<typename abstraction_d::variations>{ static_cast<typename abstraction_d::variations const&>(abstract) }
		{
			pointer_to_non_pointer();
		}

		explicit inline var(con<abstraction_d> const& original) : val<typename abstraction_d::variations>{ reinterpret_cast<typename abstraction_d::variations const&>(original) }
		{
			pointer_to_non_pointer();
		}

		inline var(var const& original) : val<typename abstraction_d::variations>{ original } // copy constructor
		{
			pointer_to_non_pointer();
		}

		explicit inline var(ptr<abstraction_d> const& original) : val<typename abstraction_d::variations>{ original }
		{
			pointer_to_non_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(con<derived_d> const& derived) : val<typename abstraction_d::variations>{ reinterpret_cast<typename abstraction_d::variations const&>(derived) }
		{
			pointer_to_non_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(var<derived_d> const& derived) : val<typename abstraction_d::variations>{ reinterpret_cast<typename abstraction_d::variations const&>(derived) }
		{
			pointer_to_non_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(ptr<derived_d> const& derived) : val<typename abstraction_d::variations>{ reinterpret_cast<typename abstraction_d::variations const&>(derived) }
		{
			pointer_to_non_pointer();
		}

		template <typename source_d>
		inline void assign_from(source_d const& original) const
		{
			if (val<typename abstraction_d::variations>::t != original.t)
			{
				val<typename abstraction_d::variations>::dec();
				val<typename abstraction_d::variations>::t = original.t;
				val<typename abstraction_d::variations>::o = original.o;
				val<typename abstraction_d::variations>::inc();
			}
			else
			{
				val<typename abstraction_d::variations>::o = original.o;
			}
			pointer_to_non_pointer();
		}

		inline var const& operator=(con<abstraction_d> const& original) const
		{
			assign_from(original);
			return *this;
		}

		inline var& operator=(con<abstraction_d> const& original)
		{
			assign_from(original);
			return *this;
		}

		inline var const& operator=(var const& original) const // copy assignment operator
		{
			assign_from(original);
			return *this;
		}

		inline var& operator=(var const& original) // copy assignment operator
		{
			assign_from(original);
			return *this;
		}

		inline var const& operator=(ptr<abstraction_d> const& original) const
		{
			assign_from(original);
			return *this;
		}

		inline var& operator=(ptr<abstraction_d> const& original)
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var const& operator=(con<derived_d> const& original) const
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var& operator=(con<derived_d> const& original)
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var const& operator=(var<derived_d> const& original) const
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var& operator=(var<derived_d> const& original)
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var const& operator=(ptr<derived_d> const& original) const
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var& operator=(ptr<derived_d> const& original)
		{
			assign_from(original);
			return *this;
		}

		using non_constant = bool;
		using is_variable = bool;
		using non_pointer = bool;

		template <typename R>
		inline R dynamic() const
		{
			R r;
			val<typename abstraction_d::variations>::o->as(*this, reinterpret_cast<var<> const&>(r));
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
			static_assert(typename R::non_pointer{ true });
			return reinterpret_cast<R const&>(*this);
		}

		template <typename R>
		inline R& reference()
		{
			static_assert(typename R::non_pointer{ true });
			return reinterpret_cast<R&>(*this);
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator con<B> const& () const
		{
			return reference<con<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator con<B>& ()
		{
			return reference<con<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator var<B> const& () const
		{
			return reference<var<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator var<B>& ()
		{
			return reference<var<B>>();
		}

		inline adr<var<abstraction_d>> address() const
		{
			return adr<var<abstraction_d>>{ *this };
		}

		template <typename function_d, typename... parameters_d>
		inline auto perform(function_d function, parameters_d const&... parameters) const
		{
			return function(*this, parameters...);
		}

		template <typename function_d, typename operation_d, typename... parameters_d>
		inline auto perform(function_d operation_d::* member, parameters_d const&... parameters) const
		{
			return (val<typename abstraction_d::variations>::o->*member)(*this, parameters...);
		}

		template <typename other_d>
		inline bool operator==(other_d const& other) const
		{
			return val<typename abstraction_d::variations>::o->equal(*this, other);
		}

		template <typename other_d>
		inline bool operator!=(other_d const& other) const
		{
			return !val<typename abstraction_d::variations>::o->equal(*this, other);
		}

		template <typename other_d>
		inline bool operator<(other_d const& other) const
		{
			return val<typename abstraction_d::variations>::o->less(*this, other);
		}

		template <typename other_d>
		inline bool operator>(other_d const& other) const
		{
			return !val<typename abstraction_d::variations>::o->less_or_equal(*this, other);
		}

		template <typename other_d>
		inline bool operator<=(other_d const& other) const
		{
			return val<typename abstraction_d::variations>::o->less_or_equal(*this, other);
		}

		template <typename other_d>
		inline bool operator>=(other_d const& other) const
		{
			return !val<typename abstraction_d::variations>::o->less(*this, other);
		}
	};
}

#endif
