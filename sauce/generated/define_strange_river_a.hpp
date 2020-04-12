
namespace strange
{

template <typename _1 = void>
class river_d;

template <typename _1 = void>
inline river_d<_1> ___river_dynamic___(any_a<> const& thing); 

template <typename _1>
class river_a : public range_a<>
{
public:
	inline forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > extract_begin() const;

	inline forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > extract_end() const;

	inline any_a<> to_lake__(range_a<> const& ___arguments___);

	inline lake_int8_a<> to_lake_();

	inline std :: string to_string();

	inline any_a<> get_char__(range_a<> const& ___arguments___);

	inline number_data_int8_a<> get_char_();

	inline int8_t get_char();

	inline any_a<> peek_char__(range_a<> const& ___arguments___);

	inline number_data_int8_a<> peek_char_();

	inline int8_t peek_char();

	inline any_a<> unget_char__(range_a<> const& ___arguments___);

	inline river_a<> unget_char_();

	inline void unget_char();

	inline any_a<> put_back_char__(range_a<> const& ___arguments___);

	inline river_a<> put_back_char_(number_data_int8_a<> const& int_8);

	inline void put_back_char(int8_t int_8 );

	inline any_a<> get_line__(range_a<> const& ___arguments___);

	inline lake_int8_a<> get_line_(number_data_int64_a<> const& count, number_data_int8_a<> const& delimiter);

	inline std :: vector < int8_t > get_line(int64_t count , int8_t delimiter );

	inline any_a<> ignore__(range_a<> const& ___arguments___);

	inline river_a<> ignore_(number_data_int64_a<> const& count);

	inline void ignore(int64_t count );

	inline any_a<> read__(range_a<> const& ___arguments___);

	inline lake_int8_a<> read_(number_data_int64_a<> const& count);

	inline std :: vector < int8_t > read(int64_t count );

	inline std :: string read_string(int64_t count );

	inline any_a<> tellg__(range_a<> const& ___arguments___) const;

	inline number_data_int64_a<> tellg_() const;

	inline int64_t tellg() const;

	inline any_a<> seekg_beg__(range_a<> const& ___arguments___);

	inline river_a<> seekg_beg_(number_data_int64_a<> const& offset);

	inline void seekg_beg(int64_t offset );

	inline any_a<> seekg_end__(range_a<> const& ___arguments___);

	inline river_a<> seekg_end_(number_data_int64_a<> const& offset);

	inline void seekg_end(int64_t offset );

	inline any_a<> seekg_cur__(range_a<> const& ___arguments___);

	inline river_a<> seekg_cur_(number_data_int64_a<> const& offset);

	inline void seekg_cur(int64_t offset );

	inline any_a<> sync__(range_a<> const& ___arguments___);

	inline any_a<> sync_();

	inline bool sync();

	inline any_a<> put_char__(range_a<> const& ___arguments___);

	inline river_a<> put_char_(number_data_int8_a<> const& int_8);

	inline void put_char(int8_t int_8 );

	inline any_a<> write__(range_a<> const& ___arguments___);

	inline river_a<> write_(lake_int8_a<> const& lake);

	inline void write(std :: vector < int8_t > const & lake );

	inline void write_string(std :: string const & str );

	inline any_a<> tellp__(range_a<> const& ___arguments___) const;

	inline number_data_int64_a<> tellp_() const;

	inline int64_t tellp() const;

	inline any_a<> seekp_beg__(range_a<> const& ___arguments___);

	inline river_a<> seekp_beg_(number_data_int64_a<> const& offset);

	inline void seekp_beg(int64_t offset );

	inline any_a<> seekp_end__(range_a<> const& ___arguments___);

	inline river_a<> seekp_end_(number_data_int64_a<> const& offset);

	inline void seekp_end(int64_t offset );

	inline any_a<> seekp_cur__(range_a<> const& ___arguments___);

	inline river_a<> seekp_cur_(number_data_int64_a<> const& offset);

	inline void seekp_cur(int64_t offset );

	inline any_a<> flush__(range_a<> const& ___arguments___);

	inline river_a<> flush_();

	inline void flush();

	inline any_a<> good__(range_a<> const& ___arguments___) const;

	inline any_a<> good_() const;

	inline bool good() const;

	inline any_a<> eof__(range_a<> const& ___arguments___) const;

	inline any_a<> eof_() const;

	inline bool eof() const;

	inline any_a<> fail__(range_a<> const& ___arguments___) const;

	inline any_a<> fail_() const;

	inline bool fail() const;

	inline any_a<> bad__(range_a<> const& ___arguments___) const;

	inline any_a<> bad_() const;

	inline bool bad() const;

	inline any_a<> set_good__(range_a<> const& ___arguments___);

	inline river_a<> set_good_(any_a<> const& value);

	inline void set_good(bool value );

	inline any_a<> set_eof__(range_a<> const& ___arguments___);

	inline river_a<> set_eof_(any_a<> const& value);

	inline void set_eof(bool value );

	inline any_a<> set_fail__(range_a<> const& ___arguments___);

	inline river_a<> set_fail_(any_a<> const& value);

	inline void set_fail(bool value );

	inline any_a<> set_bad__(range_a<> const& ___arguments___);

	inline river_a<> set_bad_(any_a<> const& value);

	inline void set_bad(bool value );

	inline any_a<> filename__(range_a<> const& ___arguments___) const;

	inline lake_int8_a<> filename_() const;

	inline std :: string filename() const;

	inline any_a<> close__(range_a<> const& ___arguments___);

	inline any_a<> close_();

	inline void close();

	inline any_a<> closed__(range_a<> const& ___arguments___) const;

	inline any_a<> closed_() const;

	inline bool closed();

protected:
	struct ___river_a_handle_base___ : range_a<>::___range_a_handle_base___
	{
		virtual forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > extract_begin() const = 0;
		virtual forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > extract_end() const = 0;
		virtual lake_int8_a<> to_lake_() = 0;
		virtual std :: string to_string() = 0;
		virtual number_data_int8_a<> get_char_() = 0;
		virtual int8_t get_char() = 0;
		virtual number_data_int8_a<> peek_char_() = 0;
		virtual int8_t peek_char() = 0;
		virtual river_a<> unget_char_() = 0;
		virtual void unget_char() = 0;
		virtual river_a<> put_back_char_(number_data_int8_a<> const& int_8) = 0;
		virtual void put_back_char(int8_t int_8 ) = 0;
		virtual lake_int8_a<> get_line_(number_data_int64_a<> const& count, number_data_int8_a<> const& delimiter) = 0;
		virtual std :: vector < int8_t > get_line(int64_t count , int8_t delimiter ) = 0;
		virtual river_a<> ignore_(number_data_int64_a<> const& count) = 0;
		virtual void ignore(int64_t count ) = 0;
		virtual lake_int8_a<> read_(number_data_int64_a<> const& count) = 0;
		virtual std :: vector < int8_t > read(int64_t count ) = 0;
		virtual std :: string read_string(int64_t count ) = 0;
		virtual number_data_int64_a<> tellg_() const = 0;
		virtual int64_t tellg() const = 0;
		virtual river_a<> seekg_beg_(number_data_int64_a<> const& offset) = 0;
		virtual void seekg_beg(int64_t offset ) = 0;
		virtual river_a<> seekg_end_(number_data_int64_a<> const& offset) = 0;
		virtual void seekg_end(int64_t offset ) = 0;
		virtual river_a<> seekg_cur_(number_data_int64_a<> const& offset) = 0;
		virtual void seekg_cur(int64_t offset ) = 0;
		virtual any_a<> sync_() = 0;
		virtual bool sync() = 0;
		virtual river_a<> put_char_(number_data_int8_a<> const& int_8) = 0;
		virtual void put_char(int8_t int_8 ) = 0;
		virtual river_a<> write_(lake_int8_a<> const& lake) = 0;
		virtual void write(std :: vector < int8_t > const & lake ) = 0;
		virtual void write_string(std :: string const & str ) = 0;
		virtual number_data_int64_a<> tellp_() const = 0;
		virtual int64_t tellp() const = 0;
		virtual river_a<> seekp_beg_(number_data_int64_a<> const& offset) = 0;
		virtual void seekp_beg(int64_t offset ) = 0;
		virtual river_a<> seekp_end_(number_data_int64_a<> const& offset) = 0;
		virtual void seekp_end(int64_t offset ) = 0;
		virtual river_a<> seekp_cur_(number_data_int64_a<> const& offset) = 0;
		virtual void seekp_cur(int64_t offset ) = 0;
		virtual river_a<> flush_() = 0;
		virtual void flush() = 0;
		virtual any_a<> good_() const = 0;
		virtual bool good() const = 0;
		virtual any_a<> eof_() const = 0;
		virtual bool eof() const = 0;
		virtual any_a<> fail_() const = 0;
		virtual bool fail() const = 0;
		virtual any_a<> bad_() const = 0;
		virtual bool bad() const = 0;
		virtual river_a<> set_good_(any_a<> const& value) = 0;
		virtual void set_good(bool value ) = 0;
		virtual river_a<> set_eof_(any_a<> const& value) = 0;
		virtual void set_eof(bool value ) = 0;
		virtual river_a<> set_fail_(any_a<> const& value) = 0;
		virtual void set_fail(bool value ) = 0;
		virtual river_a<> set_bad_(any_a<> const& value) = 0;
		virtual void set_bad(bool value ) = 0;
		virtual lake_int8_a<> filename_() const = 0;
		virtual std :: string filename() const = 0;
		virtual any_a<> close_() = 0;
		virtual void close() = 0;
		virtual any_a<> closed_() const = 0;
		virtual bool closed() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___river_a_handle_base___>
	struct ___river_a_handle___ : range_a<>::template ___range_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___river_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: range_a<>::template ___range_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___river_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: range_a<>::template ___range_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___river_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: range_a<>::template ___range_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > extract_begin() const final;

		virtual inline forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > extract_end() const final;

		virtual inline lake_int8_a<> to_lake_() final;

		virtual inline std :: string to_string() final;

		virtual inline number_data_int8_a<> get_char_() final;

		virtual inline int8_t get_char() final;

		virtual inline number_data_int8_a<> peek_char_() final;

		virtual inline int8_t peek_char() final;

		virtual inline river_a<> unget_char_() final;

		virtual inline void unget_char() final;

		virtual inline river_a<> put_back_char_(number_data_int8_a<> const& int_8) final;

		virtual inline void put_back_char(int8_t int_8 ) final;

		virtual inline lake_int8_a<> get_line_(number_data_int64_a<> const& count, number_data_int8_a<> const& delimiter) final;

		virtual inline std :: vector < int8_t > get_line(int64_t count , int8_t delimiter ) final;

		virtual inline river_a<> ignore_(number_data_int64_a<> const& count) final;

		virtual inline void ignore(int64_t count ) final;

		virtual inline lake_int8_a<> read_(number_data_int64_a<> const& count) final;

		virtual inline std :: vector < int8_t > read(int64_t count ) final;

		virtual inline std :: string read_string(int64_t count ) final;

		virtual inline number_data_int64_a<> tellg_() const final;

		virtual inline int64_t tellg() const final;

		virtual inline river_a<> seekg_beg_(number_data_int64_a<> const& offset) final;

		virtual inline void seekg_beg(int64_t offset ) final;

		virtual inline river_a<> seekg_end_(number_data_int64_a<> const& offset) final;

		virtual inline void seekg_end(int64_t offset ) final;

		virtual inline river_a<> seekg_cur_(number_data_int64_a<> const& offset) final;

		virtual inline void seekg_cur(int64_t offset ) final;

		virtual inline any_a<> sync_() final;

		virtual inline bool sync() final;

		virtual inline river_a<> put_char_(number_data_int8_a<> const& int_8) final;

		virtual inline void put_char(int8_t int_8 ) final;

		virtual inline river_a<> write_(lake_int8_a<> const& lake) final;

		virtual inline void write(std :: vector < int8_t > const & lake ) final;

		virtual inline void write_string(std :: string const & str ) final;

		virtual inline number_data_int64_a<> tellp_() const final;

		virtual inline int64_t tellp() const final;

		virtual inline river_a<> seekp_beg_(number_data_int64_a<> const& offset) final;

		virtual inline void seekp_beg(int64_t offset ) final;

		virtual inline river_a<> seekp_end_(number_data_int64_a<> const& offset) final;

		virtual inline void seekp_end(int64_t offset ) final;

		virtual inline river_a<> seekp_cur_(number_data_int64_a<> const& offset) final;

		virtual inline void seekp_cur(int64_t offset ) final;

		virtual inline river_a<> flush_() final;

		virtual inline void flush() final;

		virtual inline any_a<> good_() const final;

		virtual inline bool good() const final;

		virtual inline any_a<> eof_() const final;

		virtual inline bool eof() const final;

		virtual inline any_a<> fail_() const final;

		virtual inline bool fail() const final;

		virtual inline any_a<> bad_() const final;

		virtual inline bool bad() const final;

		virtual inline river_a<> set_good_(any_a<> const& value) final;

		virtual inline void set_good(bool value ) final;

		virtual inline river_a<> set_eof_(any_a<> const& value) final;

		virtual inline void set_eof(bool value ) final;

		virtual inline river_a<> set_fail_(any_a<> const& value) final;

		virtual inline void set_fail(bool value ) final;

		virtual inline river_a<> set_bad_(any_a<> const& value) final;

		virtual inline void set_bad(bool value ) final;

		virtual inline lake_int8_a<> filename_() const final;

		virtual inline std :: string filename() const final;

		virtual inline any_a<> close_() final;

		virtual inline void close() final;

		virtual inline any_a<> closed_() const final;

		virtual inline bool closed() final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___river_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___river_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___river_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___river_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___river_a_handle_final___ final : ___river_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___river_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___river_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___river_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___river_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___river_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___river_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___river_a_handle_final___>(___river_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___river_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___river_a_handle_final___<___TTT___&>
	{
		inline ___river_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___river_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___river_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___river_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___river_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___river_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline river_a val(river_a const& other) noexcept
	{
		return river_a{ other };
	}

	static inline river_a ref(river_a& other) noexcept
	{
		return river_a(other, any_a<>::___reference_tag___{});
	}

	static inline river_a dup(river_a& other) noexcept
	{
		return river_a(other, any_a<>::___duplicate_tag___{});
	}

	inline river_a() = default;

	inline river_a(river_a& other, any_a<>::___reference_tag___) noexcept
		: range_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline river_a(river_a& other, any_a<>::___duplicate_tag___) noexcept
		: range_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline river_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: range_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___river_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline river_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: range_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___river_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<river_a, std::decay_t<___TTT___>>::value>>
	explicit inline river_a(___TTT___ value) noexcept
		: range_a<>{ std::make_shared<___river_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline river_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: range_a<>{ std::make_shared<___river_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline river_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___river_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<river_a, std::decay_t<___TTT___>>::value>>
	inline river_a& operator=(___TTT___ value) noexcept
	{
		river_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___river_a_handle_base___>(thing.___handle___) };
	}

	static inline river_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___river_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return river_a{ thing.___handle___ };
		}
		return river_a{ river_d<_1>{ thing } };
	}

	static inline river_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___river_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return river_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return river_a{ river_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::river");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = range_a<>::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>());
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = range_a<>::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___()
	{
		static ___unordered_shoal_a___ OPERATIONS = []()
		{
			___unordered_shoal_a___ operations = range_a<>::template ___operations___<___unordered_shoal_a___>();
			operations.update_string("to_lake_", native_mutation_t<river_a>::create(&river_a::to_lake__));
			operations.update_string("get_char_", native_mutation_t<river_a>::create(&river_a::get_char__));
			operations.update_string("peek_char_", native_mutation_t<river_a>::create(&river_a::peek_char__));
			operations.update_string("unget_char_", native_mutation_t<river_a>::create(&river_a::unget_char__));
			operations.update_string("put_back_char_", native_mutation_t<river_a>::create(&river_a::put_back_char__));
			operations.update_string("get_line_", native_mutation_t<river_a>::create(&river_a::get_line__));
			operations.update_string("ignore_", native_mutation_t<river_a>::create(&river_a::ignore__));
			operations.update_string("read_", native_mutation_t<river_a>::create(&river_a::read__));
			operations.update_string("tellg_", native_extraction_t<river_a>::create(&river_a::tellg__));
			operations.update_string("seekg_beg_", native_mutation_t<river_a>::create(&river_a::seekg_beg__));
			operations.update_string("seekg_end_", native_mutation_t<river_a>::create(&river_a::seekg_end__));
			operations.update_string("seekg_cur_", native_mutation_t<river_a>::create(&river_a::seekg_cur__));
			operations.update_string("sync_", native_mutation_t<river_a>::create(&river_a::sync__));
			operations.update_string("put_char_", native_mutation_t<river_a>::create(&river_a::put_char__));
			operations.update_string("write_", native_mutation_t<river_a>::create(&river_a::write__));
			operations.update_string("tellp_", native_extraction_t<river_a>::create(&river_a::tellp__));
			operations.update_string("seekp_beg_", native_mutation_t<river_a>::create(&river_a::seekp_beg__));
			operations.update_string("seekp_end_", native_mutation_t<river_a>::create(&river_a::seekp_end__));
			operations.update_string("seekp_cur_", native_mutation_t<river_a>::create(&river_a::seekp_cur__));
			operations.update_string("flush_", native_mutation_t<river_a>::create(&river_a::flush__));
			operations.update_string("good_", native_extraction_t<river_a>::create(&river_a::good__));
			operations.update_string("eof_", native_extraction_t<river_a>::create(&river_a::eof__));
			operations.update_string("fail_", native_extraction_t<river_a>::create(&river_a::fail__));
			operations.update_string("bad_", native_extraction_t<river_a>::create(&river_a::bad__));
			operations.update_string("set_good_", native_mutation_t<river_a>::create(&river_a::set_good__));
			operations.update_string("set_eof_", native_mutation_t<river_a>::create(&river_a::set_eof__));
			operations.update_string("set_fail_", native_mutation_t<river_a>::create(&river_a::set_fail__));
			operations.update_string("set_bad_", native_mutation_t<river_a>::create(&river_a::set_bad__));
			operations.update_string("filename_", native_extraction_t<river_a>::create(&river_a::filename__));
			operations.update_string("close_", native_mutation_t<river_a>::create(&river_a::close__));
			operations.update_string("closed_", native_extraction_t<river_a>::create(&river_a::closed__));
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline river_a create(Args&&... args)
	{
		return river_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class river_a

template <typename _1>
class river_d : public range_d<>
{
public:
	inline forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > extract_begin() const
	{ throw dis("dynamic river_d::extract_begin() not available"); }

	inline forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > extract_end() const
	{ throw dis("dynamic river_d::extract_end() not available"); }

	inline any_a<> to_lake__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("to_lake_");
		if (!op)
		{
			throw dis("dynamic river_d::to_lake_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline lake_int8_a<> to_lake_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_lake_");
		if (!op)
		{
			throw dis("dynamic river_d::to_lake_ passed non-existent member");
		}
		return cast<lake_int8_a<>>(variadic_operate(op, *this));
	}

	inline std :: string to_string()
	{ return lake_to_string(to_lake_()); }

	inline any_a<> get_char__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("get_char_");
		if (!op)
		{
			throw dis("dynamic river_d::get_char_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_data_int8_a<> get_char_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("get_char_");
		if (!op)
		{
			throw dis("dynamic river_d::get_char_ passed non-existent member");
		}
		return cast<number_data_int8_a<>>(variadic_operate(op, *this));
	}

	inline int8_t get_char()
	{ return get_char_().extract_primitive(); }

	inline any_a<> peek_char__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("peek_char_");
		if (!op)
		{
			throw dis("dynamic river_d::peek_char_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline number_data_int8_a<> peek_char_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("peek_char_");
		if (!op)
		{
			throw dis("dynamic river_d::peek_char_ passed non-existent member");
		}
		return cast<number_data_int8_a<>>(variadic_operate(op, *this));
	}

	inline int8_t peek_char()
	{ return peek_char_().extract_primitive(); }

	inline any_a<> unget_char__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("unget_char_");
		if (!op)
		{
			throw dis("dynamic river_d::unget_char_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> unget_char_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("unget_char_");
		if (!op)
		{
			throw dis("dynamic river_d::unget_char_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this));
	}

	inline void unget_char()
	{ unget_char_(); }

	inline any_a<> put_back_char__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("put_back_char_");
		if (!op)
		{
			throw dis("dynamic river_d::put_back_char_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> put_back_char_(number_data_int8_a<> const& int_8)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("put_back_char_");
		if (!op)
		{
			throw dis("dynamic river_d::put_back_char_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, int_8));
	}

	inline void put_back_char(int8_t int_8 )
	{ put_back_char_(num(int_8)); }

	inline any_a<> get_line__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("get_line_");
		if (!op)
		{
			throw dis("dynamic river_d::get_line_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline lake_int8_a<> get_line_(number_data_int64_a<> const& count, number_data_int8_a<> const& delimiter)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("get_line_");
		if (!op)
		{
			throw dis("dynamic river_d::get_line_ passed non-existent member");
		}
		return cast<lake_int8_a<>>(variadic_operate(op, *this, count, delimiter));
	}

	inline std :: vector < int8_t > get_line(int64_t count , int8_t delimiter )
	{ return get_line_(num(count), num(delimiter)).extract_vector(); }

	inline any_a<> ignore__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("ignore_");
		if (!op)
		{
			throw dis("dynamic river_d::ignore_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> ignore_(number_data_int64_a<> const& count)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("ignore_");
		if (!op)
		{
			throw dis("dynamic river_d::ignore_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, count));
	}

	inline void ignore(int64_t count )
	{ ignore_(num(count)); }

	inline any_a<> read__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("read_");
		if (!op)
		{
			throw dis("dynamic river_d::read_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline lake_int8_a<> read_(number_data_int64_a<> const& count)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("read_");
		if (!op)
		{
			throw dis("dynamic river_d::read_ passed non-existent member");
		}
		return cast<lake_int8_a<>>(variadic_operate(op, *this, count));
	}

	inline std :: vector < int8_t > read(int64_t count )
	{ return read_(num(count)).extract_vector(); }

	inline std :: string read_string(int64_t count )
	{ return lake_to_string(read_(num(count))); }

	inline any_a<> tellg__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("tellg_");
		if (!op)
		{
			throw dis("dynamic river_d::tellg_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), arguments);
	}

	inline number_data_int64_a<> tellg_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("tellg_");
		if (!op)
		{
			throw dis("dynamic river_d::tellg_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline int64_t tellg() const
	{ return tellg_().extract_primitive(); }

	inline any_a<> seekg_beg__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("seekg_beg_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_beg_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> seekg_beg_(number_data_int64_a<> const& offset)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("seekg_beg_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_beg_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekg_beg(int64_t offset )
	{ seekg_beg_(num(offset)); }

	inline any_a<> seekg_end__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("seekg_end_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_end_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> seekg_end_(number_data_int64_a<> const& offset)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("seekg_end_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_end_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekg_end(int64_t offset )
	{ seekg_end_(num(offset)); }

	inline any_a<> seekg_cur__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("seekg_cur_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_cur_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> seekg_cur_(number_data_int64_a<> const& offset)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("seekg_cur_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_cur_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekg_cur(int64_t offset )
	{ seekg_cur_(num(offset)); }

	inline any_a<> sync__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("sync_");
		if (!op)
		{
			throw dis("dynamic river_d::sync_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline any_a<> sync_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("sync_");
		if (!op)
		{
			throw dis("dynamic river_d::sync_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this));
	}

	inline bool sync()
	{ return sync_(); }

	inline any_a<> put_char__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("put_char_");
		if (!op)
		{
			throw dis("dynamic river_d::put_char_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> put_char_(number_data_int8_a<> const& int_8)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("put_char_");
		if (!op)
		{
			throw dis("dynamic river_d::put_char_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, int_8));
	}

	inline void put_char(int8_t int_8 )
	{ put_char_(num(int_8)); }

	inline any_a<> write__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("write_");
		if (!op)
		{
			throw dis("dynamic river_d::write_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> write_(lake_int8_a<> const& lake)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("write_");
		if (!op)
		{
			throw dis("dynamic river_d::write_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, lake));
	}

	inline void write(std :: vector < int8_t > const & lake )
	{ write_(lake_int8_create(lake)); }

	inline void write_string(std :: string const & str )
	{ write_(lake_from_string(str)); }

	inline any_a<> tellp__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("tellp_");
		if (!op)
		{
			throw dis("dynamic river_d::tellp_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), arguments);
	}

	inline number_data_int64_a<> tellp_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("tellp_");
		if (!op)
		{
			throw dis("dynamic river_d::tellp_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline int64_t tellp() const
	{ return tellp_().extract_primitive(); }

	inline any_a<> seekp_beg__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("seekp_beg_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_beg_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> seekp_beg_(number_data_int64_a<> const& offset)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("seekp_beg_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_beg_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekp_beg(int64_t offset )
	{ seekp_beg_(num(offset)); }

	inline any_a<> seekp_end__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("seekp_end_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_end_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> seekp_end_(number_data_int64_a<> const& offset)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("seekp_end_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_end_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekp_end(int64_t offset )
	{ seekp_end_(num(offset)); }

	inline any_a<> seekp_cur__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("seekp_cur_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_cur_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> seekp_cur_(number_data_int64_a<> const& offset)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("seekp_cur_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_cur_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekp_cur(int64_t offset )
	{ seekp_cur_(num(offset)); }

	inline any_a<> flush__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("flush_");
		if (!op)
		{
			throw dis("dynamic river_d::flush_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> flush_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("flush_");
		if (!op)
		{
			throw dis("dynamic river_d::flush_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this));
	}

	inline void flush()
	{ flush_(); }

	inline any_a<> good__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("good_");
		if (!op)
		{
			throw dis("dynamic river_d::good_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), arguments);
	}

	inline any_a<> good_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("good_");
		if (!op)
		{
			throw dis("dynamic river_d::good_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline bool good() const
	{ return good_(); }

	inline any_a<> eof__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("eof_");
		if (!op)
		{
			throw dis("dynamic river_d::eof_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), arguments);
	}

	inline any_a<> eof_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("eof_");
		if (!op)
		{
			throw dis("dynamic river_d::eof_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline bool eof() const
	{ return eof_(); }

	inline any_a<> fail__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("fail_");
		if (!op)
		{
			throw dis("dynamic river_d::fail_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), arguments);
	}

	inline any_a<> fail_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("fail_");
		if (!op)
		{
			throw dis("dynamic river_d::fail_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline bool fail() const
	{ return fail_(); }

	inline any_a<> bad__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("bad_");
		if (!op)
		{
			throw dis("dynamic river_d::bad_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), arguments);
	}

	inline any_a<> bad_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("bad_");
		if (!op)
		{
			throw dis("dynamic river_d::bad_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline bool bad() const
	{ return bad_(); }

	inline any_a<> set_good__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("set_good_");
		if (!op)
		{
			throw dis("dynamic river_d::set_good_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> set_good_(any_a<> const& value)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("set_good_");
		if (!op)
		{
			throw dis("dynamic river_d::set_good_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, value));
	}

	inline void set_good(bool value )
	{ set_good_(boole(value)); }

	inline any_a<> set_eof__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("set_eof_");
		if (!op)
		{
			throw dis("dynamic river_d::set_eof_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> set_eof_(any_a<> const& value)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("set_eof_");
		if (!op)
		{
			throw dis("dynamic river_d::set_eof_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, value));
	}

	inline void set_eof(bool value )
	{ set_eof_(boole(value)); }

	inline any_a<> set_fail__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("set_fail_");
		if (!op)
		{
			throw dis("dynamic river_d::set_fail_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> set_fail_(any_a<> const& value)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("set_fail_");
		if (!op)
		{
			throw dis("dynamic river_d::set_fail_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, value));
	}

	inline void set_fail(bool value )
	{ set_fail_(boole(value)); }

	inline any_a<> set_bad__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("set_bad_");
		if (!op)
		{
			throw dis("dynamic river_d::set_bad_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline river_a<> set_bad_(any_a<> const& value)
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("set_bad_");
		if (!op)
		{
			throw dis("dynamic river_d::set_bad_ passed non-existent member");
		}
		return cast<river_a<>>(variadic_operate(op, *this, value));
	}

	inline void set_bad(bool value )
	{ set_bad_(boole(value)); }

	inline any_a<> filename__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("filename_");
		if (!op)
		{
			throw dis("dynamic river_d::filename_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), arguments);
	}

	inline lake_int8_a<> filename_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("filename_");
		if (!op)
		{
			throw dis("dynamic river_d::filename_ passed non-existent member");
		}
		return cast<lake_int8_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline std :: string filename() const
	{ return lake_to_string(filename_()); }

	inline any_a<> close__(range_a<> const& arguments)
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("close_");
		if (!op)
		{
			throw dis("dynamic river_d::close_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline any_a<> close_()
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("close_");
		if (!op)
		{
			throw dis("dynamic river_d::close_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this));
	}

	inline void close()
	{ close_(); }

	inline any_a<> closed__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("closed_");
		if (!op)
		{
			throw dis("dynamic river_d::closed_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), arguments);
	}

	inline any_a<> closed_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("closed_");
		if (!op)
		{
			throw dis("dynamic river_d::closed_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline bool closed()
	{ return closed_(); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit river_d(any_a<> const& thing)
		: range_d<>{ thing }
	{}

	explicit river_d(any_a<>& thing, any_a<>::___reference_tag___)
		: range_d<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit river_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: range_d<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
