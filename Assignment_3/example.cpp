#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Define a structure for student data
struct Student {
    string lastName;
    string firstName;
    int classGrade;
    Student* left;
    Student* right;

    // Constructor to initialize data
    Student(string lName, string fName, int grade) : lastName(lName), firstName(fName), classGrade(grade), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BST {
private:
    Student* root;

    // Helper function to insert a new student
    Student* insertUtil(Student* node, string lName, string fName, int grade) {
        if (node == nullptr) {
            return new Student(lName, fName, grade);
        }

        if (lName < node->lastName) {
            node->left = insertUtil(node->left, lName, fName, grade);
        } else if (lName > node->lastName) {
            node->right = insertUtil(node->right, lName, fName, grade);
        }

        return node;
    }

    // Helper function to deallocate memory
    void destroyTree(Student* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Destructor
    ~BST() {
        destroyTree(root);
    }

    // Function to insert a new student
    void insert(string lName, string fName, int grade) {
        root = insertUtil(root, lName, fName, grade);
    }
};

// Function to read data from CSV and insert into BST
void readCSVAndInsert(BST& bst, const string& filename) {
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        // Skip header line
        getline(file, line);

        // Read data line by line
        while (getline(file, line)) {
            stringstream ss(line);
            string lName, fName, gradeStr;

            getline(ss, lName, ',');
            getline(ss, fName, ',');
            getline(ss, gradeStr, ',');

            int grade = stoi(gradeStr);

            // Insert into BST
            bst.insert(lName, fName, grade);
        }

        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

int main() {
    BST bst;

    // Read data from CSV and insert into BST
    readCSVAndInsert(bst, "student_data.csv");

    // Perform operations on BST as needed...

    return 0;
}
