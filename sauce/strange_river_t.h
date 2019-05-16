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

		static inline river_a<> val(std::string const& str = std::string(), bool file = false)
		{
			if (file)
			{
				std::shared_ptr<std::fstream> stream = std::make_shared<std::fstream>(str, std::fstream::binary | std::fstream::in | std::fstream::out);
				return river_a<>{ river_t(stream.get(), stream.get(), stream, str) };
			}
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

		static inline river_a<> ref(std::string const& str = std::string(), bool file = false)
		{
			if (file)
			{
				std::shared_ptr<std::fstream> stream = std::make_shared<std::fstream>(str, std::fstream::binary | std::fstream::in | std::fstream::out);
				return river_a<>(river_t(stream.get(), stream.get(), stream, str), true);
			}
			std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(str);
			return river_a<>(river_t(stream.get(), stream.get(), stream), true);
		}

		static inline river_a<> cin()
		{
			return river_a<>{ river_t{ &std::cin } };
		}

		static inline river_a<> cout()
		{
			return river_a<>{ river_t(nullptr, &std::cout) };
		}

		static inline river_a<> cerr()
		{
			return river_a<>{ river_t(nullptr, &std::cerr) };
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

		any_a<> peek__(range_a<> const& _)
		{
			return peek_();
		}

		number_data_a<int8_t> peek_()
		{
			return number_int_8_t<>::val(peek());
		}

		int8_t peek()
		{
			if (!_istream)
			{
				throw dis("strange::river::peek can only be called on input rivers");
			}
			return int8_t(_istream->peek());
		}

		any_a<> unget__(range_a<> const& _);
		any_a<> unget_();
		void unget();

		any_a<> putback__(range_a<> const& range);
		any_a<> putback_(number_data_a<int8_t> const& int_8);
		void putback(int8_t int_8);

		any_a<> getline__(range_a<> const& range);
		lake_a<int8_t> getline_(number_data_a<int64_t> const& count, number_data_a<int8_t> const& delim);
		std::vector<int8_t> getline(int64_t count = -1, int8_t delim = '\n');

		any_a<> ignore__(range_a<> const& range);
		any_a<> ignore_(number_data_a<int64_t> const& count);
		void ignore(int64_t count = 1);

		any_a<> read__(range_a<> const& range);
		lake_a<int8_t> read_(number_data_a<int64_t> const& count);
		std::vector<int8_t> read(int64_t count = -1);

		any_a<> tellg__(range_a<> const& _) const;
		number_data_a<int64_t> tellg_() const;
		int64_t tellg() const;

		any_a<> seekg_beg__(range_a<> const& range);
		any_a<> seekg_beg_(number_data_a<int64_t> const& pos);
		void seekg_beg(int64_t pos);

		any_a<> seekg_end__(range_a<> const& range);
		any_a<> seekg_end_(number_data_a<int64_t> const& pos);
		void seekg_end(int64_t pos);

		any_a<> seekg_cur__(range_a<> const& range);
		any_a<> seekg_cur_(number_data_a<int64_t> const& pos);
		void seekg_cur(int64_t pos);

		any_a<> sync__(range_a<> const& _);
		any_a<> sync_();
		bool sync();

		// river output
		any_a<> put__(range_a<> const& range);
		any_a<> put_(number_data_a<int8_t> const& int_8);
		void put(int8_t int_8);

		any_a<> write__(range_a<> const& range);
		any_a<> write_(lake_a<int8_t> const& lake);
		void write(std::vector<int8_t> const& lake);

		any_a<> tellp__(range_a<> const& _) const;
		number_data_a<int64_t> tellp_() const;
		int64_t tellp() const;

		any_a<> seekp_beg__(range_a<> const& range);
		any_a<> seekp_beg_(number_data_a<int64_t> const& pos);
		void seekp_beg(int64_t pos);

		any_a<> seekp_end__(range_a<> const& range);
		any_a<> seekp_end_(number_data_a<int64_t> const& pos);
		void seekp_end(int64_t pos);

		any_a<> seekp_cur__(range_a<> const& range);
		any_a<> seekp_cur_(number_data_a<int64_t> const& pos);
		void seekp_cur(int64_t pos);

		any_a<> flush__(range_a<> const& _);
		any_a<> flush_();
		void flush();

		// river
		any_a<> good__(range_a<> const& _) const;
		any_a<> good_() const;
		bool good() const;

		any_a<> eof__(range_a<> const& _) const;
		any_a<> eof_() const;
		bool eof() const;

		any_a<> fail__(range_a<> const& _) const;
		any_a<> fail_() const;
		bool fail() const;

		any_a<> bad__(range_a<> const& _) const;
		any_a<> bad_() const;
		bool bad() const;

		any_a<> set_good__(range_a<> const& range);
		any_a<> set_good_(any_a<> const& value);
		void set_good(bool value);

		any_a<> set_eof__(range_a<> const& range);
		any_a<> set_eof_(any_a<> const& value);
		void set_eof(bool value);

		any_a<> set_fail__(range_a<> const& range);
		any_a<> set_fail_(any_a<> const& value);
		void set_fail(bool value);

		any_a<> set_bad__(range_a<> const& range);
		any_a<> set_bad_(any_a<> const& value);
		void set_bad(bool value);

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
