#ifndef String_h__
#define String_h__

#include "BlocoUtility.h"

// Removes characters up to the first '\n'
extern BLOCO_UTILITY_API void RemoveFirstLine(std::wstring &src, std::wstring &result);

// Removes leading white space
extern BLOCO_UTILITY_API void TrimLeft(std::wstring &s);

// Counts the number of lines in a block of text
extern BLOCO_UTILITY_API int CountLines(const std::wstring &s);

// Gets specified line form a textblock
extern BLOCO_UTILITY_API std::string GetLine(const std::string &s, int line);

extern BLOCO_UTILITY_API HRESULT AnsiToWideCch( WCHAR* dest, const CHAR* src, int charCount);  
extern BLOCO_UTILITY_API HRESULT WideToAnsiCch( CHAR* dest, const WCHAR* src, int charCount);  
extern BLOCO_UTILITY_API HRESULT GenericToAnsiCch( CHAR* dest, const TCHAR* src, int charCount); 
extern BLOCO_UTILITY_API HRESULT GenericToWideCch( WCHAR* dest, const TCHAR* src, int charCount); 
extern BLOCO_UTILITY_API HRESULT AnsiToGenericCch( TCHAR* dest, const CHAR* src, int charCount); 
extern BLOCO_UTILITY_API HRESULT WideToGenericCch( TCHAR* dest, const WCHAR* src, int charCount);

extern BLOCO_UTILITY_API string GetSuffix( string filename );
extern BLOCO_UTILITY_API string GetTitle( string filename );
extern BLOCO_UTILITY_API string GetName( string filename );
extern BLOCO_UTILITY_API string GetDirectory( string filename );

#endif // String_h__