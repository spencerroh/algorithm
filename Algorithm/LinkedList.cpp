template <class T>
struct List
{
	T Value;
	List<T>* Next;
};

template <class T>
List<T>* Add(List<T>** head, T value)
{
	List<T>* node = new List<T>();
	node->Value = value;
	node->Next = *head;

	*head = node;

	return node;
}

template <class T>
void Remove(List<T>** head, T value)
{
	List<T>* p = nullptr, *c = *head;

	while (c != nullptr)
	{
		if (c->Value == value)
		{
			if (p == nullptr) *head = c->Next;
			else p->Next = c->Next;

			delete c;
			return;
		}

		p = c;
		c = c->Next;
	}

	return nullptr;
}

template <class T>
void Clear(List<T>** head)
{
	List<T> *p = nullptr, *c = *head;

	while (c != nullptr)
	{
		p = c;
		c = c->Next;

		delete p;
	}

	*head = nullptr;
}