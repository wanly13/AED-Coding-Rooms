#include <iostream>
#include "solucion.h"
using namespace std;
void test_palindrome1(){
    DoubleList* list = new DoubleList();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->push_back(2);
    list->push_back(1);
    list->display();
    if(list->is_palindrome())
        cout<<"Soy palindrome\n";
    else
        cout<<"No Soy palindrome\n";
}

void test_palindrome2(){
    DoubleList* list = new DoubleList();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->push_back(5);
    list->display();
    if(list->is_palindrome())
        cout<<"Soy palindrome\n";
    else
        cout<<"No Soy palindrome\n";
}



DoubleList* union_list(DoubleList* lista1,DoubleList* lista2){
    struct DoubleList* lista3=new DoubleList;
    struct Node* temp1= lista1->head;
    struct Node* temp2 = lista2->head;
    while (lista1->head->next != NULL || lista2->head->next != NULL){
        if(lista1->head->data == lista2->head->data){
            lista3->push_back(lista1->head->data);
            lista1->head = lista1->head->next;
            lista2->head = lista2->head->next;
        } 
        
        if(lista1->head->data <lista2->head->data  ){
            lista3->push_back(lista1->head->data);
            if(lista1->head->next != NULL)
                    lista1->head = lista1->head->next;
            
        } else {
            lista3->push_back(lista2->head->data);
                if(lista2->head->next != NULL)
                    lista2->head = lista2->head->next;
        }
    }
    lista1->head->data >lista2->head->data ? lista3->push_back(lista1->head->data) : lista3->push_back(lista2->head->data);
    
    lista1->head = temp1; lista2->head = temp2;
    return lista3;
   }

void test_union1(){
    DoubleList* list1 = new DoubleList();
    list1->push_back(2);
    list1->push_back(4);
    list1->push_back(6);
    list1->push_back(8);
    list1->push_back(20);
    DoubleList* list2 = new DoubleList();
    list2->push_back(1);
    list2->push_back(4);
    list2->push_back(8);
    list2->push_back(11);
    DoubleList* list3 = union_list(list1, list2);
    list3->display();
}

int main(){
    test_palindrome1();
    test_palindrome2();
    test_union1();    
}