
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
inline bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > container_data_a<_type, _iterator>::extract_begin() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

template <typename _type, typename _iterator>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > container_data_a<_type, _iterator>::___container_data_a_handle___<___TTT___, ___DHB___>::extract_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

template <typename _type, typename _iterator>
inline bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > container_data_a<_type, _iterator>::extract_end() const
{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

template <typename _type, typename _iterator>
template <typename ___TTT___, typename ___DHB___>
inline bidirectional_extractor_data_a < container_data_a < _type , _iterator > , _iterator > container_data_a<_type, _iterator>::___container_data_a_handle___<___TTT___, ___DHB___>::extract_end() const
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
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ container_data_a<_type, _iterator>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = container_a<>::template ___operations___<___unordered_shoal_a___>();
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
