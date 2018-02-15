#include "Rational.hpp"
#include <cstring>
#include <cmath>
#include <iostream>

//--------------------Default-Constructors------------------------------------//

//Overloaded constructor
Rational::Rational(int numerator, int denominator, const char* name)
{
    setNumerator(numerator);
    setDenominator(denominator);
    m_name = nullptr;
    setName(name);
    
}

//Default constructor
Rational::Rational()
{
    setNumerator(0);
    setDenominator(1);
    m_name = nullptr;
    setName("n/a");
}

void Rational::report(std::ostream& strm)
{
	strm << m_numerator << " / " << m_denominator;
}

//------------------------------End-of-Default----------------------------------//

//----------------------------Setter-Functions---------------------------------//

//setName goes through the array of name and sets it equal to m_name
void Rational::setName(const char* name)
{
    if(m_name != nullptr)
    {
        delete []m_name;
    }
    m_name = new char [strlen(name)+1];
    strcpy(m_name, name);
}


//   -------------------------------------------------------------------
//   
//    Sets denominator to an integer value. If the denominator is negative
//    then it is changed to a positive value and the numerator of the
//    Rational is changed to a negative to avoid negatives in the denominator.
//    It also calls the reduce function incase a simplification can be made.
//   
//   -------------------------------------------------------------------
void Rational::setDenominator(int b)
{
    if (b == 0)	// Prevents 0 denominators
    {
        //
        // TODO: We can eventually do something better, but doing this for now
        m_denominator = 1;
    }
    else if (b < 0)  // Corrects negative denominators
    {
        m_numerator = -1 * m_numerator;
        m_denominator = -1 * b;
        reduce();
    }
    else
    {
        m_denominator = b;
        reduce();
    }
}


//---------------------------End-of-Setters-----------------------------------//


//Copy constructor. Sets the new Rational equal to Rational num
Rational::Rational(const Rational& num)
{
    m_numerator = num.m_numerator;
    m_denominator = num.m_denominator;
    m_name = nullptr;
    setName(num.m_name);
}


//Assignment operator for Rational
Rational& Rational::operator=(const Rational& num)
{
    
    m_numerator = num.m_numerator;
    m_denominator = num.m_denominator;
    setName(num.m_name);
    
    return *this;
}

//---------------------------Math-Functions-----------------------------------//
Rational Rational::add(const Rational& x)
{
    Rational out;
    out.m_numerator = (x.m_numerator*this->m_denominator) + (this->m_numerator*x.m_denominator);
    out.m_denominator = this->m_denominator * x.m_denominator;
   
    out.reduce();
    return out;
}

Rational Rational::subtract(const Rational& x)
{
    Rational out;
    out.m_numerator = (this->m_numerator*x.m_denominator) - (x.m_numerator*this->m_denominator);
    out.m_denominator = this->m_denominator * x.m_denominator;
    
    out.reduce();
    out.setDenominator(this->m_denominator * x.m_denominator);
    
    return out;
}

Rational Rational::multiply(const Rational& x)
{
    Rational out;
    
    out.m_numerator = this->m_numerator * x.m_numerator;
    out.m_denominator = this->m_denominator * x.m_denominator;
    
    out.reduce();
    return out;
}

Rational Rational::divide(const Rational& x)
{
    Rational out;
    Rational temp = x;
    temp = temp.reciprocal();
    
    out.m_numerator = this->m_numerator * temp.m_numerator;
    out.m_denominator = this->m_denominator * temp.m_denominator;
    
    out.reduce();
    return out;
}

Rational Rational::reciprocal()
{
    Rational out;
    int temp = this->m_numerator;
    
    out.m_numerator = this->m_denominator;
    out.m_denominator = temp;
    
    return out;
}

Rational Rational::power(int x)
{
    Rational out;
    
    out.m_numerator = pow(this->m_numerator,x);
    out.m_denominator = pow(this->m_denominator,x);
    
    out.reduce();
    return out;
}

//---------------------------End-of-Math-Functions-------------------------------//

//---------------------------Overloaded-Operators-----------------------------------//

Rational Rational::operator+(const Rational& x)
{
    Rational out;
    out.m_numerator = (x.m_numerator*this->m_denominator) + (this->m_numerator*x.m_denominator);
    out.m_denominator = this->m_denominator * x.m_denominator;
    
    out.reduce();
    return out;
}

Rational& Rational::operator+=(const Rational& x)
{
    *this= this->add(x);
    return *this;
}

Rational Rational::operator-(const Rational& x)
{
    Rational out;
    out = this->subtract(x);
    
    return out;
}

Rational& Rational::operator-=(const Rational& x)
{
    *this= this->subtract(x);
    return *this;
}

Rational Rational::operator*(const Rational& x)
{
    Rational out;
    out = this->multiply(x);
    
    return out;
}

Rational& Rational::operator*=(const Rational& num)
{
    *this = this->multiply(num);
    return *this;
}

Rational Rational::operator/(const Rational& num)
{
    Rational out;
    out = this->divide(num);
    
    return out;
}

Rational& Rational::operator/=(const Rational& num)
{
    *this = this->divide(num);
    return *this;
}

Rational Rational::operator^(int num)
{
    Rational out;
    out = this->power(num);
    
    return out;
}

Rational& Rational::operator^=(int num)
{
    *this = this->power(num);
    return *this;
}

Rational Rational::operator~()
{
    Rational out;
    out = this->reciprocal();
    return out;
}

Rational::operator double()
{
    double num;
    
    num = this->m_numerator / this->m_denominator;
    
    return num;
}

bool Rational::operator==(const Rational& num)
{
    bool answer;
    Rational temp = num;
    
    if (static_cast<double>(*this) == static_cast<double>(temp))
    {
        answer = true;
    }
    else
    {
        answer = false;
    }
        
    return answer;
}

bool Rational::operator!=(const Rational& num)
{
    bool answer;
    Rational temp = num;
    
    if (static_cast<double>(*this) != static_cast<double>(temp))
    {
        answer = true;
    }
    else
    {
        answer = false;
    }
    
    return answer;
}

bool Rational::operator<=(const Rational& num)
{
    bool answer;
    Rational temp = num;
    
    if (static_cast<double>(*this) <= static_cast<double>(temp))
    {
        answer = true;
    }
    else
    {
        answer = false;
    }
    
    return answer;
}

bool Rational::operator>=(const Rational& num)
{
    bool answer;
    Rational temp = num;
    
    if (static_cast<double>(*this) >= static_cast<double>(temp))
    {
        answer = true;
    }
    else
    {
        answer = false;
    }
    
    return answer;
}

std::ostream& operator<<(std::ostream& strm, Rational& num)
{
    
    if(num.m_denominator == 1)
    {
        strm << num.m_numerator;
    }
    else
    {
        strm << num.m_numerator << "/" << num.m_denominator;
    }
    return strm;
    
}

//---------------------------End-of-Overloaded-Operators----------------------------//

//-------------------------------------------------------------------
//
// Reduces Rationals to their simplified form by dividing the num and den by
// the greatest common divisor
//
//-------------------------------------------------------------------
void Rational::reduce()
{
	int commonDivisor = gcd(abs(m_numerator), m_denominator);
	m_numerator = (m_numerator / commonDivisor);
	m_denominator = (m_denominator / commonDivisor);
}

//-------------------------------------------------------------------
//
// Finds the gcd of two integers
//
//-------------------------------------------------------------------
int Rational::gcd(int numerator, int denominator)
{
	if (denominator == 0)
	{
		return numerator;
	}

	return gcd(denominator, numerator % denominator);
}

//Destructor
Rational::~Rational()
{
    if(m_name != nullptr)
    {
        delete []m_name;
        m_name = nullptr;
    }
    else
    {
        std::cout << "EMPTY!!!!!!!!" << std::endl;
    }
}



