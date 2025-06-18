#include <stdio.h>
#include <stdlib.h>
#include "inc/quicksort.h"
#include "inc/stack.h"

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){                        
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int* arr, int low, int high){
    t_stack* s = create_stack(20);

    push(s, low);
    push(s, high);

    while(!is_empty(s)){
        high = pop(s);
        low = pop(s);

        int piv_pos = partition(arr, low, high);

        if(high - (piv_pos + 1) >= (piv_pos - 1) - low){
            if(piv_pos - 1 > low){
                push(s, low);
                push(s, piv_pos - 1);
            }

            if(piv_pos + 1 < high){
                push(s, piv_pos + 1);
                push(s, high);
            }
        } else {            
            if(piv_pos + 1 < high){
                push(s, piv_pos + 1);
                push(s, high);
            }

            if(piv_pos - 1 > low){
                push(s, low);
                push(s, piv_pos - 1);
            }
        }
    }
    
    free(s->calls);
    free(s);
}