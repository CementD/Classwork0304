#include <iostream>

class Fraction
{
public:
    int numerator;
    int denominator;

public:
    const Fraction& getBigger(const Fraction& other) {
        if (this->denominator == other.denominator) {
            return this->numerator > other.numerator ? *this : other;
        }
        else if (this->numerator == other.numerator) {
            return this->denominator < other.denominator ? *this : other;
        }
        return (this->numerator * other.denominator > other.numerator * this->denominator) ? *this : other;
    }

    Fraction(int num, int denom) : numerator{ num }, denominator{ denom } {
        std::cout << "Creating Fraction object with address: " << this << std::endl;
    }

    //copy ctor
    // Fraction (const Fraction !!! other)
    // Fraction (!!! Fraction& other)

    void print() const {
        std::cout << numerator << "/" << denominator << " address: " << this << std::endl;
    }
};

int main()
{
    Fraction f1(2, 4);
    Fraction f2(1, 3);

    const Fraction& tmp = f1.getBigger(f2);
    tmp.print();

    return 0;
}