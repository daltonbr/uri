/* Operator Overloading
https://www.hackerrank.com/challenges/overload-operators/problem
*/

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
Complex operator+ (Complex c1, Complex c2)
{
    Complex output;
    output.a = c1.a + c2.a;
    output.b = c1.b + c2.b;
    return output;
}

//<< should print a complex number in the format "a+ib"
ostream& operator<<(ostream& out, Complex& c)
{
    out << c.a << "+i" << c.b;
    return out;
}

// supplied stub code
int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
