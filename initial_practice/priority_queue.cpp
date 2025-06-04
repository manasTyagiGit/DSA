#include <bits/stdc++.h>
using namespace std;

// A priority queue is essentially a reverse sorted queue, i.e., the smallest element is at the back,
// and the largest is at the front. On pop(), largest is ejected. It is a non-linear DS, and is 
// represented/implemented by a Tree. It has push(), and pop() as O(log n), and top as O(1)

int main (void)
{
    priority_queue <int> pq;

    pq.push (5);
    pq.push (8);
    pq.push (3);

    cout << pq.top() << "\t" << pq.size() << endl;

    // We can create a max-heap priority queue:

    priority_queue <int> pq_max;                                    // max-heap, normal PQ

    // Or a min-heap priority queue:

    priority_queue <int, vector<int>, greater<int>> pq_min;         // min-healp, sorted PQ

    pq_min.push(16);
    pq_min.push (32);
    pq_min.push(2);
    pq_min.push(1);
    
    cout << "Top of min heap :: " << pq_min.top() << endl;

    return EXIT_SUCCESS;
}