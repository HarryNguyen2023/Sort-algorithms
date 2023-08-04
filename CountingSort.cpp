#include <iostream>
#include <vector>

// Function to print out the array
void printArr(std::vector<int>& arr)
{
    std::cout<<"The array after counting sort: ";
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
std::vector<int> countingSort(std::vector<int>& arr)
{
    int max = findMax(arr);

    // Initiate some array
    std::vector<int> count(max + 1, 0);
    std::vector<int> out(arr.size(), 0);

    // Count the occurence of elements
    for(int i = 0; i < arr.size(); ++i)
        count[arr[i]]++;

    // Sum the total occurence of previous elements
    for(int i = 0; i <= max; ++i)
        count[i] += count[i - 1];

    // Arrange the elements into the new array
    for(int i = arr.size() - 1; i >= 0; --i)
    {
        out[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    return out;
}

int main()
{
    std::vector<int> arr = {3, 5, 2, 1, 5, 9, 26, 15, 33, 98, 14, 10, 6};

    std::vector<int> sort = countingSort(arr);

    printArr(sort);

    return 0;
}