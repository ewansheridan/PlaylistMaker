#include <stdio.h>																// Including the <stdio.h> library
#include <string.h>																// Including the <string.h> library
#include <stdlib.h>																// Including the <stdlib.h> library
#include "functionlist.h"														// Including my own "functionlist.h" library




void swap(char arrayA[], char arrayB[])											// Declaration of the swap function
{
	char temp[80];																// Creates a temporary array to store A's value
    strcpy(temp, arrayA);														// Copies the contents of A into temp
    strcpy(arrayA, arrayB);														// Copies the contents of B into A
    strcpy(arrayB, temp);														// Copies the contents of temp into B
}																				// This essentially "swaps" A and B




void artistSort(char artistArray[4][80])										// Declaration of the artistSort function
{
	for( int i=0 ; i<4 ; i++ )													// For-loop to let the Bubble Sort happen 4 times
	{
		for( int j=1 ; j<4 ; j++ )												// Inner for-loop to iterate along all 4 elements
		{
			if(		(strcmp(artistArray[j-1] , artistArray[j]) > 0)				// Checks if the 1st element is lexicographically greater than the 2nd
				||	(artistArray[j-1][0] == '0')								// Checks that the 1st element is not 0
				||	(artistArray[j-1][0] == '\n')								// Checks that the 1st element is not a new line
				||	(artistArray[j-1][0] == '\0')					)			// Checks that the 1st element is not the null terminator
			{
				swap( artistArray[j-1] , artistArray[j] );						// Swaps the 2 elements if any of the above conditions are true
			}
		}
	}
}




void songSort(char songArray[][80])												// Declaration of the songArray function
{
	for( int i=0 ; i<3 ; i++ )													// For-loop to let the Bubble Sort happen 3 times
	{
		for( int j=1 ; j<3 ; j++ )												// Inner for-loop to iterate along all 3 elements
		{
			if(		(strcmp(songArray[j-1] , songArray[j]) > 0)					// Checks if the 1st element is lexicographically greater than the 2nd
				||	(songArray[j-1][0] == '0')									// Checks that the 1st element is not 0
				||	(songArray[j-1][0] == '\n')									// Checks that the 1st element is not a new line
				||	(songArray[j-1][0] == '\0')					)				// Checks that the 1st element is not the null terminator
			{
				swap( songArray[j-1] , songArray[j] );							// Swaps the 2 elements if any of the above conditions are true
			}
		}
	}
}




void shuffle(char infoArray[][80], int counter)									// Declaration of the shuffle function
{
	int streams[12] = {0};														// Integer array to keep track of how many times each song has been played
	int everythingPlayedTwice = 0;												// Integer to hold a Boolean value of if every song has been played twice
	int x;																		// Integer to hold the value of the random number
	int songsPlayed = 0;														// Integer to keep track of how many songs have been played
	char lastFiveSongs[50][80] = {0};											// Character array to keep track of the last 5 songs that have been played
	
	while(everythingPlayedTwice==0)												// While-loop to keep printing until everythingPlayedTwice is true
	{
		x = rand()%counter;														// The x variable is assigned a random number between 0 and however many songs there are
		
		if(	(	strcmp( lastFiveSongs[songsPlayed-1] , infoArray [x] ) != 0		// Checks if the current selection came up 1 song ago
			&&	strcmp( lastFiveSongs[songsPlayed-2] , infoArray [x] ) != 0		// Checks if the current selection came up 2 songs ago
			&&	strcmp( lastFiveSongs[songsPlayed-3] , infoArray [x] ) != 0		// Checks if the current selection came up 3 songs ago
			&&	strcmp( lastFiveSongs[songsPlayed-4] , infoArray [x] ) != 0		// Checks if the current selection came up 4 songs ago
			&&	strcmp( lastFiveSongs[songsPlayed-5] , infoArray [x] ) != 0		// Checks if the current selection came up 5 songs ago
			&&	streams[x] < 2)													// Checks if the song has already been played twice

		||	(	counter < 5														// If there are less than 5 songs, then they are allowed to come up within 5 songs of one another
			&&	streams[x] < 2)	)												// Checks if the song has already been played twice
		{
			printf("%s",infoArray[x]);											// Prints the artist and song title
			strcpy( lastFiveSongs[songsPlayed] , infoArray[x] );				// Copies the song into the lastFiveSongs array
			streams[x]++;														// Increments the number of times that specific song has been played
			songsPlayed++;														// Increments the number of songs played
		}

		everythingPlayedTwice = 1;												// Makes the everythingPlayedTwice variable true, unless it gets changed

		for( int i=0 ; i<counter ; i++ )										// For-loop to change the everythingPlayedTwice variable to false
		{
			if( streams[i] < 2)													// Checks if the song has been played twice
			{
				everythingPlayedTwice = 0;										// Resets the everythingPlayedTwice variable to false
				break;															// Breaks the loop
			}
		}
	}
}