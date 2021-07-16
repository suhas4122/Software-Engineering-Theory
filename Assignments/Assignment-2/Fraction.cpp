#include "Fraction.hxx"

using namespace std; 

//function to calculate gcd of 2 integers 
static int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if(a >= b)
    {
        if(b == 0)
            return a;
        return gcd(b,a%b);
    }
    else
    {
        if(a == 0)
            return b;
        return gcd(a,b%a);
    }
}

//function to calculate lcm of 2 integers (used to calculate common denominator)
static int lcm(int a, int b)
{
    int x = a*b/gcd(a, b);
    return x;
}

//function to return the precision we manually set (1e6 in this case)
static int precision()
{
    int x = 1000000;
    return x;
}

//constructor to initialise fraction without arguments (1/1 be default)
Fraction::Fraction()
{
    p = q = 1;
}

//constructor to initialise fraction with just the numerator (denominator taken 1 by default)
Fraction::Fraction(int a)
{
    p = a;
    q = 1;
}

//constructor to initialise fraction when both numerator and denominator are given
Fraction::Fraction(int a, int b)
{
    if(b == 0)
    {
        cout<<"Invalid call, denominator cannot be 0"<<endl;
        exit(1);
    }
    else if(a == 0)
    {
        p = 0;
        q = 1;
    }
    else if(b < 0)
    {
        p = -a;
        q = -b;
    }
    else
    {
        p = a;
        q = b;
    }
    int gc = gcd(p, q);
    p /= gc;
    q /= gc;
}

//constructor to initialise fraction from another rational number (using precision)
Fraction::Fraction(double d)
{
    //integer and fractional parts are seperated to prevent overflow 
    int i = (int)d;
    Fraction f1(i);
    double i1 = (double)i;
    double fraction = d - i1;
    int num = fraction * precision();
    int gc = gcd(num, precision());
    num = num / gc;
    int den = precision() / gc;
    p = num + den*i1;
    q = den;
}

//funtion to reduce a fraction to its lowest form (diving p and q by gcd of p and q)
inline void Fraction::normalize()
{
    if(q == 0){
        exit(1);
    }
    else if(p == 0){
        q = 1;
        return ;
    }
    else
    {
        int k = gcd(p,q);
        p = p/k;
        q = q/k;
        return;
    }
}

//standard copy constuctor
Fraction::Fraction(const Fraction&x)
{ 
    p = x.p;
    q = x.q;
}

//standard assignment operator 
Fraction& Fraction::operator=(const Fraction&x)
{
    if(&x != this)
    {
        p = x.p;
        q = x.q;
    }
    return *this;
}

//unary - operator
Fraction Fraction::operator-()
{
    Fraction t(-p,q);
    return t;
}

//unary + operator
Fraction Fraction::operator+()
{
    Fraction t(p, q);
    return t;
}

//pre increment operator
//fraction after increment is returned 
Fraction Fraction::operator++()
{
    p  = p + q;
    normalize();
    Fraction t = *this;
    return t;
}

//post increment operator
//fraction before increment is returned 
Fraction Fraction::operator++(int)
{
    Fraction t = *this;
    p  = p + q;
    normalize();
    return t;
}

//pre decrement operator
//fraction after decrement is returned 
Fraction Fraction::operator--()
{
    p  = p - q;
    normalize();
    Fraction t = *this;
    return t;
}

//post decrement operator
//fraction before decrement is returned 
Fraction Fraction::operator--(int)
{
    Fraction t = *this;
    p  = p - q;
    //norm called for p == 0 sanity check
    normalize();
    return t;
}

//binary addition operator
Fraction operator+(const Fraction&x, const Fraction&y)
{
    Fraction t;
    int lcm1 = lcm(x.q, y.q);
    t.p = (lcm1/x.q)*x.p + (lcm1/y.q)*y.p;
    t.q = lcm1;
    t.normalize();
    return t;
}

//binary subtraction operator
Fraction operator-(const Fraction&x,const Fraction&y)
{
    Fraction t;
    int lcm1 = lcm(x.q, y.q);
    t.p = (lcm1/x.q)*x.p - (lcm1/y.q)*y.p;
    t.q = lcm1;
    t.normalize();
    return t;
}

//binary multiplication operator
Fraction operator*(const Fraction&x,const Fraction&y)
{
    Fraction t;
    t.p = x.p*y.p;
    t.q = x.q*y.q;
    t.normalize();
    return t;
}

//binary division operator
Fraction operator/(const Fraction&x,const Fraction&y)
{
    Fraction t;
    t.p = x.p*y.q;
    t.q = x.q*y.p;
    if(t.q == 0)
    {
        cout<<"Cannot divide by 0"<<endl;
        exit(1);
    }
    t.normalize();
    return t;
}

//remainder operator
Fraction operator%(const Fraction&x,const Fraction&y)
{
    Fraction t;
    int quotient = x.p*y.q/(x.q*y.p);
    Fraction q(quotient);
    t = x - q*y;
    t.normalize();
    return t;
}

//boolean equals operator
bool Fraction::operator==(const Fraction&x)
{
    if(p == x.p && q == x.q )
        return true;
    return false;
}

//boolean not-equals operator
bool Fraction::operator!=(const Fraction&x)
{
    if(p != x.p || q != x.q )
        return true;
    return false;
}

//boolean less than
bool Fraction::operator<(const Fraction&x)
{
    if(p*x.q < q*x.p)
        return true;
    return false;
}

//boolean less than or equals to
bool Fraction::operator<=(const Fraction&x){
    if(p*x.q <= q*x.p)
        return true;
    return false;
}

//boolean greater than
bool Fraction::operator>(const Fraction&x){
    if(p*x.q > q*x.p)
        return true;
    return false;
}

//boolean greater than or equals to
bool Fraction::operator>=(const Fraction&x){
    if(p*x.q >= q*x.p)
        return true;
    return false;
}

//not operator (returns q/p )
Fraction Fraction::operator!()
{
    Fraction t;
    Fraction ans;
    ans = t/(*this);
    return ans;
}

//ostream operator 
std::ostream& operator<<(std::ostream& os,const Fraction&x)
{
    os << x.p << "/" << x.q;
    return os;
}

//istream operator
std::istream& operator>>(std::istream& is,Fraction&x)
{
    char c;
    is >> x.p >> c >> x.q;
    if(c != '/')
        exit(1);
    x.normalize();
    return is;
}

const Fraction Fraction::sc_fUnity = {1, 1}; //declaration of static constants 
const Fraction Fraction::sc_fZero = {0, 1};  //declaration of static constants 