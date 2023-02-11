#include <sstream>
#include <iostream>
#include <thread>

#define SIZE 20
#define NB_THREAD 2

using namespace std;

int* tab;
thread* tids[NB_THREAD];

void displayTab();
void q_sort_rec(int low, int high);
void quicksort();
void tquicksort();

int main(int argc, char**argv){

    tab = (int *)malloc(SIZE*sizeof(int));
    for(int i = 0; i < SIZE; i++)
        tab[i] = ((i * (9+i) * i + 1) % (i + i + 5));

    displayTab();
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

void tquicksort(){
    if(SIZE < NB_THREAD*10){
        q_sort_rec(0, SIZE);
        return;
    }
    for(int i=0; i<NB_THREAD; i++)
        tids[i] = new thread(q_sort_rec, i/(NB_THREAD), (i+1)/(NB_THREAD));


    for(int i=0; i<NB_THREAD; i++)
        tids[i]->join();
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

    
    if(low != right)q_sort_rec(low, right);
    if(high != right+1) q_sort_rec(right+1, high);

}