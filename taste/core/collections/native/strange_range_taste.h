TEST_CASE("strange const range for loop", "[range_a]")
{
	auto const flock = flock_t<>::create_(lake::from_string("one\n"), lake::from_string("two\n"), lake::from_string("three\n"));
	for (auto sheep : flock)
	{
		sheep.mutate();
		if (check<lake_a<int8_t>>(sheep))
		{
			river_t<>::out_().write_(cast<lake_a<int8_t>>(sheep));
		}
	}
}

TEST_CASE("strange const range ref for loop", "[range_a]")
{
	auto const flock = flock_t<>::create_(lake::from_string("one\n"), lake::from_string("two\n"), lake::from_string("three\n"));
	for (auto& sheep : flock)
	{
		sheep.extract_thing();
		if (check<lake_a<int8_t>>(sheep))
		{
			river_t<>::out_().write_(cast<lake_a<int8_t>>(sheep));
		}
	}
}

TEST_CASE("strange range for loop", "[range_a]")
{
	auto flock = flock_t<>::create_(lake::from_string("one\n"), lake::from_string("two\n"), lake::from_string("three\n"));
	for (auto sheep : flock)
	{
		sheep.mutate();
		if (check<lake_a<int8_t>>(sheep))
		{
			river_t<>::out_().write_(cast<lake_a<int8_t>>(sheep));
		}
	}
}

TEST_CASE("strange range ref for loop", "[range_a]")
{
	auto flock = flock_t<>::create_(lake::from_string("one\n"), lake::from_string("two\n"), lake::from_string("three\n"));
	for (auto& sheep : flock)
	{
		sheep.mutate();
		if (check<lake_a<int8_t>>(sheep))
		{
			river_t<>::out_().write_(cast<lake_a<int8_t>>(sheep));
		}
	}
}