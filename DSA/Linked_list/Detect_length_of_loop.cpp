#include <iostream>
using namespace std;

// Define the structure of a node in the linked list
struct Node
{
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};

// Function to count the number of nodes in the loop
int countNodesinLoop(Node *head)
{
  if (head == nullptr || head->next == nullptr)
    return 0;

  Node *slow = head;
  Node *fast = head;

  // Detect if a loop exists in the list
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      // A loop is detected, now calculate the loop length
      int loopLength = 1;
      Node *temp = slow;
      while (temp->next != slow)
      {
        loopLength++;
        temp = temp->next;
      }
      return loopLength;
    }
  }

  // No loop found
  return 0;
}

// Helper function to create a loop in the linked list
void createLoop(Node *head, int position)
{
  if (position == 0)
    return;

  Node *temp = head;
  Node *loopStartNode = nullptr;
  int currentPos = 1;

  while (temp->next)
  {
    if (currentPos == position)
    {
      loopStartNode = temp;
    }
    temp = temp->next;
    currentPos++;
  }

  if (loopStartNode)
  {
    temp->next = loopStartNode; // Create a loop
  }
}

int main()
{
  // Create a linked list
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  // Create a loop in the linked list at position 2
  createLoop(head, 2);

  // Test the countNodesinLoop function
  int loopLength = countNodesinLoop(head);
  if (loopLength > 0)
  {
    cout << "Loop detected! Length of the loop is: " << loopLength << endl;
  }
  else
  {
    cout << "No loop detected." << endl;
  }

  return 0;
}
