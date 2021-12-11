#ifndef COM_ONEISH__STRANGE__ANY_A_H
#define COM_ONEISH__STRANGE__ANY_A_H

namespace strange
{
	struct any_o // operations
	{
		var<symbol_a> (*cat) (con<> const& me); //TODO cat

		bool (*is) (con<> const& me,
			con<> const& abstraction);

		bool (*as) (con<> const& me,
			var<> const& abstraction);

		var<symbol_a> (*type) (con<> const& me);

		static inline void set_something (var<> const& me,
			bool is_something);

		static inline bool something (con<> const& me);

		void (*set_error) (var<> const& me,
			con<> const& err);

		var<> (*error) (con<> const& me);

		static inline uint64_t identity (con<> const& me);

		uint64_t (*hash) (con<> const& me);

		bool (*equal) (con<> const& me,
			con<> const& other);

		static inline bool not_equal (con<> const& me,
			con<> const& other);

		bool (*less) (con<> const& me,
			con<> const& other);

		static inline bool greater (con<> const& me,
			con<> const& other);

		bool (*less_or_equal) (con<> const& me,
			con<> const& other);

		static inline bool greater_or_equal (con<> const& me,
			con<> const& other);

		bool (*pack) (con<> const& me,
			var<container_a> const& container);

		void (*_free) (con<> const& me);

		void (*_copy) (con<> const& me,
			var<> const& copy);

		void (*_set_pointer) (con<> const& me,
			bool is_pointer);

		bool (*_pointer) (con<> const& me);
	};

	struct any_b // base
	{
		mutable thing_t* t;
		mutable any_o const* o;
	};

	template <typename base_d>
	struct any_c : // constant
		base_d
	{
		using me_d = con<>;

		inline var<symbol_a> cat() const; //TODO cat

		inline bool is(con<> const& abstraction) const;

		inline bool as(var<> const& abstraction) const;

		inline var<symbol_a> type() const;

		inline bool something() const;

		inline var<> error() const;

		inline uint64_t identity() const;

		inline uint64_t hash() const;

		inline bool equal(con<> const& other) const;

		inline bool not_equal(con<> const& other) const;

		inline bool less(con<> const& other) const;

		inline bool greater(con<> const& other) const;

		inline bool less_or_equal(con<> const& other) const;

		inline bool greater_or_equal(con<> const& other) const;

		inline bool pack(var<container_a> const& container) const;
	};

	template <typename base_d>
	struct any_v : // variable
		base_d
	{
		using me_d = var<>;

		inline void set_something(bool is_something) const;
		
		inline void set_error(con<> const& err) const;
	};

	struct any_a : // abstraction
		any_c<any_b>
	{
		using operations = any_o;
		using variations = any_v<any_a>;
		using creator_fp = var<>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
