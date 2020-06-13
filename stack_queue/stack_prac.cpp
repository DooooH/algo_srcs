#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
	dat[pos] = x;
	pos++;
}

void pop(){
	pos--;
}

int top(){
	return dat[pos - 1];
}

void test(){

}

int main(void) {
	test();
}