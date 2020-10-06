#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//swpd stays the same
//free decreases
//buff and cache stays the same

//however, at some moment "so" became large and 
//swpd increased
//free increased
//buff and cache decreased

//after the program finished free significantly increased

int main () {
	for (int i = 0; i < 10; ++i) {
		void* a = malloc(10*1024*1024);
		memset(a, 0, 10*1024*1024);
		sleep(1);
	}
}

//for ex 3:
//VIRT and RES are increasing through running time
//SHR stays the same
//CPU usage about 0.7
//MEM increases up to 10.3