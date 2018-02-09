#include "mostuse_hd.h"
/*
gcc -E test.c -o test.i
gcc test.c get_num.c
*/
int main(int argc, char* argv[]){

	int m = 1;
	int n = 2;
	int max = max(1, 2);
	printf("%d\n", max);

	int i = getInt("12", 10, "tests");
	printf("%d\n", i);
	return 0;
}
