#include <stdio.h>
#include <stdlib.h>

char* showByte(unsigned int byte) {
  char* show = malloc(8 * sizeof(char));

  for (int i = 0; i < 8; i++) {
    if ((byte << i) & 0b10000000) {
      show[i] = '1';
    }
    else {
      show[i] = '0';
    }
  }

  return show;
}

int main() {
  unsigned int sequence[14] = { 0b01001101,
                                0x79,
                                0b00100000,
                                0b01101110,
                                0x61,
                                0x6D,
                                0b01100101,
                                0x20,
                                0x69,
                                0x73,
                                0b00101110,
                                '.',
                                0b00101110,
                                0b00100000 };
  
  for (int i = 0; i < 14; i++) {
    char* show = showByte(sequence[i]);
    printf("Index: %u, Binary: %s, Hex: %X, Decimal: %u\n",
           i,
           show,
           sequence[i],
           sequence[i]);
    free(show);
  }
  printf("String: ");
  for (int i = 0; i < 14; i++) {
    printf("%c", sequence[i]);
  }
  printf(" Ariella!\n");

  return 0;
}