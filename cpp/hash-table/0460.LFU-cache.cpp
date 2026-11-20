class LFUCache {
public:
    
    int cap ;
    int size ;

    // { key , address }
    unordered_map<int, list<vector<int>>::iterator> mpp ;

    // counter --> { key , value , counter }
    map<int, list<vector<int>>> freq ;

    LFUCache(int capacity) {

        cap = capacity ;
        size = 0 ;
        
    }

    void makeMostFrequentlyUsed(int key) {

        auto &vec = *(mpp[key]) ; // { key , value , counter }

        int value = vec[1] ;
        int f     = vec[2] ;

        freq[f].erase(mpp[key]) ;

        // agar vo counter k corresponding saare nodes remove ho gaye h toh vo counter vi hata do
        if ( freq[f].empty() ) freq.erase(f) ;

        // aab counter ki value increase krke usko most frequently used bana do
        f++ ;

        freq[f].push_front({ key , value , f }) ;

        mpp[key] = freq[f].begin() ;

    }
    
    int get(int key) {

        // agar map mai present hii nhi h vo key to -1 return krdo
        if ( mpp.find(key) == mpp.end() ) return -1 ;

        // agar map mai key present hai toh value fetch krke return krdo aur usko most frequently used bana do
        
        auto &vec = *(mpp[key]) ; // { key , value , counter }

        int value = vec[1] ;

        makeMostFrequentlyUsed(key) ;

        return value ;
        
    }
    
    void put(int key, int value) {

        if ( cap == 0 ) return ;

        // agar map mai vo key present hai toh list se uss key ki address nikal k uski value update krdo aur counter increase krdo
        if ( mpp.find(key) != mpp.end() ) {

            auto &vec = *(mpp[key]) ;

            vec[1] = value ;

            makeMostFrequentlyUsed(key) ;

            return ;

        }

        // agar map mai present nhi h aur size < capacity hai toh vo fresh banda hai usko counter 1 k start mai push krdo
        if ( size < cap ) {

            size++ ;

            freq[1].push_front(vector<int>({ key , value , 1 })) ;
            mpp[key] = freq[1].begin() ;

        }

        // agar map mai present nhi hai aur current size of list is greater than the maximum capacity of list then time to remove LFU and LRU when there is a tie
        else {

            auto &kaun_sa_list = freq.begin()->second ;

            int key_to_delete = (kaun_sa_list.back())[0] ;

            kaun_sa_list.pop_back() ;

            if ( kaun_sa_list.empty() ) freq.erase( freq.begin()->first ) ;

            freq[1].push_front(vector<int>({ key , value , 1 })) ;

            mpp.erase(key_to_delete) ;

            mpp[key] = freq[1].begin() ;

        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
