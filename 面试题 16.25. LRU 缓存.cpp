class LRUCache {
private:
	typedef struct block {
		int key;
		int val;
		block(int _k, int _v) : key(_k), val(_v) {}
	} block;
public:
	typedef list<block>::iterator plit;
	LRUCache(int capacity) {
		m_capacity = capacity;
	}

	int get(int key) {
		if (size == 0)
			return -1;
		auto it = key2block.find(key);
		if (it == key2block.end()) {
			return -1;
		}

		blist.splice(blist.begin(), blist, it->second);
		key2block[key] = blist.begin();
		return key2block[key]->val;

	}

	void put(int key, int value) {
		if (m_capacity == 0)
			return;

		auto it = key2block.find(key);
		if (it != key2block.end()) {
			it->second->val = value;
			blist.splice(blist.begin(), blist, it->second);
			key2block[key] = blist.begin();
			return;
		}

		if (size == m_capacity) {
			int oldkey = blist.back().key;
			blist.erase(--blist.end());
			key2block.erase(oldkey);
			size--;
		}
		size++;
		block bl(key, value);
		blist.emplace(blist.begin(), bl);
		key2block[key] = blist.begin();
		return;

	}

private:
	int m_capacity = 0;
	int size = 0;
	
	unordered_map<int, plit> key2block;
	list<block> blist;
};