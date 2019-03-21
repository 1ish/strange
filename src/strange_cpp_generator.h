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
		static const Ptr PUB = _public_(CPPGenerator::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Generator::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&CPPGenerator::type_name));
			shoal->update_("category", Static::fin_(&CPPGenerator::category));
			shoal->update_("categories", Static::fin_(&CPPGenerator::categories));
			shoal->update_("mut", Static::fin_(&CPPGenerator::mut, "river"));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
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

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::CPPGenerator");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return CPPGenerator::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return CPPGenerator::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(CPPGenerator::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return CPPGenerator::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return CPPGenerator::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Generator::categories_()->copy_());
			categories->insert_(CPPGenerator::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return CPPGenerator::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return CPPGenerator::categories_();
	}
};

//======================================================================
// class CPPGenerator
//======================================================================

} // namespace strange

#endif
