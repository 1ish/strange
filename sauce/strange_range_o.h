#ifndef COM_ONEISH_STRANGE_RANGE_O_H
#define COM_ONEISH_STRANGE_RANGE_O_H

namespace strange
{

template <typename _OVERRIDDEN_>
class range_o : public thing_o<_OVERRIDDEN_>
{
public:
	inline range_o(_OVERRIDDEN_&& overridden)
		: thing_o<_OVERRIDDEN_>{ std::move(overridden) }
	{}

	inline any_a<> cbegin__(range_a<> const&) const
	{
		return _OVERRIDDEN_::cbegin_();
	}

	inline any_a<> cend__(range_a<> const&) const
	{
		return _OVERRIDDEN_::cend_();
	}
};

} // namespace strange

#endif
