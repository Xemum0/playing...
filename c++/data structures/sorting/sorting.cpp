#include <iostream>
using namespace std;

void selection(int arr[], int size)
{
    for (int j = 0; j < size - 1; j++)
    {
        int max = j;
        for (int i = j + 1; i < size; i++)
        {
            if (arr[max] < arr[i])
            {
                max = i;
            }
        }
        swap(arr[max], arr[j]);
    }
}
// or
/*for (int i=0;i<size;i++){
         for (int j=i+1;j<size;j++){
             if (arr[i]<arr[j]) swap(arr[i],arr[j]);

         }

     }
*/
//...................................................
void bubble(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        // bool flag=true;
        for (int j = 0; j < size; j++)
        { // we can do j<size-i-1 ,k++after the end of this loop
            if (arr[j] < arr[j + 1])
                swap(arr[j + 1], arr[j]);
            // flag=false
        }
        // if (flag==true)break;
    }
}
//...................................................
void insertion(int arr[], int size)
{
    int key, i, j;
    for (i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = key;
    }
}
//...................................................
void merge(int arr[], int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[start + i];
    }

    for (int i = 0; i < rightSize; i++)
    {
        rightArr[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = start;

    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < leftSize)
    {
        arr[k++] = leftArr[i++];
    }

    while (j < rightSize)
    {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

//...................................................

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int pivotIndex = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {

            swap(&arr[pivotIndex], &arr[j]);
            pivotIndex++;
        }
    }

    swap(&arr[pivotIndex], &arr[high]);
    return pivotIndex;
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
//...................................................
void countingSort(int arr[], int size, int range)
{
    int count[range];
    int output[size];

    for (size_t i = 0; i < size; i++)
    {
        count[i] = 0;
    }
    for (size_t i = 0; i < size; i++)
    {
        ++count[arr[i]];
    }
    for (size_t i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }
    for (size_t i = 0; i < size; i++)
    {
        output[--count[arr[i]]] = arr[i];
    }
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

//...................................................
int maximum(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void counting_Sort(int arr[], int size, int div)
{
    int count[10] = {0};
    int output[size];

    for (int i = 0; i < size; i++)
    {
        ++count[(arr[i] / div) % 10];
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        output[--count[(arr[i] / div) % 10]] = arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int size)
{
    int div = 1;
    int m = maximum(arr, size);
    while (m > 0)
    {
        counting_Sort(arr, size, div);
        div *= 10;
        m /= 10;
    }
}
//...................................................
void shellSort(int arr[], int n) // insertion
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (size_t j = gap; j < n; j++)
        {
            int temp = arr[j];
            int i = 0;
            for (i = j; i >= gap && arr[i - gap] > temp; i -= gap)
            {
                arr[i] = arr[i - gap];
            }
            arr[i] = temp;
        }
    }
}

void shellSortBubble(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = 0; i < size - gap; i++)
        {
            for (int j = i; j >= 0; j -= gap)
            {
                if (arr[j] > arr[j + gap])
                {
                    swap(arr[j], arr[j + gap]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}
//...................................................

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr) / sizeof(arr[0]);

    shellSortBubble(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}