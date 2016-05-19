#include<stdio.h>

int main() {
  printf("Scrive i primi N numeri della serie di Fibonacci, con N scelto da utente.\n\n");
  int num, fibonacci1=1, fibonacci2=1;
  printf("Quanti numeri della serie vuoi vedere? ");
  scanf("%d", &num);
  printf("\n");
  printf("1\n");
  printf("1\n");
  while(num>0) {
    fibonacci1+=fibonacci2;
    int temp = fibonacci2;
    printf("%d\n", fibonacci1);
    fibonacci2 = fibonacci1;
    fibonacci1 = temp;
    temp = fibonacci1;
    num--;
  }
}
