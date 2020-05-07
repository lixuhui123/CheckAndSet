//#include <iostream>
//#include<vector>
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
//			//在并查集里面找它的根
//
//			while (_ufs[n] >= 0)
//			{
//				n = _ufs[n];
//			}
//			return n;
//		}
//		void Union(int x1, int x2)
//		{
//			//根据映射关系完成并查集的合并
//			int root1 = FindRoot(x1);
//			int root2 = FindRoot(x2);
//
//			if (root1 != root2)
//			{
//				_ufs[root1] += _ufs[root2];
//				_ufs[root2] = root1;
//			}
//			//有相同的根的时候，说明已经合并过了
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
//	int findCircleNum(vector<vector<int>>& M) 
//	{
//		//遍历，生成并查集，是森林
//		size_t i, j;
//		UnionFindSet ufs(M.size());
//		for (i=0;i<M.size();++i)
//		{
//			for (j=0;j<M[i].size();++j)
//			{
//				if (i<j && M[i][j]==1)
//				{
//					ufs.Union(i, j);
//				}
//			}
//		}
//		return ufs.Size();
//	}
//};
//int main()
//{
//
//	system("pause");
//	return 0;
//}