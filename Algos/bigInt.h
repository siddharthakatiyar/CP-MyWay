#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Algos
{
    class BigInt
    {
    public:
        BigInt();
        BigInt(const string& s);
        BigInt(const BigInt& other);
        BigInt& operator=(const BigInt& other);
        ~BigInt();

        BigInt operator+(const BigInt& other) const;
        BigInt operator-(const BigInt& other) const;
        BigInt operator*(const BigInt& other) const;
        BigInt operator/(const BigInt& other) const;
        BigInt operator%(const BigInt& other) const;
        BigInt operator^(const BigInt& other) const;
        BigInt operator+(const int& other) const;
        BigInt operator-(const int& other) const;
        BigInt operator*(const int& other) const;
        BigInt operator/(const int& other) const;
        BigInt operator%(const int& other) const;
        BigInt operator^(const int& other) const;
        BigInt& operator+=(const BigInt& other);
        BigInt& operator-=(const BigInt& other);
        BigInt& operator*=(const BigInt& other);
        BigInt& operator/=(const BigInt& other);
        BigInt& operator%=(const BigInt& other);
        BigInt& operator^=(const BigInt& other);
        BigInt& operator+=(const int& other);
        BigInt& operator-=(const int& other);
        BigInt& operator*=(const int& other);
        BigInt& operator/=(const int& other);
        BigInt& operator%=(const int& other);
        BigInt& operator^=(const int& other);
        bool operator==(const BigInt& other) const;
        bool operator!=(const BigInt& other) const;
        bool operator<(const BigInt& other) const;
        bool operator>(const BigInt& other) const;
        bool operator<=(const BigInt& other) const;
        bool operator>=(const BigInt& other) const;
        bool operator==(const int& other) const;
        bool operator!=(const int& other) const;
        bool operator<(const int& other) const;
        bool operator>(const int& other) const;
        bool operator<=(const int& other) const;
        bool operator>=(const int& other) const;
        friend ostream& operator<<(ostream& os, const BigInt& bi);
        friend istream& operator>>(istream& is, BigInt& bi);

    private:
        vector<int> digits;
        bool isNegative;

        void removeLeadingZeros();
        void addDigit(int digit);
        void addDigits(const vector<int>& digits);
        void subtractDigit(int digit);
        void subtractDigits(const vector<int>& digits);
        void multiplyDigit(int digit);
        void multiplyDigits(const vector<int>& digits);
        void divideDigit(int digit);
        void divideDigits(const vector<int>& digits);
        void modDigit(int digit);
        void modDigits(const vector<int>& digits);
        void powerDigit(int digit);
        void powerDigits(const vector<int>& digits);
        void add(const BigInt& other);
        void subtract(const BigInt& other);
        void multiply(const BigInt& other);
        void divide(const BigInt& other);
        void mod(const BigInt& other);
        void power(const BigInt& other);
        void add(const int& other);
        void subtract(const int& other);
        void multiply(const int& other);
        void divide(const int& other);
        void mod(const int& other);
        void power(const int& other);
    };
}

#endif // BIGINT_H