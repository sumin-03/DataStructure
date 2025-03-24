#include <iostream>
using namespace std;

class StringNode {
    private:
        string elem;
        StringNode* next;
        friend class StringLinkedList;
};

class StringLinkedList {
    private:
        StringNode* head;
    public:
        StringLinkedList() {
            head = NULL;
        };
        ~StringLinkedList() {
            while(!empty()) removeFront();
        };
        bool empty() const {
            return head == NULL;
        };
        const string& front() const {
            return head->elem;
        };
        void addFront(const string& e) {
            StringNode* v = new StringNode;
            v->elem = e;
            v->next = head;
            head = v;
        };
        void removeFront() {
            StringNode* old = head;
            head = old->next;
            delete old;
        };
};

int main(void) {

    return 0;
}