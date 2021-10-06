#ifndef COM_ONEISH__STRANGE__EXPRESSION_A_H
#define COM_ONEISH__STRANGE__EXPRESSION_A_H

/*
name ()				stu
symbol ()			'abc'
text ()				"xyz"
int ()				1
float ()			2.3
comment ()			// cool

cat (scope, name, aspects, order, representation)		<+int64_t>
type (scope, name, aspects)								strange::number[<+int64_t>=]
kind (shared, the_cat, the_type, behaviour)				$<+int64_t>=

list (1, 2, 3)						[1, 2, 3]
list [<+int64_t>#] (1, 2, 3)
table (tuple (1, 2.3))				{1 : 2.3}
table {key : <+int64_t>=, value : <+double>&} (tuple [<+int64_t>=, <+double>&] (1, 2.3))

compound (before, after, result)	(before, after, result)

associate [<+int64_t>#] (x, 42)		x :<+ int64_t ># 42

perform (x, add, y)					x.add [y]

f := function ((x :#, y :#) := x.add [y])
e := extraction ((x :#, y :#) := x.add [y])				e := operation ((me :#, x :#, y :#) := x.add [y])
m := mutation ((x :#, y :#) := (me.save [], x + y))		m := operation ((me :=, x :#, y :#) := (me.save [], x + y))
d := deviation ((x :#, y :#) := me.share [], x + y)		d := operation ((me :&, x :#, y :#) := me.share [], x + y)

(f) [1, 2]
x.(e) [1, 2]
(m) [x, 1, 2]
(d) {me : f, x : e, y : m}

namespace ()
abstraction [] ()
thing {} ()

for ()
if ()
*/

namespace strange
{
	struct expression_o :
		any_o
	{
		var<token_a> (*token) (con<expression_a> const& me);

		var<list_a<var<expression_a>>> (*terms) (con<expression_a> const& me);

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