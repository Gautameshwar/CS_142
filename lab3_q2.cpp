//load the lib
#include<iostream>
using namespace std;

//defining the building blocks of a circular linklist

class unit{
public:
	int data;
	unit* nxt;
	//default constructor
	unit(){
	          nxt=NULL;
	          data=0;
	}
	//valued constructor
	unit(int data){
	          this->data=data;
	          nxt=NULL;
	}
};

//defining the circular linklist along with its functions

class circli{
public:
         unit* head=NULL;
         
         //fn to insert a unit in our circli
         void insertit(int data){
                    //if this is the 1st element then it becomes the head
                    if(head==NULL){
                              head=new unit(data);
                              //it pointss back to head as it is the last unit of the circli
                              head->nxt=head;
                              return;
                    }
                    //if the circli atleast has one element then go to the last element
                    unit* current=head;//our var ptr that moves along the circli
                    while(current->nxt!=head){//as long as we havent reached the last unit
                    	current=current->nxt;
                    }
                    //now make the last unit point to the new unit that is inserted at the end of our circli
                    current->nxt=new unit(data);
                    //the new element points to head as it is the last element
                    current->nxt->nxt=head;                                        
         }
         
         //fn to display our circli
         void display(){
                    //if the user wants to display an empty circli
                    if(head==NULL){
                              cout<<"Your circli is empty!"<<endl;
                              return;
                    }
                    //else print the first units data first and then check if the next unit is head or not...
                    unit* current=head;//our var ptr that moves along the circli
                    cout<<current->data<<"->";
                    current=current->nxt;
                    //now we print all the elements till we reach back head again
                    while(current!=head){
                              cout<<current->data<<"->";
                              current=current->nxt;
                    }
                    cout<<"head"<<endl;
         }
         
         //fn to insert a unit at a desired pos
         void insertat(int pos, int data){
         		if(pos==1&&head==NULL){//when it is inserted at the 1st pos while the circli is empty
         			insertit(data);
         		}
         		if(pos==1&&head!=NULL){//in this case we dont need to go thru the complication of going to the pos as it is the head itself!
         			unit* temp=head;
         			head=new unit(data);
         			head->nxt=temp;
         			return;
         		}
         		else{
         			unit* current=head->nxt;//we start from the 2nd unit as pos is 2 or more if this statement is executed!
         			for(int i=2;i<pos-1;i++){
         				if(current->nxt==head){//if we reach the end of the circli before reaching pos
         					cout<<"circli is too small to pos to exist!"<<endl;
         					break;
         				}
         				else{
         					current=current->nxt;
         				}
         			}
         			//store the next units address in a temporary ptr
         			unit* temp=current->nxt;
         			//insert the new unit after current
         			current->nxt=new unit(data);
         			//make the new unit point to temp
         			current->nxt->nxt=temp;
         		}
         }
         
         //fn to delete the last unit of circli
         void deleteit(){
         		if(head==NULL){//if the circli is empty...
	         		cout<<"Your circli is empty!"<<endl;
	         		return;
         		}
         		//we now take the trouble of again going to the 2nd last unit *sigh*
         		unit* current=head;//our var ptr that moves along the circli
                    while(current->nxt->nxt!=head){//as long as we havent reached the last unit
                    	current=current->nxt;
                    }
                    //delete the last unit
                    delete current->nxt;
                    //now current is the last unit
                    current->nxt=head;
         }
         
         //fn to delete a unit at a desired pos
         void deleteat(int pos){
         		if(head==NULL){
         			cout<<"Your circli is empty!"<<endl;
         			return;
         		}
         		if(pos==1){//if its the 1st pos then no need to go to the pos as it is the head itself!
         			unit* temp=head->nxt;
         			delete head;
         			head=temp;
         			return;
         		}
         		else{
         			unit* current=head->nxt;//we start from the 2nd unit as pos is 2 or more if this statement is executed!
         			for(int i=2;i<pos-1;i++){
         				if(current->nxt==head){//if we reach the end of the circli before reaching pos
         					cout<<"circli is too small to pos to exist!"<<endl;
         					break;
         				}
         				else{
         					current=current->nxt;
         				}
         			}
         			if(current->nxt==head){
	         			//save the address of the 2nd consecutive unit of current in temp
	         			unit* temp=current->nxt->nxt;
	         			//delete the unit
	         			delete current->nxt;
	         			//current now points to temp
	         			current->nxt=temp;
	         		}
	         	}
         }
         
         //fn to count the no of elements in our circli
         int countit(){
         		//if the user wants to display an empty circli
                    if(head==NULL){
                              return 0;
                    }
                    //we start from the 2nd unit
                    unit* current=head->nxt;
                    //now we count the no of units using the for loop and saving it in i
                    int i;
                    for(i=1;current!=head;){
                              current=current->nxt;
                              i++;
                    }
                    return i;
         }
};

//main fn
int main(){
	circli c1;
          for(int i=1;i<=15;i++){
          	c1.insertit(i);
          }
          c1.display();
          c1.insertat(5, 5000);
          c1.display();
          c1.deleteit();
          c1.display();
          c1.deleteat(9);
          c1.display();
          cout<<c1.countit()<<endl;
          return 777;
}
