#include <iostream>
#include<cmath>
#include <cstdlib>
#include<ctime>
using namespace std;

const int N = 10;
const char marks[2] = {'X', 'O'};
char grid[N][N];
int counter=0;

//This function prints the grid of Tic-Tac-Toe Game as the game progresses
void print_grid() {

    cout << " __";
    for (int i = 0; i < N; cout << "___", i++);
    cout << "   \n";
    cout << "   \n";

    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << "  ";
        cout << "|";
        cout << "  ";
        for (int i = 0; i < N; cout << "  ", i++);
        cout << "  \n";}
     cout << " __";
     for (int i = 0; i < N; cout << "___", i++);
     cout << "   ";

}
//This function checks if the game has a win state or not
bool check_lose(int i , int j ,int a ) {
    if(a==0 || a==1 || a==2){ grid[i][j]='X'; return true;}
    else{ return false;}

}

bool check_win() {
    int c=0;
     for (int i =0 ; i<N; i++){
            for (int j =0 ; j<N; j++){
                if (grid[i][j]=='*'){
                        c+=1;

                }
            }
        }
    if(c==1){return true;}
    else {return false;}

}
bool check_valid_index(int i, int j){
    if(grid[i][j]=='*'){return true;}
    else{return false;}

}


//This function generates pac man
int generate_apples() {
    srand( (unsigned)time( NULL ) );
    int f=pow(N,2);
    int a = rand() % f ;
    return a;
}


//This function checks if given position is valid or not
bool check_valid_position(int i, int j) {
    bool valid= 0<=i && i<N && 0<=j && j<N;
     return valid;

}
//This function sets the given mark to the given cell
void set_cell(int i, int j, int a) {
    if (a%2){grid[i][j]='1'; counter+=1; }
    else if(a%2==0){grid[i][j]='0';}

}
//This function clears the game structures
void grid_clear() {

        for (int i =0 ; i<N; i++){
            for (int j =0 ; j<N; j++){
                grid[i][j]='*';
            }
        }
        counter =0;

}
//This function reads a valid position input
void read_input(int &i, int &j) {
	cout << "Enter the row index and column index: ";
	cin >> i >> j;
    while (!check_valid_position(i, j) || !check_valid_index(i,j)) {
		cout << "Enter a valid row index and a valid column index: ";
		cin >> i >> j;
	}
}
//MAIN FUNCTION
void play_game() {
    cout << " Bad apple Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";

    while (true) {
        //Prints the grid
        cout<<"Your score is : "<< counter<<endl;
        print_grid();

        //Read an input position from the player
        int i, j;
		read_input(i, j);
		int a = generate_apples();
		if (check_lose(i,j,a)){
            print_grid();
			//Announcement of the final statement
            cout << "Game over !\n";
            break;
		}
		else{
        //Set the player mark in the input position
        set_cell(i, j,a);

        //Check if the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
			//Announcement of the final statement
            cout << "Congrats, YOU WON";
            break;
        }}

    }
}
int main() {
    while (true) {
    	grid_clear();
    	play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
