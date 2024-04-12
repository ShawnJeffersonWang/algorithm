//
// Created by shawn on 24-3-5.
//
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int k = 0, int v = 0) : key(k), value(v) {}
};

class LRUCache {

private:
    int capacity;
    Node *dummy;
    unordered_map<int, Node *> key_to_node;

    void remove(Node *x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    void push_front(Node *x) {
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    Node *get_node(int key) {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end())
            return nullptr;
        auto node = it->second;
        remove(node);
        push_front(node);
        return node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node()) {
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key) {
        auto node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value) {
        auto node = get_node(key);
        if (node) {
            node->value = value;
            return;
        }
        key_to_node[key] = node = new Node(key, value);
        push_front(node);
        if (key_to_node.size() > capacity) {
            auto back_node = dummy->prev;
            key_to_node.erase(back_node->key);
            remove(back_node);
            delete back_node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    LRUCache *obj = new LRUCache(2);
    int result;
    // 缓存是 {1=1}
    obj->put(1, 1);
    // 缓存是 {1=1, 2=2}
    obj->put(2, 2);
    // 返回 1
    result = obj->get(1);
    cout << "result: " << result << endl;
    // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    obj->put(3, 3);
    // 返回 -1 (未找到)
    result = obj->get(2);
    cout << "result: " << result << endl;

    // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    obj->put(4, 4);
    // 返回 -1 (未找到)
    result = obj->get(1);
    cout << "result: " << result << endl;

    // 返回 3
    result = obj->get(3);
    cout << "result: " << result << endl;

    // 返回 4
    result = obj->get(4);
    cout << "result: " << result << endl;
}