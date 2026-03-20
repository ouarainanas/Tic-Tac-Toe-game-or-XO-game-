#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char b[3][3];
void init() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            b[i][j] = '1' + i * 3 + j;
}
void draw() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << b[i][0] << " | " << b[i][1] << " | " << b[i][2] << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}
char check() {
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2]) return b[i][0];
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i]) return b[0][i];
    }
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) return b[0][0];
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) return b[0][2];
    return ' ';
}
bool full() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] != 'X' && b[i][j] != 'O') return false;
    return true;
}
void computerMove() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] != 'X' && b[i][j] != 'O') {
                char tmp = b[i][j];
                b[i][j] = 'O';
                if (check() == 'O') return;
                b[i][j] = tmp;
            }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] != 'X' && b[i][j] != 'O') {
                char tmp = b[i][j];
                b[i][j] = 'X';
                if (check() == 'X') { b[i][j] = 'O'; return; }
                b[i][j] = tmp;
            }
    if (b[1][1] != 'X' && b[1][1] != 'O') { b[1][1] = 'O'; return; }
    srand(time(0));
    int r, c;
    do {
        r = rand() % 3;
        c = rand() % 3;
    } while (b[r][c] == 'X' || b[r][c] == 'O');
    b[r][c] = 'O';
}
int main() {
    init();
    cout << "---Tic Tac Toe vs computer--- \n";
    cout << "You are X , AI is O\n";
    while (true) {
        draw();
        int n;
        cout << "Pick a number (1-9): ";
        cin >> n;
        n--;
        int r = n / 3, c = n % 3;
        if (n < 0 || n > 8 || b[r][c] == 'X' || b[r][c] == 'O') {
            cout << "invalid move";
            continue;
        }
        b[r][c] = 'X';
        if (check() == 'X') { draw(); cout << "you win!"; break; }
        if (full())          { draw(); cout << "draw!";    break; }
        computerMove();
        if (check() == 'O') { draw(); cout << "computer wins!"; break; }
        if (full())          { draw(); cout << "draw!";    break; }
    }
    return 0;
}
