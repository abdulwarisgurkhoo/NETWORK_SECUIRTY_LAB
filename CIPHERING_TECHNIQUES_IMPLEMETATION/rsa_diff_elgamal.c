#include <stdio.h>

// Core mathematical function required for RSA, ElGamal, and DH
long long modExp(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}

// 11. RSA
void rsa() {
    long long p = 61, q = 53; // Small primes for lab demo
    long long n = p * q;
    long long e = 17; // Public exponent
    long long d = 2753; // Private exponent
    
    long long msg = 65;
    long long encrypted = modExp(msg, e, n);
    long long decrypted = modExp(encrypted, d, n);
    printf("RSA -> Msg: %lld | Encrypted: %lld | Decrypted: %lld\n", msg, encrypted, decrypted);
}

// 12. ElGamal
void elgamal() {
    long long p = 89, g = 3;
    long long private_key = 15;
    long long public_key = modExp(g, private_key, p);
    
    long long msg = 42, k = 17; // k is ephemeral random key
    long long c1 = modExp(g, k, p);
    long long c2 = (msg * modExp(public_key, k, p)) % p;
    
    // Decryption using Fermat's Little Theorem for mod inverse
    long long s = modExp(c1, private_key, p);
    long long s_inv = modExp(s, p - 2, p);
    long long decrypted = (c2 * s_inv) % p;
    
    printf("ElGamal -> Encrypted: (c1=%lld, c2=%lld) | Decrypted: %lld\n", c1, c2, decrypted);
}

// 13. Diffie-Hellman
void diffieHellman() {
    long long p = 23, g = 5; // Public prime and base
    long long alice_private = 4, bob_private = 3;
    
    long long alice_public = modExp(g, alice_private, p);
    long long bob_public = modExp(g, bob_private, p);
    
    long long alice_secret = modExp(bob_public, alice_private, p);
    long long bob_secret = modExp(alice_public, bob_private, p);
    
    printf("Diffie-Hellman -> Alice Secret: %lld | Bob Secret: %lld\n", alice_secret, bob_secret);
}

int main() {
    rsa();
    elgamal();
    diffieHellman();
    return 0;
}