/*
 * @brief  huffman模板
 * @file huffman2.cpp
 * @author xiyanxiyan10
 * @CreatedTime 2014/10/02
 * @LastChanged 2014/10/02
 */

#include <iostream>
#define EOF -1

using namespace std;
class huffman_node;
class huffman;
class huffman_node{
public:
        huffman_node(const int &val, const int &power):val(val), power(power), lft(NULL), rht(NULL), next(NULL){}
        int val;
        int power;
        huffman_node *lft;
        huffman_node *rht;
        huffman_node *next;
};
class huffman
{
public:
        huffman():huffman_head(new huffman_node(EOF, 0)){}
        void add_new(huffman_node *new_node);
        void construct();
        int get_power(){
                huffman_node  *node = huffman_head->next;
                return huffman_power(node, 1);
        }
        void get_code(){
                huffman_node *node = huffman_head->next;
                return huffman_code(node, "huffman:");
        }
        void destory(){
            huffman_destory(huffman_head);
        }
        int huffman_power(huffman_node *node, int level);
        void huffman_code(huffman_node *node, string code);
        void huffman_destory(huffman_node *node);
        huffman_node *huffman_head;
};

void huffman::add_new(huffman_node *new_node)
{
        huffman_node *index = huffman_head;
        while(index->next && index->next->power < new_node->power){
                    index = index->next;
        }
        new_node->next = index->next;
        index->next = new_node;
}
void huffman::construct(){
    while(huffman_head->next){
            if(NULL == huffman_head->next->next)
                    return;
             huffman_node *new_node = new huffman_node(EOF,huffman_head->next->power + huffman_head->next->next->power);
             new_node->lft = huffman_head->next;
             new_node->rht = huffman_head->next->next;
             huffman_head->next  = new_node->rht->next;
             add_new(new_node);
    }
}
int huffman::huffman_power(huffman_node *node, int level){
    if(NULL == node) return 0;
    if(NULL == node->lft && NULL == node->rht) return node->power *level;
    return huffman_power(node->lft, level + 1) + huffman_power(node->rht, level + 1);
}

void huffman::huffman_code(huffman_node *node, string code)
{
    if(NULL == node->lft && NULL == node->rht){
            cout << "char:" << static_cast<char>(node->val) << " code:" << code << "\n";
            return;
    }
    string tmp;
    tmp = code;
    if(node->lft){
            tmp += '0';
            huffman_code(node->lft, tmp);
    }
    tmp = code;
    if(node->rht){
            tmp += '1';
            huffman_code(node->rht, tmp);
    }
}
void  huffman::huffman_destory(huffman_node *node)
{
    if(node->lft)
        huffman_destory(node->lft);
    if(node->rht)
        huffman_destory(node->rht);
    if(0 == node->lft  && 0 == node->rht){
        delete node;
        return;
    }
}

int main()
{
    char val;
    int power;
    huffman test;
    while(cin >> val >> power){
            cout << "val = "<< val << endl;
            cout << "power= " << power << endl;
            test.add_new(new huffman_node(val, power));
    }
    cout << "start construct" << endl;
            test.construct();
    cout << "huffman_power:"  << test.get_power() << endl;
    cout << "huffman_code:\n" ;  test.get_code();
    test.destory();
    return 0;
}
