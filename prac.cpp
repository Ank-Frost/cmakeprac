#include <iostream>
#include "mymath.h"
#include <cryptopp/aes.h>
using namespace std;

int main(){
    cout << "hi there" << endl;
    cout << "2 + 3 = " << add(2,3) << endl;
    cout << "AES default key len: "<< CryptoPP::AES::DEFAULT_KEYLENGTH << endl;
    return 0;
}