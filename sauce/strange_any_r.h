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
		static cat_a<> CAT = cat_t<>::val(1, "strange::any");
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

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = kinds_from_cats(cats());
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = unordered_shoal_t<>::val_();
			operations.update_string("call", native_mutation_t<any_a<>>::val(&any_a<>::operator[]));
			operations.update_string("perform", native_mutation_t<any_a<>>::val(&any_a<>::operator()));
			operations.update_string("type", native_extraction_t<any_a<>>::val(&any_a<>::type__));
			operations.update_string("shared", native_extraction_t<any_a<>>::val(&any_a<>::shared__));
			operations.update_string("cat", native_extraction_t<any_a<>>::val(&any_a<>::cat__));
			operations.update_string("cats", native_extraction_t<any_a<>>::val(&any_a<>::cats__));
			operations.update_string("operations", native_extraction_t<any_a<>>::val(&any_a<>::operations__));
			operations.update_string("eater", native_extraction_t<any_a<>>::val(&any_a<>::eater__));
			operations.update_string("feeder", native_extraction_t<any_a<>>::val(&any_a<>::feeder__));
			operations.update_string("visit", native_extraction_t<any_a<>>::val(&any_a<>::visit__));
			operations.update_string("identity", native_extraction_t<any_a<>>::val(&any_a<>::identity__));
			operations.update_string("identical", native_extraction_t<any_a<>>::val(&any_a<>::identical__));
			operations.update_string("nothing", native_extraction_t<any_a<>>::val(&any_a<>::nothing__));
			operations.update_string("something", native_extraction_t<any_a<>>::val(&any_a<>::something__));
			operations.update_string("same", native_extraction_t<any_a<>>::val(&any_a<>::same__));
			operations.update_string("different", native_extraction_t<any_a<>>::val(&any_a<>::different__));
			operations.update_string("hash", native_extraction_t<any_a<>>::val(&any_a<>::hash__));
			operations.update_string("ranged", native_extraction_t<any_a<>>::val(&any_a<>::ranged__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___any_a_share___
{
	static inline bool ___share___()
	{
		return any_a<>::___share___;
	}
};

}

#endif
