#ifndef COM_ONEISH_STRANGE_BIDIRECTIONAL_CONST_ITERATOR_R_H
#define COM_ONEISH_STRANGE_BIDIRECTIONAL_CONST_ITERATOR_R_H

namespace strange
{

template<>
class reflection<bidirectional_const_iterator_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::bidirectional_const_iterator");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<forward_const_iterator_a<>>::cats();
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
			auto kinds = reflection<forward_const_iterator_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<forward_const_iterator_a<>>::operations();
			operations.update_string("decrement_", native_mutation_t<bidirectional_const_iterator_a<>>::create(&bidirectional_const_iterator_a<>::decrement__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___bidirectional_const_iterator_a_share___
{
	static inline bool ___share___()
	{
		return bidirectional_const_iterator_a<>::___share___;
	}
};

}

#endif
