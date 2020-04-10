#ifndef COM_ONEISH_STRANGE_SQUAD_T_H
#define COM_ONEISH_STRANGE_SQUAD_T_H

namespace strange
{

template <bool _concurrent_ = false, typename ___ego___ = squad_a<>>
class squad_t : public thing_t<___ego___>
{
	template <typename _element, typename _iterator_, typename ___ego_it___ = random_access_mutator_data_a<_element, _iterator_>>
	class mutator_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline random_access_mutator_data_a<_element, _iterator_> create(squad_t const& squad_thing, F&& it)
		{
			return random_access_mutator_data_a<_element, _iterator_>::template create<mutator_t<_element, _iterator_>>(squad_thing, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::squad::mutator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_element, _iterator_>>(thing) &&
				_it == fast<random_access_mutator_data_a<_element, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(random_access_mutator_data_a<_element, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(random_access_mutator_data_a<_element, _iterator_> const& it) const
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

		inline bool less_than_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_element, _iterator_>>(thing)
				? _it < fast<random_access_mutator_data_a<_element, _iterator_>>(thing).extract_it()
				: one_t::less_than_(thing);
		}

		inline bool operator<(random_access_mutator_data_a<_element, _iterator_> const& it) const
		{
			return _it < it.extract_it();
		}

		inline bool greater_than_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_element, _iterator_>>(thing)
				? _it > fast<random_access_mutator_data_a<_element, _iterator_>>(thing).extract_it()
				: one_t::greater_than_(thing);
		}

		inline bool operator>(random_access_mutator_data_a<_element, _iterator_> const& it) const
		{
			return _it > it.extract_it();
		}

		inline bool less_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_element, _iterator_>>(thing)
				? _it <= fast<random_access_mutator_data_a<_element, _iterator_>>(thing).extract_it()
				: one_t::less_or_equal_(thing);
		}

		inline bool operator<=(random_access_mutator_data_a<_element, _iterator_> const& it) const
		{
			return _it <= it.extract_it();
		}

		inline bool greater_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_element, _iterator_>>(thing)
				? _it >= fast<random_access_mutator_data_a<_element, _iterator_>>(thing).extract_it()
				: one_t::greater_or_equal_(thing);
		}

		inline bool operator>=(random_access_mutator_data_a<_element, _iterator_> const& it) const
		{
			return _it >= it.extract_it();
		}

		// forward mutator
		inline _element get_() const
		{
			return *_it;
		}

		inline _element set_(_element const& thing) const
		{
			return operator*() = thing;
		}

		inline _element* operator->() const
		{
			return &operator*();
		}

		inline _element& operator*() const
		{
			return *_it;
		}

		inline void increment_()
		{
			++_it;
		}

		// bidirectional mutator
		inline void decrement_()
		{
			--_it;
		}

		// random access mutator
		inline void self_add_(number_a<> const& number)
		{
			_it += number.to_int_64();
		}

		inline random_access_mutator_a<_element> add_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			result.mutate_it() += number.to_int_64();
			return result;
		}

		inline void self_subtract_(number_a<> const& number)
		{
			_it -= number.to_int_64();
		}

		inline random_access_mutator_a<_element> subtract_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
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
		squad_t const& _squad_thing;

		friend class any_a<>;

		template <typename F>
		inline mutator_t(squad_t const& squad_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _squad_thing{ squad_thing }
		{}
	};

	template <typename _element, typename _iterator_, typename ___ego_it___ = random_access_extractor_data_a<_element, _iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline random_access_extractor_data_a<_element, _iterator_> create(squad_a<> const& squad, squad_t const& squad_thing, F&& it)
		{
			return random_access_extractor_data_a<_element, _iterator_>::template create<extractor_t<_element, _iterator_>>(squad, squad_thing, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::squad::extractor");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_element, _iterator_>>(thing) &&
				_it == fast<random_access_extractor_data_a<_element, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(random_access_extractor_data_a<_element, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(random_access_extractor_data_a<_element, _iterator_> const& it) const
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

		inline bool less_than_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_element, _iterator_>>(thing)
				? _it < fast<random_access_extractor_data_a<_element, _iterator_>>(thing).extract_it()
				: one_t::less_than_(thing);
		}

		inline bool operator<(random_access_extractor_data_a<_element, _iterator_> const& it) const
		{
			return _it < it.extract_it();
		}

		inline bool greater_than_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_element, _iterator_>>(thing)
				? _it > fast<random_access_extractor_data_a<_element, _iterator_>>(thing).extract_it()
				: one_t::greater_than_(thing);
		}

		inline bool operator>(random_access_extractor_data_a<_element, _iterator_> const& it) const
		{
			return _it > it.extract_it();
		}

		inline bool less_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_element, _iterator_>>(thing)
				? _it <= fast<random_access_extractor_data_a<_element, _iterator_>>(thing).extract_it()
				: one_t::less_or_equal_(thing);
		}

		inline bool operator<=(random_access_extractor_data_a<_element, _iterator_> const& it) const
		{
			return _it <= it.extract_it();
		}

		inline bool greater_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_element, _iterator_>>(thing)
				? _it >= fast<random_access_extractor_data_a<_element, _iterator_>>(thing).extract_it()
				: one_t::greater_or_equal_(thing);
		}

		inline bool operator>=(random_access_extractor_data_a<_element, _iterator_> const& it) const
		{
			return _it >= it.extract_it();
		}

		// forward extractor
		inline _element get_() const
		{
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
			++_it;
		}

		// bidirectional mutator
		inline void decrement_()
		{
			--_it;
		}

		// random access mutator
		inline void self_add_(number_a<> const& number)
		{
			_it += number.to_int_64();
		}

		inline random_access_extractor_a<_element> add_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			result.mutate_it() += number.to_int_64();
			return result;
		}

		inline void self_subtract_(number_a<> const& number)
		{
			_it -= number.to_int_64();
		}

		inline random_access_extractor_a<_element> subtract_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
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
		squad_a<> const _squad;
		squad_t const& _squad_thing;

		friend class any_a<>;

		template <typename F>
		inline extractor_t(squad_a<> const& squad, squad_t const& squad_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _squad{ squad }
			, _squad_thing{ squad_thing }
		{}
	};

public:
	using std_deque_any = std::deque<any_a<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return create_() += range;
	}

	static inline squad_a<> create_()
	{
		return create(std_deque_any{});
	}

	template <typename... Args>
	static inline squad_a<> create_(Args&&... args)
	{
		return create(variadic_u<>::deque(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline squad_a<> create_refs_(Args&&... args)
	{
		return create(variadic_u<>::deque_ref(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline squad_a<> create_dups_(Args&&... args)
	{
		return create(variadic_u<>::deque_dup(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline squad_a<> create(F&& init)
	{
		return squad_a<>::create<squad_t<_concurrent_>>(std::forward<F>(init));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::squad" + std::string{ _concurrent_ ? "_concurrent" : "" });
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type_().to_string() + "::create", native_function_create(&squad_t<_concurrent_>::create__));
	}

	// visitor pattern
	inline any_a<> visit_(inventory_a<>& inventory) const
	{
		auto result = thing_t<>::visit_(inventory);
		if (result)
		{
			auto last = inventory.size() - 1;
			typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
			for (auto const& visited : _deque)
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
		if (!check<squad_a<>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque == fast<squad_a<>>(thing).extract_deque();
	}

	inline bool operator==(squad_a<> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque == squad.extract_deque();
	}

	inline bool operator!=(squad_a<> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque != squad.extract_deque();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std::size_t hash() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std::size_t seed = std::hash<std::size_t>{}(_deque.size());
		for (auto const& item : _deque)
		{
			seed ^= item.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	inline bool less_than_(any_a<> const& thing) const
	{
		if (!check<squad_a<>>(thing))
		{
			return one_t::less_than_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque < fast<squad_a<>>(thing).extract_deque();
	}

	inline bool operator<(squad_a<> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque < squad.extract_deque();
	}

	inline bool greater_than_(any_a<> const& thing) const
	{
		if (!check<squad_a<>>(thing))
		{
			return one_t::greater_than_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque > fast<squad_a<>>(thing).extract_deque();
	}

	inline bool operator>(squad_a<> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque > squad.extract_deque();
	}

	inline bool less_or_equal_(any_a<> const& thing) const
	{
		if (!check<squad_a<>>(thing))
		{
			return one_t::less_or_equal_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque <= fast<squad_a<>>(thing).extract_deque();
	}

	inline bool operator<=(squad_a<> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque <= squad.extract_deque();
	}

	inline bool greater_or_equal_(any_a<> const& thing) const
	{
		if (!check<squad_a<>>(thing))
		{
			return one_t::greater_or_equal_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque >= fast<squad_a<>>(thing).extract_deque();
	}

	inline bool operator>=(squad_a<> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque >= squad.extract_deque();
	}

	// range
	inline random_access_extractor_a<any_a<>> extract_begin_() const
	{
		return extractor_t<any_a<>, typename std_deque_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _deque.cbegin());
	}

	inline random_access_extractor_data_a<any_a<>, typename std_deque_any::const_iterator> extract_begin() const
	{
		return extractor_t<any_a<>, typename std_deque_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _deque.cbegin());
	}

	inline random_access_extractor_a<any_a<>> extract_end_() const
	{
		return extractor_t<any_a<>, typename std_deque_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _deque.cend());
	}

	inline random_access_extractor_data_a<any_a<>, typename std_deque_any::const_iterator> extract_end() const
	{
		return extractor_t<any_a<>, typename std_deque_any::const_iterator>::create(thing_t<___ego___>::me_(), *this, _deque.cend());
	}

	inline random_access_mutator_a<any_a<>> mutate_begin_()
	{
		return mutator_t<any_a<>, typename std_deque_any::iterator>::create(*this, _deque.begin());
	}

	inline random_access_mutator_data_a<any_a<>, typename std_deque_any::iterator> mutate_begin()
	{
		return mutator_t<any_a<>, typename std_deque_any::iterator>::create(*this, _deque.begin());
	}

	inline random_access_mutator_a<any_a<>> mutate_end_()
	{
		return mutator_t<any_a<>, typename std_deque_any::iterator>::create(*this, _deque.end());
	}

	inline random_access_mutator_data_a<any_a<>, typename std_deque_any::iterator> mutate_end()
	{
		return mutator_t<any_a<>, typename std_deque_any::iterator>::create(*this, _deque.end());
	}

	// collection
	inline any_a<> has_(any_a<> const& key) const
	{
		return boole(has(key));
	}

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
		return mis("strange::squad::at index is not a number");
	}

	inline any_a<> at_index(int64_t index) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		if (index >= 0 && index < int64_t(_deque.size()))
		{
			return _deque[std::size_t(index)];
		}
		return mis("strange::squad::at index out of bounds");
	}

	inline any_a<> update_(any_a<> const& key, any_a<> const& value = no())
	{
		update(key, value);
		return value;
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
			int64_t const siz = int64_t(_deque.size());
			if (index == siz)
			{
				_deque.push_back(value);
			}
			else
			{
				if (index > siz)
				{
					_deque.resize(std::size_t(index) + 1, no());
				}
				_deque[std::size_t(index)] = value;
			}
		}
	}

	inline any_a<> insert_(any_a<> const& key, any_a<> const& value = no())
	{
		return boole(insert(key, value));
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
			int64_t const siz = int64_t(_deque.size());
			if (index == siz)
			{
				_deque.push_back(value);
			}
			else
			{
				if (index > siz)
				{
					_deque.resize(std::size_t(index) + 1, no());
					_deque[std::size_t(index)] = value;
				}
				else
				{
					_deque.insert(_deque.cbegin() + index, value);
				}
			}
			return true;
		}
		return false;
	}

	inline any_a<> erase_(any_a<> const& key)
	{
		return boole(erase(key));
	}

	inline bool erase(any_a<> const& key)
	{
		return check<number_a<>>(key) && erase_index(fast<number_a<>>(key).to_int_64());
	}

	inline bool erase_index(int64_t index)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (index >= 0 && index < int64_t(_deque.size()))
		{
			_deque.erase(_deque.cbegin() + index);
			return true;
		}
		return false;
	}

	inline ___ego___ clear_()
	{
		clear();
		return thing_t<___ego___>::me_();
	}

	inline void clear()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.clear();
	}

	inline number_data_a<int64_t> size_() const
	{
		return num(size());
	}

	inline int64_t size() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return int64_t(_deque.size());
	}

	inline any_a<> empty_() const
	{
		return boole(empty());
	}

	inline bool empty() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque.empty();
	}

	inline ___ego___ push_front_(any_a<> const& value)
	{
		push_front(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_front(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.push_front(thing);
	}

	inline any_a<> pop_front_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (_deque.empty())
		{
			return no();
		}
		any_a<> result = _deque.front();
		_deque.pop_front();
		return result;
	}

	inline ___ego___ push_back_(any_a<> const& value)
	{
		push_back(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_back(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.push_back(thing);
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (_deque.empty())
		{
			return no();
		}
		any_a<> result = _deque.back();
		_deque.pop_back();
		return result;
	}

	inline void self_assign_(range_a<> const& range)
	{
		if (check<squad_a<>>(range))
		{
			auto const other = fast<squad_a<>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque = other.extract_deque();
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque.clear();
			for (auto const& thing : range)
			{
				_deque.push_back(thing);
			}
		}
	}

	inline void self_add_(range_a<> const& range)
	{
		if (check<squad_a<>>(range))
		{
			auto const other = fast<squad_a<>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_deque = other.extract_deque();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque.insert(_deque.cend(), other_deque.cbegin(), other_deque.cend());
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				_deque.push_back(thing);
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
		if (check<collection_a<>>(range))
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			_deque.resize(std::size_t(std::max<int64_t>(0, int64_t(_deque.size()) - fast<collection_a<>>(range).size())));
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				if (_deque.empty())
				{
					break;
				}
				_deque.pop_back();
			}
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
	inline std_deque_any const& extract_deque() const
	{
		return _deque;
	}

	inline std_deque_any& mutate_deque()
	{
		return _deque;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_deque_any _deque;

	friend class any_a<>;

	template <typename F>
	inline squad_t(F&& init)
		: thing_t<___ego___>{}
		, _mutex{}
		, _deque{ std::forward<F>(init) }
	{}

public:
	inline squad_t(squad_t const& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _deque{ other._deque }
	{}

	inline squad_t(squad_t&& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _deque{ std::move(other._deque) }
	{}

private:
	static bool const ___share___;
	friend class ___squad_t_share___;
};

template <bool _concurrent_, typename ___ego___>
bool const squad_t<_concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	squad_t<_concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

class ___squad_t_share___
{
	static inline bool ___share___()
	{
		return squad_t<>::___share___
			&& squad_t<true>::___share___;
	}
};

// template <bool _concurrent_ = false>
template <bool _concurrent_>
inline squad_a<> squad_create()
{
	return squad_t<_concurrent_>::create_();
}

} // namespace strange

#endif
