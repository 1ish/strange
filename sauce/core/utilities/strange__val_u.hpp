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
				ops.cat = A::cat_e;
				return ops;
			}(n.o, sizeof(*(n.o)));
			A::t = n.t;
			A::o = &operations;
			inc();
		}

		explicit inline con(A const& abstraction) : A{ abstraction }
		{
			inc();
			if (A::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
				mut();
			}
		}

		inline con(con const& original) : A{ original }
		{
			inc();
		}

		inline con(var<A> const& original) : A{ original }
		{
			inc();
		}

		inline con(ptr<A> const& original) : A{ original }
		{
			inc();
			A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
			mut();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline con(con<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline con(var<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline con(ptr<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
			A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
			mut();
		}

		inline ~con()
		{
			dec();
		}

		inline void inc() const
		{
			++(A::t->refs);
		}

		inline void dec()
		{
			if (!--(A::t->refs))
			{
				A::o->_free(reinterpret_cast<any_a&>(*this));
			}
		}

		inline void mut()
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

		using non_pointer = bool;

		template <typename T>
		inline T dynamic() const
		{
			static_assert(typename T::non_pointer{ true });
			T t;
			t.o->as(reinterpret_cast<con<> const&>(*this), reinterpret_cast<var<>&>(t));
			return t;
		}

		template <typename T>
		inline T value() const
		{
			static_assert(typename T::non_pointer{ true });
			return T{ reinterpret_cast<T const&>(*this) };
		}

		template <typename T>
		inline T const& reference() const
		{
			static_assert(typename T::non_pointer{ true });
			return reinterpret_cast<T const&>(*this);
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
				ops.cat = A::cat_e;
				return ops;
			}(n.o, sizeof(*(n.o)));
			A::t = n.t;
			A::o = &operations;
			inc();
		}

		explicit inline var(A const& abstraction) :A { abstraction }
		{
			inc();
			if (A::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
				mut();
			}
		}

		inline var(con<A> const& original) : A{ original }
		{
			inc();
		}

		inline var(var const& original) : A{ original }
		{
			inc();
		}

		inline var(ptr<A> const& original) : A{ original }
		{
			inc();
			A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
			mut();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var(con<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var(var<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var(ptr<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
			A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
			mut();
		}

		inline ~var()
		{
			dec();
		}

		inline var const& operator=(con<A> const& original)
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

		inline var const& operator=(var const& original)
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

		inline var const& operator=(ptr<A> const& original)
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
			A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
			mut();
			return *this;
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var const& operator=(con<D> const& original)
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

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var const& operator=(var<D> const& original)
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

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var const& operator=(ptr<D> const& original)
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
			A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
			mut();
			return *this;
		}

		inline void inc() const
		{
			++(A::t->refs);
		}

		inline void dec()
		{
			if (!--(A::t->refs))
			{
				A::o->_free(reinterpret_cast<any_a&>(*this));
			}
		}

		inline void mut()
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

		using non_pointer = bool;

		template <typename T>
		inline T dynamic() const
		{
			static_assert(typename T::non_pointer{ true });
			T t;
			t.o->as(reinterpret_cast<con<> const&>(*this), reinterpret_cast<var<>&>(t));
			return t;
		}

		template <typename T>
		inline T value() const
		{
			static_assert(typename T::non_pointer{ true });
			return T{ reinterpret_cast<T const&>(*this) };
		}

		template <typename T>
		inline T const& reference() const
		{
			static_assert(typename T::non_pointer{ true });
			return reinterpret_cast<T const&>(*this);
		}

		template <typename T>
		inline T& reference()
		{
			static_assert(typename T::non_pointer{ true });
			return reinterpret_cast<T&>(*this);
		}
	};

	template <typename A>
	struct ptr : A
	{
		inline ptr()
		{
			auto n = A::t->create_nothing_f();
			n.o->_set_pointer(&n, true);
			static typename A::operations const operations = [](void const* const nops, uint64_t const size)
			{
				typename A::operations ops = {};
				std::memcpy(&ops, nops, size);
				ops.cat = A::cat_e;
				return ops;
			}(n.o, sizeof(*(n.o)));
			A::t = n.t;
			A::o = &operations;
			inc();
			mut();
		}

		explicit inline ptr(A const& abstraction) :A{ abstraction }
		{
			inc();
			if (!A::o->_pointer(reinterpret_cast<con<> const&>(*this)))
			{
				mut();
			}
		}

		inline ptr(con<A> const& original) : A{ original }
		{
			inc();
			mut();
		}

		inline ptr(var<A> const& original) : A{ original }
		{
			inc();
			mut();
		}

		inline ptr(ptr const& original) : A{ original }
		{
			inc();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr(con<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
			mut();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr(var<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
			mut();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr(ptr<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			inc();
		}

		inline ~ptr()
		{
			dec();
		}

		inline ptr const& operator=(con<A> const& original)
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

		inline ptr const& operator=(var<A> const& original)
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

		inline ptr const& operator=(ptr const& original)
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

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr const& operator=(con<D> const& original)
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

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr const& operator=(var<D> const& original)
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

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr const& operator=(ptr<D> const& original)
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

		inline void dec()
		{
			if (!--(A::t->refs))
			{
				A::o->_free(reinterpret_cast<any_a&>(*this));
			}
		}

		inline void mut()
		{
			if (A::t->refs > 1)
			{
				A cp;
				A::o->_copy(reinterpret_cast<any_a const&>(*this), reinterpret_cast<any_a&>(cp));
				dec();
				A::t = cp.t;
				A::o = cp.o;
				inc();
				A::o->_set_pointer(reinterpret_cast<var<>&>(*this), true);
			}
		}

		using is_pointer = bool;

		template <typename T>
		inline T dynamic() const
		{
			static_assert(typename T::is_pointer{ true });
			T t;
			t.o->as(reinterpret_cast<con<> const&>(*this), reinterpret_cast<var<>&>(t));
			return t;
		}

		template <typename T>
		inline T value() const
		{
			static_assert(typename T::is_pointer{ true });
			return T{ reinterpret_cast<T const&>(*this) };
		}

		template <typename T>
		inline T const& reference() const
		{
			static_assert(typename T::is_pointer{ true });
			return reinterpret_cast<T const&>(*this);
		}

		template <typename T>
		inline T& reference()
		{
			static_assert(typename T::is_pointer{ true });
			return reinterpret_cast<T&>(*this);
		}
	};
}

#endif
