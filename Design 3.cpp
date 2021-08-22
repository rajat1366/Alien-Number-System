// SIMPLICITY ( Adding 1 to the number directly instead of convert it to base 10 adding 1 and back to base b).

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int addTwoNumberInGivenBase(int number1 ,int number2, int base){
    int carry = 0;
    int ans = 0;
    int multiplier = 1;
    while(number1 >0 || number2 > 0 || carry >0){
        int currDigitSum = 0;
        if(number1 > 0){
            currDigitSum += (number1 % 10);
            number1 /= 10;
        }
        if(number2 > 0){
            currDigitSum += (number2 % 10);
            number2 /= 10;
        }
        if(carry > 0) {
            currDigitSum += carry;
        }
        carry = currDigitSum / base;
        int currVal = currDigitSum % base;
        ans = multiplier * currVal + ans;
        multiplier *= 10;
    }
    return ans;
}

// function to convert interger number to alien format
string convertNumberToAlienFormat(int number, string Base){
    string AlienFormat;
    while(number>0){
        int digit = number%10;
        AlienFormat.insert(AlienFormat.begin(), Base[digit]);
        number = number/10;
    }
    return AlienFormat;
}
int convertNumberFromAlienFormatToInteger(string num , string Base){
    map<char,int> table;
    
    // storing the maping of number to symbol from the base string
    for(int i = 0 ; i < Base.length() ;i++){
        table[Base[i]] = i;
    }
    //converting string input in AlienFormat to interger value.
    int NumBaseb = 0 ; 
    for(int i=0 ; i<num.length();i++){
        NumBaseb = NumBaseb * 10 + table[num[i]];
    }
    return NumBaseb;
}

void succ_alien(string num, string Base){
    int baseValue = Base.length();
   
    //converting string input in AlienFormat to interger value.
    int NumBaseb = convertNumberFromAlienFormatToInteger(num,Base) ; 
    
    cout << num <<" -> "<<NumBaseb <<" -> ";
    
    int NextNumBaseB = addTwoNumberInGivenBase( NumBaseb , 1 , baseValue);
   
    cout << NextNumBaseB <<" "; 
    // converting this number in base b back to alien format
    string AnsAlienFormat = convertNumberToAlienFormat(NextNumBaseB , Base);
   
    // adding additional zero in the front if present in input.
    while(AnsAlienFormat.length() < num.length()){
        AnsAlienFormat.insert(AnsAlienFormat.begin(),Base[0]);
    }
    cout<<AnsAlienFormat;
    
}
int main() {
	succ_alien("!@^&*","!@^&*");
	return 0;
}



