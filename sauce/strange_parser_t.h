#ifndef COM_ONEISH_STRANGE_PARSER_T_H
#define COM_ONEISH_STRANGE_PARSER_T_H

namespace strange
{

template <typename ___ego___ = parser_a<>>
class parser_t : public thing_t<___ego___>
{
public:
	// override
	using over = thing_o<parser_t<>>;

	// construction
	static inline parser_a<> create_()
	{
		return parser_a<>{ over{ parser_t<>{} } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::parser");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		//TODO		shoal.update_string("strange::parser::create", native_function_t<>::create(&parser_t<>::create__));
	}

	// parser
	inline any_a<> parse__(range_a<> const& range)
	{
		return parse_(range); //TODO
	}
	
	inline expression_a<> parse_(range_a<> const& tokenizer)
	{
		_tokenizer = tokenizer;
		_it = _tokenizer.cbegin_();
		_end = _tokenizer.cend_();
		if (_it == _end)
		{
			return expression_t<>::create(token_t<>::create_punctuation_());
		}
		_previous = token_t<>::create_punctuation_();
		_token = cast<token_a<>>(*_it);
		if (_token.tag() == "error")
		{
			throw dis("strange::parser tokenizer error:") + _token.report_();
		}
		auto const result = _initial(0, std::make_shared<context_struct>());
		if (_it != _end)
		{
			throw dis("strange::parser unparsed tokens:") + _token.report_();
		}
		return result.recreate_();
	}

protected:
	inline parser_t()
		: thing_t<___ego___>{}
		, _tokenizer{ tokenizer_t<>::create_(river_t<>::create_()) }
		, _it{ _tokenizer.cbegin_() }
		, _end{ _tokenizer.cend_() }
		, _previous{ token_t<>::create_punctuation_() }
		, _token{ _previous }
		, _shared{ unordered_shoal_t<>::create_() }
	{
		_shared += strange::shared();
	}

private:
	range_a<> _tokenizer;
	forward_const_iterator_a<> _it;
	forward_const_iterator_a<> _end;
	token_a<> _previous;
	token_a<> _token;
	unordered_shoal_a<> _shared;

	struct context_struct;
	using context_ptr = std::shared_ptr<context_struct>;

	struct context_struct
	{
		inline context_struct(
			symbol_a<> const& _shoal = sym(""),
			symbol_a<> const& _scope = sym(""))
			: shoal{ _shoal }
			, scope{ _scope }
			, fixed{ unordered_herd_t<>::create_() }
			, kind{ unordered_shoal_t<>::create_() }
			, meta{ context_ptr{} }
			, emit{ context_ptr{} }
			, emissions{ flock_t<>::create_() }
		{}

		inline context_struct(
			symbol_a<> const& _shoal,
			symbol_a<> const& _scope,
			unordered_herd_a<>& _fixed,
			unordered_shoal_a<>& _kind,
			context_ptr const& _meta = context_ptr{},
			context_ptr const& _emit = context_ptr{})
			: shoal{ _shoal }
			, scope{ _scope }
			, fixed{ _fixed, any_a<>::___duplicate_tag___{} }
			, kind{ _kind, any_a<>::___duplicate_tag___{} }
			, meta{ _meta }
			, emit{ _emit }
			, emissions{ flock_t<>::create_() }
		{}

		symbol_a<> const shoal;
		symbol_a<> const scope;
		unordered_herd_a<> fixed;
		unordered_shoal_a<> kind;
		context_ptr meta;
		context_ptr emit;
		flock_a<> emissions;
	};

	inline bool _next()
	{
		if (_it == _end)
		{
			return false;
		}
		if (++_it == _end)
		{
			return false;
		}
		_previous = _token;
		_token = cast<token_a<>>(*_it);
		if (_token.tag() == "error")
		{
			throw dis("strange::parser tokenizer error:") + _token.report_();
		}
		if (_token.tag() == "punctuation" && _token.symbol() == "" && ++_it == _end)
		{
			return false;
		}
		return true;
	}

	inline expression_a<> _initial(
		int64_t const min_precedence,
		context_ptr const& context)
	{
		expression_a<> initial = expression_t<>::create(_token);
		if (_token.tag() == "symbol" ||
			_token.tag() == "lake" ||
			_token.tag() == "int" ||
			_token.tag() == "float")
		{
			// literal
			initial = expression_literal_t<>::create_(_token, flock_t<>::create_(_token.literal_()));
			_next();
		}
		else if (_token.tag() == "name")
		{
			if (_token.symbol_().last_character() == '_')
			{
				initial = _initial_intimate(context);
			}
			else if (_token.symbol_().first_character() == '_')
			{
				initial = _initial_attribute(context);
			}
			else if (_token.symbol() == "true")
			{
				initial = expression_literal_t<>::create_(_token, flock_t<>::create_(yes()));
				_next();
			}
			else if (_token.symbol() == "false")
			{
				initial = expression_literal_t<>::create_(_token, flock_t<>::create_(no()));
				_next();
			}
			else if (_token.symbol() == "null")
			{
				initial = expression_literal_t<>::create_(_token, flock_t<>::create_(any_a<>{}));
				_next();
			}
			else
			{
				initial = _initial_local(context);
			}
		}
		else if (_token.tag() == "punctuation")
		{
			auto const token = _token;
			std::string const op = token.symbol();
			if (op == "$" || op == "#") // shared local / dimension
			{
				initial = _initial_local(context);
			}
			else if (op == "$$") // shared scope
			{
				initial = _shared_scope(context);
			}
			else if (op == "^^") // shoal scope
			{
				initial = expression_shared_scope_t<>::create_(token,
					flock_t<>::create_(_shared, context->shoal));
			}
			else if (op == "..") // parameter range
			{
				initial = expression_local_at_t<>::create_(token, flock_t<>::create_(sym("&")));
				_next();
			}
			else if (op == "~>") // meta
			{
				initial = _meta(context);
			}
			else if (op == "(~" || op == "[~" || op == "{~") // emit
			{
				initial = _emit(context);
			}
			else if (op == "^") // me
			{
				if (_next() && _token.tag() == "punctuation")
				{
					if (_token.symbol() == ".") // me dot
					{
						initial = _initial_me_dot(context);
					}
					else if (_token.symbol() == ":.") // me colon-dot
					{
						initial = _initial_me_colon_dot(context);
					}
				}
				else
				{
					initial = expression_me_t<>::create_(token); // me
				}
			}
			else if (op == "[") // flock
			{
				initial = expression_flock_t<>::create_(token, _elements(context));
			}
			else if (op == "(") // block
			{
				initial = expression_block_t<>::create_(token, _elements(context));
			}
			else if (op == "{") // shoal or herd
			{
				initial = _initial_shoal_or_herd(context);
			}
			else if (op == "<") // kind
			{
				initial = _kind(context);
			}
			else
			{
				throw dis("strange::parser unexpected punctuation:") + token.report_();
			}
		}
		else
		{
			throw dis("strange::parser unexpected token tag:") + _token.report_();
		}
		return _subsequent(min_precedence, initial, context);
	}

	inline expression_a<> _meta(context_ptr const& context)
	{
		auto const token = _token;
		auto const emissions = _meta_emissions(context);
		int64_t const size = emissions.size();
		if (!size)
		{
			return expression_t<>::create(token);
		}
		else if (size == 1)
		{
			return cast<expression_a<>>(emissions.at_index(0));
		}
		return expression_block_t<>::create_(token, emissions);
	}

	inline flock_a<> _meta_emissions(context_ptr const& context)
	{
		auto const token = _token;
		if (!context->meta)
		{
			context->meta = std::make_shared<context_struct>();
		}
		context->meta->emit = context;
		context->meta->emissions.clear();
		for (auto const& expression : _elements(context->meta).extract_vector())
		{
			any_a<> result;
			try
			{
				result = cast<expression_a<>>(expression).evaluate_();
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::parser meta evaluation error:") + token.report_() + misunderstanding;
			}
			if (check<expression_a<>>(result))
			{
				context->meta->emissions.push_back(result);
			}
		}
		auto emissions = context->meta->emissions;
		context->meta->emissions.clear();
		context->meta->emit.reset();
		return emissions;
	}
	
	inline expression_a<> _emit(context_ptr const& context)
	{
		auto const token = _token;
		if (!context->emit)
		{
			throw dis("strange::parser " + token.symbol() + " without corresponding ~> preceding it:") + token.report_();
		}
		if (token.symbol() == "(~")
		{
			context->emissions.push_back(expression_block_t<>::create_(token, _elements(context->emit)));
		}
		else if (token.symbol() == "[~")
		{
			context->emissions += _elements(context->emit);
		}
		else if (token.symbol() == "{~")
		{
			context->emissions.push_back(_initial_shoal_or_herd(context->emit));
		}
		return expression_t<>::create(token);
	}

	inline expression_a<> _initial_me_dot(context_ptr const& context)
	{
		auto const token = _token;
		if (!_next())
		{
			throw dis("strange::parser ^. with nothing following it:") + token.report_();
		}
		if (_token.tag() != "name")
		{
			throw dis("strange::parser ^. with non-name following it:") + token.report_();
		}
		if (_token.symbol_().last_character() == '_')
		{
			return _initial_intimate(context);
		}
		return _initial_attribute(context);
	}

	inline expression_a<> _initial_me_colon_dot(context_ptr const& context)
	{
		auto const token = _token;
		if (!_next())
		{
			throw dis("strange::parser ^:. with nothing following it:") + token.report_();
		}
		if (_token.tag() != "name")
		{
			throw dis("strange::parser ^:. with non-name following it:") + token.report_();
		}
		auto const name = _token.symbol_();
		if (name.last_character() != '_')
		{
			throw dis("strange::parser ^:. with attribute name following it:") + token.report_();
		}
		_next();
		auto const terms = flock_t<>::create_(_identifier(context->scope, name)); // me:._name / me:._scope_name
		return expression_intimate_member_create(token, terms);
	}

	inline expression_a<> _initial_attribute(context_ptr const& context)
	{
		auto const token = _token;
		auto terms = flock_t<>::create_(_identifier(context->scope, token.symbol_())); // _name / _scope_name
		if (_next() && _token.tag() == "punctuation" &&
			(_token.symbol() == ":#" || _token.symbol() == ":=" ||
				_token.symbol() == ":<" || _token.symbol() == ":("))
		{
			if (_token.symbol() == ":#")
			{
				throw dis("strange::parser attribute cannot be immutably assigned:") + token.report_();
			}
			bool optional = true;
			if (_token.symbol() == ":=")
			{
				_next();
				terms.push_back(kind_t<>::create_());
			}
			else
			{
				auto const kind = _kind(context);
				if (kind.terms_().at_index(6)) // fixed
				{
					throw dis("strange::parser attribute cannot be immutably assigned:") + token.report_();
				}
				optional = kind.terms_().at_index(8);
				any_a<> any_kind = kind;
				try
				{
					any_kind = cast<expression_a<>>(kind).evaluate_();
				}
				catch (misunderstanding_a<>&)
				{}
				terms.push_back(any_kind);
			}
			if (optional)
			{
				if (_it == _end)
				{
					throw dis("strange::parser attribute assignment with nothing following it:") + token.report_();
				}
				terms.push_back(_initial(0, context)); // assignment
			}
		}
		return expression_intimate_attribute_create(token, terms);
	}

	inline expression_a<> _initial_intimate(context_ptr const& context)
	{
		auto const token = _token;
		auto terms = flock_t<>::create_(_identifier(context->scope, token.symbol_())); // _name_ / _scope_name_
		if (!_next())
		{
			throw dis("strange::parser intimate operation with no arguments:") + token.report_();
		}
		if (_token.tag() == "punctuation" && _token.symbol() == "[")
		{
			terms.push_back(_elements(context)); // me._scope_name_[...]
			return expression_intimate_create(token, terms);
		}
		terms.push_back(_initial(100, context)); // me._scope_name_ range
		return expression_intimate_member_range_create(token, terms);
	}

	static inline symbol_a<> _identifier(
		symbol_a<> const& scope_symbol,
		symbol_a<> const& name)
	{
		// name / _scope_name
		return (scope_symbol.is("") || name.first_character() != '_')
			? name
			: sym("_" + scope_symbol.to_string() + name.to_string());
	}

	static inline symbol_a<> _scope_name(
		symbol_a<> const& scope_symbol,
		symbol_a<> const& name)
	{
		// name / scope::name
		return scope_symbol.is("")
			? name
			: sym(scope_symbol.to_string() + "::" + name.to_string());
	}

	inline expression_a<> _instruction(
		token_a<> const& token,
		context_ptr const& context)
	{
		auto const instruction = _shared.at_string(token.symbol() + "!");
		if (!instruction)
		{
			throw dis("strange::parser instruction not recognised:") + token.report_();
		}
		if (_token.tag() != "punctuation" || _token.symbol() != "(")
		{
			throw dis("strange::parser instruction with no arguments:") + token.report_();
		}
		auto terms = flock_t<>::create_(context->scope);
		terms += _elements(context);
		auto _ = no();
		auto const expression = instruction.operate(_, flock_t<>::create_(token, terms));
		if (!check<expression_a<>>(expression))
		{
			throw dis("strange::parser instruction returned non-expression:") + token.report_();
		}
		return cast<expression_a<>>(expression);
	}

	inline expression_a<> _initial_local(context_ptr const& context)
	{
		bool const punctuation = _token.tag() == "punctuation";
		bool const shared = punctuation && _token.symbol() == "$";
		bool const dimension = punctuation && _token.symbol() == "#";
		auto const prefix = punctuation ? _token.symbol_() : sym("");
		if (punctuation && !_next())
		{
			throw dis("strange::parser " + _token.symbol() + " with nothing following it:") + _token.report_();
		}
		auto const token = _token;
		if (token.tag() != "name")
		{
			throw dis("strange::parser shared local/dimension without name:") + _token.report_();
		}
		auto const name = punctuation ? prefix + token.symbol_() : token.symbol_();
		bool non_instruction = !_next() || _token.tag() != "punctuation";
		if (!non_instruction)
		{
			auto kind = context->kind.at_(name);
			bool fixed = context->fixed.has(name);
			bool insert = false;
			bool update = false;
			bool reference = false;
			bool optional = true;
			auto const op = _token.symbol();
			if (kind)
			{
				if (op == ":=")
				{
					if (fixed)
					{
						throw dis("strange::parser cannot reassign fixed variable:") + _token.report_();
					}
					update = true;
					_next();
				}
				else if (op == ":#")
				{
					throw dis("strange::parser cannot reassign variable with fixed:") + _token.report_();
				}
				else if (op == ":&")
				{
					throw dis("strange::parser cannot reassign variable with reference:") + _token.report_();
				}
				else if (op == ":<" || op == ":(")
				{
					throw dis("strange::parser cannot reassign variable kind:") + _token.report_();
				}
			}
			else if (fixed)
			{
				throw dis("strange::parser recursive variable definition:") + _token.report_();
			}
			else
			{
				if (op == ":=" || op == ":#" || op == ":&")
				{
					_next();
					fixed = dimension || op == ":#";
					reference = op == ":&";
					optional = _it != _end && (_token.tag() != "punctuation" || !_delimiter(_token.symbol()));
					insert = true;
					kind = kind_t<>::create(1, "", flock_t<>::create_(), flock_t<>::create_(), flock_t<>::create_(), kind_t<>::any_sym(), fixed, reference, optional);
				}
				else if (op == ":<" || op == ":(")
				{
					auto const kind_expression = _kind(context, dimension);
					fixed = dimension || kind_expression.terms_().at_index(6);
					reference = kind_expression.terms_().at_index(7);
					optional = kind_expression.terms_().at_index(8);
					insert = true;
					kind = kind_expression;
					try
					{
						kind = cast<expression_a<>>(kind).evaluate_();
					}
					catch (misunderstanding_a<>&)
					{}
				}
			}
			if (insert || update)
			{
				if (_it == _end)
				{
					throw dis("strange::parser local assignment with no right-hand side:") + token.report_();
				}
				context->fixed.insert(name);
				any_a<> const rhs = optional
					? _initial(0, context)
					: no();
				if (!fixed)
				{
					context->fixed.erase(name);
				}
				if (insert)
				{
					context->kind.insert_(name, kind);
					if (optional)
					{
						if (shared)
						{
							return expression_shared_insert_t<>::create_(token, flock_t<>::create_(name, kind, rhs));
						}
						return expression_local_insert_t<>::create_(token, flock_t<>::create_(name, kind, rhs));
					}
					else
					{
						if (shared)
						{
							return expression_shared_insert_t<>::create_(token, flock_t<>::create_(name, kind));
						}
						return expression_local_insert_t<>::create_(token, flock_t<>::create_(name, kind));
					}
				}
				if (update)
				{
					if (shared)
					{
						return expression_shared_update_t<>::create_(token, flock_t<>::create_(name, kind, rhs));
					}
					return expression_local_update_t<>::create_(token, flock_t<>::create_(name, kind, rhs));
				}
			}
			non_instruction = dimension || kind;
		}
		if (shared)
		{
			if (!context->kind.has(name))
			{
				throw dis("strange::parser unrecognised shared variable:") + token.report_();
			}
			return expression_shared_at_t<>::create_(token, flock_t<>::create_(name));
		}
		if (!non_instruction && _shared.has_string(token.symbol() + "!"))
		{
			return _instruction(token, context);
		}
		if (!context->kind.has(name))
		{
			throw dis("strange::parser unrecognised local variable:") + token.report_();
		}
		return expression_local_at_t<>::create_(token, flock_t<>::create_(name));
	}

	inline expression_a<> _shared_scope(context_ptr const& context)
	{
		if (!_next())
		{
			throw dis("strange::parser $$ with nothing following it:") + _token.report_();
		}
		auto const token = _token;
		if (token.tag() == "punctuation" && token.symbol() == "<")
		{
			try
			{
				return expression_shared_scope_t<>::create_(token, flock_t<>::create_(_shared, _kind(context).evaluate_()));
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::parser shared scope kind evaluation error:") + token.report_() + misunderstanding;
			}
		}
		else if (token.tag() == "name")
		{
			return expression_shared_scope_t<>::create_(token, flock_t<>::create_(_shared, _scope()));
		}
		else
		{
			throw dis("strange::parser $$ with invalid token following it:") + _token.report_();
		}
	}

	inline symbol_a<> _scope()
	{
		std::string scope;
		for (bool first = true;;first = false)
		{
			if (_token.tag() != "name")
			{
				if (first)
				{
					break;
				}
				throw dis("strange::parser :: with non-name following it:") + _token.report_();
			}
			scope += _token.symbol();
			if (!_next() || _token.tag() != "punctuation" || _token.symbol() != "::")
			{
				break;
			}
			scope += "::";
			if (!_next())
			{
				throw dis("strange::parser :: with nothing following it:") + _token.report_();
			}
		}
		return sym(scope);
	}

	inline expression_a<> _initial_shoal_or_herd(context_ptr const& context)
	{
		auto const token = _token;
		if (!_next())
		{
			throw dis("strange::parser " + token.symbol() + " with nothing following it:") + token.report_();
		}
		bool const tilda = token.symbol() == "{~";
		auto flock = flock_t<>::create_();
		bool herd = false;
		bool shoal = false;
		auto key = expression_t<>::create(token);
		context_ptr key_context;
		context_ptr value_context;
		auto emissions = squad_t<>::create_();
		if (_token.tag() == "punctuation" &&
			((!tilda && _token.symbol() == "}") || (tilda && _token.symbol() == "~}") || _token.symbol() == "!"))
		{
			if (_token.symbol() == "!")
			{
				if (!_next() || (!tilda && _token.symbol() != "}") || (tilda && _token.symbol() != "~}"))
				{
					throw dis("strange::parser {! without } immediately following it:") + token.report_();
				}
				herd = true;
			}
			_next();
		}
		else for (;;)
		{
			if (emissions.empty())
			{
				if (_token.tag() == "punctuation" && _token.symbol() == "~>")
				{
					emissions += _meta_emissions(context);
					if (_it == _end)
					{
						throw dis("strange::parser meta element with nothing following it:") + _token.report_();
					}
					continue;
				}
				if (_token.tag() == "name")
				{
					key = expression_literal_t<>::create_(_token, flock_t<>::create_(_token.symbol_()));
					_next();
				}
				else
				{
					if (!key_context)
					{
						auto context_fixed = unordered_herd_a<>::ref(context->fixed);
						auto context_kind = unordered_shoal_a<>::ref(context->kind);
						key_context = std::make_shared<context_struct>(
							context->scope,
							context->scope,
							context_fixed,
							context_kind,
							context->meta,
							context->emit);
					}
					key = _initial(0, key_context);
				}
			}
			else // emissions
			{
				key = cast<expression_a<>>(emissions.pop_front_());
				if (!shoal && key.type_() == expression_herd_t<>::type_())
				{
					herd = true;
					flock += key.terms_();
					continue;
				}
				if (!herd && key.type_() == expression_shoal_t<>::type_())
				{
					shoal = true;
					flock += key.terms_();
					continue;
				}
				if (shoal && !emissions.empty())
				{
					throw dis("strange::parser invalid shoal meta emissions:") + _token.report_();
				}
			}
			if (emissions.empty())
			{
				if (_it == _end)
				{
					if (shoal)
					{
						throw dis("strange::parser shoal key with nothing following it:") + _token.report_();
					}
					throw dis("strange::parser element with nothing following it:") + _token.report_();
				}
				if (_token.tag() != "punctuation")
				{
					if (shoal)
					{
						throw dis("strange::parser shoal key with non-punctuation following it:") + _token.report_();
					}
					throw dis("strange::parser element with non-punctuation following it:") + _token.report_();
				}
				bool const comma = _token.symbol() == ",";
				if (comma)
				{
					if (shoal)
					{
						throw dis("strange::parser shoal key without a corresponding value:") + _token.report_();
					}
					if (!_next())
					{
						throw dis("strange::parser , with nothing following it:") + _token.report_();
					}
				}
				if ((!tilda && _token.symbol() == "}") || (tilda && _token.symbol() == "~}"))
				{
					if (shoal)
					{
						throw dis("strange::parser shoal key without a corresponding value:") + _token.report_();
					}
					_next();
					herd = true;
					flock.push_back(key);
					break;
				}
				if (comma)
				{
					herd = true;
					flock.push_back(key);
					continue;
				}
				if (herd)
				{
					throw dis("strange::parser herd element with unexpected punctuation following it:") + _token.report_();
				}
				shoal = true;
			}
			else // emissions
			{
				herd = true;
				flock.push_back(key);
				continue;
			}

			// shoal value
			auto const operator_token = _token;
			if (!_next())
			{
				throw dis("strange::parser shoal " + operator_token.symbol() + " with nothing following it:") + operator_token.report_();
			}
			any_a<> key_symbol;
			try
			{
				key_symbol = key.evaluate_();
			}
			catch (misunderstanding_a<>&)
			{
			}
			auto const new_scope_symbol = _scope_name(context->scope,
				check<symbol_a<>>(key_symbol) ? cast<symbol_a<>>(key_symbol) : sym("#"));

			auto value = expression_t<>::create(operator_token);
			if (operator_token.symbol() == ":")
			{
				// regular key/value pair
				if (!value_context)
				{
					auto context_fixed = unordered_herd_a<>::ref(context->fixed);
					auto context_kind = unordered_shoal_a<>::ref(context->kind);
					value_context = std::make_shared<context_struct>(
						context->scope,
						new_scope_symbol,
						context_fixed,
						context_kind,
						context->meta,
						context->emit);
				}
				value = _initial(0, value_context);
			}
			else if (operator_token.symbol() == "::")
			{
				// shared scope
				auto new_fixed = _remove_herd_non_dimensions(context->fixed);
				auto new_kind = _remove_shoal_non_dimensions(context->kind);
				value = _initial(0, std::make_shared<context_struct>(
					context->scope,
					new_scope_symbol,
					new_fixed,
					new_kind,
					context->meta,
					context->emit));
				bool clash = false;
				try
				{
					// auto lock = _shared.write_lock_();
					clash = !const_cast<unordered_shoal_t<>::std_unordered_map_any_any&>(_shared.extract_map()).emplace(new_scope_symbol, value.evaluate_()).second;
				}
				catch (misunderstanding_a<>& misunderstanding)
				{
					throw dis("strange::parser shoal :: value evaluation error:") + _token.report_() + misunderstanding;
				}
				if (clash)
				{
					throw dis("strange::parser shoal :: redefinition of shared name:") + _token.report_();
				}
			}
			else if (check<symbol_a<>>(key_symbol) && cast<symbol_a<>>(key_symbol).last_character() == '_' &&
				(operator_token.symbol() == ":#" || operator_token.symbol() == ":=" || operator_token.symbol() == ":&"))
			{
				bool const fixed = operator_token.symbol() == ":#";
				bool const reference = !fixed && operator_token.symbol() == ":&";
				any_a<> instruction;
				if (reference)
				{
					if (_token.tag() != "name")
					{
						throw dis("strange::parser shoal member instruction without name following it:") + _token.report_();
					}
					instruction = _shared.at_string(_token.symbol() + "!");
					if (!instruction)
					{
						throw dis("strange::parser shoal member instruction not recognised:") + _token.report_();
					}
					if (!_next() || _token.tag() != "punctuation" || _token.symbol() != "(")
					{
						throw dis("strange::parser shoal member instruction with no arguments:") + _token.report_();
					}
				}
				else if (_token.tag() != "punctuation" || _token.symbol() != "(")
				{
					throw dis("strange::parser shoal " + operator_token.symbol() + " without ( following it:") + _token.report_();
				}
				// reference/extraction/mutation
				auto terms = flock_t<>::create_(new_scope_symbol);
				auto new_fixed = _remove_herd_non_dimensions(context->fixed);
				auto new_kind = _remove_shoal_non_dimensions(context->kind);
				terms += _elements(std::make_shared<context_struct>(
					context->scope,
					new_scope_symbol,
					new_fixed,
					new_kind,
					context->meta,
					context->emit));
				if (reference)
				{
					auto _ = no();
					auto const expression = instruction.operate(_, flock_t<>::create_(operator_token, terms));
					if (!check<expression_a<>>(expression))
					{
						throw dis("strange::parser shoal member instruction returned non-expression:") + operator_token.report_();
					}
					value = cast<expression_a<>>(expression);
				}
				else if (fixed)
				{
					value = expression_extraction_t<>::create_(operator_token, terms);
				}
				else
				{
					value = expression_mutation_t<>::create_(operator_token, terms);
				}
			}
			else if (operator_token.symbol() == ":#" || operator_token.symbol() == ":=" || operator_token.symbol() == ":&" ||
				operator_token.symbol() == ":<" || operator_token.symbol() == ":(")
			{
				if (!check<symbol_a<>>(key_symbol))
				{
					throw dis("strange::parser shoal " + operator_token.symbol() + " with non-symbol key:") + operator_token.report_();
				}
				any_a<> kind;
				bool fixed = (operator_token.symbol() == ":#");
				bool reference = !fixed && operator_token.symbol() == ":&";
				if (fixed || reference || operator_token.symbol() == ":=")
				{
					kind = kind_t<>::create(1, "", flock_t<>::create_(), flock_t<>::create_(), flock_t<>::create_(), kind_t<>::any_sym(), fixed, reference);
				}
				else
				{
					auto const expression = _kind(context);
					kind = expression;
					fixed = expression.terms_().at_index(6);
					reference = expression.terms_().at_index(7);
				}
				any_a<> instruction;
				if (reference)
				{
					if (_token.tag() != "name")
					{
						throw dis("strange::parser shoal attribute instruction without name following it:") + _token.report_();
					}
					instruction = _shared.at_string(_token.symbol() + "!");
					if (!instruction)
					{
						throw dis("strange::parser shoal attribute instruction not recognised:") + _token.report_();
					}
					if (!_next())
					{
						throw dis("strange::parser shoal attribute instruction with no arguments:") + _token.report_();
					}
				}
				// attribute reference/extraction/mutation
				auto new_fixed = _remove_herd_non_dimensions(context->fixed);
				auto new_kind = _remove_shoal_non_dimensions(context->kind);
				auto const terms = flock_t<>::create_(key_symbol, kind, _initial(0,
					std::make_shared<context_struct>(
						context->scope,
						new_scope_symbol,
						new_fixed,
						new_kind,
						context->meta,
						context->emit)));
				if (reference)
				{
					auto _ = no();
					auto const expression = instruction.operate(_, flock_t<>::create_(operator_token, terms));
					if (!check<expression_a<>>(expression))
					{
						throw dis("strange::parser shoal attribute instruction returned non-expression:") + operator_token.report_();
					}
					value = cast<expression_a<>>(expression);
				}
				else if (fixed)
				{
					value = expression_attribute_extraction_t<>::create_(operator_token, terms);
				}
				else
				{
					value = expression_attribute_mutation_t<>::create_(operator_token, terms);
				}
			}
			else
			{
				throw dis("strange::parser shoal key with unexpected punctuation following it:") + _token.report_();
			}
			if (_it == _end)
			{
				throw dis("strange::parser shoal value with nothing following it:") + _token.report_();
			}
			flock.push_back(expression_flock_t<>::create_(operator_token, flock_t<>::create_(key, value)));
			if (_token.tag() != "punctuation")
			{
				throw dis("strange::parser shoal value with non-punctuation following it:") + _token.report_();
			}
			bool const comma = _token.symbol() == ",";
			if (comma && !_next())
			{
				throw dis("strange::parser shoal , with nothing following it:") + _token.report_();
			}
			if ((!tilda && _token.symbol() == "}") || (tilda && _token.symbol() == "~}"))
			{
				_next();
				break;
			}
			if (!comma)
			{
				throw dis("strange::parser shoal value with unexpected punctuation following it:") + _token.report_();
			}
		}
		if (herd)
		{
			return expression_herd_t<>::create_(token, flock);
		}
		return expression_shoal_t<>::create_(token, flock);
	}

	static inline unordered_herd_a<> _remove_herd_non_dimensions(unordered_herd_a<> const& herd)
	{
		unordered_herd_a<> result = unordered_herd_t<>::create_();
		for (auto const& item : herd.extract_set())
		{
			if (check<symbol_a<>>(item) && cast<symbol_a<>>(item).first_character() == '#')
			{
				result.insert(item);
			}
		}
		return result;
	}

	static inline unordered_shoal_a<> _remove_shoal_non_dimensions(unordered_shoal_a<> const& shoal)
	{
		unordered_shoal_a<> result = unordered_shoal_t<>::create_();
		for (auto const& item : shoal.extract_map())
		{
			if (check<symbol_a<>>(item.first) && cast<symbol_a<>>(item.first).first_character() == '#')
			{
				result.insert(item.first, item.second);
			}
		}
		return result;
	}

	inline expression_a<> _kind(context_ptr const& context, bool fixed = false)
	{
		auto const token = _token;
		bool punctuation = token.tag() == "punctuation";
		bool const parenthesis = punctuation && token.symbol() == ":(";
		bool const colon = parenthesis || (punctuation && token.symbol() == ":<");
		bool modify = parenthesis;
		expression_a<> expression;
		if (parenthesis)
		{
			if (!_next())
			{
				throw dis("strange::parser kind :( with nothing following it:") + token.report_();
			}
			expression = _initial(100, context);
		}
		auto terms = flock_t<>::create_();

		// order
		int64_t order = 0;
		if (!parenthesis)
		{
			while ((!order && colon) ||
				(_token.tag() == "punctuation" && _token.symbol() == "<"))
			{
				++order;
				if (!_next())
				{
					throw dis("strange::parser kind < with nothing following it:") + token.report_();
				}
			}
		}
		terms.push_back(number_int_64_t<>::create(order));

		// name
		bool const dimension = !parenthesis && _token.tag() == "punctuation" && _token.symbol() == "#";
		if (dimension && (!_next() || _token.tag() != "name"))
		{
			throw dis("strange::parser kind # with no name following it:") + token.report_();
		}
		bool const name = !parenthesis && _token.tag() == "name";
		if (name)
		{
			if (dimension)
			{
				modify = true;
				expression = expression_local_at_t<>::create_(token, flock_t<>::create_(sym("#" + _token.symbol())));
				_next();
				terms.push_back(sym(""));
			}
			else
			{
				terms.push_back(_scope());
			}
			if (_it == _end)
			{
				throw dis("strange::parser kind name with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(sym(""));
		}

		// dimensions
		bool const dimensions = !modify && _token.tag() == "punctuation" && _token.symbol() == "{";
		if (dimensions)
		{
			terms.push_back(expression_flock_t<>::create_(token, _elements(context)));
			if (_it == _end)
			{
				throw dis("strange::parser kind } with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(expression_flock_t<>::create(token));
		}

		// aspects
		bool const aspects = !modify && _token.tag() == "punctuation" && _token.symbol() == "[";
		if (aspects)
		{
			terms.push_back(expression_flock_t<>::create_(token, _elements(context)));
			if (_it == _end)
			{
				throw dis("strange::parser kind ] with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(expression_flock_t<>::create(token));
		}

		// paramters
		bool const parameters = !modify && _token.tag() == "punctuation" && _token.symbol() == "(";
		if (parameters)
		{
			terms.push_back(expression_flock_t<>::create_(token, _elements(context)));
			if (_it == _end)
			{
				throw dis("strange::parser kind ) with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(expression_flock_t<>::create(token));
		}

		// result
		bool const result = !modify && _token.tag() == "punctuation" &&
			(_token.symbol() == ":<" || _token.symbol() == ":(");
		if (result)
		{
			terms.push_back(_kind(context)); // recurse for result
			if (_it == _end)
			{
				throw dis("strange::parser kind result with nothing following it:") + token.report_();
			}
		}
		else
		{
			terms.push_back(expression_kind_t<>::create(_token, flock_t<>::create_()));
		}

		// close
		bool assignment = false;
		while (order && _it != _end && _token.tag() == "punctuation" && (_token.symbol() == ">" || (assignment = order == 1 && _token.symbol() == ">=")))
		{
			_next();
			--order;
		}
		if (order)
		{
			throw dis("strange::parser mismatched kind < and > pair:") + token.report_();
		}
		if (parenthesis)
		{
			if (_it == _end || _token.tag() != "punctuation" || _token.symbol() != ")")
			{
				throw dis("strange::parser mismatched kind :( and ) pair:") + _token.report_();
			}
			_next();
		}

		// fixed / reference
		bool reference = false;
		if (!assignment && _it != _end && _token.tag() == "punctuation")
		{
			if (_token.symbol() == "#")
			{
				_next();
				fixed = true;
				assignment = true;
			}
			else if (_token.symbol() == "=")
			{
				_next();
				assignment = true;
			}
			else if (_token.symbol() == "&")
			{
				_next();
				reference = true;
				assignment = true;
			}
		}
		terms.push_back(boole(fixed));
		terms.push_back(boole(reference));

		bool const optional = colon && assignment && _it != _end &&
			(_token.tag() != "punctuation" || !_delimiter(_token.symbol()));
		terms.push_back(boole(optional));

		// expression
		if (modify)
		{
			terms.push_back(expression);
		}
		else if (!optional)
		{
			// remove redundant terms
			terms.pop_back_();
			if (!reference)
			{
				terms.pop_back_();
				if (!fixed)
				{
					terms.pop_back_();
					if (!result)
					{
						terms.pop_back_();
						if (!parameters)
						{
							terms.pop_back_();
							if (!aspects)
							{
								terms.pop_back_();
								if (!dimensions)
								{
									terms.pop_back_();
									if (!name)
									{
										terms.pop_back_();
									}
								}
							}
						}
					}
				}
			}
		}
		return expression_kind_t<>::create_(token, terms);
	}
	
	inline expression_a<> _subsequent(
		int64_t const min_precedence,
		expression_a<> const& initial,
		context_ptr const& context)
	{
		if (min_precedence >= 100 || _it == _end)
		{
			return initial;
		}
		auto const token = _token;
		if (token.tag() == "punctuation")
		{
			auto const op = token.symbol();
			if (op == "[")
			{
				// operate with elements
				auto terms = flock_t<>::create_(initial);
				terms += _elements(context);
				return _subsequent(min_precedence, expression_operate_t<>::create_(token, terms), context);
			}
			if (op == ".")
			{
				// invoke member
				if (!_next())
				{
					throw dis("strange::parser . with nothing following it:") + token.report_();
				}
				return _subsequent_dot(min_precedence, initial, context);
			}
			if (op == ".:")
			{
				// operate
				if (!_next())
				{
					throw dis("strange::parser .: with nothing following it:") + token.report_();
				}
				return _subsequent_dot_colon(min_precedence, initial, context);
			}
			if (op == ":.")
			{
				// member
				if (!_next())
				{
					throw dis("strange::parser :. with nothing following it:") + token.report_();
				}
				return _subsequent_colon_dot(min_precedence, initial, context);
			}
			if (_delimiter(op))
			{
				return initial;
			}
			int64_t const precedence = token.precedence();
			if (precedence)
			{
				// operator
				if (precedence < min_precedence)
				{
					return initial;
				}
				if (op == "|" || op == "&&" || op == "!&" || op == "%%" || op == "!%" || op == "||" || op == "!|")
				{
					// pipe / logic operator
					if (!_next())
					{
						throw dis("strange::parser pipe / logic operator with nothing following it:") + token.report_();
					}
					auto const terms = flock_t<>::create_(
						initial,
						_initial(precedence + 1, context));
					if (op == "|")
					{
						return _subsequent(min_precedence, expression_pipe_t<>::create_(token, terms), context);
					}
					if (op == "&&")
					{
						return _subsequent(min_precedence, expression_and_t<>::create_(token, terms), context);
					}
					if (op == "!&")
					{
						return _subsequent(min_precedence, expression_nand_t<>::create_(token, terms), context);
					}
					if (op == "%%")
					{
						return _subsequent(min_precedence, expression_xor_t<>::create_(token, terms), context);
					}
					if (op == "!%")
					{
						return _subsequent(min_precedence, expression_xnor_t<>::create_(token, terms), context);
					}
					if (op == "||")
					{
						return _subsequent(min_precedence, expression_or_t<>::create_(token, terms), context);
					}
					if (op == "!|")
					{
						return _subsequent(min_precedence, expression_nor_t<>::create_(token, terms), context);
					}
				}
				auto oper = sym("");
				int64_t count = 2;
				bool right_to_left = false;
				if (op == "@?")
				{
					oper = sym("has_");
				}
				else if (op == "@")
				{
					oper = sym("at_");
				}
				else if (op == "@=")
				{
					oper = sym("update_");
					count = 3;
				}
				else if (op == "@+")
				{
					oper = sym("insert_");
					count = 3;
				}
				else if (op == "@-")
				{
					oper = sym("erase_");
				}
				else if (op == "@<")
				{
					oper = sym("push_back_");
				}
				else if (op == ">@")
				{
					oper = sym("push_front_");
				}
				else if (op == "@>")
				{
					oper = sym("pop_back_");
					count = 1;
				}
				else if (op == "<@")
				{
					oper = sym("pop_front_");
					count = 1;
				}
				else if (op == "++")
				{
					oper = sym("increment_");
					count = 1;
				}
				else if (op == "--")
				{
					oper = sym("decrement_");
					count = 1;
				}
				else if (op == "?")
				{
					oper = sym("something_");
					count = 1;
				}
				else if (op == "!")
				{
					oper = sym("nothing_");
					count = 1;
				}
				else if (op == "*")
				{
					oper = sym("multiply_");
				}
				else if (op == "/")
				{
					oper = sym("divide_");
				}
				else if (op == "%")
				{
					oper = sym("modulo_");
				}
				else if (op == "+")
				{
					oper = sym("add_");
				}
				else if (op == "-")
				{
					oper = sym("subtract_");
				}
				else if (op == "<")
				{
					oper = sym("less_than_");
				}
				else if (op == ">")
				{
					oper = sym("greater_than_");
				}
				else if (op == "<=")
				{
					oper = sym("less_or_equal_");
				}
				else if (op == ">=")
				{
					oper = sym("greater_or_equal_");
				}
				else if (op == "==")
				{
					oper = sym("same_");
				}
				else if (op == "!=")
				{
					oper = sym("different_");
				}
				else if (op == "=")
				{
					oper = sym("self_assign_");
					right_to_left = true;
				}
				else if (op == "*=")
				{
					oper = sym("self_multiply_");
					right_to_left = true;
				}
				else if (op == "/=")
				{
					oper = sym("self_divide_");
					right_to_left = true;
				}
				else if (op == "%=")
				{
					oper = sym("self_modulo_");
					right_to_left = true;
				}
				else if (op == "+=")
				{
					oper = sym("self_add_");
					right_to_left = true;
				}
				else if (op == "-=")
				{
					oper = sym("self_subtract_");
					right_to_left = true;
				}
				else
				{
					throw dis("strange::parser unexpected operator:") + token.report_();
				}
				if (count == 1)
				{
					// invoke unary operator
					_next();
					auto const terms = flock_t<>::create_(initial, oper, flock_t<>::create_());
					return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), context);
				}
				else if (count == 2)
				{
					// invoke binary operator
					if (!_next())
					{
						throw dis("strange::parser binary operator with nothing following it:") + token.report_();
					}
					auto const terms = flock_t<>::create_(
						initial,
						oper,
						flock_t<>::create_(_initial(precedence + (right_to_left ? 0 : 1), context)));
					return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), context);
				}
				else if (count == 3)
				{
					// invoke ternary operator
					if (!_next())
					{
						throw dis("strange::parser ternary operator with nothing following it:") + token.report_();
					}
					auto const second = _initial(precedence + (right_to_left ? 0 : 1), context);
					if (_token.tag() != "punctuation" || _token.symbol() != ":")
					{
						auto const terms = flock_t<>::create_(initial, oper, flock_t<>::create_(second));
						return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), context);
					}
					if (!_next())
					{
						throw dis("strange::parser ternary operator with nothing following the delimiter:") + token.report_();
					}
					auto const terms = flock_t<>::create_(
						initial,
						oper,
						flock_t<>::create_(second, _initial(precedence + (right_to_left ? 0 : 1), context)));
					return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), context);
				}
				assert(count >= 1 && count <= 3);
			}
		}
		// operate with range
		auto const terms = flock_t<>::create_(initial, _initial(100, context));
		return _subsequent(min_precedence, expression_operate_range_t<>::create_(token, terms), context);
	}

	static inline bool _delimiter(std::string const& op)
	{
		return op == "," || op == ":" || op == "::" || op == ":#" || op == ":=" || op == ":<" || op == ":(" || op == ";" || op == "]" || op == "}" || op == ")" || op == "<~" || op == "~)" || op == "~]" || op == "~}";
	}

	inline flock_a<> _elements(context_ptr const& context)
	{
		bool const square = _token.symbol() == "[" || _token.symbol() == "[~";
		bool const round = _token.symbol() == "(" || _token.symbol() == "(~";
		bool const tilda = _token.symbol() == "[~" || _token.symbol() == "(~";
		bool const angle = _token.symbol() == "~>";
		auto new_fixed_herd = context->fixed;
		auto new_kind_shoal = context->kind;
		if (round)
		{
			new_fixed_herd.mutate();
			new_kind_shoal.mutate();
		}
		auto new_context = std::make_shared<context_struct>(
			context->shoal,
			context->scope,
			new_fixed_herd,
			new_kind_shoal,
			context->meta,
			context->emit);
		if (!_next())
		{
			throw dis("strange::parser " + _token.symbol() + " with nothing following it:") + _token.report_();
		}
		auto flock = flock_t<>::create_();
		if (_token.tag() == "punctuation" &&
			((square && !tilda && _token.symbol() == "]") ||
				(round && !tilda && _token.symbol() == ")") ||
				(square && tilda && _token.symbol() == "~]") ||
				(round && tilda && _token.symbol() == "~)") ||
				(angle && _token.symbol() == "<~")))
		{
			_next();
		}
		else for (;;)
		{
			if (_token.tag() == "punctuation" && _token.symbol() == "~>") // meta
			{
				flock += _meta_emissions(new_context);
			}
			else
			{
				flock.push_back(_initial(0, new_context));
			}
			if (_it == _end)
			{
				throw dis("strange::parser element with nothing following it:") + _token.report_();
			}
			if (_token.tag() != "punctuation")
			{
				throw dis("strange::parser element with non-punctuation following it:") + _token.report_();
			}
			bool const comma = _token.symbol() == ",";
			if (comma && !_next())
			{
				throw dis("strange::parser , with nothing following it:") + _token.report_();
			}
			if ((square && !tilda && _token.symbol() == "]") ||
				(round && !tilda && _token.symbol() == ")") ||
				(square && tilda && _token.symbol() == "~]") ||
				(round && tilda && _token.symbol() == "~)") ||
				(angle && _token.symbol() == "<~"))
			{
				_next();
				break;
			}
			if (!comma)
			{
				throw dis("strange::parser element with unexpected punctuation following it:") + _token.report_();
			}
		}
		return flock;
	}

	inline expression_a<> _subsequent_dot(
		int64_t const min_precedence,
		expression_a<> const& initial,
		context_ptr const& context)
	{
		auto const token = _token;
		if (token.tag() != "name")
		{
			throw dis("strange::parser . with non-name following it:") + token.report_();
		}
		auto terms = flock_t<>::create_(initial, token.symbol_());
		if (token.symbol_().last_character() != '_')
		{
			// attribute
			if (_next() && _token.tag() == "punctuation" && _token.symbol() == ":=")
			{
				if (!_next())
				{
					throw dis("strange::parser attribute assignment with nothing following it:") + token.report_();
				}
				terms.push_back(_initial(0, context)); // assignment
			}
			return _subsequent(min_precedence, expression_invoke_attribute_t<>::create_(token, terms), context);
		}
		if (!_next())
		{
			throw dis("strange::parser . with nothing following member name:") + token.report_();
		}
		if (_token.tag() == "punctuation" && _token.symbol() == "[")
		{
			terms.push_back(_elements(context));
			return _subsequent(min_precedence, expression_invoke_t<>::create_(token, terms), context);
		}
		terms.push_back(_initial(100, context));
		return _subsequent(min_precedence, expression_invoke_member_range_t<>::create_(token, terms), context);
	}

	inline expression_a<> _subsequent_dot_colon(
		int64_t const min_precedence,
		expression_a<> const& initial,
		context_ptr const& context)
	{
		auto const token = _token;
		auto second = _initial(100, context);
		if (_it != _end && _token.tag() == "punctuation" && _token.symbol() == ":.")
		{
			// member
			if (!_next())
			{
				throw dis("strange::parser :. with nothing following it:") + token.report_();
			}
			second = _subsequent_colon_dot(100, second, context);
		}
		auto terms = flock_t<>::create_(initial, second);
		if (_it == _end)
		{
			throw dis("strange::parser .: with nothing following its operation:") + token.report_();
		}
		if (_token.tag() == "punctuation" && _token.symbol() == "[")
		{
			terms += _elements(context);
			return _subsequent(min_precedence, expression_operate_t<>::create_(token, terms), context);
		}
		terms.push_back(_initial(100, context));
		return _subsequent(min_precedence, expression_operate_range_t<>::create_(token, terms), context);
	}

	inline expression_a<> _subsequent_colon_dot(
		int64_t const min_precedence,
		expression_a<> const& initial,
		context_ptr const& context)
	{
		auto const token = _token;
		if (token.tag() != "name")
		{
			throw dis("strange::parser :. with non-name following it:") + token.report_();
		}
		_next();
		auto const terms = flock_t<>::create_(initial, token.symbol_());
		return _subsequent(min_precedence, expression_member_t<>::create_(token, terms), context);
	}

	static bool const ___share___;
	friend class ___parser_t_share___;
};

template <typename ___ego___>
bool const parser_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	parser_t<___ego___>::share(shoal);
	return shoal;
}();

class ___parser_t_share___
{
	static inline bool ___share___()
	{
		return parser_t<>::___share___;
	}
};

} // namespace strange

#endif
