#ifndef COM_ONEISH__STRANGE__PTR_U_H
#define COM_ONEISH__STRANGE__PTR_U_H

namespace strange
{
	// pointer - shared pointer
	template <typename abstraction_d>
	struct ptr : val<abstraction_d>
	{
		using abstraction = abstraction_d;

		inline ptr() : val<abstraction_d>{} // default constructor
		{
			auto nothing = val<abstraction_d>::t->create_nothing();
			nothing.o->_set_pointer(nothing, true);
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

		inline void non_pointer_to_pointer() const
		{
			if (!val<abstraction_d>::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				val<abstraction_d>::mut();
				val<abstraction_d>::o->_set_pointer(*this, true);
			}
		}

		explicit inline ptr(abstraction const& abstract) : val<abstraction_d>{ abstract }
		{
			non_pointer_to_pointer();
		}

		explicit inline ptr(con<abstraction> const& original) : val<abstraction_d>{ original }
		{
			non_pointer_to_pointer();
		}

		explicit inline ptr(var<abstraction> const& original) : val<abstraction_d>{ original }
		{
			non_pointer_to_pointer();
		}

		inline ptr(ptr const& original) : val<abstraction_d>{ original } // copy constructor
		{
			non_pointer_to_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		explicit inline ptr(con<derived_d> const& derived) : val<abstraction_d>{ reinterpret_cast<abstraction const&>(derived) }
		{
			non_pointer_to_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		explicit inline ptr(var<derived_d> const& derived) : val<abstraction_d>{ reinterpret_cast<abstraction const&>(derived) }
		{
			non_pointer_to_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		explicit inline ptr(ptr<derived_d> const& derived) : val<abstraction_d>{ reinterpret_cast<abstraction const&>(derived) }
		{
			non_pointer_to_pointer();
		}

		template <typename source_d>
		inline void assign_from(source_d const& original) const
		{
			if (val<abstraction_d>::t != original.t)
			{
				val<abstraction_d>::dec();
				val<abstraction_d>::t = original.t;
				val<abstraction_d>::o = original.o;
				val<abstraction_d>::inc();
			}
			else
			{
				val<abstraction_d>::o = original.o;
			}
			non_pointer_to_pointer();
		}

		inline ptr const& operator=(con<abstraction> const& original) const
		{
			assign_from(original);
			return *this;
		}

		inline ptr& operator=(con<abstraction> const& original)
		{
			assign_from(original);
			return *this;
		}

		inline ptr const& operator=(var<abstraction> const& original) const
		{
			assign_from(original);
			return *this;
		}

		inline ptr& operator=(var<abstraction> const& original)
		{
			assign_from(original);
			return *this;
		}

		inline ptr const& operator=(ptr const& original) const // copy assignment operator
		{
			assign_from(original);
			return *this;
		}

		inline ptr& operator=(ptr const& original) // copy assignment operator
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		inline ptr const& operator=(con<derived_d> const& original) const
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		inline ptr& operator=(con<derived_d> const& original)
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		inline ptr const& operator=(var<derived_d> const& original) const
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		inline ptr& operator=(var<derived_d> const& original)
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		inline ptr const& operator=(ptr<derived_d> const& original) const
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		inline ptr& operator=(ptr<derived_d> const& original)
		{
			assign_from(original);
			return *this;
		}

		using non_constant = bool;
		using non_variable = bool;
		using is_pointer = bool;

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
			return reinterpret_cast<R const&>(*this);
		}

		template <typename R>
		inline R& reference()
		{
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

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction::operations>, bool> = true>
		inline operator var<B> const& () const
		{
			return reference<var<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction::operations>, bool> = true>
		inline operator var<B>& ()
		{
			return reference<var<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction::operations>, bool> = true>
		inline operator ptr<B> const& () const
		{
			return reference<ptr<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction::operations>, bool> = true>
		inline operator ptr<B>& ()
		{
			return reference<ptr<B>>();
		}

		inline adr<ptr<abstraction>> address() const
		{
			return adr<ptr<abstraction>>{ *this };
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
