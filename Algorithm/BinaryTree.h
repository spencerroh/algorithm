#pragma once

template <class TKey, class TValue, class TComparer>
class BinaryTree
{
	struct Node {
	public:
		Node(TKey key, TValue value) : Key(key), Value(value), Parent(nullptr), Left(nullptr), Right(nullptr) { }
		Node() : Node(TKey(), TValue()) { }

		bool HasLeft() const { return Left != nullptr; }
		bool HasRight() const { return Right != nullptr; }
		bool HasBoth() const { return HasLeft() && HasRight(); }
		bool HasNoChild() const { return !(HasLeft() || HasRight()); }

		const TKey& GetKey() const { return Key; }
		const TValue& GetValue() const { return Value; }

		Node* GetLeftMost()
		{
			if (HasLeft())
				return Left->GetLeftMost();
			else
				return this;
		}

		Node* GetRightMost()
		{
			if (HasRight())
				return Right->GetRightMost();
			else
				return this;
		}

		unsigned int GetDepth() const
		{
			int depthOfLeft = HasLeft() ? Left->GetDepth() : 0;
			int depthOfRight = HasRight() ? Right->GetDepth() : 0;

			return (depthOfLeft > depthOfRight ? depthOfLeft : depthOfRight) + 1;
		}

		unsigned int GetCount() const
		{
			unsigned int count = 0;

			if (HasLeft())
				count += Left->GetCount();

			if (HasRight())
				count += Right->GetCount();

			return count + 1;
		}

		Node* Find(const TKey& key)
		{
			TComparer comparer;

			if (comparer(Value, key))
			{
				if (HasRight())
					return Right->Find(key);
				else
					return nullptr;
			}
			else if (comparer(key, Value))
			{
				if (HasLeft())
					return Left->Find(key);
				else
					return nullptr;
			}
			else
			{
				return this;
			}
		}

		void Add(Node* node)
		{
			if (node == nullptr)
				return;

			TComparer comparer;

			if (comparer(Value, node->Value))
			{
				if (HasRight())
					Right->Add(node);
				else
				{
					Right = node;
					node->Parent = this;
				}
			}
			else
			{
				if (HasLeft())
					Left->Add(node);
				else
				{
					Left = node;
					node->Parent = this;
				}
			}
		}

		Node* Remove()
		{
			if (HasBoth())
			{
				Node* rightMost = Left->GetRightMost();

				Swap(rightMost);

				return rightMost->Remove();
				
			}
			else if (HasLeft())
			{
				if (Parent->Left == this)
				{
					Parent->Left = Left;
					Left->Parent = Parent;
					return this;
				}
				else
				{
					Parent->Right = Left;
					Left->Parent = Parent;
					return this;
				}
			}
			else if (HasRight())
			{
				if (Parent->Left == this)
				{
					Parent->Left = Right;
					Right->Parent = Parent;
					return this;
				}
				else
				{
					Parent->Right = Right;
					Right->Parent = Parent;
					return this;
				}
			}
			else
			{
				if (Parent->Left == this)
					Parent->Left = nullptr;
				else
					Parent->Right = nullptr;

				return this;
			}
		}

		Node* Next() 
		{
			if (Right != nullptr)
			{
				return Right->GetLeftMost();
			}
			else
			{
				Node* current = this;
				
				while (current->Parent != nullptr)
				{
					if (current == current->Parent->Left)
						return current->Parent;
					else
						current = current->Parent;
				}

				return nullptr;
			}
		}

	private:
		void Swap(Node* node)
		{
			TKey tempKey = node->Key;
			node->Key = Key;
			Key = tempKey;

			TValue tempValue = node->Value;
			node->Value = Value;
			Value = tempValue;
		}

	private:
		TKey Key;
		TValue Value;

		Node* Parent;
		Node* Left;
		Node* Right;
	};

private:
	Node* mNode;

public:
	BinaryTree() : mNode(nullptr)
	{

	}

	bool Find(const TKey& key, TValue& value) const
	{
		if (mNode == nullptr)
			return false;
		else
		{
			Node* found = mNode->Find(key);

			if (found == nullptr)
				return false;
			else
			{
				value = found->GetValue;
				return true;
			}
		}
	}

	void Add(TKey key, TValue value)
	{
		Node* newNode = new Node(key, value);

		if (mNode == nullptr)
		{
			mNode = newNode;
		}
		else
		{
			mNode->Add(newNode);
		}
	}
	void Remove(TKey key)
	{
		if (mNode == nullptr)
			return;
		else
		{
			Node* found = mNode->Find(key);
			
			if (found == nullptr)
				return;
			else
			{
				Node* removed = found->Remove();
				delete removed;
			}
		}
	}

	bool Next(const TKey& key, TValue& value)
	{
		if (mNode == nullptr)
			return false;
		else
		{
			Node* found = mNode->Find(key);

			if (found == nullptr)
				return false;

			Node* next = found->Next();

			if (next == nullptr)
				return false;

			value = next->GetValue();
			return true;
		}
	}
	
	unsigned int GetDepth() const
	{
		if (mNode == nullptr)
			return 0;
		else
			return mNode->GetDepth();
	}

	unsigned int GetCount() const
	{
		if (mNode == nullptr)
			return 0;
		else
			return mNode->GetCount();
	}
};