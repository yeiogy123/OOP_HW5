//
// Created by User on 2021/5/18.
//

#include "Mixed.h"
Mixed::Mixed(int a){
    this->integer = a;
}
Mixed::Mixed(int a, int b, int c){
    if(a >= 0){
        if(b >= 0){
            if(b > 0 && c > 0){
                this->integer = a;
                this->numerator = b;
                this->denominator = c;
            }else{
                this->integer = 0;
                this->numerator = 0;
                this->denominator = 0;
            }
        }else if( a == 0 && b < 0){
            if(c > 0) {
                this->integer = a;
                this->numerator = b;
                this->denominator = c;
            }else{
                this->integer = 0;
                this->numerator = 0;
                this->denominator = 0;
            }
        }
    }else{
        if(b > 0 && c > 0 ){
            this->integer = a;
            this->numerator = b;
            this->denominator = c;
        }else{
                this->integer = 0;
                this->numerator = 0;
                this->denominator = 0;
        }
    }
}
double Mixed::Evaluate(){
    if(this->numerator == 0 || this->denominator == 0)
        return this->integer;
    if(this->integer > 0)
        return (this->integer)+(double)(this->numerator / (double)this->denominator);
    else
        return (this->integer)+-1*(double)(this->numerator / (double)this->denominator);

}
int TAD(const int a,const int b){
    if(b == 0)
        return a;
    return TAD(b,a%b);
}
void Mixed::Simplify() {
    ToFraction();
    int GCF = TAD(this->numerator,this->denominator);
    if(GCF != 0) {
        this->numerator /= GCF;
        this->denominator /= GCF;
        //cout<<this->integer<<this->numerator<<this->denominator<<endl;
        if(this->numerator > 0 && this->denominator < 0){
            this->numerator *= -1;
            this->denominator *= -1;
        }
        if(this->numerator / this->denominator != 0)
            this->integer += this->numerator / this->denominator;
        else
            this->integer = 0;
        this->numerator -= (int) (this->numerator / this->denominator) * this->denominator;
        if(this->integer< 0 && this->numerator < 0) {
                this->numerator = -1 * (this->numerator);
        }
        if(this->denominator < 0)
            this->denominator = -1*(this->denominator);

    }
    if(this->numerator == 0)
        this->denominator = 0;
}
void Mixed::ToFraction(){
    if(this->denominator == 0){
        if(this->integer != 0)
            this->denominator = 1;
    }
    int number = this->integer * this->denominator;
    if(this->integer < 0)
        this->numerator *= -1;
    else
        this->numerator *= 1;

    this->numerator += number;
    this->integer = 0;

}
bool Mixed::operator<(const Mixed &MIXED){
    Mixed mixedA = MIXED, mixedB(this->integer,this->numerator,this->denominator);
    mixedA.Simplify();
    mixedB.Simplify();
    double num1, num2;
    num1 = mixedB.Evaluate();
    num2 = mixedA.Evaluate();
    return num1 < num2;
}
bool Mixed::operator>(const Mixed &MIXED){
    Mixed mixedA = MIXED, mixedB(this->integer,this->numerator,this->denominator);
    mixedA.Simplify();
    mixedB.Simplify();
    double num1, num2;
    num1 = mixedB.Evaluate();
    num2 = mixedA.Evaluate();
    return num1 > num2;
}
bool Mixed::operator<=(const Mixed &MIXED){
    Mixed mixedA = MIXED, mixedB(this->integer,this->numerator,this->denominator);
    mixedA.Simplify();
    mixedB.Simplify();
    double num1, num2;
    num1 = mixedB.Evaluate();
    num2 = mixedA.Evaluate();
    return num1 <= num2;
}
bool Mixed::operator>=(const Mixed &MIXED){
    Mixed mixedA = MIXED, mixedB(this->integer,this->numerator,this->denominator);
    mixedA.Simplify();
    mixedB.Simplify();
    double num1, num2;
    num1 = mixedB.Evaluate();
    num2 = mixedA.Evaluate();
    return num1 >= num2;
}
bool Mixed::operator==(const Mixed &MIXED) {
    Mixed mixedA = MIXED, mixedB(this->integer,this->numerator,this->denominator);
    mixedA.Simplify();
    mixedB.Simplify();
    double num1, num2;
    num1 = mixedB.Evaluate();
    num2 = mixedA.Evaluate();
    return num1 == num2;
}
bool Mixed::operator!=(const Mixed &MIXED){
    Mixed mixedA = MIXED, mixedB(this->integer,this->numerator,this->denominator);
    mixedA.Simplify();
    mixedB.Simplify();
    double num1, num2;
    num1 = mixedB.Evaluate();
    num2 = mixedA.Evaluate();
    return num1 != num2;
}
Mixed Mixed::operator+(const Mixed &MIXED){
    Mixed mixed = MIXED;
    mixed.ToFraction();
    int inte,nume,deno;
    this->ToFraction();
    inte = 0;
    nume = this->numerator * mixed.denominator + mixed.numerator * this->denominator;
    deno = this->denominator * mixed.denominator;
    Mixed output(inte,nume,deno);
    output.Simplify();
    return output;
}
Mixed Mixed::operator-(const Mixed &MIXED){
    Mixed mixed = MIXED;
    mixed.ToFraction();
    int inte,nume,deno;
    this->ToFraction();
    inte = 0;
    nume = this->numerator * mixed.denominator - mixed.numerator * this->denominator;
    deno = this->denominator * mixed.denominator;
    //cout<<inte<<nume<<deno<<endl;
    Mixed output(inte,nume,deno);
    output.Simplify();
    return output;
}
Mixed Mixed::operator*(const Mixed &MIXED){
    Mixed mixed = MIXED;
    mixed.ToFraction();
    this->ToFraction();
    int inte,nume,deno;
    inte = 0;
    nume = this->numerator * mixed.numerator;
    deno = this->denominator * mixed.denominator;
    Mixed output(inte,nume,deno);
    output.Simplify();
    return output;
}
Mixed Mixed::operator/(const Mixed &MIXED){
    Mixed mixed = MIXED;
    mixed.ToFraction();
    this->ToFraction();
    int inte,nume,deno;
    inte = 0;
    nume = this->numerator *mixed.denominator;
    deno = this->denominator * mixed.numerator;
    Mixed output(inte,nume,deno);
    output.Simplify();
    return output;
}
Mixed & Mixed::operator++(){
    this->integer+1;
    this->Simplify();
    return *this;
}
const Mixed Mixed::operator++(int ){
    int x = this->integer;
    int y = this->numerator;
    int z = this->denominator;
    Mixed MIXED(x,y,z);
    MIXED.Simplify();
    this->integer +=1;
    this->Simplify();
    return MIXED;
}
Mixed & Mixed::operator--(){
    this->integer -= 1;
    this->Simplify();
    return *this;
}
const Mixed Mixed::operator--(int a){
    int x = this->integer;
    int y = this->numerator;
    int z = this->denominator;
    Mixed MIXED(x,y,z);
    MIXED.Simplify();
    this->integer -= 1;
    this->Simplify();
    return MIXED;
}
istream & operator>>(istream & InputStream, Mixed& MIXED) {
    char c;
    InputStream >> MIXED.integer >> MIXED.numerator >> c >> MIXED.denominator;
    return  InputStream;
}
ostream & operator<<(ostream & OutputStream, const Mixed& MIXED){
    if(MIXED.integer != 0)
        OutputStream << MIXED.integer << " " ;
    if(MIXED.numerator != 0 && MIXED.denominator != 0)
        OutputStream << MIXED.numerator << "/" << MIXED.denominator ;
    if(MIXED.integer==0 && MIXED.numerator==0 && MIXED.denominator == 0)
        OutputStream << 0;
    return OutputStream;
}