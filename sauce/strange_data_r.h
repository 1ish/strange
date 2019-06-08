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
		static cat_a<> CAT = cat_t<>::val("strange::data_dummy_read_lock_ptr");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<symbol_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<any_a<>>::operations();
	}
};

template<>
class reflection<data_a<std::shared_ptr<strange::concurrent_u<true>::read_lock>>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::data_concurrent_read_lock_ptr");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<symbol_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<any_a<>>::operations();
	}
};

template<>
class reflection<data_a<std::shared_ptr<strange::concurrent_u<false>::write_lock>>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::data_dummy_write_lock_ptr");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<symbol_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<any_a<>>::operations();
	}
};

template<>
class reflection<data_a<std::shared_ptr<strange::concurrent_u<true>::write_lock>>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::data_concurrent_write_lock_ptr");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<symbol_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<any_a<>>::operations();
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
		shoal.update("strange::data_dummy_read_lock_ptr::val", native_function_t<>::val(&data_t<std::shared_ptr<strange::concurrent_u<false>::read_lock>>::val__));
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
		shoal.update("strange::data_concurrent_read_lock_ptr::val", native_function_t<>::val(&data_t<std::shared_ptr<strange::concurrent_u<true>::read_lock>>::val__));
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
		shoal.update("strange::data_dummy_write_lock_ptr::val", native_function_t<>::val(&data_t<std::shared_ptr<strange::concurrent_u<false>::write_lock>>::val__));
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
		shoal.update("strange::data_concurrent_write_lock_ptr::val", native_function_t<>::val(&data_t<std::shared_ptr<strange::concurrent_u<true>::write_lock>>::val__));
	}
};

}

#endif