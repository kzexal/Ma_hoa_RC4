#include "C:\Users\buidu\OneDrive\Máy tính\code\RC4\thu_vien\RC4.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Cần thư viện này cho malloc, free, strtol

/* ==================================================================== */
/* === BẮT ĐẦU: Các hàm tiện ích để chuyển đổi HEX STRING === */

/**
 * @brief Chuyển 1 cặp ký tự hex (ví dụ "4A") thành 1 byte (giá trị 0x4A)
 */
unsigned char hex_char_to_byte(const char *hex_pair) {
    char byte_str[3] = { hex_pair[0], hex_pair[1], '\0' };
    return (unsigned char)strtol(byte_str, NULL, 16); 
}

/**
 * @brief Chuyển 1 chuỗi hex dài thành một mảng các byte
 * @param hex_string Chuỗi hex đầu vào (ví dụ: "4736F7...")
 * @param byte_array Mảng byte đầu ra (nơi chứa kết quả)
 * @return Số lượng byte đã được chuyển đổi
 */
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

/* === KẾT THÚC: Các hàm tiện ích === */
/* ==================================================================== */


int main() {
    // 1. Khai báo
    rc4_state state;
    
    // KHÓA PHẢI GIỐNG HỆT BÊN MÃ HÓA
    const unsigned char key[] = "Khanh";

    // =================================================================
    // >>> CHỈ CẦN DÁN CHUỖI HEX CỦA BẠN VÀO ĐÂY <<<
    const char *hex_ciphertext = "4736F7B15413DE84887E44B3689DC35DB0552B0136FFBA884C19242164FDACD2E92C1B6D963F42D723F0";
    // =================================================================
    
    size_t key_len = strlen((const char*)key);
    
    // Tự động tính kích thước
    size_t hex_len = strlen(hex_ciphertext);
    size_t data_len = hex_len / 2;
    
    // *** SỬA LỖI Ở ĐÂY ***
    // Cấp phát bộ nhớ động bằng malloc
    unsigned char *byte_ciphertext = (unsigned char*)malloc(data_len + 1);

    // Kiểm tra xem malloc có thành công không
    if (byte_ciphertext == NULL) {
        printf("Loi! Khong the cap phat bo nho.\n");
        return 1; // Thoát vì lỗi
    }

    printf("--- PROJECT DECRYPT ---\n");
    printf("Ciphertext (Hex): %s\n", hex_ciphertext);
    printf("Key: %s\n", key);

    // 2. Gọi hàm tiện ích để chuyển đổi chuỗi
    size_t converted_len = hex_string_to_bytes(hex_ciphertext, byte_ciphertext);
    if (converted_len == 0) {
        free(byte_ciphertext); // Giải phóng bộ nhớ trước khi thoát
        return 1; 
    }

    // 3. Gọi hàm từ thư viện
    rc4_ksa(&state, key, key_len);
    rc4_prga_crypt(&state, byte_ciphertext, data_len);

    // 4. In kết quả
    byte_ciphertext[data_len] = '\0'; 
    printf("Decrypted Plaintext: %s\n", byte_ciphertext);

    // *** SỬA LỖI Ở ĐÂY ***
    // Luôn giải phóng bộ nhớ đã cấp phát bằng malloc
    free(byte_ciphertext); 

    return 0;
}
