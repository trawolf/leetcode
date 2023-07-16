// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

#include<iostream>

int addDigits(int num) {
    // std::cout<<num<<':';
    int add=0;
    while(num){
        add+=num%10;
        num/=10;
    }
    // std::cout<<add<<" and "<<num<<std::endl;
    if(add<10){
        return add;
    }
    else{
        return addDigits(add);
    }
}

int main(){
    // std::cout<<38%10<<' '<<38/10<<std::endl;
    std::cout<<addDigits(38)<<std::endl;
}
