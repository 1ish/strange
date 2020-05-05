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
