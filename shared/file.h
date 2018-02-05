/* ******************************************************************** **
** @@ File Header File
** @ Copyrt : 
** @ Author : 
** @ Modify :
** @ Update :
** @ Notes  :
** ******************************************************************** */

#ifndef _FILE_HPP_
#define _FILE_HPP_

/* ******************************************************************** **
** @@ internal defines
** ******************************************************************** */

#if _MSC_VER > 1000
#pragma once
#endif

/* ******************************************************************** **
** @@ internal prototypes
** ******************************************************************** */

/* ******************************************************************** **
** @@ external global variables
** ******************************************************************** */

/* ******************************************************************** **
** @@ static global variables
** ******************************************************************** */

/* ******************************************************************** **
** @@ Classes
** ******************************************************************** */

/* ******************************************************************** **
** @@ prototypes
** ******************************************************************** */

bool     ReadBuffer (HANDLE hFile,void* pBuf,DWORD dwBufSize);
bool     WriteBuffer(HANDLE hFile,const void* const pBuf,DWORD dwBufSize);
HANDLE   CreateFile(const char* const pszFileName,DWORD dwCreationDisposition = CREATE_ALWAYS,DWORD dwShareMode = FILE_SHARE_READ);
HANDLE   OpenFileReadWrite(const char* const pszFileName,DWORD dwShareMode = FILE_SHARE_READ);
HANDLE   OpenFileReadOnly(const char* const pszFileName);
HANDLE   Open_or_CreateFile(const char* const pszFileName);
DWORD    GetFilePointer(HANDLE hFile);
DWORD    GetFileSizeLo(HANDLE hFile);
DWORD    SetFilePointerBOF(HANDLE hFile);
DWORD    SetFilePointerEOF(HANDLE hFile);
DWORD    SetFilePointerCUR(HANDLE hFile,int iOfs,DWORD dwMethod);
FILETIME GetLatestFileTime(HANDLE hFile);
FILETIME GetLatestFileTime(const char* const pszFile);
void     EnsureDirectory(const char* const pszPath);

#endif

/* ******************************************************************** **
** End of File
** ******************************************************************** */
