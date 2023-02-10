#include <sstream>
#include <iostream>

#define SIZE 10

using namespace std;

int* tab;

void displayTab();
void q_sort_rec(int low, int high);
void quicksort();

int main(int argc, char**argv){

    tab = (int *)malloc(SIZE*sizeof(int));
    for(int i = 0; i < SIZE; i++)
        tab[i] = (i * i * i + 1 % (i + i + 5));


    quicksort();
    displayTab();



    free(tab);
    return 0;
}

void displayTab(){
    if(SIZE == 0){   std::cout << "[-]" << std::endl; return;}
    std::cout << "[";
    for(int i = 0; i < SIZE-1; i++)
        std::cout << tab[i] << ", ";
    std::cout << tab[SIZE-1] << "]" << std::endl;
}

void quicksort(){
    q_sort_rec(0, SIZE);
}


void q_sort_rec(int low, int high){
    if(low == high) return;


    int pivot_index = low;
    int pivot_value = tab[pivot_index];
    int left = pivot_index + 1;
    int right = high - 1;

    while (left < right) {
        while(left < high && (tab[left] < pivot_value)) left++;
        while((tab[right] >= pivot_value)) right--;
        if(left < right)swap(left, right);
    }
    if ((pivot_value >= tab[right])) swap(right, pivot_index);

    if(low != right)   q_sort_rec(low, right);
    if(high != right+1) q_sort_rec(right+1, high);
}