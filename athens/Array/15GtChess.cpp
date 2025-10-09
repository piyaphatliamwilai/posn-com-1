#include <iostream>
using namespace std;
string arrboard[8][8];
int ki, kj, Ki, Kj;
// bool foundk = false;
// bool foundK = false;


void findk(){
    ki = kj = -1;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arrboard[i][j] == "k"){
                ki = i, kj = j;
            }
        }
    }
}

void findK(){
    Ki = Kj = -1;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arrboard[i][j] == "K"){
                Ki = i, Kj = j;
            }
        }
    }
}


bool rookCheck(string attack, int ty, int tx){
    for(int y=0; y<8; y++){
        for(int x=0; x<8; x++){
            if(arrboard[y][x] == attack){
                int Ry = y, Rx = x;

                //check right
                for(int j = Rx + 1; j < 8; j++){
                    if(Ry == ty && j == tx) return true;
                    if(arrboard[Ry][j] != ".") break;
                }
                //check left
                for(int j=Rx-1; j>=0; j--){
                    if(Ry==ty && j==tx) return true;
                    if(arrboard[Ry][j] != ".") break;
                }

                //check down
                for(int i=Ry+1; i<8; i++){
                    if(i==ty && Rx==tx) return true;
                    if(arrboard[i][Rx] != ".") break;
                }
                //check up
                for(int i=Ry-1; i>=0; i--){
                    if(i==ty && Rx==tx) return true;
                    if(arrboard[i][Rx] != ".") break;
                }
                
                
            }
        }
    }
    return false;
    
}
bool bishopCheck(string attack, int ty, int tx){
    for(int y=0; y<8; y++){
        for(int x=0; x<8; x++){
            if(arrboard[y][x] == attack){
                int By = y, Bx = x;
                //check downright
                for(int j=Bx+1, i=By+1; j<8 && i<8; j++,i++){ 
                    if(i==ty && j==tx) return true;
                    if(arrboard[i][j]!=".") break;
                }
                //check downleft
                for(int j=Bx-1, i=By+1; i<8 && j>=0; j--, i++){
                    if(i==ty && j==tx) return true;
                    if(arrboard[i][j]!=".") break;
                }
                //check upright
                for(int i=By-1, j=Bx+1; i>=0 && j<8; i--, j++){
                    if(i==ty && j==tx) return true;
                    if(arrboard[i][j]!=".") break;
                }
                //check upleft
                for(int i=By-1, j=Bx-1; i>=0 && j>=0; i--, j--){
                    if(i==ty && j==tx) return true;
                    if(arrboard[i][j]!=".") break;
                }
            }
            
        }
    }
    return false;

}
//use n
bool knightCheck(string attack, int ty, int tx){
    for(int y=0; y<8; y++){
        for(int x=0; x<8; x++){
            if(arrboard[y][x] == attack){
                //check up <-->
                if((y==ty-2&&x==tx+1) || (y==ty-2&&x==tx-1)) return true;
                //check down <-->
                if((y==ty+2&&x==tx+1) || (y==ty+2&&x==tx-1)) return true;
                //check left
                if((x==tx-2&&y==ty-1) || (x==tx-2&&y==ty+1)) return true;
                //check right
                if((x==tx+2&&y==ty-1) || (x==tx+2&&y==ty+1)) return true;

            }
        }
    }
    return false;
}
bool queenCheck(string attack, int ty, int tx){
    for(int y=0; y<8; y++){
        for(int x=0; x<8; x++){
            if(arrboard[y][x]==attack){
                return bishopCheck(attack, ty, tx) || rookCheck(attack, ty, tx);
            }
        }
    }
    return false;
}
bool whitePawn(string attack, int ty, int tx){
    for(int y=0; y<8; y++){
        for(int x=0; x<8; x++){
            if(arrboard[y][x]==attack){
                if((y-1==ty && x-1==tx) || (y-1==ty && x+1==tx)) return true;
            }
        }
    }
    return false;
}

bool blackPawn(string attack, int ty, int tx){
    for(int y=0; y<8; y++){
        for(int x=0; x<8; x++){
            if(arrboard[y][x]==attack){
                if((y+1==ty&&x-1==tx)||(y+1==ty&&x+1==tx)) return true;
            }
        }
    }
    return false;
}



int main(){
    int t; cin >> t;
    while(t--){
        for(int i=0; i<8; i++){
            string row;
            cin >> row;
            for(int j=0; j<8; j++){
                arrboard[i][j] = string(1, row[j]);
            }
        }
        findk();
        findK();
        
        //k == black
        string s = "";
        if(rookCheck("R", ki, kj)) cout << "R check black king." << endl;
        else if (bishopCheck("B", ki, kj)) cout << "B check black king." << endl;
        else if(knightCheck("N", ki, kj)) cout << "N check black king." << endl;
        else if (queenCheck("Q", ki, kj)) cout << "Q check black king." << endl;
        else if (whitePawn("P", ki, kj)) cout << "P check black king." << endl;
        
        else if(rookCheck("r", Ki, Kj)) cout << "r check white king." << endl;
        else if(bishopCheck("b", Ki, Kj)) cout << "b check white king." << endl;
        else if(knightCheck("n", Ki, Kj)) cout << "n check white king." << endl;
        else if(queenCheck("q", Ki, Kj)) cout << "q check white king." << endl;
        else if(blackPawn("p", Ki, Kj)) cout << "p check white king." << endl;
        else cout << "No king is in check." << endl;
        // bool foundk = rookCheck("R", ki, kj) || bishopCheck("B", ki, kj) || 
        // knightCheck("N", ki, kj) || queenCheck("Q", ki, kj) || whitePawn("P", ki, kj);
        // bool foundK = rookCheck("r", Ki, Kj) || bishopCheck("b", Ki, Kj) || 
        // knightCheck("n", Ki, Kj) || queenCheck("q", Ki, Kj) || blackPawn("p", Ki, Kj);
        //K == white

        // if(foundk || foundK) cout << "1" << endl;
        // else cout << "2" << endl;
        //??? check black king.
        //No king is in check.
        //??? check white king.

    }

    return 0;
}

