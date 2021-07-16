#ifndef _FRACTION_H
#define _FRACTION_H

#include<iostream>
#include<fstream>

class Fraction{
    int p; //numerator 
    unsigned int q; //denominator (unsigned because it's always positive)
    void normalize(); //function to reduce fraction to its lowest form

    public:
    Fraction(); //constructor when no argument is given
    explicit Fraction(int);  //constructor when only numerator is given, explicit as implicit typecasting isn't allowed
    Fraction(int, int);  //constructor when both numerator and denominator are given
    explicit Fraction(double); //constructor when fraction is given as a rational number (double)
    Fraction(const Fraction&); //copy-constructor
    ~Fraction(){}; //destructor (empty)
    Fraction& operator=(const Fraction&);  //Assignment operator
    Fraction operator-();  //unary - operator
    Fraction operator+();  //unary + operator
    Fraction operator++(); //pre increment operator
    Fraction operator++(int);  //post increment operator
    Fraction operator--(); //pre decrement operator
    Fraction operator--(int);  //post decrement operator
    static const Fraction sc_fUnity; //static constant
    static const Fraction sc_fZero;  //static constant
    friend Fraction operator+(const Fraction&,const Fraction&); //binary addition operator
    friend Fraction operator-(const Fraction&,const Fraction&); //binary subtraction operator
    friend Fraction operator*(const Fraction&,const Fraction&); //binary multiplication operator 
    friend Fraction operator/(const Fraction&,const Fraction&); //binary division operator
    friend Fraction operator%(const Fraction&,const Fraction&); //remainder operator
    bool operator==(const Fraction&);  //boolean equals operator
    bool operator!=(const Fraction&);  //boolean not-equals operator
    bool operator<(const Fraction&);   //boolean less than 
    bool operator<=(const Fraction&);  //boolean less than or equals to
    bool operator>(const Fraction&);   //boolean greater than
    bool operator>=(const Fraction&);  //boolean greater than or equals to
    Fraction operator!(); //not operator (returns q/p )
    friend std::ostream& operator<<(std::ostream&,const Fraction&); //ostream operator 
    friend std::istream& operator>>(std::istream&,Fraction&);       //istream operator 

};


#endif // _FRACTION_H
