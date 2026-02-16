#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class AES {
private:
    unsigned char* text[16];

public:


};

int main(){
    string plaintext = "0123456789abcdeffedcba9876543210";
    string master_key = "0f1571c947d9e8590cb7add6af7f6798";
    
    unsigned char hex_plaintxt[16];
    unsigned char hex_master_key[16];

    for(int i = 0; i < 32; i += 2){
        string byteString = plaintext.substr(i, 2);
        string byteKey = master_key.substr(i, 2);

        hex_plaintxt[i / 2] = (unsigned char)stoul(byteString, nullptr, 16);
        hex_master_key[i / 2] = (unsigned char)stoul(byteKey, nullptr, 16);

    }

    return 0;
}