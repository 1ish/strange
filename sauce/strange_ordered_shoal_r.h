#ifndef COM_ONEISH_STRANGE_ORDERED_SHOAL_R_H
#define COM_ONEISH_STRANGE_ORDERED_SHOAL_R_H

namespace strange
{

template<>
class reflection<ordered_shoal_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::ordered_shoal");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<shoal_a<>>::cats();
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
			auto kinds = reflection<shoal_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<shoal_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___ordered_shoal_a_share___
{
	static inline bool ___share___()
	{
		return ordered_shoal_a<>::___share___;
	}
};

template<>
class reflection<ordered_shoal_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::ordered_shoal");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::ordered_shoal::create", native_function_t<>::create(&ordered_shoal_t<>::create__));
	}
};

template<>
class reflection<ordered_shoal_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::ordered_shoal_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::ordered_shoal_concurrent::create", native_function_t<>::create(&ordered_shoal_t<true>::create__));
	}
};

class ___ordered_shoal_t_share___
{
	static inline bool ___share___()
	{
		return ordered_shoal_t<>::___share___
			&& ordered_shoal_t<true>::___share___;
	}
};

}

#endif
