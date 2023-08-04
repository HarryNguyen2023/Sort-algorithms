#include <iostream>
#include <vector>

// Function to print out the array
void printArr(std::vector<int>& arr)
{
    std::cout<<"The array after insertion sort: ";
    for(auto& i : arr)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}

// Function to swap 2 number
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function to perform the insertion sort
void insertionSort(std::vector<int>& arr)
{
    // Loop through all the element of the array
    for(int i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while(key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    std::vector<int> arr = {3, 5, 2, -1, -5, 9, 26, 15, 33, 98, 14, 10, -6};

    insertionSort(arr);

    printArr(arr);

    return 0;
}