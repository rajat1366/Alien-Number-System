// ADDING MODULARITY BASED ON THE TYPE OF OPERATION TO BE PERFORMED

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int convertNumberBaseBToBase10(int numberBaseB , int baseValue){
    int NumBase10=0;
    int multiplier = 1;
    int temp = numberBaseB;
    while(temp){
        int lastDigit = temp%10;
        NumBase10 = multiplier*lastDigit + NumBase10;
        multiplier = multiplier * baseValue;
        temp = temp/10;
    }
    return NumBase10;
}

int convertNumberBase10ToBaseB(int NumBase10 , int baseValue){
    int NumBaseB = 0;
    int multiplier = 1 ;
    // converting base 10 number back to base b
    while(NumBase10 > 0){
        int digit = NumBase10% baseValue;
        NumBaseB = multiplier * digit + NumBaseB;
        multiplier = multiplier * 10;
        NumBase10 = NumBase10/baseValue;
    }
    return NumBaseB;
}
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
    
    //converting number from base B to base 10
    int NumBase10= convertNumberBaseBToBase10(NumBaseb,baseValue);
    
    // incrementing by 1 
    NumBase10++;
    
    // converting number from base 10 to base B;
    int newNumBaseb = convertNumberBase10ToBaseB(NumBase10,baseValue);
    cout << newNumBaseb <<" -> ";
    
    // converting this number in base b back to alien format
    string AnsAlienFormat = convertNumberToAlienFormat(newNumBaseb , Base);
   
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



