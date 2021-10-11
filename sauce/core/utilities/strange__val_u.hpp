#ifndef COM_ONEISH__STRANGE__VAL_U_H
#define COM_ONEISH__STRANGE__VAL_U_H

namespace strange
{
	// constant - immutable value
	template <typename abstraction_d>
	struct con : abstraction_d
	{
		inline con()
		{
			auto const nothing = abstraction_d::t->create_nothing();
			static typename abstraction_d::operations const null_ops = [](void const* const nothing_ops, uint64_t const size)
			{
				typename abstraction_d::operations nops = {};
				std::memcpy(&nops, nothing_ops, size);
				nops.cat = abstraction_d::cat;
				return nops;
			}(nothing.o, sizeof(*(nothing.o)));
			abstraction_d::t = nothing.t;
			abstraction_d::o = &null_ops;
			inc();
		}

		explicit inline con(abstraction_d const& abstract) : abstraction_d{ abstract }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		inline con(con const& original) : abstraction_d{ original } // copy constructor
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		explicit inline con(var<abstraction_d> const& original) : abstraction_d{ original }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		explicit inline con(ptr<abstraction_d> const& original) : abstraction_d{ original }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline con(con<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline con(var<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline con(ptr<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		inline ~con() // intentionally non-virtual destructor
		{
			dec();
		}

		inline con& operator=(con const& original) = delete; // copy assignment operator

		inline void inc() const
		{
			++(abstraction_d::t->refs_);
		}

		inline void dec() const
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

		inline void mut() const
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

		using is_constant = bool;
		using non_variable = bool;
		using non_pointer = bool;
		using abstraction = abstraction_d;

		template <typename R>
		inline R dyn() const
		{
			R r;
			abstraction_d::o->as(*this, reinterpret_cast<var<> const&>(r));
			return r;
		}

		template <typename R>
		inline R val() const
		{
			return R{ reinterpret_cast<R const&>(*this) };
		}

		template <typename R>
		inline R const& ref() const
		{
			static_assert(typename R::is_constant{ true });
			return reinterpret_cast<R const&>(*this);
		}

		template <typename R>
		inline R& ref()
		{
			static_assert(typename R::is_constant{ true });
			return reinterpret_cast<R&>(*this);
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator con<B> const& () const
		{
			return ref<con<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator con<B>& ()
		{
			return ref<con<B>>();
		}

		inline adr<con<abstraction_d>> address() const
		{
			return adr<con<abstraction_d>>{ *this };
		}

		template <typename F, typename... Ps>
		inline auto pfm(F fp, Ps&&... ps) const
		{
			return fp(*this, ps...);
		}

		template <typename F, typename O, typename... Ps>
		inline auto pfm(F O::* mp, Ps&&... ps) const
		{
			return (abstraction_d::o->*mp)(*this, ps...);
		}

		template <typename other_d>
		inline bool operator==(other_d const& other) const
		{
			return abstraction_d::o->equal(*this, other);
		}

		template <typename other_d>
		inline bool operator!=(other_d const& other) const
		{
			return !abstraction_d::o->equal(*this, other);
		}

		template <typename other_d>
		inline bool operator<(other_d const& other) const
		{
			return abstraction_d::o->less(*this, other);
		}

		template <typename other_d>
		inline bool operator>(other_d const& other) const
		{
			return !abstraction_d::o->less_or_equal(*this, other);
		}

		template <typename other_d>
		inline bool operator<=(other_d const& other) const
		{
			return abstraction_d::o->less_or_equal(*this, other);
		}

		template <typename other_d>
		inline bool operator>=(other_d const& other) const
		{
			return !abstraction_d::o->less(*this, other);
		}
	};

	// variable - mutable value
	template <typename abstraction_d>
	struct var : abstraction_d
	{
		inline var()
		{
			auto const nothing = abstraction_d::t->create_nothing();
			static typename abstraction_d::operations const null_ops = [](void const* const nothing_ops, uint64_t const size)
			{
				typename abstraction_d::operations nops = {};
				std::memcpy(&nops, nothing_ops, size);
				nops.cat = abstraction_d::cat;
				return nops;
			}(nothing.o, sizeof(*(nothing.o)));
			abstraction_d::t = nothing.t;
			abstraction_d::o = &null_ops;
			inc();
		}

		explicit inline var(abstraction_d const& abstract) : abstraction_d{ abstract }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		explicit inline var(con<abstraction_d> const& original) : abstraction_d{ original }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		inline var(var const& original) : abstraction_d{ original } // copy constructor
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		explicit inline var(ptr<abstraction_d> const& original) : abstraction_d{ original }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(con<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(var<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(ptr<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
		}

		inline ~var() // intentionally non-virtual destructor
		{
			dec();
		}

		inline var const& operator=(con<abstraction_d> const& original) const
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		inline var& operator=(con<abstraction_d> const& original)
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		inline var const& operator=(var const& original) const // copy assignment operator
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		inline var& operator=(var const& original) // copy assignment operator
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		inline var const& operator=(ptr<abstraction_d> const& original) const
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		inline var& operator=(ptr<abstraction_d> const& original)
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var const& operator=(con<derived_d> const& original) const
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var& operator=(con<derived_d> const& original)
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var const& operator=(var<derived_d> const& original) const
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var& operator=(var<derived_d> const& original)
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var const& operator=(ptr<derived_d> const& original) const
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline var& operator=(ptr<derived_d> const& original)
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (abstraction_d::o->_pointer(*this))
			{
				abstraction_d::o->_set_pointer(*this, false);
				mut();
			}
			return *this;
		}

		inline void inc() const
		{
			++(abstraction_d::t->refs_);
		}

		inline void dec() const
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

		inline void mut() const
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

		using non_constant = bool;
		using is_variable = bool;
		using non_pointer = bool;
		using abstraction = abstraction_d;

		template <typename R>
		inline R dyn() const
		{
			R r;
			abstraction_d::o->as(*this, reinterpret_cast<var<> const&>(r));
			return r;
		}

		template <typename R>
		inline R val() const
		{
			return R{ reinterpret_cast<R const&>(*this) };
		}

		template <typename R>
		inline R const& ref() const
		{
			static_assert(typename R::non_pointer{ true });
			return reinterpret_cast<R const&>(*this);
		}

		template <typename R>
		inline R& ref()
		{
			static_assert(typename R::non_pointer{ true });
			return reinterpret_cast<R&>(*this);
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator con<B> const& () const
		{
			return ref<con<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator con<B>& ()
		{
			return ref<con<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator var<B> const& () const
		{
			return ref<var<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator var<B>& ()
		{
			return ref<var<B>>();
		}

		inline adr<var<abstraction_d>> address() const
		{
			return adr<var<abstraction_d>>{ *this };
		}

		template <typename F, typename... Ps>
		inline auto pfm(F fp, Ps&&... ps) const
		{
			return fp(*this, ps...);
		}

		template <typename F, typename O, typename... Ps>
		inline auto pfm(F O::* mp, Ps&&... ps) const
		{
			return (abstraction_d::o->*mp)(*this, ps...);
		}

		template <typename other_d>
		inline bool operator==(other_d const& other) const
		{
			return abstraction_d::o->equal(*this, other);
		}

		template <typename other_d>
		inline bool operator!=(other_d const& other) const
		{
			return !abstraction_d::o->equal(*this, other);
		}

		template <typename other_d>
		inline bool operator<(other_d const& other) const
		{
			return abstraction_d::o->less(*this, other);
		}

		template <typename other_d>
		inline bool operator>(other_d const& other) const
		{
			return !abstraction_d::o->less_or_equal(*this, other);
		}

		template <typename other_d>
		inline bool operator<=(other_d const& other) const
		{
			return abstraction_d::o->less_or_equal(*this, other);
		}

		template <typename other_d>
		inline bool operator>=(other_d const& other) const
		{
			return !abstraction_d::o->less(*this, other);
		}
	};

	// pointer - shared pointer
	template <typename abstraction_d>
	struct ptr : abstraction_d
	{
		inline ptr()
		{
			auto nothing = abstraction_d::t->create_nothing();
			nothing.o->_set_pointer(nothing, true);
			static typename abstraction_d::operations const null_ops = [](void const* const nothing_ops, uint64_t const size)
			{
				typename abstraction_d::operations nops = {};
				std::memcpy(&nops, nothing_ops, size);
				nops.cat = abstraction_d::cat;
				return nops;
			}(nothing.o, sizeof(*(nothing.o)));
			abstraction_d::t = nothing.t;
			abstraction_d::o = &null_ops;
			inc();
		}

		explicit inline ptr(abstraction_d const& abstract) : abstraction_d{ abstract }
		{
			inc();
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
		}

		explicit inline ptr(con<abstraction_d> const& original) : abstraction_d{ original }
		{
			inc();
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
		}

		explicit inline ptr(var<abstraction_d> const& original) : abstraction_d{ original }
		{
			inc();
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
		}

		inline ptr(ptr const& original) : abstraction_d{ original } // copy constructor
		{
			inc();
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline ptr(con<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline ptr(var<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline ptr(ptr<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
		}

		inline ~ptr() // intentionally non-virtual destructor
		{
			dec();
		}

		inline ptr const& operator=(con<abstraction_d> const& original) const
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		inline ptr& operator=(con<abstraction_d> const& original)
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		inline ptr const& operator=(var<abstraction_d> const& original) const
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		inline ptr& operator=(var<abstraction_d> const& original)
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		inline ptr const& operator=(ptr const& original) const // copy assignment operator
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		inline ptr& operator=(ptr const& original) // copy assignment operator
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline ptr const& operator=(con<derived_d> const& original) const
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline ptr& operator=(con<derived_d> const& original)
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline ptr const& operator=(var<derived_d> const& original) const
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline ptr& operator=(var<derived_d> const& original)
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline ptr const& operator=(ptr<derived_d> const& original) const
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		inline ptr& operator=(ptr<derived_d> const& original)
		{
			if (abstraction_d::t != original.t)
			{
				dec();
				abstraction_d::t = original.t;
				abstraction_d::o = original.o;
				inc();
			}
			else
			{
				abstraction_d::o = original.o;
			}
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
				abstraction_d::o->_set_pointer(*this, true);
			}
			return *this;
		}

		inline void inc() const
		{
			++(abstraction_d::t->refs_);
		}

		inline void dec() const
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

		inline void mut() const
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

		using non_constant = bool;
		using non_variable = bool;
		using is_pointer = bool;
		using abstraction = abstraction_d;

		template <typename R>
		inline R dyn() const
		{
			R r;
			abstraction_d::o->as(*this, reinterpret_cast<var<> const&>(r));
			return r;
		}

		template <typename R>
		inline R val() const
		{
			return R{ reinterpret_cast<R const&>(*this) };
		}

		template <typename R>
		inline R const& ref() const
		{
			return reinterpret_cast<R const&>(*this);
		}

		template <typename R>
		inline R& ref()
		{
			return reinterpret_cast<R&>(*this);
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator con<B> const& () const
		{
			return ref<con<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator con<B>& ()
		{
			return ref<con<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator var<B> const& () const
		{
			return ref<var<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator var<B>& ()
		{
			return ref<var<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator ptr<B> const& () const
		{
			return ref<ptr<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename abstraction_d::operations>, bool> = true>
		inline operator ptr<B>& ()
		{
			return ref<ptr<B>>();
		}

		inline adr<ptr<abstraction_d>> address() const
		{
			return adr<ptr<abstraction_d>>{ *this };
		}

		template <typename F, typename... Ps>
		inline auto pfm(F fp, Ps&&... ps) const
		{
			return fp(*this, ps...);
		}

		template <typename F, typename O, typename... Ps>
		inline auto pfm(F O::* mp, Ps&&... ps) const
		{
			return (abstraction_d::o->*mp)(*this, ps...);
		}

		template <typename other_d>
		inline bool operator==(other_d const& other) const
		{
			return abstraction_d::o->equal(*this, other);
		}

		template <typename other_d>
		inline bool operator!=(other_d const& other) const
		{
			return !abstraction_d::o->equal(*this, other);
		}

		template <typename other_d>
		inline bool operator<(other_d const& other) const
		{
			return abstraction_d::o->less(*this, other);
		}

		template <typename other_d>
		inline bool operator>(other_d const& other) const
		{
			return !abstraction_d::o->less_or_equal(*this, other);
		}

		template <typename other_d>
		inline bool operator<=(other_d const& other) const
		{
			return abstraction_d::o->less_or_equal(*this, other);
		}

		template <typename other_d>
		inline bool operator>=(other_d const& other) const
		{
			return !abstraction_d::o->less(*this, other);
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
			return abstraction_d::o->_operator_star(*this);
		}

		inline auto* operator->() const
		{
			return abstraction_d::o->_operator_arrow(*this);
		}

		inline fit const& operator++() const // pre
		{
			abstraction_d::o->increment(*this);
			return *this;
		}

		inline fit& operator++() // pre
		{
			abstraction_d::o->increment(*this);
			return *this;
		}

		inline fit operator++(int) const // post
		{
			auto before = *this;
			abstraction_d::o->increment(*this);
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
			abstraction_d::o->increment(*this);
			return *this;
		}

		inline bit& operator++() // pre
		{
			abstraction_d::o->increment(*this);
			return *this;
		}

		inline bit operator++(int) const // post
		{
			auto before = *this;
			abstraction_d::o->increment(*this);
			return before;
		}

		inline bit const& operator--() const // pre
		{
			abstraction_d::o->decrement(*this);
			return *this;
		}

		inline bit& operator--() // pre
		{
			abstraction_d::o->decrement(*this);
			return *this;
		}

		inline bit operator--(int) const // post
		{
			auto before = *this;
			abstraction_d::o->decrement(*this);
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
			abstraction_d::o->increment(*this);
			return *this;
		}

		inline rat& operator++() // pre
		{
			abstraction_d::o->increment(*this);
			return *this;
		}

		inline rat operator++(int) const // post
		{
			auto before = *this;
			abstraction_d::o->increment(*this);
			return before;
		}

		inline rat const& operator--() const // pre
		{
			abstraction_d::o->decrement(*this);
			return *this;
		}

		inline rat& operator--() // pre
		{
			abstraction_d::o->decrement(*this);
			return *this;
		}

		inline rat operator--(int) const // post
		{
			auto before = *this;
			abstraction_d::o->decrement(*this);
			return before;
		}

		inline rat const& operator+=(int64_t offset) const
		{
			abstraction_d::o->self_add(*this, offset);
			return *this;
		}

		inline rat& operator+=(int64_t offset)
		{
			abstraction_d::o->self_add(*this, offset);
			return *this;
		}

		inline rat const& operator-=(int64_t offset) const
		{
			abstraction_d::o->self_add(*this, -offset);
			return *this;
		}

		inline rat& operator-=(int64_t offset)
		{
			abstraction_d::o->self_add(*this, -offset);
			return *this;
		}

		inline rat operator+(int64_t offset) const
		{
			return abstraction_d::o->add(*this, offset);
		}

		inline rat operator-(int64_t offset) const
		{
			return abstraction_d::o->add(*this, -offset);
		}
	};

	// address - weak pointer
	template <typename value_d>
	struct adr : value_d::abstraction
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

		inline adr const& operator=(adr const& original) const // copy assignment operator
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
			return *this;
		}

		inline adr& operator=(adr const& original) // copy assignment operator
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
