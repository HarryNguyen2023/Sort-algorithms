#include <iostream>
#include <vector>

#define MAX 10

// Function to print out the array
void printArr(std::vector<int>& arr)
{
    std::cout<<"The array after counting sort: ";
    for(auto& i : arr)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}

// Function to find the maximum element in the array
int findMax(std::vector<int>& arr)
{
    int max = arr[0];

    for(int i = 1; i < arr.size(); ++i)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to perform the shell sort 
void countingSort(std::vector<int>& arr, int place)
{
    // Initiate some array
    std::vector<int> count(MAX, 0);
    std::vector<int> out(arr.size(), 0);

    // Count the occurence of elements
    for(int i = 0; i < arr.size(); ++i)
        count[(arr[i] / place) % 10]++;

    // Sum the total occurence of previous elements
    for(int i = 1; i < MAX; ++i)
        count[i] += count[i - 1];

    // Arrange the elements into the new array
    for(int i = arr.size() - 1; i >= 0; --i)
    {
        out[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }
    
    // Copy the output
    for(int i = 0; i < arr.size(); ++i)
        arr[i] = out[i];
}

// Function tp perform the radix sort algorithm
void radixSort(std::vector<int>& arr)
{
    int max = findMax(arr);

    for(int i = 1; max / i > 0; i *= 10)
        countingSort(arr, i);
}

int main()
{
    std::vector<int> arr = {121, 432, 564, 23, 1, 45, 788};

    radixSort(arr);

    printArr(arr);

    return 0;
}