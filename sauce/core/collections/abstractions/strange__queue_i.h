#ifndef COM_ONEISH__STRANGE__QUEUE_I_H
#define COM_ONEISH__STRANGE__QUEUE_I_H

namespace strange
{
	template <typename base_d, typename element_d>
	inline var<random_access_range_a<element_d>> queue_c<base_d, element_d>::range() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->range(me);
	}

	template <typename base_d, typename element_d>
	inline rat<random_access_extractor_a<element_d>> queue_c<base_d, element_d>::begin() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->begin(me);
	}

	template <typename base_d, typename element_d>
	inline rat<random_access_extractor_a<element_d>> queue_c<base_d, element_d>::end() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->end(me);
	}

	template <typename base_d, typename element_d>
	inline var<random_access_mutator_range_a<element_d>> queue_v<base_d, element_d>::mutator_range() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->mutator_range(me);
	}

	template <typename base_d, typename element_d>
	inline rat<random_access_mutator_a<element_d>> queue_v<base_d, element_d>::mutator_begin() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->mutator_begin(me);
	}

	template <typename base_d, typename element_d>
	inline rat<random_access_mutator_a<element_d>> queue_v<base_d, element_d>::mutator_end() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->mutator_end(me);
	}
}

#endif
