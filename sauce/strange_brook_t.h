#ifndef COM_ONEISH_STRANGE_BROOK_T_H
#define COM_ONEISH_STRANGE_BROOK_T_H

namespace strange
{

template <typename _primitive_, bool _concurrent_ = false, typename ___ego___ = brook_a<_primitive_>>
class brook_t : public thing_t<___ego___>
{
	template <typename _element, typename _iterator_, typename ___ego_it___ = random_access_mutator_data_a<_element, _iterator_>>
	class mutator_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline random_access_mutator_data_a<_element, _iterator_> create(brook_t const& brook_thing, F&& it)
		{
			return random_access_mutator_data_a<_element, _iterator_>::template create<mutator_t<_element, _iterator_>>(brook_thing, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::brook::mutator");
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

		inline std_size_t hash() const
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
			return num(*_it);
		}

		inline _element set_(_element const& thing) const
		{
			*_it = thing.extract_primitive();
			return thing;
		}

		inline _element* operator->() const
		{
			return &operator*();
		}

		inline _element& operator*() const
		{
			_brook_thing._shadow.resize(_brook_thing._deque.size());
			auto& number = _brook_thing._shadow[_it - _brook_thing._deque.begin()];
			auto& primitive = *_it;
			if (!check<any_a<>>(number) || &number.extract_primitive() != &primitive)
			{
				number = number_reference_t<_primitive_>::create(primitive);
			}
			// assigning to this reference won't change the collection
			// assigning from this reference will create a shared non-const reference
			return number;
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
		brook_t const& _brook_thing;

		friend class any_a<>;

		template <typename F>
		inline mutator_t(brook_t const& brook_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _brook_thing{ brook_thing }
		{}
	};

	template <typename _element, typename _iterator_, typename ___ego_it___ = random_access_extractor_data_a<_element, _iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline random_access_extractor_data_a<_element, _iterator_> create(brook_a<_primitive_> const& brook, brook_t const& brook_thing, F&& it)
		{
			return random_access_extractor_data_a<_element, _iterator_>::template create<extractor_t<_element, _iterator_>>(brook, brook_thing, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::brook::extractor");
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

		inline std_size_t hash() const
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
			return num(*_it);
		}

		inline _element const* operator->() const
		{
			return &operator*();
		}

		inline _element const& operator*() const
		{
			_brook_thing._shadow.resize(_brook_thing._deque.size());
			auto& number = _brook_thing._shadow[_it - _brook_thing._deque.cbegin()];
			auto& primitive = const_cast<_primitive_&>(*_it);
			if (!check<any_a<>>(number) || &number.extract_primitive() != &primitive)
			{
				number = number_reference_t<_primitive_>::create(primitive);
			}
			// assigning from this reference will create a shared non-const reference
			return number;
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
		brook_a<_primitive_> const _brook;
		brook_t const& _brook_thing;

		friend class any_a<>;

		template <typename F>
		inline extractor_t(brook_a<_primitive_> const& brook, brook_t const& brook_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _brook{ brook }
			, _brook_thing{ brook_thing }
		{}
	};

public:
	using std_deque_primitive = std_deque<_primitive_>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		auto result = create_();
		if (check<range_a<number_data_a<_primitive_>>>(range))
		{
			result += fast<range_a<number_data_a<_primitive_>>>(range);
		}
		else
		{
			for (auto const& thing : range)
			{
				result.push_back(cast<number_data_a<_primitive_>>(thing));
			}
		}
		return result;
	}

	static inline brook_a<_primitive_> create_()
	{
		return create(std_deque_primitive{});
	}

	template <typename... Args>
	static inline brook_a<_primitive_> create_(Args&&... args)
	{
		return create(variadic_u<_primitive_>::deque(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline brook_a<_primitive_> create_refs_(Args&&... args)
	{
		return create(variadic_u<_primitive_>::deque_ref(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline brook_a<_primitive_> create_dups_(Args&&... args)
	{
		return create(variadic_u<_primitive_>::deque_dup(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline brook_a<_primitive_> create(F&& init)
	{
		return brook_a<_primitive_>::template create<brook_t<_primitive_, _concurrent_>>(std::forward<F>(init));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::brook_" + 
			number_u<_primitive_>::category() +
			(_concurrent_ ? "_concurrent" : ""));
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym(type_().to_string() + "::create"), native_function_create(&brook_t<_primitive_, _concurrent_>::create__));
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		if (!check<brook_a<_primitive_>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque == fast<brook_a<_primitive_>>(thing).extract_deque();
	}

	inline bool operator==(brook_a<_primitive_> const& brook) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque == brook.extract_deque();
	}

	inline bool operator!=(brook_a<_primitive_> const& brook) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque != brook.extract_deque();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std_size_t hash() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_size_t seed = std::hash<std_size_t>{}(_deque.size());
		for (auto item : _deque)
		{
			seed ^= std::hash<_primitive_>{}(item) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	inline bool less_than_(any_a<> const& thing) const
	{
		if (!check<brook_a<_primitive_>>(thing))
		{
			return one_t::less_than_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque < fast<brook_a<_primitive_>>(thing).extract_deque();
	}

	inline bool operator<(brook_a<_primitive_> const& brook) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque < brook.extract_deque();
	}

	inline bool greater_than_(any_a<> const& thing) const
	{
		if (!check<brook_a<_primitive_>>(thing))
		{
			return one_t::greater_than_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque > fast<brook_a<_primitive_>>(thing).extract_deque();
	}

	inline bool operator>(brook_a<_primitive_> const& brook) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque > brook.extract_deque();
	}

	inline bool less_or_equal_(any_a<> const& thing) const
	{
		if (!check<brook_a<_primitive_>>(thing))
		{
			return one_t::less_or_equal_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque <= fast<brook_a<_primitive_>>(thing).extract_deque();
	}

	inline bool operator<=(brook_a<_primitive_> const& brook) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque <= brook.extract_deque();
	}

	inline bool greater_or_equal_(any_a<> const& thing) const
	{
		if (!check<brook_a<_primitive_>>(thing))
		{
			return one_t::greater_or_equal_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque >= fast<brook_a<_primitive_>>(thing).extract_deque();
	}

	inline bool operator>=(brook_a<_primitive_> const& brook) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque >= brook.extract_deque();
	}

	// range
	inline random_access_extractor_a<number_data_a<_primitive_>> extract_begin_() const
	{
		return extractor_t<number_data_a<_primitive_>, typename std_deque_primitive::const_iterator>::create(thing_t<___ego___>::me_(), *this, _deque.cbegin());
	}

	inline random_access_extractor_data_a<number_data_a<_primitive_>, typename std_deque_primitive::const_iterator> extract_begin() const
	{
		return extractor_t<number_data_a<_primitive_>, typename std_deque_primitive::const_iterator>::create(thing_t<___ego___>::me_(), *this, _deque.cbegin());
	}

	inline random_access_extractor_a<number_data_a<_primitive_>> extract_end_() const
	{
		return extractor_t<number_data_a<_primitive_>, typename std_deque_primitive::const_iterator>::create(thing_t<___ego___>::me_(), *this, _deque.cend());
	}

	inline random_access_extractor_data_a<number_data_a<_primitive_>, typename std_deque_primitive::const_iterator> extract_end() const
	{
		return extractor_t<number_data_a<_primitive_>, typename std_deque_primitive::const_iterator>::create(thing_t<___ego___>::me_(), *this, _deque.cend());
	}

	inline random_access_mutator_a<number_data_a<_primitive_>> mutate_begin_()
	{
		return mutator_t<number_data_a<_primitive_>, typename std_deque_primitive::iterator>::create(*this, _deque.begin());
	}

	inline random_access_mutator_data_a<number_data_a<_primitive_>, typename std_deque_primitive::iterator> mutate_begin()
	{
		return mutator_t<number_data_a<_primitive_>, typename std_deque_primitive::iterator>::create(*this, _deque.begin());
	}

	inline random_access_mutator_a<number_data_a<_primitive_>> mutate_end_()
	{
		return mutator_t<number_data_a<_primitive_>, typename std_deque_primitive::iterator>::create(*this, _deque.end());
	}

	inline random_access_mutator_data_a<number_data_a<_primitive_>, typename std_deque_primitive::iterator> mutate_end()
	{
		return mutator_t<number_data_a<_primitive_>, typename std_deque_primitive::iterator>::create(*this, _deque.end());
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

	inline number_data_a<_primitive_> at_(number_data_a<int64_t> const& key) const
	{
		return at_index(key.extract_primitive());
	}

	inline number_data_a<_primitive_> at_index(int64_t index) const
	{
		return num(pat(index));
	}

	inline _primitive_ pat(int64_t index) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		if (index >= 0 && index < int64_t(_deque.size()))
		{
			return _deque[std_size_t(index)];
		}
		return _primitive_{};
	}

	inline number_data_a<_primitive_> update_(number_data_a<int64_t> const& key, number_data_a<_primitive_> const& value)
	{
		update(key, value);
		return value;
	}

	inline void update(number_data_a<int64_t> const& key, number_data_a<_primitive_> const& value)
	{
		update_index(key.extract_primitive(), value);
	}

	inline void update_index(int64_t index, number_data_a<_primitive_> const& value)
	{
		return pupdate(index, value.extract_primitive());
	}

	inline void pupdate(int64_t index, _primitive_ number)
	{
		if (index >= 0)
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			int64_t const siz = int64_t(_deque.size());
			if (index == siz)
			{
				_deque.push_back(number);
			}
			else
			{
				if (index > siz)
				{
					_deque.resize(std_size_t(index) + 1, no());
				}
				_deque[std_size_t(index)] = number;
			}
		}
	}

	inline any_a<> insert_(number_data_a<int64_t> const& key, number_data_a<_primitive_> const& value)
	{
		return boole(insert(key, value));
	}

	inline bool insert(number_data_a<int64_t> const& key, number_data_a<_primitive_> const& value)
	{
		return insert_index(key.extract_primitive(), value);
	}

	inline bool insert_index(int64_t index, number_data_a<_primitive_> const& value)
	{
		return pinsert(index, value.extract_primitive());
	}

	inline bool pinsert(int64_t index, _primitive_ number)
	{
		if (index >= 0)
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			int64_t const siz = int64_t(_deque.size());
			if (index == siz)
			{
				_deque.push_back(number);
			}
			else
			{
				if (index > siz)
				{
					_deque.resize(std_size_t(index) + 1, no());
					_deque[std_size_t(index)] = number;
				}
				else
				{
					_deque.insert(_deque.cbegin() + index, number);
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

	inline ___ego___ push_front_(number_data_a<_primitive_> const& value)
	{
		push_front(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_front(number_data_a<_primitive_> const& thing)
	{
		push_front(thing.extract_primitive());
	}

	inline void push_front(_primitive_ number)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.push_front(number);
	}

	inline number_data_a<_primitive_> pop_front_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (_deque.empty())
		{
			throw dis("strange::brook::pop_front called on empty brook");
		}
		_primitive_ number = _deque.front();
		_deque.pop_front();
		return num(number);
	}

	inline _primitive_ pop_front()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_primitive_ number = _deque.front();
		_deque.pop_front();
		return number;
	}

	inline ___ego___ push_back_(number_data_a<_primitive_> const& value)
	{
		push_back(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_back(number_data_a<_primitive_> const& thing)
	{
		push_back(thing.extract_primitive());
	}

	inline void push_back(_primitive_ number)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.push_back(number);
	}

	inline number_data_a<_primitive_> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (_deque.empty())
		{
			throw dis("strange::brook::pop_back called on empty brook");
		}
		_primitive_ number = _deque.back();
		_deque.pop_back();
		return num(number);
	}

	inline _primitive_ pop_back()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_primitive_ number = _deque.back();
		_deque.pop_back();
		return number;
	}

	inline void self_assign_(range_a<number_data_a<_primitive_>> const& range)
	{
		if (check<brook_a<_primitive_>>(range))
		{
			auto const other = fast<brook_a<_primitive_>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque = other.extract_deque();
		}
		else
		{
			auto read_lock = check<collection_a<number_data_a<_primitive_>>>(range) ? fast<collection_a<number_data_a<_primitive_>>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque.clear();
			for (auto const& thing : range)
			{
				_deque.push_back(thing);
			}
		}
	}

	inline void self_add_(range_a<number_data_a<_primitive_>> const& range)
	{
		if (check<brook_a<_primitive_>>(range))
		{
			auto const other = fast<brook_a<_primitive_>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_deque = other.extract_deque();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque.insert(_deque.cend(), other_deque.cbegin(), other_deque.cend());
		}
		else
		{
			auto read_lock = check<collection_a<number_data_a<_primitive_>>>(range) ? fast<collection_a<number_data_a<_primitive_>>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				_deque.push_back(thing);
			}
		}
	}

	inline ___ego___ add_(range_a<number_data_a<_primitive_>> const& range) const
	{
		auto result = thing_t<___ego___>::me_();
		result += range;
		return result;
	}

	inline void self_subtract_(range_a<number_data_a<_primitive_>> const& range)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (check<collection_a<number_data_a<_primitive_>>>(range))
		{
			_deque.resize(std_size_t(std::max<int64_t>(0, int64_t(_deque.size()) - fast<collection_a<number_data_a<_primitive_>>>(range).size())));
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

	inline ___ego___ subtract_(range_a<number_data_a<_primitive_>> const& range) const
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
	inline std_deque_primitive const& extract_deque() const
	{
		return _deque;
	}

	inline std_deque_primitive& mutate_deque()
	{
		return _deque;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_deque_primitive _deque;
	std_vector<number_data_a<_primitive_>> mutable _shadow;

	friend class any_a<>;

	template <typename F>
	inline brook_t(F&& init)
		: thing_t<___ego___>{}
		, _mutex{}
		, _deque{ std::forward<F>(init) }
		, _shadow{}
	{}

public:
	inline brook_t(brook_t const& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _deque{ other._deque }
		, _shadow{}
	{}

	inline brook_t(brook_t&& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _deque{ std::move(other._deque) }
		, _shadow{}
	{}

private:
	static bool const ___share___;
	friend class ___brook_t_share___;
};

template <typename _primitive_, bool _concurrent_, typename ___ego___>
bool const brook_t<_primitive_, _concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	brook_t<_primitive_, _concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

template <bool _concurrent_ = false, typename ___ego___ = brook_a<int8_t>>
using brook_int_8_t = brook_t<int8_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<uint8_t>>
using brook_uint_8_t = brook_t<uint8_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<int16_t>>
using brook_int_16_t = brook_t<int16_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<uint16_t>>
using brook_uint_16_t = brook_t<uint16_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<int32_t>>
using brook_int_32_t = brook_t<int32_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<uint32_t>>
using brook_uint_32_t = brook_t<uint32_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<int64_t>>
using brook_int_64_t = brook_t<int64_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<uint64_t>>
using brook_uint_64_t = brook_t<uint64_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<float>>
using brook_float_32_t = brook_t<float, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<double>>
using brook_float_64_t = brook_t<double, _concurrent_, ___ego___>;

class ___brook_t_share___
{
	static inline bool ___share___()
	{
		return brook_int_8_t<>::___share___
			&& brook_uint_8_t<>::___share___
			&& brook_int_16_t<>::___share___
			&& brook_uint_16_t<>::___share___
			&& brook_int_32_t<>::___share___
			&& brook_uint_32_t<>::___share___
			&& brook_int_64_t<>::___share___
			&& brook_uint_64_t<>::___share___
			&& brook_float_32_t<>::___share___
			&& brook_float_64_t<>::___share___
			&& brook_int_8_t<true>::___share___
			&& brook_uint_8_t<true>::___share___
			&& brook_int_16_t<true>::___share___
			&& brook_uint_16_t<true>::___share___
			&& brook_int_32_t<true>::___share___
			&& brook_uint_32_t<true>::___share___
			&& brook_int_64_t<true>::___share___
			&& brook_uint_64_t<true>::___share___
			&& brook_float_32_t<true>::___share___
			&& brook_float_64_t<true>::___share___;
	}
};

} // namespace strange

#endif
