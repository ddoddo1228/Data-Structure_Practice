#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct test {
    int data;
    char String[20];
	
}test;

int main() {
	
    test* a;
    a = (test*) malloc (sizeof(test));
    a->data = 100;
    strcpy(a->String, "just testing");
  

    printf("����ü���� a�� �ּ�=%d\n", &a);
    
    printf("data�ּ� : %d, �� : %d\n", &a->data, a->data);
    
	free(a);
    return 0;

}
