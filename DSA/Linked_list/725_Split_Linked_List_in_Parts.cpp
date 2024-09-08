#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Function to split the linked list
vector<ListNode *> splitListToParts(ListNode *head, int k)
{
  ListNode *curr = head;
  int L = 0;

  // Step 1: Calculate the total length of the linked list
  while (curr)
  {
    L++;
    curr = curr->next;
  }

  // Step 2: Calculate the number of nodes per part and the remainder nodes
  int eachBucketNodes = L / k; // Nodes per part
  int remainderNodes = L % k;  // Extra nodes to distribute in the first few parts

  // Initialize result vector with null pointers
  vector<ListNode *> result(k, NULL);

  curr = head;
  ListNode *prev = NULL;

  // Step 3: Split the list into k parts
  for (int i = 0; curr && i < k; i++)
  {
    result[i] = curr; // Set the current part's head

    // Traverse 'eachBucketNodes' + 1 if there are still remainder nodes
    for (int count = 1; count <= eachBucketNodes + (remainderNodes > 0 ? 1 : 0); count++)
    {
      prev = curr;
      curr = curr->next;
    }

    // Break the link to the next part
    prev->next = NULL;
    remainderNodes--; // Decrease remainder count after assigning extra nodes
  }

  return result;
}

// Helper function to print a linked list
void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

// Helper function to create a linked list from a vector of values
ListNode *createList(const vector<int> &values)
{
  if (values.empty())
    return NULL;

  ListNode *head = new ListNode(values[0]);
  ListNode *curr = head;

  for (size_t i = 1; i < values.size(); i++)
  {
    curr->next = new ListNode(values[i]);
    curr = curr->next;
  }

  return head;
}

int main()
{
  // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5
  vector<int> values = {1, 2, 3, 4, 5};
  ListNode *head = createList(values);

  // Number of parts
  int k = 3;

  // Call the function to split the list
  vector<ListNode *> result = splitListToParts(head, k);

  // Print the resulting parts
  cout << "Resulting " << k << " parts:" << endl;
  for (int i = 0; i < k; ++i)
  {
    cout << "Part " << i + 1 << ": ";
    if (result[i])
    {
      printList(result[i]);
    }
    else
    {
      cout << "NULL" << endl;
    }
  }

  return 0;
}
