
namespace strange
{

template <typename _1>
inline any_a<> expression_a<_1>::recreate__(list_a<> const& ___arguments___) const
{
	return recreate_();
}

template <typename _1>
inline expression_a<> expression_a<_1>::recreate_() const
{ assert(any_a<>::___handle___); return ___read___().recreate_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline expression_a<> expression_a<_1>::___expression_a_handle___<___TTT___, ___DHB___>::recreate_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.recreate_(); }

template <typename _1>
inline any_a<> expression_a<_1>::literal__(list_a<> const& ___arguments___) const
{
	return literal_();
}

template <typename _1>
inline any_a<> expression_a<_1>::literal_() const
{ assert(any_a<>::___handle___); return ___read___().literal_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> expression_a<_1>::___expression_a_handle___<___TTT___, ___DHB___>::literal_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.literal_(); }

template <typename _1>
inline bool expression_a<_1>::literal() const
{ assert(any_a<>::___handle___); return ___read___().literal(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool expression_a<_1>::___expression_a_handle___<___TTT___, ___DHB___>::literal() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.literal(); }

template <typename _1>
inline any_a<> expression_a<_1>::evaluate__(list_a<> const& ___arguments___) const
{
	return evaluate_();
}

template <typename _1>
inline any_a<> expression_a<_1>::evaluate_() const
{ assert(any_a<>::___handle___); return ___read___().evaluate_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> expression_a<_1>::___expression_a_handle___<___TTT___, ___DHB___>::evaluate_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.evaluate_(); }

template <typename _1>
inline any_a<> expression_a<_1>::token__(list_a<> const& ___arguments___) const
{
	return token_();
}

template <typename _1>
inline token_a<> expression_a<_1>::token_() const
{ assert(any_a<>::___handle___); return ___read___().token_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline token_a<> expression_a<_1>::___expression_a_handle___<___TTT___, ___DHB___>::token_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.token_(); }

template <typename _1>
inline any_a<> expression_a<_1>::terms__(list_a<> const& ___arguments___) const
{
	return terms_();
}

template <typename _1>
inline flock_a<> expression_a<_1>::terms_() const
{ assert(any_a<>::___handle___); return ___read___().terms_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline flock_a<> expression_a<_1>::___expression_a_handle___<___TTT___, ___DHB___>::terms_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.terms_(); }

template <typename _1>
inline any_a<> expression_a<_1>::generate__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "expression_a::generate_ passed short range");
	}
	auto version = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "expression_a::generate_ passed short range");
	}
	auto indent = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "expression_a::generate_ passed short range");
	}
	auto river = cast_dup<river_a<>>(*___it___);
	return generate_(version, indent, river);
}

template <typename _1>
inline any_a<> expression_a<_1>::generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const
{ assert(any_a<>::___handle___); return ___read___().generate_(version, indent, river); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> expression_a<_1>::___expression_a_handle___<___TTT___, ___DHB___>::generate_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.generate_(version, indent, river); }

template <typename _1>
inline void expression_a<_1>::generate(int64_t version , int64_t indent , river_a < > & river ) const
{ assert(any_a<>::___handle___); ___read___().generate(version, indent, river); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void expression_a<_1>::___expression_a_handle___<___TTT___, ___DHB___>::generate(int64_t version , int64_t indent , river_a < > & river ) const
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.generate(version, indent, river); }

template <typename _1>
inline any_a<> expression_a<_1>::generate_cpp__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "expression_a::generate_cpp_ passed short range");
	}
	auto version = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "expression_a::generate_cpp_ passed short range");
	}
	auto indent = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "expression_a::generate_cpp_ passed short range");
	}
	auto river = cast_dup<river_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "expression_a::generate_cpp_ passed short range");
	}
	auto declare = cast<any_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "expression_a::generate_cpp_ passed short range");
	}
	auto define = cast<any_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		return generate_cpp_(version, indent, river, declare, define);
	}
	auto type = cast<any_a<>>(*___it___);
	return generate_cpp_(version, indent, river, declare, define, type);
}

template <typename _1>
inline any_a<> expression_a<_1>::generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type) const
{ assert(any_a<>::___handle___); return ___read___().generate_cpp_(version, indent, river, declare, define, type); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> expression_a<_1>::___expression_a_handle___<___TTT___, ___DHB___>::generate_cpp_(number_data_int64_a<> const& version, number_data_int64_a<> const& indent, river_a<> & river, any_a<> const& declare, any_a<> const& define, any_a<> const& type) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.generate_cpp_(version, indent, river, declare, define, type); }

template <typename _1>
inline void expression_a<_1>::generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type ) const
{ assert(any_a<>::___handle___); ___read___().generate_cpp(version, indent, river, declare, define, type); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void expression_a<_1>::___expression_a_handle___<___TTT___, ___DHB___>::generate_cpp(int64_t version , int64_t indent , river_a < > & river , bool declare , bool define , bool type ) const
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.generate_cpp(version, indent, river, declare, define, type); }

template <typename _1>
inline cat_a<> expression_a<_1>::___cat___()
{
	static cat_a<> CAT = cat_create(1, "strange::expression");
	return CAT;
}

template <typename _1>
inline unordered_herd_a<> expression_a<_1>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = operation_a<>::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _1>
inline kind_a<> expression_a<_1>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___());
	return KIND;
}

template <typename _1>
inline unordered_herd_a<> expression_a<_1>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = operation_a<>::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _1>
inline unordered_shoal_a<> expression_a<_1>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = operation_a<>::___operations___();
		operations.update(sym("recreate_"), native_extraction::create(&expression_a::recreate__));
		operations.update(sym("literal_"), native_extraction::create(&expression_a::literal__));
		operations.update(sym("evaluate_"), native_extraction::create(&expression_a::evaluate__));
		operations.update(sym("token_"), native_extraction::create(&expression_a::token__));
		operations.update(sym("terms_"), native_extraction::create(&expression_a::terms__));
		operations.update(sym("generate_"), native_extraction::create(&expression_a::generate__));
		operations.update(sym("generate_cpp_"), native_extraction::create(&expression_a::generate_cpp__));
		return operations;
	}();
	return OPERATIONS;
}

class ___expression_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___expression_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline expression_d<_1> ___expression_dynamic___(any_a<> const& thing)
{
	return expression_d<_1>{ thing };
}

} // namespace
