#ifndef COM_ONEISH__STRANGE__EXPRESSION_A_H
#define COM_ONEISH__STRANGE__EXPRESSION_A_H

/*
name ()				stu
symbol ()			'abc'
text ()				"xyz"
int ()				1
float ()			2.3
comment ()			// cool

cat (scope, name, aspects, order, representation)		<+ int64_t >
type (scope, name, aspects)								strange::number[=<+ int64_t >]
kind (behaviour, the_cat, the_type)						=<+ int64_t >

list (1, 2, 3)						[1, 2, 3]
list [#<+ int64_t >] (1, 2, 3)
table (tuple (1, 2.3))				{1: 2.3}
table {key: =<+ int64_t >, value: &<+ double >} (tuple [=<+ int64_t >, &<+ double >] (1, 2.3))

compound (before, after, result)	(before, after, result)

associate (x, #, 42)				x # 42
share (x$, =<+ int64_t >, 42)		x$ =<+ int64_t > 42

perform (x, add, y)					x.add [y]

f = function (x #, y #) = x.add [y]
e = extraction (x #, y #) = x.add [y]					e = operation (me #, x #, y #) = x.add [y]
m = mutation (x #, y #) & (me.save [], x + y)			m = operation (me =, x #, y #) & (me.save [], x + y)
m = modification (x #, y #) =<> (me.share [], x + y)	m = operation (me &, x #, y #) =<> (me.share [], x + y)

(f) [1, 2]
x.(e) [1, 2]
(m) [x, 1, 2]
(m) {me: f, x: e, y: m}

realm ()
abstraction {} ()
enumeration ()
thing {} ()
expression ()

for ()
if ()
*/

namespace strange
{
	struct expression_o :
		any_o
	{
		var<token_a> (*token) (con<expression_a> const& me);

		var<symbol_a> (*statement) (con<expression_a> const& me);

		var<list_a<var<kind_a>>> (*aspects) (con<expression_a> const& me);

		var<table_a<var<symbol_a>, var<kind_a>>> (*dimensions) (con<expression_a> const& me);

		var<list_a<var<expression_a>>> (*terms) (con<expression_a> const& me);

		var<kind_a> (*kind) (con<expression_a> const& me);

		var<expression_a> (*implementation) (con<expression_a> const& me);

		void (*generate) (con<expression_a> const& me,
			generation_e generation,
			int64_t version,
			int64_t indentation,
			var<brook_a> const& brook);
	};

	struct expression_a
	{
		using operations = expression_o;
		using creator_fp = var<expression_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
