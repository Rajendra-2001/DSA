#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Definition of the singly linked list node
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int value) : val(value), next(nullptr) {}
};

ListNode *modifiedList(vector<int> &nums, ListNode *head)
{
  unordered_set<int> st(nums.begin(), nums.end()); // Store values to be deleted in a set

  // Handle edge case where head itself needs to be removed
  while (head != nullptr && st.find(head->val) != st.end())
  {
    head = head->next; // Move the head to the next node
  }

  if (!head)
    return nullptr; // If all nodes are removed, return nullptr

  ListNode *temp = head;

  while (temp != nullptr)
  {
    ListNode *next = temp->next;

    // Skip over nodes whose values are in the set
    while (next != nullptr && st.find(next->val) != st.end())
    {
      temp->next = next->next; // Bypass the node
      delete next;             // Free memory
      next = temp->next;       // Move to the next node
    }

    temp = temp->next; // Move temp to the next valid node
  }

  return head;
}

// Helper function to print the list
void printList(ListNode *head)
{
  while (head != nullptr)
  {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

int main()
{
  // Creating a linked list: 1 -> 2 -> 3 -> 4 -> nullptr
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  vector<int> nums = {2, 3}; // We want to remove nodes with values 2 and 3

  cout << "Original list: ";
  printList(head);

  head = modifiedList(nums, head); // Modify the list

  cout << "Modified list: ";
  printList(head);

  return 0;
}
