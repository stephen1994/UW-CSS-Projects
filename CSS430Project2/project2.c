/**
 * Author: Stephen Choi
 * Last modification date: April 23rd, 2020
 * CSS 430 Project2
 * Professor Jim Hogg
 */
 
 #include <stdio.h>
 #include <stdlib.h> 
 #include <assert.h>
 #include <iostream>
 #include <pthread.h>
 #include <unistd.h>
 
 // structure for passing data to threads
typedef struct
{
    int row;	
    int column;
	
} parameters;
    
	// thread declarations 
    pthread_t thread_column;
	pthread_t thread_row;	
	pthread_t thread_first, thread_second, thread_third, thread_fourth, thread_fifth;
	pthread_t thread_sixth, thread_seventh, thread_eighth, thread_ninth;

// 2D array Sudoku
int sudoku[9][9] =
    {
            {6, 2, 4, 5, 3, 9, 1, 8, 7},
            {5, 1, 9, 7, 2, 8, 6, 3, 4},
            {8, 3, 7, 6, 1, 4, 2, 9, 5},
            {1, 4, 3, 8, 6, 5, 7, 2, 9},
            {9, 5, 8, 2, 4, 7, 3, 6, 1},
            {7, 6, 2, 3, 9, 1, 4, 5, 8},
            {3, 7, 1, 9, 5, 6, 8, 4, 2},
            {4, 9, 6, 1, 8, 2, 5, 7, 3},
            {2, 8, 5, 4, 7, 3, 9, 1, 6}
     };

// --------------------------------validateRow-------------------------------------- -
// Description
// validateRow: validate function for the rows
// predonditions: NONE
// postconditions: validate each row, print out row #, sum and validation  
// ----------------------------------------------------------------------------------
void *validateRow(void * params){
	
	sleep(1); 
	// array of sum to store each sum of row
	int sum[9] = {0};
	
	parameters * param = (parameters *) params;
	int paramRow = param->row;
	int paramCol = param->column;
	
	for(int i = paramRow; i < 9; i++){
		for(int j = paramCol; j < 9; j++){
		// sum of row 
		sum[i] += sudoku[i][j];		
		}
    printf("   Row #%d                %d", i+1,  sum[i]);
		if(sum[i] != 45){
		   //print Fail in Red
			printf("\033[1;31m");
			printf("                Fail\n");	
			printf("\033[0m");
		}else{
			//print Success in green
			printf("\033[1;32m");
			printf("              Success\n");
			printf("\033[0m");
		
		}
	}
	
    return NULL; 
}	

// --------------------------------validateColumn-------------------------------------- -
// Description
// validateColumn: validate function for the columns
// predonditions: NONE
// postconditions: validate each column, print out column #, sum and validation  
// ----------------------------------------------------------------------------------
void *validateColumn(void * params){
	
	sleep(1); 
	// array of sum to store each sum of column
	int sum[9] = {0};	
	parameters * param = (parameters *) params;
	int paramRow = param->row;
	int paramCol = param->column;

	for(int i = paramCol; i < 9; i++){
		for(int j = paramRow; j < 9; j++){
		// sum of column 
		sum[i] += sudoku[j][i];	
		}
    printf("   Col #%d                %d", i+1,  sum[i]);
		if(sum[i] != 45){
		    //print Fail in Red
			printf("\033[1;31m");
			printf("                Fail\n");	
			printf("\033[0m");
		}else{
			//print Success in green
			printf("\033[1;32m");
			printf("              Success\n");
			printf("\033[0m");
		}
	}
	
    return NULL; 
}	

// --------------------------------validateBox-------------------------------------- -
// Description
// validateColumn: validate function for the grid boxes
// predonditions: NONE
// postconditions: validate each grid box, print out box #, sum and validation  
// ----------------------------------------------------------------------------------
void *validateBox(void * params){
	
    sleep(1);

	int sum = 0;
	bool validated = true;
	int boxNumber[3][3]= {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	
	parameters * param = (parameters *) params;
	int paramRow = param->row;
	int paramCol = param->column;
	
	int a = paramRow;
	int b = paramCol;
	int ROW = paramRow + 3;
	int COL = paramCol + 3;
	
	for(int i = paramRow; i < ROW; i++){
		for(int j = paramCol; j < COL; j++){
		sum += sudoku[i][j];
	    }
	}	
	printf("   Box #%d                %d", boxNumber[a/3][b/3],  sum);
	if(sum != 45){
			// print out Fail in red
			printf("\033[1;31m");
			printf("                Fail\n");	
			printf("\033[0m");
	}else{		
		    //print Success in green
			printf("\033[1;32m");
			printf("              Success\n");
			printf("\033[0m");
	}
	return NULL;
}	


int main(){
	
	printf("Line/Subgrid            Sum             Validation\n");
	printf("-----------------------------------------------------------------\n");
    
	// columns
	parameters *columns = (parameters *) malloc(sizeof(parameters));
    columns->row = 0;
    columns->column = 0;
	
	// rows
	parameters *rows = (parameters *) malloc(sizeof(parameters));
    rows->row = 0;
    rows->column = 0;
	
	parameters *first = (parameters *) malloc(sizeof(parameters));
    first->row = 0;
    first->column = 0;
	
	parameters *second = (parameters *) malloc(sizeof(parameters));
    second->row = 3;
    second->column = 0;
	
	parameters *third = (parameters *) malloc(sizeof(parameters));
    third->row = 6;
    third->column = 0;
	
	parameters *fourth = (parameters *) malloc(sizeof(parameters));
    fourth->row = 0;
    fourth->column = 3;
	
	parameters *fifth = (parameters *) malloc(sizeof(parameters));
    fifth->row = 3;
    fifth->column = 3;
	
	parameters *sixth = (parameters *) malloc(sizeof(parameters));
    sixth->row = 6;
    sixth->column = 3;
	
	parameters *seventh = (parameters *) malloc(sizeof(parameters));
    seventh->row = 0;
    seventh->column = 6;
	
	parameters *eighth = (parameters *) malloc(sizeof(parameters));
    eighth->row = 3;
    eighth->column = 6;
	
	parameters *ninth = (parameters *) malloc(sizeof(parameters));
    ninth->row = 6;
    ninth->column = 6;
    
	// Now create the thread passing it data as a parameter 
	void *colReturn;
	void *rowReturn;
	void *firstReturn;
	void *secondReturn, *thirdReturn, *fourthReturn, *fifthReturn, *sixthReturn, *seventhReturn, *eighthReturn, *ninthReturn;
	
	//  (pointer to thread, attributes, name of function to be executed, 
	//  arguments to the funcion)
    pthread_create(&thread_row, NULL, validateRow, (void *) columns);
	pthread_create(&thread_column, NULL, validateColumn, (void *) rows);
	pthread_create(&thread_first, NULL, validateBox, (void *) first);
	pthread_create(&thread_second, NULL, validateBox, (void *) second);
	pthread_create(&thread_third, NULL, validateBox, (void *) third);
	pthread_create(&thread_fourth, NULL, validateBox, (void *) fourth);
	pthread_create(&thread_fifth, NULL, validateBox, (void *) fifth);
	pthread_create(&thread_sixth, NULL, validateBox, (void *) sixth);
	pthread_create(&thread_seventh, NULL, validateBox, (void *) seventh);
	pthread_create(&thread_eighth, NULL, validateBox, (void *) eighth);
	pthread_create(&thread_ninth, NULL, validateBox, (void *) ninth);
     
	// equivalent of wait() for processes, blocks the calling
	// thread until the thread with identifier
	// equal to the first argument terminates.
	pthread_join(thread_row, &colReturn);
	pthread_join(thread_column, &rowReturn);
	pthread_join(thread_first, &firstReturn);
	pthread_join(thread_second, &secondReturn);
	pthread_join(thread_third, &thirdReturn);
	pthread_join(thread_fourth, &fourthReturn);
	pthread_join(thread_fifth, &fifthReturn);
	pthread_join(thread_sixth, &sixthReturn);
	pthread_join(thread_seventh, &seventhReturn);
	pthread_join(thread_eighth, &eighthReturn);
	pthread_join(thread_ninth, &ninthReturn);

	printf("-----------------------------------------------------------------\n");
	
	return 0;
}	