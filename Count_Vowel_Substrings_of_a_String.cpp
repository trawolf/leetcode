// A substring is a contiguous (non-empty) sequence of characters within a string.

// A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.

// Given a string word, return the number of vowel substrings in word.

#include<iostream>
#include<string>
// #include<string_view>

using std::string;
using std::cin;
using std::cout;
using std::endl;

bool ifAll(const string word, const string substring){
    auto iter=word.begin();
    while(iter!=word.end()){
        if(substring.find(*iter)==string::npos){
            return false;
        }else{
            // cout<<substring.find(*iter)<<endl;
        }
        iter++;
    }
    return true;
}

int countVowelSubstrings(string word) {
    const string sub("aeiou");
    int begin=0, count=0;
    while(begin+4<word.size()){
        // cout<<word[begin]<<" ";
        if(sub.find(word[begin])==string::npos){
            begin++;
            continue;
        }else{
            int end=begin;
            cout<<"begin:"<<begin<<" ";
            while(end<word.size()&&sub.find(word[end])!=string::npos){
                end++;
            }
            cout<<begin<<"->"<<end<<":";
            string temp=word.substr(begin,end-begin);
            cout<<temp<<endl;
            int leastFirst=begin;
            for(int i=0;i<5;i++){
                if(temp.find(sub[i])==string::npos){
                    leastFirst=end;
                    break;
                }else{
                    leastFirst=(temp.find(sub[i])+begin>leastFirst)?(temp.find(sub[i])+begin):leastFirst;
                }
            }
            cout<<"leastFirst:"<<leastFirst<<" "<<"end:"<<end<<" ";
            // cout<<word.substr(begin,leastFirst-begin)<<endl;
            count+=end-leastFirst;
            cout<<end-leastFirst<<endl;
            begin++;
        }
        
    }
    return count;
}

int main(){
    string a("cuaieuouac");
    cout<<countVowelSubstrings(a)<<endl;
}