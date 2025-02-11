#include <iostream>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
// this is a minimum heap which any nood is greater than her parent
// there is a maximum heap which any nood is less than her parent
class Heap
{
private:
    int *items;
    int heapSize, capacity;

public:
    Heap(int cap)
    {
        if (cap > 0)
        {
            this->capacity = cap;
            items = new int[cap];
            heapSize = 0;
        }
        else
        {
            cout << "no valid capacity\n";
        }
    }
    void display()
    {
        for (size_t i = 0; i < capacity; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }
    int getright(int key)
    {
        return (key * 2) + 2;
    }
    int getroot(int key)
    {
        return (key - 1) / 2;
    }
    int getleft(int key)
    {
        return (key * 2) + 1;
    }
    int height()
    {
        return ceil(log2(heapSize - 1) + 1);
    }
    bool linearSearch(int key)
    {
        if (heapSize <= 0)
            return false;
        for (size_t i = 0; i < heapSize; i++)
            if (items[i] == key)
                return true;
        return false;
    }
    void insert(int key)
    {
        if (heapSize == 0)
        {
            heapSize++;
            items[0] = key;
        }
        else
        {
            heapSize++;
            items[heapSize - 1] = key;
            int i = heapSize - 1;
            while (i != 0 && items[getroot(i)] > items[i])
            {
                swap(items[getroot(i)], items[i]);
                i = getroot(i);
            }
        }
    }
    void heapify(int key)
    {
        int left = getleft(key);
        int right = getright(key);
        int smallest = key;
        if (left < heapSize && items[left] < items[smallest])
            smallest = left;
        if (right < heapSize && items[right] < items[smallest])
            smallest = right;
        if (smallest != key)
        {
            swap(items[smallest], items[key]);
            heapify(smallest);
        }
    }
    int extratMin()
    {
        if (heapSize <= 0)
            return INT_MAX;
        if (heapSize == 1)
        {
            return items[0];
            heapSize--;
        }
        int root = items[0];
        items[0] = items[heapSize - 1];
        heapSize--;
        heapify(0);
        return root;
    }
    void decreaseKey(int pos, int value)
    {
        items[pos] = value;
        while (pos != 0 && items[getroot(pos)] > items[pos])
        {
            swap(items[getroot(pos)], items[pos]);
            pos = getroot(pos);
        }
    }
    void Delet(int pos)
    {
        decreaseKey(pos, INT_MIN);
        extratMin();
    }
    int *heapSort()
    {
        int *temp = new int[capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            temp[i] = extratMin();
        }
        return temp;
    }

    ~Heap()
    {
        delete[] items;
    }
};
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

int main()
{
    // Get the starting time
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 16; i++)
    {
        cout << "hello\n";
    }
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    chrono::duration<double> duration = end - start;

    // Convert duration to seconds
    double seconds = duration.count();

    cout << "Time taken: " << seconds << " seconds" << endl;

    return 0;
}