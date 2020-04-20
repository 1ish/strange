#ifndef COM_ONEISH_STRANGE_SQUAD_T_H
#define COM_ONEISH_STRANGE_SQUAD_T_H

namespace strange
{

template <typename _element = any_a<>, bool _concurrent_ = false, typename ___ego___ = squad_a<_element>>
class squad_t : public thing_t<___ego___>
{
	template <typename _element_it, typename _iterator_, typename ___ego_it___ = random_access_mutator_data_a<_element_it, _iterator_>>
	class mutator_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline random_access_mutator_data_a<_element_it, _iterator_> create(F&& it)
		{
			return random_access_mutator_data_a<_element_it, _iterator_>::template create<mutator_t<_element_it, _iterator_>>(std::forward<F>(it));
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
			return check<random_access_mutator_data_a<_element_it, _iterator_>>(thing) &&
				_it == fast<random_access_mutator_data_a<_element_it, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(random_access_mutator_data_a<_element_it, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(random_access_mutator_data_a<_element_it, _iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std_size_t hash() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		inline bool less_than_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_element_it, _iterator_>>(thing)
				? _it < fast<random_access_mutator_data_a<_element_it, _iterator_>>(thing).extract_it()
				: one_t::less_than_(thing);
		}

		inline bool operator<(random_access_mutator_data_a<_element_it, _iterator_> const& it) const
		{
			return _it < it.extract_it();
		}

		inline bool greater_than_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_element_it, _iterator_>>(thing)
				? _it > fast<random_access_mutator_data_a<_element_it, _iterator_>>(thing).extract_it()
				: one_t::greater_than_(thing);
		}

		inline bool operator>(random_access_mutator_data_a<_element_it, _iterator_> const& it) const
		{
			return _it > it.extract_it();
		}

		inline bool less_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_element_it, _iterator_>>(thing)
				? _it <= fast<random_access_mutator_data_a<_element_it, _iterator_>>(thing).extract_it()
				: one_t::less_or_equal_(thing);
		}

		inline bool operator<=(random_access_mutator_data_a<_element_it, _iterator_> const& it) const
		{
			return _it <= it.extract_it();
		}

		inline bool greater_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_element_it, _iterator_>>(thing)
				? _it >= fast<random_access_mutator_data_a<_element_it, _iterator_>>(thing).extract_it()
				: one_t::greater_or_equal_(thing);
		}

		inline bool operator>=(random_access_mutator_data_a<_element_it, _iterator_> const& it) const
		{
			return _it >= it.extract_it();
		}

		// forward mutator
		inline _element_it get_() const
		{
			return *_it;
		}

		inline _element_it set_(_element_it const& thing) const
		{
			return operator*() = thing;
		}

		inline _element_it* operator->() const
		{
			return &operator*();
		}

		inline _element_it& operator*() const
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

		inline random_access_mutator_a<_element_it> add_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			result.mutate_it() += number.to_int_64();
			return result;
		}

		inline void self_subtract_(number_a<> const& number)
		{
			_it -= number.to_int_64();
		}

		inline random_access_mutator_a<_element_it> subtract_(number_a<> const& number) const
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

		friend class any_a<>;

		template <typename F>
		inline mutator_t(F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
		{}
	};

	template <typename _element_it, typename _iterator_, typename ___ego_it___ = random_access_extractor_data_a<_element_it, _iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline random_access_extractor_data_a<_element_it, _iterator_> create(squad_a<> const& squad, F&& it)
		{
			return random_access_extractor_data_a<_element_it, _iterator_>::template create<extractor_t<_element_it, _iterator_>>(squad, std::forward<F>(it));
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
			return check<random_access_extractor_data_a<_element_it, _iterator_>>(thing) &&
				_it == fast<random_access_extractor_data_a<_element_it, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(random_access_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(random_access_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std_size_t hash() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		inline bool less_than_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_element_it, _iterator_>>(thing)
				? _it < fast<random_access_extractor_data_a<_element_it, _iterator_>>(thing).extract_it()
				: one_t::less_than_(thing);
		}

		inline bool operator<(random_access_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it < it.extract_it();
		}

		inline bool greater_than_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_element_it, _iterator_>>(thing)
				? _it > fast<random_access_extractor_data_a<_element_it, _iterator_>>(thing).extract_it()
				: one_t::greater_than_(thing);
		}

		inline bool operator>(random_access_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it > it.extract_it();
		}

		inline bool less_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_element_it, _iterator_>>(thing)
				? _it <= fast<random_access_extractor_data_a<_element_it, _iterator_>>(thing).extract_it()
				: one_t::less_or_equal_(thing);
		}

		inline bool operator<=(random_access_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it <= it.extract_it();
		}

		inline bool greater_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_element_it, _iterator_>>(thing)
				? _it >= fast<random_access_extractor_data_a<_element_it, _iterator_>>(thing).extract_it()
				: one_t::greater_or_equal_(thing);
		}

		inline bool operator>=(random_access_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it >= it.extract_it();
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

		inline forward_extractor_a<any_a<>> to_extractor_any_() const
		{
			return extractor_t<any_a<>, _iterator_>::create(_squad, _it);
		}

		// bidirectional extractor
		inline void decrement_()
		{
			--_it;
		}

		// random access extractor
		inline void self_add_(number_a<> const& number)
		{
			_it += number.to_int_64();
		}

		inline random_access_extractor_a<_element_it> add_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			result.mutate_it() += number.to_int_64();
			return result;
		}

		inline void self_subtract_(number_a<> const& number)
		{
			_it -= number.to_int_64();
		}

		inline random_access_extractor_a<_element_it> subtract_(number_a<> const& number) const
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

		friend class any_a<>;

		template <typename F>
		inline extractor_t(squad_a<> const& squad, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _squad{ squad }
		{}
	};

public:
	using std_deque_element = std_deque<_element>;

	// construction
	static inline any_a<> create__(range_a<> const& list)
	{
		auto result = create_();
		if (check<range_a<_element>>(list))
		{
			result += fast<range_a<_element>>(list);
		}
		else
		{
			for (auto const& thing : list)
			{
				result.push_back(cast<_element>(thing));
			}
		}
		return result;
	}

	static inline squad_a<_element> create_()
	{
		return create(std_deque_element{});
	}

	template <typename... Args>
	static inline squad_a<_element> create_(Args&&... args)
	{
		return create(variadic_u<_element>::deque(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline squad_a<_element> create_refs_(Args&&... args)
	{
		return create(variadic_u<_element>::deque_ref(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline squad_a<_element> create_dups_(Args&&... args)
	{
		return create(variadic_u<_element>::deque_dup(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline squad_a<_element> create(F&& init)
	{
		return squad_a<_element>::template create<squad_t<_element, _concurrent_>>(std::forward<F>(init));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::squad" + 
			std_string{ _concurrent_ ? "_concurrent" : "" } +
			kind_of<_element>().to_string());
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym(type_().to_string() + "::create"), native_function_create(&squad_t<_element, _concurrent_>::create__));
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
		if (!check<squad_a<_element>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque == fast<squad_a<_element>>(thing).extract_deque();
	}

	inline bool operator==(squad_a<_element> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque == squad.extract_deque();
	}

	inline bool operator!=(squad_a<_element> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque != squad.extract_deque();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std_size_t hash() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_size_t seed = std::hash<std_size_t>{}(_deque.size());
		for (auto const& item : _deque)
		{
			seed ^= item.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	inline bool less_than_(any_a<> const& thing) const
	{
		if (!check<squad_a<_element>>(thing))
		{
			return one_t::less_than_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque < fast<squad_a<_element>>(thing).extract_deque();
	}

	inline bool operator<(squad_a<_element> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque < squad.extract_deque();
	}

	inline bool greater_than_(any_a<> const& thing) const
	{
		if (!check<squad_a<_element>>(thing))
		{
			return one_t::greater_than_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque > fast<squad_a<_element>>(thing).extract_deque();
	}

	inline bool operator>(squad_a<_element> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque > squad.extract_deque();
	}

	inline bool less_or_equal_(any_a<> const& thing) const
	{
		if (!check<squad_a<_element>>(thing))
		{
			return one_t::less_or_equal_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque <= fast<squad_a<_element>>(thing).extract_deque();
	}

	inline bool operator<=(squad_a<_element> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque <= squad.extract_deque();
	}

	inline bool greater_or_equal_(any_a<> const& thing) const
	{
		if (!check<squad_a<_element>>(thing))
		{
			return one_t::greater_or_equal_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque >= fast<squad_a<_element>>(thing).extract_deque();
	}

	inline bool operator>=(squad_a<_element> const& squad) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque >= squad.extract_deque();
	}

	// list
	inline forward_extractor_a<any_a<>> begin_() const
	{
		return extractor_t<any_a<>, typename std_deque_element::const_iterator>::create(thing_t<___ego___>::me_(), _deque.cbegin());
	}

	inline forward_extractor_a<any_a<>> end_() const
	{
		return extractor_t<any_a<>, typename std_deque_element::const_iterator>::create(thing_t<___ego___>::me_(), _deque.cend());
	}

	// range
	inline random_access_extractor_a<_element> extract_begin_() const
	{
		return extractor_t<_element, typename std_deque_element::const_iterator>::create(thing_t<___ego___>::me_(), _deque.cbegin());
	}

	inline random_access_extractor_data_a<_element, typename std_deque_element::const_iterator> extract_begin() const
	{
		return extractor_t<_element, typename std_deque_element::const_iterator>::create(thing_t<___ego___>::me_(), _deque.cbegin());
	}

	inline random_access_extractor_a<_element> extract_end_() const
	{
		return extractor_t<_element, typename std_deque_element::const_iterator>::create(thing_t<___ego___>::me_(), _deque.cend());
	}

	inline random_access_extractor_data_a<_element, typename std_deque_element::const_iterator> extract_end() const
	{
		return extractor_t<_element, typename std_deque_element::const_iterator>::create(thing_t<___ego___>::me_(), _deque.cend());
	}

	inline random_access_mutator_a<_element> mutate_begin_()
	{
		return mutator_t<_element, typename std_deque_element::iterator>::create(_deque.begin());
	}

	inline random_access_mutator_data_a<_element, typename std_deque_element::iterator> mutate_begin()
	{
		return mutator_t<_element, typename std_deque_element::iterator>::create(_deque.begin());
	}

	inline random_access_mutator_a<_element> mutate_end_()
	{
		return mutator_t<_element, typename std_deque_element::iterator>::create(_deque.end());
	}

	inline random_access_mutator_data_a<_element, typename std_deque_element::iterator> mutate_end()
	{
		return mutator_t<_element, typename std_deque_element::iterator>::create(_deque.end());
	}

	// collection
	inline any_a<> has_(number_data_a<int64_t> const& key) const
	{
		return boole(has(key));
	}

	inline bool has(number_data_a<int64_t> const& key) const
	{
		return has_index(key.extract_primitive());
	}

	inline bool has_index(int64_t index) const
	{
		return index >= 0 && index < size();
	}

	inline _element at_(number_data_a<int64_t> const& key) const
	{
		return at_index(key.extract_primitive());
	}

	inline _element at_index(int64_t index) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		if (index >= 0 && index < int64_t(_deque.size()))
		{
			return _deque[std_size_t(index)];
		}
		return mis("strange::squad::at index out of bounds");
	}

	inline _element update_(number_data_a<int64_t> const& key, _element const& value)
	{
		update(key, value);
		return value;
	}

	inline void update(number_data_a<int64_t> const& key, _element const& value)
	{
		update_index(key.extract_primitive(), value);
	}

	inline void update_index(int64_t index, _element const& value)
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
					_deque.resize(std_size_t(index) + 1, no());
				}
				_deque[std_size_t(index)] = value;
			}
		}
	}

	inline any_a<> insert_(number_data_a<int64_t> const& key, _element const& value)
	{
		return boole(insert(key, value));
	}

	inline bool insert(number_data_a<int64_t> const& key, _element const& value)
	{
		return insert_index(key.extract_primitive(), value);
	}

	inline bool insert_index(int64_t index, _element const& value)
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
					_deque.resize(std_size_t(index) + 1, no());
					_deque[std_size_t(index)] = value;
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

	inline any_a<> erase_(number_data_a<int64_t> const& key)
	{
		return boole(erase(key));
	}

	inline bool erase(number_data_a<int64_t> const& key)
	{
		return erase_index(key.extract_primitive());
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

	inline ___ego___ push_front_(_element const& value)
	{
		push_front(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_front(_element const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.push_front(thing);
	}

	inline _element pop_front_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (_deque.empty())
		{
			throw dis("strange::squad::pop_front called on empty squad");
		}
		_element result = _deque.front();
		_deque.pop_front();
		return result;
	}

	inline ___ego___ push_back_(_element const& value)
	{
		push_back(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_back(_element const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.push_back(thing);
	}

	inline _element pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (_deque.empty())
		{
			throw dis("strange::squad::pop_back called on empty squad");
		}
		_element result = _deque.back();
		_deque.pop_back();
		return result;
	}

	inline void self_assign_(range_a<_element> const& range)
	{
		if (check<squad_a<_element>>(range))
		{
			auto const other = fast<squad_a<_element>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque = other.extract_deque();
		}
		else
		{
			auto read_lock = check<collection_a<_element>>(range) ? fast<collection_a<_element>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque.clear();
			for (auto const& thing : range)
			{
				_deque.push_back(thing);
			}
		}
	}

	inline void self_add_(range_a<_element> const& range)
	{
		if (check<squad_a<_element>>(range))
		{
			auto const other = fast<squad_a<_element>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_deque = other.extract_deque();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque.insert(_deque.cend(), other_deque.cbegin(), other_deque.cend());
		}
		else
		{
			auto read_lock = check<collection_a<_element>>(range) ? fast<collection_a<_element>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				_deque.push_back(thing);
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
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (check<collection_a<_element>>(range))
		{
			_deque.resize(std_size_t(std::max<int64_t>(0, int64_t(_deque.size()) - fast<collection_a<_element>>(range).size())));
		}
		else
		{
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
	inline std_deque_element const& extract_deque() const
	{
		return _deque;
	}

	inline std_deque_element& mutate_deque()
	{
		return _deque;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_deque_element _deque;

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

template <typename _element, bool _concurrent_, typename ___ego___>
bool const squad_t<_element, _concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	squad_t<_element, _concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

class ___squad_t_share___
{
	static inline bool ___share___()
	{
		return squad_t<>::___share___
			&& squad_t<any_a<>, true>::___share___;
	}
};

// template <typename _element = any_a<>, bool _concurrent_ = false>
template <typename _element, bool _concurrent_>
inline squad_a<_element> squad_create()
{
	return squad_t<_element, _concurrent_>::create_();
}

} // namespace strange

#endif
