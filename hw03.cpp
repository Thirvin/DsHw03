#include <bits/stdc++.h>
#include "sorted_array.h"
#include "array_of_sorted_arrays.h"
#include "skiplist.h"
#pragma GCC optimize ("O0")
using namespace std;
using namespace chrono;

void print(multiset<int> mst){
	for(int i: mst){
		cout<<i<<" ";
	}
	cout<<"\n";
}
bool equivalent(multiset<int> a,multiset<int> b){
	return a == b;
}

multiset<int> result1;
multiset<int> result2;
multiset<int> result3;

void test_SA(int a,int k){
	ifstream data("out");
	vector<int> _data;
	int t;
	while(data >> t) _data.push_back(t);
	SortedArray sa(_data);

	auto start = high_resolution_clock::now();
	result1 = sa.range_query(a,a+k);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start).count()/1e6;	
	cout<<duration<<" ";
	

}
void test_ASA(int a,int k){
	ifstream data("out");
	vector<int> _data;
	int t;
	while(data >> t) _data.push_back(t);
	AofA asa(_data);

	auto start = high_resolution_clock::now();
	result2 = asa.range_query(a,a+k);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop-start).count()/1e6;
	cout<<duration<<" ";

}
void test_SL(int a,int k){
	ifstream data("out");
	vector<int> _data;
	int t;
	while(data >> t) _data.push_back(t);
	skipList sl(_data);

	auto start = high_resolution_clock::now();
	result3 = sl.range_query(a,a+k);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop-start).count()/1e6;
	cout<<duration<<"\n";
}
int main(int argc,char *argv[]){
	int n = pow(2,20)-1;

	int k = pow(2,atoi(argv[1]));
	mt19937 gen(random_device{}());
	int a = gen()%n;
	test_SA(a,k);
	test_ASA(a,k);
	test_SL(a,k);
	if(equivalent(result1,result2) and equivalent(result2,result3))	{
		cout<<"YES\n";
		cerr<<result1.size()<<"\n";
	}else{
		print(result1);
		print(result2);
		print(result3);
		cout<<"NO\n";
	}
}
