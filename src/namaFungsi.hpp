#ifndef __NAMA_FUNGSI_HPP__
#define __NAMA_FUNGSI_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

float calc(float left, float right, char op);
list<string> solve24(list<string> hasil , string opp[], float bil[]);
void saveFile(string filename,float bil[], list<string> hasil);
void tanyaSave(float bil[], list<string> hasil);
vector<float> mintaInput(float bil[], list<string> kartu);
void splashScreen();


#endif