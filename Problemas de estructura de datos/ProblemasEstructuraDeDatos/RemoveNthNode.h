/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *current = head;
    ListNode *last = head;

    for (int i = 0; i < n; i++) {
      if (last->next) {
        last = last->next;
      } else {
        head = current->next;
        delete current;
        return head;
      }
    }

    while (last->next) {
      last = last->next;
      if (current->next) {
        current = current->next;
      }
    }

    if (current == last) {
      delete current;
      return nullptr;
    } else {
      ListNode *del = nullptr;
      del = current->next;
      current->next = del->next;
      delete del;
    }

    return head;
  }
};