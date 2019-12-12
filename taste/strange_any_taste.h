TEST_CASE("strange any_a default constructor", "[any_a]")
{
	any_a<> a;
}

TEST_CASE("strange any_a basic logic", "[any_a]")
{
	any_a<> a;
	a = yes();
	REQUIRE(a);
	a = no();
	REQUIRE(!a);
}

TEST_CASE("strange for range loop", "[range_a]")
{
	auto flock = flock_t<>::create_();
	//TODO
	/*
	for (auto sheep : flock)
	{
		if (check<lake_a<int8_t>>(sheep))
		{
			river_t<>::out_().write_(cast<lake_a<int8_t>>(sheep));
		}
	}
	*/
}