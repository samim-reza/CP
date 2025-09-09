#include <bits/stdc++.h>
using namespace std;

struct item
{
   int key;
   int value;
};

//sort the struct according to key using merge sort
bool compare(item a, item b)
{
   return a.key < b.key;
}
void merge(item arr[], int left, int mid, int right)
{
   int n1 = mid - left + 1;
   int n2 = right - mid;

   item* L = new item[n1];
   item* R = new item[n2];

   for (int i = 0; i < n1; i++)
      L[i] = arr[left + i];
   for (int j = 0; j < n2; j++)
      R[j] = arr[mid + 1 + j];

   int i = 0;
   int j = 0;
   int k = left;

   while (i < n1 && j < n2)
   {
      if (compare(L[i], R[j]))
      {
         arr[k] = L[i];
         i++;
      }
      else
      {
         arr[k] = R[j];
         j++;
      }
      k++;
   }

   while (i < n1)
   {
      arr[k] = L[i];
      i++;
      k++;
   }

   while (j < n2)
   {
      arr[k] = R[j];
      j++;
      k++;
   }

   delete[] L;
   delete[] R;
}
void mergeSort(item arr[], int left, int right)
{
   if (left < right)
   {
      int mid = left + (right - left) / 2;

      mergeSort(arr, left, mid);
      mergeSort(arr, mid + 1, right);

      merge(arr, left, mid, right);
   }
}
//perform binary search on the struct array according to key
int binarySearch(item arr[], int n, int key)
{
   int left = 0;
   int right = n - 1;   
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid].key == key)
            return mid;
        else if (arr[mid].key < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // key not found
}
int main()
{
   item arr[] = { {5, 10}, {3, 20}, {8, 15}, {1, 30} };
   int n = sizeof(arr) / sizeof(arr[0]);

   mergeSort(arr, 0, n - 1);

   cout << "Sorted array according to key:\n";
   for (int i = 0; i < n; i++)
      cout << "{" << arr[i].key << ", " << arr[i].value << "} ";
   cout << endl;
    int key = 3;
    int result = binarySearch(arr, n, key);
    if (result != -1)
        cout << "Element with key " << key << " found at index " << result << endl;
    else
        cout << "Element with key " << key << " not found in the array" << endl;
}
