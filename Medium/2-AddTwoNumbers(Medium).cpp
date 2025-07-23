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

// This code causes overflow due to multiplication
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int num1 = 0;
//         int num2 = 0;
//         int place1 = 1;
//         int place2 = 1;
        
//         while (l1 != nullptr) {
//             num1 += l1->val * place1;
//             place1 *= 10;
//             l1 = l1->next;
//         }
        
//         while (l2 != nullptr) {
//             num2 += l2->val * place2;
//             place2 *= 10;
//             l2 = l2->next;
//         }
        
//         int sum = num1 + num2;
        
//         // Now convert sum back to linked list
//         // Look at output
//         if (sum == 0) return new ListNode(0);
        
//         ListNode* head = nullptr;
//         ListNode* current = nullptr;
        
//         while (sum > 0) {
//             int digit = sum % 10;
//             sum /= 10;
//             ListNode* newNode = new ListNode(digit);
//             if (!head) {
//                 head = newNode;
//                 current = newNode;
//             } else {
//                 current->next = newNode;
//                 current = current->next;
//             }
//         }
        
//         return head;
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* current = nullptr;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            int digit = sum % 10;
            ListNode* newNode = new ListNode(digit);
            if (head == nullptr) {
                head = newNode;
                current = newNode;
            } else {
                current->next = newNode;
                current = newNode;
            }
        }
        return head;
    }
};
