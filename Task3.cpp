#include <iostream>
#include <limits> 
using namespace std;

void display(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------\n";
    }
}

bool isValidInput(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3;
}

bool checkWinner(char mat[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (mat[i][0] == player && mat[i][1] == player && mat[i][2] == player) {
            return true;
        }
    }
    if (mat[0][0] == player && mat[1][1] == player && mat[2][2] == player) {
        return true;
    }
    if (mat[0][2] == player && mat[1][1] == player && mat[2][0] == player) {
        return true;
    }
    return false;
}

bool boardFull(char mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char mat[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char playAgain;

    do {
        int row, col;
        char player = 'X';

        while (true) {
            cout << player << "'s turn" << endl;
            display(mat);

            while (true) {
                cout << "Enter row (0, 1, 2) and column (0, 1, 2): ";
                cin >> row >> col;
                cout << endl;

                if (!cin) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter numeric values for row and column." << endl;
                }
                else if (!isValidInput(row, col)) {
                    cout << "Invalid input! Please enter values between 0 and 2 for both row and column." << endl;
                }
                else if (mat[row][col] != ' ') {
                    cout << "Cell already occupied! Choose another place." << endl;
                }
                else {
                    break;
                }
            }

            mat[row][col] = player;

            if (checkWinner(mat, player)) {
                cout << player << " is the winner!" << endl;
                break;
            }
            else if (boardFull(mat)) {
                cout << "It's a draw!" << endl;
                break;
            }

            player = (player == 'X') ? 'O' : 'X';
        }

        cout << "Do you want to play again? (y/n): ";

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}
