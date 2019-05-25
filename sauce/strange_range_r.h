#ifndef COM_ONEISH_STRANGE_RANGE_R_H
#define COM_ONEISH_STRANGE_RANGE_R_H

namespace strange
{

template<>
class reflection<range_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::range"));
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update("cbegin", native_extraction_t<range_a<>>::val(&range_a<>::cbegin__));
			operations.update("cend", native_extraction_t<range_a<>>::val(&range_a<>::cend__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
