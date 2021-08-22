#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void succ_alien(string num, string Base){
    int baseValue = Base.length();
    map<char,int> table;
    
    // storing the maping of number to symbol from the base string
    for(int i = 0 ; i < baseValue ;i++){
        table[Base[i]] = i;
    }
    
    //converting num symbols to numerical digits
    string numNumerical;
    int NumBaseb = 0 ; 
    for(int i=0 ; i<num.length();i++){
        numNumerical += table[num[i]]+'0';
        NumBaseb = NumBaseb * 10 + table[num[i]];
    }
    
    cout << numNumerical <<" "<<NumBaseb;
    
    //converting num1 from base b to base 10
    int NumBase10=0;
    int multiplier = 1;
    int temp = NumBaseb;
    while(temp){
        int lastDigit = temp%10;
        NumBase10 = multiplier*lastDigit + NumBase10;
        multiplier = multiplier * baseValue;
        
        temp = temp/10;
    }
    cout<<" "<< NumBase10;
    
    // incrementing by 1 
    NumBase10++;
    
    int newNumBaseb = 0;
    temp = NumBase10;
    multiplier = 1 ;
    // converting base 10 number back to base b
    
    while(temp > 0){
        int digit = temp% baseValue;
        newNumBaseb = multiplier * digit + newNumBaseb;
        multiplier = multiplier * 10;
        temp = temp/baseValue;
    }
    cout<< " " << newNumBaseb;
    
    // converting this number in base b back to alien format
    
    temp = newNumBaseb;
    string AnsAlienFormat;
    
    while(temp>0){
        int digit = temp%10;
        AnsAlienFormat.insert(AnsAlienFormat.begin(), Base[digit]);
        temp = temp/10;
    }
    // adding additional zero in the front if present in input.
    while(AnsAlienFormat.length() < num.length()){
        AnsAlienFormat.insert(AnsAlienFormat.begin(),Base[0]);
    }
    cout<<" "<<AnsAlienFormat;
    
}
int main() {
	succ_alien("!@^&*","!@^&*");
	return 0;
}

