#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 256   // 2^8

void printAsciiTable();
void hext_to_ascii(char *str_ret,unsigned char hexText);
void str_hex_decode(char *dump_to, unsigned char *hex_encoded);
int RCsi(char *key, char *plaintext, unsigned char *ciphertext);