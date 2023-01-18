#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

int main(){
    string input[4];
    int bil[4];
    list<string> kartu = {"a","A","2","3","4","5","6","7","8","9","10","j","J","Q","q","k","K"};
    

    for (int i = 0; i < 4; i++){
        do{
            cin >> input[i];
        }while(find(kartu.begin(), kartu.end(), input[i]) == kartu.end());
    }

    for (int i = 0; i < 4; i++){
        if(input[i] == "10"){
            bil[i] = 10;
        }else if(input[i] == "k" || input[i] == "K"){
            bil[i] = 13;
        }else if(input[i] == "q" || input[i] == "Q"){
            bil[i] = 12;
        }else if(input[i] == "j" || input[i] == "J"){
            bil[i] = 11;
        }else if(input[i] == "a" || input[i] == "A"){
            bil[i] = 1;
        }else if(input[i] == "2"){
            bil[i] = 2;
        }else if(input[i] == "3"){
            bil[i] = 3;
        }else if(input[i] == "4"){
            bil[i] = 4;
        }else if(input[i] == "5"){
            bil[i] = 5;
        }else if(input[i] == "6"){
            bil[i] = 6;
        }else if(input[i] == "7"){
            bil[i] = 7;
        }else if(input[i] == "8"){
            bil[i] = 8;
        }else if(input[i] == "9"){
            bil[i] = 9;           
        }
    }

    cout << "----------------------"<< endl;
    for (int i = 0; i < 4; i++){
        cout << bil[i] << endl;
    }



    
}