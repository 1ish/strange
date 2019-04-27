#ifndef COM_ONEISH_STRANGE_SHOAL_T_H
#define COM_ONEISH_STRANGE_SHOAL_T_H

#include <unordered_map>
#include <map>

namespace strange
{

template <typename _ABSTRACTION_ = shoal_a>
class shoal_t : public something_t<_ABSTRACTION_>
{
	class hash_f
	{
	public:
		inline std::size_t operator()(any_a thing) const
		{
			return thing.hash__();
		}
	};

	using std_unordered_map_any_any = std::unordered_map<any_a, any_a, hash_f>;

	template <typename ITERATOR, typename _ABSTRACTION_ = data_a<ITERATOR>>
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
		static inline data_a<ITERATOR> val__(shoal_a shoal, F&& it)
		{
			return data_a<ITERATOR>{ iterator_t(std::move(shoal), std::forward<F>(it)) };
		}

		static inline any_a ref(any_a range)
		{
			assert(false);
			return nothing_t<>::val_();
		}

		template <typename F>
		static inline data_a<ITERATOR> ref__(shoal_a shoal, F&& it)
		{
			return data_a<ITERATOR>(iterator_t(std::move(shoal), std::forward<F>(it)), true);
		}

		// reflection
		static inline symbol_a type_()
		{
			static symbol_a TYPE = sym__("strange::shoal::iterator");
			return TYPE;
		}

		// comparison
		inline bool operator==(any_a thing) const
		{
			if (!check_<data_a<ITERATOR>>(thing))
			{
				return false;
			}
			return _it == cast_<data_a<ITERATOR>>(thing).extract__();
			/*
			if (!type_().identical__(thing.type_()))
			{
				return false;
			}
			return _it == reinterpret_cast<const iterator_t<ITERATOR, _ABSTRACTION_>*>(thing.identity__())->_it;
			*/
		}

		inline bool operator!=(any_a thing) const
		{
			if (!check_<data_a<ITERATOR>>(thing))
			{
				return true;
			}
			return _it != cast_<data_a<ITERATOR>>(thing).extract__();
			/*
			if (!type_().identical__(thing.type_()))
			{
				return true;
			}
			return _it != reinterpret_cast<const iterator_t<ITERATOR, _ABSTRACTION_>*>(thing.identity__())->_it;
			*/
		}

		inline std::size_t hash__() const
		{
			return std::hash<const void*>{}(&*_it);
		}

		// iterator
		inline any_a& operator*() const
		{
			if (!_fresh)
			{
				_pair.update__(0, _it->first);
				_pair.update__(1, _it->second);
				_fresh = true;
			}
			return _pair;
		}

		inline iterator_t& operator++()
		{
			++_it;
			_fresh = false;
			return *this;
		}

		inline iterator_t operator++(int)
		{
			iterator_t result = *this;
			operator++();
			return result;
		}

		// data
		inline const ITERATOR& extract__() const
		{
			return _it;
		}

		inline void mutate__(const ITERATOR& it)
		{
			_it = it;
		}

		inline ITERATOR& reference__()
		{
			return _it;
		}

	private:
		ITERATOR _it;
		mutable flock_a _pair;
		mutable bool _fresh;
		shoal_a _shoal;

		template <typename F>
		inline iterator_t(shoal_a shoal, F&& it)
			: something_t{}
			, _it{ std::forward<F>(it) }
			, _pair{ flock_t<>::val_() }
			, _fresh{}
			, _shoal(std::move(shoal), true)
		{}
	};

public: ___COLLECTION___
	// construction
	static inline shoal_a val(any_a range)
	{
		return cast_<shoal_a>(val_() += std::move(range));
	}

	static inline shoal_a val_()
	{
		return val__(std_unordered_map_any_any{});
	}

	template <typename F>
	static inline shoal_a val__(F&& init)
	{
		return shoal_a{ shoal_t{ std::forward<F>(init) } };
	}

	static inline shoal_a ref(any_a range)
	{
		return cast_<shoal_a>(ref_() += std::move(range), true);
	}

	static inline shoal_a ref_()
	{
		return ref__(std_unordered_map_any_any{});
	}

	template <typename F>
	static inline shoal_a ref__(F&& init)
	{
		return shoal_a(shoal_t{ std::forward<F>(init) }, true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::shoal");
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
		return _map == reinterpret_cast<const shoal_t<_ABSTRACTION_>*>(thing.identity__())->_map;
	}

	inline bool operator!=(any_a thing) const
	{
		if (!type_().identical__(thing.type_()))
		{
			return true;
		}
		return _map != reinterpret_cast<const shoal_t<_ABSTRACTION_>*>(thing.identity__())->_map;
	}

	inline std::size_t hash__() const
	{
		std::map<any_a, std::size_t> ordered;
		for (const auto& pair : _map)
		{
			std::size_t seed = pair.first.hash__();
			seed ^= pair.second.hash__() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			ordered.emplace(pair.first, seed);
		}
		std::size_t seed = std::hash<std::size_t>{}(_map.size());
		for (const auto& pair : ordered)
		{
			seed ^= pair.second + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline any_a cbegin() const
	{
		return iterator_t<std_unordered_map_any_any::const_iterator>::val__(me_(), _map.cbegin());
	}

	inline any_a begin()
	{
		return iterator_t<std_unordered_map_any_any::iterator>::val__(me_(), _map.begin());
	}

	inline any_a cend() const
	{
		return iterator_t<std_unordered_map_any_any::const_iterator>::val__(me_(), _map.cend());
	}

	inline any_a end()
	{
		return iterator_t<std_unordered_map_any_any::iterator>::val__(me_(), _map.end());
	}

	// collection
	inline bool has__(any_a key) const
	{
		const std_unordered_map_any_any::const_iterator it = _map.find(std::move(key));
		return it != _map.cend();
	}

	inline bool has__(const std::string& s) const
	{
		return has__(sym__(s));
	}

	inline any_a at_(any_a key) const
	{
		const std_unordered_map_any_any::const_iterator it = _map.find(std::move(key));
		if (it == _map.cend())
		{
			return nothing_t<>::val_();
		}
		return it->second;
	}

	inline any_a at__(const std::string& s) const
	{
		return at_(sym__(s));
	}

	inline any_a update_(any_a key, any_a value)
	{
		return _map[std::move(key)] = std::move(value);
	}

	inline void update__(const std::string& s, any_a value)
	{
		_map[sym__(s)] = std::move(value);
	}

	inline bool insert__(any_a key, any_a value)
	{
		return _map.emplace(std::move(key), std::move(value)).second;
	}

	inline bool insert__(const std::string& s, any_a value)
	{
		return insert__(sym__(s), std::move(value));
	}

	inline bool erase__(any_a key)
	{
		return _map.erase(std::move(key));
	}

	inline bool erase__(const std::string& s)
	{
		return _map.erase(sym__(s));
	}

	inline void clear__()
	{
		_map.clear();
	}

	inline int64_t size__() const
	{
		return int64_t(_map.size());
	}

	inline bool empty__() const
	{
		return _map.empty();
	}

	inline void push_front__(any_a thing)
	{
		push_back__(std::move(thing));
	}

	inline any_a pop_front_()
	{
		return pop_back_();
	}

	inline void push_back__(any_a thing)
	{
		_map[thing] = thing;
	}

	inline any_a pop_back_()
	{
		const std_unordered_map_any_any::const_iterator it = _map.cbegin();
		if (it == _map.cend())
		{
			return nothing_t<>::val_();
		}
		any_a result = it->second;
		_map.erase(it);
		return result;
	}

	inline shoal_t& operator+=(any_a range)
	{
		for (const auto thing : range)
		{
			insert(thing);
		}
		return *this;
	}

	inline shoal_t& operator-=(any_a range)
	{
		for (const auto thing : range)
		{
			erase(thing);
		}
		return *this;
	}

protected:
	std_unordered_map_any_any _map;

	template <typename F>
	inline shoal_t(F&& init)
		: something_t{}
		, _map{ std::forward<F>(init) }
	{}
};

} // namespace strange

#endif
