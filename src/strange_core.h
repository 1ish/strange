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
class Cat;
class Static;
template <typename T> class Member;
template <typename T> class Const;
class Stateful;
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
class UInt16;
class Int32;
class UInt32;
class Int64;
class UInt64;
class Float32;
class Float64;
class Complex32;
class Complex64;
class River;

class Attribute;

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
	static inline const std::shared_ptr<T> static_(const Ptr& ptr)
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!std::dynamic_pointer_cast<T>(ptr))
		{
			throw Disagreement("bad static cast");
		}
#endif
		return std::static_pointer_cast<T>(ptr);
	}

	template <typename T>
	static inline const std::shared_ptr<T> dynamic_(const Ptr& ptr)
	{
		const auto t = std::dynamic_pointer_cast<T>(ptr);
		if (!t)
		{
			const auto attribute = std::dynamic_pointer_cast<Attribute>(ptr);
			if (attribute)
			{
				return std::dynamic_pointer_cast<T>(attribute->get_());
			}
		}
		return t;
	}

	template <>
	static inline const std::shared_ptr<Attribute> dynamic_<Attribute>(const Ptr& ptr)
	{
		return std::dynamic_pointer_cast<Attribute>(ptr);
	}

	static inline const Ptr& boolean_(const bool value)
	{
		return value ? one_() : nothing_();
	}

	template <typename... Args>
	static inline const Ptr call_(Args&&... args);

	static inline const Ptr call(const Ptr& it);

	// public static factory functions
	static inline void share_(const Ptr& shoal);

	static inline const Ptr& shared_();

	template <typename F>
	static inline const Ptr sym_(F&& symbol);

	// public static symbols
	static inline const Ptr& nothing_()
	{
		static const Ptr NOTHING = sym_("");
		return NOTHING;
	}

	static inline const Ptr& one_()
	{
		static const Ptr ONE = sym_("1");
		return ONE;
	}

	static inline const Ptr& stop_()
	{
		static const Ptr STOP = sym_(".");
		return STOP;
	}

	// public construction/destruction/assignment
	Thing(const Thing&) = delete;

	Thing& operator=(const Thing& thing) = delete;

	virtual ~Thing() = default;

	// public pure virtual member functions and adapters
	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Thing");
		return TYPE_NAME;
	}

	virtual inline const Ptr type_() const = 0;

	inline const Ptr type(const Ptr& ignore) const
	{
		return type_();
	}

	static inline const Ptr category_();

	virtual inline const Ptr cat_() const = 0;

	inline const Ptr cat(const Ptr& ignore) const
	{
		return cat_();
	}

	static inline const Ptr categories_();

	virtual inline const Ptr cats_() const = 0;

	inline const Ptr cats(const Ptr& ignore) const
	{
		return cats_();
	}

	// public impure virtual member functions and adapters
	virtual inline void finalize_() const
	{
	}

	inline const Ptr finalize(const Ptr& ignore) const
	{
		finalize_();
		return me_();
	}

	virtual inline const bool final_() const
	{
		return true;
	}

	inline const Ptr final(const Ptr& ignore) const
	{
		return boolean_(final_());
	}

	virtual inline void freeze_() const
	{
		finalize_();
	}

	inline const Ptr freeze(const Ptr& ignore) const
	{
		freeze_();
		return me_();
	}

	virtual inline const bool frozen_() const
	{
		return final_();
	}

	inline const Ptr frozen(const Ptr& ignore) const
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

	inline const Ptr copy(const Ptr& ignore) const
	{
		return copy_();
	}

	virtual inline const Ptr clone_() const
	{
		return copy_();
	}

	inline const Ptr clone(const Ptr& ignore) const
	{
		return clone_();
	}

	inline const Ptr copy_finalize_() const
	{
		if (final_())
		{
			return me_();
		}
		const Ptr result = copy_();
		result->finalize_();
		return result;
	}

	inline const Ptr copy_finalize(const Ptr& ignore) const
	{
		return copy_finalize_();
	}

	inline const Ptr clone_freeze_() const
	{
		if (frozen_())
		{
			return me_();
		}
		const Ptr result = clone_();
		result->freeze_();
		return result;
	}

	inline const Ptr clone_freeze(const Ptr& ignore) const
	{
		return clone_freeze_();
	}

	virtual inline const Ptr replicate_() const
	{
		if (final_())
		{
			return me_();
		}
		return copy_();
	}

	inline const Ptr replicate(const Ptr& ignore) const
	{
		return replicate_();
	}

	virtual inline const Ptr iterator_() const;

	inline const Ptr iterator(const Ptr& ignore) const
	{
		return iterator_();
	}

	virtual inline const Ptr next_()
	{
		return stop_();
	}

	inline const Ptr next(const Ptr& ignore)
	{
		return next_();
	}

	virtual inline std::size_t hash_() const
	{
		return std::hash<const Thing*>{}(this);
	}

	inline const Ptr hash(const Ptr& ignore) const;

	virtual inline const bool same_(const Ptr& other) const
	{
		return identical_(other);
	}

	inline const Ptr same(const Ptr& it) const
	{
		return boolean_(same_(it->next_()));
	}

	inline const Ptr different(const Ptr& it) const
	{
		return boolean_(!same_(it->next_()));
	}

	virtual inline const Ptr visit(const Ptr& it)
	{
		const Ptr visitor = it->next_();
		return visitor->invoke(it);
	}

	virtual inline const Ptr pub_() const
	{
		static const Ptr PUB = _public_(Thing::creator_());
		return PUB;
	}

	inline const Ptr pub(const Ptr& ignore) const
	{
		return pub_();
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_());

	virtual inline const Ptr eater_() const
	{
		return nothing_();
	}

	virtual inline const Ptr feeder(const Ptr& eater) const
	{
		return nothing_();
	}

	// public non-virtual member functions and adapters
	template <typename... Args>
	inline const Ptr invoke_(Args&&... args);

	inline const Ptr invoke(const Ptr& it)
	{
		return operator()(this, it);
	}

	inline const int64_t identity_() const
	{
		return int64_t(this);
	}

	inline const Ptr identity(const Ptr& ignore) const;

	inline const bool identical_(const Ptr& other) const
	{
		return identity_() == other->identity_();
	}

	inline const Ptr identical(const Ptr& it) const
	{
		return boolean_(identical_(it->next_()));
	}

	inline const bool is_(const std::string& symbol) const;

	inline const bool is_(const Ptr& symbol) const;

	inline const Ptr is(const Ptr& it) const
	{
		return boolean_(is_(it->next_()));
	}

	inline const Ptr is_not(const Ptr& it) const
	{
		return boolean_(!is_(it->next_()));
	}

	inline const bool is_nothing_() const
	{
		return is_("");
	}

	inline const Ptr is_nothing(const Ptr& ignore) const
	{
		return boolean_(is_nothing_());
	}

	inline const Ptr is_not_nothing(const Ptr& ignore) const
	{
		return boolean_(!is_nothing_());
	}

	inline const bool is_stop_() const
	{
		return is_(".");
	}

	inline const Ptr is_stop(const Ptr& ignore) const
	{
		return boolean_(is_stop_());
	}

	inline const Ptr is_not_stop(const Ptr& ignore) const
	{
		return boolean_(!is_stop_());
	}

	inline const Ptr and_op(const Ptr& it) const
	{
		if (is_nothing_())
		{
			return nothing_();
		}
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			if (i->is_nothing_())
			{
				return nothing_();
			}
		}
		return one_();
	}
	
	inline const Ptr or_op(const Ptr& it) const
	{
		if (!is_nothing_())
		{
			return one_();
		}
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			if (!i->is_nothing_())
			{
				return one_();
			}
		}
		return nothing_();
	}

	inline const Ptr xor_op(const Ptr& it) const
	{
		int64_t count = is_nothing_() ? 0 : 1;
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			if (!i->is_nothing_())
			{
				++count;
			}
		}
		return boolean_(count == 1);
	}

	inline const Ptr nand_op(const Ptr& it) const
	{
		if (is_nothing_())
		{
			return one_();
		}
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			if (i->is_nothing_())
			{
				return one_();
			}
		}
		return nothing_();
	}

	inline const Ptr nor_op(const Ptr& it) const
	{
		if (!is_nothing_())
		{
			return nothing_();
		}
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			if (!i->is_nothing_())
			{
				return nothing_();
			}
		}
		return one_();
	}

	inline const Ptr xnor_op(const Ptr& it) const
	{
		int64_t count = is_nothing_() ? 0 : 1;
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			if (!i->is_nothing_())
			{
				++count;
			}
		}
		return boolean_(count != 1);
	}

	inline void give_() const
	{
		std::atomic_thread_fence(std::memory_order_release);
	}

	inline void take_() const
	{
		std::atomic_thread_fence(std::memory_order_acquire);
	}

	// public nested classes
	class Disagreement : public std::logic_error
	{
	public:
		inline Disagreement(const std::string& description)
			: std::logic_error(description)
		{
		}
	};

	class Dismemberment : public Disagreement
	{
	public:
		inline Dismemberment(const Ptr& type, const Ptr& member);
	};

	class Mutilation : public Disagreement
	{
	public:
		inline Mutilation(const Ptr& cat);
	};

protected:
	// protected static utility functions
	static inline const Ptr operate_(Thing* const thing, const Ptr& member, const Ptr& it)
	{
		return member->operator()(thing, it);
	}

	static inline const Ptr operate_(Thing* const thing, const Ptr& member)
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

	static inline const Ptr _public_(const Ptr& creation);

	// protected construction/destruction/assignment
	Thing() = default;

	// protected impure virtual member functions and adapters
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it);

private:
	WeakPtr _me;
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
		for (Ptr p = thing.next_(); !p->is_stop_(); p = thing.next_())
		{
			vec.push_back(p);
		}
		variadic_(vec, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_(std::vector<Ptr>& vec, const Ptr& ptr, Args&&... args)
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

	inline const Thing::Ptr to_lake(const Thing::Ptr& ignore) const
	{
		return to_lake_();
	}

	// public impure virtual member functions and adapters
	virtual inline void from_lake_(const Thing::Ptr& lake)
	{
	}

	inline const Thing::Ptr from_lake(const Thing::Ptr& it)
	{
		from_lake_(it->next_());
		return Thing::nothing_();
	}

	virtual inline void to_river_(const Thing::Ptr& river) const;

	inline const Thing::Ptr to_river(const Thing::Ptr& it) const
	{
		const Thing::Ptr river = it->next_();
		to_river_(river);
		return river;
	}

	virtual inline void from_river_(const Thing::Ptr& river);

	inline const Thing::Ptr from_river(const Thing::Ptr& it)
	{
		const Thing::Ptr river = it->next_();
		from_river_(river);
		return river;
	}

	virtual inline void to_river_with_links_(const Thing::Ptr& shoal, const Thing::Ptr& river) const
	{
		to_river_(river);
	}

	inline const Thing::Ptr to_river_with_links(const Thing::Ptr& it)
	{
		const Thing::Ptr shoal = it->next_();
		const Thing::Ptr river = it->next_();
		to_river_with_links_(shoal, river);
		return river;
	}

	virtual inline void from_river_with_links_(const Thing::Ptr& river)
	{
		from_river_(river);
	}

	inline const Thing::Ptr from_river_with_links(const Thing::Ptr& it)
	{
		const Thing::Ptr river = it->next_();
		from_river_with_links_(river);
		return river;
	}

	static inline void serialize_(const Thing::Ptr& thing, const Thing::Ptr& river);

	static inline const Thing::Ptr serialize(const Thing::Ptr& it)
	{
		const Thing::Ptr thing = it->next_();
		const Thing::Ptr river = it->next_();
		serialize_(thing, river);
		return river;
	}

	virtual inline void replace_links_(const Thing::Ptr& shoal)
	{
	}

	inline const Thing::Ptr replace_links(const Thing::Ptr& it)
	{
		replace_links_(it->next_());
		return Thing::nothing_();
	}

	static inline const Thing::Ptr deserialize_(const Thing::Ptr& river);

	static inline const Thing::Ptr deserialize(const Thing::Ptr& it)
	{
		return deserialize_(it->next_());
	}

	// public non-virtual member functions and adapters
	inline const Thing::Ptr to_lake_via_river_() const;

	inline const Thing::Ptr to_lake_via_river(const Thing::Ptr& ignore) const
	{
		return to_lake_via_river_();
	}

	inline void from_lake_via_river_(const Thing::Ptr& lake);

	inline const Thing::Ptr from_lake_via_river(const Thing::Ptr& it)
	{
		from_lake_via_river_(it->next_());
		return Thing::nothing_();
	}

	static inline const Thing::Ptr type_name_()
	{
		static const Thing::Ptr TYPE_NAME = Thing::sym_("strange::Serializable");
		return TYPE_NAME;
	}

	static inline const Thing::Ptr category_();

	static inline const Thing::Ptr categories_();
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

	template <typename F>
	inline Symbol(F&& symbol, const std::size_t hash)
		: Thing{}
		, Serializable{}
		, _symbol{ std::forward<F>(symbol) }
		, _hash{ hash }
	{
	}

	virtual inline std::size_t hash_() const override
	{
		return _hash;
	}

	virtual inline const bool same_(const Ptr& other) const override;

	inline const std::string& get_() const
	{
		return _symbol;
	}

	template <typename F>
	static inline const Ptr fin_(F&& symbol)
	{
		return fake_<Symbol>(std::forward<F>(symbol));
	}

	static inline const Ptr lak_(const Ptr& lake);

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river);

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river);

	static inline const Ptr rwl(const Ptr& it)
	{
		return rwl_(it->next_());
	}

	static inline void share_(const Ptr& shoal);

	virtual inline const Ptr to_lake_() const override;

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Symbol");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Symbol::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Symbol::type_name_();
	}

	static inline const Ptr category_();

	static inline const Ptr category(const Ptr& ignore)
	{
		return Symbol::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Symbol::category_();
	}

	static inline const Ptr categories_();

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Symbol::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Symbol::categories_();
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = _public_(Symbol::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_());

	inline const Ptr add_(const std::string& s) const
	{
		return fin_(_symbol + s);
	}

	inline const Ptr add_(const Ptr& other) const;

	inline const Ptr add(const Ptr& it) const
	{
		return add_(it->next_());
	}

	inline const char at_(const int64_t index) const
	{
		if (std::size_t(index) < _symbol.length())
		{
			return _symbol[index];
		}
		return 0;
	}

	inline const char at_(const Ptr& index) const;

	inline const Ptr at(const Ptr& it) const;

	inline const bool less_than_(const Ptr& other) const;

	inline const Ptr less_than(const Ptr& it) const
	{
		return boolean_(less_than_(it->next_()));
	}

	inline const bool greater_than_(const Ptr& other) const;

	inline const Ptr greater_than(const Ptr& it) const
	{
		return boolean_(greater_than_(it->next_()));
	}

	inline const bool less_or_equal_(const Ptr& other) const;

	inline const Ptr less_or_equal(const Ptr& it) const
	{
		return boolean_(less_or_equal_(it->next_()));
	}

	inline const bool greater_or_equal_(const Ptr& other) const;

	inline const Ptr greater_or_equal(const Ptr& it) const
	{
		return boolean_(greater_or_equal_(it->next_()));
	}

protected:
	const std::string _symbol;
	const std::size_t _hash;
};

//----------------------------------------------------------------------
class Cat : public Symbol
//----------------------------------------------------------------------
{
public:
	inline Cat(const Ptr& type_name_symbol, const Ptr& arguments, const Ptr& parameters, const Ptr& return_cat = Ptr())
		: Symbol{ _symbol_(type_name_symbol, arguments, parameters, return_cat), _hash_(type_name_symbol, arguments, parameters, return_cat) }
		, _symbolic{ _symbolic_(arguments, parameters, return_cat) }
		, _type_name_symbol{ type_name_symbol }
		, _arguments{ arguments }
		, _parameters{ parameters }
		, _return_cat{ return_cat }
	{
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto other_cat = dynamic_<Cat>(other);
		if (!other_cat || _symbolic != other_cat->_symbolic || _hash != other_cat->_hash)
		{
			return false;
		}
		if (_symbolic)
		{
			return Symbol::same_(other);
		}
		if (!_type_name_symbol->is_(other_cat->_type_name_symbol))
		{
			return false;
		}
		if (_return_cat && other_cat->_return_cat)
		{
			if (!_return_cat->same_(other_cat->_return_cat))
			{
				return false;
			}
		}
		else if (_return_cat || other_cat->_return_cat)
		{
			return false;
		}
		{
			const Ptr args = _arguments->iterator_();
			const Ptr other_args = other_cat->_arguments->iterator_();
			Ptr other_arg = other_args->next_();
			for (Ptr arg = args->next_(); !arg->is_stop_(); arg = args->next_())
			{
				if (other_arg->is_stop_() || !arg->same_(other_arg))
				{
					return false;
				}
				other_arg = other_args->next_();
			}
			if (!other_arg->is_stop_())
			{
				return false;
			}
		}
		{
			const Ptr params = _parameters->iterator_();
			const Ptr other_params = other_cat->_parameters->iterator_();
			Ptr other_param = other_params->next_();
			for (Ptr param = params->next_(); !param->is_stop_(); param = params->next_())
			{
				if (other_param->is_stop_() || !param->same_(other_param))
				{
					return false;
				}
				other_param = other_params->next_();
			}
			if (!other_param->is_stop_())
			{
				return false;
			}
		}
		return true;
	}

	static inline const Ptr fin_()
	{
		static const Ptr ANY = fin_(nothing_());
		return ANY;
	}

	static inline const Ptr fin_(const Ptr& type_name_symbol);

	static inline const Ptr fin_(const Ptr& type_name_symbol, const Ptr& arguments);

	static inline const Ptr fin_(const Ptr& type_name_symbol, const Ptr& arguments, const Ptr& parameters)
	{
		return fake_<Cat>(type_name_symbol, arguments, parameters);
	}

	static inline const Ptr fin_(const Ptr& type_name_symbol, const Ptr& arguments, const Ptr& parameters, const Ptr& return_cat)
	{
		if (return_cat->is_("<>"))
		{
			return fake_<Cat>(type_name_symbol, arguments, parameters);
		}
		return fake_<Cat>(type_name_symbol, arguments, parameters, return_cat);
	}

	static inline void share_(const Ptr& shoal);

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Cat");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Cat::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Cat::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Cat::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Cat::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Cat::category_();
	}

	static inline const Ptr categories_();

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Cat::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Cat::categories_();
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = _public_(Cat::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_());

	static inline const bool check_(const Ptr& thing, const Ptr& cat);

	inline const Ptr type_name_symbol_() const
	{
		return _type_name_symbol;
	}

	inline const Ptr arguments_() const
	{
		return _arguments;
	}

	inline const Ptr parameters_() const
	{
		return _parameters;
	}

	inline const Ptr return_cat_() const
	{
		return _return_cat ? _return_cat : fin_();
	}

private:
	const bool _symbolic; // recursively true if all of the cats below are symbolic and there are no non-cat arguments
	const Ptr _type_name_symbol; // type name Symbol
	const Ptr _arguments; // Flock of creator arguments - mix of cats and non-cats
	const Ptr _parameters; // Flock of function parameter cats
	const Ptr _return_cat; // function return cat

	static inline const bool _symbolic_(const Ptr& arguments, const Ptr& parameters, const Ptr& return_cat)
	{
		if (return_cat && !static_<Cat>(return_cat)->_symbolic)
		{
			return false;
		}
		{
			const Ptr args = arguments->iterator_();
			for (Ptr arg = args->next_(); !arg->is_stop_(); arg = args->next_())
			{
				const auto cat = dynamic_<Cat>(arg);
				if (!cat || !cat->_symbolic)
				{
					return false;
				}
			}
		}
		{
			const Ptr params = parameters->iterator_();
			for (Ptr param = params->next_(); !param->is_stop_(); param = params->next_())
			{
				if (!static_<Cat>(param)->_symbolic)
				{
					return false;
				}
			}
		}
		return true;
	}

	static inline const std::string _symbol_(const Ptr& type_name_symbol, const Ptr& arguments, const Ptr& parameters, const Ptr& return_cat, const bool hash = false)
	{
		std::string result = "<" + static_<Symbol>(type_name_symbol)->get_();
		{
			bool any_args = false;
			const Ptr args = arguments->iterator_();
			int64_t anys = 0;
			for (Ptr arg = args->next_(); !arg->is_stop_(); arg = args->next_())
			{
				const auto cat = dynamic_<Cat>(arg);
				if (cat && cat->_symbol == "<>")
				{
					++anys;
					continue;
				}
				if (any_args)
				{
					result += ",";
				}
				else
				{
					result += "[";
					any_args = true;
				}
				while (anys)
				{
					result += "<>,";
					--anys;
				}
				if (cat)
				{
					result += cat->_symbol;
				}
				else if (hash)
				{
					result += _hash_arg_(arg);
				}
				else
				{
					result += "*";
				}
			}
			if (any_args)
			{
				result += "]";
			}
		}
		{
			bool any_params = false;
			const Ptr params = parameters->iterator_();
			int64_t anys = 0;
			for (Ptr param = params->next_(); !param->is_stop_(); param = params->next_())
			{
				const std::string& param_cat = static_<Cat>(param)->_symbol;
				if (param_cat == "<>")
				{
					++anys;
					continue;
				}
				if (any_params)
				{
					result += ",";
				}
				else
				{
					result += "(";
					any_params = true;
				}
				while (anys)
				{
					result += "<>,";
					--anys;
				}
				result += param_cat;
			}
			if (any_params)
			{
				result += ")";
			}
		}
		if (return_cat)
		{
			const std::string& symbol = static_<Cat>(return_cat)->_symbol;
			if (symbol != "<>")
			{
				result += symbol;
			}
		}
		return result + ">";
	}

	static inline const std::string _hash_arg_(const Ptr& arg);

	static inline const std::size_t _hash_(const Ptr& type_name_symbol, const Ptr& arguments, const Ptr& parameters, const Ptr& return_cat)
	{
		return std::hash<std::string>()(_symbol_(type_name_symbol, arguments, parameters, return_cat, true));
	}
};

//----------------------------------------------------------------------
class Static : public Thing
//----------------------------------------------------------------------
{
	using function = const Ptr(*)(const Ptr&);

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

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Static");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Static::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Static::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Static::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Static::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Static::category_();
	}

	static inline const Ptr categories_();

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Static::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Static::categories_();
	}

	virtual inline const Ptr eater_() const override;

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		return _function(it);
	}

private:
	const function _function;
	const std::vector<Ptr> _params;
};

template <typename T>
//----------------------------------------------------------------------
class Member : public Thing
//----------------------------------------------------------------------
{
	using member = const Ptr(T::*)(const Ptr&);

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

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Member");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Member::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Member::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Member::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Member::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Member::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Thing::categories_()->copy_());
			categories->insert_(Member::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Member::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Member::categories_();
	}

	virtual inline const Ptr eater_() const override;

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		if (thing->final_())
		{
			throw Mutilation(thing->cat_());
		}
		T* const t = dynamic_cast<T*>(thing);
		if (t)
		{
			return (t->*_function)(it);
		}
		throw Disagreement("Member passed wrong category of thing");
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
	using member = const Ptr(T::*)(const Ptr&) const;

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

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Const");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Const::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Const::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Const::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Const::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Const::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Thing::categories_()->copy_());
			categories->insert_(Const::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Const::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Const::categories_();
	}

	virtual inline const Ptr eater_() const override;

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		T* const t = dynamic_cast<T*>(thing);
		if (t)
		{
			return (t->*_function)(it);
		}
		throw Disagreement("Const member passed wrong category of thing");
	}

private:
	const member _function;
	std::vector<Ptr> _params;
};

//----------------------------------------------------------------------
class Stateful : public Thing
//----------------------------------------------------------------------
{
public:
	virtual inline void finalize_() const override
	{
		_final = true;
	}

	virtual inline const bool final_() const override
	{
		return _final;
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Stateful");
		return TYPE_NAME;
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Stateful::type_name_());
		return CATEGORY;
	}

	static inline const Ptr categories_();

protected:
	inline Stateful()
		: Thing{}
		, _final{ false }
	{
	}

private:
	mutable bool _final;
};

//----------------------------------------------------------------------
class Shoal : public Stateful, public Serializable
//----------------------------------------------------------------------
{
	class Hash
	{
	public:
		inline std::size_t operator()(const Ptr& ptr) const
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
	inline Shoal()
		: Stateful{}
		, Serializable{}
		, _map{}
		, _frozen{ false }
	{
	}

	inline Shoal(const Ptr& it)
		: Stateful{}
		, Serializable{}
		, _map{}
		, _frozen{ false }
	{
		Ptr key;
		int64_t index = 0;
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			if (index % 2 == 0)
			{
				key = i;
			}
			else
			{
				update_(key, i);
			}
			++index;
		}
	}

	virtual inline void freeze_() const override
	{
		if (!_frozen)
		{
			for (const auto& i : _map)
			{
				i.first->freeze_();
				i.second->freeze_();
			}
			finalize_();
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
		if (final_())
		{
			result->finalize_();
		}
		return result;
	}

	virtual inline const Ptr to_lake_() const override
	{
		return to_lake_via_river_();
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		from_lake_via_river_(lake);
	}

	virtual inline void to_river_(const Ptr& river) const override;

	virtual inline void from_river_(const Ptr& river) override;

	virtual inline void to_river_with_links_(const Ptr& shoal, const Ptr& river) const override;

	virtual inline void from_river_with_links_(const Ptr& river) override;

	virtual inline void replace_links_(const Ptr& shoal) override;

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = _public_(Shoal::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Stateful::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Shoal::type_name));
			shoal->update_("category", Static::fin_(&Shoal::category));
			shoal->update_("categories", Static::fin_(&Shoal::categories));
			shoal->update_("to_lake", Const<Shoal>::fin_(&Shoal::to_lake));
			shoal->update_("from_lake", Member<Shoal>::fin_(&Shoal::from_lake, "lake"));
			shoal->update_("to_river", Const<Shoal>::fin_(&Shoal::to_river, "river"));
			shoal->update_("from_river", Member<Shoal>::fin_(&Shoal::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Shoal::mut, "key", "value", ".."));
			shoal->update_("fin", Static::fin_(&Shoal::fin, "key", "value", ".."));
			shoal->update_("lak", Static::fin_(&Shoal::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Shoal::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Shoal::rwl, "river"));
			shoal->update_("at", Const<Shoal>::fin_(&Shoal::at, "key"));
			shoal->update_("update", Member<Shoal>::fin_(&Shoal::update, "key", "value"));
			shoal->update_("insert", Member<Shoal>::fin_(&Shoal::insert, "key", "value"));
			shoal->update_("erase", Member<Shoal>::fin_(&Shoal::erase, "key"));
			shoal->update_("clear", Member<Shoal>::fin_(&Shoal::clear));
			shoal->update_("size", Const<Shoal>::fin_(&Shoal::size));
			shoal->update_("empty", Const<Shoal>::fin_(&Shoal::empty));
			shoal->update_("self_add", Member<Shoal>::fin_(&Shoal::self_add, "shoal", ".."));
			shoal->update_("add", Const<Shoal>::fin_(&Shoal::add, "shoal", ".."));
			shoal->update_("self_subtract", Member<Shoal>::fin_(&Shoal::self_subtract, "shoal", ".."));
			shoal->update_("subtract", Const<Shoal>::fin_(&Shoal::subtract, "shoal", ".."));
			shoal->update_("feeder", Const<Shoal>::fin_(&Shoal::feeder, ".."));
			shoal->update_("itemize", Member<Shoal>::fin_(&Shoal::itemize, "key"));
			shoal->update_("gather", Member<Shoal>::fin_(&Shoal::gather, "key"));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Shoal", Static::fin_(&Shoal::creator_));
		s->update_("strange::Shoal::mut", Static::fin_(&Shoal::mut));
		s->update_("strange::Shoal::lak", Static::fin_(&Shoal::lak, "lake"));
		s->update_("strange::Shoal::riv", Static::fin_(&Shoal::riv, "river"));
		s->update_("strange::Shoal::rwl", Static::fin_(&Shoal::rwl, "river"));
	}

	static inline const Ptr mut_()
	{
		return make_<Shoal>();
	}

	static inline const Ptr mut(const Ptr& it)
	{
		return make_<Shoal>(it);
	}

	static inline const Ptr fin(const Ptr& it)
	{
		const Ptr result = mut(it);
		result->finalize_();
		return result;
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Shoal>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Shoal>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Shoal>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
	{
		return rwl_(it->next_());
	}

	inline const Ptr at_(const std::string& key) const
	{
		return at_(sym_(key));
	}

	inline const Ptr at_(const Ptr& key) const
	{
		const std_unordered_map_ptr_ptr::const_iterator mit = _map.find(key);
		if (mit == _map.cend())
		{
			return nothing_();
		}
		return mit->second;
	}

	inline const Ptr at(const Ptr& it) const
	{
		return at_(it->next_());
	}

	inline void update_(const std::string& key, const Ptr& value)
	{
		update_(sym_(key), value);
	}

	inline void update_(const Ptr& key, const Ptr& value)
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

	inline const Ptr update(const Ptr& it)
	{
		const Ptr key = it->next_();
		const Ptr value = it->next_();
		update_(key, value);
		return value;
	}

	inline const bool insert_(const std::string& key, const Ptr& value)
	{
		return insert_(sym_(key), value);
	}

	inline const bool insert_(const Ptr& key, const Ptr& value)
	{
		if (value->is_nothing_())
		{
			return false;
		}
		return _map.emplace(key, value).second;
	}

	inline const Ptr insert(const Ptr& it)
	{
		const Ptr key = it->next_();
		const Ptr value = it->next_();
		return boolean_(insert_(key, value));
	}

	inline const bool erase_(const std::string& key)
	{
		return erase_(sym_(key));
	}

	inline const bool erase_(const Ptr& key)
	{
		return _map.erase(key);
	}

	inline const Ptr erase(const Ptr& it)
	{
		return boolean_(erase_(it->next_()));
	}

	inline void clear_()
	{
		_map.clear();
	}

	inline const Ptr clear(const Ptr& ignore)
	{
		clear_();
		return me_();
	}

	inline const int64_t size_() const
	{
		return int64_t(_map.size());
	}

	inline const Ptr size(const Ptr& ignore) const;

	inline const bool empty_() const
	{
		return _map.empty();
	}

	inline const Ptr empty(const Ptr& ignore) const
	{
		return boolean_(empty_());
	}

	inline void self_add_(const Ptr& other);

	inline const Ptr self_add(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_add_(i);
		}
		return me_();
	}

	inline const Ptr add_(const Ptr& other) const
	{
		const Ptr result = copy_();
		static_<Shoal>(result)->self_add_(other);
		return result;
	}

	inline const Ptr add(const Ptr& it) const
	{
		const Ptr result = copy_();
		static_<Shoal>(result)->self_add(it);
		return result;
	}

	inline void self_subtract_(const Ptr& other);

	inline const Ptr self_subtract(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_subtract_(i);
		}
		return me_();
	}

	inline const Ptr subtract_(const Ptr& other) const
	{
		const Ptr result = copy_();
		static_<Shoal>(result)->self_subtract_(other);
		return result;
	}

	inline const Ptr subtract(const Ptr& it) const
	{
		const Ptr result = copy_();
		static_<Shoal>(result)->self_subtract(it);
		return result;
	}

	virtual inline const Ptr iterator_() const override
	{
		if (final_())
		{
			return Iterator::mut_(me_());
		}
		return Iterator::mut_(copy_());
	}

	virtual inline const Ptr feeder(const Ptr& eater) const override
	{
		if (eater->is_nothing_())
		{
			return eater;
		}
		return Feeder::mut_(me_(), eater);
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Shoal");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Shoal::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Shoal::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Shoal::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Shoal::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Shoal::category_();
	}

	static inline const Ptr categories_();

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Shoal::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Shoal::categories_();
	}

	virtual inline const Ptr visit(const Ptr& it) override
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

	inline const bool itemize_(const Ptr& key)
	{
		const Ptr size = sym_(std::to_string(_map.size()));
		return insert_(key, size);
	}

	inline const Ptr itemize(const Ptr& it)
	{
		return boolean_(itemize_(it->next_()));
	}

	inline void gather_(const Ptr& item)
	{
		item->invoke_("visit", me_(), "itemize", item);
	}

	inline const Ptr gather(const Ptr& it)
	{
		gather_(it->next_());
		return nothing_();
	}

	inline void gather_to_river_(const Ptr& thing, const Ptr& river);

	inline const Ptr gather_from_river_(const Ptr& river);

	inline const std_unordered_map_ptr_ptr& get_() const
	{
		return _map;
	}

	class Concurrent : public Stateful
	{
	public:
		inline Concurrent(const Ptr& shoal)
			: Stateful{}
			, _shoal{ shoal }
			, _mutex{}
		{
		}

		virtual inline const Ptr pub_() const override
		{
			static const Ptr PUB = _public_(Concurrent::creator_());
			return PUB;
		}

		static inline const Ptr creator_(const Ptr& ignore = nothing_())
		{
			static const Ptr CREATION = []()
			{
				const auto shoal = static_<Shoal>(Stateful::creator_()->copy_());
				shoal->update_("type_name", Static::fin_(&Concurrent::type_name));
				shoal->update_("category", Static::fin_(&Concurrent::category));
				shoal->update_("categories", Static::fin_(&Concurrent::categories));
				shoal->update_("at", Const<Concurrent>::fin_(&Concurrent::at, "key"));
				shoal->update_("update", Member<Concurrent>::fin_(&Concurrent::update, "key", "value"));
				shoal->update_("insert", Member<Concurrent>::fin_(&Concurrent::insert, "key", "value"));
				shoal->update_("mut", Static::fin_(&Concurrent::mut, "shoal"));
				shoal->finalize_();
				return shoal;
			}();
			return CREATION;
		}

		static inline void share_(const Ptr& shoal)
		{
			const auto s = static_<Shoal>(shoal);
			s->update_("strange::Shoal::Concurrent", Static::fin_(&Shoal::Concurrent::creator_));
			s->update_("strange::Shoal::Concurrent::mut", Static::fin_(&Shoal::Concurrent::mut, "shoal"));
		}

		static inline const Ptr mut_(const Ptr& shoal = Shoal::mut_())
		{
			return make_<Concurrent>(shoal);
		}

		static inline const Ptr mut(const Ptr& it)
		{
			return mut_(it->next_());
		}

		virtual inline const Ptr copy_() const override
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return mut_(_shoal->copy_());
		}

		static inline const Ptr type_name_()
		{
			static const Ptr TYPE_NAME = sym_("strange::Shoal::Concurrent");
			return TYPE_NAME;
		}

		static inline const Ptr type_name(const Ptr& ignore)
		{
			return Shoal::Concurrent::type_name_();
		}

		virtual inline const Ptr type_() const override
		{
			return Shoal::Concurrent::type_name_();
		}

		static inline const Ptr category_()
		{
			static const Ptr CATEGORY = Cat::fin_(Shoal::Concurrent::type_name_());
			return CATEGORY;
		}

		static inline const Ptr category(const Ptr& ignore)
		{
			return Shoal::Concurrent::category_();
		}

		virtual inline const Ptr cat_() const override
		{
			return Shoal::Concurrent::category_();
		}

		static inline const Ptr categories_();

		static inline const Ptr categories(const Ptr& ignore)
		{
			return Shoal::Concurrent::categories_();
		}

		virtual inline const Ptr cats_() const override
		{
			return Shoal::Concurrent::categories_();
		}

		inline const Ptr at_(const Ptr& key) const
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return static_<Shoal>(_shoal)->at_(key);
		}

		inline const Ptr at(const Ptr& it) const
		{
			return at_(it->next_());
		}

		inline void update_(const Ptr& key, const Ptr& value)
		{
			const Ptr frozen_key = key->clone_freeze_();
			const Ptr frozen_value = value->clone_freeze_();
			std::unique_lock<std::shared_timed_mutex> lock(_mutex);
			static_<Shoal>(_shoal)->update_(frozen_key, frozen_value);
		}

		inline const Ptr update(const Ptr& it)
		{
			const Ptr key = it->next_();
			const Ptr value = it->next_();
			update_(key, value);
			return value;
		}

		inline const bool insert_(const Ptr& key, const Ptr& value)
		{
			const Ptr frozen_key = key->clone_freeze_();
			const Ptr frozen_value = value->clone_freeze_();
			std::unique_lock<std::shared_timed_mutex> lock(_mutex);
			return static_<Shoal>(_shoal)->insert_(frozen_key, frozen_value);
		}

		inline const Ptr insert(const Ptr& it)
		{
			const Ptr key = it->next_();
			return boolean_(insert_(key, it->next_()));
		}

	private:
		const Ptr _shoal;
		mutable std::shared_timed_mutex _mutex;
	};

private:
	std_unordered_map_ptr_ptr _map;
	mutable bool _frozen;

	class Iterator : public Stateful
	{
	public:
		inline Iterator(const Ptr& shoal)
			: Stateful{}
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

		static inline const Ptr mut_(const Ptr& shoal)
		{
			return make_<Iterator>(shoal);
		}

		static inline const Ptr type_name_()
		{
			static const Ptr TYPE_NAME = sym_("strange::Shoal::Iterator");
			return TYPE_NAME;
		}

		static inline const Ptr type_name(const Ptr& ignore)
		{
			return Shoal::Iterator::type_name_();
		}

		virtual inline const Ptr type_() const override
		{
			return Shoal::Iterator::type_name_();
		}

		static inline const Ptr category_()
		{
			static const Ptr CATEGORY = Cat::fin_(Shoal::Iterator::type_name_());
			return CATEGORY;
		}

		static inline const Ptr category(const Ptr& ignore)
		{
			return Shoal::Iterator::category_();
		}

		virtual inline const Ptr cat_() const override
		{
			return Shoal::Iterator::category_();
		}

		static inline const Ptr categories_();

		static inline const Ptr categories(const Ptr& ignore)
		{
			return Shoal::Iterator::categories_();
		}

		virtual inline const Ptr cats_() const override
		{
			return Shoal::Iterator::categories_();
		}

	private:
		const Ptr _shoal;
		std_unordered_map_ptr_ptr::const_iterator _iterator;
	};

	class Feeder : public Stateful
	{
	public:
		inline Feeder(const Ptr& shoal, const Ptr& eater)
			: Stateful{}
			, _shoal{ shoal }
			, _eater{ eater }
		{
		}

		virtual inline const Ptr next_() override
		{
			const Ptr n = _eater->next_();
			if (n->is_stop_())
			{
				return n;
			}
			return static_<Shoal>(_shoal)->at_(n);
		}

		static inline const Ptr mut_(const Ptr& shoal, const Ptr& eater)
		{
			return make_<Feeder>(shoal, eater);
		}

		static inline const Ptr type_name_()
		{
			static const Ptr TYPE_NAME = sym_("strange::Shoal::Feeder");
			return TYPE_NAME;
		}

		static inline const Ptr type_name(const Ptr& ignore)
		{
			return Shoal::Feeder::type_name_();
		}

		virtual inline const Ptr type_() const override
		{
			return Shoal::Feeder::type_name_();
		}

		static inline const Ptr category_()
		{
			static const Ptr CATEGORY = Cat::fin_(Shoal::Feeder::type_name_());
			return CATEGORY;
		}

		static inline const Ptr category(const Ptr& ignore)
		{
			return Shoal::Feeder::category_();
		}

		virtual inline const Ptr cat_() const override
		{
			return Shoal::Feeder::category_();
		}

		static inline const Ptr categories_();

		static inline const Ptr categories(const Ptr& ignore)
		{
			return Shoal::Feeder::categories_();
		}

		virtual inline const Ptr cats_() const override
		{
			return Shoal::Feeder::categories_();
		}

	private:
		const Ptr _shoal;
		const Ptr _eater;
	};
};

//----------------------------------------------------------------------
class Flock : public Stateful, public Serializable
//----------------------------------------------------------------------
{
	using std_vector_ptr = std::vector<Ptr>;

public:
	inline Flock()
		: Stateful{}
		, Serializable{}
		, _vector{}
		, _frozen{ false }
	{
	}

	inline Flock(const Ptr& it)
		: Stateful{}
		, Serializable{}
		, _vector{}
		, _frozen{ false }
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			push_back_(i);
		}
	}

	virtual inline void freeze_() const override
	{
		if (!_frozen)
		{
			for (const auto i : _vector)
			{
				i->freeze_();
			}
			finalize_();
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
		if (final_())
		{
			result->finalize_();
		}
		return result;
	}

	virtual inline const Ptr to_lake_() const override
	{
		return to_lake_via_river_();
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		from_lake_via_river_(lake);
	}

	virtual inline void to_river_(const Ptr& river) const override;

	virtual inline void from_river_(const Ptr& river) override;

	virtual inline void to_river_with_links_(const Ptr& shoal, const Ptr& river) const override;

	virtual inline void from_river_with_links_(const Ptr& river) override;

	virtual inline void replace_links_(const Ptr& shoal) override;

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = _public_(Flock::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Stateful::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Flock::type_name));
			shoal->update_("category", Static::fin_(&Flock::category));
			shoal->update_("categories", Static::fin_(&Flock::categories));
			shoal->update_("to_lake", Const<Flock>::fin_(&Flock::to_lake));
			shoal->update_("from_lake", Member<Flock>::fin_(&Flock::from_lake, "lake"));
			shoal->update_("to_river", Const<Flock>::fin_(&Flock::to_river, "river"));
			shoal->update_("from_river", Member<Flock>::fin_(&Flock::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Flock::mut, "value", ".."));
			shoal->update_("fin", Static::fin_(&Flock::fin, "value", ".."));
			shoal->update_("lak", Static::fin_(&Flock::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Flock::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Flock::rwl, "river"));
			shoal->update_("push_back", Member<Flock>::fin_(&Flock::push_back, "value"));
			shoal->update_("size", Const<Flock>::fin_(&Flock::size));
			shoal->update_("empty", Const<Flock>::fin_(&Flock::empty));
			shoal->update_("at", Const<Flock>::fin_(&Flock::at, "index"));
			shoal->update_("update", Member<Flock>::fin_(&Flock::update, "index", "value"));
			shoal->update_("insert", Member<Flock>::fin_(&Flock::insert, "index", "value"));
			shoal->update_("erase", Member<Flock>::fin_(&Flock::erase, "index"));
			shoal->update_("clear", Member<Flock>::fin_(&Flock::clear));
			shoal->update_("self_add", Member<Flock>::fin_(&Flock::self_add, "flock", ".."));
			shoal->update_("add", Const<Flock>::fin_(&Flock::add, "flock", ".."));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Flock", Static::fin_(&Flock::creator_));
		s->update_("strange::Flock::mut", Static::fin_(&Flock::mut));
		s->update_("strange::Flock::lak", Static::fin_(&Flock::lak, "lake"));
		s->update_("strange::Flock::riv", Static::fin_(&Flock::riv, "river"));
		s->update_("strange::Flock::rwl", Static::fin_(&Flock::rwl, "river"));
	}

	static inline const Ptr mut_()
	{
		return make_<Flock>();
	}

	static inline const Ptr mut(const Ptr& it)
	{
		return make_<Flock>(it);
	}

	static inline const Ptr fin_()
	{
		return fake_<Flock>();
	}

	static inline const Ptr fin(const Ptr& it)
	{
		return fake_<Flock>(it);
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Flock>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Flock>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Flock>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
	{
		return rwl_(it->next_());
	}

	inline void push_back_(const Ptr& item)
	{
		_vector.push_back(item);
	}

	inline const Ptr push_back(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			push_back_(i);
		}
		return me_();
	}

	inline const int64_t size_() const
	{
		return int64_t(_vector.size());
	}

	inline const Ptr size(const Ptr& ignore) const;

	inline const bool empty_() const
	{
		return _vector.empty();
	}

	inline const Ptr empty(const Ptr& ignore) const
	{
		return boolean_(empty_());
	}

	inline const Ptr at_(const int64_t pos) const
	{
		if (pos >= 0 && pos < size_())
		{
			return _vector[std::size_t(pos)];
		}
		return nothing_();
	}

	inline const Ptr at_(const Ptr& pos) const;

	inline const Ptr at(const Ptr& it) const
	{
		return at_(it->next_());
	}

	inline void update_(const int64_t pos, const Ptr& value)
	{
		if (pos >= 0)
		{
			const int64_t size = size_();
			if (pos == size)
			{
				push_back_(value);
			}
			else
			{
				if (pos > size)
				{
					_vector.resize(std::size_t(pos) + 1, nothing_());
				}
				_vector[std::size_t(pos)] = value;
			}
		}
	}

	inline void update_(const Ptr& pos, const Ptr& value);

	inline const Ptr update(const Ptr& it)
	{
		const Ptr index = it->next_();
		const Ptr value = it->next_();
		update_(index, value);
		return value;
	}

	inline void insert_(const int64_t pos, const Ptr& value)
	{
		if (pos >= 0)
		{
			const int64_t size = size_();
			if (pos == size)
			{
				push_back_(value);
			}
			else
			{
				if (pos > size)
				{
					_vector.resize(std::size_t(pos) + 1, nothing_());
					_vector[std::size_t(pos)] = value;
				}
				else
				{
					_vector.insert(_vector.begin() + pos, value);
				}
			}
		}
	}

	inline void insert_(const Ptr& pos, const Ptr& value);

	inline const Ptr insert(const Ptr& it)
	{
		const Ptr index = it->next_();
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			insert_(index, i);
		}
		return me_();
	}

	inline void erase_(const int64_t pos)
	{
		if (pos >= 0 && pos < size_())
		{
			_vector.erase(_vector.begin() + pos);
		}
	}

	inline void erase_(const Ptr& pos);

	inline const Ptr erase(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			erase_(i);
		}
		return me_();
	}

	inline void clear_()
	{
		_vector.clear();
	}

	inline const Ptr clear(const Ptr& ignore)
	{
		clear_();
		return me_();
	}

	inline void self_add_(const Ptr& other);

	inline const Ptr self_add(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_add_(i);
		}
		return me_();
	}

	inline const Ptr add_(const Ptr& other) const
	{
		const Ptr result = copy_();
		static_<Flock>(result)->self_add_(other);
		return result;
	}

	inline const Ptr add(const Ptr& it) const
	{
		const Ptr result = copy_();
		static_<Flock>(result)->self_add(it);
		return result;
	}

	virtual inline const Ptr iterator_() const override
	{
		return Iterator::mut_(me_());
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Flock");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Flock::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Flock::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Flock::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Flock::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Flock::category_();
	}

	static inline const Ptr categories_();

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Flock::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Flock::categories_();
	}

	virtual inline const Ptr visit(const Ptr& it) override
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

	inline const std_vector_ptr& get_() const
	{
		return _vector;
	}

	class Concurrent : public Stateful
	{
	public:
		inline Concurrent(const Ptr& flock)
			: Stateful{}
			, _flock{ flock }
			, _mutex{}
		{
		}

		virtual inline const Ptr pub_() const override
		{
			static const Ptr PUB = _public_(Concurrent::creator_());
			return PUB;
		}

		static inline const Ptr creator_(const Ptr& ignore = nothing_())
		{
			static const Ptr CREATION = []()
			{
				const auto shoal = static_<Shoal>(Stateful::creator_()->copy_());
				shoal->update_("type_name", Static::fin_(&Concurrent::type_name));
				shoal->update_("category", Static::fin_(&Concurrent::category));
				shoal->update_("categories", Static::fin_(&Concurrent::categories));
				shoal->update_("push_back", Member<Concurrent>::fin_(&Concurrent::push_back, "value"));
				shoal->update_("size", Const<Concurrent>::fin_(&Concurrent::size));
				shoal->update_("at", Const<Concurrent>::fin_(&Concurrent::at, "index"));
				shoal->update_("mut", Static::fin_(&Concurrent::mut, "flock"));
				shoal->finalize_();
				return shoal;
			}();
			return CREATION;
		}

		static inline void share_(const Ptr& shoal)
		{
			const auto s = static_<Shoal>(shoal);
			s->update_("strange::Flock::Concurrent", Static::fin_(&Flock::Concurrent::creator_));
			s->update_("strange::Flock::Concurrent::mut", Static::fin_(&Flock::Concurrent::mut, "flock"));
		}

		static inline const Ptr mut_(const Ptr& flock = Flock::mut_())
		{
			return make_<Concurrent>(flock);
		}

		static inline const Ptr mut(const Ptr& it)
		{
			return mut_(it->next_());
		}

		virtual inline const Ptr copy_() const override
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return mut_(_flock->copy_());
		}

		static inline const Ptr type_name_()
		{
			static const Ptr TYPE_NAME = sym_("strange::Flock::Concurrent");
			return TYPE_NAME;
		}

		static inline const Ptr type_name(const Ptr& ignore)
		{
			return Flock::Concurrent::type_name_();
		}

		virtual inline const Ptr type_() const override
		{
			return Flock::Concurrent::type_name_();
		}

		static inline const Ptr category_()
		{
			static const Ptr CATEGORY = Cat::fin_(Flock::Concurrent::type_name_());
			return CATEGORY;
		}

		static inline const Ptr category(const Ptr& ignore)
		{
			return Flock::Concurrent::category_();
		}

		virtual inline const Ptr cat_() const override
		{
			return Flock::Concurrent::category_();
		}

		static inline const Ptr categories_();

		static inline const Ptr categories(const Ptr& ignore)
		{
			return Flock::Concurrent::categories_();
		}

		virtual inline const Ptr cats_() const override
		{
			return Flock::Concurrent::categories_();
		}

		inline void push_back_(const Ptr& item)
		{
			const Ptr frozen_item = item->clone_freeze_();
			std::unique_lock<std::shared_timed_mutex> lock(_mutex);
			static_<Flock>(_flock)->push_back_(frozen_item);
		}

		inline const Ptr push_back(const Ptr& it)
		{
			for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
			{
				push_back_(i);
			}
			return me_();
		}

		inline const int64_t size_() const
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return static_<Flock>(_flock)->size_();
		}

		inline const Ptr size(const Ptr& ignore) const;

		inline const Ptr at_(const int64_t pos) const
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return static_<Flock>(_flock)->at_(pos);
		}

		inline const Ptr at_(const Ptr& pos) const;

		inline const Ptr at(const Ptr& it) const
		{
			return at_(it->next_());
		}

	private:
		const Ptr _flock;
		mutable std::shared_timed_mutex _mutex;
	};

private:
	std_vector_ptr _vector;
	mutable bool _frozen;

	class Iterator : public Stateful
	{
	public:
		inline Iterator(const Ptr& flock)
			: Stateful{}
			, _flock{ flock }
			, _pos{ 0 }
		{
		}

		virtual inline const Ptr next_() override
		{
			const std_vector_ptr& vec = static_<Flock>(_flock)->_vector;
			if (_pos >= vec.size())
			{
				return stop_();
			}
			return vec[_pos++];
		}

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_flock);
			static_<Iterator>(result)->_pos = _pos;
			return result;
		}

		static inline const Ptr mut_(const Ptr& flock)
		{
			return make_<Iterator>(flock);
		}

		static inline const Ptr type_name_()
		{
			static const Ptr TYPE_NAME = sym_("strange::Flock::Iterator");
			return TYPE_NAME;
		}

		static inline const Ptr type_name(const Ptr& ignore)
		{
			return Flock::Iterator::type_name_();
		}

		virtual inline const Ptr type_() const override
		{
			return Flock::Iterator::type_name_();
		}

		static inline const Ptr category_()
		{
			static const Ptr CATEGORY = Cat::fin_(Flock::Iterator::type_name_());
			return CATEGORY;
		}

		static inline const Ptr category(const Ptr& ignore)
		{
			return Flock::Iterator::category_();
		}

		virtual inline const Ptr cat_() const override
		{
			return Flock::Iterator::category_();
		}

		static inline const Ptr categories_();

		static inline const Ptr categories(const Ptr& ignore)
		{
			return Flock::Iterator::categories_();
		}

		virtual inline const Ptr cats_() const override
		{
			return Flock::Iterator::categories_();
		}

	private:
		const Ptr _flock;
		std::size_t _pos;
	};
};

//----------------------------------------------------------------------
class Herd : public Stateful, public Serializable
//----------------------------------------------------------------------
{
	class Hash
	{
	public:
		inline std::size_t operator()(const Ptr& ptr) const
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
	inline Herd()
		: Stateful{}
		, Serializable{}
		, _set{}
		, _frozen{ false }
	{
	}

	inline Herd(const Ptr& it)
		: Stateful{}
		, Serializable{}
		, _set{}
		, _frozen{ false }
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			insert_(i);
		}
	}

	virtual inline void freeze_() const override
	{
		if (!_frozen)
		{
			for (const auto i : _set)
			{
				i->freeze_();
			}
			finalize_();
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
		if (final_())
		{
			result->finalize_();
		}
		return result;
	}

	virtual inline const Ptr to_lake_() const override
	{
		return to_lake_via_river_();
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		from_lake_via_river_(lake);
	}

	virtual inline void to_river_(const Ptr& river) const override;

	virtual inline void from_river_(const Ptr& river) override;

	virtual inline void to_river_with_links_(const Ptr& shoal, const Ptr& river) const override;

	virtual inline void from_river_with_links_(const Ptr& river) override;

	virtual inline void replace_links_(const Ptr& shoal) override;

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = _public_(Herd::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Stateful::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Herd::type_name));
			shoal->update_("category", Static::fin_(&Herd::category));
			shoal->update_("categories", Static::fin_(&Herd::categories));
			shoal->update_("to_lake", Const<Herd>::fin_(&Herd::to_lake));
			shoal->update_("from_lake", Member<Herd>::fin_(&Herd::from_lake, "lake"));
			shoal->update_("to_river", Const<Herd>::fin_(&Herd::to_river, "river"));
			shoal->update_("from_river", Member<Herd>::fin_(&Herd::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Herd::mut, "key", ".."));
			shoal->update_("fin", Static::fin_(&Herd::fin, "key", ".."));
			shoal->update_("lak", Static::fin_(&Herd::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Herd::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Herd::rwl, "river"));
			shoal->update_("at", Const<Herd>::fin_(&Herd::at, "key"));
			shoal->update_("update", Member<Herd>::fin_(&Herd::update, "key", "insert"));
			shoal->update_("insert", Member<Herd>::fin_(&Herd::insert, "key"));
			shoal->update_("erase", Member<Herd>::fin_(&Herd::erase, "key"));
			shoal->update_("clear", Member<Herd>::fin_(&Herd::clear));
			shoal->update_("size", Const<Herd>::fin_(&Herd::size));
			shoal->update_("empty", Const<Herd>::fin_(&Herd::empty));
			shoal->update_("self_add", Member<Herd>::fin_(&Herd::self_add, "herd", ".."));
			shoal->update_("add", Const<Herd>::fin_(&Herd::add, "herd", ".."));
			shoal->update_("self_subtract", Member<Herd>::fin_(&Herd::self_subtract, "herd", ".."));
			shoal->update_("subtract", Const<Herd>::fin_(&Herd::subtract, "herd", ".."));
			shoal->update_("gather", Member<Herd>::fin_(&Herd::gather, "key"));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Herd", Static::fin_(&Herd::creator_));
		s->update_("strange::Herd::mut", Static::fin_(&Herd::mut));
		s->update_("strange::Herd::lak", Static::fin_(&Herd::lak, "lake"));
		s->update_("strange::Herd::riv", Static::fin_(&Herd::riv, "river"));
		s->update_("strange::Herd::rwl", Static::fin_(&Herd::rwl, "river"));
	}

	static inline const Ptr mut_()
	{
		return make_<Herd>();
	}

	static inline const Ptr mut(const Ptr& it)
	{
		return make_<Herd>(it);
	}

	static inline const Ptr fin(const Ptr& it)
	{
		const Ptr result = mut(it);
		result->finalize_();
		return result;
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Herd>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Herd>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Herd>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
	{
		return rwl_(it->next_());
	}

	inline const bool at_(const std::string& key) const
	{
		return at_(sym_(key));
	}

	inline const bool at_(const Ptr& key) const
	{
		return _set.find(key) != _set.cend();
	}

	inline const Ptr at(const Ptr& it) const
	{
		return boolean_(at_(it->next_()));
	}

	inline void update_(const std::string& key, const bool insert)
	{
		update_(sym_(key), insert);
	}

	inline void update_(const Ptr& key, const bool insert)
	{
		if (insert)
		{
			_set.insert(key);
		}
		else
		{
			_set.erase(key);
		}
	}

	inline void update_(const Ptr& key, const Ptr& insert)
	{
		update_(key, !insert->is_nothing_());
	}

	inline const Ptr update(const Ptr& it)
	{
		const Ptr key = it->next_();
		const Ptr insert = it->next_();
		update_(key, insert);
		return insert;
	}

	inline const bool insert_(const std::string& key)
	{
		return insert_(sym_(key));
	}

	inline const bool insert_(const Ptr& key)
	{
		return _set.insert(key).second;
	}

	inline const Ptr insert(const Ptr& it)
	{
		return boolean_(insert_(it->next_()));
	}

	inline const bool erase_(const std::string& key)
	{
		return erase_(sym_(key));
	}

	inline const bool erase_(const Ptr& item)
	{
		return _set.erase(item);
	}

	inline const Ptr erase(const Ptr& it)
	{
		return boolean_(erase_(it->next_()));
	}

	inline void clear_()
	{
		_set.clear();
	}

	inline const Ptr clear(const Ptr& ignore)
	{
		clear_();
		return me_();
	}

	inline const int64_t size_() const
	{
		return int64_t(_set.size());
	}

	inline const Ptr size(const Ptr& ignore) const;

	inline const bool empty_() const
	{
		return _set.empty();
	}

	inline const Ptr empty(const Ptr& ignore) const
	{
		return boolean_(empty_());
	}

	inline void self_add_(const Ptr& other)
	{
		const auto herd = dynamic_<Herd>(other);
		if (herd)
		{
			if (&_set == &herd->_set)
			{
				const std_unordered_set_ptr copy = _set;
				for (auto i : copy)
				{
					insert_(i);
				}
			}
			else
			{
				for (auto i : herd->_set)
				{
					insert_(i);
				}
			}
		}
		else
		{
			const auto shoal = dynamic_<Shoal>(other);
			if (shoal)
			{
				for (const auto& i : shoal->get_())
				{
					update_(i.first, i.second);
				}
			}
			else
			{
				const auto flock = dynamic_<Flock>(other);
				if (flock)
				{
					for (auto i : flock->get_())
					{
						insert_(i);
					}
				}
				else
				{
					const Ptr it = other->iterator_();
					for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
					{
						insert_(i);
					}
				}
			}
		}
	}

	inline const Ptr self_add(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_add_(i);
		}
		return me_();
	}

	inline const Ptr add_(const Ptr& other) const
	{
		const Ptr result = copy_();
		static_<Herd>(result)->self_add_(other);
		return result;
	}

	inline const Ptr add(const Ptr& it) const
	{
		const Ptr result = copy_();
		static_<Herd>(result)->self_add(it);
		return result;
	}

	inline void self_subtract_(const Ptr& other)
	{
		const auto herd = dynamic_<Herd>(other);
		if (herd)
		{
			for (auto i : herd->_set)
			{
				erase_(i);
			}
		}
		else
		{
			const auto shoal = dynamic_<Shoal>(other);
			if (shoal)
			{
				for (const auto& i : shoal->get_())
				{
					erase_(i.first);
				}
			}
			else
			{
				const auto flock = dynamic_<Flock>(other);
				if (flock)
				{
					for (auto i : flock->get_())
					{
						erase_(i);
					}
				}
				else
				{
					const Ptr it = other->iterator_();
					for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
					{
						erase_(i);
					}
				}
			}
		}
	}

	inline const Ptr self_subtract(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_subtract_(i);
		}
		return me_();
	}

	inline const Ptr subtract_(const Ptr& other) const
	{
		const Ptr result = copy_();
		static_<Herd>(result)->self_subtract_(other);
		return result;
	}

	inline const Ptr subtract(const Ptr& it) const
	{
		const Ptr result = copy_();
		static_<Herd>(result)->self_subtract(it);
		return result;
	}

	virtual inline const Ptr iterator_() const override
	{
		if (final_())
		{
			return Iterator::mut_(me_());
		}
		return Iterator::mut_(copy_());
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Herd");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Herd::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Herd::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Herd::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Herd::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Herd::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Stateful::categories_()->copy_());
			categories->self_add_(Serializable::categories_());
			categories->insert_(Herd::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Herd::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Herd::categories_();
	}

	virtual inline const Ptr visit(const Ptr& it) override
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

	inline void gather_(const Ptr& item)
	{
		item->invoke_("visit", me_(), "insert", item);
	}

	inline const Ptr gather(const Ptr& it)
	{
		gather_(it->next_());
		return nothing_();
	}

	inline const std_unordered_set_ptr& get_() const
	{
		return _set;
	}

	class Concurrent : public Stateful
	{
	public:
		inline Concurrent(const Ptr& herd)
			: Stateful{}
			, _herd{ herd }
			, _mutex{}
		{
		}

		virtual inline const Ptr pub_() const override
		{
			static const Ptr PUB = _public_(Concurrent::creator_());
			return PUB;
		}

		static inline const Ptr creator_(const Ptr& ignore = nothing_())
		{
			static const Ptr CREATION = []()
			{
				const auto shoal = static_<Shoal>(Stateful::creator_()->copy_());
				shoal->update_("type_name", Static::fin_(&Concurrent::type_name));
				shoal->update_("category", Static::fin_(&Concurrent::category));
				shoal->update_("categories", Static::fin_(&Concurrent::categories));
				shoal->update_("at", Const<Concurrent>::fin_(&Concurrent::at, "key"));
				shoal->update_("insert", Member<Concurrent>::fin_(&Concurrent::insert, "key"));
				shoal->update_("mut", Static::fin_(&Concurrent::mut, "herd"));
				shoal->finalize_();
				return shoal;
			}();
			return CREATION;
		}

		static inline void share_(const Ptr& shoal)
		{
			const auto s = static_<Shoal>(shoal);
			s->update_("strange::Herd::Concurrent", Static::fin_(&Herd::Concurrent::creator_));
			s->update_("strange::Herd::Concurrent::mut", Static::fin_(&Herd::Concurrent::mut, "herd"));
		}

		static inline const Ptr mut_(const Ptr& herd = Herd::mut_())
		{
			return make_<Concurrent>(herd);
		}

		static inline const Ptr mut(const Ptr& it)
		{
			return mut_(it->next_());
		}

		virtual inline const Ptr copy_() const override
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return mut_(_herd->copy_());
		}

		static inline const Ptr type_name_()
		{
			static const Ptr TYPE_NAME = sym_("strange::Herd::Concurrent");
			return TYPE_NAME;
		}

		static inline const Ptr type_name(const Ptr& ignore)
		{
			return Herd::Concurrent::type_name_();
		}

		virtual inline const Ptr type_() const override
		{
			return Herd::Concurrent::type_name_();
		}

		static inline const Ptr category_()
		{
			static const Ptr CATEGORY = Cat::fin_(Herd::Concurrent::type_name_());
			return CATEGORY;
		}

		static inline const Ptr category(const Ptr& ignore)
		{
			return Herd::Concurrent::category_();
		}

		virtual inline const Ptr cat_() const override
		{
			return Herd::Concurrent::category_();
		}

		static inline const Ptr categories_()
		{
			static const Ptr CATEGORIES = []()
			{
				const auto categories = static_<Herd>(Stateful::categories_()->copy_());
				categories->insert_(Herd::Concurrent::category_());
				categories->finalize_();
				return categories;
			}();
			return CATEGORIES;
		}

		static inline const Ptr categories(const Ptr& ignore)
		{
			return Herd::Concurrent::categories_();
		}

		virtual inline const Ptr cats_() const override
		{
			return Herd::Concurrent::categories_();
		}

		inline const bool at_(const Ptr& item) const
		{
			std::shared_lock<std::shared_timed_mutex> lock(_mutex);
			return static_<Herd>(_herd)->at_(item);
		}

		inline const Ptr at(const Ptr& it) const
		{
			return boolean_(at_(it->next_()));
		}

		inline const bool insert_(const Ptr& item)
		{
			const Ptr frozen_item = item->clone_freeze_();
			std::unique_lock<std::shared_timed_mutex> lock(_mutex);
			return static_<Herd>(_herd)->insert_(frozen_item);
		}

		inline const Ptr insert(const Ptr& it)
		{
			return boolean_(insert_(it->next_()));
		}

	private:
		const Ptr _herd;
		mutable std::shared_timed_mutex _mutex;
	};

private:
	std_unordered_set_ptr _set;
	mutable bool _frozen;

	class Iterator : public Stateful
	{
	public:
		inline Iterator(const Ptr& herd)
			: Stateful{}
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

		static inline const Ptr mut_(const Ptr& herd)
		{
			return make_<Iterator>(herd);
		}

		static inline const Ptr type_name_()
		{
			static const Ptr TYPE_NAME = sym_("strange::Herd::Iterator");
			return TYPE_NAME;
		}

		static inline const Ptr type_name(const Ptr& ignore)
		{
			return Herd::Iterator::type_name_();
		}

		virtual inline const Ptr type_() const override
		{
			return Herd::Iterator::type_name_();
		}

		static inline const Ptr category_()
		{
			static const Ptr CATEGORY = Cat::fin_(Herd::Iterator::type_name_());
			return CATEGORY;
		}

		static inline const Ptr category(const Ptr& ignore)
		{
			return Herd::Iterator::category_();
		}

		virtual inline const Ptr cat_() const override
		{
			return Herd::Iterator::category_();
		}

		static inline const Ptr categories_()
		{
			static const Ptr CATEGORIES = []()
			{
				const auto categories = static_<Herd>(Stateful::categories_()->copy_());
				categories->insert_(Herd::Iterator::category_());
				categories->finalize_();
				return categories;
			}();
			return CATEGORIES;
		}

		static inline const Ptr categories(const Ptr& ignore)
		{
			return Herd::Iterator::categories_();
		}

		virtual inline const Ptr cats_() const override
		{
			return Herd::Iterator::categories_();
		}

	private:
		const Ptr _herd;
		std_unordered_set_ptr::const_iterator _iterator;
	};
};

//----------------------------------------------------------------------
class IteratorPtr : public Stateful
//----------------------------------------------------------------------
{
public:
	inline IteratorPtr(const Ptr& ptr)
		: Stateful{}
		, _ptr{ ptr }
	{
	}

	static inline const Ptr mut(const Ptr& it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr& ptr)
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
		static const Ptr PUB = _public_(IteratorPtr::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Stateful::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&IteratorPtr::type_name));
			shoal->update_("category", Static::fin_(&IteratorPtr::category));
			shoal->update_("categories", Static::fin_(&IteratorPtr::categories));
			shoal->update_("mut", Static::fin_(&IteratorPtr::mut, "thing"));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::IteratorPtr");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return IteratorPtr::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return IteratorPtr::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(IteratorPtr::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return IteratorPtr::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return IteratorPtr::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Stateful::categories_()->copy_());
			categories->insert_(IteratorPtr::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return IteratorPtr::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return IteratorPtr::categories_();
	}

private:
	Ptr _ptr;
};

template <typename C>
//----------------------------------------------------------------------
class IteratorCopy : public Stateful
//----------------------------------------------------------------------
{
public:
	template <typename F>
	inline IteratorCopy(F&& collection)
		: Stateful{}
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

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::IteratorCopy");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return IteratorCopy::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return IteratorCopy::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(IteratorCopy::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return IteratorCopy::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return IteratorCopy::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Stateful::categories_()->copy_());
			categories->insert_(IteratorCopy::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return IteratorCopy::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return IteratorCopy::categories_();
	}

private:
	const C _collection;
	typename C::const_iterator _iterator;
};

template <typename C>
//----------------------------------------------------------------------
class IteratorRef : public Stateful
//----------------------------------------------------------------------
{
public:
	template <typename F>
	inline IteratorRef(F&& collection)
		: Stateful{}
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

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::IteratorRef");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return IteratorRef::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return IteratorRef::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(IteratorRef::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return IteratorRef::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return IteratorRef::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Stateful::categories_()->copy_());
			categories->insert_(IteratorRef::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return IteratorRef::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return IteratorRef::categories_();
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

	inline D& ref_()
	{
		return _data;
	}

private:
	D _data;
};

template<>
class Data<float>
{
public:
	inline Data(const float& data)
		: _data{ std::isfinite(data) ? data : 0.0f }
	{
	}

	inline void set_(const float& data)
	{
		if (std::isfinite(data))
		{
			_data = data;
		}
	}

	inline const float& get_() const
	{
		return _data;
	}

	inline float& ref_()
	{
		return _data;
	}

private:
	float _data;
};

template<>
class Data<double>
{
public:
	inline Data(const double& data)
		: _data{ std::isfinite(data) ? data : 0.0 }
	{
	}

	inline void set_(const double& data)
	{
		if (std::isfinite(data))
		{
			_data = data;
		}
	}

	inline const double& get_() const
	{
		return _data;
	}

	inline double& ref_()
	{
		return _data;
	}

private:
	double _data;
};

//----------------------------------------------------------------------
class Lake : public Stateful, public Serializable, public Data<std::string>
//----------------------------------------------------------------------
{
public:
	using S = std::string;

	static inline const Ptr mut_(const S& data = S())
	{
		return make_<Lake>(data);
	}

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const S& data = S())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Lake>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Lake>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Lake>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
	{
		return rwl_(it->next_());
	}

	inline Lake(const S& data)
		: Stateful{}
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
		static const Ptr PUB = _public_(Lake::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Stateful::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Lake::type_name));
			shoal->update_("category", Static::fin_(&Lake::category));
			shoal->update_("categories", Static::fin_(&Lake::categories));
			shoal->update_("to_lake", Const<Lake>::fin_(&Lake::to_lake));
			shoal->update_("from_lake", Member<Lake>::fin_(&Lake::from_lake, "lake"));
			shoal->update_("to_river", Const<Lake>::fin_(&Lake::to_river, "river"));
			shoal->update_("from_river", Member<Lake>::fin_(&Lake::from_river, "river"));
			shoal->update_("mut", Static::fin_(&Lake::mut));
			shoal->update_("fin", Static::fin_(&Lake::fin));
			shoal->update_("lak", Static::fin_(&Lake::lak, "lake"));
			shoal->update_("riv", Static::fin_(&Lake::riv, "river"));
			shoal->update_("rwl", Static::fin_(&Lake::rwl, "river"));
			shoal->update_("self_add", Member<Lake>::fin_(&Lake::self_add, "lake", ".."));
			shoal->update_("add", Const<Lake>::fin_(&Lake::add, "lake", ".."));
			shoal->update_("at", Const<Lake>::fin_(&Lake::at, "index"));
			shoal->update_("update", Member<Lake>::fin_(&Lake::update, "index", "byte"));
			shoal->update_("less_than", Const<Lake>::fin_(&Lake::less_than, "lake"));
			shoal->update_("greater_than", Const<Lake>::fin_(&Lake::greater_than, "lake"));
			shoal->update_("less_or_equal", Const<Lake>::fin_(&Lake::less_or_equal, "lake"));
			shoal->update_("greater_or_equal", Const<Lake>::fin_(&Lake::greater_or_equal, "lake"));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Lake", Static::fin_(&Lake::creator_));
		s->update_("strange::Lake::mut", Static::fin_(&Lake::mut));
		s->update_("strange::Lake::fin", Static::fin_(&Lake::fin));
		s->update_("strange::Lake::lak", Static::fin_(&Lake::lak, "lake"));
		s->update_("strange::Lake::riv", Static::fin_(&Lake::riv, "river"));
		s->update_("strange::Lake::rwl", Static::fin_(&Lake::rwl, "river"));
	}

	virtual inline const Ptr to_lake_() const override
	{
		const Ptr lake = copy_();
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("Lake::from_lake_ passed wrong category of thing");
		}
		set_(lak->get_());
		if (lak->final_())
		{
			finalize_();
		}
	}

	virtual inline void to_river_(const Ptr& river) const override;

	virtual inline void from_river_(const Ptr& river) override;

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Lake");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Lake::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Lake::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Lake::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Lake::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Lake::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Stateful::categories_()->copy_());
			categories->self_add_(Serializable::categories_());
			categories->insert_(Lake::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Lake::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Lake::categories_();
	}

	inline void self_add_(const std::string& s)
	{
		ref_() += s;
	}

	inline void self_add_(const Ptr& other)
	{
		const auto lake = dynamic_<Lake>(other);
		if (lake)
		{
			self_add_(lake->get_());
		}
		else
		{
			const auto symbol = dynamic_<Symbol>(other);
			if (symbol)
			{
				self_add_(symbol->get_());
			}
			else
			{
				throw Disagreement("strange::Lake::self_add_ passed invalid argument");
			}
		}
	}

	inline const Ptr self_add(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_add_(i);
		}
		return me_();
	}

	inline const Ptr add_(const Ptr& other) const
	{
		const Ptr result = copy_();
		static_<Lake>(result)->self_add_(other);
		return result;
	}

	inline const Ptr add(const Ptr& it) const
	{
		const Ptr result = copy_();
		static_<Lake>(result)->self_add(it);
		return result;
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto lake = dynamic_<Lake>(other);
		if (lake)
		{
			return get_() == lake->get_();
		}
		const auto symbol = dynamic_<Symbol>(other);
		return symbol && (get_() == symbol->get_());
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<S>()(get_());
	}

	inline const char at_(const int64_t index) const
	{
		const S& s = get_();
		if (std::size_t(index) < s.length())
		{
			return s[index];
		}
		return 0;
	}

	inline const char at_(const Ptr& index) const;

	inline const Ptr at(const Ptr& it) const;

	inline void update_(const int64_t index, const int64_t byte)
	{
		S& s = ref_();
		if (std::size_t(index) < s.length())
		{
			s[index] = char(byte);
		}
	}

	inline void update_(const Ptr& index, const Ptr& byte);

	inline const Ptr update(const Ptr& it)
	{
		const Ptr index = it->next_();
		const Ptr byte = it->next_();
		update_(index, byte);
		return byte;
	}

	inline const bool less_than_(const Ptr& other) const;

	inline const Ptr less_than(const Ptr& it) const
	{
		return boolean_(less_than_(it->next_()));
	}

	inline const bool greater_than_(const Ptr& other) const;

	inline const Ptr greater_than(const Ptr& it) const
	{
		return boolean_(greater_than_(it->next_()));
	}

	inline const bool less_or_equal_(const Ptr& other) const;

	inline const Ptr less_or_equal(const Ptr& it) const
	{
		return boolean_(less_or_equal_(it->next_()));
	}

	inline const bool greater_or_equal_(const Ptr& other) const;

	inline const Ptr greater_or_equal(const Ptr& it) const
	{
		return boolean_(greater_or_equal_(it->next_()));
	}
};

//----------------------------------------------------------------------
class Number : public Stateful, public Serializable
//----------------------------------------------------------------------
{
public:
	Number() = default;

	virtual inline int64_t to_int64_() const
	{
		return int64_t(std::llround(to_float64_()));
	}

	inline const Ptr to_int64(const Ptr& ignore) const;

	virtual inline void from_int64_(const int64_t int64)
	{
		from_float64_(double(int64));
	}

	inline void from_int64_(const Ptr& ptr);

	inline const Ptr from_int64(const Ptr& it)
	{
		from_int64_(it->next_());
		return nothing_();
	}

	virtual inline double to_float64_() const
	{
		return double(to_int64_());
	}

	inline const Ptr to_float64(const Ptr& ignore) const;

	virtual inline void from_float64_(const double float64)
	{
		from_int64_(int64_t(std::llround(float64)));
	}

	inline void from_float64_(const Ptr& ptr);

	inline const Ptr from_float64(const Ptr& it)
	{
		from_float64_(it->next_());
		return nothing_();
	}

	virtual inline double to_imaginary64_() const
	{
		return 0.0;
	}

	inline const Ptr to_imaginary64(const Ptr& ignore) const;

	virtual inline void from_imaginary64_(const double imaginary64)
	{
	}

	inline void from_imaginary64_(const Ptr& ptr);

	inline const Ptr from_imaginary64(const Ptr& it)
	{
		from_imaginary64_(it->next_());
		return nothing_();
	}

	virtual inline std::complex<double> to_complex64_() const
	{
		return std::complex<double>(to_float64_(), 0.0);
	}

	inline const Ptr to_complex64(const Ptr& ignore) const;

	virtual inline void from_complex64_(const std::complex<double>& complex64)
	{
		from_float64_(complex64.real());
	}

	inline void from_complex64_(const Ptr& ptr);

	inline const Ptr from_complex64(const Ptr& it)
	{
		from_complex64_(it->next_());
		return nothing_();
	}

	virtual inline const Ptr to_symbol_() const = 0;

	inline const Ptr to_symbol(const Ptr& ignore) const
	{
		return to_symbol_();
	}

	virtual inline void from_symbol_(const Ptr& ptr) = 0;

	inline const Ptr from_symbol(const Ptr& it)
	{
		from_symbol_(it->next_());
		return nothing_();
	}

	virtual inline void increment_() = 0;

	inline const Ptr increment(const Ptr& ignore)
	{
		increment_();
		return me_();
	}

	virtual inline void decrement_() = 0;

	inline const Ptr decrement(const Ptr& ignore)
	{
		decrement_();
		return me_();
	}

	virtual inline void self_add_(const Ptr& other) = 0;

	inline const Ptr self_add(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_add_(i);
		}
		return me_();
	}

	inline const Ptr add_(const Ptr& other) const
	{
		const Ptr result = copy_();
		static_<Number>(result)->self_add_(other);
		return result;
	}

	inline const Ptr add(const Ptr& it) const
	{
		const Ptr result = copy_();
		static_<Number>(result)->self_add(it);
		return result;
	}

	virtual inline void self_subtract_(const Ptr& other) = 0;

	inline const Ptr self_subtract(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_subtract_(i);
		}
		return me_();
	}

	inline const Ptr subtract_(const Ptr& other) const
	{
		const Ptr result = copy_();
		static_<Number>(result)->self_subtract_(other);
		return result;
	}

	inline const Ptr subtract(const Ptr& it) const
	{
		const Ptr result = copy_();
		static_<Number>(result)->self_subtract(it);
		return result;
	}

	virtual inline void self_multiply_(const Ptr& other) = 0;

	inline const Ptr self_multiply(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_multiply_(i);
		}
		return me_();
	}

	inline const Ptr multiply_(const Ptr& other) const
	{
		const Ptr result = copy_();
		static_<Number>(result)->self_multiply_(other);
		return result;
	}

	inline const Ptr multiply(const Ptr& it) const
	{
		const Ptr result = copy_();
		static_<Number>(result)->self_multiply(it);
		return result;
	}

	virtual inline void self_divide_(const Ptr& other) = 0;

	inline const Ptr self_divide(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_divide_(i);
		}
		return me_();
	}

	inline const Ptr divide_(const Ptr& other) const
	{
		const Ptr result = copy_();
		static_<Number>(result)->self_divide_(other);
		return result;
	}

	inline const Ptr divide(const Ptr& it) const
	{
		const Ptr result = copy_();
		static_<Number>(result)->self_divide(it);
		return result;
	}

	virtual inline void self_modulo_(const Ptr& other) = 0;

	inline const Ptr self_modulo(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_modulo_(i);
		}
		return me_();
	}

	inline const Ptr modulo_(const Ptr& other) const
	{
		const Ptr result = copy_();
		static_<Number>(result)->self_modulo_(other);
		return result;
	}

	inline const Ptr modulo(const Ptr& it) const
	{
		const Ptr result = copy_();
		static_<Number>(result)->self_modulo(it);
		return result;
	}

	virtual inline const bool less_than_(const Ptr& other) const = 0;

	inline const Ptr less_than(const Ptr& it) const
	{
		return boolean_(less_than_(it->next_()));
	}

	virtual inline const bool greater_than_(const Ptr& other) const = 0;

	inline const Ptr greater_than(const Ptr& it) const
	{
		return boolean_(greater_than_(it->next_()));
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const = 0;

	inline const Ptr less_or_equal(const Ptr& it) const
	{
		return boolean_(less_or_equal_(it->next_()));
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const = 0;

	inline const Ptr greater_or_equal(const Ptr& it) const
	{
		return boolean_(greater_or_equal_(it->next_()));
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = _public_(Number::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Stateful::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Number::type_name));
			shoal->update_("category", Static::fin_(&Number::category));
			shoal->update_("categories", Static::fin_(&Number::categories));
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
			shoal->update_("increment", Member<Number>::fin_(&Number::increment));
			shoal->update_("decrement", Member<Number>::fin_(&Number::decrement));
			shoal->update_("self_add", Member<Number>::fin_(&Number::self_add, "number", ".."));
			shoal->update_("add", Const<Number>::fin_(&Number::add, "number", ".."));
			shoal->update_("self_subtract", Member<Number>::fin_(&Number::self_subtract, "number", ".."));
			shoal->update_("subtract", Const<Number>::fin_(&Number::subtract, "number", ".."));
			shoal->update_("self_multiply", Member<Number>::fin_(&Number::self_multiply, "number", ".."));
			shoal->update_("multiply", Const<Number>::fin_(&Number::multiply, "number", ".."));
			shoal->update_("self_divide", Member<Number>::fin_(&Number::self_divide, "number", ".."));
			shoal->update_("divide", Const<Number>::fin_(&Number::divide, "number", ".."));
			shoal->update_("self_modulo", Member<Number>::fin_(&Number::self_modulo, "number", ".."));
			shoal->update_("modulo", Const<Number>::fin_(&Number::modulo, "number", ".."));
			shoal->update_("less_than", Const<Number>::fin_(&Number::less_than, "number"));
			shoal->update_("greater_than", Const<Number>::fin_(&Number::greater_than, "number"));
			shoal->update_("less_or_equal", Const<Number>::fin_(&Number::less_or_equal, "number"));
			shoal->update_("greater_or_equal", Const<Number>::fin_(&Number::greater_or_equal, "number"));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Number");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Number::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Number::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Number::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Number::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Number::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Stateful::categories_()->copy_());
			categories->self_add_(Serializable::categories_());
			categories->insert_(Number::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Number::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Number::categories_();
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

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Bit>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Bit>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Bit>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
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
		static const Ptr PUB = _public_(Bit::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Bit::type_name));
			shoal->update_("category", Static::fin_(&Bit::category));
			shoal->update_("categories", Static::fin_(&Bit::categories));
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
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Bit", Static::fin_(&Bit::creator_));
		s->update_("strange::Bit::mut", Static::fin_(&Bit::mut));
		s->update_("strange::Bit::fin", Static::fin_(&Bit::fin));
		s->update_("strange::Bit::lak", Static::fin_(&Bit::lak, "lake"));
		s->update_("strange::Bit::riv", Static::fin_(&Bit::riv, "river"));
		s->update_("strange::Bit::rwl", Static::fin_(&Bit::rwl, "river"));
	}

	virtual inline const Ptr to_lake_() const override
	{
		const Ptr lake = Lake::mut_(std::string(1, get_() ? char(1) : char(0)));
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("Bit::from_lake_ passed wrong category of thing");
		}
		set_(bool(lak->get_()[0]));
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Bit");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Bit::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Bit::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Bit::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Bit::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Bit::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(Bit::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Bit::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Bit::categories_();
	}

	virtual inline int64_t to_int64_() const override
	{
		return get_() ? 1 : 0;
	}

	virtual inline void from_int64_(const int64_t int64) override
	{
		set_(int64 & 1);
	}

	virtual inline const Ptr to_symbol_() const override
	{
		return sym_(get_() ? "1" : "0");
	}

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(std::stoull(symbol->get_()) & 1);
		}
		else
		{
			throw Disagreement("strange::Bit::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		bool& b = ref_();
		b = !b;
	}

	virtual inline void decrement_() override
	{
		bool& b = ref_();
		b = !b;
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			bool& b = ref_();
			b = (b != bool(number->to_int64_() & 1));
		}
		else
		{
			throw Disagreement("strange::Bit::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number && (number->to_int64_() & 1))
		{
			bool& b = ref_();
			b = !b;
		}
		else
		{
			throw Disagreement("strange::Bit::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			bool& b = ref_();
			b = (b && (number->to_int64_() & 1));
		}
		else
		{
			throw Disagreement("strange::Bit::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0 && divisor != 1)
			{
				from_int64_(to_int64_() / divisor);
			}
		}
		else
		{
			throw Disagreement("strange::Bit::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0)
			{
				from_int64_(to_int64_() % divisor);
			}
		}
		else
		{
			throw Disagreement("strange::Bit::self_modulo_ passed invalid Number");
		}
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (to_int64_() == number->to_int64_());
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<int64_t>()(to_int64_());
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() < number->to_int64_();
		}
		throw Disagreement("strange::Bit::less_than_ passed invalid Number");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() > number->to_int64_();
		}
		throw Disagreement("strange::Bit::greater_than_ passed invalid Number");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() <= number->to_int64_();
		}
		throw Disagreement("strange::Bit::less_or_equal_ passed invalid Number");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() >= number->to_int64_();
		}
		throw Disagreement("strange::Bit::greater_or_equal_ passed invalid Number");
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

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Int8>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Int8>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Int8>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
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
		static const Ptr PUB = _public_(Int8::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Int8::type_name));
			shoal->update_("category", Static::fin_(&Int8::category));
			shoal->update_("categories", Static::fin_(&Int8::categories));
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
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Int8", Static::fin_(&Int8::creator_));
		s->update_("strange::Int8::mut", Static::fin_(&Int8::mut));
		s->update_("strange::Int8::fin", Static::fin_(&Int8::fin));
		s->update_("strange::Int8::lak", Static::fin_(&Int8::lak, "lake"));
		s->update_("strange::Int8::riv", Static::fin_(&Int8::riv, "river"));
		s->update_("strange::Int8::rwl", Static::fin_(&Int8::rwl, "river"));
	}

	virtual inline const Ptr to_lake_() const override
	{
		const Ptr lake = Lake::mut_(std::string(1, get_()));
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("Int8::from_lake_ passed wrong category of thing");
		}
		set_(lak->get_()[0]);
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Int8");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Int8::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Int8::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Int8::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Int8::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Int8::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(Int8::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Int8::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Int8::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoll(symbol->get_())));
		}
		else
		{
			throw Disagreement("strange::Int8::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		++ref_();
	}

	virtual inline void decrement_() override
	{
		--ref_();
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() + number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::Int8::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() - number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::Int8::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() * number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::Int8::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0 && divisor != 1)
			{
				from_int64_(to_int64_() / divisor);
			}
		}
		else
		{
			throw Disagreement("strange::Int8::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0)
			{
				from_int64_(to_int64_() % divisor);
			}
		}
		else
		{
			throw Disagreement("strange::Int8::self_modulo_ passed invalid Number");
		}
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (to_int64_() == number->to_int64_());
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<int64_t>()(to_int64_());
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() < number->to_int64_();
		}
		throw Disagreement("strange::Int8::less_than_ passed invalid Number");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() > number->to_int64_();
		}
		throw Disagreement("strange::Int8::greater_than_ passed invalid Number");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() <= number->to_int64_();
		}
		throw Disagreement("strange::Int8::less_or_equal_ passed invalid Number");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() >= number->to_int64_();
		}
		throw Disagreement("strange::Int8::greater_or_equal_ passed invalid Number");
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

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<UInt8>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<UInt8>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<UInt8>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
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
		static const Ptr PUB = _public_(UInt8::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&UInt8::type_name));
			shoal->update_("category", Static::fin_(&UInt8::category));
			shoal->update_("categories", Static::fin_(&UInt8::categories));
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
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::UInt8", Static::fin_(&UInt8::creator_));
		s->update_("strange::UInt8::mut", Static::fin_(&UInt8::mut));
		s->update_("strange::UInt8::fin", Static::fin_(&UInt8::fin));
		s->update_("strange::UInt8::lak", Static::fin_(&UInt8::lak, "lake"));
		s->update_("strange::UInt8::riv", Static::fin_(&UInt8::riv, "river"));
		s->update_("strange::UInt8::rwl", Static::fin_(&UInt8::rwl, "river"));
	}

	virtual inline const Ptr to_lake_() const override
	{
		const Ptr lake = Lake::mut_(std::string(1, *reinterpret_cast<const char*>(&(get_()))));
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("UInt8::from_lake_ passed wrong category of thing");
		}
		set_(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0])));
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::UInt8");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return UInt8::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return UInt8::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(UInt8::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return UInt8::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return UInt8::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(UInt8::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return UInt8::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return UInt8::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoull(symbol->get_())));
		}
		else
		{
			throw Disagreement("strange::UInt8::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		++ref_();
	}

	virtual inline void decrement_() override
	{
		--ref_();
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() + number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::UInt8::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() - number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::UInt8::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() * number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::UInt8::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0 && divisor != 1)
			{
				from_int64_(to_int64_() / divisor);
			}
		}
		else
		{
			throw Disagreement("strange::UInt8::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0)
			{
				from_int64_(to_int64_() % divisor);
			}
		}
		else
		{
			throw Disagreement("strange::UInt8::self_modulo_ passed invalid Number");
		}
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (to_int64_() == number->to_int64_());
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<int64_t>()(to_int64_());
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() < number->to_int64_();
		}
		throw Disagreement("strange::UInt8::less_than_ passed invalid Number");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() > number->to_int64_();
		}
		throw Disagreement("strange::UInt8::greater_than_ passed invalid Number");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() <= number->to_int64_();
		}
		throw Disagreement("strange::UInt8::less_or_equal_ passed invalid Number");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() >= number->to_int64_();
		}
		throw Disagreement("strange::UInt8::greater_or_equal_ passed invalid Number");
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

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Int16>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Int16>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Int16>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
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
		static const Ptr PUB = _public_(Int16::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Int16::type_name));
			shoal->update_("category", Static::fin_(&Int16::category));
			shoal->update_("categories", Static::fin_(&Int16::categories));
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
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Int16", Static::fin_(&Int16::creator_));
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
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("Int16::from_lake_ passed wrong category of thing");
		}
		set_(
			uint16_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint16_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8
			);
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Int16");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Int16::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Int16::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Int16::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Int16::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Int16::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(Int16::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Int16::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Int16::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoll(symbol->get_())));
		}
		else
		{
			throw Disagreement("strange::Int16::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		++ref_();
	}

	virtual inline void decrement_() override
	{
		--ref_();
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() + number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::Int16::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() - number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::Int16::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() * number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::Int16::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0 && divisor != 1)
			{
				from_int64_(to_int64_() / divisor);
			}
		}
		else
		{
			throw Disagreement("strange::Int16::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0)
			{
				from_int64_(to_int64_() % divisor);
			}
		}
		else
		{
			throw Disagreement("strange::Int16::self_modulo_ passed invalid Number");
		}
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (to_int64_() == number->to_int64_());
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<int64_t>()(to_int64_());
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() < number->to_int64_();
		}
		throw Disagreement("strange::Int16::less_than_ passed invalid Number");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() > number->to_int64_();
		}
		throw Disagreement("strange::Int16::greater_than_ passed invalid Number");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() <= number->to_int64_();
		}
		throw Disagreement("strange::Int16::less_or_equal_ passed invalid Number");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() >= number->to_int64_();
		}
		throw Disagreement("strange::Int16::greater_or_equal_ passed invalid Number");
	}
};

//----------------------------------------------------------------------
class UInt16 : public Number, public Data<uint16_t>
//----------------------------------------------------------------------
{
public:
	using D = uint16_t;

	static inline const Ptr mut_(const D& data = D())
	{
		return make_<UInt16>(data);
	}

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<UInt16>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<UInt16>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<UInt16>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
	{
		return rwl_(it->next_());
	}

	inline UInt16(const D& data)
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
		static const Ptr PUB = _public_(UInt16::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&UInt16::type_name));
			shoal->update_("category", Static::fin_(&UInt16::category));
			shoal->update_("categories", Static::fin_(&UInt16::categories));
			shoal->update_("to_lake", Const<UInt16>::fin_(&UInt16::to_lake));
			shoal->update_("from_lake", Member<UInt16>::fin_(&UInt16::from_lake, "lake"));
			shoal->update_("to_river", Const<UInt16>::fin_(&UInt16::to_river, "river"));
			shoal->update_("from_river", Member<UInt16>::fin_(&UInt16::from_river, "river"));
			shoal->update_("mut", Static::fin_(&UInt16::mut));
			shoal->update_("fin", Static::fin_(&UInt16::fin));
			shoal->update_("lak", Static::fin_(&UInt16::lak, "lake"));
			shoal->update_("riv", Static::fin_(&UInt16::riv, "river"));
			shoal->update_("rwl", Static::fin_(&UInt16::rwl, "river"));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::UInt16", Static::fin_(&UInt16::creator_));
		s->update_("strange::UInt16::mut", Static::fin_(&UInt16::mut));
		s->update_("strange::UInt16::fin", Static::fin_(&UInt16::fin));
		s->update_("strange::UInt16::lak", Static::fin_(&UInt16::lak, "lake"));
		s->update_("strange::UInt16::riv", Static::fin_(&UInt16::riv, "river"));
		s->update_("strange::UInt16::rwl", Static::fin_(&UInt16::rwl, "river"));
	}

	virtual inline const Ptr to_lake_() const override
	{
		std::string str(2, 0);
		str[0] = get_() & 0xFF;
		str[1] = (get_() >> 8) & 0xFF;
		const Ptr lake = Lake::mut_(str);
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("UInt16::from_lake_ passed wrong category of thing");
		}
		set_(
			uint16_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint16_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8
		);
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::UInt16");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return UInt16::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return UInt16::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(UInt16::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return UInt16::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return UInt16::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(UInt16::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return UInt16::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return UInt16::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoull(symbol->get_())));
		}
		else
		{
			throw Disagreement("strange::UInt16::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		++ref_();
	}

	virtual inline void decrement_() override
	{
		--ref_();
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() + number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::UInt16::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() - number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::UInt16::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() * number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::UInt16::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0 && divisor != 1)
			{
				from_int64_(to_int64_() / divisor);
			}
		}
		else
		{
			throw Disagreement("strange::UInt16::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0)
			{
				from_int64_(to_int64_() % divisor);
			}
		}
		else
		{
			throw Disagreement("strange::UInt16::self_modulo_ passed invalid Number");
		}
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (to_int64_() == number->to_int64_());
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<int64_t>()(to_int64_());
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() < number->to_int64_();
		}
		throw Disagreement("strange::UInt16::less_than_ passed invalid Number");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() > number->to_int64_();
		}
		throw Disagreement("strange::UInt16::greater_than_ passed invalid Number");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() <= number->to_int64_();
		}
		throw Disagreement("strange::UInt16::less_or_equal_ passed invalid Number");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() >= number->to_int64_();
		}
		throw Disagreement("strange::UInt16::greater_or_equal_ passed invalid Number");
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

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Int32>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Int32>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Int32>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
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
		static const Ptr PUB = _public_(Int32::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Int32::type_name));
			shoal->update_("category", Static::fin_(&Int32::category));
			shoal->update_("categories", Static::fin_(&Int32::categories));
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
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Int32", Static::fin_(&Int32::creator_));
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
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("Int32::from_lake_ passed wrong category of thing");
		}
		set_(
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[3]))) << 24
			);
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Int32");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Int32::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Int32::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Int32::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Int32::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Int32::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(Int32::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Int32::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Int32::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoll(symbol->get_())));
		}
		else
		{
			throw Disagreement("strange::Int32::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		++ref_();
	}

	virtual inline void decrement_() override
	{
		--ref_();
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() + number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::Int32::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() - number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::Int32::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() * number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::Int32::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0 && divisor != 1)
			{
				from_int64_(to_int64_() / divisor);
			}
		}
		else
		{
			throw Disagreement("strange::Int32::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0)
			{
				from_int64_(to_int64_() % divisor);
			}
		}
		else
		{
			throw Disagreement("strange::Int32::self_modulo_ passed invalid Number");
		}
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (to_int64_() == number->to_int64_());
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<int64_t>()(to_int64_());
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() < number->to_int64_();
		}
		throw Disagreement("strange::Int32::less_than_ passed invalid Number");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() > number->to_int64_();
		}
		throw Disagreement("strange::Int32::greater_than_ passed invalid Number");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() <= number->to_int64_();
		}
		throw Disagreement("strange::Int32::less_or_equal_ passed invalid Number");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() >= number->to_int64_();
		}
		throw Disagreement("strange::Int32::greater_or_equal_ passed invalid Number");
	}
};

//----------------------------------------------------------------------
class UInt32 : public Number, public Data<uint32_t>
//----------------------------------------------------------------------
{
public:
	using D = uint32_t;

	static inline const Ptr mut_(const D& data = D())
	{
		return make_<UInt32>(data);
	}

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<UInt32>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<UInt32>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<UInt32>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
	{
		return rwl_(it->next_());
	}

	inline UInt32(const D& data)
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
		static const Ptr PUB = _public_(UInt32::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&UInt32::type_name));
			shoal->update_("category", Static::fin_(&UInt32::category));
			shoal->update_("categories", Static::fin_(&UInt32::categories));
			shoal->update_("to_lake", Const<UInt32>::fin_(&UInt32::to_lake));
			shoal->update_("from_lake", Member<UInt32>::fin_(&UInt32::from_lake, "lake"));
			shoal->update_("to_river", Const<UInt32>::fin_(&UInt32::to_river, "river"));
			shoal->update_("from_river", Member<UInt32>::fin_(&UInt32::from_river, "river"));
			shoal->update_("mut", Static::fin_(&UInt32::mut));
			shoal->update_("fin", Static::fin_(&UInt32::fin));
			shoal->update_("lak", Static::fin_(&UInt32::lak, "lake"));
			shoal->update_("riv", Static::fin_(&UInt32::riv, "river"));
			shoal->update_("rwl", Static::fin_(&UInt32::rwl, "river"));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::UInt32", Static::fin_(&UInt32::creator_));
		s->update_("strange::UInt32::mut", Static::fin_(&UInt32::mut));
		s->update_("strange::UInt32::fin", Static::fin_(&UInt32::fin));
		s->update_("strange::UInt32::lak", Static::fin_(&UInt32::lak, "lake"));
		s->update_("strange::UInt32::riv", Static::fin_(&UInt32::riv, "river"));
		s->update_("strange::UInt32::rwl", Static::fin_(&UInt32::rwl, "river"));
	}

	virtual inline const Ptr to_lake_() const override
	{
		std::string str(4, 0);
		str[0] = get_() & 0xFF;
		str[1] = (get_() >> 8) & 0xFF;
		str[2] = (get_() >> 16) & 0xFF;
		str[3] = (get_() >> 24) & 0xFF;
		const Ptr lake = Lake::mut_(str);
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("UInt32::from_lake_ passed wrong category of thing");
		}
		set_(
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[3]))) << 24
		);
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::UInt32");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return UInt32::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return UInt32::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(UInt32::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return UInt32::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return UInt32::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(UInt32::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return UInt32::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return UInt32::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoull(symbol->get_())));
		}
		else
		{
			throw Disagreement("strange::UInt32::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		++ref_();
	}

	virtual inline void decrement_() override
	{
		--ref_();
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() + number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::UInt32::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() - number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::UInt32::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_int64_(to_int64_() * number->to_int64_());
		}
		else
		{
			throw Disagreement("strange::UInt32::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0 && divisor != 1)
			{
				from_int64_(to_int64_() / divisor);
			}
		}
		else
		{
			throw Disagreement("strange::UInt32::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0)
			{
				from_int64_(to_int64_() % divisor);
			}
		}
		else
		{
			throw Disagreement("strange::UInt32::self_modulo_ passed invalid Number");
		}
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (to_int64_() == number->to_int64_());
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<int64_t>()(to_int64_());
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() < number->to_int64_();
		}
		throw Disagreement("strange::UInt32::less_than_ passed invalid Number");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() > number->to_int64_();
		}
		throw Disagreement("strange::UInt32::greater_than_ passed invalid Number");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() <= number->to_int64_();
		}
		throw Disagreement("strange::UInt32::less_or_equal_ passed invalid Number");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_int64_() >= number->to_int64_();
		}
		throw Disagreement("strange::UInt32::greater_or_equal_ passed invalid Number");
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

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Int64>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Int64>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Int64>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
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
		static const Ptr PUB = _public_(Int64::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Int64::type_name));
			shoal->update_("category", Static::fin_(&Int64::category));
			shoal->update_("categories", Static::fin_(&Int64::categories));
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
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Int64", Static::fin_(&Int64::creator_));
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
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("Int64::from_lake_ passed wrong category of thing");
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
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Int64");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Int64::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Int64::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Int64::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Int64::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Int64::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(Int64::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Int64::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Int64::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoll(symbol->get_())));
		}
		else
		{
			throw Disagreement("strange::Int64::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		++ref_();
	}

	virtual inline void decrement_() override
	{
		--ref_();
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			ref_() += number->to_int64_();
		}
		else
		{
			throw Disagreement("strange::Int64::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			ref_() -= number->to_int64_();
		}
		else
		{
			throw Disagreement("strange::Int64::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			ref_() *= number->to_int64_();
		}
		else
		{
			throw Disagreement("strange::Int64::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0 && divisor != 1)
			{
				ref_() /= divisor;
			}
		}
		else
		{
			throw Disagreement("strange::Int64::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t divisor = number->to_int64_();
			if (divisor != 0)
			{
				ref_() %= divisor;
			}
		}
		else
		{
			throw Disagreement("strange::Int64::self_modulo_ passed invalid Number");
		}
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (get_() == number->to_int64_());
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<int64_t>()(get_());
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return get_() < number->to_int64_();
		}
		throw Disagreement("strange::Int64::less_than_ passed invalid Number");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return get_() > number->to_int64_();
		}
		throw Disagreement("strange::Int64::greater_than_ passed invalid Number");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return get_() <= number->to_int64_();
		}
		throw Disagreement("strange::Int64::less_or_equal_ passed invalid Number");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return get_() >= number->to_int64_();
		}
		throw Disagreement("strange::Int64::greater_or_equal_ passed invalid Number");
	}
};

//----------------------------------------------------------------------
class UInt64 : public Number, public Data<uint64_t>
//----------------------------------------------------------------------
{
public:
	using D = uint64_t;

	static inline const Ptr mut_(const D& data = D())
	{
		return make_<UInt64>(data);
	}

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<UInt64>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<UInt64>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<UInt64>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
	{
		return rwl_(it->next_());
	}

	inline UInt64(const D& data)
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
		static const Ptr PUB = _public_(UInt64::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&UInt64::type_name));
			shoal->update_("category", Static::fin_(&UInt64::category));
			shoal->update_("categories", Static::fin_(&UInt64::categories));
			shoal->update_("to_lake", Const<UInt64>::fin_(&UInt64::to_lake));
			shoal->update_("from_lake", Member<UInt64>::fin_(&UInt64::from_lake, "lake"));
			shoal->update_("to_river", Const<UInt64>::fin_(&UInt64::to_river, "river"));
			shoal->update_("from_river", Member<UInt64>::fin_(&UInt64::from_river, "river"));
			shoal->update_("mut", Static::fin_(&UInt64::mut));
			shoal->update_("fin", Static::fin_(&UInt64::fin));
			shoal->update_("lak", Static::fin_(&UInt64::lak, "lake"));
			shoal->update_("riv", Static::fin_(&UInt64::riv, "river"));
			shoal->update_("rwl", Static::fin_(&UInt64::rwl, "river"));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::UInt64", Static::fin_(&UInt64::creator_));
		s->update_("strange::UInt64::mut", Static::fin_(&UInt64::mut));
		s->update_("strange::UInt64::fin", Static::fin_(&UInt64::fin));
		s->update_("strange::UInt64::lak", Static::fin_(&UInt64::lak, "lake"));
		s->update_("strange::UInt64::riv", Static::fin_(&UInt64::riv, "river"));
		s->update_("strange::UInt64::rwl", Static::fin_(&UInt64::rwl, "river"));
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
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("UInt64::from_lake_ passed wrong category of thing");
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
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::UInt64");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return UInt64::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return UInt64::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(UInt64::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return UInt64::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return UInt64::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(UInt64::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return UInt64::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return UInt64::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(D(std::stoull(symbol->get_())));
		}
		else
		{
			throw Disagreement("strange::UInt64::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		++ref_();
	}

	virtual inline void decrement_() override
	{
		--ref_();
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto uint64 = dynamic_<UInt64>(other);
		if (uint64)
		{
			ref_() += uint64->get_();
		}
		else
		{
			const auto number = dynamic_<Number>(other);
			if (number)
			{
				ref_() += number->to_int64_();
			}
			else
			{
				throw Disagreement("strange::UInt64::self_add_ passed invalid Number");
			}
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto uint64 = dynamic_<UInt64>(other);
		if (uint64)
		{
			ref_() -= uint64->get_();
		}
		else
		{
			const auto number = dynamic_<Number>(other);
			if (number)
			{
				ref_() -= number->to_int64_();
			}
			else
			{
				throw Disagreement("strange::UInt64::self_subtract_ passed invalid Number");
			}
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto uint64 = dynamic_<UInt64>(other);
		if (uint64)
		{
			ref_() *= uint64->get_();
		}
		else
		{
			const auto number = dynamic_<Number>(other);
			if (number)
			{
				ref_() *= number->to_int64_();
			}
			else
			{
				throw Disagreement("strange::UInt64::self_multiply_ passed invalid Number");
			}
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto uint64 = dynamic_<UInt64>(other);
		if (uint64)
		{
			const D divisor = uint64->get_();
			if (divisor != 0 && divisor != 1)
			{
				ref_() /= divisor;
			}
		}
		else
		{
			const auto number = dynamic_<Number>(other);
			if (number)
			{
				const int64_t divisor = number->to_int64_();
				if (divisor != 0 && divisor != 1)
				{
					ref_() /= divisor;
				}
			}
			else
			{
				throw Disagreement("strange::UInt64::self_divide_ passed invalid Number");
			}
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		const auto uint64 = dynamic_<UInt64>(other);
		if (uint64)
		{
			const D divisor = uint64->get_();
			if (divisor != 0 && divisor != 1)
			{
				ref_() %= divisor;
			}
		}
		else
		{
			const auto number = dynamic_<Number>(other);
			if (number)
			{
				const int64_t divisor = number->to_int64_();
				if (divisor != 0)
				{
					ref_() %= divisor;
				}
			}
			else
			{
				throw Disagreement("strange::UInt64::self_modulo_ passed invalid Number");
			}
		}
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto uint64 = dynamic_<UInt64>(other);
		if (uint64)
		{
			return get_() == uint64->get_();
		}
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t int64 = number->to_int64_();
			return int64 >= 0 && get_() == D(int64);
		}
		return false;
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<int64_t>()(get_());
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		const auto uint64 = dynamic_<UInt64>(other);
		if (uint64)
		{
			return (get_() < uint64->get_());
		}
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t int64 = number->to_int64_();
			return int64 > 0 && get_() < D(int64);
		}
		throw Disagreement("strange::UInt64::less_than_ passed invalid Number");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		const auto uint64 = dynamic_<UInt64>(other);
		if (uint64)
		{
			return (get_() > uint64->get_());
		}
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t int64 = number->to_int64_();
			return int64 < 0 || get_() > D(int64);
		}
		throw Disagreement("strange::UInt64::greater_than_ passed invalid Number");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		const auto uint64 = dynamic_<UInt64>(other);
		if (uint64)
		{
			return (get_() <= uint64->get_());
		}
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t int64 = number->to_int64_();
			return int64 >= 0 && get_() <= D(int64);
		}
		throw Disagreement("strange::UInt64::less_or_equal_ passed invalid Number");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		const auto uint64 = dynamic_<UInt64>(other);
		if (uint64)
		{
			return (get_() >= uint64->get_());
		}
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const int64_t int64 = number->to_int64_();
			return int64 <= 0 || get_() >= D(int64);
		}
		throw Disagreement("strange::UInt64::greater_or_equal_ passed invalid Number");
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

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Float32>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Float32>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Float32>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
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
		static const Ptr PUB = _public_(Float32::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Float32::type_name));
			shoal->update_("category", Static::fin_(&Float32::category));
			shoal->update_("categories", Static::fin_(&Float32::categories));
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
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Float32", Static::fin_(&Float32::creator_));
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
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("Float32::from_lake_ passed wrong category of thing");
		}
		const uint32_t i =
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[0]))) |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const uint8_t*>(&(lak->get_()[3]))) << 24;
		set_(*reinterpret_cast<const float*>(&i));
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Float32");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Float32::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Float32::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Float32::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Float32::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Float32::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(Float32::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Float32::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Float32::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(std::stof(symbol->get_()));
		}
		else
		{
			throw Disagreement("strange::Float32::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		from_int64_(to_int64_() + 1);
	}

	virtual inline void decrement_() override
	{
		from_int64_(to_int64_() - 1);
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_float64_(to_float64_() + number->to_float64_());
		}
		else
		{
			throw Disagreement("strange::Float32::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_float64_(to_float64_() - number->to_float64_());
		}
		else
		{
			throw Disagreement("strange::Float32::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_float64_(to_float64_() * number->to_float64_());
		}
		else
		{
			throw Disagreement("strange::Float32::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const double divisor = number->to_float64_();
			if (std::isnormal(divisor))
			{
				from_float64_(to_float64_() / divisor);
			}
		}
		else
		{
			throw Disagreement("strange::Float32::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const double divisor = number->to_float64_();
			if (std::isnormal(divisor))
			{
				from_float64_(std::fmod(to_float64_(), divisor));
			}
		}
		else
		{
			throw Disagreement("strange::Float32::self_modulo_ passed invalid Number");
		}
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (to_float64_() == number->to_float64_());
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<double>()(to_float64_());
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_float64_() < number->to_float64_();
		}
		throw Disagreement("strange::Float32::less_than_ passed invalid Number");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_float64_() > number->to_float64_();
		}
		throw Disagreement("strange::Float32::greater_than_ passed invalid Number");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_float64_() <= number->to_float64_();
		}
		throw Disagreement("strange::Float32::less_or_equal_ passed invalid Number");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return to_float64_() >= number->to_float64_();
		}
		throw Disagreement("strange::Float32::greater_or_equal_ passed invalid Number");
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

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Float64>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Float64>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Float64>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
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
		static const Ptr PUB = _public_(Float64::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Float64::type_name));
			shoal->update_("category", Static::fin_(&Float64::category));
			shoal->update_("categories", Static::fin_(&Float64::categories));
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
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Float64", Static::fin_(&Float64::creator_));
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
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("Float64::from_lake_ passed wrong category of thing");
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
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Float64");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Float64::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Float64::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Float64::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Float64::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Float64::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(Float64::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Float64::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Float64::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			set_(std::stod(symbol->get_()));
		}
		else
		{
			throw Disagreement("strange::Float64::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		from_int64_(to_int64_() + 1);
	}

	virtual inline void decrement_() override
	{
		from_int64_(to_int64_() - 1);
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			ref_() += number->to_float64_();
		}
		else
		{
			throw Disagreement("strange::Float64::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			ref_() -= number->to_float64_();
		}
		else
		{
			throw Disagreement("strange::Float64::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			ref_() *= number->to_float64_();
		}
		else
		{
			throw Disagreement("strange::Float64::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const double divisor = number->to_float64_();
			if (std::isnormal(divisor))
			{
				ref_() /= divisor;
			}
		}
		else
		{
			throw Disagreement("strange::Float64::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			const double divisor = number->to_float64_();
			if (std::isnormal(divisor))
			{
				double& d = ref_();
				d = std::fmod(d, divisor);
			}
		}
		else
		{
			throw Disagreement("strange::Float64::self_modulo_ passed invalid Number");
		}
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (get_() == number->to_float64_());
	}

	virtual inline std::size_t hash_() const override
	{
		return std::hash<double>()(get_());
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return get_() < number->to_float64_();
		}
		throw Disagreement("strange::Float64::less_than_ passed invalid Number");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return get_() > number->to_float64_();
		}
		throw Disagreement("strange::Float64::greater_than_ passed invalid Number");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return get_() <= number->to_float64_();
		}
		throw Disagreement("strange::Float64::less_or_equal_ passed invalid Number");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			return get_() >= number->to_float64_();
		}
		throw Disagreement("strange::Float64::greater_or_equal_ passed invalid Number");
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

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Complex32>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Complex32>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Complex32>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
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
		static const Ptr PUB = _public_(Complex32::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("self_modulo", nothing_());
			shoal->update_("less_than", nothing_());
			shoal->update_("greater_than", nothing_());
			shoal->update_("less_or_equal", nothing_());
			shoal->update_("greater_or_equal", nothing_());
			shoal->update_("type_name", Static::fin_(&Complex32::type_name));
			shoal->update_("category", Static::fin_(&Complex32::category));
			shoal->update_("categories", Static::fin_(&Complex32::categories));
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
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Complex32", Static::fin_(&Complex32::creator_));
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
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("Complex32::from_lake_ passed wrong category of thing");
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
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Complex32");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Complex32::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Complex32::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Complex32::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Complex32::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Complex32::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(Complex32::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Complex32::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Complex32::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			std::stringstream str(symbol->get_());
			std::string first;
			std::string second;
			std::getline(str, first, delim);
			std::getline(str, second, delim);
			set_(D(std::stof(first), std::stof(second)));
		}
		else
		{
			throw Disagreement("strange::Complex32::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		from_int64_(to_int64_() + 1);
	}

	virtual inline void decrement_() override
	{
		from_int64_(to_int64_() - 1);
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_complex64_(to_complex64_() + number->to_complex64_());
		}
		else
		{
			throw Disagreement("strange::Complex32::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_complex64_(to_complex64_() - number->to_complex64_());
		}
		else
		{
			throw Disagreement("strange::Complex32::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_complex64_(to_complex64_() * number->to_complex64_());
		}
		else
		{
			throw Disagreement("strange::Complex32::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			from_complex64_(to_complex64_() / number->to_complex64_());
		}
		else
		{
			throw Disagreement("strange::Complex32::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		throw Disagreement("strange::Complex32::self_modulo_ called");
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (to_complex64_() == number->to_complex64_());
	}

	virtual inline std::size_t hash_() const override
	{
		const std::complex<double> c = to_complex64_();
		const std::size_t i = std::hash<double>()(c.imag());
		const std::size_t s = sizeof(i) * 4;
		return std::hash<double>()(c.real()) ^ ((i << s) | (i >> s));
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		throw Disagreement("strange::Complex32::less_than_ called");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		throw Disagreement("strange::Complex32::greater_than_ called");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		throw Disagreement("strange::Complex32::less_or_equal_ called");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		throw Disagreement("strange::Complex32::greater_or_equal_ called");
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

	static inline const Ptr mut(const Ptr& ignore)
	{
		return mut_();
	}

	static inline const Ptr fin_(const D& data = D())
	{
		const Ptr result = mut_(data);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& ignore)
	{
		return fin_();
	}

	static inline const Ptr lak_(const Ptr& lake)
	{
		const Ptr ptr = mut_();
		static_<Complex64>(ptr)->from_lake_(lake);
		return ptr;
	}

	static inline const Ptr lak(const Ptr& it)
	{
		return lak_(it->next_());
	}

	static inline const Ptr riv_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Complex64>(ptr)->from_river_(river);
		return ptr;
	}

	static inline const Ptr riv(const Ptr& it)
	{
		return riv_(it->next_());
	}

	static inline const Ptr rwl_(const Ptr& river)
	{
		const Ptr ptr = mut_();
		static_<Complex64>(ptr)->from_river_with_links_(river);
		return ptr;
	}

	static inline const Ptr rwl(const Ptr& it)
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
		static const Ptr PUB = _public_(Complex64::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("self_modulo", nothing_());
			shoal->update_("less_than", nothing_());
			shoal->update_("greater_than", nothing_());
			shoal->update_("less_or_equal", nothing_());
			shoal->update_("greater_or_equal", nothing_());
			shoal->update_("type_name", Static::fin_(&Complex64::type_name));
			shoal->update_("category", Static::fin_(&Complex64::category));
			shoal->update_("categories", Static::fin_(&Complex64::categories));
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
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Complex64", Static::fin_(&Complex64::creator_));
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
		if (final_())
		{
			lake->finalize_();
		}
		return lake;
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const auto lak = dynamic_<Lake>(lake);
		if (!lak)
		{
			throw Disagreement("Complex64::from_lake_ passed wrong category of thing");
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
		if (lak->final_())
		{
			finalize_();
		}
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Complex64");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Complex64::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Complex64::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Complex64::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Complex64::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Complex64::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Number::categories_()->copy_());
			categories->insert_(Complex64::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Complex64::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Complex64::categories_();
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

	virtual inline void from_symbol_(const Ptr& ptr) override
	{
		const auto symbol = dynamic_<Symbol>(ptr);
		if (symbol)
		{
			std::stringstream str(symbol->get_());
			std::string first;
			std::string second;
			std::getline(str, first, delim);
			std::getline(str, second, delim);
			set_(D(std::stod(first), std::stod(second)));
		}
		else
		{
			throw Disagreement("strange::Complex64::from_symbol_ passed invalid Symbol");
		}
	}

	virtual inline void increment_() override
	{
		from_int64_(to_int64_() + 1);
	}

	virtual inline void decrement_() override
	{
		from_int64_(to_int64_() - 1);
	}

	virtual inline void self_add_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			ref_() += number->to_complex64_();
		}
		else
		{
			throw Disagreement("strange::Complex64::self_add_ passed invalid Number");
		}
	}

	virtual inline void self_subtract_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			ref_() -= number->to_complex64_();
		}
		else
		{
			throw Disagreement("strange::Complex64::self_subtract_ passed invalid Number");
		}
	}

	virtual inline void self_multiply_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			ref_() *= number->to_complex64_();
		}
		else
		{
			throw Disagreement("strange::Complex64::self_multiply_ passed invalid Number");
		}
	}

	virtual inline void self_divide_(const Ptr& other) override
	{
		const auto number = dynamic_<Number>(other);
		if (number)
		{
			ref_() /= number->to_complex64_();
		}
		else
		{
			throw Disagreement("strange::Complex64::self_divide_ passed invalid Number");
		}
	}

	virtual inline void self_modulo_(const Ptr& other) override
	{
		throw Disagreement("strange::Complex64::self_modulo_ called");
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const auto number = dynamic_<Number>(other);
		return number && (get_() == number->to_complex64_());
	}

	virtual inline std::size_t hash_() const override
	{
		const std::complex<double> c = get_();
		const std::size_t i = std::hash<double>()(c.imag());
		const std::size_t s = sizeof(i) * 4;
		return std::hash<double>()(c.real()) ^ ((i << s) | (i >> s));
	}

	virtual inline const bool less_than_(const Ptr& other) const override
	{
		throw Disagreement("strange::Complex64::less_than_ called");
	}

	virtual inline const bool greater_than_(const Ptr& other) const override
	{
		throw Disagreement("strange::Complex64::greater_than_ called");
	}

	virtual inline const bool less_or_equal_(const Ptr& other) const override
	{
		throw Disagreement("strange::Complex64::less_or_equal_ called");
	}

	virtual inline const bool greater_or_equal_(const Ptr& other) const override
	{
		throw Disagreement("strange::Complex64::greater_or_equal_ called");
	}
};

//----------------------------------------------------------------------
class River : public Stateful
//----------------------------------------------------------------------
{
	using const_std_unique_ios_base = const std::unique_ptr<std::ios_base>;

public:
	inline River(std::ios_base* const stream, const bool del, const Ptr& filename = nothing_())
		: Stateful{}
		, _stream{ del ? stream : 0 }
		, _in{ dynamic_cast<std::istream*>(stream) }
		, _out{ dynamic_cast<std::ostream*>(stream) }
		, _filename{ filename }
	{
	}

	static inline const Ptr mut_(std::ios_base* const stream, const bool del, const Ptr& filename = nothing_())
	{
		return make_<River>(stream, del, filename);
	}

	static inline const Ptr mut_(const std::string& str = std::string(), const bool file = false)
	{
		if (file)
		{
			return mut_(new std::fstream(str, std::fstream::binary | std::fstream::in | std::fstream::out), true, sym_(str));
		}
		return mut_(new std::stringstream(str), true);
	}

	static inline const Ptr mut(const Ptr& it)
	{
		const Ptr str = it->next_();
		if (str->is_stop_())
		{
			return mut_();
		}
		const Ptr str_to_lake = str->invoke_("to_lake");
		const auto lake = dynamic_<Lake>(str_to_lake);
		if (!lake)
		{
			return mut_();
		}
		const Ptr file = it->next_();
		if (file->is_stop_())
		{
			return mut_(lake->get_());
		}
		return mut_(lake->get_(), !file->is_nothing_());
	}

	static inline const Ptr in_()
	{
		return make_<River>(&std::cin, false);
	}

	static inline const Ptr in(const Ptr& ignore)
	{
		return in_();
	}

	static inline const Ptr out_()
	{
		return make_<River>(&std::cout, false);
	}

	static inline const Ptr out(const Ptr& ignore)
	{
		return out_();
	}

	static inline const Ptr err_()
	{
		return make_<River>(&std::cerr, false);
	}

	static inline const Ptr err(const Ptr& ignore)
	{
		return err_();
	}

	inline const Ptr to_lake_() const
	{
		std::stringstream* const str = dynamic_cast<std::stringstream*>(_stream.get());
		if (str)
		{
			return Lake::mut_(str->str());
		}
		return Lake::mut_();
	}

	inline const Ptr to_lake(const Ptr& ignore) const
	{
		return to_lake_();
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = _public_(River::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Number::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&River::type_name));
			shoal->update_("category", Static::fin_(&River::category));
			shoal->update_("categories", Static::fin_(&River::categories));
			shoal->update_("mut", Static::fin_(&River::mut, "lake", "is_file"));
			shoal->update_("in", Static::fin_(&River::in));
			shoal->update_("out", Static::fin_(&River::out));
			shoal->update_("err", Static::fin_(&River::err));
			shoal->update_("filename", Const<River>::fin_(&River::filename));
			shoal->update_("push_back", Member<River>::fin_(&River::push_back, "thing"));
			shoal->update_("write", Member<River>::fin_(&River::write, "thing"));
			shoal->update_("pop_front", Member<River>::fin_(&River::pop_front));
			shoal->update_("good", Const<River>::fin_(&River::good));
			shoal->update_("get", Member<River>::fin_(&River::get));
			shoal->update_("peek", Member<River>::fin_(&River::peek));
			shoal->update_("to_lake", Const<River>::fin_(&River::to_lake));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::River", Static::fin_(&River::creator_));
		s->update_("strange::River::mut", Static::fin_(&River::mut, "lake", "is_file"));
		s->update_("strange::River::in", Static::fin_(&River::in));
		s->update_("strange::River::out", Static::fin_(&River::out));
		s->update_("strange::River::err", Static::fin_(&River::err));
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::River");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return River::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return River::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(River::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return River::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return River::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Stateful::categories_()->copy_());
			categories->insert_(River::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return River::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return River::categories_();
	}

	inline const Ptr filename_() const
	{
		return _filename;
	}

	inline const Ptr filename(const Ptr& ignore) const
	{
		return filename_();
	}

	inline const bool push_back_(const Ptr& ptr)
	{
		const Ptr type = ptr->type_();
		write_(Int16::mut_(int16_t(static_<Symbol>(type)->get_().length())));
		write_(type);
		ptr->invoke_("to_river", me_());
		return true;
	}

	inline const Ptr push_back(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			push_back_(i);
		}
		return me_();
	}

	inline const bool push_back_with_links_(const Ptr& ptr, const Ptr& shoal)
	{
		const Ptr type = ptr->type_();
		write_(Int16::mut_(int16_t(static_<Symbol>(type)->get_().length())));
		write_(type);
		ptr->invoke_("to_river_with_links", shoal, me_());
		return true;
	}

	inline void write_(const std::string& str)
	{
		if (!_out)
		{
			throw Disagreement("strange::River::write_ cannot write to input");
		}
		_out->write(str.data(), str.length());
	}

	inline void write_(const Ptr& ptr)
	{
		const Ptr ptr_to_lake = ptr->invoke_("to_lake");
		const auto lake = dynamic_<Lake>(ptr_to_lake);
		if (lake)
		{
			write_(lake->get_());
		}
		else
		{
			throw Disagreement("strange::River::write_ passed wrong category of thing");
		}
	}

	inline const Ptr write(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			write_(i);
		}
		return me_();
	}

	inline const Ptr pop_front_()
	{
		const int16_t int16 = read_<Int16>();
		const std::string type = static_<Lake>(read_(int16))->get_();
		return call_(type + "::riv", me_());
	}

	inline const Ptr pop_front(const Ptr& ignore)
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
		if (!_in)
		{
			throw Disagreement("strange::River::read_ cannot read from output");
		}
		std::string str;
		str.resize(std::size_t(length));
		_in->read(&str[0], str.length());
		return Lake::mut_(str);
	}

	template <typename T>
	inline const typename T::D read_()
	{
		return static_<T>(T::lak_(read_(int64_t(sizeof(T::D)))))->get_();
	}

	inline const bool good_() const
	{
		if (_in)
		{
			return _in->good();
		}
		if (_out)
		{
			return _out->good();
		}
		return false;
	}

	inline const Ptr good(const Ptr& ignore) const
	{
		return boolean_(good_());
	}

	inline const int get_()
	{
		if (!_in)
		{
			throw Disagreement("strange::River::get_ cannot read from output");
		}
		return _in->get();
	}

	inline const Ptr get(const Ptr& ignore)
	{
		return Int8::fin_(get_());
	}

	inline const int peek_()
	{
		if (!_in)
		{
			throw Disagreement("strange::River::peek_ cannot read from output");
		}
		return _in->peek();
	}

	inline const Ptr peek(const Ptr& ignore)
	{
		return Int8::fin_(peek_());
	}

private:
	const_std_unique_ios_base _stream;
	std::istream* const _in;
	std::ostream* const _out;
	const Ptr _filename;
};

//======================================================================
// class Thing
//======================================================================

inline const Thing::Ptr Thing::iterator_() const
{
	return IteratorPtr::mut_(me_());
}

inline const bool Thing::is_(const std::string& str) const
{
	const Symbol* const symbol = dynamic_cast<const Symbol*>(this);
	return symbol && (symbol->get_() == str);
}

inline const bool Thing::is_(const Ptr& symbol) const
{
	const auto sym = dynamic_<Symbol>(symbol);
	return sym && is_(sym->get_());
}

template <typename F>
inline const Thing::Ptr Thing::sym_(F&& symbol)
{
	return Symbol::fin_(std::forward<F>(symbol));
}

inline const Thing::Ptr Thing::call(const Ptr& it)
{
	const Ptr function = it->next_();
	const Ptr fun = static_<Shoal>(shared_())->at_(function);
	if (fun->is_nothing_())
	{
		throw Dismemberment(nothing_(), function);
	}
	return fun->invoke(it);
}

inline const Thing::Ptr Thing::creator_(const Ptr& ignore)
{
	static const Ptr CREATION = []()
	{
		const auto shoal = static_<Shoal>(Shoal::mut_());
		shoal->update_("invoke", Member<Thing>::fin_(&Thing::invoke, "member", ".."));
		shoal->update_("iterator", Const<Thing>::fin_(&Thing::iterator));
		shoal->update_("next", Member<Thing>::fin_(&Thing::next));
		shoal->update_("is", Const<Thing>::fin_(&Thing::is, "symbol"));
		shoal->update_("is_not", Const<Thing>::fin_(&Thing::is_not, "symbol"));
		shoal->update_("is_nothing", Const<Thing>::fin_(&Thing::is_nothing));
		shoal->update_("is_not_nothing", Const<Thing>::fin_(&Thing::is_not_nothing));
		shoal->update_("is_stop", Const<Thing>::fin_(&Thing::is_stop));
		shoal->update_("is_not_stop", Const<Thing>::fin_(&Thing::is_not_stop));
		shoal->update_("and", Const<Thing>::fin_(&Thing::and_op, "other", ".."));
		shoal->update_("or", Const<Thing>::fin_(&Thing::or_op, "other", ".."));
		shoal->update_("xor", Const<Thing>::fin_(&Thing::xor_op, "other", ".."));
		shoal->update_("nand", Const<Thing>::fin_(&Thing::nand_op, "other", ".."));
		shoal->update_("nor", Const<Thing>::fin_(&Thing::nor_op, "other", ".."));
		shoal->update_("xnor", Const<Thing>::fin_(&Thing::xnor_op, "other", ".."));
		shoal->update_("hash", Const<Thing>::fin_(&Thing::hash));
		shoal->update_("same", Const<Thing>::fin_(&Thing::same, "other"));
		shoal->update_("different", Const<Thing>::fin_(&Thing::different, "other"));
		shoal->update_("finalize", Const<Thing>::fin_(&Thing::finalize));
		shoal->update_("final", Const<Thing>::fin_(&Thing::final));
		shoal->update_("freeze", Const<Thing>::fin_(&Thing::freeze));
		shoal->update_("frozen", Const<Thing>::fin_(&Thing::frozen));
		shoal->update_("copy", Const<Thing>::fin_(&Thing::copy));
		shoal->update_("clone", Const<Thing>::fin_(&Thing::clone));
		shoal->update_("copy_finalize", Const<Thing>::fin_(&Thing::copy_finalize));
		shoal->update_("clone_freeze", Const<Thing>::fin_(&Thing::clone_freeze));
		shoal->update_("replicate", Const<Thing>::fin_(&Thing::replicate));
		shoal->update_("call", Static::fin_(&Thing::call, "function", ".."));
		shoal->update_("type", Const<Thing>::fin_(&Thing::type));
		shoal->update_("cat", Const<Thing>::fin_(&Thing::cat));
		shoal->update_("cats", Const<Thing>::fin_(&Thing::cats));
		shoal->update_("visit", Member<Thing>::fin_(&Thing::visit, "visitor", "member", ".."));
		shoal->update_("pub", Const<Thing>::fin_(&Thing::pub));
		shoal->finalize_();
		return shoal;
	}();
	return CREATION;
}

inline const Thing::Ptr Thing::operator()(Thing* const thing, const Ptr& it)
{
	const Ptr name = it->next_();
	const Ptr member = static_<Shoal>(thing->pub_())->at_(name);
	if (member->is_nothing_())
	{
		throw Dismemberment(thing->cat_(), name);
	}
	return operate_(thing, member, it);
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

inline const Thing::Ptr Thing::identity(const Ptr& ignore) const
{
	return Int64::mut_(identity_());
}

inline const Thing::Ptr Thing::hash(const Ptr& ignore) const
{
	return Int64::mut_(int64_t(hash_()));
}

inline const Thing::Ptr Thing::category_()
{
	static const Ptr CATEGORY = Cat::fin_(Thing::type_name_());
	return CATEGORY;
}

inline const Thing::Ptr Thing::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Herd::mut_());
		categories->insert_(Cat::fin_());
		categories->insert_(Thing::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

inline const Thing::Ptr& Thing::shared_()
{
	static const Ptr SHARED = []()
	{
		const Ptr shoal = Shoal::mut_();
		share_(shoal);
		return shoal;
	}();
	return SHARED;
}

inline const Thing::Ptr Thing::_public_(const Ptr& creation)
{
	const auto result = static_<Shoal>(Shoal::mut_());
	const Ptr it = creation->iterator_();
	for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
	{
		const auto flock = static_<Flock>(i);
		const auto symbol = dynamic_<Symbol>(flock->at_(0));
		if (symbol && symbol->get_()[0] != '_')
		{
			result->update_(symbol, flock->at_(1));
		}
	}
	result->finalize_();
	return result;
}

inline Thing::Dismemberment::Dismemberment(const Ptr& type, const Ptr& member)
	:Disagreement("Dismemberment "
		+ (dynamic_<Symbol>(type) ? static_<Symbol>(type)->get_() : std::string("[UNKNOWN]")) + "."
		+ (dynamic_<Symbol>(member) ? static_<Symbol>(member)->get_() : std::string("[UNKNOWN]")))
{
}

inline Thing::Mutilation::Mutilation(const Ptr& cat)
	:Disagreement("Mutilation "
		+ (dynamic_<Symbol>(cat) ? static_<Symbol>(cat)->get_() : std::string("[UNKNOWN]")))
{
}

//======================================================================
// class Variadic
//======================================================================

//======================================================================
// class Serializable
//======================================================================

inline void Serializable::serialize_(const Thing::Ptr& thing, const Thing::Ptr& river)
{
	Thing::static_<Shoal>(Shoal::mut_())->gather_to_river_(thing, river);
}

inline const Thing::Ptr Serializable::deserialize_(const Thing::Ptr& river)
{
	return Thing::static_<Shoal>(Shoal::mut_())->gather_from_river_(river);
}

inline void Serializable::to_river_(const Thing::Ptr& river) const
{
	const Thing::Ptr to_lake = to_lake_();
	const auto lake = Thing::dynamic_<Lake>(to_lake);
	if (lake)
	{
		lake->to_river_(river);
	}
	else
	{
		throw Thing::Disagreement("Serializable::to_river_ passed wrong category of thing");
	}
}

inline void Serializable::from_river_(const Thing::Ptr& river)
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

inline void Serializable::from_lake_via_river_(const Thing::Ptr& lake)
{
	const auto lak = Thing::dynamic_<Lake>(lake);
	if (!lak)
	{
		throw Thing::Disagreement("Serializable::from_lake_via_river_ passed wrong category of thing");
	}
	const Thing::Ptr river = River::mut_();
	lak->to_river_(river);
	from_river_(river);
}

inline const Thing::Ptr Serializable::category_()
{
	static const Thing::Ptr CATEGORY = Cat::fin_(Serializable::type_name_());
	return CATEGORY;
}

inline const Thing::Ptr Serializable::categories_()
{
	static const Thing::Ptr CATEGORIES = []()
	{
		const auto categories = Thing::static_<Herd>(Herd::mut_());
		categories->insert_(Serializable::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

//======================================================================
// class Symbol
//======================================================================

inline const bool Symbol::same_(const Ptr& other) const
{
	const auto symbol = dynamic_<Symbol>(other);
	if (symbol)
	{
		return get_() == symbol->get_();
	}
	const auto lake = dynamic_<Lake>(other);
	return lake && (get_() == lake->get_());
}

inline const bool Symbol::less_than_(const Ptr& other) const
{
	const auto symbol = dynamic_<Symbol>(other);
	if (symbol)
	{
		return get_() < symbol->get_();
	}
	const auto lake = dynamic_<Lake>(other);
	if (lake)
	{
		return get_() < lake->get_();
	}
	throw Disagreement("Symbol::less_than_ passed wrong category of thing");
}

inline const bool Symbol::greater_than_(const Ptr& other) const
{
	const auto symbol = dynamic_<Symbol>(other);
	if (symbol)
	{
		return get_() > symbol->get_();
	}
	const auto lake = dynamic_<Lake>(other);
	if (lake)
	{
		return get_() > lake->get_();
	}
	throw Disagreement("Symbol::greater_than_ passed wrong category of thing");
}

inline const bool Symbol::less_or_equal_(const Ptr& other) const
{
	const auto symbol = dynamic_<Symbol>(other);
	if (symbol)
	{
		return get_() <= symbol->get_();
	}
	const auto lake = dynamic_<Lake>(other);
	if (lake)
	{
		return get_() <= lake->get_();
	}
	throw Disagreement("Symbol::less_or_equal_ passed wrong category of thing");
}

inline const bool Symbol::greater_or_equal_(const Ptr& other) const
{
	const auto symbol = dynamic_<Symbol>(other);
	if (symbol)
	{
		return get_() >= symbol->get_();
	}
	const auto lake = dynamic_<Lake>(other);
	if (lake)
	{
		return get_() >= lake->get_();
	}
	throw Disagreement("Symbol::greater_or_equal_ passed wrong category of thing");
}

inline const Thing::Ptr Symbol::creator_(const Ptr& ignore)
{
	static const Ptr CREATION = []()
	{
		const auto shoal = static_<Shoal>(Thing::creator_()->copy_());
		shoal->update_("type_name", Static::fin_(&Symbol::type_name));
		shoal->update_("category", Static::fin_(&Symbol::category));
		shoal->update_("categories", Static::fin_(&Symbol::categories));
		shoal->update_("to_lake", Const<Symbol>::fin_(&Symbol::to_lake));
		shoal->update_("to_river", Const<Symbol>::fin_(&Symbol::to_river, "river"));
		shoal->update_("lak", Static::fin_(&Symbol::lak, "lake"));
		shoal->update_("riv", Static::fin_(&Symbol::riv, "river"));
		shoal->update_("rwl", Static::fin_(&Symbol::rwl, "river"));
		shoal->update_("add", Const<Symbol>::fin_(&Symbol::add, "symbol", ".."));
		shoal->update_("at", Const<Symbol>::fin_(&Symbol::at, "index"));
		shoal->update_("less_than", Const<Symbol>::fin_(&Symbol::less_than, "symbol"));
		shoal->update_("greater_than", Const<Symbol>::fin_(&Symbol::greater_than, "symbol"));
		shoal->update_("less_or_equal", Const<Symbol>::fin_(&Symbol::less_or_equal, "symbol"));
		shoal->update_("greater_or_equal", Const<Symbol>::fin_(&Symbol::greater_or_equal, "symbol"));
		shoal->finalize_();
		return shoal;
	}();
	return CREATION;
}

inline void Symbol::share_(const Ptr& shoal)
{
	const auto s = static_<Shoal>(shoal);
	s->update_("strange::Symbol", Static::fin_(&Symbol::creator_));
	s->update_("strange::Symbol::lak", Static::fin_(&Symbol::lak, "lake"));
	s->update_("strange::Symbol::riv", Static::fin_(&Symbol::riv, "river"));
	s->update_("strange::Symbol::rwl", Static::fin_(&Symbol::rwl, "river"));
}

inline const Thing::Ptr Symbol::lak_(const Ptr& lake)
{
	const auto lak = dynamic_<Lake>(lake);
	if (!lak)
	{
		throw Disagreement("Symbol::lak_ passed wrong category of thing");
	}
	return fin_(lak->get_());
}

inline const Thing::Ptr Symbol::riv_(const Ptr& river)
{
	return fin_(static_<Lake>(Lake::riv_(river))->get_());
}

inline const Thing::Ptr Symbol::rwl_(const Ptr& river)
{
	return fin_(static_<Lake>(Lake::rwl_(river))->get_());
}

inline const Thing::Ptr Symbol::to_lake_() const
{
	const Ptr lake = Lake::mut_(_symbol);
	lake->finalize_();
	return lake;
}

inline const Thing::Ptr Symbol::category_()
{
	static const Ptr CATEGORY = Cat::fin_(Symbol::type_name_());
	return CATEGORY;
}

inline const Thing::Ptr Symbol::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Thing::categories_()->copy_());
		categories->self_add_(Serializable::categories_());
		categories->insert_(Symbol::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

inline const Thing::Ptr Symbol::add_(const Ptr& other) const
{
	const auto symbol = dynamic_<Symbol>(other);
	if (symbol)
	{
		return add_(symbol->_symbol);
	}
	const auto lake = dynamic_<Lake>(other);
	if (lake)
	{
		return add_(lake->get_());
	}
	else
	{
		throw Disagreement("strange::Symbol::add_ passed invalid argument");
	}
	return me_();
}

inline const char Symbol::at_(const Ptr& index) const
{
	const auto ind = dynamic_<Number>(index);
	if (ind)
	{
		return at_(ind->to_int64_());
	}
	throw Disagreement("strange::Symbol::at_ passed wrong category of Number");
}

inline const Thing::Ptr Symbol::at(const Ptr& it) const
{
	return UInt8::mut_(at_(it->next_()));
}

//======================================================================
// class Cat
//======================================================================

inline const Thing::Ptr Cat::fin_(const Ptr& type_name_symbol)
{
	return fake_<Cat>(type_name_symbol, Flock::fin_(), Flock::fin_());
}

inline const Thing::Ptr Cat::fin_(const Ptr& type_name_symbol, const Ptr& arguments)
{
	return fake_<Cat>(type_name_symbol, arguments, Flock::fin_());
}

inline void Cat::share_(const Ptr& shoal)
{
	const auto s = static_<Shoal>(shoal);
	s->update_("strange::Cat", Static::fin_(&Cat::creator_));
}

inline const Thing::Ptr Cat::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Symbol::categories_()->copy_());
		categories->insert_(Cat::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

inline const Thing::Ptr Cat::creator_(const Ptr& thing)
{
	static const Ptr CREATION = []()
	{
		const auto shoal = static_<Shoal>(Symbol::creator_()->copy_());
		shoal->update_("type_name", Static::fin_(&Cat::type_name));
		shoal->update_("category", Static::fin_(&Cat::category));
		shoal->update_("categories", Static::fin_(&Cat::categories));
		shoal->finalize_();
		return shoal;
	}();
	return CREATION;
}

inline const bool Cat::check_(const Ptr& thing, const Ptr& cat)
{
	if (cat->is_("<>"))
	{
		return true;
	}
	const auto thing_cats = static_<Herd>(thing->cats_());
	const auto cat_herd = dynamic_<Herd>(cat);
	if (cat_herd)
	{
		for (const auto& item : cat_herd->get_())
		{
			const auto cat_item = dynamic_<Cat>(item);
			if (cat_item)
			{
				if (thing_cats->at_(cat_item))
				{
					return true;
				}
			}
			else if (cat_item->same_(thing))
			{
				return true;
			}
		}
		return false;
	}
	return thing_cats->at_(cat);
}

inline const std::string Cat::_hash_arg_(const Ptr& arg)
{
	return static_<Lake>(static_<UInt64>(UInt64::fin_(uint64_t(arg->hash_())))->to_lake_())->get_();
}

//======================================================================
// class Static
//======================================================================

inline const Thing::Ptr Static::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Thing::categories_()->copy_());
		categories->insert_(Static::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

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
// class Stateful
//======================================================================

inline const Thing::Ptr Stateful::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Thing::categories_()->copy_());
		categories->insert_(Stateful::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

//======================================================================
// class Shoal
//======================================================================

inline void Shoal::to_river_(const Ptr& river) const
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Shoal::to_river_ passed wrong category of thing");
	}
	riv->write_(Bit::mut_(final_()));
	riv->write_(Int64::mut_(int64_t(_map.size())));
	for (const auto& i : _map)
	{
		riv->push_back_(i.first);
		riv->push_back_(i.second);
	}
}

inline void Shoal::from_river_(const Ptr& river)
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Shoal::from_river_ passed wrong category of thing");
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

inline void Shoal::to_river_with_links_(const Ptr& shoal, const Ptr& river) const
{
	const auto sho = dynamic_<Shoal>(shoal);
	if (!sho)
	{
		throw Disagreement("Shoal::to_river_with_links_ passed wrong category of shoal thing");
	}
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Shoal::to_river_with_links_ passed wrong category of river thing");
	}
	riv->write_(Bit::mut_(final_()));
	riv->write_(Int64::mut_(int64_t(_map.size())));
	for (const auto& i : _map)
	{
		static_<Symbol>(sho->at_(i.first))->to_river_(river);
		static_<Symbol>(sho->at_(i.second))->to_river_(river);
	}
}

inline void Shoal::from_river_with_links_(const Ptr& river)
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Shoal::from_river_with_links_ passed wrong category of thing");
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

inline void Shoal::replace_links_(const Ptr& shoal)
{
	std_unordered_map_ptr_ptr replacement;
	const auto sho = static_<Shoal>(shoal);
	for (const auto& i : _map)
	{
		replacement.emplace(sho->at_(i.first), sho->at_(i.second));
	}
	_map.swap(replacement);
}

inline void Shoal::gather_to_river_(const Ptr& thing, const Ptr& river)
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Shoal::gather_to_river_ passed wrong category of river thing");
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

inline const Thing::Ptr Shoal::gather_from_river_(const Ptr& river)
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Shoal::gather_from_river_ passed wrong category of river thing");
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
	return at_(nothing_());
}

inline const Thing::Ptr Shoal::size(const Ptr& ignore) const
{
	return Int64::mut_(size_());
}

inline void Shoal::self_add_(const Ptr& other)
{
	const auto shoal = dynamic_<Shoal>(other);
	if (shoal)
	{
		if (&_map == &shoal->_map)
		{
			const std_unordered_map_ptr_ptr copy = _map;
			for (const auto& i : copy)
			{
				update_(i.first, i.second);
			}
		}
		else
		{
			for (const auto& i : shoal->_map)
			{
				update_(i.first, i.second);
			}
		}
	}
	else
	{
		const auto herd = dynamic_<Herd>(other);
		if (herd)
		{
			for (auto i : herd->get_())
			{
				update_(i, one_());
			}
		}
		else
		{
			const auto flock = dynamic_<Flock>(other);
			if (flock)
			{
				const Ptr index = Int64::mut_();
				const auto ind = static_<Int64>(index);
				for (auto i : flock->get_())
				{
					update_(ind->copy_(), i);
					ind->increment_();
				}
			}
			else
			{
				const Ptr index = Int64::mut_();
				const auto ind = static_<Int64>(index);
				const Ptr it = other->iterator_();
				for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
				{
					update_(ind->copy_(), i);
					ind->increment_();
				}
			}
		}
	}
}

inline void Shoal::self_subtract_(const Ptr& other)
{
	const auto shoal = dynamic_<Shoal>(other);
	if (shoal)
	{
		if (&_map == &shoal->_map)
		{
			clear_();
		}
		else
		{
			for (const auto& i : shoal->_map)
			{
				erase_(i.first);
			}
		}
	}
	else
	{
		const auto herd = dynamic_<Herd>(other);
		if (herd)
		{
			for (auto i : herd->get_())
			{
				erase_(i);
			}
		}
		else
		{
			const auto flock = dynamic_<Flock>(other);
			if (flock)
			{
				for (auto i : flock->get_())
				{
					erase_(i);
				}
			}
			else
			{
				const Ptr it = other->iterator_();
				for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
				{
					erase_(i);
				}
			}
		}
	}
}

inline const Thing::Ptr Shoal::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Stateful::categories_()->copy_());
		categories->self_add_(Serializable::categories_());
		categories->insert_(Shoal::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

inline const Thing::Ptr Shoal::Concurrent::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Stateful::categories_()->copy_());
		categories->insert_(Shoal::Concurrent::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

inline const Thing::Ptr Shoal::Iterator::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Stateful::categories_()->copy_());
		categories->insert_(Shoal::Iterator::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

inline const Thing::Ptr Shoal::Iterator::next_()
{
	if (_iterator == static_<Shoal>(_shoal)->_map.cend())
	{
		return stop_();
	}
	const Ptr result = Flock::mut_();
	const auto flock = static_<Flock>(result);
	flock->push_back_(_iterator->first);
	flock->push_back_(_iterator->second);
	flock->finalize_();
	++_iterator;
	return result;
}

inline const Thing::Ptr Shoal::Feeder::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Stateful::categories_()->copy_());
		categories->insert_(Shoal::Feeder::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

//======================================================================
// class Flock
//======================================================================

inline const Thing::Ptr Flock::size(const Ptr& ignore) const
{
	return Int64::mut_(size_());
}

inline const Thing::Ptr Flock::at_(const Ptr& pos) const
{
	const auto number = dynamic_<Number>(pos);
	if (number)
	{
		return at_(number->to_int64_());
	}
	throw Disagreement("strange::Flock::at_ passed wrong category of Number");
}

inline void Flock::update_(const Ptr& pos, const Ptr& value)
{
	const auto number = dynamic_<Number>(pos);
	if (number)
	{
		update_(number->to_int64_(), value);
	}
	else
	{
		throw Disagreement("strange::Flock::update_ passed wrong category of Number");
	}
}

inline void Flock::insert_(const Ptr& pos, const Ptr& value)
{
	const auto number = dynamic_<Number>(pos);
	if (number)
	{
		insert_(number->to_int64_(), value);
	}
	else
	{
		throw Disagreement("strange::Flock::insert_ passed wrong category of Number");
	}
}

inline void Flock::erase_(const Ptr& pos)
{
	const auto number = dynamic_<Number>(pos);
	if (number)
	{
		erase_(number->to_int64_());
	}
	else
	{
		throw Disagreement("strange::Flock::erase_ passed wrong category of Number");
	}
}

inline void Flock::self_add_(const Ptr& other)
{
	const auto flock = dynamic_<Flock>(other);
	if (flock)
	{
		if (&_vector == &flock->_vector)
		{
			const std_vector_ptr copy = _vector;
			_vector.insert(_vector.end(), copy.cbegin(), copy.cend());
		}
		else
		{
			_vector.insert(_vector.end(), flock->_vector.cbegin(), flock->_vector.cend());
		}
	}
	else
	{
		const auto herd = dynamic_<Herd>(other);
		if (herd)
		{
			_vector.insert(_vector.end(), herd->get_().cbegin(), herd->get_().cend());
		}
		else
		{
			const auto shoal = dynamic_<Shoal>(other);
			if (shoal)
			{
				for (const auto& i : shoal->get_())
				{
					_vector.push_back(i.second);
				}
			}
			else
			{
				const Ptr it = other->iterator_();
				for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
				{
					_vector.push_back(i);
				}
			}
		}
	}
}

inline const Thing::Ptr Flock::Concurrent::size(const Ptr& ignore) const
{
	return Int64::mut_(size_());
}

inline const Thing::Ptr Flock::Concurrent::at_(const Ptr& pos) const
{
	const auto number = dynamic_<Number>(pos);
	if (number)
	{
		const int64_t p = number->to_int64_();
		std::shared_lock<std::shared_timed_mutex> lock(_mutex);
		if (p >= 0 && p < static_<Flock>(_flock)->size_())
		{
			return static_<Flock>(_flock)->at_(p);
		}
	}
	else
	{
		throw Disagreement("strange::Flock::Concurrent::at_ passed wrong category of Number");
	}
	return nothing_();
}

inline void Flock::to_river_(const Ptr& river) const
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Flock::to_river_ passed wrong category of thing");
	}
	riv->write_(Bit::mut_(final_()));
	riv->write_(Int64::mut_(int64_t(_vector.size())));
	for (const auto i : _vector)
	{
		riv->push_back_(i);
	}
}

inline void Flock::from_river_(const Ptr& river)
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Flock::from_river_ passed wrong category of thing");
	}
	const bool bit = riv->read_<Bit>();
	const int64_t int64 = riv->read_<Int64>();
	_vector.reserve(std::size_t(int64));
	for (int64_t i = int64; i > 0; --i)
	{
		_vector.push_back(riv->pop_front_());
	}
	if (bit)
	{
		finalize_();
	}
}

inline void Flock::to_river_with_links_(const Ptr& shoal, const Ptr& river) const
{
	const auto sho = dynamic_<Shoal>(shoal);
	if (!sho)
	{
		throw Disagreement("Flock::to_river_with_links_ passed wrong category of shoal thing");
	}
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Flock::to_river_with_links_ passed wrong category of river thing");
	}
	riv->write_(Bit::mut_(final_()));
	riv->write_(Int64::mut_(int64_t(_vector.size())));
	for (const auto i : _vector)
	{
		static_<Symbol>(sho->at_(i))->to_river_(river);
	}
}

inline void Flock::from_river_with_links_(const Ptr& river)
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Flock::from_river_with_links_ passed wrong category of thing");
	}
	const bool bit = riv->read_<Bit>();
	const int64_t int64 = riv->read_<Int64>();
	_vector.reserve(std::size_t(int64));
	for (int64_t i = int64; i > 0; --i)
	{
		_vector.push_back(Symbol::riv_(river));
	}
	if (bit)
	{
		finalize_();
	}
}

inline void Flock::replace_links_(const Ptr& shoal)
{
	const auto sho = static_<Shoal>(shoal);
	for (std_vector_ptr::iterator i = _vector.begin(); i != _vector.end(); ++i)
	{
		*i = sho->at_(*i);
	}
}

inline const Thing::Ptr Flock::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Stateful::categories_()->copy_());
		categories->self_add_(Serializable::categories_());
		categories->insert_(Flock::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

inline const Thing::Ptr Flock::Concurrent::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Stateful::categories_()->copy_());
		categories->insert_(Flock::Concurrent::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

inline const Thing::Ptr Flock::Iterator::categories_()
{
	static const Ptr CATEGORIES = []()
	{
		const auto categories = static_<Herd>(Stateful::categories_()->copy_());
		categories->insert_(Flock::Iterator::category_());
		categories->finalize_();
		return categories;
	}();
	return CATEGORIES;
}

//======================================================================
// class Herd
//======================================================================

inline void Herd::to_river_(const Ptr& river) const
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Herd::to_river_ passed wrong category of thing");
	}
	riv->write_(Bit::mut_(final_()));
	riv->write_(Int64::mut_(int64_t(_set.size())));
	for (const auto i : _set)
	{
		riv->push_back_(i);
	}
}

inline void Herd::from_river_(const Ptr& river)
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Herd::from_river_ passed wrong category of thing");
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

inline void Herd::to_river_with_links_(const Ptr& shoal, const Ptr& river) const
{
	const auto sho = dynamic_<Shoal>(shoal);
	if (!sho)
	{
		throw Disagreement("Herd::to_river_with_links_ passed wrong category of shoal thing");
	}
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Herd::to_river_with_links_ passed wrong category of river thing");
	}
	riv->write_(Bit::mut_(final_()));
	riv->write_(Int64::mut_(int64_t(_set.size())));
	for (const auto i : _set)
	{
		static_<Symbol>(sho->at_(i))->to_river_(river);
	}
}

inline void Herd::from_river_with_links_(const Ptr& river)
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Herd::from_river_with_links_ passed wrong category of thing");
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

inline void Herd::replace_links_(const Ptr& shoal)
{
	std_unordered_set_ptr replacement;
	const auto sho = static_<Shoal>(shoal);
	for (const auto i : _set)
	{
		replacement.insert(sho->at_(i));
	}
	_set.swap(replacement);
}

inline const Thing::Ptr Herd::size(const Ptr& ignore) const
{
	return Int64::mut_(size_());
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

inline void Lake::to_river_(const Ptr& river) const
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Lake::to_river_ passed wrong category of thing");
	}
	riv->write_(Bit::mut_(final_()));
	riv->write_(Int64::mut_(int64_t(get_().length())));
	riv->write_(get_());
}

inline void Lake::from_river_(const Ptr& river)
{
	const auto riv = dynamic_<River>(river);
	if (!riv)
	{
		throw Disagreement("Lake::from_river_ passed wrong category of thing");
	}
	const bool bit = riv->read_<Bit>();
	const int64_t int64 = riv->read_<Int64>();
	set_(static_<Lake>(riv->read_(int64))->get_());
	if (bit)
	{
		finalize_();
	}
}

inline const char Lake::at_(const Ptr& index) const
{
	const auto ind = dynamic_<Number>(index);
	if (ind)
	{
		return at_(ind->to_int64_());
	}
	throw Disagreement("strange::Lake::at_ passed wrong category of Number");
}

inline const Thing::Ptr Lake::at(const Ptr& it) const
{
	return UInt8::mut_(at_(it->next_()));
}

inline void Lake::update_(const Ptr& index, const Ptr& byte)
{
	const auto ind = dynamic_<Number>(index);
	if (ind)
	{
		const auto byt = dynamic_<Number>(byte);
		if (byt)
		{
			update_(ind->to_int64_(), byt->to_int64_());
		}
	}
	else
	{
		throw Disagreement("strange::Lake::update_ passed wrong category of Number");
	}
}

inline const bool Lake::less_than_(const Ptr& other) const
{
	const auto lake = dynamic_<Lake>(other);
	if (lake)
	{
		return get_() < lake->get_();
	}
	const auto symbol = dynamic_<Symbol>(other);
	if (symbol)
	{
		return get_() < symbol->get_();
	}
	throw Disagreement("Lake::less_than_ passed wrong category of thing");
}

inline const bool Lake::greater_than_(const Ptr& other) const
{
	const auto lake = dynamic_<Lake>(other);
	if (lake)
	{
		return get_() > lake->get_();
	}
	const auto symbol = dynamic_<Symbol>(other);
	if (symbol)
	{
		return get_() > symbol->get_();
	}
	throw Disagreement("Lake::greater_than_ passed wrong category of thing");
}

inline const bool Lake::less_or_equal_(const Ptr& other) const
{
	const auto lake = dynamic_<Lake>(other);
	if (lake)
	{
		return get_() <= lake->get_();
	}
	const auto symbol = dynamic_<Symbol>(other);
	if (symbol)
	{
		return get_() <= symbol->get_();
	}
	throw Disagreement("Lake::less_or_equal_ passed wrong category of thing");
}

inline const bool Lake::greater_or_equal_(const Ptr& other) const
{
	const auto lake = dynamic_<Lake>(other);
	if (lake)
	{
		return get_() >= lake->get_();
	}
	const auto symbol = dynamic_<Symbol>(other);
	if (symbol)
	{
		return get_() >= symbol->get_();
	}
	throw Disagreement("Lake::greater_or_equal_ passed wrong category of thing");
}

//======================================================================
// class Number
//======================================================================

inline const Thing::Ptr Number::to_int64(const Ptr& ignore) const
{
	return Int64::mut_(to_int64_());
}

inline void Number::from_int64_(const Ptr& ptr)
{
	const auto int64 = dynamic_<Int64>(ptr);
	if (int64)
	{
		from_int64_(int64->get_());
	}
	else
	{
		throw Disagreement("strange::Number::from_int64_ passed wrong category of thing");
	}
}

inline const Thing::Ptr Number::to_float64(const Ptr& ignore) const
{
	return Float64::mut_(to_float64_());
}

inline void Number::from_float64_(const Ptr& ptr)
{
	const auto float64 = dynamic_<Float64>(ptr);
	if (float64)
	{
		from_float64_(float64->get_());
	}
	else
	{
		throw Disagreement("strange::Number::from_float64_ passed wrong category of thing");
	}
}

inline const Thing::Ptr Number::to_imaginary64(const Ptr& ignore) const
{
	return Float64::mut_(to_imaginary64_());
}

inline void Number::from_imaginary64_(const Ptr& ptr)
{
	const auto float64 = dynamic_<Float64>(ptr);
	if (float64)
	{
		from_imaginary64_(float64->get_());
	}
	else
	{
		throw Disagreement("strange::Number::from_imaginary64_ passed wrong category of thing");
	}
}

inline const Thing::Ptr Number::to_complex64(const Ptr& ignore) const
{
	return Complex64::mut_(to_complex64_());
}

inline void Number::from_complex64_(const Ptr& ptr)
{
	const auto complex64 = dynamic_<Complex64>(ptr);
	if (complex64)
	{
		from_complex64_(complex64->get_());
	}
	else
	{
		throw Disagreement("strange::Number::from_complex64_ passed wrong category of thing");
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
// class UInt16
//======================================================================

//======================================================================
// class Int32
//======================================================================

//======================================================================
// class UInt32
//======================================================================

//======================================================================
// class Int64
//======================================================================

//======================================================================
// class UInt64
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
