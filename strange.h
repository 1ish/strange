#ifndef COM_ONEISH_STRANGE_H
#define COM_ONEISH_STRANGE_H

#include <memory>
#include <cstring>
#include <iostream>
#include <atomic>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstdint>
#include <type_traits>

namespace strange
{
	// Categories:
	// private typedefs
	// protected typedefs
	// public typedefs
	// public static utility functions
	// public static factory functions
	// public static symbols
	// public construction/destruction/assignment
	// public pure virtual member functions and adapters
	// public impure virtual member functions and adapters
	// public non-virtual member functions and adapters
	// protected static utility functions
	// protected static factory functions
	// protected static symbols
	// protected construction/destruction/assignment
	// protected pure virtual member functions and adapters
	// protected impure virtual member functions and adapters
	// protected non-virtual member functions and adapters
	// private static utility functions
	// private static factory functions
	// private static symbols
	// private construction/destruction/assignment
	// private pure virtual member functions and adapters
	// private impure virtual member functions and adapters
	// private non-virtual member functions and adapters

class Thing
{
public:
	// public typedefs
	using Ptr = std::shared_ptr<Thing>;
	using Weak = std::weak_ptr<Thing>;

	// public static utility functions
	template <typename T>
	static inline T* const static_(const Ptr ptr)
	{
		return static_cast<T*>(ptr.get());
	}

	template <typename T>
	static inline T* const dynamic_(const Ptr ptr)
	{
		return dynamic_cast<T*>(ptr.get());
	}

	static inline const Ptr boolean_(const bool value)
	{
		return value ? one_() : nothing_();
	}

	static inline const Ptr boolean_(const Ptr ptr)
	{
		return boolean_(!ptr->is_("0"));
	}

	static inline const Ptr boolean(const Ptr it)
	{
		return boolean_(it->next_());
	}

	template <typename F>
	static inline void log_(F&& message)
	{
		std::cout << std::forward<F>(message);
	}

	static inline void log_(const Ptr ptr);

	static inline const Ptr log(const Ptr it)
	{
		log_(it->next_());
		return nothing_();
	}

	// public static factory functions
	static inline const Ptr factory_();

	static inline const Ptr factory(const Ptr ignore)
	{
		return factory_();
	}

	virtual inline const Ptr pub_() const;

	inline const Ptr pub(const Ptr ignore) const
	{
		return pub_();
	}

	template <typename F>
	static inline const Ptr sym_(F&& symbol);

	// public static symbols
	static inline const Ptr nothing_();

	static inline const Ptr nothing(const Ptr ignore)
	{
		return nothing_();
	}

	static inline const Ptr one_();

	static inline const Ptr one(const Ptr ignore)
	{
		return one_();
	}

	static inline const Ptr end_();

	static inline const Ptr end(const Ptr ignore)
	{
		return end_();
	}

	// public construction/destruction/assignment
	Thing(const Thing&) = delete;

	Thing& operator=(const Thing& thing) = delete;

	virtual ~Thing() = default;

	// public pure virtual member functions and adapters
	virtual inline const Ptr type_() const = 0;

	inline const Ptr type(const Ptr ignore) const
	{
		return type_();
	}

	virtual inline const Ptr copy_() const = 0;

	inline const Ptr copy(const Ptr ignore) const
	{
		return copy_();
	}

	// public impure virtual member functions and adapters
	virtual inline const Ptr clone_() const
	{
		return copy_();
	}

	inline const Ptr clone(const Ptr ignore) const
	{
		return clone_();
	}

	virtual inline void finalize_()
	{
	}

	inline const Ptr finalize(const Ptr ignore)
	{
		finalize_();
		return nothing_();
	}

	virtual inline const bool finalized_() const
	{
		return true;
	}

	inline const Ptr finalized(const Ptr ignore) const
	{
		return boolean_(finalized_());
	}

	virtual inline void freeze_()
	{
		finalize_();
	}

	inline const Ptr freeze(const Ptr ignore)
	{
		freeze_();
		return nothing_();
	}

	virtual inline const Ptr next_()
	{
		return end_();
	}

	inline const Ptr next(const Ptr ignore)
	{
		return next_();
	}

	virtual inline size_t hash_() const
	{
		return std::hash<const Thing*>{}(this);
	}

	inline const Ptr hash(const Ptr ignore) const;

	virtual inline const bool same_(const Ptr other) const
	{
		return (this == other.get());
	}

	inline const Ptr same(const Ptr it) const
	{
		return boolean_(same_(it->next_()));
	}

	virtual inline const Ptr visit(const Ptr it)
	{
		const Ptr visitor = it->next_();
		visitor->thing(it);
		return visitor;
	}

	virtual inline const Ptr cats_() const;

	inline const Ptr cats(const Ptr ignore) const
	{
		return cats_();
	}

	// public non-virtual member functions and adapters
	template <typename... Args>
	inline const Ptr call_(Args&&... args)
	{
		std::vector<Ptr> v;
		v.reserve(sizeof...(Args));
		Variadic::variadic_(v, std::forward<Args>(args)...);
		return thing(Iterator<std::vector<Ptr>>::mut_(std::move(v)));
	}

	inline const Ptr thing(const Ptr it)
	{
		return operator()(this, it);
	}

	template <typename F>
	inline const bool is_(F&& symbol) const;

	inline const bool is_(const Ptr symbol) const;

	inline const Ptr is(const Ptr it) const
	{
		return boolean_(is_(it->next_()));
	}

protected:
	// protected static utility functions
	static inline const Ptr thing_(Thing* const thing, const Ptr member, const Ptr it)
	{
		return member->operator()(thing, it);
	}

	// protected construction/destruction/assignment
	Thing() = default;

	// protected impure virtual member functions and adapters
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it);
};

class Variadic
{
public:
	// public typedefs
	using Ptr = Thing::Ptr;

	// public static utility functions
	static inline void variadic_(std::vector<Ptr>& vec)
	{
	}

	template <typename... Args>
	static inline void variadic_(std::vector<Ptr>& vec, const std::string& symbol, Args&&... args)
	{
		vec.push_back(Thing::sym_(symbol));
		variadic_(vec, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_(std::vector<Ptr>& vec, Thing& thing, Args&&... args)
	{
		for (Ptr p = thing.next_(); !p->is_("end"); p = thing.next_())
		{
			vec.push_back(p);
		}
		variadic_(vec, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_(std::vector<Ptr>& vec, const Ptr ptr, Args&&... args)
	{
		vec.push_back(ptr);
		variadic_(vec, std::forward<Args>(args)...);
	}
};

template <typename T>
class Me
{
protected:
	Me() = default;

	template <typename... Args>
	static inline const Thing::Ptr make_(Args&&... args)
	{
		const Thing::Ptr result = std::make_shared<T>(std::forward<Args>(args)...);
		Thing::static_<T>(result)->_me = result;
		return result;
	}

	inline const Thing::Ptr me_() const
	{
		const Thing::Ptr ptr = _me.lock();
		if (ptr)
		{
			return ptr;
		}
		return Thing::nothing_();
	}

private:
	Thing::Weak _me;
};

class Serializable
{
public:
	// public pure virtual member functions and adapters
	virtual inline const Thing::Ptr to_buffer_() const = 0;

	inline const Thing::Ptr to_buffer(const Thing::Ptr ignore) const
	{
		return to_buffer_();
	}

	// public impure virtual member functions and adapters

	virtual inline void from_buffer_(const Thing::Ptr buffer)
	{
	}

	inline const Thing::Ptr from_buffer(const Thing::Ptr it)
	{
		from_buffer_(it->next_());
		return Thing::nothing_();
	}

	virtual inline void to_stream_(const Thing::Ptr stream) const;

	inline const Thing::Ptr to_stream(const Thing::Ptr it) const
	{
		const Thing::Ptr stream = it->next_();
		to_stream_(stream);
		return stream;
	}

	virtual inline void from_stream_(const Thing::Ptr stream);

	inline const Thing::Ptr from_stream(const Thing::Ptr it)
	{
		const Thing::Ptr stream = it->next_();
		from_stream_(stream);
		return stream;
	}

	virtual inline void to_stream_with_links_(const Thing::Ptr index, const Thing::Ptr stream) const
	{
		to_stream_(stream);
	}

	static inline void serialize_(const Thing::Ptr thing, const Thing::Ptr stream);

	static inline const Thing::Ptr serialize(const Thing::Ptr it)
	{
		const Thing::Ptr thing = it->next_();
		const Thing::Ptr stream = it->next_();
		serialize_(thing, stream);
		return stream;
	}

	virtual inline void replace_links_(const Thing::Ptr index)
	{
	}

	static inline const Thing::Ptr deserialize_(const Thing::Ptr stream);

	static inline const Thing::Ptr deserialize(const Thing::Ptr it)
	{
		return deserialize_(it->next_());
	}

protected:
	// protected non-virtual member functions and adapters
	inline const Thing::Ptr to_buffer_via_stream_() const;

	inline void from_buffer_via_stream_(const Thing::Ptr buffer);
};

class Symbol : public Thing, public Me<Symbol>, public Serializable
{
public:
	template <typename F>
	inline Symbol(F&& symbol)
		: Me{}
		, _symbol{ std::forward<F>(symbol) }
		, _hash{ std::hash<std::string>()(_symbol) }
	{
	}

	virtual inline size_t hash_() const override
	{
		return _hash;
	}

	virtual inline const bool same_(const Ptr other) const override
	{
		return other->is_(_symbol);
	}

	inline const std::string& symbol_() const
	{
		return _symbol;
	}

	virtual inline const Ptr copy_() const override
	{
		return me_();
	}

	template <typename F>
	static inline const Ptr fin_(F&& symbol)
	{
		return make_(std::forward<F>(symbol));
	}

	static inline const Ptr buf_(const Ptr buffer);

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream);

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	virtual inline const Ptr to_buffer_() const override;

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Symbol");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		return me_();
	}

private:
	const std::string _symbol;
	const size_t _hash;
};

template <typename F>
inline const bool Thing::is_(F&& symbol) const
{
	const Symbol* const sym = dynamic_cast<const Symbol*>(this);
	return (sym && sym->symbol_() == std::forward<F>(symbol));
}

inline const bool Thing::is_(const Thing::Ptr symbol) const
{
	const Symbol* const sym = dynamic_<const Symbol>(symbol);
	return (sym && is_(sym->symbol_()));
}

template <typename F>
inline const Thing::Ptr Thing::sym_(F&& symbol)
{
	return Symbol::fin_(std::forward<F>(symbol));
}

inline const Thing::Ptr Thing::nothing_()
{
	static const Ptr NOTHING = sym_("0");
	return NOTHING;
}

inline const Thing::Ptr Thing::one_()
{
	static const Ptr ONE = sym_("1");
	return ONE;
}

inline const Thing::Ptr Thing::end_()
{
	static const Ptr END = sym_("end");
	return END;
}

class Static : public Thing, public Me<Static>
{
	using function = const Ptr(*)(const Ptr);

public:
	Static(const function fun)
		: Me{}
		, _function{ fun }
	{
	}

	static inline const Ptr fin_(const function fun)
	{
		return make_(fun);
	}

	virtual inline const Ptr copy_() const override
	{
		return me_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Static");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		return _function(it);
	}

private:
	const function _function;
};

template <typename T>
class Member : public Thing, public Me<Member<T>>
{
	using member = const Ptr(T::*)(const Ptr);

public:
	Member(const member fun)
		: Me<Member<T>>{}
		, _function{ fun }
	{
	}

	static inline const Ptr fin_(const member fun)
	{
		return make_(fun);
	}

	virtual inline const Ptr copy_() const override
	{
		return me_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Member");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		T* const t = dynamic_cast<T*>(thing);
		if (t)
		{
			if (t->finalized_())
			{
				log_("ERROR: Member passed finalized thing\n");
				return nothing_();
			}
			return (t->*_function)(it);
		}
		log_("ERROR: Member passed wrong type of thing\n");
		return nothing_();
	}

private:
	const member _function;
};

template <typename T>
class Const : public Thing, public Me<Const<T>>
{
	using member = const Ptr(T::*)(const Ptr) const;

public:
	Const(const member fun)
		: Me<Const<T>>{}
		, _function{ fun }
	{
	}

	static inline const Ptr fin_(const member fun)
	{
		return make_(fun);
	}

	virtual inline const Ptr copy_() const override
	{
		return me_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Const");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		T* const t = dynamic_cast<T*>(thing);
		if (t)
		{
			return (t->*_function)(it);
		}
		log_("ERROR: Const passed wrong type of thing\n");
		return nothing_();
	}

private:
	const member _function;
};

class Mutable : public Thing
{
public:
	virtual inline void finalize_() override
	{
		_finalized = true;
	}

	virtual inline const bool finalized_() const override
	{
		return _finalized;
	}

protected:
	inline Mutable()
		: Thing{}
		, _finalized{ false }
	{
	}

private:
	bool _finalized;
};

class Index : public Mutable, public Me<Index>, public Serializable
{
	class Hash
	{
	public:
		inline size_t operator()(const Ptr ptr) const
		{
			return ptr->hash_();
		}
	};

	class Pred
	{
	public:
		inline const bool operator()(const Ptr lhs, const Ptr rhs) const
		{
			return lhs->same_(rhs);
		}
	};

	using std_unordered_map_ptr_ptr = std::unordered_map<Ptr, Ptr, Hash, Pred>;

public:
	Index() = default;

	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_();
		static_<Index>(result)->_map = _map;
		return result;
	}

	virtual inline const Ptr clone_() const override
	{
		const Ptr result = mut_();
		std_unordered_map_ptr_ptr& clone = static_<Index>(result)->_map;
		for (const auto& i : _map)
		{
			clone[i.first->clone_()] = i.second->clone_();
		}
		return result;
	}

	virtual inline void freeze_() override
	{
		for (const auto& i : _map)
		{
			i.first->freeze_();
			i.second->freeze_();
		}
	}

	virtual inline const Ptr to_buffer_() const override
	{
		return to_buffer_via_stream_();
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		from_buffer_via_stream_(buffer);
	}

	virtual inline void to_stream_(const Thing::Ptr stream) const override;

	virtual inline void from_stream_(const Thing::Ptr stream) override;

	virtual inline void to_stream_with_links_(const Thing::Ptr index, const Thing::Ptr stream) const override;

	virtual inline void replace_links_(const Thing::Ptr index) override;

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("to_buffer", Const<Index>::fin_(&Index::to_buffer));
			index->update_("from_buffer", Member<Index>::fin_(&Index::from_buffer));
			index->update_("to_stream", Const<Index>::fin_(&Index::to_stream));
			index->update_("from_stream", Member<Index>::fin_(&Index::from_stream));
			index->update_("mut", Static::fin_(&Index::mut));
			index->update_("buf", Static::fin_(&Index::buf));
			index->update_("str", Static::fin_(&Index::str));
			index->update_("find", Const<Index>::fin_(&Index::find));
			index->update_("update", Member<Index>::fin_(&Index::update));
			index->update_("insert", Member<Index>::fin_(&Index::insert));
			index->update_("iterator", Const<Index>::fin_(&Index::iterator));
			index->update_("itemize", Member<Index>::fin_(&Index::itemize));
			index->update_("gather", Member<Index>::fin_(&Index::gather));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr mut_()
	{
		return make_();
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr buf_(const Ptr buffer)
	{
		const Ptr ptr = mut_();
		static_<Index>(ptr)->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream)
	{
		const Ptr ptr = mut_();
		static_<Index>(ptr)->from_stream_(stream);
		return ptr;
	}

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	template <typename F>
	inline const Ptr find_(F&& symbol) const
	{
		return find_(sym_(std::forward<F>(symbol)));
	}

	inline const Ptr find_(const Ptr key) const
	{
		const std_unordered_map_ptr_ptr::const_iterator mit = _map.find(key);
		if (mit == _map.cend())
		{
			return nothing_();
		}
		return mit->second;
	}

	inline const Ptr find(const Ptr it) const
	{
		return find_(it->next_());
	}

	template <typename F>
	inline void update_(F&& key, const Ptr value)
	{
		update_(sym_(std::forward<F>(key)), value);
	}

	inline void update_(const Ptr key, const Ptr value)
	{
		_map[key] = value;
	}

	inline const Ptr update(const Ptr it)
	{
		const Ptr key = it->next_();
		const Ptr value = it->next_();
		update_(key, value);
		return value;
	}

	template <typename F>
	inline const bool insert_(F&& key, const Ptr value)
	{
		return insert_(sym_(std::forward<F>(key)), value);
	}

	inline const bool insert_(const Ptr key, const Ptr value)
	{
		return _map.emplace(key, value).second;
	}

	inline const Ptr insert(const Ptr it)
	{
		const Ptr key = it->next_();
		const Ptr value = it->next_();
		return boolean_(insert_(key, value));
	}

	inline const Ptr iterator_() const
	{
		return It::mut_(me_());
	}

	inline const Ptr iterator(const Ptr ignore) const
	{
		return iterator_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Index");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

	virtual inline const Ptr visit(const Ptr it) override
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		const Ptr rest = it->copy_();
		if (visitor->call_(member, *it)->is_("0"))
		{
			return visitor;
		}
		rest->next_();
		for (const auto& visited : _map)
		{
			visited.first->call_("visit", visitor, member, visited.first, *(rest->copy_()));
			visited.second->call_("visit", visitor, member, visited.second, *(rest->copy_()));
		}
		return visitor;
	}

	inline const bool itemize_(const Ptr key)
	{
		const Ptr size = sym_(std::to_string(_map.size()));
		return insert_(key, size);
	}

	inline const Ptr itemize(const Ptr it)
	{
		return boolean_(itemize_(it->next_()));
	}

	inline const Ptr gather_(const Ptr item)
	{
		return item->call_("visit", me_(), "itemize", item);
	}

	inline const Ptr gather(const Ptr it)
	{
		return gather_(it->next_());
	}

	inline void gather_to_stream_(const Ptr thing, const Ptr stream);

	inline const Ptr gather_from_stream_(const Ptr stream);

private:
	std_unordered_map_ptr_ptr _map;

	class It : public Mutable
	{
	public:
		inline It(const Ptr index)
			: Mutable{}
			, _index{ index }
			, _iterator{ static_<Index>(_index)->_map.cbegin() }
		{
		}

		virtual inline const Ptr next_() override;

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_index);
			static_<It>(result)->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr index)
		{
			return std::make_shared<It>(index);
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Index:It");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override;

	private:
		const Ptr _index;
		std_unordered_map_ptr_ptr::const_iterator _iterator;
	};
};

inline const Thing::Ptr Thing::pub_() const
{
	static const Ptr PUB = []()
	{
		const Ptr pub = Index::mut_();
		Index* const index = static_<Index>(pub);
		index->update_("thing", Member<Thing>::fin_(&Thing::thing));
		index->update_("next", Member<Thing>::fin_(&Thing::next));
		index->update_("is", Const<Thing>::fin_(&Thing::is));
		index->update_("hash", Const<Thing>::fin_(&Thing::hash));
		index->update_("same", Const<Thing>::fin_(&Thing::same));
		index->update_("copy", Const<Thing>::fin_(&Thing::copy));
		index->update_("clone", Const<Thing>::fin_(&Thing::clone));
		index->update_("finalize", Member<Thing>::fin_(&Thing::finalize));
		index->update_("finalized", Const<Thing>::fin_(&Thing::finalized));
		index->update_("freeze", Member<Thing>::fin_(&Thing::freeze));
		index->update_("boolean", Static::fin_(&Thing::boolean));
		index->update_("factory", Static::fin_(&Thing::factory));
		index->update_("pub", Const<Thing>::fin_(&Thing::pub));
		index->update_(nothing_(), nothing_());
		index->update_(one_(), one_());
		index->update_(end_(), end_());
		index->update_("log", Static::fin_(&Thing::log));
		index->update_("type", Const<Thing>::fin_(&Thing::type));
		index->update_("cats", Const<Thing>::fin_(&Thing::cats));
		index->update_("visit", Member<Thing>::fin_(&Thing::visit));
		index->finalize_();
		return pub;
	}();
	return PUB;
}

inline const Thing::Ptr Thing::operator()(Thing* const thing, const Thing::Ptr it)
{
	const Ptr member = static_<Index>(pub_())->find(it);
	return thing_(thing, member, it);
}

inline void Serializable::serialize_(const Thing::Ptr thing, const Thing::Ptr stream)
{
	Thing::static_<Index>(Index::mut_())->gather_to_stream_(thing, stream);
}

inline const Thing::Ptr Serializable::deserialize_(const Thing::Ptr stream)
{
	return Thing::static_<Index>(Index::mut_())->gather_from_stream_(stream);
}

class Decorator : public Thing
{
protected:
	inline Decorator(const Ptr decorated)
		: Thing{}
		, _decorated{ decorated }
	{
	}

	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		const Ptr cit = it->copy_();
		const Ptr member = static_<Index>(pub_())->find(it);
		if (member->is_("0"))
		{
			return _decorated->thing(cit);
		}
		return thing_(thing, member, it);
	}

	const Ptr _decorated;
};

template <typename C>
class Iterator : public Mutable
{
public:
	template <typename F>
	inline Iterator(F&& collection)
		: Mutable{}
		, _collection{ std::forward<F>(collection) }
		, _iterator{ _collection.cbegin() }
	{
	}

	virtual inline const Ptr next_() override
	{
		if (_iterator == _collection.cend())
		{
			return end_();
		}
		return *_iterator++;
	}

	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_(C{ _collection });
		static_<Iterator>(result)->_iterator += (_iterator - _collection.cbegin());
		return result;
	}

	template <typename F>
	static inline const Ptr mut_(F&& collection)
	{
		return std::make_shared<Iterator>(std::forward<F>(collection));
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Iterator");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

private:
	const C _collection;
	typename C::const_iterator _iterator;
};

class Flock : public Mutable, public Me<Flock>, public Serializable
{
	using std_vector_ptr = std::vector<Ptr>;

public:
	Flock() = default;

	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_();
		static_<Flock>(result)->_vector = _vector;
		return result;
	}

	virtual inline const Ptr clone_() const override
	{
		const Ptr result = mut_();
		std_vector_ptr& clone = static_<Flock>(result)->_vector;
		clone.reserve(_vector.size());
		for (const auto i : _vector)
		{
			clone.push_back(i->clone_());
		}
		return result;
	}

	virtual inline void freeze_() override
	{
		for (const auto i : _vector)
		{
			i->freeze_();
		}
	}

	virtual inline const Ptr to_buffer_() const override
	{
		return to_buffer_via_stream_();
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		from_buffer_via_stream_(buffer);
	}

	virtual inline void to_stream_(const Thing::Ptr stream) const override;

	virtual inline void from_stream_(const Thing::Ptr stream) override;

	virtual inline void to_stream_with_links_(const Thing::Ptr index, const Thing::Ptr stream) const override;

	virtual inline void replace_links_(const Thing::Ptr index) override;

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("to_buffer", Const<Flock>::fin_(&Flock::to_buffer));
			index->update_("from_buffer", Member<Flock>::fin_(&Flock::from_buffer));
			index->update_("to_stream", Const<Flock>::fin_(&Flock::to_stream));
			index->update_("from_stream", Member<Flock>::fin_(&Flock::from_stream));
			index->update_("mut", Static::fin_(&Flock::mut));
			index->update_("buf", Static::fin_(&Flock::buf));
			index->update_("str", Static::fin_(&Flock::str));
			index->update_("push_back", Member<Flock>::fin_(&Flock::push_back));
			index->update_("iterator", Const<Flock>::fin_(&Flock::iterator));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr mut_()
	{
		return make_();
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr buf_(const Ptr buffer)
	{
		const Ptr ptr = mut_();
		static_<Flock>(ptr)->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream)
	{
		const Ptr ptr = mut_();
		static_<Flock>(ptr)->from_stream_(stream);
		return ptr;
	}

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	inline const Ptr push_back(const Ptr it)
	{
		const Ptr item = it->next_();
		_vector.push_back(item);
		return item;
	}

	inline const Ptr iterator_() const
	{
		return It::mut_(me_());
	}

	inline const Ptr iterator(const Ptr ignore) const
	{
		return iterator_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Flock");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

	virtual inline const Ptr visit(const Ptr it) override
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		const Ptr rest = it->copy_();
		if (visitor->call_(member, *it)->is_("0"))
		{
			return visitor;
		}
		rest->next_();
		for (const auto visited : _vector)
		{
			visited->call_("visit", visitor, member, visited, *(rest->copy_()));
		}
		return visitor;
	}

private:
	std_vector_ptr _vector;

	class It : public Mutable
	{
	public:
		inline It(const Ptr flock)
			: Mutable{}
			, _flock{ flock }
			, _iterator{ static_<Flock>(_flock)->_vector.cbegin() }
		{
		}

		virtual const Ptr next_() override
		{
			if (_iterator == static_<Flock>(_flock)->_vector.cend())
			{
				return end_();
			}
			return *_iterator++;
		}

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_flock);
			static_<It>(result)->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr flock)
		{
			return std::make_shared<It>(flock);
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Flock::It");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override;

	private:
		const Ptr _flock;
		std_vector_ptr::const_iterator _iterator;
	};
};

inline const Thing::Ptr Index::It::next_()
{
	if (_iterator == static_<Index>(_index)->_map.cend())
	{
		return end_();
	}
	const Ptr result = Flock::mut_();
	Flock* const flock = static_<Flock>(result);
	flock->push_back(_iterator->first);
	flock->push_back(_iterator->second);
	flock->finalize_();
	++_iterator;
	return result;
}

class Herd : public Mutable, public Me<Herd>, public Serializable
{
	class Hash
	{
	public:
		inline size_t operator()(const Ptr ptr) const
		{
			return ptr->hash_();
		}
	};

	class Pred
	{
	public:
		inline const bool operator()(const Ptr lhs, const Ptr rhs) const
		{
			return lhs->same_(rhs);
		}
	};

	using std_unordered_set_ptr = std::unordered_set<Ptr, Hash, Pred>;

public:
	Herd() = default;

	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_();
		static_<Herd>(result)->_set = _set;
		return result;
	}

	virtual inline const Ptr clone_() const override
	{
		const Ptr result = mut_();
		std_unordered_set_ptr& clone = static_<Herd>(result)->_set;
		for (const auto i : _set)
		{
			clone.insert(i->clone_());
		}
		return result;
	}

	virtual inline void freeze_() override
	{
		for (const auto i : _set)
		{
			i->freeze_();
		}
	}

	virtual inline const Ptr to_buffer_() const override
	{
		return to_buffer_via_stream_();
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		from_buffer_via_stream_(buffer);
	}

	virtual inline void to_stream_(const Thing::Ptr stream) const override;

	virtual inline void from_stream_(const Thing::Ptr stream) override;

	virtual inline void to_stream_with_links_(const Thing::Ptr index, const Thing::Ptr stream) const override;

	virtual inline void replace_links_(const Thing::Ptr index) override;

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("to_buffer", Const<Herd>::fin_(&Herd::to_buffer));
			index->update_("from_buffer", Member<Herd>::fin_(&Herd::from_buffer));
			index->update_("to_stream", Const<Herd>::fin_(&Herd::to_stream));
			index->update_("from_stream", Member<Herd>::fin_(&Herd::from_stream));
			index->update_("mut", Static::fin_(&Herd::mut));
			index->update_("buf", Static::fin_(&Herd::buf));
			index->update_("str", Static::fin_(&Herd::str));
			index->update_("find", Const<Herd>::fin_(&Herd::find));
			index->update_("insert", Member<Herd>::fin_(&Herd::insert));
			index->update_("iterator", Const<Herd>::fin_(&Herd::iterator));
			index->update_("gather", Member<Herd>::fin_(&Herd::gather));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr mut_()
	{
		return make_();
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr buf_(const Ptr buffer)
	{
		const Ptr ptr = mut_();
		static_<Herd>(ptr)->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream)
	{
		const Ptr ptr = mut_();
		static_<Herd>(ptr)->from_stream_(stream);
		return ptr;
	}

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	template <typename F>
	inline const Ptr find_(F&& item)
	{
		return find_(sym_(std::forward<F>(item)));
	}

	inline const Ptr find_(const Ptr item) const
	{
		const std_unordered_set_ptr::const_iterator sit = _set.find(item);
		if (sit == _set.cend())
		{
			return nothing_();
		}
		return *sit;
	}

	inline const Ptr find(const Ptr it) const
	{
		return find_(it->next_());
	}

	template <typename F>
	inline const bool insert_(F&& key)
	{
		return insert_(sym_(std::forward<F>(key)));
	}

	inline const bool insert_(const Ptr item)
	{
		return _set.insert(item).second;
	}

	inline const Ptr insert(const Ptr it)
	{
		return boolean_(insert_(it->next_()));
	}

	inline const Ptr iterator_() const
	{
		return It::mut_(me_());
	}

	inline const Ptr iterator(const Ptr ignore) const
	{
		return iterator_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Herd");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Iterable");
			herd->insert_("strange::Herd");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline const Ptr visit(const Ptr it) override
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		const Ptr rest = it->copy_();
		if (visitor->call_(member, *it)->is_("0"))
		{
			return visitor;
		}
		rest->next_();
		for (const auto visited : _set)
		{
			visited->call_("visit", visitor, member, visited, *(rest->copy_()));
		}
		return visitor;
	}

	inline const Ptr gather_(const Ptr item)
	{
		return item->call_("visit", me_(), "insert", item);
	}

	inline const Ptr gather(const Ptr it)
	{
		return gather_(it->next_());
	}

private:
	std_unordered_set_ptr _set;

	class It : public Mutable
	{
	public:
		inline It(const Ptr herd)
			: Mutable{}
			, _herd{ herd }
			, _iterator{ static_<Herd>(_herd)->_set.cbegin() }
		{
		}

		virtual inline const Ptr next_() override
		{
			if (_iterator == static_<Herd>(_herd)->_set.cend())
			{
				return end_();
			}
			return *_iterator++;
		}

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_herd);
			static_<It>(result)->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr herd)
		{
			return std::make_shared<It>(herd);
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Herd::It");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override
		{
			static const Ptr CATS = []()
			{
				const Ptr cats = Herd::mut_();
				Herd* const herd = static_<Herd>(cats);
				herd->insert_("strange::Mutable");
				herd->insert_("strange::Iterator");
				herd->insert_("strange::Thing");
				herd->finalize_();
				return cats;
			}();
			return CATS;
		}

	private:
		const Ptr _herd;
		std_unordered_set_ptr::const_iterator _iterator;
	};
};

template <typename D>
class Data
{
public:
	Data(const D& data)
		: _data{ data }
	{
	}

	inline void set_(const D& data)
	{
		_data = data;
	}

	inline const D& get_() const
	{
		return _data;
	}

private:
	D _data;
};

class Buffer : public Mutable, public Serializable, public Data<std::string>
{
public:
	using S = std::string;

	static inline const Ptr mut_(const S& data = S())
	{
		return std::make_shared<Buffer>(data);
	}

	static inline const Ptr fin_(const S& data = S())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr buf_(const Ptr buffer)
	{
		const Ptr ptr = mut_();
		static_<Buffer>(ptr)->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream)
	{
		const Ptr ptr = mut_();
		static_<Buffer>(ptr)->from_stream_(stream);
		return ptr;
	}

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	inline Buffer(const S& data)
		: Mutable{}
		, Serializable{}
		, Data{ data }
	{
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(get_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("to_buffer", Const<Buffer>::fin_(&Buffer::to_buffer));
			index->update_("from_buffer", Member<Buffer>::fin_(&Buffer::from_buffer));
			index->update_("to_stream", Const<Buffer>::fin_(&Buffer::to_stream));
			index->update_("from_stream", Member<Buffer>::fin_(&Buffer::from_stream));
			index->update_("buf", Static::fin_(&Buffer::buf));
			index->update_("str", Static::fin_(&Buffer::str));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	virtual inline const Ptr to_buffer_() const override
	{
		const Ptr buffer = copy_();
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_<Buffer>(buffer);
		if (!buf)
		{
			log_("Buffer::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(buf->get_());
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline void to_stream_(const Ptr stream) const override;

	virtual inline void from_stream_(const Ptr stream) override;

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Buffer");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Serializable");
			herd->insert_("strange::Buffer");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}
};

inline void Thing::log_(const Thing::Ptr ptr)
{
	Serializable* const ser = dynamic_<Serializable>(ptr);
	if (ser)
	{
		log_(static_<const Buffer>(ser->to_buffer_())->get_());
	}
}

inline void Serializable::to_stream_(const Thing::Ptr stream) const
{
	Thing::static_<Buffer>(to_buffer_())->to_stream_(stream);
}

inline void Serializable::from_stream_(const Thing::Ptr stream)
{
	const Thing::Ptr buffer = Buffer::mut_();
	Thing::static_<Buffer>(buffer)->from_stream_(stream);
	from_buffer_(buffer);
}

inline const Thing::Ptr Symbol::buf_(const Thing::Ptr buffer)
{
	Buffer* const buf = dynamic_<Buffer>(buffer);
	if (!buf)
	{
		log_("Symbol::buf_ called with wrong type of thing");
		return fin_("");
	}
	return fin_(buf->get_());
}

inline const Thing::Ptr Symbol::str_(const Thing::Ptr stream)
{
	return fin_(static_<Buffer>(Buffer::str_(stream))->get_());
}

inline const Thing::Ptr Symbol::to_buffer_() const
{
	const Ptr buffer = Buffer::mut_(_symbol);
	buffer->finalize_();
	return buffer;
}

class Bit : public Mutable, public Serializable, public Data<bool>
{
public:
	using D = bool;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Bit>(data);
	}

	static inline const Ptr mut(const Ptr it)
	{
		return mut_(!it->next_()->is_("0"));
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr it)
	{
		const Ptr result = mut(it);
		result->finalize_();
		return result;
	}

	static inline const Ptr buf_(const Ptr buffer)
	{
		const Ptr ptr = mut_();
		static_<Bit>(ptr)->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream)
	{
		const Ptr ptr = mut_();
		static_<Bit>(ptr)->from_stream_(stream);
		return ptr;
	}

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	inline Bit(const D& data)
		: Mutable{}
		, Serializable{}
		, Data{ data }
	{
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(get_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("to_buffer", Const<Bit>::fin_(&Bit::to_buffer));
			index->update_("from_buffer", Member<Bit>::fin_(&Bit::from_buffer));
			index->update_("to_stream", Const<Bit>::fin_(&Bit::to_stream));
			index->update_("from_stream", Member<Bit>::fin_(&Bit::from_stream));
			index->update_("mut", Static::fin_(&Bit::mut));
			index->update_("fin", Static::fin_(&Bit::fin));
			index->update_("buf", Static::fin_(&Bit::buf));
			index->update_("str", Static::fin_(&Bit::str));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	virtual inline const Ptr to_buffer_() const override
	{
		const Ptr buffer = Buffer::mut_(std::string(1, get_() ? char(1) : char(0)));
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_<Buffer>(buffer);
		if (!buf)
		{
			log_("Bit::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(buf->get_() != "0");
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Bit");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Serializable");
			herd->insert_("strange::Bit");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}
};

class Byte : public Mutable, public Serializable, public Data<unsigned char>
{
public:
	using D = unsigned char;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Byte>(data);
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr buf_(const Ptr buffer)
	{
		const Ptr ptr = mut_();
		static_<Byte>(ptr)->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream)
	{
		const Ptr ptr = mut_();
		static_<Byte>(ptr)->from_stream_(stream);
		return ptr;
	}

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	inline Byte(const D& data)
		: Mutable{}
		, Serializable{}
		, Data{ data }
	{
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(get_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("to_buffer", Const<Byte>::fin_(&Byte::to_buffer));
			index->update_("from_buffer", Member<Byte>::fin_(&Byte::from_buffer));
			index->update_("to_stream", Const<Byte>::fin_(&Byte::to_stream));
			index->update_("from_stream", Member<Byte>::fin_(&Byte::from_stream));
			index->update_("buf", Static::fin_(&Byte::buf));
			index->update_("str", Static::fin_(&Byte::str));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	virtual inline const Ptr to_buffer_() const override
	{
		const Ptr buffer = Buffer::mut_(std::string(1, *reinterpret_cast<const char*>(&(get_()))));
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_<Buffer>(buffer);
		if (!buf)
		{
			log_("Byte::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0])));
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Byte");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Serializable");
			herd->insert_("strange::Byte");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}
};

class Int16 : public Mutable, public Serializable, public Data<int16_t>
{
public:
	using D = int16_t;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Int16>(data);
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr buf_(const Ptr buffer)
	{
		const Ptr ptr = mut_();
		static_<Int16>(ptr)->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream)
	{
		const Ptr ptr = mut_();
		static_<Int16>(ptr)->from_stream_(stream);
		return ptr;
	}

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	inline Int16(const D& data)
		: Mutable{}
		, Serializable{}
		, Data{ data }
	{
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(get_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("to_buffer", Const<Int16>::fin_(&Int16::to_buffer));
			index->update_("from_buffer", Member<Int16>::fin_(&Int16::from_buffer));
			index->update_("to_stream", Const<Int16>::fin_(&Int16::to_stream));
			index->update_("from_stream", Member<Int16>::fin_(&Int16::from_stream));
			index->update_("buf", Static::fin_(&Int16::buf));
			index->update_("str", Static::fin_(&Int16::str));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(2, 0);
		str[0] = get_() & 0xFF;
		str[1] = (get_() >> 8) & 0xFF;
		const Ptr buffer = Buffer::mut_(str);
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_<Buffer>(buffer);
		if (!buf)
		{
			log_("Int16::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(
			uint16_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0]))) |
			uint16_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[1]))) << 8
			);
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Int16");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Serializable");
			herd->insert_("strange::Int16");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}
};

class Int32 : public Mutable, public Serializable, public Data<int32_t>
{
public:
	using D = int32_t;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Int32>(data);
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr buf_(const Ptr buffer)
	{
		const Ptr ptr = mut_();
		static_<Int32>(ptr)->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream)
	{
		const Ptr ptr = mut_();
		static_<Int32>(ptr)->from_stream_(stream);
		return ptr;
	}

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	inline Int32(const D& data)
		: Mutable{}
		, Serializable{}
		, Data{ data }
	{
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(get_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("to_buffer", Const<Int32>::fin_(&Int32::to_buffer));
			index->update_("from_buffer", Member<Int32>::fin_(&Int32::from_buffer));
			index->update_("to_stream", Const<Int32>::fin_(&Int32::to_stream));
			index->update_("from_stream", Member<Int32>::fin_(&Int32::from_stream));
			index->update_("buf", Static::fin_(&Int32::buf));
			index->update_("str", Static::fin_(&Int32::str));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(4, 0);
		str[0] = get_() & 0xFF;
		str[1] = (get_() >> 8) & 0xFF;
		str[2] = (get_() >> 16) & 0xFF;
		str[3] = (get_() >> 24) & 0xFF;
		const Ptr buffer = Buffer::mut_(str);
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_<Buffer>(buffer);
		if (!buf)
		{
			log_("Int32::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0]))) |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[3]))) << 24
			);
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Int32");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Serializable");
			herd->insert_("strange::Int32");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}
};

class Int64 : public Mutable, public Serializable, public Data<int64_t>
{
public:
	using D = int64_t;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Int64>(data);
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr buf_(const Ptr buffer)
	{
		const Ptr ptr = mut_();
		static_<Int64>(ptr)->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream)
	{
		const Ptr ptr = mut_();
		static_<Int64>(ptr)->from_stream_(stream);
		return ptr;
	}

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	inline Int64(const D& data)
		: Mutable{}
		, Serializable{}
		, Data{ data }
	{
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(get_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("to_buffer", Const<Int64>::fin_(&Int64::to_buffer));
			index->update_("from_buffer", Member<Int64>::fin_(&Int64::from_buffer));
			index->update_("to_stream", Const<Int64>::fin_(&Int64::to_stream));
			index->update_("from_stream", Member<Int64>::fin_(&Int64::from_stream));
			index->update_("buf", Static::fin_(&Int64::buf));
			index->update_("str", Static::fin_(&Int64::str));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(8, 0);
		str[0] = get_() & 0xFF;
		str[1] = (get_() >> 8) & 0xFF;
		str[2] = (get_() >> 16) & 0xFF;
		str[3] = (get_() >> 24) & 0xFF;
		str[4] = (get_() >> 32) & 0xFF;
		str[5] = (get_() >> 40) & 0xFF;
		str[6] = (get_() >> 48) & 0xFF;
		str[7] = (get_() >> 56) & 0xFF;
		const Ptr buffer = Buffer::mut_(str);
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_<Buffer>(buffer);
		if (!buf)
		{
			log_("Int64::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0]))) |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[1]))) << 8 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[2]))) << 16 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[3]))) << 24 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[4]))) << 32 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[5]))) << 40 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[6]))) << 48 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[7]))) << 56
			);
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Int64");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Serializable");
			herd->insert_("strange::Int64");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}
};

inline const Thing::Ptr Thing::hash(const Thing::Ptr ignore) const
{
	return Int64::fin_(int64_t{ hash_() });
}

class Float32 : public Mutable, public Serializable, public Data<float>
{
public:
	using D = float;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Float32>(data);
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr buf_(const Ptr buffer)
	{
		const Ptr ptr = mut_();
		static_<Float32>(ptr)->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream)
	{
		const Ptr ptr = mut_();
		static_<Float32>(ptr)->from_stream_(stream);
		return ptr;
	}

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	inline Float32(const D& data)
		: Mutable{}
		, Serializable{}
		, Data{ data }
	{
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(get_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("to_buffer", Const<Float32>::fin_(&Float32::to_buffer));
			index->update_("from_buffer", Member<Float32>::fin_(&Float32::from_buffer));
			index->update_("to_stream", Const<Float32>::fin_(&Float32::to_stream));
			index->update_("from_stream", Member<Float32>::fin_(&Float32::from_stream));
			index->update_("buf", Static::fin_(&Float32::buf));
			index->update_("str", Static::fin_(&Float32::str));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(4, 0);
		uint32_t i = *reinterpret_cast<const uint32_t*>(&(get_()));
		str[0] = i & 0xFF;
		str[1] = (i >> 8) & 0xFF;
		str[2] = (i >> 16) & 0xFF;
		str[3] = (i >> 24) & 0xFF;
		const Ptr buffer = Buffer::mut_(str);
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_<Buffer>(buffer);
		if (!buf)
		{
			log_("Float32::from_buffer_ called with wrong type of thing");
			return;
		}
		const uint32_t i =
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0]))) |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[3]))) << 24;
		set_(*reinterpret_cast<const float*>(&i));
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Float32");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Serializable");
			herd->insert_("strange::Float32");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}
};

class Float64 : public Mutable, public Serializable, public Data<double>
{
public:
	using D = double;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Float64>(data);
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr buf_(const Ptr buffer)
	{
		const Ptr ptr = mut_();
		static_<Float64>(ptr)->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	static inline const Ptr str_(const Ptr stream)
	{
		const Ptr ptr = mut_();
		static_<Float64>(ptr)->from_stream_(stream);
		return ptr;
	}

	static inline const Ptr str(const Ptr it)
	{
		return str_(it->next_());
	}

	inline Float64(const D& data)
		: Mutable{}
		, Serializable{}
		, Data{ data }
	{
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(get_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("to_buffer", Const<Float64>::fin_(&Float64::to_buffer));
			index->update_("from_buffer", Member<Float64>::fin_(&Float64::from_buffer));
			index->update_("to_stream", Const<Float64>::fin_(&Float64::to_stream));
			index->update_("from_stream", Member<Float64>::fin_(&Float64::from_stream));
			index->update_("buf", Static::fin_(&Float64::buf));
			index->update_("str", Static::fin_(&Float64::str));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(8, 0);
		uint64_t i = *reinterpret_cast<const uint64_t*>(&(get_()));
		str[0] = i & 0xFF;
		str[1] = (i >> 8) & 0xFF;
		str[2] = (i >> 16) & 0xFF;
		str[3] = (i >> 24) & 0xFF;
		str[4] = (i >> 32) & 0xFF;
		str[5] = (i >> 40) & 0xFF;
		str[6] = (i >> 48) & 0xFF;
		str[7] = (i >> 56) & 0xFF;
		const Ptr buffer = Buffer::mut_(str);
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_<Buffer>(buffer);
		if (!buf)
		{
			log_("Float64::from_buffer_ called with wrong type of thing");
			return;
		}
		const uint64_t i =
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0]))) |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[1]))) << 8 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[2]))) << 16 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[3]))) << 24 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[4]))) << 32 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[5]))) << 40 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[6]))) << 48 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[7]))) << 56;
		set_(*reinterpret_cast<const double*>(&i));
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Float64");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Serializable");
			herd->insert_("strange::Float64");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}
};

class Stream : public Mutable, public Me<Stream>
{
	using const_std_unique_iostream = const std::unique_ptr<std::iostream>;

public:
	Stream(std::iostream* const stream)
		: Mutable{}
		, _stream{ stream }
	{
	}

	static inline const Ptr mut_(std::iostream* const stream)
	{
		return make_(stream);
	}

	static inline const Ptr mut_(const std::string& str = std::string())
	{
		return mut_(new std::stringstream(str));
	}

	virtual inline const Ptr copy_() const override
	{
		return me_();
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("push_back", Member<Stream>::fin_(&Stream::push_back));
			index->update_("write", Member<Stream>::fin_(&Stream::write));
			index->update_("pop_front", Member<Stream>::fin_(&Stream::pop_front));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Stream");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Stream");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	inline const bool push_back_(const Ptr ptr)
	{
		Serializable* const ser = dynamic_<Serializable>(ptr);
		if (!ser)
		{
			return false;
		}
		const Ptr type = ptr->type_();
		write_(Int16::mut_(int16_t(static_<Symbol>(type)->symbol_().length())));
		write_(type);
		ser->to_stream_(me_());
		return true;
	}

	inline const Ptr push_back(const Ptr it)
	{
		push_back_(it->next_());
		return nothing_();
	}

	inline const bool push_back_with_links_(const Ptr ptr, const Ptr index)
	{
		Serializable* const ser = dynamic_<Serializable>(ptr);
		if (!ser)
		{
			return false;
		}
		const Ptr type = ptr->type_();
		write_(Int16::mut_(int16_t(static_<Symbol>(type)->symbol_().length())));
		write_(type);
		ser->to_stream_with_links_(index, me_());
		return true;
	}

	inline void write_(const std::string& str)
	{
		_stream->write(str.data(), str.length());
	}

	inline void write_(const Ptr ptr)
	{
		Serializable* const ser = dynamic_<Serializable>(ptr);
		if (ser)
		{
			write_(static_<Buffer>(ser->to_buffer_())->get_());
		}
	}

	inline const Ptr write(const Ptr it)
	{
		write_(it->next_());
	}

	inline const Ptr pop_front_()
	{
		const int16_t int16 = read_<Int16>();
		const std::string function = static_<Buffer>(read_(int16))->get_() + "::str";
		const Ptr fun = static_<Index>(factory_())->find_(function);
		if (fun->is_("0"))
		{
			log_("Stream::pop_front_ read unknown type");
			return fun;
		}
		return fun->call_(me_());
	}

	inline const Ptr pop_front(const Ptr ignore)
	{
		return pop_front_();
	}

	inline const Ptr read_(const int64_t length)
	{
		std::string str;
		str.resize(size_t(length));
		_stream->read(&str[0], str.length());
		return Buffer::mut_(str);
	}

	template <typename T>
	const typename T::D read_()
	{
		return static_<T>(T::buf_(read_(int64_t(sizeof(T::D)))))->get_();
	}

private:
	const_std_unique_iostream _stream;
};

inline const Thing::Ptr Serializable::to_buffer_via_stream_() const
{
	const Thing::Ptr stream = Stream::mut_();
	to_stream_(stream);
	const Thing::Ptr buffer = Buffer::mut_();
	Thing::static_<Buffer>(buffer)->from_stream_(stream);
	return buffer;
}

inline void Serializable::from_buffer_via_stream_(const Thing::Ptr buffer)
{
	Buffer* const buf = Thing::dynamic_<Buffer>(buffer);
	if (!buf)
	{
		Thing::log_("Serializable::from_buffer_via_stream_ called with wrong type of thing");
		return;
	}
	const Thing::Ptr stream = Stream::mut_();
	buf->to_stream_(stream);
	from_stream_(stream);
}

inline void Index::to_stream_(const Thing::Ptr stream) const
{
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Index::to_stream_ called with wrong type of thing");
		return;
	}
	strm->write_(Bit::fin_(finalized_()));
	strm->write_(Int64::fin_(int64_t(_map.size())));
	for (const auto& i : _map)
	{
		strm->push_back_(i.first);
		strm->push_back_(i.second);
	}
}

inline void Index::from_stream_(const Thing::Ptr stream)
{
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Index::from_stream_ called with wrong type of thing");
		return;
	}
	const bool bit = strm->read_<Bit>();
	for (int64_t i = strm->read_<Int64>(); i > 0; --i)
	{
		const Ptr first = strm->pop_front_();
		const Ptr second = strm->pop_front_();
		_map[first] = second;
	}
	if (bit)
	{
		finalize_();
	}
}

inline void Index::to_stream_with_links_(const Thing::Ptr index, const Thing::Ptr stream) const
{
	Index* const ind = dynamic_<Index>(index);
	if (!ind)
	{
		log_("Index::to_stream_with_links_ called with wrong type of index thing");
		return;
	}
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Index::to_stream_with_links_ called with wrong type of stream thing");
		return;
	}
	strm->write_(Bit::fin_(finalized_()));
	strm->write_(Int64::fin_(int64_t(_map.size())));
	for (const auto& i : _map)
	{
		static_<Symbol>(ind->find_(i.first))->to_stream_(stream);
		static_<Symbol>(ind->find_(i.second))->to_stream_(stream);
	}
}

inline void Index::replace_links_(const Thing::Ptr index)
{
	std_unordered_map_ptr_ptr replacement;
	Index* const ind = static_<Index>(index);
	for (const auto& i : _map)
	{
		replacement.emplace(ind->find_(i.first), ind->find_(i.second));
	}
	_map.swap(replacement);
}

inline void Index::gather_to_stream_(const Thing::Ptr thing, const Thing::Ptr stream)
{
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Index::gather_to_stream_ called with wrong type of stream thing");
		return;
	}
	gather_(thing);
	strm->write_(Int64::fin_(int64_t(_map.size())));
	for (const auto& i : _map)
	{
		if (strm->push_back_with_links_(i.first, me_()))
		{
			static_<Symbol>(i.second)->to_stream_(stream);
		}
	}
}

inline const Thing::Ptr Index::gather_from_stream_(const Thing::Ptr stream)
{
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Index::gather_from_stream_ called with wrong type of stream thing");
		return nothing_();
	}
	for (int64_t i = strm->read_<Int64>(); i > 0; --i)
	{
		const Ptr thing = strm->pop_front_();
		const Ptr symbol = Symbol::str_(stream);
		_map.emplace(symbol, thing);
	}
	for (const auto& i : _map)
	{
		Serializable* const ser = dynamic_<Serializable>(i.second);
		if (ser)
		{
			ser->replace_links_(me_());
		}
	}
	return find_(nothing_());
}

inline void Flock::to_stream_(const Thing::Ptr stream) const
{
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Flock::to_stream_ called with wrong type of thing");
		return;
	}
	strm->write_(Bit::fin_(finalized_()));
	strm->write_(Int64::fin_(int64_t(_vector.size())));
	for (const auto i : _vector)
	{
		strm->push_back_(i);
	}
}

inline void Flock::from_stream_(const Thing::Ptr stream)
{
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Flock::from_stream_ called with wrong type of thing");
		return;
	}
	const bool bit = strm->read_<Bit>();
	const int64_t int64 = strm->read_<Int64>();
	_vector.reserve(size_t(int64));
	for (int64_t i = int64; i > 0; --i)
	{
		_vector.push_back(strm->pop_front_());
	}
	if (bit)
	{
		finalize_();
	}
}

inline void Flock::to_stream_with_links_(const Thing::Ptr index, const Thing::Ptr stream) const
{
	Index* const ind = dynamic_<Index>(index);
	if (!ind)
	{
		log_("Flock::to_stream_with_links_ called with wrong type of index thing");
		return;
	}
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Flock::to_stream_with_links_ called with wrong type of stream thing");
		return;
	}
	strm->write_(Bit::fin_(finalized_()));
	strm->write_(Int64::fin_(int64_t(_vector.size())));
	for (const auto i : _vector)
	{
		static_<Symbol>(ind->find_(i))->to_stream_(stream);
	}
}

inline void Flock::replace_links_(const Thing::Ptr index)
{
	Index* const ind = static_<Index>(index);
	for (std_vector_ptr::iterator i = _vector.begin(); i != _vector.end(); ++i)
	{
		*i = ind->find_(*i);
	}
}

inline void Herd::to_stream_(const Thing::Ptr stream) const
{
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Herd::to_stream_ called with wrong type of thing");
		return;
	}
	strm->write_(Bit::fin_(finalized_()));
	strm->write_(Int64::fin_(int64_t(_set.size())));
	for (const auto i : _set)
	{
		strm->push_back_(i);
	}
}

inline void Herd::from_stream_(const Thing::Ptr stream)
{
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Herd::from_stream_ called with wrong type of thing");
		return;
	}
	const bool bit = strm->read_<Bit>();
	for (int64_t i = strm->read_<Int64>(); i > 0; --i)
	{
		_set.insert(strm->pop_front_());
	}
	if (bit)
	{
		finalize_();
	}
}

inline void Herd::to_stream_with_links_(const Thing::Ptr index, const Thing::Ptr stream) const
{
	Index* const ind = dynamic_<Index>(index);
	if (!ind)
	{
		log_("Herd::to_stream_with_links_ called with wrong type of index thing");
		return;
	}
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Herd::to_stream_with_links_ called with wrong type of stream thing");
		return;
	}
	strm->write_(Bit::fin_(finalized_()));
	strm->write_(Int64::fin_(int64_t(_set.size())));
	for (const auto i : _set)
	{
		static_<Symbol>(ind->find_(i))->to_stream_(stream);
	}
}

inline void Herd::replace_links_(const Thing::Ptr index)
{
	std_unordered_set_ptr replacement;
	Index* const ind = static_<Index>(index);
	for (const auto i : _set)
	{
		replacement.insert(ind->find_(i));
	}
	_set.swap(replacement);
}

inline void Buffer::to_stream_(const Thing::Ptr stream) const
{
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Buffer::to_stream_ called with wrong type of thing");
		return;
	}
	strm->write_(Bit::fin_(finalized_()));
	strm->write_(Int64::fin_(int64_t(get_().length())));
	strm->write_(get_());
}

inline void Buffer::from_stream_(const Thing::Ptr stream)
{
	Stream* const strm = dynamic_<Stream>(stream);
	if (!strm)
	{
		log_("Buffer::from_stream_ called with wrong type of thing");
		return;
	}
	const bool bit = strm->read_<Bit>();
	const int64_t int64 = strm->read_<Int64>();
	set_(static_<Buffer>(strm->read_(int64))->get_());
	if (bit)
	{
		finalize_();
	}
}

class Fence : public Mutable
{
public:
	inline Fence(const Ptr ptr)
		: Mutable{}
		, _fence{}
		, _ptr{ ptr }
	{
		_fence.store(false, std::memory_order_release);
	}

	static inline const Ptr mut(const Ptr it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr ptr)
	{
		return std::make_shared<Fence>(ptr);
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(_ptr);
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_<Index>(pub);
			index->update_("mut", Static::fin_(&Fence::mut));
			index->update_("give", Member<Fence>::fin_(&Fence::give));
			index->update_("take", Member<Fence>::fin_(&Fence::take));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	inline const bool give_(const Ptr ptr)
	{
		if (_fence.load(std::memory_order_acquire))
		{
			return false;
		}
		_ptr = ptr;
		_fence.store(true, std::memory_order_release);
		return true;
	}

	inline const Ptr give(const Ptr it)
	{
		return boolean_(give_(it->next_()));
	}

	inline const Ptr take_()
	{
		if (_fence.load(std::memory_order_acquire))
		{
			_fence.store(false, std::memory_order_release);
			return _ptr;
		}
		return nothing_();
	}

	inline const Ptr take(const Ptr ignore)
	{
		return take_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Bit");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Concurrent");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	std::atomic<bool> _fence;
	Ptr _ptr;
};

inline const Thing::Ptr Thing::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		cats->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Symbol::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_<Herd>(cats);
		herd->insert_("strange::Final");
		herd->insert_("strange::Symbol");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Index::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_<Herd>(cats);
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterable");
		herd->insert_("strange::Index");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Index::It::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_<Herd>(cats);
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterator");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

template <typename C>
inline const Thing::Ptr Iterator<C>::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_<Herd>(cats);
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterator");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Flock::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_<Herd>(cats);
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterable");
		herd->insert_("strange::Flock");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Flock::It::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_<Herd>(cats);
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterator");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Thing::factory_()
{
	static const Ptr FACTORY = []()
	{
		const Ptr factory = Index::mut_();
		Index* const index = static_<Index>(factory);
		index->update_("strange::Symbol::buf", Static::fin_(&Symbol::buf));
		index->update_("strange::Symbol::str", Static::fin_(&Symbol::str));
		index->update_("strange::Index::mut", Static::fin_(&Index::mut));
		index->update_("strange::Index::buf", Static::fin_(&Index::buf));
		index->update_("strange::Index::str", Static::fin_(&Index::str));
		index->update_("strange::Flock::mut", Static::fin_(&Flock::mut));
		index->update_("strange::Flock::buf", Static::fin_(&Flock::buf));
		index->update_("strange::Flock::str", Static::fin_(&Flock::str));
		index->update_("strange::Herd::mut", Static::fin_(&Herd::mut));
		index->update_("strange::Herd::buf", Static::fin_(&Herd::buf));
		index->update_("strange::Herd::str", Static::fin_(&Herd::str));
		index->update_("strange::Buffer::buf", Static::fin_(&Buffer::buf));
		index->update_("strange::Buffer::str", Static::fin_(&Buffer::str));
		index->update_("strange::Bit::buf", Static::fin_(&Bit::buf));
		index->update_("strange::Bit::str", Static::fin_(&Bit::str));
		index->update_("strange::Byte::buf", Static::fin_(&Byte::buf));
		index->update_("strange::Byte::str", Static::fin_(&Byte::str));
		index->update_("strange::Int16::buf", Static::fin_(&Int16::buf));
		index->update_("strange::Int16::str", Static::fin_(&Int16::str));
		index->update_("strange::Int32::buf", Static::fin_(&Int32::buf));
		index->update_("strange::Int32::str", Static::fin_(&Int32::str));
		index->update_("strange::Int64::buf", Static::fin_(&Int64::buf));
		index->update_("strange::Int64::str", Static::fin_(&Int64::str));
		index->update_("strange::Float32::buf", Static::fin_(&Float32::buf));
		index->update_("strange::Float32::str", Static::fin_(&Float32::str));
		index->update_("strange::Float64::buf", Static::fin_(&Float64::buf));
		index->update_("strange::Float64::str", Static::fin_(&Float64::str));
		index->finalize_();
		return factory;
	}();
	return FACTORY;
}

} // namespace strange

#endif
