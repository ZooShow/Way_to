#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstring>

using namespace std;

const int V=9;

struct Road{
    string from;
    string to;
    int dist;
};

void Read_file(Road* mas);

int Way_to(string from, string to, Road *mass);