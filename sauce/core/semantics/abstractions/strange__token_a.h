#ifndef COM_ONEISH__STRANGE__TOKEN_A_H
#define COM_ONEISH__STRANGE__TOKEN_A_H

namespace strange
{
	struct token_o :
		any_o
	{
		var<text_a> (*filename) (con<token_a> const& me);

		int64_t (*line) (con<token_a> const& me);

		int64_t (*position) (con<token_a> const& me);

		classification_e (*classification) (con<token_a> const& me);

		var<lake_a> (*lake) (con<token_a> const& me);

		var<text_a> (*report) (con<token_a> const& me);
	};

	struct token_a
	{
		using operations = token_o;
		using creator_fp = var<token_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
