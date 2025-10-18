#include "C:\Users\buidu\OneDrive\Máy tính\code\RC4\thu_vien\RC4.h"  // Đường dẫn tương đối đến file .h
#include <stdio.h>
#include <string.h>

// Hàm tiện ích để in dữ liệu (bản mã) dưới dạng hex
void print_hex(const char* label, const unsigned char* data, size_t len) {
    printf("%s: ", label);
    for (size_t i = 0; i < len; i++) {
        printf("%02X", data[i]); // %02X: In 2 ký tự HEX, có đệm số 0
    }
    printf("\n");
}

int main() {
    // 1. Khai báo
    rc4_state state;
    
    // BẠN PHẢI TỰ CHỌN KHÓA NÀY
    const unsigned char key[] = "Khanh"; 
    
    // Chuỗi plaintext cần mã hóa
    unsigned char plaintext[] = "Hanoi University of Science and Technology";
    
    size_t key_len = strlen((const char*)key);
    size_t data_len = strlen((const char*)plaintext);

    printf("--- PROJECT ENCRYPT ---\n");
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);

    // 2. Gọi hàm từ thư viện
    
    // KSA: Chuẩn bị mảng S
    rc4_ksa(&state, key, key_len);
    
    // PRGA & Crypt: Mã hóa
    rc4_prga_crypt(&state, plaintext, data_len);

    // 3. In kết quả
    // 'plaintext' bây giờ đã bị ghi đè thành ciphertext
    print_hex("Ciphertext (Hex)", plaintext, data_len);

    return 0;
}