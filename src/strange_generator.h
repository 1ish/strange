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

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Generator");
		return TYPE;
	}

	virtual inline const Ptr cat_() const override
	{
		static const Ptr CAT = Cat::fin_(Generator::type_());
		return CAT;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = [this]()
		{
			const Ptr cats = Herd::mut_();
			const auto herd = static_<Herd>(cats);
			herd->self_add_(Stateful::categories_());
			herd->insert_(Generator::cat_());
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

protected:
	Ptr _river;
};

//======================================================================
// class Generator
//======================================================================

} // namespace strange

#endif
