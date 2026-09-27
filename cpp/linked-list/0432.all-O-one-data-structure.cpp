class AllOne {
public:

    unordered_map<string,int> count;
    map<int,unordered_set<string>> keys;

    AllOne() {

    }

    void inc(string key) {
        count[key]++;
        int cnt = count[key];

        keys[cnt].insert(key);

        if(cnt != 1){
            keys[cnt-1].erase(key);

            if(keys[cnt-1].empty()){
                keys.erase(cnt-1);
            }
        }
    }

    void dec(string key) {
        int prevCount = count[key];

        count[key]--;

        keys[prevCount].erase(key);

        if(keys[prevCount].empty()){
            keys.erase(prevCount);
        }

        if(count[key] == 0){
            count.erase(key);
        }
        else{
            keys[prevCount-1].insert(key);
        }
    }

    string getMaxKey() {
        if(keys.empty())
            return "";

        return *keys.rbegin()->second.begin();
    }

    string getMinKey() {
        if(keys.empty())
            return "";

        return *keys.begin()->second.begin();
    }
};
