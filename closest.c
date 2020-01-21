#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://github.com/alura-cursos/maratonaprogramacao/blob/aula4-exc/find.cpp
int buscaBin (int ini, int end, int val, int v[]) {	
	if (ini == end) {
		return ini;
	}
	
	int meio = (ini + end + 1) / 2;
	
	if (v[meio] <= val) {
		return buscaBin(meio, end, val, v);
	} else {
		return buscaBin(ini, meio - 1, val, v);
	}
}

int main () {
	
	FILE * fp;
	fp = freopen("input1.txt", "r", stdin);
	
	if (fp != NULL) {
		
		char aux[15];
		memset(aux, 0, 15);
		
		fgets(aux, 5, fp);		
		int test_cases = strtol(aux, NULL, 10);
		
		while (test_cases--) {
			int n, k;
			fgets(aux, 15, fp);
			sscanf(aux, "%d %d", &n, &k);
			//printf("n %d, k %d\n", n, k);
			
			int buf[n];
			char temp[n*6];
			memset(buf, 0, n);
			memset(temp, 0, n*6);
			
			int i;
			char *pEnd;
			fgets(temp, n * 6, fp);
			//printf("%s\n", buf);
			for (i = 0; i < n; i++) {
				buf[i] = strtof(temp, &pEnd);
				memcpy(temp, &pEnd[1], strlen(pEnd));
				//printf("%d ", buf[i]);
			}
			
			int pos = buscaBin(0, n, k, buf);
			//printf("\nBusca val prox. de %d: v[%d]=%d\n", k, pos, buf[pos]);
			
			if (k - buf[pos] < buf[pos + 1] - k)
				printf("%d\n", buf[pos]);
			else
				printf("%d\n", buf[pos + 1]);
		}
	}
	
	return (0);
}
