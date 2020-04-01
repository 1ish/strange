#ifndef COM_ONEISH_STRANGE_UNORDERED_HERD_T_H
#define COM_ONEISH_STRANGE_UNORDERED_HERD_T_H

namespace strange
{

template <bool _concurrent_ = false, typename ___ego___ = unordered_herd_a<>>
class unordered_herd_t : public thing_t<___ego___>
{
	template <typename _element, typename _iterator_, typename ___ego_it___ = forward_extractor_data_a<_element, _iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline forward_extractor_data_a<_element, _iterator_> create(unordered_herd_a<> const& unordered_herd, unordered_herd_t const& unordered_herd_thing, F&& it)
		{
			return forward_extractor_data_a<_element, _iterator_>::template create<extractor_t<_element, _iterator_>>(unordered_herd, unordered_herd_thing, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::unordered_herd::extractor");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<forward_extractor_data_a<_element, _iterator_>>(thing) &&
				_it == fast<forward_extractor_data_a<_element, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(forward_extractor_data_a<_element, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(forward_extractor_data_a<_element, _iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_herd_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		// forward extractor
		inline _element get_() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_herd_thing._mutex);
			return *_it;
		}

		inline _element const* operator->() const
		{
			return &operator*();
		}

		inline _element const& operator*() const
		{
			return *_it;
		}

		inline void increment_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_unordered_herd_thing._mutex);
			++_it;
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
		unordered_herd_a<> const _unordered_herd;
		unordered_herd_t const& _unordered_herd_thing;

		friend class any_a<>;

		template <typename F>
		inline extractor_t(unordered_herd_a<> const& unordered_herd, unordered_herd_t const& unordered_herd_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _unordered_herd{ unordered_herd }
			, _unordered_herd_thing{ unordered_herd_thing }
		{}
	};

public:
	using std_unordered_set_any = std::unordered_set<any_a<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return create_() += range;
	}

	static inline unordered_herd_a<> create_()
	{
		return create(std_unordered_set_any{});
	}

	template <typename... Args>
	static inline unordered_herd_a<> create_(Args&&... args)
	{
		return create(variadic_u<any_a<>>::unordered_set(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline unordered_herd_a<> create_refs_(Args&&... args)
	{
		return create(variadic_u<any_a<>>::unordered_set_ref(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline unordered_herd_a<> create_dups_(Args&&... args)
	{
		return create(variadic_u<any_a<>>::unordered_set_dup(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline unordered_herd_a<> create(F&& init)
	{
		return unordered_herd_a<>::create<unordered_herd_t<_concurrent_>>(std::forward<F>(init));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::unordered_herd" + std::string{ _concurrent_ ? "_concurrent" : "" });
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type_().to_string() + "::create", native_function_create(&unordered_herd_t<_concurrent_>::create__));
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
		if (!check<unordered_herd_a<>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _set == fast<unordered_herd_a<>>(thing).extract_set();
	}

	inline bool operator==(unordered_herd_a<> const& herd) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _set == herd.extract_set();
	}

	inline bool operator!=(unordered_herd_a<> const& herd) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _set != herd.extract_set();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std::size_t hash() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std::set<any_a<>> const ordered(_set.cbegin(), _set.cend());
		std::size_t seed = std::hash<std::size_t>{}(_set.size());
		for (auto const& item : ordered)
		{
			seed ^= item.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline forward_extractor_a<any_a<>> extract_begin_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_unordered_set_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _set.cbegin());
	}

	inline forward_extractor_data_a<any_a<>, typename std_unordered_set_any::const_iterator> extract_begin() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_unordered_set_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _set.cbegin());
	}

	inline forward_extractor_a<any_a<>> extract_end_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_unordered_set_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _set.cend());
	}

	inline forward_extractor_data_a<any_a<>, typename std_unordered_set_any::const_iterator> extract_end() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_unordered_set_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _set.cend());
	}

	// collection
	inline any_a<> has_(any_a<> const& key) const
	{
		return boole(has(key));
	}

	inline bool has(any_a<> const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_unordered_set_any::const_iterator const it = _set.find(key);
		return it != _set.cend();
	}

	inline bool has_string(std::string const& s) const
	{
		return has(sym(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_unordered_set_any::const_iterator const it = _set.find(key);
		if (it == _set.cend())
		{
			return mis("strange::unordered_herd::at key not found");
		}
		return *it;
	}

	inline any_a<> at_string(std::string const& s) const
	{
		return at_(sym(s));
	}

	inline any_a<> update_(any_a<> const& key, any_a<> const&)
	{
		update_thing(key);
		return key;
	}

	inline void update(any_a<> const& key, any_a<> const&)
	{
		update_thing(key);
	}

	inline any_a<> update_thing_(any_a<> const& thing)
	{
		update_thing(thing);
		return thing;
	}

	inline void update_thing(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.erase(thing);
		_set.insert(thing);
	}

	inline void update_string(std::string const& s)
	{
		update_thing(sym(s));
	}

	inline any_a<> insert_(any_a<> const& key, any_a<> const&)
	{
		return boole(insert_thing(key));
	}

	inline bool insert(any_a<> const& key, any_a<> const&)
	{
		return insert_thing(key);
	}

	inline any_a<> insert_thing_(any_a<> const& thing)
	{
		return boole(insert_thing(thing));
	}

	inline bool insert_thing(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _set.insert(thing).second;
	}

	inline bool insert_string(std::string const& s)
	{
		return insert_thing(sym(s));
	}

	inline any_a<> erase_(any_a<> const& key)
	{
		return boole(erase(key));
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

	inline ___ego___ clear_()
	{
		clear();
		return thing_t<___ego___>::me_();
	}

	inline void clear()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.clear();
	}

	inline number_data_a<int64_t> size_() const
	{
		return num(size());
	}

	inline int64_t size() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return int64_t(_set.size());
	}

	inline any_a<> empty_() const
	{
		return boole(empty());
	}

	inline bool empty() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _set.empty();
	}

	inline ___ego___ push_front_(any_a<> const& value)
	{
		push_front(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_front(any_a<> const& thing)
	{
		push_back(thing);
	}

	inline any_a<> pop_front_()
	{
		return pop_back_();
	}

	inline ___ego___ push_back_(any_a<> const& value)
	{
		push_back(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_back(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.insert(thing);
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		std_unordered_set_any::const_iterator const it = _set.cbegin();
		if (it == _set.cend())
		{
			return no();
		}
		any_a<> result = *it;
		_set.erase(it);
		return result;
	}

	inline void self_assign_(range_a<> const& range)
	{
		if (check<unordered_herd_a<>>(range))
		{
			auto const other = fast<unordered_herd_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set = other.extract_set();
		}
		else if (check<ordered_herd_a<>>(range))
		{
			auto const other = fast<ordered_herd_a<>>(range);
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
		if (check<unordered_herd_a<>>(range))
		{
			auto const other = fast<unordered_herd_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_set = other.extract_set();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set.insert(other_set.cbegin(), other_set.cend());
		}
		else if (check<ordered_herd_a<>>(range))
		{
			auto const other = fast<ordered_herd_a<>>(range);
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

	inline ___ego___ add_(range_a<> const& range) const
	{
		auto result = thing_t<___ego___>::me_();
		result += range;
		return result;
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

	inline ___ego___ subtract_(range_a<> const& range) const
	{
		auto result = thing_t<___ego___>::me_();
		result -= range;
		return result;
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
	inline std_unordered_set_any const& extract_set() const
	{
		return _set;
	}

	inline std_unordered_set_any& mutate_set()
	{
		return _set;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_unordered_set_any _set;

	friend class any_a<>;

	template <typename F>
	inline unordered_herd_t(F&& init)
		: thing_t<___ego___>{}
		, _mutex{}
		, _set{ std::forward<F>(init) }
	{}

public:
	inline unordered_herd_t(unordered_herd_t const& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _set{ other._set }
	{}

	inline unordered_herd_t(unordered_herd_t&& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _set{ std::move(other._set) }
	{}

private:
	static bool const ___share___;
	friend class ___unordered_herd_t_share___;
};

template <bool _concurrent_, typename ___ego___>
bool const unordered_herd_t<_concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	unordered_herd_t<_concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

class ___unordered_herd_t_share___
{
	static inline bool ___share___()
	{
		return unordered_herd_t<>::___share___
			&& unordered_herd_t<true>::___share___;
	}
};

// template <bool _concurrent_ = false>
template <bool _concurrent_>
inline unordered_herd_a<> unordered_herd_create()
{
	return unordered_herd_t<_concurrent_>::create_();
}

template <typename... Args>
inline unordered_herd_a<> unordered_herd_vals(Args&&... args)
{
	return unordered_herd_t<>::create_(std::forward<Args>(args)...);
}

template <typename... Args>
inline unordered_herd_a<> unordered_herd_refs(Args&&... args)
{
	return unordered_herd_t<>::create_refs_(std::forward<Args>(args)...);
}

template <typename... Args>
inline unordered_herd_a<> unordered_herd_dups(Args&&... args)
{
	return unordered_herd_t<>::create_dups_(std::forward<Args>(args)...);
}

} // namespace strange

#endif
