#include <iostream>
#include <string>
#include <exception>
#include <algorithm>

using namespace std;

class div_by_zero_error : public range_error
{
public:
    explicit div_by_zero_error(const string &msg);
};

class denominator_zero_error : public range_error
{
public:
    explicit denominator_zero_error(const string &msg);
};

class Fraction
{
private:
    uint32_t numerator;
    uint32_t denominator;

    uint32_t greatest_commom_divisor(uint32_t n1, uint32_t n2);
    uint32_t lowest_commom_multiplier(uint32_t n1, uint32_t n2);

public:
    explicit Fraction();
    explicit Fraction(uint32_t fraction_value);
    explicit Fraction(uint32_t numerator, uint32_t denominator) throw(denominator_zero_error);
    ~Fraction();

    uint32_t get_numerator(void);
    uint32_t get_denominator(void);

    Fraction operator!(void); // Reduces the fraction
    Fraction operator+(Fraction &fraction);
    Fraction operator-(Fraction &fraction);
    Fraction operator*(Fraction &fraction);
    Fraction operator/(Fraction &fraction) throw(div_by_zero_error);
    Fraction& operator+=(Fraction fraction);

    string to_human_readable(void);
    double to_double(void);
};

ostream &operator<<(ostream &ostr, Fraction &f);
