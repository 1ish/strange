#ifndef COM_ONEISH_STRANGE_EXPRESSION_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_R_H

namespace strange
{

template<>
class reflection<expression_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::expression");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<operation_a<>>::cats();
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
			auto kinds = reflection<operation_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<operation_a<>>::operations();
			operations.update_string("evaluate", native_extraction_t<expression_a<>>::create(&expression_a<>::evaluate__));
			operations.update_string("token", native_extraction_t<expression_a<>>::create(&expression_a<>::token__));
			operations.update_string("terms", native_extraction_t<expression_a<>>::create(&expression_a<>::terms__));
			operations.update_string("generate", native_extraction_t<expression_a<>>::create(&expression_a<>::generate__));
			operations.update_string("generate_cpp", native_extraction_t<expression_a<>>::create(&expression_a<>::generate_cpp__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___expression_a_share___
{
	static inline bool ___share___()
	{
		return expression_a<>::___share___;
	}
};

template<>
class reflection<expression_c<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("<strange::expression>");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("<strange::expression>::animate", native_function_t<>::create(&expression_c<>::animate__));
	}
};

class ___expression_c_share___
{
	static inline bool ___share___()
	{
		return expression_c<>::___share___;
	}
};

template<>
class reflection<expression_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression::create", native_function_t<>::create(&expression_t<>::over::create__));
	}
};

class ___expression_t_share___
{
	static inline bool ___share___()
	{
		return expression_t<>::___share___;
	}
};

}

#endif
