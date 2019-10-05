#ifndef COM_ONEISH_STRANGE_DATA_R_H
#define COM_ONEISH_STRANGE_DATA_R_H

namespace strange
{

template<>
class reflection<data_a<std::shared_ptr<strange::concurrent_u<false>::read_lock>>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::data_dummy_read_lock_ptr");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<any_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<any_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

template<>
class reflection<data_a<std::shared_ptr<strange::concurrent_u<true>::read_lock>>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::data_concurrent_read_lock_ptr");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<any_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<any_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

template<>
class reflection<data_a<std::shared_ptr<strange::concurrent_u<false>::write_lock>>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::data_dummy_write_lock_ptr");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<any_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<any_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

template<>
class reflection<data_a<std::shared_ptr<strange::concurrent_u<true>::write_lock>>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::data_concurrent_write_lock_ptr");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<any_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<any_a<>>::operations();
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___data_a_share___
{
	static inline bool ___share___()
	{
		return data_a<std::shared_ptr<strange::concurrent_u<false>::read_lock>>::___share___
			&& data_a<std::shared_ptr<strange::concurrent_u<true>::read_lock>>::___share___
			&& data_a<std::shared_ptr<strange::concurrent_u<false>::write_lock>>::___share___
			&& data_a<std::shared_ptr<strange::concurrent_u<true>::write_lock>>::___share___;
	}
};

template<>
class reflection<data_t<std::shared_ptr<strange::concurrent_u<false>::read_lock>>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::data_dummy_read_lock_ptr");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::data_dummy_read_lock_ptr::create", native_function_t<>::create(&data_t<std::shared_ptr<strange::concurrent_u<false>::read_lock>>::create__));
	}
};

template<>
class reflection<data_t<std::shared_ptr<strange::concurrent_u<true>::read_lock>>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::data_concurrent_read_lock_ptr");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::data_concurrent_read_lock_ptr::create", native_function_t<>::create(&data_t<std::shared_ptr<strange::concurrent_u<true>::read_lock>>::create__));
	}
};

template<>
class reflection<data_t<std::shared_ptr<strange::concurrent_u<false>::write_lock>>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::data_dummy_write_lock_ptr");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::data_dummy_write_lock_ptr::create", native_function_t<>::create(&data_t<std::shared_ptr<strange::concurrent_u<false>::write_lock>>::create__));
	}
};

template<>
class reflection<data_t<std::shared_ptr<strange::concurrent_u<true>::write_lock>>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::data_concurrent_write_lock_ptr");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::data_concurrent_write_lock_ptr::create", native_function_t<>::create(&data_t<std::shared_ptr<strange::concurrent_u<true>::write_lock>>::create__));
	}
};

class ___data_t_share___
{
	static inline bool ___share___()
	{
		return data_t<std::shared_ptr<strange::concurrent_u<false>::read_lock>>::___share___
			&& data_t<std::shared_ptr<strange::concurrent_u<true>::read_lock>>::___share___
			&& data_t<std::shared_ptr<strange::concurrent_u<false>::write_lock>>::___share___
			&& data_t<std::shared_ptr<strange::concurrent_u<true>::write_lock>>::___share___;
	}
};

}

#endif
