#ifndef COM_ONEISH_STRANGE_SQUAD_R_H
#define COM_ONEISH_STRANGE_SQUAD_R_H

namespace strange
{

template<>
class reflection<squad_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::squad");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<inventory_a<>>::cats();
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
			auto kinds = reflection<inventory_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<inventory_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___squad_a_share___
{
	static inline bool ___share___()
	{
		return squad_a<>::___share___;
	}
};

template<>
class reflection<squad_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::squad");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::squad::create", native_function_t<>::create(&squad_t<>::create__));
	}
};

template<>
class reflection<squad_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::squad_concurrent");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::squad_concurrent::create", native_function_t<>::create(&squad_t<true>::create__));
	}
};

class ___squad_t_share___
{
	static inline bool ___share___()
	{
		return squad_t<>::___share___
			&& squad_t<true>::___share___;
	}
};

}

#endif
