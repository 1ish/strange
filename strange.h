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

class Thing
{
public:
	using Ptr = std::shared_ptr<Thing>;
	using Weak = std::weak_ptr<Thing>;

	template <typename... Args>
	inline const Ptr call_(Args&&... args)
	{
		std::vector<Ptr> v;
		v.reserve(sizeof...(Args));
		variadic_(v, std::forward<Args>(args)...);
		return thing(Iterator<std::vector<Ptr>>::mut_(std::move(v)));
	}

	static inline void variadic_(std::vector<Ptr>& vec)
	{
	}

	template <typename... Args>
	static inline void variadic_(std::vector<Ptr>& vec, const char* const symbol, Args&&... args)
	{
		vec.push_back(sym_(symbol));
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

	inline const bool is_(const Ptr symbol) const;

	inline const Ptr is(const Ptr it) const
	{
		return boolean_(is_(it->next_()));
	}

	virtual inline size_t hash_() const
	{
		return (size_t)(this);
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

	virtual inline const Ptr copy_() const = 0;

	inline const Ptr copy(const Ptr ignore) const
	{
		return copy_();
	}

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

	static inline void log_(const char* const message)
	{
		std::cout << message;
	}

	static inline void log_(const Ptr ptr);

	static inline const Ptr log(const Ptr it)
	{
		log_(it->next_());
		return nothing_();
	}

	virtual inline const Ptr to_buffer_() const;

	inline const Ptr to_buffer(const Ptr ignore) const
	{
		return to_buffer_();
	}

	virtual inline void from_buffer_(const Ptr buffer);

	inline const Ptr from_buffer(const Ptr it)
	{
		from_buffer_(it->next_());
		return nothing_();
	}
	
	virtual inline const Ptr type_() const = 0;

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

template <typename T>
class Me
{
protected:
	Me() = default;

	template <typename... Args>
	static inline const Thing::Ptr make_(Args&&... args)
	{
		const Thing::Ptr result = std::make_shared<T>(std::forward<Args>(args)...);
		static_cast<T*>(result.get())->_me = result;
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

class Symbol : public Thing, public Me<Symbol>
{
public:
	inline Symbol(const char* const symbol)
		: Me()
		, _symbol(symbol)
		, _hash(std::hash<std::string>()(symbol))
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

	inline const char* const symbol_() const
	{
		return _symbol;
	}

	virtual inline const Ptr copy_() const override
	{
		return me_();
	}

	static inline const Ptr fin_(const char* const symbol)
	{
		return make_(symbol);
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
	const char* const _symbol;
	const size_t _hash;
};

inline const bool Thing::is_(const char* const symbol) const
{
	const Symbol* const sym = dynamic_cast<const Symbol*>(this);
	return (sym && (strcmp(symbol, sym->symbol_()) == 0));
}

inline const bool Thing::is_(const Thing::Ptr symbol) const
{
	const Symbol* const sym = dynamic_cast<const Symbol*>(symbol.get());
	return (sym && is_(sym->symbol_()));
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

class Static : public Thing, public Me<Static>
{
	using function = const Ptr(*)(const Ptr);

public:
	Static(const function fun)
		: Me()
		, _function(fun)
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
		: Me<Member<T>>()
		, _function(fun)
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
		: Me<Const<T>>()
		, _function(fun)
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
		: Thing()
		, _finalized(false)
	{
	}

private:
	bool _finalized;
};

class Index : public Mutable, public Me<Index>
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
			return lhs->same_(rhs);
		}
	};

	using std_unordered_map_ptr_ptr = std::unordered_map<Ptr, Ptr, Hash, Pred>;

public:
	Index() = default;

	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_();
		static_cast<Index*>(result.get())->_map = _map;
		return result;
	}

	virtual inline const Ptr pub_() const override
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
		return make_();
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	inline const Ptr find(const Ptr it) const
	{
		return find_(it->next_());
	}

	inline const Ptr find_(const char* const symbol) const
	{
		return find_(sym_(symbol));
	}

	inline const Ptr find_(const Ptr key) const
	{
		const std_unordered_map_ptr_ptr::const_iterator mit = _map.find(key);
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

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Index");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

	virtual const Ptr visit(const Ptr it) override
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		if (visitor->call_(member, it->next_())->is_("0"))
		{
			return visitor;
		}
		for (const auto& visited : _map)
		{
			visited.first->call_("visit", visitor, member, visited.first);
			visited.second->call_("visit", visitor, member, visited.second);
		}
		return visitor;
	}

private:
	std_unordered_map_ptr_ptr _map;

	class It : public Mutable
	{
	public:
		inline It(const Ptr index)
			: Mutable()
			, _index(index)
			, _iterator(static_cast<Index*>(_index.get())->_map.begin())
		{
		}

		virtual inline const Ptr next_() override;

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_index);
			static_cast<It*>(result.get())->_iterator = _iterator;
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
		Index* const index = static_cast<Index*>(pub.get());
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
		index->update_("to_buffer", Const<Thing>::fin_(&Thing::to_buffer));
		index->update_("from_buffer", Member<Thing>::fin_(&Thing::from_buffer));
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

	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
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
	template <typename F>
	inline Iterator(F&& collection)
		: Mutable()
		, _collection(std::forward<F>(collection))
		, _iterator(_collection.cbegin())
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
		const Ptr result = mut_(C(_collection));
		static_cast<Iterator*>(result.get())->_iterator += (_iterator - _collection.cbegin());
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

class Flock : public Mutable, public Me<Flock>
{
	using std_vector_ptr = std::vector<Ptr>;

public:
	Flock() = default;

	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_();
		static_cast<Flock*>(result.get())->_vector = _vector;
		return result;
	}

	virtual inline const Ptr pub_() const override
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
		return make_();
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

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Flock");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

	virtual const Ptr visit(const Ptr it) override
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		if (visitor->call_(member, it->next_())->is_("0"))
		{
			return visitor;
		}
		for (const auto& visited : _vector)
		{
			visited->call_("visit", visitor, member, visited);
		}
		return visitor;
	}

private:
	std_vector_ptr _vector;

	class It : public Mutable
	{
	public:
		inline It(const Ptr flock)
			: Mutable()
			, _flock(flock)
			, _iterator(static_cast<Flock*>(_flock.get())->_vector.begin())
		{
		}

		virtual const Ptr next_() override
		{
			if (_iterator == static_cast<Flock*>(_flock.get())->_vector.cend())
			{
				return end_();
			}
			return *_iterator++;
		}

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_flock);
			static_cast<It*>(result.get())->_iterator = _iterator;
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
	if (_iterator == static_cast<Index*>(_index.get())->_map.cend())
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

class Herd : public Mutable, public Me<Herd>
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
			return lhs->same_(rhs);
		}
	};

	using std_unordered_set_ptr = std::unordered_set<Ptr, Hash, Pred>;

public:
	Herd() = default;

	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_();
		static_cast<Herd*>(result.get())->_set = _set;
		return result;
	}

	virtual inline const Ptr pub_() const override
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
		return make_();
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

	virtual const Ptr visit(const Ptr it) override
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		if (visitor->call_(member, it->next_())->is_("0"))
		{
			return visitor;
		}
		for (const auto& visited : _set)
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
	std_unordered_set_ptr _set;

	class It : public Mutable
	{
	public:
		inline It(const Ptr herd)
			: Mutable()
			, _herd(herd)
			, _iterator(static_cast<Herd*>(_herd.get())->_set.begin())
		{
		}

		virtual inline const Ptr next_() override
		{
			if (_iterator == static_cast<Herd*>(_herd.get())->_set.cend())
			{
				return end_();
			}
			return *_iterator++;
		}

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_herd);
			static_cast<It*>(result.get())->_iterator = _iterator;
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
		const Ptr _herd;
		std_unordered_set_ptr::const_iterator _iterator;
	};
};

template <typename D>
class Data : public Mutable
{
public:
	Data(const D& data)
		: Mutable()
		, _data(data)
	{
	}

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Data>(data);
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
		ptr->from_buffer_(buffer);
		return ptr;
	}

	static inline const Ptr buf(const Ptr it)
	{
		return buf_(it->next_());
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(_data);
	}

	inline void set_(const D& data)
	{
		_data = data;
	}

	inline const D& get_() const
	{
		return _data;
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Data");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_cast<Herd*>(cats.get());
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	D _data;
};

class Buffer : public Data<std::string>
{
public:
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
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
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

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Buffer");
		return TYPE;
	}
};

inline void Thing::log_(const Thing::Ptr ptr)
{
	const Ptr buffer = ptr->to_buffer_();
	log_(static_cast<const Buffer*>(ptr.get())->get_().c_str());
}

inline const Thing::Ptr Thing::to_buffer_() const
{
	const Ptr buffer = Buffer::mut_(std::string());
	if (finalized_())
	{
		buffer->finalize_();
	}
	return buffer;
}

inline void Thing::from_buffer_(const Thing::Ptr buffer)
{
	Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
	if (!buf)
	{
		log_("Thing::from_buffer_ called with wrong type of thing");
		return;
	}
	if (buf->finalized_())
	{
		finalize_();
	}
}

inline const Thing::Ptr Symbol::to_buffer_() const
{
	const Ptr buffer = Buffer::mut_(std::string(_symbol));
	buffer->finalize_();
	return buffer;
}

class Bit : public Data<bool>
{
public:
	static inline const Ptr mut(const Ptr it)
	{
		return mut_(!it->next_()->is_("0"));
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_cast<Index*>(pub.get());
			index->update_("mut", Static::fin_(&Bit::mut));
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
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
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
};

class Byte : public Data<unsigned char>
{
public:
	virtual inline const Ptr to_buffer_() const override
	{
		const Ptr buffer = Buffer::mut_(std::string(1, *reinterpret_cast<const char*>(&get_())));
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
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
};

class Int16 : public Data<int16_t>
{
public:
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
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
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
};

class Int32 : public Data<int32_t>
{
public:
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
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
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
};

class Int64 : public Data<int64_t>
{
public:
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
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
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
};

inline const Thing::Ptr Thing::hash(const Thing::Ptr ignore) const
{
	return Int64::fin_(hash_());
}

class Float32 : public Data<float>
{
public:
	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(4, 0);
		uint32_t i = *reinterpret_cast<const uint32_t*>(&get_());
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
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
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
};

class Float64 : public Data<double>
{
public:
	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(8, 0);
		uint64_t i = *reinterpret_cast<const uint64_t*>(&get_());
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
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
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
};

class Fence : public Mutable
{
public:
	inline Fence(const Ptr ptr)
		: Mutable()
		, _fence()
		, _ptr(ptr)
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
			Index* const index = static_cast<Index*>(pub.get());
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
			Herd* const herd = static_cast<Herd*>(cats.get());
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

class Stream : public Mutable, public Me<Stream>
{
	using const_std_unique_iostream = const std::unique_ptr<std::iostream>;

public:
	Stream(std::iostream* const stream)
		: Mutable()
		, _stream(stream)
	{
	}

	static inline const Ptr mut_(std::iostream* const stream)
	{
		return make_(stream);
	}

	virtual inline const Ptr copy_() const override
	{
		return me_();
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
			Herd* const herd = static_cast<Herd*>(cats.get());
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Stream");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	inline void push_back_(const Ptr ptr)
	{
		const Ptr type = ptr->type_();
		const Ptr buffer = ptr->to_buffer_();
		Buffer* const buf = static_cast<Buffer*>(buffer.get());
		write_(Bit::mut_(buf->finalized_()));
		write_(Int16::mut_(int16_t(strlen(static_cast<Symbol*>(type.get())->symbol_()))));
		write_(type);
		write_(Int64::mut_(buf->get_().length()));
		write_(buffer);
	}

	inline void write_(const Ptr ptr)
	{
		const Ptr buffer = ptr->to_buffer_();
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
		if (buf)
		{
			const std::string& str = buf->get_();
			_stream->write(str.data(), str.length());
		}
	}

	inline const Ptr pop_front_()
	{
		const Ptr bit = Bit::buf(read_(1));
		const Ptr int16 = Int16::buf(read_(2));
		const std::string function = static_cast<Buffer*>(read_(static_cast<Int16*>(int16.get())->get_()).get())->get_() + "::buf";
		const Ptr fun = static_cast<Index*>(factory_().get())->find_(function.c_str());
		if (fun->is_("0"))
		{
			log_("Stream::pop_front_ read unknown type");
			return fun;
		}
		const Ptr int64 = Int64::buf_(read_(8));
		const Ptr result = fun->call_(read_(size_t(static_cast<Int64*>(int64.get())->get_())));
		if (static_cast<Bit*>(bit.get())->get_())
		{
			result->finalize_();
		}
		return result;
	}

	inline const Ptr read_(const size_t length)
	{
		std::string str(length, 0);
		_stream->read(const_cast<char*>(str.data()), length);
		return Buffer::mut_(str);
	}

private:
	const_std_unique_iostream _stream;
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

template <typename C>
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

inline const Thing::Ptr Thing::factory_()
{
	static const Ptr FACTORY = []()
	{
		const Ptr factory = Index::mut_();
		Index* const index = static_cast<Index*>(factory.get());
		index->update_("strange::Index::mut", Static::fin_(&Index::mut));
		index->update_("strange::Flock::mut", Static::fin_(&Flock::mut));
		index->update_("strange::Herd::mut", Static::fin_(&Herd::mut));
		index->update_("strange::Buffer::buf", Static::fin_(&Buffer::buf));
		index->update_("strange::Bit::buf", Static::fin_(&Bit::buf));
		index->update_("strange::Byte::buf", Static::fin_(&Byte::buf));
		index->update_("strange::Int16::buf", Static::fin_(&Int16::buf));
		index->update_("strange::Int32::buf", Static::fin_(&Int32::buf));
		index->update_("strange::Int64::buf", Static::fin_(&Int64::buf));
		index->update_("strange::Float32::buf", Static::fin_(&Float32::buf));
		index->update_("strange::Float64::buf", Static::fin_(&Float64::buf));
		index->finalize_();
		return factory;
	}();
	return FACTORY;
}

} // namespace strange

#endif
