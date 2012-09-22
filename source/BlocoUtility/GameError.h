#ifndef GAMEERROR_H
#define GAMEERROR_H 

#include <DxErr.h>

using namespace std;

// Error Codes
enum GE
{
	GE_INIT_NOT_ENOUGH_PHYS_RAM,
	GE_INIT_NOT_ENOUGH_VIRT_RAM,
	GE_INIT_NOT_ENOUGH_CONTIG_RAM,
	GE_INIT_CPU_TOO_SLOW,
	GE_INIT_NOT_ENOUGH_DISK_SPACE,
	GE_INIT_WINDOWCREATION_FAILED,
	GE_INIT_DEVICECREATON_FAILED,
	GE_INIT_CANNOT_CREATE_SAVEGAME_DIRECTORY,
};

class GameError
{
private:
	DWORD		m_Handle;
	DWORD		m_DXHandle;
	wstring		m_Message;
	WCHAR		m_Buffer[2048];

public:
	inline DWORD	GetHandle()			{return m_Handle;}
	inline DWORD	GetDXHandle()		{return m_DXHandle;}
	inline wstring  GetMessage()		{return m_Message;}
	
	void InformUser()			
	{
		if (FAILED(m_DXHandle))
		{
			wsprintf(m_Buffer,L"%s\n\n%s\n\nDirectX Error Code: %i", DXGetErrorString(m_DXHandle), DXGetErrorDescription(m_DXHandle), m_DXHandle); 
			MessageBoxW(NULL, m_Buffer, L"Error", MB_ICONEXCLAMATION | MB_OK); 
		}
		else
		{
			wsprintf(m_Buffer,L"%s\n\nError Code: %i", m_Message.data(), m_Handle); 
			MessageBoxW(NULL, m_Buffer, L"Error", MB_ICONEXCLAMATION | MB_OK); 
		}
	}

	GameError()	: m_Handle(NULL), m_Message(L""), m_DXHandle(NULL) {}
	GameError(DWORD handle) : m_Handle(handle), m_Message(L""), m_DXHandle(NULL) {}
	GameError(DWORD handle, wstring message) : m_Handle(handle), m_Message(message), m_DXHandle(NULL) {}
	GameError(DWORD handle, DWORD dxHandle) : m_Handle(handle), m_Message(L""), m_DXHandle(dxHandle) {}
	~GameError(void){ }
};

#endif
