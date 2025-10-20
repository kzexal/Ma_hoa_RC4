#ifndef RC4_H
#define RC4_H

#include <string.h>
#include <stdio.h>

// Cấu trúc để lưu trạng thái của RC4 (mảng S)
typedef struct {
    unsigned char S[256];
    unsigned char i;
    unsigned char j;
} trang_thai_rc4;

void rc4_ksa(trang_thai_rc4 *s, const unsigned char *key, size_t key_len);

void rc4_prga_crypt(trang_thai_rc4 *s, unsigned char *data, size_t data_len);

#endif