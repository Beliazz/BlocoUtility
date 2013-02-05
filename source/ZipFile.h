#ifndef ZipFile_h__
#define ZipFile_h__

#include "BlocoUtility.h"
#include <stdio.h>

typedef map<string, int> BLOCO_UTILITY_API ZipContentsMap;		// maps path to a zip content id

class BLOCO_UTILITY_API ZipFile
{
public:
	ZipFile() { m_nEntries=0; m_pFile=NULL; m_pDirData=NULL; }
	virtual ~ZipFile() { End(); if(m_pFile){fclose(m_pFile);}; }

	bool Init(const _TCHAR *resFileName);
	void End();

	int GetNumFiles()const { return m_nEntries; }
	void GetFilename(int i, char *pszDest) const;
	int GetFileLen(int i) const;
	bool ReadFile(int i, void *pBuf);

	// Added to show multi-threaded decompression
	bool ReadLargeFile(int i, void *pBuf, void (*callback)(int, bool &));

	optional<int> Find(const char *path) const;

	ZipContentsMap m_ZipContentsMap;

private:
	struct TZipDirHeader;
	struct TZipDirFileHeader;
	struct TZipLocalHeader;

	FILE *m_pFile;		// Zip file
	char *m_pDirData;	// Raw data buffer.
	int  m_nEntries;	// Number of entries.

	// Pointers to the dir entries in pDirData.
	const TZipDirFileHeader **m_papDir;   
};

#endif // ZipFile_h__