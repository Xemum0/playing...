#include <iostream>
#include <cstdlib>
#include <ctime>
// the median-of-three pivot selection method to avoid the worst case in quick sort
int getRandomPivot(int low, int high)
{
    std::srand(time(NULL));
    return low + std::rand() % (high - low + 1);
}

int medianOfThree(int arr[], int low, int high)
{
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low])
    {
        std::swap(arr[low], arr[mid]);
    }
    if (arr[high] < arr[low])
    {
        std::swap(arr[low], arr[high]);
    }
    if (arr[high] < arr[mid])
    {
        std::swap(arr[mid], arr[high]);
    }
    return mid;
}

int partition(int arr[], int low, int high)
{
    int pivotIndex = medianOfThree(arr, low, high);
    std::swap(arr[pivotIndex], arr[high]);

    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int num = 0; num < n; num++)
    {
        std::cout << arr[num] << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int num = 0; num < n; num++)
    {
        std::cout << arr[num] << " ";
    }
    std::cout << std::endl;

    return 0;
}
