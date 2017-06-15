#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>

static int bssvar; 

int main(void)
{
	char *pmem;
	long heap_gap_bss;
	printf("end of bss section:%p\n", (long)&bssvar + 4);
	pmem = (char *)malloc(32);
	if(pmem == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	printf("pmem:%p\n", pmem);
	heap_gap_bss = (long)pmem - (long)&bssvar - 4;
	printf("1-gap between heap and bss:%lu\n", heap_gap_bss);
	printf("brk_start_1 %p\n", (int *)sbrk(0)); 
	free(pmem);
	//sbrk(2);
	printf("brk_start_2 %p\n", (int *)sbrk(0));
	pmem = (char *)malloc(32);
	printf("brk_start_3 %p\n", (int *)sbrk(0));
	if(pmem == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	printf("pmem:%p\n", pmem);
  printf("gap between heap and block %lu\n",(char *)sbrk(0) - pmem);
	heap_gap_bss = (long)pmem - (long)&bssvar - 4;
	printf("2-gap between heap and bss:%lu\n", heap_gap_bss);
	free(pmem);
	return 0;
}
