#ifndef Smoother_h__
#define Smoother_h__

#include "BlocoUtility.h"

template<typename T> 
class BLOCO_UTILITY_API	Smoother
{
private:
	T*		m_pBuffer;
	T		m_stdVal;
	UINT	m_filterSize;
	UINT	m_cursor;

public:
	Smoother(int filterSize, const T& stdVal) :  m_cursor(0),
		m_filterSize(filterSize),
		m_stdVal(stdVal)
	{
		m_pBuffer = DEBUG_CLIENTBLOCK T[m_filterSize];
	}
	~Smoother(void) { SAFE_DELETE_ARRAY(m_pBuffer);}

	void Add(const T& value) {
		m_pBuffer[m_cursor++ % m_filterSize] = value;
	}
	T GetSmoothed() const {
		UINT n = m_cursor < m_filterSize ? m_cursor : m_filterSize;

		if(!n) return m_stdVal;
		else
		{
			T avg;
			UINT i;
			ZeroMemory(&avg, sizeof(avg));
			for ( i = 0; i < n; i++) avg += m_pBuffer[i];
			avg /= static_cast<T>(i);
			return avg;
		}
	}
	void Reset() { 
		m_cursor = 0;
	}
};

template		BLOCO_UTILITY_API Smoother<int>::Smoother( int filterSize, const int& stdVal );
template		BLOCO_UTILITY_API Smoother<int>::~Smoother();
template void	BLOCO_UTILITY_API Smoother<int>::Add( const int& value );
template int	BLOCO_UTILITY_API  Smoother<int>::GetSmoothed() const;
template void	BLOCO_UTILITY_API  Smoother<int>::Reset();

template		BLOCO_UTILITY_API Smoother<long>::Smoother( int filterSize, const long& stdVal );
template		BLOCO_UTILITY_API Smoother<long>::~Smoother();
template void	BLOCO_UTILITY_API Smoother<long>::Add( const long& value );
template long	BLOCO_UTILITY_API  Smoother<long>::GetSmoothed() const;
template void	BLOCO_UTILITY_API  Smoother<long>::Reset();

template		BLOCO_UTILITY_API Smoother<float>::Smoother( int filterSize, const float& stdVal );
template		BLOCO_UTILITY_API Smoother<float>::~Smoother();
template void	BLOCO_UTILITY_API Smoother<float>::Add( const float& value );
template float	BLOCO_UTILITY_API  Smoother<float>::GetSmoothed() const;
template void	BLOCO_UTILITY_API  Smoother<float>::Reset();

template		BLOCO_UTILITY_API Smoother<double>::Smoother( int filterSize, const double& stdVal );
template		BLOCO_UTILITY_API Smoother<double>::~Smoother();
template void	BLOCO_UTILITY_API Smoother<double>::Add( const double& value );
template double	BLOCO_UTILITY_API  Smoother<double>::GetSmoothed() const;
template void	BLOCO_UTILITY_API  Smoother<double>::Reset();


#endif // Smoother_h__