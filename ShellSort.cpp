#include <iostream>
#include <vector>

// Function to print out the array
void printArr(std::vector<int>& arr)
{
    std::cout<<"The array after shell sort: ";
    for(auto& i : arr)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}

// Function to perform the shell sort 
void shellSort(std::vector<int>& arr)
{
    for(int step = arr.size() / 2; step > 0; step /= 2)
    {
        for(int i = step; i < arr.size(); i++)
        {
            int j, temp = arr[i];
            // Swap all the smaller 
            for(j = i; j >= step && arr[j - step] > temp; j -= step)
                arr[j] = arr[j - step];
            arr[j] = temp;
        }
    }
}

int main()
{
    std::vector<int> arr = {3, 5, 2, -1, -5, 9, 26, 15, 33, 98, 14, 10, -6};

    shellSort(arr);

    printArr(arr);

    return 0;
}