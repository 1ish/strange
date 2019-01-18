#ifndef COM_ONEISH_STRANGE_TOKEN_H
#define COM_ONEISH_STRANGE_TOKEN_H

#include "strange_core.h"

namespace strange
{
	class Token;

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
class Token : public Mutable
//----------------------------------------------------------------------
{
public:
	inline Token(const Ptr& tag, const Ptr& x, const Ptr& y, const Ptr& symbol, const Ptr& value, const Ptr& ptr)
		: Mutable{}
		, _tag{ tag }
		, _x{ x }
		, _y{ y }
		, _symbol{ symbol }
		, _value{ value }
		, _ptr{ ptr }
	{
	}

	static inline const Ptr mut_(const char tag, const int64_t x, const int64_t y, const Ptr& symbol, const Ptr& value = nothing_(), const Ptr& ptr = nothing_())
	{
		return mut_(Int8::fin_(tag), Int64::fin_(x), Int64::fin_(y), symbol, value, ptr);
	}

	static inline const Ptr mut_(const Ptr& tag, const Ptr& x, const Ptr& y, const Ptr& symbol, const Ptr& value, const Ptr& ptr)
	{
		return make_<Token>(tag, x, y, symbol, value, ptr);
	}

	static inline const Ptr mut(const Ptr& it)
	{
		const Ptr tag = it->next_();
		const Ptr x = it->next_();
		const Ptr y = it->next_();
		const Ptr symbol = it->next_();
		const Ptr value = it->next_();
		const Ptr ptr = it->next_();
		return mut_(tag, x, y, symbol, value, ptr);
	}

	static inline const Ptr symbol_(const int64_t x, const int64_t y, const std::string& str)
	{
		return mut_('S', x, y, sym_(str), _symbol_(str));
	}

	static inline const Ptr lake_(const int64_t x, const int64_t y, const std::string& str)
	{
		return mut_('L', x, y, sym_(str), Lake::fin_(str.substr(1, str.length() - 2)));
	}

	static inline const Ptr integer_(const int64_t x, const int64_t y, const std::string& str)
	{
		const Ptr symbol = sym_(str);
		const Ptr int64 = Int64::mut_();
		static_<Int64>(int64)->from_symbol_(symbol);
		return mut_('I', x, y, symbol, int64);
	}

	static inline const Ptr float_(const int64_t x, const int64_t y, const std::string& str)
	{
		const Ptr symbol = sym_(str);
		const Ptr float64 = Float64::mut_();
		static_<Float64>(float64)->from_symbol_(symbol);
		return mut_('F', x, y, symbol, float64);
	}

	static inline const Ptr name_(const int64_t x, const int64_t y, const std::string& str)
	{
		return mut_('N', x, y, sym_(str));
	}

	static inline const Ptr punctuation_(const int64_t x, const int64_t y, const std::string& str)
	{
		return mut_('P', x, y, sym_(str));
	}

	static inline const Ptr error_(const int64_t x, const int64_t y, const std::string& str)
	{
		return mut_('E', x, y, sym_(str));
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(_tag, _x, _y, _symbol, _value, _ptr);
	}

	virtual inline const Ptr clone_() const override
	{
		return mut_(_tag->clone_(), _x->clone_(), _y->clone_(), _symbol->clone_(), _value->clone_(), _ptr->clone_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&Token::mut, "tag", "x", "y", "symbol", "value", "thing"));
			shoal->update_("tag", Const<Token>::fin_(&Token::tag));
			shoal->update_("x", Const<Token>::fin_(&Token::x));
			shoal->update_("y", Const<Token>::fin_(&Token::y));
			shoal->update_("symbol", Const<Token>::fin_(&Token::symbol));
			shoal->update_("value", Const<Token>::fin_(&Token::value));
			shoal->update_("set", Member<Token>::fin_(&Token::set, "thing"));
			shoal->update_("get", Const<Token>::fin_(&Token::get));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr& shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Token::mut", Static::fin_(&Token::mut, "tag", "x", "y", "symbol", "value", "thing"));
	}

	inline const char tag_() const
	{
		return static_<Int8>(_tag)->get_();
	}

	inline const Ptr tag(const Ptr& ignore = nothing_()) const
	{
		return _tag;
	}

	inline const int64_t x_() const
	{
		return static_<Int64>(_x)->get_();
	}

	inline const Ptr x(const Ptr& ignore = nothing_()) const
	{
		return _x;
	}

	inline const int64_t y_() const
	{
		return static_<Int64>(_y)->get_();
	}

	inline const Ptr y(const Ptr& ignore = nothing_()) const
	{
		return _y;
	}

	inline const std::string symbol_() const
	{
		return static_<Symbol>(_symbol)->get_();
	}

	inline const Ptr symbol(const Ptr& ignore = nothing_()) const
	{
		return _symbol;
	}

	inline const Ptr value_() const
	{
		return _value;
	}

	inline const Ptr value(const Ptr& ignore) const
	{
		return value_();
	}

	inline const Ptr set_(const std::string& str)
	{
		return set_(sym_(str));
	}

	inline const Ptr set_(const Ptr& ptr)
	{
		_ptr = ptr;
		return me_();
	}

	inline const Ptr set(const Ptr& it)
	{
		const Ptr ptr = it->next_();
		set_(ptr);
		return ptr;
	}

	inline const Ptr get_() const
	{
		return _ptr;
	}

	inline const Ptr get(const Ptr& ignore) const
	{
		return get_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Token");
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
	const Ptr _tag;
	const Ptr _x;
	const Ptr _y;
	const Ptr _symbol;
	const Ptr _value;
	Ptr _ptr;

	static inline const Ptr _symbol_(const std::string& str)
	{
		const Ptr symbol = sym_(str.substr(1, str.length() - 2));
		if (symbol->is_nothing_())
		{
			return nothing_();
		}
		else if (symbol->is_("1"))
		{
			return one_();
		}
		else if (symbol->is_("."))
		{
			return stop_();
		}
		return symbol;
	}
};

//======================================================================
// class Token
//======================================================================

} // namespace strange

#endif
