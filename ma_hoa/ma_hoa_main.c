#include "../thu_vien/RC4.h"
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

    trang_thai_rc4 s;
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
    rc4_ksa(&s, key, key_len);

    // PRGA & Crypt: Mã hóa
    rc4_prga_crypt(&s, plaintext, data_len);


    //In kết quả
    print_hex("Ciphertext (Hex)", plaintext, data_len);

    return 0;
}