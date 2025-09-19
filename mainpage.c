#include <stdio.h>																// Including the <stdio.h> library
#include <string.h>																// Including the <string.h> library
#include <stdlib.h>																// Including the <stdlib.h> library
#include "functionlist.h"														// Including my own "functionlist.h" library

int main(void)																	// Declaration of the main function
{
	char artists[4][80] = {0};													// Stores artists' names and keeps them in their original entered order
	char sortedArtists[4][80] = {0};											// Stores artists' names in alphabetical order
	char songs[4][3][80] = {0};													// Stores all of the songs for each artist
	char allInfo[12][80] = {0};													// Stores every song as well as their respective artists
	int counter = 0;															// Counter variable for indexing the allInfo array
	char spaceAndHyphen[] = " -  ";												// An array to display the space and hyphen between artists and songs


	for ( int i=0 ; i<4 ; i++ )													// For-loop for input of artists
	{
		printf("\n\n\nInsert an artist/group name:\n");							// Asks the user to input an artist's name
		fflush();
        fgets(artists[i] , 80 , stdin);											// Takes an artist's name and stores it in the artists array
        printf("\n");															// Prints a new line

        if(artists[i][0] == '\n')												// Tells the loop to break if the user presses ENTER
        	break;																// Breaks the loop
        
        for( int j=0 ; j<3 ; j++ )												// For-loop for input of songs
        {
        	printf("Insert song %d for %s" , j+1 , artists[i]);					// Asks the user to input a song title
        	fgets(songs[i][j] , 80 , stdin);									// Takes the song title and stores it in the songs array
    		
    		if(songs[i][j][0] != '\n')
    		{
    			strcpy(allInfo[counter] , artists[i]);							// Stores the artists name in the allInfo array
    			allInfo[counter][strlen(allInfo[counter])-1] = ' ';				// Replaces the new-line character with a space character
    			strcat(allInfo[counter] , spaceAndHyphen);						// Appends the spaceAndHyphen array onto the artist's name

        		strcat(allInfo[counter] , songs[i][j]);							// Appends the song title onto the allInfo array
        		counter++;														// The counter variable is incremented
        	}

        	if(songs[i][j][0] == '\n')											// Tells the loop to break if the user presses ENTER
        		break;															// Breaks the loop
        }
	}


	for( int i=0 ; i<4 ; i++ )													// For-loop to copy the contents of artists into sortedArtists
    {
        strcpy( sortedArtists[i] , artists[i] );								// Using the strcpy function to do this
    }


    artistSort( sortedArtists );												// Using the artistSort function which is defined in functionlist.c


    for( int i=0 ; i<4 ; i++ )													// For-loop to use songSort on each artist's discography
    {
    	songSort( songs[i] );													// Using the songSort function which is defined in functionlist.c
    }


    printf("\n\n\nSorted list of songs:");										// Heading to display the sorted list of songs


    for( int i=0 ; i<4 ; i++ )													// For-loop to display the results
    {
    	if(sortedArtists[i][0] == '\n')											// Tells the loop to break if the user pressed ENTER
    		break;																// Breaks the loop

    	printf("\n\n%s" , sortedArtists[i]);									// Prints the artists' names in alphabetical order

    	int p = 0;																// Declaration of p, used to hold j's value when the for-loop breaks

    	for( int j=0 ; j<4 ; j++)												// For-loop to match the artist to the discography
    	{
    		if(   strcmp(sortedArtists[i] , artists[j])   ==   0   )			// Compares everyone in "artists" to the artist in question
    		{	
    			p = j;															// Assigns the value of j to the p variable
    			break;															// Breaks the loop
    		}
    	}

		for( int k=0 ; k<3 ; k++)												// For-loop to print the songs array
		{
			if(songs[p][k][0] == '\n')											// Tells the loop to break if the user pressed ENTER
				break;															// Breaks the loop

			printf("-  %s" , songs[p][k]);										// Prints the song title, as well as some hyphens and spaces
		}
    }


    printf("\n\n\nShuffled Playlist:\n\n");										// Heading to display the shuffled playlist
	shuffle(allInfo, counter);													// Calling the shuffle function to shuffle all of the songs
}
