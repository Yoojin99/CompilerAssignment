#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define _CRT_SECURE_NO_WARNINGS
#define FILE_NAME "testdata1.txt"
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

char separators[] = " .,;:?!\t\n";

HTpointer HT[HTsize];
char ST[STsize];

//more global variables…
ERRORtypes err;
int nextid = 0;
int nextfree = 0;
int found = 0;
int hashcode = 0;
int sameid = 0;
int is_separator = 0;	//읽어들인 문자가 유효 separator인지 검사

FILE *fp;	//to be a pointer to FILE
char input;

//Initialize - open input file
void initialize() {
	fp = fopen(FILE_NAME, "r");
	input = fgetc(fp);
}

//Skip Separators - skip over strings of space, tabs, newlines, . , ; : ? !
//			if illegal separators, print out error message.
void SkipSeparators() {
	//공백문자일때 계속 반복
	//이상한 문자 나오면 오류 설정하고 빠져나옴
	//정상문자일 경우 그냥 나옴
	while (1) {
		is_separator = 0;
		//공백검사
		for (int i = 0; i < 9; i++) {
			if (input == separators[i]) {
				is_separator = 1;
				break;
			}
		}
		//공백이라면 계속 읽어들임
		if (is_separator == 1)
			input = fgetc(fp);
		else {
			//유효한 문자다
			if (isalnum(input) || input == '_')
				break;
			else {
				err = illsp;
				break;
			}
		}
	}
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
void ComputeHS(int nid, int nfree) {

	// m=size of hash table, f(x)=sum of ordinal values of x's characters
	// H(x)=(f(x) mod m)+1
	// 순서: a~z(대소문자 구분x),_,0~9
	int sum = 0;
	char now = ST[nid];
	int i = nid;
	for (i = nid; i < nfree || now==' '; i++) {
		now = ST[i];
		if (now >= 'A'&&now <= 'Z')
			sum += now - 'A';
		else if (now >= 'a'&&now <= 'Z')
			sum += now - 'a';
		else if (now == '_')
			sum += 26;
		else if (now >= '0'&&now <= '9')
			sum += 27 + now - '0';
	}

	hashcode = sum % HTsize;

}

//LookupHS -	For each identifier, Look it up in the hashtable for previous occurrence 
//				of the identifier. If find a match, set the found flag as true.
//				Otherwise flase <? 오탄가
//				If find a match, save the starting index of ST in same id.
void LookupHS(int nid, int hscode)
{
	int i, j;
	HTpointer temp = HT[hscode];

	found = 0;
	while (temp != NULL && found==0) {
		i = temp->index;
		j = nid;
		sameid = i;
		found = 1;
		while (ST[i] != ' ' && ST[j] != ' ') {
			if (ST[i] != ST[j]) {
				found = 0;
				break;
			}
			i++;
			j++;
		}
		temp = temp->next;
		
	}
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
	//PrintHeading();
	initialize();

	//26페이지
	while (input != EOF) {
		err = noerror;
		SkipSeparators();
		printf("%c", input);
		input = fgetc(fp);

		
		ReadID();
		if (input != EOF && err != illid) {
			if (nextfree == STsize) {
				// print error message
			}
			ST[nextfree++] = ' ';

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
