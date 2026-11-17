<div align="center">

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=28&pause=1000&color=00E5A0&center=true&vCenter=true&width=800&lines=Network+Security+Laboratory;Cryptography+%26+Network+Protocols;Central+University+of+Kashmir" alt="Typing SVG" />

<br/>

![GitHub repo size](https://img.shields.io/github/repo-size/abdulwarisgurkhoo/NETWORK_SECUIRTY_LAB?color=00e5a0&style=for-the-badge&logo=github)
![GitHub last commit](https://img.shields.io/github/last-commit/abdulwarisgurkhoo/NETWORK_SECUIRTY_LAB?color=ff6b35&style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C-4fc3f7?style=for-the-badge&logo=c)
![License](https://img.shields.io/badge/License-Academic-ffd54f?style=for-the-badge)
![Institution](https://img.shields.io/badge/CUK-Information%20Technology-00e5a0?style=for-the-badge)

<br/>

> **A comprehensive academic repository for Network Security coursework — covering classical ciphers, modern encryption, asymmetric cryptography, and in-depth study guides on network security protocols.**

<br/>

</div>

---

## 🧭 Table of Contents

- [About This Repository](#about-this-repository)
- [Repository Structure](#repository-structure)
- [Cipher Implementations](#cipher-implementations)
  - [Classical / Substitution Ciphers](#1-classical--substitution-ciphers)
  - [Transposition Ciphers](#2-transposition-ciphers)
  - [Symmetric Block Ciphers](#3-symmetric-block-ciphers)
  - [Asymmetric / Public-Key Cryptography](#4-asymmetric--public-key-cryptography)
- [Study Resources](#study-resources)
- [How to Compile & Run](#how-to-compile--run)
- [Academic Information](#academic-information)
- [Reference Textbook](#reference-textbook)

---

## 📌 About This Repository

This repository contains all lab work and academic materials for the **Network Security** course at the **Department of Information Technology, Central University of Kashmir**. It includes:

- ✅ **13 cipher implementations** written in C, covering the full cryptography curriculum
- ✅ **A professional HTML study guide** on Web Security, Email Security, IP Security & Firewalls
- ✅ **Lab Reports** and **Seminar Presentations** (Zero-Trust Architecture)
- ✅ Based on **William Stallings — Cryptography and Network Security, 5th Edition**

---

## 📁 Repository Structure

```
NETWORK_SECURITY_LAB/
│
├── 📂 CIPHERING_TECHNIQUES_IMPLEMETATION/
│   │
│   ├── 🔐 Substitution Ciphers
│   │   ├── monoalphabetic.c          # Fixed letter-substitution cipher
│   │   ├── ceaser_vergriner_vernum_otp.c  # Caesar + Vigenère + Vernam/OTP
│   │   ├── vigenere.c                # Polyalphabetic Vigenère cipher
│   │   ├── one_time_pad.c            # Theoretically unbreakable OTP
│   │   ├── hillcipher.c              # Matrix-based Hill cipher
│   │   └── playfair.c                # Digraph substitution (Playfair)
│   │
│   ├── 🔀 Transposition Ciphers
│   │   ├── rail_fence.c              # Zigzag Rail Fence cipher
│   │   ├── railfrance_rowcol.c       # Rail Fence + Row-Column combo
│   │   └── row_column.c              # Columnar transposition cipher
│   │
│   └── 🛡️ Modern Ciphers
│       ├── aes.c                     # AES step-by-step (SubBytes, ShiftRows)
│       ├── des.c                     # Full DES with IP/FP tables & S-boxes
│       └── rsa_diff_elgamal.c        # RSA + ElGamal + Diffie-Hellman (DH)
│
├── 📂 Labreport/
│   └── 2324CUKmr01_ABDUL_WARIS_GURKHOO_Network_Security_Lab_Report.pdf
│
├── 📂 presenataion/
│   ├── 2324CUKmr01_ABDUL_WARIS_GURKHOO_Seminar_Presentation.pptx
│   └── Zero_Trust_Architecture.pptx  # Seminar: Zero Trust Architecture
│
├── 🌐 network_security_web_email_ip_firewalls.html   # Interactive study guide
├── 📖 William Stallings - Cryptography and Network Security.pdf
├── 📄 .gitignore
└── 📋 README.md
```

---

## 🔐 Cipher Implementations

All implementations are written in **ANSI C** and compile cleanly with GCC.

### 1. Classical / Substitution Ciphers

| File | Cipher | Type | Description |
|------|--------|------|-------------|
| `monoalphabetic.c` | Monoalphabetic | Substitution | Fixed QWERTY-based alphabet substitution with encrypt & decrypt |
| `ceaser_vergriner_vernum_otp.c` | Caesar + Vigenère + Vernam | Multi-cipher | Three classical ciphers in one file for comparative study |
| `vigenere.c` | Vigenère | Polyalphabetic | Repeating keyword shifts; full encrypt & decrypt |
| `one_time_pad.c` | One-Time Pad (OTP) | Perfect secrecy | Auto-generates random key; theoretically unbreakable |
| `hillcipher.c` | Hill Cipher | Matrix | n×n key matrix; VLA-based, supports 2×2 and 3×3 |
| `playfair.c` | Playfair | Digraph | 5×5 key matrix, digraph substitution with full rules |

### 2. Transposition Ciphers

| File | Cipher | Description |
|------|--------|-------------|
| `rail_fence.c` | Rail Fence | Zigzag write, row-by-row read; full encrypt & decrypt |
| `railfrance_rowcol.c` | Rail Fence + Row-Column | Combined transposition demonstration |
| `row_column.c` | Columnar Transposition | Keyword-ordered column reading; full encrypt & decrypt |

### 3. Symmetric Block Ciphers

| File | Cipher | Description |
|------|--------|-------------|
| `aes.c` | AES (Simplified) | Demonstrates AddRoundKey, SubBytes, ShiftRows on a 4-byte state |
| `des.c` | DES | Full IP/FP permutation tables, E-expansion, S-boxes, and P-box |

### 4. Asymmetric / Public-Key Cryptography

| File | Algorithm | Description |
|------|-----------|-------------|
| `rsa_diff_elgamal.c` | RSA + ElGamal + Diffie-Hellman | All three in one file using modular exponentiation |

---

## 🌐 Study Resources

### Interactive HTML Study Guide

**`network_security_web_email_ip_firewalls.html`** — A dark-themed, sidebar-navigated single-page reference covering:

| Module | Topics Covered |
|--------|----------------|
| **Module 1 — Web Security** | HTTPS/TLS handshake, SSL record protocol, certificate chain of trust |
| **Module 2 — Email Security** | PGP, S/MIME, DKIM, SPF, DMARC, email threat taxonomy |
| **Module 3 — IP Security (IPSec)** | AH, ESP, IKEv2, Security Associations, tunnel vs. transport mode |
| **Module 4 — Firewalls** | Packet-filter, stateful inspection, application-proxy, bastion hosts, DMZ design |
| **Module 5 — Malicious Software** | Viruses, worms, Trojans, ransomware, botnets, rootkits |
| **Module 6 — Intrusion Detection & Prevention** | IDS types, anomaly detection, honeypots, NIPS vs. HIPS |

> Open in any modern browser — no server required. Features smooth-scroll navigation, intersection-observer active links, and responsive layout.

### Presentations

| File | Topic |
|------|-------|
| `Zero_Trust_Architecture.pptx` | Zero Trust Security Model — seminar presentation |
| `2324CUKmr01_..._Seminar_Presentation.pptx` | Individual seminar presentation |

---

## ⚙️ How to Compile & Run

### Prerequisites

```bash
# Linux / macOS
sudo apt install gcc          # Debian/Ubuntu
brew install gcc              # macOS

# Windows — MinGW or MSYS2
winget install -e --id MSYS2.MSYS2
```

### Compile & Execute

```bash
# Navigate to the ciphers directory
cd CIPHERING_TECHNIQUES_IMPLEMETATION

# Example: Compile and run Vigenère cipher
gcc -o vigenere vigenere.c && ./vigenere

# Example: Compile and run Hill Cipher (requires math library)
gcc -o hillcipher hillcipher.c -lm && ./hillcipher

# Example: Compile and run RSA + ElGamal + Diffie-Hellman
gcc -o rsa rsa_diff_elgamal.c && ./rsa

# Example: Compile and run DES
gcc -o des des.c && ./des

# Example: Compile and run Rail Fence
gcc -o rail_fence rail_fence.c && ./rail_fence
```

> **Note:** `hillcipher.c` requires the `-lm` flag to link the math library for `sqrt()`.

### Quick Batch Compile (Linux/macOS)

```bash
for f in *.c; do gcc -o "${f%.c}" "$f" -lm 2>/dev/null && echo "✓ $f compiled"; done
```

---

## 🎓 Academic Information

| Field | Details |
|-------|---------|
| **Student** | Abdul Waris Gurkhoo |
| **Roll Number** | 2324CUKMR01 |
| **Department** | Information Technology |
| **Institution** | Central University of Kashmir |
| **Course** | Network Security |
| **Academic Year** | 2023–2024 |

---

## 📖 Reference Textbook

<div align="center">

**William Stallings — *Cryptography and Network Security: Principles and Practice*, 5th Edition**

> The standard reference for all theory, algorithms, and security protocols covered in this repository.

</div>

---

## ⚠️ Academic Integrity

> This repository is shared for **educational and reference purposes only**.  
> All implementations are original academic work by **Abdul Waris Gurkhoo**.  
> Please do not submit this code as your own work without proper attribution.

---

<div align="center">

**Made with 🛡️ for the Network Security Lab**  
*Central University of Kashmir — Department of Information Technology*

</div>
