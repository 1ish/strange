#ifndef COM_ONEISH_STRANGE_COLLECTION_T_H
#define COM_ONEISH_STRANGE_COLLECTION_T_H

namespace strange
{

template <typename _ABSTRACTION_>
class collection_t : public something_t<_ABSTRACTION_>
{
protected:
	inline collection_t()
		: something_t{}
	{}
};

// adaptation
#define ___COLLECTION___ ___THING___ \
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
	return update_(key, *it); \
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
	return insert_(key, *it); \
} \
inline any_a insert_(any_a key, any_a value) \
{ \
	return _boole_(insert__(key, value)); \
} \
inline any_a erase(any_a range) \
{ \
	bool erased = false; \
	for (const auto key : range) \
	{ \
		if (erase__(key)) \
		{ \
			erased = true; \
		} \
	} \
	return _boole_(erased); \
} \
inline any_a erase_(any_a key) \
{ \
	return _boole_(erase__(key)); \
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
	for (const auto value : range) \
	{ \
		push_front__(value); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ push_front_(any_a value) \
{ \
	push_front__(value); \
	return me_(); \
} \
inline any_a pop_front(any_a) \
{ \
	return pop_front_(); \
} \
inline _ABSTRACTION_ push_back(any_a range) \
{ \
	for (const auto value : range) \
	{ \
		push_back__(value); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ push_back_(any_a value) \
{ \
	push_back__(value); \
	return me_(); \
} \
inline any_a pop_back(any_a) \
{ \
	return pop_back_(); \
} \
inline _ABSTRACTION_ self_add(any_a range) \
{ \
	for (const auto collection : range) \
	{ \
		operator+=(collection); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ self_add_(collection_a collection) \
{ \
	operator+=(collection); \
	return me_(); \
} \
inline _ABSTRACTION_ add(any_a range) const \
{ \
	_ABSTRACTION_ result = me_(); \
	for (const auto collection : range) \
	{ \
		result += collection; \
	} \
	return result; \
} \
inline _ABSTRACTION_ add_(collection_a collection) const \
{ \
	return operator+(collection); \
} \
inline _ABSTRACTION_ operator+(collection_a collection) const \
{ \
	_ABSTRACTION_ result = me_(); \
	result += collection; \
	return result; \
} \
inline _ABSTRACTION_ self_subtract(any_a range) \
{ \
	for (const auto collection : range) \
	{ \
		operator-=(collection); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ self_subtract_(collection_a collection) \
{ \
	operator-=(collection); \
	return me_(); \
} \
inline _ABSTRACTION_ subtract(any_a range) const \
{ \
	_ABSTRACTION_ result = me_(); \
	for (const auto collection : range) \
	{ \
		result -= collection; \
	} \
	return result; \
} \
inline _ABSTRACTION_ subtract_(collection_a collection) const \
{ \
	return operator-(collection); \
} \
inline _ABSTRACTION_ operator-(collection_a collection) const \
{ \
	_ABSTRACTION_ result = me_(); \
	result -= collection; \
	return result; \
} \

} // namespace strange

#endif
