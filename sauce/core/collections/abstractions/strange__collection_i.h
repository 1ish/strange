#ifndef COM_ONEISH__STRANGE__COLLECTION_I_H
#define COM_ONEISH__STRANGE__COLLECTION_I_H

namespace strange
{
	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline var<range_a<element_d>> collection_c<base_d, key_d, value_d, element_d>::range() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->range(me);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline fit<forward_extractor_a<element_d>> collection_c<base_d, key_d, value_d, element_d>::begin() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->begin(me);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline fit<forward_extractor_a<element_d>> collection_c<base_d, key_d, value_d, element_d>::end() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->end(me);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline ptr<> collection_c<base_d, key_d, value_d, element_d>::read_lock() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->read_lock(me);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline bool collection_c<base_d, key_d, value_d, element_d>::has(key_d const& key) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->has(me, key);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline value_d collection_c<base_d, key_d, value_d, element_d>::at(key_d const& key) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->at(me, key);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline int64_t collection_c<base_d, key_d, value_d, element_d>::size() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->size(me);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline bool collection_c<base_d, key_d, value_d, element_d>::empty() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->empty(me);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline var<collection_a<key_d, value_d, element_d>> collection_c<base_d, key_d, value_d, element_d>::add(con<range_a<element_d>> const& range) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->add(me, range);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline var<collection_a<key_d, value_d, element_d>> collection_c<base_d, key_d, value_d, element_d>::subtract(con<range_a<element_d>> const& range) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->subtract(me, range);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline ptr<> collection_v<base_d, key_d, value_d, element_d>::write_lock() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->write_lock(me);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline void collection_v<base_d, key_d, value_d, element_d>::update(key_d const& key,
		value_d const& value) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.o->update(me, key, value);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline bool collection_v<base_d, key_d, value_d, element_d>::insert(key_d const& key,
		value_d const& value) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->insert(me, key, value);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline bool collection_v<base_d, key_d, value_d, element_d>::erase(key_d const& key) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->erase(me, key);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline void collection_v<base_d, key_d, value_d, element_d>::clear() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.o->clear(me);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline void collection_v<base_d, key_d, value_d, element_d>::push_front(element_d const& element) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.o->push_front(me, element);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline element_d collection_v<base_d, key_d, value_d, element_d>::pop_front() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->pop_front(me);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline void collection_v<base_d, key_d, value_d, element_d>::push_back(element_d const& element) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.o->push_back(me, element);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline element_d collection_v<base_d, key_d, value_d, element_d>::pop_back() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->pop_back(me);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline void collection_v<base_d, key_d, value_d, element_d>::self_assign(con<range_a<element_d>> const& range) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.o->self_assign(me, range);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline void collection_v<base_d, key_d, value_d, element_d>::self_add(con<range_a<element_d>> const& range) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.o->self_add(me, range);
	}

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	inline void collection_v<base_d, key_d, value_d, element_d>::self_subtract(con<range_a<element_d>> const& range) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.o->self_subtract(me, range);
	}
}

#endif
