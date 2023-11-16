//Aidan Sullivan
//05-17-2023
//Chapter 6 Assignment - 6.34 - Write an efficient routine to perform insert using binomial queues. Do not call merge.

#include<iostream>
#include<vector>
using namespace std;

template<typename Comparable>
class BinomialQueue
{
public:
	BinomialQueue();
	BinomialQueue(const Comparable& item);
	BinomialQueue(const BinomialQueue& rhs);
	BinomialQueue(BinomialQueue&& rhs);
	
	~BinomialQueue();

	BinomialQueue& operator=(const BinomialQueue& rhs);
	BinomialQueue& operator=(BinomialQueue&& rhs);

	bool isEmpty() const;
	const Comparable& findMin() const;

	void insert(const Comparable& x);
	void deleteMin();
	void deleteMin(Comparable& minItem);

	void makeEmpty();

private:
	struct BinomialNode
	{
		Comparable element;
		BinomialNode* leftChild;
		BinomialNode* nextSibling;

		BinomialNode(const Comparable & e, BinomialNode *lt, BinomialNode *rt)
			: element{ e }, leftChild{ lt }, nextSibling{ rt } {}

		BinomialNode(Comparable&& e, BinomialNode* lt, BinomialNode* rt)
			: element{ std::move(e) }, leftChild{ lt }, nextSibling{ rt } {}
	};

	const static int DEFAULT_TREES = 1;

	vector<BinomialNode*> theTrees; // An array of tree roots
	int currentSize; // Number of items in the priority queue

	int findMinIndex() const;
	int capacity() const;
    BinomialNode* combineTrees(BinomialNode* t1, BinomialNode* t2);
	void makeEmpty(BinomialNode*& t);
	BinomialNode* clone(BinomialNode* t) const;
};


template<typename Comparable>
void BinomialQueue<Comparable>::insert(const Comparable& x) //Insert function for binomial queue
{
	BinomialQueue rhs;
	rhs.currentSize = 1;
	rhs.theTrees[0] = new BinomialNode<Comparable>(x, nullptr, nullptr);
    
    if (this == &rhs)
        return;

    currentSize += rhs.currentSize;

    if (currentSize > capacity())
    {
        int oldNumTrees = theTrees.size();
        int newNumTrees = max(theTrees.size(), rhs.theTrees.size()) + 1;
        theTrees.resize(newNumTrees);
        for (int i = oldNumTrees; i < newNumTrees; ++i)
            theTrees[i] = nullptr;
    }

    BinomialNode *carry = nullptr;
    for (int i = 0, j = 1; j <= currentSize; i++, j *= 2)
    {
        BinomialNode* t1 = theTrees[i];
        BinomialNode* t2 = i < rhs.theTrees.size() ? rhs.theTrees[i] : nullptr;


        int whichCase = t1 == nullptr ? 0 : 1;
        whichCase += t2 == nullptr ? 0 : 2;
        whichCase += carry == nullptr ? 0 : 4;

        switch (whichCase)
        {
        case 0: /* No trees */
        case 1: /* Only this */
            break;
        case 2: /* Only rhs */
            theTrees[i] = t2;
            rhs.theTrees[i] = nullptr;
            break;
        case 4: /* Only carry */
            theTrees[i] = carry;
            carry = nullptr;
            break;
        case 3: /* this and rhs */
            carry = combineTrees(t1, t2);
            theTrees[i] = rhs.theTrees[i] = nullptr;
            break;
        case 5: /* this and carry */
            carry = combineTrees(t1, carry);
            theTrees[i] = nullptr;
            break;
        case 6: /* rhs and carry */
            carry = combineTrees(t2, carry);
            rhs.theTrees[i] = nullptr;
            break;
        case 7: /* All three */
            theTrees[i] = carry;
            carry = combineTrees(t1, t2);
            rhs.theTrees[i] = nullptr;
            break;
        }
    }

    for (int k = 0; k < rhs.theTrees.size(); k++)
        rhs.theTrees[k] = nullptr;
    rhs.currentSize = 0;
}

template<typename Comparable>
BinomialNode* BinomialQueue<Comparable>::combineTrees(BinomialNode* t1, BinomialNode* t2)
{
    if (t2->element < t1->element)
        return combineTrees(t2, t1);
    t2->nextSibling = t1->leftChild;
    t1->leftChild = t2;
    return t1;
}
