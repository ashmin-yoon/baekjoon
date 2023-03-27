#include <iostream>
using namespace std;

template <typename T>
class Node {
	public:
		Node(T data) : data(data) { prev = NULL; next = NULL;}
		Node* prev;
		Node* next;
		T data;
};

template <typename T>
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

		void push(T data) 
		{ 
			if (empty())
			{
				_rear= new Node<T>(data);
				_front = _rear;
				_size++;	
				return;
			}

			_size++;	
			Node<T>* preRear = _rear;
			_rear = new Node<T>(data);
			_rear->prev = preRear;
			preRear->next = _rear;
		}

		T pop()
		{
			if (empty()) 
				return -1;
			Node<T>* dNode = _front;
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

		T front()
		{
			if (empty()) return -1;
			return _front->data;
		}

		T back()
		{
			if (empty()) return -1;
			return _rear->data;
		}

	private:
		int _size;
		Node<T>* _front;
		Node<T>* _rear;

};

int N;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	Queue<int> q;
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
