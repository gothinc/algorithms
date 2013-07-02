#include <stdio.h>

#define MAX 1000
#define MAXV 10000

int v[MAX], w[MAX];
int d[MAX][MAXV];

int
main(int argc, char *argv[]){
	FILE *in, *out;
	int n, volume, i, j;
	in = freopen("in.txt", "r", stdin);
	out = freopen("out.txt", "w", stdout);

	while(scanf("%d %d", &n, &volume) != EOF){
		for(i = 0; i < n; i ++) scanf("%d %d", &v[i], &w[i]);

		for(i = 0; i < n; i ++){
			for(j = 0; j <= volume; j ++){
				if(i == 0){
					d[i][j] = j >= v[i] ? w[i] : 0;
				}else{
					if(v[i] > j){
						d[i][j] = d[i - 1][j];
					}else{
						d[i][j] = d[i - 1][j] > (d[i - 1][j - v[i]] + w[i]) ? d[i - 1][j] : (d[i - 1][j - v[i]] + w[i]);
					}
				}
			}
		}

		printf("%d\n", d[n - 1][volume]);

		scanf("");
	}
}
