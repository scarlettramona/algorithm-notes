#include <iostream>
#include <vector>
#include <stdexcept>

class MaxHeap {
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
        while (i > 0 && heap[i] > heap[parent(i)]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // moves the element at index i down to restore the heap property
    void bubbleDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        // find the largest among the current node and its children
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        // swap and continue bubbling down if the current node is not the largest
        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            bubbleDown(largest);
        }
    }

public:
    // adds an element to the heap
    void insert(int value) {
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }

    // removes and returns the maximum element
    int extractMax() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        int rootValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        bubbleDown(0);
        return rootValue;
    }

    // returns the maximum element without removing it
    int getMax() {
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
    MaxHeap heap;
    heap.insert(10);
    heap.insert(15);
    heap.insert(20);
    heap.insert(17);
    heap.insert(8);

    std::cout << "Heap contents: ";
    heap.printHeap();

    std::cout << "Extracted max: " << heap.extractMax() << "\n";
    heap.printHeap();

    std::cout << "Current max: " << heap.getMax() << "\n";

    return 0;
}
