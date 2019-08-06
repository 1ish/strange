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
		static cat_a<> CAT = cat_t<>::val(1, "strange::kind");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<cat_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<cat_a<>>::operations();
			operations.update_string("aspects", native_extraction_t<kind_a<>>::val(&kind_a<>::aspects__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___kind_a_share___
{
	static inline bool ___share___()
	{
		return kind_a<>::___share___;
	}
};
/* //TODO
template<>
class reflection<kind_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::kind");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::kind::val", native_function_t<>::val(&kind_t<>::val__));
	}
};

class ___kind_t_share___
{
	static inline bool ___share___()
	{
		return kind_t<>::___share___;
	}
};
*/
}

#endif
