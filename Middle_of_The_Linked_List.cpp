// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow=head;
    int n=0;
    while(head){
        n++;
        head=head->next;
        if(n%2==0){
            slow=slow->next;
        }
    }
    return slow;
}

void display(ListNode* head){
    std::cout<<"Linked List: ";
    auto temp=head;
    while(temp){
        if(!temp->next){
            std::cout<<temp->val;
        }else{
           std::cout<<temp->val<<"->"; 
        }
        temp=temp->next;
    }
    std::cout<<std::endl;
}

int main(){
    ListNode* list=new ListNode(1);
    auto head=list;
    int Size=5;
    for(int i=1;i<Size;i++){
        ListNode*temp=new ListNode(i+1);
        list->next=temp;
        // free(temp);
        list=list->next;
    }
    display(head);
    display(middleNode(head));
    return 0;
}