// A complex number can be represented as a string on the form "real+imaginaryi" where:

// real is the real part and is an integer in the range [-100, 100].
// imaginary is the imaginary part and is an integer in the range [-100, 100].
// i2 == -1.
// Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::to_string;

struct Complex{
    int real;
    int imaginary;
    Complex():real(0),imaginary(0){};
    Complex(int r, int i):real(r),imaginary(i){};
    string multiplication(const Complex &num);
};
string Complex::multiplication(const Complex &num){
    int real=this->real*num.real-this->imaginary*num.imaginary;
    int imaginary=this->real*num.imaginary+this->imaginary*num.real;
    return to_string(real)+"+"+to_string(imaginary)+"i";
}

string complexNumberMultiply(string num1, string num2) {
    auto temp1=num1.substr(0,num1.find('+'));
    auto temp2=num1.substr(num1.find('+')+1,num1.find('i'));
    Complex num1_(stoi(temp1),stoi(temp2));

    auto temp3=num2.substr(0,num2.find('+'));
    auto temp4=num2.substr(num2.find('+')+1,num2.find('i'));
    Complex num2_(stoi(temp3),stoi(temp4));

    return num1_.multiplication(num2_);
}

int main(){
    string num1="1+-1i",num2="1+-1i";
    auto out=complexNumberMultiply(num1,num2);
    cout<<out<<endl;
    return 0;
}