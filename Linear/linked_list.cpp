// By Eugenius Mario Situmorang
#include "bits/stdc++.h"
#include <iostream>
using namespace std;

class Node {
  public:
    Node* next;
    Node* prev;
    int value;
    // Constructor Node
    Node() {
    }
    Node(Node* p, Node* n, int v) {
      prev = p;
      next = n;
      value = v;
    }
};

// Methods:
// *) is_empty()
// *) get_size()
// *) push_back(int)
// *) push_front(int)
// *) push_after(Node, int)
// *) push_before(Node, int)
// *) pop_back()
// *) pop_front()
// *) pop_after(Node)
// *) pop_before(Node)
// *) print()
// *) print_reverse()
class LinkedList {
  public:
    int size;
    Node* header;
    Node* footer;
    // Inisiasi LinkedList baru
    LinkedList() {
      size = 0;
      header = new Node(NULL, footer, 0);
      footer = new Node(header, NULL, 0);
    }
    // Mengembalikan apakah LinkedList kosong atau tidak
    bool is_empty() {
      return (size == 0);
    }
    // Mengambil ukuran LinkedList
    int get_size() {
      return size;
    }
    // Meletakkan data baru ke belakang LinkedList
    Node* push_back(int value) {
      Node* node = new Node(footer->prev, footer, value);
      footer->prev->next = node;
      footer->prev = node;
      size++;
      return node;
    }
    // Meletakkan data baru ke depan LinkedList
    Node* push_front(int value) {
      Node* node = new Node(header, header->next, value);
      header->next->prev = node;
      header->next = node;
      size++;
      return node;
    }
    // Meletakkan data baru di antara Node p -> New Node -> Other Node
    Node* push_after(Node* p, int value) {
      Node* node = new Node(p, p->next, value);
      p->next->prev = node;
      p->next = node;
      size++;
      return node;
    }
    // Meletakkan data baru di antara Other Node -> New Node -> Node n
    Node* push_before(Node* n, int value) {
      Node* node = new Node(n->prev, n, value);
      n->prev->next = node;
      n->prev = node;
      size++;
      return node;
    }
    // Menghapus data terakhir dari LinkedList
    Node* pop_back() {
      if (size == 0) {
        cout << "[ALERT] LinkedList Kosong - Gagal Pop Back!\n";
        return NULL;
      }
      Node* node = footer->prev;
      footer->prev->prev->next = footer;
      footer->prev = footer->prev->prev;
      size--;
      return node;
    }
    // Menghapus data terdepan dari LinkedList
    Node* pop_front() {
      if (size == 0) {
        cout << "[ALERT] LinkedList Kosong - Gagal Pop Front!\n";
        return NULL;
      }
      Node* node = header->next;
      header->next->next->prev = header;
      header->next = header->next->next;
      size--;
      return node;
    }
    // Menghapus data di antara Node p -> Deleted Node -> Other Node
    Node* pop_after(Node* p) {
      if (size == 0) {
        cout << "[ALERT] LinkedList Kosong - Gagal Pop After!\n";
        return NULL;
      }
      Node* node = p->next;
      p->next->next->prev = p;
      p->next = p->next->next;
      size--;
      return node;
    }
    // Menghapus data di antara Other Node -> Deleted Node -> Node n
    Node* pop_before(Node* n) {
      if (size == 0) {
        cout << "[ALERT] LinkedList Kosong - Gagal Pop Before!\n";
        return NULL;
      }
      Node* node = n->prev;
      n->prev->prev->next = n;
      n->prev = n->prev->prev;
      size--;
      return node;
    }
    // Print LinkedList
    void print() {
      Node* node = header;
      cout << "Header -> ";
      while(node->next != footer) {
        cout << node->next->value << " -> ";
        node = node->next;
      }
      cout << "Footer\n";
    }
    // Print LinkedList dari belakang ke depan
    void print_reverse() {
      Node* node = footer;
      cout << "Footer -> ";
      while(node->prev != header) {
        cout << node->prev->value << " -> ";
        node = node->prev;
      }
      cout << "Header\n";
    }
};

int main() {
  // Inisiasi LinkedList
  LinkedList list;

  // push_back()
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);

  // print() & print_reverse()
  list.print();
  list.print_reverse();

  // push_front()
  list.push_front(8);
  list.push_front(7);
  list.push_front(6);
  list.push_front(5);

  // print() & print_reverse()
  list.print();
  list.print_reverse();

  // pop_back()
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();

  // print() & print_reverse()
  list.print();
  list.print_reverse();

  // pop_front()
  list.pop_front();
  list.pop_front();
  list.pop_front();
  list.pop_front();

  // pop when empty
  list.pop_front();
  list.pop_back();

  // print() & print_reverse()
  list.print();
  list.print_reverse();

  // push_after() & push_before()
  Node* one = list.push_back(1);
  list.push_back(2);
  list.push_after(one, 3);
  list.push_before(one, 4);

  // print() & print_reverse()
  list.print();
  list.print_reverse();

  // pop_after() & pop_before()
  list.pop_after(one);
  list.pop_before(one);

  // print() & print_reverse()
  list.print();
  list.print_reverse();

  return 0;
}