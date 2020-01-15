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
		//存在，返回值，将pair到最开头，删除原来的位置，改变哈希表的映射、
		/* 找值，返回的是迭代器 */
		auto hashit = _hashmap.find(key);
		if (hashit == _hashmap.end())
		{
			return -1;
		}
		else
		{
			list<pair<int, int>>::iterator listit = hashit->second;
			//得到在list中的位置
			pair<int, int> kv = *listit;
			//改变将本位删除，添加到头部
			_lrulist.erase(listit);
			_lrulist.push_front(kv);
			//改变在hash中的映射
			_hashmap[key] = _lrulist.begin();

			return kv.second;//?
		}

	}

	void put(int key, int value) {
		auto hashit = _hashmap.find(key);
		if (hashit == _hashmap.end())
		{
			//不存在
			if (_hashmap.size()==_capacity)
			{
				//删除list里面的最后一个，改变hash里面的映射
				_hashmap.erase(_lrulist.back().first);//hash的删除是删key
				_lrulist.pop_back();
			}
			//添加一个新的节点，并在hash里面添加映射
			_lrulist.push_front(make_pair(key, value));
			_hashmap[key] = _lrulist.begin();//链表的接口不熟
		}
		else
		{
			//存在，改变value，放到表头，改变hash映射
			list<pair<int, int>>::iterator listit = hashit->second;
			//得到在list中的位置
			pair<int, int> kv = *listit;
			kv.second = value;

			_lrulist.erase(listit);
			_lrulist.push_front(kv);
			_hashmap[key] = _lrulist.begin();//自己的hash，val值是链表迭代器
		}



	}
private:
	list<pair<int, int >> _lrulist;
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
	size_t _capacity;
};
//哈希表的增删查改的复杂度为O(1),双向链表的增删也是O(1)
int main()
{
	 
	system("pause");
	return 0;
}