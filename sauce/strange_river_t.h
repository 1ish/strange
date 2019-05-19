#ifndef COM_ONEISH_STRANGE_RIVER_T_H
#define COM_ONEISH_STRANGE_RIVER_T_H

namespace strange
{

	template <typename _ABSTRACTION_ = river_a<>>
	class river_t : public something_t<_ABSTRACTION_>
	{
		template <typename ITERATOR, typename _ABSTRACTION_ = forward_const_iterator_data_a<ITERATOR>>
		class const_iterator_t : public something_t<_ABSTRACTION_>
		{
		public: ___STRANGE_THING___
			// construction
			template <typename F>
				static inline forward_const_iterator_data_a<ITERATOR> val(river_a<> const& river, F&& it)
				{
					return forward_const_iterator_data_a<ITERATOR>{ const_iterator_t(river, std::forward<F>(it)) };
				}

				template <typename F>
				static inline forward_const_iterator_data_a<ITERATOR> ref(river_a<> const& river, F&& it)
				{
					return forward_const_iterator_data_a<ITERATOR>(const_iterator_t(river, std::forward<F>(it)), true);
				}

				// reflection
				static inline symbol_a<> type_()
				{
					static symbol_a<> TYPE = sym("strange::river::const_iterator");
					return TYPE;
				}

				// comparison
				inline bool operator==(any_a<> const& thing) const
				{
					if (!check_<forward_const_iterator_data_a<ITERATOR>>(thing))
					{
						return false;
					}
					return _it == cast_<forward_const_iterator_data_a<ITERATOR>>(thing).extract();
				}

				inline bool operator!=(any_a<> const& thing) const
				{
					if (!check_<forward_const_iterator_data_a<ITERATOR>>(thing))
					{
						return true;
					}
					return _it != cast_<forward_const_iterator_data_a<ITERATOR>>(thing).extract();
				}

				inline std::size_t hash() const
				{
					return std::hash<int64_t>{}(_it == ITERATOR{});
				}

				// forward iterator
				inline any_a<> get__(range_a<> const&) const
				{
					return get_();
				}

				inline any_a<> get_() const
				{
					_int_8 = number_int_8_t<>::val(*_it);
					return _int_8;
				}

				inline any_a<> const* operator->() const
				{
					return &operator*();
				}

				inline any_a<> const& operator*() const
				{
					_int_8 = number_int_8_t<>::val(*_it);
					return _int_8;
				}

				inline _ABSTRACTION_ increment__(range_a<> const&)
				{
					return increment_();
				}

				inline _ABSTRACTION_ increment_()
				{
					operator++();
					return me_();
				}

				inline const_iterator_t& operator++()
				{
					++_it;
					return *this;
				}

				inline const_iterator_t operator++(int)
				{
					const_iterator_t result = *this;
					operator++();
					return result;
				}

				// data
				inline ITERATOR const& extract() const
				{
					return _it;
				}

				inline void mutate(ITERATOR const& it)
				{
					_it = it;
				}

				inline ITERATOR& reference()
				{
					return _it;
				}

		protected:
			ITERATOR _it;
			river_a<> _river;
			mutable number_data_a<int8_t> _int_8;

			template <typename F>
			inline const_iterator_t(river_a<> const& river, F&& it)
				: something_t{}
				, _it{ std::forward<F>(it) }
				, _river(river, true)
				, _int_8{ number_int_8_t<>::val_() }
			{}
		};

	public: ___STRANGE_COLLECTION___
		using std_shared_ios_base = std::shared_ptr<std::ios_base>;
		using std_istreambuf_iterator_char = std::istreambuf_iterator<char>;

		// construction
		static inline river_a<> val__(range_a<> const& _)
		{
			return val_();
		}

		static inline river_a<> val_()
		{
			return val();
		}

		static inline river_a<> val(std::string const& str = std::string())
		{
			std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(str);
			return river_a<>{ river_t(stream.get(), stream.get(), stream) };
		}

		static inline river_a<> ref__(range_a<> const& _)
		{
			return ref_();
		}

		static inline river_a<> ref_()
		{
			return ref();
		}

		static inline river_a<> ref(std::string const& str = std::string())
		{
			std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(str);
			return river_a<>(river_t(stream.get(), stream.get(), stream), true);
		}

		static inline river_a<> file(std::string const& name)
		{
			std::shared_ptr<std::fstream> stream = std::make_shared<std::fstream>(str, std::fstream::binary | std::fstream::in | std::fstream::out);
			return river_a<>(river_t(stream.get(), stream.get(), stream, name), true);
		}

		static inline river_a<> cin()
		{
			return river_a<>(river_t{ &std::cin }, true);
		}

		static inline river_a<> cout()
		{
			return river_a<>(river_t(nullptr, &std::cout), true);
		}

		static inline river_a<> cerr()
		{
			return river_a<>(river_t(nullptr, &std::cerr), true);
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::river");
			return TYPE;
		}

		inline any_a<> feeder__(range_a<> const& range) const // return range of parameter values
		{
			return nothing_t<>::val_(); //TODO
		}

		// visitor pattern
		static inline any_a<> visit__(range_a<> const& range)
		{
			return nothing_t<>::val_(); //TODO
		}

		// range
		inline forward_const_iterator_a<> cbegin() const
		{
			if (!_istream)
			{
				throw dis("strange::river::cbegin can only be called on input rivers");
			}
			return const_iterator_t<std_istreambuf_iterator_char>::val(me_(), std_istreambuf_iterator_char{ *_istream });
		}

		inline forward_const_iterator_a<> begin() const
		{
			if (!_istream)
			{
				throw dis("strange::river::begin can only be called on input rivers");
			}
			return const_iterator_t<std_istreambuf_iterator_char>::val(me_(), std_istreambuf_iterator_char{ *_istream });
		}

		inline forward_const_iterator_a<> cend() const
		{
			return const_iterator_t<std_istreambuf_iterator_char>::val(me_(), std_istreambuf_iterator_char{});
		}

		inline forward_const_iterator_a<> end() const
		{
			return const_iterator_t<std_istreambuf_iterator_char>::val(me_(), std_istreambuf_iterator_char{});
		}

		// river input
		inline any_a<> get__(range_a<> const& _)
		{
			return get_();
		}

		inline number_data_a<int8_t> get_()
		{
			return number_int_8_t<>::val(get());
		}

		inline int8_t get()
		{
			if (!_istream)
			{
				throw dis("strange::river::get can only be called on input rivers");
			}
			return int8_t(_istream->get());
		}

		inline any_a<> peek__(range_a<> const& _)
		{
			return peek_();
		}

		inline number_data_a<int8_t> peek_()
		{
			return number_int_8_t<>::val(peek());
		}

		inline int8_t peek()
		{
			if (!_istream)
			{
				throw dis("strange::river::peek can only be called on input rivers");
			}
			return int8_t(_istream->peek());
		}

		inline any_a<> unget__(range_a<> const& _)
		{
			return unget_();
		}

		inline any_a<> unget_()
		{
			unget();
			return me_();
		}

		inline void unget()
		{
			if (!_istream)
			{
				throw dis("strange::river::unget can only be called on input rivers");
			}
			_istream->unget();
		}

		inline any_a<> putback__(range_a<> const& range)
		{
			for (auto const& thing : range)
			{
				if (!check_<number_data_a<int8_t>>(thing))
				{
					throw dis("strange::river::putback called with non-int-8");
				}
				putback(cast_<number_data_a<int8_t>>(thing).extract());
			}
			return me_();
		}

		inline any_a<> putback_(number_data_a<int8_t> const& int_8)
		{
			putback(int_8.extract());
			return me_();
		}

		inline void putback(int8_t int_8)
		{
			if (!_istream)
			{
				throw dis("strange::river::unget can only be called on input rivers");
			}
			_istream->putback(char(int_8));
		}

		inline any_a<> getline__(range_a<> const& range)
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				return getline_();
			}
			any_a<> thing = *it;
			if (!check_<number_data_a<int64_t>>(thing))
			{
				throw dis("strange::river::getline passed non-int-64 count");
			}
			if (++it == range.cend())
			{
				return getline_(cast_<number_data_a<int64_t>>(thing));
			}
			any_a<> delimiter = *it;
			if (!check_<number_data_a<int8_t>>(delimiter))
			{
				throw dis("strange::river::getline passed non-int-8 delimiter");
			}
			return getline_(cast_<number_data_a<int64_t>>(thing), cast_<number_data_a<int8_t>>(delimiter));
		}

		inline lake_a<int8_t> getline_(number_data_a<int64_t> const& count = number_int_64_t<>::val(-1), number_data_a<int8_t> const& delimiter = number_int_8_t<>::val('\n'))
		{
			return lake_int_8_t<>::val(getline(count.extract(), delimiter.extract()));
		}

		inline std::vector<int8_t> getline(int64_t count = -1, int8_t delimiter = '\n')
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

		inline any_a<> ignore__(range_a<> const& range)
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				return ignore_();
			}
			any_a<> thing = *it;
			if (!check_<number_data_a<int64_t>>(thing))
			{
				throw dis("strange::river::ignore passed non-int-64 count");
			}
			return ignore_(cast_<number_data_a<int64_t>>(thing));
		}

		inline any_a<> ignore_(number_data_a<int64_t> const& count = number_int_64_t<>::val(1))
		{
			ignore(count.extract());
			return me_();
		}

		inline void ignore(int64_t count = 1)
		{
			if (!_istream)
			{
				throw dis("strange::river::ignore can only be called on input rivers");
			}
			_istream->ignore(count);
		}

		inline any_a<> read__(range_a<> const& range)
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				return read_();
			}
			any_a<> thing = *it;
			if (!check_<number_data_a<int64_t>>(thing))
			{
				throw dis("strange::river::read passed non-int-64 count");
			}
			return read_(cast_<number_data_a<int64_t>>(thing));
		}

		inline lake_a<int8_t> read_(number_data_a<int64_t> const& count = number_int_64_t<>::val(-1))
		{
			return lake_int_8_t<>::val(read(count.extract()));
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

		inline any_a<> tellg__(range_a<> const& _) const
		{
			return tellg_();
		}

		inline number_data_a<int64_t> tellg_() const
		{
			return number_int_64_t<>::val(tellg());
		}

		inline int64_t tellg() const
		{
			if (!_istream)
			{
				throw dis("strange::river::tellg can only be called on input rivers");
			}
			return _istream->tellg();
		}

		inline any_a<> seekg_beg__(range_a<> const& range)
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				return seekg_beg_();
			}
			any_a<> thing = *it;
			if (!check_<number_data_a<int64_t>>(thing))
			{
				throw dis("strange::river::seekg_beg passed non-int-64 offset");
			}
			return seekg_beg_(cast_<number_data_a<int64_t>>(thing));
		}

		inline any_a<> seekg_beg_(number_data_a<int64_t> const& offset = number_int_64_t<>::val_())
		{
			seekg_beg(offset.extract());
			return me_();
		}

		inline void seekg_beg(int64_t offset = 0)
		{
			if (!_istream)
			{
				throw dis("strange::river::seekg_beg can only be called on input rivers");
			}
			_istream->seekg(offset, std::ios_base::beg);
		}

		inline any_a<> seekg_end__(range_a<> const& range)
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				return seekg_end_();
			}
			any_a<> thing = *it;
			if (!check_<number_data_a<int64_t>>(thing))
			{
				throw dis("strange::river::seekg_end passed non-int-64 offset");
			}
			return seekg_end_(cast_<number_data_a<int64_t>>(thing));
		}

		inline any_a<> seekg_end_(number_data_a<int64_t> const& offset = number_int_64_t<>::val_())
		{
			seekg_end(offset.extract());
			return me_();
		}

		inline void seekg_end(int64_t offset = 0)
		{
			if (!_istream)
			{
				throw dis("strange::river::seekg_end can only be called on input rivers");
			}
			_istream->seekg(offset, std::ios_base::end);
		}

		inline any_a<> seekg_cur__(range_a<> const& range)
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				return seekg_cur_();
			}
			any_a<> thing = *it;
			if (!check_<number_data_a<int64_t>>(thing))
			{
				throw dis("strange::river::seekg_cur passed non-int-64 offset");
			}
			return seekg_cur_(cast_<number_data_a<int64_t>>(thing));
		}

		inline any_a<> seekg_cur_(number_data_a<int64_t> const& offset = number_int_64_t<>::val_())
		{
			seekg_cur(offset.extract());
			return me_();
		}

		inline void seekg_cur(int64_t offset = 0)
		{
			if (!_istream)
			{
				throw dis("strange::river::seekg_cur can only be called on input rivers");
			}
			_istream->seekg(offset, std::ios_base::cur);
		}

		inline any_a<> sync__(range_a<> const& _)
		{
			return sync_();
		}

		inline any_a<> sync_()
		{
			return _boole_(sync());
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
		inline any_a<> put__(range_a<> const& range)
		{
			for (auto const& thing : range)
			{
				if (!check_<number_data_a<int8_t>>(thing))
				{
					throw dis("strange::river::put called with non-int-8");
				}
				put(cast_<number_data_a<int8_t>>(thing).extract());
			}
			return me_();
		}

		inline any_a<> put_(number_data_a<int8_t> const& int_8)
		{
			put(int_8.extract());
			return me_();
		}

		inline void put(int8_t int_8)
		{
			if (!_ostream)
			{
				throw dis("strange::river::put can only be called on output rivers");
			}
			_ostream->put(char(int_8));
		}

		inline any_a<> write__(range_a<> const& range)
		{
			for (auto const& thing : range)
			{
				if (!check_<lake_a<int8_t>>(thing))
				{
					throw dis("strange::river::write called with non-lake-int-8");
				}
				write(cast_<lake_a<int8_t>>(thing).extract());
			}
			return me_();
		}

		inline any_a<> write_(lake_a<int8_t> const& lake)
		{
			write(lake.extract());
			return me_();
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

		inline any_a<> tellp__(range_a<> const& _) const
		{
			return tellp_();
		}

		inline number_data_a<int64_t> tellp_() const
		{
			return number_int_64_t<>::val(tellp());
		}

		inline int64_t tellp() const
		{
			if (!_ostream)
			{
				throw dis("strange::river::tellp can only be called on output rivers");
			}
			return _ostream->tellp();
		}

		inline any_a<> seekp_beg__(range_a<> const& range)
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				return seekp_beg_();
			}
			any_a<> thing = *it;
			if (!check_<number_data_a<int64_t>>(thing))
			{
				throw dis("strange::river::seekp_beg passed non-int-64 offset");
			}
			return seekp_beg_(cast_<number_data_a<int64_t>>(thing));
		}

		inline any_a<> seekp_beg_(number_data_a<int64_t> const& offset = number_int_64_t<>::val_())
		{
			seekp_beg(offset.extract());
			return me_();
		}

		inline void seekp_beg(int64_t offset = 0)
		{
			if (!_ostream)
			{
				throw dis("strange::river::seekp_beg can only be called on output rivers");
			}
			_ostream->seekp(offset, std::ios_base::beg);
		}

		inline any_a<> seekp_end__(range_a<> const& range)
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				return seekp_end_();
			}
			any_a<> thing = *it;
			if (!check_<number_data_a<int64_t>>(thing))
			{
				throw dis("strange::river::seekp_end passed non-int-64 offset");
			}
			return seekp_end_(cast_<number_data_a<int64_t>>(thing));
		}

		inline any_a<> seekp_end_(number_data_a<int64_t> const& offset = number_int_64_t<>::val_())
		{
			seekp_end(offset.extract());
			return me_();
		}

		inline void seekp_end(int64_t offset = 0)
		{
			if (!_ostream)
			{
				throw dis("strange::river::seekp_end can only be called on output rivers");
			}
			_ostream->seekp(offset, std::ios_base::end);
		}

		inline any_a<> seekp_cur__(range_a<> const& range)
		{
			forward_const_iterator_a<> it = range.cbegin();
			if (it == range.cend())
			{
				return seekp_cur_();
			}
			any_a<> thing = *it;
			if (!check_<number_data_a<int64_t>>(thing))
			{
				throw dis("strange::river::seekp_cur passed non-int-64 offset");
			}
			return seekp_cur_(cast_<number_data_a<int64_t>>(thing));
		}

		inline any_a<> seekp_cur_(number_data_a<int64_t> const& offset = number_int_64_t<>::val_())
		{
			seekp_cur(offset.extract());
			return me_();
		}

		inline void seekp_cur(int64_t offset = 0)
		{
			if (!_ostream)
			{
				throw dis("strange::river::seekp_cur can only be called on output rivers");
			}
			_ostream->seekp(offset, std::ios_base::cur);
		}

		inline any_a<> flush__(range_a<> const& _)
		{
			return flush_();
		}

		inline any_a<> flush_()
		{
			flush();
			return me_();
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
		inline any_a<> good__(range_a<> const& _) const;
		inline any_a<> good_() const;
		inline bool good() const;

		inline any_a<> eof__(range_a<> const& _) const;
		inline any_a<> eof_() const;
		inline bool eof() const;

		inline any_a<> fail__(range_a<> const& _) const;
		inline any_a<> fail_() const;
		inline bool fail() const;

		inline any_a<> bad__(range_a<> const& _) const;
		inline any_a<> bad_() const;
		inline bool bad() const;

		inline any_a<> set_good__(range_a<> const& range);
		inline any_a<> set_good_(any_a<> const& value);
		inline void set_good(bool value);

		inline any_a<> set_eof__(range_a<> const& range);
		inline any_a<> set_eof_(any_a<> const& value);
		inline void set_eof(bool value);

		inline any_a<> set_fail__(range_a<> const& range);
		inline any_a<> set_fail_(any_a<> const& value);
		inline void set_fail(bool value);

		inline any_a<> set_bad__(range_a<> const& range);
		inline any_a<> set_bad_(any_a<> const& value);
		inline void set_bad(bool value);

	protected:
		std::istream* const _istream;
		std::ostream* const _ostream;
		std_shared_ios_base const _stream;
		std::string const& _filename;

		inline river_t(std::istream* const is = nullptr, std::ostream* const os = nullptr, std_shared_ios_base const& stream = std_shared_ios_base{}, std::string const& filename = std::string{})
			: something_t{}
			, _istream{ is }
			, _ostream{ os }
			, _stream{ stream }
			, _filename{ filename }
		{}
	};

} // namespace strange

#endif
