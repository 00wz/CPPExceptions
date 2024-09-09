#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int numerator, int denominator):
        m_numerator(numerator), m_denominator(denominator)
    {
        if (denominator == 0)
        {
            throw std::runtime_error{ "DivideByZeroException" };
        }
    }

    friend std::ostream& operator <<(std::ostream& out, Fraction& fraction)
    {
        out << fraction.m_numerator << '/' << fraction.m_denominator;
        return out;
    }
};

int main()
{
    int numerator;
    int denominator;
    std::cout << "enter numerator: ";
    std::cin >> numerator;
    std::cout << "enter denominator: ";
    std::cin >> denominator;

    try
    {
        Fraction fraction{ numerator, denominator };
        std::cout << fraction;
    }
    catch(std::exception ex)
    {
        std::cout << ex.what();
    }

    return 0;
}
