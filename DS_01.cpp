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
  

    printf("구조체변수 a의 주소=%d\n", &a);
    
    printf("data주소 : %d, 값 : %d\n", &a->data, a->data);
    
	free(a);
    return 0;

}
