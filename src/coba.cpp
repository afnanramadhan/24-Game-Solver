#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int main(){
    string opp[64] = {"+++","++-","++*","++/","+-+","+--","+-*","+-/","+*+","+*-","+**","+*/","+/+","+/-","+/*","+//","-++","-+-","-+*","-+/","--+","---","--*","--/","-*+","-*-","-**","-*/","-/+","-/-","-/*","-//","*++","*+-","*+*","*+/","*-+","*--","*-*","*-/","**+","**-","***","**/","*/+","*/-","*/*","*//","/++","/+-","/+*","/+/","/-+","/--","/-*","/-/","/*+","/*-","/**","/*/","//+","//-","//*","///"};

    list<string> hasil;

    // for(int i=0; i<5; i++){
    //     string a = opp[i];
    //     hasil.insert(hasil.end(),a);
    // }

    // for (list<string>::iterator i = hasil.begin();i != hasil.end();i++){
    //     cout << *i << " ";
    // }


    for(int j=0; j<64; j++){ // iterasi buat 4 operator
        cout << j+1 << ". ";
        for(int k=0; k<3; k++){ // iterasi isi operator
            cout << opp[j][k] << " ";
        }
        cout << endl;
    }

}

