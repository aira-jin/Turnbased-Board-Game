#include <stdio.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0

#define MAX 9
#define maxNUM 3

typedef struct {
	int x, y;
} orderedPairType;

typedef struct {
	int One[MAX], Two[MAX], Three[MAX], Four[MAX], Five[MAX], Six[MAX];
} WType;

int linearSearchINT(int key, int n[MAX], int num) 
{
  int found = 0;
  int i = 0;

while (found == 0 && i < num) {
    if (n[i] == key) {
      found = 1;
   	}
    i++;
}
 	if (found == 0)
 		return -1;
 	else
  		return i-1;
}

void Display(int peg, int UnionNUM[MAX], int BoxPeg[MAX], orderedPairType BoardPos[MAX], orderedPairType Free[MAX], int Peg[MAX], int PegMAIN[MAX], orderedPairType FreeMAIN[MAX]) 
{
    int i, n, index = 0;

    printf("+---+---+---+\n");
    printf("|");

    for (i = 0; i < 9; i++) {
    	if ( BoardPos[i].x != FreeMAIN[i].x && BoardPos[i].y != FreeMAIN[i].y ) {
    		printf(" %d |", UnionNUM[index++] );
    		
		}
        	
        else
        	printf(" X |");

        if ((i + 1) % 3 == 0) {
            printf("\n+---+---+---+");
            if (i != 8) {
                printf("\n|");
            }
        }
    }

    printf("\n");
    printf("\n");
    
    printf("+---+---+---+---+---+---+---+---+---+\n");
    printf("|");

    for (i = 0; i < 9; i++) {
    	if ( PegMAIN[i] == BoxPeg[i] )
    		printf(" %d |", PegMAIN[i]);
        else
        	printf(" X |");
    }

    printf("\n+---+---+---+---+---+---+---+---+---+\n");

}



int linearSearchOP(orderedPairType key, orderedPairType Free[MAX], int numFree) 
{
  int found = 0;
  int i = 0;

while (found == 0 && i < numFree) {
    if (key.x == Free[i].x && key.y == Free[i].y) {
      found = 1;
   	}
    i++;
}

  	if (found == 0)
 		return -1;
 	else
  		return i-1;
}

int addOcc ( orderedPairType pos, orderedPairType Occ[MAX], int nOcc ) 
{
	Occ[nOcc].x = pos.x;
	Occ[nOcc].y = pos.y;
	nOcc++;
	
	return nOcc;
}

int checkOneRow (orderedPairType pos, orderedPairType row[MAX])
{
  int i;
  int found = 0;
  while (i<MAX && found == 0) {
    if (row[i].x == pos.x && row[i].y == pos.y)
      found = 1;
    i++;
  }
  	
  return found;
}

char checkRow ( orderedPairType pos, orderedPairType row1[MAX],  orderedPairType row2[MAX], orderedPairType row3[MAX] )
{
  int i;
  int found = 0;
  
    found = checkOneRow(pos, row1);
    if (found)
      return 'T';
    else {
      found = checkOneRow(pos, row2);
      if (found)
        return 'M';
      else
        return 'B';
    }
}


int removeElement(int arr[], int size, int index) {
    int i;

    // Shift all the elements after the element to remove one position to the left
    for (i = index; i <size - 1; i++) {
        arr[i] = arr[i+1];
    }

    // Decrement the size of the array
    return size-1;
}

int removeOrderedPair(orderedPairType pos, orderedPairType Free[MAX], int nFree) 
{
    int i = 0;
    int found = 0;
    
    int index = linearSearchOP(pos, Free, nFree); 

    // Shift all the elements after the element to remove one position to the left
    for (i = index; i <nFree - 1; i++) {
        Free[i].x = Free[i+1].x;
        Free[i].y = Free[i+1].y;
    }

    // Decrement the size of the array
    return nFree-1;
}


int main ()
{
	int peg, valid=0;
	int Peg[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int PegMAIN[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int nPeg = 9; 
	
	orderedPairType S[MAX] = {{1,1}, {1,2}, {1,3}, {2,1}, {2,2}, {2,3}, {3,1}, {3,2}, {3,3}};
	orderedPairType Free[MAX] = {{1,1}, {1,2}, {1,3}, {2,1}, {2,2}, {2,3}, {3,1}, {3,2}, {3,3}};
	orderedPairType FreeMAIN[MAX] = {{1,1}, {1,2}, {1,3}, {2,1}, {2,2}, {2,3}, {3,1}, {3,2}, {3,3}};
	int nFree = 9;
	
	orderedPairType Occ[MAX];
	int nOcc = 0;
	orderedPairType pos;
	
	int P[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int One[MAX] = {0,0,0},
		Two[MAX] = {0,0,0},
		 Three[MAX] = {0,0,0},
		  Four[MAX] = {0,0,0},
		   Five[MAX] = {0,0,0},
		    Six[MAX] = {0,0,0};
	int nOne=0, nTwo=0, nThree=0, nFour=0, nFive=0, nSix=0;
	int UnionNum[MAX] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int W[6][3] = { {0,0,0}, {0,0,0}, {0,0,0},
					{0,0,0}, {0,0,0}, {0,0,0}, }; 
	int indexNUMBERS[6];

orderedPairType T[3] = {{1,1}, {1,2}, {1,3}};
orderedPairType M[3] = {{2,1}, {2,2}, {2,3}};
orderedPairType B[3] = {{3,1}, {3,2}, {3,3}};
orderedPairType L[3] = {{1,1}, {2,1}, {3,1}};
orderedPairType C[3] = {{1,2}, {2,2}, {3,2}};
orderedPairType R[3] = {{1,3}, {2,3}, {3,3}};
	
	int ok = FALSE;
	int next = FALSE;
	int turn = TRUE;
	int over = FALSE;
	
	int i, valid1 = 0;
	int foundIndex = -1;
	char row, column;
	int rowIndex = 0, colIndex = 0;
	int unionIndex = 0;
	
	int BoxPeg[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	orderedPairType BoardPos[MAX] = {{1,1}, {1,2}, {1,3}, {2,1}, {2,2}, {2,3}, {3,1}, {3,2}, {3,3}};
	
	i=0;
			int j;
			int sum = 0;
			int found = 0;
			int sum15 = 0;
			int OVER = 0;
			int boardIndex = 0;
			int boxIndex = 0;
	
	do {
	if (turn)
		printf("Player A's Turn\n");
	else
		printf("Player B's Turn\n");
	Display(peg, UnionNum, BoxPeg, BoardPos, Free, Peg, PegMAIN, FreeMAIN);
	do {
			
		valid = 0;
		valid1 = 0;
		printf("Enter peg: ");
	if (scanf("%d", &peg) != 1) { // check if input is not an integer
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n'); // clear input buffer
        continue; // repeat the loop
    	}
		valid = linearSearchINT(peg, Peg, nPeg);
		if (valid != -1) {
			UnionNum[unionIndex++] = peg;
			BoxPeg[peg-1] = 0; 
			nPeg = removeElement(Peg, nPeg, valid);
			valid1 = 1;
		}
		else 
			printf("Peg is already taken.\n");
	} while (valid1 == 0);
	
	valid1 = 0;
	do {
		valid = 0;
		printf("Enter position: ");
if (scanf("%d %d", &pos.x, &pos.y) != 2) { // check if input is not two integers
        printf("Invalid input. Please enter two numbers.\n");
        while (getchar() != '\n'); // clear input buffer
        continue; // repeat the loop
    }
		valid = linearSearchOP( pos, Free, 9 );
		if (valid != -1) {
			boardIndex = linearSearchOP(pos, FreeMAIN, MAX);
			BoardPos[boardIndex].x = 0;
			BoardPos[boardIndex].y = 0; 
			//remove ordered pair from Free
			nFree = removeOrderedPair(pos, Free, nFree);
			valid1 = 1;
		}
		else 
			printf("\nPosition is already taken.\n");
	} while (valid1 == 0);
	
	
		
	
	switch (1) {
		case 1: 
			if ( linearSearchINT(peg,PegMAIN,9) != -1 && linearSearchOP(pos,FreeMAIN,9) != -1) {
				ok = !ok;
				nOcc = addOcc(pos, Occ, nOcc);
			}
		case 2:	
			if ( ok == TRUE && linearSearchOP(pos, T, 3) != -1) {
				One[nOne] = peg;
        W[0][nOne] = One[nOne];
				nOne++;
				next = !next;
			}
			else if ( ok == TRUE && linearSearchOP(pos, M, 3) != -1) {
				Two[nTwo] = peg;
        W[1][nTwo] = Two[nTwo];
				nTwo++;
				next = !next;
			}
			else if ( ok == TRUE && linearSearchOP(pos, B, 3) != -1) {
				Three[nThree] = peg;
        W[2][nThree] = Three[nThree];
				nThree++;
				next = !next;
			}	
		case 3:
			if ( ok == TRUE && next == TRUE && linearSearchOP(pos, L, 3) != -1 ) {
				Four[nFour] = peg;
        W[3][nFour] = Four[nFour];
				nFour++;
				next = !next;
				ok = !ok;
			}
			else if ( ok == TRUE && next == TRUE && linearSearchOP(pos, C, 3) != -1 ) {
				Five[nFive] = peg;
        W[4][nFive] = Five[nFive];
				nFive++;
				next = !next;
				ok = !ok;
			}
			else if ( ok == TRUE && next == TRUE && linearSearchOP(pos, R, 3) != -1 ) {
				Six[nSix] = peg;
        W[5][nSix] = Six[nSix];
				nSix++;
				next = !next;
				ok = !ok;
			}
		case 4:
			// check if over
				
			indexNUMBERS[0] = nOne;
			indexNUMBERS[1] = nTwo;
			indexNUMBERS[2] = nThree;
			indexNUMBERS[3] = nFour;
			indexNUMBERS[4] = nFive;
			indexNUMBERS[5] = nSix;
			
			i=0;
			int j;
			int sum = 0;
			int found = 0;
			over = 0;
			int sum15 = 0;
			
			while ( found == 0 && i < 6) {
				sum15 = 0;
				sum = 0;
				if (indexNUMBERS[i] == 3) {
					for ( j=0; j<3; j++) {
						sum += W[i][j];
					}

					if (sum < 15)
						found = 1;
					else if (sum == 15)
						sum15++;
				}
				if (sum15 == 6)
					over = 1;
				i++;
			}
			
			if (found == 1 || over == 1) {
				printf("\nGAME OVER!\n");
			}
			
			//check if over
			
			if ( found == 1 ) {
				OVER = 1;
				if (turn == 1)
					printf("\nB WINS!");
				else 
					printf("\nA WINS!");	
			}
			
			else if ( over == 1 ) {
				OVER = 1;
				if (turn == 1)
					printf("\nA WINS!");
				else
					printf("\nB WINS!");
			}	
			
			else {
				turn = !turn;
			}
			
		break;

	printf("END");					 
	} // switch brace
	Sleep(4000);
	system("cls");
} while (OVER == 0);
	
		
	return 0;
	
}
