#ifndef MIN_HEAP
#define MIN_HEAP

#include <iostream>
#include<vector>
using namespace std;

template<typename T>
class MinHeap {
private:
	vector<T> heap;
	void heapifyUp(int index);
	
	void heapifyDown(int index);
public:
	bool isEmpty();
	void insert(T value);
	void remove(int index);
	void printHeap();

	T get_min();
	T extract_min();
};

// min Heap property
template<typename T>
void MinHeap<T>::heapifyUp(int index) {
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (heap[parent] > heap[index]) {
			swap(heap[parent], heap[index]);
			index = parent;
		}
		else {
			break;
		}
	}
}
// min Heap property
template<typename T>
void MinHeap<T>::heapifyDown(int index) {
	int left, right, smallest;
	while (true) {
		left = 2 * index + 1;
		right = 2 * index + 2;
		smallest = index;

		if (left < heap.size() && heap[left] < heap[smallest]) {
			smallest = left;
		}
		if (right < heap.size() && heap[right] < heap[smallest]) {
			smallest = right;
		}

		if (smallest != index) {
			swap(heap[index], heap[smallest]);
			index = smallest;
		}
		else {
			break;
		}
	}
}

template<typename T>
bool MinHeap<T>::isEmpty()
{
	return heap.empty();
	
}

//insert the element
template<typename T>
void MinHeap<T>::insert(T value) {
	heap.push_back(value);
	heapifyUp(heap.size() - 1);
}

//delete an element by index
template<typename T>
void MinHeap<T>::remove(int index)
{
	if (index >= heap.size()) {
		throw out_of_range("Index out of range");
	}
	if (index == heap.size() - 1) {
		heap.pop_back();
		return;
	}
	heap[index] = heap.back();	
	heap.pop_back();
	if (!heap.empty()) {
		if (index > 0 && heap[index] < heap[(index - 1) / 2]) {
			heapifyUp(index);
		}
		else {
			heapifyDown(index);
		}

	}
}
//print
template<typename T>
void MinHeap<T>::printHeap()
{
	for (const auto& x : heap) {
		cout << x << " ";
	}
	cout << endl;
}

//get min element from heap
template<typename T>
T MinHeap<T>::get_min()
{
	if (heap.empty()) {
		throw out_of_range("Heap is empty"); 
	}

	return heap[0];

}

//take out the min element from heap and delete it
template<typename T>
T MinHeap<T>::extract_min()
{
	if (isEmpty()) {
		throw out_of_range("heap is empty");
	}
	T minValue = heap[0];
	heap[0] = heap.back();
	heap.pop_back();

	if (!isEmpty()) {
		heapifyDown(0);
	}
	return minValue;
}
#endif // !MIN_HEAP

