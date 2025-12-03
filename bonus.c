#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char buffer[100]; 

  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    printf("Erreur d'ouverture du fichier\n");
    return -1;
  }

  int dial = 50;
  int count = 0;
  
  char direction;
  int length;

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    direction = buffer[0];
    length = atoi(buffer + 1);

    for (int i = 0; i < length; i++) {
      if (dial == 0) {
        count++; 
      }

      if (direction == 'R') {
        dial++;
        if (dial > 99) {
          dial = dial - 100;
        }
      }
      if (direction == 'L') {
        dial--;
        if (dial < 0) {
          dial = dial + 100;
        }
      }
    }
  }

  printf("Le mot de passe final est : %d\n", count);
  
  fclose(fp);
  return 0;
}
