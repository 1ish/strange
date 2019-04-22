#ifndef COM_ONEISH_STRANGE_SHOAL_T_H
#define COM_ONEISH_STRANGE_SHOAL_T_H

#include <unordered_map>

namespace strange
{

template <typename _ABSTRACTION_ = collection_a>
class shoal_t : public collection_t<_ABSTRACTION_>
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

	template <typename ITERATOR, typename _ABSTRACTION_ = any_a>
	class iterator_t : public something_t<_ABSTRACTION_>
	{
	public: ___THING___
		// construction
		static inline any_a val(any_a range)
		{
			return nothing_t<>::val_(); //TODO
		}

		template <typename F>
		static inline any_a val__(F&& it, F&& end)
		{
			return any_a{ iterator_t(std::forward<F>(it), std::forward<F>(end)) };
		}

		static inline any_a ref(any_a range)
		{
			return nothing_t<>::val_(); //TODO
		}

		template <typename F>
		static inline any_a ref__(F&& it, F&& end)
		{
			return any_a(iterator_t(std::forward<F>(it), std::forward<F>(end)), true);
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
			return (_it == _end) == thing->nothing__();
		}

		inline bool operator!=(any_a thing) const
		{
			return (_it == _end) != thing->nothing__();
		}

		inline std::size_t hash__() const
		{
			return operator*().hash__();
		}

		// iterator
		inline any_a& operator*() const
		{
			if (_it == _end)
			{
				return nothing_t<>::val__();
			}
			return const_cast<any_a&>(_it->second); //TODO
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
		ITERATOR _end;

		template <typename F>
		inline iterator_t(F&& it, F&& end)
			: something_t{}
			, _it{ std::forward<F>(it) }
			, _end{ std::forward<F>(end) }
		{}
	};

public: ___COLLECTION___
	// construction
	static inline collection_a val(any_a range)
	{
		return cast_<collection_a>(val_() += range);
	}

	static inline collection_a val_()
	{
		return val__(std_unordered_map_any_any{});
	}

	template <typename F>
	static inline collection_a val__(F&& init)
	{
		return collection_a{ shoal_t{ std::forward<F>(init) } };
	}

	static inline collection_a ref(any_a range)
	{
		return cast_<collection_a>(ref_() += range, true);
	}

	static inline collection_a ref_()
	{
		return ref__(std_unordered_map_any_any{});
	}

	template <typename F>
	static inline collection_a ref__(F&& init)
	{
		return collection_a(shoal_t{ std::forward<F>(init) }, true);
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
		return false; //TODO
	}

	inline bool operator!=(any_a thing) const
	{
		return true; //TODO
	}

	inline std::size_t hash__() const
	{
		return 0; //TODO
	}

	// range
	inline any_a cbegin() const
	{
		return iterator_t<std_unordered_map_any_any::const_iterator>::val__(_map.cbegin(), _map.cend());
	}

	inline any_a begin()
	{
		return iterator_t<std_unordered_map_any_any::iterator>::val__(_map.begin(), _map.end());
	}

	inline any_a cend() const
	{
		return nothing_t<>::val_();
	}

	inline any_a end()
	{
		return nothing_t<>::val_();
	}

	// collection
	inline any_a at_(any_a key) const
	{
		const std_unordered_map_any_any::const_iterator mit = _map.find(key);
		if (mit == _map.cend())
		{
			return nothing_t<>::val_();
		}
		return mit->second;
	}

	inline any_a update_(any_a key, any_a value)
	{
		if (value.nothing__())
		{
			_map.erase(key);
		}
		else
		{
			_map[key] = value;
		}
		return value;
	}

	inline bool insert__(any_a key, any_a value)
	{
		if (value.nothing__())
		{
			return false;
		}
		return _map.emplace(key, value).second;
	}

	inline bool erase__(any_a key)
	{
		return _map.erase(key);
	}

	inline void clear__()
	{
		_map.clear();
	}

	inline std::size_t size__() const
	{
		return _map.size();
	}

	inline bool empty__() const
	{
		return _map.empty();
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
		if (thing.nothing__())
		{
			_map.erase(thing);
		}
		else
		{
			_map[thing] = thing;
		}
	}

	inline any_a pop_back_()
	{
		const std_unordered_map_any_any::const_iterator mit = _map.cbegin();
		if (mit == _map.cend())
		{
			return nothing_t<>::val_();
		}
		any_a result = mit->second;
		_map.erase(mit);
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
		: collection_t{}
		, _map{ std::forward<F>(init) }
	{}
};

} // namespace strange

#endif
