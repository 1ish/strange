#ifndef COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_DATA_R_H
#define COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_DATA_R_H

namespace strange
{

template<>
class reflection<bidirectional_iterator_data_a<std::map<any_a<>, any_a<>>::iterator>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::bidirectional_iterator_data_shoal");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<bidirectional_iterator_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<bidirectional_iterator_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<bidirectional_iterator_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___bidirectional_iterator_data_a_share___
{
	static inline bool ___share___()
	{
		return bidirectional_iterator_data_a<std::map<any_a<>, any_a<>>::iterator>::___share___;
	}
};

}

#endif
