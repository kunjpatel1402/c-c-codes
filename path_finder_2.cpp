#include<iostream>
#include<conio.h>
#include<stdio.h>
int a[23][33]={
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,
    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,
    1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,
    1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
    1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,
    1,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,
    1,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,1,1,0,1,
    1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,1,0,1,
    1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,
    1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,
    1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,
    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};
struct node{
    int x,y;
    node *next;
}*start,*new_ptr,*ptr,*save;

node *create_new_node(int x,int y){
    new_ptr=new node;
    new_ptr->x=x;
    new_ptr->y=y;
    new_ptr->next=NULL;
    return new_ptr;
}
void join_node(node *ptr){
    if (start==NULL){
        start=ptr;
    }
    else{
        ptr->next=start;
        start=ptr;
    }
}
void delete_node(){
    if(start==NULL){
        printf("\n empty list");
    }
    else{
        ptr=start;
        start=start->next;
        delete ptr;
    }
}
int x=1,y=1,solved=1;
void print(int a[23][33]){
    for (int row=0;row<23;row++){
        for(int col=0;col<33;col++){
            printf(" %d",a[row][col]);
        }
        printf("\n");
    }
}
int spread(){
    
    if (a[x][y+1]==0){
        a[x][y+1]=3;
        x=x;
        y=y+1;
        ptr=create_new_node(x,y);
        join_node(ptr);
        printf("\n x:%d",x);
        printf("\n y:%d",y);
    }
    else if (a[x][y+1]==2){
        printf("\n solved");
        printf("\n x:%d",x);
        printf("\n y:%d",y);
        return 0;
    }
    else if(a[x+1][y]==0){
        a[x+1][y]=3;
        x+=1;
        y=y;
        ptr=create_new_node(x,y);
        join_node(ptr);
        printf("\n x:%d",x);
        printf("\n y:%d",y);
    }
    else if(a[x+1][y]==2){
        printf("\n solved");
        printf("\n x:%d",x);
        printf("\n y:%d",y);
        return 0;
    }
    else if(a[x][y-1]==0){
        a[x][y-1]=3;
        x=x;
        y-=1;
        ptr=create_new_node(x,y);
        join_node(ptr);
        printf("\n x:%d",x);
        printf("\n y:%d",y);
    }
    else if(a[x][y-1]==2){
        printf("\n solved");
        printf("\n x:%d",x);
        printf("\n y:%d",y);
        return 0;
    }
    else if(a[x-1][y]==0){
        a[x-1][y]=3;
        x-=1;
        y=y;
        ptr=create_new_node(x,y);
        join_node(ptr);
        printf("\n x:%d",x);
        printf("\n y:%d",y);
    }
    else if(a[x-1][y]==2){
        printf("\n solved");
        printf("\n x:%d",x);
        printf("\n y:%d",y);
        return 0;
    }
    else{
        a[x][y]=4;
        delete_node();
        x=start->x;
        y=start->y;
    }
    printf("\n");
    system("cls");
    //print(a);
    printf("\n");
    return 1;
}
void print_solved(){
    for (int i=0;i<23;i++){
        for (int j=0;j<33;j++){
            if (a[i][j]==1){
                printf("[-]");
            }
            else if((a[i][j]==3)||(a[i][j]==2)){
                printf(" * ");
            }
            else {
                printf("   ");
            }
        }
        printf("\n");
    }
}
int main(){
    system("cls");
    while(solved){
        print_solved();
        //int cont;
        solved = spread();
        //printf("\n cont:");scanf("%d",&cont);
    }
    return 0;
}
