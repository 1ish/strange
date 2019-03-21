#ifndef COM_ONEISH_STRANGE_GENERATOR_H
#define COM_ONEISH_STRANGE_GENERATOR_H

#include "strange_core.h"
#include "strange_expression.h"

namespace strange
{
class Generator;

//----------------------------------------------------------------------
class Generator : public Stateful
//----------------------------------------------------------------------
{
public:
	inline Generator(const Ptr& river)
		: Stateful{}
		, _river{ river }
	{
	}

	static inline const Ptr mut(const Ptr& it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr& ptr)
	{
		return make_<Generator>(ptr);
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			const auto shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&Generator::mut, "river"));
			shoal->update_("set", Member<Generator>::fin_(&Generator::set, "river"));
			shoal->update_("get", Const<Generator>::fin_(&Generator::get));
			shoal->update_("generate_local_code", Member<Generator>::fin_(&Generator::generate_local_code, "token", "flock"));
			shoal->update_("generate_thing_code", Member<Generator>::fin_(&Generator::generate_thing_code, "token", "flock"));
			shoal->update_("generate_invoke_code", Member<Generator>::fin_(&Generator::generate_invoke_code, "token", "flock"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Generator::mut", Static::fin_(&Generator::mut, "river"));
	}

	inline void set_(const Ptr& river)
	{
		_river = river;
	}

	inline const Ptr set(const Ptr& it)
	{
		const Ptr ptr = it->next_();
		set_(ptr);
		return ptr;
	}

	inline const Ptr get_() const
	{
		return _river;
	}

	inline const Ptr get(const Ptr& ignore) const
	{
		return get_();
	}

	virtual inline void generate_local_code_(const Token& tok, const std::vector<Ptr>& vec, const Ptr& me, River& riv)
	{

	}

	inline const Ptr generate_local_code(const Ptr& it)
	{
		const Token& tok = *static_<Token>(it->next_());
		generate_local_code_(tok, static_<Flock>(it->next_())->get_(), me_(), *static_<River>(_river));
		return _river;
	}

	virtual inline void generate_thing_code_(const Token& tok, const std::vector<Ptr>& vec, const Ptr& me, River& riv)
	{

	}

	inline const Ptr generate_thing_code(const Ptr& it)
	{
		const Token& tok = *static_<Token>(it->next_());
		generate_thing_code_(tok, static_<Flock>(it->next_())->get_(), me_(), *static_<River>(_river));
		return _river;
	}

	virtual inline void generate_invoke_code_(const Token& tok, const std::vector<Ptr>& vec, const Ptr& me, River& riv)
	{
		static_<Expression>(vec[0])->generate_(me);
		riv.write_("[");
		bool first = true;
		for (std::size_t i = 1; i < vec.size(); ++i)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				riv.write_(",");
			}
			static_<Expression>(vec[i])->generate_(me);
		}
		riv.write_("]");
	}

	inline const Ptr generate_invoke_code(const Ptr& it)
	{
		const Token& tok = *static_<Token>(it->next_());
		generate_thing_code_(tok, static_<Flock>(it->next_())->get_(), me_(), *static_<River>(_river));
		return _river;
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Generator");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Generator::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Generator::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Generator::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Generator::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Generator::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Stateful::categories_()->copy_());
			categories->insert_(Generator::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Generator::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Generator::categories_();
	}

protected:
	Ptr _river;
};

//======================================================================
// class Generator
//======================================================================

} // namespace strange

#endif
