#include<iostream>

using namespace std;

void searchPattern( int patternlen, int stringlen, char pattern[], char string[]){

    cout<<patternlen<<endl;
    cout<<stringlen<<endl;

    bool found = false;
    for(int i = 0; i <= stringlen - patternlen; i++){

        int j;
        for(j = 0; j < patternlen; j++){
            if(pattern[j] != string[i + j]){
                break;
            }
        }

        if(j == patternlen){
            found = true;
            cout<<"Pattern found at index "<<i<<endl;
        }
    }

    if(!found)
    cout<<"Pattern not found in the string"<<endl;

    
}

void input(){
    int patternlen;
    cout<<"Enter the length of the pattern you want to input"<<endl;
    cin>>patternlen;
    char pattern[patternlen];
    cout<<"Enter the string"<<endl;
    cin>>pattern;

    int strlen;
    cout<<"Enter the length of the string you want to input"<<endl;
    cin>>strlen;

    if(strlen < patternlen){
        cout<<endl<<"Pattern length should be smaller than string length. Please try again!"<<endl<<endl;
        return;
    }

    char str[strlen];
    cout<<"Enter the string"<<endl;
    cin>>str;

   

    searchPattern(patternlen,strlen,pattern,str);
}

int main(){
    int ch;

    while(ch != 2){
        cout<<"Enter your choice\n1. Search Pattern\n2. Exit "<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            input();
        case 2:
            break;
        default:
            break;
        }
    }
    
    return 0;
}

