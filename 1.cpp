#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include<conio.h>
using namespace std;
void begin() , change( int s ) , gm();
bool go() , gyj( int x , int y , char z );
int a[4][4];
int main(){
	srand( (int) time (0) );
	int time;
	cout << "按任意键开始";
	getch();
	begin();
	time = clock();
	gm();
	system("cls");
	cout << "你赢了!\n用时" << ( clock() - time ) / 60000 << "分" << (( clock() - time ) / 1000 ) % 60 << "秒" << endl;;
	system("pause");
}
void begin(){		//将15个数字打乱 
	char z;
	int erb[15] , k , l = 0;
	for( int i = 0 ; i < 14 ; i++ ){
		erb[i] = 99;
	}
	for( int i = 0 ; i < 4 ; i++ ){
		for( int j = 0 ; j < 4 ; j++ ){
			if( i == 3 && j == 3 ){
				break;
			}
			aaa:;
			k = rand() % 16;
			for( int x = 0 ; x < 16 ; x++ ){
				if( k == erb[x] || k == 0 ){
					goto aaa;
				}
			}
			a[i][j] = k;
			erb[l] = k;
			l++;
		}
	}
}
void change( int s ){		//将数字工整地输出 
	char x;
	switch( s ){
		case 1 : cout << "1 ";break;
		case 2 : cout << "2 ";break;
		case 3 : cout << "3 ";break;
		case 4 : cout << "4 ";break;
		case 5 : cout << "5 ";break;
		case 6 : cout << "6 ";break;
		case 7 : cout << "7 ";break;
		case 8 : cout << "8 ";break;
		case 9 : cout << "9 ";break;
		case 10 : cout << "10";break;
		case 11 : cout << "11";break;
		case 12 : cout << "12";break;
		case 13 : cout << "13";break;
		case 14 : cout << "14";break;
		case 15 : cout << "15";break;
		default: cout << "  ";break;
	}
}
void gm(){		//游戏主体部分 
	char z;
	int k_i = 3 , k_j = 3 , t;
	for( ; ; ){
		if( go() == 0 ){
			break;
		}
		system("cls");
		for( int i = 0 ; i < 4 ; i++ ){
			for( int j = 0 ; j < 4 ; j++ ){
				change( a[i][j] );
				cout << ' ';
			}
			cout << endl;
		}
		z = getch();
		if( gyj( k_i , k_j , z ) == 1 ){}
		else if( z == 'w' || z == 'W' ){
			t = a[k_i - 1][k_j];
			a[k_i - 1][k_j] = 0;
			a[k_i][k_j] = t;
			k_i--;
		}
		else if( z == 's' || z == 'S' ){
			t = a[k_i + 1][k_j];
			a[k_i + 1][k_j] = 0;
			a[k_i][k_j] = t;
			k_i++;
		}
		else if( z == 'a' || z == 'Z' ){
			t = a[k_i][k_j - 1];
			a[k_i][k_j - 1] = 0;
			a[k_i][k_j] = t;
			k_j--;
		}
		else if( z == 'd' || z == 'D' ){
			t = a[k_i][k_j + 1];
			a[k_i][k_j + 1] = 0;
			a[k_i][k_j] = t;
			k_j++;
		}
	}
}
bool go(){		//检查有没有赢，15个数字有没有归位 
	int z = 0 , k = 0;
	for( int i = 0 ; i < 4 ; i++ ){
		for( int j = 0 ; j < 4 ; j++ ){
			if( i == 3 && j == 3){
				break;
			}
			z++;
			if( a[i][j] != z ){
				k = 1;
				goto bbb;
			}
		}
	}
	bbb:;
	return k;
}
bool gyj( int x , int y , char z ){		//检测有没有数组越界 
	int t = 0;
	if( x == 0 ){
		if( z == 'w' || z == 'W' ){
			t = 1;
		}
	}
	if( x == 3 ){
		if( z == 's'|| z == 'S' ){
			t = 1;
		}
	}
	if( y == 0 ){
		if( z == 'a'|| z == 'A' ){
			t = 1;
		}
	}
	if( y == 3 ){
		if( z == 'd'|| z == 'D' ){
			t = 1;
		}
	}
	return t;
}
