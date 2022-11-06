
#include<iostream>
using namespace std; 
class Nod
{
    public:
    int row;
    int col;
    int data;
    Nod *next;
}; 
//creating a new node
void new_nod(Nod **node, int row_index,
                     int col_index, int z)
{
    Nod *temp = *node;
    Nod *p;     
    
    
    if (temp == NULL)
    {
        temp = new Nod();
        temp->row = row_index;
        temp->col = col_index;
        temp->data = z;
        temp->next = NULL;
        *node = temp;
    }
     
    else
    {
        while (temp->next != NULL){ 
            temp = temp->next;
        }             
        p = new Nod();
        p->row = row_index;
        p->col = col_index;
        p->data = z;
        p->next = NULL;
        temp->next = p;
    }
}
void printList(Nod *start)
{
    Nod *ptr = start;
    cout << "row_pos: ";
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "col_pos: "; 
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "value: ";
    ptr = start;     
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{    
    int sparse_matrix[4][5] = { { 0 , 0 , 3 , 0 , 4 },
                               { 0 , 0 , 5 , 7 , 0 },
                               { 0 , 0 , 0 , 0 , 0 },
                               { 0 , 2 , 6 , 0 , 0 } };     
    
    Nod *first = NULL;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {             
            if (sparse_matrix[i][j] != 0){
                new_nod(&first, i, j,sparse_matrix[i][j]);
            }
        }
    }
    printList(first); 
    return 0;
}
