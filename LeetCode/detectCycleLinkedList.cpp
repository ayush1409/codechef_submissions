// Problem : https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head ;
        
        if(fast == NULL || fast -> next == NULL)
            return false ;
        
        while(fast != NULL){
            fast = fast -> next ;
            
            if(fast == slow)
                return true ;
            
            if(fast != NULL)
                fast = fast -> next ;
            
            if(fast == slow)
                return true ;
            slow = slow -> next ;
        }
        
        return false ;
    }
};
