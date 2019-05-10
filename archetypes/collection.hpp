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
	inline any_a<> has__(range_a<> const& range) const;
	inline any_a<> has_(any_a<> const& key) const;
	inline bool has(any_a<> const& key) const;

	inline any_a<> at__(range_a<> const& range) const;
	inline any_a<> at_(any_a<> const& key) const;

	inline any_a<> update__(range_a<> const& range);
	inline any_a<> update_(any_a<> const& key, any_a<> const& value);

	inline any_a<> insert__(range_a<> const& range);
	inline any_a<> insert_(any_a<> const& key, any_a<> const& value);
	inline bool insert(any_a<> const& key, any_a<> const& value);

	inline any_a<> erase__(range_a<> const& range);
	inline any_a<> erase_(any_a<> const& key);
	inline bool erase(any_a<> const& key);

	inline any_a<> clear__(range_a<> const& _);
	inline any_a<> clear_();
	inline void clear();

	inline any_a<> size__(range_a<> const& _) const;
	inline number_data_a_int64 size_() const;
	inline int64_t size() const;

	inline any_a<> empty__(range_a<> const& _) const;
	inline any_a<> empty_() const;
	inline bool empty() const;

	inline any_a<> push_front__(range_a<> const& range);
	inline any_a<> push_front_(any_a<> const& thing);
	inline void push_front(any_a<> const& thing);

	inline any_a<> pop_front__(range_a<> const& _);
	inline any_a<> pop_front_();

	inline any_a<> push_back__(range_a<> const& range);
	inline any_a<> push_back_(any_a<> const& thing);
	inline void push_back(any_a<> const& thing);

	inline any_a<> pop_back__(range_a<> const& _);
	inline any_a<> pop_back_();

	inline any_a<> self_add__(range_a<> const& range);
	inline collection_a self_add_(collection_a const& collection);

	inline any_a<> add__(range_a<> const& range) const;
	inline collection_a add_(collection_a const& collection) const;
	inline collection_a operator+(collection_a const& collection) const;

	inline any_a<> self_subtract__(range_a<> const& range);
	inline collection_a self_subtract_(collection_a const& collection);

	inline any_a<> subtract__(range_a<> const& range) const;
	inline collection_a subtract_(collection_a const& collection) const;
	inline collection_a operator-(collection_a const& collection) const;
};

} // namespace strange

#endif
