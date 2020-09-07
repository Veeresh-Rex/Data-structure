#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
class minheap
{

    int *arr;
    int size, cap;

public:
    minheap(int x)
    {
        size = 0;
        cap = x;
        arr = new int[x];
    }
    int smallele() { return arr[0]; }
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    void insert(int k);
    void deletekey(int k);
    void extractMin();
    void heapify(int i);
    void decreseKey(int i, int k);
    void print();
};
void minheap::heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && arr[l] < arr[i])
    {
        smallest = l;
    }
    if (r < size && arr[r] < arr[i])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(&arr[smallest], &arr[i]);
        heapify(smallest);
    }
}
void minheap::extractMin()
{
    if (size <= 0)
        return;
    if (size == 1)
    {
        size--;
        return;
    }
    arr[0] = arr[size - 1];
    size--;
    heapify(0);
}
void minheap::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void minheap::deletekey(int k)
{
    // arr[k]=INT_MIN;
    decreseKey(k, INT_MIN);
    extractMin();
}
void minheap::decreseKey(int i, int k)
{
    arr[i] = k;
    int j = i;
    while (j != 0 && arr[j] < arr[parent(j)])
    {
        swap(&arr[j], &arr[parent(j)]);
        j = parent(j);
    }
}
void minheap ::insert(int k)
{
    if (size == cap)
    {
        cout << "Overflow heaf\n";
        return;
    }
    if (size == 0)
    {
        arr[0] = k;
        size++;
        return;
    }

    arr[size] = k;
    int i = size;
    size++;
    while (i != 0 && arr[i] < arr[parent(i)])
    {
        //   cout << "before" << arr[i] << " " << arr[parent(i)] << "\n";
        swap(&arr[i], &arr[parent(i)]);
        //   cout << "after" << arr[i] << " " << arr[parent(i)] << "\n";
        i = parent(i);
    }
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        minheap heap(8);
        heap.insert(10);
        heap.insert(12);
        heap.insert(45);
        heap.insert(11);
        heap.insert(1);
        heap.decreseKey(1, 7);
        //cout << heap.smallele();
        heap.deletekey(0);
        heap.print();
    }
    return 0;
}
