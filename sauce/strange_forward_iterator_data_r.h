#ifndef COM_ONEISH_STRANGE_FORWARD_ITERATOR_DATA_R_H
#define COM_ONEISH_STRANGE_FORWARD_ITERATOR_DATA_R_H

namespace strange
{

template<>
class reflection<forward_iterator_data_a<std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f>::iterator>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::forward_iterator_data_unordered_shoal");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<forward_iterator_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<forward_iterator_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

}

#endif
