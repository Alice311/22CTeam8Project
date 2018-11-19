
#include "BinarySearchTree.h"
#include "Student.h"
#include "HashList.h"

using namespace std;

int compareByID( Student*& l,  Student*& r){
    return l->getStudentID().compare(r->getStudentID());
}

int compareByName(Student*& l, Student*& r){
    return l->getName().compare(r->getName());
}

void display(Student*& stu){
    cout << "Student#" << stu->getStudentID() << " name is " << stu->getName() << endl;;
}

int main(){
    Student* s1 = new Student("20321578", "name 1", "Computer Science", "1111 test ave", 2);
    Student* s2 = new Student("48920123", "name 2", "Computer Science", "1111 test ave", 2);
    Student* s3 = new Student("54281923", "name 3", "Computer Science", "1111 test ave", 2);
    Student* s4 = new Student("12451293", "name 4", "Computer Science", "1111 test ave", 2);
    Student* s5 = new Student("41284932", "name 5", "Computer Science", "1111 test ave", 2);
    Student* s6 = new Student("63473234", "name 6", "Computer Science", "1111 test ave", 2);
    Student* s7 = new Student("58124912", "name 7", "Computer Science", "1111 test ave", 2);
    Student* s8 = new Student("54125890", "name 8", "Computer Science", "1111 test ave", 2);
    Student* s9 = new Student("87654321", "name 9", "Computer Science", "1111 test ave", 2);
    Student* s10 = new Student("15350928", "name 10", "Computer Science", "1111 test ave", 2);
    Student* s11 = new Student("52690863", "name 11", "Computer Science", "1111 test ave", 2);
    Student* s12 = new Student("60982343", "name 12", "Computer Science", "1111 test ave", 2);
    Student* s13 = new Student("32663553", "name 13", "Computer Science", "1111 test ave", 2);
    Student* s14 = new Student("62352142", "name 14", "Computer Science", "1111 test ave", 2);
    Student* s15 = new Student("61389421", "name 15", "Computer Science", "1111 test ave", 2);
    Student* s16 = new Student("98201523", "name 16", "Computer Science", "1111 test ave", 2);

    HashList hash(33);

    hash.goodHashing(s1->getStudentID(), s1);
    hash.goodHashing(s2->getStudentID(), s2);
    hash.goodHashing(s3->getStudentID(), s3);
    hash.goodHashing(s4->getStudentID(), s4);
    hash.goodHashing(s5->getStudentID(), s5);
    hash.goodHashing(s6->getStudentID(), s6);
    hash.goodHashing(s7->getStudentID(), s7);
    hash.goodHashing(s8->getStudentID(), s8);
    hash.goodHashing(s9->getStudentID(), s9);
    hash.goodHashing(s10->getStudentID(), s10);
    hash.goodHashing(s11->getStudentID(), s11);
    hash.goodHashing(s11->getStudentID(), s12);
    hash.goodHashing(s11->getStudentID(), s13);
    hash.goodHashing(s11->getStudentID(), s14);
    hash.goodHashing(s11->getStudentID(), s15);
    hash.goodHashing(s11->getStudentID(), s16);
    hash.debugPrinting();

    cout << "====================" << endl;

    HashList shash(23);
    shash.badHashing(s1->getStudentID(), s1);
    shash.badHashing(s2->getStudentID(), s2);
    shash.badHashing(s3->getStudentID(), s3);
    shash.badHashing(s4->getStudentID(), s4);
    shash.badHashing(s5->getStudentID(), s5);
    shash.badHashing(s6->getStudentID(), s6);
    shash.badHashing(s7->getStudentID(), s7);
    shash.badHashing(s8->getStudentID(), s8);
    shash.badHashing(s9->getStudentID(), s9);
    shash.badHashing(s10->getStudentID(), s10);
    shash.badHashing(s11->getStudentID(), s11);
    shash.badHashing(s11->getStudentID(), s12);
    shash.badHashing(s11->getStudentID(), s13);
    shash.badHashing(s11->getStudentID(), s14);
    shash.badHashing(s11->getStudentID(), s15);
    shash.badHashing(s11->getStudentID(), s16);
    shash.debugPrinting();

/*******
    BinaryNode<Student*> bn1(s1);
    BinaryNode<Student*> bn2(s2);
    BinaryNode<Student*> bn3(s3);
    BinaryNode<Student*> bn4(s4);
    BinaryNode<Student*> bn5(s5);
    BinaryNode<Student*> bn6(s6);
    BinaryNode<Student*> bn7(s7);
    BinaryNode<Student*> bn8(s8);
    BinaryNode<Student*> bn9(s9);
    BinaryNode<Student*> bn10(s10);
    BinaryNode<Student*> bn11(s11);
    BinaryNode<Student*> bn12(s12);
    BinaryNode<Student*> bn13(s13);
    BinaryNode<Student*> bn14(s14);
    BinaryNode<Student*> bn15(s15);
    BinaryNode<Student*> bn16(s16);

    BinarySearchTree<Student*> bst1;
    bst1.insert(s1,compareByID);
    bst1.insert(s2,compareByID);
    bst1.insert(s3,compareByID);
    bst1.insert(s4,compareByID);
    bst1.insert(s5,compareByID);
    bst1.insert(s6,compareByID);
    bst1.insert(s7,compareByID);
    bst1.insert(s8,compareByID);
    bst1.insert(s9,compareByID);
    bst1.insert(s10,compareByID);
    bst1.insert(s11,compareByID);
    bst1.insert(s12,compareByID);
    bst1.insert(s13,compareByID);
    bst1.insert(s14,compareByID);
    bst1.insert(s15,compareByID);
    bst1.insert(s16,compareByID);

    BinarySearchTree<Student*> bst2;
    bst2.insert(s1,compareByName);
    bst2.insert(s2,compareByName);
    bst2.insert(s3,compareByName);
    bst2.insert(s4,compareByName);
    bst2.insert(s5,compareByName);
    bst2.insert(s6,compareByName);
    bst2.insert(s7,compareByName);
    bst2.insert(s8,compareByName);
    bst2.insert(s9,compareByName);
    bst2.insert(s10,compareByName);
    bst2.insert(s11,compareByName);
    bst2.insert(s12,compareByName);
    bst2.insert(s13,compareByName);
    bst2.insert(s14,compareByName);
    bst2.insert(s15,compareByName);
    bst2.insert(s16,compareByName);


    cout << "============BST1===============" << endl;
    bst1.inOrder(display);
    cout << "============BST2===============" << endl;
    bst2.inOrder(display);

    s1->setName("name 222");
    cout << "============BST1===============" << endl;
    bst1.inOrder(display);
    cout << "============BST2===============" << endl;
    bst2.inOrder(display);



    *********/






}

