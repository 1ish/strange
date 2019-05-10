#ifndef COM_ONEISH_STRANGE_COLLECTION_A_H
#define COM_ONEISH_STRANGE_COLLECTION_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/dderived.hpp -c ~/source/repos/strange/archetypes/collection.hpp > ~/source/repos/strange/sauce/strange_collection_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"

namespace strange
{

template <typename number_data_a_int64>
class collection_a
{
public:
	// collection
	inline any_a<> has(range_a<> const& range) const;
	inline any_a<> has_(any_a<> const& key) const;
	inline bool has__(any_a<> const& key) const;

	inline any_a<> at(range_a<> const& range) const;
	inline any_a<> at_(any_a<> const& key) const;

	inline any_a<> update(range_a<> const& range);
	inline any_a<> update_(any_a<> const& key, any_a<> const& value);

	inline any_a<> insert(range_a<> const& range);
	inline any_a<> insert_(any_a<> const& key, any_a<> const& value);
	inline bool insert__(any_a<> const& key, any_a<> const& value);

	inline any_a<> erase(range_a<> const& range);
	inline any_a<> erase_(any_a<> const& key);
	inline bool erase__(any_a<> const& key);

	inline any_a<> clear(range_a<> const& _);
	inline any_a<> clear_();
	inline void clear__();

	inline any_a<> size(range_a<> const& _) const;
	inline number_data_a_int64 size_() const;
	inline int64_t size__() const;

	inline any_a<> empty(range_a<> const& _) const;
	inline any_a<> empty_() const;
	inline bool empty__() const;

	inline any_a<> push_front(range_a<> const& range);
	inline any_a<> push_front_(any_a<> const& thing);
	inline void push_front__(any_a<> const& thing);

	inline any_a<> pop_front(range_a<> const& _);
	inline any_a<> pop_front_();

	inline any_a<> push_back(range_a<> const& range);
	inline any_a<> push_back_(any_a<> const& thing);
	inline void push_back__(any_a<> const& thing);

	inline any_a<> pop_back(range_a<> const& _);
	inline any_a<> pop_back_();

	inline any_a<> self_add(range_a<> const& range);
	inline collection_a self_add_(collection_a const& collection);

	inline any_a<> add(range_a<> const& range) const;
	inline collection_a add_(collection_a const& collection) const;
	inline collection_a operator+(collection_a const& collection) const;

	inline any_a<> self_subtract(range_a<> const& range);
	inline collection_a self_subtract_(collection_a const& collection);

	inline any_a<> subtract(range_a<> const& range) const;
	inline collection_a subtract_(collection_a const& collection) const;
	inline collection_a operator-(collection_a const& collection) const;
};

} // namespace strange

#endif
