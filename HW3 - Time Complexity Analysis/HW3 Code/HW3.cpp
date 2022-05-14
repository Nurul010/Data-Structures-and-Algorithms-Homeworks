#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <cmath>
#include <sstream>
#include <string>



using namespace std;


// x: input array
// n: length of array
void oneSecond(){
    this_thread::sleep_for(1s);
}


double* prefixAverage1(double* x, int len){
	double* a = new double[len];
	for(int j = 0; j < len; j++){
		double total = 0;
		for(int i = 0; i <= j; i++){
			total += x[i];
		}
		a[j] = total/(j+1);
	}
	return a;
}


// x: input array
// n: length of array
double* prefixAverage2(double* x, int len){
	double* a = new double[len];
	double total = 0;
	for(int j = 0; j < len; j++){
		total += x[j];
		a[j] = total/(j+1);
	}
	return a;
}


// x: input array
// n: length of array
int example1(int* x, int len){
	int total = 0;
	for(int i = 0; i < len; i++){
		total += x[i];
	}
	return total;
}


// x: input array
// n: length of array
int example2(int* x, int len){
	int total = 0;
	for(int i = 0; i < len; i+=2){
		total += x[i];
	}
	return total;
}


// x: input array
// n: length of array
int example3(int* x, int len){
	int total = 0;
	for(int i = 0; i < len; i++){
		for(int k = 0; k <= i; k++){
			total += x[i];
		}
	}
	return total;
}


// x: input array
// n: length of array
int example4(int* x, int len){
	int prefix = 0;
	int total = 0;
	for(int i = 0; i < len; i++){
		prefix += x[i];
		total += prefix;
	}
	return total;
}


// x: input array
// n: length of array
int example5(int* first, int* second, int len){
	int count = 0;
	for(int i = 0; i < len; i++){
		int total = 0;
		for(int j = 0; j < len; j++){
			for(int k = 0; k <= j; k++){
				total += first[k];
			}
		}
		if(second[i] == total){
			count++;
		}
	}
	return count;
}



int main(int argc, char** argv){
	// depending on argv call one of these functions:
	// p1 for prefixAverage1, p2 for prefixAverage2, e1 for example1
	// e2 for example2, e3 for example3, e4 for example4, e5 for example5
	string j = argv[3];
	istringstream ss(j);
	int upperlimit;
	ss>>upperlimit;
	string algorithm = argv[1];
	ofstream output(argv[2]);
	for(int i = 1; i<=upperlimit; i++){
		int length = pow(10, i);
		//output << "length: " << length << endl;
		//cout << "length: " << length << endl;
		double arr[length];
		int arr2[length];
		for(int j = 0; j < length; j++){
			arr[j] = 0;
			arr2[j] = 0;
    	}
		double *a;
		int a2;
		auto start = std::chrono::steady_clock::now();

		if(algorithm == "p1"){
			a = prefixAverage1(arr, length);
            //cout << *a << "\n";
		}
		else if (algorithm == "p2"){
			a = prefixAverage2(arr, length);
            //cout << *a << "\n";
		}
		else if (algorithm == "e1"){
			a2 = example1(arr2, length);
            //cout << a2 << "\n";
		}
		else if (algorithm == "e2"){
			a2 = example2(arr2, length);
            // cout << a2 << "\n";
		}
		else if (algorithm == "e3"){
			a2 = example3(arr2, length);
            // cout << a2 << "\n";
		}
		else if (algorithm == "e4"){
			a2 = example4(arr2, length);
            // cout << a2 << "\n";
		}
		else if (algorithm == "e5"){
			a2 = example5(arr2, arr2, length);
            // cout << a2 << "\n";
		}

		auto end = std::chrono::steady_clock::now();
		chrono::duration<double, std::milli> duration = end - start;
		cout << "for magnitude " << i << ":\n";
		cout << (duration.count()) << "ms\n";
		//output << "for magnitude " << i << ":\n";
		output << log10(duration.count()) << "\n";
	}

	output.close();
	return 0;
}