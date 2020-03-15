#ifndef COM_ONEISH_STRANGE_FLOCK_T_H
#define COM_ONEISH_STRANGE_FLOCK_T_H

namespace strange
{

// template <bool _concurrent_ = false, typename ___ego___ = flock_a<>>
template <bool _concurrent_, typename ___ego___>
class flock_t : public thing_t<___ego___>
{
	template <typename _iterator_, typename ___ego_it___ = random_access_mutator_data_a<_iterator_>>
	class mutator_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline random_access_mutator_data_a<_iterator_> create(flock_t const& flock_thing, F&& it)
		{
			return random_access_mutator_data_a<_iterator_>::template create<mutator_t<_iterator_>>(flock_thing, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::flock::mutator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_iterator_>>(thing) &&
				_it == fast<random_access_mutator_data_a<_iterator_>>(thing).extract_it();
		}

		inline bool operator==(random_access_mutator_data_a<_iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(random_access_mutator_data_a<_iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		inline bool less_than_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_iterator_>>(thing)
				? _it < fast<random_access_mutator_data_a<_iterator_>>(thing).extract_it()
				: one_t::less_than_(thing);
		}

		inline bool operator<(random_access_mutator_data_a<_iterator_> const& it) const
		{
			return _it < it.extract_it();
		}

		inline bool greater_than_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_iterator_>>(thing)
				? _it > fast<random_access_mutator_data_a<_iterator_>>(thing).extract_it()
				: one_t::greater_than_(thing);
		}

		inline bool operator>(random_access_mutator_data_a<_iterator_> const& it) const
		{
			return _it > it.extract_it();
		}

		inline bool less_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_iterator_>>(thing)
				? _it <= fast<random_access_mutator_data_a<_iterator_>>(thing).extract_it()
				: one_t::less_or_equal_(thing);
		}

		inline bool operator<=(random_access_mutator_data_a<_iterator_> const& it) const
		{
			return _it <= it.extract_it();
		}

		inline bool greater_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_iterator_>>(thing)
				? _it >= fast<random_access_mutator_data_a<_iterator_>>(thing).extract_it()
				: one_t::greater_or_equal_(thing);
		}

		inline bool operator>=(random_access_mutator_data_a<_iterator_> const& it) const
		{
			return _it >= it.extract_it();
		}

		// forward mutator
		inline any_a<> get_() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			return *_it;
		}

		inline any_a<> set_(any_a<> const& thing) const
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_flock_thing._mutex);
			return *_it = thing;
		}

		inline any_a<>* operator->() const
		{
			return &operator*();
		}

		inline any_a<>& operator*() const
		{
			return *_it;
		}

		inline void increment_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			++_it;
		}

		// bidirectional mutator
		inline void decrement_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			--_it;
		}

		// random access mutator
		inline void self_add_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			_it += number.to_int_64();
		}

		inline random_access_mutator_a<> add_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			result.mutate_it() += number.to_int_64();
			return result;
		}

		inline void self_subtract_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			_it -= number.to_int_64();
		}

		inline random_access_mutator_a<> subtract_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			result.mutate_it() -= number.to_int_64();
			return result;
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
		flock_t const& _flock_thing;

		friend class any_a<>;

		template <typename F>
		inline mutator_t(flock_t const& flock_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _flock_thing{ flock_thing }
		{}
	};

	template <typename _iterator_, typename ___ego_it___ = random_access_extractor_data_a<_iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline random_access_extractor_data_a<_iterator_> create(flock_a<> const& flock, flock_t const& flock_thing, F&& it)
		{
			return random_access_extractor_data_a<_iterator_>::template create<extractor_t<_iterator_>>(flock, flock_thing, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::flock::extractor");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_iterator_>>(thing) &&
				_it == fast<random_access_extractor_data_a<_iterator_>>(thing).extract_it();
		}

		inline bool operator==(random_access_extractor_data_a<_iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(random_access_extractor_data_a<_iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		inline bool less_than_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_iterator_>>(thing)
				? _it < fast<random_access_extractor_data_a<_iterator_>>(thing).extract_it()
				: one_t::less_than_(thing);
		}

		inline bool operator<(random_access_extractor_data_a<_iterator_> const& it) const
		{
			return _it < it.extract_it();
		}

		inline bool greater_than_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_iterator_>>(thing)
				? _it > fast<random_access_extractor_data_a<_iterator_>>(thing).extract_it()
				: one_t::greater_than_(thing);
		}

		inline bool operator>(random_access_extractor_data_a<_iterator_> const& it) const
		{
			return _it > it.extract_it();
		}

		inline bool less_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_iterator_>>(thing)
				? _it <= fast<random_access_extractor_data_a<_iterator_>>(thing).extract_it()
				: one_t::less_or_equal_(thing);
		}

		inline bool operator<=(random_access_extractor_data_a<_iterator_> const& it) const
		{
			return _it <= it.extract_it();
		}

		inline bool greater_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_iterator_>>(thing)
				? _it >= fast<random_access_extractor_data_a<_iterator_>>(thing).extract_it()
				: one_t::greater_or_equal_(thing);
		}

		inline bool operator>=(random_access_extractor_data_a<_iterator_> const& it) const
		{
			return _it >= it.extract_it();
		}

		// forward extractor
		inline any_a<> get_() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
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
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			++_it;
		}

		// bidirectional mutator
		inline void decrement_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			--_it;
		}

		// random access mutator
		inline void self_add_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			_it += number.to_int_64();
		}

		inline random_access_extractor_a<> add_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			result.mutate_it() += number.to_int_64();
			return result;
		}

		inline void self_subtract_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			_it -= number.to_int_64();
		}

		inline random_access_extractor_a<> subtract_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_flock_thing._mutex);
			result.mutate_it() -= number.to_int_64();
			return result;
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
		flock_a<> const _flock;
		flock_t const& _flock_thing;

		friend class any_a<>;

		template <typename F>
		inline extractor_t(flock_a<> const& flock, flock_t const& flock_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _flock{ flock }
			, _flock_thing{ flock_thing }
		{}
	};

public:
	using std_vector_any = std::vector<any_a<>>;

	// override
	using over = collection_o<flock_t<_concurrent_>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return create_() += range;
	}

	static inline flock_a<> create_()
	{
		return create(std_vector_any{});
	}

	template <typename... Args>
	static inline flock_a<> create_(Args&&... args)
	{
		return create(variadic_u<>::vector(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline flock_a<> create_refs_(Args&&... args)
	{
		return create(variadic_u<>::vector_ref(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline flock_a<> create_dups_(Args&&... args)
	{
		return create(variadic_u<>::vector_dup(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline flock_a<> create(F&& init)
	{
		return flock_a<>::create<over>(flock_t<_concurrent_>{ std::forward<F>(init) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::flock" + std::string{ _concurrent_ ? "_concurrent" : "" });
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type_().to_string() + "::create", native_function_create(&flock_t<_concurrent_>::create__));
	}

	// visitor pattern
	inline any_a<> visit_(inventory_a<>& inventory) const
	{
		auto result = thing_t<>::visit_(inventory);
		if (result)
		{
			auto last = inventory.size() - 1;
			typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
			for (auto const& visited : _vector)
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
		if (!check<flock_a<>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector == fast<flock_a<>>(thing).extract_vector();
	}

	inline bool operator==(flock_a<> const& flock) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector == flock.extract_vector();
	}

	inline bool operator!=(flock_a<> const& flock) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector != flock.extract_vector();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std::size_t hash() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std::size_t seed = std::hash<std::size_t>{}(_vector.size());
		for (auto const& item : _vector)
		{
			seed ^= item.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	inline bool less_than_(any_a<> const& thing) const
	{
		if (!check<flock_a<>>(thing))
		{
			return one_t::less_than_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector < fast<flock_a<>>(thing).extract_vector();
	}

	inline bool operator<(flock_a<> const& flock) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector < flock.extract_vector();
	}

	inline bool greater_than_(any_a<> const& thing) const
	{
		if (!check<flock_a<>>(thing))
		{
			return one_t::greater_than_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector > fast<flock_a<>>(thing).extract_vector();
	}

	inline bool operator>(flock_a<> const& flock) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector > flock.extract_vector();
	}

	inline bool less_or_equal_(any_a<> const& thing) const
	{
		if (!check<flock_a<>>(thing))
		{
			return one_t::less_or_equal_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector <= fast<flock_a<>>(thing).extract_vector();
	}

	inline bool operator<=(flock_a<> const& flock) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector <= flock.extract_vector();
	}

	inline bool greater_or_equal_(any_a<> const& thing) const
	{
		if (!check<flock_a<>>(thing))
		{
			return one_t::greater_or_equal_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector >= fast<flock_a<>>(thing).extract_vector();
	}

	inline bool operator>=(flock_a<> const& flock) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector >= flock.extract_vector();
	}

	// range
	inline random_access_extractor_a<> extract_begin_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<typename std_vector_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _vector.cbegin());
	}

	inline random_access_extractor_data_a<typename std_vector_any::const_iterator> extract_begin() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<typename std_vector_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _vector.cbegin());
	}

	inline random_access_extractor_a<> extract_end_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<typename std_vector_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _vector.cend());
	}

	inline random_access_extractor_data_a<typename std_vector_any::const_iterator> extract_end() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<typename std_vector_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _vector.cend());
	}

	inline random_access_mutator_a<> mutate_begin_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<typename std_vector_any::iterator>::create(*this, _vector.begin());
	}

	inline random_access_mutator_data_a<typename std_vector_any::iterator> mutate_begin()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<typename std_vector_any::iterator>::create(*this, _vector.begin());
	}

	inline random_access_mutator_a<> mutate_end_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<typename std_vector_any::iterator>::create(*this, _vector.end());
	}

	inline random_access_mutator_data_a<typename std_vector_any::iterator> mutate_end()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<typename std_vector_any::iterator>::create(*this, _vector.end());
	}

	// collection
	inline bool has(any_a<> const& key) const
	{
		return check<number_a<>>(key) && has_index(fast<number_a<>>(key).to_int_64());
	}

	inline bool has_index(int64_t index) const
	{
		return index >= 0 && index < size();
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		if (check<number_a<>>(key))
		{
			return at_index(fast<number_a<>>(key).to_int_64());
		}
		return mis("strange::flock::at index is not a number");
	}

	inline any_a<> at_index(int64_t index) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		if (index >= 0 && index < int64_t(_vector.size()))
		{
			return _vector[std::size_t(index)];
		}
		return mis("strange::flock::at index out of bounds");
	}

	inline void update(any_a<> const& key, any_a<> const& value)
	{
		if (check<number_a<>>(key))
		{
			update_index(fast<number_a<>>(key).to_int_64(), value);
		}
	}

	inline void update_index(int64_t index, any_a<> const& value)
	{
		if (index >= 0)
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			int64_t const siz = int64_t(_vector.size());
			if (index == siz)
			{
				_vector.push_back(value);
			}
			else
			{
				if (index > siz)
				{
					_vector.resize(std::size_t(index) + 1, no());
				}
				_vector[std::size_t(index)] = value;
			}
		}
	}

	inline bool insert(any_a<> const& key, any_a<> const& value)
	{
		return check<number_a<>>(key) && insert_index(fast<number_a<>>(key).to_int_64(), value);
	}

	inline bool insert_index(int64_t index, any_a<> const& value)
	{
		if (index >= 0)
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			int64_t const siz = int64_t(_vector.size());
			if (index == siz)
			{
				_vector.push_back(value);
			}
			else
			{
				if (index > siz)
				{
					_vector.resize(std::size_t(index) + 1, no());
					_vector[std::size_t(index)] = value;
				}
				else
				{
					_vector.insert(_vector.cbegin() + index, value);
				}
			}
			return true;
		}
		return false;
	}

	inline bool erase(any_a<> const& key)
	{
		return check<number_a<>>(key) && erase_index(fast<number_a<>>(key).to_int_64());
	}

	inline bool erase_index(int64_t index)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (index >= 0 && index < int64_t(_vector.size()))
		{
			_vector.erase(_vector.cbegin() + index);
			return true;
		}
		return false;
	}

	inline void clear()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_vector.clear();
	}

	inline int64_t size() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return int64_t(_vector.size());
	}

	inline bool empty() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector.empty();
	}

	inline void push_front(any_a<> const& thing)
	{
		push_back(thing);
	}

	inline any_a<> pop_front_()
	{
		return pop_back_();
	}

	inline void push_back(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_vector.push_back(thing);
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (_vector.empty())
		{
			return no();
		}
		any_a<> result = _vector.back();
		_vector.pop_back();
		return result;
	}

	inline void self_assign_(range_a<> const& range)
	{
		if (check<flock_a<>>(range))
		{
			auto const other = fast<flock_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_vector = other.extract_vector();
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_vector.clear();
			for (auto const& thing : range)
			{
				_vector.push_back(thing);
			}
		}
	}
	
	inline void self_add_(range_a<> const& range)
	{
		if (check<flock_a<>>(range))
		{
			auto const other = fast<flock_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_vector = other.extract_vector();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_vector.insert(_vector.cend(), other_vector.cbegin(), other_vector.cend());
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				_vector.push_back(thing);
			}
		}
	}

	inline void self_subtract_(range_a<> const& range)
	{
		if (check<collection_a<>>(range))
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			_vector.resize(std::size_t(std::max<int64_t>(0, int64_t(_vector.size()) - fast<collection_a<>>(range).size())));
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				if (_vector.empty())
				{
					break;
				}
				_vector.pop_back();
			}
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
	inline std_vector_any const& extract_vector() const
	{
		return _vector;
	}

	inline std_vector_any& mutate_vector()
	{
		return _vector;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_vector_any _vector;

	template <typename F>
	inline flock_t(F&& init)
		: thing_t<___ego___>{}
		, _mutex{}
		, _vector{ std::forward<F>(init) }
	{}

public:
	inline flock_t(flock_t const& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _vector{ other._vector }
	{}

	inline flock_t(flock_t&& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _vector{ std::move(other._vector) }
	{}

private:
	static bool const ___share___;
	friend class ___flock_t_share___;
};

template <bool _concurrent_, typename ___ego___>
bool const flock_t<_concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	flock_t<_concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

class ___flock_t_share___
{
	static inline bool ___share___()
	{
		return flock_t<>::___share___
			&& flock_t<true>::___share___;
	}
};

// template <bool _concurrent_ = false>
template <bool _concurrent_>
inline flock_a<> flock_create()
{
	return flock_t<_concurrent_>::create_();
}

template <typename F>
inline flock_a<> flock_create(F&& init)
{
	return flock_t<>::create(std::forward<F>(init));
}

template <typename... Args>
inline flock_a<> flock_vals(Args&&... args)
{
	return flock_t<>::create_(std::forward<Args>(args)...);
}

template <typename... Args>
inline flock_a<> flock_refs(Args&&... args)
{
	return flock_t<>::create_refs_(std::forward<Args>(args)...);
}

template <typename... Args>
inline flock_a<> flock_dups(Args&&... args)
{
	return flock_t<>::create_dups_(std::forward<Args>(args)...);
}

} // namespace strange

#endif
