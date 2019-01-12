//load the lib
#include<iostream>
using namespace std;
//our building blocks of a linklist
class unit{
    public:
    //has two things: the data it stores and the link to the next unit(ptr)
    int data;
    unit* ptr;
    //default constructor
    unit(){
        data=0;
        ptr=NULL;
    }
    //constructor with an input
    unit(int a){
        data=a;
        ptr=NULL;
    }
};
//the linklist with its fns
class lil{
    public:
    //a linklist points to the head of the chain of datas
    unit* head=NULL;
    //a linklist has several fns like:
    //inserting a unit at the end of the linklist
    void insert(int data){
        //first create a unit in heap with this data stored and save its address
        unit* temp=new unit(data);
        //now go to the second last unit in the linklist
        if(head==NULL){//the case when linklist is empty
            head=temp;
        }
        else{//the case when linklist atleast has one unit
            unit* current;
            for(current=head;current->ptr!=NULL;){
                current=current->ptr;
            }
            current->ptr=temp;
        }
    }
    //printing the linklist
    void display(){
        //go to head, print the data and shift the address to the next unit
        unit* current=head;
        for(;current!=NULL;){
            cout<<current->data<<"->";
            current=current->ptr;
        }
        //the linklist ends with a NULL
        cout<<"NULL"<<endl;
    }
    //inserting a unit at a specified location in the linklist
    void insertat(int pos, int data){
        //first create a unit in the heap with the data stored and its address is recorded
        unit* temp=new unit(data);
        //now go to the desired place in the linklist
        unit* current=head;
        //a boolean to verify whether we reached the desired pos or not
        bool exist=1;
        for (int i=1;i<pos-1;i++){
            if(current->ptr!=NULL){//if some unit exists after the current unit
                current=current->ptr;
            }
            else{//otherwise our linklist is too short (i is always < pos-1)
                cout<<"Such position doesnt exist in the linklist"<<endl;
                exist=0;
                break;
            }
        }
        if(exist==1){//this only gets executed if we reach the desired pos
            //now that current holds the desired positions address, we make temps ptr point to currents next unit
            temp->ptr=current->ptr;
            //next point current unit to temp
            current->ptr=temp;
        }
    }
    //a fn to delete the last unit
    void deleteit(){
        //first go to the second last unit of the linklist
         if(head==NULL){//the case when linklist is empty
            cout<<"Linklist is already empty!"<<endl;
        }
        else{//the case when linklist atleast has two units
            unit* current;
            unit* temp;
            for(current=head;current->ptr->ptr!=NULL;){
                current=current->ptr;
            }
            //now that we have reached the second last unit, we store the last units address in temp and point the second last ptr to null
            temp=current->ptr;
            current->ptr=NULL;
            delete temp;
        }
    }
    //a fn to delete at a desired pos
    void deleteat(int pos){
        //first go to that pos
        unit* current=head;
        //a boolean to verify whether we reached the desired pos or not
        bool exist=1;
        for (int i=1;i<pos-1;i++){
            if(current->ptr!=NULL){//if some unit exists after the current unit
                current=current->ptr;
            }
            else{//otherwise our linklist is too short (i is always < pos-1)
                cout<<"Such position doesnt exist in the linklist"<<endl;
                exist=0;
                break;
            }
        }
        if(exist==1){//this only gets executed if we reach the desired pos
            //now that current holds the desired positions address, we store the next units address in temp and point the current unit to null
            unit* temp=current->ptr;
            current->ptr=current->ptr->ptr;
            delete temp;
        }
    }
    //a fn to count no of units in linklist
    int countit(){
        //we create a variable ptr that points to head and then moves to the next unit as each loop is executed
        unit* current=head;
        int i=0;//our data that stores the no of times the loop is executed
        for(;current!=NULL;i++){
            current=current->ptr;
        }
        return i;
    }
};
//main fn
int main(){
    //create a linklist
    lil l1;
    l1.insert(1);
    l1.display();
    l1.insert(5);
    l1.display();
    l1.insert(3);
    l1.insert(66575);
    l1.insert(334);
    l1.display();
    cout<<l1.countit()<<endl;
    l1.insertat(20 , 777);
    l1.display();
    l1.deleteit();
    l1.display();
    l1.deleteat(2);
    l1.display();
    cout<<l1.countit()<<endl;
    //terminate the fn
    return 777;
}
