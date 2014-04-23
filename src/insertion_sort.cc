
#include <iostream>
#include <vector>

/**
 * @brief Insertionion Sort of integeres by inserting
 * high values into the lower indices of the array. i is an int
 * so that it can be a negative number for the while loop check
 * instead of wrapping around.
 * T(n) = n(n+1)/2 = O(n^2).
 * @param size Size of the array
 * @param array Array to sort by reference
 * @return void
 */
void InsertionSortInts(size_t size, std::vector<int> &array)
{
  // Loop through each index starting with the second ([1])
  // and check if lower indices have larger values. If so, swap
  for (size_t j = 1; j < size; ++j) {

    int key = array.at(j);   // Save the current value to insert somewhere
    int i = j - 1;           // Start comparing with the value to the left of j

    // Check the key against every value to its left.
    // If value at i is greater than the key, swap values
    // at i and i+1 and then decrement i.
    while (i >= 0 && array.at(i) > key) {
      array.at(i+1) = array.at(i);
      --i;
    }

    // Put the key to the right of the current i position.
    // If i hasn't changed, (ie. we didn't enter the while loop),
    // it do// esn't change the array
    array.at(i+1) = key;
  }
}

int main(int argc, char **argv)
{
  // Get array from user using std::vector
  std::vector<int> input_array;

  int array_length = 0;
  std::cout << "How many numbers do you want to sort? ";
  while (array_length <= 0) {
    std::cin >> array_length;
    if (array_length <= 0) {
      std::cout << "Please enter a positive integer" << std::endl;
    }
  }

  for (int i = 0; i < array_length; ++i) {
    std::cout << "Enter #: ";
    int new_int = 0;
    std::cin >> new_int;
    input_array.push_back(new_int);
  }

  std::cout << "Initial array: ";
  for (size_t i = 0; i < input_array.size(); ++i) {
    std::cout << input_array[i] << " ";
  }
  std::cout << std::endl;

  // Sort the array
  InsertionSortInts(input_array.size(), input_array);

  std::cout << "Final array: ";
  for (size_t i = 0; i < input_array.size(); ++i) {
    std::cout << input_array.at(i) << " ";
  }
  std::cout << std::endl;
}
