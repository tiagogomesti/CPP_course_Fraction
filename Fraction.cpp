#include "Fraction.h"

div_by_zero_error::div_by_zero_error(const string &msg) : range_error(msg)
{
}

denominator_zero_error::denominator_zero_error(const string &msg) : range_error(msg)
{
}

Fraction::Fraction() : numerator(0), denominator(1)
{
}

Fraction::Fraction(uint32_t fraction_value) : numerator(fraction_value), denominator(1)
{
}

Fraction::Fraction(uint32_t numerator, uint32_t denominator) throw(denominator_zero_error) : numerator(numerator), denominator(denominator)
{
    if (denominator == 0)
    {
        throw denominator_zero_error("Division by zero isn't possible!!!");
    }
}

Fraction::~Fraction()
{
}

uint32_t Fraction::greatest_commom_divisor(uint32_t n1, uint32_t n2)
{
    uint32_t gcd;

    if (n2 > n1)
    {
        uint32_t temp = n2;
        n2 = n1;
        n1 = temp;
    }

    for (int i = 1; i <= n2; ++i)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }

    return gcd;
}

uint32_t Fraction::lowest_commom_multiplier(uint32_t n1, uint32_t n2)
{
    uint32_t max = (n1 > n2) ? n1 : n2;

    do
    {
        if (max % n1 == 0 && max % n2 == 0)
        {
            break;
        }
        else
        {
            ++max;
        }
    } while (true);

    return max;
}

uint32_t Fraction::get_numerator(void)
{
    return numerator;
}

uint32_t Fraction::get_denominator(void)
{
    return denominator;
}

Fraction &Fraction::operator+=(Fraction fraction)
{
    *this = *this + fraction;
    return *this;
}

Fraction Fraction::operator!(void) // Reduces the fraction
{
    uint32_t gcd = greatest_commom_divisor(numerator, denominator);
    return Fraction(numerator / gcd, denominator / gcd);
}

Fraction Fraction::operator+(Fraction &fraction)
{
    uint32_t lcm = lowest_commom_multiplier(this->denominator, fraction.denominator);
    uint32_t new_numerator = ((lcm / this->denominator) * this->numerator) + ((lcm / fraction.denominator) * fraction.numerator);
    Fraction result(new_numerator, lcm);
    result = !result;

    return result;
}

Fraction Fraction::operator-(Fraction &fraction)
{
    uint32_t lcm = lowest_commom_multiplier(this->denominator, fraction.denominator);
    uint32_t new_numerator = ((lcm / this->denominator) * this->numerator) - ((lcm / fraction.denominator) * fraction.numerator);
    Fraction result(new_numerator, lcm);
    result = !result;

    return result;
}

Fraction Fraction::operator*(Fraction &fraction)
{
    Fraction result(this->numerator * fraction.numerator, this->denominator * fraction.denominator);
    result = !result;

    return result;
}

Fraction Fraction::operator/(Fraction &fraction) throw(div_by_zero_error)
{
    if (fraction.numerator == 0)
    {
        throw div_by_zero_error("Divsion by zero is forbiden!");
    }

    Fraction result(this->numerator * fraction.denominator, this->denominator * fraction.numerator);
    result = !result;

    return result;
}

ostream &operator<<(ostream &os, Fraction &fraction)
{
    os << "[" << fraction.get_numerator() << "/" << fraction.get_denominator() << "]";
    return os;
}

string Fraction::to_human_readable(void)
{
    return "";
}

double Fraction::to_double(void)
{
    return double(numerator) / double(denominator);
}
