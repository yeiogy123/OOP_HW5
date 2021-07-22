//
// Created by User on 2021/5/18.
//

#ifndef OOP_HW5_MIXED_H
#define OOP_HW5_MIXED_H
#include <iostream>
using namespace std;
class Mixed {
    friend istream & operator>>(istream &, Mixed&);
    friend ostream & operator<<(ostream &, const Mixed &);
private:
    int integer = 0;
    int numerator = 0;
    int denominator = 0;
public:
    Mixed(int = 0);
    Mixed(int, int, int);
    double Evaluate();
    void Simplify();
    void ToFraction();
    bool operator<(const Mixed &);
    bool operator>(const Mixed &);
    bool operator<=(const Mixed &);
    bool operator>=(const Mixed &);
    bool operator==(const Mixed &);
    bool operator!=(const Mixed &);
    Mixed operator+(const Mixed &);
    Mixed operator-(const Mixed &);
    Mixed operator*(const Mixed &);
    Mixed operator/(const Mixed &);
    Mixed &operator++();
    const Mixed operator++(int);
    Mixed & operator--();
    const Mixed operator--(int);
};
int TAD(int, int);

#endif //OOP_HW5_MIXED_H
