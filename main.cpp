
#include "lib.h"
using namespace std;

int main(){
    Road* mas = new Road[V];
    Read_file(mas);
    int res = Way_to("C", "B", mas);
    cout<<res;
    return 0;
}