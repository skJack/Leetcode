/*

Category	Difficulty	Likes	Dislikes
algorithms	Hard (33.31%)	152	-
Tags
Companies
设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。

get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
put(key, value) - 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。

一个项目的使用次数就是该项目被插入后对其调用 get 和 put 函数的次数之和。使用次数会在对应项目被移除后置为 0。

进阶：
你是否可以在 O(1) 时间复杂度内执行两项操作？

示例：

LFUCache cache = new LFUCache( 2 /* capacity (缓存容量) */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回 1
cache.put(3, 3);    // 去除 key 2
cache.get(2);       // 返回 -1 (未找到key 2)
cache.get(3);       // 返回 3
cache.put(4, 4);    // 去除 key 1
cache.get(1);       // 返回 -1 (未找到 key 1)
cache.get(3);       // 返回 3
cache.get(4);       // 返回 4
*/

//自己的方法，大体正确，但是没想到用set自动排序 卡了好久。优先队列还是不行啊
// @lc code=start
// struct node
// {
//     int key;
//     int value;
//     int count;
//     int latest_use = 0;//最近一次被调用的次序
//     friend bool operator < (const node &a,const node &b)
//     {
//         if(a.count!=b.count)
//         {
//             return a.count>b.count;//最小值优先
//         }
//         else
//         {
//             return a.latest_use>b.latest_use;//latest_use越小代表最近使用少，所以应该优先被取掉
//         }
        
//     }
// };

// class LFUCache {
// public:
//     int capacity;
//     int all_count;//调用总次数
//     map<int,node>m;
//     //priority_queue<node>util;
//     LFUCache(int capacity) {
//         capacity = capacity;
//         all_count = 0;
//     }
//     int get(int key) {
//         if(m.count(key)==0)
//         {
//                 all_count++;
//                 return -1;
//         }
//         else
//         {
//             all_count++;
//             m[key].latest_use = all_count;
//             m[key].count++;
//             return m[key].value;
//         }
//     }
//     void put(int key, int value) {
//         int count = m.size();
//         all_count++;
//         if(count>capacity)
//         {

//             node tmp = util.top();
//             util.pop();
//             int delete_key = tmp.key;
//             m.erase(delete_key);//删除优先队列对应的元素
//         }
//         m[key] = value;
//         node tmp;
//         tmp.key = key;
//         tmp.value = value;
//         tmp.count = 1;
//         tmp.latest_use = all_count;
//         util.insert(tmp);
//     }
// };
struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}
    
    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};
class LFUCache {
    // 缓存容量，时间戳
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        // 如果哈希表中没有键 key，返回 -1
        if (it == key_table.end()) return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it -> second;
        // 从平衡二叉树中删除旧的缓存
        S.erase(cache);
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将新缓存重新放入哈希表和平衡二叉树中
        S.insert(cache);
        it -> second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 如果到达缓存容量上限
            if (key_table.size() == capacity) {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                key_table.erase(S.begin() -> key);//注意这里的使用方法
                S.erase(S.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        }
        else {
            // 这里和 get() 函数类似
            Node cache = it -> second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it -> second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
