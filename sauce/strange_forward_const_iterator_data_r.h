#ifndef COM_ONEISH_STRANGE_FORWARD_CONST_ITERATOR_DATA_R_H
#define COM_ONEISH_STRANGE_FORWARD_CONST_ITERATOR_DATA_R_H

namespace strange
{

template<>
class reflection<forward_const_iterator_data_a<std::istreambuf_iterator<char>>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::forward_const_iterator_data_river"));
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<forward_const_iterator_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<forward_const_iterator_a<>>::operations();
	}
};

template<>
class reflection<forward_const_iterator_data_a<std::unordered_set<any_a<>, any_a<>::hash_f>::const_iterator>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::forward_const_iterator_data_unordered_herd"));
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<forward_const_iterator_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<forward_const_iterator_a<>>::operations();
	}
};

template<>
class reflection<forward_const_iterator_data_a<std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f>::const_iterator>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::forward_const_iterator_data_unordered_shoal"));
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<forward_const_iterator_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<forward_const_iterator_a<>>::operations();
	}
};

}

#endif