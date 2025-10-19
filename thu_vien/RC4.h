#ifndef RC4_H
#define RC4_H

#include <string.h>
#include <stdio.h>

// Cấu trúc để lưu trạng thái của RC4 (mảng S)
typedef struct {
    unsigned char S[256];
    unsigned char i;
    unsigned char j;
} rc4_state;

void rc4_ksa(rc4_state *state, const unsigned char *key, size_t key_len);

void rc4_prga_crypt(rc4_state *state, unsigned char *data, size_t data_len);

#endif