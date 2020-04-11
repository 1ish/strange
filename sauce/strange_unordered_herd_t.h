#ifndef COM_ONEISH_STRANGE_UNORDERED_HERD_T_H
#define COM_ONEISH_STRANGE_UNORDERED_HERD_T_H

namespace strange
{

template <typename _element = any_a<>, bool _concurrent_ = false, typename ___ego___ = unordered_herd_a<_element>>
class unordered_herd_t : public thing_t<___ego___>
{
	template <typename _element_it, typename _iterator_, typename ___ego_it___ = forward_extractor_data_a<_element_it, _iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline forward_extractor_data_a<_element_it, _iterator_> create(unordered_herd_a<_element_it> const& unordered_herd, F&& it)
		{
			return forward_extractor_data_a<_element_it, _iterator_>::template create<extractor_t<_element_it, _iterator_>>(unordered_herd, std::forward<F>(it));
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
			return check<forward_extractor_data_a<_element_it, _iterator_>>(thing) &&
				_it == fast<forward_extractor_data_a<_element_it, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(forward_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(forward_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std::size_t hash() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		// forward extractor
		inline _element_it get_() const
		{
			return *_it;
		}

		inline _element_it const* operator->() const
		{
			return &operator*();
		}

		inline _element_it const& operator*() const
		{
			return *_it;
		}

		inline void increment_()
		{
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

		friend class any_a<>;

		template <typename F>
		inline extractor_t(unordered_herd_a<> const& unordered_herd, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _unordered_herd{ unordered_herd }
		{}
	};

public:
	using std_unordered_set_element = std::unordered_set<_element>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		auto result = create_();
		if (check<range_a<_element>>(range))
		{
			result += fast<range_a<_element>>(range);
		}
		else
		{
			for (auto const& thing : range)
			{
				result.push_back(cast<_element>(thing));
			}
		}
		return result;
	}

	static inline unordered_herd_a<_element> create_()
	{
		return create(std_unordered_set_element{});
	}

	template <typename... Args>
	static inline unordered_herd_a<_element> create_(Args&&... args)
	{
		return create(variadic_u<_element>::unordered_set(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline unordered_herd_a<_element> create_refs_(Args&&... args)
	{
		return create(variadic_u<_element>::unordered_set_ref(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline unordered_herd_a<_element> create_dups_(Args&&... args)
	{
		return create(variadic_u<_element>::unordered_set_dup(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline unordered_herd_a<_element> create(F&& init)
	{
		return unordered_herd_a<_element>::template create<unordered_herd_t<_element, _concurrent_>>(std::forward<F>(init));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::unordered_herd" + 
			std::string{ _concurrent_ ? "_concurrent" : "" } +
			kind_of<_element>().to_string());
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type_().to_string() + "::create", native_function_create(&unordered_herd_t<_element, _concurrent_>::create__));
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
		if (!check<unordered_herd_a<_element>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _set == fast<unordered_herd_a<_element>>(thing).extract_set();
	}

	inline bool operator==(unordered_herd_a<_element> const& herd) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _set == herd.extract_set();
	}

	inline bool operator!=(unordered_herd_a<_element> const& herd) const
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
	inline forward_extractor_a<_element> extract_begin_() const
	{
		return extractor_t<_element, typename std_unordered_set_element::const_iterator>::create(thing_t<___ego___>::me_(), _set.cbegin());
	}

	inline forward_extractor_data_a<_element, typename std_unordered_set_element::const_iterator> extract_begin() const
	{
		return extractor_t<_element, typename std_unordered_set_element::const_iterator>::create(thing_t<___ego___>::me_(), _set.cbegin());
	}

	inline forward_extractor_a<_element> extract_end_() const
	{
		return extractor_t<_element, typename std_unordered_set_element::const_iterator>::create(thing_t<___ego___>::me_(), _set.cend());
	}

	inline forward_extractor_data_a<_element, typename std_unordered_set_element::const_iterator> extract_end() const
	{
		return extractor_t<_element, typename std_unordered_set_element::const_iterator>::create(thing_t<___ego___>::me_(), _set.cend());
	}

	// collection
	inline any_a<> has_(_element const& key) const
	{
		return boole(has(key));
	}

	inline bool has(_element const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		typename std_unordered_set_element::const_iterator const it = _set.find(key);
		return it != _set.cend();
	}

	inline bool has_string(std::string const& s) const
	{
		return has(sym(s));
	}

	inline any_a<> at_(_element const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		typename std_unordered_set_element::const_iterator const it = _set.find(key);
		if (it == _set.cend())
		{
			return mis("strange::unordered_herd::at key not found");
		}
		return *it;
	}

	inline _element at_string(std::string const& s) const
	{
		return at_(sym(s));
	}

	inline _element update_(_element const& key, _element const&)
	{
		update_thing(key);
		return key;
	}

	inline void update(_element const& key, _element const&)
	{
		update_thing(key);
	}

	inline _element update_thing_(_element const& thing)
	{
		update_thing(thing);
		return thing;
	}

	inline void update_thing(_element const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.erase(thing);
		_set.insert(thing);
	}

	inline void update_string(std::string const& s)
	{
		update_thing(sym(s));
	}

	inline any_a<> insert_(_element const& key, _element const&)
	{
		return boole(insert_thing(key));
	}

	inline bool insert(_element const& key, _element const&)
	{
		return insert_thing(key);
	}

	inline any_a<> insert_thing_(_element const& thing)
	{
		return boole(insert_thing(thing));
	}

	inline bool insert_thing(_element const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _set.insert(thing).second;
	}

	inline bool insert_string(std::string const& s)
	{
		return insert_thing(sym(s));
	}

	inline any_a<> erase_(_element const& key)
	{
		return boole(erase(key));
	}

	inline bool erase(_element const& key)
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

	inline ___ego___ push_front_(_element const& value)
	{
		push_front(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_front(_element const& thing)
	{
		push_back(thing);
	}

	inline _element pop_front_()
	{
		return pop_back_();
	}

	inline ___ego___ push_back_(_element const& value)
	{
		push_back(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_back(_element const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.insert(thing);
	}

	inline _element pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		typename std_unordered_set_element::const_iterator const it = _set.cbegin();
		if (it == _set.cend())
		{
			throw dis("strange::unordered_herd::pop_back called on empty flock");
		}
		_element result = *it;
		_set.erase(it);
		return result;
	}

	inline void self_assign_(range_a<_element> const& range)
	{
		if (check<unordered_herd_a<_element>>(range))
		{
			auto const other = fast<unordered_herd_a<_element>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set = other.extract_set();
		}
		else if (check<ordered_herd_a<_element>>(range))
		{
			auto const other = fast<ordered_herd_a<_element>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_set = other.extract_set();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set.clear();
			_set.insert(other_set.cbegin(), other_set.cend());
		}
		else
		{
			auto read_lock = check<collection_a<_element>>(range) ? fast<collection_a<_element>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set.clear();
			for (auto const& thing : range)
			{
				_set.insert(thing);
			}
		}
	}

	inline void self_add_(range_a<_element> const& range)
	{
		if (check<unordered_herd_a<_element>>(range))
		{
			auto const other = fast<unordered_herd_a<_element>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_set = other.extract_set();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set.insert(other_set.cbegin(), other_set.cend());
		}
		else if (check<ordered_herd_a<_element>>(range))
		{
			auto const other = fast<ordered_herd_a<_element>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_set = other.extract_set();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_set.insert(other_set.cbegin(), other_set.cend());
		}
		else
		{
			auto read_lock = check<collection_a<_element>>(range) ? fast<collection_a<_element>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				_set.insert(thing);
			}
		}
	}

	inline ___ego___ add_(range_a<_element> const& range) const
	{
		auto result = thing_t<___ego___>::me_();
		result += range;
		return result;
	}

	inline void self_subtract_(range_a<_element> const& range)
	{
		auto read_lock = check<collection_a<_element>>(range) ? fast<collection_a<_element>>(range).read_lock_() : no();
		typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
		for (auto const& thing : range)
		{
			_set.erase(thing);
		}
	}

	inline ___ego___ subtract_(range_a<_element> const& range) const
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
	inline std_unordered_set_element const& extract_set() const
	{
		return _set;
	}

	inline std_unordered_set_element& mutate_set()
	{
		return _set;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_unordered_set_element _set;

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

template <typename _element, bool _concurrent_, typename ___ego___>
bool const unordered_herd_t<_element, _concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	unordered_herd_t<_element, _concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

class ___unordered_herd_t_share___
{
	static inline bool ___share___()
	{
		return unordered_herd_t<>::___share___
			&& unordered_herd_t<any_a<>, true>::___share___;
	}
};

// template <typename _element = any_a<>, bool _concurrent_ = false>
template <typename _element, bool _concurrent_>
inline unordered_herd_a<_element> unordered_herd_create()
{
	return unordered_herd_t<_element, _concurrent_>::create_();
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
