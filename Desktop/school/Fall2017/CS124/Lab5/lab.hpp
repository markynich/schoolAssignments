#include "lab.h"

template <class SOMETYPE>
inline void Swap(SOMETYPE &a, SOMETYPE &b)
{
    SOMETYPE temp = a;
    a = b;
    b = temp;
}

template <class SOMETYPE>
void SelectionSort(SOMETYPE a[], int n)
{
    int i , iMax;
    while(n > 1)
    {
        for(iMax = 0, i = 1; i <n; i++)
            if(a[i] > a[iMax]) iMax = i;
        Swap(a[iMax], a[n-1]);
        n--;
    }
}

template <class SOMETYPE>
void InsertionSort(SOMETYPE a[], int n)
{
    int i, j;
    SOMETYPE aCurrent;
    for(i = 1; i < n; i++)
    {
        aCurrent = a[i];
        for(j = 0; j < i; j++)
            if(a[j] >=aCurrent) break;
        for(int k = i-1; k>= j; k--)
            a[k+1] = a[k];
        a[j] = aCurrent;
    }
}

template <class SOMETYPE>
void BubbleSort(SOMETYPE a[], int n)
{
    int i, disorder = n;
    while(disorder)
    {
        disorder = 0;
        for(i = 1; i < n; i++)
        {
            if(a[i-1] > a[i])
            {
                Swap(a[i], a[i-1]);
                disorder++;
            }
        }
        n--;
    }
}

template <class SOMETYPE>
void MERGESORT<SOMETYPE>::Sort(SOMETYPE a[], int n)
{
    {
    int n1, n2;
    SOMETYPE *a2;
    if (n <= 2) { // Base case:
        if (n == 2 && a[1] < a[0])
            Swap(a[0], a[1]);
    }
    else { // Recursive case:
        n1 = n/2; n2 = n - n1;
        a2 = &a[n1]; // a2 points to the second half of the
        // array.
        Sort(a, n1);
        Sort(a2, n2);
        Merge(a, n1, a2, n2);
    }
}
}

template <class SOMETYPE>
void MERGESORT<SOMETYPE>::Merge(SOMETYPE a1[], int n1, SOMETYPE a2[], int n2)
{
 int n = n1 + n2;
 int i1, i2, j;
    // Merge two arrays into the work array:
 i1 = i2 = 0;
 for (j = 0; j < n; j++) {
    if (i1 < n1 && i2 < n2) {
        if (a1[i1] < a2[i2])
            work[j] = a1[i1++];
        else
            work[j] = a2[i2++];
    }
    else if (i1 < n1)
        work[j] = a1[i1++];
    else // if (i2 < n2)
        work[j] = a2[i2++];
    }
    // Copy work[] back to a1[]:
    for (j = 0; j < n; j++)
        a1[j] = work[j];
}

template <class SOMETYPE>
void MERGESORT<SOMETYPE>::Swap(SOMETYPE &a, SOMETYPE &b)
{
 SOMETYPE temp = a; a = b; b = temp;
}

template <class SOMETYPE>
int QUICKSORT<SOMETYPE>::Split(SOMETYPE a[], int n)
// Takes one of the values (here a[n/2]) as "pivot"
// and splits the array into two parts so that:
// a[p] == pivot
// a[i] <= pivot for i < p
// a[j] >= pivot for j > p
// Returns p;
{
    int p = n/2; // In this version the "pivot" value is the
                // middle element.
    SOMETYPE pivot = a[p];
    int i = 0, j = n-1;
    // Increment i if a[i] <= pivot; decrement j if a[j] >= pivot;
    // otherwise swap a[i] and a[j] and advance both i and j:
    while (i <= j) {
        if (a[i] <= pivot)
            i++;
        else if (a[j] >= pivot)
            j--;
        else {
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    }
 // Now a[i] and a[j] are adjacent elements; i > j.
 // Swap a[i] or a[j] with the pivot, making sure that
 // the swapped element remains on the same side of the pair:
    if (p < j) {
        Swap(a[p], a[j]);
        p = j;
    }
    else if (p > i) {
        Swap(a[p], a[i]);
        p = i;
    }
    return p;
}
#ifdef  SIMPLIFIED

template <class SOMETYPE>
void QUICKSORT<SOMETYPE>::Sort(SOMETYPE a[], int n)
// Sorts array a of length n in ascending order.
// The maximum recursion depth is O(log n).
{
    int p;
    while (n > 1) {
        if (n == 2) { // Base case
            if (a[1] < a[0]) Swap(a[0], a[1]);
                break;
        }
        else { // Recursive case
            p = Split(a, n);
            if (p > n/2) {
                Sort(&a[p+1], n-p-1); // Process recursively the
                                        // right part
                n = p; // Continue iteratively with
                        // the left part
                }
            else {
                Sort(a, p); // Process recursively the
    //                      left part
                a += p+1; // Continue iteratively with
                n -= p+1; // the right part
            }
        }
    }
}
#endif
