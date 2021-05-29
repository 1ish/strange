#ifndef COM_ONEISH__STRANGE__VAL_U_H
#define COM_ONEISH__STRANGE__VAL_U_H

namespace strange
{
	template <typename A = any_a>
	struct var;

	template <typename A = any_a>
	struct ptr;

	template <typename A = any_a>
	struct val : A
	{
		inline val()
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
			ref();
		}

		explicit inline val(A const& abstraction) : A{ abstraction }
		{
			ref();
			if (A::o->_pointer(reinterpret_cast<val<> const&>(*this)))
			{
				A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
				mut();
			}
		}

		inline val(val const& original) : A{ original }
		{
			ref();
		}

		inline val(var<A> const& original) : A{ original }
		{
			ref();
		}

		inline val(ptr<A> const& original) : A{ original }
		{
			ref();
			A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
			mut();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline val(val<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			ref();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline val(var<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			ref();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline val(ptr<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			ref();
			A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
			mut();
		}

		inline ~val()
		{
			rel();
		}

		inline void ref() const
		{
			++(A::t->refs);
		}

		inline void rel()
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
				rel();
				A::t = cp.t;
				A::o = cp.o;
				ref();
			}
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
			ref();
		}

		explicit inline var(A const& abstraction) :A { abstraction }
		{
			ref();
			if (A::o->_pointer(reinterpret_cast<val<> const&>(*this)))
			{
				A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
				mut();
			}
		}

		inline var(val<A> const& original) : A{ original }
		{
			ref();
		}

		inline var(var const& original) : A{ original }
		{
			ref();
		}

		inline var(ptr<A> const& original) : A{ original }
		{
			ref();
			A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
			mut();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var(val<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			ref();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var(var<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			ref();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline var(ptr<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			ref();
			A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
			mut();
		}

		inline ~var()
		{
			rel();
		}
/*
		inline var const& operator=(A const& abstraction)
		{
			if (A::t != abstraction.t)
			{
				rel();
				A::t = abstraction.t;
				A::o = abstraction.o;
				ref();
			}
			else
			{
				A::o = abstraction.o;
			}
			if (A::o->_pointer(reinterpret_cast<val<> const&>(*this)))
			{
				A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
				mut();
			}
			return *this;
		}
*/
		inline var const& operator=(val<A> const& original)
		{
			if (A::t != original.t)
			{
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
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
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
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
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
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
		inline var const& operator=(val<D> const& original)
		{
			if (A::t != original.t)
			{
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
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
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
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
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
			}
			else
			{
				A::o = original.o;
			}
			A::o->_set_pointer(reinterpret_cast<var<>&>(*this), false);
			mut();
			return *this;
		}

		inline void ref() const
		{
			++(A::t->refs);
		}

		inline void rel()
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
				rel();
				A::t = cp.t;
				A::o = cp.o;
				ref();
			}
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
			ref();
			mut();
		}

		explicit inline ptr(A const& abstraction) :A{ abstraction }
		{
			ref();
			if (!A::o->_pointer(reinterpret_cast<val<> const&>(*this)))
			{
				mut();
			}
		}

		inline ptr(val<A> const& original) : A{ original }
		{
			ref();
			mut();
		}

		inline ptr(var<A> const& original) : A{ original }
		{
			ref();
			mut();
		}

		inline ptr(ptr const& original) : A{ original }
		{
			ref();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr(val<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			ref();
			mut();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr(var<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			ref();
			mut();
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr(ptr<D> const& derived) : A{ reinterpret_cast<A const&>(derived) }
		{
			ref();
		}

		inline ~ptr()
		{
			rel();
		}
/*
		inline ptr const& operator=(A const& abstraction)
		{
			if (A::t != abstraction.t)
			{
				rel();
				A::t = abstraction.t;
				A::o = abstraction.o;
				ref();
			}
			else
			{
				A::o = abstraction.o;
			}
			if (!A::o->_pointer(reinterpret_cast<val<> const&>(*this)))
			{
				mut();
			}
			return *this;
		}
*/
		inline ptr const& operator=(val<A> const& original)
		{
			if (A::t != original.t)
			{
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
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
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
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
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
			}
			else
			{
				A::o = original.o;
			}
			return *this;
		}

		template <typename D,
			std::enable_if_t<std::is_base_of_v<typename A::operations, typename D::operations>, bool> = true>
		inline ptr const& operator=(val<D> const& original)
		{
			if (A::t != original.t)
			{
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
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
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
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
				rel();
				A::t = original.t;
				A::o = original.o;
				ref();
			}
			else
			{
				A::o = original.o;
			}
			return *this;
		}

		inline void ref() const
		{
			++(A::t->refs);
		}

		inline void rel()
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
				rel();
				A::t = cp.t;
				A::o = cp.o;
				ref();
				A::o->_set_pointer(reinterpret_cast<var<>&>(*this), true);
			}
		}
	};
}

#endif
