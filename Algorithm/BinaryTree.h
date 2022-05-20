#pragma once

template <class TKey, class TValue, class TComparer>
class BinaryNode
{
public:
	BinaryNode(TKey key, TValue value) : Key(key), Value(value), Parent(nullptr), Left(nullptr), Right(nullptr) { }
	BinaryNode(TKey key) : BinaryNode(key, key) { }
	BinaryNode() : BinaryNode(TKey(), TValue()) { }
	~BinaryNode() {
		if (Left != nullptr)
			delete Left;

		if (Right != nullptr)
			delete Right;
	}

	bool HasLeft() const { return Left != nullptr; }
	bool HasRight() const { return Right != nullptr; }
	bool HasBoth() const { return HasLeft() && HasRight(); }
	bool HasNoChild() const { return !(HasLeft() || HasRight()); }
	bool HasParent() const { return Parent != nullptr; }
	bool IsLeft() const { return (Parent != nullptr) && (Parent->Left == this); }
	bool IsRight() const { return (Parent != nullptr) && (Parent->Right == this); }

	const TKey& GetKey() const { return Key; }
	const TValue& GetValue() const { return Value; }

	BinaryNode* GetLeft() { return Left; }
	BinaryNode* GetRight() { return Right; }
	BinaryNode* GetParent() { return Parent; }
	BinaryNode* GetRoot()
	{
		if (Parent == nullptr)
			return this;
		else
			return Parent->GetRoot();
	}

	BinaryNode* GetLeftMost()
	{
		if (HasLeft())
			return Left->GetLeftMost();
		else
			return this;
	}

	BinaryNode* GetRightMost()
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

	BinaryNode* Find(const TKey& key)
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

	void Add(BinaryNode* node)
	{
		if (node == nullptr)
			return;

		if (TComparer()(Value, node->Value))
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

	BinaryNode* Remove()
	{
		if (HasBoth())
		{
			BinaryNode* rightMost = Left->GetRightMost();

			Swap(rightMost);

			return rightMost->Remove();

		}
		else if (HasLeft())
		{
			if (HasParent())
			{
				if (IsLeft())
				{
					Parent->Left = Left;
					Left->Parent = Parent;
					return Parent->GetRoot();
				}
				else
				{
					Parent->Right = Left;
					Left->Parent = Parent;
					return Parent->GetRoot();
				}
			}
			else
			{
				return Left;
			}
		}
		else if (HasRight())
		{
			if (IsLeft())
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
			if (IsLeft())
				Parent->Left = nullptr;
			else
				Parent->Right = nullptr;

			return this;
		}
	}

	BinaryNode* Next()
	{
		if (Right != nullptr)
		{
			return Right->GetLeftMost();
		}
		else
		{
			BinaryNode* current = this;

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

	BinaryNode* Previous()
	{
		if (Left != nullptr)
		{
			return Left->GetRightMost();
		}
		else
		{
			BinaryNode* current = this;

			while (current->Parent != nullptr)
			{
				if (current == current->Parent->Right)
					return current->Parent;
				else
					current = current->Parent;
			}

			return nullptr;
		}
	}

private:
	void Swap(BinaryNode* node)
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

	BinaryNode* Parent;
	BinaryNode* Left;
	BinaryNode* Right;
};

template <class TKey, class TValue, class TComparer>
class BinaryTree
{
	
private:
	typedef BinaryNode<TKey, TValue, TComparer> TNode;
	TNode* mNode;

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
		auto newNode = new TNode(key, value);

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
			auto* found = mNode->Find(key);
			
			if (found == nullptr)
				return;
			else
			{
				auto* removed = found->Remove();
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
			auto found = mNode->Find(key);

			if (found == nullptr)
				return false;

			auto next = found->Next();

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