#ifndef COM_ONEISH_STRANGE_ANY_R_H
#define COM_ONEISH_STRANGE_ANY_R_H

namespace strange
{

template<>
class reflection<any_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::any"));
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = unordered_herd_t<>::val_();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = unordered_shoal_t<>::val_();
			operations.update("type", native_extraction_t<any_a<>>::val(&any_a<>::type__));
			operations.update("cat", native_extraction_t<any_a<>>::val(&any_a<>::cat__));
			operations.update("operations", native_extraction_t<any_a<>>::val(&any_a<>::operations__));
			operations.update("eater", native_extraction_t<any_a<>>::val(&any_a<>::eater__));
			operations.update("feeder", native_extraction_t<any_a<>>::val(&any_a<>::feeder__));
			operations.update("visit", native_mutation_t<any_a<>>::val(&any_a<>::visit__));
			operations.update("invoke", native_extraction_t<any_a<>>::val(&any_a<>::invoke__));
			operations.update("operate", native_extraction_t<any_a<>>::val(&any_a<>::operate__));
			operations.update("identical", native_extraction_t<any_a<>>::val(&any_a<>::identical__));
			operations.update("nothing", native_extraction_t<any_a<>>::val(&any_a<>::nothing__));
			operations.update("everything", native_extraction_t<any_a<>>::val(&any_a<>::everything__));
			operations.update("operation", native_extraction_t<any_a<>>::val(&any_a<>::operation__));
			operations.update("same", native_extraction_t<any_a<>>::val(&any_a<>::same__));
			operations.update("different", native_extraction_t<any_a<>>::val(&any_a<>::different__));
			operations.update("hash", native_extraction_t<any_a<>>::val(&any_a<>::hash__));
			operations.update("ranged", native_extraction_t<any_a<>>::val(&any_a<>::ranged__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
