#include <cassert>
#include "min_heap_implementation.h"


void test_insert() {
    MinHeap<int> heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);

    assert(heap.get_min() == 1);
    cout << "test_insert passed!" << endl;
}

void test_extract_min() {
    MinHeap<int> heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);

    assert(heap.extract_min() == 1);
    assert(heap.extract_min() == 3);
    assert(heap.extract_min() == 5);
    assert(heap.extract_min() == 8);

    assert(heap.isEmpty());  
    cout << "test_extract_min passed!" << endl;
}

void test_remove() {
    MinHeap<int> heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    heap.insert(4);

    heap.remove(1); 
    assert(heap.get_min() == 1);

    heap.remove(0); 
    assert(heap.get_min() == 4);

    cout << "test_remove passed!" << endl;
}

void test_get_min() {
    MinHeap<int> heap;
    heap.insert(10);
    heap.insert(15);
    heap.insert(5);
    assert(heap.get_min() == 5);

    heap.extract_min();
    assert(heap.get_min() == 10);

    cout << "test_get_min passed!" << endl;
}

void test_empty_heap() {
    MinHeap<int> heap;
    try {
        heap.get_min();
        assert(false);  
    }
    catch (const out_of_range&) {
        cout << "test_empty_heap (get_min) passed!" << endl;
    }

    try {
        heap.extract_min();
        assert(false);  
    }
    catch (const out_of_range&) {
        cout << "test_empty_heap (extract_min) passed!" << endl;
    }
}


int main()
{
    test_insert();
    test_extract_min();
    test_remove();
    test_get_min();
    test_empty_heap();
    
    cout << "All tests passed!" << endl;
    
    return 0;
}




