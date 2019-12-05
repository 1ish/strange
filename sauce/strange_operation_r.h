#ifndef COM_ONEISH_STRANGE_OPERATION_R_H
#define COM_ONEISH_STRANGE_OPERATION_R_H

namespace strange
{

template<>
class reflection<operation_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::operation");
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

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<any_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update_string("pure_", native_extraction_t<operation_a<>>::create(&operation_a<>::pure__));
			operations.update_string("literal_", native_extraction_t<operation_a<>>::create(&operation_a<>::literal__));
			operations.update_string("eater_", native_extraction_t<operation_a<>>::create(&operation_a<>::eater__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___operation_a_share___
{
	static inline bool ___share___()
	{
		return operation_a<>::___share___;
	}
};

template<>
class reflection<operation_c<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("<strange::operation>");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("<strange::operation>::animate", native_function_t<>::create(&operation_c<>::animate__));
	}
};

class ___operation_c_share___
{
	static inline bool ___share___()
	{
		return operation_c<>::___share___;
	}
};

}

#endif
