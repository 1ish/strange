#ifndef COM_ONEISH__STRANGE__EXPRESSION_A_H
#define COM_ONEISH__STRANGE__EXPRESSION_A_H

/*
name ("stu")			stu
symbol ("abc")			'abc'
text ("xyz")			"xyz"	- infinte regress
int ("1")				1		- 64 bit signed
float ("2.3")			2.3		- 64 bit
comment ("// cool")		// cool

cat (order, representation, scope, name, aspects)		<+ int64_t >
type (scope, name, aspects)								strange::number[=<+ int64_t >]
kind (behaviour, the_cat, the_type)						=<+ int64_t >

list (1, 2, 3)						[1, 2, 3]
list [#<+ int64_t >] (1, 2, 3)
table (tuple (1, 2.3))				{1: 2.3}
table {key: =<+ int64_t >, value: @<+ double >} (tuple [=<+ int64_t >, @<+ double >] (1, 2.3))

composition (before, after, result)				(before, after, result)

association (x, #, 42)							x # 42
syndication (x$, =<+ int64_t >, 42)				x$ =<+ int64_t > 42

invocation (x, add, y)							x.add[y]

f = function (x #, y #) = x.add[y]
e = extraction (x #, y #) = x.add[y]					e = operation (me #, x #, y #) = x.add[y]
m = mutation (x #, y #) @ (me.save[], x + y)			m = operation (me =, x #, y #) @ (me.save[], x + y)
p = perversion (x #, y #) =<> (me.share[], x + y)		p = operation (me @, x #, y #) =<> (me.share[], x + y)

f.execute[1, 2]
e.perform[x, 1, 2]
m.perform[x, 1, 2]
p.perform{me: f, x: e, y: m}

realm ()
abstraction {} [] ()
enumeration ()
thing {} ()
expression ()

for ()
if ()

strange: realm
(
	number: abstraction {type: <<+>>} [<mutable_numeric>]
	(	equal				# extraction (other #^^) =<+ bool >,
		not_equal			# extraction (other #^^) =<+ bool >,
		less				# extraction (other #^^) =<+ bool >,
		greater				# extraction (other #^^) =<+ bool >,
		less_or_equal		# extraction (other #^^) =<+ bool >,
		greater_or_equal	# extraction (other #^^) =<+ bool >,
		data				# extraction () =<data[^type]>,
		extract				# extraction () #<+ type_d >,
		mutate				# mutation () @<+ type_d >,
		extractor			# extraction () *<random_access_extractor[^type]>,
	)
	{	not_equal:			me.equal[] !,
		greater:			me.less_or_equal[] !,
		greater_or_equal:	me.less[] !,
	},

	number: thing {type: <<+>>} [data[^type]]
	(	data_				=^type,

		number				# manifestation
		(	me		#<number[<+ std::remove_reference_t<type_d> >]>
		)	=<number[<+ std::remove_reference_t<type_d> >]>,

		data				# manifestation
		(	me		#<number[<+ std::remove_reference_t<type_d> >]>
		)	=<data[<+ std::remove_reference_t<type_d> >]>,

		extractor			# manifestation
		(	me		#<number[<+ std::remove_reference_t<type_d> >]>
		)	*<random_access_extractor[<+ std::remove_reference_t<type_d> >]>,

		equal_number		# function
		(	me		#<number[<+ std::remove_reference_t<type_d> >]>,
			other	#<number[<+ std::remove_reference_t<type_d> >]>,
		)	=<+ bool >,

		less_number			# function
		(	me		#<number[<+ std::remove_reference_t<type_d> >]>,
			other	#<number[<+ std::remove_reference_t<type_d> >]>,
		)	=<+ bool >,

		less_or_equal_number	# function
		(	me		#<number[<+ std::remove_reference_t<type_d> >]>,
			other	#<number[<+ std::remove_reference_t<type_d> >]>,
		)	=<+ bool >,
	)
	{	number:
		{	equal:			equal_number,
			less:			less_number,
			less_or_equal:	less_or_equal_number,
		},
	
		equal_number:
		(+++	auto const mt = static_cast<number_t<type_d> const* const>(me.t);
				return mt->data_ == other.o->extract(other);			
		)+++,

		less_number:
		(+++	auto const mt = static_cast<number_t<type_d> const* const>(me.t);
				return mt->data_ < other.o->extract(other);
		)+++,

		less_or_equal_number:
		(+++	auto const mt = static_cast<number_t<type_d> const* const>(me.t);
				return mt->data_ <= other.o->extract(other);
		)+++,
	},
)

*/

namespace strange
{
	struct expression_o :
		any_o
	{
		var<token_a> (*token) (con<expression_a> const& me);

		var<symbol_a> (*statement) (con<expression_a> const& me);

		var<list_a<var<expression_a>>> (*list) (con<expression_a> const& me);

		var<table_a<var<expression_a>, var<expression_a>>> (*table) (con<expression_a> const& me);

		var<list_a<var<expression_a>>> (*terms) (con<expression_a> const& me);

		var<expression_a> (*kind) (con<expression_a> const& me);

		var<expression_a> (*body) (con<expression_a> const& me);

		var<expression_a> (*parent) (con<expression_a> const& me);

		void (*resolve) (var<expression_a> const& me);

		void (*generate) (con<expression_a> const& me,
			generation_e generation,
			int64_t version,
			int64_t indentation,
			var<brook_a> const& brook);

		var<> (*evaluate) (con<expression_a> const& me);
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
