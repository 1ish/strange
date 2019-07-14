#ifndef COM_ONEISH_STRANGE_CREATURE_C_H
#define COM_ONEISH_STRANGE_CREATURE_C_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class creature_c : public one_t
{
public:
	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::creature::val passed empty range");
		}
		any_a<> creation = *it;
		if (!check<shoal_a<>>(creation))
		{
			throw dis("strange::creature::val passed non-shoal creation");
		}
		return val_(cast<shoal_a<>>(creation));
	}

	static inline any_a<> val_(shoal_a<> const& creation)
	{
		return any_a<>{ creature_c{ creation } };
	}

	// erasure
	inline _ABSTRACTION_ const me_() const
	{
		return _ABSTRACTION_(_meek.lock(), true);
	}

	inline _ABSTRACTION_ me_()
	{
		return _ABSTRACTION_(_meek.lock(), true);
	}

	// reflection
	inline any_a<> type__(range_a<> const& range) const
	{
		auto op = _creation.at_string("type");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return reflection<creature_c<>>::type();
	}

	inline symbol_a<> type_() const
	{
		auto op = _creation.at_string("type");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<symbol_a<>>(result))
			{
				throw dis("strange::creature::type returned non-symbol");
			}
			return cast<symbol_a<>>(result);
		}
		return reflection<creature_c<>>::type();
	}

	inline any_a<> share__(range_a<> const& range) const
	{
		auto op = _creation.at_string("share");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::creature share passed empty range");
		}
		any_a<> thing = *it;
		if (!check<shoal_a<>>(thing))
		{
			throw dis("strange::creature share passed non-shoal");
		}
		reflection<creature_c<>>::share(cast<shoal_a<>>(thing, true));
		return thing;
	}

	inline shoal_a<> share_(shoal_a<>& shoal) const
	{
		auto op = _creation.at_string("share");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), shoal.ranged_());
			if (!check<shoal_a<>>(result))
			{
				throw dis("strange::creature::share returned non-shoal");
			}
			return cast<shoal_a<>>(result);
		}
		reflection<creature_c<>>::share(shoal);
		return shoal;
	}

	inline void share(shoal_a<>& shoal) const
	{
		auto op = _creation.at_string("share");
		if (op)
		{
			op.operate_(any_a<>(me_(), true), shoal.ranged_());
		}
		reflection<creature_c<>>::share(shoal);
	}

	inline any_a<> shared__(range_a<> const& range) const
	{
		auto op = _creation.at_string("shared");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::val_();
		share(shoal);
		return shoal;
	}

	inline unordered_shoal_a<> shared_() const
	{
		auto op = _creation.at_string("shared");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<unordered_shoal_a<>>(result))
			{
				throw dis("strange::creature::shared returned non-unordered-shoal");
			}
			return cast<unordered_shoal_a<>>(result);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::val_();
		share(shoal);
		return shoal;
	}

	inline any_a<> cat__(range_a<> const& range) const
	{
		auto op = _creation.at_string("cat");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return reflection<_ABSTRACTION_>::cat();
	}
	
	inline cat_a<> cat_() const
	{
		auto op = _creation.at_string("cat");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<cat_a<>>(result))
			{
				throw dis("strange::creature::shared returned non-cat");
			}
			return cast<cat_a<>>(result);
		}
		return reflection<_ABSTRACTION_>::cat();
	}

	inline any_a<> cats__(range_a<> const& range) const
	{
		auto op = _creation.at_string("cats");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return reflection<_ABSTRACTION_>::cats();
	}

	inline unordered_herd_a<> cats_() const
	{
		auto op = _creation.at_string("cats");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<unordered_herd_a<>>(result))
			{
				throw dis("strange::creature::shared returned non-unordered-herd");
			}
			return cast<unordered_herd_a<>>(result);
		}
		return reflection<_ABSTRACTION_>::cats();
	}

	inline any_a<> operations__(range_a<> const& range) const
	{
		auto op = _creation.at_string("operations");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return reflection<_ABSTRACTION_>::operations();
	}
	
	inline unordered_shoal_a<> operations_() const
	{
		auto op = _creation.at_string("operations");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<unordered_shoal_a<>>(result))
			{
				throw dis("strange::creature::operations returned non-unordered-shoal");
			}
			return cast<unordered_shoal_a<>>(result);
		}
		return reflection<_ABSTRACTION_>::operations();
	}

	inline any_a<> eater__(range_a<> const& range) const
	{
		auto op = _creation.at_string("eater");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return no();
	}

	inline any_a<> eater_() const
	{
		auto op = _creation.at_string("eater");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range_t<>::val_());
		}
		return no();
	}

	inline any_a<> feeder__(range_a<> const& range) const
	{
		auto op = _creation.at_string("feeder");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return no();
	}

	// visitor pattern
	inline any_a<> visit__(range_a<> const& range) const
	{
		auto op = _creation.at_string("visit");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return thing_t<>::operate__(range);
	}

	inline any_a<> visit_(inventory_a<>& inventory) const
	{
		return visit__(inventory);
	}

	// function
	inline any_a<> invoke_(any_a<>& thing, range_a<> const& range) const
	{
		auto op = _creation.at_string("invoke");
		if (op)
		{
			op.operate_(any_a<>(me_(), true), flock_t<>::val_(thing) += range);
		}
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::creature::invoke passed short range");
		}
		any_a<> member = *it;
		if (!thing.operations_().has_(member))
		{
			throw dis("strange::creature::invoke passed non-existent member");
		}
		return thing.operations_().at_(member).operate_(thing, range_t<>::val_(++it, range.cend_()));
	}

	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		auto op = _creation.at_string("operate");
		if (op)
		{
			op.operate_(any_a<>(me_(), true), flock_t<>::val_(thing) += range);
		}
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::creature::operate passed short range");
		}
		any_a<> operation = *it;
		return operation.operate_(thing, range_t<>::val_(++it, range.cend_()));
	}

	// identification
	inline any_a<> identity__(range_a<> const&) const // cannot be overridden
	{
		return identity_();
	}

	inline number_data_a<uint64_t> identity_() const
	{
		return number_uint_64_t<>::val(uint64_t(identity()));
	}

	inline any_a<> identical__(range_a<> const& range) const // cannot be overridden
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::creature::identical passed empty range");
		}
		return identical_(*it);
	}

	inline any_a<> identical_(any_a<> const& thing) const
	{
		return boole(identical(thing));
	}

	// comparison
	inline any_a<> nothing__(range_a<> const&) const // cannot be overridden
	{
		return nothing_();
	}

	inline any_a<> nothing_() const
	{
		return no();
	}

	inline any_a<> something__(range_a<> const&) const // cannot be overridden
	{
		return something_();
	}

	inline any_a<> something_() const
	{
		return yes();
	}

	inline any_a<> same__(range_a<> const& range) const
	{
		auto op = _creation.at_string("same");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::creature same passed empty range");
		}
		return identical_(*it);
	}

	inline any_a<> same_(any_a<> const& thing) const
	{
		auto op = _creation.at_string("same");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), thing.ranged_());
		}
		return identical_(thing);
	}

	inline bool operator==(any_a<> const& thing) const
	{
		auto op = _creation.at_string("same");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), thing.ranged_());
		}
		return identical(thing);
	}

	inline any_a<> different__(range_a<> const& range) const // cannot be overridden
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::creature different passed empty range");
		}
		return different_(*it);
	}

	inline any_a<> different_(any_a<> const& thing) const
	{
		return boole(operator!=(thing));
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !operator==(thing);
	}

	inline any_a<> hash__(range_a<> const& range) const
	{
		auto op = _creation.at_string("hash");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return number_uint_64_t<>::val(uint64_t(std::hash<void const*>{}(identity())));
	}

	inline number_data_a<uint64_t> hash_() const
	{
		auto op = _creation.at_string("hash");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<number_data_a<uint64_t>>(result))
			{
				throw dis("strange::creature::hash returned non-number-uint64");
			}
			return cast<number_data_a<uint64_t>>(result);
		}
		return number_uint_64_t<>::val(uint64_t(std::hash<void const*>{}(identity())));
	}

	inline std::size_t hash() const
	{
		auto op = _creation.at_string("hash");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<number_data_a<uint64_t>>(result))
			{
				throw dis("strange::creature::hash returned non-number-uint64");
			}
			return cast<number_data_a<uint64_t>>(result).extract();
		}
		return std::hash<void const*>{}(identity());
	}

	// conversion
	inline any_a<> ranged__(range_a<> const& _) const
	{
		return ranged_();
	}

	inline range_a<> ranged_() const
	{
		return range_t<>::val_(it_t<true>::val_(me_()), it_t<true>::val_());
	}

	// operators
	inline void operator++()
	{}

	inline void operator++(int)
	{}

	inline void operator--()
	{}

	inline void operator--(int)
	{}

	inline void operator+=(any_a<> const& other)
	{}

	inline void operator-=(any_a<> const& other)
	{}

	inline void operator*=(any_a<> const& other)
	{}

	inline void operator/=(any_a<> const& other)
	{}

	inline void operator%=(any_a<> const& other)
	{}

protected:
	shoal_a<> const _creation;

	// construction
	inline creature_c(shoal_a<> const& creation)
		: one_t{}
		, _creation{ creation }
	{}
};

} // namespace strange

#endif
