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

// Function to perform selection sort
void selectionSort(std::vector<int>& arr)
{
    // Loop through all the elements
    for(int i = 0; i < arr.size() - 1; ++i)
    {
        int min_idx = i;

        // Find the minimum of all other 
        for(int j = i + 1; j < arr.size(); ++j)
        {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the current node with the min number
        swap(arr[i], arr[min_idx]);
    }
}

int main()
{
    std::vector<int> arr = {3, 5, 2, -1, -5, 9, 26, 15, 33, 98, 14, 10, -6};

    selectionSort(arr);

    printArr(arr);

    return 0;
}