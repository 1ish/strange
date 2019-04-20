#ifndef COM_ONEISH_STRANGE_COLLECTION_A_H
#define COM_ONEISH_STRANGE_COLLECTION_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/collection.hpp > ~/source/repos/strange/sauce/strange_collection_a.h
*/

#include "any.hpp"

namespace strange
{

class collection
{
public:
	// collection
	inline any_a at(any_a range) const;
	inline any_a at_(any_a key) const;
	inline const any_a& operator[](any_a key) const;

	inline any_a update(any_a range);
	inline any_a update_(any_a key, any_a value);
	inline any_a& operator[](any_a key);

	inline any_a insert(any_a range);
	inline any_a insert_(any_a key, any_a value);
	inline bool insert__(any_a key, any_a value);

	inline any_a erase(any_a range);
	inline any_a erase_(any_a key);
	inline bool erase__(any_a key);

	inline any_a clear(any_a _);
	inline any_a clear_();
	inline void clear__();

	inline any_a size(any_a _) const;
	inline any_a size_() const;
	inline std::size_t size__() const;

	inline any_a empty(any_a _) const;
	inline any_a empty_() const;
	inline bool empty__() const;

	inline collection_a self_add(any_a range);
	inline collection_a self_add_(collection_a collection);

	inline collection_a add(any_a range) const;
	inline collection_a add_(collection_a collection) const;
	inline collection_a operator+(collection_a collection) const;
};

} // namespace strange

#endif
