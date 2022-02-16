#ifndef COM_ONEISH__STRANGE__COLLECTION_A_H
#define COM_ONEISH__STRANGE__COLLECTION_A_H

namespace strange
{
	template <typename key_d, typename value_d, typename element_d>
	struct collection_o : // operations
		any_o
	{
		var<range_a<element_d>> (*range) (con<collection_a<key_d, value_d, element_d>> const& me);

		fit<forward_extractor_a<element_d>> (*begin) (con<collection_a<key_d, value_d, element_d>> const& me);

		fit<forward_extractor_a<element_d>> (*end) (con<collection_a<key_d, value_d, element_d>> const& me);

		ptr<> (*read_lock) (con<collection_a<key_d, value_d, element_d>> const& me);

		ptr<> (*write_lock) (var<collection_a<key_d, value_d, element_d>> const& me);

		bool (*has) (con<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		value_d (*at) (con<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		void (*update) (var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key,
			value_d const& value);

		bool (*insert) (var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key,
			value_d const& value);

		bool (*erase) (var<collection_a<key_d, value_d, element_d>> const& me,
			key_d const& key);

		void (*clear) (var<collection_a<key_d, value_d, element_d>> const& me);

		int64_t (*size) (con<collection_a<key_d, value_d, element_d>> const& me);

		bool (*empty) (con<collection_a<key_d, value_d, element_d>> const& me);

		void (*push_front) (var<collection_a<key_d, value_d, element_d>> const& me,
			element_d const& element);

		element_d (*pop_front) (var<collection_a<key_d, value_d, element_d>> const& me);

		void (*push_back) (var<collection_a<key_d, value_d, element_d>> const& me,
			element_d const& element);

		element_d (*pop_back) (var<collection_a<key_d, value_d, element_d>> const& me);

		void (*self_assign) (var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		void (*self_add) (var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		var<collection_a<key_d, value_d, element_d>> (*add) (con<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		void (*self_subtract) (var<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);

		var<collection_a<key_d, value_d, element_d>> (*subtract) (con<collection_a<key_d, value_d, element_d>> const& me,
			con<range_a<element_d>> const& range);
	};

	template <typename key_d, typename value_d, typename element_d>
	struct collection_b // base
	{
		mutable thing_t* t;
		mutable collection_o<key_d, value_d, element_d> const* o;
	};

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	struct collection_c : // constant
		any_c<base_d>
	{
		using me_d = con<collection_a<key_d, value_d, element_d>>;

		inline var<range_a<element_d>> range() const;

		inline fit<forward_extractor_a<element_d>> begin() const;

		inline fit<forward_extractor_a<element_d>> end() const;

		inline ptr<> read_lock() const;

		inline bool has(key_d const& key) const;

		inline value_d at(key_d const& key) const;

		inline int64_t size() const;

		inline bool empty() const;

		inline var<collection_a<key_d, value_d, element_d>> add(con<range_a<element_d>> const& range) const;

		inline var<collection_a<key_d, value_d, element_d>> subtract(con<range_a<element_d>> const& range) const;
	};

	template <typename base_d, typename key_d, typename value_d, typename element_d>
	struct collection_v : // variable
		any_v<base_d>
	{
		using me_d = var<collection_a<key_d, value_d, element_d>>;

		inline ptr<> write_lock() const;

		inline void update(key_d const& key,
			value_d const& value) const;

		inline bool insert(key_d const& key,
			value_d const& value) const;

		inline bool erase(key_d const& key) const;

		inline void clear() const;

		inline void push_front(element_d const& element) const;

		inline element_d pop_front() const;

		inline void push_back(element_d const& element) const;

		inline element_d pop_back() const;

		inline void self_assign(con<range_a<element_d>> const& range) const;

		inline void self_add(con<range_a<element_d>> const& range) const;

		inline void self_subtract(con<range_a<element_d>> const& range) const;
	};

	template <typename key_d, typename value_d, typename element_d>
	struct collection_a : // abstraction
		collection_c<collection_b<key_d, value_d, element_d>, key_d, value_d, element_d>
	{
		using non_mutator_range = bool;
		using operations = collection_o<key_d, value_d, element_d>;
		using variations = collection_v<collection_a<key_d, value_d, element_d>, key_d, value_d, element_d>;
		using creator_fp = var<collection_a<key_d, value_d, element_d>>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
