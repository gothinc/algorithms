#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define MAXV 10000

int v[MAX], w[MAX];
int d[MAX][MAXV];
int s[MAX];

int
main(int argc, char *argv[]){
	FILE *in, *out;
	int n, volume, i, j;

	memset(s, 0, sizeof(s));

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

		for(j = volume, i = n - 1; i > 0; i --){
			if(d[i][j] > d[i - 1][j]){
				printf("volume:%d value:%d\n", v[i], w[i]);
				j -= v[i];
			}
		}

		if(d[i][j] == w[i]) printf("volume:%d value:%d\n", v[i], w[i]);

		printf("count:%d\n", d[n - 1][volume]);
		printf("-------------------\n");

		scanf("");
	}
}
