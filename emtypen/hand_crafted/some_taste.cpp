#include "gtest/gtest.h"

#include "base_.h"
#include "derived_.h"
#include "finale_.h"

class base
{
public:
	static base_ val()
	{
		return base_{ base{} };
	}

	void print() const
	{
		std::cout << "base print" << std::endl;
	}
private:
	base() {};
};

class derived
{
public:
	static derived_ val()
	{
		return derived_{ derived{} };
	}

	void mutate()
	{
		std::cout << "derived mutate" << std::endl;
	}

	void print() const
	{
		std::cout << "derived print" << std::endl;
	}
private:
	derived() {};
};

class finale
{
public:
	static finale_ val()
	{
		return finale_{ finale{} };
	}

	void finish()
	{
		std::cout << "finale finish" << std::endl;
	}

	void mutate()
	{
		std::cout << "finale mutate" << std::endl;
	}

	void print() const
	{
		std::cout << "finale print" << std::endl;
	}
private:
	finale() {};
};

TEST(SomeTaste, TestName) {

	base_ b_{ base::val() };

	std::cout << "\n b_.print()" << std::endl;
	b_.print();

	derived_ d_{ derived::val() };
	
	std::cout << "\n d_.print()" << std::endl;
	d_.print();
	std::cout << "\n d_.mutate()" << std::endl;
	d_.mutate();

	b_ = d_;

	std::cout << "\n b_.print()" << std::endl;
	b_.print();

	base_ b2{ d_ };

	std::cout << "\n b2.print()" << std::endl;
	b2.print();

	base_ b3{ derived::val() };

	std::cout << "\n b3.print()" << std::endl;
	b3.print();

	derived_ d3{ static_<derived_>(b3) };

	std::cout << "\n d3.mutate()" << std::endl;
	d3.mutate();

	finale_ f_{ finale::val() };

	std::cout << "\n f_.print()" << std::endl;
	f_.print();
	std::cout << "\n f_.mutate()" << std::endl;
	f_.mutate();
	std::cout << "\n f_.finish()" << std::endl;
	f_.finish();

	b_ = f_;

	std::cout << "\n b_.print()" << std::endl;
	b_.print();

	EXPECT_TRUE(check_<finale_>(b_));

	f_ = static_<finale_>(b_);

	std::cout << "\n f_.print()" << std::endl;
	f_.print();
	std::cout << "\n f_.mutate()" << std::endl;
	f_.mutate();
	std::cout << "\n f_.finish()" << std::endl;
	f_.finish();

	b_ = f_;

	std::cout << "\n b_.print()" << std::endl;
	b_.print();

	b_ = b2;

	std::cout << "\n b_.print()" << std::endl;
	b_.print();

	base_ b4{ d_ };

	std::cout << "\n b4.print()" << std::endl;
	b4.print();

	d_ = f_;

	std::cout << "\n d_.print()" << std::endl;
	d_.print();

	derived_ d4{ f_ };

	std::cout << "\n d4.print()" << std::endl;
	d4.print();

	EXPECT_EQ(1, 1);
}

TEST(SomeTaste, BadTest) {
	base_ b_{ base::val() };
	if (check_<derived_>(b_))
	{
		static_<derived_>(b_);
	}
	EXPECT_EQ(1, 1);
}
