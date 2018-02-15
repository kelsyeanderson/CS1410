#include <iostream>

#include "Rational.hpp"
#include "TestCases.hpp"

void report(Rational a, std::string operation, Rational b, Rational r)
{
    std::cout << a.getName() << " " << operation << " " << b.getName() << std::endl;
    a.report(std::cout);
    std::cout << " " << operation << " ";
    b.report(std::cout);
    std::cout << " = ";
    r.report(std::cout);
    std::cout << std::endl << std::endl;
    
    
}

void report(Rational a, std::string operation, Rational r)
{
    a.report(std::cout);
    std::cout << " " << operation << " ";
    r.report(std::cout);
    std::cout << std::endl << std::endl;
}

int main()
{
	TestCases::runTestCases();

	Rational c(1, 3, "first");
	Rational d(7, 9, "second");
	Rational x;

	std::cout << "-- Member Functions --" << std::endl << std::endl;
	
    report(c, "+", d, c.add(d));
	report(c, "-", d, c.subtract(d));
	report(c, "*", d, c.multiply(d));
	report(c, "/", d, c.divide(d));
	report(c, "reciprocal", c.reciprocal());
	report(c, "to power of 4", c.power(4));

	return 0;
}
