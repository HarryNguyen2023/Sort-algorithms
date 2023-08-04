#include <iostream>
#include <vector>

// Function to print out the array
void printArr(std::vector<int>& arr)
{
    std::cout<<"The array after bubblr sort: ";
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

// Function to perform the bubble sort
void bubbleSort(std::vector<int>& arr)
{
    for(int i = 0; i < arr.size() - 1; ++i)
    {
        bool swapped = false;

        for(int j = 0; j < arr.size() - i - 1   ; ++j)
        {
            if(arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
                swapped = true;
            }
        }
        if(! swapped)
            break;
    }
}

int main()
{
    std::vector<int> arr = {3, 5, 2, -1, -5, 9, 26, 15, 33, 98, 14, 10, -6};

    bubbleSort(arr);

    printArr(arr);

    return 0;
}