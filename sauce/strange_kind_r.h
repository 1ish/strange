#ifndef COM_ONEISH_STRANGE_KIND_R_H
#define COM_ONEISH_STRANGE_KIND_R_H

namespace strange
{

template<>
class reflection<kind_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::kind");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<cat_a<>>::cats();
			cats.insert_thing(cat());
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
			auto kinds = reflection<cat_a<>>::kinds();
			kinds.insert_thing(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<cat_a<>>::operations();
			operations.update_string("aspects_", native_extraction_t<kind_a<>>::create(&kind_a<>::aspects__));
			operations.update_string("fixed_", native_extraction_t<kind_a<>>::create(&kind_a<>::fixed__));
			operations.update_string("reference_", native_extraction_t<kind_a<>>::create(&kind_a<>::reference__));
			operations.update_string("optional_", native_extraction_t<kind_a<>>::create(&kind_a<>::optional__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___kind_a_share___
{
	static inline bool ___share___()
	{
		return kind_a<>::___share___;
	}
};

}

#endif
