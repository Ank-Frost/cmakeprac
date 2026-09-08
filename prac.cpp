#include <iostream>
#include "mymath.h"
#include <zlib.h>
using namespace std;

int main(){
    cout << "hi there" << endl;
    cout << "2 + 3 = " << add(2,3) << endl;
    cout << "zlib version: " << zlibVersion() << endl; 
    return 0;
}