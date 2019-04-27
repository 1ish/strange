#ifndef COM_ONEISH_STRANGE_COLLECTION_T_H
#define COM_ONEISH_STRANGE_COLLECTION_T_H

namespace strange
{

// adaptation
#define ___COLLECTION___ ___THING___ \
inline any_a has(any_a range) const \
{ \
	any_a it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		return dis__("has passed empty range"); \
	} \
	return has_(*it); \
} \
inline any_a has_(any_a key) const \
{ \
	return _boole_(has__(std::move(key))); \
} \
inline any_a at(any_a range) const \
{ \
	any_a it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		return dis__("at passed empty range"); \
	} \
	return at_(*it); \
} \
inline any_a update(any_a range) \
{ \
	any_a it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		return dis__("update passed empty range"); \
	} \
	any_a key = *it; \
	if (++it == range.cend()) \
	{ \
		return update_(key, key); \
	} \
	return update_(std::move(key), *it); \
} \
inline any_a insert(any_a range) \
{ \
	any_a it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		return dis__("insert passed empty range"); \
	} \
	any_a key = *it; \
	if (++it == range.cend()) \
	{ \
		return insert_(key, key); \
	} \
	return insert_(std::move(key), *it); \
} \
inline any_a insert_(any_a key, any_a value) \
{ \
	return _boole_(insert__(std::move(key), std::move(value))); \
} \
inline any_a erase(any_a range) \
{ \
	bool erased = false; \
	for (auto key : range) \
	{ \
		if (erase__(std::move(key))) \
		{ \
			erased = true; \
		} \
	} \
	return _boole_(erased); \
} \
inline any_a erase_(any_a key) \
{ \
	return _boole_(erase__(std::move(key))); \
} \
inline _ABSTRACTION_ clear(any_a) \
{ \
	return clear_(); \
} \
inline _ABSTRACTION_ clear_() \
{ \
	clear__(); \
	return me_(); \
} \
inline any_a size(any_a) const \
{ \
	return size_(); \
} \
inline any_a size_() const \
{ \
	return nothing_t<>::val_(); /* //TODO */ \
} \
inline any_a empty(any_a) const \
{ \
	return empty_(); \
} \
inline any_a empty_() const \
{ \
	return _boole_(empty__()); \
} \
inline _ABSTRACTION_ push_front(any_a range) \
{ \
	for (auto value : range) \
	{ \
		push_front__(std::move(value)); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ push_front_(any_a value) \
{ \
	push_front__(std::move(value)); \
	return me_(); \
} \
inline any_a pop_front(any_a) \
{ \
	return pop_front_(); \
} \
inline _ABSTRACTION_ push_back(any_a range) \
{ \
	for (auto value : range) \
	{ \
		push_back__(std::move(value)); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ push_back_(any_a value) \
{ \
	push_back__(std::move(value)); \
	return me_(); \
} \
inline any_a pop_back(any_a) \
{ \
	return pop_back_(); \
} \
inline _ABSTRACTION_ self_add(any_a range) \
{ \
	for (auto collection : range) \
	{ \
		operator+=(std::move(collection)); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ self_add_(collection_a collection) \
{ \
	operator+=(std::move(collection)); \
	return me_(); \
} \
inline _ABSTRACTION_ add(any_a range) const \
{ \
	_ABSTRACTION_ result = me_(); \
	for (auto collection : range) \
	{ \
		result += std::move(collection); \
	} \
	return result; \
} \
inline _ABSTRACTION_ add_(collection_a collection) const \
{ \
	return operator+(std::move(collection)); \
} \
inline _ABSTRACTION_ operator+(collection_a collection) const \
{ \
	_ABSTRACTION_ result = me_(); \
	result += collection; \
	return result; \
} \
inline _ABSTRACTION_ self_subtract(any_a range) \
{ \
	for (auto collection : range) \
	{ \
		operator-=(std::move(collection)); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ self_subtract_(collection_a collection) \
{ \
	operator-=(std::move(collection)); \
	return me_(); \
} \
inline _ABSTRACTION_ subtract(any_a range) const \
{ \
	_ABSTRACTION_ result = me_(); \
	for (auto collection : range) \
	{ \
		result -= std::move(collection); \
	} \
	return result; \
} \
inline _ABSTRACTION_ subtract_(collection_a collection) const \
{ \
	return operator-(std::move(collection)); \
} \
inline _ABSTRACTION_ operator-(collection_a collection) const \
{ \
	_ABSTRACTION_ result = me_(); \
	result -= collection; \
	return result; \
} \

} // namespace strange

#endif
