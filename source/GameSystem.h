#ifndef GAMEADAPTER_H
#define	GAMEADAPTER_H 

#include "BlocoUtility.h"

class GameSystem;

struct CpuInfo
{
	SYSTEM_INFO desc;
	int			speed;
};
struct MemoryInfo
{
	MEMORYSTATUSEX status;
};

typedef vector<AdapterInfo*> AdapterList;
class GameSystem
{
private:
	// Memory ------------------------------------------------------------
	MemoryInfo										m_MemoryInfo;

	// GPU ---------------------------------------------------------------
	AdapterList										m_Adapter;
	LUID											m_SelectedAdapter;
										
	// CPU ---------------------------------------------------------------
	CpuInfo											m_CpuInfo;

	int StartTimingCPU();
	void UpdateCPUTime();
	int CalcCPUSpeed();
	int GetCPUSpeed();
	void CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	void CheckHardDisk(const DWORDLONG diskSpaceNeeded);
	void CheckCPU(const int minCpuSpeed);
	void AddAdapter(CD3D11EnumAdapterInfo* pAdapter, CD3D11EnumDeviceInfo* pDeviceInfo);

public:
	GameSystem();
	GameSystem(const GameSystem& rhs);
	~GameSystem();

	bool Analyze( const DWORDLONG physicalRAMNeeded = 512 * MB, 
				  const DWORDLONG virtualRAMNeeded = 1024 * MB,
				  const DWORDLONG diskSpaceNeeded = 1 * GB,
				  const int minCpuSpeed = 1500);

	void UpdateMemory();
	void SetGameAdapter(LUID adapterLUID)	{m_SelectedAdapter = adapterLUID;}
	AdapterInfo& GetGameAdapter();

	inline LUID&				GetSelectedAdapterLUID()	{return m_SelectedAdapter;}
	inline AdapterList&			GetAdapter()				{return m_Adapter;}
	inline CpuInfo&				GetCPUInfo()				{return m_CpuInfo;}
	inline MemoryInfo&			GetRAMInfo()				{return m_MemoryInfo;}

	bool Verifiy(const CD3D11EnumAdapterInfo* pAdapterInfo);
	
	wstring ToString();
};

#endif

