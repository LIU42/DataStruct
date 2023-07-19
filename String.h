#ifndef __STRING_H__
#define __STRING_H__

#include <stdlib.h>
#include <memory.h>

typedef struct String String;

struct String
{
    char* pCharData;
    int capacity;
};

void String_Init(String*, char*);
void String_Destroy(String*);
void String_SetData(String*, char*);
void String_Insert(String*, String*, int);
void String_Append(String*, String*);
void String_Delete(String*, int, int);
int String_Find(String*, String*);

char* String_GetData(String*);
char String_GetCharAt(String*, int);
int String_GetLength(String*);
String String_GetSubString(String*, int, int);

#endif