#include <stdio.h>
#include <stdlib.h>

void check_cube(void);
//incompelete
char top[3][3] = {
	'w','y','y',
	'g','w','y',
	'y','b','r'
},front[3][3] = {
	'o','r','g',
	'o','g','r',
	'r','w','y'	
},rear[3][3] = {
	'r','o','r',
	'y','b','o',
	'w','b','w'
},bottom[3][3] = {
	'g','g','o',
	'b','y','w',
	'o','y','o'
},left[3][3] = {
	'b','r','g',
	'w','o','g',
	'g','o','w'
},right[3][3] = {
	'y','r','b',
	'w','r','g',
	'b','b','b'
};

struct side{
    char *face[3][3],*front_face[3][3],*rear_face[3][3],*right_face[3][3],*left_face[3][3],*bottom_face[3][3];
    struct side *side_front,*side_rear,*side_right,*side_left,*side_bottom;
}top_side,front_side,left_side,right_side,rear_side,bottom_side;

void print_cube(){
    printf("top \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", top[row][col]);
        }
        printf("\n");
    }
    printf("front \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", front[row][col]);
        }
        printf("\n");
    }
    printf("left \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", left[row][col]);
        }
        printf("\n");
    }
    printf("rear \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", rear[row][col]);
        }
        printf("\n");
    }
    printf("right \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", right[row][col]);
        }
        printf("\n");
    }
    printf("bottom \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", bottom[row][col]);
        }
        printf("\n");
    }
}

void turn_clockwise(struct side curr_side){
    if ( *curr_side.face[1][1] == top[1][1]){
        printf ("\n turn top face clockwise");
    }
    else if ( *curr_side.face[1][1] == front[1][1]){
        printf ("\n turn front face clockwise");
    }
    else if ( *curr_side.face[1][1] == left[1][1]){
        printf ("\n turn left face clockwise");
    }
    else if ( *curr_side.face[1][1] == rear[1][1]){
        printf ("\n turn rear face clockwise");
    }
    else if ( *curr_side.face[1][1] == right[1][1]){
        printf ("\n turn right face clockwise");
    }
    else if ( *curr_side.face[1][1] == bottom[1][1]){
        printf ("\n turn bottom face clockwise");
    }
    char temp[]={*curr_side.face[0][0],*curr_side.face[0][2],*curr_side.face[2][2],*curr_side.face[2][0]};
        *curr_side.face[0][0] = temp[3];
        *curr_side.face[0][2] = temp[0];
        *curr_side.face[2][2] = temp[1];
        *curr_side.face[2][0] = temp[2];
        temp[0] = *curr_side.face[0][1];
        temp[1] = *curr_side.face[1][2];
        temp[2] = *curr_side.face[2][1];
        temp[3] = *curr_side.face[1][0];
        *curr_side.face[0][1] = temp[3];
        *curr_side.face[1][2] = temp[0];
        *curr_side.face[2][1] = temp[1];
        *curr_side.face[1][0] = temp[2];
        //printf ("\n switching faces");
        for(int i = 0; i < 3; i++){
            temp[0] = *curr_side.rear_face[0][i];
            temp[1] = *curr_side.right_face[0][i];
            temp[2] = *curr_side.front_face[0][i];
            temp[3] = *curr_side.left_face[0][i];
            *curr_side.rear_face[0][i] = temp[3];
            *curr_side.right_face[0][i] = temp[0];
            *curr_side.front_face[0][i] = temp[1];
            *curr_side.left_face[0][i] = temp[2];
        }
        check_cube();   
}

void turn_anticlockwise(struct side curr_side){
    if ( *curr_side.face[1][1] == top[1][1]){
        printf ("\n turn top face anticlockwise");
    }
    else if ( *curr_side.face[1][1] == front[1][1]){
        printf ("\n turn front face anticlockwise");
    }
    else if ( *curr_side.face[1][1] == left[1][1]){
        printf ("\n turn left face anticlockwise");
    }
    else if ( *curr_side.face[1][1] == rear[1][1]){
        printf ("\n turn rear face anticlockwise");
    }
    else if ( *curr_side.face[1][1] == right[1][1]){
        printf ("\n turn right face anticlockwise");
    }
    else if ( *curr_side.face[1][1] == bottom[1][1]){
        printf ("\n turn bottom face anticlockwise");
    }
    char temp[]={*curr_side.face[0][0],*curr_side.face[0][2],*curr_side.face[2][2],*curr_side.face[2][0]};
        *curr_side.face[0][0] = temp[1];
        *curr_side.face[0][2] = temp[2];
        *curr_side.face[2][2] = temp[3];
        *curr_side.face[2][0] = temp[0];
        temp[0] = *curr_side.face[0][1];
        temp[1] = *curr_side.face[1][2];
        temp[2] = *curr_side.face[2][1];
        temp[3] = *curr_side.face[1][0];
        *curr_side.face[0][1] = temp[1];
        *curr_side.face[1][2] = temp[2];
        *curr_side.face[2][1] = temp[3];
        *curr_side.face[1][0] = temp[0];
        //printf ("\n switching faces");
        for(int i = 0; i < 3; i++){
            temp[0] = *curr_side.rear_face[0][i];
            temp[1] = *curr_side.right_face[0][i];
            temp[2] = *curr_side.front_face[0][i];
            temp[3] = *curr_side.left_face[0][i];
            *curr_side.rear_face[0][i] = temp[1];
            *curr_side.right_face[0][i] = temp[2];
            *curr_side.front_face[0][i] = temp[3];
            *curr_side.left_face[0][i] = temp[0];
        }
        check_cube();   
}

void b1(struct side curr_side){
    if ( *curr_side.face[2][1] == *curr_side.face[1][1]){
        turn_clockwise(curr_side);
        turn_clockwise(curr_side);
    }
    else if ( *curr_side.face[2][1] == *curr_side.right_face[1][1]){
        turn_clockwise(*curr_side.side_front);
        turn_clockwise(*curr_side.side_right);
        turn_clockwise(*curr_side.side_right);
    }
    else if ( *curr_side.face[2][1] == *curr_side.bottom_face[1][1]){
        turn_clockwise(*curr_side.side_front);
        turn_clockwise(*curr_side.side_front);
        turn_clockwise(*curr_side.side_bottom);
        turn_clockwise(*curr_side.side_bottom);
    }
    else if ( *curr_side.face[2][1] == *curr_side.left_face[1][1]){
        turn_anticlockwise(*curr_side.side_front);
        turn_clockwise(*curr_side.side_bottom);
        turn_clockwise(*curr_side.side_bottom);
    }

}
void a1 (struct side curr_side){
    turn_clockwise(curr_side);
    turn_clockwise(*curr_side.side_right);
    turn_anticlockwise(curr_side);
    turn_anticlockwise(*curr_side.side_right);
    turn_anticlockwise(*curr_side.side_right);
    turn_anticlockwise(*curr_side.side_front);
    turn_clockwise(*curr_side.side_right);
    b1(curr_side);
}
void a2 (struct side curr_side){
    turn_clockwise(*curr_side.side_left);
    turn_clockwise(*curr_side.side_front);
    turn_anticlockwise(*curr_side.side_left);
    b1(curr_side);
}
void a3 (struct side curr_side){
    turn_clockwise(*curr_side.side_front);
    turn_clockwise(*curr_side.side_right);
    turn_anticlockwise(curr_side);
    turn_anticlockwise(*curr_side.side_right);
    turn_clockwise(curr_side);
    turn_clockwise(curr_side);
    b1(curr_side);
}
void a4 (struct side curr_side){
    turn_anticlockwise(*curr_side.side_right);
    turn_anticlockwise(*curr_side.side_front);
    turn_clockwise(*curr_side.side_right);
    b1(curr_side);
}
void make_cross(){
    if ( front[0][1] == top[1][1] ){
        a1(front_side);
    }
    if ( front[1][0] == top[1][1] ){
        a2(front_side);
    }
    if ( front[2][1] == top[1][1] ){
        a3(front_side);
    }
    if ( front[1][2] == top[1][1] ){
        a4(front_side);

    }if ( left[0][1] == top[1][1] ){
        a1(left_side);
    }
    if ( left[1][0] == top[1][1] ){
        a2(left_side);
    }
    if ( left[2][1] == top[1][1] ){
        a3(left_side);
    }
    if ( left[1][2] == top[1][1] ){
        a4(left_side);
    }
    
    if ( rear[0][1] == top[1][1] ){
        a1(rear_side);
    }
    if ( rear[1][0] == top[1][1] ){
        a2(rear_side);
    }
    if ( rear[2][1] == top[1][1] ){
        a3(rear_side);
    }
    if ( rear[1][2] == top[1][1] ){
        a4(rear_side);
    }

    if ( right[0][1] == top[1][1] ){
        a1(right_side);
    }
    if ( right[1][0] == top[1][1] ){
        a2(right_side);
    }
    if ( right[2][1] == top[1][1] ){
        a3(right_side);
    }
    if ( right[1][2] == top[1][1] ){
        a4(right_side);
    }

    if ( bottom[0][1] == top[1][1] ){
        b1(front_side);
    }
    if ( bottom[1][0] == top[1][1] ){
        b1(left_side);
    }
    if ( bottom[2][1] == top[1][1] ){
        b1(rear_side);
    }
    if ( bottom[1][2] == top[1][1] ){
        b1(right_side);
    }
}
void check_cube(){
	int r=0,w=0,g=0,b=0,o=0,y=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if (top[i][j]=='r')r++;
			else if (top[i][j]=='w')w++;
			else if (top[i][j]=='g')g++;
			else if (top[i][j]=='b')b++;
			else if (top[i][j]=='o')o++;
			else if (top[i][j]=='y')y++;
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if (front[i][j]=='r')r++;
			else if (front[i][j]=='w')w++;
			else if (front[i][j]=='g')g++;
			else if (front[i][j]=='b')b++;
			else if (front[i][j]=='o')o++;
			else if (front[i][j]=='y')y++;
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if (rear[i][j]=='r')r++;
			else if (rear[i][j]=='w')w++;
			else if (rear[i][j]=='g')g++;
			else if (rear[i][j]=='b')b++;
			else if (rear[i][j]=='o')o++;
			else if (rear[i][j]=='y')y++;
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if (bottom[i][j]=='r')r++;
			else if (bottom[i][j]=='w')w++;
			else if (bottom[i][j]=='g')g++;
			else if (bottom[i][j]=='b')b++;
			else if (bottom[i][j]=='o')o++;
			else if (bottom[i][j]=='y')y++;
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if (left[i][j]=='r')r++;
			else if (left[i][j]=='w')w++;
			else if (left[i][j]=='g')g++;
			else if (left[i][j]=='b')b++;
			else if (left[i][j]=='o')o++;
			else if (left[i][j]=='y')y++;
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if (right[i][j]=='r')r++;
			else if (right[i][j]=='w')w++;
			else if (right[i][j]=='g')g++;
			else if (right[i][j]=='b')b++;
			else if (right[i][j]=='o')o++;
			else if (right[i][j]=='y')y++;
		}
	}
	if ((r==9)&&(w==9)&&(g==9)&&(b==9)&&(o==9)&&(y==9)){
		printf("\n CUBE PRESEVERED");
		printf("\n%d %d %d %d %d %d ",r,w,g,b,o,y);
	}
	else {
		print_cube();
		printf("\n CUBE NOT PRESEVERED");
		printf("\n%d %d %d %d %d %d ",r,w,g,b,o,y);
		int cont;
		printf("\n:");scanf("%d",&cont);
	}
}

void print_side(struct side curr_side){
    printf("top \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", *curr_side.face[row][col]);
        }
        printf("\n");
    }
    printf("front \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", *curr_side.front_face[row][col]);
        }
        printf("\n");
    }
    printf("left \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", *curr_side.left_face[row][col]);
        }
        printf("\n");
    }
    printf("rear \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", *curr_side.rear_face[row][col]);
        }
        printf("\n");
    }
    printf("right \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", *curr_side.right_face[row][col]);
        }
        printf("\n");
    }
    printf("bottom \n");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            printf("%c ", *curr_side.bottom_face[row][col]);
        }
        printf("\n");
    }
}

int main(){
    //print_cube();
    //-----------------------------------------setup----------------------------------------------------------------------------------------------------------------------
    //--------------------------------top side-------------------------------------------------
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            top_side.face[row][col] = &top[row][col];
        }
    }
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            top_side.front_face[row][col] = &front[row][col];
        }
    }
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            top_side.rear_face[row][col] = &rear[row][col];
        }
    }
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            top_side.right_face[row][col] = &right[row][col];
        }
    }
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            top_side.left_face[row][col] = &left[row][col];
        }
    }
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            top_side.bottom_face[row][col] = &bottom[row][col];
        }
    }
    //-----------------front side----------------------------------------------
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            front_side.face[row][col] = &front[row][col];
        }
    }
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            front_side.front_face[row][col] = &bottom[row][col];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            front_side.rear_face[row][col] = &top[row_][col_];
        }
    }
    for (int row = 0, row_ = 0; (row < 3)&&(row_ < 3); row++, row_++){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            front_side.right_face[row][col] = &right[col_][row_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 0; (col < 3)&&(col_ < 3); col++, col_++){
            front_side.left_face[row][col] = &left[col_][row_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            front_side.bottom_face[row][col] = &rear[row_][col_];
        }
    }
    //------------------left side----------------------------------------
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            left_side.face[row][col] = &left[row][col];
        }
    }
    for (int row = 0, row_ = 0; (row < 3)&&(row_ <= 2); row++, row_++){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            left_side.front_face[row][col] = &bottom[col_][row_];
        }
    }
    for (int row = 0, row_ = 0; (row < 3)&&(row_ <= 2); row++, row_++){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            left_side.rear_face[row][col] = &top[col_][row_];
        }
    }
    for (int row = 0, row_ = 0; (row < 3)&&(row_ <= 2); row++, row_++){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            left_side.right_face[row][col] = &front[col_][row_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 0; (col < 3)&&(col_ <= 2); col++, col_++){
            left_side.left_face[row][col] = &rear[col_][row_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            left_side.bottom_face[row][col] = &right[row_][col_];
        }
    }
    //----------------------rear side---------------------------------
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            rear_side.face[row][col] = &rear[row][col];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            rear_side.front_face[row][col] = &bottom[row_][col_];
        }
    }
    for (int row = 0, row_ = 0; (row < 3)&&(row_ <= 2); row++, row_++){
        for (int col = 0, col_ = 0; (col < 3)&&(col_ <= 2); col++, col_++){
            rear_side.rear_face[row][col] = &top[row_][col_];
        }
    }
    for (int row = 0, row_ = 0; (row < 3)&&(row_ <= 2); row++, row_++){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            rear_side.right_face[row][col] = &left[col_][row_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 0; (col < 3)&&(col_ <= 2); col++, col_++){
            rear_side.left_face[row][col] = &right[col_][row_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            rear_side.bottom_face[row][col] = &front[row_][col_];
        }
    }
    //-------------------right side--------------------------------------
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            right_side.face[row][col] = &right[row][col];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 0; (col < 3)&&(col_ <= 2); col++, col_++){
            right_side.front_face[row][col] = &bottom[col_][row_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 0; (col < 3)&&(col_ <= 2); col++, col_++){
            right_side.rear_face[row][col] = &top[col_][row_];
        }
    }
    for (int row = 0, row_ = 0; (row < 3)&&(row_ <= 2); row++, row_++){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            right_side.right_face[row][col] = &rear[col_][row_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 0; (col < 3)&&(col_ <= 2); col++, col_++){
            right_side.left_face[row][col] = &front[col_][row_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            right_side.bottom_face[row][col] = &left[row_][col_];
        }
    }
    //------------------------------bottom side---------------------------
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            bottom_side.face[row][col] = &bottom[row][col];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            bottom_side.front_face[row][col] = &rear[row_][col_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            bottom_side.rear_face[row][col] = &front[row_][col_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            bottom_side.right_face[row][col] = &right[row_][col_];
        }
    }
    for (int row = 0, row_ = 2; (row < 3)&&(row_ >= 0); row++, row_--){
        for (int col = 0, col_ = 2; (col < 3)&&(col_ >= 0); col++, col_--){
            bottom_side.left_face[row][col] = &left[row_][col_];
        }
    }
    for (int row = 0, row_ = 0; (row < 3)&&(row_ <= 2); row++, row_++){
        for (int col = 0, col_ = 0; (col < 3)&&(col_ <= 2); col++, col_++){
            bottom_side.bottom_face[row][col] = &top[row_][col_];
        }
    }
    //------------------------referencing sides-----------------------------
    top_side.side_front = &front_side;
    top_side.side_left = &left_side;
    top_side.side_rear = &rear_side;
    top_side.side_right = &right_side;
    top_side.side_bottom = &bottom_side;
    
    front_side.side_front = &bottom_side;
    front_side.side_left = &left_side;
    front_side.side_rear = &top_side;
    front_side.side_right = &right_side;
    front_side.side_bottom = &rear_side;
    
    left_side.side_front = &bottom_side;
    left_side.side_left = &rear_side;
    left_side.side_rear = &top_side;
    left_side.side_right = &front_side;
    left_side.side_bottom = &right_side;
    
    rear_side.side_front = &bottom_side;
    rear_side.side_left = &right_side;
    rear_side.side_rear = &top_side;
    rear_side.side_right = &left_side;
    rear_side.side_bottom = &front_side;
    
    right_side.side_front = &bottom_side;
    right_side.side_left = &front_side;
    right_side.side_rear = &top_side;
    right_side.side_right = &rear_side;
    right_side.side_bottom = &left_side;
    
    bottom_side.side_front = &rear_side;
    bottom_side.side_left = &left_side;
    bottom_side.side_rear = &front_side;
    bottom_side.side_right = &right_side;
    bottom_side.side_bottom = &top_side;
    //-------------------------------------------algorithm-------------------------------------------------------------------------------------------------------------------
    //turn_anticlockwise(*top_side.side_front);
    check_cube();
    printf("\n cube");
    print_cube();
    make_cross();
    printf("\n side");
    print_side(top_side);
    printf("\n side");
    print_side(front_side);
    printf("\n side");
    print_side(left_side);
    printf("\n side");
    print_side(rear_side);
    printf("\n side");
    print_side(right_side);
    printf("\n side");
    print_side(bottom_side);
    return 0;
}
