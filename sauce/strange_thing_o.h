#ifndef COM_ONEISH_STRANGE_THING_O_H
#define COM_ONEISH_STRANGE_THING_O_H

namespace strange
{
	
template <typename _OVERRIDDEN_>
class thing_o : public _OVERRIDDEN_
{
public:
	inline thing_o(_OVERRIDDEN_&& overridden)
		: _OVERRIDDEN_{ std::move(overridden) }
	{}

	inline bool different_(any_a<> const& thing) const
	{
		return !_OVERRIDDEN_::same_(thing);
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(_OVERRIDDEN_::hash()));
	}
};

} // namespace strange

#endif
