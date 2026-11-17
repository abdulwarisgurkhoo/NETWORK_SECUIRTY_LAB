# 🔐 Ciphering Techniques — Implementation Reference

> All programs written in **C (C99/C11)**. Compile with `gcc`. Detailed per-file usage below.

---

## Classical Substitution Ciphers

### `monoalphabetic.c`
**Cipher:** Monoalphabetic Substitution  
**Key:** Fixed alphabet `QWERTYUIOPASDFGHJKLZXCVBNM`  
**How it works:** Every plaintext letter is replaced by a fixed unique ciphertext letter. Case-preserving. Full encrypt + decrypt.

```bash
gcc -o monoalphabetic monoalphabetic.c && ./monoalphabetic
```

---

### `vigenere.c`
**Cipher:** Vigenère (Polyalphabetic Substitution)  
**Key:** A keyword string  
**How it works:** Each plaintext letter is shifted by the corresponding keyword letter (cycled). Spaces and punctuation pass through unchanged.

```bash
gcc -o vigenere vigenere.c && ./vigenere
# Input: plaintext → "Hello World", key → "KEY"
# Output: Ciphertext + Decrypted plaintext
```

---

### `one_time_pad.c`
**Cipher:** One-Time Pad (OTP)  
**Key:** Auto-generated random uppercase key (same length as alphabetic chars in plaintext)  
**How it works:** Each alphabetic character is shifted by a random key character. Theoretically unbreakable if key is truly random and used once.

```bash
gcc -o one_time_pad one_time_pad.c && ./one_time_pad
```

---

### `hillcipher.c`
**Cipher:** Hill Cipher (Matrix-based)  
**Key:** A string whose length is a perfect square (4 for 2×2, 9 for 3×3)  
**How it works:** Plaintext is split into vectors; each is multiplied by the key matrix mod 26. Pads with 'X' as needed.

```bash
gcc -o hillcipher hillcipher.c -lm && ./hillcipher
# Key: "DCBA" (2×2), Plaintext: "ACT"
```

---

### `playfair.c`
**Cipher:** Playfair  
**Key:** A keyword that generates a 5×5 matrix (I/J merged)  
**Rules:** Same row → shift right; same column → shift down; rectangle → swap columns.

```bash
gcc -o playfair playfair.c && ./playfair
# Key: "MONARCHY", Plaintext: "BALLOON"
```

---

### `ceaser_vergriner_vernum_otp.c`
**Ciphers:** Caesar + Vigenère + Vernam/OTP  
**Purpose:** Comparative demonstration of three related ciphers.  
Hardcoded with `text = "hello"`, `shift = 3`, `key = "key"` / `"apple"`.

```bash
gcc -o multi_cipher ceaser_vergriner_vernum_otp.c && ./multi_cipher
```

---

## Transposition Ciphers

### `rail_fence.c`
**Cipher:** Rail Fence  
**Key:** Number of rails (≥ 2)  
**How it works:** Text is written diagonally in a zigzag across N rails, then read row-by-row. Fully reversible.

```bash
gcc -o rail_fence rail_fence.c && ./rail_fence
# Input: "WEAREDISCOVEREDFLEEATONCE", rails: 3
```

---

### `row_column.c`
**Cipher:** Columnar Transposition (Row-Column)  
**Key:** A keyword string  
**How it works:** Plaintext is written row-by-row into a grid; columns are read in alphabetical keyword order.

```bash
gcc -o row_column row_column.c && ./row_column
# Input: "ATTACKPOSTPONEDUNTILTWOAM", key: "ZEBRAS"
```

---

### `railfrance_rowcol.c`
**Ciphers:** Rail Fence + Row-Column (combined demonstration)

```bash
gcc -o railfrance_rowcol railfrance_rowcol.c && ./railfrance_rowcol
```

---

## Symmetric Block Ciphers

### `aes.c`
**Cipher:** AES (Simplified — educational)  
**What it shows:** `AddRoundKey` → `SubBytes` → `ShiftRows` on a 4-byte state vector.  
Hardcoded state `{0x1A, 0x2B, 0x3C, 0x4D}` with round key `0x55`.

```bash
gcc -o aes aes.c && ./aes
```

---

### `des.c`
**Cipher:** DES (Data Encryption Standard)  
**Tables included:** IP, FP (inverse permutation), E-expansion, P-box, S1 & S2 boxes.  
Encrypts `"Hellowor"` with key `"Key12345"` and prints the hex output.

```bash
gcc -o des des.c && ./des
```

---

## Asymmetric Cryptography

### `rsa_diff_elgamal.c`
Three public-key algorithms in one file:

| Function | Algorithm | Key Parameters |
|----------|-----------|----------------|
| `rsa()` | RSA | p=61, q=53, e=17, d=2753; encrypts M=65 |
| `elgamal()` | ElGamal | p=89, g=3, priv=15; encrypts M=42 |
| `diffieHellman()` | Diffie-Hellman | p=23, g=5; Alice priv=4, Bob priv=3 |

All three use `modExp(base, exp, mod)` — fast modular exponentiation via square-and-multiply.

```bash
gcc -o rsa_diff_elgamal rsa_diff_elgamal.c && ./rsa_diff_elgamal
```

---

## Compilation Summary

| File | Compile Command | Notes |
|------|----------------|-------|
| `monoalphabetic.c` | `gcc -o monoalphabetic monoalphabetic.c` | Interactive input |
| `vigenere.c` | `gcc -o vigenere vigenere.c` | Interactive input |
| `one_time_pad.c` | `gcc -o one_time_pad one_time_pad.c` | Interactive input |
| `hillcipher.c` | `gcc -o hillcipher hillcipher.c -lm` | Requires `-lm` |
| `playfair.c` | `gcc -o playfair playfair.c` | Interactive input |
| `rail_fence.c` | `gcc -o rail_fence rail_fence.c` | Interactive input |
| `row_column.c` | `gcc -o row_column row_column.c` | Interactive input |
| `ceaser_vergriner_vernum_otp.c` | `gcc -o multi ceaser_vergriner_vernum_otp.c` | Hardcoded demo |
| `railfrance_rowcol.c` | `gcc -o combo railfrance_rowcol.c` | Hardcoded demo |
| `aes.c` | `gcc -o aes aes.c` | Hardcoded demo |
| `des.c` | `gcc -o des des.c` | Hardcoded demo |
| `rsa_diff_elgamal.c` | `gcc -o rsa rsa_diff_elgamal.c` | Hardcoded demo |
