class A
{
public:
	A(char const*const lab)
		:label{ lab }
	{
		std__cout << "construct " << label << std::endl;
	}
	~A()
	{
		std__cout << "destruct " << label << std::endl;
	}
	char const*const label;
};

A make(char const*const label)
{
	return A{ label };
}

void fun(A& a, A& b)
{
	std__cout << "fun " << a.label << b.label << std::endl;
}

TEST_CASE("first", "[first]")
{
	std__cout << "first taste" << std::endl;
	A a{ "a" };
	fun(make("1"), make("2"));
	A b{ "b" };
}
