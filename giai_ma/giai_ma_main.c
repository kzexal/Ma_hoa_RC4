#include "C:\Users\buidu\OneDrive\Máy tính\code\RC4\thu_vien\RC4.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

unsigned char hex_char_to_byte(const char *hex_pair) {
    char byte_str[3] = { hex_pair[0], hex_pair[1], '\0' };
    return (unsigned char)strtol(byte_str, NULL, 16); 
}

size_t hex_string_to_bytes(const char *hex_string, unsigned char *byte_array) {
    size_t string_len = strlen(hex_string);

    if (string_len % 2 != 0) {
        printf("Loi: Chuoi hex khong hop le (so ky tu bi le).\n");
        return 0;
    }

    size_t byte_len = 0;
    for (size_t i = 0; i < string_len; i += 2) {
        byte_array[byte_len] = hex_char_to_byte(&hex_string[i]);
        byte_len++;
    }

    return byte_len;
}


int main() {
    rc4_state state;

    // Key
    const unsigned char key[] = "Khanh";

    // Ciphertext (Hex)
    const char *hex_ciphertext = "477A457EC2DA2E943EC2D8D32E2EAE3C4DEFDF375C64DD55E74AF78F82FF17C38452CBA7B2CA1B878374";

    size_t key_len = strlen((const char*)key);

    // Tự động tính kích thước
    size_t hex_len = strlen(hex_ciphertext);
    size_t data_len = hex_len / 2;

    // Cấp phát bộ nhớ động bằng malloc
    unsigned char *byte_ciphertext = (unsigned char*)malloc(data_len + 1);

    // Kiểm tra xem malloc có thành công không
    if (byte_ciphertext == NULL) {
        printf("Loi! Khong the cap phat bo nho.\n");
        return 1;
    }

    printf("--- PROJECT DECRYPT ---\n");
    printf("Ciphertext (Hex): %s\n", hex_ciphertext);
    printf("Key: %s\n", key);

    // Chuyển đổi chuỗi hex sang byte array
    size_t converted_len = hex_string_to_bytes(hex_ciphertext, byte_ciphertext);
    if (converted_len == 0) {
        free(byte_ciphertext);
        return 1;
    }

    rc4_ksa(&state, key, key_len);
    rc4_prga_crypt(&state, byte_ciphertext, data_len);

    // In kết quả
    byte_ciphertext[data_len] = '\0';
    printf("Decrypted Plaintext: %s\n", byte_ciphertext);

    free(byte_ciphertext);

    return 0;
}
