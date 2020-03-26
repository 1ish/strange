#ifndef COM_ONEISH_STRANGE_LAKE_T_H
#define COM_ONEISH_STRANGE_LAKE_T_H

namespace strange
{

template <typename _primitive_, bool _concurrent_ = false, typename ___ego___ = lake_a<_primitive_>>
class lake_t : public thing_t<___ego___>
{
	template <typename _element, typename _iterator_, typename ___ego_it___ = random_access_mutator_data_a<_element, _iterator_>>
	class mutator_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline random_access_mutator_data_a<_element, _iterator_> create(lake_t const& lake_thing, F&& it)
		{
			return random_access_mutator_data_a<_element, _iterator_>::template create<mutator_t<_element, _iterator_>>(lake_thing, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::lake::mutator");
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
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
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
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			return num(*_it);
		}

		inline _element set_(_element const& thing) const
		{
			if (!check<number_a<>>(thing))
			{
				throw dis("strange::lake::mutator set passed non-number");
			}
			typename concurrent_u<_concurrent_>::write_lock lock(_lake_thing._mutex);
			*_it = number_u<_primitive_>::from_number(fast<number_a<>>(thing));
			return thing;
		}

		inline _element* operator->() const
		{
			return &operator*();
		}

		inline _element& operator*() const
		{
			_lake_thing._shadow.resize(_lake_thing._vector.size());
			auto& number = _lake_thing._shadow[_it - _lake_thing._vector.begin()];
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
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			++_it;
		}

		// bidirectional mutator
		inline void decrement_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			--_it;
		}

		// random access mutator
		inline void self_add_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			_it += number.to_int_64();
		}

		inline random_access_mutator_a<_element> add_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			result.mutate_it() += number.to_int_64();
			return result;
		}

		inline void self_subtract_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			_it -= number.to_int_64();
		}

		inline random_access_mutator_a<_element> subtract_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
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
		lake_t const& _lake_thing;

		friend class any_a<>;

		template <typename F>
		inline mutator_t(lake_t const& lake_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _lake_thing{ lake_thing }
		{}
	};

	template <typename _element, typename _iterator_, typename ___ego_it___ = random_access_extractor_data_a<_element, _iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline random_access_extractor_data_a<_element, _iterator_> create(lake_a<_primitive_> const& lake, lake_t const& lake_thing, F&& it)
		{
			return random_access_extractor_data_a<_element, _iterator_>::template create<extractor_t<_element, _iterator_>>(lake, lake_thing, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::lake::extractor");
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
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
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
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			return num(*_it);
		}

		inline _element const* operator->() const
		{
			return &operator*();
		}

		inline _element const& operator*() const
		{
			_lake_thing._shadow.resize(_lake_thing._vector.size());
			auto& number = _lake_thing._shadow[_it - _lake_thing._vector.cbegin()];
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
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			++_it;
		}

		// bidirectional mutator
		inline void decrement_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			--_it;
		}

		// random access mutator
		inline void self_add_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			_it += number.to_int_64();
		}

		inline random_access_extractor_a<_element> add_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			result.mutate_it() += number.to_int_64();
			return result;
		}

		inline void self_subtract_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
			_it -= number.to_int_64();
		}

		inline random_access_extractor_a<_element> subtract_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_lake_thing._mutex);
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
		lake_a<_primitive_> const _lake;
		lake_t const& _lake_thing;

		friend class any_a<>;

		template <typename F>
		inline extractor_t(lake_a<_primitive_> const& lake, lake_t const& lake_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _lake{ lake }
			, _lake_thing{ lake_thing }
		{}
	};

public:
	using std_vector_number = std::vector<_primitive_>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return create_() += range;
	}

	static inline lake_a<_primitive_> create_()
	{
		return create(std_vector_number{});
	}

	template <typename... Args>
	static inline lake_a<_primitive_> create_(Args&&... args)
	{
		return create(variadic_u<_primitive_>::vector(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline lake_a<_primitive_> create_refs_(Args&&... args)
	{
		return create(variadic_u<_primitive_>::vector_ref(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline lake_a<_primitive_> create_dups_(Args&&... args)
	{
		return create(variadic_u<_primitive_>::vector_dup(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline lake_a<_primitive_> create(F&& init)
	{
		return lake_a<_primitive_>::template create<lake_t<_primitive_, _concurrent_>>(std::forward<F>(init));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::lake_" + number_u<_primitive_>::category() +
			(_concurrent_ ? "_concurrent" : ""));
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type_().to_string() + "::create", native_function_create(&lake_t<_primitive_, _concurrent_>::create__));
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		if (!check<lake_a<_primitive_>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector == fast<lake_a<_primitive_>>(thing).extract_vector();
	}

	inline bool operator==(lake_a<_primitive_> const& lake) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector == fast<lake_a<_primitive_>>(lake).extract_vector();
	}

	inline bool operator!=(lake_a<_primitive_> const& lake) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector != fast<lake_a<_primitive_>>(lake).extract_vector();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std::size_t hash() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std::size_t seed = std::hash<std::size_t>{}(_vector.size());
		for (auto item : _vector)
		{
			seed ^= std::hash<_primitive_>{}(item) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	inline bool less_than_(any_a<> const& thing) const
	{
		if (!check<lake_a<_primitive_>>(thing))
		{
			return one_t::less_than_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector < fast<lake_a<_primitive_>>(thing).extract_vector();
	}

	inline bool operator<(lake_a<_primitive_> const& lake) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector < lake.extract_vector();
	}

	inline bool greater_than_(any_a<> const& thing) const
	{
		if (!check<lake_a<_primitive_>>(thing))
		{
			return one_t::greater_than_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector > fast<lake_a<_primitive_>>(thing).extract_vector();
	}

	inline bool operator>(lake_a<_primitive_> const& lake) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector > lake.extract_vector();
	}

	inline bool less_or_equal_(any_a<> const& thing) const
	{
		if (!check<lake_a<_primitive_>>(thing))
		{
			return one_t::less_or_equal_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector <= fast<lake_a<_primitive_>>(thing).extract_vector();
	}

	inline bool operator<=(lake_a<_primitive_> const& lake) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector <= lake.extract_vector();
	}

	inline bool greater_or_equal_(any_a<> const& thing) const
	{
		if (!check<lake_a<_primitive_>>(thing))
		{
			return one_t::greater_or_equal_(thing);
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector >= fast<lake_a<_primitive_>>(thing).extract_vector();
	}

	inline bool operator>=(lake_a<_primitive_> const& lake) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector >= lake.extract_vector();
	}

	// range
	inline random_access_extractor_a<any_a<>> extract_begin_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_vector_number::const_iterator>::create(thing_t<___ego___>::me_(), *this, _vector.cbegin());
	}

	inline random_access_extractor_data_a<any_a<>, typename std_vector_number::const_iterator> extract_begin() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_vector_number::const_iterator>::create(thing_t<___ego___>::me_(), *this, _vector.cbegin());
	}

	inline random_access_extractor_a<any_a<>> extract_end_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_vector_number::const_iterator>::create(thing_t<___ego___>::me_(), *this, _vector.cend());
	}

	inline random_access_extractor_data_a<any_a<>, typename std_vector_number::const_iterator> extract_end() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<any_a<>, typename std_vector_number::const_iterator>::create(thing_t<___ego___>::me_(), *this, _vector.cend());
	}

	inline random_access_mutator_a<any_a<>> mutate_begin_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<any_a<>, typename std_vector_number::iterator>::create(*this, _vector.begin());
	}

	inline random_access_mutator_data_a<any_a<>, typename std_vector_number::iterator> mutate_begin()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<any_a<>, typename std_vector_number::iterator>::create(*this, _vector.begin());
	}

	inline random_access_mutator_a<any_a<>> mutate_end_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<any_a<>, typename std_vector_number::iterator>::create(*this, _vector.end());
	}

	inline random_access_mutator_data_a<any_a<>, typename std_vector_number::iterator> mutate_end()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<any_a<>, typename std_vector_number::iterator>::create(*this, _vector.end());
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
		return at_index(-1);
	}

	inline any_a<> at_index(int64_t index) const
	{
		return num(pat(index));
	}

	inline _primitive_ pat(int64_t index) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		if (index >= 0 && index < int64_t(_vector.size()))
		{
			return _vector[std::size_t(index)];
		}
		return _primitive_{};
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
		if (!check<number_a<>>(value))
		{
			throw dis("strange::lake::update passed non-number value");
		}
		return pupdate(index, number_u<_primitive_>::from_number(fast<number_a<>>(value)));
	}

	inline void pupdate(int64_t index, _primitive_ number)
	{
		if (index >= 0)
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			int64_t const siz = int64_t(_vector.size());
			if (index == siz)
			{
				_vector.push_back(number);
			}
			else
			{
				if (index > siz)
				{
					_vector.resize(std::size_t(index) + 1, no());
				}
				_vector[std::size_t(index)] = number;
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
		if (!check<number_a<>>(value))
		{
			throw dis("strange::lake::insert passed non-number value");
		}
		return pinsert(index, number_u<_primitive_>::from_number(fast<number_a<>>(value)));
	}

	inline bool pinsert(int64_t index, _primitive_ number)
	{
		if (index >= 0)
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			int64_t const siz = int64_t(_vector.size());
			if (index == siz)
			{
				_vector.push_back(number);
			}
			else
			{
				if (index > siz)
				{
					_vector.resize(std::size_t(index) + 1, no());
					_vector[std::size_t(index)] = number;
				}
				else
				{
					_vector.insert(_vector.cbegin() + index, number);
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
		if (index >= 0 && index < int64_t(_vector.size()))
		{
			_vector.erase(_vector.cbegin() + index);
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
		_vector.clear();
	}

	inline number_data_a<int64_t> size_() const
	{
		return num(size());
	}

	inline int64_t size() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return int64_t(_vector.size());
	}

	inline any_a<> empty_() const
	{
		return boole(empty());
	}

	inline bool empty() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _vector.empty();
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

	inline void push_front(_primitive_ number)
	{
		push_back(number);
	}

	inline any_a<> pop_front_()
	{
		return pop_back_();
	}

	inline _primitive_ pop_front()
	{
		return pop_back();
	}

	inline ___ego___ push_back_(any_a<> const& value)
	{
		push_back(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_back(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::lake::push_back passed non-number");
		}
		push_back(number_u<_primitive_>::from_number(fast<number_a<>>(thing)));
	}

	inline void push_back(_primitive_ number)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_vector.push_back(number);
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (_vector.empty())
		{
			return no();
		}
		_primitive_ number = _vector.back();
		_vector.pop_back();
		return num(number);
	}

	inline _primitive_ pop_back()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_primitive_ number = _vector.back();
		_vector.pop_back();
		return number;
	}

	inline void self_assign_(range_a<> const& range)
	{
		if (check<lake_a<_primitive_>>(range))
		{
			auto const other = fast<lake_a<_primitive_>>(range);
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
		if (check<lake_a<_primitive_>>(range))
		{
			auto const other = fast<lake_a<_primitive_>>(range);
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
	inline std_vector_number const& extract_vector() const
	{
		return _vector;
	}

	inline std_vector_number& mutate_vector()
	{
		return _vector;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_vector_number _vector;
	std::vector<number_data_a<_primitive_>> mutable _shadow;

	friend class any_a<>;

	template <typename F>
	inline lake_t(F&& init)
		: thing_t<___ego___>{}
		, _mutex{}
		, _vector{ std::forward<F>(init) }
		, _shadow{}
	{}

public:
	inline lake_t(lake_t const& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _vector{ other._vector }
		, _shadow{}
	{}

	inline lake_t(lake_t&& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _vector{ std::move(other._vector) }
		, _shadow{}
	{}

private:
	static bool const ___share___;
	friend class ___lake_t_share___;
};

template <typename _primitive_, bool _concurrent_, typename ___ego___>
bool const lake_t<_primitive_, _concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	lake_t<_primitive_, _concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

template <bool _concurrent_ = false, typename ___ego___ = lake_a<int8_t>>
using lake_int_8_t = lake_t<int8_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = lake_a<uint8_t>>
using lake_uint_8_t = lake_t<uint8_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = lake_a<int16_t>>
using lake_int_16_t = lake_t<int16_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = lake_a<uint16_t>>
using lake_uint_16_t = lake_t<uint16_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = lake_a<int32_t>>
using lake_int_32_t = lake_t<int32_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = lake_a<uint32_t>>
using lake_uint_32_t = lake_t<uint32_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = lake_a<int64_t>>
using lake_int_64_t = lake_t<int64_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = lake_a<uint64_t>>
using lake_uint_64_t = lake_t<uint64_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = lake_a<float>>
using lake_float_32_t = lake_t<float, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = lake_a<double>>
using lake_float_64_t = lake_t<double, _concurrent_, ___ego___>;

class ___lake_t_share___
{
	static inline bool ___share___()
	{
		return lake_int_8_t<>::___share___
			&& lake_uint_8_t<>::___share___
			&& lake_int_16_t<>::___share___
			&& lake_uint_16_t<>::___share___
			&& lake_int_32_t<>::___share___
			&& lake_uint_32_t<>::___share___
			&& lake_int_64_t<>::___share___
			&& lake_uint_64_t<>::___share___
			&& lake_float_32_t<>::___share___
			&& lake_float_64_t<>::___share___
			&& lake_int_8_t<true>::___share___
			&& lake_uint_8_t<true>::___share___
			&& lake_int_16_t<true>::___share___
			&& lake_uint_16_t<true>::___share___
			&& lake_int_32_t<true>::___share___
			&& lake_uint_32_t<true>::___share___
			&& lake_int_64_t<true>::___share___
			&& lake_uint_64_t<true>::___share___
			&& lake_float_32_t<true>::___share___
			&& lake_float_64_t<true>::___share___;
	}
};

inline lake_a<int8_t> lake_from_string(std::string const& str)
{
	return lake_int_8_t<>::create(lake_int_8_t<>::std_vector_number(str.cbegin(), str.cend()));
}

inline std::string lake_to_string(lake_a<int8_t> const& lake)
{
	auto const& v = lake.extract_vector();
	return std::string(v.cbegin(), v.cend());
}

template <typename F>
inline lake_a<int8_t> lake_int8_create(F&& init)
{
	return lake_int_8_t<>::create(std::forward<F>(init));
}

} // namespace strange

#endif
