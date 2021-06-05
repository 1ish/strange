#ifndef COM_ONEISH__STRANGE__VAL_U_H
#define COM_ONEISH__STRANGE__VAL_U_H

namespace strange
{
	template <typename A = any_a>
	struct var;

	template <typename A = any_a>
	struct ptr;

	template <typename A = any_a>
	struct con : A
	{
		inline con()
		{
			auto const n = A::t->create_nothing_f();
			static typename A::operations const operations = [](void const* const nops, uint64_t const size)
			{
				typename A::operations ops = {};
				std::memcpy(&ops, nops, size);
				ops.cat = A::cat_f;
				return ops;
			}(n.o, sizeof(*(n.o)));
			A::t = n.t;
			A::o = &operations;
			inc();
		}

		explicit inline con(A const& abstraction) : A{ abstraction }
		{
			inc();
			if (A::o->_pointer(*this))
			{
				A::o->_set_pointer(*this, false);
				mut();
			}
		}

		inline con(con const& original) : A{ original } // copy constructor
		{
			inc();
		}

		explicit inline con(var<A> const& original) : A{ original }
		{
			inc();
		}

		explicit inline con(ptr<A> const& original) : A{ original }
		{
			inc();
			A::o->_set_pointer(*this, false);
			mut();
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		explicit inline con(con<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		explicit inline con(var<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		explicit inline con(ptr<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
			A::o->_set_pointer(*this, false);
			mut();
		}

		inline ~con()
		{
			dec();
		}

		inline con& operator=(con const& original) = delete; // copy assignment operator

		inline void inc() const
		{
			++(A::t->refs);
		}

		inline void dec() const
		{
			if (!--(A::t->refs))
			{
				A::o->_free(reinterpret_cast<any_a const&>(*this));
			}
		}

		inline void mut() const
		{
			if (A::t->refs > 1)
			{
				A cp;
				A::o->_copy(reinterpret_cast<any_a const&>(*this), reinterpret_cast<any_a&>(cp));
				dec();
				A::t = cp.t;
				A::o = cp.o;
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
			A::o->as(*this, reinterpret_cast<var<> const&>(r));
			return r;
		}

		template <typename R, typename R::is_pointer = true>
		inline R dyn() const
		{
			R r;
			A::o->as(*this, reinterpret_cast<var<> const&>(r));
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

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename A::operations>, bool> = true>
		inline operator con<B> const& () const
		{
			return ref<con<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename A::operations>, bool> = true>
		inline operator con<B>& ()
		{
			return ref<con<B>>();
		}

		template <typename F, typename... Ps>
		inline auto op(F fp, Ps&&... ps) const
		{
			return fp(*this, ps...);
		}

		template <typename F, typename O, typename... Ps>
		inline auto op(F O::* mp, Ps&&... ps) const
		{
			return (A::o->*mp)(*this, ps...);
		}
	};

	template <typename A>
	struct var : A
	{
		inline var()
		{
			auto const n = A::t->create_nothing_f();
			static typename A::operations const operations = [](void const* const nops, uint64_t const size)
			{
				typename A::operations ops = {};
				std::memcpy(&ops, nops, size);
				ops.cat = A::cat_f;
				return ops;
			}(n.o, sizeof(*(n.o)));
			A::t = n.t;
			A::o = &operations;
			inc();
		}

		explicit inline var(A const& abstraction) : A{ abstraction }
		{
			inc();
			if (A::o->_pointer(*this))
			{
				A::o->_set_pointer(*this, false);
				mut();
			}
		}

		explicit inline var(con<A> const& original) : A{ original }
		{
			inc();
		}

		inline var(var const& original) : A{ original } // copy constructor
		{
			inc();
		}

		explicit inline var(ptr<A> const& original) : A{ original }
		{
			inc();
			A::o->_set_pointer(*this, false);
			mut();
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		explicit inline var(con<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		explicit inline var(var<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		explicit inline var(ptr<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
			A::o->_set_pointer(*this, false);
			mut();
		}

		inline ~var()
		{
			dec();
		}

		inline var const& operator=(con<A> const& original) const
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			return *this;
		}

		inline var const& operator=(var const& original) const // copy assignment operator
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			return *this;
		}

		inline var const& operator=(ptr<A> const& original) const
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			A::o->_set_pointer(*this, false);
			mut();
			return *this;
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var const& operator=(con<D> const& original) const
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			return *this;
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var const& operator=(var<D> const& original) const
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			return *this;
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var const& operator=(ptr<D> const& original) const
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			A::o->_set_pointer(*this, false);
			mut();
			return *this;
		}

		inline void inc() const
		{
			++(A::t->refs);
		}

		inline void dec() const
		{
			if (!--(A::t->refs))
			{
				A::o->_free(reinterpret_cast<any_a const&>(*this));
			}
		}

		inline void mut() const
		{
			if (A::t->refs > 1)
			{
				A cp;
				A::o->_copy(reinterpret_cast<any_a const&>(*this), reinterpret_cast<any_a&>(cp));
				dec();
				A::t = cp.t;
				A::o = cp.o;
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
			A::o->as(*this, reinterpret_cast<var<> const&>(r));
			return r;
		}

		template <typename R, typename R::is_pointer = true>
		inline R dyn() const
		{
			R r;
			A::o->as(*this, reinterpret_cast<var<> const&>(r));
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

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename A::operations>, bool> = true>
		inline operator con<B> const& () const
		{
			return ref<con<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename A::operations>, bool> = true>
		inline operator con<B>& ()
		{
			return ref<con<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename A::operations>, bool> = true>
		inline operator var<B> const& () const
		{
			return ref<var<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename A::operations>, bool> = true>
		inline operator var<B>& ()
		{
			return ref<var<B>>();
		}

		template <typename F, typename... Ps>
		inline auto op(F fp, Ps&&... ps) const
		{
			return fp(*this, ps...);
		}

		template <typename F, typename O, typename... Ps>
		inline auto op(F O::* mp, Ps&&... ps) const
		{
			return (A::o->*mp)(*this, ps...);
		}
	};

	template <typename A>
	struct ptr : A
	{
		inline ptr()
		{
			auto n = A::t->create_nothing_f();
			n.o->_set_pointer(n, true);
			static typename A::operations const operations = [](void const* const nops, uint64_t const size)
			{
				typename A::operations ops = {};
				std::memcpy(&ops, nops, size);
				ops.cat = A::cat_f;
				return ops;
			}(n.o, sizeof(*(n.o)));
			A::t = n.t;
			A::o = &operations;
			inc();
			mut();
		}

		explicit inline ptr(A const& abstraction) : A{ abstraction }
		{
			inc();
			if (!A::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
			}
		}

		explicit inline ptr(con<A> const& original) : A{ original }
		{
			inc();
			mut();
		}

		explicit inline ptr(var<A> const& original) : A{ original }
		{
			inc();
			mut();
		}

		inline ptr(ptr const& original) : A{ original } // copy constructor
		{
			inc();
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		explicit inline ptr(con<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
			mut();
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		explicit inline ptr(var<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
			mut();
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		explicit inline ptr(ptr<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
		}

		inline ~ptr()
		{
			dec();
		}

		inline ptr const& operator=(con<A> const& original) const
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			mut();
			return *this;
		}

		inline ptr const& operator=(var<A> const& original) const
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			mut();
			return *this;
		}

		inline ptr const& operator=(ptr const& original) const // copy assignment operator
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			return *this;
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr const& operator=(con<D> const& original) const
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			mut();
			return *this;
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr const& operator=(var<D> const& original) const
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			mut();
			return *this;
		}

		template <typename D, std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr const& operator=(ptr<D> const& original) const
		{
			if (A::t != original.t)
			{
				dec();
				A::t = original.t;
				A::o = original.o;
				inc();
			}
			else
			{
				A::o = original.o;
			}
			return *this;
		}

		inline void inc() const
		{
			++(A::t->refs);
		}

		inline void dec() const
		{
			if (!--(A::t->refs))
			{
				A::o->_free(reinterpret_cast<any_a const&>(*this));
			}
		}

		inline void mut() const
		{
			if (A::t->refs > 1)
			{
				A cp;
				A::o->_copy(reinterpret_cast<any_a const&>(*this), reinterpret_cast<any_a&>(cp));
				dec();
				A::t = cp.t;
				A::o = cp.o;
				inc();
				A::o->_set_pointer(reinterpret_cast<var<> const&>(*this), true);
			}
		}

		using non_constant = bool;
		using non_variable = bool;
		using is_pointer = bool;

		template <typename R, typename R::is_pointer = true>
		inline R dyn() const
		{
			R r;
			A::o->as(reinterpret_cast<con<> const&>(*this), reinterpret_cast<var<> const&>(r));
			return r;
		}

		template <typename R, typename R::non_pointer = true>
		inline R dyn() const
		{
			R r;
			A::o->as(reinterpret_cast<con<> const&>(*this), reinterpret_cast<var<> const&>(r));
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

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename A::operations>, bool> = true>
		inline operator ptr<B> const& () const
		{
			return ref<ptr<B>>();
		}

		template <typename B, std::enable_if_t<std::is_base_of_v<typename B::operations, typename A::operations>, bool> = true>
		inline operator ptr<B>& ()
		{
			return ref<ptr<B>>();
		}

		template <typename F, typename... Ps>
		inline auto op(F fp, Ps&&... ps) const
		{
			return fp(*this, ps...);
		}

		template <typename F, typename O, typename... Ps>
		inline auto op(F O::* mp, Ps&&... ps) const
		{
			return (A::o->*mp)(*this, ps...);
		}
	};
}

#endif
