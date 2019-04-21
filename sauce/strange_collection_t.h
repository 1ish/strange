#ifndef COM_ONEISH_STRANGE_COLLECTION_T_H
#define COM_ONEISH_STRANGE_COLLECTION_T_H

namespace strange
{

template <typename _ABSTRACTION_>
class collection_t : public something_t<_ABSTRACTION_>
{
public:
	// comparison
	inline bool operator==(any_a thing) const
	{
		return false; //TODO
	}

	inline bool operator!=(any_a thing) const
	{
		return true; //TODO
	}

	inline std::size_t hash__() const
	{
		return 0; //TODO
	}

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

	inline any_a push_front(any_a range);
	inline any_a push_front_(any_a thing);

	inline any_a pop_front(any_a _);
	inline any_a pop_front_();

	inline any_a push_back(any_a range);
	inline any_a push_back_(any_a thing);

	inline any_a pop_back(any_a _);
	inline any_a pop_back_();

	inline collection_a self_add(any_a range);
	inline collection_a self_add_(collection_a collection);
	inline collection_a& operator+=(collection_a collection);

	inline collection_a add(any_a range) const;
	inline collection_a add_(collection_a collection) const;
	inline collection_a operator+(collection_a collection) const;

	inline collection_a self_subtract(any_a range);
	inline collection_a self_subtract_(collection_a collection);
	inline collection_a& operator-=(collection_a collection);

	inline collection_a subtract(any_a range) const;
	inline collection_a subtract_(collection_a collection) const;
	inline collection_a operator-(collection_a collection) const;

protected:
	inline collection_t()
		: something_t{}
	{}
};

} // namespace strange

#endif
