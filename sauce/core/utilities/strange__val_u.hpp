#ifndef COM_ONEISH__STRANGE__VAL_U_H
#define COM_ONEISH__STRANGE__VAL_U_H

namespace strange
{
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

		explicit inline con(abstraction_d const& abstraction) : abstraction_d{ abstraction }
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
		}

		explicit inline con(var<abstraction_d> const& original) : abstraction_d{ original }
		{
			inc();
		}

		explicit inline con(ptr<abstraction_d> const& original) : abstraction_d{ original }
		{
			inc();
			abstraction_d::o->_set_pointer(*this, false);
			mut();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline con(con<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline con(var<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline con(ptr<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			abstraction_d::o->_set_pointer(*this, false);
			mut();
		}

		inline ~con()
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
			}
		}

		inline void mut() const
		{
			if (abstraction_d::t->refs_ > 1)
			{
				abstraction_d cp;
				abstraction_d::o->_copy(reinterpret_cast<any_a const&>(*this), reinterpret_cast<any_a&>(cp));
				dec();
				abstraction_d::t = cp.t;
				abstraction_d::o = cp.o;
				inc();
			}
		}

		using is_constant = bool;
		using non_variable = bool;
		using non_pointer = bool;

		template <typename R, typename R::non_pointer = true>
		inline R dyn() const
		{
			R r;
			abstraction_d::o->as(*this, reinterpret_cast<var<> const&>(r));
			return r;
		}

		template <typename R, typename R::is_pointer = true>
		inline R dyn() const
		{
			R r;
			abstraction_d::o->as(*this, reinterpret_cast<var<> const&>(r));
			r.mut();
			return r;
		}

		template <typename R, typename R::non_pointer = true>
		inline R val() const
		{
			return R{ reinterpret_cast<R const&>(*this) };
		}

		template <typename R, typename R::is_pointer = true>
		inline R val() const
		{
			R r{ reinterpret_cast<R const&>(*this) };
			r.mut();
			return r;
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
	};

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

		explicit inline var(abstraction_d const& abstraction) : abstraction_d{ abstraction }
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
		}

		inline var(var const& original) : abstraction_d{ original } // copy constructor
		{
			inc();
		}

		explicit inline var(ptr<abstraction_d> const& original) : abstraction_d{ original }
		{
			inc();
			abstraction_d::o->_set_pointer(*this, false);
			mut();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(con<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(var<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline var(ptr<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			abstraction_d::o->_set_pointer(*this, false);
			mut();
		}

		inline ~var()
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
			abstraction_d::o->_set_pointer(*this, false);
			mut();
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
			abstraction_d::o->_set_pointer(*this, false);
			mut();
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
			abstraction_d::o->_set_pointer(*this, false);
			mut();
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
			abstraction_d::o->_set_pointer(*this, false);
			mut();
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
			}
		}

		inline void mut() const
		{
			if (abstraction_d::t->refs_ > 1)
			{
				abstraction_d cp;
				abstraction_d::o->_copy(reinterpret_cast<any_a const&>(*this), reinterpret_cast<any_a&>(cp));
				dec();
				abstraction_d::t = cp.t;
				abstraction_d::o = cp.o;
				inc();
			}
		}

		using non_constant = bool;
		using is_variable = bool;
		using non_pointer = bool;

		template <typename R, typename R::non_pointer = true>
		inline R dyn() const
		{
			R r;
			abstraction_d::o->as(*this, reinterpret_cast<var<> const&>(r));
			return r;
		}

		template <typename R, typename R::is_pointer = true>
		inline R dyn() const
		{
			R r;
			abstraction_d::o->as(*this, reinterpret_cast<var<> const&>(r));
			r.mut();
			return r;
		}

		template <typename R, typename R::non_pointer = true>
		inline R val() const
		{
			return R{ reinterpret_cast<R const&>(*this) };
		}

		template <typename R, typename R::is_pointer = true>
		inline R val() const
		{
			R r{ reinterpret_cast<R const&>(*this) };
			r.mut();
			return r;
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
	};

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
			mut();
		}

		explicit inline ptr(abstraction_d const& abstraction) : abstraction_d{ abstraction }
		{
			inc();
			if (!abstraction_d::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
			}
		}

		explicit inline ptr(con<abstraction_d> const& original) : abstraction_d{ original }
		{
			inc();
			mut();
		}

		explicit inline ptr(var<abstraction_d> const& original) : abstraction_d{ original }
		{
			inc();
			mut();
		}

		inline ptr(ptr const& original) : abstraction_d{ original } // copy constructor
		{
			inc();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline ptr(con<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			mut();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline ptr(var<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
			mut();
		}

		template <typename derived_d, std::enable_if_t<std::is_base_of_v<typename abstraction_d::operations, typename derived_d::operations>, bool> = true>
		explicit inline ptr(ptr<derived_d> const& derived) : abstraction_d{ reinterpret_cast<abstraction_d const&>(derived) }
		{
			inc();
		}

		inline ~ptr()
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
			mut();
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
			mut();
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
			mut();
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
			mut();
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
			mut();
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
			mut();
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
			mut();
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
			mut();
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
			}
		}

		inline void mut() const
		{
			if (abstraction_d::t->refs_ > 1)
			{
				abstraction_d cp;
				abstraction_d::o->_copy(reinterpret_cast<any_a const&>(*this), reinterpret_cast<any_a&>(cp));
				dec();
				abstraction_d::t = cp.t;
				abstraction_d::o = cp.o;
				inc();
				abstraction_d::o->_set_pointer(reinterpret_cast<var<> const&>(*this), true);
			}
		}

		using non_constant = bool;
		using non_variable = bool;
		using is_pointer = bool;

		template <typename R, typename R::is_pointer = true>
		inline R dyn() const
		{
			R r;
			abstraction_d::o->as(reinterpret_cast<con<> const&>(*this), reinterpret_cast<var<> const&>(r));
			return r;
		}

		template <typename R, typename R::non_pointer = true>
		inline R dyn() const
		{
			R r;
			abstraction_d::o->as(reinterpret_cast<con<> const&>(*this), reinterpret_cast<var<> const&>(r));
			r.o->_set_pointer(reinterpret_cast<var<> const&>(r), false);
			r.mut();
			return r;
		}

		template <typename R, typename R::is_pointer = true>
		inline R val() const
		{
			return R{ reinterpret_cast<R const&>(*this) };
		}

		template <typename R, typename R::non_pointer = true>
		inline R val() const
		{
			R r{ reinterpret_cast<R const&>(*this) };
			r.o->_set_pointer(reinterpret_cast<var<> const&>(r), false);
			r.mut();
			return r;
		}

		template <typename R>
		inline R const& ref() const
		{
			static_assert(typename R::is_pointer{ true });
			return reinterpret_cast<R const&>(*this);
		}

		template <typename R>
		inline R& ref()
		{
			static_assert(typename R::is_pointer{ true });
			return reinterpret_cast<R&>(*this);
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
	};

	template <typename abstraction_d>
	struct fit : var<abstraction_d>
	{
		explicit inline fit(abstraction_d const& abstraction) : var<abstraction_d>{ abstraction }
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

		inline bool operator==(con<> const& other) const
		{
			return abstraction_d::o->equal(*this, other);
		}

		inline bool operator!=(con<> const& other) const
		{
			return !abstraction_d::o->equal(*this, other);
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

	template <typename abstraction_d>
	struct bit : fit<abstraction_d>
	{
		explicit inline bit(abstraction_d const& abstraction) : fit<abstraction_d>{ abstraction }
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

	template <typename abstraction_d>
	struct rat : bit<abstraction_d>
	{
		explicit inline rat(abstraction_d const& abstraction) : bit<abstraction_d>{ abstraction }
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
}

#endif
