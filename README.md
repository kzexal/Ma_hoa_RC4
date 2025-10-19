# RC4 Encryption/Decryption Project
## Mã hóa

1. Mở file `ma_hoa_main.c`
2. Sửa biến `key` và `plaintext` theo nhu cầu
3. Biên dịch và chạy chương trình mã hoá
4. Ghi lại ciphertext (dạng hex) được in ra để giải (nếu cần)
   
### Biên dịch chương trình mã hoá
```
gcc -g ma_hoa/ma_hoa_main.c thu_vien/RC4.c -o ma_hoa/ma_hoa_main.exe
```

### Chạy chương trình mã hoá
```
./ma_hoa/ma_hoa_main.exe
```

## Giải mã

1. Mở file `giai_ma_main.c`
2. Sửa biến `key` để khớp với key đã dùng để mã hóa
3. Dán ciphertext (dạng hex) vào biến `hex_ciphertext`
4. Biên dịch và chạy chương trình giải mã
### Biên dịch chương trình giải mã
```
gcc -g giai_ma/giai_ma_main.c thu_vien/RC4.c -o giai_ma/giai_ma_main.exe
```

### Chạy chương trình giải mã
```
./giai_ma/giai_ma_main.exe
```


## Test Vectors

Dưới đây là một số test vectors để kiểm tra tính đúng đắn của thuật toán

### Test Vector 1
```
Key: Key
Plaintext: Plaintext
Ciphertext (Hex): BBF316E8D940AF0AD3
```

### Test Vector 2
```
Key: Wiki
Plaintext: pedia
Ciphertext (Hex): 1021BF0420
```

### Test Vector 3
```
Key: Secret
Plaintext: Attack at dawn
Ciphertext (Hex): 45A01F645FC35B383552544B9BF5
```
### Test Vector 4
```
Key: Khanh
Plaintext: Hanoi University of Science and Technology
Ciphertext (Hex): 477A457EC2DA2E943EC2D8D32E2EAE3C4DEFDF375C64DD55E74AF78F82FF17C38452CBA7B2CA1B878374
```
