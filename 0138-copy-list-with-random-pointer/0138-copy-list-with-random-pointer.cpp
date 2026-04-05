/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* newHead = new Node(head->val);

        mp[head] = newHead;

        Node* oldTemp = head->next;

        Node* newTemp = newHead;

        while (oldTemp != nullptr) {

            Node* copyNode = new Node(oldTemp->val);

            mp[oldTemp] = copyNode;

            newTemp->next = copyNode;

            oldTemp = oldTemp->next;

            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != nullptr) {

            newTemp->random = mp[oldTemp->random];
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        return newHead;
    }
};