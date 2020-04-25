#ifndef COM_ONEISH_STRANGE_PARCEL_T_H
#define COM_ONEISH_STRANGE_PARCEL_T_H

namespace strange
{

template <bool _concurrent_ = false, typename ___ego___ = container_data_a<dart_packet, dart_packet::iterator>>
class parcel_t : public thing_t<___ego___>
{
	template <typename _element_it, typename _iterator_, typename ___ego_it___ = bidirectional_extractor_data_a<_element_it, _iterator_>>
	class key_extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline bidirectional_extractor_data_a<_element_it, _iterator_> create(container_a<> const& container, parcel_t const& parcel_thing, F&& it)
		{
			return bidirectional_extractor_data_a<_element_it, _iterator_>::template create<key_extractor_t<_element_it, _iterator_>>(container, parcel_thing, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::parcel::key_extractor");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<bidirectional_extractor_data_a<_element_it, _iterator_>>(thing) &&
				_it == fast<bidirectional_extractor_data_a<_element_it, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(bidirectional_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(bidirectional_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std_size_t hash() const
		{
			return std::hash<void const*>{}(_it->str());
		}

		// forward extractor
		inline _element_it get_() const
		{
			return sym(_it->str());
		}

		inline _element_it const* operator->() const
		{
			return &operator*();
		}

		inline _element_it const& operator*() const
		{
			_parcel_thing._shadow_keys.resize(_parcel_thing.size());
			_element_it& thing = _parcel_thing._shadow_keys[_pos];
			thing = get_();
			return thing;
		}

		inline void increment_()
		{
			++_it;
			++_pos;
		}

		inline forward_extractor_a<any_a<>> to_extractor_any_() const
		{
			return bidirectional_extractor_data_a<any_a<>, _iterator_>::template create<key_extractor_t<any_a<>, _iterator_>>(_container, _parcel_thing, _it, _pos);
		}

		// bidirectional extractor
		inline void decrement_()
		{
			--_it;
			--_pos;
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
		container_a<> const _container;
		parcel_t const& _parcel_thing;
		int64_t _pos;

		friend class any_a<>;

		template <typename F>
		inline key_extractor_t(container_a<> const& container, parcel_t const& parcel_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _container{ container }
			, _parcel_thing{ parcel_thing }
			, _pos{ _it == parcel_thing._packet.key_begin() ? 0 : parcel_thing.size() }
		{}

		template <typename F>
		inline key_extractor_t(container_a<> const& container, parcel_t const& parcel_thing, F&& it, int64_t pos)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _container{ container }
			, _parcel_thing{ parcel_thing }
			, _pos{ pos }
		{}
	};

	template <typename _element_it, typename _iterator_, typename ___ego_it___ = bidirectional_extractor_data_a<_element_it, _iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline bidirectional_extractor_data_a<_element_it, _iterator_> create(container_a<> const& container, parcel_t const& parcel_thing, F&& it)
		{
			return bidirectional_extractor_data_a<_element_it, _iterator_>::template create<extractor_t<_element_it, _iterator_>>(container, parcel_thing, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::parcel::extractor");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<bidirectional_extractor_data_a<_element_it, _iterator_>>(thing) &&
				_it == fast<bidirectional_extractor_data_a<_element_it, _iterator_>>(thing).extract_it();
		}

		inline bool operator==(bidirectional_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(bidirectional_extractor_data_a<_element_it, _iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std_size_t hash() const
		{
			dart_packet copy = *_it;
			return std::hash<void const*>{}(copy.finalize().get_bytes().data());
		}

		// forward extractor
		inline _element_it get_() const
		{
			return parcel_create(*_it);
		}

		inline _element_it const* operator->() const
		{
			return &operator*();
		}

		inline _element_it const& operator*() const
		{
			_parcel_thing._shadow_values.resize(_parcel_thing.size());
			_element_it& thing = _parcel_thing._shadow_values[_pos];
			thing = get_();
			return thing;
		}

		inline void increment_()
		{
			++_it;
			++_pos;
		}

		inline forward_extractor_a<any_a<>> to_extractor_any_() const
		{
			return bidirectional_extractor_data_a<any_a<>, _iterator_>::template create<extractor_t<any_a<>, _iterator_>>(_container, _parcel_thing, _it, _pos);
		}

		// bidirectional extractor
		inline void decrement_()
		{
			--_it;
			--_pos;
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
		container_a<> const _container;
		parcel_t const& _parcel_thing;
		int64_t _pos;

		friend class any_a<>;

		template <typename F>
		inline extractor_t(container_a<> const& container, parcel_t const& parcel_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _container{ container }
			, _parcel_thing{ parcel_thing }
			, _pos{ _it == parcel_thing._packet.cbegin() ? 0 : parcel_thing.size() }
		{}

		template <typename F>
		inline extractor_t(container_a<> const& container, parcel_t const& parcel_thing, F&& it, int64_t pos)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _container{ container }
			, _parcel_thing{ parcel_thing }
			, _pos{ pos }
		{}
	};

public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		auto result = create_();
		if (check<range_a<container_a<>>>(list))
		{
			result += fast<range_a<container_a<>>>(list);
		}
		else
		{
			for (auto const& thing : list)
			{
				auto container = create_();
				thing.pack_(container);
				result.push_back(container);
			}
		}
		return result;
	}

	static inline container_data_a<dart_packet, dart_packet::iterator> create_()
	{
		return create(dart_packet::make_null());
	}
/*
	static inline container_data_a<dart_packet, dart_packet::iterator> create_null_()
	{
		return create(dart_packet::make_null());
	}

	static inline container_data_a<dart_packet, dart_packet::iterator> create_boolean_(any_a<> const& thing)
	{
		return create(dart_packet::make_boolean(bool{ thing }));
	}

	static inline container_data_a<dart_packet, dart_packet::iterator> create_number_(number_a<> const& number)
	{
		if (number.is_int())
		{
			return create(dart_packet::make_integer(number.to_int_64()));
		}
		return create(dart_packet::make_decimal(number.to_float_64()));
	}

	static inline container_data_a<dart_packet, dart_packet::iterator> create_int_64_(number_data_a<int64_t> const& number)
	{
		return create(dart_packet::make_integer(number.extract_primitive()));
	}

	static inline container_data_a<dart_packet, dart_packet::iterator> create_float_64_(number_data_a<double> const& number)
	{
		return create(dart_packet::make_decimal(number.extract_primitive()));
	}

	static inline container_data_a<dart_packet, dart_packet::iterator> create_lake_(lake_a<int8_t> const& lake)
	{
		return create(dart_packet::make_string(lake_to_string(lake)));
	}

	static inline container_data_a<dart_packet, dart_packet::iterator> create_symbol_(symbol_a<> const& symbol)
	{
		return create(dart_packet::make_string(symbol.to_string()));
	}

	template <typename... Args>
	static inline container_data_a<dart_packet, dart_packet::iterator> create_inventory_(Args&&... args)
	{
		return create(dart_packet::make_array(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline container_data_a<dart_packet, dart_packet::iterator> create_shoal_(Args&&... args)
	{
		return create(dart_packet::make_object(std::forward<Args>(args)...));
	}
*/
	template <typename F>
	static inline container_data_a<dart_packet, dart_packet::iterator> create(F&& init)
	{
		return container_data_a<dart_packet, dart_packet::iterator>::template create<parcel_t<_concurrent_>>(std::forward<F>(init));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::parcel" + 
			std_string{ _concurrent_ ? "_concurrent" : "" });
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym(type_().to_string() + "::create"), native_function_create(&parcel_t<_concurrent_>::create__));
	}

	// visitor pattern
	inline any_a<> visit_(inventory_a<>& inventory) const
	{
		auto result = thing_t<>::visit_(inventory);
		if (result)
		{
			auto last = inventory.size() - 1;
			typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
			for (auto const& packet : _packet)
			{
				auto visited = create(packet);
				inventory.update_index(last, visited);
				visited.visit_(inventory);
			}
		}
		return result;
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		if (!check<container_data_a<dart_packet, dart_packet::iterator>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _packet == fast<container_data_a<dart_packet, dart_packet::iterator>>(thing).extract_packet();
	}

	inline bool operator==(container_data_a<dart_packet, dart_packet::iterator> const& parcel) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _packet == parcel.extract_packet();
	}

	inline bool operator!=(container_data_a<dart_packet, dart_packet::iterator> const& parcel) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _packet != parcel.extract_packet();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std_size_t hash() const
	{
		dart_packet copy = _packet;
		auto bytes = copy.finalize().get_bytes();
		return std::hash<std_string>{}(std_string{ reinterpret_cast<char const*>(bytes.data()), bytes.size() });
	}

	// list
	inline forward_extractor_a<any_a<>> begin_() const
	{
		return extractor_t<any_a<>, typename dart_packet::iterator>::create(thing_t<___ego___>::me_(), *this, _packet.cbegin());
	}

	inline forward_extractor_a<any_a<>> end_() const
	{
		return extractor_t<any_a<>, typename dart_packet::iterator>::create(thing_t<___ego___>::me_(), *this, _packet.cend());
	}

	// range
	inline bidirectional_extractor_a<any_a<>> keys_begin_() const
	{
		return key_extractor_t<any_a<>, typename dart_packet::iterator>::create(thing_t<___ego___>::me_(), *this, _packet.key_begin());
	}

	inline bidirectional_extractor_data_a<any_a<>, typename dart_packet::iterator> keys_begin() const
	{
		return key_extractor_t<any_a<>, typename dart_packet::iterator>::create(thing_t<___ego___>::me_(), *this, _packet.key_begin());
	}

	inline bidirectional_extractor_a<any_a<>> keys_end_() const
	{
		return key_extractor_t<any_a<>, typename dart_packet::iterator>::create(thing_t<___ego___>::me_(), *this, _packet.key_end());
	}

	inline bidirectional_extractor_data_a<any_a<>, typename dart_packet::iterator> keys_end() const
	{
		return key_extractor_t<any_a<>, typename dart_packet::iterator>::create(thing_t<___ego___>::me_(), *this, _packet.key_end());
	}

	inline bidirectional_extractor_a<container_a<>> extract_begin_() const
	{
		return extractor_t<container_a<>, typename dart_packet::iterator>::create(thing_t<___ego___>::me_(), *this, _packet.cbegin());
	}

	inline bidirectional_extractor_data_a<container_a<>, typename dart_packet::iterator> extract_begin() const
	{
		return extractor_t<container_a<>, typename dart_packet::iterator>::create(thing_t<___ego___>::me_(), *this, _packet.cbegin());
	}

	inline bidirectional_extractor_a<container_a<>> extract_end_() const
	{
		return extractor_t<container_a<>, typename dart_packet::iterator>::create(thing_t<___ego___>::me_(), *this, _packet.cend());
	}

	inline bidirectional_extractor_data_a<container_a<>, typename dart_packet::iterator> extract_end() const
	{
		return extractor_t<container_a<>, typename dart_packet::iterator>::create(thing_t<___ego___>::me_(), *this, _packet.cend());
	}

	// collection / parcel
	inline any_a<> has_(any_a<> const& key) const
	{
		return boole(has(key));
	}

	inline bool has(any_a<> const& key) const
	{
		if (check<symbol_a<>>(key))
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
			return _packet.has_key(fast<symbol_a<>>(key).to_string());
		}
		if (check<number_a<>>(key))
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
			return fast<number_a<>>(key).to_uint_64() < _packet.size();
		}
		throw dis("strange::parcel::has passed wrong type of key");
	}

	inline container_a<> at_(any_a<> const& key) const
	{
		if (check<symbol_a<>>(key))
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
			return create(_packet.at(fast<symbol_a<>>(key).to_string()));
		}
		if (check<number_a<>>(key))
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
			return create(_packet.at(fast<number_a<>>(key).to_uint_64()));
		}
		throw dis("strange::parcel::at passed wrong type of key");
	}

	inline container_a<> update_(any_a<> const& key, container_a<> const& value)
	{
		update(key, value);
		return value;
	}

	inline void update(any_a<> const& key, container_a<> const& value)
	{
		if (!check<container_data_a<dart_packet, dart_packet::iterator>>(value))
		{
			throw dis("strange::parcel::update passed wrong type of value");
		}
		if (check<symbol_a<>>(key))
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			_packet.set(fast<symbol_a<>>(key).to_string(), fast<container_data_a<dart_packet, dart_packet::iterator>>(value).extract_packet());
		}
		if (check<number_a<>>(key))
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			_packet.set(fast<number_a<>>(key).to_uint_64(), fast<container_data_a<dart_packet, dart_packet::iterator>>(value).extract_packet());
		}
		throw dis("strange::parcel::update passed wrong type of key");
	}

	inline any_a<> insert_(any_a<> const& key, container_a<> const& value)
	{
		return boole(insert(key, value));
	}

	inline bool insert(any_a<> const& key, container_a<> const& value)
	{
		if (!check<container_data_a<dart_packet, dart_packet::iterator>>(value))
		{
			throw dis("strange::parcel::insert passed wrong type of value");
		}
		if (check<symbol_a<>>(key))
		{
			auto const key_string = fast<symbol_a<>>(key).to_string();
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			bool const result = !_packet.has_key(key_string);
			if (result)
			{
				_packet.insert(key_string, fast<container_data_a<dart_packet, dart_packet::iterator>>(value).extract_packet());
			}
			return result;
		}
		if (check<number_a<>>(key))
		{
			auto const index = fast<number_a<>>(key).to_uint_64();
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			bool const result = index <= _packet.size();
			if (result)
			{
				_packet.insert(index, fast<container_data_a<dart_packet, dart_packet::iterator>>(value).extract_packet());
			}
			return result;
		}
		throw dis("strange::parcel::insert passed wrong type of key");
	}

	inline any_a<> erase_(any_a<> const& key)
	{
		return boole(erase(key));
	}

	inline bool erase(any_a<> const& key)
	{
		if (check<symbol_a<>>(key))
		{
			auto const key_string = fast<symbol_a<>>(key).to_string();
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			bool const result = _packet.has_key(key_string);
			if (result)
			{
				_packet.erase(key_string);
			}
			return result;
		}
		if (check<number_a<>>(key))
		{
			auto const index = fast<number_a<>>(key).to_uint_64();
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			bool const result = index < _packet.size();
			if (result)
			{
				_packet.erase(index);
			}
			return result;
		}
		throw dis("strange::parcel::erase passed wrong type of key");
	}

	inline ___ego___ clear_()
	{
		clear();
		return thing_t<___ego___>::me_();
	}

	inline void clear()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_packet.clear();
	}

	inline number_data_a<int64_t> size_() const
	{
		return num(size());
	}

	inline int64_t size() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return int64_t(_packet.size());
	}

	inline any_a<> empty_() const
	{
		return boole(empty());
	}

	inline bool empty() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _packet.empty();
	}

	inline ___ego___ push_front_(container_a<> const& value)
	{
		push_front(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_front(container_a<> const& thing)
	{
		if (!check<container_data_a<dart_packet, dart_packet::iterator>>(thing))
		{
			throw dis("strange::parcel::push_front passed wrong type of thing");
		}
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_packet.push_front(fast<container_data_a<dart_packet, dart_packet::iterator>>(thing).extract_packet());
	}

	inline container_a<> pop_front_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		container_a<> result = create(_packet.front());
		_packet.pop_front();
		return result;
	}

	inline ___ego___ push_back_(container_a<> const& value)
	{
		push_back(value);
		return thing_t<___ego___>::me_();
	}

	inline void push_back(container_a<> const& thing)
	{
		if (!check<container_data_a<dart_packet, dart_packet::iterator>>(thing))
		{
			throw dis("strange::parcel::push_back passed wrong type of thing");
		}
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_packet.push_back(fast<container_data_a<dart_packet, dart_packet::iterator>>(thing).extract_packet());
	}

	inline container_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		container_a<> result = create(_packet.back());
		_packet.pop_back();
		return result;
	}

	inline void self_assign_(range_a<container_a<>> const& range)
	{
		if (check<container_data_a<dart_packet, dart_packet::iterator>>(range))
		{
			auto const other = fast<container_data_a<dart_packet, dart_packet::iterator>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_packet = other.extract_packet();
		}
		else
		{
			auto read_lock = check<collection_a<container_a<>>>(range) ? fast<collection_a<container_a<>>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_packet.clear();
			for (auto const& thing : range)
			{
				if (!check<container_data_a<dart_packet, dart_packet::iterator>>(thing))
				{
					throw dis("strange::parcel::self_assign passed wrong type of thing");
				}
				_packet.push_back(fast<container_data_a<dart_packet, dart_packet::iterator>>(thing).extract_packet());
			}
		}
	}

	inline void self_add_(range_a<container_a<>> const& range)
	{
		if (check<container_data_a<dart_packet, dart_packet::iterator>>(range))
		{
			auto const other = fast<container_data_a<dart_packet, dart_packet::iterator>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_packet = other.extract_packet();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& packet : other_packet)
			{
				_packet.push_back(packet);
			}
		}
		else
		{
			auto read_lock = check<collection_a<container_a<>>>(range) ? fast<collection_a<container_a<>>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				if (!check<container_data_a<dart_packet, dart_packet::iterator>>(thing))
				{
					throw dis("strange::parcel::self_add passed wrong type of thing");
				}
				_packet.push_back(fast<container_data_a<dart_packet, dart_packet::iterator>>(thing).extract_packet());
			}
		}
	}

	inline ___ego___ add_(range_a<container_a<>> const& range) const
	{
		auto result = thing_t<___ego___>::me_();
		result += range;
		return result;
	}

	inline void self_subtract_(range_a<container_a<>> const& range)
	{
		if (check<container_data_a<dart_packet, dart_packet::iterator>>(range))
		{
			auto const other = fast<container_data_a<dart_packet, dart_packet::iterator>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_packet = other.extract_packet();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& packet : other_packet)
			{
				_packet.erase(packet);
			}
		}
		else
		{
			auto read_lock = check<collection_a<container_a<>>>(range) ? fast<collection_a<container_a<>>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				if (!check<container_data_a<dart_packet, dart_packet::iterator>>(thing))
				{
					throw dis("strange::parcel::self_subtract passed wrong type of thing");
				}
				_packet.erase(fast<container_data_a<dart_packet, dart_packet::iterator>>(thing).extract_packet());
			}
		}
	}

	inline ___ego___ subtract_(range_a<container_a<>> const& range) const
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

	// container
	inline any_a<> unpack_(shoal_a<> const& shared_shoal) const
	{
		auto no_shoal = no();
		return unpack(shared_shoal, no_shoal);
	}

	inline any_a<> unpack_unique_(shoal_a<> const& shared_shoal, shoal_a<number_data_a<uint64_t>, any_a<>>& unique_shoal) const
	{
		return unpack(shared_shoal, unique_shoal);
	}

	inline any_a<> unpack(shoal_a<> const& shared_shoal, any_a<>& unique_shoal) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		switch (_packet.get_type())
		{
		case dart_packet::type::array:
		{
			auto it = _packet.cbegin();
			auto end = _packet.cend();
			if (it == end || !it->is_boolean())
			{
				break;
			}
			auto unique = it->boolean();
			if (++it == end)
			{
				throw dis("strange::parcel::unpack called for array with initial boolean and nothing else");
			}
			number_data_a<uint64_t> id;
			if (unique)
			{
				if (!it->is_integer())
				{
					throw dis("strange::parcel::unpack called for array with unique true but no reference id");
				}
				id = num(static_cast<uint64_t>(it->integer()));
				if (++it == end)
				{
					if (!check<shoal_a<number_data_a<uint64_t>, any_a<>>>(unique_shoal))
					{
						throw dis("strange::parcel::unpack called for array with reference id but no shoal");
					}
					auto shoal = fast<shoal_a<number_data_a<uint64_t>, any_a<>>>(unique_shoal);
					if (!shoal.has(id))
					{
						throw dis("strange::parcel::unpack called for array with unknown reference id");
					}
					return shoal.at_(id);
				}
			}
			if (!it->is_str())
			{
				throw dis("strange::parcel::unpack called for array with no name");
			}
			auto name = sym(it->str());
			auto function = shared_shoal.at_(name);
			if (!function)
			{
				throw dis("strange::parcel::unpack called for array with unrecognised function name: " + name.to_string());
			}
			auto flock = flock_t<>::create_();
			int64_t const remaining = _packet.size() - (unique ? 3 : 2);
			if (remaining)
			{
				auto& vector = flock.mutate_vector();
				vector.reserve(remaining);
				while (++it != end)
				{
					vector.push_back(create(*it).unpack(shared_shoal, unique_shoal));
				}
			}
			auto result = function.operate(function, flock);
			if (unique && 
				check<shoal_a<number_data_a<uint64_t>, any_a<>>>(unique_shoal) &&
				!fast<shoal_a<number_data_a<uint64_t>, any_a<>>>(unique_shoal).insert(id, result))
			{
				throw dis("strange::parcel::unpack called for array with duplicate reference id");
			}
			return result;
		}
		case dart_packet::type::boolean:
		{
			bool const boolean = _packet.boolean();
			if (boolean == bool{ unique_shoal })
			{
				return unique_shoal;
			}
			return boole(boolean);
		}
		case dart_packet::type::decimal:
			return num(_packet.decimal());
		case dart_packet::type::integer:
			return num(_packet.integer());
		case dart_packet::type::null:
			return any_a<>{};
		case dart_packet::type::string:
			return sym(_packet.str());
		default:
			break;
		}
		return thing_t<___ego___>::me_();
	}

	inline any_a<> close_()
	{
		typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
		if (!_packet.is_finalized())
		{
			_packet.finalize();
			return yes();
		}
		return no();
	}

	inline any_a<> closed_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return boole(_packet.is_finalized());
	}

	inline any_a<> reopen_()
	{
		typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
		if (_packet.is_finalized())
		{
			_packet.definalize();
			return yes();
		}
		return no();
	}

	inline container_a<> from_json_(lake_int8_a<> const& lake)
	{
		from_json(lake_to_string(lake));
		return thing_t<___ego___>::me_();
	}

	inline void from_json(std_string const& str)
	{
		throw dis("strange::parcel::from_json requires sajson"); //TODO
		/*
		auto packet = dart_packet::from_json(str);
		typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
		_packet = packet;
		*/
	}

	inline lake_int8_a<> to_json_() const
	{
		return lake_from_string(to_json());
	}

	inline std_string to_json() const
	{
		throw dis("strange::parcel::to_json requires rapidjson"); //TODO
		/*
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _packet.to_json();
		*/
	}

	inline container_a<> from_binary_(lake_int8_a<> const& lake)
	{
		auto packet = dart_packet_from_vector(lake.extract_vector());
		typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
		_packet = packet;
		return thing_t<___ego___>::me_();
	}

	inline void from_binary(std_string const& str)
	{
		auto packet = dart_packet_from_string(str);
		typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
		_packet = packet;
	}

	inline lake_int8_a<> to_binary_() const
	{
		return lake_from_string(to_binary());
	}

	inline std_string to_binary() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		if (!_packet.is_finalized())
		{
			throw dis("strange::parcel::to_binary called on parcel that has not been closed");
		}
		auto buffer = _packet.get_bytes();
		return std_string(reinterpret_cast<char const*>(buffer.data()), buffer.size());
	}

	// data
	inline dart_packet const& extract_packet() const
	{
		return _packet;
	}

	inline dart_packet& mutate_packet()
	{
		return _packet;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	dart_packet _packet;
	std_vector<any_a<>> mutable _shadow_keys;
	std_vector<container_a<>> mutable _shadow_values;

	friend class any_a<>;

	template <typename F>
	inline parcel_t(F&& init)
		: thing_t<___ego___>{}
		, _mutex{}
		, _packet{ std::forward<F>(init) }
		, _shadow_keys{}
		, _shadow_values{}
	{}

public:
	inline parcel_t(parcel_t const& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _packet{ other._packet }
		, _shadow_keys{}
		, _shadow_values{}
	{}

	inline parcel_t(parcel_t&& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _packet{ std::move(other._packet) }
		, _shadow_keys{}
		, _shadow_values{}
	{}

private:
	static bool const ___share___;
	friend class ___parcel_t_share___;
};

template <bool _concurrent_, typename ___ego___>
bool const parcel_t<_concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	parcel_t<_concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

class ___parcel_t_share___
{
	static inline bool ___share___()
	{
		return parcel_t<>::___share___
			&& parcel_t<true>::___share___;
	}
};

// template <bool _concurrent_ = false>
template <bool _concurrent_>
inline container_data_a<dart_packet, dart_packet::iterator> parcel_create()
{
	return parcel_t<_concurrent_>::create_();
}

template <typename F>
inline container_data_a<dart_packet, dart_packet::iterator> parcel_create(F&& init)
{
	return parcel_t<>::create(std::forward<F>(init));
}

} // namespace strange

#endif
