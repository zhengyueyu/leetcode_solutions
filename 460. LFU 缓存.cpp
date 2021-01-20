class LFUCache {
public:
    typedef list<pair<int, int>>::iterator lpit;
    LFUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if(m_capacity == 0) return -1;
        if(key2val.end() == key2val.find(key))
            return -1;
        int res = key2val[key]->second;
        int preFreq = key2freq[key];
        int curFreq = preFreq + 1;

        freq2fptr[preFreq].erase(key2val[key]);
        freq2fptr[curFreq].push_front({key, res});
        
        lpit np = freq2fptr[curFreq].begin();
        key2val[key] = np;
        key2freq[key] = curFreq;

        if(freq2fptr[preFreq].begin() == freq2fptr[preFreq].end() &&
            last == preFreq) last += 1;
        return res;
    }
    
    void put(int key, int value) {
        if(m_capacity == 0) return;
        if(key2val.find(key) != key2val.end()) {
            get(key);
            key2val[key]->second = value;
            return;
        }

        if(size == m_capacity) {
            size--;
            lpit tmp = --freq2fptr[last].end();
            int oldkey = tmp->first;
            freq2fptr[last].erase(tmp);
            key2val.erase(key2val.find(oldkey));
            key2freq.erase(key2freq.find(oldkey));
        }

        

        freq2fptr[1].push_front({key, value});
        key2val[key] = freq2fptr[1].begin();
        key2freq[key]++;
        last = 1;
        size++;
    }

private:
    int last = 0;
    int size = 0;
    int m_capacity;
    unordered_map<int, lpit> key2val;
    unordered_map<int, int> key2freq;

    //pair<key, value>   unordered_map<freq, pair>
    unordered_map<int, list<pair<int, int>>> freq2fptr;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */