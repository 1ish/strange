
namespace strange
{

template <typename _type, typename _iterator>
inline bool container_data_a<_type, _iterator>::operator==(container_data_a < _type , _iterator > const & container ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(container); }

template <typename _type, typename _iterator>
template <typename ___TTT___, typename ___DHB___>
inline bool container_data_a<_type, _iterator>::___container_data_a_handle___<___TTT___, ___DHB___>::operator==(container_data_a < _type , _iterator > const & container ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(container); }

template <typename _type, typename _iterator>
inline bool container_data_a<_type, _iterator>::operator!=(container_data_a < _type , _iterator > const & container ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(container); }

template <typename _type, typename _iterator>
template <typename ___TTT___, typename ___DHB___>
inline bool container_data_a<_type, _iterator>::___container_data_a_handle___<___TTT___, ___DHB___>::operator!=(container_data_a < _type , _iterator > const & container ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(container); }

template <typename _type, typename _iterator>
inline bidirectional_extractor_data_a < any_a < > , _iterator > container_data_a<_type, _iterator>::keys_begin() const
{ assert(any_a<>::___handle___); return ___read___().keys_begin(); }

template <typename _type, typename _iterator>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < any_a < > , _iterator > container_data_a<_type, _iterator>::___container_data_a_handle___<___TTT___, ___DHB___>::keys_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.keys_begin(); }

template <typename _type, typename _iterator>
inline bidirectional_extractor_data_a < any_a < > , _iterator > container_data_a<_type, _iterator>::keys_end() const
{ assert(any_a<>::___handle___); return ___read___().keys_end(); }

template <typename _type, typename _iterator>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < any_a < > , _iterator > container_data_a<_type, _iterator>::___container_data_a_handle___<___TTT___, ___DHB___>::keys_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.keys_end(); }

template <typename _type, typename _iterator>
inline bidirectional_extractor_data_a < container_a < > , _iterator > container_data_a<_type, _iterator>::extract_begin() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

template <typename _type, typename _iterator>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < container_a < > , _iterator > container_data_a<_type, _iterator>::___container_data_a_handle___<___TTT___, ___DHB___>::extract_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

template <typename _type, typename _iterator>
inline bidirectional_extractor_data_a < container_a < > , _iterator > container_data_a<_type, _iterator>::extract_end() const
{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

template <typename _type, typename _iterator>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < container_a < > , _iterator > container_data_a<_type, _iterator>::___container_data_a_handle___<___TTT___, ___DHB___>::extract_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

template <typename _type, typename _iterator>
inline _type const & container_data_a<_type, _iterator>::extract_packet() const
{ assert(any_a<>::___handle___); return ___read___().extract_packet(); }

template <typename _type, typename _iterator>
template <typename ___TTT___, typename ___DHB___>
inline _type const & container_data_a<_type, _iterator>::___container_data_a_handle___<___TTT___, ___DHB___>::extract_packet() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_packet(); }

template <typename _type, typename _iterator>
inline _type & container_data_a<_type, _iterator>::mutate_packet()
{ assert(any_a<>::___handle___); return ___write___().mutate_packet(); }

template <typename _type, typename _iterator>
template <typename ___TTT___, typename ___DHB___>
inline _type & container_data_a<_type, _iterator>::___container_data_a_handle___<___TTT___, ___DHB___>::mutate_packet()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_packet(); }

template <typename _type, typename _iterator>
inline cat_a<> container_data_a<_type, _iterator>::___cat___()
{
	static cat_a<> CAT = cat_create(1, "strange::container_data", flock::create_vals(kind_create(2, ""), kind_create(2, "")));
	return CAT;
}

template <typename _type, typename _iterator>
inline unordered_herd_a<> container_data_a<_type, _iterator>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = container_a<>::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _type, typename _iterator>
inline kind_a<> container_data_a<_type, _iterator>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___(), flock::create_vals(kind_of<_type>(), kind_of<_iterator>()));
	return KIND;
}

template <typename _type, typename _iterator>
inline unordered_herd_a<> container_data_a<_type, _iterator>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = container_a<>::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _type, typename _iterator>
inline unordered_shoal_a<> container_data_a<_type, _iterator>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = container_a<>::___operations___();
		return operations;
	}();
	return OPERATIONS;
}

class ___container_data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___container_data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _type, typename _iterator>
inline container_data_d<_type, _iterator> ___container_data_dynamic___(any_a<> const& thing)
{
	return container_data_d<_type, _iterator>{ thing };
}

} // namespace
