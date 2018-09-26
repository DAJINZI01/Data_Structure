#include <stdio.h>

#define MAXN 1001
#define MINH -10001

int H[MAXN], size;

void Create(){
	size = 0;
	H[0] = MINH; /*设置“哨兵”*/	
}

void insert(int X){
	/*将X插入H，这里省略检查堆是否已满的代码*/
	int i;
	for(i = ++size; H[i/2] > X; i /= 2)/*判别的起点为++size, i 上移*/
		H[i] = H[i/2];/*将父节点移下来*/
	H[i] = X;
}




int main()
{
	int n, m, x, i, j;

	return 0;
}
