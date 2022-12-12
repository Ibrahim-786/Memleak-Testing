#include"library.h"



void definitely_lost(){
	

	printf("definitely lost: 40 bytes in 1 blocks\n");
	printf("#############################\n");

	int *ptr=(int*)calloc(10,sizeof(int));


	for(int i=0; i<10; i++){
		ptr[i] = 12;
	}

	for(int j=0; j<10; j++){
		printf("%d ",ptr[j]);

	}

	//free(ptr);
}


void indirectly_lost()
{
	printf("\n");


	printf("#############################\n\n");

	printf("definitely lost: 40 bytes in 1 blocks\n");
	printf("indirectly lost: 200 bytes in 5 blocks\n");
	printf("#############################\n");

	int **pt = (int**)calloc(5,sizeof(int*));

	for(int i=0; i<5; i++){
		pt[i]= (int*)calloc(10,sizeof(int));
	}

	for(int i=0;i<5;i++){
		for(int j=0; j<10;j++){
			pt[i][j] = 50;
		}
	}


	printf("#############################\n\n");


	for(int i=0; i<5;i++){
		//free(pt[i]);
	}

	//free(pt);

}



void possible_lost()
{


	printf("possible lost: 40 bytes in 1 blocks\n");

	int *ptr = (int*)malloc(10*sizeof(int));
	int count =1;


	for(int i=0; i<10;i++){
		ptr[i] = 20;
	}

   // move the pointer into the array
  // we know we can reset the pointer by subtracting
  // but for valgrind the array is now lost

	ptr++;


	if(count = 1)
	{
		// exit/crash the program
		//due to these librcheck does't create trace file
		printf("due to exit() or abort(), librcheck does't create trace file please see valgrind output\n");
		exit(1);
		//abort();
	}

	else{
		 // reset the pointer to the beginning of the array
		ptr--;

		// properly free the memory for the array
		free(ptr);

		return;
	}

}




