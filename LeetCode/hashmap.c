#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义哈希表的节点结构
typedef struct {
    char* key;
    char value;
} HashNode;

// 定义哈希表结构
typedef struct {
    HashNode** buckets;
    int size;
} HashMap;

// 哈希函数：计算字符串的哈希值
int hashFunc(const char* key) {
    int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key;
        key++;
    }
    return hash;
}

// 创建哈希表
HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->buckets = (HashNode**)calloc(size, sizeof(HashNode*));
    map->size = size;
    return map;
}

// 销毁哈希表
void destroyHashMap(HashMap* map) {
    if (map == NULL) return;
    for (int i = 0; i < map->size; i++) {
        HashNode* node = map->buckets[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

// 向哈希表中插入键值对
void insertHashMap(HashMap* map, const char* key, char value) {
    int index = hashFunc(key) % map->size;

    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = strdup(key);
    node->value = value;
    node->next = map->buckets[index];

    map->buckets[index] = node;
}

// 从哈希表中查找键对应的值
char* findHashMap(HashMap* map, const char* key) {
    int index = hashFunc(key) % map->size;

    HashNode* node = map->buckets[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return &(node->value);
        }
        node = node->next;
    }

    return NULL;
}

int main() {
    HashMap* map = createHashMap(100);

    // 向哈希表中插入键值对
    insertHashMap(map, "key1", 'A');
    insertHashMap(map, "key2", 'B');
    insertHashMap(map, "key3", 'C');

    // 从哈希表中查找键对应的值
    char* value1 = findHashMap(map, "key1");
    char* value2 = findHashMap(map, "key2");
    char* value3 = findHashMap(map, "key3");

    if (value1 != NULL) {
        printf("Value for key1: %c\n", *value1);
    }
    if (value2 != NULL) {
        printf("Value for key2: %c\n", *value2);
    }
    if (value3 != NULL) {
        printf("Value for key3: %c\n", *value3);
    }

    // 销毁哈希表
    destroyHashMap(map);

    return 0;
}