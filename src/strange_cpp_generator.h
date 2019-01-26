#ifndef COM_ONEISH_STRANGE_CPP_GENERATOR_H
#define COM_ONEISH_STRANGE_CPP_GENERATOR_H

#include "strange_core.h"
#include "strange_generator.h"
#include "strange_expression.h"

namespace strange
{
	class CPPGenerator;

	// Categories:
	// private typedefs
	// protected typedefs
	// public typedefs
	// public static utility functions
	// public static factory functions
	// public static symbols
	// public construction/destruction/assignment
	// public pure virtual member functions and adapters
	// public impure virtual member functions and adapters
	// public non-virtual member functions and adapters
	// protected static utility functions
	// protected static factory functions
	// protected static symbols
	// protected construction/destruction/assignment
	// protected pure virtual member functions and adapters
	// protected impure virtual member functions and adapters
	// protected non-virtual member functions and adapters
	// private static utility functions
	// private static factory functions
	// private static symbols
	// private construction/destruction/assignment
	// private pure virtual member functions and adapters
	// private impure virtual member functions and adapters
	// private non-virtual member functions and adapters

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

	virtual inline const Ptr generate_local_code(const Ptr& it) override
	{
		River* const riv = static_<River>(_river);
		const std::vector<Ptr>& vec = static_<Flock>(it->next_())->get_();
		const Ptr me = me_();

		return _river;
	}

	virtual inline const Ptr generate_thing_code(const Ptr& it) override
	{
		River* const riv = static_<River>(_river);
		const std::vector<Ptr>& vec = static_<Flock>(it->next_())->get_();
		const Ptr me = me_();

		return _river;
	}

	virtual inline const Ptr generate_invoke_code(const Ptr& it) override
	{
		River* const riv = static_<River>(_river);
		const std::vector<Ptr>& vec = static_<Flock>(it->next_())->get_();
		const Ptr me = me_();

		static_<Expression>(vec[0])->generate_(me);
		riv->write_("->invoke_(");
		bool first = true;
		for (size_t i = 1; i < vec.size(); ++i)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				riv->write_(",");
			}
			static_<Expression>(vec[i])->generate_(me);
		}
		riv->write_(")");
		return _river;
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::CPPGenerator");
		return TYPE;
	}
};

//======================================================================
// class CPPGenerator
//======================================================================

} // namespace strange

#endif
