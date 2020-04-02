#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "testdata.txt"
#define STsize 1000	//size of string table
#define HTsize 100	//size of hash table

//more define variables…

typedef struct HTentry *HTpointer;
typedef struct HTentry {
	int index;	//index of identifier in ST
	HTpointer next;	//pointer to next identifier
} HTentry;

enum errorTypes { noerror, illsp, illid, overst };
typedef enum errorTypes ERRORtypes;

char separators[] = ".,;:?!\t\n";

HTpointer HT[HTsize];
char ST[STsize];

//more global variables…
ERRORtypes err;
int nextid = 0;
int nextfree = 0;
int found = 0;
int hashcode = 0;

FILE *fp;	//to be a pointer to FILE
char input;

//Initialize - open input file
void initialize() {
	fp = fopen(FILE_NAME,"r");
	input = fgetc(fp);
}

//Skip Separators - skip over strings of space, tabs, newlines, . , ; : ? !
//			if illegal separators, print out error message.
void SkipSeparators() {

}

//PrintHStable -	Prints the hash table.write out the hashcode and the list of identifiers
// 					associated with each hashcode, but only for non-empty list.
//					Print out the number of characters used up in ST.
void PrintHStable()
{
}

//PrintError - Print out error messages
//		overst : overflow in ST
//		print the hashtable and abort by calling the function “abort()”.
//		illid : illegal identifier.
//		illsp : illegal separator
void PrintError(ERRORtypes err)
{
}

//ReadIO -	Read identifier from the input file the string tables ST directly into
//			ST(append it to the previous identifier).
//			An identifier is a string of letters and digits, starting with a letter.
//			If first letter is digit, print out error message.
void ReadID()
{
}



//ComputeHS -	Compute the hash code of identifier by summing the ordinal values of its
//				characters and then taking the sum modulo the size of HT.
void ComputeHS(int nid, int nfree)
{
}

//LookupHS -	For each identifier, Look it up in the hashtable for previous occurrence 
//				of the identifier. If find a match, set the found flag as true.
//				Otherwise flase <? 오탄가
//				If find a match, save the starting index of ST in same id.
void LookupHS(int nid, int hscode)
{
}

//ADDHT -	Add a new identifier to the hash table.
//			If list head ht[hascode] is null, simply add a list element with
//			starting index of the identifier in ST.
//			IF list head is not a null, it adds a new identifier to the head of the chain
void ADDHT(int hscode)
{

}


/* MAIN	-	Read the identifier from the file directly into ST.
Compute its hashcode.
Look up the identifier in hashtable from ST and print ST - index
of the matching identifier.
if not matched, add a new element to the list, point to new identifier.
Print the identifier, its index in ST, and whether it was entered or present.
Print out the hashtable, and number of characters used up in ST
*/

int main()
{
	int i;
	PrintHeading();
	initialize();


	//26페이지


	while (input != EOF) {
		err = noerror;
		SkipSeparators();
		ReadID();
		if (input != EOF && err != illid) {
			if (nextfree == STsize) {
				// print error message
			}
			ST[nextfree++] = '/0';

			ComputeHS(nextid, nextfree);
			LookupHS(nextid, hashcode);

			if (!found) {
				// print message
				ADDHT(hashcode);
			}
			else {
				// print message
			}
		}
	}
	PrintHStable();
}
