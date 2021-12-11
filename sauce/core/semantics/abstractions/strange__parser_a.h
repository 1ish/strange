#ifndef COM_ONEISH__STRANGE__PARSER_A_H
#define COM_ONEISH__STRANGE__PARSER_A_H

namespace strange
{
	struct parser_o :
		any_o
	{
		var<expression_a> (*parse) (var<parser_a> const& me,
			var<range_a<token_a>> const& tokens);
	};

	struct parser_a
	{
		using operations = parser_o;
		using variations = any_v<parser_a>;
		using creator_fp = var<parser_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
