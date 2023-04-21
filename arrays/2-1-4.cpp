#include<iostream>
using namespace std;

class Complex{
public:
    Complex(){real=0,img=0;};
    Complex(double a,double b){real=a,img=b;};
    friend ostream& operator <<(ostream& os,const Complex& c1);
    friend istream& operator >>(istream& is ,Complex& c1);  
    friend Complex operator +(const Complex& c1,const Complex& c2);
    friend Complex operator *(const Complex& c1,const Complex& c2);           
private:
    double real,img;
};

int main(void){

    Complex a(3,2),b,c,d;
    cin>>c>>d;
    cout<<"sum of four Complex : "<<a+b+c+d<<endl;
    cout<<"product of four Complex : "<<a*b*c*d<<endl;

}

ostream& operator <<(ostream& os,const Complex& c1){
    if(c1.img>=0){
        return os<<c1.real<<"+"<<c1.img<<"i";
    }
    else return os<<c1.real<<"-"<<c1.img<<"i";
    
}

istream& operator >>(istream& is ,Complex& c1){
    return is>>c1.real>>c1.img;
}

Complex operator +(const Complex& c1,const Complex& c2){
    Complex result(c1.real+c2.real,c1.img+c2.img);
    return result;
}

Complex operator *(const Complex& c1,const Complex& c2){
    double tmpreal=(c1.real*c2.real)+(c1.img*c2.img)*-1,
    tmpimg=(c1.real*c2.img)+(c2.real*c1.img);
    Complex result(tmpreal,tmpimg);
    return result;
}   