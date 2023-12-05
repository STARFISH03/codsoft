#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 5;
const double TICKET_PRICE = 10.0;

// Function to display the seating chart
void displaySeatingChart(const vector<vector<char>>& seats) {
    cout << "  ";
    for (int i = 1; i <= NUM_COLS; ++i) {
        cout << setw(3) << i;
    }
    cout << endl;

    for (int i = 0; i < NUM_ROWS; ++i) {
        cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < NUM_COLS; ++j) {
            cout << setw(3) << seats[i][j];
        }
        cout << endl;
    }
}

// Function to check if a seat is available
bool isSeatAvailable(const vector<vector<char>>& seats, int row, int col) {
    return seats[row][col] == 'O';
}

// Function to make a booking
void makeBooking(vector<vector<char>>& seats, int row, int col) {
    seats[row][col] = 'X';
}

int main() {
    // Initialize the seating chart
    vector<vector<char>> seats(NUM_ROWS, vector<char>(NUM_COLS, 'O'));

    while (true) {
        // Display menu
        cout << "\nMovie Ticket Booking System\n";
        cout << "1. View Movie Listings\n";
        cout << "2. Make a Booking\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                // View Movie Listings
                displaySeatingChart(seats);
                break;

            case 2:
                // Make a Booking
                char row;
                int col;

                // Get user input for seat selection
                cout << "Enter the row (A-E): ";
                cin >> row;
                row = toupper(row) - 'A';  // Convert to uppercase and convert to index

                cout << "Enter the column (1-5): ";
                cin >> col;
                col--;  // Convert to zero-based index

                // Validate seat selection
                if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS &&
                    isSeatAvailable(seats, row, col)) {
                    makeBooking(seats, row, col);
                    cout << "Booking successful! Total cost: $" << fixed << setprecision(2)
                         << TICKET_PRICE << endl;
                } else {
                    cout << "Invalid seat selection. Please try again.\n";
                }
                break;

            case 3:
                // Exit
                cout << "Exiting program. Thank you!\n";
                return 0;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
