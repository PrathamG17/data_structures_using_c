#include <stdio.h>
#include <malloc.h>

struct node
{
	int iNo;
	int iKey;
};

void Display(void);
int HashIndex(int);
void Insert(int, int);
struct node* Search(int);
struct node* Delete(int);

struct node* HashTable[20];

int main(void)
{
	int iKey;
	int iData;
	int iChoice;
	int iCounter;
	struct node *iTemp = NULL;
	
	while(1)
	{
		printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n\nEnter Your Choice :- \t");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:
				printf("\nHow Many Records You Want To Insert :- \t");
				scanf("%d",&iChoice);
				
				for(iCounter = 0; iCounter < iChoice; iCounter++)
				{
					printf("\nRecord %d Data :- \t",iCounter+1);
					scanf("%d",&iData);
					printf("\nRecord %d Key :- \t",iCounter+1);
					scanf("%d",&iKey);
					
					Insert(iKey,iData);
				}
				
				break;
			
			case 2:
				printf("\nEnter Key For The Data Retrieve :-\t");
				scanf("%d",&iKey);
				
				iTemp = Search(iKey);
				if(iTemp != NULL)
					printf("\nData Found => %d\n",iTemp->iNo);
				else
					printf("\nData Not Found\n");
				
				break;

			case 3:
				printf("\nEnter Key Of Record To Be Deleted:-\t");
				scanf("%d",&iKey);
			
				iTemp = Delete(iKey);
				printf("\nData => %d Deleted!\n",iTemp->iNo);
				
				break;
			
			case 4:
				printf("\n----Hash Table----\n");
				Display();
				
				break;
			
			case 5:
				return 0;
			
			default :
					printf("\nEnter Valid Choice.\n");
		}
	}
	
	return 0;
}

void Insert(int iKey,int iData)
{		
	int iIndex;
	struct node* pNewNode = NULL;
	
	pNewNode = (struct node *)malloc(sizeof(struct node));
	if(NULL == pNewNode)
	{
		printf("\nMemory Allocation Failed\n");
		return;
	}
	
	pNewNode->iNo = iData;
	pNewNode->iKey = iKey;
	
	iIndex = HashIndex(iKey);
	/*  
		ABOVE:-(52-65) User kadun data aani key ghetli aani node banvun tyat te bharala...
			   (67) Aalelya key cha vaapar karun index find keli...
	*/
		
	while(iIndex < 20 && HashTable[iIndex] != NULL)
	{
		++iIndex;
		
		iIndex =HashIndex(iIndex);
	}
	/*  
		ABOVE:-(73-78) jar find keleli Index valid asel aani tya Index varati koni dusara node asel..
						tar..navin node sathi index find keli...
	*/
	if(iIndex < 20 && NULL == HashTable[iIndex])
		HashTable[iIndex] = pNewNode;
	/*  
		ABOVE:- (83,84) jar line 67 laa..find keleli index valid plus NULL asel tar direct ithe yeun ..
						aaani..NULL nasel koni dusara node tithe asel tar new node sathi valid aani not
						NULL index find karun...ithe yeun node successfully jodlaa...
	*/
}

int HashIndex(int iKey)
{
	return iKey % 20;
	/*  
		ABOVE:-(94) By division(actually modulus) method find and return Index..
	*/
}

void Display(void)
{
	int iCounter;
	
	for(iCounter = 0; iCounter < 20; iCounter++)
	{
		if(HashTable[iCounter] != NULL)
			printf("\nRecord %d :- Data => %d\n",iCounter+1,HashTable[iCounter]->iNo);
	}
	/*  
		ABOVE:-(104-109) HashTable navachya array size pramane array traverse karat karat pratek node
						cha data print kelaa ...as a record... table aslyaaa karnaane ..
	*/
}

struct node* Search(int iKey)
{
	int iIndex;
	
	iIndex = HashIndex(iKey);
	/*  
		ABOVE:-(150-156) user kadun key gheun...aalelya key cha index find karun ghetla...
	*/
	while(iIndex < 20 && HashTable[iIndex] != NULL)
	{
		if(iKey == HashTable[iIndex]->iKey)
			return HashTable[iIndex];
		else
		{
			++iIndex;
			
			iIndex = HashIndex(iIndex);
		}
	}
	/*  
		ABOVE:-(123-133) jar find keleli index valid asel..aani tya index varati node asel(kontaa hee)
						tar aat yeun check kela...aapli(user ne dilili key) aani tya index varchya node 
						chi key jar same asel ...tar to node return kela...
						jar key match karat nasel...tar else madhe jaun current index chya pudhchya index laa jaun HashIndex calculate kela...aani parat check kelaa..joparyant valid index aahe..aani not null means tithe node aahe...to paryant check karat
						rahil...yaa goshti...satisfied jhaly nahi..tar baher yeun...line 177 laa NULL
						return karel...
	*/
	return NULL;
}

struct node* Delete(int iKey)
{
	int iIndex;
	struct node* pTemp = NULL;
	
	iIndex = HashIndex(iKey);
	/*  
		ABOVE:-(180-185) user kadun key gheun...aalelya key cha index find karun ghetla...
	*/	
	while(iIndex < 20 && HashTable[iIndex] != NULL)
	{
		if(iKey == HashTable[iIndex]->iKey)
		{
			pTemp = HashTable[iIndex];
			HashTable[iIndex] = NULL;
			return pTemp;
		}
		else
		{
			++iIndex;
			
			iIndex = HashIndex(iIndex);
		}
	}
	/*  
		ABOVE:-(154-168) calculated index valid asel aani tya index laa node asel...tar aat yeun 
						check kela ...key match karun...ki toch node aahe ka..jar toch asel..
						tar local pointer madhe tya node cha address gheun...tya node chi jaga NULL
						keli...aani tya node cha address return kelaa...
						
						jar key match jhali nahi ..tar else madhe yeun...pudhchya index la jaun..
						HashTable array cha navin index find karun...parat check kela...asa tovar chalu 
						rahil jovar...find kelaa jannara...index..valid aahe..aani tya thikani kontaa
						tari node aahe...jar yaa donhi paiki ek sudha condition satisfied jhali nahi 
						tari...baher yeun...line 181 laa NULL return hoel...
	*/
	return NULL;
}
/*  
	O/P:-
		1.Insert
		2.Search
		3.Delete
		4.Display
		5.Exit

		Enter Your Choice :-    1

		How Many Records You Want To Insert :-  4

		Record 1 Data :-        100

		Record 1 Key :-         2

		Record 2 Data :-        200

		Record 2 Key :-         23

		Record 3 Data :-        300

		Record 3 Key :-         15

		Record 4 Data :-        400

		Record 4 Key :-         7

		1.Insert
		2.Search
		3.Delete
		4.Display
		5.Exit

		Enter Your Choice :-    4

		----Hash Table----

		Record 3 :- Data => 100

		Record 4 :- Data => 200

		Record 8 :- Data => 400

		Record 16 :- Data => 300

		1.Insert
		2.Search
		3.Delete
		4.Display
		5.Exit

		Enter Your Choice :-    2

		Enter Key For The Data Retrieve :-      23

		Data Found => 200

		1.Insert
		2.Search
		3.Delete
		4.Display
		5.Exit

		Enter Your Choice :-    3

		Enter Key Of Record To Be Deleted:-     7

		Data => 400 Deleted!

		1.Insert
		2.Search
		3.Delete
		4.Display
		5.Exit

		Enter Your Choice :-    4

		----Hash Table----

		Record 3 :- Data => 100

		Record 4 :- Data => 200

		Record 16 :- Data => 300

		1.Insert
		2.Search
		3.Delete
		4.Display
		5.Exit

		Enter Your Choice :-    1

		How Many Records You Want To Insert :-  1

		Record 1 Data :-        500

		Record 1 Key :-         45

		1.Insert
		2.Search
		3.Delete
		4.Display
		5.Exit

		Enter Your Choice :-    4

		----Hash Table----

		Record 3 :- Data => 100

		Record 4 :- Data => 200

		Record 6 :- Data => 500

		Record 16 :- Data => 300

		1.Insert
		2.Search
		3.Delete
		4.Display
		5.Exit

		Enter Your Choice :-    6

		Enter Valid Choice.

		1.Insert
		2.Search
		3.Delete
		4.Display
		5.Exit

		Enter Your Choice :-    5
*/
