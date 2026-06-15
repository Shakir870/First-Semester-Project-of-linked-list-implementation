#include <iostream>
struct Node
{
    int data;
    Node* next;
};

// Insert at beginning
void insert_begin(Node*& head, int d)
{
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insert_end(Node*& head, int d)
{
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at position
void insert_at(Node*& head, int d, int pos)
{
    if (pos == 1)
    {
        insert_begin(head, d);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        std::cout << "Invalid Position!\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at beginning
void delete_begin(Node*& head)
{
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete at end
void delete_end(Node*& head)
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// Delete at position
void delete_at(Node*& head, int pos)
{
    if (head == NULL)
        return;

    if (pos == 1)
    {
        delete_begin(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
    {
        std::cout << "Invalid Position!\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Delete by data
void delete_data(Node*& head, int d)
{
    if (head == NULL)
        return;

    if (head->data == d)
    {
        delete_begin(head);
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != d)
        temp = temp->next;

    if (temp->next == NULL)
    {
        std::cout << "Data not found!\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Search
Node* Search(Node* head, int d)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data == d)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

// Display
void display(Node* head)
{
    if (head == NULL)
    {
        std::cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }

    std::cout << "NULL\n";
}

int main()
{
    Node* head = NULL;
    int choice, value, pos;
    do
    {
        std::cout << "\n===== LINKED LIST MENU =====\n";
        std::cout << "1. Insert at Beginning\n";
        std::cout << "2. Insert at End\n";
        std::cout << "3. Insert at Position\n";
        std::cout << "4. Delete at Beginning\n";
        std::cout << "5. Delete at End\n";
        std::cout << "6. Delete at Position\n";
        std::cout << "7. Delete by Data\n";
        std::cout << "8. Search\n";
        std::cout << "9. Display\n";
        std::cout << "0. Exit\n";

        std::cout << "Enter Choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                std::cout << "Enter Value: ";
                std::cin >> value;
                insert_begin(head, value);
                break;

            case 2:
                std::cout << "Enter Value: ";
                std::cin >> value;
                insert_end(head, value);
                break;

            case 3:
                std::cout << "Enter Value and Position: ";
                std::cin >> value >> pos;
                insert_at(head, value, pos);
                break;

            case 4:
                delete_begin(head);
                break;

            case 5:
                delete_end(head);
                break;

            case 6:
                std::cout << "Enter Position: ";
                std::cin >> pos;
                delete_at(head, pos);
                break;

            case 7:
                std::cout << "Enter Value to Delete: ";
                std::cin >> value;
                delete_data(head, value);
                break;

            case 8:
                std::cout << "Enter Value to Search: ";
                std::cin >> value;

                if (Search(head, value))
                    std::cout << "Found\n";
                else
                    std::cout << "Not Found\n";
                break;

            case 9:
                display(head);
                break;

            case 0:
                std::cout << "Exiting Program...\n";
                break;

            default:
                std::cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
	

