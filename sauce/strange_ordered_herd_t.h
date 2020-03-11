#ifndef COM_ONEISH_STRANGE_ORDERED_HERD_T_H
#define COM_ONEISH_STRANGE_ORDERED_HERD_T_H

namespace strange
{

template <bool _concurrent_ = false, typename ___ego___ = ordered_herd_a<>>
class ordered_herd_t : public thing_t<___ego___>
{
	template <typename _iterator_, typename ___ego_it___ = bidirectional_const_iterator_data_a<_iterator_>>
	class const_iterator_t : public thing_t<___ego_it___>
	{
	public:
		// override
		using over = thing_o<const_iterator_t<_iterator_>>;

		// construction
		template <typename F>
		static inline bidirectional_const_iterator_data_a<_iterator_> create(ordered_herd_a<> const& ordered_herd, ordered_herd_t const& ordered_herd_thing, F&& it)
		{
			return bidirectional_const_iterator_data_a<_iterator_>::template create<over>(const_iterator_t<_iterator_>(ordered_herd, ordered_herd_thing, std::forward<F>(it)));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::ordered_herd::const_iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			if (!check<bidirectional_const_iterator_data_a<_iterator_>>(thing))
			{
				return false;
			}
			return _it == cast<bidirectional_const_iterator_data_a<_iterator_>>(thing).extract_it();
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_herd_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		// forward iterator
		inline any_a<> get_() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_herd_thing._mutex);
			return *_it;
		}

		inline any_a<> const* operator->() const
		{
			return &operator*();
		}

		inline any_a<> const& operator*() const
		{
			return *_it;
		}

		inline void increment_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_herd_thing._mutex);
			++_it;
		}

		// bidirectional iterator
		inline void decrement_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_ordered_herd_thing._mutex);
			--_it;
		}

		// data
		inline _iterator_ const& extract_it() const
		{
			return _it;
		}

		inline _iterator_& mutate_it()
		{
			return _it;
		}

	protected:
		_iterator_ _it;
		ordered_herd_a<> const _ordered_herd;
		ordered_herd_t const& _ordered_herd_thing;

		template <typename F>
		inline const_iterator_t(ordered_herd_a<> const& ordered_herd, ordered_herd_t const& ordered_herd_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _ordered_herd{ ordered_herd }
			, _ordered_herd_thing{ ordered_herd_thing }
		{}
	};

public:
	using std_set_any = std::set<any_a<>>;

	// override
	using over = collection_o<ordered_herd_t<_concurrent_>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return create_() += range;
	}

	static inline ordered_herd_a<> create_()
	{
		return create(std_set_any{});
	}

	template <typename... Args>
	static inline ordered_herd_a<> create_(Args&&... args)
	{
		return create(variadic_u<>::set(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline ordered_herd_a<> create_refs_(Args&&... args)
	{
		return create(variadic_u<>::set_ref(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline ordered_herd_a<> create_dups_(Args&&... args)
	{
		return create(variadic_u<>::set_dup(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline ordered_herd_a<> create(F&& init)
	{
		return ordered_herd_a<>::create<over>(ordered_herd_t<_concurrent_>{ std::forward<F>(init) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::ordered_herd" + std::string{ _concurrent_ ? "_concurrent" : "" });
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type_().to_string() + "::create", native_function_create(&ordered_herd_t<_concurrent_>::create__));
	}

	// visitor pattern
	inline any_a<> visit_(inventory_a<>& inventory) const
	{
		auto result = thing_t<>::visit_(inventory);
		if (result)
		{
			auto last = inventory.size() - 1;
			typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
			for (auto const& visited : _set)
			{
				inventory.update_index(last, visited);
				visited.visit_(inventory);
			}
		}
		return result;
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		if (!check<ordered_herd_a<>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _set == cast<ordered_herd_a<>>(thing).extract_set();
	}

	inline std::size_t hash() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std::size_t seed = std::hash<std::size_t>{}(_set.size());
		for (auto const& item : _set)
		{
			seed ^= item.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline bidirectional_const_iterator_a<> cbegin_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return const_iterator_t<typename std_set_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _set.cbegin());
	}

	inline bidirectional_const_iterator_a<> cend_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return const_iterator_t<typename std_set_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _set.cend());
	}

	// collection / herd
	inline bool has(any_a<> const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_set_any::const_iterator const it = _set.find(key);
		return it != _set.cend();
	}

	inline bool has_string(std::string const& s) const
	{
		return has(sym(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_set_any::const_iterator const it = _set.find(key);
		if (it == _set.cend())
		{
			return mis("strange::ordered_herd::at key not found");
		}
		return *it;
	}

	inline any_a<> at_string(std::string const& s) const
	{
		return at_(sym(s));
	}

	inline void update(any_a<> const& key, any_a<> const&)
	{
		update_thing(key);
	}

	inline void update_thing(any_a<> const& key)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.erase(key);
		_set.insert(key);
	}

	inline void update_string(std::string const& s)
	{
		update_thing(sym(s));
	}

	inline bool insert(any_a<> const& key, any_a<> const&)
	{
		return insert_thing(key);
	}

	inline bool insert_thing(any_a<> const& key)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _set.insert(key).second;
	}

	inline bool insert_string(std::string const& s)
	{
		return insert_thing(sym(s));
	}

	inline bool erase(any_a<> const& key)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _set.erase(key);
	}

	inline bool erase_string(std::string const& s)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _set.erase(sym(s));
	}

	inline void clear()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.clear();
	}

	inline int64_t size() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return int64_t(_set.size());
	}

	inline bool empty() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _set.empty();
	}

	inline void push_front(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.insert(thing);
	}

	inline any_a<> pop_front_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		std_set_any::const_iterator const it = _set.cbegin();
		if (it == _set.cend())
		{
			return no();
		}
		any_a<> result = *it;
		_set.erase(it);
		return result;
	}

	inline void push_back(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.insert(thing);
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		std_set_any::const_iterator it = _set.cend();
		if (it == _set.cbegin())
		{
			return no();
		}
		any_a<> result = *--it;
		_set.erase(it);
		return result;
	}

	inline void self_assign_(range_a<> const& range)
	{
		if (check<ordered_herd_a<>>(range))
		{
			auto const other = fast<ordered_herd_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set = other.extract_set();
		}
		else if (check<unordered_herd_a<>>(range))
		{
			auto const other = fast<unordered_herd_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_set = other.extract_set();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set.clear();
			_set.insert(other_set.cbegin(), other_set.cend());
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set.clear();
			for (auto const& thing : range)
			{
				_set.insert(thing);
			}
		}
	}

	inline void self_add_(range_a<> const& range)
	{
		if (check<ordered_herd_a<>>(range))
		{
			auto const other = fast<ordered_herd_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_set = other.extract_set();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set.insert(other_set.cbegin(), other_set.cend());
		}
		else if (check<unordered_herd_a<>>(range))
		{
			auto const other = fast<unordered_herd_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_set = other.extract_set();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set.insert(other_set.cbegin(), other_set.cend());
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				_set.insert(thing);
			}
		}
	}

	inline void self_subtract_(range_a<> const& range)
	{
		auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
		typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
		for (auto const& thing : range)
		{
			_set.erase(thing);
		}
	}

	inline any_a<> read_lock_() const
	{
		return data_t<read_lock_ptr<_concurrent_>>::create(make_read_lock_ptr<_concurrent_>(_mutex));
	}

	inline any_a<> write_lock_() const
	{
		return data_t<write_lock_ptr<_concurrent_>>::create(make_write_lock_ptr<_concurrent_>(_mutex));
	}

	// data
	inline std_set_any const& extract_set() const
	{
		return _set;
	}

	inline std_set_any& mutate_set()
	{
		return _set;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_set_any _set;

	template <typename F>
	inline ordered_herd_t(F&& init)
		: thing_t<___ego___>{}
		, _mutex{}
		, _set{ std::forward<F>(init) }
	{}

public:
	inline ordered_herd_t(ordered_herd_t const& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _set{ other._set }
	{}

	inline ordered_herd_t(ordered_herd_t&& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _set{ std::move(other._set) }
	{}

private:
	static bool const ___share___;
	friend class ___ordered_herd_t_share___;
};

template <bool _concurrent_, typename ___ego___>
bool const ordered_herd_t<_concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	ordered_herd_t<_concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

class ___ordered_herd_t_share___
{
	static inline bool ___share___()
	{
		return ordered_herd_t<>::___share___
			&& ordered_herd_t<true>::___share___;
	}
};

// template <bool _concurrent_ = false>
template <bool _concurrent_>
inline ordered_herd_a<> ordered_herd_create()
{
	return ordered_herd_t<_concurrent_>::create_();
}

template <typename... Args>
inline ordered_herd_a<> ordered_herd_vals(Args&&... args)
{
	return ordered_herd_t<>::create_(std::forward<Args>(args)...);
}

template <typename... Args>
inline ordered_herd_a<> ordered_herd_refs(Args&&... args)
{
	return ordered_herd_t<>::create_refs_(std::forward<Args>(args)...);
}

template <typename... Args>
inline ordered_herd_a<> ordered_herd_dups(Args&&... args)
{
	return ordered_herd_t<>::create_dups_(std::forward<Args>(args)...);
}

} // namespace strange

#endif
