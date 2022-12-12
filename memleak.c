#include"library.h"

#define SUPPORTED_OPTIONS "h:dip"



int main(int argc,char **argv){

		printf("hello world\n");

		printf("before libfoo.so\n");

		if(argc < 2){
		    printf("Usage:\n");
                             
            printf("-d                          directly_lost()\n");
            printf("-i                          indirectly_lost()\n");
            printf("-p                          indirectly_lost()\n");
		}


		int opt;

		while ((opt = getopt(argc, argv, SUPPORTED_OPTIONS)) != -1) {
        switch (opt) {
            case 'h':
            	printf("Usage:\n");
                             
                printf("-d                          directly_lost()\n");
                printf("-i                          indirectly_lost()\n");
                printf("-p                          indirectly_lost()\n");
                break;
            case 'd':
               definitely_lost();
                break;
            case 'i':
                indirectly_lost();
                break;
            case 'p':
                possible_lost();
                break;
                         
            default:
                printf("Usage:\n");
                               
                printf("-d                          directly_lost\n");
                printf("-i                          indirectly_lost()\n");
                printf("-p                          indirectly_lost()\n");
                exit (EXIT_FAILURE);
                break;
        }
    }

		printf("after libfoo.so\n");


  return 0;


}