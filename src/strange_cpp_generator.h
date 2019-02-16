#ifndef COM_ONEISH_STRANGE_CPP_GENERATOR_H
#define COM_ONEISH_STRANGE_CPP_GENERATOR_H

#include "strange_core.h"
#include "strange_generator.h"
#include "strange_expression.h"

namespace strange
{
class CPPGenerator;

//----------------------------------------------------------------------
class CPPGenerator : public Generator
//----------------------------------------------------------------------
{
public:
	inline CPPGenerator(const Ptr& river)
		: Generator{ river }
	{
	}

	static inline const Ptr mut(const Ptr& it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr& ptr)
	{
		return make_<CPPGenerator>(ptr);
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Generator::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&CPPGenerator::mut, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr& shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Generator::mut", Static::fin_(&CPPGenerator::mut, "river"));
	}

	virtual inline void generate_local_code_(const Token& tok, const std::vector<Ptr>& vec, const Ptr& me, River& riv) override
	{
	}

	virtual inline void generate_thing_code_(const Token& tok, const std::vector<Ptr>& vec, const Ptr& me, River& riv) override
	{
	}

	virtual inline void generate_invoke_code_(const Token& tok, const std::vector<Ptr>& vec, const Ptr& me, River& riv) override
	{
		static_<Expression>(vec[0])->generate_(me);
		riv.write_("->invoke_(");
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
		riv.write_(")");
	}

	virtual inline const Ptr cat_() const override
	{
		static const Ptr CAT = Cat::fin_("<strange::CPPGenerator>");
		return CAT;
	}
};

//======================================================================
// class CPPGenerator
//======================================================================

} // namespace strange

#endif
