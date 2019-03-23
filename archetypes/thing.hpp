#ifndef COM_ONEISH_STRANGE_THING_H
#define COM_ONEISH_STRANGE_THING_H

// export PATH=$PATH:/c/Users/oneish/source/repos/type_erasure/windows
// ./emtypen.exe -c --form cow.hpp ../../strange/archetypes/thing.hpp > ../../strange/sauce/strange_thing.h

namespace strange
{

class Thing
{
public:
	Thing operator()(Thing thing);
	Thing begin(Thing thing);
	Thing end(Thing thing);
	Thing get(Thing thing);
	Thing set(Thing thing);

	Thing& operator*();
	const Thing& operator*() const;
	Thing* operator->();
	const Thing* operator->() const;
};

} // namespace strange

#endif
