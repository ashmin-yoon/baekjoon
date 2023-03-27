#include <iostream>
using namespace std;

class Node {
	public:
		Node(int data) : data(data) { prev = NULL; next = NULL;}
		Node* prev;
		Node* next;
		int data;
};

class Queue {
	public:
		Queue()
		{
			_size = 0;
			_front = NULL;
			_rear = NULL;
		}

		~Queue()
		{
			for (; !empty();)
			{
				pop();
			}
		}	

		void push(int data) 
		{ 
			if (empty())
			{
				_rear= new Node(data);
				_front = _rear;
				_size++;	
				return;
			}

			_size++;	
			Node* preRear = _rear;
			_rear = new Node(data);
			_rear->prev = preRear;
			preRear->next = _rear;
		}

		int pop()
		{
			if (empty()) 
				return -1;
			Node* dNode = _front;
			_front = _front->next;

			int data = dNode->data;
			delete dNode;
			_size--;
			return data;
		}

		int size() 
		{ 
			return _size;
		}

		bool empty()
		{
			return _size == 0;
		}

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
	Queue q;
	cin >> N;

	string cmd;
	while(N--)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			int data;
			cin >> data;
			q.push(data);
		} 
		else if (cmd == "pop")
		{
			cout << q.pop() << '\n';
		}
		else if (cmd == "size")
		{
			cout << q.size() << '\n';
		}
		else if (cmd == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (cmd == "front")
		{
			cout << q.front() << '\n';
		}
		else if (cmd == "back")
		{
			cout << q.back() << '\n';
		}
	}

	return 0;
}
