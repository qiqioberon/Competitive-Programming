// C++ program to Count
// Inversions in an array
// using Merge Sort
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll _mergeSort(ll arr[], ll temp[], ll left, ll right);

ll merge(ll arr[], ll temp[], ll left, ll mid,

         ll right);

// This function sorts the
// input array and returns the
// number of inversions in the array

ll mergeSort(ll arr[], ll array_size)
{

    ll temp[array_size];

    return _mergeSort(arr, temp, 0, array_size - 1);
}

// An auxiliary recursive function
// that sorts the input array and
// returns the number of inversions in the array.

ll _mergeSort(ll arr[], ll temp[], ll left, ll right)
{

    ll mid, inv_count = 0;

    if (right > left)
    {

        // Divide the array llo two parts and

        // call _mergeSortAndCountInv()

        // for each of the parts

        mid = (right + left) / 2;

        // Inversion count will be sum of

        // inversions in left-part, right-part

        // and number of inversions in merging

        inv_count += _mergeSort(arr, temp, left, mid);

        inv_count += _mergeSort(arr, temp, mid + 1, right);

        // Merge the two parts

        inv_count += merge(arr, temp, left, mid + 1, right);
    }

    return inv_count;
}

// This function merges two sorted arrays
// and returns inversion count in the arrays.

ll merge(ll arr[], ll temp[], ll left, ll mid,

         ll right)
{

    ll i, j, k;

    ll inv_count = 0;

    i = left;

    j = mid;

    k = left;

    while ((i <= mid - 1) && (j <= right))
    {

        if (arr[i] <= arr[j])
        {

            temp[k++] = arr[i++];
        }

        else
        {

            temp[k++] = arr[j++];

            // this is tricky -- see above

            // explanation/diagram for merge()

            inv_count = inv_count + (mid - i);
        }
    }

    // Copy the remaining elements of left subarray

    // (if there are any) to temp

    while (i <= mid - 1)

        temp[k++] = arr[i++];

    // Copy the remaining elements of right subarray

    // (if there are any) to temp

    while (j <= right)

        temp[k++] = arr[j++];

    // Copy back the merged elements to original array

    for (i = left; i <= right; i++)

        arr[i] = temp[i];

    return inv_count;
}

int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        ll angka, jml;
        cin >> jml;
        ll arr[jml];
        for (ll j = 0; j < jml; j++)
        {
            cin >> angka;
            arr[j] = angka;
        }
        ll n = sizeof(arr) / sizeof(arr[0]);
        ll ans = mergeSort(arr, n);
        cout << ans << endl;
    }

    return 0;
}