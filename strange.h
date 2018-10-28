#ifndef COM_ONEISH_STRANGE_H
#define COM_ONEISH_STRANGE_H

#include <memory>
#include <cstring>
#include <iostream>
#include <atomic>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdint>
#include <type_traits>
#include <complex>
#include <shared_mutex>

namespace strange
{
	class Thing;
	class Iterable;
	class Variadic;
	template <typename T> class Me;
	class Serializable;
	class Symbol;
	class Static;
	template <typename T> class Member;
	template <typename T> class Const;
	class Mutable;
	class Shoal;
	class Decorator;
	template <typename C> class Iterator;
	class Flock;
	class Herd;
	template <typename D> class Data;
	class Lake;
	class Number;
	class Bit;
	class Byte;
	class Int16;
	class Int32;
	class Int64;
	class Float32;
	class Float64;
	class Complex32;
	class Complex64;
	class River;
	class Fence;
	class Creator;
	class Creature;
	class Expression;
	class Function;
	class Tokenizer;
	class Parser;

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

//----------------------------------------------------------------------
class Thing
//----------------------------------------------------------------------
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

	template <typename... Args>
	static inline const Ptr call_(Args&&... args);

	static inline const Ptr call(const Ptr it);

	// public static factory functions
	static inline const Ptr stats_();

	static inline const Ptr stats(const Ptr ignore)
	{
		return stats_();
	}

	static inline const Ptr stat_();

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
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

	static inline const Ptr stop_();

	static inline const Ptr stop(const Ptr ignore)
	{
		return stop_();
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
		_finalized_().store(true, std::memory_order_release);
	}

	inline const Ptr finalize(const Ptr ignore)
	{
		finalize_();
		return nothing_();
	}

	virtual inline const bool finalized_() const
	{
		return _finalized_().load(std::memory_order_acquire);
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

	virtual inline const bool frozen_() const
	{
		return finalized_();
	}

	inline const Ptr frozen(const Ptr ignore) const
	{
		return boolean_(frozen_());
	}

	virtual inline const Ptr next_()
	{
		return stop_();
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
		return identical_(other);
	}

	inline const Ptr same(const Ptr it) const
	{
		return boolean_(same_(it->next_()));
	}

	inline const Ptr different(const Ptr it) const
	{
		return boolean_(!same_(it->next_()));
	}

	virtual inline const Ptr visit(const Ptr it)
	{
		const Ptr visitor = it->next_();
		return visitor->invoke(it);
	}

	virtual inline const Ptr cats_() const;

	inline const Ptr cats(const Ptr ignore) const
	{
		return cats_();
	}

	virtual inline const Ptr pub_() const;

	inline const Ptr pub(const Ptr ignore) const
	{
		return pub_();
	}

	// public non-virtual member functions and adapters
	template <typename... Args>
	inline const Ptr invoke_(Args&&... args);

	inline const Ptr invoke(const Ptr it)
	{
		return operator()(this, it);
	}

	inline const int64_t identity_() const
	{
		return int64_t(this);
	}

	inline const Ptr identity(const Ptr ignore) const;

	inline const bool identical_(const Ptr other) const
	{
		return identity_() == other->identity_();
	}

	inline const Ptr identical(const Ptr it) const
	{
		return boolean_(identical_(it->next_()));
	}

	template <typename F>
	inline const bool is_(F&& symbol) const;

	inline const bool is_(const Ptr symbol) const;

	inline const Ptr is(const Ptr it) const
	{
		return boolean_(is_(it->next_()));
	}

	inline const Ptr is_not(const Ptr it) const
	{
		return boolean_(!is_(it->next_()));
	}

protected:
	// protected static utility functions
	static inline const Ptr operate_(Thing* const thing, const Ptr member, const Ptr it)
	{
		return member->operator()(thing, it);
	}

	static inline const Ptr operate_(Thing* const thing, const Ptr member)
	{
		return operate_(thing, member, nothing_());
	}

	// protected construction/destruction/assignment
	Thing() = default;

	// protected impure virtual member functions and adapters
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it);

private:
	// private static utility functions
	static std::atomic<bool>& _finalized_()
	{
		static std::atomic<bool> FINALIZED(true);
		return FINALIZED;
	}
};

//----------------------------------------------------------------------
class Iterable
//----------------------------------------------------------------------
{
public:
	// public pure virtual member functions and adapters
	virtual inline const Thing::Ptr iterator_() const = 0;

	inline const Thing::Ptr iterator(const Thing::Ptr ignore) const
	{
		return iterator_();
	}
};

//----------------------------------------------------------------------
class Variadic
//----------------------------------------------------------------------
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
		for (Ptr p = thing.next_(); !p->is_("."); p = thing.next_())
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
//----------------------------------------------------------------------
class Me
//----------------------------------------------------------------------
{
public:
	inline const Thing::Ptr me_() const
	{
		const Thing::Ptr ptr = _me.lock();
		if (ptr)
		{
			return ptr;
		}
		return Thing::nothing_();
	}

protected:
	Me() = default;

	template <typename... Args>
	static inline const Thing::Ptr make_(Args&&... args)
	{
		const Thing::Ptr result = std::make_shared<T>(std::forward<Args>(args)...);
		Thing::static_<T>(result)->_me = result;
		return result;
	}

private:
	Thing::Weak _me;
};

//----------------------------------------------------------------------
class Serializable
//----------------------------------------------------------------------
{
public:
	// public pure virtual member functions and adapters
	virtual inline const Thing::Ptr to_lake_() const = 0;

	inline const Thing::Ptr to_lake(const Thing::Ptr ignore) const
	{
		return to_lake_();
	}

	// public impure virtual member functions and adapters

	virtual inline void from_lake_(const Thing::Ptr lake)
	{
	}

	inline const Thing::Ptr from_lake(const Thing::Ptr it)
	{
		from_lake_(it->next_());
		return Thing::nothing_();
	}

	virtual inline void to_river_(const Thing::Ptr river) const;

	inline const Thing::Ptr to_river(const Thing::Ptr it) const
	{
		const Thing::Ptr river = it->next_();
		to_river_(river);
		return river;
	}

	virtual inline void from_river_(const Thing::Ptr river);

	inline const Thing::Ptr from_river(const Thing::Ptr it)
	{
		const Thing::Ptr river = it->next_();
		from_river_(river);
		return river;
	}

	virtual inline void to_river_with_links_(const Thing::Ptr shoal, const Thing::Ptr river) const
	{
		const Thing* thing = dynamic_cast<const Thing*>(this);
		if (thing)
		{
			const_cast<Thing*>(thing)->invoke_("to_river", river);
		}
	}

	inline const Thing::Ptr to_river_with_links(const Thing::Ptr it)
	{
		const Thing::Ptr shoal = it->next_();
		const Thing::Ptr river = it->next_();
		to_river_with_links_(shoal, river);
		return river;
	}

	virtual inline void from_river_with_links_(const Thing::Ptr river)
	{
		Thing* thing = dynamic_cast<Thing*>(this);
		if (thing)
		{
			thing->invoke_("from_river", river);
		}
	}

	inline const Thing::Ptr from_river_with_links(const Thing::Ptr it)
	{
		const Thing::Ptr river = it->next_();
		from_river_with_links_(river);
		return river;
	}

	static inline void serialize_(const Thing::Ptr thing, const Thing::Ptr river);

	static inline const Thing::Ptr serialize(const Thing::Ptr it)
	{
		const Thing::Ptr thing = it->next_();
		const Thing::Ptr river = it->next_();
		serialize_(thing, river);
		return river;
	}

	virtual inline void replace_links_(const Thing::Ptr shoal)
	{
	}

	inline const Thing::Ptr replace_links(const Thing::Ptr it)
	{
		replace_links_(it->next_());
		return Thing::nothing_();
	}

	static inline const Thing::Ptr deserialize_(const Thing::Ptr river);

	static inline const Thing::Ptr deserialize(const Thing::Ptr it)
	{
		return deserialize_(it->next_());
	}

	// public non-virtual member functions and adapters
	inline const Thing::Ptr to_lake_via_river_() const;

	inline const Thing::Ptr to_lake_via_river(const Thing::Ptr ignore) const
	{
		return to_lake_via_river_();
	}

	inline void from_lake_via_river_(const Thing::Ptr lake);

	inline const Thing::Ptr from_lake_via_river(const Thing::Ptr it)
	{
		from_lake_via_river_(it->next_());
		return Thing::nothing_();
	}
};

//----------------------------------------------------------------------
class Symbol : public Thing, public Me<Symbol>, public Serializable
//----------------------------------------------------------------------
{
public:
	template <typename F>
	inline Symbol(F&& symbol)
		: Thing{}
		, Me{}
		, Serializable{}
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
		return Me<Symbol>::me_();
	}

	template <typename F>
	static inline const Ptr fin_(F&& symbol)
	{
		const Ptr result = Me<Symbol>::make_(std::forward<F>(symbol));
		result->finalize_();
		return result;
	}

	static inline const Ptr lak_(const Ptr lake);

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river);

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river);

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	static inline const Ptr stat_();

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr to_lake_() const override;

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Symbol");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

	virtual inline const Ptr pub_() const override;

private:
	const std::string _symbol;
	const size_t _hash;
};

//----------------------------------------------------------------------
class Static : public Thing, public Me<Static>
//----------------------------------------------------------------------
{
	using function = const Ptr(*)(const Ptr);

public:
	Static(const function fun)
		: Thing{}
		, Me {}
		, _function{ fun }
	{
	}

	static inline const Ptr fin_(const function fun)
	{
		const Ptr result = Me<Static>::make_(fun);
		result->finalize_();
		return result;
	}

	virtual inline const Ptr copy_() const override
	{
		return Me<Static>::me_();
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
//----------------------------------------------------------------------
class Member : public Thing, public Me<Member<T>>
//----------------------------------------------------------------------
{
	using member = const Ptr(T::*)(const Ptr);

public:
	Member(const member fun)
		: Thing{}
		, Me<Member<T>>{}
		, _function{ fun }
	{
	}

	static inline const Ptr fin_(const member fun)
	{
		const Ptr result = Me<Member<T>>::make_(fun);
		result->finalize_();
		return result;
	}

	virtual inline const Ptr copy_() const override
	{
		return Me<Member<T>>::me_();
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
//----------------------------------------------------------------------
class Const : public Thing, public Me<Const<T>>
//----------------------------------------------------------------------
{
	using member = const Ptr(T::*)(const Ptr) const;

public:
	Const(const member fun)
		: Thing{}
		, Me<Const<T>>{}
		, _function{ fun }
	{
	}

	static inline const Ptr fin_(const member fun)
	{
		const Ptr result = Me<Const<T>>::make_(fun);
		result->finalize_();
		return result;
	}

	virtual inline const Ptr copy_() const override
	{
		return Me<Const<T>>::me_();
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

//----------------------------------------------------------------------
class Mutable : public Thing
//----------------------------------------------------------------------
{
public:
	virtual inline void finalize_() override
	{
		_finalized.store(true, std::memory_order_release);
	}

	virtual inline const bool finalized_() const override
	{
		return _finalized.load(std::memory_order_acquire);
	}

protected:
	inline Mutable()
		: Thing{}
		, _finalized{}
	{
		_finalized.store(false, std::memory_order_release);
	}

private:
	std::atomic<bool> _finalized;
};

//----------------------------------------------------------------------
class Shoal : public Mutable, public Me<Shoal>, public Serializable, public Iterable
//----------------------------------------------------------------------
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
	inline Shoal()
		: Mutable{}
		, Me{}
		, Serializable{}
		, Iterable{}
		, _map{}
		, _frozen{ false }
	{
	}

	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_();
		static_<Shoal>(result)->_map = _map;
		return result;
	}

	virtual inline const Ptr clone_() const override
	{
		const Ptr result = mut_();
		std_unordered_map_ptr_ptr& clone = static_<Shoal>(result)->_map;
		for (const auto& i : _map)
		{
			clone[i.first->clone_()] = i.second->clone_();
		}
		return result;
	}

	virtual inline void freeze_() override
	{
		if (!_frozen)
		{
			for (const auto& i : _map)
			{
				i.first->freeze_();
				i.second->freeze_();
			}
			_frozen = true;
		}
	}

	virtual inline const bool frozen_() const override
	{
		return _frozen;
	}

	virtual inline const Ptr to_lake_() const override
	{
		return to_lake_via_river_();
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		from_lake_via_river_(lake);
	}

	virtual inline void to_river_(const Thing::Ptr river) const override;

	virtual inline void from_river_(const Thing::Ptr river) override;

	virtual inline void to_river_with_links_(const Thing::Ptr shoal, const Thing::Ptr river) const override;

	virtual inline void from_river_with_links_(const Thing::Ptr river) override;

	virtual inline void replace_links_(const Thing::Ptr shoal) override;

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Shoal>::fin_(&Shoal::to_lake));
			shoal->update_("from_lake", Member<Shoal>::fin_(&Shoal::from_lake));
			shoal->update_("to_river", Const<Shoal>::fin_(&Shoal::to_river));
			shoal->update_("from_river", Member<Shoal>::fin_(&Shoal::from_river));
			shoal->update_("stat", Static::fin_(&Shoal::stat));
			shoal->update_("mut", Static::fin_(&Shoal::mut));
			shoal->update_("lak", Static::fin_(&Shoal::lak));
			shoal->update_("riv", Static::fin_(&Shoal::riv));
			shoal->update_("rwl", Static::fin_(&Shoal::rwl));
			shoal->update_("find", Const<Shoal>::fin_(&Shoal::find));
			shoal->update_("update", Member<Shoal>::fin_(&Shoal::update));
			shoal->update_("insert", Member<Shoal>::fin_(&Shoal::insert));
			shoal->update_("iterator", Const<Shoal>::fin_(&Shoal::iterator));
			shoal->update_("itemize", Member<Shoal>::fin_(&Shoal::itemize));
			shoal->update_("gather", Member<Shoal>::fin_(&Shoal::gather));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Shoal::stat));
			shoal->update_("mut", Static::fin_(&Shoal::mut));
			shoal->update_("lak", Static::fin_(&Shoal::lak));
			shoal->update_("riv", Static::fin_(&Shoal::riv));
			shoal->update_("rwl", Static::fin_(&Shoal::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	static inline const Ptr mut_()
	{
		return Me<Shoal>::make_();
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Shoal>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Shoal>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Shoal>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
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

	virtual inline const Ptr iterator_() const override
	{
		return It::mut_(me_());
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Shoal");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

	virtual inline const Ptr visit(const Ptr it) override
	{
		const Ptr rest = it->copy_();
		const Ptr result = Thing::visit(it);
		if (!result->is_("0"))
		{
			const Ptr visitor = rest->next_();
			const Ptr member = rest->next_();
			rest->next_();
			for (const auto& visited : _map)
			{
				visited.first->invoke_("visit", visitor, member, visited.first, *(rest->copy_()));
				visited.second->invoke_("visit", visitor, member, visited.second, *(rest->copy_()));
			}
		}
		return result;
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

	inline void gather_(const Ptr item)
	{
		item->invoke_("visit", Me<Shoal>::me_(), "itemize", item);
	}

	inline const Ptr gather(const Ptr it)
	{
		gather_(it->next_());
		return nothing_();
	}

	inline void gather_to_river_(const Ptr thing, const Ptr river);

	inline const Ptr gather_from_river_(const Ptr river);

	class Concurrent : public Mutable, public Me<Concurrent>
	{
	public:
		inline Concurrent()
			: Mutable{}
			, Me{}
			, _shoal{ Shoal::mut_() }
			, _mutex{}
		{
		}

		virtual inline const Ptr pub_() const override
		{
			static const Ptr PUB = [this]()
			{
				const Ptr pub = Thing::pub_()->copy_();
				Shoal* const shoal = static_<Shoal>(pub);
				shoal->update_("stat", Static::fin_(&Concurrent::stat));
				shoal->update_("find", Const<Concurrent>::fin_(&Concurrent::find));
				shoal->update_("update", Member<Concurrent>::fin_(&Concurrent::update));
				shoal->update_("insert", Member<Concurrent>::fin_(&Concurrent::insert));
				shoal->finalize_();
				return pub;
			}();
			return PUB;
		}

		static inline const Ptr stat_()
		{
			static const Ptr STAT = []()
			{
				const Ptr stat = Shoal::mut_();
				Shoal* const shoal = static_<Shoal>(stat);
				shoal->update_("stat", Static::fin_(&Concurrent::stat));
				shoal->finalize_();
				return stat;
			}();
			return STAT;
		}

		static inline const Ptr stat(const Ptr ignore)
		{
			return stat_();
		}

		static inline const Ptr mut_()
		{
			return Me<Concurrent>::make_();
		}

		virtual inline const Ptr copy_() const override
		{
			return Me<Concurrent>::me_();
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Shoal::Concurrent");
			return TYPE;
		}

		inline const Ptr find_(const Ptr key) const
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return static_<Shoal>(_shoal)->find_(key);
		}

		inline const Ptr find(const Ptr it) const
		{
			return find_(it->next_());
		}

		inline void update_(const Ptr key, const Ptr value)
		{
			if (key->finalized_() && value->finalized_())
			{
				std::unique_lock<std::shared_timed_mutex> lock(_mutex);
				static_<Shoal>(_shoal)->update_(key, value);
			}
		}

		inline const Ptr update(const Ptr it)
		{
			const Ptr key = it->next_();
			const Ptr value = it->next_();
			update_(key, value);
			return value;
		}

		inline const bool insert_(const Ptr key, const Ptr value)
		{
			if (key->finalized_() && value->finalized_())
			{
				std::unique_lock<std::shared_timed_mutex> lock(_mutex);
				return static_<Shoal>(_shoal)->insert_(key, value);
			}
			return false;
		}

		inline const Ptr insert(const Ptr it)
		{
			const Ptr key = it->next_();
			const Ptr value = it->next_();
			return boolean_(insert_(key, value));
		}

	private:
		const Ptr _shoal;
		mutable std::shared_timed_mutex _mutex;
	};

private:
	std_unordered_map_ptr_ptr _map;
	bool _frozen;

	class It : public Mutable
	{
	public:
		inline It(const Ptr shoal)
			: Mutable{}
			, _shoal{ shoal }
			, _iterator{ static_<Shoal>(_shoal)->_map.cbegin() }
		{
		}

		virtual inline const Ptr next_() override;

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_shoal);
			static_<It>(result)->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr shoal)
		{
			return std::make_shared<It>(shoal);
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Shoal:It");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override;

	private:
		const Ptr _shoal;
		std_unordered_map_ptr_ptr::const_iterator _iterator;
	};
};

//----------------------------------------------------------------------
class Decorator : public Thing
//----------------------------------------------------------------------
{
protected:
	inline Decorator(const Ptr decorated)
		: Thing{}
		, _decorated{ decorated }
	{
	}

	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		const Ptr name = it->next_();
		const Ptr member = static_<Shoal>(pub_())->find_(name);
		if (member->is_("0"))
		{
			return _decorated->invoke_(name, *it);
		}
		return operate_(thing, member, it);
	}

	const Ptr _decorated;
};

template <typename C>
//----------------------------------------------------------------------
class Iterator : public Mutable
//----------------------------------------------------------------------
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
			return stop_();
		}
		return *_iterator++;
	}

	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_(_collection);
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

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		const Ptr member = static_<Shoal>(pub_())->find_(it->next_());
		if (member->is_("0"))
		{
			return member;
		}
		return operate_(thing, member, it);
	}

private:
	const C _collection;
	typename C::const_iterator _iterator;
};

//----------------------------------------------------------------------
class Flock : public Mutable, public Me<Flock>, public Serializable, public Iterable
//----------------------------------------------------------------------
{
	using std_vector_ptr = std::vector<Ptr>;

public:
	inline Flock()
		: Mutable{}
		, Me{}
		, Serializable{}
		, Iterable{}
		, _vector{}
		, _frozen{ false }
	{
	}

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
		if (!_frozen)
		{
			for (const auto i : _vector)
			{
				i->freeze_();
			}
			_frozen = true;
		}
	}

	virtual inline const bool frozen_() const override
	{
		return _frozen;
	}

	virtual inline const Ptr to_lake_() const override
	{
		return to_lake_via_river_();
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		from_lake_via_river_(lake);
	}

	virtual inline void to_river_(const Thing::Ptr river) const override;

	virtual inline void from_river_(const Thing::Ptr river) override;

	virtual inline void to_river_with_links_(const Thing::Ptr shoal, const Thing::Ptr river) const override;

	virtual inline void from_river_with_links_(const Thing::Ptr river) override;

	virtual inline void replace_links_(const Thing::Ptr shoal) override;

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Flock>::fin_(&Flock::to_lake));
			shoal->update_("from_lake", Member<Flock>::fin_(&Flock::from_lake));
			shoal->update_("to_river", Const<Flock>::fin_(&Flock::to_river));
			shoal->update_("from_river", Member<Flock>::fin_(&Flock::from_river));
			shoal->update_("stat", Static::fin_(&Flock::stat));
			shoal->update_("mut", Static::fin_(&Flock::mut));
			shoal->update_("lak", Static::fin_(&Flock::lak));
			shoal->update_("riv", Static::fin_(&Flock::riv));
			shoal->update_("rwl", Static::fin_(&Flock::rwl));
			shoal->update_("push_back", Member<Flock>::fin_(&Flock::push_back));
			shoal->update_("iterator", Const<Flock>::fin_(&Flock::iterator));
			shoal->update_("size", Const<Flock>::fin_(&Flock::size));
			shoal->update_("empty", Const<Flock>::fin_(&Flock::empty));
			shoal->update_("at", Const<Flock>::fin_(&Flock::at));
			shoal->update_("update", Member<Flock>::fin_(&Flock::update));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Flock::stat));
			shoal->update_("mut", Static::fin_(&Flock::mut));
			shoal->update_("lak", Static::fin_(&Flock::lak));
			shoal->update_("riv", Static::fin_(&Flock::riv));
			shoal->update_("rwl", Static::fin_(&Flock::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	static inline const Ptr mut_()
	{
		return Me<Flock>::make_();
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Flock>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Flock>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Flock>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline void push_back_(const Ptr item)
	{
		_vector.push_back(item);
	}

	inline const Ptr push_back(const Ptr it)
	{
		const Ptr item = it->next_();
		push_back_(item);
		return item;
	}

	inline const int64_t size_() const
	{
		return int64_t(_vector.size());
	}

	inline const Ptr size(const Ptr ignore) const;

	inline const bool empty_() const
	{
		return _vector.empty();
	}

	inline const Ptr empty(const Ptr ignore) const
	{
		return boolean_(empty_());
	}

	inline const Ptr at_(const int64_t pos) const
	{
		if (pos >= 0 && pos < size_())
		{
			return _vector[size_t(pos)];
		}
		return nothing_();
	}

	inline const Ptr at_(const Ptr pos) const;

	inline const Ptr at(const Ptr it) const
	{
		return at_(it->next_());
	}

	inline const Ptr update_(const int64_t pos, const Ptr value)
	{
		if (pos >= 0 && pos < size_())
		{
			_vector[size_t(pos)] = value;
			return value;
		}
		return nothing_();
	}

	inline const Ptr update_(const Ptr pos, const Ptr value);

	inline const Ptr update(const Ptr it)
	{
		const Ptr index = it->next_();
		const Ptr value = it->next_();
		return update_(index, value);
	}

	virtual inline const Ptr iterator_() const override
	{
		return It::mut_(me_());
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Flock");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

	virtual inline const Ptr visit(const Ptr it) override
	{
		const Ptr rest = it->copy_();
		const Ptr result = Thing::visit(it);
		if (!result->is_("0"))
		{
			const Ptr visitor = rest->next_();
			const Ptr member = rest->next_();
			rest->next_();
			for (const auto visited : _vector)
			{
				visited->invoke_("visit", visitor, member, visited, *(rest->copy_()));
			}
		}
		return result;
	}

	class Concurrent : public Mutable, public Me<Concurrent>
	{
	public:
		inline Concurrent()
			: Mutable{}
			, Me{}
			, _flock{ Flock::mut_() }
			, _mutex{}
		{
		}

		virtual inline const Ptr pub_() const override
		{
			static const Ptr PUB = [this]()
			{
				const Ptr pub = Thing::pub_()->copy_();
				Shoal* const shoal = static_<Shoal>(pub);
				shoal->update_("stat", Static::fin_(&Concurrent::stat));
				shoal->update_("push_back", Member<Concurrent>::fin_(&Concurrent::push_back));
				shoal->update_("size", Const<Concurrent>::fin_(&Concurrent::size));
				shoal->update_("at", Const<Concurrent>::fin_(&Concurrent::at));
				shoal->finalize_();
				return pub;
			}();
			return PUB;
		}

		static inline const Ptr stat_()
		{
			static const Ptr STAT = []()
			{
				const Ptr stat = Shoal::mut_();
				Shoal* const shoal = static_<Shoal>(stat);
				shoal->update_("stat", Static::fin_(&Concurrent::stat));
				shoal->finalize_();
				return stat;
			}();
			return STAT;
		}

		static inline const Ptr stat(const Ptr ignore)
		{
			return stat_();
		}

		static inline const Ptr mut_()
		{
			return Me<Concurrent>::make_();
		}

		virtual inline const Ptr copy_() const override
		{
			return Me<Concurrent>::me_();
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Flock::Concurrent");
			return TYPE;
		}

		inline void push_back_(const Ptr item)
		{
			std::unique_lock<std::shared_timed_mutex> lock(_mutex);
			static_<Flock>(_flock)->push_back_(item);
		}

		inline const Ptr push_back(const Ptr it)
		{
			const Ptr item = it->next_();
			push_back_(item);
			return item;
		}

		inline const int64_t size_() const
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return static_<Flock>(_flock)->size_();
		}

		inline const Ptr size(const Ptr ignore) const;

		inline const Ptr at_(const int64_t pos) const
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return static_<Flock>(_flock)->at_(pos);
		}

		inline const Ptr at_(const Ptr pos) const;

		inline const Ptr at(const Ptr it) const
		{
			return at(it->next_());
		}

	private:
		const Ptr _flock;
		mutable std::shared_timed_mutex _mutex;
	};

private:
	std_vector_ptr _vector;
	bool _frozen;

	class It : public Mutable
	{
	public:
		inline It(const Ptr flock)
			: Mutable{}
			, _flock{ flock }
			, _iterator{ static_<Flock>(_flock)->_vector.cbegin() }
		{
		}

		virtual inline const Ptr next_() override
		{
			if (_iterator == static_<Flock>(_flock)->_vector.cend())
			{
				return stop_();
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

inline const Thing::Ptr Shoal::It::next_()
{
	if (_iterator == static_<Shoal>(_shoal)->_map.cend())
	{
		return stop_();
	}
	const Ptr result = Flock::mut_();
	Flock* const flock = static_<Flock>(result);
	flock->push_back(_iterator->first);
	flock->push_back(_iterator->second);
	flock->finalize_();
	++_iterator;
	return result;
}

//----------------------------------------------------------------------
class Herd : public Mutable, public Me<Herd>, public Serializable, public Iterable
//----------------------------------------------------------------------
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
	inline Herd()
		: Mutable{}
		, Me{}
		, Serializable{}
		, Iterable{}
		, _set{}
		, _frozen{ false }
	{
	}

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
		if (!_frozen)
		{
			for (const auto i : _set)
			{
				i->freeze_();
			}
			_frozen = true;
		}
	}

	virtual inline const bool frozen_() const override
	{
		return _frozen;
	}

	virtual inline const Ptr to_lake_() const override
	{
		return to_lake_via_river_();
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		from_lake_via_river_(lake);
	}

	virtual inline void to_river_(const Thing::Ptr river) const override;

	virtual inline void from_river_(const Thing::Ptr river) override;

	virtual inline void to_river_with_links_(const Thing::Ptr shoal, const Thing::Ptr river) const override;

	virtual inline void from_river_with_links_(const Thing::Ptr river) override;

	virtual inline void replace_links_(const Thing::Ptr shoal) override;

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Herd>::fin_(&Herd::to_lake));
			shoal->update_("from_lake", Member<Herd>::fin_(&Herd::from_lake));
			shoal->update_("to_river", Const<Herd>::fin_(&Herd::to_river));
			shoal->update_("from_river", Member<Herd>::fin_(&Herd::from_river));
			shoal->update_("stat", Static::fin_(&Herd::stat));
			shoal->update_("mut", Static::fin_(&Herd::mut));
			shoal->update_("lak", Static::fin_(&Herd::lak));
			shoal->update_("riv", Static::fin_(&Herd::riv));
			shoal->update_("rwl", Static::fin_(&Herd::rwl));
			shoal->update_("find", Const<Herd>::fin_(&Herd::find));
			shoal->update_("insert", Member<Herd>::fin_(&Herd::insert));
			shoal->update_("iterator", Const<Herd>::fin_(&Herd::iterator));
			shoal->update_("gather", Member<Herd>::fin_(&Herd::gather));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Herd::stat));
			shoal->update_("mut", Static::fin_(&Herd::mut));
			shoal->update_("lak", Static::fin_(&Herd::lak));
			shoal->update_("riv", Static::fin_(&Herd::riv));
			shoal->update_("rwl", Static::fin_(&Herd::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	static inline const Ptr mut_()
	{
		return Me<Herd>::make_();
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Herd>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Herd>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Herd>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	template <typename F>
	inline const Ptr find_(F&& item) const
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

	virtual inline const Ptr iterator_() const override
	{
		return It::mut_(me_());
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
		const Ptr rest = it->copy_();
		const Ptr result = Thing::visit(it);
		if (!result->is_("0"))
		{
			const Ptr visitor = rest->next_();
			const Ptr member = rest->next_();
			rest->next_();
			for (const auto visited : _set)
			{
				visited->invoke_("visit", visitor, member, visited, *(rest->copy_()));
			}
		}
		return result;
	}

	inline void gather_(const Ptr item)
	{
		item->invoke_("visit", Me<Herd>::me_(), "insert", item);
	}

	inline const Ptr gather(const Ptr it)
	{
		gather_(it->next_());
		return nothing_();
	}

	class Concurrent : public Mutable, public Me<Concurrent>
	{
	public:
		inline Concurrent()
			: Mutable{}
			, Me{}
			, _herd{ Herd::mut_() }
			, _mutex{}
		{
		}

		virtual inline const Ptr pub_() const override
		{
			static const Ptr PUB = [this]()
			{
				const Ptr pub = Thing::pub_()->copy_();
				Shoal* const shoal = static_<Shoal>(pub);
				shoal->update_("stat", Static::fin_(&Concurrent::stat));
				shoal->update_("find", Const<Concurrent>::fin_(&Concurrent::find));
				shoal->update_("insert", Member<Concurrent>::fin_(&Concurrent::insert));
				shoal->finalize_();
				return pub;
			}();
			return PUB;
		}

		static inline const Ptr stat_()
		{
			static const Ptr STAT = []()
			{
				const Ptr stat = Shoal::mut_();
				Shoal* const shoal = static_<Shoal>(stat);
				shoal->update_("stat", Static::fin_(&Concurrent::stat));
				shoal->finalize_();
				return stat;
			}();
			return STAT;
		}

		static inline const Ptr stat(const Ptr ignore)
		{
			return stat_();
		}

		static inline const Ptr mut_()
		{
			return Me<Concurrent>::make_();
		}

		virtual inline const Ptr copy_() const override
		{
			return Me<Concurrent>::me_();
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Herd::Concurrent");
			return TYPE;
		}

		inline const Ptr find_(const Ptr item) const
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return static_<Herd>(_herd)->find_(item);
		}

		inline const Ptr find(const Ptr it) const
		{
			return find_(it->next_());
		}

		inline const bool insert_(const Ptr item)
		{
			if (item->finalized_())
			{
				std::unique_lock<std::shared_timed_mutex> lock(_mutex);
				return static_<Herd>(_herd)->insert_(item);
			}
			return false;
		}

		inline const Ptr insert(const Ptr it)
		{
			return boolean_(insert_(it->next_()));
		}

	private:
		const Ptr _herd;
		mutable std::shared_timed_mutex _mutex;
	};

private:
	std_unordered_set_ptr _set;
	bool _frozen;

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
				return stop_();
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
//----------------------------------------------------------------------
class Data
//----------------------------------------------------------------------
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

//----------------------------------------------------------------------
class Lake : public Mutable, public Serializable, public Data<std::string>
//----------------------------------------------------------------------
{
public:
	using S = std::string;

	static inline const Ptr mut_(const S& data = S())
	{
		return std::make_shared<Lake>(data);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const S& data = S())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Lake>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Lake>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Lake>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline Lake(const S& data)
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
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Lake>::fin_(&Lake::to_lake));
			shoal->update_("from_lake", Member<Lake>::fin_(&Lake::from_lake));
			shoal->update_("to_river", Const<Lake>::fin_(&Lake::to_river));
			shoal->update_("from_river", Member<Lake>::fin_(&Lake::from_river));
			shoal->update_("stat", Static::fin_(&Lake::stat));
			shoal->update_("mut", Static::fin_(&Lake::mut));
			shoal->update_("fin", Static::fin_(&Lake::fin));
			shoal->update_("lak", Static::fin_(&Lake::lak));
			shoal->update_("riv", Static::fin_(&Lake::riv));
			shoal->update_("rwl", Static::fin_(&Lake::rwl));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Lake::stat));
			shoal->update_("mut", Static::fin_(&Lake::mut));
			shoal->update_("fin", Static::fin_(&Lake::fin));
			shoal->update_("lak", Static::fin_(&Lake::lak));
			shoal->update_("riv", Static::fin_(&Lake::riv));
			shoal->update_("rwl", Static::fin_(&Lake::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr to_lake_() const override
	{
		const Ptr lake = copy_();
		if (finalized_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		Lake* const lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			log_("Lake::from_lake_ passed wrong type of thing");
			return;
		}
		set_(lak->get_());
		if (lak->finalized_())
		{
			finalize_();
		}
	}

	virtual inline void to_river_(const Ptr river) const override;

	virtual inline void from_river_(const Ptr river) override;

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Lake");
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
			herd->insert_("strange::Lake");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}
};

//----------------------------------------------------------------------
class Number : public Mutable, public Serializable
//----------------------------------------------------------------------
{
public:
	Number() = default;

	virtual inline int64_t to_int64_() const
	{
		return int64_t(std::llround(to_float64_()));
	}

	inline const Ptr to_int64(const Ptr ignore) const;

	virtual inline void from_int64_(const int64_t int64)
	{
		from_float64_(double(int64));
	}

	inline void from_int64_(const Ptr ptr);

	inline const Ptr from_int64(const Ptr it)
	{
		from_int64_(it->next_());
		return nothing_();
	}

	virtual inline double to_float64_() const
	{
		return double(to_int64_());
	}

	inline const Ptr to_float64(const Ptr ignore) const;

	virtual inline void from_float64_(const double float64)
	{
		from_int64_(int64_t(std::llround(float64)));
	}

	inline void from_float64_(const Ptr ptr);

	inline const Ptr from_float64(const Ptr it)
	{
		from_float64_(it->next_());
		return nothing_();
	}

	virtual inline double to_imaginary64_() const
	{
		return 0.0;
	}

	inline const Ptr to_imaginary64(const Ptr ignore) const;

	virtual inline void from_imaginary64_(const double imaginary64)
	{
	}

	inline void from_imaginary64_(const Ptr ptr);

	inline const Ptr from_imaginary64(const Ptr it)
	{
		from_imaginary64_(it->next_());
		return nothing_();
	}

	virtual inline std::complex<double> to_complex64_() const
	{
		return std::complex<double>(to_float64_(), 0.0);
	}

	inline const Ptr to_complex64(const Ptr ignore) const;

	virtual inline void from_complex64_(const std::complex<double>& complex64)
	{
		from_float64_(complex64.real());
	}

	inline void from_complex64_(const Ptr ptr);

	inline const Ptr from_complex64(const Ptr it)
	{
		from_complex64_(it->next_());
		return nothing_();
	}

	virtual inline const Ptr to_symbol_() const = 0;

	inline const Ptr to_symbol(const Ptr ignore) const
	{
		return to_symbol_();
	}

	virtual inline void from_symbol_(const Ptr ptr) = 0;

	inline const Ptr from_symbol(const Ptr it)
	{
		from_symbol_(it->next_());
		return nothing_();
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_int64", Const<Number>::fin_(&Number::to_int64));
			shoal->update_("from_int64", Member<Number>::fin_(&Number::from_int64));
			shoal->update_("to_float64", Const<Number>::fin_(&Number::to_float64));
			shoal->update_("from_float64", Member<Number>::fin_(&Number::from_float64));
			shoal->update_("to_imaginary64", Const<Number>::fin_(&Number::to_imaginary64));
			shoal->update_("from_imaginary64", Member<Number>::fin_(&Number::from_imaginary64));
			shoal->update_("to_complex64", Const<Number>::fin_(&Number::to_complex64));
			shoal->update_("from_complex64", Member<Number>::fin_(&Number::from_complex64));
			shoal->update_("to_symbol", Const<Number>::fin_(&Number::to_symbol));
			shoal->update_("from_symbol", Member<Number>::fin_(&Number::from_symbol));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}
};

//----------------------------------------------------------------------
class Bit : public Number, public Data<bool>
//----------------------------------------------------------------------
{
public:
	using D = bool;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Bit>(data);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Bit>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Bit>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Bit>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline Bit(const D& data)
		: Number{}
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
			const Ptr pub = Number::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Bit>::fin_(&Bit::to_lake));
			shoal->update_("from_lake", Member<Bit>::fin_(&Bit::from_lake));
			shoal->update_("to_river", Const<Bit>::fin_(&Bit::to_river));
			shoal->update_("from_river", Member<Bit>::fin_(&Bit::from_river));
			shoal->update_("stat", Static::fin_(&Bit::stat));
			shoal->update_("mut", Static::fin_(&Bit::mut));
			shoal->update_("fin", Static::fin_(&Bit::fin));
			shoal->update_("lak", Static::fin_(&Bit::lak));
			shoal->update_("riv", Static::fin_(&Bit::riv));
			shoal->update_("rwl", Static::fin_(&Bit::rwl));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Bit::stat));
			shoal->update_("mut", Static::fin_(&Bit::mut));
			shoal->update_("fin", Static::fin_(&Bit::fin));
			shoal->update_("lak", Static::fin_(&Bit::lak));
			shoal->update_("riv", Static::fin_(&Bit::riv));
			shoal->update_("rwl", Static::fin_(&Bit::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr to_lake_() const override
	{
		const Ptr lake = Lake::mut_(std::string(1, get_() ? char(1) : char(0)));
		if (finalized_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		Lake* const lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			log_("Bit::from_lake_ passed wrong type of thing");
			return;
		}
		set_(bool(lak->get_()[0]));
		if (lak->finalized_())
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
			herd->insert_("strange::Number");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline int64_t to_int64_() const override
	{
		return int64_t(get_());
	}

	virtual inline void from_int64_(const int64_t int64) override
	{
		set_(D(int64));
	}

	virtual inline const Ptr to_symbol_() const override
	{
		return sym_(std::to_string(get_()));
	}

	virtual inline void from_symbol_(const Ptr ptr) override
	{
		Symbol* const symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoll(symbol->symbol_())));
		}
	}
};

//----------------------------------------------------------------------
class Byte : public Number, public Data<unsigned char>
//----------------------------------------------------------------------
{
public:
	using D = unsigned char;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Byte>(data);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Byte>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Byte>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Byte>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline Byte(const D& data)
		: Number{}
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
			const Ptr pub = Number::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Byte>::fin_(&Byte::to_lake));
			shoal->update_("from_lake", Member<Byte>::fin_(&Byte::from_lake));
			shoal->update_("to_river", Const<Byte>::fin_(&Byte::to_river));
			shoal->update_("from_river", Member<Byte>::fin_(&Byte::from_river));
			shoal->update_("stat", Static::fin_(&Byte::stat));
			shoal->update_("mut", Static::fin_(&Byte::mut));
			shoal->update_("fin", Static::fin_(&Byte::fin));
			shoal->update_("lak", Static::fin_(&Byte::lak));
			shoal->update_("riv", Static::fin_(&Byte::riv));
			shoal->update_("rwl", Static::fin_(&Byte::rwl));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Byte::stat));
			shoal->update_("mut", Static::fin_(&Byte::mut));
			shoal->update_("fin", Static::fin_(&Byte::fin));
			shoal->update_("lak", Static::fin_(&Byte::lak));
			shoal->update_("riv", Static::fin_(&Byte::riv));
			shoal->update_("rwl", Static::fin_(&Byte::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr to_lake_() const override
	{
		const Ptr lake = Lake::mut_(std::string(1, *reinterpret_cast<const char*>(&(get_()))));
		if (finalized_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		Lake* const lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			log_("Byte::from_lake_ passed wrong type of thing");
			return;
		}
		set_(*reinterpret_cast<const unsigned char*>(&(lak->get_()[0])));
		if (lak->finalized_())
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
			herd->insert_("strange::Number");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline int64_t to_int64_() const override
	{
		return int64_t(get_());
	}

	virtual inline void from_int64_(const int64_t int64) override
	{
		set_(D(int64));
	}

	virtual inline const Ptr to_symbol_() const override
	{
		return sym_(std::to_string(get_()));
	}

	virtual inline void from_symbol_(const Ptr ptr) override
	{
		Symbol* const symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoll(symbol->symbol_())));
		}
	}
};

//----------------------------------------------------------------------
class Int16 : public Number, public Data<int16_t>
//----------------------------------------------------------------------
{
public:
	using D = int16_t;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Int16>(data);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Int16>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Int16>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Int16>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline Int16(const D& data)
		: Number{}
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
			const Ptr pub = Number::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Int16>::fin_(&Int16::to_lake));
			shoal->update_("from_lake", Member<Int16>::fin_(&Int16::from_lake));
			shoal->update_("to_river", Const<Int16>::fin_(&Int16::to_river));
			shoal->update_("from_river", Member<Int16>::fin_(&Int16::from_river));
			shoal->update_("stat", Static::fin_(&Int16::stat));
			shoal->update_("mut", Static::fin_(&Int16::mut));
			shoal->update_("fin", Static::fin_(&Int16::fin));
			shoal->update_("lak", Static::fin_(&Int16::lak));
			shoal->update_("riv", Static::fin_(&Int16::riv));
			shoal->update_("rwl", Static::fin_(&Int16::rwl));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Int16::stat));
			shoal->update_("mut", Static::fin_(&Int16::mut));
			shoal->update_("fin", Static::fin_(&Int16::fin));
			shoal->update_("lak", Static::fin_(&Int16::lak));
			shoal->update_("riv", Static::fin_(&Int16::riv));
			shoal->update_("rwl", Static::fin_(&Int16::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr to_lake_() const override
	{
		std::string str(2, 0);
		str[0] = get_() & 0xFF;
		str[1] = (get_() >> 8) & 0xFF;
		const Ptr lake = Lake::mut_(str);
		if (finalized_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		Lake* const lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			log_("Int16::from_lake_ passed wrong type of thing");
			return;
		}
		set_(
			uint16_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[0]))) |
			uint16_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[1]))) << 8
			);
		if (lak->finalized_())
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
			herd->insert_("strange::Number");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline int64_t to_int64_() const override
	{
		return int64_t(get_());
	}

	virtual inline void from_int64_(const int64_t int64) override
	{
		set_(D(int64));
	}

	virtual inline const Ptr to_symbol_() const override
	{
		return sym_(std::to_string(get_()));
	}

	virtual inline void from_symbol_(const Ptr ptr) override
	{
		Symbol* const symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoll(symbol->symbol_())));
		}
	}
};

//----------------------------------------------------------------------
class Int32 : public Number, public Data<int32_t>
//----------------------------------------------------------------------
{
public:
	using D = int32_t;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Int32>(data);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Int32>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Int32>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Int32>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline Int32(const D& data)
		: Number{}
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
			const Ptr pub = Number::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Int32>::fin_(&Int32::to_lake));
			shoal->update_("from_lake", Member<Int32>::fin_(&Int32::from_lake));
			shoal->update_("to_river", Const<Int32>::fin_(&Int32::to_river));
			shoal->update_("from_river", Member<Int32>::fin_(&Int32::from_river));
			shoal->update_("stat", Static::fin_(&Int32::stat));
			shoal->update_("mut", Static::fin_(&Int32::mut));
			shoal->update_("fin", Static::fin_(&Int32::fin));
			shoal->update_("lak", Static::fin_(&Int32::lak));
			shoal->update_("riv", Static::fin_(&Int32::riv));
			shoal->update_("rwl", Static::fin_(&Int32::rwl));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Int32::stat));
			shoal->update_("mut", Static::fin_(&Int32::mut));
			shoal->update_("fin", Static::fin_(&Int32::fin));
			shoal->update_("lak", Static::fin_(&Int32::lak));
			shoal->update_("riv", Static::fin_(&Int32::riv));
			shoal->update_("rwl", Static::fin_(&Int32::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr to_lake_() const override
	{
		std::string str(4, 0);
		str[0] = get_() & 0xFF;
		str[1] = (get_() >> 8) & 0xFF;
		str[2] = (get_() >> 16) & 0xFF;
		str[3] = (get_() >> 24) & 0xFF;
		const Ptr lake = Lake::mut_(str);
		if (finalized_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		Lake* const lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			log_("Int32::from_lake_ passed wrong type of thing");
			return;
		}
		set_(
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[0]))) |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[3]))) << 24
			);
		if (lak->finalized_())
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
			herd->insert_("strange::Number");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline int64_t to_int64_() const override
	{
		return int64_t(get_());
	}

	virtual inline void from_int64_(const int64_t int64) override
	{
		set_(D(int64));
	}

	virtual inline const Ptr to_symbol_() const override
	{
		return sym_(std::to_string(get_()));
	}

	virtual inline void from_symbol_(const Ptr ptr) override
	{
		Symbol* const symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoll(symbol->symbol_())));
		}
	}
};

//----------------------------------------------------------------------
class Int64 : public Number, public Data<int64_t>
//----------------------------------------------------------------------
{
public:
	using D = int64_t;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Int64>(data);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Int64>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Int64>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Int64>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline Int64(const D& data)
		: Number{}
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
			const Ptr pub = Number::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Int64>::fin_(&Int64::to_lake));
			shoal->update_("from_lake", Member<Int64>::fin_(&Int64::from_lake));
			shoal->update_("to_river", Const<Int64>::fin_(&Int64::to_river));
			shoal->update_("from_river", Member<Int64>::fin_(&Int64::from_river));
			shoal->update_("stat", Static::fin_(&Int64::stat));
			shoal->update_("mut", Static::fin_(&Int64::mut));
			shoal->update_("fin", Static::fin_(&Int64::fin));
			shoal->update_("lak", Static::fin_(&Int64::lak));
			shoal->update_("riv", Static::fin_(&Int64::riv));
			shoal->update_("rwl", Static::fin_(&Int64::rwl));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Int64::stat));
			shoal->update_("mut", Static::fin_(&Int64::mut));
			shoal->update_("fin", Static::fin_(&Int64::fin));
			shoal->update_("lak", Static::fin_(&Int64::lak));
			shoal->update_("riv", Static::fin_(&Int64::riv));
			shoal->update_("rwl", Static::fin_(&Int64::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr to_lake_() const override
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
		const Ptr lake = Lake::mut_(str);
		if (finalized_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		Lake* const lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			log_("Int64::from_lake_ passed wrong type of thing");
			return;
		}
		set_(
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[0]))) |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[1]))) << 8 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[2]))) << 16 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[3]))) << 24 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[4]))) << 32 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[5]))) << 40 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[6]))) << 48 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[7]))) << 56
			);
		if (lak->finalized_())
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
			herd->insert_("strange::Number");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline int64_t to_int64_() const override
	{
		return get_();
	}

	virtual inline void from_int64_(const int64_t int64) override
	{
		set_(int64);
	}

	virtual inline const Ptr to_symbol_() const override
	{
		return sym_(std::to_string(get_()));
	}

	virtual inline void from_symbol_(const Ptr ptr) override
	{
		Symbol* const symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoll(symbol->symbol_())));
		}
	}
};

//----------------------------------------------------------------------
class Float32 : public Number, public Data<float>
//----------------------------------------------------------------------
{
public:
	using D = float;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Float32>(data);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Float32>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Float32>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Float32>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline Float32(const D& data)
		: Number{}
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
			const Ptr pub = Number::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Float32>::fin_(&Float32::to_lake));
			shoal->update_("from_lake", Member<Float32>::fin_(&Float32::from_lake));
			shoal->update_("to_river", Const<Float32>::fin_(&Float32::to_river));
			shoal->update_("from_river", Member<Float32>::fin_(&Float32::from_river));
			shoal->update_("stat", Static::fin_(&Float32::stat));
			shoal->update_("mut", Static::fin_(&Float32::mut));
			shoal->update_("fin", Static::fin_(&Float32::fin));
			shoal->update_("lak", Static::fin_(&Float32::lak));
			shoal->update_("riv", Static::fin_(&Float32::riv));
			shoal->update_("rwl", Static::fin_(&Float32::rwl));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Float32::stat));
			shoal->update_("mut", Static::fin_(&Float32::mut));
			shoal->update_("fin", Static::fin_(&Float32::fin));
			shoal->update_("lak", Static::fin_(&Float32::lak));
			shoal->update_("riv", Static::fin_(&Float32::riv));
			shoal->update_("rwl", Static::fin_(&Float32::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr to_lake_() const override
	{
		std::string str(4, 0);
		const uint32_t i = *reinterpret_cast<const uint32_t*>(&(get_()));
		str[0] = i & 0xFF;
		str[1] = (i >> 8) & 0xFF;
		str[2] = (i >> 16) & 0xFF;
		str[3] = (i >> 24) & 0xFF;
		const Ptr lake = Lake::mut_(str);
		if (finalized_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		Lake* const lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			log_("Float32::from_lake_ passed wrong type of thing");
			return;
		}
		const uint32_t i =
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[0]))) |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[3]))) << 24;
		set_(*reinterpret_cast<const float*>(&i));
		if (lak->finalized_())
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
			herd->insert_("strange::Number");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline double to_float64_() const override
	{
		return double(get_());
	}

	virtual inline void from_float64_(const double float64) override
	{
		set_(D(float64));
	}

	virtual inline const Ptr to_symbol_() const override
	{
		return sym_(std::to_string(get_()));
	}

	virtual inline void from_symbol_(const Ptr ptr) override
	{
		Symbol* const symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(std::stof(symbol->symbol_()));
		}
	}
};

//----------------------------------------------------------------------
class Float64 : public Number, public Data<double>
//----------------------------------------------------------------------
{
public:
	using D = double;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Float64>(data);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Float64>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Float64>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Float64>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline Float64(const D& data)
		: Number{}
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
			const Ptr pub = Number::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Float64>::fin_(&Float64::to_lake));
			shoal->update_("from_lake", Member<Float64>::fin_(&Float64::from_lake));
			shoal->update_("to_river", Const<Float64>::fin_(&Float64::to_river));
			shoal->update_("from_river", Member<Float64>::fin_(&Float64::from_river));
			shoal->update_("stat", Static::fin_(&Float64::stat));
			shoal->update_("mut", Static::fin_(&Float64::mut));
			shoal->update_("fin", Static::fin_(&Float64::fin));
			shoal->update_("lak", Static::fin_(&Float64::lak));
			shoal->update_("riv", Static::fin_(&Float64::riv));
			shoal->update_("rwl", Static::fin_(&Float64::rwl));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Float64::stat));
			shoal->update_("mut", Static::fin_(&Float64::mut));
			shoal->update_("fin", Static::fin_(&Float64::fin));
			shoal->update_("lak", Static::fin_(&Float64::lak));
			shoal->update_("riv", Static::fin_(&Float64::riv));
			shoal->update_("rwl", Static::fin_(&Float64::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr to_lake_() const override
	{
		std::string str(8, 0);
		const uint64_t i = *reinterpret_cast<const uint64_t*>(&(get_()));
		str[0] = i & 0xFF;
		str[1] = (i >> 8) & 0xFF;
		str[2] = (i >> 16) & 0xFF;
		str[3] = (i >> 24) & 0xFF;
		str[4] = (i >> 32) & 0xFF;
		str[5] = (i >> 40) & 0xFF;
		str[6] = (i >> 48) & 0xFF;
		str[7] = (i >> 56) & 0xFF;
		const Ptr lake = Lake::mut_(str);
		if (finalized_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		Lake* const lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			log_("Float64::from_lake_ passed wrong type of thing");
			return;
		}
		const uint64_t i =
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[0]))) |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[1]))) << 8 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[2]))) << 16 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[3]))) << 24 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[4]))) << 32 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[5]))) << 40 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[6]))) << 48 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[7]))) << 56;
		set_(*reinterpret_cast<const double*>(&i));
		if (lak->finalized_())
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
			herd->insert_("strange::Number");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline double to_float64_() const override
	{
		return get_();
	}

	virtual inline void from_float64_(const double float64) override
	{
		set_(float64);
	}

	virtual inline const Ptr to_symbol_() const override
	{
		return sym_(std::to_string(get_()));
	}

	virtual inline void from_symbol_(const Ptr ptr) override
	{
		Symbol* const symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(std::stod(symbol->symbol_()));
		}
	}
};

//----------------------------------------------------------------------
class Complex32 : public Number, public Data<std::complex<float>>
//----------------------------------------------------------------------
{
	static const char delim = '|';

public:
	using D = std::complex<float>;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Complex32>(data);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Complex32>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Complex32>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Complex32>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline Complex32(const D& data)
		: Number{}
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
			const Ptr pub = Number::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Complex32>::fin_(&Complex32::to_lake));
			shoal->update_("from_lake", Member<Complex32>::fin_(&Complex32::from_lake));
			shoal->update_("to_river", Const<Complex32>::fin_(&Complex32::to_river));
			shoal->update_("from_river", Member<Complex32>::fin_(&Complex32::from_river));
			shoal->update_("stat", Static::fin_(&Complex32::stat));
			shoal->update_("mut", Static::fin_(&Complex32::mut));
			shoal->update_("fin", Static::fin_(&Complex32::fin));
			shoal->update_("lak", Static::fin_(&Complex32::lak));
			shoal->update_("riv", Static::fin_(&Complex32::riv));
			shoal->update_("rwl", Static::fin_(&Complex32::rwl));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Complex32::stat));
			shoal->update_("mut", Static::fin_(&Complex32::mut));
			shoal->update_("fin", Static::fin_(&Complex32::fin));
			shoal->update_("lak", Static::fin_(&Complex32::lak));
			shoal->update_("riv", Static::fin_(&Complex32::riv));
			shoal->update_("rwl", Static::fin_(&Complex32::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr to_lake_() const override
	{
		std::string str(8, 0);
		const float real = get_().real();
		const uint32_t r = *reinterpret_cast<const uint32_t*>(&real);
		str[0] = r & 0xFF;
		str[1] = (r >> 8) & 0xFF;
		str[2] = (r >> 16) & 0xFF;
		str[3] = (r >> 24) & 0xFF;
		const float imag = get_().imag();
		const uint32_t i = *reinterpret_cast<const uint32_t*>(&imag);
		str[4] = i & 0xFF;
		str[5] = (i >> 8) & 0xFF;
		str[6] = (i >> 16) & 0xFF;
		str[7] = (i >> 24) & 0xFF;
		const Ptr lake = Lake::mut_(str);
		if (finalized_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		Lake* const lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			log_("Complex32::from_lake_ passed wrong type of thing");
			return;
		}
		const uint32_t r =
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[0]))) |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[3]))) << 24;
		const uint32_t i =
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[4]))) |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[5]))) << 8 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[6]))) << 16 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[7]))) << 24;
		set_(D(*reinterpret_cast<const float*>(&r), *reinterpret_cast<const float*>(&i)));
		if (lak->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Complex32");
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
			herd->insert_("strange::Complex32");
			herd->insert_("strange::Number");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline double to_float64_() const override
	{
		return double(get_().real());
	}

	virtual inline void from_float64_(const double float64) override
	{
		set_(D(float(float64), get_().imag()));
	}

	virtual inline double to_imaginary64_() const override
	{
		return double(get_().imag());
	}

	virtual inline void from_imaginary64_(const double float64) override
	{
		set_(D(get_().real(), float(float64)));
	}

	virtual inline std::complex<double> to_complex64_() const override
	{
		return std::complex<double>(double(get_().real()), double(get_().imag()));
	}

	virtual inline void from_complex64_(const std::complex<double>& complex64) override
	{
		set_(D(float(complex64.real()), float(complex64.imag())));
	}

	virtual inline const Ptr to_symbol_() const override
	{
		return sym_(std::to_string(get_().real()) + std::string(1, delim) + std::to_string(get_().imag()));
	}

	virtual inline void from_symbol_(const Ptr ptr) override
	{
		Symbol* const symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			std::stringstream str(symbol->symbol_());
			std::string first;
			std::string second;
			std::getline(str, first, delim);
			std::getline(str, second, delim);
			set_(D(std::stof(first), std::stof(second)));
		}
	}
};

//----------------------------------------------------------------------
class Complex64 : public Number, public Data<std::complex<double>>
//----------------------------------------------------------------------
{
	static const char delim = '|';

public:
	using D = std::complex<double>;

	static inline const Ptr mut_(const D& data = D())
	{
		return std::make_shared<Complex64>(data);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr lake)
	{
		const Ptr ptr = mut_();
		static_<Complex64>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Complex64>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Complex64>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline Complex64(const D& data)
		: Number{}
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
			const Ptr pub = Number::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("to_lake", Const<Complex64>::fin_(&Complex64::to_lake));
			shoal->update_("from_lake", Member<Complex64>::fin_(&Complex64::from_lake));
			shoal->update_("to_river", Const<Complex64>::fin_(&Complex64::to_river));
			shoal->update_("from_river", Member<Complex64>::fin_(&Complex64::from_river));
			shoal->update_("stat", Static::fin_(&Complex64::stat));
			shoal->update_("mut", Static::fin_(&Complex64::mut));
			shoal->update_("fin", Static::fin_(&Complex64::fin));
			shoal->update_("lak", Static::fin_(&Complex64::lak));
			shoal->update_("riv", Static::fin_(&Complex64::riv));
			shoal->update_("rwl", Static::fin_(&Complex64::rwl));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Complex64::stat));
			shoal->update_("mut", Static::fin_(&Complex64::mut));
			shoal->update_("fin", Static::fin_(&Complex64::fin));
			shoal->update_("lak", Static::fin_(&Complex64::lak));
			shoal->update_("riv", Static::fin_(&Complex64::riv));
			shoal->update_("rwl", Static::fin_(&Complex64::rwl));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr to_lake_() const override
	{
		std::string str(16, 0);
		const double real = get_().real();
		const uint64_t r = *reinterpret_cast<const uint64_t*>(&real);
		str[0] = r & 0xFF;
		str[1] = (r >> 8) & 0xFF;
		str[2] = (r >> 16) & 0xFF;
		str[3] = (r >> 24) & 0xFF;
		str[4] = (r >> 32) & 0xFF;
		str[5] = (r >> 40) & 0xFF;
		str[6] = (r >> 48) & 0xFF;
		str[7] = (r >> 56) & 0xFF;
		const double imag = get_().imag();
		const uint64_t i = *reinterpret_cast<const uint64_t*>(&imag);
		str[8] = i & 0xFF;
		str[9] = (i >> 8) & 0xFF;
		str[10] = (i >> 16) & 0xFF;
		str[11] = (i >> 24) & 0xFF;
		str[12] = (i >> 32) & 0xFF;
		str[13] = (i >> 40) & 0xFF;
		str[14] = (i >> 48) & 0xFF;
		str[15] = (i >> 56) & 0xFF;
		const Ptr lake = Lake::mut_(str);
		if (finalized_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		Lake* const lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			log_("Complex64::from_lake_ passed wrong type of thing");
			return;
		}
		const uint64_t r =
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[0]))) |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[1]))) << 8 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[2]))) << 16 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[3]))) << 24 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[4]))) << 32 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[5]))) << 40 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[6]))) << 48 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[7]))) << 56;
		const uint64_t i =
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[8]))) |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[9]))) << 8 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[10]))) << 16 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[11]))) << 24 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[12]))) << 32 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[13]))) << 40 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[14]))) << 48 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(lak->get_()[15]))) << 56;
		set_(D(*reinterpret_cast<const double*>(&r), *reinterpret_cast<const double*>(&i)));
		if (lak->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Complex64");
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
			herd->insert_("strange::Complex64");
			herd->insert_("strange::Number");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline double to_float64_() const override
	{
		return get_().real();
	}

	virtual inline void from_float64_(const double float64) override
	{
		set_(D(float64, get_().imag()));
	}

	virtual inline double to_imaginary64_() const override
	{
		return get_().imag();
	}

	virtual inline void from_imaginary64_(const double float64) override
	{
		set_(D(get_().real(), float64));
	}

	virtual inline std::complex<double> to_complex64_() const override
	{
		return get_();
	}

	virtual inline void from_complex64_(const std::complex<double>& complex64) override
	{
		set_(complex64);
	}

	virtual inline const Ptr to_symbol_() const override
	{
		return sym_(std::to_string(get_().real()) + std::string(1, delim) + std::to_string(get_().imag()));
	}

	virtual inline void from_symbol_(const Ptr ptr) override
	{
		Symbol* const symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			std::stringstream str(symbol->symbol_());
			std::string first;
			std::string second;
			std::getline(str, first, delim);
			std::getline(str, second, delim);
			set_(D(std::stod(first), std::stod(second)));
		}
	}
};

//----------------------------------------------------------------------
class River : public Mutable, public Me<River>
//----------------------------------------------------------------------
{
	using const_std_unique_iostream = const std::unique_ptr<std::iostream>;

public:
	River(std::iostream* const stream)
		: Mutable{}
		, Me{}
		, _stream{ stream }
	{
	}

	static inline const Ptr mut_(std::iostream* const stream)
	{
		return Me<River>::make_(stream);
	}

	static inline const Ptr mut_(const std::string& str = std::string(), const bool file = false)
	{
		if (file)
		{
			return mut_(new std::fstream(str, std::fstream::binary | std::fstream::in | std::fstream::out));
		}
		return mut_(new std::stringstream(str));
	}

	static inline const Ptr mut(const Ptr it)
	{
		const Ptr str = it->next_();
		if (str->is_("."))
		{
			return mut_();
		}
		const Lake* const lake = dynamic_<Lake>(str->invoke_("to_lake"));
		if (!lake)
		{
			return mut_();
		}
		const Ptr file = it->next_();
		if (file->is_("."))
		{
			return mut_(lake->get_());
		}
		return mut_(lake->get_(), !file->is_("0"));
	}

	virtual inline const Ptr copy_() const override
	{
		return Me<River>::me_();
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("stat", Static::fin_(&River::stat));
			shoal->update_("mut", Static::fin_(&River::mut));
			shoal->update_("push_back", Member<River>::fin_(&River::push_back));
			shoal->update_("write", Member<River>::fin_(&River::write));
			shoal->update_("pop_front", Member<River>::fin_(&River::pop_front));
			shoal->update_("eof", Const<River>::fin_(&River::eof));
			shoal->update_("get", Member<River>::fin_(&River::get));
			shoal->update_("peek", Member<River>::fin_(&River::peek));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&River::stat));
			shoal->update_("mut", Static::fin_(&River::mut));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::River");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::River");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	inline const bool push_back_(const Ptr ptr)
	{
		const Ptr type = ptr->type_();
		write_(Int16::mut_(int16_t(static_<Symbol>(type)->symbol_().length())));
		write_(type);
		ptr->invoke_("to_river", Me<River>::me_());
		return true;
	}

	inline const Ptr push_back(const Ptr it)
	{
		push_back_(it->next_());
		return nothing_();
	}

	inline const bool push_back_with_links_(const Ptr ptr, const Ptr shoal)
	{
		const Ptr type = ptr->type_();
		write_(Int16::mut_(int16_t(static_<Symbol>(type)->symbol_().length())));
		write_(type);
		ptr->invoke_("to_river_with_links", shoal, Me<River>::me_());
		return true;
	}

	inline void write_(const std::string& str)
	{
		_stream->write(str.data(), str.length());
	}

	inline void write_(const Ptr ptr)
	{
		Lake* const lake = dynamic_<Lake>(ptr->invoke_("to_lake"));
		if (lake)
		{
			write_(lake->get_());
		}
	}

	inline const Ptr write(const Ptr it)
	{
		write_(it->next_());
	}

	inline const Ptr pop_front_()
	{
		const int16_t int16 = read_<Int16>();
		const std::string type = static_<Lake>(read_(int16))->get_();
		return call_(type, "riv", Me<River>::me_());
	}

	inline const Ptr pop_front(const Ptr ignore)
	{
		return pop_front_();
	}

	inline const Ptr pop_front_with_links_()
	{
		const int16_t int16 = read_<Int16>();
		const std::string type = static_<Lake>(read_(int16))->get_();
		return call_(type, "rwl", Me<River>::me_());
	}

	inline const Ptr read_(const int64_t length)
	{
		std::string str;
		str.resize(size_t(length));
		_stream->read(&str[0], str.length());
		return Lake::mut_(str);
	}

	template <typename T>
	inline const typename T::D read_()
	{
		return static_<T>(T::lak_(read_(int64_t(sizeof(T::D)))))->get_();
	}

	inline const bool eof_() const
	{
		return _stream->eof();
	}

	inline const Ptr eof(const Ptr ignore) const
	{
		return boolean_(eof_());
	}

	inline const int get_()
	{
		return _stream->get();
	}

	inline const Ptr get(const Ptr ignore)
	{
		return Byte::fin_(get_());
	}

	inline const int peek_()
	{
		return _stream->peek();
	}

	inline const Ptr peek(const Ptr ignore)
	{
		return Byte::fin_(peek_());
	}

private:
	const_std_unique_iostream _stream;
};

//----------------------------------------------------------------------
class Fence : public Mutable
//----------------------------------------------------------------------
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
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("stat", Static::fin_(&Fence::stat));
			shoal->update_("mut", Static::fin_(&Fence::mut));
			shoal->update_("give", Member<Fence>::fin_(&Fence::give));
			shoal->update_("take", Member<Fence>::fin_(&Fence::take));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Fence::stat));
			shoal->update_("mut", Static::fin_(&Fence::mut));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
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
		static const Ptr TYPE = sym_("strange::Fence");
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

//----------------------------------------------------------------------
class Creator : public Mutable
//----------------------------------------------------------------------
{
};

//----------------------------------------------------------------------
class Creature : public Mutable, public Me<Creature>, public Serializable
//----------------------------------------------------------------------
{
public:
	inline Creature(const Ptr creator, const Ptr members)
		: Mutable{}
		, Me{}
		, Serializable{}
		, _creator{ creator }
		, _members{ members }
	{
	}

	static inline const Ptr mut_(const Ptr creator, const Ptr members)
	{
		return Me<Creature>::make_(creator, members);
	}

	static inline const Ptr fin_(const Ptr creator, const Ptr members)
	{
		const Ptr result = mut_(creator, members);
		result->finalize_();
		return result;
	}

	virtual inline const Ptr type_() const override
	{
		const Ptr over = static_<Shoal>(_members)->find_("type");
		if (!over->is_("0"))
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		static const Ptr TYPE = sym_("strange::Creature");
		return TYPE;
	}

	virtual inline const Ptr copy_() const override
	{
		const Ptr over = static_<Shoal>(_members)->find_("copy");
		if (!over->is_("0"))
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return Me<Creature>::me_();
	}

	virtual inline const Ptr clone_() const override
	{
		const Ptr over = static_<Shoal>(_members)->find_("clone");
		if (!over->is_("0"))
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return Thing::clone_();
	}

	virtual inline void finalize_() override
	{
		const Ptr over = static_<Shoal>(_members)->find_("finalize");
		if (!over->is_("0"))
		{
			operate_(this, over);
		}
		Mutable::finalize_();
	}

	virtual inline const bool finalized_() const override
	{
		const Ptr over = static_<Shoal>(_members)->find_("finalized");
		if (!over->is_("0"))
		{
			return !operate_(const_cast<Creature*>(this), over)->is_("0");
		}
		return Mutable::finalized_();
	}

	virtual inline void freeze_() override
	{
		const Ptr over = static_<Shoal>(_members)->find_("freeze");
		if (!over->is_("0"))
		{
			operate_(this, over);
		}
		Thing::freeze_();
	}

	virtual inline const bool frozen_() const override
	{
		const Ptr over = static_<Shoal>(_members)->find_("frozen");
		if (!over->is_("0"))
		{
			return !operate_(const_cast<Creature*>(this), over)->is_("0");
		}
		return Mutable::frozen_();
	}

	virtual inline const Ptr next_() override
	{
		const Ptr over = static_<Shoal>(_members)->find_("next");
		if (!over->is_("0"))
		{
			return operate_(this, over);
		}
		return Thing::next_();
	}

	virtual inline size_t hash_() const override
	{
		const Ptr over = static_<Shoal>(_members)->find_("hash");
		if (!over->is_("0"))
		{
			return size_t(static_<Int64>(operate_(const_cast<Creature*>(this), over))->get_());
		}
		return Thing::hash_();
	}

	virtual inline const bool same_(const Ptr other) const override
	{
		const Ptr over = static_<Shoal>(_members)->find_("same");
		if (!over->is_("0"))
		{
			return !operate_(const_cast<Creature*>(this), over,
				Iterator<std::vector<Ptr>>::mut_(std::vector<Ptr>{ other }))->is_("0");
		}
		return Thing::same_(other);
	}

	virtual inline const Ptr visit(const Ptr it) override
	{
		const Ptr over = static_<Shoal>(_members)->find_("visit");
		if (!over->is_("0"))
		{
			return operate_(this, over, it);
		}
		return Thing::visit(it);
	}

	virtual inline const Ptr cats_() const override
	{
		const Ptr over = static_<Shoal>(_members)->find_("cats");
		if (!over->is_("0"))
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Creature");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline const Ptr to_lake_() const override
	{
		const Ptr over = static_<Shoal>(_members)->find_("to_lake");
		if (!over->is_("0"))
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return to_lake_via_river_();
	}

	virtual inline void from_lake_(const Ptr lake) override
	{
		const Ptr over = static_<Shoal>(_members)->find_("from_lake");
		if (!over->is_("0"))
		{
			operate_(this, over, Iterator<std::vector<Ptr>>::mut_(std::vector<Ptr>{ lake }));
		}
		else
		{
			from_lake_via_river_(lake);
		}
	}

	virtual inline void to_river_(const Thing::Ptr river) const override
	{
		const Ptr over = static_<Shoal>(_members)->find_("to_river");
		if (!over->is_("0"))
		{
			operate_(const_cast<Creature*>(this), over, Iterator<std::vector<Ptr>>::mut_(std::vector<Ptr>{ river }));
		}
		else
		{
			static_<Shoal>(_members)->to_river_(river);
		}
	}

	virtual inline void from_river_(const Thing::Ptr river) override
	{
		const Ptr over = static_<Shoal>(_members)->find_("from_river");
		if (!over->is_("0"))
		{
			operate_(this, over, Iterator<std::vector<Ptr>>::mut_(std::vector<Ptr>{ river }));
		}
		else
		{
			static_<Shoal>(_members)->from_river_(river);
		}
	}

	virtual inline void to_river_with_links_(const Thing::Ptr shoal, const Thing::Ptr river) const override
	{
		const Ptr over = static_<Shoal>(_members)->find_("to_river_with_links");
		if (!over->is_("0"))
		{
			operate_(const_cast<Creature*>(this), over, Iterator<std::vector<Ptr>>::mut_(std::vector<Ptr>{ shoal, river }));
		}
		else
		{
			static_<Shoal>(_members)->to_river_with_links_(shoal, river);
		}
	}

	virtual inline void from_river_with_links_(const Thing::Ptr river) override
	{
		const Ptr over = static_<Shoal>(_members)->find_("from_river_with_links");
		if (!over->is_("0"))
		{
			operate_(this, over, Iterator<std::vector<Ptr>>::mut_(std::vector<Ptr>{ river }));
		}
		else
		{
			static_<Shoal>(_members)->from_river_with_links_(river);
		}
	}

	virtual inline void replace_links_(const Thing::Ptr shoal) override
	{
		const Ptr over = static_<Shoal>(_members)->find_("replace_links");
		if (!over->is_("0"))
		{
			operate_(this, over, Iterator<std::vector<Ptr>>::mut_(std::vector<Ptr>{ shoal }));
		}
		else
		{
			static_<Shoal>(_members)->replace_links_(shoal);
		}
	}

protected:
	// protected impure virtual member functions and adapters
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		const Ptr name = it->next_();
		Symbol* const symbol = dynamic_<Symbol>(name);
		if (symbol && symbol->symbol_()[0] == '_')
		{
			return nothing_();
		}
		const Ptr over = static_<Shoal>(_members)->find_(name);
		if (!over->is_("0"))
		{
			return operate_(thing, over, it);
		}
		const Ptr member = static_<Shoal>(pub_())->find_(name);
		if (member->is_("0"))
		{
			return member;
		}
		return operate_(thing, member, it);
	}

private:
	friend class Function;
	const Ptr _creator;
	const Ptr _members;
};

//----------------------------------------------------------------------
class Expression : public Mutable
//----------------------------------------------------------------------
{
	typedef const Ptr(Expression::*MemberPtr)(const Ptr, const Ptr);

public:
	inline Expression(const MemberPtr member, const Ptr flock)
		: Mutable{}
		, _member{ member }
		, _flock{ flock }
	{
	}

	static inline const Ptr fin_(const MemberPtr member, const Ptr flock)
	{
		return std::make_shared<Expression>(member, flock);
	}

	static inline const Ptr fin_(const Ptr statement, const Ptr flock)
	{
		if (statement->is_("invoke"))
		{
			return fin_(&Expression::_invoke_, flock);
		}
		else if (statement->is_("break"))
		{
			return fin_(&Expression::_break_, flock);
		}
		else if (statement->is_("continue"))
		{
			return fin_(&Expression::_continue_, flock);
		}
		else if (statement->is_("return"))
		{
			return fin_(&Expression::_return_, flock);
		}
		else if (statement->is_("block"))
		{
			return fin_(&Expression::_block_, flock);
		}
		else if (statement->is_("if"))
		{
			return fin_(&Expression::_if_, flock);
		}
		else if (statement->is_("question"))
		{
			return fin_(&Expression::_question_, flock);
		}
		else if (statement->is_("while"))
		{
			return fin_(&Expression::_while_, flock);
		}
		else if (statement->is_("do"))
		{
			return fin_(&Expression::_do_, flock);
		}
		else if (statement->is_("for"))
		{
			return fin_(&Expression::_for_, flock);
		}
		const Ptr none = Flock::mut_();
		static_<Flock>(none)->push_back_(nothing_());
		return fin_(&Expression::_invoke_, none);
	}

	static inline const Ptr fin_()
	{
		return fin_(nothing_(), nothing_());
	}

	static inline const Ptr fin(const Ptr it)
	{
		const Ptr statement = it->next_();
		const Ptr flock = it->next_();
		return fin_(statement, flock);
	}

	static inline const Ptr evaluate_(const Ptr expression, const Ptr local)
	{
		Expression* const exp = static_<Expression>(expression);
		return (exp->*(exp->_member))(expression, local);
	}

	static inline const Ptr immediate_(const Ptr expression)
	{
		return evaluate_(expression, Shoal::mut_());
	}

	static inline const Ptr iterator_(const Ptr expression, const Ptr local)
	{
		return It::mut_(expression, local);
	}

	virtual inline const Ptr copy_() const override
	{
		return fin_(_member, _flock);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Expression");
		return TYPE;
	}

private:
	const MemberPtr _member;
	const Ptr _flock;

	inline const Ptr _invoke_(const Ptr expression, const Ptr local)
	{
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size = flock->size_();
		if (size == 0)
		{
			return local;
		}
		if (size == 1)
		{
			return flock->at_(0);
		}
		const Ptr it = Expression::iterator_(expression, local);
		const Ptr thing = it->next_();
		return thing->invoke(it);
	}

	inline const Ptr _break_(const Ptr expression, const Ptr local)
	{
		Byte* const action = static_<Byte>(static_<Shoal>(local)->find_("@"));
		action->set_('b');
		return nothing_();
	}

	inline const Ptr _continue_(const Ptr expression, const Ptr local)
	{
		Byte* const action = static_<Byte>(static_<Shoal>(local)->find_("@"));
		action->set_('c');
		return nothing_();
	}

	inline const Ptr _return_(const Ptr expression, const Ptr local)
	{
		Byte* const action = static_<Byte>(static_<Shoal>(local)->find_("@"));
		action->set_('r');
		Flock* const flock = static_<Flock>(_flock);
		if (flock->size_())
		{
			return Expression::evaluate_(flock->at_(0), local);
		}
		return nothing_();
	}

	inline const Ptr _block_(const Ptr expression, const Ptr local)
	{
		Byte* const action = static_<Byte>(static_<Shoal>(local)->find_("@"));
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size = flock->size_();
		for (int64_t i = 0; i < size; ++i)
		{
			const Ptr result = Expression::evaluate_(flock->at_(i), local);
			if (action->get_())
			{
				return result;
			}
		}
		return nothing_();
	}

	inline const Ptr _if_(const Ptr expression, const Ptr local)
	{
		Byte* const action = static_<Byte>(static_<Shoal>(local)->find_("@"));
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size = flock->size_();
		if (size == 2)
		{
			if (!Expression::evaluate_(flock->at_(0), local)->is_("0"))
			{
				action->set_(0);
				const Ptr result = Expression::evaluate_(flock->at_(1), local);
				if (action->get_())
				{
					return result;
				}
			}
		}
		else if (size == 3)
		{
			if (!Expression::evaluate_(flock->at_(0), local)->is_("0"))
			{
				action->set_(0);
				const Ptr result = Expression::evaluate_(flock->at_(1), local);
				if (action->get_())
				{
					return result;
				}
			}
			else
			{
				action->set_(0);
				const Ptr result = Expression::evaluate_(flock->at_(2), local);
				if (action->get_())
				{
					return result;
				}
			}
		}
		return nothing_();
	}

	inline const Ptr _question_(const Ptr expression, const Ptr local)
	{
		Byte* const action = static_<Byte>(static_<Shoal>(local)->find_("@"));
		Flock* const flock = static_<Flock>(_flock);
		if (flock->size_() == 3)
		{
			if (!Expression::evaluate_(flock->at_(0), local)->is_("0"))
			{
				const Ptr result = Expression::evaluate_(flock->at_(1), local);
				action->set_(0);
				return result;
			}
			else
			{
				const Ptr result = Expression::evaluate_(flock->at_(2), local);
				action->set_(0);
				return result;
			}
		}
		return nothing_();
	}

	inline const Ptr _while_(const Ptr expression, const Ptr local)
	{
		Byte* const action = static_<Byte>(static_<Shoal>(local)->find_("@"));
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size = flock->size_();
		if (size >= 1)
		{
			while (!Expression::evaluate_(flock->at_(0), local)->is_("0"))
			{
				action->set_(0);
				for (int64_t i = 1; i < size; ++i)
				{
					const Ptr result = Expression::evaluate_(flock->at_(i), local);
					const Byte::D a = action->get_();
					if (a)
					{
						if (a == 'r')
						{
							return result;
						}
						action->set_(0);
						if (a == 'c')
						{
							break;
						}
						return result;
					}
				}
			}
		}
		return nothing_();
	}

	inline const Ptr _do_(const Ptr expression, const Ptr local)
	{
		Byte* const action = static_<Byte>(static_<Shoal>(local)->find_("@"));
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size = flock->size_();
		if (size >= 1)
		{
			do
			{
				action->set_(0);
				for (int64_t i = 0; i < size - 1; ++i)
				{
					const Ptr result = Expression::evaluate_(flock->at_(i), local);
					const Byte::D a = action->get_();
					if (a)
					{
						if (a == 'r')
						{
							return result;
						}
						action->set_(0);
						if (a == 'c')
						{
							break;
						}
						return result;
					}
				}
			} while (!Expression::evaluate_(flock->at_(size - 1), local)->is_("0"));
			action->set_(0);
		}
		return nothing_();
	}

	inline const Ptr _for_(const Ptr expression, const Ptr local)
	{
		Byte* const action = static_<Byte>(static_<Shoal>(local)->find_("@"));
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size = flock->size_();
		if (size >= 3)
		{
			for (Expression::evaluate_(flock->at_(0), local);
				!Expression::evaluate_(flock->at_(1), local)->is_("0");
				Expression::evaluate_(flock->at_(2), local))
			{
				action->set_(0);
				for (int64_t i = 3; i < size; ++i)
				{
					const Ptr result = Expression::evaluate_(flock->at_(i), local);
					const Byte::D a = action->get_();
					if (a)
					{
						if (a == 'r')
						{
							return result;
						}
						action->set_(0);
						if (a == 'c')
						{
							break;
						}
						return result;
					}
				}
			}
		}
		return nothing_();
	}

	class It : public Mutable
	{
	public:
		inline It(const Ptr flock, const Ptr local)
			: Mutable{}
			, _components{ flock }
			, _local{ local }
			, _pos{ 0 }
		{
		}

		virtual inline const Ptr next_() override;

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_components, _local);
			static_<It>(result)->_pos = _pos;
			return result;
		}

		static inline const Ptr mut_(const Ptr flock, const Ptr local)
		{
			return std::make_shared<It>(flock, local);
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Expression::It");
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
		const Ptr _components;
		const Ptr _local;
		int64_t _pos;
	};
};

//----------------------------------------------------------------------
class Function : public Thing, public Me<Function>
//----------------------------------------------------------------------
{
public:
	Function(const Ptr expression, const Ptr stat)
		: Thing{}
		, Me{}
		, _expression{ expression }
		, _static{ stat }
	{
	}

	static inline const Ptr fin_(const Ptr expression, const Ptr stat = Shoal::mut_())
	{
		const Ptr result = Me<Function>::make_(expression, stat);
		result->finalize_();
		return result;
	}

	virtual inline const Ptr copy_() const override
	{
		return Me<Function>::me_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Function");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		const Ptr local = Shoal::mut_();
		Shoal* const loc = static_<Shoal>(local);
		loc->insert_("$", _static);
		Me<Creature>* const me = dynamic_cast<Me<Creature>*>(thing);
		if (me)
		{
			Creature* const creature = static_cast<Creature*>(thing);
			loc->insert_("|", me->me_());
		}
		loc->insert_("&", it);
		loc->insert_("@", Byte::mut_());
		return static_<Expression>(_expression)->evaluate_(_expression, local);
	}

private:
	const Ptr _expression;
	const Ptr _static;
};

//----------------------------------------------------------------------
class Tokenizer : public Mutable, public Me<Tokenizer>
//----------------------------------------------------------------------
{
public:
	inline Tokenizer(const Ptr river)
		: Mutable{}
		, Me{}
		, _river{ river }
	{
	}

	static inline const Ptr mut(const Ptr it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr river)
	{
		return Me<Tokenizer>::make_(river);
	}

	virtual inline const Ptr copy_() const override
	{
		return Me<Tokenizer>::me_();
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("stat", Static::fin_(&Tokenizer::stat));
			shoal->update_("mut", Static::fin_(&Tokenizer::mut));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Tokenizer::stat));
			shoal->update_("mut", Static::fin_(&Tokenizer::mut));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	inline const bool eof_()
	{
		River* const river = dynamic_<River>(_river);
		if (river)
		{
			return river->eof_();
		}
		return !_river->invoke_("eof")->is_("0");
	}

	inline const Ptr eof(const Ptr ignore)
	{
		River* const river = dynamic_<River>(_river);
		if (river)
		{
			return river->eof(ignore);
		}
		return _river->invoke_("eof");
	}

	virtual inline const Ptr next_() override
	{
		River* const river = dynamic_<River>(_river);
		bool alphanumeric = false;
		bool numeric = false;
		bool point = false;
		bool exponent = false;
		bool second = false;
		bool singlequote = false;
		bool doublequote = false;
		bool escape = false;
		bool commentblock = false;
		bool commentline = false;
		std::string token;
		while (true)
		{
			char char1;
			char char2;
			if (river)
			{
				if (river->eof_())
				{
					break;
				}
				if (_dot)
				{
					char1 = '.';
					_dot = false;
				}
				else if (_exp)
				{
					char1 = _exp;
					_exp = 0;
				}
				else
				{
					char1 = river->get_();
				}
				char2 = river->eof_() ? 0 : river->peek_();
			}
			else
			{
				if (eof_())
				{
					break;
				}
				if (_dot)
				{
					char1 = '.';
					_dot = false;
				}
				else if (_exp)
				{
					char1 = _exp;
					_exp = 0;
				}
				else
				{
					Byte* const byte1 = dynamic_<Byte>(_river->invoke_("get"));
					if (!byte1)
					{
						break;
					}
					char1 = byte1->get_();
				}
				Byte* const byte2 = eof_() ? 0 : dynamic_<Byte>(_river->invoke_("peek"));
				char2 = byte2 ? byte2->get_() : 0;
			}

			if (char1 == '\n')
			{
				_x = 0;
				++_y;
			}

			if (commentblock)
			{
				if (char1)
					if (second && char1 == '/')
					{
						commentblock = false;
					}
				second = (char1 == '*');
			}
			else if (commentline)
			{
				if (char1 == '\n')
				{
					commentline = false;
				}
			}
			else if (escape)
			{
				switch (char1)
				{
				case '\a':
					token += '\a';
					break;
				case '\b':
					token += '\b';
					break;
				case '\f':
					token += '\f';
					break;
				case '\n':
					token += '\n';
					break;
				case '\r':
					token += '\r';
					break;
				case '\t':
					token += '\t';
					break;
				case '\v':
					token += '\v';
					break;
				default:
					token += char1;
				}
				escape = false;
			}
			else if (second)
			{
				if (char1 == '*')
				{
					commentblock = true;
					second = false;
				}
				else
				{
					return punctuation_(token + char1);
				}
			}
			else if (singlequote && char1 == '\'')
			{
				return symbol_(token + char1);
			}
			else if (doublequote && char1 == '\"')
			{
				return lake_(token + char1);
			}
			else if (singlequote || doublequote)
			{
				if (char1 == '\\')
				{
					escape = true;
				}
				else
				{
					token += char1;
				}
			}
			else switch (char1)
			{
			case ' ':
			case '\n':
			case '\t':
			case '\r':
				// skip whitespace
				break;
			case '\'':
				token = char1;
				singlequote = true;
				break;
			case '\"':
				token = char1;
				doublequote = true;
				break;
			case '!':
				if (char2 == '&' || char2 == '|' || char2 == '%')
				{
					second = true;
				}
			case '<':
			case '>':
			case '+':
			case '-':
			case '*':
			case '%':
				if (char2 == '=' || char1 == char2)
				{
					second = true;
				}
				token = char1;
				if (second)
				{
					break;
				}
				return punctuation_(token);
			case '&':
			case '|':
			case '?':
			case '@':
			case '^':
			case '$':
			case '#':
			case '~':
			case ':':
			case '.':
				token = char1;
				if (char1 == char2)
				{
					second = true;
					break;
				}
				return punctuation_(token);
			case '/':
				token = char1;
				if (char2 == '*' || char2 == '=')
				{
					second = true;
					break;
				}
				if (char2 == '/')
				{
					commentline = true;
					break;
				}
				return punctuation_(token);
			default:
			{
				const bool alpha1 = alpha_(char1);
				const bool num1 = numeric_(char1);
				const bool alpha2 = alpha_(char2);
				const bool num2 = numeric_(char2);
				if (!alphanumeric && !numeric)
				{
					if (num1 || char1 == '-' && num2)
					{
						numeric = true;
					}
					else if (alpha1)
					{
						alphanumeric = true;
					}
				}
				if (numeric)
				{
					token += char1;
					const bool exp1 = (char1 == 'E' || char1 == 'e');
					const bool pnt1 = (char1 == '.');
					if (exp1)
					{
						exponent = true;
						point = true;
					}
					else if (pnt1)
					{
						point = true;
					}
					const bool pnt2 = (char2 == '.');
					const bool exp2 = (char2 == 'E' || char2 == 'e');
					const bool sig2 = (char2 == '+' || char2 == '-');
					if (!num2 &&
						(!pnt2 || (pnt2 && point)) &&
						(!exp2 || (exp2 && exponent)) &&
						(!sig2 || (sig2 && !exp1)))
					{
						if (point || exponent)
						{
							if (pnt1)
							{
								_dot = true;
								return integer_(token.substr(0, token.length() - 1));
							}
							if (exp1)
							{
								_exp = char1;
								if (point)
								{
									if (token[token.length() - 2] == '.')
									{
										_dot = true;
										return integer_(token.substr(0, token.length() - 2));
									}
									return float_(token.substr(0, token.length() - 1));
								}
								return integer_(token.substr(0, token.length() - 1));
							}
							return float_(token);
						}
						return integer_(token);
					}
				}
				else if (alphanumeric)
				{
					token += char1;
					if (!alpha2 && !num2)
					{
						return name_(token);
					}
				}
				else
				{
					// single character punctuation
					return punctuation_(std::string(&char1, 1));
				}
			}
			}
			++_x;
		}
		if (commentline || token.empty())
		{
			return stop_();
		}
		return error_(token);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Tokenizer");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Tokenizer");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	const Ptr _river;
	int64_t _x = 0;
	int64_t _y = 0;
	bool _dot = false;
	char _exp = 0;

	static inline const bool alpha_(const char c)
	{
		return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
	}

	static inline const bool numeric_(const char c)
	{
		return c >= '0' && c <= '9';
	}

	inline const Ptr symbol_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Byte::fin_('S'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		flk->push_back_(sym_(s));
		const Ptr symbol = sym_(s.substr(1, s.length() - 2));
		if (symbol->is_("0"))
		{
			flk->push_back_(nothing_());
		}
		else if (symbol->is_("1"))
		{
			flk->push_back_(one_());
		}
		else if (symbol->is_("."))
		{
			flk->push_back_(stop_());
		}
		else
		{
			flk->push_back_(symbol);
		}
		return flock;
	}

	inline const Ptr lake_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Byte::fin_('L'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		flk->push_back_(sym_(s));
		flk->push_back_(Lake::fin_(s.substr(1, s.length() - 2)));
		return flock;
	}

	inline const Ptr name_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Byte::fin_('N'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		flk->push_back_(sym_(s));
		return flock;
	}

	inline const Ptr integer_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Byte::fin_('I'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		const Ptr symbol = sym_(s);
		flk->push_back_(symbol);
		const Ptr int64 = Int64::mut_();
		static_<Int64>(int64)->from_symbol_(symbol);
		flk->push_back_(int64);
		return flock;
	}

	inline const Ptr float_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Byte::fin_('F'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		const Ptr symbol = sym_(s);
		flk->push_back_(symbol);
		const Ptr float64 = Float64::mut_();
		static_<Float64>(float64)->from_symbol_(symbol);
		flk->push_back_(float64);
		return flock;
	}

	inline const Ptr punctuation_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Byte::fin_('P'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		flk->push_back_(sym_(s));
		return flock;
	}

	inline const Ptr error_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Byte::fin_('E'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		flk->push_back_(sym_(s));
		return flock;
	}
};

//----------------------------------------------------------------------
class Parser : public Mutable, public Me<Parser>
//----------------------------------------------------------------------
{
public:
	inline Parser(const Ptr tokenizer)
		: Mutable{}
		, Me{}
		, _tokenizer{ tokenizer }
		, _flock{ Flock::mut_() }
		, _deque{}
		, _ahead{ 0 }
	{
	}

	static inline const Ptr mut(const Ptr it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr tokenizer)
	{
		return Me<Parser>::make_(tokenizer);
	}

	virtual inline const Ptr copy_() const override
	{
		return Me<Parser>::me_();
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("stat", Static::fin_(&Parser::stat));
			shoal->update_("mut", Static::fin_(&Parser::mut));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr stat_()
	{
		static const Ptr STAT = []()
		{
			const Ptr stat = Shoal::mut_();
			Shoal* const shoal = static_<Shoal>(stat);
			shoal->update_("stat", Static::fin_(&Parser::stat));
			shoal->update_("mut", Static::fin_(&Parser::mut));
			shoal->finalize_();
			return stat;
		}();
		return STAT;
	}

	static inline const Ptr stat(const Ptr ignore)
	{
		return stat_();
	}

	inline const bool eof_()
	{
		Tokenizer* const tokenizer = dynamic_<Tokenizer>(_tokenizer);
		if (tokenizer)
		{
			return tokenizer->eof_();
		}
		return !_tokenizer->invoke_("eof")->is_("0");
	}

	inline const Ptr eof(const Ptr ignore)
	{
		Tokenizer* const tokenizer = dynamic_<Tokenizer>(_tokenizer);
		if (tokenizer)
		{
			return tokenizer->eof(ignore);
		}
		return _tokenizer->invoke_("eof");
	}

	inline const Ptr parse_()
	{
		Ptr result;
		for (bool first = true; true; first = false)
		{
			const Ptr token = _token_();
			if (token->is_("."))
			{
				break;
			}
			Flock* const tok = static_<Flock>(token);
			const char tag = char(static_<Byte>(tok->at_(0))->get_());
			const int64_t x = static_<Int64>(tok->at_(1))->get_();
			const int64_t y = static_<Int64>(tok->at_(2))->get_();
			const Ptr symbol = tok->at_(3);
			const Ptr flock = Flock::mut_();
			Flock* const flk = static_<Flock>(flock);
			const Ptr invoke = sym_("invoke");
			if (first)
			{
				if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
				{
					const Ptr lit = tok->at_(4);
					flk->push_back_(lit);
					_next_();
					_thing_(invoke, flock);
					result = Expression::fin_(invoke, flock);
					continue;
				}
				else if (tag == 'N') // name
				{
					if (symbol->is_("break") || symbol->is_("continue"))
					{
						_next_();
						result = Expression::fin_(symbol, flock);
					}
					else if (symbol->is_("return"))
					{
						_next_();
						flk->push_back_(parse_());
						result = Expression::fin_(symbol, flock);
					}
					else if (symbol->is_("if"))
					{
						_next_();
						_statement_(symbol, flock);
						const int64_t size = flk->size_();
						if (size >= 2 && size <= 3)
						{
							result = Expression::fin_(symbol, flock);
						}
						else
						{
							log_("parser error: invalid if");
						}
					}
					else if (symbol->is_("question"))
					{
						_next_();
						_statement_(symbol, flock);
						const int64_t size = flk->size_();
						if (size == 3)
						{
							result = Expression::fin_(symbol, flock);
						}
						else
						{
							log_("parser error: invalid question");
						}
					}
					else if (symbol->is_("while") || symbol->is_("do"))
					{
						_next_();
						_statement_(symbol, flock);
						const int64_t size = flk->size_();
						if (size >= 1)
						{
							result = Expression::fin_(symbol, flock);
						}
						else
						{
							log_("parser error: invalid while/do");
						}
					}
					else if (symbol->is_("for"))
					{
						_next_();
						_statement_(symbol, flock);
						const int64_t size = flk->size_();
						if (size >= 3)
						{
							result = Expression::fin_(symbol, flock);
						}
						else
						{
							log_("parser error: invalid for");
						}
					}
					else if (symbol->is_("block"))
					{
						_next_();
						_statement_(symbol, flock);
						result = Expression::fin_(symbol, flock);
					}
					else
					{
						log_("parser error: invalid statement");
					}
				}
				else if (tag == 'P') // punctuation
				{
					const Ptr at = sym_("at");
					if (symbol->is_("$")) // static
					{
						const Ptr nested = Flock::mut_();
						Flock* const nest = static_<Flock>(nested);
						nest->push_back_(Expression::fin_(invoke, Flock::mut_())); // local
						nest->push_back_(at);
						nest->push_back_(symbol);

						flk->push_back_(Expression::fin_(invoke, nested));
						flk->push_back_(at);
						_next_();
						_at_(invoke, flock);
						result = Expression::fin_(invoke, flock);
						continue;
					}
					else if (symbol->is_("|") || symbol->is_("&")) // me or it
					{
						const Ptr nested = Flock::mut_();
						Flock* const nest = static_<Flock>(nested);
						nest->push_back_(Expression::fin_(invoke, Flock::mut_())); // local
						nest->push_back_(at);
						nest->push_back_(symbol);

						flk->push_back_(Expression::fin_(invoke, nested));
						_next_();
						_thing_(invoke, flock);
						result = Expression::fin_(invoke, flock);
						continue;
					}
					else if (symbol->is_("@")) // local at
					{
						flk->push_back_(Expression::fin_(invoke, Flock::mut_())); // local
						_thing_(invoke, flock);
						result = Expression::fin_(invoke, flock);
						continue;
					}
					else if (symbol->is_("(")) // expression
					{
						//TODO
						_next_();
						_list_(invoke, flock, symbol, sym_(")"));
						result = Expression::fin_(invoke, flock);
						continue;
					}
					else if (symbol->is_("[")) // flock
					{
						//TODO
						_next_();
						_list_(invoke, flock, symbol, sym_("]"));
						result = Expression::fin_(invoke, flock);
						continue;
					}
					else if (symbol->is_("{")) // shoal
					{
						//TODO
						_next_();
					}
				}
				else if (tag == 'E') // error
				{
					log_("tokenizer error");
				}
			}
			else
			{
				if (tag == 'P') // punctuation
				{
					if (symbol->is_(".") || symbol->is_("!") || symbol->is_("#") || symbol->is_("##") ||
						symbol->is_("%") || symbol->is_("%%") || symbol->is_("%=") || symbol->is_("!%") ||
						symbol->is_("&") || symbol->is_("&&") || symbol->is_("!&") || symbol->is_("(") ||
						symbol->is_("*") || symbol->is_("**") || symbol->is_("*=") || symbol->is_("+") ||
						symbol->is_("++") || symbol->is_("+=") || symbol->is_("-") || symbol->is_("--") ||
						symbol->is_("-=") || symbol->is_("/") || symbol->is_("/=") || symbol->is_("=") ||
						symbol->is_("!=") || symbol->is_("?") || symbol->is_("@") || symbol->is_("~") ||
						symbol->is_("~~") || symbol->is_("[") || symbol->is_("^") || symbol->is_("||") ||
						symbol->is_("!|"))
					{
						flk->push_back_(result);
						_thing_(invoke, flock);
						result = Expression::fin_(invoke, flock);
						continue;
					}
				}
				else if (tag == 'E') // error
				{
					log_("tokenizer error");
				}
			}
			break;
		}
		if (result.get())
		{
			return result;
		}
		return Expression::fin_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Parser");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Parser");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	const Ptr _tokenizer;
	Ptr _flock;
	std::deque<Ptr> _deque;
	int64_t _ahead;

	inline const Ptr _token_(const int64_t lookahead = 0)
	{
		while (int64_t(_deque.size()) <= lookahead)
		{
			_deque.push_back(_tokenizer->next_());
		}
		return _deque.at(lookahead);
	}

	inline const void _next_()
	{
		if (_deque.empty())
		{
			_tokenizer->next_();
		}
		else
		{
			_deque.pop_front();
		}
	}

	inline void _thing_(const Ptr statement, const Ptr flock)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			return;
		}
		Flock* const tok = static_<Flock>(token);
		const char tag = char(static_<Byte>(tok->at_(0))->get_());
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		Flock* const flk = static_<Flock>(flock);
		if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
		{
			log_("parser error: thing literal");
		}
		else if (tag == 'N') // name
		{
			log_("parser error: thing name");
		}
		else if (tag == 'P') // punctuation
		{
			if (symbol->is_("."))
			{
				_next_();
				_dot_(statement, flock);
			}
			else if (symbol->is_("["))
			{
				_next_();
				_list_(statement, flock, symbol, sym_("]"));
			}
			else if (symbol->is_("("))
			{
				_next_();
				_list_(statement, flock, symbol, sym_(")"));
			}
			else if (symbol->is_("}") || symbol->is_(")") || symbol->is_("]") || symbol->is_(","))
			{
				return;
			}
			else if (symbol->is_("%"))
			{
				flk->push_back_(sym_("modulo"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("%="))
			{
				flk->push_back_(sym_("self_modulo"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("%%"))
			{
				flk->push_back_(sym_("xor"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("!%"))
			{
				flk->push_back_(sym_("xnor"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("+"))
			{
				flk->push_back_(sym_("add"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("+="))
			{
				flk->push_back_(sym_("self_add"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("++"))
			{
				flk->push_back_(sym_("increment"));
				_next_();
			}
			else if (symbol->is_("-"))
			{
				flk->push_back_(sym_("subtract"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("-="))
			{
				flk->push_back_(sym_("self_subtract"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("--"))
			{
				flk->push_back_(sym_("decrement"));
				_next_();
			}
			else if (symbol->is_("*"))
			{
				flk->push_back_(sym_("multiply"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("**"))
			{
				flk->push_back_(sym_("power"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("*="))
			{
				flk->push_back_(sym_("self_multiply"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("/"))
			{
				flk->push_back_(sym_("divide"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("/="))
			{
				flk->push_back_(sym_("self_divide"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("="))
			{
				flk->push_back_(sym_("same"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("!="))
			{
				flk->push_back_(sym_("different"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("@"))
			{
				flk->push_back_(sym_("at"));
				_next_();
				_at_(statement, flock);
			}
			else if (symbol->is_("&"))
			{
				flk->push_back_(sym_("iterator"));
				_next_();
			}
			else if (symbol->is_("&&"))
			{
				flk->push_back_(sym_("and"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("!&"))
			{
				flk->push_back_(sym_("nand"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("||"))
			{
				flk->push_back_(sym_("or"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("!|"))
			{
				flk->push_back_(sym_("nor"));
				_next_();
				_member_(statement, flock);
			}
			else if (symbol->is_("^"))
			{
				flk->push_back_(sym_("next"));
				_next_();
			}
			else if (symbol->is_("~"))
			{
				flk->push_back_(sym_("copy"));
				_next_();
			}
			else if (symbol->is_("~~"))
			{
				flk->push_back_(sym_("clone"));
				_next_();
			}
			else if (symbol->is_("#"))
			{
				flk->push_back_(sym_("finalize"));
				_next_();
			}
			else if (symbol->is_("##"))
			{
				flk->push_back_(sym_("freeze"));
				_next_();
			}
			else if (symbol->is_("!"))
			{
				flk->push_back_(sym_("is"));
				flk->push_back_(sym_("0"));
				_next_();
			}
			else if (symbol->is_("?"))
			{
				flk->push_back_(sym_("is_not"));
				flk->push_back_(sym_("0"));
				_next_();
			}
			else
			{
				log_("parser error: thing punctuation");
			}
		}
		else if (tag == 'E') // error
		{
			log_("tokenizer error");
		}
	}

	inline void _dot_(const Ptr statement, const Ptr flock)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			log_("parser error: dot eof");
			return;
		}
		Flock* const tok = static_<Flock>(token);
		const char tag = char(static_<Byte>(tok->at_(0))->get_());
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		Flock* const flk = static_<Flock>(flock);
		if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
		{
			log_("parser error: dot literal");
		}
		else if (tag == 'N') // name
		{
			flk->push_back_(symbol);
			_next_();
			_member_(statement, flock);
		}
		else if (tag == 'P') // punctuation
		{
			log_("parser error: dot punctuation");
		}
		else if (tag == 'E') // error
		{
			log_("tokenizer error");
		}
	}

	inline void _member_(const Ptr statement, const Ptr flock)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			return;
		}
		Flock* const tok = static_<Flock>(token);
		const char tag = char(static_<Byte>(tok->at_(0))->get_());
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
		{
			log_("parser error: member literal");
		}
		else if (tag == 'N') // name
		{
			log_("parser error: member name");
		}
		else if (tag == 'P') // punctuation
		{
			if (symbol->is_("."))
			{
				_next_();
				_dot_(statement, flock);
			}
			else if (symbol->is_("["))
			{
				_next_();
				_list_(statement, flock, symbol, sym_("]"));
			}
			else if (symbol->is_("("))
			{
				_next_();
				_list_(statement, flock, symbol, sym_(")"));
			}
			else
			{
				log_("parser error: member punctuation");
			}
		}
		else if (tag == 'E') // error
		{
			log_("tokenizer error");
		}
	}

	inline void _statement_(const Ptr statement, const Ptr flock)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			log_("parser error: statement eof");
			return;
		}
		Flock* const tok = static_<Flock>(token);
		const char tag = char(static_<Byte>(tok->at_(0))->get_());
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
		{
			log_("parser error: statement literal");
		}
		else if (tag == 'N') // name
		{
			log_("parser error: statement name");
		}
		else if (tag == 'P') // punctuation
		{
			if (symbol->is_("("))
			{
				_next_();
				_list_(statement, flock, symbol, sym_(")"));
			}
			else
			{
				log_("parser error: statement punctuation");
			}
		}
		else if (tag == 'E') // error
		{
			log_("tokenizer error");
		}
	}

	inline void _list_(const Ptr statement, const Ptr flock, const Ptr open, const Ptr close)
	{
		for (bool first = true; true; first = false)
		{
			const Ptr token = _token_();
			if (token->is_("."))
			{
				log_("parser error: open without close");
				return;
			}
			Flock* const tok = static_<Flock>(token);
			const char tag = char(static_<Byte>(tok->at_(0))->get_());
			const int64_t x = static_<Int64>(tok->at_(1))->get_();
			const int64_t y = static_<Int64>(tok->at_(2))->get_();
			const Ptr symbol = tok->at_(3);
			Flock* const flk = static_<Flock>(flock);
			if (first)
			{
				if (tag == 'P') // punctuation
				{
					if (symbol->is_(close))
					{
						_next_();
						return;
					}
					if (symbol->is_(","))
					{
						log_("parser error: open followed immediately by ,");
						return;
					}
				}
				else if (tag == 'E') // error
				{
					log_("tokenizer error");
					return;
				}
			}
			else
			{
				if (tag == 'P') // punctuation
				{
					if (symbol->is_(close))
					{
						_next_();
						return;
					}
					if (symbol->is_(","))
					{
						_next_();
					}
					else
					{
						log_("parser error: open expecting , or close");
						return;
					}
				}
				else if (tag == 'E') // error
				{
					log_("tokenizer error");
					return;
				}
				else
				{
					log_("parser error: open expecting , or close");
					return;
				}
			}
			if (open->is_("["))
			{
				flk->push_back_(Expression::immediate_(parse_()));
			}
			else
			{
				flk->push_back_(parse_());
			}
		}
	}

	inline void _at_(const Ptr statement, const Ptr flock)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			log_("parser error: at eof");
			return;
		}
		Flock* const tok = static_<Flock>(token);
		const char tag = char(static_<Byte>(tok->at_(0))->get_());
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		Flock* const flk = static_<Flock>(flock);
		if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
		{
			flk->push_back_(tok->at_(4));
		}
		else if (tag == 'N') // name
		{
			flk->push_back_(symbol);
		}
		else if (tag == 'P') // punctuation
		{
			log_("parser error: at punctuation");
			return;
		}
		else if (tag == 'E') // error
		{
			log_("tokenizer error");
			return;
		}
		_next_();
		_update_(statement, flock);
	}

	inline void _update_(const Ptr statement, const Ptr flock)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			return;
		}
		Flock* const tok = static_<Flock>(token);
		const char tag = char(static_<Byte>(tok->at_(0))->get_());
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		Flock* const flk = static_<Flock>(flock);
		if (tag == 'P') // punctuation
		{
			if (symbol->is_(":"))
			{
				flk->update_(flk->size_() - 2, sym_("update"));
				_next_();
				flk->push_back_(parse_());
			}
		}
		else if (tag == 'E') // error
		{
			log_("tokenizer error");
		}
	}
};

//======================================================================
// class Thing
//======================================================================
template <typename F>
inline const bool Thing::is_(F&& symbol) const
{
	const Symbol* const sym = dynamic_cast<const Symbol*>(this);
	return (sym && sym->symbol_() == std::forward<F>(symbol));
}

inline const bool Thing::is_(const Thing::Ptr symbol) const
{
	Symbol* const sym = dynamic_<Symbol>(symbol);
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

inline const Thing::Ptr Thing::stop_()
{
	static const Ptr STOP = sym_(".");
	return STOP;
}

inline const Thing::Ptr Thing::call(const Thing::Ptr it)
{
	const Ptr type = it->next_();
	const Ptr function = it->next_();
	const Ptr stat = static_<Shoal>(stats_())->find_(type);
	if (stat->is_("0"))
	{
		log_("call passed unknown type:");
		log_(type);
		log_(function);
		return stat;
	}
	const Ptr fun = static_<Shoal>(stat->invoke(nothing_()))->find_(function);
	if (fun->is_("0"))
	{
		log_("call passed unknown function:");
		log_(type);
		log_(function);
		return fun;
	}
	return fun->invoke(it);
}

inline const Thing::Ptr Thing::pub_() const
{
	static const Ptr PUB = []()
	{
		const Ptr pub = Shoal::mut_();
		Shoal* const shoal = static_<Shoal>(pub);
		shoal->update_("invoke", Member<Thing>::fin_(&Thing::invoke));
		shoal->update_("next", Member<Thing>::fin_(&Thing::next));
		shoal->update_("is", Const<Thing>::fin_(&Thing::is));
		shoal->update_("is_not", Const<Thing>::fin_(&Thing::is_not));
		shoal->update_("hash", Const<Thing>::fin_(&Thing::hash));
		shoal->update_("same", Const<Thing>::fin_(&Thing::same));
		shoal->update_("different", Const<Thing>::fin_(&Thing::different));
		shoal->update_("copy", Const<Thing>::fin_(&Thing::copy));
		shoal->update_("clone", Const<Thing>::fin_(&Thing::clone));
		shoal->update_("finalize", Member<Thing>::fin_(&Thing::finalize));
		shoal->update_("finalized", Const<Thing>::fin_(&Thing::finalized));
		shoal->update_("freeze", Member<Thing>::fin_(&Thing::freeze));
		shoal->update_("call", Static::fin_(&Thing::call));
		shoal->update_("stats", Static::fin_(&Thing::stats));
		shoal->update_("stat", Static::fin_(&Thing::stat));
		shoal->update_("boolean", Static::fin_(&Thing::boolean));
		shoal->update_(nothing_(), Static::fin_(&Thing::nothing));
		shoal->update_(one_(), Static::fin_(&Thing::one));
		shoal->update_(stop_(), Static::fin_(&Thing::stop));
		shoal->update_("log", Static::fin_(&Thing::log));
		shoal->update_("type", Const<Thing>::fin_(&Thing::type));
		shoal->update_("cats", Const<Thing>::fin_(&Thing::cats));
		shoal->update_("visit", Member<Thing>::fin_(&Thing::visit));
		shoal->update_("pub", Const<Thing>::fin_(&Thing::pub));
		shoal->finalize_();
		return pub;
	}();
	return PUB;
}

inline const Thing::Ptr Thing::stat_()
{
	static const Ptr STAT = []()
	{
		const Ptr stat = Shoal::mut_();
		Shoal* const shoal = static_<Shoal>(stat);
		shoal->update_("stats", Static::fin_(&Thing::stats));
		shoal->update_("stat", Static::fin_(&Thing::stat));
		shoal->update_("boolean", Static::fin_(&Thing::boolean));
		shoal->update_(nothing_(), Static::fin_(&Thing::nothing));
		shoal->update_(one_(), Static::fin_(&Thing::one));
		shoal->update_(stop_(), Static::fin_(&Thing::stop));
		shoal->update_("log", Static::fin_(&Thing::log));
		shoal->finalize_();
		return stat;
	}();
	return STAT;
}

inline const Thing::Ptr Thing::operator()(Thing* const thing, const Thing::Ptr it)
{
	const Ptr member = static_<Shoal>(pub_())->find_(it->next_());
	if (member->is_("0"))
	{
		return member;
	}
	return operate_(thing, member, it);
}

inline void Thing::log_(const Thing::Ptr ptr)
{
	const Lake* const lake = dynamic_<Lake>(ptr->invoke_("to_lake"));
	if (lake)
	{
		log_(lake->get_());
	}
}

template <typename... Args>
inline const Thing::Ptr Thing::call_(Args&&... args)
{
	std::vector<Thing::Ptr> v;
	v.reserve(sizeof...(Args));
	Variadic::variadic_(v, std::forward<Args>(args)...);
	return call(Iterator<std::vector<Ptr>>::mut_(std::move(v)));
}

template <typename... Args>
inline const Thing::Ptr Thing::invoke_(Args&&... args)
{
	std::vector<Thing::Ptr> v;
	v.reserve(sizeof...(Args));
	Variadic::variadic_(v, std::forward<Args>(args)...);
	return invoke(Iterator<std::vector<Ptr>>::mut_(std::move(v)));
}

inline const Thing::Ptr Thing::identity(const Thing::Ptr ignore) const
{
	return Int64::fin_(identity_());
}

inline const Thing::Ptr Thing::hash(const Thing::Ptr ignore) const
{
	return Int64::mut_(int64_t(hash_()));
}

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

inline const Thing::Ptr Thing::stats_()
{
	static const Ptr STATS = []()
	{
		const Ptr stats = Shoal::mut_();
		Shoal* const shoal = static_<Shoal>(stats);
		shoal->update_("strange::Thing", Static::fin_(&Thing::stat));
		shoal->update_("strange::Symbol", Static::fin_(&Symbol::stat));
		shoal->update_("strange::Shoal", Static::fin_(&Shoal::stat));
		shoal->update_("strange::Flock", Static::fin_(&Flock::stat));
		shoal->update_("strange::Herd", Static::fin_(&Herd::stat));
		shoal->update_("strange::Lake", Static::fin_(&Lake::stat));
		shoal->update_("strange::Bit", Static::fin_(&Bit::stat));
		shoal->update_("strange::Byte", Static::fin_(&Byte::stat));
		shoal->update_("strange::Int16", Static::fin_(&Int16::stat));
		shoal->update_("strange::Int32", Static::fin_(&Int32::stat));
		shoal->update_("strange::Int64", Static::fin_(&Int64::stat));
		shoal->update_("strange::Float32", Static::fin_(&Float32::stat));
		shoal->update_("strange::Float64", Static::fin_(&Float64::stat));
		shoal->update_("strange::Complex32", Static::fin_(&Complex32::stat));
		shoal->update_("strange::Complex64", Static::fin_(&Complex64::stat));
		shoal->update_("strange::River", Static::fin_(&River::stat));
		shoal->update_("strange::Fence", Static::fin_(&Fence::stat));
		shoal->finalize_();
		return stats;
	}();
	return STATS;
}

//======================================================================
// class Iterable
//======================================================================

//======================================================================
// class Variadic
//======================================================================

//======================================================================
// class Me
//======================================================================

//======================================================================
// class Serializable
//======================================================================

inline void Serializable::serialize_(const Thing::Ptr thing, const Thing::Ptr river)
{
	Thing::static_<Shoal>(Shoal::mut_())->gather_to_river_(thing, river);
}

inline const Thing::Ptr Serializable::deserialize_(const Thing::Ptr river)
{
	return Thing::static_<Shoal>(Shoal::mut_())->gather_from_river_(river);
}

inline void Serializable::to_river_(const Thing::Ptr river) const
{
	const Thing* const thing = dynamic_cast<const Thing*>(this);
	if (thing)
	{
		Lake* const lake = Thing::dynamic_<Lake>(const_cast<Thing*>(thing)->invoke_("to_lake"));
		if (lake)
		{
			lake->to_river_(river);
		}
	}
}

inline void Serializable::from_river_(const Thing::Ptr river)
{
	const Thing::Ptr lake = Lake::mut_();
	Thing::static_<Lake>(lake)->from_river_(river);
	Thing* const thing = dynamic_cast<Thing*>(this);
	if (thing)
	{
		thing->invoke_("from_lake", lake);
	}
}

inline const Thing::Ptr Serializable::to_lake_via_river_() const
{
	const Thing* const thing = dynamic_cast<const Thing*>(this);
	if (thing)
	{
		const Thing::Ptr river = River::mut_();
		const_cast<Thing*>(thing)->invoke_("to_river", river);
		const Thing::Ptr lake = Lake::mut_();
		Thing::static_<Lake>(lake)->from_river_(river);
		return lake;
	}
	return Thing::nothing_();
}

inline void Serializable::from_lake_via_river_(const Thing::Ptr lake)
{
	Lake* const lak = Thing::dynamic_<Lake>(lake);
	if (!lak)
	{
		Thing::log_("Serializable::from_lake_via_river_ passed wrong type of thing");
		return;
	}
	const Thing::Ptr river = River::mut_();
	lak->to_river_(river);
	Thing* const thing = dynamic_cast<Thing*>(this);
	if (thing)
	{
		thing->invoke_("from_river", river);
	}
}

//======================================================================
// class Symbol
//======================================================================

inline const Thing::Ptr Symbol::pub_() const
{
	static const Ptr PUB = [this]()
	{
		const Ptr pub = Thing::pub_()->copy_();
		Shoal* const shoal = static_<Shoal>(pub);
		shoal->update_("to_lake", Const<Symbol>::fin_(&Symbol::to_lake));
		shoal->update_("to_river", Const<Symbol>::fin_(&Symbol::to_river));
		shoal->update_("stat", Static::fin_(&Symbol::stat));
		shoal->update_("lak", Static::fin_(&Symbol::lak));
		shoal->update_("riv", Static::fin_(&Symbol::riv));
		shoal->update_("rwl", Static::fin_(&Symbol::rwl));
		shoal->finalize_();
		return pub;
	}();
	return PUB;
}

inline const Thing::Ptr Symbol::stat_()
{
	static const Ptr STAT = []()
	{
		const Ptr stat = Shoal::mut_();
		Shoal* const shoal = static_<Shoal>(stat);
		shoal->update_("stat", Static::fin_(&Symbol::stat));
		shoal->update_("lak", Static::fin_(&Symbol::lak));
		shoal->update_("riv", Static::fin_(&Symbol::riv));
		shoal->update_("rwl", Static::fin_(&Symbol::rwl));
		shoal->finalize_();
		return stat;
	}();
	return STAT;
}

inline const Thing::Ptr Symbol::lak_(const Thing::Ptr lake)
{
	Lake* const lak = dynamic_<Lake>(lake);
	if (!lak)
	{
		log_("Symbol::lak_ passed wrong type of thing");
		return fin_("");
	}
	return fin_(lak->get_());
}

inline const Thing::Ptr Symbol::riv_(const Thing::Ptr river)
{
	return fin_(static_<Lake>(Lake::riv_(river))->get_());
}

inline const Thing::Ptr Symbol::rwl_(const Thing::Ptr river)
{
	return fin_(static_<Lake>(Lake::rwl_(river))->get_());
}

inline const Thing::Ptr Symbol::to_lake_() const
{
	const Ptr lake = Lake::mut_(_symbol);
	lake->finalize_();
	return lake;
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

//======================================================================
// class Static
//======================================================================

//======================================================================
// class Member
//======================================================================

//======================================================================
// class Const
//======================================================================

//======================================================================
// class Mutable
//======================================================================

//======================================================================
// class Shoal
//======================================================================

inline void Shoal::to_river_(const Thing::Ptr river) const
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Shoal::to_river_ passed wrong type of thing");
		return;
	}
	riv->write_(Bit::mut_(finalized_()));
	riv->write_(Int64::mut_(int64_t(_map.size())));
	for (const auto& i : _map)
	{
		riv->push_back_(i.first);
		riv->push_back_(i.second);
	}
}

inline void Shoal::from_river_(const Thing::Ptr river)
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Shoal::from_river_ passed wrong type of thing");
		return;
	}
	const bool bit = riv->read_<Bit>();
	for (int64_t i = riv->read_<Int64>(); i > 0; --i)
	{
		const Ptr first = riv->pop_front_();
		const Ptr second = riv->pop_front_();
		_map[first] = second;
	}
	if (bit)
	{
		finalize_();
	}
}

inline void Shoal::to_river_with_links_(const Thing::Ptr shoal, const Thing::Ptr river) const
{
	Shoal* const sho = dynamic_<Shoal>(shoal);
	if (!sho)
	{
		log_("Shoal::to_river_with_links_ passed wrong type of shoal thing");
		return;
	}
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Shoal::to_river_with_links_ passed wrong type of river thing");
		return;
	}
	riv->write_(Bit::mut_(finalized_()));
	riv->write_(Int64::mut_(int64_t(_map.size())));
	for (const auto& i : _map)
	{
		static_<Symbol>(sho->find_(i.first))->to_river_(river);
		static_<Symbol>(sho->find_(i.second))->to_river_(river);
	}
}

inline void Shoal::from_river_with_links_(const Thing::Ptr river)
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Shoal::from_river_with_links_ passed wrong type of thing");
		return;
	}
	const bool bit = riv->read_<Bit>();
	for (int64_t i = riv->read_<Int64>(); i > 0; --i)
	{
		const Ptr first = Symbol::riv_(river);
		const Ptr second = Symbol::riv_(river);
		_map[first] = second;
	}
	if (bit)
	{
		finalize_();
	}
}

inline void Shoal::replace_links_(const Thing::Ptr shoal)
{
	std_unordered_map_ptr_ptr replacement;
	Shoal* const sho = static_<Shoal>(shoal);
	for (const auto& i : _map)
	{
		replacement.emplace(sho->find_(i.first), sho->find_(i.second));
	}
	_map.swap(replacement);
}

inline void Shoal::gather_to_river_(const Thing::Ptr thing, const Thing::Ptr river)
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Shoal::gather_to_river_ passed wrong type of river thing");
		return;
	}
	gather_(thing);
	riv->write_(Int64::mut_(int64_t(_map.size())));
	for (const auto& i : _map)
	{
		if (riv->push_back_with_links_(i.first, Me<Shoal>::me_()))
		{
			static_<Symbol>(i.second)->to_river_(river);
		}
	}
}

inline const Thing::Ptr Shoal::gather_from_river_(const Thing::Ptr river)
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Shoal::gather_from_river_ passed wrong type of river thing");
		return nothing_();
	}
	for (int64_t i = riv->read_<Int64>(); i > 0; --i)
	{
		const Ptr thing = riv->pop_front_with_links_();
		const Ptr symbol = Symbol::riv_(river);
		_map.emplace(symbol, thing);
	}
	for (const auto& i : _map)
	{
		i.second->invoke_("replace_links", Me<Shoal>::me_());
	}
	return find_(nothing_());
}

inline const Thing::Ptr Shoal::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_<Herd>(cats);
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterable");
		herd->insert_("strange::Shoal");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Shoal::It::cats_() const
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

//======================================================================
// class Decorator
//======================================================================

//======================================================================
// class Iterator
//======================================================================

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

//======================================================================
// class Flock
//======================================================================

inline const Thing::Ptr Flock::size(const Thing::Ptr ignore) const
{
	return Int64::mut_(size_());
}

inline const Thing::Ptr Flock::at_(const Thing::Ptr pos) const
{
	Number* const number = dynamic_<Number>(pos);
	if (number)
	{
		return at_(number->to_int64_());
	}
	return nothing_();
}

inline const Thing::Ptr Flock::update_(const Thing::Ptr pos, const Thing::Ptr value)
{
	Number* const number = dynamic_<Number>(pos);
	if (number)
	{
		return update_(number->to_int64_(), value);
	}
	return nothing_();
}

inline const Thing::Ptr Flock::Concurrent::size(const Thing::Ptr ignore) const
{
	return Int64::mut_(size_());
}

inline const Thing::Ptr Flock::Concurrent::at_(const Thing::Ptr pos) const
{
	Number* const number = dynamic_<Number>(pos);
	if (number)
	{
		const int64_t p = number->to_int64_();
		std::shared_lock<std::shared_timed_mutex> lock(_mutex);
		if (p >= 0 && p < static_<Flock>(_flock)->size_())
		{
			return static_<Flock>(_flock)->at_(p);
		}
	}
	return nothing_();
}

inline void Flock::to_river_(const Thing::Ptr river) const
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Flock::to_river_ passed wrong type of thing");
		return;
	}
	riv->write_(Bit::mut_(finalized_()));
	riv->write_(Int64::mut_(int64_t(_vector.size())));
	for (const auto i : _vector)
	{
		riv->push_back_(i);
	}
}

inline void Flock::from_river_(const Thing::Ptr river)
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Flock::from_river_ passed wrong type of thing");
		return;
	}
	const bool bit = riv->read_<Bit>();
	const int64_t int64 = riv->read_<Int64>();
	_vector.reserve(size_t(int64));
	for (int64_t i = int64; i > 0; --i)
	{
		_vector.push_back(riv->pop_front_());
	}
	if (bit)
	{
		finalize_();
	}
}

inline void Flock::to_river_with_links_(const Thing::Ptr shoal, const Thing::Ptr river) const
{
	Shoal* const sho = dynamic_<Shoal>(shoal);
	if (!sho)
	{
		log_("Flock::to_river_with_links_ passed wrong type of shoal thing");
		return;
	}
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Flock::to_river_with_links_ passed wrong type of river thing");
		return;
	}
	riv->write_(Bit::mut_(finalized_()));
	riv->write_(Int64::mut_(int64_t(_vector.size())));
	for (const auto i : _vector)
	{
		static_<Symbol>(sho->find_(i))->to_river_(river);
	}
}

inline void Flock::from_river_with_links_(const Thing::Ptr river)
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Flock::from_river_with_links_ passed wrong type of thing");
		return;
	}
	const bool bit = riv->read_<Bit>();
	const int64_t int64 = riv->read_<Int64>();
	_vector.reserve(size_t(int64));
	for (int64_t i = int64; i > 0; --i)
	{
		_vector.push_back(Symbol::riv_(river));
	}
	if (bit)
	{
		finalize_();
	}
}

inline void Flock::replace_links_(const Thing::Ptr shoal)
{
	Shoal* const sho = static_<Shoal>(shoal);
	for (std_vector_ptr::iterator i = _vector.begin(); i != _vector.end(); ++i)
	{
		*i = sho->find_(*i);
	}
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

//======================================================================
// class Herd
//======================================================================

inline void Herd::to_river_(const Thing::Ptr river) const
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Herd::to_river_ passed wrong type of thing");
		return;
	}
	riv->write_(Bit::mut_(finalized_()));
	riv->write_(Int64::mut_(int64_t(_set.size())));
	for (const auto i : _set)
	{
		riv->push_back_(i);
	}
}

inline void Herd::from_river_(const Thing::Ptr river)
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Herd::from_river_ passed wrong type of thing");
		return;
	}
	const bool bit = riv->read_<Bit>();
	for (int64_t i = riv->read_<Int64>(); i > 0; --i)
	{
		_set.insert(riv->pop_front_());
	}
	if (bit)
	{
		finalize_();
	}
}

inline void Herd::to_river_with_links_(const Thing::Ptr shoal, const Thing::Ptr river) const
{
	Shoal* const sho = dynamic_<Shoal>(shoal);
	if (!sho)
	{
		log_("Herd::to_river_with_links_ passed wrong type of shoal thing");
		return;
	}
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Herd::to_river_with_links_ passed wrong type of river thing");
		return;
	}
	riv->write_(Bit::mut_(finalized_()));
	riv->write_(Int64::mut_(int64_t(_set.size())));
	for (const auto i : _set)
	{
		static_<Symbol>(sho->find_(i))->to_river_(river);
	}
}

inline void Herd::from_river_with_links_(const Thing::Ptr river)
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Herd::from_river_with_links_ passed wrong type of thing");
		return;
	}
	const bool bit = riv->read_<Bit>();
	for (int64_t i = riv->read_<Int64>(); i > 0; --i)
	{
		_set.insert(Symbol::riv_(river));
	}
	if (bit)
	{
		finalize_();
	}
}

inline void Herd::replace_links_(const Thing::Ptr shoal)
{
	std_unordered_set_ptr replacement;
	Shoal* const sho = static_<Shoal>(shoal);
	for (const auto i : _set)
	{
		replacement.insert(sho->find_(i));
	}
	_set.swap(replacement);
}

//======================================================================
// class Data
//======================================================================

//======================================================================
// class Lake
//======================================================================

inline void Lake::to_river_(const Thing::Ptr river) const
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Lake::to_river_ passed wrong type of thing");
		return;
	}
	riv->write_(Bit::mut_(finalized_()));
	riv->write_(Int64::mut_(int64_t(get_().length())));
	riv->write_(get_());
}

inline void Lake::from_river_(const Thing::Ptr river)
{
	River* const riv = dynamic_<River>(river);
	if (!riv)
	{
		log_("Lake::from_river_ passed wrong type of thing");
		return;
	}
	const bool bit = riv->read_<Bit>();
	const int64_t int64 = riv->read_<Int64>();
	set_(static_<Lake>(riv->read_(int64))->get_());
	if (bit)
	{
		finalize_();
	}
}

//======================================================================
// class Number
//======================================================================

inline const Thing::Ptr Number::to_int64(const Thing::Ptr ignore) const
{
	return Int64::mut_(to_int64_());
}

inline void Number::from_int64_(const Thing::Ptr ptr)
{
	Int64* const int64 = dynamic_<Int64>(ptr);
	if (int64)
	{
		from_int64_(int64->get_());
	}
}

inline const Thing::Ptr Number::to_float64(const Thing::Ptr ignore) const
{
	return Float64::mut_(to_float64_());
}

inline void Number::from_float64_(const Thing::Ptr ptr)
{
	Float64* const float64 = dynamic_<Float64>(ptr);
	if (float64)
	{
		from_float64_(float64->get_());
	}
}

inline const Thing::Ptr Number::to_imaginary64(const Thing::Ptr ignore) const
{
	return Float64::mut_(to_imaginary64_());
}

inline void Number::from_imaginary64_(const Thing::Ptr ptr)
{
	Float64* const float64 = dynamic_<Float64>(ptr);
	if (float64)
	{
		from_imaginary64_(float64->get_());
	}
}

inline const Thing::Ptr Number::to_complex64(const Thing::Ptr ignore) const
{
	return Complex64::mut_(to_complex64_());
}

inline void Number::from_complex64_(const Thing::Ptr ptr)
{
	Complex64* const complex64 = dynamic_<Complex64>(ptr);
	if (complex64)
	{
		from_complex64_(complex64->get_());
	}
}

//======================================================================
// class Bit
//======================================================================

//======================================================================
// class Byte
//======================================================================

//======================================================================
// class Int16
//======================================================================

//======================================================================
// class Int32
//======================================================================

//======================================================================
// class Int64
//======================================================================

//======================================================================
// class Float32
//======================================================================

//======================================================================
// class Float64
//======================================================================

//======================================================================
// class Complex32
//======================================================================

//======================================================================
// class Complex64
//======================================================================

//======================================================================
// class River
//======================================================================

//======================================================================
// class Fence
//======================================================================

//======================================================================
// class Creator
//======================================================================

//======================================================================
// class Creature
//======================================================================

//======================================================================
// class Expression
//======================================================================

//======================================================================
// class Function
//======================================================================

//======================================================================
// class Tokenizer
//======================================================================

//======================================================================
// class Parser
//======================================================================

} // namespace strange

#endif
