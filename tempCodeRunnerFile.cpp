
#include <iostream>
using namespace std;

#define MAX_ROWS 100
#define MAX_COLS 100

void readArray(int arr[][MAX_COLS], int& rows, int& cols) {
    cout << "Enter the number of rows and columns of the array (max " << MAX_ROWS << "x" << MAX_COLS << "): ";
    cin >> rows >> cols;

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }
}

void displayArray(const int arr[][MAX_COLS], int rows, int cols) {
    cout << "Array contents:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void searchNumber(const int arr[][MAX_COLS], int rows, int cols, int num) {
    bool found = false;
    cout << "Searching for number " << num << "..." << endl;
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (arr[i][j] == num) {
                cout << "Number " << num << " found at position (" << i << ", " << j << ")" << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Number " << num << " not found in the array." << endl;
    }
}

void searchMin(const int arr[][MAX_COLS], int rows, int cols) {
    int minNum = arr[0][0];
    int minRow = 0, minCol = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] < minNum) {
                minNum = arr[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
    cout << "Minimum number: " << minNum << " at position (" << minRow << ", " << minCol << ")" << endl;
}

int countEven(const int arr[][MAX_COLS], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] % 2 == 0) {
                count++;
            }
        }
    }
    return count;
}

void updateLocation(int arr[][MAX_COLS], int rows, int cols) {
    int row, col, newValue;
    cout << "Enter the row and column to update: ";
    cin >> row >> col;
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        cout << "Enter the new value: ";
        cin >> newValue;
        arr[row][col] = newValue;
        cout << "Value updated successfully." << endl;
    } else {
        cout << "Invalid row or column." << endl;
    }
}

void transpose(int arr[][MAX_COLS], int& rows, int& cols) {
    int transposed[MAX_COLS][MAX_ROWS];
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            transposed[i][j] = arr[j][i];
        }
    }
    // Swap rows and cols
    swap(rows, cols);
    // Copy transposed array back to original array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = transposed[i][j];
        }
    }
}

void multiplyArray(int arr1[][MAX_COLS], int arr2[][MAX_COLS], int& rows1, int& cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        cout << "Error: Incompatible dimensions for multiplication." << endl;
        return;
    }
    int result[MAX_ROWS][MAX_COLS] = {0};
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    // Copy result to arr1
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            arr1[i][j] = result[i][j];
        }
    }
    // Update dimensions of arr1
    cols1 = cols2;
}

int main() {
    int arr[MAX_ROWS][MAX_COLS], rows, cols;
    int choice, num;
    bool arrayInitialized = false;

    do {
        cout << "\n********MENU FOR ARRAY OPERATIONS********" << endl;
        cout << "1. Read or Append Data" << endl;
        cout << "2. Search for a Number and Its Location" << endl;
        cout << "3. Search for the Minimum Number and Its Location" << endl;
        cout << "4. Count Even Numbers" << endl;
        cout << "5. Update Contents of a Location" << endl;
        cout << "6. Find the Transpose" << endl;
        cout << "7. Multiply with Another Array" << endl;
        cout << "8. Display Array Contents" << endl;
        cout << "9. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                readArray(arr, rows, cols);
                arrayInitialized = true;
                break;
            case 2:
                if (arrayInitialized) {
                    cout << "Enter the number to search: ";
                    cin >> num;
                    searchNumber(arr, rows, cols, num);
                } else {
                    cout << "Error: Array not initialized. Please read or append data first." << endl;
                }
                break;
            case 3:
                if (arrayInitialized) {
                    searchMin(arr, rows, cols);
                } else {
                    cout << "Error: Array not initialized. Please read or append data first." << endl;
                }
                break;
            case 4:
                if (arrayInitialized) {
                    cout << "Number of even numbers: " << countEven(arr, rows, cols) << endl;
                } else {
                    cout << "Error: Array not initialized. Please read or append data first." << endl;
                }
                break;
            case 5:
                if (arrayInitialized) {
                    updateLocation(arr, rows, cols);
                } else {
                    cout << "Error: Array not initialized. Please read or append data first." << endl;
                }
                break;
            case 6:
                if (arrayInitialized) {
                    transpose(arr, rows, cols);
                    cout << "Array transposed successfully." << endl;
                } else {
                    cout << "Error: Array not initialized. Please read or append data first." << endl;
                }
                break;
            case 7:
                if (arrayInitialized) {
                    int arr2[MAX_ROWS][MAX_COLS], rows2, cols2;
                    cout << "Enter the second array:" << endl;
                    readArray(arr2, rows2, cols2);
                    multiplyArray(arr, arr2, rows, cols, rows2, cols2);
                    cout << "Arrays multiplied successfully." << endl;
                } else {
                    cout << "Error: First array not initialized. Please read or append data first." << endl;
                }
                break;
            case 8:
                if (arrayInitialized) {
                    displayArray(arr, rows, cols); 
                } else {
                    cout << "Error: Array not initialized. Please read or append data first." << endl;
                }
                break;
            case 9:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);

    return 0;
}
