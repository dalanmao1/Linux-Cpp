#include <iostream>
#include <iterator>

int arry[] = {4, 1, 3, 2, 5, 6, 9, 8, 7};

void quick_sort(int a[], int start, int end) {
    int l=start,r=end;
    if (l > r) return;

  int pos = l;
  while (l < r) {
    while (a[r] >= a[pos] && l < r) r--;
    while (a[l] <= a[pos] && l < r) l++;
    
    if (l < r) std::swap(a[l], a[r]);
  }
  std::swap(a[l], a[pos]);
  quick_sort(arry, start, l-1);
  quick_sort(arry, l+1, end);
}

int main(int argc, char const *argv[]) {
  for (int i = 0; i < 9; i++) std::cout << arry[i] << ' ';

  std::cout << std::endl;
  quick_sort(arry, 0, 8);

  for (int i = 0; i < 9; i++) std::cout << arry[i] << ' ';

  return 0;
}
