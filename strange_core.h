#ifndef COM_ONEISH_STRANGE_CORE_H
#define COM_ONEISH_STRANGE_CORE_H

#include <memory>
#include <cstring>
#include <iostream>
#include <atomic>
#include <vector>
#include <unordered_set>
#include <unordered_map>
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
	class Variadic;
	class Serializable;
	class Symbol;
	class Static;
	template <typename T> class Member;
	template <typename T> class Const;
	class Mutable;
	class Shoal;
	class Flock;
	class Herd;
	class IteratorPtr;
	template <typename C> class IteratorCopy;
	template <typename C> class IteratorRef;
	template <typename D> class Data;
	class Lake;
	class Number;
	class Bit;
	class Int8;
	class UInt8;
	class Int16;
	class Int32;
	class Int64;
	class Float32;
	class Float64;
	class Complex32;
	class Complex64;
	class River;

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
	using WeakPtr = std::weak_ptr<Thing>;

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
		return boolean_(!ptr->is_nothing_());
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
	static inline void share_(const Ptr shoal);

	static inline const Ptr shared_();

	template <typename F>
	static inline const Ptr sym_(F&& symbol);

	// public static symbols
	static inline const Ptr nothing_()
	{
		static const Ptr NOTHING = sym_("");
		return NOTHING;
	}

	static inline const Ptr nothing(const Ptr ignore)
	{
		return nothing_();
	}

	static inline const Ptr one_()
	{
		static const Ptr ONE = sym_("1");
		return ONE;
	}

	static inline const Ptr one(const Ptr ignore)
	{
		return one_();
	}

	static inline const Ptr stop_()
	{
		static const Ptr STOP = sym_(".");
		return STOP;
	}

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

	// public impure virtual member functions and adapters
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

	inline const Ptr me_() const
	{
		const Ptr ptr = _me.lock();
		if (ptr)
		{
			return ptr;
		}
		return nothing_();
	}

	virtual inline const Ptr copy_() const
	{
		return me_();
	}

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

	virtual inline const Ptr replicate_() const
	{
		if (finalized_())
		{
			return me_();
		}
		return copy_();
	}

	inline const Ptr replicate(const Ptr ignore) const
	{
		return replicate_();
	}

	virtual inline const Ptr iterator_() const;

	inline const Ptr iterator(const Ptr ignore) const
	{
		return iterator_();
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

	virtual inline const Ptr eater_() const
	{
		return nothing_();
	}

	virtual inline const Ptr feeder(const Ptr eater) const
	{
		return nothing_();
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

	inline const bool is_nothing_() const
	{
		return is_("");
	}

	inline const Ptr is_nothing(const Ptr ignore) const
	{
		return boolean_(is_nothing_());
	}

	inline const Ptr is_not_nothing(const Ptr ignore) const
	{
		return boolean_(!is_nothing_());
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

	template <typename T, typename... Args>
	static inline const Ptr make_(Args&&... args)
	{
		const Ptr result = std::make_shared<T>(std::forward<Args>(args)...);
		result->_me = result;
		return result;
	}

	template <typename T, typename... Args>
	static inline const Ptr fake_(Args&&... args)
	{
		const Ptr result = make_<T>(std::forward<Args>(args)...);
		result->finalize_();
		return result;
	}

	// protected construction/destruction/assignment
	Thing() = default;

	// protected impure virtual member functions and adapters
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it);

private:
	WeakPtr _me;

	// private static utility functions
	static std::atomic<bool>& _finalized_()
	{
		static std::atomic<bool> FINALIZED(true);
		return FINALIZED;
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
		to_river_(river);
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
		from_river_(river);
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
class Symbol : public Thing, public Serializable
//----------------------------------------------------------------------
{
public:
	template <typename F>
	inline Symbol(F&& symbol)
		: Thing{}
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

	template <typename F>
	static inline const Ptr fin_(F&& symbol)
	{
		return fake_<Symbol>(std::forward<F>(symbol));
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

	static inline void share_(const Ptr shoal);

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
class Static : public Thing
//----------------------------------------------------------------------
{
	using function = const Ptr(*)(const Ptr);

public:
	template <typename F>
	inline Static(const function fun, F&& params)
		: Thing{}
		, _function{ fun }
		, _params{ std::forward<F>(params) }
	{
	}

	template <typename F>
	static inline const Ptr with_params_(const function fun, F&& params)
	{
		return fake_<Static>(fun, std::forward<F>(params));
	}

	template <typename... Args>
	static inline const Ptr fin_(const function fun, Args&&... args)
	{
		std::vector<Thing::Ptr> v;
		v.reserve(sizeof...(Args));
		Variadic::variadic_(v, std::forward<Args>(args)...);
		return with_params_(fun, std::move(v));
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Static");
		return TYPE;
	}

	virtual inline const Ptr eater_() const override;

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		return _function(it);
	}

private:
	const function _function;
	std::vector<Ptr> _params;
};

template <typename T>
//----------------------------------------------------------------------
class Member : public Thing
//----------------------------------------------------------------------
{
	using member = const Ptr(T::*)(const Ptr);

public:
	template <typename F>
	inline Member(const member fun, F&& params)
		: Thing{}
		, _function{ fun }
		, _params{ std::forward<F>(params) }
	{
	}

	template <typename F>
	static inline const Ptr with_params_(const member fun, F&& params)
	{
		return fake_<Member<T>>(fun, std::forward<F>(params));
	}

	template <typename... Args>
	static inline const Ptr fin_(const member fun, Args&&... args)
	{
		std::vector<Thing::Ptr> v;
		v.reserve(sizeof...(Args));
		Variadic::variadic_(v, std::forward<Args>(args)...);
		return with_params_(fun, std::move(v));
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Member");
		return TYPE;
	}

	virtual inline const Ptr eater_() const override;

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
	std::vector<Ptr> _params;
};

template <typename T>
//----------------------------------------------------------------------
class Const : public Thing
//----------------------------------------------------------------------
{
	using member = const Ptr(T::*)(const Ptr) const;

public:
	template <typename F>
	inline Const(const member fun, F&& params)
		: Thing{}
		, _function{ fun }
		, _params{ std::forward<F>(params) }
	{
	}

	template <typename F>
	static inline const Ptr with_params_(const member fun, F&& params)
	{
		return fake_<Const<T>>(fun, std::forward<F>(params));
	}

	template <typename... Args>
	static inline const Ptr fin_(const member fun, Args&&... args)
	{
		std::vector<Thing::Ptr> v;
		v.reserve(sizeof...(Args));
		Variadic::variadic_(v, std::forward<Args>(args)...);
		return with_params_(fun, std::move(v));
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Const");
		return TYPE;
	}

	virtual inline const Ptr eater_() const override;

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
	std::vector<Ptr> _params;
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
class Shoal : public Mutable, public Serializable
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
		, Serializable{}
		, _map{}
		, _frozen{ false }
	{
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

	virtual inline const Ptr replicate_() const override
	{
		if (frozen_())
		{
			return me_();
		}
		const Ptr result = mut_();
		std_unordered_map_ptr_ptr& replicant = static_<Shoal>(result)->_map;
		for (const auto& i : _map)
		{
			replicant[i.first->replicate_()] = i.second->replicate_();
		}
		if (finalized_())
		{
			result->finalize_();
		}
		return result;
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
			shoal->update_("from_lake", Member<Shoal>::fin_(&Shoal::from_lake, "lake"));
			shoal->update_("to_river", Const<Shoal>::fin_(&Shoal::to_river, "river"));
			shoal->update_("from_river", Member<Shoal>::fin_(&Shoal::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Shoal::mut));
			shoal->update_("lak", Static::fin_(&Shoal::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Shoal::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Shoal::rwl, "river"));
			shoal->update_("find", Const<Shoal>::fin_(&Shoal::find, "key"));
			shoal->update_("update", Member<Shoal>::fin_(&Shoal::update, "key", "value"));
			shoal->update_("insert", Member<Shoal>::fin_(&Shoal::insert, "key", "value"));
			shoal->update_("feeder", Const<Shoal>::fin_(&Shoal::feeder, ".."));
			shoal->update_("itemize", Member<Shoal>::fin_(&Shoal::itemize, "key"));
			shoal->update_("gather", Member<Shoal>::fin_(&Shoal::gather, "key"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Shoal::mut", Static::fin_(&Shoal::mut));
		s->update_("strange::Shoal::lak", Static::fin_(&Shoal::lak, "lake"));
		s->update_("strange::Shoal::riv", Static::fin_(&Shoal::riv, "river"));
		s->update_("strange::Shoal::rwl", Static::fin_(&Shoal::rwl, "river"));
	}

	static inline const Ptr mut_()
	{
		return make_<Shoal>();
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
		if (value->is_nothing_())
		{
			_map.erase(key);
		}
		else
		{
			_map[key] = value;
		}
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
		return Iterator::mut_(me_());
	}

	virtual inline const Ptr feeder(const Ptr eater) const override
	{
		return Feeder::mut_(me_(), eater);
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
		if (!result->is_nothing_())
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
		item->invoke_("visit", me_(), "itemize", item);
	}

	inline const Ptr gather(const Ptr it)
	{
		gather_(it->next_());
		return nothing_();
	}

	inline void gather_to_river_(const Ptr thing, const Ptr river);

	inline const Ptr gather_from_river_(const Ptr river);

	class Concurrent : public Mutable
	{
	public:
		inline Concurrent(const Ptr shoal)
			: Mutable{}
			, _shoal{ shoal }
			, _mutex{}
		{
		}

		virtual inline const Ptr pub_() const override
		{
			static const Ptr PUB = [this]()
			{
				const Ptr pub = Thing::pub_()->copy_();
				Shoal* const shoal = static_<Shoal>(pub);
				shoal->update_("find", Const<Concurrent>::fin_(&Concurrent::find, "key"));
				shoal->update_("update", Member<Concurrent>::fin_(&Concurrent::update, "key", "value"));
				shoal->update_("insert", Member<Concurrent>::fin_(&Concurrent::insert, "key", "value"));
				shoal->update_("mut", Static::fin_(&Concurrent::mut, "shoal"));
				shoal->finalize_();
				return pub;
			}();
			return PUB;
		}

		static inline void share_(const Ptr shoal)
		{
			Shoal* const s = static_<Shoal>(shoal);
			s->update_("strange::Shoal::Concurrent::mut", Static::fin_(&Shoal::Concurrent::mut, "shoal"));
		}

		static inline const Ptr mut_(const Ptr shoal)
		{
			return make_<Concurrent>(shoal);
		}

		static inline const Ptr mut(const Ptr it)
		{
			return mut_(it->next_());
		}

		virtual inline const Ptr copy_() const override
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return mut_(_shoal->copy_());
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

	class Iterator : public Mutable
	{
	public:
		inline Iterator(const Ptr shoal)
			: Mutable{}
			, _shoal{ shoal }
			, _iterator{ static_<Shoal>(_shoal)->_map.cbegin() }
		{
		}

		virtual inline const Ptr next_() override;

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_shoal);
			static_<Iterator>(result)->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr shoal)
		{
			return make_<Iterator>(shoal);
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Shoal:Iterator");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override;

	private:
		const Ptr _shoal;
		std_unordered_map_ptr_ptr::const_iterator _iterator;
	};

	class Feeder : public Thing
	{
	public:
		inline Feeder(const Ptr shoal, const Ptr eater)
			: Thing{}
			, _shoal{ shoal }
			, _eater{ eater }
		{
		}

		virtual inline const Ptr next_() override
		{
			const Ptr n = _eater->next_();
			if (n->is_("."))
			{
				return n;
			}
			return static_<Shoal>(_shoal)->find_(n);
		}

		static inline const Ptr mut_(const Ptr shoal, const Ptr eater)
		{
			return make_<Feeder>(shoal, eater);
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Shoal:Feeder");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override;

	private:
		const Ptr _shoal;
		const Ptr _eater;
	};
};

//----------------------------------------------------------------------
class Flock : public Mutable, public Serializable
//----------------------------------------------------------------------
{
	using std_vector_ptr = std::vector<Ptr>;

public:
	inline Flock()
		: Mutable{}
		, Serializable{}
		, _vector{}
		, _frozen{ false }
	{
	}

	inline Flock(const Ptr it)
		: Mutable{}
		, Serializable{}
		, _vector{}
		, _frozen{ false }
	{
		for (Ptr n = it->next_(); !n->is_("."); n = it->next_())
		{
			_vector.push_back(n);
		}
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

	virtual inline const Ptr replicate_() const override
	{
		if (frozen_())
		{
			return me_();
		}
		const Ptr result = mut_();
		std_vector_ptr& replicant = static_<Flock>(result)->_vector;
		replicant.reserve(_vector.size());
		for (const auto i : _vector)
		{
			replicant.push_back(i->replicate_());
		}
		if (finalized_())
		{
			result->finalize_();
		}
		return result;
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
			shoal->update_("from_lake", Member<Flock>::fin_(&Flock::from_lake, "lake"));
			shoal->update_("to_river", Const<Flock>::fin_(&Flock::to_river, "river"));
			shoal->update_("from_river", Member<Flock>::fin_(&Flock::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Flock::mut));
			shoal->update_("lak", Static::fin_(&Flock::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Flock::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Flock::rwl, "river"));
			shoal->update_("push_back", Member<Flock>::fin_(&Flock::push_back, "value"));
			shoal->update_("size", Const<Flock>::fin_(&Flock::size));
			shoal->update_("empty", Const<Flock>::fin_(&Flock::empty));
			shoal->update_("at", Const<Flock>::fin_(&Flock::at, "index"));
			shoal->update_("update", Member<Flock>::fin_(&Flock::update, "index", "value"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Flock::mut", Static::fin_(&Flock::mut));
		s->update_("strange::Flock::lak", Static::fin_(&Flock::lak, "lake"));
		s->update_("strange::Flock::riv", Static::fin_(&Flock::riv, "river"));
		s->update_("strange::Flock::rwl", Static::fin_(&Flock::rwl, "river"));
	}

	static inline const Ptr mut_()
	{
		return make_<Flock>();
	}

	static inline const Ptr mut(const Ptr it)
	{
		return make_<Flock>(it);
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
		return Iterator::mut_(me_());
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
		if (!result->is_nothing_())
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

	class Concurrent : public Mutable
	{
	public:
		inline Concurrent(const Ptr flock)
			: Mutable{}
			, _flock{ flock }
			, _mutex{}
		{
		}

		virtual inline const Ptr pub_() const override
		{
			static const Ptr PUB = [this]()
			{
				const Ptr pub = Thing::pub_()->copy_();
				Shoal* const shoal = static_<Shoal>(pub);
				shoal->update_("push_back", Member<Concurrent>::fin_(&Concurrent::push_back, "value"));
				shoal->update_("size", Const<Concurrent>::fin_(&Concurrent::size));
				shoal->update_("at", Const<Concurrent>::fin_(&Concurrent::at, "index"));
				shoal->update_("mut", Static::fin_(&Concurrent::mut, "flock"));
				shoal->finalize_();
				return pub;
			}();
			return PUB;
		}

		static inline void share_(const Ptr shoal)
		{
			Shoal* const s = static_<Shoal>(shoal);
			s->update_("strange::Flock::Concurrent::mut", Static::fin_(&Flock::Concurrent::mut, "flock"));
		}

		static inline const Ptr mut_(const Ptr flock)
		{
			return make_<Concurrent>(flock);
		}

		static inline const Ptr mut(const Ptr it)
		{
			return mut_(it->next_());
		}

		virtual inline const Ptr copy_() const override
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return mut_(_flock->copy_());
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

	class Iterator : public Mutable
	{
	public:
		inline Iterator(const Ptr flock)
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
			static_<Iterator>(result)->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr flock)
		{
			return make_<Iterator>(flock);
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Flock::Iterator");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override;

	private:
		const Ptr _flock;
		std_vector_ptr::const_iterator _iterator;
	};
};

//----------------------------------------------------------------------
class Herd : public Mutable, public Serializable
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
		, Serializable{}
		, _set{}
		, _frozen{ false }
	{
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

	virtual inline const Ptr replicate_() const override
	{
		if (frozen_())
		{
			return me_();
		}
		const Ptr result = mut_();
		std_unordered_set_ptr& replicant = static_<Herd>(result)->_set;
		for (const auto i : _set)
		{
			replicant.insert(i->replicate_());
		}
		if (finalized_())
		{
			result->finalize_();
		}
		return result;
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
			shoal->update_("from_lake", Member<Herd>::fin_(&Herd::from_lake, "lake"));
			shoal->update_("to_river", Const<Herd>::fin_(&Herd::to_river, "river"));
			shoal->update_("from_river", Member<Herd>::fin_(&Herd::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Herd::mut));
			shoal->update_("lak", Static::fin_(&Herd::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Herd::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Herd::rwl, "river"));
			shoal->update_("find", Const<Herd>::fin_(&Herd::find, "key"));
			shoal->update_("insert", Member<Herd>::fin_(&Herd::insert, "key"));
			shoal->update_("gather", Member<Herd>::fin_(&Herd::gather, "key"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Herd::mut", Static::fin_(&Herd::mut));
		s->update_("strange::Herd::lak", Static::fin_(&Herd::lak, "lake"));
		s->update_("strange::Herd::riv", Static::fin_(&Herd::riv, "river"));
		s->update_("strange::Herd::rwl", Static::fin_(&Herd::rwl, "river"));
	}

	static inline const Ptr mut_()
	{
		return make_<Herd>();
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
		if (item->is_nothing_())
		{
			return false;
		}
		return _set.insert(item).second;
	}

	inline const Ptr insert(const Ptr it)
	{
		return boolean_(insert_(it->next_()));
	}

	virtual inline const Ptr iterator_() const override
	{
		return Iterator::mut_(me_());
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
		if (!result->is_nothing_())
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
		item->invoke_("visit", me_(), "insert", item);
	}

	inline const Ptr gather(const Ptr it)
	{
		gather_(it->next_());
		return nothing_();
	}

	class Concurrent : public Mutable
	{
	public:
		inline Concurrent(const Ptr herd)
			: Mutable{}
			, _herd{ herd }
			, _mutex{}
		{
		}

		virtual inline const Ptr pub_() const override
		{
			static const Ptr PUB = [this]()
			{
				const Ptr pub = Thing::pub_()->copy_();
				Shoal* const shoal = static_<Shoal>(pub);
				shoal->update_("find", Const<Concurrent>::fin_(&Concurrent::find, "key"));
				shoal->update_("insert", Member<Concurrent>::fin_(&Concurrent::insert, "key"));
				shoal->update_("mut", Static::fin_(&Concurrent::mut, "herd"));
				shoal->finalize_();
				return pub;
			}();
			return PUB;
		}

		static inline void share_(const Ptr shoal)
		{
			Shoal* const s = static_<Shoal>(shoal);
			s->update_("strange::Herd::Concurrent::mut", Static::fin_(&Herd::Concurrent::mut, "herd"));
		}

		static inline const Ptr mut_(const Ptr herd)
		{
			return make_<Concurrent>(herd);
		}

		static inline const Ptr mut(const Ptr it)
		{
			return mut_(it->next_());
		}

		virtual inline const Ptr copy_() const override
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return mut_(_herd->copy_());
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

	class Iterator : public Mutable
	{
	public:
		inline Iterator(const Ptr herd)
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
			static_<Iterator>(result)->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr herd)
		{
			return make_<Iterator>(herd);
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Herd::Iterator");
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

//----------------------------------------------------------------------
class IteratorPtr : public Mutable
//----------------------------------------------------------------------
{
public:
	inline IteratorPtr(const Ptr ptr)
		: Mutable{}
		, _ptr{ ptr }
	{
	}

	static inline const Ptr mut(const Ptr it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr ptr)
	{
		return make_<IteratorPtr>(ptr);
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(_ptr);
	}

	virtual inline const Ptr next_() override
	{
		const Ptr ptr = _ptr;
		_ptr = stop_();
		return ptr;
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&IteratorPtr::mut, "thing"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::IteratorPtr");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	Ptr _ptr;
};

template <typename C>
//----------------------------------------------------------------------
class IteratorCopy : public Mutable
//----------------------------------------------------------------------
{
public:
	template <typename F>
	inline IteratorCopy(F&& collection)
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
		static_<IteratorCopy<C>>(result)->_iterator += (_iterator - _collection.cbegin());
		return result;
	}

	template <typename F>
	static inline const Ptr mut_(F&& collection)
	{
		return make_<IteratorCopy<C>>(std::forward<F>(collection));
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::IteratorCopy");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::IteratorCopy");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	const C _collection;
	typename C::const_iterator _iterator;
};

template <typename C>
//----------------------------------------------------------------------
class IteratorRef : public Mutable
//----------------------------------------------------------------------
{
public:
	template <typename F>
	inline IteratorRef(F&& collection)
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
		static_<IteratorRef<C>>(result)->_iterator += (_iterator - _collection.cbegin());
		return result;
	}

	template <typename F>
	static inline const Ptr mut_(F&& collection)
	{
		return make_<IteratorRef<C>>(std::forward<F>(collection));
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::IteratorRef");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::IteratorRef");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	const C& _collection;
	typename C::const_iterator _iterator;
};

template <typename D>
//----------------------------------------------------------------------
class Data
//----------------------------------------------------------------------
{
public:
	inline Data(const D& data)
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
		return make_<Lake>(data);
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
			shoal->update_("from_lake", Member<Lake>::fin_(&Lake::from_lake, "lake"));
			shoal->update_("to_river", Const<Lake>::fin_(&Lake::to_river, "river"));
			shoal->update_("from_river", Member<Lake>::fin_(&Lake::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Lake::mut));
			shoal->update_("fin", Static::fin_(&Lake::fin));
			shoal->update_("lak", Static::fin_(&Lake::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Lake::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Lake::rwl, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Lake::mut", Static::fin_(&Lake::mut));
		s->update_("strange::Lake::fin", Static::fin_(&Lake::fin));
		s->update_("strange::Lake::lak", Static::fin_(&Lake::lak, "lake"));
		s->update_("strange::Lake::riv", Static::fin_(&Lake::riv, "river"));
		s->update_("strange::Lake::rwl", Static::fin_(&Lake::rwl, "river"));
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
			shoal->update_("from_int64", Member<Number>::fin_(&Number::from_int64, "int64"));
			shoal->update_("to_float64", Const<Number>::fin_(&Number::to_float64));
			shoal->update_("from_float64", Member<Number>::fin_(&Number::from_float64, "float64"));
			shoal->update_("to_imaginary64", Const<Number>::fin_(&Number::to_imaginary64));
			shoal->update_("from_imaginary64", Member<Number>::fin_(&Number::from_imaginary64, "imaginary64"));
			shoal->update_("to_complex64", Const<Number>::fin_(&Number::to_complex64));
			shoal->update_("from_complex64", Member<Number>::fin_(&Number::from_complex64, "complex64"));
			shoal->update_("to_symbol", Const<Number>::fin_(&Number::to_symbol));
			shoal->update_("from_symbol", Member<Number>::fin_(&Number::from_symbol, "symbol"));
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
		return make_<Bit>(data);
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
			shoal->update_("from_lake", Member<Bit>::fin_(&Bit::from_lake, "lake"));
			shoal->update_("to_river", Const<Bit>::fin_(&Bit::to_river, "river"));
			shoal->update_("from_river", Member<Bit>::fin_(&Bit::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Bit::mut));
			shoal->update_("fin", Static::fin_(&Bit::fin));
			shoal->update_("lak", Static::fin_(&Bit::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Bit::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Bit::rwl, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Bit::mut", Static::fin_(&Bit::mut));
		s->update_("strange::Bit::fin", Static::fin_(&Bit::fin));
		s->update_("strange::Bit::lak", Static::fin_(&Bit::lak, "lake"));
		s->update_("strange::Bit::riv", Static::fin_(&Bit::riv, "river"));
		s->update_("strange::Bit::rwl", Static::fin_(&Bit::rwl, "river"));
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
class Int8 : public Number, public Data<int8_t>
//----------------------------------------------------------------------
{
public:
	using D = int8_t;

	static inline const Ptr mut_(const D& data = D())
	{
		return make_<Int8>(data);
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
		static_<Int8>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Int8>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<Int8>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline Int8(const D& data)
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
			shoal->update_("to_lake", Const<Int8>::fin_(&Int8::to_lake));
			shoal->update_("from_lake", Member<Int8>::fin_(&Int8::from_lake, "lake"));
			shoal->update_("to_river", Const<Int8>::fin_(&Int8::to_river, "river"));
			shoal->update_("from_river", Member<Int8>::fin_(&Int8::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Int8::mut));
			shoal->update_("fin", Static::fin_(&Int8::fin));
			shoal->update_("lak", Static::fin_(&Int8::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Int8::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Int8::rwl, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Int8::mut", Static::fin_(&Int8::mut));
		s->update_("strange::Int8::fin", Static::fin_(&Int8::fin));
		s->update_("strange::Int8::lak", Static::fin_(&Int8::lak, "lake"));
		s->update_("strange::Int8::riv", Static::fin_(&Int8::riv, "river"));
		s->update_("strange::Int8::rwl", Static::fin_(&Int8::rwl, "river"));
	}

	virtual inline const Ptr to_lake_() const override
	{
		const Ptr lake = Lake::mut_(std::string(1, get_()));
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
			log_("Int8::from_lake_ passed wrong type of thing");
			return;
		}
		set_(lak->get_()[0]);
		if (lak->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Int8");
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
			herd->insert_("strange::Int8");
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
class UInt8 : public Number, public Data<uint8_t>
//----------------------------------------------------------------------
{
public:
	using D = uint8_t;

	static inline const Ptr mut_(const D& data = D())
	{
		return make_<UInt8>(data);
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
		static_<UInt8>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<UInt8>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr river)
	{
		const Ptr ptr = mut_();
		static_<UInt8>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr it)
	{
		return rwl_(it->next_());
	}

	inline UInt8(const D& data)
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
			shoal->update_("to_lake", Const<UInt8>::fin_(&UInt8::to_lake));
			shoal->update_("from_lake", Member<UInt8>::fin_(&UInt8::from_lake, "lake"));
			shoal->update_("to_river", Const<UInt8>::fin_(&UInt8::to_river, "river"));
			shoal->update_("from_river", Member<UInt8>::fin_(&UInt8::from_river, "river"));
			shoal->update_("mut", Static::fin_(&UInt8::mut));
			shoal->update_("fin", Static::fin_(&UInt8::fin));
			shoal->update_("lak", Static::fin_(&UInt8::lak, "lake"));
			shoal->update_("riv", Static::fin_(&UInt8::riv, "river"));
			shoal->update_("rwl", Static::fin_(&UInt8::rwl, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::UInt8::mut", Static::fin_(&UInt8::mut));
		s->update_("strange::UInt8::fin", Static::fin_(&UInt8::fin));
		s->update_("strange::UInt8::lak", Static::fin_(&UInt8::lak, "lake"));
		s->update_("strange::UInt8::riv", Static::fin_(&UInt8::riv, "river"));
		s->update_("strange::UInt8::rwl", Static::fin_(&UInt8::rwl, "river"));
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
			log_("UInt8::from_lake_ passed wrong type of thing");
			return;
		}
		set_(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0])));
		if (lak->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::UInt8");
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
			herd->insert_("strange::UInt8");
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
		return make_<Int16>(data);
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
			shoal->update_("from_lake", Member<Int16>::fin_(&Int16::from_lake, "lake"));
			shoal->update_("to_river", Const<Int16>::fin_(&Int16::to_river, "river"));
			shoal->update_("from_river", Member<Int16>::fin_(&Int16::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Int16::mut));
			shoal->update_("fin", Static::fin_(&Int16::fin));
			shoal->update_("lak", Static::fin_(&Int16::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Int16::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Int16::rwl, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Int16::mut", Static::fin_(&Int16::mut));
		s->update_("strange::Int16::fin", Static::fin_(&Int16::fin));
		s->update_("strange::Int16::lak", Static::fin_(&Int16::lak, "lake"));
		s->update_("strange::Int16::riv", Static::fin_(&Int16::riv, "river"));
		s->update_("strange::Int16::rwl", Static::fin_(&Int16::rwl, "river"));
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
			uint16_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint16_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8
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
		return make_<Int32>(data);
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
			shoal->update_("from_lake", Member<Int32>::fin_(&Int32::from_lake, "lake"));
			shoal->update_("to_river", Const<Int32>::fin_(&Int32::to_river, "river"));
			shoal->update_("from_river", Member<Int32>::fin_(&Int32::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Int32::mut));
			shoal->update_("fin", Static::fin_(&Int32::fin));
			shoal->update_("lak", Static::fin_(&Int32::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Int32::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Int32::rwl, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Int32::mut", Static::fin_(&Int32::mut));
		s->update_("strange::Int32::fin", Static::fin_(&Int32::fin));
		s->update_("strange::Int32::lak", Static::fin_(&Int32::lak, "lake"));
		s->update_("strange::Int32::riv", Static::fin_(&Int32::riv, "river"));
		s->update_("strange::Int32::rwl", Static::fin_(&Int32::rwl, "river"));
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
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[3]))) << 24
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
		return make_<Int64>(data);
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
			shoal->update_("from_lake", Member<Int64>::fin_(&Int64::from_lake, "lake"));
			shoal->update_("to_river", Const<Int64>::fin_(&Int64::to_river, "river"));
			shoal->update_("from_river", Member<Int64>::fin_(&Int64::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Int64::mut));
			shoal->update_("fin", Static::fin_(&Int64::fin));
			shoal->update_("lak", Static::fin_(&Int64::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Int64::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Int64::rwl, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Int64::mut", Static::fin_(&Int64::mut));
		s->update_("strange::Int64::fin", Static::fin_(&Int64::fin));
		s->update_("strange::Int64::lak", Static::fin_(&Int64::lak, "lake"));
		s->update_("strange::Int64::riv", Static::fin_(&Int64::riv, "river"));
		s->update_("strange::Int64::rwl", Static::fin_(&Int64::rwl, "river"));
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
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[2]))) << 16 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[3]))) << 24 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[4]))) << 32 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[5]))) << 40 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[6]))) << 48 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[7]))) << 56
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
		return make_<Float32>(data);
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
			shoal->update_("from_lake", Member<Float32>::fin_(&Float32::from_lake, "lake"));
			shoal->update_("to_river", Const<Float32>::fin_(&Float32::to_river, "river"));
			shoal->update_("from_river", Member<Float32>::fin_(&Float32::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Float32::mut));
			shoal->update_("fin", Static::fin_(&Float32::fin));
			shoal->update_("lak", Static::fin_(&Float32::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Float32::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Float32::rwl, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Float32::mut", Static::fin_(&Float32::mut));
		s->update_("strange::Float32::fin", Static::fin_(&Float32::fin));
		s->update_("strange::Float32::lak", Static::fin_(&Float32::lak, "lake"));
		s->update_("strange::Float32::riv", Static::fin_(&Float32::riv, "river"));
		s->update_("strange::Float32::rwl", Static::fin_(&Float32::rwl, "river"));
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
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[3]))) << 24;
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
		return make_<Float64>(data);
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
			shoal->update_("from_lake", Member<Float64>::fin_(&Float64::from_lake, "lake"));
			shoal->update_("to_river", Const<Float64>::fin_(&Float64::to_river, "river"));
			shoal->update_("from_river", Member<Float64>::fin_(&Float64::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Float64::mut));
			shoal->update_("fin", Static::fin_(&Float64::fin));
			shoal->update_("lak", Static::fin_(&Float64::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Float64::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Float64::rwl, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Float64::mut", Static::fin_(&Float64::mut));
		s->update_("strange::Float64::fin", Static::fin_(&Float64::fin));
		s->update_("strange::Float64::lak", Static::fin_(&Float64::lak, "lake"));
		s->update_("strange::Float64::riv", Static::fin_(&Float64::riv, "river"));
		s->update_("strange::Float64::rwl", Static::fin_(&Float64::rwl, "river"));
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
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[2]))) << 16 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[3]))) << 24 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[4]))) << 32 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[5]))) << 40 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[6]))) << 48 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[7]))) << 56;
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
		return make_<Complex32>(data);
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
			shoal->update_("from_lake", Member<Complex32>::fin_(&Complex32::from_lake, "lake"));
			shoal->update_("to_river", Const<Complex32>::fin_(&Complex32::to_river, "river"));
			shoal->update_("from_river", Member<Complex32>::fin_(&Complex32::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Complex32::mut));
			shoal->update_("fin", Static::fin_(&Complex32::fin));
			shoal->update_("lak", Static::fin_(&Complex32::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Complex32::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Complex32::rwl, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Complex32::mut", Static::fin_(&Complex32::mut));
		s->update_("strange::Complex32::fin", Static::fin_(&Complex32::fin));
		s->update_("strange::Complex32::lak", Static::fin_(&Complex32::lak, "lake"));
		s->update_("strange::Complex32::riv", Static::fin_(&Complex32::riv, "river"));
		s->update_("strange::Complex32::rwl", Static::fin_(&Complex32::rwl, "river"));
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
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[3]))) << 24;
		const uint32_t i =
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[4]))) |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[5]))) << 8 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[6]))) << 16 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[7]))) << 24;
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
		return make_<Complex64>(data);
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
			shoal->update_("from_lake", Member<Complex64>::fin_(&Complex64::from_lake, "lake"));
			shoal->update_("to_river", Const<Complex64>::fin_(&Complex64::to_river, "river"));
			shoal->update_("from_river", Member<Complex64>::fin_(&Complex64::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Complex64::mut));
			shoal->update_("fin", Static::fin_(&Complex64::fin));
			shoal->update_("lak", Static::fin_(&Complex64::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Complex64::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Complex64::rwl, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Complex64::mut", Static::fin_(&Complex64::mut));
		s->update_("strange::Complex64::fin", Static::fin_(&Complex64::fin));
		s->update_("strange::Complex64::lak", Static::fin_(&Complex64::lak, "lake"));
		s->update_("strange::Complex64::riv", Static::fin_(&Complex64::riv, "river"));
		s->update_("strange::Complex64::rwl", Static::fin_(&Complex64::rwl, "river"));
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
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[2]))) << 16 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[3]))) << 24 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[4]))) << 32 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[5]))) << 40 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[6]))) << 48 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[7]))) << 56;
		const uint64_t i =
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[8]))) |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[9]))) << 8 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[10]))) << 16 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[11]))) << 24 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[12]))) << 32 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[13]))) << 40 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[14]))) << 48 |
			uint64_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[15]))) << 56;
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
class River : public Mutable
//----------------------------------------------------------------------
{
	using const_std_unique_iostream = const std::unique_ptr<std::iostream>;

public:
	inline River(std::iostream* const stream)
		: Mutable{}
		, _stream{ stream }
	{
	}

	static inline const Ptr mut_(std::iostream* const stream)
	{
		return make_<River>(stream);
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
		return mut_(lake->get_(), !file->is_nothing_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&River::mut, "lake", "is_file"));
			shoal->update_("push_back", Member<River>::fin_(&River::push_back, "thing"));
			shoal->update_("write", Member<River>::fin_(&River::write, "thing"));
			shoal->update_("pop_front", Member<River>::fin_(&River::pop_front));
			shoal->update_("eof", Const<River>::fin_(&River::eof));
			shoal->update_("get", Member<River>::fin_(&River::get));
			shoal->update_("peek", Member<River>::fin_(&River::peek));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::River::mut", Static::fin_(&River::mut, "lake", "is_file"));
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
		ptr->invoke_("to_river", me_());
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
		ptr->invoke_("to_river_with_links", shoal, me_());
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
		return call_(type + "::riv", me_());
	}

	inline const Ptr pop_front(const Ptr ignore)
	{
		return pop_front_();
	}

	inline const Ptr pop_front_with_links_()
	{
		const int16_t int16 = read_<Int16>();
		const std::string type = static_<Lake>(read_(int16))->get_();
		return call_(type + "::rwl", me_());
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
		return Int8::fin_(get_());
	}

	inline const int peek_()
	{
		return _stream->peek();
	}

	inline const Ptr peek(const Ptr ignore)
	{
		return Int8::fin_(peek_());
	}

private:
	const_std_unique_iostream _stream;
};

//======================================================================
// class Thing
//======================================================================

inline const Thing::Ptr Thing::iterator_() const
{
	return IteratorPtr::mut_(me_());
}

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

inline const Thing::Ptr Thing::call(const Thing::Ptr it)
{
	const Ptr function = it->next_();
	const Ptr fun = static_<Shoal>(shared_())->find_(function);
	if (fun->is_nothing_())
	{
		log_("call passed unknown function:");
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
		shoal->update_("invoke", Member<Thing>::fin_(&Thing::invoke, "member", ".."));
		shoal->update_("iterator", Const<Thing>::fin_(&Thing::iterator));
		shoal->update_("next", Member<Thing>::fin_(&Thing::next));
		shoal->update_("is", Const<Thing>::fin_(&Thing::is, "symbol"));
		shoal->update_("is_not", Const<Thing>::fin_(&Thing::is_not, "symbol"));
		shoal->update_("is_nothing", Const<Thing>::fin_(&Thing::is_nothing));
		shoal->update_("is_not_nothing", Const<Thing>::fin_(&Thing::is_not_nothing));
		shoal->update_("hash", Const<Thing>::fin_(&Thing::hash));
		shoal->update_("same", Const<Thing>::fin_(&Thing::same, "other"));
		shoal->update_("different", Const<Thing>::fin_(&Thing::different, "other"));
		shoal->update_("finalize", Member<Thing>::fin_(&Thing::finalize));
		shoal->update_("finalized", Const<Thing>::fin_(&Thing::finalized));
		shoal->update_("freeze", Member<Thing>::fin_(&Thing::freeze));
		shoal->update_("frozen", Const<Thing>::fin_(&Thing::frozen));
		shoal->update_("copy", Const<Thing>::fin_(&Thing::copy));
		shoal->update_("clone", Const<Thing>::fin_(&Thing::clone));
		shoal->update_("replicate", Const<Thing>::fin_(&Thing::replicate));
		shoal->update_("call", Static::fin_(&Thing::call, "function", ".."));
		shoal->update_("boolean", Static::fin_(&Thing::boolean, "thing"));
		shoal->update_("nothing", Static::fin_(&Thing::nothing));
		shoal->update_("one", Static::fin_(&Thing::one));
		shoal->update_("stop", Static::fin_(&Thing::stop));
		shoal->update_("log", Static::fin_(&Thing::log, "message"));
		shoal->update_("type", Const<Thing>::fin_(&Thing::type));
		shoal->update_("cats", Const<Thing>::fin_(&Thing::cats));
		shoal->update_("visit", Member<Thing>::fin_(&Thing::visit, "visitor", "member", ".."));
		shoal->update_("pub", Const<Thing>::fin_(&Thing::pub));
		shoal->finalize_();
		return pub;
	}();
	return PUB;
}

inline const Thing::Ptr Thing::operator()(Thing* const thing, const Thing::Ptr it)
{
	const Ptr member = static_<Shoal>(thing->pub_())->find_(it->next_());
	if (member->is_nothing_())
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
	return call(IteratorCopy<std::vector<Ptr>>::mut_(std::move(v)));
}

template <typename... Args>
inline const Thing::Ptr Thing::invoke_(Args&&... args)
{
	std::vector<Thing::Ptr> v;
	v.reserve(sizeof...(Args));
	Variadic::variadic_(v, std::forward<Args>(args)...);
	return invoke(IteratorCopy<std::vector<Ptr>>::mut_(std::move(v)));
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

inline const Thing::Ptr Thing::shared_()
{
	static const Ptr SHARED = []()
	{
		const Ptr shoal = Shoal::mut_();
		share_(shoal);
		return shoal;
	}();
	return SHARED;
}

//======================================================================
// class Variadic
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
	Lake* const lake = Thing::dynamic_<Lake>(to_lake_());
	if (lake)
	{
		lake->to_river_(river);
	}
}

inline void Serializable::from_river_(const Thing::Ptr river)
{
	const Thing::Ptr lake = Lake::mut_();
	Thing::static_<Lake>(lake)->from_river_(river);
	from_lake_(lake);
}

inline const Thing::Ptr Serializable::to_lake_via_river_() const
{
	const Thing::Ptr river = River::mut_();
	to_river_(river);
	const Thing::Ptr lake = Lake::mut_();
	Thing::static_<Lake>(lake)->from_river_(river);
	return lake;
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
	from_river_(river);
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
		shoal->update_("to_river", Const<Symbol>::fin_(&Symbol::to_river, "river"));
		shoal->update_("lak", Static::fin_(&Symbol::lak, "lake"));
		shoal->update_("riv", Static::fin_(&Symbol::riv, "river"));
		shoal->update_("rwl", Static::fin_(&Symbol::rwl, "river"));
		shoal->finalize_();
		return pub;
	}();
	return PUB;
}

inline void Symbol::share_(const Thing::Ptr shoal)
{
	Shoal* const s = static_<Shoal>(shoal);
	s->update_("strange::Symbol::lak", Static::fin_(&Symbol::lak, "lake"));
	s->update_("strange::Symbol::riv", Static::fin_(&Symbol::riv, "river"));
	s->update_("strange::Symbol::rwl", Static::fin_(&Symbol::rwl, "river"));
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

inline const Thing::Ptr Static::eater_() const
{
	return IteratorRef<std::vector<Ptr>>::mut_(_params);
}

//======================================================================
// class Member
//======================================================================

template <typename T>
inline const Thing::Ptr Member<T>::eater_() const
{
	return IteratorRef<std::vector<Ptr>>::mut_(_params);
}

//======================================================================
// class Const
//======================================================================

template <typename T>
inline const Thing::Ptr Const<T>::eater_() const
{
	return IteratorRef<std::vector<Ptr>>::mut_(_params);
}

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
		if (riv->push_back_with_links_(i.first, me_()))
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
		i.second->invoke_("replace_links", me_());
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
		herd->insert_("strange::Shoal");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Shoal::Iterator::cats_() const
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

inline const Thing::Ptr Shoal::Iterator::next_()
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

inline const Thing::Ptr Shoal::Feeder::cats_() const
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
		herd->insert_("strange::Flock");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Flock::Iterator::cats_() const
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
// class IteratorPtr
//======================================================================

//======================================================================
// class IteratorCopy
//======================================================================

//======================================================================
// class IteratorRef
//======================================================================

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
// class Int8
//======================================================================

//======================================================================
// class UInt8
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

} // namespace strange

#endif