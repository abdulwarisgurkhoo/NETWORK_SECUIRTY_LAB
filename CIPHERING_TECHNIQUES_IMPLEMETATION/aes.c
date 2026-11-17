#include <stdio.h>
#include <stdint.h>

// Simplified substitution box (S-box)
static const uint8_t sbox[16] = {
    0x9, 0x4, 0xA, 0xB, 0x1, 0x5, 0x8, 0x2, 
    0x3, 0xD, 0x0, 0xE, 0x7, 0x6, 0xF, 0xC
};

void add_round_key(uint8_t state[4], uint8_t key) {
    for (int i = 0; i < 4; i++) {
        state[i] ^= key;
    }
}

void sub_bytes(uint8_t state[4]) {
    for (int i = 0; i < 4; i++) {
        state[i] = sbox[state[i] & 0x0F];
    }
}

void shift_rows(uint8_t state[4]) {
    uint8_t temp = state[0];
    state[0] = state[1];
    state[1] = state[2];
    state[2] = state[3];
    state[3] = temp;
}

int main() {
    // A simplified 4-byte state vector representing a row/column slice of the AES state matrix
    uint8_t state[4] = {0x1A, 0x2B, 0x3C, 0x4D};
    uint8_t round_key = 0x55;

    printf("--- AES Simplified Step-by-Step ---\n");
    printf("Initial State: %02X %02X %02X %02X\n", state[0], state[1], state[2], state[3]);

    add_round_key(state, round_key);
    printf("After AddRoundKey: %02X %02X %02X %02X\n", state[0], state[1], state[2], state[3]);

    sub_bytes(state);
    printf("After SubBytes:    %02X %02X %02X %02X\n", state[0], state[1], state[2], state[3]);

    shift_rows(state);
    printf("After ShiftRows:   %02X %02X %02X %02X\n", state[0], state[1], state[2], state[3]);

    return 0;
}