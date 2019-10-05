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
		static cat_a<> CAT = cat_t<>::create(1, "strange::forward_iterator_data_unordered_shoal");
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

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<forward_iterator_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<forward_iterator_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___forward_iterator_data_a_share___
{
	static inline bool ___share___()
	{
		return forward_iterator_data_a<std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f>::iterator>::___share___;
	}
};

}

#endif
