#pragma once
#include <vector>
#include <string>

class Map;

class MapLoader
{
#pragma region f/p
private:
	std::vector<Map*> maps = std::vector<Map*>();
	int count = 0;
#pragma endregion 
#pragma region constructor
public:
	MapLoader() = default;
	MapLoader(const MapLoader& _copy);
	~MapLoader();
#pragma endregion
#pragma region methods
public:
	void Load(); 
	int Count() const;
	bool IsEmpty() const;
	std::vector<std::string> MapsName() const;
	Map* GetMap(const int _index) const;
	void DisplayMapNames();
#pragma endregion
};