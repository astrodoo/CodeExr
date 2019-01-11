#include <iostream>
using namespace std;

class CMyData
{
public:
	int GetData() { return m_nData; }
	
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

class CMyDataEx : public CMyData
{
public:
	// override the method in the parent class
	void SetData(int nParam)
	{
		if (nParam < 0)
			CMyData::SetData(0);
			
		if (nParam > 0)
			CMyData::SetData(10);
	}
};

int main(int argc, char* argv[])
{
	CMyData *pData = new CMyDataEx;
	pData->SetData(15);
	cout << pData->CMyData::GetData() << endl;
	delete pData;

	return 0;
}