
#include<iostream> 
#include<windows.h>
#include<ctime>
using namespace std;
int const ROW = 4;
int const COL=4;
int score = 0;
//game用來記錄遊戲結果 
int game[4][4]= {0};
void x(){
	srand(time(0));
    int x=rand()% ROW;
    int y=rand()% COL;
    int cnt =0;
    for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(game[i][j] !=0){
				cnt++;
			}
		} 
	}
	if(cnt == 16){		
		cout<< "Game Over"<<endl;
		exit(0);
		return;
		}

    while (game[x][y]!=0){
        x=rand()% ROW;
        y=rand()% COL; 
	}
		game[x][y]=2;	
} 
void PrintScore(){
	cout << "你目前的分數是:" << score << "\n"; 
}
void Print(){
    for (int i = 0; i < ROW; ++i)  
    {  
        cout << "---------------------------------"<< endl;  
        for (int j = 0; j < COL; ++j)  
        {  
            if (game[i][j] == 0)  
            {  
                cout <<"|   \t";  
            }  
            else   
            {  
                cout <<"|   " << game[i][j] << "\t";  
            }  
        }  
        cout << "|" << endl;  
    }  
    cout << "---------------------------------"<< endl;  
}  
void up(){
    int nextGame[4][4] = {};

    int now = 0;
    // for (int i = 0; i < 4; i++) {
    //     if (game[0][i] != 0) {
    //         nextGame[0][now] = game[0][i];
    //         now++;
    //     }
    // }
    // (0, 0)
    // (1, 0)
    // (2, 0)
    // (3, 0)

    for (int j = 0; j < 4; j++) {
        now = 0;
        for (int i = 0; i < 4; i++) {
            if (game[i][j] != 0) {
                nextGame[now][j] = game[i][j];
                now++;
            }
        } 
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game[i][j] = nextGame[i][j];
        }
    }
    for (int j = 0; j < 4; j++) {
        now = 0;
        for (int i = 0; i < 4; i++) {
            if (i + 1 < 4 && game[i][j] == game[i + 1][j]&&game[i][j]!=0) {
                nextGame[now][j] = game[i][j] + game[i][j];
                score+= game[i][j] + game[i][j];
                now++;
                i++;
            } else {
                nextGame[now][j] = game[i][j];
                now++;
            }
        } 
    }

    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) {
            game[i][j] = nextGame[i][j];
        }
}
	x();
    Print();
}
void down(){
	
    int nextGame[4][4] = {};

    int now = 0;
    // for (int i = 0; i < 4; i++) {
    //     if (game[0][i] != 0) {
    //         nextGame[0][now] = game[0][i];
    //         now++;
    //     }
    // }
    // (0, 0)
    // (1, 0)
    // (2, 0)
    // (3, 0)

    for (int j = 3; j >= 0; j--) {
        now = 3;
        for (int i = 3; i >= 0; i--) {
            if (game[i][j] != 0) {
                nextGame[now][j] = game[i][j];
                now--;
            }
        } 
    }
     for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game[i][j] = nextGame[i][j];
        }
    }
	 for (int j = 0; j < 4; j++) {
        now = 3;
        for (int i = 3; i >= 0;i--) {
            if (i - 1 > -1 && game[i][j] == game[i - 1][j]&&game[i][j] != 0) {
                nextGame[now][j] = game[i][j] + game[i][j];
                  score+= game[i][j] + game[i][j];
                now--;
                i--;
            } else {
                nextGame[now][j] = game[i][j];
                now--;
            }
        } 
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game[i][j] = nextGame[i][j];
        }
    }
	x();
    Print();

}
void left(){
	int nextGame[4][4]={};
	int now=0;
	for(int j=0;j<4;j++){
		now=0;
		for(int i=0;i<4;i++){
			if(game[j][i]!=0){
			nextGame[j][now]=game[j][i];
			now++ ;
			}
		}	
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			game[i][j]=nextGame[i][j];
		}
	}
		for (int j = 0; j < 4; j++) {
        now = 0;
        for (int i = 0; i <4;i++) {
            if (i + 1 < 4 && game[j][i] == game[j][i+1]&&game[j][i] !=0) {
                nextGame[j][now] = game[j][i] + game[j][i];
                  score+= game[j][i] + game[j][i];
                now++;
                i++;
            } else {
                nextGame[j][now] = game[j][i];
                now++;
            }
        } 
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game[i][j] = nextGame[i][j];
        }
    }
	x();
	Print();
	
}
void right(){
	

	int nextGame[4][4] = {};
    int now = 3;
    	for(int j=3;j>=0;j--){
		now=3;
		for(int i=3;i>=0;i--){
			if(game[j][i]!=0){
				nextGame[j][now]=game[j][i];
				now-- ;
			}
		}	
	}
	for(int i=3;i>=0;i--){
			for(int j=3;j>=0;j--){
			game[i][j]=nextGame[i][j];
		}	
	}
		for (int j = 0; j < 4; j++) {
        now = 3;
        for (int i = 3; i >= 0 ; i--) {
            if (i -1 > -1 && game[j][i] == game[j][i-1]&&game[j][i] != 0) {
                nextGame[j][now] = game[j][i] + game[j][i];
                score += game[j][i] + game[j][i];
                now--;
                i--;
            } else {
                nextGame[j][now] = game[j][i];
                now--;
            }
        } 
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game[i][j] = nextGame[i][j];
        }
    }

	x();
	Print();
	
}

int main(){
    srand(time(0));
    int x=rand()% ROW;
    int y=rand()% COL;
    game[x][y]=2;
    while (game[x][y]!=0){
        x=rand()% ROW;
        y=rand()% COL; 
    }
    game[x][y]=2;
    Print();
    char ch;
    PrintScore();
    while(cin>>ch){
    	system("CLS");
    	if(ch=='w'){
    		up();
		}
		if(ch=='s'){
			down();
		}
		if(ch=='a'){
			left();
		}
		if(ch=='d'){
			right();
		}
	PrintScore();
	}
}
