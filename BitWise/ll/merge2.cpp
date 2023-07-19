#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *temp, *head;
        temp = new ListNode;
        temp = list1;

        while (list1->next != NULL || list2->next != NULL)
        {
            if (list1->next != NULL && list2->next != NULL)
            {

                if (list1->val <= list2->val)
                {
                    list1 = list1->next;
                }
                else if (list1->val > list2->val)
                {
                    head = list1;
                    list1=new ListNode;
                    
                    list1->val = list2->val;
                    list1->next = head;
                    temp->next=list1;
                    list2 = list2->next;
                }
            }
            else if (list2->next != NULL)
            {
                list1->next=list2->next;
                list2->next = list1;
                list1=list2;
            }
        }
        return temp;
    }
};
int main()
{

    ListNode *x1 = new ListNode;
    ListNode *x2 = new ListNode;
    Solution a;
    ListNode *t = x1, *y = x2;
    for (int i = 0; i < 3; i++)
    {
        int arr[] = {0, 3, 5};
        x1->val = arr[i];
        if (i != 2)
        {
            x1->next = new ListNode;
            x1 = x1->next;
        }
        else
            x1->next = NULL;
    }
    for (int i = 0; i < 3; i++)
    {
        int arr[] = {2, 3, 4};

        x2->val = arr[i];
        if (i != 2)
        {
            x2->next = new ListNode;
            x2 = x2->next;
        }
        else
            x2->next = NULL;
    }
    a.mergeTwoLists(t, y);

    return 0;
}