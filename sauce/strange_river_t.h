#ifndef COM_ONEISH_STRANGE_RIVER_T_H
#define COM_ONEISH_STRANGE_RIVER_T_H

namespace strange
{

template <typename ___ego___ = river_a<>>
class river_t : public thing_t<___ego___>
{
	template <typename _iterator_, typename ___ego_it___ = forward_extractor_data_a<_iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// override
		using over = thing_o<extractor_t<_iterator_>>;

		// construction
		template <typename F>
		static inline forward_extractor_data_a<_iterator_> create(river_a<> const& river, F&& it)
		{
			return forward_extractor_data_a<_iterator_>::template create<over>(extractor_t<_iterator_>(river, std::forward<F>(it)));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::river::extractor");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<forward_extractor_data_a<_iterator_>>(thing) &&
				_it == fast<forward_extractor_data_a<_iterator_>>(thing).extract_it();
		}

		inline bool operator==(forward_extractor_data_a<_iterator_> const& it) const
		{
			return _it == it.extract_it();
		}

		inline bool operator!=(forward_extractor_data_a<_iterator_> const& it) const
		{
			return _it != it.extract_it();
		}

		inline std::size_t hash() const
		{
			return std::hash<int64_t>{}(_it == _iterator_{});
		}

		// forward extractor
		inline any_a<> get_() const
		{
			_int_8 = number_int_8_t<>::create(*_it);
			return _int_8;
		}

		inline any_a<> const* operator->() const
		{
			return &operator*();
		}

		inline any_a<> const& operator*() const
		{
			_int_8 = number_int_8_t<>::create(*_it);
			return _int_8;
		}

		inline void increment_()
		{
			++_it;
		}

		// data
		inline _iterator_ const& extract_it() const
		{
			return _it;
		}

		inline _iterator_& mutate_it()
		{
			return _it;
		}

	protected:
		_iterator_ _it;
		river_a<> const _river;
		number_data_a<int8_t> mutable _int_8; // stashing mutator

		template <typename F>
		inline extractor_t(river_a<> const& river, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _river{ river }
			, _int_8{ number_int_8_t<>::create_() }
		{}
	};

public:
	using std_shared_basic_ios_char = std::shared_ptr<std::basic_ios<char>>;
	using std_istreambuf_iterator_char = std::istreambuf_iterator<char>;

	// override
	using over = thing_o<river_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& _)
	{
		return create_();
	}

	static inline river_a<> create_()
	{
		return create();
	}

	static inline river_a<> create(std::string const& str = std::string())
	{
		std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(str);
		return river_a<>::create<over>(river_t<>(stream.get(), stream.get(), stream));
	}

	static inline any_a<> file__(range_a<> const& range)
	{
		forward_extractor_a<> it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("strange::river::file passed empty range");
		}
		any_a<> const name = *it;
		if (!check<lake_a<int8_t>>(name))
		{
			throw dis("strange::river::file passed non-lake-int-8");
		}
		if (++it == range.extract_end_())
		{
			return file_(fast<lake_a<int8_t>>(name));
		}
		any_a<> const in = *it;
		if (++it == range.extract_end_())
		{
			return file_(fast<lake_a<int8_t>>(name), in);
		}
		any_a<> const out = *it;
		if (++it == range.extract_end_())
		{
			return file_(fast<lake_a<int8_t>>(name), in, out);
		}
		return file_(fast<lake_a<int8_t>>(name), in, out, *it);
	}

	static inline river_a<> file_(lake_a<int8_t> const& name, any_a<> const& in = yes(), any_a<> const& out = no(), any_a<> const& trunc = no())
	{
		return file(lake_to_string(name));
	}

	static inline river_a<> file(std::string const& name, bool in = true, bool out = false, bool trunc = false)
	{
		std::shared_ptr<std::fstream> stream = std::make_shared<std::fstream>(name,
			std::fstream::binary |
			(in ? std::fstream::in : static_cast<std::fstream::openmode>(0)) |
			(out ? std::fstream::out : static_cast<std::fstream::openmode>(0)) |
			(trunc ? std::fstream::trunc : static_cast<std::fstream::openmode>(0)));
		return river_a<>::create<over>(river_t<>(stream.get(), stream.get(), stream, name));
	}

	static inline any_a<> in__(range_a<> const& _)
	{
		return in_();
	}

	static inline river_a<> in_()
	{
		return river_a<>::create<over>(river_t<>{ &std::cin });
	}

	static inline any_a<> out__(range_a<> const& _)
	{
		return out_();
	}

	static inline river_a<> out_()
	{
		return river_a<>::create<over>(river_t<>(nullptr, &std::cout));
	}

	static inline any_a<> err__(range_a<> const& _)
	{
		return err_();
	}

	static inline river_a<> err_()
	{
		return river_a<>::create<over>(river_t<>(nullptr, &std::cerr));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::river");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::river::create", native_function_create(&river_t<>::create__));
		shoal.update_string("strange::river::file", native_function_create(&river_t<>::file__));
		shoal.update_string("strange::river::in", native_function_create(&river_t<>::in__));
		shoal.update_string("strange::river::out", native_function_create(&river_t<>::out__));
		shoal.update_string("strange::river::err", native_function_create(&river_t<>::err__));
	}

	// range
	inline forward_extractor_a<> extract_begin_() const
	{
		if (!_istream)
		{
			throw dis("strange::river::extract_begin can only be called on input rivers");
		}
		return extractor_t<std_istreambuf_iterator_char>::create(thing_t<___ego___>::me_(), std_istreambuf_iterator_char{ *_istream });
	}

	inline forward_extractor_data_a<std_istreambuf_iterator_char> extract_begin() const
	{
		if (!_istream)
		{
			throw dis("strange::river::extract_begin can only be called on input rivers");
		}
		return extractor_t<std_istreambuf_iterator_char>::create(thing_t<___ego___>::me_(), std_istreambuf_iterator_char{ *_istream });
	}

	inline forward_extractor_a<> extract_end_() const
	{
		return extractor_t<std_istreambuf_iterator_char>::create(thing_t<___ego___>::me_(), std_istreambuf_iterator_char{});
	}

	inline forward_extractor_data_a<std_istreambuf_iterator_char> extract_end() const
	{
		return extractor_t<std_istreambuf_iterator_char>::create(thing_t<___ego___>::me_(), std_istreambuf_iterator_char{});
	}

	// river input
	inline std::string to_string()
	{
		std::string result;
		while (good())
		{
			result += read_string();
		}
		return result;
	}

	inline number_data_a<int8_t> get_char_()
	{
		return num(get_char());
	}

	inline int8_t get_char()
	{
		if (!_istream)
		{
			throw dis("strange::river::get can only be called on input rivers");
		}
		return int8_t(_istream->get());
	}

	inline number_data_a<int8_t> peek_char_()
	{
		return num(peek_char());
	}

	inline int8_t peek_char()
	{
		if (!_istream)
		{
			throw dis("strange::river::peek can only be called on input rivers");
		}
		return int8_t(_istream->peek());
	}

	inline any_a<> unget_char_()
	{
		unget_char();
		return thing_t<___ego___>::me_();
	}

	inline void unget_char()
	{
		if (!_istream)
		{
			throw dis("strange::river::unget can only be called on input rivers");
		}
		_istream->unget();
	}

	inline any_a<> put_back_char_(number_data_a<int8_t> const& int_8)
	{
		put_back_char(int_8.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void put_back_char(int8_t int_8)
	{
		if (!_istream)
		{
			throw dis("strange::river::unget can only be called on input rivers");
		}
		_istream->putback(char(int_8));
	}

	inline lake_a<int8_t> get_line_(number_data_a<int64_t> const& count = number_int_64_t<>::create(-1), number_data_a<int8_t> const& delimiter = number_int_8_t<>::create('\n'))
	{
		return lake_int_8_t<>::create(get_line(count.extract_primitive(), delimiter.extract_primitive()));
	}

	inline std::vector<int8_t> get_line(int64_t count = -1, int8_t delimiter = '\n')
	{
		if (!count)
		{
			return std::vector<int8_t>{};
		}
		if (!_istream)
		{
			throw dis("strange::river::getline can only be called on input rivers");
		}
		if (count < 0)
		{
			std::string str;
			std::getline(*_istream, str, char(delimiter));
			return std::vector<int8_t>(str.cbegin(), str.cend());
		}
		std::vector<int8_t> v(std::size_t(++count), 0);
		_istream->getline(reinterpret_cast<char*>(&v[0]), count, char(delimiter));
		v.resize(std::size_t(std::max<int64_t>(0, _istream->gcount() - 1)));
		return v;
	}

	inline any_a<> ignore_(number_data_a<int64_t> const& count = number_int_64_t<>::create(1))
	{
		ignore(count.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void ignore(int64_t count = 1)
	{
		if (!_istream)
		{
			throw dis("strange::river::ignore can only be called on input rivers");
		}
		_istream->ignore(count);
	}

	inline lake_a<int8_t> read_(number_data_a<int64_t> const& count = number_int_64_t<>::create(-1))
	{
		return lake_int_8_t<>::create(read(count.extract_primitive()));
	}

	inline std::vector<int8_t> read(int64_t count = -1)
	{
		if (!count)
		{
			return std::vector<int8_t>{};
		}
		if (!_istream)
		{
			throw dis("strange::river::read can only be called on input rivers");
		}
		if (count < 0)
		{
			count = STRANGE_RIVER_DEFAULT_READ_SIZE;
		}
		std::vector<int8_t> v(std::size_t(count), 0);
		_istream->read(reinterpret_cast<char*>(&v[0]), count);
		v.resize(std::size_t(_istream->gcount()));
		return v;
	}

	inline std::string read_string(int64_t count = -1)
	{
		if (!count)
		{
			return std::string{};
		}
		if (!_istream)
		{
			throw dis("strange::river::read_string can only be called on input rivers");
		}
		if (count < 0)
		{
			count = STRANGE_RIVER_DEFAULT_READ_SIZE;
		}
		std::string s(std::size_t(count), '\0');
		_istream->read(&s[0], count);
		s.resize(std::size_t(_istream->gcount()));
		return s;
	}

	inline number_data_a<int64_t> tellg_() const
	{
		return number_int_64_t<>::create(tellg());
	}

	inline int64_t tellg() const
	{
		if (!_istream)
		{
			throw dis("strange::river::tellg can only be called on input rivers");
		}
		return _istream->tellg();
	}

	inline any_a<> seekg_beg_(number_data_a<int64_t> const& offset = number_int_64_t<>::create_())
	{
		seekg_beg(offset.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void seekg_beg(int64_t offset = 0)
	{
		if (!_istream)
		{
			throw dis("strange::river::seekg_beg can only be called on input rivers");
		}
		_istream->seekg(offset, std::ios_base::beg);
	}

	inline any_a<> seekg_end_(number_data_a<int64_t> const& offset = number_int_64_t<>::create_())
	{
		seekg_end(offset.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void seekg_end(int64_t offset = 0)
	{
		if (!_istream)
		{
			throw dis("strange::river::seekg_end can only be called on input rivers");
		}
		_istream->seekg(offset, std::ios_base::end);
	}

	inline any_a<> seekg_cur_(number_data_a<int64_t> const& offset = number_int_64_t<>::create_())
	{
		seekg_cur(offset.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void seekg_cur(int64_t offset = 0)
	{
		if (!_istream)
		{
			throw dis("strange::river::seekg_cur can only be called on input rivers");
		}
		_istream->seekg(offset, std::ios_base::cur);
	}

	inline any_a<> sync_()
	{
		return boole(sync());
	}

	inline bool sync()
	{
		if (!_istream)
		{
			throw dis("strange::river::sync can only be called on input rivers");
		}
		return !_istream->sync();
	}

	// river output
	inline any_a<> put_char_(number_data_a<int8_t> const& int_8)
	{
		put_char(int_8.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void put_char(int8_t int_8)
	{
		if (!_ostream)
		{
			throw dis("strange::river::put can only be called on output rivers");
		}
		_ostream->put(char(int_8));
	}

	inline any_a<> write_(lake_a<int8_t> const& lake)
	{
		write(lake.extract_vector());
		return thing_t<___ego___>::me_();
	}

	inline void write(std::vector<int8_t> const& lake)
	{
		if (lake.empty())
		{
			return;
		}
		if (!_ostream)
		{
			throw dis("strange::river::write can only be called on output rivers");
		}
		_ostream->write(reinterpret_cast<char const*>(&lake[0]), int64_t(lake.size()));
	}

	inline void write_string(std::string const& str)
	{
		if (str.empty())
		{
			return;
		}
		if (!_ostream)
		{
			throw dis("strange::river::write_string can only be called on output rivers");
		}
		_ostream->write(&str[0], int64_t(str.length()));
	}

	inline number_data_a<int64_t> tellp_() const
	{
		return number_int_64_t<>::create(tellp());
	}

	inline int64_t tellp() const
	{
		if (!_ostream)
		{
			throw dis("strange::river::tellp can only be called on output rivers");
		}
		return _ostream->tellp();
	}

	inline any_a<> seekp_beg_(number_data_a<int64_t> const& offset = number_int_64_t<>::create_())
	{
		seekp_beg(offset.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void seekp_beg(int64_t offset = 0)
	{
		if (!_ostream)
		{
			throw dis("strange::river::seekp_beg can only be called on output rivers");
		}
		_ostream->seekp(offset, std::ios_base::beg);
	}

	inline any_a<> seekp_end_(number_data_a<int64_t> const& offset = number_int_64_t<>::create_())
	{
		seekp_end(offset.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void seekp_end(int64_t offset = 0)
	{
		if (!_ostream)
		{
			throw dis("strange::river::seekp_end can only be called on output rivers");
		}
		_ostream->seekp(offset, std::ios_base::end);
	}

	inline any_a<> seekp_cur_(number_data_a<int64_t> const& offset = number_int_64_t<>::create_())
	{
		seekp_cur(offset.extract_primitive());
		return thing_t<___ego___>::me_();
	}

	inline void seekp_cur(int64_t offset = 0)
	{
		if (!_ostream)
		{
			throw dis("strange::river::seekp_cur can only be called on output rivers");
		}
		_ostream->seekp(offset, std::ios_base::cur);
	}

	inline any_a<> flush_()
	{
		flush();
		return thing_t<___ego___>::me_();
	}

	inline void flush()
	{
		if (!_ostream)
		{
			throw dis("strange::river::flush can only be called on output rivers");
		}
		_ostream->flush();
	}

	// river
	inline any_a<> good_() const
	{
		return boole(good());
	}

	inline bool good() const
	{
		return (_istream ? static_cast<std::basic_ios<char>*>(_istream) : static_cast<std::basic_ios<char>*>(_ostream))->good();
	}

	inline any_a<> eof_() const
	{
		return boole(eof());
	}

	inline bool eof() const
	{
		return (_istream ? static_cast<std::basic_ios<char>*>(_istream) : static_cast<std::basic_ios<char>*>(_ostream))->eof();
	}

	inline any_a<> fail_() const
	{
		return boole(fail());
	}

	inline bool fail() const
	{
		return (_istream ? static_cast<std::basic_ios<char>*>(_istream) : static_cast<std::basic_ios<char>*>(_ostream))->fail();
	}

	inline any_a<> bad_() const
	{
		return boole(bad());
	}

	inline bool bad() const
	{
		return (_istream ? static_cast<std::basic_ios<char>*>(_istream) : static_cast<std::basic_ios<char>*>(_ostream))->bad();
	}

	inline any_a<> set_good_(any_a<> const& value = yes())
	{
		set_good(value.something());
		return thing_t<___ego___>::me_();
	}

	inline void set_good(bool value = true)
	{
		std::basic_ios<char>* const ios = _istream ? static_cast<std::basic_ios<char>*>(_istream) : static_cast<std::basic_ios<char>*>(_ostream);
		if (value)
		{
			ios->clear();
		}
		else
		{
			ios->setstate(std::ios_base::badbit);
		}
	}

	inline any_a<> set_eof_(any_a<> const& value = yes())
	{
		set_eof(value.something());
		return thing_t<___ego___>::me_();
	}

	inline void set_eof(bool value = true)
	{
		std::basic_ios<char>* const ios = _istream ? static_cast<std::basic_ios<char>*>(_istream) : static_cast<std::basic_ios<char>*>(_ostream);
		if (value)
		{
			ios->setstate(std::ios_base::eofbit);
		}
		else
		{
			ios->clear((ios->fail() ? std::ios_base::failbit : std::ios_base::goodbit) | (ios->bad() ? std::ios_base::badbit : std::ios_base::goodbit));
		}
	}

	inline any_a<> set_fail_(any_a<> const& value = yes())
	{
		set_fail(value.something());
		return thing_t<___ego___>::me_();
	}

	inline void set_fail(bool value = true)
	{
		std::basic_ios<char>* const ios = _istream ? static_cast<std::basic_ios<char>*>(_istream) : static_cast<std::basic_ios<char>*>(_ostream);
		if (value)
		{
			ios->setstate(std::ios_base::failbit);
		}
		else
		{
			ios->clear((ios->eof() ? std::ios_base::eofbit : std::ios_base::goodbit) | (ios->bad() ? std::ios_base::badbit : std::ios_base::goodbit));
		}
	}

	inline any_a<> set_bad_(any_a<> const& value = yes())
	{
		set_bad(value.something());
		return thing_t<___ego___>::me_();
	}

	inline void set_bad(bool value = true)
	{
		std::basic_ios<char>* const ios = _istream ? static_cast<std::basic_ios<char>*>(_istream) : static_cast<std::basic_ios<char>*>(_ostream);
		if (value)
		{
			ios->setstate(std::ios_base::badbit);
		}
		else
		{
			ios->clear((ios->eof() ? std::ios_base::eofbit : std::ios_base::goodbit) | (ios->fail() ? std::ios_base::failbit : std::ios_base::goodbit));
		}
	}

	inline lake_a<int8_t> filename_() const
	{
		return lake_from_string(_filename);
	}

	inline std::string filename() const
	{
		return _filename;
	}

protected:
	std::istream* const _istream;
	std::ostream* const _ostream;
	std_shared_basic_ios_char const _stream;
	std::string const _filename;

	inline river_t(std::istream* const is = nullptr, std::ostream* const os = nullptr, std_shared_basic_ios_char const& stream = std_shared_basic_ios_char{}, std::string const& filename = std::string{})
		: thing_t<___ego___>{}
		, _istream{ is }
		, _ostream{ os }
		, _stream{ stream }
		, _filename{ filename }
	{
		assert(_istream || _ostream);
	}

private:
	static bool const ___share___;
	friend class ___river_t_share___;
};

template <typename ___ego___>
bool const river_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	river_t<___ego___>::share(shoal);
	return shoal;
}();

class ___river_t_share___
{
	static inline bool ___share___()
	{
		return river_t<>::___share___;
	}
};

} // namespace strange

#endif
