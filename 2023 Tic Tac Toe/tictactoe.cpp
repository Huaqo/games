// clear && g++ -std=c++11 tictactoe.cpp -o tictactoe && ./tictactoe

#include <iostream>
#include <vector>
#include <string>
#include <map>

bool checkWin(std::vector<std::vector<char>>& board, char player);
void printBoard(const std::vector<std::vector<char>>& board);

int main() {

    std::vector<std::vector<char>> board = {{' ', ' ', ' '},
                                            {' ', ' ', ' '},
                                            {' ', ' ', ' '}};

    struct position {
        int row;
        int col;
    };

    std::map<std::string, position> input = {
        {"L1", {0, 0}},
        {"M1", {0, 1}},
        {"R1", {0, 2}},
        {"L2", {1, 0}},
        {"M2", {1, 1}},
        {"R2", {1, 2}},
        {"L3", {2, 0}},
        {"M3", {2, 1}},
        {"R3", {2, 2}},
    };

    char Player1 = 'X';
    char Player2 = 'O';
    char currentPlayer = Player1;
    std::string move;
    char winner = ' ';

    while (winner == ' ') {
        std::cout << "This is the Tic Tac Toe the Board: \n";
        std::cout << "\n";         
        printBoard(board);
        std::cout << "Here are the inputs for the Board: \n";
        std::cout << "\n"; 
        std::cout << "|L1|M1|R1| \n"; 
        std::cout << "|L2|M2|R2| \n"; 
        std::cout << "|L3|M3|R3| \n";
        std::cout << "\n";
        std::cout << "Spieler " << currentPlayer << ", du bist am Zug: ";

        std::cin >> move;
        std::cout << "\n\n";

        if (input.find(move) != input.end()) {
            position pos = input[move];

            if (board[pos.row][pos.col] == ' ') {
                board[pos.row][pos.col] = currentPlayer;

                if (checkWin(board, currentPlayer)) {
                    winner = currentPlayer;
                    break;
                }

                if (currentPlayer == Player1) {
                    currentPlayer = Player2;
                } 
                else {
                    currentPlayer = Player1;
                }
            } 
            else {
                std::cout << "Das Feld ist bereits besetzt. Bitte waehle ein anderes Feld.\n";
            }
        } 
        else {
            std::cout << "Ungueltige Eingabe. Bitte gebe einen gueltigen Zug ein (z.B. 'L1', 'M2', ...).\n";
        }
    }

    printBoard(board);
    std::cout << "!!! Der Gewinner ist " << winner << " 🥳🥳🥳 !!!" <<std::endl;
    std::cout << "\n";

}

bool checkWin(std::vector<std::vector<char>>& board, char player) {
    // Überprüfe die Zeilen
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Überprüfe die Spalten
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Überprüfe die Diagonalen
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

void printBoard(const std::vector<std::vector<char>>& board) {
    for (const auto &row : board) {
        for (const auto &col : row) {
            std::cout << '|' << col << '|';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}
