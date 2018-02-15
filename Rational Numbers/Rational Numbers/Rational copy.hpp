#ifndef _RATIONAL_HPP_
#define _RATIONAL_HPP_

#include <fstream>

class TestCases;

class Rational
{
public:

    //Default Constructor
    Rational();
    //Overloaded constructor
    Rational(int numerator, int denominator, const char* name);
	const char* getName() { return m_name; }
    //Copy Constructor
    Rational(const Rational& num);
    //Assignment operator
    Rational& operator=(const Rational& num);
    //Destructor
    ~Rational();
    
    //Overloaded operators
    Rational operator+(const Rational& num);
    Rational& operator+=(const Rational& num);
    Rational operator-(const Rational& num);
    Rational& operator-=(const Rational& num);
    Rational operator*(const Rational& num);
    Rational& operator*=(const Rational& num);
    Rational operator/(const Rational& num);
    Rational& operator/=(const Rational& num);
    Rational operator^(int num);
    Rational& operator^=(int num);
    Rational operator~();
    operator double();
    bool operator==(const Rational& num);
    bool operator!=(const Rational& num);
    bool operator<=(const Rational& num);
    bool operator>=(const Rational& num);
    friend std::ostream& operator<<(std::ostream& stream, const Rational& num);

	friend TestCases;

private:
	int m_numerator;
	int	m_denominator;
	char* m_name;

    //Math functions
    Rational add(const Rational& x);
    Rational subtract(const Rational& x);
    Rational multiply(const Rational& x);
    Rational divide(const Rational& x);
    Rational reciprocal();
    Rational power(int x);
    
    void report(std::ostream& strm);
	void reduce();
	int gcd(int, int);
	void setDenominator(int denominator);
    //Numerator setter
    void setNumerator(int numerator){m_numerator = numerator;};
    //Name setter
    void setName(const char* name);
    

};

#endif
