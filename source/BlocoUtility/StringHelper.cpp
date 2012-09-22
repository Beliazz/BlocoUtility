#include "BlocoUtility.h"

void BLOCO_UTILITY_API RemoveFirstLine(std::wstring &src, std::wstring &result)
{
	int breakPosition = (int)src.find('\n');
	result = _T("");
	if(breakPosition != string::npos)	//if found...
	{
		int len = (int)src.length();
		result = src.substr(0, breakPosition);
		src = src.substr(breakPosition+1, (len-breakPosition)-1);		// skip the '/n'
	}
	else
	{
		result = src;
		src = _T("");
	}
}


// Remove all leading whitespace
void BLOCO_UTILITY_API TrimLeft(std::wstring &s)
{
	// find first non-space character
	int i = 0;
	int len = (int)s.length();
	while( i <  len )
	{
		TCHAR ch = s[i];			
		int white = 
#ifdef UNICODE
			iswspace( ch );
#else
			isspace( ch );
#endif
		if (!white)
			break;
		++i;
	}

	if (i<len)
		s = s.substr(i);
}


int BLOCO_UTILITY_API CountLines(const std::wstring &s)
{
	int lines = 0;
	int breakPos = 0;

	do 
	{
		++lines;
		breakPos = (int)s.find('\n', breakPos+1);
	} while (breakPos != std::string::npos);

	return lines;
}	


//-----------------------------------------------------------------------------
// Name: AnsiToWideCch()
// Desc: This is a UNICODE conversion utility to convert a CHAR string into a
//       WCHAR string. 
//       cchDestChar is the size in TCHARs of wstrDestination.  Be careful not to 
//       pass in sizeof(strDest) 
//-----------------------------------------------------------------------------
HRESULT BLOCO_UTILITY_API AnsiToWideCch( WCHAR* wstrDestination, const CHAR* strSource, int cchDestChar )
{
	if( wstrDestination==NULL || strSource==NULL || cchDestChar < 1 )
		return E_INVALIDARG;

	int nResult = MultiByteToWideChar( CP_ACP, 0, strSource, -1, 
		wstrDestination, cchDestChar );
	wstrDestination[cchDestChar-1] = 0;

	if( nResult == 0 )
		return E_FAIL;
	return S_OK;
}


//-----------------------------------------------------------------------------
// Name: WideToAnsi()
// Desc: This is a UNICODE conversion utility to convert a WCHAR string into a
//       CHAR string. 
//       cchDestChar is the size in TCHARs of strDestination
//-----------------------------------------------------------------------------
HRESULT BLOCO_UTILITY_API WideToAnsiCch( CHAR* strDestination, const WCHAR* wstrSource, int cchDestChar )
{
	if( strDestination==NULL || wstrSource==NULL || cchDestChar < 1 )
		return E_INVALIDARG;

	int nResult = WideCharToMultiByte( CP_ACP, 0, wstrSource, -1, strDestination, 
		cchDestChar*sizeof(CHAR), NULL, NULL );
	strDestination[cchDestChar-1] = 0;

	if( nResult == 0 )
		return E_FAIL;
	return S_OK;
}


//-----------------------------------------------------------------------------
// Name: GenericToAnsi()
// Desc: This is a UNICODE conversion utility to convert a TCHAR string into a
//       CHAR string. 
//       cchDestChar is the size in TCHARs of strDestination
//-----------------------------------------------------------------------------
HRESULT BLOCO_UTILITY_API GenericToAnsiCch( CHAR* strDestination, const TCHAR* tstrSource, int cchDestChar )
{
	if( strDestination==NULL || tstrSource==NULL || cchDestChar < 1 )
		return E_INVALIDARG;

#ifdef _UNICODE
	return WideToAnsiCch( strDestination, tstrSource, cchDestChar );
#else
	strncpy( strDestination, tstrSource, cchDestChar );
	strDestination[cchDestChar-1] = '\0';
	return S_OK;
#endif   
}


//-----------------------------------------------------------------------------
// Name: GenericToWide()
// Desc: This is a UNICODE conversion utility to convert a TCHAR string into a
//       WCHAR string. 
//       cchDestChar is the size in TCHARs of wstrDestination.  Be careful not to 
//       pass in sizeof(strDest) 
//-----------------------------------------------------------------------------
HRESULT BLOCO_UTILITY_API GenericToWideCch( WCHAR* wstrDestination, const TCHAR* tstrSource, int cchDestChar )
{
	if( wstrDestination==NULL || tstrSource==NULL || cchDestChar < 1 )
		return E_INVALIDARG;

#ifdef _UNICODE
	wcsncpy( wstrDestination, tstrSource, cchDestChar );
	wstrDestination[cchDestChar-1] = L'\0';
	return S_OK;
#else
	return AnsiToWideCch( wstrDestination, tstrSource, cchDestChar );
#endif    
}


//-----------------------------------------------------------------------------
// Name: AnsiToGeneric()
// Desc: This is a UNICODE conversion utility to convert a CHAR string into a
//       TCHAR string. 
//       cchDestChar is the size in TCHARs of tstrDestination.  Be careful not to 
//       pass in sizeof(strDest) on UNICODE builds
//-----------------------------------------------------------------------------
HRESULT BLOCO_UTILITY_API AnsiToGenericCch( TCHAR* tstrDestination, const CHAR* strSource, int cchDestChar )
{
	if( tstrDestination==NULL || strSource==NULL || cchDestChar < 1 )
		return E_INVALIDARG;

#ifdef _UNICODE
	return AnsiToWideCch( tstrDestination, strSource, cchDestChar );
#else
	strncpy( tstrDestination, strSource, cchDestChar );
	tstrDestination[cchDestChar-1] = '\0';
	return S_OK;
#endif    
}


//-----------------------------------------------------------------------------
// Name: AnsiToGeneric()
// Desc: This is a UNICODE conversion utility to convert a WCHAR string into a
//       TCHAR string. 
//       cchDestChar is the size in TCHARs of tstrDestination.  Be careful not to 
//       pass in sizeof(strDest) on UNICODE builds
//-----------------------------------------------------------------------------
HRESULT BLOCO_UTILITY_API WideToGenericCch( TCHAR* tstrDestination, const WCHAR* wstrSource, int cchDestChar )
{
	if( tstrDestination==NULL || wstrSource==NULL || cchDestChar < 1 )
		return E_INVALIDARG;

#ifdef _UNICODE
	wcsncpy( tstrDestination, wstrSource, cchDestChar );
	tstrDestination[cchDestChar-1] = L'\0';    
	return S_OK;
#else
	return WideToAnsiCch( tstrDestination, wstrSource, cchDestChar );
#endif
}

string BLOCO_UTILITY_API GetLine( const std::string &s, int line )
{
	if(line < 0)
		return string();

	if (line == 0)
	{

		int len = 0;
		for (UINT i = 0; i < s.length(); i++)
		{
			if (s[i] == '\n')
			{
				break;
			}
			else if( i == s.length() - 1)
			{
				break;
			}

			len++;
		}

		string out;
		out.resize(len);
		memcpy((void*)out.data(), (void*)s.data(), len);
		out += '\0';

		return out;
	}
	else
	{
		int lineStart = 0;
		int lineEnd = 0;
		int counter = -1;
		UINT i;
		for (i = 0; i < s.length(); i++)
		{
			if (s[i] == '\n')
			{
				lineStart = lineEnd + 1;
				lineEnd = i;

				counter++;
				if (counter == line)
				{
					break;
				}
			}
		}

		if ( i == s.length() )
			return string();

		string out;
		out.resize(lineEnd - lineStart);
		memcpy((void*)out.data(), (void*)(&s[lineStart]), lineEnd - lineStart);
		out += '\0';

		return out;
	}
}

string BLOCO_UTILITY_API GetTitle( string filename )
{
	string title = filename;

	for (int i = filename.length() - 1; i >= 0 ; i--)
	{
		if (filename[i] == '\\' || filename[i] == '/')
		{
			title.erase(title.begin(),title.begin()+i+1);
			break;
		}
	}

	return title;
}

string BLOCO_UTILITY_API GetSuffix( string filename )
{
	std::string extension = filename;

	for (int i = filename.length() - 1; i >= 0 ; i--)
	{
		if (filename[i] == '.')
		{
			extension.erase(extension.begin(), extension.begin() + i + 1);
			break;
		}
	}

	return extension;
}

string BLOCO_UTILITY_API GetName( string filename )
{
	string name = GetTitle( filename );
	string suffix = GetSuffix(filename);

	name.erase( name.end() - suffix.length() - 1, name.end());

	return name;
}

string BLOCO_UTILITY_API GetDirectory( string filename )
{
	string dir = filename;

	for (int i = filename.length() - 1; i >= 0 ; i--)
	{
		if (filename[i] == '\\' )
		{
			dir.erase(i + 1,filename.length());
			break;
		}
	}

	return dir;
}
