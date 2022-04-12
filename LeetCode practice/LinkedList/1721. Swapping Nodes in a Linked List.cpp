// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    void swapNode(ListNode* n1, ListNode* n2){
        swap(n1->val, n2->val);
    }
    
    ListNode* findMidNode(ListNode* head, int &j, int &n){
        ListNode* fastNode = head;
        while(fastNode && fastNode->next){
            fastNode = fastNode->next->next;
            head = head->next;
            j++;
        }
        
        // if total nodes is odd then fastNode!=null
        if(!fastNode) n=2*j;
        else n= 2*j+1;
        
        return head;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int i=0,j=0,n;
        ListNode *midEvenNode = findMidNode(head, j, n);
        int lIndex = min(k-1, n-k);
        int rIndex = max(k-1, n-k);
        if(lIndex!=rIndex) {
            ListNode *leftNode = head;
            while(lIndex!= i++)
                leftNode = leftNode->next;
            
            ListNode *rightNode = midEvenNode;
            while(rIndex != j++)
                rightNode = rightNode->next;
            
            swapNode(leftNode, rightNode);
        }
        return head;
    }
};