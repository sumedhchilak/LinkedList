#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void init()
{
    for(int i = 1; i <= 5; i++){
        add(i);
    }
};

struct Node* add(int val)
{
    struct Node *newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node*));
    if(head == NULL){
        return head;
    }
    newNode->data = malloc(sizeof(int));
    if(newNode->data == NULL){
        free(newNode);
        return head;
    }
    if(val < head->data){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else{
        struct Node *curr = head;
        while(curr->next != NULL && curr->data < val){
            curr = curr->next;
        }
        if(curr->next == NULL && curr->data < val){
            curr->next = newNode;
            newNode->prev = curr;
        } else{
            struct Node *previous = curr->prev;
            previous->next = newNode;
            newNode->prev = previous;
            newNode->next = curr;
            curr->prev = newNode;
        }
    }
    return head;
};

struct Node* remove(int val)
{
    struct Node *curr = head;
    if(head == NULL){
        return NULL;
    }
    while(curr){
        if(curr->data == val){
            break;
        }
        curr = curr->next;
    }
    if(curr == head){
        head = head->next;
        head->prev = NULL;
        return curr;
    } else{
        if(curr != NULL){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
    }
    return curr;
};

void main(){
    init();
    add(6);
    add(10);
}