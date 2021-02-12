#include<stdio.h>
#include<stdlib.h>
//printf("\n:");scanf("%d",&cont); acts as a pause between loops preventing infinite loops so just enter any random integer when you encounter this statement
char top[3][3]={
	'o','b','g',
	'b','w','y',
	'o','y','b'
},front[3][3]={
	'b','g','w',
	'g','r','b',
	'g','g','b'	
},rear[3][3]={
	'y','r','b',
	'r','o','w',
	'g','y','g'
},bottom[3][3]={
	'w','r','r',
	'o','y','o',
	'y','r','o'
},left[3][3]={
	'y','w','w',
	'o','g','w',
	'r','g','r'
},right[3][3]={
	'r','o','o',
	'y','b','w',
	'y','b','w'
};
/*
char top[3][3]={
	'b','w','g',
	'g','w','y',
	'o','g','b'
},front[3][3]={
	'y','o','w',
	'g','r','g',
	'b','b','r'	
},rear[3][3]={
	'y','b','o',
	'r','o','w',
	'g','y','g'
},bottom[3][3]={
	'y','y','w',
	'r','y','o',
	'y','r','o'
},left[3][3]={
	'w','w','b',
	'o','g','r',
	'r','b','r'
},right[3][3]={
	'r','o','o',
	'y','b','w',
	'g','b','w'
};*/
void print_cube(void);
void check_cube(void);
void turn_clockwise_top(){
	printf("\n turn top face clockwise");
	char temp[]={top[0][0],top[0][2],top[2][2],top[2][0]};
	top[0][0]=temp[3];
	top[0][2]=temp[0];
	top[2][2]=temp[1];
	top[2][0]=temp[2];
	temp[0]=top[0][1];
	temp[1]=top[1][2];
	temp[2]=top[2][1];
	temp[3]=top[1][0];
	top[0][1]=temp[3];
	top[1][2]=temp[0];
	top[2][1]=temp[1];
	top[1][0]=temp[2];
	for(int i=0;i<3;i++){
		temp[0]=rear[0][i];
		temp[1]=right[0][i];
		temp[2]=front[0][i];
		temp[3]=left[0][i];
		rear[0][i]=temp[3];
		right[0][i]=temp[0];
		front[0][i]=temp[1];
		left[0][i]=temp[2];
	}
	check_cube();
	//print_cube();
}

void turn_anticlockwise_top(){
	printf("\n turn top face anticlockwise \n");
	char temp[]={top[0][0],top[0][2],top[2][2],top[2][0]};
	top[0][0]=temp[1];
	top[0][2]=temp[2];
	top[2][2]=temp[3];
	top[2][0]=temp[0];
	temp[0]=top[0][1];
	temp[1]=top[1][2];
	temp[2]=top[2][1];
	temp[3]=top[1][0];
	top[0][1]=temp[1];
	top[1][2]=temp[2];
	top[2][1]=temp[3];
	top[1][0]=temp[0];
	for(int i=0;i<3;i++){
		temp[0]=rear[0][i];
		temp[1]=right[0][i];
		temp[2]=front[0][i];
		temp[3]=left[0][i];
		rear[0][i]=temp[1];
		right[0][i]=temp[2];
		front[0][i]=temp[3];
		left[0][i]=temp[0];
	}
	check_cube();
}

void turn_clockwise_rear(){
	printf("\n turn rear face clockwise");
	char temp[]={rear[0][0],rear[0][2],rear[2][2],rear[2][0]};
	rear[0][0]=temp[3];
	rear[0][2]=temp[0];
	rear[2][2]=temp[1];
	rear[2][0]=temp[2];
	temp[0]=rear[0][1];
	temp[1]=rear[1][2];
	temp[2]=rear[2][1];
	temp[3]=rear[1][0];
	rear[0][1]=temp[3];
	rear[1][2]=temp[0];
	rear[2][1]=temp[1];
	rear[1][0]=temp[2];

	temp[0]=right[0][2];
	temp[1]=top[0][0];
	temp[2]=left[2][0];
	temp[3]=bottom[2][2];
	right[0][2]=temp[3];
	top[0][0]=temp[0];
	left[2][0]=temp[1];
	bottom[2][2]=temp[2];

	temp[0]=right[1][2];
	temp[1]=top[0][1];
	temp[2]=left[1][0];
	temp[3]=bottom[2][1];
	right[1][2]=temp[3];
	top[0][1]=temp[0];
	left[1][0]=temp[1];
	bottom[2][1]=temp[2];

	temp[0]=right[2][2];
	temp[1]=top[0][2];
	temp[2]=left[0][0];
	temp[3]=bottom[2][0];
	right[2][2]=temp[3];
	top[0][2]=temp[0];
	left[0][0]=temp[1];
	bottom[2][0]=temp[2];	
	//check_cube();	
}
void turn_anticlockwise_rear(){
	printf("\n turn rear face anticlockwise");
	char temp[]={rear[0][0],rear[0][2],rear[2][2],rear[2][0]};
	rear[0][0]=temp[1];
	rear[0][2]=temp[2];
	rear[2][2]=temp[3];
	rear[2][0]=temp[0];
	temp[0]=rear[0][1];
	temp[1]=rear[1][2];
	temp[2]=rear[2][1];
	temp[3]=rear[1][0];
	rear[0][1]=temp[1];
	rear[1][2]=temp[2];
	rear[2][1]=temp[3];
	rear[1][0]=temp[0];

	temp[0]=right[0][2];
	temp[1]=top[0][0];
	temp[2]=left[2][0];
	temp[3]=bottom[2][2];
	right[0][2]=temp[1];
	top[0][0]=temp[2];
	left[2][0]=temp[3];
	bottom[2][2]=temp[0];

	temp[0]=right[1][2];
	temp[1]=top[0][1];
	temp[2]=left[1][0];
	temp[3]=bottom[2][1];
	right[1][2]=temp[1];
	top[0][1]=temp[2];
	left[1][0]=temp[3];
	bottom[2][1]=temp[0];

	temp[0]=right[2][2];
	temp[1]=top[0][2];
	temp[2]=left[0][0];
	temp[3]=bottom[2][0];
	right[2][2]=temp[1];
	top[0][2]=temp[2];
	left[0][0]=temp[3];
	bottom[2][0]=temp[0];
	check_cube();		
}

void turn_clockwise_front(){
	printf("\n turn front face clockwise");
	char temp[]={front[0][0],front[0][2],front[2][2],front[2][0]};
	front[0][0]=temp[3];
	front[0][2]=temp[0];
	front[2][2]=temp[1];
	front[2][0]=temp[2];
	temp[0]=front[0][1];
	temp[1]=front[1][2];
	temp[2]=front[2][1];
	temp[3]=front[1][0];
	front[0][1]=temp[3];
	front[1][2]=temp[0];
	front[2][1]=temp[1];
	front[1][0]=temp[2];

	temp[0]=top[2][0];
	temp[1]=right[0][0];
	temp[2]=bottom[0][2];
	temp[3]=left[2][2];
	top[2][0]=temp[3];
	right[0][0]=temp[0];
	bottom[0][2]=temp[1];
	left[2][2]=temp[2];
	
	temp[0]=top[2][1];
	temp[1]=right[1][0];
	temp[2]=bottom[0][1];
	temp[3]=left[1][2];
	top[2][1]=temp[3];
	right[1][0]=temp[0];
	bottom[0][1]=temp[1];
	left[1][2]=temp[2];
	
	temp[0]=top[2][2];
	temp[1]=right[2][0];
	temp[2]=bottom[0][0];
	temp[3]=left[0][2];
	top[2][2]=temp[3];
	right[2][0]=temp[0];
	bottom[0][0]=temp[1];
	left[0][2]=temp[2];
	check_cube();

}
void turn_anticlockwise_front(){
	printf("\n turn front face anticlockwise");
	char temp[]={front[0][0],front[0][2],front[2][2],front[2][0]};
	front[0][0]=temp[1];
	front[0][2]=temp[2];
	front[2][2]=temp[3];
	front[2][0]=temp[0];
	temp[0]=front[0][1];
	temp[1]=front[1][2];
	temp[2]=front[2][1];
	temp[3]=front[1][0];
	front[0][1]=temp[1];
	front[1][2]=temp[2];
	front[2][1]=temp[3];
	front[1][0]=temp[0];

	temp[0]=top[2][0];
	temp[1]=right[0][0];
	temp[2]=bottom[0][2];
	temp[3]=left[2][2];
	top[2][0]=temp[1];
	right[0][0]=temp[2];
	bottom[0][2]=temp[3];
	left[2][2]=temp[0];
	
	temp[0]=top[2][1];
	temp[1]=right[1][0];
	temp[2]=bottom[0][1];
	temp[3]=left[1][2];
	top[2][1]=temp[1];
	right[1][0]=temp[2];
	bottom[0][1]=temp[3];
	left[1][2]=temp[0];
	
	temp[0]=top[2][2];
	temp[1]=right[2][0];
	temp[2]=bottom[0][0];
	temp[3]=left[0][2];
	top[2][2]=temp[1];
	right[2][0]=temp[2];
	bottom[0][0]=temp[3];
	left[0][2]=temp[0];
	check_cube();
}
int i=0;
void turn_clockwise_bottom(){
	printf("\n turn bottom face clockwise");
	char temp[]={bottom[0][0],bottom[0][2],bottom[2][2],bottom[2][0]};
	bottom[0][0]=temp[3];
	bottom[0][2]=temp[0];
	bottom[2][2]=temp[1];
	bottom[2][0]=temp[2];
	temp[0]=bottom[0][1];
	temp[1]=bottom[1][2];
	temp[2]=bottom[2][1];
	temp[3]=bottom[1][0];
	bottom[0][1]=temp[3];
	bottom[1][2]=temp[0];
	bottom[2][1]=temp[1];
	bottom[1][0]=temp[2];
	
	temp[0]=front[2][0];
	temp[1]=right[2][0];
	temp[2]=rear[2][0];
	temp[3]=left[2][0];
	front[2][0]=temp[3];
	right[2][0]=temp[0];
	rear[2][0]=temp[1];
	left[2][0]=temp[2];
	
	temp[0]=front[2][1];
	temp[1]=right[2][1];
	temp[2]=rear[2][1];
	temp[3]=left[2][1];
	front[2][1]=temp[3];
	right[2][1]=temp[0];
	rear[2][1]=temp[1];
	left[2][1]=temp[2];
	
	temp[0]=front[2][2];
	temp[1]=right[2][2];
	temp[2]=rear[2][2];
	temp[3]=left[2][2];
	front[2][2]=temp[3];
	right[2][2]=temp[0];
	rear[2][2]=temp[1];
	left[2][2]=temp[2];
	check_cube();
}
void turn_anticlockwise_bottom(){
	printf("\n turn bottom face anticlockwise");
	char temp[]={bottom[0][0],bottom[0][2],bottom[2][2],bottom[2][0]};
	bottom[0][0]=temp[1];
	bottom[0][2]=temp[2];
	bottom[2][2]=temp[3];
	bottom[2][0]=temp[0];
	temp[0]=bottom[0][1];
	temp[1]=bottom[1][2];
	temp[2]=bottom[2][1];
	temp[3]=bottom[1][0];
	bottom[0][1]=temp[1];
	bottom[1][2]=temp[2];
	bottom[2][1]=temp[3];
	bottom[1][0]=temp[0];

	temp[0]=front[2][0];
	temp[1]=right[2][0];
	temp[2]=rear[2][0];
	temp[3]=left[2][0];
	front[2][0]=temp[1];
	right[2][0]=temp[2];
	rear[2][0]=temp[3];
	left[2][0]=temp[0];
	
	temp[0]=front[2][1];
	temp[1]=right[2][1];
	temp[2]=rear[2][1];
	temp[3]=left[2][1];
	front[2][1]=temp[1];
	right[2][1]=temp[2];
	rear[2][1]=temp[3];
	left[2][1]=temp[0];
	
	temp[0]=front[2][2];
	temp[1]=right[2][2];
	temp[2]=rear[2][2];
	temp[3]=left[2][2];
	front[2][2]=temp[1];
	right[2][2]=temp[2];
	rear[2][2]=temp[3];
	left[2][2]=temp[0];
	check_cube();
}
void turn_clockwise_right(){
	printf("\n turn right face clockwise");
	char temp[]={right[0][0],right[0][2],right[2][2],right[2][0]};
	right[0][0]=temp[3];
	right[0][2]=temp[0];
	right[2][2]=temp[1];
	right[2][0]=temp[2];
	temp[0]=right[0][1];
	temp[1]=right[1][2];
	temp[2]=right[2][1];
	temp[3]=right[1][0];
	right[0][1]=temp[3];
	right[1][2]=temp[0];
	right[2][1]=temp[1];
	right[1][0]=temp[2];

	temp[0]=top[2][2];
	temp[1]=rear[0][0];
	temp[2]=bottom[2][2];
	temp[3]=front[2][2];
	top[2][2]=temp[3];
	rear[0][0]=temp[0];
	bottom[2][2]=temp[1];
	front[2][2]=temp[2];
	
	temp[0]=top[1][2];
	temp[1]=rear[1][0];
	temp[2]=bottom[1][2];
	temp[3]=front[1][2];
	top[1][2]=temp[3];
	rear[1][0]=temp[0];
	bottom[1][2]=temp[1];
	front[1][2]=temp[2];

	temp[0]=top[0][2];
	temp[1]=rear[2][0];
	temp[2]=bottom[0][2];
	temp[3]=front[0][2];
	top[0][2]=temp[3];
	rear[2][0]=temp[0];
	bottom[0][2]=temp[1];
	front[0][2]=temp[2];
	
	check_cube();
}
void turn_anticlockwise_right(){
	printf("\n turn right face anticlockwise");
	char temp[]={right[0][0],right[0][2],right[2][2],right[2][0]};
	right[0][0]=temp[1];
	right[0][2]=temp[2];
	right[2][2]=temp[3];
	right[2][0]=temp[0];
	temp[0]=right[0][1];
	temp[1]=right[1][2];
	temp[2]=right[2][1];
	temp[3]=right[1][0];
	right[0][1]=temp[1];
	right[1][2]=temp[2];
	right[2][1]=temp[3];
	right[1][0]=temp[0];

	temp[0]=top[2][2];
	temp[1]=rear[0][0];
	temp[2]=bottom[2][2];
	temp[3]=front[2][2];
	top[2][2]=temp[1];
	rear[0][0]=temp[2];
	bottom[2][2]=temp[3];
	front[2][2]=temp[0];
	
	temp[0]=top[1][2];
	temp[1]=rear[1][0];
	temp[2]=bottom[1][2];
	temp[3]=front[1][2];
	top[1][2]=temp[1];
	rear[1][0]=temp[2];
	bottom[1][2]=temp[3];
	front[1][2]=temp[0];

	temp[0]=top[0][2];
	temp[1]=rear[2][0];
	temp[2]=bottom[0][2];
	temp[3]=front[0][2];
	top[0][2]=temp[1];
	rear[2][0]=temp[2];
	bottom[0][2]=temp[3];
	front[0][2]=temp[0];
	
	check_cube();
}
void turn_clockwise_left(){
	printf("\n turn left face clockwise");
	char temp[]={left[0][0],left[0][2],left[2][2],left[2][0]};
	left[0][0]=temp[3];
	left[0][2]=temp[0];
	left[2][2]=temp[1];
	left[2][0]=temp[2];
	temp[0]=left[0][1];
	temp[1]=left[1][2];
	temp[2]=left[2][1];
	temp[3]=left[1][0];
	left[0][1]=temp[3];
	left[1][2]=temp[0];
	left[2][1]=temp[1];
	left[1][0]=temp[2];

	temp[0]=top[0][0];
	temp[1]=front[0][0];
	temp[2]=bottom[0][0];
	temp[3]=rear[2][2];
	top[0][0]=temp[3];
	front[0][0]=temp[0];
	bottom[0][0]=temp[1];
	rear[2][2]=temp[2];
	
	temp[0]=top[1][0];
	temp[1]=front[1][0];
	temp[2]=bottom[1][0];
	temp[3]=rear[1][2];
	top[1][0]=temp[3];
	front[1][0]=temp[0];
	bottom[1][0]=temp[1];
	rear[1][2]=temp[2];
	
	temp[0]=top[2][0];
	temp[1]=front[2][0];
	temp[2]=bottom[2][0];
	temp[3]=rear[0][2];
	top[2][0]=temp[3];
	front[2][0]=temp[0];
	bottom[2][0]=temp[1];
	rear[0][2]=temp[2];	
	check_cube();
}
void turn_anticlockwise_left(){
	printf("\n turn left face anticlockwise");
	char temp[]={left[0][0],left[0][2],left[2][2],left[2][0]};
	left[0][0]=temp[1];
	left[0][2]=temp[2];
	left[2][2]=temp[3];
	left[2][0]=temp[0];
	temp[0]=left[0][1];
	temp[1]=left[1][2];
	temp[2]=left[2][1];
	temp[3]=left[1][0];
	left[0][1]=temp[1];
	left[1][2]=temp[2];
	left[2][1]=temp[3];
	left[1][0]=temp[0];

	temp[0]=top[0][0];
	temp[1]=front[0][0];
	temp[2]=bottom[0][0];
	temp[3]=rear[2][2];
	top[0][0]=temp[1];
	front[0][0]=temp[2];
	bottom[0][0]=temp[3];
	rear[2][2]=temp[0];
	
	temp[0]=top[1][0];
	temp[1]=front[1][0];
	temp[2]=bottom[1][0];
	temp[3]=rear[1][2];
	top[1][0]=temp[1];
	front[1][0]=temp[2];
	bottom[1][0]=temp[3];
	rear[1][2]=temp[0];
	
	temp[0]=top[2][0];
	temp[1]=front[2][0];
	temp[2]=bottom[2][0];
	temp[3]=rear[0][2];
	top[2][0]=temp[1];
	front[2][0]=temp[2];
	bottom[2][0]=temp[3];
	rear[0][2]=temp[0];	
	check_cube();
}
void print_cube(){
	printf("\n top \n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%c ",top[i][j]);
		}
		printf("\n");
	}
	
	printf("\n front \n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%c ",front[i][j]);
		}
		printf("\n");
	}
	
	printf("\n rear \n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%c ",rear[i][j]);
		}
		printf("\n");
	}
	
	printf("\n bottom \n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%c ",bottom[i][j]);
		}
		printf("\n");
	}
	
	printf("\n left \n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%c ",left[i][j]);
		}
		printf("\n");
	}
	
	printf("\n right \n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%c ",right[i][j]);
		}
		printf("\n");
	}
}

void create_cross(){
	//top
	if (top[0][1]==top[1][1]){
		if (rear[0][1]==rear[1][1]){
			;
		}
		else if(rear[0][1]==right[1][1]){
			turn_clockwise_top();
		}
		else if (rear[0][1]==front[1][1]){
			turn_clockwise_top();
			turn_clockwise_top();
		}
		else if (rear[0][1]==left[1][1]){
			//turn_clockwise_top();
			//turn_clockwise_top();
			//turn_clockwise_top();
			turn_anticlockwise_top();
		}
	}
	if (top[1][2]==top[1][1]){
		if (right[0][1]==right[1][1]){
			;
		}
		else if(right[0][1]==front[1][1]){
			turn_clockwise_top();
		}
		else if(right[0][1]==left[1][1]){
			turn_clockwise_top();
			turn_clockwise_top();
		}
		else if(right[0][1]==rear[1][1]){
			//turn_clockwise_top();
			//turn_clockwise_top();
			//turn_clockwise_top();
			turn_anticlockwise_top();
		}
	}
	if (top[2][1]==top[1][1]){
		if(front[0][1]==front[1][1]){
			;
		}
		else if(front[0][1]==left[1][1]){
			turn_clockwise_top();
		}
		else if(front[0][1]==rear[1][1]){
			turn_clockwise_top();
			turn_clockwise_top();
		}
		else if(front[0][1]==right[1][1]){
			//turn_clockwise_top();
			//turn_clockwise_top();
			//turn_clockwise_top();
			turn_anticlockwise_top();
		}
	}
	if (top[1][0]==top[1][1]){
		if (left[0][1]==left[1][1]){
			;
		}
		else if (left[0][1]==rear[1][1]){
			turn_clockwise_top();
		}
		else if(left[0][1]==right[1][1]){
			turn_clockwise_top();
			turn_clockwise_top();
		}
		else if(left[0][1]==front[1][1]){
			//turn_clockwise_top();
			//turn_clockwise_top();
			//turn_clockwise_top();
			turn_anticlockwise_top();
		}
	}
	//front
	if (front[0][1]==top[1][1]){
		if(top[2][1]==front[1][1]){
			//turn_clockwise_top();
			//turn_clockwise_top();
			//turn_clockwise_top();
			turn_anticlockwise_top();
			//turn_clockwise_right();
			//turn_clockwise_right();
			//turn_clockwise_right();
			turn_anticlockwise_right();			
		}
		else if(top[2][1]==right[1][1]){
			turn_clockwise_front();
			turn_clockwise_right();
		}
		else if(top[2][1]==left[1][1]){
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_top();
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
		}
		else if(top[2][1]==rear[1][1]){
			turn_clockwise_front();
			//turn_clockwise_right();
			//turn_clockwise_right();
			//turn_clockwise_right();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
		}
	}
	if(front[1][2]==top[1][1]){
		if(right[1][0]==right[1][1]){
			turn_clockwise_right();
		}
		else if(right[1][0]==front[1][1]){
			turn_clockwise_right();
			turn_clockwise_top();
		}
		else if(right[1][0]==left[1][1]){
			turn_clockwise_front();
			turn_clockwise_front();
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
		}
		else if(right[1][0]==rear[1][1]){
			//turn_clockwise_right();
			//turn_clockwise_right();
			//turn_clockwise_right();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_rear();
		}
	}
	if (front[2][1]==top[1][1]){
		if (bottom[0][1]==right[1][1]){
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
			turn_clockwise_right();
		}
		else if(bottom[0][1]==left[1][1]){
			turn_clockwise_front();
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
		}
		else if(bottom[0][1]==front[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_right();
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
		}
		else if(bottom[0][1]==rear[1][1]){
			turn_clockwise_bottom();
			//turn_clockwise_right();
			//turn_clockwise_right();
			//turn_clockwise_right();
			turn_anticlockwise_right();
			turn_clockwise_rear();
		}
	}
	if (front[1][0]==top[1][1]){
		if(left[1][2]==left[1][1]){
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
		}
		else if(left[1][2]==front[1][1]){
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_front();
		}
		else if(left[1][2]==right[1][1]){
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
	}
	//right
	if (right[0][1]==top[1][1]){
		if(top[1][2]==front[1][1]){
			//turn_clockwise_right();
			//turn_clockwise_right();
			//turn_clockwise_right();
			turn_anticlockwise_right();
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
		}
		else if(top[1][2]==right[1][1]){
			turn_clockwise_right();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			turn_anticlockwise_rear();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
		else if(top[1][2]==rear[1][1]){
			turn_clockwise_right();
			turn_clockwise_rear();
		}
		else if(top[1][2]==left[1][1]){
			turn_clockwise_right();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			turn_anticlockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_left();
		}
	}
	if (right[1][2]==top[1][1]){
		if(rear[1][0]==rear[1][1]){
			turn_clockwise_rear();
		}
		else if(rear[1][0]==right[1][1]){
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			turn_anticlockwise_rear();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
		else if(rear[1][0]==front[1][1]){
			turn_clockwise_right();
			turn_clockwise_right();
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
		}
		else if(rear[1][0]==left[1][1]){
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			turn_anticlockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_left();
		}
	}
	if (right[2][1]==top[1][1]){
		if(bottom[1][2]==front[1][1]){
			turn_clockwise_right();
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
		}
		else if(bottom[1][2]==rear[1][1]){
			//turn_clockwise_right();
			//turn_clockwise_right();
			//turn_clockwise_right();
			turn_anticlockwise_right();
			turn_clockwise_rear();
		}
		else if(bottom[1][2]==right[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_rear();
			//turn_clockwise_right();
			//turn_clockwise_right();
			//turn_clockwise_right();
			turn_anticlockwise_right();
		}
		else if(bottom[1][2]==left[1][1]){
			turn_clockwise_right();
			turn_clockwise_front();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_left();
		}
	}
	if (right[1][0]==top[1][1]){
		if(front[1][2]==front[1][1]){
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_clockwise_front();
		}
		else if(front[1][2]==right[1][1]){
			turn_clockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
		else if(front[1][2]==left[1][1]){
			turn_clockwise_front();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_left();
		}
		else if(front[1][2]==rear[1][1]){
			turn_clockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_rear();
		}
	}
	//rear
	if (rear[0][1]==top[1][1]){
		if (top[0][1]==left[1][1]){
			turn_clockwise_rear();
			turn_clockwise_left();
		}
		else if(top[0][1]==right[1][1]){
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			turn_anticlockwise_rear();
			//turn_clockwise_right();
			//turn_clockwise_right();
			//turn_clockwise_right();
			turn_anticlockwise_right();
		}
		else if(top[0][1]==rear[1][1]){
			turn_clockwise_rear();
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_rear();
		}
		else if(top[0][1]==front[1][1]){
			turn_clockwise_rear();
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_front();
		}
	} 
	if(rear[1][2]==top[1][1]){
		if(left[1][0]==left[1][1]){
			turn_clockwise_left();
		}
		else if(left[1][0]==rear[1][1]){
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_rear();
		}
		else if(left[1][0]==front[1][1]){
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_front();
		}
		else if(left[1][0]==right[1][1]){
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
	}
	if (rear[2][1]==top[1][1]){
		if(bottom[2][1]==left[1][1]){
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			turn_anticlockwise_rear();
			turn_clockwise_left();
		}
		else if(bottom[2][1]==right[1][1]){
			turn_clockwise_rear();
			//turn_clockwise_right();
			//turn_clockwise_right();
			//turn_clockwise_right();
			turn_anticlockwise_right();
		}
		else if(bottom[2][1]==front[1][1]){
			turn_clockwise_rear();
			turn_clockwise_right();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_front();
		}
		else if(bottom[2][1]==rear[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_left();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			turn_anticlockwise_rear();
		}		
	}
	if(rear[1][0]==top[1][1]){
		if(right[1][2]==rear[1][1]){
			turn_clockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_rear();
		}
		else if(right[1][2]==right[1][1]){
			//turn_clockwise_right();
			//turn_clockwise_right();
			//turn_clockwise_right();
			turn_anticlockwise_right();
		}
		else if(right[1][2]==front[1][1]){
			turn_clockwise_right();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_front();
		}
		else if(right[1][2]==left[1][1]){
			turn_clockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_left();
		}
	}
	//bottom
	if(bottom[0][1]==top[1][1]){
		if(front[2][1]==front[1][1]){
			turn_clockwise_front();
			turn_clockwise_front();
		}
		else if(front[2][1]==right[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
		else if (front[2][1]==left[1][1]){
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_left();
		}
		else if(front[2][1]==rear[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_rear();
		}
	}
	if(bottom[1][2]==top[1][1]){
		if(right[2][1]==right[1][1]){
			turn_clockwise_right();
			turn_clockwise_right();
		}
		else if(right[2][1]==front[1][1]){
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_front();
		}
		else if(right[2][1]==rear[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_rear();
		}
		else if(right[2][1]==left[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_left();
		}
	}
	if(bottom[2][1]==top[1][1]){
		if(rear[2][1]==rear[1][1]){
			turn_clockwise_rear();
			turn_clockwise_rear();
		}
		else if(rear[2][1]==left[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_left();
		}
		else if(rear[2][1]==front[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_front();
		}
		else if(rear[2][1]==right[1][1]){
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
	}
	if(bottom[1][0]==top[1][1]){
		if(left[2][1]==left[1][1]){
			turn_clockwise_left();
			turn_clockwise_left();
		}
		else if(left[2][1]==front[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_front();
		}
		else if(left[2][1]==right[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
		else if(left[2][1]==rear[1][1]){
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_rear();
		}
	}
	//left
	if(left[0][1]==top[1][1]){
		if(top[1][0]==front[1][1]){
			turn_clockwise_left();
			turn_clockwise_front();
		}
		else if(top[1][0]==right[1][1]){
			turn_clockwise_left();
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
		else if(top[1][0]==left[1][1]){
			turn_clockwise_top();
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
		}
		else if(top[1][0]==rear[1][1]){
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			turn_anticlockwise_rear();
		}
	}
	if(left[1][2]==top[1][1]){
		if(front[1][0]==front[1][1]){
			turn_clockwise_front();
		}
		else if(front[1][0]==right[1][1]){
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
		else if(front[1][0]==rear[1][1]){
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_rear();

		}
		else if(front[1][0]==left[1][1]){
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_left();
		}
	}
	if(left[2][1]==top[1][1]){
		if(bottom[1][0]==front[1][1]){
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
			turn_clockwise_front();
		}
		else if(bottom[1][0]==right[1][1]){
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
		else if(bottom[1][0]==rear[1][1]){
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_rear();
		}
		else if(bottom[1][0]==left[1][1]){
			//turn_clockwise_left();
			//turn_clockwise_left();
			//turn_clockwise_left();
			turn_anticlockwise_left();
			//turn_clockwise_front();
			//turn_clockwise_front();
			//turn_clockwise_front();
			turn_anticlockwise_front();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_left();
		}
	}
	if (left[1][0]==top[1][1]){
		if(rear[1][2]==rear[1][1]){
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			//turn_clockwise_rear();
			turn_anticlockwise_rear();
		}
		else if(rear[1][2]==left[1][1]){
			turn_clockwise_rear();
			turn_clockwise_bottom();
		}
		else if(rear[1][2]==front[1][1]){
			turn_clockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_front();
		}
		else if(rear[1][2]==right[1][1]){
			turn_clockwise_rear();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			//turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
		}
	}
}
int check_cross(){
	int flag=0;
	if ((top[0][1]==top[1][1])&&(rear[0][1]==rear[1][1])){
		flag++;
	}
	if ((top[1][2]==top[1][1])&&(right[0][1]==right[1][1])){
		flag++;
	}
	if ((top[2][1]==top[1][1])&&(front[0][1]==front[1][1])){
		flag++;
	}
	if ((top[1][0]==top[1][1])&&(left[0][1]==left[1][1])){
		flag++;
	}
	if (flag==4){
		return 0;
	}
	else{
		return 1;
	}
}
void fill_corners(){
	// top face corners
	if (top[0][0]==top[1][1]){
		if ((rear[0][2]==rear[1][1])&&(left[0][0]==left[1][1])){
			;
		}
		else if ((rear[0][2]==right[1][1])&&(left[0][0]==rear[1][1])){
			turn_anticlockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_rear();
			turn_clockwise_bottom();
			turn_anticlockwise_rear();
		}
		else if ((rear[0][2]==front[1][1])&&(left[0][0]==right[1][1])){
			turn_anticlockwise_left();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_right();
		}
		else if ((rear[0][2]==left[1][1])&&(left[0][0]==front[1][1])){
			turn_anticlockwise_left();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_front();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
		}
	}
	if (top[0][2]==top[1][1]){
		if ((rear[0][0]==rear[1][1])&&(right[0][2]==right[1][1])){
			;
		}
		else if ((rear[0][0]==right[1][1])&&(right[0][2]==front[1][1])){
			turn_anticlockwise_rear();
			turn_anticlockwise_bottom();
			turn_clockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_right();
		}
		else if ((rear[0][0]==front[1][1])&&(right[0][2]==left[1][1])){
			turn_anticlockwise_rear();
			turn_anticlockwise_bottom();
			turn_clockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_front();
		}
		else if ((rear[0][0]==left[1][1])&&(right[0][2]==rear[1][1])){
			turn_anticlockwise_rear();
			turn_anticlockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
		}
	}
	if (top[2][2]==top[1][1]){
		if ((right[0][0]==right[1][1])&&(front[0][2]==front[1][1])){
			;
		}
		else if ((right[0][0]==front[1][1])&&(front[0][2]==left[1][1])){
			turn_anticlockwise_right();
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_front();
		}
		else if ((right[0][0]==left[1][1])&&(front[0][2]==rear[1][1])){
			turn_anticlockwise_right();
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
		}
		else if ((right[0][0]==rear[1][1])&&(front[0][2]==left[1][1])){
			turn_anticlockwise_right();
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_bottom();
			turn_anticlockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_rear();
		}
	}
	if (top[2][0]==top[1][1]){
		if ((front[0][0]==front[1][1])&&(left[0][2]==left[1][1])){
			;
		}
		else if ((front[0][0]==left[1][1])&&(left[0][2]==rear[1][1])){
			turn_anticlockwise_front();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
		}
		else if ((front[0][0]==rear[1][1])&&(left[0][2]==right[1][1])){
			turn_anticlockwise_front();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_rear();
		}
		else if ((front[0][0]==right[1][1])&&(left[0][2]==front[1][1])){
			turn_anticlockwise_front();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_bottom();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_right();
		}
	}
	//front face corners
	if (front[0][0]==top[1][1]){
		//front and left
		if ((top[2][0]==front[1][1])&&(left[0][2]==left[1][1])){
			printf("\n no instructions given1");
		}
		else if ((top[2][0]==left[1][1])&&(left[0][2]==front[1][1])){
			turn_anticlockwise_front();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
		}
		//left and rear
		else if ((top[2][0]==left[1][1])&&(left[0][2]==rear[1][1])){
			printf("\n no instructions given2");
		}
		else if ((top[2][0]==rear[1][1])&&(left[0][2]==left[1][1])){
			turn_anticlockwise_front();
			turn_clockwise_rear();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
			turn_anticlockwise_rear();
		}
		//rear and right
		else if ((top[2][0]==right[1][1])&&(left[0][2]==rear[1][1])){
			turn_anticlockwise_front();
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_anticlockwise_bottom();
			turn_anticlockwise_right();
			turn_clockwise_front();
		}
		else if ((top[2][0]==rear[1][1])&&(left[0][2]==right[1][1])){
			printf("\n no instructions given3");
		}
		//right and front
		else if ((top[2][0]==front[1][1])&&(left[0][2]==right[1][1])){
			turn_anticlockwise_front();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
		}
		else if ((top[2][0]==right[1][1])&&(left[0][2]==front[1][1])){
			printf("\n no instructions given4");
		}
	}
	if (front[0][2]==top[1][1]){
		//front and right
		if ((top[2][2]==right[1][1])&&(right[0][0]==front[1][1])){
			turn_clockwise_front();
			turn_clockwise_bottom();
			turn_anticlockwise_front();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_right();
		}
		else if ((top[2][2]==front[1][1])&&(right[0][0]==right[1][1])){
			printf("\n no instructions given5");
		}
		//right and rear
		else if ((top[2][2]==rear[1][1])&&(right[0][0]==right[1][1])){
			turn_clockwise_front();
			turn_anticlockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_rear();
			turn_anticlockwise_front();
		}
		else if ((top[2][2]==right[1][1])&&(right[0][0]==rear[1][1])){
			printf("\n no instructions given6");
		}
		//rear and left
		else if ((top[2][2]==left[1][1])&&(right[0][0]==rear[1][1])){
			turn_clockwise_front();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_anticlockwise_front();
		}
		else if ((top[2][2]==rear[1][1])&&(right[0][0]==left[1][1])){
			printf("\n no instructions given7");
		}
		//left and front
		else if ((top[2][2]==front[1][1])&&(right[0][0]==left[1][1])){
			turn_clockwise_front();
			turn_clockwise_bottom();
			turn_anticlockwise_front();
			turn_anticlockwise_front();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
		}
		else if ((top[2][2]==left[1][1])&&(right[0][0]==front[1][1])){
			printf("\n no instructions given8");
		}
	}
	if (front[2][2]==top[1][1]){
		//front and left
		if ((bottom[0][2]==left[1][1])&&(right[2][0]==front[1][1])){
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_front();
		}
		else if ((bottom[0][2]==left[1][1])&&(right[2][0]==front[1][1])){
			printf("no instructions given9");
		}
		//left and rear
		else if ((bottom[0][2]==rear[1][1])&&(right[2][0]==left[1][1])){
			turn_anticlockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
		}
		else if ((bottom[0][2]==left[1][1])&&(right[2][0]==rear[1][1])){
			printf("no instructions given10");
		}
		//rear and right
		else if ((bottom[0][2]==right[1][1])&&(right[2][0]==rear[1][1])){
			turn_anticlockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_rear();
		}
		else if ((bottom[0][2]==rear[1][1])&&(right[2][0]==right[1][1])){
			printf("no instructions given11");
		}
		//right and front
		else if ((bottom[0][2]==front[1][1])&&(right[2][0]==right[1][1])){
			turn_anticlockwise_bottom();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_right();
		}
		else if ((bottom[0][2]==right[1][1])&&(right[2][0]==front[1][1])){
			printf("no instructions given12");
		}
	}
	if (front[2][0]==top[1][1]){
		//front and left
		if ((bottom[0][0]==front[1][1])&&(left[2][2]==left[1][1])){
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
		}
		else if ((bottom[0][0]==left[1][1])&&(left[2][2]==front[1][1])){
			printf("\n no instructions given13");
		}
		//left and rear
		else if ((bottom[0][0]==left[1][1])&&(left[2][2]==rear[1][1])){
			turn_clockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_rear();
		}
		else if ((bottom[0][0]==rear[1][1])&&(left[2][2]==left[1][1])){
			printf("\n no instructions given14");
		}
		//rear and right
		else if ((bottom[0][0]==rear[1][1])&&(left[2][2]==right[1][1])){
			turn_clockwise_right();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_right();
		}
		else if ((bottom[0][0]==right[1][1])&&(left[2][2]==rear[1][1])){
			printf("\n no instructions given15");
		}
		//right and front
		else if ((bottom[0][0]==right[1][1])&&(left[2][2]==front[1][1])){
			turn_anticlockwise_bottom();
			turn_clockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_front();
		}
		else if ((bottom[0][0]==front[1][1])&&(left[2][2]==right[1][1])){
			printf("\n no instructions given16");
		}
	}
	//right face corners
	if (right[0][0]==top[1][1]){
		//front and left
		if ((top[2][2]==left[1][1])&&(front[0][2]==front[1][1])){
			turn_anticlockwise_right();
			turn_clockwise_left();
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_anticlockwise_left();
		}
		else if ((top[2][2]==front[1][1])&&(front[0][2]==left[1][1])){
			printf("\n instruction given17");
		}
		//left and rear
		else if ((top[2][2]==rear[1][1])&&(front[0][2]==left[1][1])){
			turn_anticlockwise_right();
			turn_clockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_rear();
			turn_clockwise_right();
		}
		else if ((top[2][2]==left[1][1])&&(front[0][2]==rear[1][1])){
			printf("\n instruction given18");
		}
		//rear and right
		else if ((top[2][2]==right[1][1])&&(front[0][2]==rear[1][1])){
			turn_anticlockwise_right();
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_right();
		}
		else if ((top[2][2]==rear[1][1])&&(front[0][2]==right[1][1])){
			printf("\n instruction given19");
		}
		//front and right
		else if ((top[2][2]==front[1][1])&&(front[0][2]==right[1][1])){
			turn_anticlockwise_right();
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_front();
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
		}
		else if ((top[2][2]==right[1][1])&&(front[0][2]==front[1][1])){
			printf("\n instruction given20");
		}
	}
	if (right[0][2]==top[1][1]){
		//front and left
		if ((top[0][2]==front[1][1])&&(rear[0][0]==left[1][1])){
			turn_clockwise_right();
			turn_clockwise_bottom();
			turn_anticlockwise_right();
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_front();
		}
		else if ((top[0][2]==left[1][1])&&(rear[0][0]==front[1][1])){
			printf("\n no instructions given21");
		}
		//left and rear
		else if ((top[0][2]==left[1][1])&&(rear[0][0]==rear[1][1])){
			turn_clockwise_right();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_right();
			turn_clockwise_left();
		}
		else if ((top[0][2]==rear[1][1])&&(rear[0][0]==left[1][1])){
			printf("\n no instructions given22");
		}
		//rear and right
		else if ((top[0][2]==rear[1][1])&&(rear[0][0]==right[1][1])){
			turn_clockwise_right();
			turn_clockwise_bottom();
			turn_anticlockwise_right();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_rear();
		}
		else if ((top[0][2]==right[1][1])&&(rear[0][0]==rear[1][1])){
			printf("\n no instructions given23");
		}
		//right and front
		else if ((top[0][2]==right[1][1])&&(rear[0][0]==front[1][1])){
			turn_clockwise_right();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_right();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_right();
		}
		else if ((top[0][2]==front[1][1])&&(rear[0][0]==right[1][1])){
			printf("\n no instructions given24");
		}
	}
	if (right[2][2]==top[1][1]){
		//front and left
		if ((bottom[2][2]==left[1][1])&&(rear[2][0]==front[1][1])){
			turn_anticlockwise_front();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_front();
		}
		else if ((bottom[2][2]==front[1][1])&&(rear[2][0]==left[1][1])){
			printf("\n no instructions given25");
		}
		//left and rear
		else if ((bottom[2][2]==rear[1][1])&&(rear[2][0]==left[1][1])){
			turn_anticlockwise_left();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
		}
		else if ((bottom[2][2]==left[1][1])&&(rear[2][0]==rear[1][1])){
			printf("\n no instructions given26");
		}
		//rear and right
		else if ((bottom[2][2]==right[1][1])&&(rear[2][0]==rear[1][1])){
			turn_anticlockwise_bottom();
			turn_anticlockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_rear();
		}
		else if ((bottom[2][2]==rear[1][1])&&(rear[2][0]==right[1][1])){
			printf("\n no instructions given27");
		}
		//right and front
		else if ((bottom[2][2]==front[1][1])&&(rear[2][0]==right[1][1])){
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_right();
		}
		else if ((bottom[2][2]==right[1][1])&&(rear[2][0]==front[1][1])){
			printf("\n no instructions given28");
		}
	}
	if (right[2][0]==top[1][1]){
		//front and left
		if ((bottom[0][2]==front[1][1])&&(front[2][2]==left[1][1])){
			turn_clockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
		}
		else if ((bottom[0][2]==left[1][1])&&(front[2][2]==front[1][1])){
			printf("\n no instructions given29");
		}
		//left and rear
		else if ((bottom[0][2]==left[1][1])&&(front[2][2]==rear[1][1])){
			turn_clockwise_rear();
			turn_clockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_rear();
		}
		else if ((bottom[0][2]==rear[1][1])&&(front[2][2]==left[1][1])){
			printf("\n no instructions given30");
		}
		//rear and right
		else if ((bottom[0][2]==rear[1][1])&&(front[2][2]==right[1][1])){
			turn_anticlockwise_bottom();
			turn_clockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_right();
		}
		else if ((bottom[0][2]==right[1][1])&&(front[2][2]==rear[1][1])){
			printf("\n no instructions given31");
		}
		//right and front
		else if ((bottom[0][2]==right[1][1])&&(front[2][2]==front[1][1])){
			turn_clockwise_bottom();
			turn_clockwise_front();
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
		}
		else if ((bottom[0][2]==front[1][1])&&(front[2][2]==right[1][1])){
			printf("\n no instructions given32");
		}
	}
	//rear face corner
	if (rear[0][0]==top[1][1]){
		//front and left
		if ((top[0][2]==left[1][1])&&(right[0][2]==front[1][1])){
			turn_clockwise_left();
			turn_anticlockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_rear();
		}
		else if ((top[0][2]==front[1][1])&&(right[0][2]==left[1][1])){
			printf("\n no instructions given33");
		}
		//left and rear
		else if ((top[0][2]==rear[1][1])&&(right[0][2]==left[1][1])){
			turn_anticlockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_rear();
		}
		else if ((top[0][2]==left[1][1])&&(right[0][2]==rear[1][1])){
			printf("\n no instructions given34");
		}
		//rear and right
		else if ((top[0][2]==right[1][1])&&(right[0][2]==rear[1][1])){
			turn_anticlockwise_rear();
			turn_anticlockwise_bottom();
			turn_clockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_right();
			turn_anticlockwise_bottom();
			turn_anticlockwise_right();
		}
		else if ((top[0][2]==rear[1][1])&&(right[0][2]==right[1][1])){
			printf("\n no instructions given35");
		}
		//right and front
		else if ((top[0][2]==front[1][1])&&(right[0][2]==right[1][1])){
			turn_anticlockwise_rear();
			turn_clockwise_front();
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
			turn_clockwise_rear();
		}
		else if ((top[0][2]==right[1][1])&&(right[0][2]==front[1][1])){
			printf("\n no instructions given36");
		}
	}
	if (rear[2][0]==top[1][1]){
		//front and left
		if ((top[0][0]==front[1][1])&&(left[0][0]==left[1][1])){
			turn_anticlockwise_front();
			turn_clockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_front();
			turn_anticlockwise_rear();
		}
		else if ((top[0][0]==left[1][1])&&(left[0][0]==front[1][1])){
			printf("\n no instructions given37");
		}
		//left and rear
		else if ((top[0][0]==left[1][1])&&(left[0][0]==rear[1][1])){
			turn_clockwise_rear();
			turn_clockwise_bottom();
			turn_anticlockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
		}
		else if ((top[0][0]==rear[1][1])&&(left[0][0]==left[1][1])){
			printf("\n no instructions given38");
		}
		//rear and right
		else if ((top[0][0]==rear[1][1])&&(left[0][0]==right[1][1])){
			turn_clockwise_rear();
			turn_clockwise_bottom();
			turn_anticlockwise_rear();
			turn_anticlockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_rear();
		}
		else if ((top[0][0]==right[1][1])&&(left[0][0]==rear[1][1])){
			printf("\n no instructions given39");
		}
		//right and front
		else if ((top[0][0]==right[1][1])&&(left[0][0]==front[1][1])){
			turn_clockwise_rear();
			turn_clockwise_bottom();
			turn_anticlockwise_rear();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_right();
		}
		else if ((top[0][0]==front[1][1])&&(left[0][0]==right[1][1])){
			printf("\n no instructions given40");
		}
	}
	if (rear[2][2]==top[1][1]){
		//front and left
		if ((bottom[2][0]==left[1][1])&&(left[2][0]==front[1][1])){
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_front();
		}
		else if ((bottom[2][0]==front[1][1])&&(left[2][0]==left[1][1])){
			printf("\n no instructions given41");
		}
		//left and rear
		else if ((bottom[2][0]==rear[1][1])&&(left[2][0]==left[1][1])){
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
		}
		else if ((bottom[2][0]==left[1][1])&&(left[2][0]==rear[1][1])){
			printf("\n no instructions given42");
		}
		//rear and right
		else if ((bottom[2][0]==right[1][1])&&(left[2][0]==rear[1][1])){
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_rear();
		}
		else if ((bottom[2][0]==rear[1][1])&&(left[2][0]==right[1][1])){
			printf("\n no instructions given43");
		}
		//right and front
		else if ((bottom[2][0]==front[1][1])&&(left[2][0]==right[1][1])){
			turn_clockwise_bottom();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_right();
		}
		else if ((bottom[2][0]==right[1][1])&&(left[2][0]==front[1][1])){
			printf("\n no instructions given44");
		}
	}
	if (rear[2][0]==top[1][1]){
		//front and left
		if ((bottom[2][2]==front[1][1])&&(right[2][2]==left[1][1])){
			turn_clockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
		}
		else if ((bottom[2][2]==left[1][1])&&(right[2][2]==front[1][1])){
			printf("\n no instructions given45");
		}
		//left and rear
		else if ((bottom[2][2]==left[1][1])&&(right[2][2]==rear[1][1])){
			turn_anticlockwise_bottom();
			turn_clockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_rear();
		}
		else if ((bottom[2][2]==rear[1][1])&&(right[2][2]==left[1][1])){
			printf("\n no instructions given46");
		}
		//rear and right
		else if ((bottom[2][2]==rear[1][1])&&(right[2][2]==right[1][1])){
			turn_clockwise_bottom();
			turn_clockwise_right();
			turn_anticlockwise_bottom();
			turn_anticlockwise_right();
		}
		else if ((bottom[2][2]==right[1][1])&&(right[2][2]==rear[1][1])){
			printf("\n no instructions given47");
		}
		//right and front
		else if ((bottom[2][2]==right[1][1])&&(right[2][2]==front[1][1])){
			turn_clockwise_front();
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
		}
		else if ((bottom[2][2]==front[1][1])&&(right[2][2]==right[1][1])){
			printf("\n no instructions given48");
		}
	}
	//left face corners
	if (left[0][0]==top[1][1]){
		//front and left
		if ((top[0][0]==left[1][1])&&(rear[0][2]==front[1][1])){
			turn_anticlockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
		}
		else if ((top[0][0]==front[1][1])&&(rear[0][2]==left[1][1])){
			printf("\n no instructions given49");
		}
		//left and rear
		else if ((top[0][0]==rear[1][1])&&(rear[0][2]==left[1][1])){
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_rear();
		}
		else if ((top[0][0]==left[1][1])&&(rear[0][2]==rear[1][1])){
			printf("\n no instructions given50");
		}
		//rear and right
		else if ((top[0][0]==right[1][1])&&(rear[0][2]==rear[1][1])){
			turn_anticlockwise_left();
			turn_clockwise_right();
			turn_clockwise_bottom();
			turn_anticlockwise_right();
			turn_clockwise_left();
		}
		else if ((top[0][0]==rear[1][1])&&(rear[0][2]==right[1][1])){
			printf("\n no instructions given51");
		}
		//right and front
		else if ((top[0][0]==front[1][1])&&(rear[0][2]==right[1][1])){
			turn_clockwise_front();
			turn_anticlockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
			turn_clockwise_left();
		}
		else if ((top[0][0]==right[1][1])&&(rear[0][2]==front[1][1])){
			printf("\n no instructions given52");
		}
	}
	if (left[0][2]==top[1][1]){
		//front and left
		if ((top[2][0]==front[1][1])&&(front[0][0]==left[1][1])){
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_front();
		}
		else if ((top[2][0]==left[1][1])&&(front[0][0]==front[1][1])){
			printf("\n no instructions given53");
		}
		//left and rear
		else if ((top[2][0]==left[1][1])&&(front[0][0]==rear[1][1])){
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_anticlockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
		}
		else if ((top[2][0]==rear[1][1])&&(front[0][0]==left[1][1])){
			printf("\n no instructions given54");
		}
		//rear and right
		else if ((top[2][0]==rear[1][1])&&(front[0][0]==right[1][1])){
			turn_clockwise_left();
			turn_anticlockwise_rear();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_rear();
		}
		else if ((top[2][0]==right[1][1])&&(front[0][0]==rear[1][1])){
			printf("\n no instructions given55");
		}
		//right and front
		else if ((top[2][0]==right[1][1])&&(front[0][0]==front[1][1])){
			turn_clockwise_left();
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_right();
			turn_anticlockwise_left();
		}
		else if ((top[2][0]==front[1][1])&&(front[0][0]==right[1][1])){
			printf("\n no instructions given56");
		}
	}
	if (left[2][2]==top[1][1]){
		//front and left
		if ((front[2][0]==front[1][1])&&(bottom[0][0]==left[1][1])){
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
			turn_clockwise_bottom();
			turn_clockwise_front();
		}
		else if ((front[2][0]==left[1][1])&&(bottom[0][0]==front[1][1])){
			printf("\n no instructions given57");
		}
		//left and rear
		else if ((front[2][0]==left[1][1])&&(bottom[0][0]==rear[1][1])){
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
		}
		else if ((front[2][0]==rear[1][1])&&(bottom[0][0]==left[1][1])){
			printf("\n no instructions given58");
		}
		//rear and right
		else if ((front[2][0]==rear[1][1])&&(bottom[0][0]==right[1][1])){
			turn_anticlockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_rear();
		}
		else if ((front[2][0]==right[1][1])&&(bottom[0][0]==rear[1][1])){
			printf("\n no instructions given59");
		}
		//right and front
		else if ((front[2][0]==right[1][1])&&(bottom[0][0]==front[1][1])){
			turn_anticlockwise_right();
			turn_clockwise_bottom();
			turn_clockwise_right();
		}
		else if ((front[2][0]==front[1][1])&&(bottom[0][0]==right[1][1])){
			printf("\n no instructions given60");
		}
	}
	if (left[2][0]==top[1][1]){
		//front and left
		if ((bottom[2][0]==front[1][1])&&(rear[2][2]==left[1][1])){
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_anticlockwise_bottom();
			turn_anticlockwise_left();
		}
		else if ((bottom[2][0]==left[1][1])&&(rear[2][2]==front[1][1])){
			printf("\n no instructions given61");
		}
		//left and rear
		else if ((bottom[2][0]==left[1][1])&&(rear[2][2]==rear[1][1])){
			turn_clockwise_bottom();
			turn_clockwise_rear();
			turn_anticlockwise_bottom();
			turn_anticlockwise_rear();
		}
		else if ((bottom[2][0]==rear[1][1])&&(rear[2][2]==left[1][1])){
			printf("\n no instructions given62");
		}
		//rear and right
		else if ((bottom[2][0]==rear[1][1])&&(rear[2][2]==right[1][1])){
			turn_clockwise_right();
			turn_anticlockwise_bottom();
			turn_anticlockwise_right();
		}
		else if ((bottom[2][0]==right[1][1])&&(rear[2][2]==rear[1][1])){
			printf("\n no instructions given63");
		}
		//right and front
		else if ((bottom[2][0]==right[1][1])&&(rear[2][2]==front[1][1])){
			turn_clockwise_front();
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_anticlockwise_front();
		}
		else if ((bottom[2][0]==front[1][1])&&(rear[2][2]==right[1][1])){
			printf("\n no instructions given64");
		}
	}
	//bottom face corners
	bottom_solution:{
		if (bottom[0][0]==top[1][1]){
			//front and left
			if ((front[2][0]==left[1][1])&&(left[2][2]==front[1][1])){
				turn_clockwise_bottom();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_anticlockwise_left();
				turn_anticlockwise_front();
				turn_anticlockwise_bottom();
				turn_clockwise_front();
				turn_clockwise_bottom();
				turn_clockwise_bottom();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_anticlockwise_left();
			}
			else if ((front[2][0]==front[1][1])&&(left[2][2]==left[1][1])){
				printf("\n no instructions given65");
			}
			//left and rear
			else if ((front[2][0]==rear[1][1])&&(left[2][2]==left[1][1])){
				turn_clockwise_bottom();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_anticlockwise_left();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_anticlockwise_bottom();
				turn_clockwise_front();
				turn_anticlockwise_rear();
			}
			else if ((front[2][0]==left[1][1])&&(left[2][2]==rear[1][1])){
				printf("\n no instructions given66");
			}
			//rear and right
			else if ((front[2][0]==right[1][1])&&(left[2][2]==rear[1][1])){
				turn_clockwise_bottom();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_anticlockwise_left();
				turn_anticlockwise_front();
				turn_clockwise_right();
				turn_anticlockwise_bottom();
				turn_anticlockwise_bottom();
				turn_anticlockwise_right();
				turn_clockwise_front();
			}
			else if ((front[2][0]==rear[1][1])&&(left[2][2]==right[1][1])){
				printf("\n no instructions given67");
			}
			//right and front
			else if ((front[2][0]==front[1][1])&&(left[2][2]==right[1][1])){
				turn_clockwise_bottom();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_anticlockwise_left();
				turn_anticlockwise_front();
				turn_anticlockwise_bottom();
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_bottom();
				turn_anticlockwise_bottom();
				turn_anticlockwise_front();
			}
			else if ((front[2][0]==right[1][1])&&(left[2][2]==front[1][1])){
				printf("\n no instructions given68");
			}
		}
	}
	int cont;
	if (bottom[0][2]==top[1][1]){
		//front and left
		//left and rear
		//rear and right
		//right and front
		turn_anticlockwise_bottom();
		printf("\n goto bottom_solution---------------------");
		printf("\n:");scanf("%d",&cont);
		goto bottom_solution;
	}
	if (bottom[2][2]==top[1][1]){
		//front and left
		//left and rear
		//rear and right
		//right and front
		turn_anticlockwise_bottom();
		printf("\n goto bottom_solution---------------------");
		printf("\n:");scanf("%d",&cont);
		goto bottom_solution;
	}
	if (bottom[2][0]==top[1][1]){
		//front and left
		//left and rear
		//rear and right
		//right and front
		turn_clockwise_bottom();
		printf("\n goto bottom_solution---------------------");
		printf("\n:");scanf("%d",&cont);
		goto bottom_solution;
	}
}
int check_first_layer(){
	int count=0;
	if ((top[0][0]==top[1][1])&&(rear[0][2]==rear[1][1])&&(left[0][0]==left[1][1])){
		count++;printf("\n count+1_1");
	}
	if ((top[0][2]==top[1][1])&&(rear[0][0]==rear[1][1])&&(right[0][2]==right[1][1])){
		count++;printf("\n count+1_2");
	}
	if ((top[2][2]==top[1][1])&&(front[0][2]==front[1][1])&&(right[0][0]==right[1][1])){
		count++;printf("\n count+1_3");
	}
	if ((top[2][0]==top[1][1])&&(left[0][2]==left[1][1])&&(front[0][0]==front[1][1])){
		count++;printf("\n count+1_4");
	}
	if (count==4){
		return 0;
	}
	else {
		return 1;
	}
}
void fill_edges(){
	//front and left edge
	if ((front[2][1]==front[1][1])&&(bottom[0][1]==left[1][1])){
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
	}
	else if ((front[2][1]==left[1][1])&&(bottom[0][1]==front[1][1])){
		turn_anticlockwise_bottom();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
	}
	else if ((left[2][1]==front[1][1])&&(bottom[1][0]==left[1][1])){
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
	}
	else if ((left[2][1]==left[1][1])&&(bottom[1][0]==front[1][1])){
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
	}
	else if ((rear[2][1]==front[1][1])&&(bottom[2][1]==left[1][1])){
		turn_anticlockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
	}
	else if ((rear[2][1]==left[1][1])&&(bottom[2][1]==front[1][1])){
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
	}
	else if ((right[2][1]==front[1][1])&&(bottom[1][2]==left[1][1])){
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
	}
	else if ((right[2][1]==left[1][1])&&(bottom[1][2]==front[1][1])){
		turn_clockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
	}
		//front and left
	else if ((front[1][0]==front[1][1])&&(left[1][2]==left[1][1])){
		;
	}
	else if ((front[1][0]==left[1][1])&&(left[1][2]==front[1][1])){
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
	}
		//front and right
	else if ((front[1][2]==left[1][1])&&(right[1][0]==front[1][1])){
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
	}
	else if ((front[1][2]==front[1][1])&&(right[1][0]==left[1][1])){
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_anticlockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
	}
		//right and rear
	else if ((right[1][2]==front[1][1])&&(rear[1][0]==left[1][1])){
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
	}
	else if ((right[1][2]==left[1][1])&&(rear[1][0]==front[1][1])){
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
	}
		//rear and left
	else if ((rear[1][2]==left[1][1])&&(left[1][0]==front[1][1])){
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
	}
	else if ((rear[1][2]==front[1][1])&&(left[1][0]==left[1][1])){
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
	}
	//left and rear edge
	if ((left[2][1]==left[1][1])&&(bottom[1][0]==rear[1][1])){
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
	}
	else if ((front[2][1]==left[1][1])&&(bottom[0][1]==rear[1][1])){
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
	}
	else if ((right[2][1]==left[1][1])&&(bottom[1][2]==rear[1][1])){
		turn_anticlockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
	}
	else if ((rear[2][1]==left[1][1])&&(bottom[2][1]==rear[1][1])){
		turn_anticlockwise_bottom();
		turn_anticlockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
	}
	else if ((left[2][1]==rear[1][1])&&(bottom[1][2]==left[1][1])){
		turn_anticlockwise_bottom();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
	}
	else if ((front[2][1]==rear[1][1])&&(bottom[0][1]==left[1][1])){
		turn_clockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
	}
	else if ((right[2][1]==rear[1][1])&&(bottom[1][2]==left[1][1])){
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
	}
	else if ((rear[2][1]==rear[1][1])&&(bottom[2][1]==left[1][1])){
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
	}
		//front and left
	if ((front[1][0]==left[1][1])&&(left[1][2]==rear[1][1])){
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
	}
	else if ((front[1][0]==rear[1][1])&&(left[1][2]==left[1][1])){
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
	}
		//rear and left
	else if ((left[1][0]==rear[1][1])&&(rear[1][2]==left[1][1])){
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
	}
	else if ((left[1][0]==left[1][1])&&(rear[1][2]==rear[1][1])){
		;
	}
		//rear and right
	else if ((right[1][2]==left[1][1])&&(rear[1][0]==rear[1][1])){
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
	}
	else if ((right[1][2]==rear[1][1])&&(rear[1][0]==left[1][1])){
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
	}
		//front and right
	else if ((front[1][2]==left[1][1])&&(right[1][0]==rear[1][1])){
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
	}
	else if ((front[1][2]==rear[1][1])&&(right[1][0]==left[1][1])){
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
	}
	//rear and right edge
	if ((front[2][1]==right[1][1])&&(bottom[0][1]==rear[1][1])){
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
	}
	else if ((left[2][1]==right[1][1])&&(bottom[1][0]==rear[1][1])){
		turn_clockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
	}
	else if ((rear[2][1]==right[1][1])&&(bottom[2][1]==rear[1][1])){
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
	}
	else if ((right[2][1]==right[1][1])&&(bottom[1][2]==rear[1][1])){
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
	}
	else if ((front[2][1]==rear[1][1])&&(bottom[0][1]==right[1][1])){
		turn_anticlockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
	}
	else if ((left[2][1]==rear[1][1])&&(bottom[1][0]==right[1][1])){
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
	}
	else if ((rear[2][1]==rear[1][1])&&(bottom[2][1]==right[1][1])){
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
	}
	else if ((right[2][1]==rear[1][1])&&(bottom[1][2]==right[1][1])){
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
	}
		//front and left
	else if ((front[1][0]==rear[1][1])&&(left[1][2]==right[1][1])){
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
	}
	else if ((front[1][0]==right[1][1])&&(left[1][2]==rear[1][1])){
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
	}
		//left and rear
	else if ((left[1][0]==right[1][1])&&(rear[1][2]==rear[1][1])){
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
	}
	else if ((left[1][0]==rear[1][1])&&(rear[1][2]==right[1][1])){
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_anticlockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
	}
		//rear and right
	else if ((rear[1][0]==rear[1][1])&&(right[1][2]==right[1][1])){
		;
	}
	else if ((rear[1][0]==right[1][1])&&(right[1][2]==rear[1][1])){
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
	}
		//front and right
	else if ((front[1][2]==rear[1][1])&&(right[1][0]==right[1][1])){
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
	}
	else if ((front[1][2]==right[1][1])&&(right[1][0]==rear[1][1])){
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
	}
	//front and right
	if ((front[2][1]==right[1][1])&&(bottom[0][1]==front[1][1])){
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
	}
	else if ((left[2][1]==right[1][1])&&(bottom[1][0]==front[1][1])){
		turn_anticlockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
	}
	else if ((rear[2][1]==right[1][1])&&(bottom[2][1]==front[1][1])){
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
	}
	else if ((right[2][1]==right[1][1])&&(bottom[1][2]==front[1][1])){
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
	}
	else if ((front[2][1]==front[1][1])&&(bottom[0][1]==right[1][1])){
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
	}
	else if ((left[2][1]==front[1][1])&&(bottom[1][0]==right[1][1])){
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
	}
	else if ((rear[2][1]==front[1][1])&&(bottom[2][1]==right[1][1])){
		turn_clockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
	}
	else if ((right[2][1]==front[1][1])&&(bottom[1][2]==right[1][1])){
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
	}
		//front and left
	else if ((front[1][0]==right[1][1])&&(left[1][2]==front[1][1])){
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
	}
	else if ((front[1][0]==front[1][1])&&(left[1][2]==right[1][1])){
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
	}
		//left and rear
	else if ((left[1][0]==front[1][1])&&(rear[1][2]==right[1][1])){
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
	}
	else if ((left[1][0]==right[1][1])&&(rear[1][2]==front[1][1])){
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_anticlockwise_bottom();
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
	}
		//rear and right
	else if ((rear[1][0]==right[1][1])&&(right[1][2]==front[1][1])){
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_anticlockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
	}
	else if ((rear[1][0]==front[1][1])&&(right[1][2]==right[1][1])){
		turn_anticlockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_rear();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
	}
	else if ((front[1][2]==front[1][1])&&(right[1][0]==right[1][1])){
		;
	}
	else if ((front[1][2]==right[1][1])&&(right[1][0]==front[1][1])){
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
		turn_clockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_front();
	}
}
int check_edges(){
	int count=0;
	if ((front[1][0]==front[1][1])&&(left[1][2]==left[1][1])){
		count++;printf("\n count_1_edge");
	}
	if ((left[1][0]==left[1][1])&&(rear[1][2]==rear[1][1])){
		count++;printf("\n count_2_edge");
	}
	if ((rear[1][0]==rear[1][1])&&(right[1][2]==right[1][1])){
		count++;printf("\n count_3_edge");
	}
	if ((right[1][0]==right[1][1])&&(front[1][2]==front[1][1])){
		count++;printf("\n count_4_edge");
	}
	if (count==4){
		return 0;
	}
	else {
		return 1;
	}
}
void fill_bottom_cross(){
	if ((bottom[0][1]!=bottom[1][1])&&(bottom[1][2]!=bottom[1][1])&&(bottom[2][1]!=bottom[1][1])&&(bottom[1][0]!=bottom[1][1])){
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_front();
	}
	if ((bottom[0][1]==bottom[1][1])&&(bottom[1][2]!=bottom[1][1])&&(bottom[2][1]==bottom[1][1])&&(bottom[1][0]!=bottom[1][1])){
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_front();
	}
	if ((bottom[0][1]!=bottom[1][1])&&(bottom[1][2]==bottom[1][1])&&(bottom[2][1]!=bottom[1][1])&&(bottom[1][0]==bottom[1][1])){
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_front();
	}
	if ((bottom[0][1]!=bottom[1][1])&&(bottom[1][2]==bottom[1][1])&&(bottom[2][1]==bottom[1][1])&&(bottom[1][0]!=bottom[1][1])){
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_front();
	}
	if ((bottom[0][1]!=bottom[1][1])&&(bottom[1][2]!=bottom[1][1])&&(bottom[2][1]==bottom[1][1])&&(bottom[1][0]==bottom[1][1])){
		turn_anticlockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_front();
	}
	if ((bottom[0][1]==bottom[1][1])&&(bottom[1][2]!=bottom[1][1])&&(bottom[2][1]!=bottom[1][1])&&(bottom[1][0]==bottom[1][1])){
		turn_anticlockwise_bottom();
		turn_anticlockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_front();
	}
	if ((bottom[0][1]==bottom[1][1])&&(bottom[1][2]==bottom[1][1])&&(bottom[2][1]!=bottom[1][1])&&(bottom[1][0]!=bottom[1][1])){
		turn_clockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_anticlockwise_front();
	}
}
int check_bottom_cross(){
	if ((bottom[0][1]==bottom[1][1])&&(bottom[1][2]==bottom[1][1])&&(bottom[2][1]==bottom[1][1])&&(bottom[1][0]==bottom[1][1])){
		return 0;
	}
	else {
		return 1;
	}
}
void fill_bottom_corners(){
	int corners=0;
	if (bottom[0][0]==bottom[1][1]){
		corners++;
	}
	if (bottom[0][2]==bottom[1][1]){
		corners++;
	}
	if (bottom[2][2]==bottom[1][1]){
		corners++;
	}
	if (bottom[2][0]==bottom[1][1]){
		corners++;
	}
	if ((corners==0)||(corners==2)){
		if (front[2][0]==bottom[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
		}
		else if (right[2][0]==bottom[1][1]){
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
		}
		else if (rear[2][0]==bottom[1][1]){
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
		}
		else if (left[2][0]==bottom[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
		}
		else {
			printf("\n no instructions given69");
		}
	}
	else if (corners==1){
		if ((bottom[0][2]==bottom[1][1])&&(bottom[2][2]!=bottom[1][1])&&(bottom[2][0]!=bottom[1][1])&&(bottom[0][0]!=bottom[1][1])){
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
		}
		else if ((bottom[0][2]!=bottom[1][1])&&(bottom[2][2]==bottom[1][1])&&(bottom[2][0]!=bottom[1][1])&&(bottom[0][0]!=bottom[1][1])){
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
		}
		else if ((bottom[0][2]!=bottom[1][1])&&(bottom[2][2]!=bottom[1][1])&&(bottom[2][0]==bottom[1][1])&&(bottom[0][0]!=bottom[1][1])){
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
		}
		else if ((bottom[0][2]!=bottom[1][1])&&(bottom[2][2]!=bottom[1][1])&&(bottom[2][0]!=bottom[1][1])&&(bottom[0][0]==bottom[1][1])){
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_left();
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			turn_anticlockwise_left();
		}
	}
	else {
		printf("\n no instructions given70");
	}
}
int check_bottom_corners(){
	if ((bottom[0][0]==bottom[1][1])&&(bottom[0][2]==bottom[1][1])&&(bottom[2][2]==bottom[1][1])&&(bottom[2][0]==bottom[1][1])){
		return 0;
	}
	else {
		return 1;
	}
}
void match_corners(){
	if ((front[2][0]!=front[2][2])&&(left[2][0]!=left[2][2])&&(rear[2][0]!=rear[2][2])&&(right[2][0]!=right[2][2])){
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_left();
	}
	if (front[2][0]==front[2][2]){
		turn_clockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_left();
	}
	if (left[2][0]==left[2][2]){
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_left();
	}
	if (rear[2][0]==rear[2][2]){
		turn_anticlockwise_bottom();
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_left();
	}
	if (right[2][0]==right[2][2]){
		turn_anticlockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_clockwise_right();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_left();
		turn_clockwise_bottom();
		turn_clockwise_bottom();
		turn_anticlockwise_left();
	}
}
int check_bottom_layer_corners(){
	if ((front[2][0]==front[2][2])&&(left[2][0]==left[2][2])&&(rear[2][0]==rear[2][2])&&(right[2][0]==right[2][2])){
		return 0;
	}
	else {
		return 1;
	}
}void check_cube(){
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

void match_bottom_edges(){
	if ((front[2][0]==front[2][1])&&(front[2][1]==front[2][2])&&(front[2][0]==front[2][2])){
		if (front[2][1]==front[1][1]){
			if ((left[2][1]==right[1][1])&&(right[2][1]==rear[1][1])&&(rear[2][1]==left[1][1])){
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_clockwise_bottom();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_left();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_bottom();
				turn_clockwise_rear();
				turn_clockwise_rear();
			}
			else if((left[2][1]==rear[1][1])&&(rear[2][1]==right[1][1])&&(right[2][1]==left[1][1])){
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_bottom();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_anticlockwise_bottom();
				turn_clockwise_rear();
				turn_clockwise_rear();
			}
			else {
				printf("\n no instructions given71");
			}
		}
		else if (front[2][1]==right[1][1]){
			turn_clockwise_bottom();
			if ((front[2][1]==rear[1][1])&&(rear[2][1]==left[1][1])&&(left[2][1]==front[1][1])){
				turn_clockwise_left();
				turn_clockwise_left();
				turn_clockwise_bottom();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_bottom();
				turn_anticlockwise_left();
				turn_anticlockwise_left();
			}
			else if ((front[2][1]==left[1][1])&&(left[2][1]==rear[1][1])&&(rear[2][1]==front[1][1])){
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_anticlockwise_bottom();
				turn_anticlockwise_bottom();
				turn_clockwise_left();
				turn_clockwise_left();
			}
			else {
				printf("\n no instructions given72");
			}
		}
		else if (front[2][1]==rear[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			if ((right[2][1]==left[1][1])&&(left[2][1]==front[1][1])&&(front[2][1]==right[1][1])){
				turn_clockwise_front();
				turn_clockwise_front();
				turn_clockwise_bottom();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_bottom();
				turn_clockwise_front();
				turn_clockwise_front();
			}
			else if ((right[2][1]==front[1][1])&&(left[2][1]==right[1][1])&&(front[2][1]==left[1][1])){
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_bottom();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_clockwise_front();
				turn_clockwise_front();
			}
			else {
				printf("\n no instructions given73");
			}
		}
		else if (front[2][1]==left[1][1]){
			turn_anticlockwise_bottom();
			if ((rear[2][1]==front[1][1])&&(front[2][1]==right[1][1])&&(right[2][1]==rear[1][1])){
				//printf("\nclockwise");
				turn_clockwise_right();
				turn_clockwise_right();
				turn_clockwise_bottom();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_bottom();
				turn_clockwise_right();
				turn_clockwise_right();
			}
			else if ((front[2][1]==rear[1][1])&&(rear[2][1]==right[1][1])&&(right[2][1]==front[1][1])){
				//printf("\n anticlockwise");
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_bottom();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_anticlockwise_bottom();
				turn_clockwise_right();
				turn_clockwise_right();
			}
			else {
				printf("\n no instructions given74");
			}
		}
		else {
			printf("\n no instructions given75");
		}
	}
	else if ((left[2][0]==left[2][1])&&(left[2][1]==left[2][2])&&(left[2][2]==left[2][0])){
		if (left[2][1]==front[1][1]){
			turn_clockwise_bottom();
			if ((left[2][1]==right[1][1])&&(right[2][1]==rear[1][1])&&(rear[2][1]==left[1][1])){
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_clockwise_bottom();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_left();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_bottom();
				turn_clockwise_rear();
				turn_clockwise_rear();
			}
			else if((left[2][1]==rear[1][1])&&(rear[2][1]==right[1][1])&&(right[2][1]==left[1][1])){
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_bottom();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_anticlockwise_bottom();
				turn_clockwise_rear();
				turn_clockwise_rear();
			}
			else {
				printf("\n no instructions given77");
			}
		}
		else if (left[2][1]==right[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			if ((front[2][1]==rear[1][1])&&(rear[2][1]==left[1][1])&&(left[2][1]==front[1][1])){
				turn_clockwise_left();
				turn_clockwise_left();
				turn_clockwise_bottom();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_bottom();
				turn_anticlockwise_left();
				turn_anticlockwise_left();
			}
			else if ((front[2][1]==left[1][1])&&(left[2][1]==rear[1][1])&&(rear[2][1]==front[1][1])){
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_anticlockwise_bottom();
				turn_anticlockwise_bottom();
				turn_clockwise_left();
				turn_clockwise_left();
			}
			else {
				printf("\n no instructions given78");
			}
		}
		else if (left[2][1]==rear[1][1]){
			turn_anticlockwise_bottom();
			if ((right[2][1]==left[1][1])&&(left[2][1]==front[1][1])&&(front[2][1]==right[1][1])){
				turn_clockwise_front();
				turn_clockwise_front();
				turn_clockwise_bottom();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_bottom();
				turn_clockwise_front();
				turn_clockwise_front();
			}
			else if ((right[2][1]==front[1][1])&&(left[2][1]==right[1][1])&&(front[2][1]==left[1][1])){
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_bottom();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_clockwise_front();
				turn_clockwise_front();
			}
			else {
				printf("\n no instructions given79");
			}
		}
		else if (left[2][1]==left[1][1]){
			if ((rear[2][1]==front[1][1])&&(front[2][1]==right[1][1])&&(right[2][1]==rear[1][1])){
				//printf("\nclockwise");
				turn_clockwise_right();
				turn_clockwise_right();
				turn_clockwise_bottom();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_bottom();
				turn_clockwise_right();
				turn_clockwise_right();
			}
			else if ((front[2][1]==rear[1][1])&&(rear[2][1]==right[1][1])&&(right[2][1]==front[1][1])){
				//printf("\n anticlockwise");
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_bottom();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_anticlockwise_bottom();
				turn_clockwise_right();
				turn_clockwise_right();
			}
			else {
				printf("\n no instructions given80");
			}
		}
		else {
			printf("\n no instruction given81");
		}
	}
	else if ((rear[2][0]==rear[2][1])&&(rear[2][1]==rear[2][2])&&(rear[2][2]==rear[2][0])){
		if (rear[2][1]==front[1][1]){
			turn_anticlockwise_bottom();
			turn_anticlockwise_bottom();
			if ((left[2][1]==right[1][1])&&(right[2][1]==rear[1][1])&&(rear[2][1]==left[1][1])){
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_clockwise_bottom();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_left();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_bottom();
				turn_clockwise_rear();
				turn_clockwise_rear();
			}
			else if((left[2][1]==rear[1][1])&&(rear[2][1]==right[1][1])&&(right[2][1]==left[1][1])){
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_bottom();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_anticlockwise_bottom();
				turn_clockwise_rear();
				turn_clockwise_rear();
			}
			else {
				printf("\n no instructions given82");
			}
		}
		else if (rear[2][1]==right[1][1]){
			turn_anticlockwise_bottom();
			if ((front[2][1]==rear[1][1])&&(rear[2][1]==left[1][1])&&(left[2][1]==front[1][1])){
				turn_clockwise_left();
				turn_clockwise_left();
				turn_clockwise_bottom();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_bottom();
				turn_anticlockwise_left();
				turn_anticlockwise_left();
			}
			else if ((front[2][1]==left[1][1])&&(left[2][1]==rear[1][1])&&(rear[2][1]==front[1][1])){
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_anticlockwise_bottom();
				turn_anticlockwise_bottom();
				turn_clockwise_left();
				turn_clockwise_left();
			}
			else {
				printf("\n no instructions given82");
			}
		}
		else if (rear[2][1]==rear[1][1]){
			if ((right[2][1]==left[1][1])&&(left[2][1]==front[1][1])&&(front[2][1]==right[1][1])){
				turn_clockwise_front();
				turn_clockwise_front();
				turn_clockwise_bottom();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_bottom();
				turn_clockwise_front();
				turn_clockwise_front();
			}
			else if ((right[2][1]==front[1][1])&&(left[2][1]==right[1][1])&&(front[2][1]==left[1][1])){
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_bottom();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_clockwise_front();
				turn_clockwise_front();
			}
			else {
				printf("\n no instructions given83");
			}
		}
		else if (rear[2][1]==left[1][1]){
			turn_clockwise_bottom();
			if ((rear[2][1]==front[1][1])&&(front[2][1]==right[1][1])&&(right[2][1]==rear[1][1])){
				//printf("\nclockwise");
				turn_clockwise_right();
				turn_clockwise_right();
				turn_clockwise_bottom();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_bottom();
				turn_clockwise_right();
				turn_clockwise_right();
			}
			else if ((front[2][1]==rear[1][1])&&(rear[2][1]==right[1][1])&&(right[2][1]==front[1][1])){
				//printf("\n anticlockwise");
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_bottom();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_anticlockwise_bottom();
				turn_clockwise_right();
				turn_clockwise_right();
			}
			else {
				printf("\n no instructions given84");
			}
		}
		else {
			printf("\n no instructions given85");
		}
	}
	else if ((right[2][0]==right[2][1])&&(right[2][1]==right[2][2])&&(right[2][2]==right[2][0])){
		if (right[2][1]==front[1][1]){
			turn_anticlockwise_bottom();
			if ((left[2][1]==right[1][1])&&(right[2][1]==rear[1][1])&&(rear[2][1]==left[1][1])){
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_clockwise_bottom();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_left();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_bottom();
				turn_clockwise_rear();
				turn_clockwise_rear();
			}
			else if((left[2][1]==rear[1][1])&&(rear[2][1]==right[1][1])&&(right[2][1]==left[1][1])){
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_bottom();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_rear();
				turn_clockwise_rear();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_anticlockwise_bottom();
				turn_clockwise_rear();
				turn_clockwise_rear();
			}
			else {
				printf("\n no instructions given86");
			}
		}
		else if (right[2][1]==right[1][1]){
			if ((front[2][1]==rear[1][1])&&(rear[2][1]==left[1][1])&&(left[2][1]==front[1][1])){
				turn_clockwise_left();
				turn_clockwise_left();
				turn_clockwise_bottom();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_bottom();
				turn_anticlockwise_left();
				turn_anticlockwise_left();
			}
			else if ((front[2][1]==left[1][1])&&(left[2][1]==rear[1][1])&&(rear[2][1]==front[1][1])){
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_left();
				turn_clockwise_left();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_anticlockwise_bottom();
				turn_anticlockwise_bottom();
				turn_clockwise_left();
				turn_clockwise_left();
			}
			else {
				printf("\n no instructions given87");
			}
		}
		else if (right[2][1]==rear[1][1]){
			turn_clockwise_bottom();
			if ((right[2][1]==left[1][1])&&(left[2][1]==front[1][1])&&(front[2][1]==right[1][1])){
				turn_clockwise_front();
				turn_clockwise_front();
				turn_clockwise_bottom();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_clockwise_bottom();
				turn_clockwise_front();
				turn_clockwise_front();
			}
			else if ((right[2][1]==front[1][1])&&(left[2][1]==right[1][1])&&(front[2][1]==left[1][1])){
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_bottom();
				turn_anticlockwise_left();
				turn_clockwise_right();
				turn_clockwise_front();
				turn_clockwise_front();
				turn_anticlockwise_right();
				turn_clockwise_left();
				turn_anticlockwise_bottom();
				turn_clockwise_front();
				turn_clockwise_front();
			}
			else {
				printf("\n no instructions given88");
			}
		}
		else if (right[2][1]==left[1][1]){
			turn_clockwise_bottom();
			turn_clockwise_bottom();
			if ((rear[2][1]==front[1][1])&&(front[2][1]==right[1][1])&&(right[2][1]==rear[1][1])){
				//printf("\nclockwise");
				turn_clockwise_right();
				turn_clockwise_right();
				turn_clockwise_bottom();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_clockwise_bottom();
				turn_clockwise_right();
				turn_clockwise_right();
			}
			else if ((front[2][1]==rear[1][1])&&(rear[2][1]==right[1][1])&&(right[2][1]==front[1][1])){
				//printf("\n anticlockwise");
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_bottom();
				turn_anticlockwise_front();
				turn_clockwise_rear();
				turn_clockwise_right();
				turn_clockwise_right();
				turn_anticlockwise_rear();
				turn_clockwise_front();
				turn_anticlockwise_bottom();
				turn_clockwise_right();
				turn_clockwise_right();
			}
			else {
				printf("\n no instructions given89");
			}
		}
	}
	else {
		printf("\n perform anticlockwise algo");
		turn_clockwise_front();
		turn_clockwise_front();
		turn_anticlockwise_bottom();
		turn_anticlockwise_left();
		turn_clockwise_right();
		turn_clockwise_front();
		turn_clockwise_front();
		turn_anticlockwise_right();
		turn_clockwise_left();
		turn_anticlockwise_bottom();
		turn_clockwise_front();
		turn_clockwise_front();
	}
}
int check_bottom_layer_edges(){
	if ((front[2][1]==front[1][1])&&(right[2][1]==right[1][1])&&(bottom[2][1]==bottom[1][1])&&(left[2][1]==left[1][1])){
		return 0;
	}
	else {
		return 1;
	}
}
int main(){
	print_cube();
	check_cube();
	int cont;
	int cross_unsolved=1;
	while (cross_unsolved){
		create_cross();
		cross_unsolved=check_cross();
		print_cube();
		check_cube();
		printf("\n:");scanf("%d",&cont);
	}
	printf("\n cross made");
	int first_layer_unsolved=1;
	while (first_layer_unsolved){
		fill_corners();
		print_cube();
		check_cube();
		printf("\n:");scanf("%d",&cont);
		first_layer_unsolved=check_first_layer();
	}
	printf("\n first layer solved");
	int edges_unsolved=1;
	while (edges_unsolved){
		fill_edges();
		print_cube();
		check_cube();
		printf("\n:");scanf("%d",&cont);
		edges_unsolved=check_edges();
	}
	int bottom_cross_unsolved=1;
	while (bottom_cross_unsolved){
		fill_bottom_cross();
		print_cube();
		check_cube();
		printf("\n:");scanf("%d",&cont);
		bottom_cross_unsolved=check_bottom_cross();
	}
	int bottom_corners_unsolved=1;
	while (bottom_corners_unsolved){
		fill_bottom_corners();
		print_cube();
		check_cube();
		printf("\n:");scanf("%d",&cont);
		bottom_corners_unsolved=check_bottom_corners();
	}
	int bottom_layer_corners_unmatched=1;
	while (bottom_layer_corners_unmatched){
		match_corners();
		print_cube();
		check_cube();
		printf("\n:");scanf("%d",&cont);
		bottom_layer_corners_unmatched=check_bottom_layer_corners();
	}
	int bottom_edges_unmatched=1;
	printf("\n last step");
	while (bottom_edges_unmatched){
		match_bottom_edges();
		print_cube();
		check_cube();
		printf("\n:");scanf("%d",&cont);
		bottom_edges_unmatched=check_bottom_layer_edges();
	}
	print_cube();
	return 0;
}
