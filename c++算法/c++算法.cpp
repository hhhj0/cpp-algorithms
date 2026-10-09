#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct BinaryTreeNode { //二叉树
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class InsertionSort {  //插入排序
public :
	void insertionsort(vector<int>& arr) {
		int n = arr.size();
		for (int i = 1;i < n;i++) {
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
	}
};
class shellSort { //希尔排序
public :
	void shellsort(vector<int>& arr) {
		int n = arr.size();
		for (int gap = n / 2;gap > 0;gap /= 2) {
			for (int i = gap;i < n;i++) {
				int key = arr[i];
				int j = i;
				while (j >= gap && arr[j - gap] > key) {
					arr[j] = arr[j - gap];
					j -= gap;
				}
				arr[j] = key;
			}
		}
	}
};
class MergeSort {   //归并排序
public:
	void merge(vector<int>& arr, int left,int mid, int right, vector<int>& tmp) {
		int i = left,j = mid + 1, k = 0;
		while (i <= mid && j <= right) {
			if (arr[i] <= arr[j])tmp[k++] = arr[i++];
			else tmp[k++] = arr[j++];
		}
		while (i <= mid)tmp[k++] = arr[i++];
		while (j <= right)tmp[k++] = arr[j++];
		for (int p = 0;p < k;p++) arr[left + p] = tmp[p];
	}
	void mergeSort(vector<int>& arr, int left, int right, vector<int>& tmp) {
		if (left >= right)return;
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid, tmp);
		mergeSort(arr, mid + 1, right, tmp);
		merge(arr, left, mid, right, tmp);
	}
	void mergeSort(vector<int>& arr) {
		if (arr.empty())return;
		vector<int>tmp(arr.size());
		mergeSort(arr, 0, arr.size() - 1, tmp);
	}
};
class QuickSort { //快速排序
public :
	int partition(vector<int>& arr, int low, int high) {
		int pivot = arr[low];
		int i = low, j = high;
		while (i < j) {
			while (i < j && arr[j] >= pivot)j--;
			arr[i] = arr[j];
			while (i < j && arr[i] <= pivot)i++;
			arr[j] = arr[i];
		}
		arr[i] = pivot;
		return i;
	}
	void quicksort(vector<int>& arr, int low, int high) {
		if (low < high) {
			int pos = partition(arr, low, high);
			quicksort(arr, low, pos - 1);
			quicksort(arr, pos + 1, high);
		}
	}
};
class HeapifySort { //堆排序
public:
	void heapify(vector<int>& arr, int n, int i) {
		int largest = i;
		int left = 2 * i + 1, right = 2 * i + 2;
		if (left<n && arr[left]>arr[largest])largest = left;
		if (right<n && arr[right]>arr[largest])largest = right;
		if (largest != i) {
			swap(arr[i], arr[largest]);
			heapify(arr, n, largest);
		}
	}
	void heapsort(vector<int>& arr) {
		int n = arr.size();
		for (int i = n / 2 - 1;i >= 0;--i) {
			heapify(arr, n, i);
		}
		for (int i = n - 1;i > 0;--i) {
			swap(arr[0], arr[i]);
			heapify(arr, i, 0);
		}
	}
};
class CountSort { //计数排序
public:
	void countsort(vector<int>& arr) {
		if (arr.empty())return;
		int min = *min_element(arr.begin(), arr.end());
		int max = *max_element(arr.begin(), arr.end());
		int range = max - min + 1;
		vector<int>count(range, 0);
		for (auto x : arr) {
			count[x - min]++;
		}
		int idx = 0;
		for (int i = 0;i < range;i++) {
			while (count[i] > 0) {
				arr[idx++] = i + min;
				count[i]--;
			}
		}
	}
	};
class BucketSort { //桶排序
public:
	void bucketsort(vector<int>& arr) {
		if (arr.empty())return;
		int min = *min_element(arr.begin(), arr.end());
		int max = *max_element(arr.begin(), arr.end());
		double range = max - min + 1;
		int n = arr.size();
		if (n == 0)return;
		double bucketsize = range / n;
		vector<vector<int>>buckets(n);
		for (auto i : arr) {
			int idx = (i - min) / n;
			if (idx >= n)idx = n - 1;
			buckets[idx].push_back(i);
		}
		for (auto &x : buckets) {
			sort(x.begin(), x.end());
		}
		int pos = 0;
		for (auto &b : buckets) {
			for (auto c : b) {
				arr[pos++] = c;
			}
		}

	}
};
class RadixSort { //基数排序
public :
	void radixsort(vector<int>& arr) {
		if (arr.size() <= 1)return;
		int maxval = *max_element(arr.begin(), arr.end());
		int exp = 1;
		while (maxval / exp > 0) {
			vector<int>temp(arr.size());
			vector<int>count(10, 0);
			for (int i = 0;i < arr.size();i++) {
				int digit = (arr[i] / exp) % 10;
				count[digit]++;
			}
			for (int i = 1;i < 10;i++) {
				count[i] += count[i - 1];
			}
			for (int i = arr.size() - 1;i >= 0;i--) {
				int digit = (arr[i] / exp) % 10;
				temp[count[digit] - 1] = arr[i];
				count[digit]--;
			}
			arr = temp;
			exp *= 10;
		}
	}
};
	class BinaryTree {
	public:
		BinaryTreeNode* root;
		BinaryTree() :root(nullptr) {}
		BinaryTreeNode* buildFromPreorder(vector<int>& data, int& idx) {
			if (idx >= (int)data.size() || data[idx] == -1) { idx++;return nullptr; }
			BinaryTreeNode* node = new BinaryTreeNode(data[idx++]);
			node->left = buildFromPreorder(data, idx);
			node->right = buildFromPreorder(data, idx);
			return node;
		}
		void create(vector<int>& data) {
			int idx = 0;
			root = buildFromPreorder(data, idx);
		}
		void preorder(BinaryTreeNode* node) {
			if (!node)return;
			cout << node->val << "  ";
			preorder(node->left);
			preorder(node->right);
		}
		void inorder(BinaryTreeNode* node) {
			if (!node)return;
			inorder(node->left);
			cout << node->val << " ";
			inorder(node->right);
		}
		void postorder(BinaryTreeNode* node) {
			if (!node)return;
			postorder(node->left);
			postorder(node->right);
			cout << node->val << " ";
		}
		void levelOrder() {
			if (!root)return;
			queue<BinaryTreeNode*>q;
			q.push(root);
			while (!q.empty()) {
				BinaryTreeNode* current = q.front();q.pop();
				cout << current->val << " ";
				if (current->left)q.push(current->left);
				if (current->right)q.push(current->right);
			}
		}
		void destory(BinaryTreeNode* node) {
			if (!node)return;
			destory(node->left);
			destory(node->right);
			delete node;
		}
		~BinaryTree() { destory(root); }
	};
	struct TreeNode {
		int data;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int data) {
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
		}
	};
	TreeNode* findMin(TreeNode* root) {
		while (root->left != nullptr) {
			root = root->left;
		}
		return root;
	}
	TreeNode* deleteNode(TreeNode* root, int data) {
		if (root == nullptr) {
			return root;
		}
		if (data < root->data) {
			root->left = deleteNode(root->left, data);
		}
		else if (data > root->data) {
			root->right = deleteNode(root->right, data);
		}
		else {
			if (root->left == nullptr) {
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) {
				TreeNode* temp = root->left;
				delete root;
				return temp;
			}
		}
	}
	TreeNode* insert(TreeNode* root, int data) {
		if (root == nullptr) {
			return new TreeNode(data);
		}
		if (data < root->data) {
			root->left = insert(root->left, data);
		}
		else if (data > root->data) {
			root->right = insert(root->right, data);
		}
		return root;
	}
	void preorder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
	void inorder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
	void postorder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
	struct Node {
		int data;
		Node* next;
	};
	Node* createNode(int data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		return newNode;
	}
	void insertTail(Node*& head, int data) {
		Node* newNode = createNode(data);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
	void printList(Node* head) {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << "->";
			current = current->next;
		}
		cout << "nullptr" << endl;
	}
	void freeList(Node* head) {
		Node* current = head;
		while (current != nullptr) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}
	int main() {
		InsertionSort sort;
		vector<int>arr = { 11,13,9,5,12,19,14 };
		sort.insertionsort(arr);
		for (auto i : arr) {
			cout << i << " ";
		}
	}


