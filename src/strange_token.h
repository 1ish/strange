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
	inline Token(const Ptr& filename, const Ptr& x, const Ptr& y, const Ptr& tag, const Ptr& symbol, const Ptr& value)
		: Mutable{}
		, _filename{ filename }
		, _x{ x }
		, _y{ y }
		, _tag{ tag }
		, _symbol{ symbol }
		, _value{ value }
	{
	}

	static inline const Ptr mut_(const Ptr& filename, const int64_t x, const int64_t y, const char tag, const std::string& str, const Ptr& value = nothing_())
	{
		return mut_(filename, Int64::fin_(x), Int64::fin_(y), Int8::fin_(tag), sym_(str), value);
	}

	static inline const Ptr mut_(const Ptr& filename, const Ptr& x, const Ptr& y, const Ptr& tag, const Ptr& symbol, const Ptr& value)
	{
		return make_<Token>(filename, x, y, tag, symbol, value);
	}

	static inline const Ptr mut(const Ptr& it)
	{
		const Ptr filename = it->next_();
		const Ptr x = it->next_();
		const Ptr y = it->next_();
		const Ptr tag = it->next_();
		const Ptr symbol = it->next_();
		const Ptr value = it->next_();
		return mut_(filename, x, y, tag, symbol, value);
	}

	static inline const Ptr symbol_(const Ptr& filename, const int64_t x, const int64_t y, const std::string& str)
	{
		return mut_(filename, x, y, 'S', str, _symbol_(str));
	}

	static inline const Ptr lake_(const Ptr& filename, const int64_t x, const int64_t y, const std::string& str)
	{
		return mut_(filename, x, y, 'L', str, Lake::fin_(str.substr(1, str.length() - 2)));
	}

	static inline const Ptr integer_(const Ptr& filename, const int64_t x, const int64_t y, const std::string& str)
	{
		const Ptr int64 = Int64::mut_();
		static_<Int64>(int64)->from_symbol_(sym_(str));
		return mut_(filename, x, y, 'I', str, int64);
	}

	static inline const Ptr float_(const Ptr& filename, const int64_t x, const int64_t y, const std::string& str)
	{
		const Ptr float64 = Float64::mut_();
		static_<Float64>(float64)->from_symbol_(sym_(str));
		return mut_(filename, x, y, 'F', str, float64);
	}

	static inline const Ptr name_(const Ptr& filename, const int64_t x, const int64_t y, const std::string& str)
	{
		return mut_(filename, x, y, 'N', str);
	}

	static inline const Ptr punctuation_(const Ptr& filename, const int64_t x, const int64_t y, const std::string& str)
	{
		return mut_(filename, x, y, 'P', str);
	}

	static inline const Ptr error_(const Ptr& filename, const int64_t x, const int64_t y, const std::string& str)
	{
		return mut_(filename, x, y, 'E', str);
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&Token::mut, "filename", "x", "y", "tag", "symbol", "value"));
			shoal->update_("filename", Const<Token>::fin_(&Token::filename));
			shoal->update_("x", Const<Token>::fin_(&Token::x));
			shoal->update_("y", Const<Token>::fin_(&Token::y));
			shoal->update_("tag", Const<Token>::fin_(&Token::tag));
			shoal->update_("symbol", Const<Token>::fin_(&Token::symbol));
			shoal->update_("value", Const<Token>::fin_(&Token::value));
			shoal->update_("error", Const<Token>::fin_(&Token::error, "message"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr& shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Token::mut", Static::fin_(&Token::mut, "filename", "x", "y", "tag", "symbol", "value"));
	}

	inline const std::string filename_() const
	{
		return static_<Symbol>(_filename)->get_();
	}

	inline const Ptr filename(const Ptr& ignore = nothing_()) const
	{
		return _filename;
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

	inline const char tag_() const
	{
		return static_<Int8>(_tag)->get_();
	}

	inline const Ptr tag(const Ptr& ignore = nothing_()) const
	{
		return _tag;
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

	inline const Ptr error_(const std::string& err, const Ptr& misunderstanding = Misunderstanding::mut_()) const
	{
		Misunderstanding* const m = static_<Misunderstanding>(misunderstanding);
		m->self_add_(err);
		const std::string filename = filename_();
		if (!filename.empty())
		{
			m->self_add_(" " + filename);
		}
		m->self_add_(" (");
		m->self_add_(std::to_string(x_()));
		m->self_add_(",");
		m->self_add_(std::to_string(y_()));
		m->self_add_(") ");
		m->self_add_(std::string() + tag_());
		m->self_add_(" ");
		m->self_add_(symbol_());
		return misunderstanding;
	}

	inline const Ptr error_(const Ptr& err) const
	{
		const Ptr to_lake = err->invoke_("to_lake");
		Lake* const lake = dynamic_<Lake>(to_lake);
		if (lake)
		{
			return error_(lake->get_());
		}
		return error_("unknown");
	}

	inline const Ptr error(const Ptr& it) const
	{
		return error_(it->next_());
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
	const Ptr _filename;
	const Ptr _x;
	const Ptr _y;
	const Ptr _tag;
	const Ptr _symbol;
	const Ptr _value;

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
