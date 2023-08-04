#include <iostream>
#include <vector>

// Function to print out the array
template<typename T>
void printArr(std::vector<T>& arr)
{
    std::cout<<"The array after counting sort: ";
    for(auto& i : arr)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}

// Function to sort and merge 2 sub-arrays
template <typename T>
void merge(std::vector<T>& arr, int start, int mid, int end)
{
    // Create 2 arrays for each halft of the original array
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<T> arr1(n1);
    std::vector<T> arr2(n2);
    // Fill these 2 arrays with the associated elements
    for(int i = 0; i < n1; i++)
        arr1[i] = arr[start + i];
    for(int i = 0; i < n2; i++)
        arr2[i] = arr[mid + i + 1];

    // Initiate some variables
    int i = 0, j = 0, k = start;

    // Sort and merge elements from 2 arrays to 1 array
    while(i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }

    // Merge the left over elements of the 2 arrays
    while(i < n1)
        arr[k++] = arr1[i++];
    
    while(j < n2)
        arr[k++] = arr2[j++];
}

// Function to perform the merge sort algorithm using divide and conquer algorithm
template <typename T>
void mergeSort(std::vector<T>& arr, int start, int end)
{
    if(start >= end)
        return;
    
    int mid = (start + end) / 2;

    // Separate the original array into 2 sub-arrays
    mergeSort<T>(arr, start, mid);
    mergeSort<T>(arr, mid + 1, end);

    // Sort and merge the sub-arrays
    merge<T>(arr, start, mid, end);
}

int main()
{
    std::vector<float> arr = {3, 5, 2, -1, -5, 9, 26, 15, 33, 98, 14, 10, -6};

    mergeSort<float>(arr, 0, arr.size() - 1);

    printArr<float>(arr);

    return 0;
}