#include <iostream>
using namespace std;

class CIntArray
{
public:
	CIntArray(int nSize)
	{
		cout << "CIntArray (int)" << endl;
		// procure the memory depend upon the size of the input
		m_pnData = new int[nSize];
		memset(m_pnData, 0, sizeof(int) * nSize);
	}
	
	~CIntArray(){ delete m_pnData; }
	
	// array operator for constant input
	int operator[](int nIndex) const
	{
		cout << "operator[] const" << endl;
		return m_pnData[nIndex];
	}
	
	// general array operator
	int& operator[](int nIndex)
	{
		cout << "operator[]" << endl;
		return m_pnData[nIndex];
	}
	
private:
	// memory for the array
	int *m_pnData;
	
	// array size
	int nSize;
};

void TestFunc(const CIntArray &arParam)
{
	cout << "TestFunc()" << endl;
	
	cout << arParam[3] << endl;
}

int main(int argc, char* argv[])
{
	CIntArray arr(5);
	
	for (int i=0; i<5; ++i)
		arr[i] = i*10;
	
	TestFunc(arr);
	
	return 0;
}