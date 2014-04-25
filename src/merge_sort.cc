#include <iostream>
#include <vector>
#include <math.h>

void PrintArray(std::vector<int> array, std::string header="")
{
  std::cout << header;
  for (uint i = 0; i < array.size(); ++i) {
    std::cout << array.at(i) << " ";
  }
}

void MergeSorted(std::vector<int> a1, std::vector<int> a2, std::vector<int> &aout)
{
  size_t x = 0, i1 = 0, i2 = 0;
  while (x < aout.size()) {
    if (i1 == a1.size()) {
      aout[x] = a2.at(i2);
      ++i2;
    } else if (i2 == a2.size()) {
      aout[x] = a1.at(i1);
      ++i1;
    } else if (a1[i1] < a2[i2]) {
      aout[x] = a1[i1];
      ++i1;
    } else {
      aout[x] = a2[i2];
      ++i2;
    }
    ++x;
  }
}

void MergeSort(std::vector<int> &array)
{
  double size = (double)array.size();

  // If array is only one value, return
  if (size <= 1) {
    return;
  }

  int half_size = (int)(ceil(size / 2.0));

  // Create two arrays with 
  std::vector<int> a1(array.begin(), array.begin() + half_size);
  std::vector<int> a2((array.begin() + half_size), array.end());

  MergeSort(a1);
  MergeSort(a2);

  MergeSorted(a1, a2, array);
}

int main(int argc, char **argv)
{
  int array_length = 0;

  std::cout << "How many numbers do you want to merge sort? ";
  std::cin >> array_length;
  while (array_length <= 0) {
    std::cout << "Please enter a positive integer: ";
    std::cin >> array_length;
  }

  std::vector<int> input_array(array_length);

  for (int i = 0; i < array_length; ++i) {
    std::cin >> input_array[i];
  }

  std::cout << "Initial Array: "; PrintArray(input_array);
  std::cout << std::endl;

  MergeSort(input_array);

  std::cout << "Final Array: "; PrintArray(input_array);
  std::cout << std::endl;

  return 0;
}
