#include "gtest/gtest.h"

#include "root_.h"
#include "derived_.h"
#include "finale_.h"

class root
{
public:
	static root_ val__()
	{
		return root_{ root{} };
	}

	static root_ ref__()
	{
		return root_(root{}, true);
	}

	void print() const
	{
		std::cout << "root print" << std::endl;
	}

	void ___weak___(root_::___WEAK___ weak) const
	{
		_meek = weak;
	}

protected:
	mutable root_::___WEAK___ _meek;

private:
	root() {};
};

class derived
{
public:
	static derived_ val__()
	{
		return derived_{ derived{} };
	}

	static derived_ ref__()
	{
		return derived_(derived{}, true);
	}

	void mutate()
	{
		std::cout << "derived mutate" << std::endl;
	}

	void print() const
	{
		std::cout << "derived print" << std::endl;
	}

	void ___weak___(root_::___WEAK___ weak) const
	{
		_meek = weak;
	}

protected:
	mutable root_::___WEAK___ _meek;

private:
	derived() {};
};

class finale
{
public:
	static finale_ val__()
	{
		return finale_{ finale{} };
	}

	static finale_ ref__()
	{
		return finale_(finale{}, true);
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

	void ___weak___(root_::___WEAK___ weak) const
	{
		_meek = weak;
	}

protected:
	mutable root_::___WEAK___ _meek;

private:
	finale() {};
};

TEST(SomeTaste, TestName)
{
	root_ r_{ root::val__() };

	std::cout << "\n r_.print()" << std::endl;
	r_.print();

	derived_ d_{ derived::val__() };
	
	std::cout << "\n d_.print()" << std::endl;
	d_.print();
	std::cout << "\n d_.mutate()" << std::endl;
	d_.mutate();

	r_ = d_;

	std::cout << "\n r_.print()" << std::endl;
	r_.print();

	root_ r2{ d_ };

	std::cout << "\n r2.print()" << std::endl;
	r2.print();

	root_ r3{ derived::val__() };

	std::cout << "\n r3.print()" << std::endl;
	r3.print();

	derived_ d3{ cast_<derived_>(r3) };

	std::cout << "\n d3.mutate()" << std::endl;
	d3.mutate();

	finale_ f_{ finale::val__() };

	std::cout << "\n f_.print()" << std::endl;
	f_.print();
	std::cout << "\n f_.mutate()" << std::endl;
	f_.mutate();
	std::cout << "\n f_.finish()" << std::endl;
	f_.finish();

	r_ = f_;

	std::cout << "\n r_.print()" << std::endl;
	r_.print();

	EXPECT_TRUE(check<finale_>(r_));

	f_ = cast_<finale_>(r_);

	std::cout << "\n f_.print()" << std::endl;
	f_.print();
	std::cout << "\n f_.mutate()" << std::endl;
	f_.mutate();
	std::cout << "\n f_.finish()" << std::endl;
	f_.finish();

	r_ = f_;

	std::cout << "\n r_.print()" << std::endl;
	r_.print();

	r_ = r2;

	std::cout << "\n r_.print()" << std::endl;
	r_.print();

	root_ r4{ d_ };

	std::cout << "\n r4.print()" << std::endl;
	r4.print();

	d_ = f_;

	std::cout << "\n d_.print()" << std::endl;
	d_.print();

	derived_ d4{ f_ };

	std::cout << "\n d4.print()" << std::endl;
	d4.print();

	EXPECT_EQ(1, 1);
}

TEST(SomeTaste, BadTest)
{
	root_ r_{ root::val__() };
	if (check<derived_>(r_))
	{
		cast_<derived_>(r_);
	}
	EXPECT_EQ(1, 1);
}
