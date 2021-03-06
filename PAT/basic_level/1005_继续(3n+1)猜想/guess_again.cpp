// #include <cstdlib>
#include <iostream>
#include <algorithm>
#define TRUE	1
#define FALSE	0
using namespace std;

typedef struct{
	int value;
	int key;
}Number;

int init_num(Number *num, const int us_N);

// int cmp_dec_c_qsort(const void *p1, const void *p2);
int cmp_dec_cpp_sort(const Number p1, const Number p2);

int filter_keys(Number *num, const int us_N);

int print_key_value(const Number *num, const int us_N);

int main(int argc, char *argv[]){
	int us_N=0, sub_num=0, i=0;

	cin>>us_N;
	Number *num = new Number[us_N];

	init_num(num, us_N);
	// qsort(num, us_N, sizeof(Number), cmp_dec_c_qsort);
	sort(num, &num[us_N], cmp_dec_cpp_sort);
	filter_keys(num, us_N);
	print_key_value(num, us_N);

	delete [] num;
	return 0;
}


int init_num(Number *num, const int us_N){
	int i=0;
	for(i=0; i<us_N; i++){
		cin>>num[i].value;
		num[i].key = TRUE;
	}

	return 0;
}

// int cmp_dec_c_qsort(const void *p1, const void *p2){
// 	const Number *a1 = (const Number *)p1;
// 	const Number *a2 = (const Number *)p2;

// 	return a1->value < a2->value;
// }

int cmp_dec_cpp_sort(const Number p1, const Number p2){
	return p1.value > p2.value;
}

int filter_keys(Number *num, const int us_N){
	int i=0, j=0, sub_num=0;

	for(i=0; i<us_N; i++){
		if( num[i].key==TRUE ){
			sub_num = num[i].value;
			while( sub_num != 1 ){
				if( sub_num%2 )
					sub_num = (sub_num*3 + 1) / 2;
				else
					sub_num /= 2;
				for( j=0; j<us_N; j++ ){
					if( j==i || num[j].key==FALSE )
						continue;
					else if( num[j].value==sub_num ){
						num[j].key = FALSE;
					}
				}
			}
		}
	}

	return 0;
}

int print_key_value(const Number *num, const int us_N){
	int i=0, is_start=1;

	for(i=0; i<us_N; i++){
		if( num[i].key==TRUE ){
			if( is_start==1 ){
				cout<<num[i].value;
				is_start = 0;
			}else
				cout<<' '<<num[i].value;
		}
	}

	return 0;
}
