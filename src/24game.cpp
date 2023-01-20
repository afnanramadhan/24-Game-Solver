#include <iostream>
#include <string>
#include <algorithm>
#include <list>


using namespace std;


float calc(float left, float right, char op){
    if (op == '+') return left + right;
    if (op == '-') return left - right;
    if (op == '*') return left * right;
    if (op == '/'){
        if (right == 0){
            return -99999999;
        }
        // else if(right>left){
        //     return -99999999;
        // }1135
        else{
            return left / right;
        }
    } 
        
}

int main(){
    // progam untuk menyelesaikan permainan 24
    // 4 angka dan 3 operator
    // 4 angka = 1 2 3 4
    // 3 operator = + - *
    float bil[4] = {7,3,5,2};    
    string opp[64] = {"+++","++-","++*","++/","+-+","+--","+-*","+-/","+*+","+*-","+**","+*/","+/+","+/-","+/*","+//","-++","-+-","-+*","-+/","--+","---","--*","--/","-*+","-*-","-**","-*/","-/+","-/-","-/*","-//","*++","*+-","*+*","*+/","*-+","*--","*-*","*-/","**+","**-","***","**/","*/+","*/-","*/*","*//","/++","/+-","/+*","/+/","/-+","/--","/-*","/-/","/*+","/*-","/**","/*/","//+","//-","//*","///"};

    list<string> hasil;

    int count = 1;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                for(int l=0; l<4; l++){
                    for(int m=0; m<64; m++){
                        if (i!=j && i!=k && i!=l && j!=k && j!=l && k!=l){
                            float ans;
                            // tanpa kurung
                            // ans = calc(calc(calc(bil[i],bil[j],opp[m][0]),bil[k],opp[m][1]),bil[l],opp[m][2]);
                            // if(ans == 24){
                            //     // cout << count << ". ";  
                            //     // cout << bil[i] << opp[m][0] << bil[j] << opp[m][1] << bil[k] << opp[m][2] << bil[l] << " = ";
                            //     // cout << ans << endl;
                            //     string temp = to_string(bil[i]) + (1, opp[m][0]) + to_string(bil[j]) + (1,opp[m][1]) + to_string(bil[k]) + (1,opp[m][2]) + to_string(bil[l]) +"";
                            //     // cout << temp << endl;
                            //     hasil.insert(hasil.end(),temp);
                            //     hasil.sort();
                            //     hasil.unique();
                            //     count++;
                            // }

                            // // ((a+b)+c)+d
                            ans = calc(calc(calc(bil[i],bil[j],opp[m][0]),bil[k],opp[m][1]),bil[l],opp[m][2]);
                            if(ans == 24){
                                // cout << ans << endl;
                                // cout << count << ". ";  
                                // cout << "((" << bil[i] << opp[m][0] << bil[j] << ")" << opp[m][1] << bil[k] << ")" << opp[m][2] << bil[l] << " = ";
                                // cout << ans << endl;
                                string temp = "((" + to_string((int)bil[i]) + (1,opp[m][0]) + to_string((int)bil[j]) + ")" + (1,opp[m][1]) + to_string((int)bil[k]) + ")" + (1,opp[m][2]) + to_string((int)bil[l]) + "";
                                hasil.insert(hasil.end(),temp);
                                hasil.sort();
                                hasil.unique();
                                count++;
                            }
                            
                            // //(a+(b+c))+d
                            ans = calc(calc(bil[i],calc(bil[j],bil[k],opp[m][1]),opp[m][0]),bil[l],opp[m][2]);
                            if(ans == 24){
                                // cout << ans << endl;
                                // cout << count << ". ";  
                                // cout << "(" << bil[i] << opp[m][0] << "(" << bil[j] << "))"  << opp[m][1] << bil[k] << opp[m][2] << bil[l] << " = ";
                                // cout << ans << endl;
                                string temp = "(" + to_string((int)bil[i]) + (1,opp[m][0]) + "(" + to_string((int)bil[j]) + (1,opp[m][1]) + to_string((int)bil[k]) + "))" + (1,opp[m][2]) + to_string((int)bil[l]) + "";
                                count++;
                                hasil.insert(hasil.end(),temp);
                                hasil.sort();
                                hasil.unique();
                            }

                            // // a+((b+c)+d)
                            ans = calc(bil[i],calc(calc(bil[j],bil[k],opp[m][1]),bil[l],opp[m][2]),opp[m][0]);
                            if(ans == 24){
                                // cout << ans << endl;
                                // cout << count << ". ";  
                                // cout << bil[i] << opp[m][0] << "((" << bil[j] << opp[m][1] << bil[k] << ")" << opp[m][2] << bil[l] << ") = ";
                                // cout << ans << endl;
                                string temp = to_string((int)bil[i]) + (1,opp[m][0]) + "((" + to_string((int)bil[j]) + (1,opp[m][1]) + to_string((int)bil[k]) + ')' + (1,opp[m][2]) + to_string((int)bil[l]) + ")";
                                count++;
                                hasil.insert(hasil.end(),temp);
                                hasil.sort();
                                hasil.unique();
                            }

                            // //a+(b+(c+d))
                            ans = calc(bil[i],calc(bil[j],calc(bil[k],bil[l],opp[m][2]),opp[m][1]),opp[m][0]);
                            if(ans == 24){
                                // cout << count << ". ";  
                                // cout << bil[i] << opp[m][0] << "(" << bil[j] << opp[m][1] << "(" << bil[k] << opp[m][2] << bil[l] << ")) = ";
                                // cout << ans << endl;
                                string temp = to_string((int)bil[i]) + (1,opp[m][0]) + "(" + to_string((int)bil[j]) + (1,opp[m][1]) + "(" + to_string((int)bil[k]) + (1,opp[m][2]) + to_string((int)bil[l]) + "))";
                                count++;
                                hasil.insert(hasil.end(),temp);
                                hasil.sort();
                                hasil.unique();
                            }

                            // (a+b)+(c+d)
                            ans = calc(calc(bil[i],bil[j],opp[m][0]),calc(bil[k],bil[l],opp[m][2]),opp[m][1]);
                            if(ans == 24){
                                // cout << ans << endl;    
                                // cout << count << ". ";  
                                // cout << bil[i] << opp[m][0] << "(" << bil[j] << opp[m][1] << "(" << bil[k] << opp[m][2] << bil[l] << ")) = ";
                                // cout << ans << endl;
                                string temp = "(" + to_string((int)bil[i]) + (1,opp[m][0]) + to_string((int)bil[j])+ ")" + (1,opp[m][1]) + "(" + to_string((int)bil[k]) + (1,opp[m][2]) + to_string((int)bil[l]) + ")";
                                count++;
                                hasil.insert(hasil.end(),temp);
                                hasil.sort();
                                hasil.unique();
                            }
                        }
                    }
                }
            }
        }
    }

    for (list<string>::iterator i = hasil.begin();i != hasil.end();i++){
        cout << *i << endl;
    }

    cout << hasil.size() << endl;

}