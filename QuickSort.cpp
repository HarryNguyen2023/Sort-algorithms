#include <iostream>
#include <vector>

// Function to print out the array
template <typename T>
void printArr(std::vector<T>& arr)
{
    std::cout<<"The array after counting sort: ";
    for(auto& i : arr)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}

// Function to swap 2 number
template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Function to spearate the array into smaller and larger hafts compared to the pivot
template <typename T>
int seperatePivot(std::vector<T>& arr, int start, int end)
{
    // Select the right most element of the array as the pivot element
    T pivot = arr[end];

    int i = start - 1;
    // Loop and swap the position of smaller element to the left
    for(int j = start; j < end; ++j)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Swap the position of the pivot
    swap(arr[i + 1], arr[end]);

    return i + 1;
}

// function to perform the quick sort using divide and conquer approach
template <typename T>
void quickSort(std::vector<T>& arr, int start, int end)
{
    if(start >= end)
        return;
    
    int pivot = seperatePivot<T>(arr, start, end);

    // Recursively sort the 2 half sub-arrays
    quickSort<T>(arr, start, pivot - 1);
    quickSort<T>(arr, pivot + 1, end);
}

int main()
{
    std::vector<int> arr = {3, 5, 2, -1, -5, 9, 26, 15, 33, 98, 14, 10, -6};

    quickSort<int>(arr, 0, arr.size() - 1);

    printArr<int>(arr);

    return 0;
}
