#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Function to rotate the linked list to the right by k places.
ListNode *rotateRight(ListNode *head, int k)
{
  if (!head || !head->next || k == 0)
  {
    // If the list is empty, has only one node, or no rotation is needed, return the head.
    return head;
  }

  ListNode *curr = head;
  int count = 1;

  // Find the length of the list and make it a circular list.
  while (curr->next)
  {
    curr = curr->next;
    count++;
  }

  // Complete the circular list by connecting the last node to the head.
  curr->next = head;

  // Calculate the effective number of rotations needed.
  k = k % count;
  k = count - k;

  // Move to the node just before the new head.
  while (k--)
  {
    curr = curr->next;
  }

  // Set the new head and break the circle.
  head = curr->next;
  curr->next = NULL;

  return head;
}

// Function to print the linked list.
void printList(ListNode *head)
{
  ListNode *temp = head;
  while (temp)
  {
    std::cout << temp->val << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

// Driver code to test the rotateRight function.
int main()
{
  // Create a linked list 1->2->3->4->5.
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  std::cout << "Original list: ";
  printList(head);

  int k = 2;
  head = rotateRight(head, k);

  std::cout << "List after rotating " << k << " places to the right: ";
  printList(head);

  // Cleanup memory.
  ListNode *temp;
  while (head)
  {
    temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}
