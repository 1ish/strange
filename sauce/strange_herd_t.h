#ifndef COM_ONEISH_STRANGE_HERD_T_H
#define COM_ONEISH_STRANGE_HERD_T_H

#include <unordered_set>
#include <set>

namespace strange
{

template <typename _ABSTRACTION_ = herd_a>
class herd_t : public something_t<_ABSTRACTION_>
{
	class hash_f
	{
	public:
		inline std::size_t operator()(any_a thing) const
		{
			return thing.hash__();
		}
	};

	using std_unordered_set_any = std::unordered_set<any_a, hash_f>;

	template <typename ITERATOR, typename _ABSTRACTION_ = any_a>
	class iterator_t : public something_t<_ABSTRACTION_>
	{
	public: ___THING___
		// construction
		static inline any_a val(any_a range)
		{
			assert(false);
			return nothing_t<>::val_();
		}

		template <typename F>
		static inline any_a val__(herd_a herd, F&& it)
		{
			return any_a{ iterator_t(std::move(herd), std::forward<F>(it)) };
		}

		static inline any_a ref(any_a range)
		{
			assert(false);
			return nothing_t<>::val_();
		}

		template <typename F>
		static inline any_a ref__(herd_a herd, F&& it)
		{
			return any_a(iterator_t(std::move(herd), std::forward<F>(it)), true);
		}

		// reflection
		static inline symbol_a type_()
		{
			static symbol_a TYPE = sym__("strange::herd::iterator");
			return TYPE;
		}

		// comparison
		inline bool operator==(any_a thing) const
		{
			if (!type_().identical__(thing.type_()))
			{
				return false;
			}
			return _it == reinterpret_cast<const iterator_t<ITERATOR, _ABSTRACTION_>*>(thing.identity__())->_it;
		}

		inline bool operator!=(any_a thing) const
		{
			if (!type_().identical__(thing.type_()))
			{
				return true;
			}
			return _it != reinterpret_cast<const iterator_t<ITERATOR, _ABSTRACTION_>*>(thing.identity__())->_it;
		}

		inline std::size_t hash__() const
		{
			return std::hash<const void*>{}(&*_it);
		}

		// iterator
		inline any_a& operator*() const
		{
			return const_cast<any_a&>(*_it);
		}

		inline iterator_t& operator++()
		{
			++_it;
			return *this;
		}

		inline iterator_t operator++(int)
		{
			iterator_t result = *this;
			operator++();
			return result;
		}

	private:
		ITERATOR _it;
		herd_a _herd;

		template <typename F>
		inline iterator_t(herd_a herd, F&& it)
			: something_t{}
			, _it{ std::forward<F>(it) }
			, _herd(std::move(herd), true)
		{}
	};

public: ___COLLECTION___
	// construction
	static inline herd_a val(any_a range)
	{
		return cast_<herd_a>(val_() += range);
	}

	static inline herd_a val_()
	{
		return val__(std_unordered_set_any{});
	}

	template <typename F>
	static inline herd_a val__(F&& init)
	{
		return herd_a{ herd_t{ std::forward<F>(init) } };
	}

	static inline herd_a ref(any_a range)
	{
		return cast_<herd_a>(ref_() += range, true);
	}

	static inline herd_a ref_()
	{
		return ref__(std_unordered_set_any{});
	}

	template <typename F>
	static inline herd_a ref__(F&& init)
	{
		return herd_a(herd_t{ std::forward<F>(init) }, true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::herd");
		return TYPE;
	}

	inline any_a feeder(any_a range) const // return range of parameter values
	{
		return nothing_t<>::val_(); //TODO
	}

	// visitor pattern
	static inline any_a visit(any_a range)
	{
		return nothing_t<>::val_(); //TODO
	}

	// comparison
	inline bool operator==(any_a thing) const
	{
		if (!type_().identical__(thing.type_()))
		{
			return false;
		}
		return _set == reinterpret_cast<const herd_t<_ABSTRACTION_>*>(thing.identity__())->_set;
	}

	inline bool operator!=(any_a thing) const
	{
		if (!type_().identical__(thing.type_()))
		{
			return true;
		}
		return _set != reinterpret_cast<const herd_t<_ABSTRACTION_>*>(thing.identity__())->_set;
	}

	inline std::size_t hash__() const
	{
		const std::set<any_a> ordered(_set.cbegin(), _set.cend());
		std::size_t seed = std::hash<std::size_t>{}(_set.size());
		for (const auto item : ordered)
		{
			seed ^= item.hash__() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline any_a cbegin() const
	{
		return iterator_t<std_unordered_set_any::const_iterator>::val__(me_(), _set.cbegin());
	}

	inline any_a begin()
	{
		return iterator_t<std_unordered_set_any::iterator>::val__(me_(), _set.begin());
	}

	inline any_a cend() const
	{
		return iterator_t<std_unordered_set_any::const_iterator>::val__(me_(), _set.cend());
	}

	inline any_a end()
	{
		return iterator_t<std_unordered_set_any::iterator>::val__(me_(), _set.end());
	}

	// collection
	inline bool has__(any_a key) const
	{
		const std_unordered_set_any::const_iterator it = _set.find(key);
		return it != _set.cend();
	}

	inline bool has__(const std::string& s) const
	{
		return has__(sym__(s));
	}

	inline any_a at_(any_a key) const
	{
		const std_unordered_set_any::const_iterator it = _set.find(key);
		if (it == _set.cend())
		{
			return nothing_t<>::val_();
		}
		return *it;
	}

	inline bool at__(const std::string& s) const
	{
		const std_unordered_set_any::const_iterator it = _set.find(sym__(s));
		return it != _set.cend();
	}

	inline any_a update_(any_a key, any_a value)
	{
		_set.insert(key);
		return value;
	}

	inline bool insert__(any_a key, any_a)
	{
		return _set.insert(key).second;
	}

	inline bool insert__(const std::string& s)
	{
		return _set.insert(sym__(s)).second;
	}

	inline bool erase__(any_a key)
	{
		return _set.erase(key);
	}

	inline bool erase__(const std::string& s)
	{
		return _set.erase(sym__(s));
	}

	inline void clear__()
	{
		_set.clear();
	}

	inline int64_t size__() const
	{
		return int64_t(_set.size());
	}

	inline bool empty__() const
	{
		return _set.empty();
	}

	inline void push_front__(any_a thing)
	{
		push_back__(thing);
	}

	inline any_a pop_front_()
	{
		return pop_back_();
	}

	inline void push_back__(any_a thing)
	{
		_set.insert(thing);
	}

	inline any_a pop_back_()
	{
		const std_unordered_set_any::const_iterator it = _set.cbegin();
		if (it == _set.cend())
		{
			return nothing_t<>::val_();
		}
		any_a result = *it;
		_set.erase(it);
		return result;
	}

	inline herd_t& operator+=(any_a range)
	{
		for (const auto thing : range)
		{
			insert(thing);
		}
		return *this;
	}

	inline herd_t& operator-=(any_a range)
	{
		for (const auto thing : range)
		{
			erase(thing);
		}
		return *this;
	}

protected:
	std_unordered_set_any _set;

	template <typename F>
	inline herd_t(F&& init)
		: something_t{}
		, _set{ std::forward<F>(init) }
	{}
};

} // namespace strange

#endif
