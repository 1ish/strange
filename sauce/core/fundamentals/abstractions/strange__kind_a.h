#ifndef COM_ONEISH__STRANGE__KIND_A_H
#define COM_ONEISH__STRANGE__KIND_A_H

namespace strange
{
	struct kind_o : // operations
		symbol_o
	{
		var<cat_a> (*the_cat) (con<kind_a> const& me);

		behaviour_e (*behaviour) (con<kind_a> const& me);

		bool (*address) (con<kind_a> const& me);

		bool (*shared) (con<kind_a> const& me);

		var<type_a> (*the_type) (con<kind_a> const& me);

		// constant					@any#						address of constant					@any# &
		// variable					@any%						shared variable						@any% $
		// pointer					@any*						shared address of pointer			@any* & $
		// forward_iterator			@forward_extractor <any>+	address of forward_iterator			@forward_extractor <any>+ &
		// bidirectional_iterator	@bidirectional_mutator-		address of bidirectional_iterator	@bidirectional_mutator- &
		// random_access_iterator	@random_access_extractor@	address of random_access_iterator	@random_access_extractor@ &
	};

	struct kind_b // base
	{
		mutable thing_t* t;
		mutable kind_o const* o;
	};

	template <typename base_d>
	struct kind_c : // constant
		symbol_c<base_d>
	{
		using me_d = con<kind_a>;

		inline var<cat_a> the_cat() const;

		inline behaviour_e behaviour() const;

		inline bool address() const;

		inline bool shared() const;

		inline var<type_a> the_type() const;
	};
	
	template <typename base_d>
	struct kind_v : // variable
		symbol_v<base_d>
	{
		using me_d = var<kind_a>;
	};

	struct kind_a : // abstraction
		kind_c<kind_b>
	{
		using operations = kind_o;
		using variations = kind_v<kind_a>;
		using creator_fp = var<kind_a>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
