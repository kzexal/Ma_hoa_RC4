#include "RC4.h"

// Hàm hoán vị 2 phần tử
static void swap_bytes(unsigned char *a, unsigned char *b) {
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

// Giai đoạn KSA
void rc4_ksa(rc4_state *state, const unsigned char *key, size_t key_len) {
    int j = 0;
    
    // Khởi tạo mảng S
    for (int i = 0; i < 256; i++) {
        state->S[i] = i;
    }
    
    // Xáo trộn mảng S dựa trên key
    for (int i = 0; i < 256; i++) {
        j = (j + state->S[i] + key[i % key_len]) % 256;
        swap_bytes(&state->S[i], &state->S[j]);
    }
    
    // Đặt lại i, j cho PRGA
    state->i = 0;
    state->j = 0;
}

// Giai đoạn PRGA và XOR
void rc4_prga_crypt(rc4_state *state, unsigned char *data, size_t data_len) {
    unsigned char i = state->i;
    unsigned char j = state->j;
    
    for (size_t n = 0; n < data_len; n++) {
        i = (i + 1) % 256;
        j = (j + j + state->S[i]) % 256;
        
        swap_bytes(&state->S[i], &state->S[j]);
        
        unsigned char k = state->S[(state->S[i] + state->S[j]) % 256];
        
        // Thực hiện XOR để mã hóa hoặc giải mã
        data[n] = data[n] ^ k;
    }
    
    // Lưu lại trạng thái i, j (nếu muốn mã hóa tiếp)
    state->i = i;
    state->j = j;
}