#include <iostream>
#include <algorithm>
#include <vector>

// Function to print out the array
void printArr(std::vector<float>& arr)
{
    std::cout<<"The array after counting sort: ";
    for(auto& i : arr)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}

// Function to perform bucket sort algorithm
void bucketSort(std::vector<float>& arr)
{
    // Initiate the vector of the buckets
    std::vector<float> bucket[arr.size()];

    // Hash the elements into the corresponding bucket
    for(int i = 0; i < arr.size(); ++i)
    {
        int bi = arr.size() * arr[i];
        bucket[bi].push_back(arr[i]);
    }

    // Sort individual buckets
    for(int i = 0; i < arr.size(); ++i)
        std::sort(bucket[i].begin(), bucket[i].end());

    // Concatenate all the buckets again
    int idx = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        for(int j = 0; j < bucket[i].size(); ++j)
            arr[idx++] = bucket[i][j];
    }
}   

int main()
{
    std::vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434, 0.6765, 0.3174, 0.7749};

    bucketSort(arr);
    
    printArr(arr);

    return 0;
}