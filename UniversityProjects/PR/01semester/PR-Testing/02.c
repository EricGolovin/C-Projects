#include <stdio.h>

#ifdef MAC
#define M 5
#endif
#define MAC

int main(void) {
	#if defined(M)
		printf("MAC1");
	#endif
	#if defined(MAC)
		printf("MAC2");
	#endif
	
	#define MAC "MAC3"
	
	#if defined(MAC)
	printf("%s", MAC);
	#endif

	return 0;
}	

