#include <iostream>
using namespace std;

typedef string Elem;
class DNode {
    private:
        Elem elem;
        DNode* prev;
        DNode* next;
        friend class DLinkedList;
};

class DLinkedList {
    private:
        DNode* header;
        DNode* tailer;
    public:
        DLinkedList() {
            header = new DNode;     // create sentinels
            tailer = new DNode;
            header->next = tailer;  // have them point to each other
            tailer->prev = header;
        };
        ~DLinkedList() {
            while(!empty()) removeFront(); // remove all excepts for sentinels
            delete header;
            delete tailer;
        };
        bool empty() const {
            return (header->next == tailer);
        };
        const Elem& front() const {
            return header->next->elem;
        };
        const Elem& back() const {
            return tailer->prev->elem;
        };
        void addFront(const Elem& e) {
            DNode* v = new DNode;
            v->elem = e;
            v->next = header->next;
            header->next->prev = v;
            v->prev = header;
            header->next = v;
        };
        void addBack(const Elem& e) {
            DNode* v = new DNode;
            v->elem = e;
            v->prev = tailer->prev;
            tailer->prev->next = v;
            v->next = tailer;
            tailer->prev = v;
        };
        void removeFront() {
            DNode* old = header->next;
            header->next = header->next->next;
            header->next->prev = header;
            delete old;
        };
        void removeBack() {
            DNode* old = tailer->prev;
            tailer->prev = tailer->prev->prev;
            tailer->prev->next = tailer;
        };
    protected:
        void add(DNode* v, const Elem& e);
        void remove(DNode* v);
};

int main(void) {

    return 0;
}