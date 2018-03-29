// uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=44
#include<bits/stdc++.h>
#define clr(v, d) memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
int A[100+9][100+9];
int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                scanf("%d", &A[i][j]);
                if (i > 0) A[i][j] += A[i - 1][j]; // if possible, add from top
                if (j > 0) A[i][j] += A[i][j - 1]; // if possible, add from left
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1]; // avoid double count
            }
        int maxSubRect = -127*100*100; // the lowest possible value for this problem
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) // start coordinate
                for (int k = i; k < n; k++)
                    for (int l = j; l < n; l++) { // end coord
                        int subRect = A[k][l]; // sum of all items from (0, 0) to (k, l): O(1)
                        if (i > 0) subRect -= A[i - 1][l]; // O(1)
                        if (j > 0) subRect -= A[k][j - 1]; // O(1)
                        if (i > 0 && j > 0) subRect += A[i - 1][j - 1]; // O(1)
                        maxSubRect = max(maxSubRect, subRect); } // the answer is here
        printf("%d\n",maxSubRect);



    }
    return 0;
}
