#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int a[9][9]={
    0,7,0,0,0,0,0,0,9,
    5,1,0,4,2,0,6,0,0,
    0,8,0,3,0,0,7,0,0,
    0,0,8,0,0,1,3,7,0,
    0,2,3,0,8,0,0,4,0,
    4,0,0,9,0,0,1,0,0,
    9,6,2,8,0,0,0,3,0,
    0,0,0,0,1,0,4,0,0,
    7,0,0,2,0,3,0,9,6
};
int b[9][9]={
    0,7,0,0,0,0,0,0,9,
    5,1,0,4,2,0,6,0,0,
    0,8,0,3,0,0,7,0,0,
    0,0,8,0,0,1,3,7,0,
    0,2,3,0,8,0,0,4,0,
    4,0,0,9,0,0,1,0,0,
    9,6,2,8,0,0,0,3,0,
    0,0,0,0,1,0,4,0,0,
    7,0,0,2,0,3,0,9,6
};
int check_value(int  a[9][9],int row,int col,int i){
    
        int flag_row=1,flag_col=1,flag_box=1;
        // checking in row
        for(int temp_col=0;temp_col<9;temp_col++){
            if(a[row][temp_col]==i){
                flag_row=0;
                //printf("\n row not clear");
            }
        }
        //checking in col
        for(int temp_row=0;temp_row<9;temp_row++){
            if(a[temp_row][col]==i){
                flag_col=0;
                //printf("\n col not clear");
            }
        }
        //checking in box
        // first three rows
        //printf("\n before boxes");
        if((row<3&&row>=0)&&(col<3&&col>=0)){
            //printf("\n checking box 1");
            for(int box_row=0;box_row<3;box_row++){
                for(int box_col=0;box_col<3;box_col++){
                    if(a[box_row][box_col]==i){
                        flag_box=0;
                        //printf("\n box not clear");
                    }
                }
            }
        }
        else if((row<3&&row>=0)&&(col<6&&col>=3)){
            //printf("\n checking box 2");
            for(int box_row=0;box_row<3;box_row++){
                for(int box_col=3;box_col<6;box_col++){
                    if(a[box_row][box_col]==i){
                        flag_box=0;
                        //printf("\n box not clear");
                    }
                }
            }
        }
        else if((row<3&&row>=0)&&(col<9&&col>=6)){
            //printf("\n checking box 3");
            for(int box_row=0;box_row<3;box_row++){
                for(int box_col=6;box_col<9;box_col++){
                    if(a[box_row][box_col]==i){
                        flag_box=0;
                        //printf("\n box not clear");
                    }
                }
            }
        }
        else if((row<6&&row>=3)&&(col<3&&col>=0)){
            //printf("\n checking box 4");
            for(int box_row=3;box_row<6;box_row++){
                for(int box_col=0;box_col<3;box_col++){
                    if(a[box_row][box_col]==i){
                        flag_box=0;
                        //printf("\n box not clear");
                    }
                }
            }
        }
        else if((row<6&&row>=3)&&(col<6&&col>=3)){
            //printf("\n checking box 5");
            for(int box_row=3;box_row<6;box_row++){
                for(int box_col=3;box_col<6;box_col++){
                    if(a[box_row][box_col]==i){
                        flag_box=0;
                        //printf("\n box not clear");
                    }
                }
            }
        }
        else if((row<6&&row>=3)&&(col<9&&col>=6)){
            //printf("\n checking box 6");
            for(int box_row=3;box_row<6;box_row++){
                for(int box_col=6;box_col<9;box_col++){
                    if(a[box_row][box_col]==i){
                        flag_box=0;
                        //printf("\n box not clear");
                    }
                }
            }
        }
        else if((row<9&&row>=6)&&(col<3&&col>=0)){
            //printf("\n checking box 7");
            for(int box_row=6;box_row<9;box_row++){
                for(int box_col=0;box_col<3;box_col++){
                    if(a[box_row][box_col]==i){
                        flag_box=0;
                        //printf("\n box not clear");
                    }
                }
            }
        }
        else if((row<9&&row>=6)&&(col<6&&col>=3)){
            //printf("\n checking box 8");
            for(int box_row=6;box_row<9;box_row++){
                for(int box_col=3;box_col<6;box_col++){
                    if(a[box_row][box_col]==i){
                        flag_box=0;
                        //printf("\n box not clear");
                    }
                }
            }
        }
        else if((row<9&&row>=6)&&(col<9&&col>=6)){
            //printf("\n checking box 9");
            for(int box_row=6;box_row<9;box_row++){
                for(int box_col=6;box_col<9;box_col++){
                    if(a[box_row][box_col]==i){
                        flag_box=0;
                        //printf("\n box not clear");
                    }
                }
            }
        }
        //printf("\n after boxes");
        //printf("\n i:%d",i);
        if(flag_box&&flag_col&&flag_row){
            //printf("\n before changing(num):%d",num);
            //num++;
            //printf("\n returning:%d",i);
            //printf("\n printing\n");
            system("cls");
            for(int row=0;row<9;row++){
                for(int col=0;col<9;col++){
                    printf("%d ",a[row][col]);
                }
                printf("\n");
            }   
            return i;
        }
    
    /*printf("\n printing\n");
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            printf("%d ",a[row][col]);
        }
        printf("\n");
    }*/
    //printf("\n returning zero");
    return 0;
}
// function to check if sudoku is solved
int check_solved(int a[9][9]){
    for(int row=0;row<9;row++){
        int count=0;
        for(int col=0;col<9;col++){
            switch(a[row][col]){
                case 1:
                count++;
                break;

                case 2:
                count++;
                break;

                case 3:
                count++;
                break;

                case 4:
                count++;
                break;

                case 5:
                count++;
                break;

                case 6:
                count++;
                break;

                case 7:
                count++;
                break;

                case 8:
                count++;
                break;

                case 9:
                count++;
                break;

                default:
                break;
            }
        }
        if(count!=9){
            return 0;
        }
    }
    for(int col=0;col<9;col++){
        int count=0;
        for(int row=0;row<9;row++){
            switch(a[row][col]){
                case 1:
                count++;
                break;

                case 2:
                count++;
                break;

                case 3:
                count++;
                break;

                case 4:
                count++;
                break;

                case 5:
                count++;
                break;

                case 6:
                count++;
                break;

                case 7:
                count++;
                break;

                case 8:
                count++;
                break;

                case 9:
                count++;
                break;

                default:
                break;
            }
        }
        if(count!=9){
            return 0;
        }
    }
    for(int min_box_row=0;min_box_row<9;min_box_row+=3){
        for(int min_box_col=0;min_box_col<9;min_box_col+=3){
            int count=0;
            for(int temp_box_row=min_box_row;temp_box_row<(min_box_row+3);temp_box_row++){
                for(int temp_box_col=min_box_col;temp_box_col<(min_box_col+3);temp_box_col++){
                    switch(a[temp_box_row][temp_box_col]){
                        case 1:
                        count++;
                        break;

                        case 2:
                        count++;
                        break;

                        case 3:
                        count++;
                        break;

                        case 4:
                        count++;
                        break;

                        case 5:
                        count++;
                        break;

                        case 6:
                        count++;
                        break;

                        case 7:
                        count++;
                        break;

                        case 8:
                        count++;
                        break;

                        case 9:
                        count++;
                        break;

                        default:
                        break;

                    }

                }
            }
            if(count!=9){
                return 0;
            }
        }
    }
    return 1;
}
int print_sudoku(int a[9][9]){
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            printf("%d ",a[row][col]);
        }
        printf("\n");
    }
    return 0;
}
int main(){
    system("cls");
    int solved=0;
    do{
        int cont;int count=0;
        printf("\n cont:");scanf("%d",&cont);
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                int value=1,returning_back=0;
                if(returning_back){
                    label:{
                        //printf("\n retruned back");
                        value=a[row][col]+1;
                        if(value==10){
                            a[row][col]=0;
                            goto again;
                        }
                    }
                }
                //printf("\n value:%d",value);
                //printf("\n row:%d",row);
                //printf("\n col:%d",col);
                if(b[row][col]==0){
                    while(value<=9){
                        a[row][col]=check_value(a,row,col,value);
                        if(a[row][col]){
                            goto outside_while;
                        }
                        value++;
                    }
                    outside_while:
                    {}
                    if(a[row][col]==0){
                        again:
                        {}
                        if(col>0){
                            col-=1;
                        }
                        else if(col==0&&row!=0){
                            col=8;
                            row-=1;
                        }
                        if(b[row][col]!=0){
                            goto again;
                        }
                        //printf("\n returning back");
                        returning_back=1;
                        goto label;
                    }
                }
                else{
                    //printf("\n occupied");
                    ;
                }
                int num;
                //printf("\n");
                system("cls");
                num=print_sudoku(a);
                if(count==5000){
                    printf("\n cont:");scanf("%d",&cont);
                    count=0;
                }
                count++;
            }
        }
        solved=check_solved(a);
        if(solved){
            printf("\n SOLVED");
        }
    }while(solved==0);
    return 0;
}