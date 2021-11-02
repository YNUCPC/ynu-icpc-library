#pragma once
#include<bits/stdc++.h>
using namespace std;

// 整数配列を複素数へ
 
vector<complex<double>> encode(vector<long long> &a){
    int N = a.size();
    vector<complex<double>> ret(N);
    for(int i = 0;i < N;i++){
        ret[i] = complex<double>(a[i],0);
    }
    return ret;
}
 
//複素数配列を整数へ
vector<long long> decode(vector<complex<double>> &a){
    int N = a.size();
    vector<long long> ret(N);
    for(int i = 0;i < N;i++){
        ret[i] = (long long)round(a[i].real());
    }
    return ret;
}
 
//非再帰
void FFT(vector<complex<double>> &a,int reverse = false) {
    int n = a.size();
    int h = 0; 
    for (int i = 0; 1 << i < n; i++) h++;
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (int k = 0; k < h; k++) j |= (i >> k & 1) << (h - 1 - k);
        if (i < j) swap(a[i], a[j]);
    }
    for (int b = 1; b < n; b *= 2) {
        for (int j = 0; j < b; j++) {
            double p2 = 2*acos(-1);
            if(reverse)p2 *= -1;
            complex<double> w = exp(complex<double>(0,p2*j/(double)(2*b)));
            for (int k = 0; k < n; k += b * 2) {
                complex<double> s = a[j+k];         
                complex<double> t = a[j+k+b]*w; 
                a[j+k] = s+t;                    
                a[j+k+b] = s-t;                 
            }
        }
    }
    if (reverse)for (int i = 0; i < n; i++) a[i] /= (double)n;
    return;
}
 
vector<long long> convolution(vector<long long> &a,vector<long long> &b){
    vector<complex<double>> A = encode(a),B = encode(b);
    int s = (int)a.size()+(int)b.size()-1;
    int t = 1;
    while(t < s)t *= 2;
    A.resize(t);B.resize(t);
    FFT(A,0);FFT(B,0);
    for(int i = 0;i < t;i++){
        A[i] *= B[i];
    }
    FFT(A,1);
    A.resize(s);
    return decode(A);
}