// NodeLL.h
#ifndef __NODE_LL_H__
#define __NODE_LL_H__


class NodeLL  // ll = linked List
{
public:
	NodeLL()
	{
		id = 0; prox = nullptr; tail = nullptr;count = 0;
	};

	NodeLL(int id, NodeLL* prox, NodeLL* tail, int count)
	{
		this->id = id;
		this->prox = prox;
		this->tail = tail;
		this->count = count;
	};

	~NodeLL();

	NodeLL* getProx()
	{
		return prox;
	};

	int getId()
	{
		return id;
	};

	void setProx(NodeLL* prox)
	{
		this->prox = prox;
	};

	void setId(int id)
	{
		this->id = id;
	};

	int getCount()
	{
		return count;
	}
	void setCount(int n)
	{
		this->count = n;
	}
	void setTail(NodeLL* tail)
	{
		this->tail = tail;
	}

	NodeLL* getTail()
	{
		return tail;
	}

private:
	int id;
	NodeLL* prox;
	NodeLL* tail;
	int count;
};
#endif
