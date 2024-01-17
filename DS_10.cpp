#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void selection_sort(int list[], int n)
{     int i, j, least, temp, k;
      for(i=0; i<n-1; i++) {
         least = i;
   for(j=i+1; j<n; j++)    
                     if  (list[j]<list[least]) least = j;
             SWAP(list[i], list[least], temp);
                for (k = 0; k < n; k++)
         printf("%d  ", list[k]);
   printf("\n");
   }
}

int main() {
    int list[MAX_SIZE];
    int n = MAX_SIZE;

    printf("<선택정렬>\n정렬 이전 배열 : ");
    for (int i = 0; i < n; i++) {
        list[i] = rand() % n;
        printf("%d ", list[i]);
    }
    printf("\n");

    selection_sort(list, n); 

    printf("최종 정렬 결과 : ");
    for (int i = 0; i < n; i++) 
        printf("%d ", list[i]);
    printf("\n");
    system("pause");
}
