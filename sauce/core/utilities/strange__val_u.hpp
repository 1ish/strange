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

		template <typename F, typename... Ps>
		inline auto pfm(F fp, Ps&&... ps) const
		{
			return fp(*this, ps...);
		}

		template <typename F, typename O, typename... Ps>
		inline auto pfm(F O::* mp, Ps&&... ps) const
		{
			return (val<abstraction_d>::o->*mp)(*this, ps...);
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

	// variable - mutable value
	template <typename abstraction_d>
	struct var : val<abstraction_d>
	{
		using abstraction = abstraction_d;

		inline var() : val<abstraction_d>{} // default constructor
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

		explicit inline var(abstraction const& abstract) : val<abstraction_d>{ abstract }
		{
			pointer_to_non_pointer();
		}

		explicit inline var(con<abstraction> const& original) : val<abstraction_d>{ original }
		{
			pointer_to_non_pointer();
		}

		inline var(var const& original) : val<abstraction_d>{ original } // copy constructor
		{
			pointer_to_non_pointer();
		}

		explicit inline var(ptr<abstraction> const& original) : val<abstraction_d>{ original }
		{
			pointer_to_non_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(con<derived_d> const& derived) : val<abstraction_d>{ reinterpret_cast<abstraction const&>(derived) }
		{
			pointer_to_non_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(var<derived_d> const& derived) : val<abstraction_d>{ reinterpret_cast<abstraction const&>(derived) }
		{
			pointer_to_non_pointer();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(ptr<derived_d> const& derived) : val<abstraction_d>{ reinterpret_cast<abstraction const&>(derived) }
		{
			pointer_to_non_pointer();
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
			pointer_to_non_pointer();
		}

		inline var const& operator=(con<abstraction> const& original) const
		{
			assign_from(original);
			return *this;
		}

		inline var& operator=(con<abstraction> const& original)
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

		inline var const& operator=(ptr<abstraction> const& original) const
		{
			assign_from(original);
			return *this;
		}

		inline var& operator=(ptr<abstraction> const& original)
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		inline var const& operator=(con<derived_d> const& original) const
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		inline var& operator=(con<derived_d> const& original)
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		inline var const& operator=(var<derived_d> const& original) const
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		inline var& operator=(var<derived_d> const& original)
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
		inline var const& operator=(ptr<derived_d> const& original) const
		{
			assign_from(original);
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction::operations, typename derived_d::operations>, bool> = true>
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
			static_assert(typename R::non_pointer{ true });
			return reinterpret_cast<R const&>(*this);
		}

		template <typename R>
		inline R& reference()
		{
			static_assert(typename R::non_pointer{ true });
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

		inline adr<var<abstraction>> address() const
		{
			return adr<var<abstraction>>{ *this };
		}

		template <typename F, typename... Ps>
		inline auto pfm(F fp, Ps&&... ps) const
		{
			return fp(*this, ps...);
		}

		template <typename F, typename O, typename... Ps>
		inline auto pfm(F O::* mp, Ps&&... ps) const
		{
			return (val<abstraction_d>::o->*mp)(*this, ps...);
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

		template <typename F, typename... Ps>
		inline auto pfm(F fp, Ps&&... ps) const
		{
			return fp(*this, ps...);
		}

		template <typename F, typename O, typename... Ps>
		inline auto pfm(F O::* mp, Ps&&... ps) const
		{
			return (val<abstraction_d>::o->*mp)(*this, ps...);
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

	// forward iterator - variable with extra operators
	template <typename abstraction_d>
	struct fit : var<abstraction_d>
	{
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

	// bidirectional iterator - variable with extra operators
	template <typename abstraction_d>
	struct bit : fit<abstraction_d>
	{
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

	// random access iterator - variable with extra operators
	template <typename abstraction_d>
	struct rat : bit<abstraction_d>
	{
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
