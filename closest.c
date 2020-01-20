#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int buscaBin (int ini, int end, int val, int v[]) {
	if (ini > end) return -1;
	
	if (ini == end) {
		if (v[ini] == val) return ini;
		else  return -1;
	}
	
	int meio = (ini + end) / 2;
	
	if (v[meio] < val) return buscaBin(meio + 1, end, val, v);
	else if (v[meio] == val) return buscaBin(ini, meio, val, v);
	else return buscaBin(ini, meio - 1, val, v);
}

int main () {
	
	FILE * fp;
	fp = freopen("input1.txt", "r", stdin);
	
	if (fp != NULL) {
		
		char aux[15];
		memset(aux, 0, 15);
		
		fgets(aux, 5, fp);		
		int test_cases = strtol(aux, NULL, 10);
		
		int n, k;
		fgets(aux, 15, fp);
		sscanf(aux, "%d %d", &n, &k);
		printf("n %d, k %d\n", n, k);
		
		int buf[n];
		int temp[n*6];
		memset(buf, 0, n);
		memset(temp, 0, n*6);
		
		int i;
		char *pEnd;
		fgets(temp, n * 6, fp);
		//printf("%s\n", buf);
		for (i = 0; i < n; i++) {
			buf[i] = strtof(temp, &pEnd);
			memcpy(temp, &pEnd[1], strlen(pEnd));
			printf("%d ", buf[i]);
		}
		
		
		printf("\nBusca 1 %d\n", buscaBin(0, n, k, buf));
		
		
		
	}
	
	return (0);
}
