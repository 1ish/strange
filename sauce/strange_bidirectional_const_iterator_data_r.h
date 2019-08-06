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
		static cat_a<> CAT = cat_t<>::val(1, "strange::bidirectional_const_iterator_data_herd");
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

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

template<>
class reflection<bidirectional_const_iterator_data_a<std::map<any_a<>, any_a<>>::const_iterator>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::bidirectional_const_iterator_data_shoal");
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

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___bidirectional_const_iterator_data_a_share___
{
	static inline bool ___share___()
	{
		return bidirectional_const_iterator_data_a<std::set<any_a<>>::const_iterator>::___share___
			&& bidirectional_const_iterator_data_a<std::map<any_a<>, any_a<>>::const_iterator>::___share___;
	}
};

}

#endif
