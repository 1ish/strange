#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_O_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_O_H

namespace strange
{

template<>
class reflection<misunderstanding_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::misunderstanding"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update("add", native_extraction_t<misunderstanding_a<>>::val(&misunderstanding_a<>::add__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
