//
// Created by tonedcandy on 18/2/18.
//
#include<stdio.h>
#include <string.h>
#include <wchar.h>
#include<stdlib.h>
struct card_attr
{
    char suit[4];
    int rank;

}card[52];
/* C implementation QuickSort */


// A utility function to swap two elements
void swap(struct card_attr* a, struct card_attr* b)
{
    struct card_attr t;

   t.rank=(*a).rank;
	strcpy(t.suit,a->suit);
    (*a).rank=(*b).rank;
	strcpy(a->suit,b->suit);
    (*b).rank=t.rank;
	strcpy(b->suit,t.suit);

}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (struct card_attr* arr, int low, int high)
{
    int j;
	int pivot = arr[high].rank;    // pivot
    int i = (low - 1);  // Index of smaller element

    for ( j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j].rank<= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(struct card_attr* arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}
int process(char *s)
{
    switch(s[1])
    {

        case 'a':
        case 'A': return 1;
        case '1': // if(s[2]!=0)
               //return 1;
              // else 
					return 10;
        case '2':return 2;
        case '3':return 3;
        case '4':return 4;
        case '5':return 5;
        case '6':return 6;
        case '7':return 7;
        case '8':return 8;
        case '9':return 9;
        case 'j':
        case 'J':return 11;
        case 'q':
        case 'Q':return 12;
        case 'k':
        case 'K':return 13;







    }




}

int main(){
    int i=0,len,deck[4],k=0,j=0,c,d,h,s;
	deck[0]=deck[1]=deck[2]=deck[3]=0;
    char input[4],delim='1',suit_check,suits[]="cdhs",suit_sym;
//    int  a[]={1,45,65,765,10};
	printf("\t\t\t\tTONEDCANDY'S PLAYING CARDS SORTING PROGRAM\n");
	printf("\t\t\t\t------------------------------------------\n");
    printf("INPUT FORMAT:\n<Suit Letter><Rank Number/Letter>\n(E.g. 'hk' for King of Hearts, 'sa' for Ace of Spades, 'd10' for 10 of Diamonds)\nPLEASE ENTER THE LIST OF CARDS:\n");
    while(delim!='\n')
	{

		scanf("%s[^\n]",&input[0]);
		switch(input[0])
		{
			case 'c':deck[0]++;
					 break;
		case 'd': 	deck[1]++;	
					 break;
		case 'h': deck[2]++;
					 break;
		case 's': deck[3]++;
					 break;


		}
		
        strcpy(card[i].suit,input);
	
        card[i].rank=process(input);
		i++;
		scanf("%c",&delim);



    }
//printf("c:%d d:%d h:%d s:%d",deck[0],deck[1],deck[2],deck[3]);
len=i;
c=deck[0];
d=deck[1];
h=deck[2];
s=deck[3];
//printf("len:%d ",len);
//    for(i=0;i<3;i++)
//    {
//        puts(card[i].c);
//
//
//
//
//    }
suit_check=suits[k];
for(i=0;i<len;i++)
{
	if(deck[k]==0)
	{
		k++;
		suit_check=suits[k];
	}
if(card[i].suit[0]==suit_check)
{
	//printf("%s == %c\n",card[i].suit,suit_check);	
	deck[k]--;
	

}
else
	{
		//printf("in Else\n");		
		for(j=i+1;j<len;j++)
		{
			if(card[j].suit[0]==suit_check)
			{		
				//printf("Swapping %s and %s",card[i].suit,card[j].suit);				
				swap(&card[i],&card[j]);
				deck[k]--;
				break;


			}



		}




	}


}

//printf("AFTER SORTING DECKS:\n");
//for(i=0;i<len;i++)
//{

  //      printf("%s ",card[i].suit);


//}
	//printf("c:%d d:%d h:%d s:%d",c,d,h,s);
    quickSort(card,0,c-1);
    quickSort(card,c,c+d-1);
 	quickSort(card,c+d,c+d+h-1);
    quickSort(card,c+d+h,len-1);
    k=0;
    printf("\t\t\t\t-------------------SORTED CARDS-------------------\n");
    //suit_sym=03;
    
    for(i=0;i<len;i++)
    {
         if(i==0&&c!=0)
             printf("\t\t\t\t|CLUBS: ");

		 
		 else if(i==c&&d!=0)
         	{
         		if(c!=0)
         		printf("\n");
				 printf("\t\t\t\t|DIAMONDS: ");
         		
			 }
			else if(i==c+d&&h!=0)
			{	if(d!=0)
         		printf("\n");
				         		printf("\t\t\t\t|HEARTS: ");

			}
			else if(i==c+d+h&&s!=0)
			{		
				if(h!=0)
         		printf("\n");
				         		printf("\t\t\t\t|SPADES: ");

			}
		
		 printf("%s ",card[i].suit);



    }
	printf("\n\t\t\t\t--------------------------------------------------");



    return 0;
}
