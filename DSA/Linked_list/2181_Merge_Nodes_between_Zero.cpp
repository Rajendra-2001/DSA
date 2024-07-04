#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

int sum(ListNode *p)
{
  int sum = 0;
  while (p != nullptr && p->val != 0)
  {
    sum += p->val;
    p = p->next;
  }
  return sum;
}

ListNode *mergeNodes(ListNode *head)
{
  ListNode *dummy = new ListNode(0); // Create a new dummy node
  ListNode *current = dummy;
  ListNode *p = head->next; // Skip the initial zero node

  while (p != nullptr)
  {
    int segmentSum = sum(p);
    current->next = new ListNode(segmentSum);
    current = current->next;

    // Move p to the next segment (after the next zero)
    while (p != nullptr && p->val != 0)
    {
      p = p->next;
    }
    if (p != nullptr)
    {
      p = p->next; // Skip the zero node
    }
  }

  return dummy->next; // Return the new list, skipping the dummy node
}

int main()
{
  // Create a sample linked list: 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0
  ListNode *head = new ListNode(0);
  head->next = new ListNode(3);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(0);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next->next = new ListNode(2);
  head->next->next->next->next->next->next->next = new ListNode(0);

  ListNode *result = mergeNodes(head);

  // Print the result list
  while (result != nullptr)
  {
    std::cout << result->val << " ";
    result = result->next;
  }

  return 0;
}
