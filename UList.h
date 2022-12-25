// Charan, S. (2020, November 16). Implementation of unrolled linked list using 
// C++. CodeSpeedy. Retrieved December 4, 2022, 
// from https://www.codespeedy.com/a-c-program-for-unrolled-list/#:~:text=Unrolled%20Linked%20List%20is%20a,also%20decreases%20the%20storage%20requirements. 

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<time.h>
using namespace std;
#define maxlength 1000
//Node contents
struct node
{
 int length;
 int* arr[maxlength];
 node* next;
};
//Class to demonstrate the linked list
class unrolled_list
{   node* first;
    node* last;
public:
    unrolled_list();
    void display_list();

    //My implementation
    //insert node containing arr at the end of the list
    void insert(int *a) {
        node* nod= new node;
        //If the pointer nod isn't created then it means that the machine has insufficient memory
        if(nod==nullptr)
        {
            cout<<"Memory Insufficient!";
            return;
        }
        
        memcpy(nod->arr, a, sizeof(int));
        
        if(first==nullptr) //Case for the first node adition
        {
            first=nod;
            last=first;
            last->next=nullptr;
        }
        else              // Case for adding other nodes
        {
            last->next=nod;
            nod->next=nullptr;
            last=nod;
        }
    }

    //My implementation
    //increment each element of the array by 1
    double increment() {
        clock_t start, end;
        double cpu_time_used = 0;
        if(first==nullptr) //To check if the list is empty
        {
            cout<<"Empty List!";
            return 0;
        }

        node* nod=first;
        while(nod!=nullptr)
        {
            start = clock();
            for(int i=0;i<1000;i++)
                nod->arr[i]+=1;
            end = clock();
            cpu_time_used += ((end - start)/(double)(CLOCKS_PER_SEC/1000));
            nod=nod->next;
        }
        return cpu_time_used;
    }

    //My implementation
    //get length of the array
    int arrLen() {
        return this->first->length;
    }
    
};
//Constructor which initiates the head and tail of the linked list as null 
unrolled_list::unrolled_list()
{
    first=nullptr;
    last=nullptr;
}

//Function to dispaly the linked list items
void unrolled_list::display_list()
{   system("cls");

    int i=1;
    if(first==nullptr)   //To check if the list is empty
    {
        cout<<"Empty List!";
        return;
    }
    node* nod=first;
    while(nod!=nullptr)
    {
        cout<<"Node "<<i<<":"<<endl;
        for(int j=0;j<nod->length;j++)
            cout<<(nod->arr[j])<<" ";
        cout<<endl<<endl;
        i++;
        nod=nod->next;
    }
}