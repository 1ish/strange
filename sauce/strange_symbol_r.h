#ifndef COM_ONEISH_STRANGE_SYMBOL_R_H
#define COM_ONEISH_STRANGE_SYMBOL_R_H

namespace strange
{

template<>
class reflection<symbol_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::symbol"));
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
			operations.update("add", native_extraction_t<symbol_a<>>::val(&symbol_a<>::add__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
