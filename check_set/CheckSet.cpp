//#include <iostream>
//#include <vector>
//#include<assert.h>
//class UnionFindSet
//{
//public:
//	UnionFindSet(size_t n)
//	{
//		_ufs.resize(n, -1);
//	}
//	int FindRoot(int n)
//	{
//		//�ڲ��鼯���������ĸ�
//	 
//		while (_ufs[n]>=0)
//		{
//			n = _ufs[n];
//		}
//		return n;
//	}
//	void Union(int x1, int x2)
//	{
//		//����ӳ���ϵ��ɲ��鼯�ĺϲ�
//		int root1 = FindRoot(x1);
//		int root2 = FindRoot(x2);
//
//		if (root1 != root2)
//		{
//			_ufs[root1] += _ufs[root2];
//			_ufs[root2] = root1;
//		}
//		//����ͬ�ĸ���ʱ��˵���Ѿ��ϲ�����
//	}
//
//	size_t Size()
//	{
//		size_t n = 0;
//		for (auto & e : _ufs)
//		{
//			if (e<0)
//			{
//				++n;
//			}
//		}
//		return n;
//	}
//
//private:
//	vector<int> _ufs;
//};
//using namespace std;
//int main()
//{
//	
//	system("pause"); 
//	return 0;
//}