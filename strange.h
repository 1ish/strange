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

namespace strange
{

class Thing
{
public:
	typedef std::shared_ptr<Thing> Ptr;
	typedef std::weak_ptr<Thing> Weak;

	template<typename... Args>
	inline const Ptr call_(Args... args)
	{
		std::vector<Ptr>* const v = new std::vector<Ptr>;
		variadic_(*v, args...);
		return thing(Iterator<const std::vector<Ptr>>::mut_(v));
	}

	static inline void variadic_(std::vector<Ptr>& vec)
	{
	}

	template<typename... Args>
	static inline void variadic_(std::vector<Ptr>& vec, const char* const symbol, Args... args)
	{
		vec.push_back(sym_(symbol));
		variadic_(vec, args...);
	}

	template<typename... Args>
	static inline void variadic_(std::vector<Ptr>& vec, Thing& thing, Args... args)
	{
		for (Ptr p = thing.next_(); !p->is_("end"); p = thing.next_())
		{
			vec.push_back(p);
		}
		variadic_(vec, args...);
	}

	template<typename... Args>
	static inline void variadic_(std::vector<Ptr>& vec, const Ptr ptr, Args... args)
	{
		vec.push_back(ptr);
		variadic_(vec, args...);
	}

	inline const Ptr thing(const Ptr it)
	{
		return operator()(this, it);
	}

	virtual ~Thing() = default;

	virtual inline const Ptr next_()
	{
		return end_();
	}

	inline const Ptr next(const Ptr ignore)
	{
		return next_();
	}

	inline const bool is_(const char* const symbol) const;

	virtual inline size_t hash_() const
	{
		return (size_t)(this);
	}

	virtual inline const bool same_(const Thing& other) const
	{
		return (this == &other);
	}

	virtual inline const Ptr copy_() const = 0;

	inline const Ptr copy(const Ptr ignore) const
	{
		return copy_();
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

	static inline const Ptr boolean_(const bool value)
	{
		return value ? one_() : nothing_();
	}

	static inline const Ptr boolean(const Ptr it)
	{
		return boolean_(!it->next_()->is_("0"));
	}

	static inline const Ptr factory(const Ptr it);

	virtual inline const Ptr pub_() const;

	inline const Ptr pub(const Ptr ignore) const
	{
		return pub_();
	}

	static inline const Ptr sym_(const char* const symbol);

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

	static inline const Ptr log_(const char* const message)
	{
		std::cout << message;
		return nothing_();
	}

	virtual inline const Ptr type_() const
	{
		static const Ptr TYPE = sym_("strange::Thing");
		return TYPE;
	}

	inline const Ptr type(const Ptr ignore) const
	{
		return type_();
	}

	virtual inline const Ptr cats_() const;

	inline const Ptr cats(const Ptr ignore) const
	{
		return cats_();
	}

	virtual const Ptr visit(const Ptr it)
	{
		const Ptr visitor = it->next_();
		visitor->thing(it);
		return visitor;
	}

protected:
	Thing() = default;

	static inline const Ptr thing_(Thing* const thing, const Ptr member, const Ptr it)
	{
		return member->operator()(thing, it);
	}

	virtual inline const Ptr operator()(Thing* const thing, const Ptr it);

private:
	Thing(const Thing&) = delete;
	Thing& operator=(const Thing& thing) = delete;
};

class Me
{
protected:
	Me() = default;

	template<typename T>
	static inline const Thing::Ptr me_(T* const thing)
	{
		const Thing::Ptr result = Thing::Ptr(thing);
		thing->_me = result;
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

class Symbol : public Thing, public Me
{
public:
	virtual inline size_t hash_() const
	{
		return _hash;
	}

	virtual inline const bool same_(const Thing& other) const
	{
		return other.is_(_symbol);
	}

	inline const char* const symbol_() const
	{
		return _symbol;
	}

	virtual inline const Ptr copy_() const
	{
		return me_();
	}

	static inline const Ptr fin_(const char* const symbol)
	{
		return me_<Symbol>(new Symbol(symbol));
	}

	virtual inline const Ptr type_() const
	{
		static const Ptr TYPE = sym_("strange::Symbol");
		return TYPE;
	}

	virtual inline const Ptr cats_() const;

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it)
	{
		return me_();
	}

private:
	inline Symbol(const char* const symbol)
		: Me()
		, _symbol(symbol)
		, _hash(std::hash<std::string>()(symbol))
	{
	}

	const char* const _symbol;
	const size_t _hash;
};

inline const bool Thing::is_(const char* const symbol) const
{
	const Symbol* const sym = dynamic_cast<const Symbol*>(this);
	return (sym && (strcmp(symbol, sym->symbol_()) == 0));
}

inline const Thing::Ptr Thing::sym_(const char* const symbol)
{
	return Symbol::fin_(symbol);
}

inline const Thing::Ptr Thing::nothing_()
{
	static const Ptr NOTHING(sym_("0"));
	return NOTHING;
}

inline const Thing::Ptr Thing::one_()
{
	static const Ptr ONE(sym_("1"));
	return ONE;
}

inline const Thing::Ptr Thing::end_()
{
	static const Ptr END(sym_("end"));
	return END;
}

class Static : public Thing, public Me
{
	typedef const Ptr(*function)(const Ptr);

public:
	static inline const Ptr fin_(const function fun)
	{
		return me_<Static>(new Static(fun));
	}

	virtual inline const Ptr copy_() const
	{
		return me_();
	}

	virtual inline const Ptr type_() const
	{
		static const Ptr TYPE = sym_("strange::Static");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it)
	{
		return _function(it);
	}

private:
	Static(const function fun)
		: Me()
		, _function(fun)
	{
	}

	const function _function;
};

template <typename T>
class Member : public Thing, public Me
{
	typedef const Ptr(T::* member)(const Ptr);

public:
	static inline const Ptr fin_(const member fun)
	{
		return me_<Member>(new Member(fun));
	}

	virtual inline const Ptr copy_() const
	{
		return me_();
	}

	virtual inline const Ptr type_() const
	{
		static const Ptr TYPE = sym_("strange::Member");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it)
	{
		T* const t = dynamic_cast<T*>(thing);
		if (t)
		{
			if (t->finalized_())
			{
				return log_("ERROR: Member passed finalized thing\n");
			}
			return (t->*_function)(it);
		}
		return log_("ERROR: Member passed wrong type of thing\n");
	}

private:
	Member(const member fun)
		: Me()
		, _function(fun)
	{
	}

	const member _function;
};

template <typename T>
class Const : public Thing, public Me
{
	typedef const Ptr(T::* member)(const Ptr) const;

public:
	static inline const Ptr fin_(const member fun)
	{
		return me_<Const>(new Const(fun));
	}

	virtual inline const Ptr copy_() const
	{
		return me_();
	}

	virtual inline const Ptr type_() const
	{
		static const Ptr TYPE = sym_("strange::Const");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it)
	{
		T* const t = dynamic_cast<T*>(thing);
		if (t)
		{
			return (t->*_function)(it);
		}
		return log_("ERROR: Const passed wrong type of thing\n");
	}

private:
	Const(const member fun)
		: Me()
		, _function(fun)
	{
	}

	const member _function;
};

class Mutable : public Thing
{
public:
	virtual inline void finalize_()
	{
		_finalized = true;
	}

	virtual inline const bool finalized_() const
	{
		return _finalized;
	}

	virtual inline const Ptr type_() const
	{
		static const Ptr TYPE = sym_("strange::Mutable");
		return TYPE;
	}

protected:
	inline Mutable()
		: Thing()
		, _finalized(false)
	{
	}

private:
	bool _finalized;
};

class Index : public Mutable, public Me
{
	class Hash
	{
	public:
		inline size_t operator()(const Ptr& ptr) const
		{
			return ptr->hash_();
		}
	};

	class Pred
	{
	public:
		inline const bool operator()(const Ptr& lhs, const Ptr& rhs) const
		{
			return lhs->same_(*rhs);
		}
	};

	typedef std::unordered_map<Ptr, Ptr, Hash, Pred> std_unordered_map_ptr_ptr;

public:
	virtual inline const Ptr copy_() const
	{
		const Ptr result = mut_();
		static_cast<Index*>(result.get())->_map = _map;
		return result;
	}

	virtual inline const Ptr pub_() const
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_cast<Index*>(pub.get());
			index->update_("mut", Static::fin_(&Index::mut));
			index->update_("find", Const<Index>::fin_(&Index::find));
			index->update_("update", Member<Index>::fin_(&Index::update));
			index->update_("iterator", Const<Index>::fin_(&Index::iterator));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr mut_()
	{
		return me_<Index>(new Index);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	inline const Ptr find(const Ptr it) const
	{
		const std_unordered_map_ptr_ptr::const_iterator mit = _map.find(it->next_());
		if (mit == _map.end())
		{
			return nothing_();
		}
		return mit->second;
	}

	inline const Ptr update(const Ptr it)
	{
		const Ptr key = it->next_();
		const Ptr value = it->next_();
		return update_(key, value);
	}

	inline const Ptr update_(const Ptr key, const Ptr value)
	{
		return _map[key] = value;
	}

	inline const Ptr update_(const char* const key, const Ptr value)
	{
		return update_(sym_(key), value);
	}

	inline const Ptr iterator_() const
	{
		return It::mut_(me_());
	}

	inline const Ptr iterator(const Ptr ignore) const
	{
		return iterator_();
	}

	virtual inline const Ptr type_() const
	{
		static const Ptr TYPE = sym_("strange::Index");
		return TYPE;
	}

	virtual inline const Ptr cats_() const;

	virtual const Ptr visit(const Ptr it)
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		if (visitor->call_(member, it->next_())->is_("0"))
		{
			return visitor;
		}
		for (auto visited : _map)
		{
			visited.first->call_("visit", visitor, member, visited.first);
			visited.second->call_("visit", visitor, member, visited.second);
		}
		return visitor;
	}

private:
	Index() = default;

	std_unordered_map_ptr_ptr _map;

	class It : public Mutable
	{
	public:
		virtual inline const Ptr next_();

		virtual inline const Ptr copy_() const
		{
			const Ptr result = mut_(_index);
			static_cast<It*>(result.get())->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr index)
		{
			return Ptr(new It(index));
		}

		virtual inline const Ptr type_() const
		{
			static const Ptr TYPE = sym_("strange::Index:It");
			return TYPE;
		}

		virtual inline const Ptr cats_() const;

	private:
		inline It(const Ptr index)
			: Mutable()
			, _index(index)
			, _iterator(static_cast<Index*>(_index.get())->_map.begin())
		{
		}

		const Ptr _index;
		std_unordered_map_ptr_ptr::const_iterator _iterator;
	};
};

inline const Thing::Ptr Thing::pub_() const
{
	static const Ptr PUB = []()
	{
		const Ptr pub = Index::mut_();
		Index* const index = static_cast<Index*>(pub.get());
		index->update_("thing", Member<Thing>::fin_(&Thing::thing));
		index->update_("next", Member<Thing>::fin_(&Thing::next));
		index->update_("copy", Const<Thing>::fin_(&Thing::copy));
		index->update_("finalize", Member<Thing>::fin_(&Thing::finalize));
		index->update_("finalized", Const<Thing>::fin_(&Thing::finalized));
		index->update_("freeze", Member<Thing>::fin_(&Thing::freeze));
		index->update_("boolean", Static::fin_(&Thing::boolean));
		index->update_("factory", Static::fin_(&Thing::factory));
		index->update_("pub", Const<Thing>::fin_(&Thing::pub));
		index->update_(nothing_(), nothing_());
		index->update_(one_(), one_());
		index->update_(end_(), end_());
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
	const Ptr member = static_cast<Index*>(pub_().get())->find(it);
	return thing_(thing, member, it);
}

class Decorator : public Thing
{
protected:
	inline Decorator(const Ptr decorated)
		: Thing()
		, _decorated(decorated)
	{
	}

	virtual inline const Ptr operator()(Thing* const thing, const Ptr it)
	{
		const Ptr cit = it->copy_();
		const Ptr member = static_cast<Index*>(pub_().get())->find(it);
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
	virtual inline const Ptr next_()
	{
		if (_iterator == _collection->cend())
		{
			return end_();
		}
		return *_iterator++;
	}

	virtual inline const Ptr copy_() const
	{
		const Ptr result = mut_(0);
		Iterator* const iterator = static_cast<Iterator*>(result.get());
		iterator->_collection = _collection;
		iterator->_iterator = _iterator;
		return result;
	}

	static inline const Ptr mut_(C* const collection)
	{
		return Ptr(new Iterator(collection));
	}

	virtual inline const Ptr type_() const
	{
		static const Ptr TYPE = sym_("strange::Iterator");
		return TYPE;
	}

	virtual inline const Ptr cats_() const;

private:
	inline Iterator(C* const collection)
		: Mutable()
		, _collection(collection)
		, _iterator(collection->cbegin())
	{
	}

	std::shared_ptr<C> _collection;
	typename C::const_iterator _iterator;
};

class Flock : public Mutable, public Me
{
	typedef std::vector<Ptr> std_vector_ptr;

public:
	virtual inline const Ptr copy_() const
	{
		const Ptr result = mut_();
		static_cast<Flock*>(result.get())->_vector = _vector;
		return result;
	}

	virtual inline const Ptr pub_() const
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_cast<Index*>(pub.get());
			index->update_("mut", Static::fin_(&Flock::mut));
			index->update_("push_back", Member<Flock>::fin_(&Flock::push_back));
			index->update_("iterator", Const<Flock>::fin_(&Flock::iterator));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr mut_()
	{
		return me_<Flock>(new Flock);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
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

	virtual inline const Ptr type_() const
	{
		static const Ptr TYPE = sym_("strange::Flock");
		return TYPE;
	}

	virtual inline const Ptr cats_() const;

	virtual const Ptr visit(const Ptr it)
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		if (visitor->call_(member, it->next_())->is_("0"))
		{
			return visitor;
		}
		for (auto visited : _vector)
		{
			visited->call_("visit", visitor, member, visited);
		}
		return visitor;
	}

private:
	Flock() = default;

	std_vector_ptr _vector;

	class It : public Mutable
	{
	public:
		virtual const Ptr next_()
		{
			if (_iterator == static_cast<Flock*>(_flock.get())->_vector.end())
			{
				return end_();
			}
			return *_iterator++;
		}

		virtual inline const Ptr copy_() const
		{
			const Ptr result = mut_(_flock);
			static_cast<It*>(result.get())->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr flock)
		{
			return Ptr(new It(flock));
		}

		virtual inline const Ptr type_() const
		{
			static const Ptr TYPE = sym_("strange::Flock::It");
			return TYPE;
		}

		virtual inline const Ptr cats_() const;

	private:
		inline It(const Ptr flock)
			: Mutable()
			, _flock(flock)
			, _iterator(static_cast<Flock*>(_flock.get())->_vector.begin())
		{
		}

		const Ptr _flock;
		std_vector_ptr::const_iterator _iterator;
	};
};

inline const Thing::Ptr Index::It::next_()
{
	if (_iterator == static_cast<Index*>(_index.get())->_map.end())
	{
		return end_();
	}
	const Ptr result = Flock::mut_();
	Flock* const flock = static_cast<Flock*>(result.get());
	flock->push_back(_iterator->first);
	flock->push_back(_iterator->second);
	flock->finalize_();
	++_iterator;
	return result;
}

class Herd : public Mutable, public Me
{
	class Hash
	{
	public:
		inline size_t operator()(const Ptr& ptr) const
		{
			return ptr->hash_();
		}
	};

	class Pred
	{
	public:
		inline const bool operator()(const Ptr& lhs, const Ptr& rhs) const
		{
			return lhs->same_(*rhs);
		}
	};

	typedef std::unordered_set<Ptr, Hash, Pred> std_unordered_set_ptr;

public:
	virtual inline const Ptr copy_() const
	{
		const Ptr result = mut_();
		static_cast<Herd*>(result.get())->_set = _set;
		return result;
	}

	virtual inline const Ptr pub_() const
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_cast<Index*>(pub.get());
			index->update_("mut", Static::fin_(&Herd::mut));
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
		return me_<Herd>(new Herd);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	inline const Ptr find(const Ptr it) const
	{
		const std_unordered_set_ptr::const_iterator sit = _set.find(it->next_());
		if (sit == _set.end())
		{
			return nothing_();
		}
		return *sit;
	}

	inline const Ptr insert(const Ptr it)
	{
		return boolean_(_set.insert(it->next_()).second);
	}

	inline const Ptr insert_(const char* const key)
	{
		return insert(sym_(key));
	}

	inline const Ptr iterator_() const
	{
		return It::mut_(me_());
	}

	inline const Ptr iterator(const Ptr ignore) const
	{
		return iterator_();
	}

	virtual inline const Ptr type_() const
	{
		static const Ptr TYPE = sym_("strange::Herd");
		return TYPE;
	}

	virtual inline const Ptr cats_() const
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_cast<Herd*>(cats.get());
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Iterable");
			herd->insert_("strange::Herd");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual const Ptr visit(const Ptr it)
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		if (visitor->call_(member, it->next_())->is_("0"))
		{
			return visitor;
		}
		for (auto visited : _set)
		{
			visited->call_("visit", visitor, member, visited);
		}
		return visitor;
	}

	inline const Ptr gather(const Ptr it)
	{
		const Ptr visited = it->next_();
		return visited->call_("visit", me_(), "insert", visited);
	}

private:
	Herd() = default;

	std_unordered_set_ptr _set;

	class It : public Mutable
	{
	public:
		virtual inline const Ptr next_()
		{
			if (_iterator == static_cast<Herd*>(_herd.get())->_set.end())
			{
				return end_();
			}
			return *_iterator++;
		}

		virtual inline const Ptr copy_() const
		{
			const Ptr result = mut_(_herd);
			static_cast<It*>(result.get())->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr herd)
		{
			return Ptr(new It(herd));
		}

		virtual inline const Ptr type_() const
		{
			static const Ptr TYPE = sym_("strange::Herd::It");
			return TYPE;
		}

		virtual inline const Ptr cats_() const
		{
			static const Ptr CATS = []()
			{
				const Ptr cats = Herd::mut_();
				Herd* const herd = static_cast<Herd*>(cats.get());
				herd->insert_("strange::Mutable");
				herd->insert_("strange::Iterator");
				herd->insert_("strange::Thing");
				herd->finalize_();
				return cats;
			}();
			return CATS;
		}

	private:
		inline It(const Ptr herd)
			: Mutable()
			, _herd(herd)
			, _iterator(static_cast<Herd*>(_herd.get())->_set.begin())
		{
		}

		const Ptr _herd;
		std_unordered_set_ptr::const_iterator _iterator;
	};
};

class Stream : public Mutable, public Me
{
	typedef std::unique_ptr<std::iostream> std_unique_iostream;
public:

private:
	Stream() = default;

	std_unique_iostream _stream;
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
		Herd* const herd = static_cast<Herd*>(cats.get());
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
		Herd* const herd = static_cast<Herd*>(cats.get());
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
		Herd* const herd = static_cast<Herd*>(cats.get());
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterator");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

template<typename C>
inline const Thing::Ptr Iterator<C>::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_cast<Herd*>(cats.get());
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
		Herd* const herd = static_cast<Herd*>(cats.get());
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
		Herd* const herd = static_cast<Herd*>(cats.get());
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterator");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Thing::factory(const Ptr it)
{
	static const Ptr FACTORY = []()
	{
		const Ptr factory = Index::mut_();
		Index* const index = static_cast<Index*>(factory.get());
		index->update_("strange::Index::mut", Static::fin_(&Index::mut));
		index->update_("strange::Flock::mut", Static::fin_(&Flock::mut));
		index->update_("strange::Herd::mut", Static::fin_(&Herd::mut));
		index->finalize_();
		return factory;
	}();
	return FACTORY;
}

} // namespace strange

#endif
