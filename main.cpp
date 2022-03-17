#include<iostream>
#include<algorithm>
#include<fstream>  

struct pair{
    int score = 0;
    int side = 0; //0,1,2,3 - zero,diag,top,left
    int x;
    int y;
};

// CHECK IF PAIR IS EQUAL
int checkPair(char c1, char c2){
    if(c1==c2){
        return 2;
    }
    else{
        return -1;
    }
}

// CHOOSE THE HIGHEST VALUE SIDE
int maxValue(int values[])
{
    if(values[1]>=values[0] && values[1]>=values[2] && values[1]>=values[3]){
        return 1;
    }
    else if(values[2]>=values[0] && values[2]>=values[3]){
        return 2;
    }
    else if(values[3]>=values[0] && values[3]>values[2]){
        return 3;
    }
    else{
        return 0;
    }
}

int main(){
    int n, m, score, diag, ins, del, temp;
    int values[4] = {};
    pair tempPair;
    tempPair.score = -1;
    std::string a, b;
    std::cin >> n;
    std::cin >> m;
    std::cin >> a;
    std::cin >> b;
    int maxSeq = m+n+2;
    int scoreList[maxSeq];
    std::string sequenceA, sequenceB;
    pair H[n+1][m+1] = {};

    // GENERATE SCORE MATRIX
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=m; j++){
            values[1] = H[i-1][j-1].score + checkPair(a[i-1], b[j-1]);
            values[2] = H[i-1][j].score-1;
            values[3] = H[i][j-1].score-1;
            temp = maxValue(values);
            H[i][j].score = values[temp];
            H[i][j].side = temp;
            H[i][j].x = i;
            H[i][j].y = j;
            if(values[temp] > tempPair.score){
                tempPair.score = values[temp];
                tempPair.side = temp;
                tempPair.x = i;
                tempPair.y = j;
            }
        }
    }

    std::ofstream outfile ("output.txt");

    // PRINT SCORE MATRIX
    for(int i = 0; i <=n; i++){
        for(int j = 0; j <=m; j++){
            outfile << H[i][j].score << " ";
        }
        outfile << std::endl;
    }

    outfile << std::endl << "max score: " << tempPair.score << std::endl;

    // GET SEQUENCES
    int tempScore = tempPair.score;
    int gapA = 0;
    int gapB = 0;
    int count = 0;
    while(tempScore != 0){
        scoreList[count] = tempPair.score;
        if(tempPair.side!=0){
            if(tempPair.side == 1){
                sequenceB = sequenceB + b[tempPair.y-1];
                sequenceA = sequenceA + a[tempPair.x-1];
                tempPair.x--;
                tempPair.y--;
            }
            else if(tempPair.side == 2){
                sequenceB = sequenceB + '_';
                sequenceA = sequenceA + a[tempPair.x-1];
                tempPair.x--;
            }
            else if(tempPair.side == 3){
                sequenceB = sequenceB + b[tempPair.y-1];
                sequenceA = sequenceA + '_';
                tempPair.y--;
            }
            else{
                std::reverse(sequenceA.begin(), sequenceA.end());
                std::reverse(sequenceB.begin(), sequenceB.end());
                outfile << "sequenceA:  " << sequenceA << std::endl << "sequenceB:  " << sequenceB << std::endl;
                outfile.close();
                return 1;
            }
            tempPair.side=H[tempPair.x][tempPair.y].side;
            tempPair.score=H[tempPair.x][tempPair.y].score;
        }
        else{
            std::reverse(sequenceA.begin(), sequenceA.end());
            std::reverse(sequenceB.begin(), sequenceB.end());
            outfile << "sequenceA:  " << sequenceA << std::endl << "sequenceB:  " << sequenceB << std::endl;
            outfile.close();
            return 1;
        }
        count++;
    }
}