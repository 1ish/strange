#ifndef COM_ONEISH_STRANGE_BIDIRECTIONAL_CONST_ITERATOR_DATA_R_H
#define COM_ONEISH_STRANGE_BIDIRECTIONAL_CONST_ITERATOR_DATA_R_H

namespace strange
{

template<>
class reflection<bidirectional_const_iterator_data_a<std::set<any_a<>>::const_iterator>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::bidirectional_const_iterator_data_herd"));
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<bidirectional_const_iterator_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<bidirectional_const_iterator_a<>>::operations();
	}
};

template<>
class reflection<bidirectional_const_iterator_data_a<std::map<any_a<>, any_a<>>::const_iterator>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::bidirectional_const_iterator_data_shoal"));
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<bidirectional_const_iterator_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<bidirectional_const_iterator_a<>>::operations();
	}
};

}

#endif
