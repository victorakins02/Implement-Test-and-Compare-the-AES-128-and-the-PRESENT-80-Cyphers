#include <iostream>
#include <cstdint>

using namespace std;

class PRESENT {
private:
    uint64_t state;
    uint64_t start_key;
    uint16_t end_key; 
    static const uint16_t s_box[16];

public:
    PRESENT(uint64_t plaintext, uint64_t startkey, uint16_t endkey) 
        : state(plaintext), start_key(startkey), end_key(endkey) {};
    
    void updateKey(int roundCounter) {
        uint64_t oldHigh = start_key; // Store the old high part of the key
        uint16_t oldLow = end_key; // Store the old low part of the key

        // Rotate bits
        start_key = (oldHigh << 61) | ((uint64_t)oldLow << 45) | (oldHigh >> 19);
        end_key = (uint16_t)((oldHigh >> 3) & 0xFFFF);

        // Substitute the top 4 bits of the high part of the key using the S-Box
        uint8_t top4 = start_key >> 60;
        start_key = (start_key & 0x0FFFFFFFFFFFFFFF) | ((uint64_t)s_box[top4] << 60);

        // XOR the round counter with the key
        start_key ^= ((uint64_t)roundCounter >> 1);
        end_key ^= ((uint16_t)(roundCounter & 0x01) << 15);
    }

    void sBoxLayer() {
        uint64_t newState = 0;
        for (int i = 0; i < 16; i++) {
            // Extract the 4 bits (nibble)
            uint8_t top4 = (state >> (i * 4)) & 0xF;
            // Swap them and shift back to the correct position
            newState |= ((uint64_t)s_box[top4] << (i * 4));
            }
        state = newState;
    }
    
};

const uint16_t PRESENT::s_box[16] = {0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2};

int main() {
    cout << "Hello! The PRESENT class is now ready." << endl;
    return 0;
}