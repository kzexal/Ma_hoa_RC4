#include "RC4.h"

// Hàm hoán vị 2 byte
static void swap_bytes(unsigned char *a, unsigned char *b) {
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

// Giai đoạn KSA (Key-Scheduling Algorithm) theo RFC 6229
void rc4_ksa(rc4_state *state, const unsigned char *key, size_t key_len) {
    unsigned char j = 0;

    // Khởi tạo mảng S với giá trị từ 0 đến 255
    for (int i = 0; i < 256; i++) {
        state->S[i] = (unsigned char)i;
    }

    // Xáo trộn mảng S dựa trên khóa
    for (int i = 0; i < 256; i++) {
        j = (j + state->S[i] + key[i % key_len]) & 0xFF;  // Sử dụng & 0xFF thay vì % 256
        swap_bytes(&state->S[i], &state->S[j]);
    }

    // Khởi tạo chỉ số cho PRGA
    state->i = 0;
    state->j = 0;
}

// Giai đoạn PRGA (Pseudo-Random Generation Algorithm) và mã hóa/giải mã theo RFC 6229
void rc4_prga_crypt(rc4_state *state, unsigned char *data, size_t data_len) {
    unsigned char i = state->i;
    unsigned char j = state->j;

    for (size_t n = 0; n < data_len; n++) {
        i = (i + 1) & 0xFF;  // Sử dụng & 0xFF thay vì % 256
        j = (j + state->S[i]) & 0xFF;
        swap_bytes(&state->S[i], &state->S[j]);

        // Tạo byte của keystream
        unsigned char k = state->S[(state->S[i] + state->S[j]) & 0xFF];

        // XOR với dữ liệu để mã hóa/giải mã
        data[n] ^= k;
    }

    // Lưu lại trạng thái i, j (nếu muốn tiếp tục mã hóa trên cùng một stream)
    state->i = i;
    state->j = j;
}
