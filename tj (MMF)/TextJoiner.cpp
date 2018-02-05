/* ******************************************************************** **
** @@ TextJoiner
** @  Copyrt : 
** @  Author : 
** @  Update :
** @  Update :
** @  Notes  :
** ******************************************************************** */

/* ******************************************************************** **
**                uses pre-compiled headers
** ******************************************************************** */

#include "stdafx.h"
#include "..\shared\file_find.h"
#include "..\shared\file.h"
#include "..\shared\mmf.h"

/* ******************************************************************** **
** @@                   internal defines
** ******************************************************************** */

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef NDEBUG
#pragma optimize("gsy",on)
#pragma comment(linker,"/FILEALIGN:512 /MERGE:.rdata=.text /MERGE:.data=.text /SECTION:.text,EWR /IGNORE:4078")
#endif 

/* ******************************************************************** **
** @@                   internal prototypes
** ******************************************************************** */

/* ******************************************************************** **
** @@                   external global variables
** ******************************************************************** */

extern DWORD   dwKeepError = 0;

/* ******************************************************************** **
** @@                   static global variables
** ******************************************************************** */

static HANDLE     _hDst = INVALID_HANDLE_VALUE;

static MMF        _MF;

/* ******************************************************************** **
** @@                   real code
** ******************************************************************** */

/* ******************************************************************** **
** @@ ForEach()
** @  Copyrt : 
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

static void ForEach(const char* const pszFileName)
{
   if (!_MF.OpenReadOnly(pszFileName))
   {
      // Error !
      perror("\a\nOpen Input File Error !\n");
      return;
   }

   if (!WriteBuffer(_hDst,_MF.Buffer(),_MF.Size()))
   {
      // Error !
      perror("\a\nWrite Error !\n");
   }

   _MF.Close();
}

/* ******************************************************************** **
** @@ ShowHelp()
** @  Copyrt : 
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

void ShowHelp()
{
   const char  pszCopyright[] = "-*-   TextJoiner (MMF) 1.0   *   Copyright (c) Gazlan  2014   -*-";
   const char  pszDescript [] = "Text files joiner (MMF)";
   const char  pszE_Mail   [] = "complains_n_suggestions direct to gazlan@yandex.ru";

   printf("%s\n\n",pszCopyright);
   printf("%s\n\n",pszDescript);
   printf("Usage: tj.com wildcards\n\n");
   printf("%s\n\n",pszE_Mail);
}

/* ******************************************************************** **
** @@ main()
** @  Copyrt : 
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

int main(int argc,char** argv)
{
   if ((argc < 2) || (argc > 4))
   {
      ShowHelp();
      return 0;
   }

   if (argc == 2 && ((!strcmp(argv[1],"?")) || (!strcmp(argv[1],"/?")) || (!strcmp(argv[1],"-?")) || (!stricmp(argv[1],"/h")) || (!stricmp(argv[1],"-h"))))
   {
      ShowHelp();
      return 0;
   }

   _hDst = CreateFile("dst.txt");

   if (_hDst == INVALID_HANDLE_VALUE)
   {
      perror("\a\nOpen Output File Error !\n");
      return 0;
   }

   FindFile   FF;

   FF.SetMask(argv[1]);

   int      iTotal = 0;

   while (FF.Fetch())
   {
      if ((FF._w32fd.dwFileAttributes | FILE_ATTRIBUTE_NORMAL) && !(FF._w32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
      {  
         ForEach(FF._w32fd.cFileName);
         ++iTotal;
      }
   }

   CloseHandle(_hDst);
   _hDst = INVALID_HANDLE_VALUE;

   printf("\n[i]: Processed %d file(s) total.\n",iTotal);

   return 0;
}

/* ******************************************************************** **
** @@                   The End
** ******************************************************************** */
