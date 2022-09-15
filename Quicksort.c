#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 1000000


int medianThree(int a, int b, int c) {
    if ((a > b) && (a > c))
        return a;
    else if ((b < a) && (b < c))
        return b;
    else
        return c;
}


void quickSort(int arr[], int comeco, int final) {
    int temp;
    if (final > comeco) {
        int i = comeco;
        int j = final;
        int x = (rand() % (comeco - final + 1)) + comeco;

        while (i < j) {
            while (arr[i] <= arr[x] && i < final)
                i++;
            while (arr[j] > arr[x])
                j--;
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[x];
        arr[x] = arr[j];
        arr[j] = temp;
        quickSort(arr, comeco, j - 1);
        quickSort(arr, j + 1, final);
    }
}
int main() {
    int *arr;
    arr = (int*)malloc(TAMANHO * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < TAMANHO; i++)
        arr[i] = rand();
    quickSort(arr, 0, TAMANHO - 1);
    return 0;
}
