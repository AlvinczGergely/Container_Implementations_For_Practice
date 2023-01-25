#include <iostream> 

struct node{            //struck as an element for the linkedList
    int data;
    node *linkNext;
};


class linkiList
{
public:
    linkiList(){ head = NULL;}                  //constructor
    ~linkiList() {};                            //destructor
    void add(int val);                          //plus element
    void toString();                            //print the whoel list     
    void deleteElem(int index);           //delete element at the written position  
    int sizeOf();
private:
    node* head;
};


void linkiList::add(int value){             //add element ot the end of the linked list
    node* newElement = new node(); 
    newElement -> data = value;  
    newElement -> linkNext = NULL;
    if(head == NULL){                       // if we are pasting the first element
        head = newElement;
    }
    else{                                   // if we are pasting the second or more distant element
        node* temp = head;
        if(temp -> linkNext == NULL) 
            temp -> linkNext = newElement;
        else{
            while(temp -> linkNext != NULL){
                temp = temp -> linkNext;
            }
            temp -> linkNext = newElement;
        }
            
    }

}


int linkiList::sizeOf(){
    int counter = 1;
    node* temp = head;
    if(head == NULL){
        return 0;
    }
    while (temp ->linkNext != NULL){
        temp = temp -> linkNext;
        counter ++;
    };
    return counter; 
}

void linkiList::deleteElem(int index){
    if(index <=0 || index > sizeOf()-1){
        std::cout << "The given index is out of range." << index << '\n'   ;
        return;
    }
    if(index == 0){
        delete head; 
    }
    if(index > 0){
        node* temp = head;
        node* prev = NULL;
        for(int i = 1 ; i<=index; i++){
            temp = temp ->linkNext;
            if(i == index-1){
                prev = temp;
            }

        }
        prev ->linkNext = temp ->linkNext;
        delete temp;

    }
    
}



void linkiList::toString(){                                // print the list
    if(head == NULL){
        std::cout << "The list is empty." ;     
    }
    else{
        node* temp = head;
        while (temp != NULL){
            std::cout <<temp->data << ' ';
            temp = temp->linkNext;
        }
        std::cout <<'\n';
    }
}




int main() {

    linkiList* list = new linkiList();
    list->add(5);
    list->add(69);
    list->add(6);
    list->add(563);
    list->add(21);
    list->add(4);

    list->toString();

    
    list ->deleteElem(3);
    list ->deleteElem(-1);
    list ->deleteElem(69);
    


    list->toString();

    std::cout << "The size of the magic list is: " << list->sizeOf();
};