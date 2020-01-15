#include <iostream>
#include <unordered_map>
using namespace std;
class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key)
	{
		//���ڣ�����ֵ����pair���ͷ��ɾ��ԭ����λ�ã��ı��ϣ���ӳ�䡢
		/* ��ֵ�����ص��ǵ����� */
		auto hashit = _hashmap.find(key);
		if (hashit == _hashmap.end())
		{
			return -1;
		}
		else
		{
			list<pair<int, int>>::iterator listit = hashit->second;
			//�õ���list�е�λ��
			pair<int, int> kv = *listit;
			//�ı佫��λɾ������ӵ�ͷ��
			_lrulist.erase(listit);
			_lrulist.push_front(kv);
			//�ı���hash�е�ӳ��
			_hashmap[key] = _lrulist.begin();

			return kv.second;//?
		}

	}

	void put(int key, int value) {
		auto hashit = _hashmap.find(key);
		if (hashit == _hashmap.end())
		{
			//������
			if (_hashmap.size()==_capacity)
			{
				//ɾ��list��������һ�����ı�hash�����ӳ��
				_hashmap.erase(_lrulist.back().first);//hash��ɾ����ɾkey
				_lrulist.pop_back();
			}
			//���һ���µĽڵ㣬����hash�������ӳ��
			_lrulist.push_front(make_pair(key, value));
			_hashmap[key] = _lrulist.begin();//����Ľӿڲ���
		}
		else
		{
			//���ڣ��ı�value���ŵ���ͷ���ı�hashӳ��
			list<pair<int, int>>::iterator listit = hashit->second;
			//�õ���list�е�λ��
			pair<int, int> kv = *listit;
			kv.second = value;

			_lrulist.erase(listit);
			_lrulist.push_front(kv);
			_hashmap[key] = _lrulist.begin();//�Լ���hash��valֵ�����������
		}



	}
private:
	list<pair<int, int >> _lrulist;
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
	size_t _capacity;
};
//��ϣ�����ɾ��ĵĸ��Ӷ�ΪO(1),˫���������ɾҲ��O(1)
int main()
{
	 
	system("pause");
	return 0;
}