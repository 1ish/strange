#ifndef COM_ONEISH__STRANGE__FORWARD_MUTATOR_A_H
#define COM_ONEISH__STRANGE__FORWARD_MUTATOR_A_H

namespace strange
{
	template <typename element_d>
	struct forward_mutator_o :
		any_o
	{
		bool (*equal) (con<forward_mutator_a<element_d>> const& me,
			con<forward_mutator_a<element_d>> const& other);

		static inline bool not_equal(con<forward_mutator_a<element_d>> const& me,
			con<forward_mutator_a<element_d>> const& other);

		element_d (*get) (con<forward_mutator_a<element_d>> const& me);

		void (*set) (con<forward_mutator_a<element_d>> const& me,
			element_d const& element);

		void (*increment) (var<forward_mutator_a<element_d>> const& me);

		element_d& (*_operator_star) (con<forward_mutator_a<element_d>> const& me);

		element_d* (*_operator_arrow) (con<forward_mutator_a<element_d>> const& me);
	};

	template <typename element_d>
	struct forward_mutator_a
	{
		using operations = forward_mutator_o<element_d>;
		using creator_fp = fit<forward_mutator_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};

	template <typename element_d>
	inline bool forward_mutator_o<element_d>::not_equal(con<forward_mutator_a<element_d>> const& me,
		con<forward_mutator_a<element_d>> const& other)
	{
		return !me.o->equal(me, other);
	}
}

#endif
