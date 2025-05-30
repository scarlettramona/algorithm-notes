#include <iostream>
#include <vector>
#include <stdexcept>


// array index relationships
// parent: (i - 1) / 2
// left child: 2 * i + 1
// right child: 2 * i + 2


class MinHeap {
private:
    std::vector<int> heap;

    // returns the parent index
    int parent(int i) {
        return (i - 1) / 2;
    }

    // returns the left child index
    int leftChild(int i) {
        return 2 * i + 1;
    }

    // returns the right child index
    int rightChild(int i) {
        return 2 * i + 2;
    }

    // moves the element at index i up to restore the heap property
    void bubbleUp(int i) {
        while (i > 0 && heap[i] < heap[parent(i)]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // moves the element at index i down to restore the heap property
    void bubbleDown(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        // find the smallest among the current node and its children
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // swap and continue bubbling down if the current node is not the smallest
        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            bubbleDown(smallest);
        }
    }

public:
    // adds an element to the heap
    void insert(int value) {
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }

    // removes and returns the minimum element
    int extractMin() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        int rootValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        bubbleDown(0);
        return rootValue;
    }

    // returns the minimum element without removing it
    int getMin() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    // returns the current size of the heap
    int size() const {
        return heap.size();
    }

    // prints the contents of the heap (for debugging)
    void printHeap() {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    MinHeap heap;
    heap.insert(10);
    heap.insert(15);
    heap.insert(20);
    heap.insert(17);
    heap.insert(8);

    std::cout << "Heap contents: ";
    heap.printHeap();

    std::cout << "Extracted min: " << heap.extractMin() << "\n";
    std::cout << "Heap after extraction: ";
    heap.printHeap();

    std::cout << "Current min: " << heap.getMin() << "\n";

    return 0;
}
