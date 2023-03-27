#include <iostream>
using namespace std;

class Node {
	public:
		Node(int data) : data(data) {
			prev = next = NULL;	
		};
		Node* prev;
		Node* next;
		int data;
};

class Deque {
	public:
		Deque()
		{
			_size = 0;
			_front = _rear = NULL;
		}

		~Deque()
		{
			for (; !empty();)
			{
				pop_front();
			}
		}

		bool empty() { return _size == 0; }
		int front()
		{
			if (empty()) return -1;
			return _front->data;
		}

		int back()
		{
			if (empty()) return -1;
			return _rear->data;
		}
		
		int size()
		{
			return _size;
		}

		void push_front(int data)
		{
			Node* newNode = new Node(data);
			if (empty())
			{
				_front = newNode;
				_rear = newNode;
				_size++;
				return;
			}
			newNode->next = _front;
			_front->prev = newNode;
			_front = newNode;
			_size++;
		}

		void push_back(int data)
		{
			Node* newNode = new Node(data);
			if (empty())
			{
				_front = newNode;
				_rear = newNode;
				_size++;
				return;
			}
			newNode->prev = _rear;
			_rear->next = newNode;
			_rear = newNode;
			_size++;	
		}

		int pop_back()
		{
			if (empty()) return -1;
			Node* dNode = _rear;
			int data = dNode->data;
			
			_size--;
			_rear = dNode->prev;
			if (_rear != NULL)
				_rear->next = NULL;
			delete dNode;
			return data;
		}

		int pop_front()
		{
			if (empty()) return -1;
			Node* dNode = _front;
			int data = dNode->data;

			_size--;
			_front = dNode->next;
			if (_front != NULL)
				_front->prev = NULL;
			delete dNode;
			return data;
		}
	private:
		int _size;
		Node* _front;
		Node* _rear;
};

int N;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	Deque dq;
	cin >> N;

	string cmd;
	while(N--)
	{
		cin >> cmd;
		if (cmd == "push_back")
		{
			int data;
			cin >> data;
			dq.push_back(data);
		}
		else if (cmd == "push_front")
		{
			int data;
			cin >> data;
			dq.push_front(data);
		}
		else if (cmd == "pop_back")
		{
			cout << dq.pop_back() << "\n";
		}
		else if (cmd == "pop_front")
		{
			cout << dq.pop_front() << "\n";
		}
		else if (cmd == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (cmd == "empty")
		{
			cout << dq.empty() << "\n";
		}
		else if (cmd == "front")
		{
			cout << dq.front() << "\n";
		}
		else if (cmd == "back")
		{
			cout << dq.back() << "\n";
		}
	}

	return 0;
}
