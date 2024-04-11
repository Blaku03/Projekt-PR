#ifndef SERVER_LINKED_LIST_H
#define SERVER_LINKED_LIST_H

#include <pthread.h>
#include <stdio.h>

typedef struct Node {
    char *content; // Paragraph content
    int locked; // 0 if not locked, 1 if locked
    int socket_id; // ID of the socket that has locked the paragraph
    struct Node* next;
    struct Node* previous;
} Node;


typedef struct LinkedList{
    Node* head;
    Node * tail;
    pthread_mutex_t linked_list_mutex;
}LinkedList;

void initLinkedList(LinkedList *list);
void insert_after_tail(LinkedList *list, char *content);
void insert_before_head(LinkedList* list, char *content);
void insert_after_node_number(LinkedList *list, int node_number, char *content);
void delete(LinkedList* list, char *content);
void print_list(LinkedList* list);
void edit_content_of_paragraph(LinkedList* list, int paragraph_number, char* new_content);
void refresh_file(LinkedList* list, const char *file_name);
int get_socket_id(LinkedList* list, int paragraph_number);
int is_locked(LinkedList* list, int paragraph_number);
void lock_paragraph(LinkedList* list, int paragraph_number, int socket_id);
void unlock_paragraph(LinkedList *list, int paragraph_number, int socket_id);
void parse_file_to_linked_list(LinkedList* list, const char *file_name);
void free_linked_list(LinkedList* list);


#endif //SERVER_LINKED_LIST_H