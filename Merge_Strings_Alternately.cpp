// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
// If a string is longer than the other, append the additional letters onto the end of the merged string.

// Return the merged string.

#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

string mergeAlternately(string word1, string word2) {
    string mergedString=word1;
    int add=1;
    auto iter1=word2.begin(), iter2=mergedString.begin()+add;
    while(iter1!=word2.end()){
        cout<<*iter1<<endl;
        if(iter2!=mergedString.end()){
            mergedString.insert(iter2,*iter1);
        }else{
            mergedString.append(iter1,word2.end());
            break;
        }
        cout<<mergedString<<endl;
        iter1++;
        add+=2;
        iter2=mergedString.begin()+add;
    }
    // cout<<mergedString<<endl;
    return mergedString;
}

int main(){
    string word1("dajmknzgidixqgt"), word2("nahamebx");
    cout<<mergeAlternately(word1, word2)<<endl;
    return 0;
}