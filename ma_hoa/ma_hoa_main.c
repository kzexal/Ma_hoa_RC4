#include "C:\Users\buidu\OneDrive\Máy tính\code\RC4\thu_vien\RC4.h"  // Đường dẫn tương đối đến file .h
#include <stdio.h>
#include <string.h>

// In ciphertext dưới dạng hex
void print_hex(const char* label, const unsigned char* data, size_t len) {
    printf("%s: ", label);
    for (size_t i = 0; i < len; i++) {
        printf("%02X", data[i]);
    }
    printf("\n");
}

int main() {

    rc4_state state;
    //key
    const unsigned char key[] = "Khanh";

    // Chuỗi plaintext
    unsigned char plaintext[] = "Hanoi University of Science and Technology";

    size_t key_len = strlen((const char*)key);
    size_t data_len = strlen((const char*)plaintext);

    printf("--- PROJECT ENCRYPT ---\n");
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);



    // KSA: Chuẩn bị mảng S
    rc4_ksa(&state, key, key_len);

    // PRGA & Crypt: Mã hóa
    rc4_prga_crypt(&state, plaintext, data_len);


    //In kết quả
    print_hex("Ciphertext (Hex)", plaintext, data_len);

    return 0;
}