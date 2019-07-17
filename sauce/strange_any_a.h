#ifndef COM_ONEISH_STRANGE_ANY_A_H
#define COM_ONEISH_STRANGE_ANY_A_H

 //#include "definitions.hpp"
 //#include "range_forward.hpp"
 //#include "symbol_forward.hpp"
 //#include "cat_forward.hpp"
 //#include "inventory_forward.hpp"
 //#include "unordered_herd_forward.hpp"
 //#include "shoal_forward.hpp"
 //#include "unordered_shoal_forward.hpp"
 //#include "number_data_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename range_a , typename symbol_a , typename cat_a , typename inventory_a , typename unordered_herd_a , typename shoal_a , typename unordered_shoal_a , typename number_data_a_uint64 >
    class any_a
    {
    public:
    	class hash_f
    	{
    	public:
    		inline std::size_t operator()(any_a const& thing) const
    		{
    			return thing.hash();
    		}
    	};
    
    	inline any_a operator[](range_a const& range)
    	{
    		return invoke_(*this, range);
    	}
    
    	inline any_a operator()(range_a const& range)
    	{
    		return operate_(*this, range);
    	}
    
    	inline operator bool() const
    	{
    		assert(handle_);
    		return read().operator bool();
    	}
    
    	inline any_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline any_a operator++(int)
    	{
    		assert(handle_);
    		any_a result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline any_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline any_a operator--(int)
    	{
    		assert(handle_);
    		any_a result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline any_a& operator+=(any_a const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline any_a& operator-=(any_a const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline any_a& operator*=(any_a const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline any_a& operator/=(any_a const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline any_a& operator%=(any_a const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     inline one_t const & const_thing ( ) const
     { assert(handle_); return read().const_thing( ); }
     inline one_t & mutable_thing ( )
     { assert(handle_); return write().mutable_thing( ); }
     inline any_a type__ ( range_a const & _ ) const
     { assert(handle_); return read().type__(_ ); }
     inline symbol_a type_ ( ) const
     { assert(handle_); return read().type_( ); }
     inline any_a shared__ ( range_a const & _ ) const
     { assert(handle_); return read().shared__(_ ); }
     inline unordered_shoal_a shared_ ( ) const
     { assert(handle_); return read().shared_( ); }
     inline void share ( shoal_a & shoal ) const
     { assert(handle_); read().share(shoal ); }
     inline any_a cat__ ( range_a const & _ ) const
     { assert(handle_); return read().cat__(_ ); }
     inline cat_a cat_ ( ) const
     { assert(handle_); return read().cat_( ); }
     inline any_a cats__ ( range_a const & _ ) const
     { assert(handle_); return read().cats__(_ ); }
     inline unordered_herd_a cats_ ( ) const
     { assert(handle_); return read().cats_( ); }
     inline any_a operations__ ( range_a const & _ ) const
     { assert(handle_); return read().operations__(_ ); }
     inline unordered_shoal_a operations_ ( ) const
     { assert(handle_); return read().operations_( ); }
     inline any_a eater__ ( range_a const & _ ) const
     { assert(handle_); return read().eater__(_ ); }
     inline any_a eater_ ( ) const
     { assert(handle_); return read().eater_( ); }
     inline any_a feeder__ ( range_a const & range ) const
     { assert(handle_); return read().feeder__(range ); }
     inline any_a visit__ ( range_a const & range ) const
     { assert(handle_); return read().visit__(range ); }
     inline any_a visit_ ( inventory_a & inventory ) const
     { assert(handle_); return read().visit_(inventory ); }
     inline any_a invoke_ ( any_a & thing , range_a const & range ) const
     { assert(handle_); return read().invoke_(thing, range ); }
     inline any_a operate_ ( any_a & thing , range_a const & range ) const
     { assert(handle_); return read().operate_(thing, range ); }
     inline any_a identity__ ( range_a const & _ ) const
     { assert(handle_); return read().identity__(_ ); }
     inline number_data_a_uint64 identity_ ( ) const
     { assert(handle_); return read().identity_( ); }
     inline void const * identity ( ) const
     { assert(handle_); return read().identity( ); }
     inline any_a identical__ ( range_a const & range ) const
     { assert(handle_); return read().identical__(range ); }
     inline any_a identical_ ( any_a const & thing ) const
     { assert(handle_); return read().identical_(thing ); }
     inline bool identical ( any_a const & thing ) const
     { assert(handle_); return read().identical(thing ); }
     inline any_a nothing__ ( range_a const & _ ) const
     { assert(handle_); return read().nothing__(_ ); }
     inline any_a nothing_ ( ) const
     { assert(handle_); return read().nothing_( ); }
     inline bool nothing ( ) const
     { assert(handle_); return read().nothing( ); }
     inline any_a something__ ( range_a const & _ ) const
     { assert(handle_); return read().something__(_ ); }
     inline any_a something_ ( ) const
     { assert(handle_); return read().something_( ); }
     inline bool something ( ) const
     { assert(handle_); return read().something( ); }
     inline any_a same__ ( range_a const & range ) const
     { assert(handle_); return read().same__(range ); }
     inline any_a same_ ( any_a const & thing ) const
     { assert(handle_); return read().same_(thing ); }
     inline bool operator == ( any_a const & thing ) const
     { assert(handle_); return read().operator==(thing ); }
     inline any_a different__ ( range_a const & range ) const
     { assert(handle_); return read().different__(range ); }
     inline any_a different_ ( any_a const & thing ) const
     { assert(handle_); return read().different_(thing ); }
     inline bool operator != ( any_a const & thing ) const
     { assert(handle_); return read().operator!=(thing ); }
     inline any_a hash__ ( range_a const & _ ) const
     { assert(handle_); return read().hash__(_ ); }
     inline number_data_a_uint64 hash_ ( ) const
     { assert(handle_); return read().hash_( ); }
     inline std :: size_t hash ( ) const
     { assert(handle_); return read().hash( ); }
     inline bool is ( std :: string const & s ) const
     { assert(handle_); return read().is(s ); }
     inline any_a ranged__ ( range_a const & _ ) const
     { assert(handle_); return read().ranged__(_ ); }
     inline range_a ranged_ ( ) const
     { assert(handle_); return read().ranged_( ); }
    
    protected:
    	struct ___root_handle_base___
    	{
    		___root_handle_base___() = default;
    		___root_handle_base___(___root_handle_base___ const&) = default;
    		___root_handle_base___(___root_handle_base___&&) = default;
    		___root_handle_base___& operator=(___root_handle_base___ const&) = default;
    		___root_handle_base___& operator=(___root_handle_base___&&) = default;
    		virtual ~___root_handle_base___() = default;
    
    		virtual std::shared_ptr<___root_handle_base___> ___clone___() const = 0;
    
    		virtual void ___weak___(std::weak_ptr<___root_handle_base___> const& weak) const = 0;
    
    		virtual inline operator bool() const = 0;
    
    		virtual inline void operator++() = 0;
    
    		virtual inline void operator--() = 0;
    
    		virtual inline void operator+=(any_a const& other) = 0;
    
    		virtual inline void operator-=(any_a const& other) = 0;
    
    		virtual inline void operator*=(any_a const& other) = 0;
    
    		virtual inline void operator/=(any_a const& other) = 0;
    
    		virtual inline void operator%=(any_a const& other) = 0;
    
      virtual inline one_t const & const_thing ( ) const = 0;
      virtual inline one_t & mutable_thing ( ) = 0;
      virtual inline any_a type__ ( range_a const & _ ) const = 0;
      virtual inline symbol_a type_ ( ) const = 0;
      virtual inline any_a shared__ ( range_a const & _ ) const = 0;
      virtual inline unordered_shoal_a shared_ ( ) const = 0;
      virtual inline void share ( shoal_a & shoal ) const = 0;
      virtual inline any_a cat__ ( range_a const & _ ) const = 0;
      virtual inline cat_a cat_ ( ) const = 0;
      virtual inline any_a cats__ ( range_a const & _ ) const = 0;
      virtual inline unordered_herd_a cats_ ( ) const = 0;
      virtual inline any_a operations__ ( range_a const & _ ) const = 0;
      virtual inline unordered_shoal_a operations_ ( ) const = 0;
      virtual inline any_a eater__ ( range_a const & _ ) const = 0;
      virtual inline any_a eater_ ( ) const = 0;
      virtual inline any_a feeder__ ( range_a const & range ) const = 0;
      virtual inline any_a visit__ ( range_a const & range ) const = 0;
      virtual inline any_a visit_ ( inventory_a & inventory ) const = 0;
      virtual inline any_a invoke_ ( any_a & thing , range_a const & range ) const = 0;
      virtual inline any_a operate_ ( any_a & thing , range_a const & range ) const = 0;
      virtual inline any_a identity__ ( range_a const & _ ) const = 0;
      virtual inline number_data_a_uint64 identity_ ( ) const = 0;
      virtual inline void const * identity ( ) const = 0;
      virtual inline any_a identical__ ( range_a const & range ) const = 0;
      virtual inline any_a identical_ ( any_a const & thing ) const = 0;
      virtual inline bool identical ( any_a const & thing ) const = 0;
      virtual inline any_a nothing__ ( range_a const & _ ) const = 0;
      virtual inline any_a nothing_ ( ) const = 0;
      virtual inline bool nothing ( ) const = 0;
      virtual inline any_a something__ ( range_a const & _ ) const = 0;
      virtual inline any_a something_ ( ) const = 0;
      virtual inline bool something ( ) const = 0;
      virtual inline any_a same__ ( range_a const & range ) const = 0;
      virtual inline any_a same_ ( any_a const & thing ) const = 0;
      virtual inline bool operator == ( any_a const & thing ) const = 0;
      virtual inline any_a different__ ( range_a const & range ) const = 0;
      virtual inline any_a different_ ( any_a const & thing ) const = 0;
      virtual inline bool operator != ( any_a const & thing ) const = 0;
      virtual inline any_a hash__ ( range_a const & _ ) const = 0;
      virtual inline number_data_a_uint64 hash_ ( ) const = 0;
      virtual inline std :: size_t hash ( ) const = 0;
      virtual inline bool is ( std :: string const & s ) const = 0;
      virtual inline any_a ranged__ ( range_a const & _ ) const = 0;
      virtual inline range_a ranged_ ( ) const = 0;
    	};
    
    	template <typename ___TTT___, typename ___BHB___ = ___root_handle_base___>
    	struct ___root_handle___ : ___BHB___
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___root_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: value_{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___root_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: value_{ std::move(value) }
    		{}
    
    		virtual inline void ___weak___(std::weak_ptr<___root_handle_base___> const& weak) const final
    		{
    			value_.___weak___(weak);
    		}
    
    		virtual inline operator bool() const final
    		{
    			return value_.operator bool();
    		}
    
    		virtual inline void operator++() final
    		{
    			value_.operator++();
    		}
    
    		virtual inline void operator--() final
    		{
    			value_.operator--();
    		}
    
    		virtual inline void operator+=(any_a const& other) final
    		{
    			value_.operator+=(other);
    		}
    
    		virtual inline void operator-=(any_a const& other) final
    		{
    			value_.operator-=(other);
    		}
    
    		virtual inline void operator*=(any_a const& other) final
    		{
    			value_.operator*=(other);
    		}
    
    		virtual inline void operator/=(any_a const& other) final
    		{
    			value_.operator/=(other);
    		}
    
    		virtual inline void operator%=(any_a const& other) final
    		{
    			value_.operator%=(other);
    		}
    
      virtual inline one_t const & const_thing ( ) const
      { return value_.const_thing( ); }
      virtual inline one_t & mutable_thing ( )
      { return value_.mutable_thing( ); }
      virtual inline any_a type__ ( range_a const & _ ) const
      { return value_.type__(_ ); }
      virtual inline symbol_a type_ ( ) const
      { return value_.type_( ); }
      virtual inline any_a shared__ ( range_a const & _ ) const
      { return value_.shared__(_ ); }
      virtual inline unordered_shoal_a shared_ ( ) const
      { return value_.shared_( ); }
      virtual inline void share ( shoal_a & shoal ) const
      { value_.share(shoal ); }
      virtual inline any_a cat__ ( range_a const & _ ) const
      { return value_.cat__(_ ); }
      virtual inline cat_a cat_ ( ) const
      { return value_.cat_( ); }
      virtual inline any_a cats__ ( range_a const & _ ) const
      { return value_.cats__(_ ); }
      virtual inline unordered_herd_a cats_ ( ) const
      { return value_.cats_( ); }
      virtual inline any_a operations__ ( range_a const & _ ) const
      { return value_.operations__(_ ); }
      virtual inline unordered_shoal_a operations_ ( ) const
      { return value_.operations_( ); }
      virtual inline any_a eater__ ( range_a const & _ ) const
      { return value_.eater__(_ ); }
      virtual inline any_a eater_ ( ) const
      { return value_.eater_( ); }
      virtual inline any_a feeder__ ( range_a const & range ) const
      { return value_.feeder__(range ); }
      virtual inline any_a visit__ ( range_a const & range ) const
      { return value_.visit__(range ); }
      virtual inline any_a visit_ ( inventory_a & inventory ) const
      { return value_.visit_(inventory ); }
      virtual inline any_a invoke_ ( any_a & thing , range_a const & range ) const
      { return value_.invoke_(thing, range ); }
      virtual inline any_a operate_ ( any_a & thing , range_a const & range ) const
      { return value_.operate_(thing, range ); }
      virtual inline any_a identity__ ( range_a const & _ ) const
      { return value_.identity__(_ ); }
      virtual inline number_data_a_uint64 identity_ ( ) const
      { return value_.identity_( ); }
      virtual inline void const * identity ( ) const
      { return value_.identity( ); }
      virtual inline any_a identical__ ( range_a const & range ) const
      { return value_.identical__(range ); }
      virtual inline any_a identical_ ( any_a const & thing ) const
      { return value_.identical_(thing ); }
      virtual inline bool identical ( any_a const & thing ) const
      { return value_.identical(thing ); }
      virtual inline any_a nothing__ ( range_a const & _ ) const
      { return value_.nothing__(_ ); }
      virtual inline any_a nothing_ ( ) const
      { return value_.nothing_( ); }
      virtual inline bool nothing ( ) const
      { return value_.nothing( ); }
      virtual inline any_a something__ ( range_a const & _ ) const
      { return value_.something__(_ ); }
      virtual inline any_a something_ ( ) const
      { return value_.something_( ); }
      virtual inline bool something ( ) const
      { return value_.something( ); }
      virtual inline any_a same__ ( range_a const & range ) const
      { return value_.same__(range ); }
      virtual inline any_a same_ ( any_a const & thing ) const
      { return value_.same_(thing ); }
      virtual inline bool operator == ( any_a const & thing ) const
      { return value_.operator==(thing ); }
      virtual inline any_a different__ ( range_a const & range ) const
      { return value_.different__(range ); }
      virtual inline any_a different_ ( any_a const & thing ) const
      { return value_.different_(thing ); }
      virtual inline bool operator != ( any_a const & thing ) const
      { return value_.operator!=(thing ); }
      virtual inline any_a hash__ ( range_a const & _ ) const
      { return value_.hash__(_ ); }
      virtual inline number_data_a_uint64 hash_ ( ) const
      { return value_.hash_( ); }
      virtual inline std :: size_t hash ( ) const
      { return value_.hash( ); }
      virtual inline bool is ( std :: string const & s ) const
      { return value_.is(s ); }
      virtual inline any_a ranged__ ( range_a const & _ ) const
      { return value_.ranged__(_ ); }
      virtual inline range_a ranged_ ( ) const
      { return value_.ranged_( ); }
    
    		___TTT___ value_;
    	};
    
    	template <typename ___TTT___, typename ___BHB___>
    	struct ___root_handle___<std::reference_wrapper<___TTT___>, ___BHB___>
    		: ___root_handle___<___TTT___&, ___BHB___>
    	{
    		inline ___root_handle___(std::reference_wrapper<___TTT___> ref)
    			: ___root_handle___<___TTT___&, ___BHB___>{ ref.get() }
    		{}
    	};
    
    	std::shared_ptr<___root_handle_base___> handle_;
    
    	bool const ___reference___;
    
    private:
    	template <typename ___TTT___>
    	struct ___root_handle_final___ final : ___root_handle___<___TTT___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___root_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: ___root_handle___<___TTT___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___root_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: ___root_handle___<___TTT___>{ std::move(value) }
    		{}
    
    		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
    		{
    			return std::make_shared<___root_handle_final___>(___root_handle___<___TTT___>::value_);
    		}
    	};
    
    	template <typename ___TTT___>
    	struct ___root_handle_final___<std::reference_wrapper<___TTT___>> final
    		: ___root_handle_final___<___TTT___&>
    	{
    		inline ___root_handle_final___(std::reference_wrapper<___TTT___> ref)
    			: ___root_handle_final___<___TTT___&>{ ref.get() }
    		{}
    	};
    
    	inline ___root_handle_base___ const& read() const noexcept
    	{
    		return *handle_;
    	}
    
    	inline ___root_handle_base___& write() noexcept
    	{
    		if (!___reference___ && !handle_.unique())
    		{
    			handle_ = handle_->___clone___();
    			handle_->___weak___(handle_);
    		}
    		return *handle_;
    	}
    
    	template <typename ___TTT___>
    	friend inline bool check(any_a<> const& value) noexcept;
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	friend inline ___TTT___ cast(any_a<> const& value, bool reference = false);
    #else
    	template <typename ___TTT___>
    	friend inline ___TTT___ cast(any_a<> const& value, bool reference = false) noexcept;
    #endif
    
    public:
    	using ___WEAK___ = std::weak_ptr<___root_handle_base___>;
    
    	static inline bool ___check___(std::shared_ptr<___root_handle_base___> const&) noexcept
    	{
    		return true;
    	}
    
    	inline any_a() noexcept
    		: handle_{}
    		, ___reference___{ false }
    	{}
    
    	explicit inline any_a(bool reference) noexcept
    		: handle_{}
    		, ___reference___{ reference }
    	{}
    
    	inline any_a(any_a const& other) noexcept
    		: handle_{ other.handle_ }
    		, ___reference___{ false }
    	{
    		handle_->___weak___(handle_);
    	}
    
    	inline any_a(any_a const& other, bool reference) noexcept
    		: handle_{ other.handle_ }
    		, ___reference___{ reference }
    	{
    		handle_->___weak___(handle_);
    	}
    
    	inline any_a(any_a&& other) noexcept
    		: handle_{ std::move(other.handle_) }
    		, ___reference___{ false }
    	{
    		handle_->___weak___(handle_);
    	}
    
    	inline any_a(any_a&& other, bool reference) noexcept
    		: handle_{ std::move(other.handle_) }
    		, ___reference___{ reference }
    	{
    		handle_->___weak___(handle_);
    	}
    
    	inline any_a& operator=(any_a const& other) noexcept
    	{
    		handle_ = other.handle_;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    
    	inline any_a& operator=(any_a&& other) noexcept
    	{
    		handle_ = std::move(other.handle_);
    		handle_->___weak___(handle_);
    		return *this;
    	}
    
    	virtual ~any_a() = default;
    
    	template <typename ___TTT___>
    	explicit inline any_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
    		: handle_{ handle }
    		, ___reference___{ reference }
    	{
    		handle_->___weak___(handle_);
    	}
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<any_a, std::decay_t<___TTT___>>::value>>
    	explicit inline any_a(___TTT___ value, bool reference = false) noexcept
    		: handle_{ std::make_shared<___root_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
    		, ___reference___{ reference }
    	{
    		handle_->___weak___(handle_);
    	}
    
    	template <typename ___TTT___>
    	inline any_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		handle_ = handle;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<any_a, std::decay_t<___TTT___>>::value>>
    	inline any_a& operator=(___TTT___ value) noexcept
    	{
    		any_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		handle_->___weak___(handle_);
    		return *this;
    	}
    };
    
    template <typename ___TTT___>
    inline bool check(any_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    template <typename ___TTT___, typename ___VVV___>
    inline bool check(___VVV___ const&) noexcept
    {
    	return false;
    }
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    template <typename ___TTT___>
    inline ___TTT___ cast(any_a<> const& value, bool reference)
    {
    	return ___TTT___(value.handle_, reference);
    }
    #else
    template <typename ___TTT___>
    inline ___TTT___ cast(any_a<> const& value, bool reference) noexcept
    {
    	return ___TTT___(value.handle_, reference);
    }
    #endif

}
#endif
