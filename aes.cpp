#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class AES {
private:
    unsigned char state[16];
    unsigned char roundkeys[176];

    static const unsigned char sbox[256];
    static const unsigned char rcon[11];

public:
    AES(string plaintextHex, string keyHex) {
            for (int i = 0; i < 32; i += 2) {
                state[i / 2] = (unsigned char)stoul(plaintextHex.substr(i, 2), nullptr, 16);
                roundkeys[i / 2] = (unsigned char)stoul(keyHex.substr(i, 2), nullptr, 16);
            }
        }

        void printState() {
            for (int i = 0; i < 16; i++) {
                cout << hex << setfill('0') << setw(2) << (int)state[i] << " ";
                if ((i + 1) % 4 == 0) cout << endl;
            }
        }
    };

int main(){
    string plaintext = "0123456789abcdeffedcba9876543210";
    string master_key = "0f1571c947d9e8590cb7add6af7f6798";
    
    AES example(plaintext, master_key);

    example.printState();

    return 0;
}