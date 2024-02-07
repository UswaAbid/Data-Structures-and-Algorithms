
 #include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = NULL;
        }
    }

    // Basic hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node{key, NULL};

        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != NULL) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    // Delete a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = NULL;

        while (current != NULL && current->data != key) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            // Key not found
            return;
        }

        if (prev == NULL) {
            // Key is at the beginning of the linked list
            table[index] = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    // Display the contents of the hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "Bucket " << i << ": ";
            Node* current = table[i];
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;

    // Inserting keys
    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);

    // Display the hash table
    cout << "Hash Table after insertion:" << endl;
    hashTable.display();

    // Searching for a key
    int searchKey = 15;
    if (hashTable.search(searchKey)) {
        cout << "Key " << searchKey << " found in the hash table." << endl;
    } else {
        cout << "Key " << searchKey << " not found in the hash table." << endl;
    }

    // Removing a key
    int removeKey = 15;
    hashTable.remove(removeKey);

    // Display the hash table after removal
    cout << "Hash Table after removal:" << endl;
    hashTable.display();

    return 0;
}

