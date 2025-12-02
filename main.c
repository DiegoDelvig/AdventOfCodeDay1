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

    if (direction == 'R') {
      if (dial + length > 99) {
        count++;
      }
      dial = (dial + length) % 100;
    } 
    else if (direction == 'L') {
      dial = dial - length;        
      dial = dial % 100;

      if (dial <= 0) {
        count++;
        dial = dial + 100;
      }
    }
  }

  printf("Le mot de passe final est : %d\n", count);
  
  fclose(fp);
  return 0;
}
