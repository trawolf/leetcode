// Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, 
// and then at each step perform either of the following:

// Append the character '0' zero times.
// Append the character '1' one times.
// This can be performed any number of times.

// A good string is a string constructed by the above process having a length between low and high (inclusive).

// Return the number of different good strings that can be constructed satisfying these properties. 
// Since the answer can be large, return it modulo 10^9 + 7.

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include<vector>
using std::vector;

// #include<algorithm>
// using std::max;
// using std::min;

struct Mix
{
    int zeros,ones;
    Mix()=default;
    Mix(int zeros, int ones):zeros(zeros),ones(ones){};
};

int arrangement(const int x, const int y){
    int sum=x+y;
    int idx=0,a=1,b=1;
    while(idx<x){
        a*=sum;
        sum--;
        b*=(idx+1);
        ++idx;
    }
    return a/b;
}

int countGoodStrings(int low, int high, int zero, int one) {
    vector<Mix> combinations;
    int out=0;
    for(int zeros=0;zeros*zero<=high;++zeros){
        for(int ones=0;zeros*zero+ones*one<=high;++ones){
            if(zeros*zero+ones*one>=low){
                combinations.push_back(Mix(zeros,ones));
                out+=arrangement(zeros,ones);
            }
        }
    }
    return out;
}

int main(){
    int low=2,high=3,zero=1,one=2;
    // cin>>low>>high>>zero>>one;
    cout<<"the number of different good strings is: "<<countGoodStrings(low,high,zero,one)<<endl;
    return 0;
}