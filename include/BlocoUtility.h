// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#ifndef BlocoUtility_H__
#define BlocoUtility_H__

#ifdef BLOCOUTILITY_EXPORTS
#define BLOCO_UTILITY_API __declspec(dllexport)
#else
#define BLOCO_UTILITY_API __declspec(dllimport)
#endif

#define SAFE_RELEASE(x)			if(x){x->Release(); x = NULL;}
#define SAFE_DELETE(x)			if(x){delete x;		x = NULL;}
#define SAFE_FREE(x)			if(x){free(x);		x = NULL;}
#define SAFE_DELETE_ARRAY(x)	if(x){delete[] x;	x = NULL;}


#pragma warning (disable: 4251)
#pragma warning (disable: 4996)
#pragma warning (disable: 4275)
#pragma warning (disable: 4099)
#pragma warning (disable: 4099)

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX


// Windows6
#include <Windows.h>
#include <WindowsX.h>
#pragma comment(lib, "winmm.lib" )
#pragma comment(lib, "comctl32.lib" )

#if defined (_MSC_VER) && (_MSC_VER < 1300)
		#include "types.h"
	#else
		#ifdef _DEBUG
		#undef _DEBUG
		#include <atltypes.h>			// for CSize, CPoint and CRect - it's all inline.
		#define _DEBUG
	#else
		#include <atltypes.h>
	#endif
#endif


// General
#include <stdlib.h>
#include <malloc.h>
#include <memory>
#include <wchar.h>
#include <tchar.h>
#include <assert.h>
#include <cassert>
#include <crtdbg.h>
#include <mmsystem.h>
#include <direct.h>
#include <shlobj.h>
#include <strstream>
#include <functional>
#include <time.h>
#include <WinSock2.h>
#include <io.h>
#include <sys/stat.h>

#include <locale>
#include <iostream>
#include <sstream>

// STL
#include <string>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <fstream>


// winsock library
#pragma comment(lib, "ws2_32.lib")

// zlib
#include <3dParty\zlib\include\zlib.h>

// xml
#include <3dParty\TinyXML\include\tinyxml.h>

using namespace std;

#include "Debug.h"

#include "Templates.h"
#include "Constants.h"
#include "GameError.h"
#include "GameOptions.h"
#include "Smoother.h"
#include "StringHelper.h"
#include "ZipFile.h"
#include "Resource.h"


#endif
