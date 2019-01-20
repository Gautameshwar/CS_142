//LOAD THE LIB
#include<iostream>
using namespace std;

//define the building blocks for dubli
class link{
    public:
    int data;//the stored var
    link* nxt;//ptr to next link
    link* prv;//ptr to previous link
    link(){//default constructor
        data=0;
        nxt=NULL;
        prv=NULL;
    }
    link(int a){//constructor for inputted var
        data=a;
        nxt=NULL;
        prv=NULL;
    }
};

class dubli{//our doubly linkedlist
    public:
    link* head=NULL;//the ptr to the first link in the dubli
    //fn to insert a link in the dubli
    void insertit(int a){
        //create a link in heap and store its address in temp
        link* temp=new link(a);
        //if dubli is empty then the head is the new link
        if(head==NULL){
            head=temp;
        }
        //when dubli has atleast one link in it
        else{
            //our var ptr that moves along the dubli
            link* current=head;
            //go to the last link
            while(current->nxt!=NULL){
                current=current->nxt;
            }
            //make the link b/w current and temp
            current->nxt=temp;
            //make the back link b/w current and temp
            if(current==head)
            temp->prv=head;//head->prv ==NULL. so this separate code!

            else
            temp->prv=current->prv->nxt;
            //done :)
        }
    }
    //fn to insert a link at a desired position
    void insertat(int pos, int a){
        //create a new link in heap and store its var in temp
        link* temp=new link(a);
        //make this fn fool-proof
        if(head==NULL&&pos!=1){
            cout<<"Your dubli is empty!"<<endl;
            return;
        }
        if(pos==1){
            //temp must point to head
            temp->nxt=head;
            //temp is the new head
            head=temp;
        }
        else{
            //our var ptr that moves along the dubli
            link* current=head;
                //move to the desired pos
                for(int i=1;i<pos-1&&current!=NULL;i++){
                    if(current!=NULL)
                    current=current->nxt;
                    //the case when the dubli ends before we reach pos-1
                    if(current==NULL){
                        cout<<"Your dubli is too short for such pos to exist!"<<endl;
                        break;
                    }
                }

                if(current==NULL)//terminate the fn as it is useless to proceed further!
                return;

                //temp points to both its successor and predecessor
                temp->nxt=current->nxt;
                temp->prv=current->prv->nxt;
                //temps successor ad predecessor points to temp
                if(current->nxt!=NULL)//if current is last then NULL doesnt have any prv or nxt prt!
                current->nxt->prv=temp;

                current->nxt=temp;
        }
    }
    //fn to display the dubli
    void display(){
        link* current=head;
        while(current!=NULL){
            cout<<current->data<<"->";
            current=current->nxt;
        }
        cout<<"NULL"<<endl;
    }
    //fn to delete the last link in the dubli
    void deleteit(){
        //when the dubli is empty
        if(head==NULL){
            cout<<"Dubli is empty!"<<endl;
        }
        //otherwise just go the last link
        link* current=head;
        while(current->nxt!=NULL){
            current=current->nxt;
        }
        //take a step back
        current=current->prv;
        //destroy the next link!
        delete current->nxt;
        //point the current next to null
        current->nxt=NULL;
    }
    //fn to delete the link at pos
    void deleteat(int pos){
        //when dubli is empty
        if(head==NULL)
        cout<<"Dubli is empty!"<<endl;

        //our var ptr that moves along the dubli
        link* current=head;
        //if only one link exists
        if(current->nxt==NULL){
            deleteit();
            return;
        }
        //else go to the pos
        for(int i=1;i<pos-1;i++){
            //when some link exists after pos
            if(current->nxt!=NULL)
            current=current->nxt;

            if(current->nxt==NULL){
                cout<<"Dubli is too short for such position to exist to delete!"<<endl;
                break;
            }
        }
        //store the link that currents next points in temp
        link* temp=current->nxt->nxt;
        delete current->nxt;
        //current now points to temp
        current->nxt=temp;
        //temp now points to current
        temp->prv=current;
    }
    //fn to count the no of links in the dubli
    int countit(){
        //go to the last link using loops and add the links one by one to i
        link* current=head;
        int i;
        for(i=0;current!=NULL;i++){
            current=current->nxt;
        }
        return i;
    }
};

//main fn
int main(){
    dubli d1;
    for(int i=1;i<10;i++){
        d1.insertit(i);
    }
    d1.display();
    d1.insertat(3, 777);
    d1.display();
    d1.deleteit();
    d1.display();
    d1.deleteat(4);
    d1.display();
    cout<<d1.countit();
    //terminate the fn
    return 777;
}
