#include <iostream>
#include <vector>
 
using std::vector;
 
struct segment {
    int a;
    int b;
 
    segment(int _a, int _b) : a(_a), b(_b) {};
};
 
bool operator<(const segment &X, const segment &Y) {
    return X.b < Y.b;
}
 
void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}
 
template<typename DataType>
void insertionSort(vector<DataType> &A) {
    for (int i = 1; i < A.size(); ++i) {
        DataType key = A[i];
        int j = i - 1;
 
        while (j >= 0 && key < A[j]) {
            A[j + 1] = A[j];
            --j;
        }
 
        A[j + 1] = key;
    }
}
 
template<typename DataType>
void heapSort(vector<DataType> &A) {
    for (int i = A.size() / 2 - 1; i >= 0; --i) {
        int j = i;
 
        while (2 * j + 1 < A.size()) {
            int smallest = 2 * j + 1;
 
            if (2 * j + 2 < A.size() && A[smallest] < A[2 * j + 2]) {
                smallest = 2 * j + 2;
            }
 
            if (!(A[j] < A[smallest])) {
                break;
            }
            std::swap(A[j], A[smallest]);
            j = smallest;
        }
    }
 
    int heapSize = A.size();
 
    for (int i = 0; i < A.size() - 1; ++i) {
        std::swap(A[0], A[A.size() - 1 - i]);
        heapSize--;
        int j = 0;
        while (2 * j + 1 < heapSize) {
            int smallest = 2 * j + 1;
 
            if (2 * j + 2 < heapSize && A[smallest] < A[2 * j + 2]) {
                smallest = 2 * j + 2;
            }
 
            if (!(A[j] < A[smallest])) {
                break;
            }
            std::swap(A[j], A[smallest]);
            j = smallest;
        }
    }
}
 
 
int main() {
    int n = 0;
 
    std::cin >> n;
 
    vector<segment> A;
 
    for (int i = 0; i < n; ++i) {
        int a = 0;
        int b = 0;
 
        std::cin >> a >> b;
 
        A.emplace_back(a, b);
    }
 
    heapSort(A);
 
    int answer = 0;
    int lastAd1 = -1;
    int lastAd2 = -1;
 
    for (int i = 0; i < n; ++i) {
        if (lastAd2 < A[i].a) {
            if (lastAd1 < A[i].a) {
                lastAd1 = A[i].b - 1;
                lastAd2 = A[i].b;
                answer += 2;
            } else {
                lastAd1 = lastAd2;
                lastAd2 = A[i].b;
 
                if (lastAd1 == lastAd2) {
                    --lastAd1;
                }
 
                answer += 1;
            }
        } else if(lastAd1 < A[i].a){
            lastAd1 = lastAd2;
            lastAd2 = A[i].b;
 
            if (lastAd1 == lastAd2) {
                --lastAd1;
            }
 
            answer += 1;
        }
    }
 
    std::cout << answer;
 
    return 0;
}
