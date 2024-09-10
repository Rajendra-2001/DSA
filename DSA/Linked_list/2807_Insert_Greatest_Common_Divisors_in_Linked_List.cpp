#include <iostream>
#include <numeric>
#include <bits/stdc++.h>
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
int gcd(int a, int b)
{
  // Base case: if the second number becomes 0, the first number is the GCD
  while (b != 0)
  {
    int temp = b;
    b = a % b; // Modulus operation
    a = temp;
  }
  return a; // 'a' contains the GCD at the end of the loop
}
ListNode *insertGreatestCommonDivisors(ListNode *head)
{
  ListNode *p = head;

  while (p != nullptr && p->next != nullptr)
  {
    ListNode *q = p->next;
    int gcd_value = gcd(p->val, q->val);      // Calculate GCD of adjacent nodes
    ListNode *temp = new ListNode(gcd_value); // Create a new node with the GCD value
    p->next = temp;                           // Insert the GCD node between p and q
    temp->next = q;                           // Link GCD node to the next node q
    p = q;                                    // Move to the next original node q
  }

  return head;
}

// Helper function to print the linked list
void printList(ListNode *head)
{
  ListNode *curr = head;
  while (curr != nullptr)
  {
    std::cout << curr->val << " -> ";
    curr = curr->next;
  }
  std::cout << "nullptr" << std::endl;
}

int main()
{
  // Create the linked list: 12 -> 15 -> 18
  ListNode *head = new ListNode(12);
  head->next = new ListNode(15);
  head->next->next = new ListNode(18);

  std::cout << "Original List: ";
  printList(head);

  // Insert GCD nodes
  head = insertGreatestCommonDivisors(head);

  std::cout << "Modified List: ";
  printList(head);

  return 0;
}
