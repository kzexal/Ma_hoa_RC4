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

/**
 * @brief Khởi tạo trạng thái RC4 (Giai đoạn KSA)
 * @param state Con trỏ tới cấu trúc trạng thái
 * @param key Khóa bí mật
 * @param key_len Độ dài của khóa
 */
void rc4_ksa(rc4_state *state, const unsigned char *key, size_t key_len);

/**
 * @brief Tạo keystream và thực hiện XOR (Giai đoạn PRGA và mã hóa/giải mã)
 * @param state Con trỏ tới cấu trúc trạng thái (đã được KSA)
 * @param data Con trỏ tới dữ liệu (plaintext hoặc ciphertext)
 * @param data_len Độ dài của dữ liệu
 * @note Hàm này sẽ sửa đổi trực tiếp mảng data (in-place)
 */
void rc4_prga_crypt(rc4_state *state, unsigned char *data, size_t data_len);

#endif // RC4_H