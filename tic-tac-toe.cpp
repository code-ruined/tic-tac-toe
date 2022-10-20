#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
vector<pair<int,int>> index;
void startGame(){
index.pb(mp(-1,-1));
index.pb(mp(0,0));
index.pb(mp(0,2));
index.pb(mp(0,4));
index.pb(mp(1,0));
index.pb(mp(1,2));
index.pb(mp(1,4));
index.pb(mp(2,0));
index.pb(mp(2,2));
index.pb(mp(2,4));
}
bool isTaken[10]={0};
char temp[3][5]={
{'1','|','2','|','3'},
{'4','|','5','|','6'},
{'7','|','8','|','9'},
};
char grid[3][5]={
{' ','|',' ','|',' '},
{' ','|',' ','|',' '},
{' ','|',' ','|',' '},
};

void printGrid(){
cout<<"\n";
for(int i=0;i<3;i++){
    cout<<"\t\t";
    for(int j=0;j<5;j++){
        cout<<grid[i][j]<<" ";
    }
    if(i!=2)cout<<"\n\t\t--+---+--\n";
}
cout<<"\n";
}

void printTemp(){
cout<<"\n";
for(int i=0;i<3;i++){
    cout<<"\t\t";
    for(int j=0;j<5;j++){
        cout<<temp[i][j]<<" ";
    }
    if(i!=2)cout<<"\n\t\t--+---+--\n";
}
cout<<"\n";
}


int randomMove(){
    int x = rand() % 8 + 1;
    while(isTaken[x]){
        x = rand() % 8 + 1;
    }
    return x;
}

void makeMove(int m,char x){
    grid[index[m].F][index[m].S]=x;
    isTaken[m]=1;
}

char Winner(){
   char x=' ';
   int row[3]={2,5,8};
   int column[3]={4,5,6};
   for(int i=0;i<3;i++){
    if(grid[index[row[i]].F][index[row[i]].S]==grid[index[row[i]-1].F][index[row[i]-1].S]&&
       grid[index[row[i]].F][index[row[i]].S]==grid[index[row[i]+1].F][index[row[i]+1].S]){
            x=grid[index[row[i]].F][index[row[i]].S];
            if(x!=' ') break;
       }
   }

   if(x!=' ') return x;

   for(int i=0;i<3;i++){
    if(grid[index[column[i]].F][index[column[i]].S]==grid[index[column[i]-3].F][index[column[i]-3].S]&&
       grid[index[column[i]].F][index[column[i]].S]==grid[index[column[i]+3].F][index[column[i]+3].S]){
            x=grid[index[column[i]].F][index[column[i]].S];
            if(x!=' ') break;
       }
   }

   if(x!=' ') return x;

    if(grid[index[5].F][index[5].S]==grid[index[3].F][index[3].S]&&
       grid[index[5].F][index[5].S]==grid[index[7].F][index[7].S]){
            x=grid[index[5].F][index[5].S];
       }

    if(grid[index[5].F][index[5].S]==grid[index[1].F][index[1].S]&&
       grid[index[5].F][index[5].S]==grid[index[9].F][index[9].S]){
            x=grid[index[5].F][index[5].S];
       }

    return x;

}


int Menu(){
    int x;
    cout<<"Select game type : \n";
    cout<<"1.Human v/s Human\n";
    cout<<"2.Human v/s Computer\n";
    // cout<<"Computer[Hard]\n"; future scope

    cout<<"\nEnter your choice : ";
    cin>>x;

    return x;
}


void playGame(int type,string player[]){
    cout<<"\n          ------------------- "<<player[0]<<" v/s "<<player[1]<<" -------------------\n";
    int t=9,m;
    printTemp();
    char x,w;
    bool draw=true;
    while(t--){
        printGrid();
        w=Winner();
        if(w!=' '){
            if(w=='X') cout<<"\n"<<player[0]<<" Won!\n";
            else cout<<"\n"<<player[1]<<" Won!\n";
            draw=false;
            break;
        }
        again:
        cout<<"\n"<<player[t%2]<<"'s move : ";
        if(player[t%2] == "Computer") m = randomMove();
        else cin>>m;
        if(m>9||isTaken[m]){
            if(m>9) cout<<"\nInvalid position. ";
            else cout<<"\nPosition already taken. ";
            cout<<"Select another position\n";
            goto again;
        }
        x=(t%2)?'O':'X';
        makeMove(m,x);
    }
    if(draw) cout<<"\nIts a draw!\n";
}


int main(){
startGame();

string player[2];

int x = Menu();

if(x == 1){
    cout<<"Enter player 1 name : "; cin>>player[0];
    cout<<"\n";
    cout<<"Enter player 2 name : "; cin>>player[1];
    playGame(1,player);
}
else if(x == 2){
    cout<<"Enter player name : "; cin>>player[0];
    player[1] = "Computer";
    playGame(2,player);
}
else{

}

return 0;
}