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
		static cat_a<> CAT = cat_t<>::val("strange::any");
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
			operations.update_string("call", native_mutation_t<any_a<>>::val(&any_a<>::operator[], "call"));
			operations.update_string("perform", native_mutation_t<any_a<>>::val(&any_a<>::operator(), "perform"));
			operations.update_string("type", native_extraction_t<any_a<>>::val(&any_a<>::type__, "type"));
			operations.update_string("shared", native_extraction_t<any_a<>>::val(&any_a<>::shared__, "shared"));
			operations.update_string("cat", native_extraction_t<any_a<>>::val(&any_a<>::cat__, "cat"));
			operations.update_string("cats", native_extraction_t<any_a<>>::val(&any_a<>::cats__, "cats"));
			operations.update_string("operations", native_extraction_t<any_a<>>::val(&any_a<>::operations__, "operations"));
			operations.update_string("eater", native_extraction_t<any_a<>>::val(&any_a<>::eater__, "eater"));
			operations.update_string("feeder", native_extraction_t<any_a<>>::val(&any_a<>::feeder__, "feeder"));
			operations.update_string("visit", native_extraction_t<any_a<>>::val(&any_a<>::visit__, "visit"));
			operations.update_string("identity", native_extraction_t<any_a<>>::val(&any_a<>::identity__, "identity"));
			operations.update_string("identical", native_extraction_t<any_a<>>::val(&any_a<>::identical__, "identical"));
			operations.update_string("nothing", native_extraction_t<any_a<>>::val(&any_a<>::nothing__, "nothing"));
			operations.update_string("something", native_extraction_t<any_a<>>::val(&any_a<>::something__, "something"));
			operations.update_string("same", native_extraction_t<any_a<>>::val(&any_a<>::same__, "same"));
			operations.update_string("different", native_extraction_t<any_a<>>::val(&any_a<>::different__, "different"));
			operations.update_string("hash", native_extraction_t<any_a<>>::val(&any_a<>::hash__, "hash"));
			operations.update_string("ranged", native_extraction_t<any_a<>>::val(&any_a<>::ranged__, "ranged"));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
