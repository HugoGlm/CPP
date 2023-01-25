#pragma once
#include <initializer_list>
#include <exception>
#include "../KeyValuePair/KeyValuePair.h"

template<typename Ty>
struct hash
{
	size_t operator()(Ty _value) const;
};

template<typename Key, typename Value>
struct Hash
{
	Key key;
	Value value;
};

template<typename Key, typename Value>
class Map
{
#pragma region f/p
private:
	KeyValuePair<Key, Value>* map = new KeyValuePair<Key, Value>[0];
	int count = 0;
#pragma endregion
#pragma region typedef
public:
	typedef KeyValuePair<Key, Value>* iterator;
	typedef const KeyValuePair<Key, Value>* const_iterator;
	iterator begin()
	{
		return &map[0];
	}
	const_iterator begin() const
	{
		return &map[0];
	}
	iterator end()
	{
		return &map[count];
	}
	const_iterator end() const
	{
		return &map[count];
	}
#pragma endregion
#pragma region constructor
public:
	Map() = default;
	Map(std::initializer_list<KeyValuePair<Key, Value>> _map);
	Map(const Map& _copy);
	~Map();
#pragma endregion
#pragma region methods
private:
	int IndexOfKey(const Key& _key) const;
public:
	void Insert(const Key& _key, const Value& _value);
	void Insert(const KeyValuePair<Key, Value>& _pair);
	Value& At(const Key& _key);
	void Clear();
	bool IsEmpty() const;
	void Remove(const Key& _key);
	bool Contains(const Key& _key);
#pragma endregion
#pragma region operator
public:
	Value& operator[](const Key& _key);
#pragma endregion

};

#pragma region constructor
template<typename Key, typename Value>
Map<Key, Value>::Map(const std::initializer_list<KeyValuePair<Key, Value>> _map)
{
	for (KeyValuePair<Hash<Key, Value>> _pair : _map)
		Insert(_pair);
}
template<typename Key, typename Value>
Map<Key, Value>::Map(const Map& _copy)
{
	map = _copy.map;
	count = _copy.count;
}
template<typename Key, typename Value>
Map<Key, Value>::~Map()
{
	delete[] map;
	count = 0;
	map = nullptr;
}
#pragma endregion

#pragma region methods
template<typename Key, typename Value>
int Map<Key, Value>::IndexOfKey(const Key& _key) const
{
	for (size_t i = 0; i < count; i++)
	{
		if (map[i].Key() == _key)
			return i;
	}
	return -1;
}
template<typename Key, typename Value>
void Map<Key, Value>::Insert(const Key& _key, const Value& _value)
{
	Insert(KeyValuePair<Key, Value>(_key, _value));
}
template<typename Key, typename Value>
void Map<Key, Value>::Insert(const KeyValuePair<Key, Value>& _pair)
{
	if (Contains(_pair.Key()))
		throw std::exception("key already exist");

	KeyValuePair<Key, Value>* _tmp = map;
	map = new KeyValuePair<Key, Value>[count + 1];
	for (int i = 0; i < count; i++)
		map[i] = _tmp[i];
	map[count] = _pair;
	count++;
}
template<typename Key, typename Value>
Value& Map<Key, Value>::At(const Key& _key)
{
	const int _index = IndexOfKey(_key);
	if (_index == -1)
		throw std::exception("key doesn't exist ! ");
	return map[_index].Value();
}
template<typename Key, typename Value>
void Map<Key, Value>::Clear()
{
	delete[] map;
	count = 0;
	map = new KeyValuePair<Key, Value>[0];
}
template<typename Key, typename Value>
bool Map<Key, Value>::IsEmpty() const
{
	return count == 0;
}
template<typename Key, typename Value>
void Map<Key, Value>::Remove(const Key& _key)
{
	const int _index = IndexOfKey(_key);
	if (_index == -1)
		throw std::exception("key doesn't existr !");
	KeyValuePair<Key, Value>* _tmp = map;
	map = new KeyValuePair<Key, Value>[count - 1];
	for (int i = 0; i < _index; i++)
		map[i] = _tmp[i];
	for (int i = _index + 1; i < count; i++)
		map[i - 1] = _tmp[i];
	count--;
}
template<typename Key, typename Value>
bool Map<Key, Value>::Contains(const Key& _key)
{
	return IndexOfKey(_key) != -1;
}
#pragma endregion

#pragma region operator
template<typename Key, typename Value>
Value& Map<Key, Value>::operator[](const Key& _key)
{
	return At(_key);
}
#pragma endregion