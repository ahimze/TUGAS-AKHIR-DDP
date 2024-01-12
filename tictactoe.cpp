#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
int pilihan;
int row,column;
char giliran ;
bool draw = false;
bool ulang= true;
char type,lagi;

//fungsi untuk memilih type player
 char menu_pilihan(){

 	cout<<"Silahkan Player 1 Memilih [X] atau [O]"<<endl;
	cin>>type;

	}
	
 
void papan_display(){
	system("CLS");
    
	cout<<"PERMAINAN SEDERHANA TIC TAC TOE"<<endl;
	cout<<" _________________"<<endl;
    cout<<"|     |     |     |"<<endl;
    cout<<"|  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  |"<<endl;
    cout<<"|_____|_____|_____|"<<endl;
    cout<<"|     |     |     |"<<endl;
    cout<<"|  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  |"<<endl;
    cout<<"|_____|_____|_____|"<<endl;
    cout<<"|     |     |     |"<<endl;
    cout<<"|  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  |"<<endl;
    cout<<"|     |     |     |"<<endl;
    cout<<" -----------------"<<endl;
}

//Fungsi untuk menginput angka di papan player 1 sebagai X

void player_turn1(){
    if(giliran == 'X' ){
        cout<<" Giliran Player - 1 [X] : ";

    }
    else if(giliran == 'O'){
        cout<<" Giliran Player - 2 [O]  : ";
    }
    
    //menginput pilihan angka yang dimasukkan oleh user
    //updating the board according to pilihan and reassigning the turn Start

    cin>> pilihan;
	if(pilihan > 9){
		cout<<"Tidak Ada Pilihan "<<endl;
		player_turn1();
		
	}
    //switch case untuk mendapatkan baris dan kolom mana yang akan diperbarui atau dipilih
    switch(pilihan){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Tidak Ada Pilihan ";
    }

    if(giliran == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //memperbarui posisi untuk 'X' symbol if
        //jika belum ditempati oleh x atau o atau dalam kata lain masih angka
        board[row][column] = 'X'; //maka akan digantikan oleh x
        giliran = 'O';
    }else if(giliran == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //memperbarui posisi untuk'O' symbol if
        //jika belum ditempati oleh x atau o atau dalam kata lain masih angka
        board[row][column] = 'O';//maka akan digantikan oleh o
        giliran = 'X';
    }else {
        //jika kotak yang di input itu sudah terisi x atau o
        cout<<"Kotak sudah terisi , silahkan cari yang lain"<<endl;
        player_turn1();
    }
    /* Ends */
    papan_display();
}
void player_turn2(){
    if(giliran == 'O' ){
        cout<<" Giliran Player - 1 [O] : ";

    }
    else if(giliran == 'X'){
        cout<<" Giliran Player - 2 [X]  : ";
    }
    
    cin>> pilihan;

	if(pilihan > 9){
		cout<<"Tidak Ada Pilihan "<<endl;
		
		player_turn2();
	}
    switch(pilihan){
    	
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Tidak Ada Pilihan";
    }

    if(giliran == 'O' && board[row][column] != 'O' && board[row][column] != 'X'){
        board[row][column] = 'O';
        giliran = 'X';
    }else if(giliran == 'X' && board[row][column] != 'O' && board[row][column] != 'X'){
        board[row][column] = 'X';
        giliran = 'O';
    }else {
        cout<<"Kotak sudah terisi , silahkan cari yang lain"<<endl;
        player_turn2();
    }
    /* Ends */
    papan_display();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //mengecheck apakah permainan berlanjut atau tidak
    //dengan mengecheck giliran pemain dengan batas 3 kali bermain tiap pemainnya
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //jika giliran sudah terpenuhi dan tidak ada pemenang
    //maka draw
    draw = true;
    return false;
}

//Program Main Method

int main()
{ while(ulang = true)
{
	papan_display();
	menu_pilihan();
	
	switch(type){
		
		case 'X'|'x':
		giliran = 'X';
		while(gameover()){
        papan_display();
        player_turn1();
        gameover();}
        break;
        
        case 'O'|'o':
        giliran = 'O';
		while(gameover()){
        papan_display();
        player_turn2();
        gameover();}
        break;
        
        default:
        	cout<<"Pilihan Tidak Tersedia";
        	main();
        	
	}
	
    if(giliran == 'X' && draw == false){
        cout<<"Selamat !Player 'O' telah memenangkan pertandingan "<<endl;
        
    }
    else if(giliran == 'O' && draw == false){
        cout<<"Selamat !Player 'X' telah memenangkan pertandingan"<<endl;
    }
    else{
    	cout<<"GAME DRAW!!!"<<endl;
	}      
   
   	cout<<"Lanjut?(Y/T)"<<endl;
   	cin>>lagi;
   	switch(lagi){
   		case 'Y'|'y':
   		 ulang = true;
        
	   	board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
        board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
        board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';
        ulang = 0;
		break;
		
		case 'T'|'t':
		ulang = false;
   		return 0;
   		break;	
   		default:
   			return 0;
	   }
	 
	   }
   	
	   

}

