//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	class UnionFindSet
//	{
//	public:
//		UnionFindSet(size_t n)
//		{
//			_ufs.resize(n, -1);
//		}
//		int FindRoot(int n)
//		{
//			//�ڲ��鼯���������ĸ�
//
//			while (_ufs[n] >= 0)
//			{
//				n = _ufs[n];
//			}
//			return n;
//		}
//		void Union(int x1, int x2)
//		{
//			//����ӳ���ϵ��ɲ��鼯�ĺϲ�
//			int root1 = FindRoot(x1);
//			int root2 = FindRoot(x2);
//
//			if (root1 != root2)
//			{
//				_ufs[x1] += _ufs[x2];
//				_ufs[x2] = x1;
//			}
//			//����ͬ�ĸ���ʱ��˵���Ѿ��ϲ�����
//		}
//
//		size_t Size()
//		{
//			size_t n = 0;
//			for (auto & e : _ufs)
//			{
//				if (e < 0)
//				{
//					++n;
//				}
//			}
//			return n;
//		}
//
//	private:
//		vector<int> _ufs;
//	};
//	bool equationsPossible(vector<string>& equations)
//	{
//		//���첢�鼯�������е���ȵ�Ԫ�ش浽���鼯����
//		UnionFindSet ufs(26);
//		for (auto & e :equations)
//		{
//			if (e[1]=='=')
//			{
//				ufs.Union(e[0]-'a', e[3]-'a');
//              //ʹ�ò��鼯Ҫ��Ԫ�ش�������±�������ص�
//			}
//		}
//		for (auto & e : equations)
//		{
//			if (e[1] != '=')
//			{
//				int root1 = ufs.FindRoot(e[0]-'a');
//				int root2 = ufs.FindRoot(e[3]-'a');
//				if (root1==root2)
//				{
//					return false;
//				}
//			}
//		}
//		return true;
//
//	}
//};
//
//int main()
//{
//	
//	system("pause"); 
//	return 0;
//}