#include <stdio.h>
#include <stdlib.h>

int main () {
	int n;
	printf("Input number of page frames:\n");
	scanf("%d", &n);

	//referenced-bit
	char* R_bit = (char*)calloc(n, 1);
	//age of page
	unsigned short* age = (unsigned short*)calloc(n, sizeof(unsigned short));
	//imitation of MMU present-bit
	char* MMU_present_bit = (char*)calloc(1000, 1);
	//imitation of MMU page table
	char* MMU_page_table = (char*)calloc(1000, 1);
	//which page stored in this page frame
	short* stored_page = (short*)calloc(n, sizeof(short));
	//used - number of pages in memory
	//tick - time that past
	int used = 0, tick = 0;
	//current referenced page
	int current_page;
	FILE * input = fopen("input.txt", "r");
	int hits = 0, misses = 0;
	while(fscanf(input, "%d", &current_page) != EOF) {
		// printf("%d\n", current_page);
		tick++;
		if (MMU_present_bit[current_page]) {
			//if this page is present in page table do nothing, we hitted
			hits++;
		} else {
			misses++;
			//otherwise if there are free slots
			if (used < n) {
				//we store this page into this slot
				MMU_present_bit[current_page] = 1;
				MMU_page_table[current_page] = used;
				stored_page[used++] = current_page;
			} else {
				//otherwise search for table with lowest age
				int min = 0;
				for (int i = 1; i < n; ++i) {
					if (age[i] < age[min]) {
						min = i;
					} else {
						if (age[i] == age[min] && R_bit[i] < R_bit[min]) {
							min = i;
						}
					}
				}
				//and replace it
				age[min] = 0;
				MMU_present_bit[stored_page[min]] = 0;
				stored_page[min] = current_page;
				MMU_present_bit[current_page] = 1;
				MMU_page_table[current_page] = min;
			}
		}
		//mark curent page as referenced
		R_bit[MMU_page_table[current_page]] = 1;
		if (tick % (n / 10) == 0) {
			//every n / 10 ticks perform computing age for stored pages
			//also clear R bits
			for (int i = 0; i < n; ++i) {
				age[i]>>=1;
				age[i] += R_bit[i] << 8 * sizeof(unsigned short);
				R_bit[i] = 0;
			}
		}
	}
	//as the number of page frames increases we obtain higher hit/miss ratio
	printf("%f\n", 1. * hits / misses);
	return 0;
}