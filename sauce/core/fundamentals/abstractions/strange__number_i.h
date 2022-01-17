#ifndef COM_ONEISH__STRANGE__NUMBER_I_H
#define COM_ONEISH__STRANGE__NUMBER_I_H

namespace strange
{
	template <typename base_d, typename type_d>
	inline bool number_c<base_d, type_d>::equal(con<number_a<type_d>> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->equal(me, other);
	}

	template <typename base_d, typename type_d>
	inline bool number_c<base_d, type_d>::not_equal(con<number_a<type_d>> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->not_equal(me, other);
	}

	template <typename base_d, typename type_d>
	inline bool number_c<base_d, type_d>::less(con<number_a<type_d>> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->less(me, other);
	}

	template <typename base_d, typename type_d>
	inline bool number_c<base_d, type_d>::greater(con<number_a<type_d>> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->greater(me, other);
	}

	template <typename base_d, typename type_d>
	inline bool number_c<base_d, type_d>::less_or_equal(con<number_a<type_d>> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->less_or_equal(me, other);
	}

	template <typename base_d, typename type_d>
	inline bool number_c<base_d, type_d>::greater_or_equal(con<number_a<type_d>> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->greater_or_equal(me, other);
	}

	template <typename base_d, typename type_d>
	inline var<data_a<type_d>> number_c<base_d, type_d>::data() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->data(me);
	}

	template <typename base_d, typename type_d>
	inline type_d const& number_c<base_d, type_d>::extract() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->extract(me);
	}

	template <typename base_d, typename type_d>
	inline rat<random_access_extractor_a<type_d>> number_c<base_d, type_d>::extractor() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->extractor(me);
	}

	template <typename base_d, typename type_d>
	inline type_d& number_v<base_d, type_d>::mutate() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->mutate(me);
	}

	template <typename type_d>
	inline bool number_o<type_d>::not_equal(con<number_a<type_d>> const& me,
		con<number_a<type_d>> const& other)
	{
		return !me.o->equal(me, other);
	}

	template <typename type_d>
	inline bool number_o<type_d>::greater(con<number_a<type_d>> const& me,
		con<number_a<type_d>> const& other)
	{
		return !me.o->less_or_equal(me, other);
	}

	template <typename type_d>
	inline bool number_o<type_d>::greater_or_equal(con<number_a<type_d>> const& me,
		con<number_a<type_d>> const& other)
	{
		return !me.o->less(me, other);
	}
}

#endif
