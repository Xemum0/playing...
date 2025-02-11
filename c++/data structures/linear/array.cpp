#include <iostream>
using namespace std;

class Array
{
private:
    int length;
    int size;
    int *items;

public:
    Array(int arrsize)
    {
        size = arrsize;
        length = 0;
        items = new int[size];
    }
    //.............._operation_..............................

    void fill()
    {
        int no_of_elem;
        cout << "enter the no of elem you want to fill : ";
        cin >> no_of_elem;
        if (no_of_elem > size)
        {
            cout << "your number of elem is greater than size ";
            return;
        }
        else
        {
            for (int i = 0; i < no_of_elem; i++)
            {
                cout << "enter the no " << i + 1 << ": ";
                cin >> items[i];
                length++;
            }
        }
    }
    //............................................

    void display()
    {
        cout << "your array elem are : ";
        for (int i = 0; i < length; i++)
        {
            cout << items[i] << "  ";
        }
        cout << endl;
    }
    //............................................

    int getsize()
    {
        return this->size;
    }

    int getlength()
    {
        return this->length;
    }
    //............................................

    int search(int key, int low = 0, int high = -1)
    {
        if (high == -1)
        {
            high = length - 1;
        }
        if (low > high)
            return -1;
        int mid = (low + high) / 2;
        if (items[mid] == key)
            return mid;
        else if (items[mid] < key)
            return search(key, mid + 1, high);
        else
            return search(key, low, mid - 1);
    }
    //............................................
    void append(int data)
    {
        if (items[size - 1] != 0)
        {
            cout << "the array is full\n";
            return;
        }
        else
        {
            items[length] = data;
            length++;
        }
    }
    //............................................
    void push_back(int value)
    {
        int *arr2 = new int[size + 1];

        for (int i = 0; i < size; i++)
            arr2[i] = items[i];
        arr2[size++] = value;
        swap(items, arr2); // exchange the pointers
        delete[] arr2;
        length++;
        size = size + 1;
    }
    //............................................
    void insert(int data, int pos)
    {
        if (items[pos] != 0 || pos < 0 || pos > size)
        {
            cout << "the array is full";
            return;
        }
        else
        {
            for (int j = length; j >= pos; j--)
            {
                items[j] = items[j - 1];
            }
            items[pos] = data;
            length++;
        }
    }

    //............................................
    void delet(int pos)
    {
        if (pos < 0 || pos > size)
        {
            cout << "invalid operation" << endl;
            return;
        }
        else
        {
            for (int i = pos; i < length - 1; i++)
            {
                items[i] = items[i + 1];
            }
            items[length - 1] = 0;
            length--;
        }
    }
    //............................................
    void enlarge(int arrsize)
    {
        if (arrsize <= size)
        {
            cout << "invalide operation" << endl;
            return;
        }
        else
        {
            int *old = items;
            items = new int[arrsize];
            size = arrsize;
            for (int i = 0; i < length; i++)
            {
                items[i] = old[i];
            }
            delete[] old;
        }
    }
    //............................................
    void merge(int arr[], int arrsize)
    {
        int *old = items;
        int temp;
        items = new int[size + arrsize];
        for (int i = 0; i < length; i++)
        {
            items[i] = old[i];
        }
        for (int i = length; i <= arrsize + length; i++)
        {
            items[i] = arr[i - length];
            temp = i;
        }
        length = temp;
        delete[] old;
        size += arrsize;
    }
    //............................................
    void merge_same_type(Array other)
    {
        int *old = items;
        int temp;
        items = new int[size + other.getsize()];
        for (int i = 0; i < length; i++)
        {
            items[i] = old[i];
        }
        for (int i = length; i < other.getsize() + length; i++)
        {
            items[i] = other.items[i - length];
            temp = i;
        }
        length = temp + 1;
        delete[] old;
        size += other.getsize();
    }
};
int main()
{
    int size;
    cout << "enter the array size ";
    cin >> size;
    Array array1(size);
    array1.fill();
    array1.display();

    return 0;
}
