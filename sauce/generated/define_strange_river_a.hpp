
namespace strange
{

template <typename _1_ = void>
class river_d;

template <typename _1_ = void>
inline river_d<_1_> ___river_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename _1__chk = void>
inline bool check(river_a<_1__chk> const& value) noexcept;

template <typename _1_>
class river_a : public range_a<>
{
public:
	// arithmetic operator overloads
	inline river_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline river_a operator++(int)
	{
		assert(___handle___);
		river_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline river_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline river_a operator--(int)
	{
		assert(___handle___);
		river_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline river_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline river_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline river_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline river_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline river_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: string to_string()
	{ assert(___handle___); return ___write___().to_string(); }

	inline any_a<> get__(range_a<> const& range)
	{ assert(___handle___); return ___write___().get__(range); }

	inline number_data_int8_a<> get_()
	{ assert(___handle___); return ___write___().get_(); }

	inline int8_t get()
	{ assert(___handle___); return ___write___().get(); }

	inline any_a<> peek__(range_a<> const& range)
	{ assert(___handle___); return ___write___().peek__(range); }

	inline number_data_int8_a<> peek_()
	{ assert(___handle___); return ___write___().peek_(); }

	inline int8_t peek()
	{ assert(___handle___); return ___write___().peek(); }

	inline any_a<> unget__(range_a<> const& range)
	{ assert(___handle___); return ___write___().unget__(range); }

	inline any_a<> unget_()
	{ assert(___handle___); return ___write___().unget_(); }

	inline void unget()
	{ assert(___handle___); ___write___().unget(); }

	inline any_a<> putback__(range_a<> const& range)
	{ assert(___handle___); return ___write___().putback__(range); }

	inline any_a<> putback_(number_data_int8_a<> const& int_8)
	{ assert(___handle___); return ___write___().putback_(int_8); }

	inline void putback(int8_t int_8 )
	{ assert(___handle___); ___write___().putback(int_8); }

	inline any_a<> getline__(range_a<> const& range)
	{ assert(___handle___); return ___write___().getline__(range); }

	inline lake_int8_a<> getline_(number_data_int64_a<> const& count, number_data_int8_a<> const& delimiter)
	{ assert(___handle___); return ___write___().getline_(count, delimiter); }

	inline std :: vector < int8_t > getline(int64_t count , int8_t delimiter )
	{ assert(___handle___); return ___write___().getline(count, delimiter); }

	inline any_a<> ignore__(range_a<> const& range)
	{ assert(___handle___); return ___write___().ignore__(range); }

	inline any_a<> ignore_(number_data_int64_a<> const& count)
	{ assert(___handle___); return ___write___().ignore_(count); }

	inline void ignore(int64_t count )
	{ assert(___handle___); ___write___().ignore(count); }

	inline any_a<> read__(range_a<> const& range)
	{ assert(___handle___); return ___write___().read__(range); }

	inline lake_int8_a<> read_(number_data_int64_a<> const& count)
	{ assert(___handle___); return ___write___().read_(count); }

	inline std :: vector < int8_t > read(int64_t count )
	{ assert(___handle___); return ___write___().read(count); }

	inline std :: string read_string(int64_t count )
	{ assert(___handle___); return ___write___().read_string(count); }

	inline any_a<> tellg__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().tellg__(range); }

	inline number_data_int64_a<> tellg_() const
	{ assert(___handle___); return ___read___().tellg_(); }

	inline int64_t tellg() const
	{ assert(___handle___); return ___read___().tellg(); }

	inline any_a<> seekg_beg__(range_a<> const& range)
	{ assert(___handle___); return ___write___().seekg_beg__(range); }

	inline any_a<> seekg_beg_(number_data_int64_a<> const& offset)
	{ assert(___handle___); return ___write___().seekg_beg_(offset); }

	inline void seekg_beg(int64_t offset )
	{ assert(___handle___); ___write___().seekg_beg(offset); }

	inline any_a<> seekg_end__(range_a<> const& range)
	{ assert(___handle___); return ___write___().seekg_end__(range); }

	inline any_a<> seekg_end_(number_data_int64_a<> const& offset)
	{ assert(___handle___); return ___write___().seekg_end_(offset); }

	inline void seekg_end(int64_t offset )
	{ assert(___handle___); ___write___().seekg_end(offset); }

	inline any_a<> seekg_cur__(range_a<> const& range)
	{ assert(___handle___); return ___write___().seekg_cur__(range); }

	inline any_a<> seekg_cur_(number_data_int64_a<> const& offset)
	{ assert(___handle___); return ___write___().seekg_cur_(offset); }

	inline void seekg_cur(int64_t offset )
	{ assert(___handle___); ___write___().seekg_cur(offset); }

	inline any_a<> sync__(range_a<> const& range)
	{ assert(___handle___); return ___write___().sync__(range); }

	inline any_a<> sync_()
	{ assert(___handle___); return ___write___().sync_(); }

	inline bool sync()
	{ assert(___handle___); return ___write___().sync(); }

	inline any_a<> put__(range_a<> const& range)
	{ assert(___handle___); return ___write___().put__(range); }

	inline any_a<> put_(number_data_int8_a<> const& int_8)
	{ assert(___handle___); return ___write___().put_(int_8); }

	inline void put(int8_t int_8 )
	{ assert(___handle___); ___write___().put(int_8); }

	inline any_a<> write__(range_a<> const& range)
	{ assert(___handle___); return ___write___().write__(range); }

	inline any_a<> write_(lake_int8_a<> const& lake)
	{ assert(___handle___); return ___write___().write_(lake); }

	inline void write(std :: vector < int8_t > const & lake )
	{ assert(___handle___); ___write___().write(lake); }

	inline void write_string(std :: string const & str )
	{ assert(___handle___); ___write___().write_string(str); }

	inline any_a<> tellp__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().tellp__(range); }

	inline number_data_int64_a<> tellp_() const
	{ assert(___handle___); return ___read___().tellp_(); }

	inline int64_t tellp() const
	{ assert(___handle___); return ___read___().tellp(); }

	inline any_a<> seekp_beg__(range_a<> const& range)
	{ assert(___handle___); return ___write___().seekp_beg__(range); }

	inline any_a<> seekp_beg_(number_data_int64_a<> const& offset)
	{ assert(___handle___); return ___write___().seekp_beg_(offset); }

	inline void seekp_beg(int64_t offset )
	{ assert(___handle___); ___write___().seekp_beg(offset); }

	inline any_a<> seekp_end__(range_a<> const& range)
	{ assert(___handle___); return ___write___().seekp_end__(range); }

	inline any_a<> seekp_end_(number_data_int64_a<> const& offset)
	{ assert(___handle___); return ___write___().seekp_end_(offset); }

	inline void seekp_end(int64_t offset )
	{ assert(___handle___); ___write___().seekp_end(offset); }

	inline any_a<> seekp_cur__(range_a<> const& range)
	{ assert(___handle___); return ___write___().seekp_cur__(range); }

	inline any_a<> seekp_cur_(number_data_int64_a<> const& offset)
	{ assert(___handle___); return ___write___().seekp_cur_(offset); }

	inline void seekp_cur(int64_t offset )
	{ assert(___handle___); ___write___().seekp_cur(offset); }

	inline any_a<> flush__(range_a<> const& range)
	{ assert(___handle___); return ___write___().flush__(range); }

	inline any_a<> flush_()
	{ assert(___handle___); return ___write___().flush_(); }

	inline void flush()
	{ assert(___handle___); ___write___().flush(); }

	inline any_a<> good__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().good__(range); }

	inline any_a<> good_() const
	{ assert(___handle___); return ___read___().good_(); }

	inline bool good() const
	{ assert(___handle___); return ___read___().good(); }

	inline any_a<> eof__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().eof__(range); }

	inline any_a<> eof_() const
	{ assert(___handle___); return ___read___().eof_(); }

	inline bool eof() const
	{ assert(___handle___); return ___read___().eof(); }

	inline any_a<> fail__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().fail__(range); }

	inline any_a<> fail_() const
	{ assert(___handle___); return ___read___().fail_(); }

	inline bool fail() const
	{ assert(___handle___); return ___read___().fail(); }

	inline any_a<> bad__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().bad__(range); }

	inline any_a<> bad_() const
	{ assert(___handle___); return ___read___().bad_(); }

	inline bool bad() const
	{ assert(___handle___); return ___read___().bad(); }

	inline any_a<> set_good__(range_a<> const& range)
	{ assert(___handle___); return ___write___().set_good__(range); }

	inline any_a<> set_good_(any_a<> const& value)
	{ assert(___handle___); return ___write___().set_good_(value); }

	inline void set_good(bool value )
	{ assert(___handle___); ___write___().set_good(value); }

	inline any_a<> set_eof__(range_a<> const& range)
	{ assert(___handle___); return ___write___().set_eof__(range); }

	inline any_a<> set_eof_(any_a<> const& value)
	{ assert(___handle___); return ___write___().set_eof_(value); }

	inline void set_eof(bool value )
	{ assert(___handle___); ___write___().set_eof(value); }

	inline any_a<> set_fail__(range_a<> const& range)
	{ assert(___handle___); return ___write___().set_fail__(range); }

	inline any_a<> set_fail_(any_a<> const& value)
	{ assert(___handle___); return ___write___().set_fail_(value); }

	inline void set_fail(bool value )
	{ assert(___handle___); ___write___().set_fail(value); }

	inline any_a<> set_bad__(range_a<> const& range)
	{ assert(___handle___); return ___write___().set_bad__(range); }

	inline any_a<> set_bad_(any_a<> const& value)
	{ assert(___handle___); return ___write___().set_bad_(value); }

	inline void set_bad(bool value )
	{ assert(___handle___); ___write___().set_bad(value); }

	inline any_a<> filename__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().filename__(range); }

	inline lake_int8_a<> filename_() const
	{ assert(___handle___); return ___read___().filename_(); }

	inline std :: string filename() const
	{ assert(___handle___); return ___read___().filename(); }

protected:
	struct ___river_a_handle_base___ : ___range_a_handle_base___
	{
		virtual std :: string to_string() = 0;
		virtual any_a<> get__(range_a<> const& range) = 0;
		virtual number_data_int8_a<> get_() = 0;
		virtual int8_t get() = 0;
		virtual any_a<> peek__(range_a<> const& range) = 0;
		virtual number_data_int8_a<> peek_() = 0;
		virtual int8_t peek() = 0;
		virtual any_a<> unget__(range_a<> const& range) = 0;
		virtual any_a<> unget_() = 0;
		virtual void unget() = 0;
		virtual any_a<> putback__(range_a<> const& range) = 0;
		virtual any_a<> putback_(number_data_int8_a<> const& int_8) = 0;
		virtual void putback(int8_t int_8 ) = 0;
		virtual any_a<> getline__(range_a<> const& range) = 0;
		virtual lake_int8_a<> getline_(number_data_int64_a<> const& count, number_data_int8_a<> const& delimiter) = 0;
		virtual std :: vector < int8_t > getline(int64_t count , int8_t delimiter ) = 0;
		virtual any_a<> ignore__(range_a<> const& range) = 0;
		virtual any_a<> ignore_(number_data_int64_a<> const& count) = 0;
		virtual void ignore(int64_t count ) = 0;
		virtual any_a<> read__(range_a<> const& range) = 0;
		virtual lake_int8_a<> read_(number_data_int64_a<> const& count) = 0;
		virtual std :: vector < int8_t > read(int64_t count ) = 0;
		virtual std :: string read_string(int64_t count ) = 0;
		virtual any_a<> tellg__(range_a<> const& range) const = 0;
		virtual number_data_int64_a<> tellg_() const = 0;
		virtual int64_t tellg() const = 0;
		virtual any_a<> seekg_beg__(range_a<> const& range) = 0;
		virtual any_a<> seekg_beg_(number_data_int64_a<> const& offset) = 0;
		virtual void seekg_beg(int64_t offset ) = 0;
		virtual any_a<> seekg_end__(range_a<> const& range) = 0;
		virtual any_a<> seekg_end_(number_data_int64_a<> const& offset) = 0;
		virtual void seekg_end(int64_t offset ) = 0;
		virtual any_a<> seekg_cur__(range_a<> const& range) = 0;
		virtual any_a<> seekg_cur_(number_data_int64_a<> const& offset) = 0;
		virtual void seekg_cur(int64_t offset ) = 0;
		virtual any_a<> sync__(range_a<> const& range) = 0;
		virtual any_a<> sync_() = 0;
		virtual bool sync() = 0;
		virtual any_a<> put__(range_a<> const& range) = 0;
		virtual any_a<> put_(number_data_int8_a<> const& int_8) = 0;
		virtual void put(int8_t int_8 ) = 0;
		virtual any_a<> write__(range_a<> const& range) = 0;
		virtual any_a<> write_(lake_int8_a<> const& lake) = 0;
		virtual void write(std :: vector < int8_t > const & lake ) = 0;
		virtual void write_string(std :: string const & str ) = 0;
		virtual any_a<> tellp__(range_a<> const& range) const = 0;
		virtual number_data_int64_a<> tellp_() const = 0;
		virtual int64_t tellp() const = 0;
		virtual any_a<> seekp_beg__(range_a<> const& range) = 0;
		virtual any_a<> seekp_beg_(number_data_int64_a<> const& offset) = 0;
		virtual void seekp_beg(int64_t offset ) = 0;
		virtual any_a<> seekp_end__(range_a<> const& range) = 0;
		virtual any_a<> seekp_end_(number_data_int64_a<> const& offset) = 0;
		virtual void seekp_end(int64_t offset ) = 0;
		virtual any_a<> seekp_cur__(range_a<> const& range) = 0;
		virtual any_a<> seekp_cur_(number_data_int64_a<> const& offset) = 0;
		virtual void seekp_cur(int64_t offset ) = 0;
		virtual any_a<> flush__(range_a<> const& range) = 0;
		virtual any_a<> flush_() = 0;
		virtual void flush() = 0;
		virtual any_a<> good__(range_a<> const& range) const = 0;
		virtual any_a<> good_() const = 0;
		virtual bool good() const = 0;
		virtual any_a<> eof__(range_a<> const& range) const = 0;
		virtual any_a<> eof_() const = 0;
		virtual bool eof() const = 0;
		virtual any_a<> fail__(range_a<> const& range) const = 0;
		virtual any_a<> fail_() const = 0;
		virtual bool fail() const = 0;
		virtual any_a<> bad__(range_a<> const& range) const = 0;
		virtual any_a<> bad_() const = 0;
		virtual bool bad() const = 0;
		virtual any_a<> set_good__(range_a<> const& range) = 0;
		virtual any_a<> set_good_(any_a<> const& value) = 0;
		virtual void set_good(bool value ) = 0;
		virtual any_a<> set_eof__(range_a<> const& range) = 0;
		virtual any_a<> set_eof_(any_a<> const& value) = 0;
		virtual void set_eof(bool value ) = 0;
		virtual any_a<> set_fail__(range_a<> const& range) = 0;
		virtual any_a<> set_fail_(any_a<> const& value) = 0;
		virtual void set_fail(bool value ) = 0;
		virtual any_a<> set_bad__(range_a<> const& range) = 0;
		virtual any_a<> set_bad_(any_a<> const& value) = 0;
		virtual void set_bad(bool value ) = 0;
		virtual any_a<> filename__(range_a<> const& range) const = 0;
		virtual lake_int8_a<> filename_() const = 0;
		virtual std :: string filename() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___river_a_handle_base___>
	struct ___river_a_handle___ : ___range_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___river_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___range_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___river_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___range_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline std :: string to_string() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_string(); }

		virtual inline any_a<> get__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.get__(range); }

		virtual inline number_data_int8_a<> get_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.get_(); }

		virtual inline int8_t get() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.get(); }

		virtual inline any_a<> peek__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.peek__(range); }

		virtual inline number_data_int8_a<> peek_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.peek_(); }

		virtual inline int8_t peek() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.peek(); }

		virtual inline any_a<> unget__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.unget__(range); }

		virtual inline any_a<> unget_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.unget_(); }

		virtual inline void unget() final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.unget(); }

		virtual inline any_a<> putback__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.putback__(range); }

		virtual inline any_a<> putback_(number_data_int8_a<> const& int_8) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.putback_(int_8); }

		virtual inline void putback(int8_t int_8 ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.putback(int_8); }

		virtual inline any_a<> getline__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.getline__(range); }

		virtual inline lake_int8_a<> getline_(number_data_int64_a<> const& count, number_data_int8_a<> const& delimiter) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.getline_(count, delimiter); }

		virtual inline std :: vector < int8_t > getline(int64_t count , int8_t delimiter ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.getline(count, delimiter); }

		virtual inline any_a<> ignore__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.ignore__(range); }

		virtual inline any_a<> ignore_(number_data_int64_a<> const& count) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.ignore_(count); }

		virtual inline void ignore(int64_t count ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.ignore(count); }

		virtual inline any_a<> read__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.read__(range); }

		virtual inline lake_int8_a<> read_(number_data_int64_a<> const& count) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.read_(count); }

		virtual inline std :: vector < int8_t > read(int64_t count ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.read(count); }

		virtual inline std :: string read_string(int64_t count ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.read_string(count); }

		virtual inline any_a<> tellg__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.tellg__(range); }

		virtual inline number_data_int64_a<> tellg_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.tellg_(); }

		virtual inline int64_t tellg() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.tellg(); }

		virtual inline any_a<> seekg_beg__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_beg__(range); }

		virtual inline any_a<> seekg_beg_(number_data_int64_a<> const& offset) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_beg_(offset); }

		virtual inline void seekg_beg(int64_t offset ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_beg(offset); }

		virtual inline any_a<> seekg_end__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_end__(range); }

		virtual inline any_a<> seekg_end_(number_data_int64_a<> const& offset) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_end_(offset); }

		virtual inline void seekg_end(int64_t offset ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_end(offset); }

		virtual inline any_a<> seekg_cur__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_cur__(range); }

		virtual inline any_a<> seekg_cur_(number_data_int64_a<> const& offset) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_cur_(offset); }

		virtual inline void seekg_cur(int64_t offset ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_cur(offset); }

		virtual inline any_a<> sync__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.sync__(range); }

		virtual inline any_a<> sync_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.sync_(); }

		virtual inline bool sync() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.sync(); }

		virtual inline any_a<> put__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.put__(range); }

		virtual inline any_a<> put_(number_data_int8_a<> const& int_8) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.put_(int_8); }

		virtual inline void put(int8_t int_8 ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.put(int_8); }

		virtual inline any_a<> write__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.write__(range); }

		virtual inline any_a<> write_(lake_int8_a<> const& lake) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.write_(lake); }

		virtual inline void write(std :: vector < int8_t > const & lake ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.write(lake); }

		virtual inline void write_string(std :: string const & str ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.write_string(str); }

		virtual inline any_a<> tellp__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.tellp__(range); }

		virtual inline number_data_int64_a<> tellp_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.tellp_(); }

		virtual inline int64_t tellp() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.tellp(); }

		virtual inline any_a<> seekp_beg__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_beg__(range); }

		virtual inline any_a<> seekp_beg_(number_data_int64_a<> const& offset) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_beg_(offset); }

		virtual inline void seekp_beg(int64_t offset ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_beg(offset); }

		virtual inline any_a<> seekp_end__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_end__(range); }

		virtual inline any_a<> seekp_end_(number_data_int64_a<> const& offset) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_end_(offset); }

		virtual inline void seekp_end(int64_t offset ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_end(offset); }

		virtual inline any_a<> seekp_cur__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_cur__(range); }

		virtual inline any_a<> seekp_cur_(number_data_int64_a<> const& offset) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_cur_(offset); }

		virtual inline void seekp_cur(int64_t offset ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_cur(offset); }

		virtual inline any_a<> flush__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.flush__(range); }

		virtual inline any_a<> flush_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.flush_(); }

		virtual inline void flush() final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.flush(); }

		virtual inline any_a<> good__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.good__(range); }

		virtual inline any_a<> good_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.good_(); }

		virtual inline bool good() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.good(); }

		virtual inline any_a<> eof__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.eof__(range); }

		virtual inline any_a<> eof_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.eof_(); }

		virtual inline bool eof() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.eof(); }

		virtual inline any_a<> fail__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.fail__(range); }

		virtual inline any_a<> fail_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.fail_(); }

		virtual inline bool fail() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.fail(); }

		virtual inline any_a<> bad__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.bad__(range); }

		virtual inline any_a<> bad_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.bad_(); }

		virtual inline bool bad() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.bad(); }

		virtual inline any_a<> set_good__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_good__(range); }

		virtual inline any_a<> set_good_(any_a<> const& value) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_good_(value); }

		virtual inline void set_good(bool value ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_good(value); }

		virtual inline any_a<> set_eof__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_eof__(range); }

		virtual inline any_a<> set_eof_(any_a<> const& value) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_eof_(value); }

		virtual inline void set_eof(bool value ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_eof(value); }

		virtual inline any_a<> set_fail__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_fail__(range); }

		virtual inline any_a<> set_fail_(any_a<> const& value) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_fail_(value); }

		virtual inline void set_fail(bool value ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_fail(value); }

		virtual inline any_a<> set_bad__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_bad__(range); }

		virtual inline any_a<> set_bad_(any_a<> const& value) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_bad_(value); }

		virtual inline void set_bad(bool value ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.set_bad(value); }

		virtual inline any_a<> filename__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.filename__(range); }

		virtual inline lake_int8_a<> filename_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.filename_(); }

		virtual inline std :: string filename() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.filename(); }

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

		virtual inline ___SHARED___ ___clone___() const final
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
		return *std::static_pointer_cast<___river_a_handle_base___ const>(___handle___);
	}

	inline ___river_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___river_a_handle_base___>(___handle___);
	}

private:
	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(river_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___river_a_handle_base___>(handle));
	}

	static inline river_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___river_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return river_a{ ptr };
		}
		return river_a{ river_d<_1_>{ thing } };
	}

	static inline river_a val(river_a const& other) noexcept
	{
		return river_a{ other };
	}

	static inline river_a ref(river_a& other) noexcept
	{
		return river_a(other, ___reference_tag___{});
	}

	static inline river_a dup(river_a& other) noexcept
	{
		return river_a(other, ___duplicate_tag___{});
	}

	inline river_a() = default;

	inline river_a(river_a& other, ___reference_tag___) noexcept
		: range_a(other, ___reference_tag___{})
	{}

	inline river_a(river_a& other, ___duplicate_tag___) noexcept
		: range_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline river_a(std::shared_ptr<___TTT___> const& handle)
		: range_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___river_a_handle_base___>(handle))
		{
			throw dis("river_a constructor failed to cast from base to river_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline river_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: range_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___river_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline river_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: range_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___river_a_handle_base___>(handle))
		{
			throw dis("river_a constructor failed to cast from base to river_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline river_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: range_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___river_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<river_a, std::decay_t<___TTT___>>::value>>
	explicit inline river_a(___TTT___ value) noexcept
		: range_a{ std::make_shared<___river_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline river_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___river_a_handle_base___>(handle))
		{
			throw dis("river_a assignment failed to cast from base to river_a");
		}
		___handle___ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline river_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___river_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<river_a, std::decay_t<___TTT___>>::value>>
	inline river_a& operator=(___TTT___ value) noexcept
	{
		river_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___river_a_share___;
}; // class river_a

template <typename ___TTT___, typename _1__chk>
inline bool check(river_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

template <typename _1_>
bool const river_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<river_a<_1_>>::share(shoal);
	return shoal;
}();

template <typename _1_>
class river_d : public range_d<>
{
public:
	// arithmetic operator overloads
	inline river_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline river_d operator++(int)
	{
		assert(___handle___);
		river_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline river_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline river_d operator--(int)
	{
		assert(___handle___);
		river_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline river_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline river_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline river_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline river_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline river_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline std :: string to_string()
	{ throw dis("dynamic river_d::to_string() not available"); }

	inline any_a<> get__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("get_");
		if (!op)
		{
			throw dis("dynamic river_d::get_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline number_data_int8_a<> get_()
	{
		assert(___handle___);
		auto const op = operation("get_");
		if (!op)
		{
			throw dis("dynamic river_d::get_ passed non-existent member");
		}
		return cast<number_data_int8_a<>>(variadic_operate(op, *this));
	}

	inline int8_t get()
	{ return get_().extract_primitive(); }

	inline any_a<> peek__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("peek_");
		if (!op)
		{
			throw dis("dynamic river_d::peek_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline number_data_int8_a<> peek_()
	{
		assert(___handle___);
		auto const op = operation("peek_");
		if (!op)
		{
			throw dis("dynamic river_d::peek_ passed non-existent member");
		}
		return cast<number_data_int8_a<>>(variadic_operate(op, *this));
	}

	inline int8_t peek()
	{ return peek_().extract_primitive(); }

	inline any_a<> unget__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("unget_");
		if (!op)
		{
			throw dis("dynamic river_d::unget_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> unget_()
	{
		assert(___handle___);
		auto const op = operation("unget_");
		if (!op)
		{
			throw dis("dynamic river_d::unget_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this));
	}

	inline void unget()
	{ unget_(); }

	inline any_a<> putback__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("putback_");
		if (!op)
		{
			throw dis("dynamic river_d::putback_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> putback_(number_data_int8_a<> const& int_8)
	{
		assert(___handle___);
		auto const op = operation("putback_");
		if (!op)
		{
			throw dis("dynamic river_d::putback_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, int_8));
	}

	inline void putback(int8_t int_8 )
	{ putback_(num(int_8)); }

	inline any_a<> getline__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("getline_");
		if (!op)
		{
			throw dis("dynamic river_d::getline_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline lake_int8_a<> getline_(number_data_int64_a<> const& count, number_data_int8_a<> const& delimiter)
	{
		assert(___handle___);
		auto const op = operation("getline_");
		if (!op)
		{
			throw dis("dynamic river_d::getline_ passed non-existent member");
		}
		return cast<lake_int8_a<>>(variadic_operate(op, *this, count, delimiter));
	}

	inline std :: vector < int8_t > getline(int64_t count , int8_t delimiter )
	{ return getline_(num(count), num(delimiter)).extract_vector(); }

	inline any_a<> ignore__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("ignore_");
		if (!op)
		{
			throw dis("dynamic river_d::ignore_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> ignore_(number_data_int64_a<> const& count)
	{
		assert(___handle___);
		auto const op = operation("ignore_");
		if (!op)
		{
			throw dis("dynamic river_d::ignore_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, count));
	}

	inline void ignore(int64_t count )
	{ ignore_(num(count)); }

	inline any_a<> read__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("read_");
		if (!op)
		{
			throw dis("dynamic river_d::read_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline lake_int8_a<> read_(number_data_int64_a<> const& count)
	{
		assert(___handle___);
		auto const op = operation("read_");
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

	inline any_a<> tellg__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("tellg_");
		if (!op)
		{
			throw dis("dynamic river_d::tellg_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), range);
	}

	inline number_data_int64_a<> tellg_() const
	{
		assert(___handle___);
		auto const op = operation("tellg_");
		if (!op)
		{
			throw dis("dynamic river_d::tellg_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline int64_t tellg() const
	{ return tellg_().extract_primitive(); }

	inline any_a<> seekg_beg__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("seekg_beg_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_beg_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> seekg_beg_(number_data_int64_a<> const& offset)
	{
		assert(___handle___);
		auto const op = operation("seekg_beg_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_beg_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekg_beg(int64_t offset )
	{ seekg_beg_(num(offset)); }

	inline any_a<> seekg_end__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("seekg_end_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_end_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> seekg_end_(number_data_int64_a<> const& offset)
	{
		assert(___handle___);
		auto const op = operation("seekg_end_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_end_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekg_end(int64_t offset )
	{ seekg_end_(num(offset)); }

	inline any_a<> seekg_cur__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("seekg_cur_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_cur_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> seekg_cur_(number_data_int64_a<> const& offset)
	{
		assert(___handle___);
		auto const op = operation("seekg_cur_");
		if (!op)
		{
			throw dis("dynamic river_d::seekg_cur_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekg_cur(int64_t offset )
	{ seekg_cur_(num(offset)); }

	inline any_a<> sync__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("sync_");
		if (!op)
		{
			throw dis("dynamic river_d::sync_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> sync_()
	{
		assert(___handle___);
		auto const op = operation("sync_");
		if (!op)
		{
			throw dis("dynamic river_d::sync_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this));
	}

	inline bool sync()
	{ return sync_(); }

	inline any_a<> put__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("put_");
		if (!op)
		{
			throw dis("dynamic river_d::put_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> put_(number_data_int8_a<> const& int_8)
	{
		assert(___handle___);
		auto const op = operation("put_");
		if (!op)
		{
			throw dis("dynamic river_d::put_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, int_8));
	}

	inline void put(int8_t int_8 )
	{ put_(num(int_8)); }

	inline any_a<> write__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("write_");
		if (!op)
		{
			throw dis("dynamic river_d::write_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> write_(lake_int8_a<> const& lake)
	{
		assert(___handle___);
		auto const op = operation("write_");
		if (!op)
		{
			throw dis("dynamic river_d::write_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, lake));
	}

	inline void write(std :: vector < int8_t > const & lake )
	{ write_(lake_int8_create(lake)); }

	inline void write_string(std :: string const & str )
	{ write_(lake_from_string(str)); }

	inline any_a<> tellp__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("tellp_");
		if (!op)
		{
			throw dis("dynamic river_d::tellp_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), range);
	}

	inline number_data_int64_a<> tellp_() const
	{
		assert(___handle___);
		auto const op = operation("tellp_");
		if (!op)
		{
			throw dis("dynamic river_d::tellp_ passed non-existent member");
		}
		return cast<number_data_int64_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline int64_t tellp() const
	{ return tellp_().extract_primitive(); }

	inline any_a<> seekp_beg__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("seekp_beg_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_beg_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> seekp_beg_(number_data_int64_a<> const& offset)
	{
		assert(___handle___);
		auto const op = operation("seekp_beg_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_beg_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekp_beg(int64_t offset )
	{ seekp_beg_(num(offset)); }

	inline any_a<> seekp_end__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("seekp_end_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_end_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> seekp_end_(number_data_int64_a<> const& offset)
	{
		assert(___handle___);
		auto const op = operation("seekp_end_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_end_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekp_end(int64_t offset )
	{ seekp_end_(num(offset)); }

	inline any_a<> seekp_cur__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("seekp_cur_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_cur_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> seekp_cur_(number_data_int64_a<> const& offset)
	{
		assert(___handle___);
		auto const op = operation("seekp_cur_");
		if (!op)
		{
			throw dis("dynamic river_d::seekp_cur_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, offset));
	}

	inline void seekp_cur(int64_t offset )
	{ seekp_cur_(num(offset)); }

	inline any_a<> flush__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("flush_");
		if (!op)
		{
			throw dis("dynamic river_d::flush_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> flush_()
	{
		assert(___handle___);
		auto const op = operation("flush_");
		if (!op)
		{
			throw dis("dynamic river_d::flush_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this));
	}

	inline void flush()
	{ flush_(); }

	inline any_a<> good__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("good_");
		if (!op)
		{
			throw dis("dynamic river_d::good_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), range);
	}

	inline any_a<> good_() const
	{
		assert(___handle___);
		auto const op = operation("good_");
		if (!op)
		{
			throw dis("dynamic river_d::good_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline bool good() const
	{ return good_(); }

	inline any_a<> eof__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("eof_");
		if (!op)
		{
			throw dis("dynamic river_d::eof_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), range);
	}

	inline any_a<> eof_() const
	{
		assert(___handle___);
		auto const op = operation("eof_");
		if (!op)
		{
			throw dis("dynamic river_d::eof_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline bool eof() const
	{ return eof_(); }

	inline any_a<> fail__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("fail_");
		if (!op)
		{
			throw dis("dynamic river_d::fail_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), range);
	}

	inline any_a<> fail_() const
	{
		assert(___handle___);
		auto const op = operation("fail_");
		if (!op)
		{
			throw dis("dynamic river_d::fail_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline bool fail() const
	{ return fail_(); }

	inline any_a<> bad__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("bad_");
		if (!op)
		{
			throw dis("dynamic river_d::bad_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), range);
	}

	inline any_a<> bad_() const
	{
		assert(___handle___);
		auto const op = operation("bad_");
		if (!op)
		{
			throw dis("dynamic river_d::bad_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline bool bad() const
	{ return bad_(); }

	inline any_a<> set_good__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("set_good_");
		if (!op)
		{
			throw dis("dynamic river_d::set_good_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> set_good_(any_a<> const& value)
	{
		assert(___handle___);
		auto const op = operation("set_good_");
		if (!op)
		{
			throw dis("dynamic river_d::set_good_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, value));
	}

	inline void set_good(bool value )
	{ set_good_(boole(value)); }

	inline any_a<> set_eof__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("set_eof_");
		if (!op)
		{
			throw dis("dynamic river_d::set_eof_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> set_eof_(any_a<> const& value)
	{
		assert(___handle___);
		auto const op = operation("set_eof_");
		if (!op)
		{
			throw dis("dynamic river_d::set_eof_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, value));
	}

	inline void set_eof(bool value )
	{ set_eof_(boole(value)); }

	inline any_a<> set_fail__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("set_fail_");
		if (!op)
		{
			throw dis("dynamic river_d::set_fail_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> set_fail_(any_a<> const& value)
	{
		assert(___handle___);
		auto const op = operation("set_fail_");
		if (!op)
		{
			throw dis("dynamic river_d::set_fail_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, value));
	}

	inline void set_fail(bool value )
	{ set_fail_(boole(value)); }

	inline any_a<> set_bad__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("set_bad_");
		if (!op)
		{
			throw dis("dynamic river_d::set_bad_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> set_bad_(any_a<> const& value)
	{
		assert(___handle___);
		auto const op = operation("set_bad_");
		if (!op)
		{
			throw dis("dynamic river_d::set_bad_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, value));
	}

	inline void set_bad(bool value )
	{ set_bad_(boole(value)); }

	inline any_a<> filename__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("filename_");
		if (!op)
		{
			throw dis("dynamic river_d::filename_ passed non-existent member");
		}
		return op.operate(*const_cast<river_d*>(this), range);
	}

	inline lake_int8_a<> filename_() const
	{
		assert(___handle___);
		auto const op = operation("filename_");
		if (!op)
		{
			throw dis("dynamic river_d::filename_ passed non-existent member");
		}
		return cast<lake_int8_a<>>(variadic_operate(op, *const_cast<river_d*>(this)));
	}

	inline std :: string filename() const
	{ return lake_to_string(filename_()); }

	void ___weak___(range_d<>::___WEAK___ const& weak) const {}

	explicit river_d(any_a<> const& thing)
		: range_d<>{ thing }
	{}
};

template <typename _1_>
inline river_d<_1_> ___river_dynamic___(any_a<> const& thing)
{
	return river_d<_1_>{ thing };
}

} // namespace
