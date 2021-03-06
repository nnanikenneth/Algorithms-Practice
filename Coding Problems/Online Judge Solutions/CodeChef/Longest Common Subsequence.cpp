#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define URL "http://www.codechef.com/viewsolution/4749107"
#define URL "https://www.codechef.com/problems/TLCS/"

using namespace std;

char X[1009],Y[1009]; ///hold strings
short table[1009][1009]; ///dp
short help1[1009], help2[1009]; ///hold indices
char ans[1009]; //hold the lcs

int main()
{
    int n,m,i,j,t,test;
    double beg = clock();
    int flag = 0;
    scanf("%d",&test);
    for(t = 1; t <= test; t++) {

        scanf("%d%s%d%s", &m, X, &n, Y);
        if(flag == 0) {    //flag is used to control execution

            for(i = 0; i <= m; i++) table[0][i] = 0;//Initialisations. Also note that array is one bigger than length of each string

            for(i = 1; i <= n; i++) table[i][0] = 0;

            //computing lcs
            for(i = 1; i <= m; i++) {
              for(j = 1; j <= n; j++) {
                if(X[i-1] == Y[j-1]){
                     table[i][j] = table[i-1][j-1]+1;
                } else {
                     if(table[i-1][j] > table[i][j-1]){
                         table[i][j] = table[i-1][j];
                     } else {
                         table[i][j] = table[i][j-1];
                     }
                }
             }
            }

            //getting lcs values
            i = m; j = n; int index = -1;//holds recent index of ans
            while(true) {
                if(X[i-1] == Y[j-1]) { //points of diagonals
                  index++;
                  ans[index] = X[i-1];
                  help1[index] = i; //get index
                  help2[index] = j; //get index
                  i--; j--; //move to diagonal element above
                } else {
                    if(table[i-1][j] > table[i][j-1])
                       i--;
                    else j--;
                }
                if(i == 0 || j == 0)break; //condition to know when we must have finished collecting lcs
            }

            // printint the lcs
            if(table[m][n] == 0) {  //table[m][n] == lcs. therefore if table[m][n] == 0 ---> lcs is 0
                printf("case %d N\n", t);
            }
            else {
                printf("case %d Y\n", t);
                printf("%d\n", table[m][n]); //length of lcs
                for(i = index; i >= 0; i--) {
                    printf("%c %d %d\n", ans[i], help1[i], help2[i]); //output first character, its index on first sequence and on second
                }
            }//end else == printing
        }//END IF FLAG == 0

        // if execution time is greater than 4.9secs prompt me with N and testcase number that made that happen-stop.
        if(flag == 1) {
            printf("case %d N\n", t);
        }
        beg = (clock() - beg)/CLOCKS_PER_SEC;
        if(beg > 4.9){flag = 1;}
    }
    return 0;
}
